FROM ubuntu:questing

COPY customer /bin/customer

CMD ["/bin/customer"]
