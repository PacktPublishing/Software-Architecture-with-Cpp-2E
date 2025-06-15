#include "customer/promstat.h"

#include <drogon/HttpAppFramework.h>
#include <drogon/plugins/PromExporter.h>
#include <drogon/utils/monitoring/Counter.h>
#include <drogon/utils/monitoring/Histogram.h>

using namespace std::literals::chrono_literals;
using namespace drogon;

void PromStat::invoke(const HttpRequestPtr &req,
                      MiddlewareNextCallback &&nextCb,
                      MiddlewareCallback &&mcb) {
  std::string path{req->matchedPathPattern()};
  auto method = req->methodString();
  const auto promExporter = app().getPlugin<plugin::PromExporter>();
  if (promExporter) {
    const auto collector =
        promExporter->getCollector<monitoring::Counter>("http_requests_total");
    if (collector) {
      collector->metric({method, path})->increment();
    }
  }
  const auto start = trantor::Date::date();

  nextCb([mcb = std::move(mcb), &promExporter, start, method,
          path](const HttpResponsePtr &resp) {
    if (promExporter) {
      const auto collector = promExporter->getCollector<monitoring::Histogram>(
          "http_request_duration_seconds");
      if (collector) {
        static const std::vector<double> boundaries{0.0001, 0.001, 0.01, 0.1,
                                                    0.5,    1,     2,    3};
        const auto end = trantor::Date::date();
        const auto duration =
            end.microSecondsSinceEpoch() - start.microSecondsSinceEpoch();
        collector->metric({method, path}, boundaries, 1h, 6)
            ->observe(static_cast<double>(duration) / 1000000);
      }
    }

    mcb(resp);
  });
}
