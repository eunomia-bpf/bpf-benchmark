FROM docker.io/library/rockylinux:9@sha256:d7be1c094cc5845ee815d4632fe377514ee6ebcf8efaed6892889657e5ddaaa6

RUN dnf -y install --setopt=install_weak_deps=False --nodocs \
        dnf-plugins-core \
        epel-release \
    && dnf config-manager --set-enabled crb \
    && dnf -y install --setopt=install_weak_deps=False --nodocs \
        autoconf \
        automake \
        bc \
        binutils-devel \
        bison \
        bpftool \
        boost-devel \
        boost-static \
        bzip2-devel \
        cargo \
        clang \
        cmake \
        cpio \
        diffutils \
        double-conversion-devel \
        dwarves \
        elfutils-devel \
        elfutils-devel-static \
        elfutils-libelf-devel \
        file \
        findutils \
        flex \
        fmt-devel \
        gcc-c++ \
        git \
        glog-devel \
        golang \
        kmod \
        libaio-devel \
        libatomic-static \
        libdwarf-devel \
        libmnl-devel \
        libsodium-static \
        libtool \
        libunwind-devel \
        llvm \
        lz4-devel \
        make \
        openssl-devel \
        perl \
        pkgconf-pkg-config \
        python3 \
        python3-scons \
        re2-devel \
        rsync \
        rust \
        snappy-devel \
        spdlog-devel \
        tar \
        unzip \
        which \
        xz-devel \
        yaml-cpp-devel \
        zlib-devel \
        zlib-static \
    && dnf clean all

WORKDIR /workspace
