FROM ubuntu:plucky AS builder

RUN apt update && DEBIAN_FRONTEND=noninteractive apt install -y build-essential gcc cmake ninja-build git python3-pip python3-venv

RUN python3 -m venv /opt/venv
ENV PATH="/opt/venv/bin:$PATH"
RUN pip3 install conan==2.* && conan profile detect

ADD . /root/src
WORKDIR /root/src

RUN mkdir -p build && cd build && \
    conan install .. --build=missing -s:a build_type=Release -s:a compiler.cppstd=gnu20 -of . && \
    cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release && cmake --build . && cmake --install .

FROM ubuntu:plucky

COPY --from=builder /root/src/build/bin/customer /bin/customer

CMD ["/bin/customer"]
