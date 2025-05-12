#include <iostream>
#include <string>
#include <utility>
#include <variant>
#include <vector>

class SMSNotifier {
 public:
  void notify(const std::string &message) { sendSMS(message); }

 private:
  void sendSMS(const std::string &message) {
    std::cout << "SMS channel: " << message << std::endl;
  }
};

class EMailNotifier {
 public:
  void notify(const std::string &message) { sendEmail(message); }

 private:
  void sendEmail(const std::string &message) {
    std::cout << "Email channel: " << message << std::endl;
  }
};

class ChatNotifier {
 public:
  void notify(const std::string &message) { sendMessage(message); }

 private:
  void sendMessage(const std::string &message) {
    std::cout << "Chat channel: " << message << std::endl;
  }
};

template <typename... T>
class NotificationSystem {
 public:
  using Notifiers = std::vector<std::variant<T...>>;

  explicit NotificationSystem(Notifiers notifiers)
      : notifiers_{std::move(notifiers)} {}

  void notify(const std::string &message) {
    for (auto &notifier : notifiers_) {
      std::visit([&](auto &n) { n.notify(message); }, notifier);
    }
  }

 private:
  Notifiers notifiers_;
};

using MyNotificationSystem =
    NotificationSystem<SMSNotifier, EMailNotifier, ChatNotifier>;

int main() {
  auto sn = SMSNotifier{};
  auto en = EMailNotifier{};
  auto cn = ChatNotifier{};
  auto ns = MyNotificationSystem{{sn, en, cn}};
  ns.notify("Azabeth Burns");
}
