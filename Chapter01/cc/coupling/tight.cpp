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

class ChatNotifier {
 public:
  void sendMessage(const std::string &message) {
    std::cout << "Chat channel: " << message << std::endl;
  }
};

class NotificationSystem {
 public:
  void notify(const std::string &message) {
    sms_.sendSMS(message);
    email_.sendEmail(message);
    chat_.sendMessage(message);
  }

 private:
  SMSNotifier sms_;
  EMailNotifier email_;
  ChatNotifier chat_;
};

int main() {
  auto ns = NotificationSystem{};
  ns.notify("Azabeth Burns");
}
