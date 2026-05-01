# syntax=docker/dockerfile:1.6
ARG TRACEE_IMAGE=docker.io/aquasec/tracee:0.24.1@sha256:cfbbfee972e64a644f6b1bac74ee26998e6e12442697be4c797ae563553a2a5b
ARG TETRAGON_IMAGE=quay.io/cilium/tetragon:v1.6.1@sha256:ff96ace3e6a0166ba04ff3eecfaeee19b7e6deee2b7cdbe3245feda57df5015f
ARG CILIUM_IMAGE=quay.io/cilium/cilium:v1.19.3@sha256:2e61680593cddca8b6c055f6d4c849d87a26a1c91c7e3b8b56c7fb76ab7b7b10
ARG CALICO_NODE_IMAGE=quay.io/calico/node:v3.31.3@sha256:f2339c4ff3a57228cbc39a1f67ab81abded1997d843e0e0b1e86664c7c4eb6c0
ARG RUN_TARGET_ARCH=x86_64
ARG VENDOR_LINUX_FRAMEWORK_COMMIT
ARG KERNEL_FORK_IMAGE_PLATFORM=linux/amd64

FROM docker.io/library/ubuntu:24.04 AS runner-runtime-runtime-base

ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        auditd \
        bash \
        bpfcc-tools \
        bpftrace \
        bzip2 \
        ca-certificates \
        clang \
        curl \
        debianutils \
        diffutils \
        elfutils \
        etcd-server \
        file \
        findutils \
        fio \
        ipset \
        iptables \
        iproute2 \
        jq \
        kmod \
        libaio1t64 \
        libboost-atomic1.83.0 \
        libboost-chrono1.83.0t64 \
        libboost-container1.83.0 \
        libboost-context1.83.0 \
        libboost-coroutine1.83.0 \
        libboost-date-time1.83.0 \
        libboost-fiber1.83.0 \
        libboost-filesystem1.83.0 \
        libboost-iostreams1.83.0 \
        libboost-json1.83.0 \
        libboost-locale1.83.0 \
        libboost-log1.83.0 \
        libboost-program-options1.83.0 \
        libboost-random1.83.0 \
        libboost-regex1.83.0 \
        libboost-serialization1.83.0 \
        libboost-stacktrace1.83.0 \
        libboost-system1.83.0 \
        libboost-thread1.83.0 \
        libboost-timer1.83.0 \
        libbpf1 \
        libbpfcc \
        libbz2-1.0 \
        libcap2 \
        libcurl4t64 \
        libdouble-conversion3 \
        libdw1t64 \
        libdwarf1 \
        libedit2 \
        libelf1t64 \
        libevent-2.1-7t64 \
        libfmt9 \
        libgflags2.2 \
        libgoogle-glog0v6t64 \
        libgrpc++1.51t64 \
        liblz4-1 \
        libmnl0 \
        libpcap0.8t64 \
        libprotobuf32t64 \
        libre2-10 \
        libsodium23 \
        libsnappy1v5 \
        libspdlog1.12 \
        libssl3t64 \
        libunwind8 \
        libyaml-cpp0.8 \
        libzstd1 \
        llvm \
        lz4 \
        nftables \
        openssl \
        perl \
        procps \
        python3 \
        python3-bpfcc \
        python3-yaml \
        rt-tests \
        stress-ng \
        tar \
        util-linux \
        wrk \
        xz-utils \
        zlib1g \
        zstd \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p "${IMAGE_WORKSPACE}"
WORKDIR ${IMAGE_WORKSPACE}

FROM runner-runtime-runtime-base AS runner-runtime-build-base

