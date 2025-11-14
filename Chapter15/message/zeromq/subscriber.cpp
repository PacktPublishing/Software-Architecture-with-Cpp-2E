#include <cassert>
#include <cstdio>

#include <zmq.h>

#define MSG_SIZE 1024

int main() {
  void *context = zmq_ctx_new();
  void *subscriber = zmq_socket(context, ZMQ_SUB);

  int rc = zmq_connect(subscriber, "tcp://127.0.0.1:5556");
  assert(rc == 0);

  rc = zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "", 0);
  assert(rc == 0);

  char msg[MSG_SIZE + 1];

  while (true) {
    rc = zmq_recv(subscriber, msg, MSG_SIZE, 0);
    assert(rc != -1);
    msg[rc] = '\0'; // important

    printf("%s\n", msg);
  }

  zmq_close(subscriber);
  zmq_ctx_destroy(context);

  return 0;
}
