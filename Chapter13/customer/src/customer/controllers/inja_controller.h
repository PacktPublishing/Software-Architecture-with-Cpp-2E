#pragma once

#include <drogon/HttpResponse.h>
#include <drogon/HttpSimpleController.h>

using namespace drogon;

class InjaController final : public HttpSimpleController<InjaController> {
 public:
  PATH_LIST_BEGIN
  PATH_ADD("/customer/v4", Get);
  PATH_LIST_END

 protected:
  void asyncHandleHttpRequest(
      const HttpRequestPtr &request,
      std::function<void(const HttpResponsePtr &)> &&callback) override;
};
