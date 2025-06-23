#pragma once

#include <opentelemetry/metrics/sync_instruments.h>
#include <opentelemetry/nostd/unique_ptr.h>

namespace otlp_metrics {
void init_metrics();

opentelemetry::nostd::unique_ptr<opentelemetry::metrics::Counter<uint64_t>>
init_int64_counter(std::string name);
}  // namespace otlp_metrics
