#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class Notifier {
 public:
  virtual ~Notifier() = default;
  virtual void notify(const std::string &message) = 0;
};

class SMSNotifier : public Notifier {
 public:
  void notify(const std::string &message) override { sendSMS(message); }

 private:
  void sendSMS(const std::string &message) {
    std::cout << "SMS channel: " << message << std::endl;
  }
};

class EMailNotifier : public Notifier {
 public:
  void notify(const std::string &message) override { sendEmail(message); }

 private:
  void sendEmail(const std::string &message) {
    std::cout << "Email channel: " << message << std::endl;
  }
};

class NotificationSystem {
 public:
  using Notifiers = std::vector<std::unique_ptr<Notifier>>;

  explicit NotificationSystem(Notifiers notifiers)
      : notifiers_{std::move(notifiers)} {}

  void notify(const std::string &message) {
    for (const auto &notifier : notifiers_) {
      notifier->notify(message);
    }
  }

 private:
  Notifiers notifiers_;
};

int main() {
  auto notifiers = NotificationSystem::Notifiers{};
  notifiers.emplace_back(std::make_unique<SMSNotifier>());
  notifiers.emplace_back(std::make_unique<EMailNotifier>());
  auto ns = NotificationSystem{std::move(notifiers)};
  ns.notify("Quinn, Wade, Arturo, Rembrandt");
}
