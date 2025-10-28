#pragma once

#include <drogon/HttpController.h>

#include "customer/responder.h"

using namespace drogon;

class Controller final : public HttpController<Controller> {
public:
  METHOD_LIST_BEGIN
  ADD_METHOD_TO(Controller::respond, "/customer/v2", Get);
  METHOD_LIST_END

protected:
  void respond(const HttpRequestPtr &request,
               std::function<void(const HttpResponsePtr &)> &&callback);

  static inline responder get_responder;
};
