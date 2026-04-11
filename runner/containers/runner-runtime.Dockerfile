FROM docker.io/library/rockylinux:9@sha256:d7be1c094cc5845ee815d4632fe377514ee6ebcf8efaed6892889657e5ddaaa6

RUN dnf -y install --setopt=install_weak_deps=False --nodocs \
        dnf-plugins-core \
        epel-release \
    && dnf config-manager --set-enabled crb \
    && dnf -y install --setopt=install_weak_deps=False --nodocs \
        bash \
        bpftrace \
        bpftool \
        boost \
        bzip2-libs \
        coreutils \
        curl \
        double-conversion \
        elfutils-libelf \
        file \
        findutils \
        fio \
        fmt \
        glog \
        iproute \
        iproute-tc \
        kmod \
        libaio \
        libbpf \
        libdwarf \
        libmnl \
        libsodium \
        libtool-ltdl \
        libunwind \
        lz4-libs \
        openssl-libs \
        procps-ng \
        python3 \
        python3-pyyaml \
        re2 \
        snappy \
        spdlog \
        stress-ng \
        tar \
        util-linux \
        which \
        xz-libs \
        yaml-cpp \
        zlib \
    && dnf clean all

WORKDIR /workspace
