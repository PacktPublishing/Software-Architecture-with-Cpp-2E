FROM ubuntu:noble

COPY customer /bin/customer

CMD ["/bin/customer"]
