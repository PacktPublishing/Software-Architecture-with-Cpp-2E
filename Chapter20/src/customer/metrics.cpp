#include "customer/metrics.h"

#include <opentelemetry/exporters/otlp/otlp_grpc_metric_exporter_factory.h>
#include <opentelemetry/exporters/otlp/otlp_grpc_metric_exporter_options.h>
#include <opentelemetry/metrics/provider.h>
#include <opentelemetry/metrics/sync_instruments.h>
#include <opentelemetry/nostd/unique_ptr.h>
#include <opentelemetry/sdk/metrics/export/periodic_exporting_metric_reader.h>
#include <opentelemetry/sdk/metrics/export/periodic_exporting_metric_reader_options.h>
#include <opentelemetry/sdk/metrics/meter_provider.h>
#include <opentelemetry/sdk/metrics/metric_reader.h>

#include <memory>

namespace otlp_exporter = opentelemetry::exporter::otlp;
namespace metrics_sdk = opentelemetry::sdk::metrics;
namespace metrics_api = opentelemetry::metrics;

namespace otlp_metrics {
void init_metrics() {
  const otlp_exporter::OtlpGrpcMetricExporterOptions exporter_options;
  auto exporter =
      otlp_exporter::OtlpGrpcMetricExporterFactory::Create(exporter_options);

  const metrics_sdk::PeriodicExportingMetricReaderOptions reader_options;
  std::unique_ptr<metrics_sdk::MetricReader> reader{
      new metrics_sdk::PeriodicExportingMetricReader(std::move(exporter),
                                                     reader_options)};
  const auto provider =
      std::static_pointer_cast<opentelemetry::metrics::MeterProvider>(
          std::make_shared<metrics_sdk::MeterProvider>());
  const auto p = std::static_pointer_cast<metrics_sdk::MeterProvider>(provider);
  p->AddMetricReader(std::move(reader));
  metrics_api::Provider::SetMeterProvider(provider);
}

opentelemetry::nostd::unique_ptr<metrics_api::Counter<uint64_t>>
init_int64_counter(std::string name) {
  const auto provider = metrics_api::Provider::GetMeterProvider();
  const opentelemetry::nostd::shared_ptr<metrics_api::Meter> meter =
      provider->GetMeter(name);
  return meter->CreateUInt64Counter(name + "_counter");
}
}  // namespace otlp_metrics
