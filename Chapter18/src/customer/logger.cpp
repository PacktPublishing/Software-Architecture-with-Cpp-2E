#include "customer/logger.h"

#include <opentelemetry/exporters/ostream/log_record_exporter_factory.h>
#include <opentelemetry/exporters/otlp/otlp_grpc_log_record_exporter_factory.h>
#include <opentelemetry/exporters/otlp/otlp_grpc_log_record_exporter_options.h>
#include <opentelemetry/logs/logger.h>
#include <opentelemetry/logs/provider.h>
#include <opentelemetry/nostd/shared_ptr.h>
#include <opentelemetry/sdk/logs/logger_context_factory.h>
#include <opentelemetry/sdk/logs/logger_provider_factory.h>
#include <opentelemetry/sdk/logs/processor.h>
#include <opentelemetry/sdk/logs/simple_log_record_processor_factory.h>

#include <format>
#include <memory>
#include <vector>

namespace otlp_exporter = opentelemetry::exporter::otlp;
namespace logs_exporter = opentelemetry::exporter::logs;
namespace logs_api = opentelemetry::logs;
namespace logs_sdk = opentelemetry::sdk::logs;
namespace nostd = opentelemetry::nostd;

namespace otlp_logger {
void init_logger() {
  const otlp_exporter::OtlpGrpcLogRecordExporterOptions grpc_logger_options;
  auto grpc_exporter = otlp_exporter::OtlpGrpcLogRecordExporterFactory::Create(
      grpc_logger_options);
  auto grpc_processor = logs_sdk::SimpleLogRecordProcessorFactory::Create(
      std::move(grpc_exporter));

  auto os_exporter = logs_exporter::OStreamLogRecordExporterFactory::Create();
  auto os_processor =
      logs_sdk::SimpleLogRecordProcessorFactory::Create(std::move(os_exporter));

  std::vector<std::unique_ptr<logs_sdk::LogRecordProcessor>> processors;
  processors.push_back(std::move(grpc_processor));
  processors.push_back(std::move(os_processor));

  auto context = logs_sdk::LoggerContextFactory::Create(std::move(processors));
  const std::shared_ptr<logs_api::LoggerProvider> provider =
      logs_sdk::LoggerProviderFactory::Create(std::move(context));
  logs_api::Provider::SetLoggerProvider(provider);
}

nostd::shared_ptr<logs_api::Logger> get_logger(std::string name) {
  const auto provider = logs_api::Provider::GetLoggerProvider();
  return provider->GetLogger(name + "_logger");
}
} // namespace otlp_logger
