#include <cstdlib>
#include <iostream>
#include <string>

#include <kafka/KafkaConsumer.h>

int main() {
  using namespace kafka;
  using namespace kafka::clients::consumer;

  // 192.168.0.1:9092,192.168.0.2:9092,192.168.0.3:9092
  const char *tmp = std::getenv("KAFKA_BROKER_LIST");
  std::string brokers{tmp != nullptr ? tmp : "127.0.0.1:9092"};

  tmp = std::getenv("TOPIC");
  const Topic topic{tmp != nullptr ? tmp : "test-topic"};

  const Properties props({{"bootstrap.servers", {brokers}},
                          {"auto.create.topics.enable", {"true"}}});

  KafkaConsumer consumer(props);

  consumer.subscribe({topic});

  while (true) {
    auto records = consumer.poll(std::chrono::milliseconds(100));

    for (const auto &record : records) {
      if (!record.error()) {
        std::cout << "Got a new message..." << std::endl;
        std::cout << "    Topic    : " << record.topic() << std::endl;
        std::cout << "    Partition: " << record.partition() << std::endl;
        std::cout << "    Offset   : " << record.offset() << std::endl;
        std::cout << "    Timestamp: " << record.timestamp().toString()
                  << std::endl;
        std::cout << "    Headers  : " << toString(record.headers())
                  << std::endl;
        std::cout << "    Key   [" << record.key().toString() << "]"
                  << std::endl;
        std::cout << "    Value [" << record.value().toString() << "]"
                  << std::endl;
      } else {
        std::cerr << record.toString() << std::endl;
      }
    }
  }

  consumer.close();
}
