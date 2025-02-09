#!/bin/sh

set -x

ctr=$(buildah from ubuntu:plucky)

buildah run $ctr -- /bin/sh -c 'apt update && apt install -y build-essential gcc'

buildah config --cmd '/usr/bin/gcc' "$ctr"

buildah commit "$ctr" tradefair-gcc

buildah rm "$ctr"
