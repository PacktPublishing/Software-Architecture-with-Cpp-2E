#include <functional>
#include <iostream>
#include <mutex>
#include <unordered_map>
#include <utility>

#include <drogon/HttpSimpleController.h>
#include <drogon/drogon.h>

using namespace drogon;

class ItemsController final : public HttpController<ItemsController> {
public:
  METHOD_LIST_BEGIN
  // list of items
  ADD_METHOD_TO(ItemsController::getItems, "/api/items", Get);
  // create new item
  ADD_METHOD_TO(ItemsController::createItem, "/api/items", Post);
  // view an item
  ADD_METHOD_TO(ItemsController::getItemById, "/api/items/{1}", Get);
  // update an item
  ADD_METHOD_TO(ItemsController::updateItem, "/api/items/{1}", Put);
  // delete an item
  ADD_METHOD_TO(ItemsController::deleteItem, "/api/items/{1}", Delete);
  METHOD_LIST_END

  void getItems(const HttpRequestPtr &,
                std::function<void(const HttpResponsePtr &)> &&callback) {
    Json::Value array(Json::arrayValue);
    std::lock_guard lock(storage_mutex_);

    for (const auto &[id, name] : items_) {
      Json::Value item;
      item["id"] = id;
      item["name"] = name;
      array.append(item);
    }

    auto resp = HttpResponse::newHttpJsonResponse(array);
    callback(resp);
  }

  void createItem(const HttpRequestPtr &req,
                  std::function<void(const HttpResponsePtr &)> &&callback) {
    auto json = req->getJsonObject();

    if (!json || !json->isMember("name")) {
      auto resp = HttpResponse::newHttpResponse();
      resp->setStatusCode(k400BadRequest);
      resp->setBody("No name");
      callback(resp);
      return;
    }

    int id;
    auto name = (*json)["name"].asString();
    {
      std::lock_guard lock(storage_mutex_);

      items_.emplace(id = ++next_id_, name);
    }

    Json::Value result;
    result["id"] = id;
    result["name"] = name;

    auto resp = HttpResponse::newHttpJsonResponse(result);
    resp->setStatusCode(k201Created);
    resp->addHeader("Location", "/api/items/" + std::to_string(id));
    callback(resp);
  }

  void getItemById(const HttpRequestPtr &,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   int id) {
    auto item = [this, id]() -> std::optional<std::pair<int, std::string>> {
      std::lock_guard lock(storage_mutex_);

      if (const auto it = items_.find(id); it != items_.end()) {
        return {{it->first, it->second}};
      }
      return std::nullopt;
    }();

    if (!item.has_value()) {
      auto resp = HttpResponse::newHttpResponse();
      resp->setStatusCode(k404NotFound);
      callback(resp);
      return;
    }

    Json::Value json;
    json["id"] = item->first;
    json["name"] = item->second;

    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
  }

  void updateItem(const HttpRequestPtr &req,
                  std::function<void(const HttpResponsePtr &)> &&callback,
                  int id) {
    auto json = req->getJsonObject();
    if (!json || !json->isMember("name")) {
      auto resp = HttpResponse::newHttpResponse();
      resp->setStatusCode(k400BadRequest);
      resp->setBody("No name");
      callback(resp);
      return;
    }

    auto item = [this, id,
                 json]() -> std::optional<std::pair<int, std::string>> {
      std::lock_guard lock(storage_mutex_);

      if (const auto it = items_.find(id); it != items_.end()) {
        it->second = (*json)["name"].asString();
        return {{it->first, it->second}};
      }
      return std::nullopt;
    }();

    if (!item.has_value()) {
      auto resp = HttpResponse::newHttpResponse();
      resp->setStatusCode(k404NotFound);
      callback(resp);
      return;
    }

    Json::Value result;
    result["id"] = item->first;
    result["name"] = item->second;

    auto resp = HttpResponse::newHttpJsonResponse(result);
    callback(resp);
  }

  void deleteItem(const HttpRequestPtr &,
                  std::function<void(const HttpResponsePtr &)> &&callback,
                  int id) {
    auto item = [this, id]() -> std::optional<int> {
      std::lock_guard lock(storage_mutex_);

      if (const auto it = items_.find(id); it != items_.end()) {
        items_.erase(it);
        return {it->first};
      }
      return std::nullopt;
    }();

    auto resp = HttpResponse::newHttpResponse();
    if (!item.has_value()) {
      resp->setStatusCode(k404NotFound);
      callback(resp);
      return;
    }

    resp->setStatusCode(k204NoContent);
    callback(resp);
  }

private:
  std::unordered_map<int, std::string> items_;
  int next_id_ = 0;
  std::mutex storage_mutex_;
};

int main() {
  app()
      .addListener("0.0.0.0", 8080)
      .setThreadNum(0)
      .setDocumentRoot("./static")
      .setFileTypes(
          {"html", "js", "css", "gif", "png", "jpg", "ico", "yaml", "json"})
      .run();
}
