#include <iostream>
#include <mqtt/async_client.h>
#include <string>

const std::string SERVER_ADDRESS("tcp://localhost:1883");
const std::string CLIENT_ID("publisher");
const std::string TOPIC("test/topic");
constexpr int QOS = 1;

class callback final : public mqtt::callback {
public:
  void connection_lost(const std::string &cause) override {
    std::cout << "Connection lost: " << cause << std::endl;
  }

  void delivery_complete(mqtt::delivery_token_ptr token) override {
    std::cout << "Message delivered" << std::endl;
  }
};

int main() {
  mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);
  callback cb;
  client.set_callback(cb);

  mqtt::connect_options conn_opts;
  conn_opts.set_keep_alive_interval(20);
  conn_opts.set_clean_session(true);

  try {
    client.connect(conn_opts)->wait();
    std::cout << "Connected to MQTT broker" << std::endl;

    std::string payload = "It's a UNIX system!";
    mqtt::message_ptr pub_msg = mqtt::make_message(TOPIC, payload, QOS, false);
    client.publish(pub_msg)->wait();
    std::cout << "Message published: " << payload << std::endl;

    client.disconnect()->wait();
    std::cout << "Disconnected" << std::endl;
  } catch (const mqtt::exception &exc) {
    std::cerr << "MQTT Exception: " << exc.what() << std::endl;
    return 1;
  }

  return 0;
}
