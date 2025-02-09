FROM ubuntu:plucky AS builder

RUN apt update && DEBIAN_FRONTEND=noninteractive apt install -y build-essential gcc cmake gdb file ninja-build git python3-pip python3-venv

RUN python3 -m venv /opt/venv
ENV PATH="/opt/venv/bin:$PATH"
RUN pip3 install conan==2.* && conan profile detect
