#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TServerSocket.h>

// generated types
#include "gen-cpp/Service.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

using namespace Service;

class ServiceHandler final : public ServiceIf {
public:
  void sayHello(std::string &_return, const std::string &name) {
    std::cout << name << std::endl;
    _return = "Trust me " + name;
  }
};

int main() {
  std::shared_ptr<ServiceHandler> handler(new ServiceHandler());
  std::shared_ptr<TProcessor> processor(new ServiceProcessor(handler));
  std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(9090));
  std::shared_ptr<TTransportFactory> transportFactory(
      new TBufferedTransportFactory());
  std::shared_ptr<TProtocolFactory> protocolFactory(
      new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory,
                       protocolFactory);
  server.serve();

  return 0;
}
