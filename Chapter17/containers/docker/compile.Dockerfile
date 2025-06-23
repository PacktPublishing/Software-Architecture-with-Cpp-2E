FROM ubuntu:plucky

RUN apt update && DEBIAN_FRONTEND=noninteractive apt install -y build-essential gcc cmake ninja-build git python3-pip python3-venv && \
    python3 -mvenv /opt/venv && . /opt/venv/bin/activate && pip3 install conan==2.* && conan profile detect

ADD . /root/src
WORKDIR /root/src

RUN mkdir -p build && cd build && . /opt/venv/bin/activate && \
    conan install .. --build=missing -s:a build_type=Release -s:a compiler.cppstd=gnu20 -of . && \
    cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release && cmake --build . && cmake --install .

CMD ["/usr/local/bin/customer"]
