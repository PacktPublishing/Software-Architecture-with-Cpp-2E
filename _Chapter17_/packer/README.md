# Software Architecture with C++, Second Edition

Software Architecture with C++, Second Edition, Published by Packt

## Chapter 17: Service Oriented Architecture

### Packer

You can create an API token at
https://cloud.digitalocean.com/account/api/tokens. You need a token with Write
permissions. Copy it and either set the environment variable yourself or put it
into the `.env` file if you're using Direnv.

```
export DIGITALOCEAN_ACCESS_TOKEN=alongkeyhere
```

Building the package image requires having a customer-1.0.3.deb package in your
working directory. You may either build it using the instructions from the other
chapters or you may substitute it with another valid deb package, eg.:

```
wget http://mirrors.kernel.org/ubuntu/pool/main/t/time/time_1.7-25.1build1_amd64.deb -O packer/customer-1.0.3.deb
```

To build the image with Packer run

```
cd packer
packer build packer-digitalocean.json
```

**Important**: Make sure to delete the cloud resources after testing. You can
find the created image at https://cloud.digitalocean.com/images/snapshots/droplets
