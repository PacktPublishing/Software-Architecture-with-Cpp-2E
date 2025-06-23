#include <iostream>
#include <string>

class SMSNotifier {
public:
  void sendSMS(const std::string &message) {
    std::cout << "SMS channel: " << message << std::endl;
  }
};

class EMailNotifier {
public:
  void sendEmail(const std::string &message) {
    std::cout << "Email channel: " << message << std::endl;
  }
};

class NotificationSystem {
public:
  void notify(const std::string &message) {
    sms_.sendSMS(message);
    email_.sendEmail(message);
  }

private:
  SMSNotifier sms_;
  EMailNotifier email_;
};

int main() {
  auto ns = NotificationSystem{};
  ns.notify("Quinn, Wade, Arturo, Rembrandt");
}
