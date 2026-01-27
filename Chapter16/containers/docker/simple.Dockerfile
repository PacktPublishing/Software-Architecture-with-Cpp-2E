FROM ubuntu:resolute

COPY customer /bin/customer

CMD ["/bin/customer"]
