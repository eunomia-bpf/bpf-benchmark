# syntax=docker/dockerfile:1.4
FROM docker.io/library/ubuntu:24.04 AS runner-runtime-userspace

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

RUN mkdir -p "${IMAGE_WORKSPACE}"
WORKDIR ${IMAGE_WORKSPACE}

COPY vendor/libbpf ./vendor/libbpf
COPY vendor/llvmbpf ./vendor/llvmbpf
COPY vendor/linux-framework/Makefile ./vendor/linux-framework/
COPY vendor/linux-framework/include ./vendor/linux-framework/include
COPY vendor/linux-framework/scripts ./vendor/linux-framework/scripts
COPY vendor/linux-framework/tools/bpf/bpftool ./vendor/linux-framework/tools/bpf/bpftool
COPY vendor/linux-framework/tools/build ./vendor/linux-framework/tools/build
COPY vendor/linux-framework/tools/include ./vendor/linux-framework/tools/include
COPY vendor/linux-framework/tools/lib ./vendor/linux-framework/tools/lib
COPY vendor/linux-framework/tools/sched_ext/include ./vendor/linux-framework/tools/sched_ext/include
COPY vendor/linux-framework/tools/scripts ./vendor/linux-framework/tools/scripts

COPY Makefile ./
COPY runner/mk ./runner/mk

COPY runner/repos/bcc ./runner/repos/bcc
RUN make image-bcc-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1

COPY runner/repos/bpftrace ./runner/repos/bpftrace
RUN make image-bpftrace-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1

COPY runner/repos/katran ./runner/repos/katran
RUN make image-katran-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1

COPY runner/repos/tracee ./runner/repos/tracee
RUN make image-tracee-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1

COPY runner/repos/tetragon ./runner/repos/tetragon
RUN make image-tetragon-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1

COPY runner/repos/scx ./runner/repos/scx
RUN make image-scx-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1

COPY runner/repos/workload-tools ./runner/repos/workload-tools
RUN make image-workload-tools-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1

COPY runner/CMakeLists.txt ./runner/
COPY runner/include ./runner/include
COPY runner/src ./runner/src
RUN make image-runner-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1

COPY micro/programs ./micro/programs
RUN make image-micro-program-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1

COPY tests/unittest ./tests/unittest
COPY tests/negative ./tests/negative
RUN make image-test-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1

