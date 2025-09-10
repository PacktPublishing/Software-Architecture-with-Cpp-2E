FROM ubuntu:questing

RUN apt update && apt install -y build-essential gcc

CMD ["/usr/bin/gcc"]
