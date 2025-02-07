{ pkgs ? import (
  builtins.fetchTarball {
    url = "https://github.com/NixOS/nixpkgs/archive/24.05.tar.gz";
    sha256 = "sha256:1lr1h35prqkd1mkmzriwlpvxcb34kmhc9dnr48gkm8hh089hifmx";
  }
) {} }:

let
  additionalInputs = if pkgs.system == "x86_64-linux" then pkgs.lsb-release else "";
in
with pkgs; {
  gcc14Env = stdenvNoCC.mkDerivation {
    name = "gcc14-environment";
    buildInputs = [
      ansible
      autoconf
      automake
      awscli
      buildah
      clang
      cmake
      conan
      conmon
      docker
      docker-compose
      doxygen
      gcc14
      libtool
      lsb-release
      ninja
      nomad
      packer
      pkg-config
      podman
      pre-commit
      runc
      slirp4netns
      terraform
      additionalInputs
      ensureNewerSourcesForZipFilesHook
      python3Packages.pip
      python3Packages.setuptools
      python3Packages.virtualenv
      additionalInputs
    ];
    shellHook = ''
      pre-commit install -f --hook-type pre-commit

      virtualenv venv
      source venv/bin/activate
      pip install sphinx sphinx-rtd-theme breathe sphinx_mdinclude

      # <setup for buildah toolchain>
      sudo mkdir -p /etc/containers
      cat <<EOF | sudo tee /etc/containers/policy.json
      {
          "default": [
              {
                  "type": "insecureAcceptAnything"
              }
          ]
      }
      EOF
      cat <<EOF | sudo tee /etc/containers/registries.conf
      [registries.search]
      registries = [ 'docker.io' ]
      EOF

      # documentation for this is very disorganized at this point
      # see https://github.com/containers/libpod/blob/master/docs/libpod.conf.5.md
      cat <<EOF | tee $HOME/podman.conf
      conmon_path = [ "$(which conmon)" ]
      events_logger = "file"
      [runtimes]
      runc = [ "$(which runc)" ]
      EOF
      unset SOURCE_DATE_EPOCH
      virtualenv venv
      source venv/bin/activate
      pip install ansible-bender==0.10.1 docker-compose==1.29.2
    '';
  };
}
