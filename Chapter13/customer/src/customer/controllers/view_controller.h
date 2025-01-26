#pragma once

#include <drogon/HttpResponse.h>
#include <drogon/HttpSimpleController.h>

using namespace drogon;

class ViewController final : public HttpSimpleController<ViewController> {
 public:
  PATH_LIST_BEGIN
  PATH_ADD("/customer/v3", Get);
  PATH_LIST_END

 protected:
  void asyncHandleHttpRequest(
      const HttpRequestPtr &request,
      std::function<void(const HttpResponsePtr &)> &&callback) override;
};