RUN rm -rf \
        /tmp/bpf-benchmark-build \
        ./runner/repos \
        ./runner/src \
        ./runner/include \
        ./runner/CMakeLists.txt \
        ./micro/programs \
        ./tests/unittest/Makefile \
        ./tests/unittest/module \
        ./tests/unittest/progs \
        ./tests/unittest/*.c \
        ./tests/unittest/*.h \
        ./tests/negative/Makefile \
        ./tests/negative/*.c \
        ./tests/negative/*.h \
    && find ./runner -maxdepth 3 -type d \( -name CMakeFiles -o -name vendor \) -prune -exec rm -rf {} + \
    && find ./runner -maxdepth 3 -type f \( -name CMakeCache.txt -o -name cmake_install.cmake -o -name Makefile \) -delete \
    && find ./tests -type f \( -name '*.o' -o -name '*.d' -o -name '*.cmd' \) -delete

COPY micro/generated-inputs ./micro/generated-inputs
COPY corpus/bcf ./corpus/bcf
COPY corpus/inputs ./corpus/inputs

COPY daemon ./daemon
RUN make image-daemon-artifact RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 \
    && find ./daemon/target -type d \( -name build -o -name deps -o -name incremental -o -name .fingerprint \) -prune -exec rm -rf {} + \
    && rm -rf \
        ./Makefile \
        ./runner/mk \
        ./vendor \
        ./daemon/src \
        ./daemon/tests \
        ./daemon/Cargo.toml \
        ./daemon/Cargo.lock \
        ./daemon/Makefile \
        ./daemon/README.md

COPY micro/config ./micro/config
COPY micro/*.py ./micro/
COPY corpus/config ./corpus/config
COPY corpus/*.py ./corpus/
COPY e2e/cases ./e2e/cases
COPY e2e/*.py ./e2e/
COPY runner/__init__.py runner/repos.yaml ./runner/
COPY runner/libs ./runner/libs
COPY runner/suites ./runner/suites
COPY runner/targets ./runner/targets

RUN mkdir -p micro/results corpus/results e2e/results tests/results

ENV BPFREJIT_IMAGE_WORKSPACE=${IMAGE_WORKSPACE} \
    BPFREJIT_REPO_ARTIFACT_ROOT=/opt/bpf-benchmark/repo-artifacts/${RUN_TARGET_ARCH} \
    BPFREJIT_WORKLOAD_TOOL_BIN_DIR=/opt/bpf-benchmark/workload-tools/${RUN_TARGET_ARCH}/bin \
    PYTHONPATH=${IMAGE_WORKSPACE} \
    RUN_TARGET_ARCH=${RUN_TARGET_ARCH} \
    PATH=${IMAGE_WORKSPACE}/runner/build-llvmbpf:${IMAGE_WORKSPACE}/runner/build-arm64-llvmbpf:/opt/bpf-benchmark/repo-artifacts/${RUN_TARGET_ARCH}/bpftrace/bin:/opt/bpf-benchmark/workload-tools/${RUN_TARGET_ARCH}/bin:/usr/local/go/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

FROM runner-runtime-userspace AS runner-runtime

ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
ARG RUN_TARGET_ARCH=x86_64

COPY Makefile ./
COPY runner/mk ./runner/mk
COPY vendor/linux-framework ./vendor/linux-framework
COPY vendor/bpfrejit_x86_defconfig vendor/bpfrejit_arm64_defconfig ./vendor/
COPY module ./module

RUN make image-runtime-kinsn-artifacts \
        RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" \
        HOST_ARTIFACT_OUTPUT_ROOT="${IMAGE_WORKSPACE}" \
        BPFREJIT_IMAGE_BUILD=1 \
    && find ./module -mindepth 2 -type f ! -name '*.ko' -delete \
    && find ./module -mindepth 1 -type d -empty -delete \
    && rm -rf \
        /tmp/bpf-benchmark-build \
        /root/.cache/go-build \
        /root/go \
        /usr/local/go \
        ./.cache \
        ./Makefile \
        ./runner/mk \
        ./vendor \
    && apt-get purge -y \
        autoconf \
        automake \
        bc \
        binutils-dev \
        bison \
        cargo \
        clang \
        cmake \
        dwarves \
        flex \
        g++ \
        gcc \
        git \
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
        llvm \
        llvm-dev \
        make \
        pkg-config \
        rustc \
        scons \
        unzip \
        zlib1g-dev \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

ENV PATH=${IMAGE_WORKSPACE}/runner/build-llvmbpf:${IMAGE_WORKSPACE}/runner/build-arm64-llvmbpf:/opt/bpf-benchmark/repo-artifacts/${RUN_TARGET_ARCH}/bpftrace/bin:/opt/bpf-benchmark/workload-tools/${RUN_TARGET_ARCH}/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

FROM runner-runtime-userspace AS runner-host-artifacts-build

ARG RUN_HOST_ARTIFACT_TARGET
ARG HOST_WORKSPACE_ROOT

COPY Makefile ./
COPY runner/mk ./runner/mk
COPY vendor/linux-framework ./vendor/linux-framework
COPY vendor/bpfrejit_x86_defconfig vendor/bpfrejit_arm64_defconfig ./vendor/
COPY module ./module

RUN mkdir -p /image-output \
    && make image-host-artifacts \
        RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" \
        RUN_HOST_ARTIFACT_TARGET="${RUN_HOST_ARTIFACT_TARGET}" \
        HOST_ARTIFACT_OUTPUT_ROOT=/image-output \
        HOST_WORKSPACE_ROOT="${HOST_WORKSPACE_ROOT}" \
        BPFREJIT_IMAGE_BUILD=1 \
    && rm -rf /tmp/bpf-benchmark-build

FROM scratch AS runner-host-artifacts
COPY --from=runner-host-artifacts-build /image-output/ /

FROM runner-runtime AS runner-default
