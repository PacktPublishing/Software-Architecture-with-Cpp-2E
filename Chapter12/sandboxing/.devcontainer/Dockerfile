FROM ubuntu:jammy

RUN apt update && apt install -y software-properties-common
RUN add-apt-repository -y ppa:leaningtech-dev/cheerp-ppa && apt update && apt install -y cheerp-core cmake ninja-build gdb

ENV PATH=/opt/cheerp/bin:$PATH

WORKDIR /src
