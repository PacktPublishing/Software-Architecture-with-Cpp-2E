#include <algorithm>
#include <string>

#include <cheerp/client.h>
#include <cheerp/clientlib.h>

[[cheerp::wasm]]
std::string transformStr(std::string str) {
  std::reverse(str.begin(), str.end());
  return str;
}

[[cheerp::genericjs]]
void configureUI() {
  using namespace client;
  console.log("configure UI");

  HTMLElement *body = document.get_body();

  auto inputBox =
      static_cast<HTMLInputElement *>(document.createElement("input"));
  inputBox->setAttribute("type", "text");
  inputBox->setAttribute("value", "Input anything in here");
  inputBox->setAttribute("style", "width:200px");

  HTMLElement *textDisplay = document.createElement("h1");

  auto mirrorText = [textDisplay, inputBox]() -> void {
    const String *text = inputBox->get_value();
    // no Unicode support
    const auto &jsStr =
        String(transformStr(static_cast<std::string>(*text)).c_str());
    textDisplay->set_textContent(jsStr);
  };

  mirrorText();

  inputBox->addEventListener("input", cheerp::Callback(mirrorText));

  body->appendChild(textDisplay);
  body->appendChild(inputBox);
}

[[cheerp::genericjs]]
void webMain() {
  using namespace client;
  console.log("web main");

  configureUI();
}
