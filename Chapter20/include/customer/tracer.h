#pragma once

#include <drogon/drogon.h>
#include <opentelemetry/nostd/shared_ptr.h>
#include <opentelemetry/trace/tracer.h>

namespace otlp_tracer {
void init_tracer();

opentelemetry::nostd::shared_ptr<opentelemetry::trace::Tracer> get_tracer(
    std::string name);

opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span>
get_http_request_span(
    const drogon::HttpRequestPtr &request,
    const opentelemetry::nostd::shared_ptr<opentelemetry::trace::Tracer>
        &tracer,
    std::string name);
}  // namespace otlp_tracer
