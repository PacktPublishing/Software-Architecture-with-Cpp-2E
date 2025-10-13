#include <cheerp/client.h>
#include <cheerp/clientlib.h>

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
    textDisplay->set_textContent(text);
  };

  mirrorText();

  inputBox->addEventListener("input", cheerp::Callback(mirrorText));

  body->appendChild(textDisplay);
  body->appendChild(inputBox);
}

[[cheerp::genericjs]]
void loadCallback() {
  configureUI();
}

[[cheerp::genericjs]]
void webMain() {
  using namespace client;

  document.addEventListener("load", cheerp::Callback(loadCallback));
}
