FROM alpine AS builder

FROM scratch
COPY ./bin/customer /bin/customer

ENV GRPC_DEFAULT_SSL_ROOTS_FILE_PATH=/usr/share/grpc/roots.pem
COPY --from=builder /etc/ssl/certs/ca-certificates.crt /usr/share/grpc/roots.pem

VOLUME /tmp
ENTRYPOINT ["/bin/customer"]

EXPOSE 8080
