# syntax=docker/dockerfile:1.4
FROM docker.io/library/ubuntu:24.04 AS runner-runtime

ARG GO_VERSION=1.26.0
ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
ARG RUN_TARGET_ARCH=x86_64
ARG TARGETARCH

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        autoconf \
        automake \
        bash \
        bc \
        binutils-dev \
        bison \
        bpfcc-tools \
        bzip2 \
        ca-certificates \
        cargo \
        clang \
        cmake \
        cpio \
        curl \
        debianutils \
        diffutils \
        dwarves \
        elfutils \
        file \
        findutils \
        fio \
        flex \
        g++ \
        gcc \
        git \
        iproute2 \
        kmod \
        libaio-dev \
        libboost-all-dev \
        libbpf-dev \
        libbpfcc-dev \
        libbz2-dev \
        libcereal-dev \
        libclang-dev \
        libcurl4-openssl-dev \
        libdouble-conversion-dev \
        libdw-dev \
        libdwarf-dev \
        libedit-dev \
        libelf-dev \
        libevent-dev \
        libffi-dev \
        libfl-dev \
        libfmt-dev \
        libgflags-dev \
        libgoogle-glog-dev \
        liblz4-dev \
        libmnl-dev \
        libpcap-dev \
        libre2-dev \
        libsodium-dev \
        libsnappy-dev \
        libssl-dev \
        libtool \
        libtool-bin \
        libltdl-dev \
        libunwind-dev \
        libyaml-cpp-dev \
        libzstd-dev \
        linux-tools-common \
        linux-tools-generic \
        llvm \
        llvm-dev \
        lz4 \
        make \
        openssl \
        perl \
        pkg-config \
        procps \
        python3 \
        python3-yaml \
        rustc \
        scons \
        stress-ng \
        tar \
        unzip \
        util-linux \
        xz-utils \
        zlib1g-dev \
        zstd \
    && bpftool_bin="$(find /usr/lib/linux-tools -type f -name bpftool | sort -V | tail -n 1)" \
    && test -n "$bpftool_bin" \
    && ln -sf "$bpftool_bin" /usr/local/bin/bpftool \
    && rm -rf /var/lib/apt/lists/*

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

COPY . ${IMAGE_WORKSPACE}

WORKDIR ${IMAGE_WORKSPACE}

RUN make image-userspace-artifacts \
        RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" \
        RUN_SUITE_NEEDS_LLVMBPF=1 \
        BPFREJIT_IMAGE_BUILD=1 \
    && rm -rf /tmp/bpf-benchmark-build

ENV BPFREJIT_IMAGE_WORKSPACE=${IMAGE_WORKSPACE} \
    BPFREJIT_REPO_ARTIFACT_ROOT=/opt/bpf-benchmark/repo-artifacts/${RUN_TARGET_ARCH} \
    BPFREJIT_WORKLOAD_TOOL_BIN_DIR=/opt/bpf-benchmark/workload-tools/${RUN_TARGET_ARCH}/bin \
    PYTHONPATH=${IMAGE_WORKSPACE} \
    RUN_TARGET_ARCH=${RUN_TARGET_ARCH} \
    PATH=${IMAGE_WORKSPACE}/runner/build-llvmbpf:${IMAGE_WORKSPACE}/runner/build-arm64-llvmbpf:/opt/bpf-benchmark/repo-artifacts/${RUN_TARGET_ARCH}/bpftrace/bin:/opt/bpf-benchmark/workload-tools/${RUN_TARGET_ARCH}/bin:/usr/local/go/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

FROM runner-runtime AS runner-host-artifacts

ARG RUN_HOST_ARTIFACT_TARGET
ARG HOST_WORKSPACE_ROOT

RUN mkdir -p /image-output \
    && make image-host-artifacts \
        RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" \
        RUN_HOST_ARTIFACT_TARGET="${RUN_HOST_ARTIFACT_TARGET}" \
        HOST_ARTIFACT_OUTPUT_ROOT=/image-output \
        HOST_WORKSPACE_ROOT="${HOST_WORKSPACE_ROOT}" \
        BPFREJIT_IMAGE_BUILD=1 \
    && rm -rf /tmp/bpf-benchmark-build

FROM runner-runtime AS runner-default
