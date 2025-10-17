#include <iostream>

#include <amqpcpp.h>
#include <amqpcpp/libevent.h>
#include <event2/event.h>

int main() {
  auto evbase = event_base_new();

  AMQP::LibEventHandler handler(evbase);
  AMQP::TcpConnection connection(
      &handler, AMQP::Address("amqp://guest:guest@localhost:5672/"));
  AMQP::TcpChannel channel(&connection);

  channel.onError([&evbase](const char *message) {
    std::cout << "Channel error: " << message << std::endl;
    event_base_loopbreak(evbase);
  });

  auto exchange_name = "greet-exchange";
  channel.declareExchange(exchange_name, AMQP::ExchangeType::direct);

  channel.confirmSelect()
      .onSuccess([&]() {
        auto routing_key = "greet-routing";
        channel.publish(exchange_name, routing_key, "Hello RabbitMQ from C++");
      })
      .onAck([&](uint64_t delivery_tag, bool multiple) {
        event_base_loopbreak(evbase);
      })
      .onNack([&](uint64_t delivery_tag, bool multiple, bool requeue) {
        event_base_loopbreak(evbase);
      });

  event_base_dispatch(evbase);
  event_base_free(evbase);

  return 0;
}