ARG GO_VERSION=1.26.0
ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        autoconf \
        automake \
        bc \
        binutils-dev \
        bison \
        build-essential \
        cmake \
        cpio \
        dwarves \
        flex \
        g++ \
        gcc \
        gcc-aarch64-linux-gnu \
        git \
        libaio-dev \
        libboost-all-dev \
        libbpf-dev \
        libbpfcc-dev \
        libbz2-dev \
        libcap-dev \
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
        libgrpc++-dev \
        libiberty-dev \
        liblz4-dev \
        libmnl-dev \
        libpcap-dev \
        libprotobuf-dev \
        libre2-dev \
        libsodium-dev \
        libsnappy-dev \
        libspdlog-dev \
        libssl-dev \
        libtool \
        libtool-bin \
        libltdl-dev \
        libunwind-dev \
        libyaml-cpp-dev \
        libzstd-dev \
        llvm-dev \
        make \
        pkg-config \
        protobuf-compiler \
        protobuf-compiler-grpc \
        rsync \
        scons \
        unzip \
        xxd \
        zlib1g-dev \
    && rm -rf /var/lib/apt/lists/*

RUN set -eux; \
    go_arch="$(dpkg --print-architecture)"; \
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

ARG RUST_VERSION=1.90.0

ENV RUSTUP_HOME=/opt/rustup \
    CARGO_HOME=/opt/cargo \
    PATH="/opt/cargo/bin:${PATH}"

RUN set -eux; \
    curl --proto '=https' --tlsv1.2 -fsSL https://sh.rustup.rs -o /tmp/rustup-init.sh; \
    sh /tmp/rustup-init.sh -y --no-modify-path --profile minimal --default-toolchain "${RUST_VERSION}"; \
    rm -f /tmp/rustup-init.sh; \
    chmod -R a+rX /opt/rustup /opt/cargo; \
    rustc --version; \
    cargo --version

FROM ${TRACEE_IMAGE} AS runner-runtime-tracee-upstream

FROM ${TETRAGON_IMAGE} AS runner-runtime-tetragon-upstream

FROM ${CILIUM_IMAGE} AS runner-runtime-cilium-upstream

FROM ${CALICO_NODE_IMAGE} AS runner-runtime-calico-upstream

FROM runner-runtime-build-base AS runner-runtime-app-artifacts

ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
ARG RUN_TARGET_ARCH=x86_64
ARG TARGETARCH
# The requested v0.120.0 asset is not published upstream; use the earliest
# verified official otelcol-ebpf-profiler release instead.
ARG OTELCOL_EBPF_PROFILER_VERSION=0.140.0

COPY --link --from=runner-runtime-tracee-upstream --chmod=0755 /tracee/tracee /artifacts/tracee/bin/tracee
COPY --link --from=runner-runtime-tracee-upstream --chmod=0755 /tracee/tracee-ebpf /artifacts/tracee/bin/tracee-ebpf
COPY --link --from=runner-runtime-tracee-upstream --chmod=0755 /lib/ld-musl-*.so.1 /lib/
COPY --link --from=runner-runtime-tracee-upstream /lib/libc.musl-*.so.1 /lib/
COPY --link --from=runner-runtime-tracee-upstream /usr/lib/libelf*.so* /usr/lib/
COPY --link --from=runner-runtime-tracee-upstream /usr/lib/libz.so* /usr/lib/
COPY --link --from=runner-runtime-tracee-upstream /usr/lib/libzstd.so* /usr/lib/

COPY --link --from=runner-runtime-tetragon-upstream --chmod=0755 /usr/bin/tetragon /artifacts/tetragon/bin/tetragon
COPY --link --from=runner-runtime-tetragon-upstream /var/lib/tetragon/ /artifacts/tetragon/

COPY --link --from=runner-runtime-katran-upstream /artifacts/katran /artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}/katran

COPY --link --from=runner-runtime-cilium-upstream --chmod=0755 /usr/bin/cilium-agent /usr/local/bin/cilium-agent
COPY --link --from=runner-runtime-cilium-upstream --chmod=0755 /usr/bin/cilium-dbg /usr/local/bin/cilium-dbg
COPY --link --from=runner-runtime-cilium-upstream --chmod=0755 /usr/bin/cilium-bugtool /usr/local/bin/cilium-bugtool
COPY --link --from=runner-runtime-cilium-upstream --chmod=0755 /usr/bin/cilium-health /usr/local/bin/cilium-health
COPY --link --from=runner-runtime-cilium-upstream --chmod=0755 /usr/bin/cilium-health-responder /usr/local/bin/cilium-health-responder
COPY --link --from=runner-runtime-cilium-upstream --chmod=0755 /usr/bin/cilium-mount /usr/local/bin/cilium-mount
COPY --link --from=runner-runtime-cilium-upstream --chmod=0755 /usr/bin/cilium-sysctlfix /usr/local/bin/cilium-sysctlfix
COPY --link --from=runner-runtime-cilium-upstream --chmod=0755 /usr/local/bin/clang /usr/local/bin/clang
COPY --link --from=runner-runtime-cilium-upstream --chmod=0755 /usr/local/bin/llc /usr/local/bin/llc
COPY --link --from=runner-runtime-cilium-upstream /var/lib/cilium/ /var/lib/cilium/

COPY --link --from=runner-runtime-calico-upstream --chmod=0755 /usr/bin/calico-node /usr/local/bin/calico-node
COPY --link --from=runner-runtime-calico-upstream /etc/calico/ /etc/calico/
COPY --link --from=runner-runtime-calico-upstream /usr/lib/calico/bpf/ /usr/lib/calico/bpf/
COPY --link --from=runner-runtime-calico-upstream /included-source/ /included-source/
COPY --link --from=runner-runtime-calico-upstream /usr/lib64/libpcap.so.1 /usr/local/lib/libpcap.so.1
COPY --link --from=runner-runtime-calico-upstream /usr/lib64/libpcap.so.1.9.1 /usr/local/lib/libpcap.so.1.9.1

COPY --chmod=0755 runner/scripts/bpfrejit-install /usr/local/bin/bpfrejit-install

RUN set -eux; \
    musl_loader="$(find /lib /usr/lib -maxdepth 1 -name 'ld-musl-*.so.1' -print -quit)"; \
    musl_arch="$(basename "${musl_loader}" | sed -e 's/^ld-musl-//' -e 's/\.so\.1$//')"; \
    musl_lib_dir="/usr/lib/${musl_arch}-linux-musl"; \
    mkdir -p "${musl_lib_dir}"; \
    cp -a /usr/lib/libelf*.so* /usr/lib/libz.so* /usr/lib/libzstd.so* /usr/lib/libc.musl-*.so.1 "${musl_lib_dir}/"; \
    ldconfig; \
    command -v etcd >/dev/null; \
    etcd --version >/dev/null; \
    command -v iptables >/dev/null; \
    command -v iptables-save >/dev/null; \
    command -v ip6tables-save >/dev/null; \
    command -v ipset >/dev/null; \
    command -v nft >/dev/null; \
    test -x /usr/local/bin/cilium-agent; \
    test -x /usr/local/bin/calico-node; \
    test -x /usr/local/bin/clang; \
    test -x /usr/local/bin/llc; \
    test -d /var/lib/cilium/bpf; \
    test -d /usr/lib/calico/bpf; \
    test -f /usr/lib/calico/bpf/common_map_stub.o; \
    test -f /usr/lib/calico/bpf/xdp_preamble.o; \
    test -f /usr/local/lib/libpcap.so.1; \
    test -x "/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}/katran/bin/katran_server_grpc"; \
    test -f "/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}/katran/bpf/balancer.bpf.o"; \
    image_arch="${TARGETARCH}"; \
    if [ -z "${image_arch}" ]; then image_arch="$(dpkg --print-architecture)"; fi; \
    case "${image_arch}" in \
        amd64|x86_64) otel_arch=amd64 ;; \
        arm64|aarch64) otel_arch=arm64 ;; \
        *) echo "unsupported runtime arch for otelcol-ebpf-profiler: ${image_arch}" >&2; exit 1 ;; \
    esac; \
    otel_tar="/tmp/otelcol-ebpf-profiler_${OTELCOL_EBPF_PROFILER_VERSION}_linux_${otel_arch}.tar.gz"; \
    curl -fsSL "https://github.com/open-telemetry/opentelemetry-collector-releases/releases/download/v${OTELCOL_EBPF_PROFILER_VERSION}/otelcol-ebpf-profiler_${OTELCOL_EBPF_PROFILER_VERSION}_linux_${otel_arch}.tar.gz" -o "${otel_tar}"; \
    tar -C /usr/local/bin -xzf "${otel_tar}" otelcol-ebpf-profiler; \
    rm -f "${otel_tar}"; \
    test -x /usr/local/bin/otelcol-ebpf-profiler; \
    mkdir -p /opt; \
    ln -sfn /artifacts/user /opt/bpf-benchmark; \
    repo_artifact_root="/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}"; \
    mkdir -p \
        "${repo_artifact_root}" \
        "${repo_artifact_root}/calico/bin" \
        "${repo_artifact_root}/cilium/bin" \
        "${repo_artifact_root}/otelcol-ebpf-profiler/bin"; \
    ln -sfn /artifacts/tracee "${repo_artifact_root}/tracee"; \
    ln -sfn /artifacts/tetragon "${repo_artifact_root}/tetragon"; \
    ln -sfn /artifacts/tracee/bin/tracee /usr/local/bin/tracee; \
    ln -sfn /artifacts/tetragon/bin/tetragon /usr/local/bin/tetragon; \
    ln -sfn /usr/local/bin/calico-node "${repo_artifact_root}/calico/bin/calico-node"; \
    ln -sfn /usr/local/bin/cilium-agent "${repo_artifact_root}/cilium/bin/cilium-agent"; \
    ln -sfn /usr/local/bin/cilium-dbg "${repo_artifact_root}/cilium/bin/cilium-dbg"; \
    ln -sfn /usr/local/bin/otelcol-ebpf-profiler "${repo_artifact_root}/otelcol-ebpf-profiler/bin/otelcol-ebpf-profiler"

FROM --platform=${KERNEL_FORK_IMAGE_PLATFORM} bpf-benchmark/kernel-fork:${RUN_TARGET_ARCH}-${VENDOR_LINUX_FRAMEWORK_COMMIT} AS runner-runtime-kernel-base

FROM runner-runtime-app-artifacts AS runner-runtime-artifacts

ARG IMAGE_BUILD_JOBS=4
ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
ARG RUN_TARGET_ARCH=x86_64

COPY --link --from=runner-runtime-kernel-base /artifacts/kernel /artifacts/kernel
COPY --link --from=runner-runtime-kernel-base /artifacts/modules /artifacts/modules
COPY --link --from=runner-runtime-kernel-base /artifacts/headers /usr/src/linux-headers-fork
COPY --link --from=runner-runtime-kernel-base /artifacts/manifest.json /artifacts/manifest.json

COPY Makefile ./Makefile
COPY runner/mk ./runner/mk
COPY vendor/libbpf ./vendor/libbpf
COPY vendor/llvmbpf ./vendor/llvmbpf
COPY vendor/linux-framework/Makefile ./vendor/linux-framework/Makefile
COPY vendor/linux-framework/include ./vendor/linux-framework/include
COPY vendor/linux-framework/arch/arm64/include/uapi/asm ./vendor/linux-framework/arch/arm64/include/uapi/asm
COPY vendor/linux-framework/scripts ./vendor/linux-framework/scripts
COPY vendor/linux-framework/kernel/bpf ./vendor/linux-framework/kernel/bpf
COPY vendor/linux-framework/tools/arch ./vendor/linux-framework/tools/arch
COPY vendor/linux-framework/tools/bpf/bpftool ./vendor/linux-framework/tools/bpf/bpftool
COPY vendor/linux-framework/tools/build ./vendor/linux-framework/tools/build
COPY vendor/linux-framework/tools/include ./vendor/linux-framework/tools/include
COPY vendor/linux-framework/tools/lib ./vendor/linux-framework/tools/lib
COPY vendor/linux-framework/tools/scripts ./vendor/linux-framework/tools/scripts
COPY runner/CMakeLists.txt ./runner/CMakeLists.txt
COPY runner/include ./runner/include
COPY runner/src ./runner/src
COPY micro/programs ./micro/programs
COPY tests/unittest ./tests/unittest
COPY tests/negative ./tests/negative

RUN set -eux; \
    make -C vendor/linux-framework/tools/bpf/bpftool \
        VMLINUX_BTF= \
        feature-llvm=0 \
        feature-libbfd=0 \
        feature-libbfd-liberty=0 \
        feature-libbfd-liberty-z=0 \
        -j"${IMAGE_BUILD_JOBS}"; \
    install -m 0755 vendor/linux-framework/tools/bpf/bpftool/bpftool /usr/local/bin/bpftool; \
    bpftool version; \
    make image-runner-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    CLANG=/usr/bin/clang make image-micro-program-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    PATH="/usr/bin:${PATH}" make image-test-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    rm -rf \
        /tmp/bpf-benchmark-build \
        ./vendor \
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
        ./tests/negative/*.h; \
    find ./runner -maxdepth 3 -type d \( -name CMakeFiles -o -name vendor \) -prune -exec rm -rf {} +; \
    find ./runner -maxdepth 3 -type f \( -name CMakeCache.txt -o -name cmake_install.cmake -o -name Makefile \) -delete; \
    find ./tests -type f \( \( -name '*.o' ! -name '*.bpf.o' \) -o -name '*.d' -o -name '*.cmd' \) -delete

FROM --platform=${KERNEL_FORK_IMAGE_PLATFORM} runner-runtime-build-base AS runner-runtime-kinsn-artifacts

ARG IMAGE_BUILD_JOBS=4
ARG KERNEL_FORK_IMAGE_PLATFORM=linux/amd64
ARG RUN_TARGET_ARCH=x86_64

WORKDIR /src

COPY --link --from=runner-runtime-kernel-base /artifacts /artifacts
COPY module ./module

RUN --mount=type=cache,target=/tmp/kinsn-build,id=kinsn-build-${RUN_TARGET_ARCH},sharing=locked <<'EOF'
set -eux

case "${IMAGE_BUILD_JOBS}" in
    ''|*[!0-9]*|0)
        echo "IMAGE_BUILD_JOBS must be a positive integer: ${IMAGE_BUILD_JOBS}" >&2
        exit 1
        ;;
esac

case "${RUN_TARGET_ARCH}" in
    x86_64)
        kernel_arch=x86_64
        module_arch=x86
        cross_compile=
        expected_modules=6
        ;;
    arm64)
        kernel_arch=arm64
        module_arch=arm64
        cross_compile=aarch64-linux-gnu-
        expected_modules=8
        command -v aarch64-linux-gnu-gcc >/dev/null
        ;;
    *)
        echo "unsupported RUN_TARGET_ARCH: ${RUN_TARGET_ARCH}" >&2
        exit 1
        ;;
esac

mkdir -p /tmp/kinsn-build /artifacts/kinsn
find /tmp/kinsn-build -mindepth 1 -maxdepth 1 -exec rm -rf {} +
find ./module -type f \( \
    -name '*.ko' -o -name '*.o' -o -name '*.mod' -o -name '*.mod.c' \
    -o -name '*.cmd' -o -name 'Module.symvers' -o -name 'modules.order' \
\) -delete

make_args="ARCH=${kernel_arch}"
if [ -n "${cross_compile}" ]; then
    make_args="${make_args} CROSS_COMPILE=${cross_compile}"
fi

make -C /artifacts/headers ${make_args} M="${PWD}/module/${module_arch}" MO=/tmp/kinsn-build modules -j"${IMAGE_BUILD_JOBS}"
install -m 0644 /tmp/kinsn-build/*.ko /artifacts/kinsn/
module_count="$(find /artifacts/kinsn -maxdepth 1 -type f -name '*.ko' | wc -l)"
test "${module_count}" -eq "${expected_modules}"
for ko_path in /artifacts/kinsn/*.ko; do
    readelf -S "${ko_path}" | awk '$2 == ".BTF" { found = 1 } END { exit(found ? 0 : 1) }'
done
EOF

FROM runner-runtime-build-base AS runner-runtime-daemon-artifact

ARG IMAGE_BUILD_JOBS=4
ARG RUN_TARGET_ARCH=x86_64

COPY Makefile ./Makefile
COPY runner/mk ./runner/mk
COPY bpfopt/Cargo.toml bpfopt/Cargo.lock ./bpfopt/
COPY bpfopt/crates/kernel-sys ./bpfopt/crates/kernel-sys
COPY daemon ./daemon

# Build the daemon against kernel-sys without copying the rest of bpfopt.
RUN --mount=type=cache,target=/bpfopt/target,id=bpfopt-cargo-target,sharing=locked \
    --mount=type=cache,target=/opt/cargo/registry,id=opt-cargo-registry,sharing=locked \
    --mount=type=cache,target=/opt/cargo/git,id=opt-cargo-git,sharing=locked \
    set -eux; \
    mkdir -p ./vendor/linux-framework; \
    touch ./vendor/linux-framework/Makefile; \
    ln -sfn /bpfopt/target ./daemon/target; \
    make image-daemon-artifact RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    daemon_bin_dir="/bpfopt/target/release"; \
    daemon_image_dir="/artifacts/rust/daemon/target/release"; \
    if [ "${RUN_TARGET_ARCH}" = "arm64" ]; then \
        daemon_bin_dir="/bpfopt/target/aarch64-unknown-linux-gnu/release"; \
        daemon_image_dir="/artifacts/rust/daemon/target/aarch64-unknown-linux-gnu/release"; \
    fi; \
    install -d /artifacts/rust/usr-local-bin "${daemon_image_dir}"; \
    install -m 0755 "${daemon_bin_dir}/bpfrejit-daemon" /artifacts/rust/usr-local-bin/bpfrejit-daemon; \
    install -m 0755 "${daemon_bin_dir}/bpfrejit-daemon" "${daemon_image_dir}/bpfrejit-daemon"

FROM runner-runtime-build-base AS runner-runtime-bpfopt-artifacts

ARG IMAGE_BUILD_JOBS=4
ARG RUN_TARGET_ARCH=x86_64

COPY Makefile ./Makefile
COPY runner/mk ./runner/mk
COPY bpfopt/Cargo.toml bpfopt/Cargo.lock ./bpfopt/
COPY bpfopt/crates/bpfopt ./bpfopt/crates/bpfopt
COPY bpfopt/crates/bpfprof ./bpfopt/crates/bpfprof
COPY bpfopt/crates/kernel-sys ./bpfopt/crates/kernel-sys

# Build bpfopt-suite CLIs in this upper layer; kernel-sys is a library crate only.
RUN --mount=type=cache,target=/bpfopt/target,id=bpfopt-cargo-target,sharing=locked \
    --mount=type=cache,target=/opt/cargo/registry,id=opt-cargo-registry,sharing=locked \
    --mount=type=cache,target=/opt/cargo/git,id=opt-cargo-git,sharing=locked \
    set -eux; \
    mkdir -p ./vendor/linux-framework; \
    touch ./vendor/linux-framework/Makefile; \
    ln -sfn /bpfopt/target ./bpfopt/target; \
    make image-bpfopt-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    bpfopt_bin_dir="./bpfopt/target/release"; \
    if [ "${RUN_TARGET_ARCH}" = "arm64" ]; then bpfopt_bin_dir="./bpfopt/target/aarch64-unknown-linux-gnu/release"; fi; \
    install -d /artifacts/rust/usr-local-bin; \
    install -m 0755 \
        "$bpfopt_bin_dir/bpfopt" \
        "$bpfopt_bin_dir/bpfprof" \
        /artifacts/rust/usr-local-bin/

FROM runner-runtime-runtime-base AS runner-runtime

ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
ARG RUN_TARGET_ARCH=x86_64

COPY --link --from=runner-runtime-artifacts /artifacts /artifacts
COPY --link --from=runner-runtime-artifacts /usr/local/bin/ /usr/local/bin/
COPY --link --from=runner-runtime-artifacts /usr/local/lib/ /usr/local/lib/
COPY --link --from=runner-runtime-artifacts /lib/ld-musl-*.so.1 /lib/
COPY --link --from=runner-runtime-artifacts /lib/libc.musl-*.so.1 /lib/
COPY --link --from=runner-runtime-artifacts /usr/lib/*-linux-musl/ /usr/lib/
COPY --link --from=runner-runtime-artifacts /var/lib/cilium /var/lib/cilium
COPY --link --from=runner-runtime-artifacts /etc/calico /etc/calico
COPY --link --from=runner-runtime-artifacts /usr/lib/calico /usr/lib/calico
COPY --link --from=runner-runtime-artifacts /included-source /included-source
COPY --link --from=runner-runtime-artifacts ${IMAGE_WORKSPACE}/runner ${IMAGE_WORKSPACE}/runner
COPY --link --from=runner-runtime-artifacts ${IMAGE_WORKSPACE}/tests ${IMAGE_WORKSPACE}/tests
COPY --link --from=runner-runtime-kinsn-artifacts /artifacts/kinsn /artifacts/kinsn
COPY --link --from=runner-runtime-daemon-artifact /artifacts/rust/usr-local-bin/bpfrejit-daemon /usr/local/bin/bpfrejit-daemon
COPY --link --from=runner-runtime-daemon-artifact /artifacts/rust/daemon/target/ ./daemon/target/
COPY --link --from=runner-runtime-bpfopt-artifacts /artifacts/rust/usr-local-bin/ /usr/local/bin/

RUN set -eux; \
    mkdir -p /opt; \
    ln -sfn /artifacts/user /opt/bpf-benchmark; \
    ldconfig; \
    test -x /usr/local/bin/bpftool; \
    test -x /usr/local/bin/bpfrejit-daemon; \
    test -x /usr/local/bin/bpfopt; \
    test -x /usr/local/bin/bpfprof; \
    test -x /usr/local/bin/cilium-agent; \
    test -x /usr/local/bin/calico-node; \
    test -d /artifacts/kernel; \
    test -d /artifacts/modules; \
    test -d /artifacts/kinsn; \
    test -x "/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}/katran/bin/katran_server_grpc"; \
    case "${RUN_TARGET_ARCH}" in \
        x86_64) test -x "${IMAGE_WORKSPACE}/runner/build-llvmbpf/micro_exec"; test -d "${IMAGE_WORKSPACE}/tests/unittest/build/progs" ;; \
        arm64) test -x "${IMAGE_WORKSPACE}/runner/build-arm64-llvmbpf/micro_exec"; test -d "${IMAGE_WORKSPACE}/tests/unittest/build-arm64/progs" ;; \
        *) echo "unsupported RUN_TARGET_ARCH: ${RUN_TARGET_ARCH}" >&2; exit 1 ;; \
    esac

COPY --link corpus/bcf ./corpus/bcf
COPY --link e2e/cases ./e2e/cases
COPY runner/__init__.py runner/repos.yaml ./runner/
COPY runner/libs ./runner/libs
COPY runner/suites ./runner/suites
COPY runner/targets ./runner/targets
COPY micro/*.py ./micro/
COPY micro/config ./micro/config
COPY corpus/*.py ./corpus/
COPY corpus/config ./corpus/config
COPY corpus/inputs ./corpus/inputs
COPY e2e/*.py ./e2e/

RUN set -eux; \
    find ./runner ./micro ./corpus ./e2e -type d -name __pycache__ -prune -exec rm -rf {} +; \
    find ./e2e/cases/tetragon/policies -type f \( -name '*.yaml' -o -name '*.yml' \) | grep -q .; \
    mkdir -p micro/results corpus/results e2e/results tests/results /var/tmp/bpfrejit-runtime

RUN <<'EOF'
set -eux
cat > /usr/local/bin/bpfrejit-runtime-entrypoint <<'SCRIPT'
#!/usr/bin/env bash
set -euo pipefail

suite_results=""
previous_arg=""
for arg in "$@"; do
    if [ "$previous_arg" = "-m" ]; then
        case "$arg" in
            runner.suites.micro) suite_results="micro/results" ;;
            runner.suites.corpus) suite_results="corpus/results" ;;
            runner.suites.e2e) suite_results="e2e/results" ;;
            runner.suites.test) suite_results="tests/results" ;;
        esac
        break
    fi
    previous_arg="$arg"
done

if [ -z "${BPFREJIT_DAEMON_FAILURE_ROOT:-}" ] && [ -n "$suite_results" ]; then
    workspace="${BPFREJIT_IMAGE_WORKSPACE:-/workspace}"
    export BPFREJIT_DAEMON_FAILURE_ROOT="${workspace}/${suite_results}"
fi

if [ -n "${BPFREJIT_DAEMON_FAILURE_ROOT:-}" ]; then
    mkdir -p "$BPFREJIT_DAEMON_FAILURE_ROOT"
    probe="${BPFREJIT_DAEMON_FAILURE_ROOT}/.bpfrejit-write-probe.$$"
    if ! : > "$probe"; then
        printf 'bpfrejit-runtime-entrypoint: failure root is not writable: %s\n' "$BPFREJIT_DAEMON_FAILURE_ROOT" >&2
        exit 1
    fi
    rm "$probe"
fi

exec "$@"
SCRIPT
chmod +x /usr/local/bin/bpfrejit-runtime-entrypoint
EOF

ENV BPFREJIT_IMAGE_WORKSPACE=${IMAGE_WORKSPACE} \
    BPFREJIT_REPO_ARTIFACT_ROOT=/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH} \
    PYTHONPATH=${IMAGE_WORKSPACE} \
    RUN_TARGET_ARCH=${RUN_TARGET_ARCH} \
    PATH=${IMAGE_WORKSPACE}/runner/build-llvmbpf:${IMAGE_WORKSPACE}/runner/build-arm64-llvmbpf:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

ENTRYPOINT ["/usr/local/bin/bpfrejit-runtime-entrypoint"]

FROM runner-runtime AS runner-default
