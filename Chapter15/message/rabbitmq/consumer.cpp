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

  auto queue_name = "greet-queue";
  channel.declareQueue(queue_name, AMQP::durable);

  auto routing_key = "greet-routing";
  channel.bindQueue(exchange_name, queue_name, routing_key);

  channel.consume(queue_name)
      .onReceived(
          [&channel](const AMQP::Message &msg, uint64_t tag, bool redelivered) {
            std::cout << "Received: " << std::string{msg.body(), msg.bodySize()}
                      << std::endl;
            channel.ack(tag);
          });

  event_base_dispatch(evbase);
  event_base_free(evbase);

  return 0;
}
