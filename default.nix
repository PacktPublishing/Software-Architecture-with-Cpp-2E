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
      #ansible
      autoconf
      automake
      awscli
      clang
      cmake
      conan
      docker
      docker-compose
      doxygen
      gcc14
      libtool
      lsb-release
      ninja
      packer
      pkg-config
      pre-commit
      terraform
      python3Packages.setuptools
      python3Packages.pip
      python3Packages.virtualenv
      additionalInputs
    ];
    shellHook = ''
      pre-commit install -f --hook-type pre-commit
      virtualenv venv
      source venv/bin/activate
      pip install sphinx sphinx-rtd-theme breathe sphinx_mdinclude
    '';
  };
}
