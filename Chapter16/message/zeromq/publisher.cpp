#include <cassert>
#include <cstdio>
#include <cstring>

#include <zmq.h>

int main() {
  void *context = zmq_ctx_new();
  void *publisher = zmq_socket(context, ZMQ_PUB);

  int rc = zmq_bind(publisher, "tcp://127.0.0.1:5556");
  assert(rc == 0);

  char msg[] = "Hello, ZeroMQ from C/C++!";
  size_t msg_size = strlen(msg);

  while (true) {
    rc = zmq_send(publisher, msg, msg_size, 0);
    assert(rc == msg_size);
  }

  zmq_close(publisher);
  zmq_ctx_destroy(context);

  return 0;
}
