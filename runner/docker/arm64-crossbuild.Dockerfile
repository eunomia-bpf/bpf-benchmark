FROM amazonlinux:2023

RUN dnf install -y --setopt=install_weak_deps=False \
        cmake \
        elfutils-libelf-devel \
        file \
        gcc-c++ \
        gzip \
        kernel6.18-libbpf-devel \
        make \
        pkgconf-pkg-config \
        tar \
        yaml-cpp-devel \
        zlib-devel \
        libzstd-devel \
    && dnf clean all \
    && rm -rf /var/cache/dnf
