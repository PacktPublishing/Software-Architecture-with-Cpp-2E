#include "customer/tracer.h"

#include <opentelemetry/context/propagation/global_propagator.h>
#include <opentelemetry/context/propagation/text_map_propagator.h>
#include <opentelemetry/context/runtime_context.h>
#include <opentelemetry/exporters/otlp/otlp_grpc_exporter_factory.h>
#include <opentelemetry/nostd/shared_ptr.h>
#include <opentelemetry/sdk/trace/simple_processor_factory.h>
#include <opentelemetry/sdk/trace/tracer_provider_factory.h>
#include <opentelemetry/semconv/http_attributes.h>
#include <opentelemetry/semconv/network_attributes.h>
#include <opentelemetry/semconv/url_attributes.h>
#include <opentelemetry/trace/context.h>
#include <opentelemetry/trace/propagation/http_trace_context.h>
#include <opentelemetry/trace/provider.h>
#include <opentelemetry/trace/span_metadata.h>
#include <opentelemetry/trace/span_startoptions.h>
#include <opentelemetry/trace/tracer.h>
#include <opentelemetry/trace/tracer_provider.h>

#include <memory>

namespace otlp_exporter = opentelemetry::exporter::otlp;
namespace trace_sdk = opentelemetry::sdk::trace;
namespace trace_api = opentelemetry::trace;
namespace context = opentelemetry::context;
namespace semconv = opentelemetry::semconv;

namespace otlp_tracer {
void init_tracer() {
  auto exporter =
      opentelemetry::exporter::otlp::OtlpGrpcExporterFactory::Create();

  auto processor =
      trace_sdk::SimpleSpanProcessorFactory::Create(std::move(exporter));

  const std::shared_ptr<opentelemetry::trace::TracerProvider> provider =
      trace_sdk::TracerProviderFactory::Create(std::move(processor));

  trace_api::Provider::SetTracerProvider(provider);

  context::propagation::GlobalTextMapPropagator::SetGlobalPropagator(
      opentelemetry::nostd::shared_ptr<context::propagation::TextMapPropagator>(
          new trace_api::propagation::HttpTraceContext()));
}

opentelemetry::nostd::shared_ptr<trace_api::Tracer>
get_tracer(const std::string &name) {
  const auto provider = trace_api::Provider::GetTracerProvider();
  return provider->GetTracer(name + "_tracer");
}

class HttpTextMapCarrier final : public context::propagation::TextMapCarrier {
public:
  explicit HttpTextMapCarrier(const drogon::SafeStringMap<std::string> &headers)
      : headers_(headers) {}

  [[nodiscard]] opentelemetry::nostd::string_view
  Get(const opentelemetry::nostd::string_view key) const noexcept override {
    if (const std::string key_ = key.data(); headers_.contains(key_)) {
      return headers_.at(key_);
    }
    return "";
  }

  void Set(const opentelemetry::nostd::string_view,
           const opentelemetry::nostd::string_view) noexcept override {
    // not required for server
  }

  const drogon::SafeStringMap<std::string> &headers_;
};

opentelemetry::nostd::shared_ptr<trace_api::Span> get_http_request_span(
    const drogon::HttpRequestPtr &request,
    const opentelemetry::nostd::shared_ptr<trace_api::Tracer> &tracer,
    const std::string &name) {
  trace_api::StartSpanOptions options;
  options.kind = trace_api::SpanKind::kServer;

  const HttpTextMapCarrier carrier{request->headers()};
  const auto propagator =
      context::propagation::GlobalTextMapPropagator::GetGlobalPropagator();

  // extract context from HTTP headers
  auto current_ctx = context::RuntimeContext::GetCurrent();
  const auto new_context = propagator->Extract(carrier, current_ctx);
  options.parent = trace_api::GetSpan(new_context)->GetContext();

  // start span with parent context extracted from HTTP headers
  auto span = tracer->StartSpan(
      name,
      {{semconv::http::kHttpRequestMethod, request->method()},
       {semconv::url::kUrlPath, request->path()},
       {semconv::url::kUrlQuery, request->query()},
       {semconv::network::kNetworkLocalAddress, request->getLocalAddr().toIp()},
       {semconv::network::kNetworkLocalPort,
        std::to_string(request->getLocalAddr().toPort())},
       {semconv::network::kNetworkPeerAddress, request->getPeerAddr().toIp()},
       {semconv::network::kNetworkPeerPort,
        std::to_string(request->getPeerAddr().toPort())}},
      options);

  for (const auto &[key, value] : request->headers()) {
    span->SetAttribute("http.header." + key, value);
  }

  return span;
}
} // namespace otlp_tracer
