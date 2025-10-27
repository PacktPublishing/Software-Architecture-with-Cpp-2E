#include <cstdlib>
#include <iostream>
#include <string>

#include <kafka/KafkaProducer.h>

int main() {
  using namespace kafka;
  using namespace kafka::clients::producer;

  // 192.168.0.1:9092,192.168.0.2:9092,192.168.0.3:9092
  const char *tmp = std::getenv("KAFKA_BROKER_LIST");
  std::string brokers{tmp != nullptr ? tmp : "127.0.0.1:9092"};

  tmp = std::getenv("TOPIC");
  const Topic topic{tmp != nullptr ? tmp : "test-topic"};

  const Properties props({{"bootstrap.servers", {brokers}},
                          {"auto.create.topics.enable", {"true"}}});
  KafkaProducer producer(props);

  std::string line{"Ready player three"};
  ProducerRecord record(topic, NullKey, Value(line.c_str(), line.size()));

  auto deliveryCb = [](const RecordMetadata &metadata, const Error &error) {
    if (!error) {
      std::cout << "Message delivered: " << metadata.toString() << std::endl;
    } else {
      std::cerr << "Message failed to be delivered: " << error.message()
                << std::endl;
    }
  };

  producer.send(record, deliveryCb);

  producer.close();
}
