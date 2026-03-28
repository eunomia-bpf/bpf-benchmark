FROM amazonlinux:2023

RUN dnf install -y --setopt=install_weak_deps=False \
        cargo \
        cmake \
        elfutils-libelf-devel \
        file \
        gcc-c++ \
        git \
        gzip \
        kernel6.18-libbpf-devel \
        llvm-devel \
        make \
        ncurses-devel \
        pkgconf-pkg-config \
        rust \
        tar \
        yaml-cpp-devel \
        zlib-devel \
        libzstd-devel \
    && dnf clean all \
    && rm -rf /var/cache/dnf
