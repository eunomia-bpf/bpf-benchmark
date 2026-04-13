FROM docker.io/library/rockylinux:9@sha256:d7be1c094cc5845ee815d4632fe377514ee6ebcf8efaed6892889657e5ddaaa6

ARG GO_VERSION=1.26.0
ARG TARGETARCH

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
        ca-certificates \
        cargo \
        clang \
        cmake \
        cpio \
        curl-minimal \
        diffutils \
        double-conversion-devel \
        dwarves \
        elfutils-devel \
        elfutils-libelf-devel \
        file \
        findutils \
        flex \
        fmt-devel \
        gcc-c++ \
        gcc-toolset-14-gcc-c++ \
        gcc-toolset-14-libstdc++-devel \
        git \
        glog-devel \
        kmod \
        libaio-devel \
        libbpf-devel \
        libdwarf-devel \
        libmnl-devel \
        libpcap-devel \
        libsodium-static \
        libtool \
        libunwind-devel \
        llvm \
        llvm-devel \
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
        xz \
        xz-devel \
        yaml-cpp-devel \
        zlib-devel \
        zlib-static \
        zstd \
    && dnf clean all

RUN set -eux; \
    go_arch="${TARGETARCH}"; \
    if [ -z "$go_arch" ]; then go_arch="$(uname -m)"; fi; \
    case "$go_arch" in \
        amd64|x86_64) go_arch=amd64 ;; \
        arm64|aarch64) go_arch=arm64 ;; \
        *) echo "unsupported Go arch: $go_arch" >&2; exit 1 ;; \
    esac; \
    curl -fsSL "https://go.dev/dl/go${GO_VERSION}.linux-${go_arch}.tar.gz" -o /tmp/go.tgz; \
    rm -rf /usr/local/go; \
    tar -C /usr/local -xzf /tmp/go.tgz; \
    rm -f /tmp/go.tgz; \
    /usr/local/go/bin/go version

ENV PATH="/usr/local/go/bin:${PATH}" \
    GOTOOLCHAIN=local

WORKDIR /workspace
