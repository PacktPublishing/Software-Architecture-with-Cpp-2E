#pragma once

#include <opentelemetry/logs/logger.h>
#include <opentelemetry/nostd/shared_ptr.h>

namespace otlp_logger {
void init_logger();

opentelemetry::nostd::shared_ptr<opentelemetry::logs::Logger> get_logger(
    std::string name);
}  // namespace otlp_logger
