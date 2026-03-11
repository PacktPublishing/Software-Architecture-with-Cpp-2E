FROM ubuntu:noble

RUN apt update && apt install -y build-essential gcc

CMD ["/usr/bin/gcc"]
