#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "Service.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;

using namespace ::Service;

int main() {
  std::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
  std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

  ServiceClient client(protocol);

  try {
    transport->open();

    std::string return_;
    client.sayHello(return_, "World");

    transport->close();

    std::cout << return_ << std::endl;
  } catch (TException &ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
  }

  return 0;
}
