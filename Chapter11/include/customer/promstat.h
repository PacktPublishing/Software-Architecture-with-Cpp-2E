#pragma once

#include <drogon/HttpMiddleware.h>

using namespace drogon;

class PromStat final : public HttpMiddleware<PromStat, false> {
 public:
  void invoke(const HttpRequestPtr &req, MiddlewareNextCallback &&nextCb,
              MiddlewareCallback &&mcb) override;
};
