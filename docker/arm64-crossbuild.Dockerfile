FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN dpkg --add-architecture arm64 \
    && rm -f /etc/apt/sources.list.d/ubuntu.sources \
    && printf '%s\n' \
        'Types: deb' \
        'URIs: http://archive.ubuntu.com/ubuntu' \
        'Suites: noble noble-updates noble-backports' \
        'Components: main universe restricted multiverse' \
        'Architectures: amd64' \
        'Signed-By: /usr/share/keyrings/ubuntu-archive-keyring.gpg' \
        '' \
        'Types: deb' \
        'URIs: http://security.ubuntu.com/ubuntu' \
        'Suites: noble-security' \
        'Components: main universe restricted multiverse' \
        'Architectures: amd64' \
        'Signed-By: /usr/share/keyrings/ubuntu-archive-keyring.gpg' \
        > /etc/apt/sources.list.d/ubuntu-amd64.sources \
    && printf '%s\n' \
        'Types: deb' \
        'URIs: http://ports.ubuntu.com/ubuntu-ports' \
        'Suites: noble noble-updates noble-backports noble-security' \
        'Components: main universe restricted multiverse' \
        'Architectures: arm64' \
        'Signed-By: /usr/share/keyrings/ubuntu-archive-keyring.gpg' \
        > /etc/apt/sources.list.d/ubuntu-arm64.sources \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
        cmake \
        gcc-aarch64-linux-gnu \
        g++-aarch64-linux-gnu \
        libelf-dev:arm64 \
        libyaml-cpp-dev:arm64 \
        zlib1g-dev:arm64 \
        libzstd-dev:arm64 \
        make \
        pkg-config \
    && rm -rf /var/lib/apt/lists/*
