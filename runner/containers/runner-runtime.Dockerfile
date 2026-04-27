# syntax=docker/dockerfile:1.4
ARG TRACEE_IMAGE=docker.io/aquasec/tracee:0.24.1@sha256:cfbbfee972e64a644f6b1bac74ee26998e6e12442697be4c797ae563553a2a5b
ARG TETRAGON_IMAGE=quay.io/cilium/tetragon:v1.6.1@sha256:ff96ace3e6a0166ba04ff3eecfaeee19b7e6deee2b7cdbe3245feda57df5015f
ARG CILIUM_IMAGE=quay.io/cilium/cilium:v1.19.3@sha256:2e61680593cddca8b6c055f6d4c849d87a26a1c91c7e3b8b56c7fb76ab7b7b10
ARG CALICO_NODE_IMAGE=quay.io/calico/node:v3.31.3@sha256:f2339c4ff3a57228cbc39a1f67ab81abded1997d843e0e0b1e86664c7c4eb6c0
FROM docker.io/library/ubuntu:24.04 AS runner-runtime-build-base

ARG GO_VERSION=1.26.0
ARG IMAGE_BUILD_JOBS=4
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
        bpftrace \
        bzip2 \
        ca-certificates \
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
        ipset \
        iptables \
        iproute2 \
        kmod \
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
        libiberty-dev \
        liblz4-dev \
        libmnl-dev \
        libpcap-dev \
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
        llvm \
        llvm-dev \
        lz4 \
        make \
        openssl \
        perl \
        pkg-config \
        procps \
        python3 \
        python3-bpfcc \
        python3-yaml \
        rsync \
        rt-tests \
        scons \
        stress-ng \
        tar \
        unzip \
        util-linux \
        wrk \
        xz-utils \
        xxd \
        zlib1g-dev \
        zstd \
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

RUN mkdir -p "${IMAGE_WORKSPACE}"
WORKDIR ${IMAGE_WORKSPACE}

ARG TARGETPLATFORM

FROM --platform=$TARGETPLATFORM ${TRACEE_IMAGE} AS runner-runtime-tracee-upstream

FROM --platform=$TARGETPLATFORM ${TETRAGON_IMAGE} AS runner-runtime-tetragon-upstream

FROM --platform=$TARGETPLATFORM ${CILIUM_IMAGE} AS runner-runtime-cilium-upstream

FROM --platform=$TARGETPLATFORM ${CALICO_NODE_IMAGE} AS runner-runtime-calico-upstream

FROM runner-runtime-build-base AS runner-runtime-userspace

ARG IMAGE_BUILD_JOBS=4
ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
ARG RUN_TARGET_ARCH=x86_64

RUN --mount=type=bind,source=.,target=/src,readonly \
    set -eux; \
    cp -a /src/Makefile ./Makefile; \
    mkdir -p ./runner ./vendor ./vendor/linux-framework; \
    rsync -a /src/runner/mk ./runner/; \
    mkdir -p ./runner/repos; \
    if [ -d /src/runner/repos/katran ]; then rsync -a /src/runner/repos/katran ./runner/repos/; fi; \
    has_repo_content() { [ -n "$(find "./runner/repos/$1" -mindepth 1 -maxdepth 1 -print -quit 2>/dev/null)" ]; }; \
    clone_sparse_repo() { \
        repo_name="$1"; repo_url="$2"; repo_branch="$3"; shift 3; \
        repo_dest="./runner/repos/${repo_name}"; \
        rm -rf "${repo_dest}"; \
        git clone --depth 1 --filter=blob:none --sparse --branch "${repo_branch}" "${repo_url}" "${repo_dest}"; \
        (cd "${repo_dest}" && git sparse-checkout set --no-cone "$@"); \
    }; \
    has_repo_content katran || clone_sparse_repo katran https://github.com/facebookincubator/katran.git main \
        /CMakeLists.txt build /build_bpf_modules_opensource.sh /build_katran.sh cmake example_grpc katran/decap katran/lib; \
    rsync -a /src/vendor/libbpf ./vendor/; \
    rsync -a /src/vendor/llvmbpf ./vendor/; \
    cp -a /src/vendor/linux-framework/Makefile ./vendor/linux-framework/; \
    for path in \
        include \
        arch/arm64/include/uapi/asm \
        scripts \
        kernel/bpf \
        tools/arch \
        tools/bpf/bpftool \
        tools/build \
        tools/include \
        tools/lib \
        tools/scripts; \
    do \
        mkdir -p "./vendor/linux-framework/$(dirname "$path")"; \
        rsync -a "/src/vendor/linux-framework/$path" "./vendor/linux-framework/$(dirname "$path")/"; \
    done; \
    make -C vendor/linux-framework/tools/bpf/bpftool \
        VMLINUX_BTF= \
        feature-llvm=0 \
        feature-libbfd=0 \
        feature-libbfd-liberty=0 \
        feature-libbfd-liberty-z=0 \
        -j"${IMAGE_BUILD_JOBS}"; \
    install -m 0755 vendor/linux-framework/tools/bpf/bpftool/bpftool /usr/local/bin/bpftool; \
    bpftool version; \
    make image-katran-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    rm -rf \
        /tmp/bpf-benchmark-build \
        ./Makefile \
        ./runner/mk \
        ./vendor \
        ./runner/repos

COPY --from=runner-runtime-tracee-upstream --chmod=0755 /tracee/tracee /artifacts/tracee/bin/tracee
COPY --from=runner-runtime-tracee-upstream --chmod=0755 /tracee/tracee-ebpf /artifacts/tracee/bin/tracee-ebpf
COPY --from=runner-runtime-tracee-upstream --chmod=0755 /lib/ld-musl-*.so.1 /lib/
COPY --from=runner-runtime-tracee-upstream /lib/libc.musl-*.so.1 /lib/
COPY --from=runner-runtime-tracee-upstream /usr/lib/libelf*.so* /usr/lib/
COPY --from=runner-runtime-tracee-upstream /usr/lib/libz.so* /usr/lib/
COPY --from=runner-runtime-tracee-upstream /usr/lib/libzstd.so* /usr/lib/
RUN set -eux; \
    musl_loader="$(find /lib /usr/lib -maxdepth 1 -name 'ld-musl-*.so.1' -print -quit)"; \
    musl_arch="$(basename "${musl_loader}" | sed -e 's/^ld-musl-//' -e 's/\.so\.1$//')"; \
    musl_lib_dir="/usr/lib/${musl_arch}-linux-musl"; \
    mkdir -p "${musl_lib_dir}"; \
    cp -a /usr/lib/libelf*.so* /usr/lib/libz.so* /usr/lib/libzstd.so* /usr/lib/libc.musl-*.so.1 "${musl_lib_dir}/"
COPY --from=runner-runtime-tetragon-upstream --chmod=0755 /usr/bin/tetragon /artifacts/tetragon/bin/tetragon
COPY --from=runner-runtime-tetragon-upstream /var/lib/tetragon/ /artifacts/tetragon/

FROM runner-runtime-build-base AS runner-runtime-kernel-artifacts

ARG IMAGE_BUILD_JOBS=4
ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
ARG RUN_TARGET_ARCH=x86_64

RUN apt-get update \
    && apt-get install -y --no-install-recommends bsdextrautils \
    && rm -rf /var/lib/apt/lists/*

RUN --mount=type=bind,source=.,target=/src,readonly \
    set -eux; \
    cp -a /src/Makefile ./Makefile; \
    mkdir -p ./runner ./vendor /artifacts; \
    rsync -a /src/runner/mk ./runner/; \
    ln -sfn /src/vendor/linux-framework ./vendor/linux-framework; \
    cp -a /src/vendor/bpfrejit_x86_defconfig /src/vendor/bpfrejit_arm64_defconfig ./vendor/; \
    rsync -a \
        --exclude='*.ko' \
        --exclude='*.mod.c' \
        --exclude='*.mod' \
        --exclude='Module.symvers' \
        --exclude='modules.order' \
        --exclude='*.o' \
        --exclude='.*.o' \
        --exclude='*.cmd' \
        --exclude='.*.cmd' \
        --exclude='.tmp_versions/' \
        /src/module ./; \
    make image-kernel-artifacts \
        RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" \
        BPFREJIT_IMAGE_BUILD=1 \
        JOBS="${IMAGE_BUILD_JOBS}"; \
    rm -rf \
        /tmp/bpf-benchmark-build \
        ./Makefile \
        ./runner/mk \
        ./vendor \
        ./module

FROM runner-runtime-userspace AS runner-runtime

ARG IMAGE_BUILD_JOBS=4
ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
ARG RUN_TARGET_ARCH=x86_64
ARG TARGETARCH
# The requested v0.120.0 asset is not published upstream; use the earliest
# verified official otelcol-ebpf-profiler release instead.
ARG OTELCOL_EBPF_PROFILER_VERSION=0.140.0

RUN --mount=type=bind,source=.,target=/src,readonly \
    set -eux; \
    cp -a /src/Makefile ./Makefile; \
    mkdir -p ./runner ./vendor ./vendor/linux-framework ./micro ./corpus ./e2e ./e2e/cases/tetragon ./tests; \
    rsync -a /src/runner/mk ./runner/; \
    rsync -a /src/vendor/libbpf ./vendor/; \
    rsync -a /src/vendor/llvmbpf ./vendor/; \
    cp -a /src/vendor/linux-framework/Makefile ./vendor/linux-framework/; \
    for path in \
        include \
        arch/arm64/include/uapi/asm \
        scripts \
        kernel/bpf \
        tools/arch \
        tools/bpf/bpftool \
        tools/build \
        tools/include \
        tools/lib \
        tools/scripts; \
    do \
        mkdir -p "./vendor/linux-framework/$(dirname "$path")"; \
        rsync -a "/src/vendor/linux-framework/$path" "./vendor/linux-framework/$(dirname "$path")/"; \
    done; \
    cp -a /src/runner/CMakeLists.txt ./runner/; \
    rsync -a /src/runner/include ./runner/; \
    rsync -a /src/runner/src ./runner/; \
    rsync -a /src/micro/programs ./micro/; \
    rsync -a /src/tests/unittest ./tests/; \
    rsync -a /src/tests/negative ./tests/; \
    rsync -a /src/daemon ./; \
    if [ -d /src/micro/generated-inputs ]; then rsync -a /src/micro/generated-inputs ./micro/; fi; \
    rsync -a /src/corpus/bcf ./corpus/; \
    rsync -a /src/corpus/inputs ./corpus/; \
    rsync -a /src/micro/config ./micro/; \
    find /src/micro -maxdepth 1 -type f -name '*.py' -exec cp -a {} ./micro/ \;; \
    rsync -a /src/corpus/config ./corpus/; \
    find /src/corpus -maxdepth 1 -type f -name '*.py' -exec cp -a {} ./corpus/ \;; \
    rsync -a /src/e2e/cases/tetragon/policies ./e2e/cases/tetragon/; \
    rsync -a /src/e2e/cases ./e2e/; \
    find /src/e2e -maxdepth 1 -type f -name '*.py' -exec cp -a {} ./e2e/ \;; \
    cp -a /src/runner/__init__.py /src/runner/repos.yaml ./runner/; \
    rsync -a /src/runner/libs ./runner/; \
    rsync -a /src/runner/suites ./runner/; \
    rsync -a /src/runner/targets ./runner/; \
    make image-runner-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    make image-micro-program-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    make image-test-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    make image-daemon-artifact RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    find ./e2e/cases/tetragon/policies -type f \( -name '*.yaml' -o -name '*.yml' \) | grep -q .; \
    find ./daemon/target -type d \( -name build -o -name deps -o -name incremental -o -name .fingerprint \) -prune -exec rm -rf {} +; \
    rm -rf \
        /tmp/bpf-benchmark-build \
        /opt/cargo \
        /opt/rustup \
        ./Makefile \
        ./runner/mk \
        ./vendor \
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
        ./daemon/src \
        ./daemon/tests \
        ./daemon/Cargo.toml \
        ./daemon/Cargo.lock \
        ./daemon/Makefile \
        ./daemon/README.md; \
    find ./runner -maxdepth 3 -type d \( -name CMakeFiles -o -name vendor \) -prune -exec rm -rf {} +; \
    find ./runner -maxdepth 3 -type f \( -name CMakeCache.txt -o -name cmake_install.cmake -o -name Makefile \) -delete; \
    find ./tests -type f \( -name '*.o' -o -name '*.d' -o -name '*.cmd' \) -delete; \
    mkdir -p micro/results corpus/results e2e/results tests/results /opt; \
    ln -sfn /artifacts/user /opt/bpf-benchmark; \
    repo_artifact_root="/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}"; \
    mkdir -p "${repo_artifact_root}"; \
    ln -sfn /artifacts/tracee "${repo_artifact_root}/tracee"; \
    ln -sfn /artifacts/tetragon "${repo_artifact_root}/tetragon"; \
    ln -sfn /artifacts/tracee/bin/tracee /usr/local/bin/tracee; \
    ln -sfn /artifacts/tetragon/bin/tetragon /usr/local/bin/tetragon; \
    apt-get purge -y \
        autoconf \
        automake \
        bc \
        binutils-dev \
        bison \
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
        libiberty-dev \
        liblz4-dev \
        libmnl-dev \
        libpcap-dev \
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
        llvm \
        llvm-dev \
        make \
        pkg-config \
        rsync \
        scons \
        unzip \
        xxd \
        zlib1g-dev \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

COPY --from=runner-runtime-kernel-artifacts /artifacts/kernel /artifacts/kernel
COPY --from=runner-runtime-kernel-artifacts /artifacts/modules /artifacts/modules
COPY --from=runner-runtime-kernel-artifacts /artifacts/kinsn /artifacts/kinsn
COPY --from=runner-runtime-kernel-artifacts /artifacts/manifest.json /artifacts/manifest.json
COPY --from=runner-runtime-cilium-upstream --chmod=0755 /usr/bin/cilium-agent /usr/local/bin/cilium-agent
COPY --from=runner-runtime-cilium-upstream --chmod=0755 /usr/bin/cilium-dbg /usr/local/bin/cilium-dbg
COPY --from=runner-runtime-cilium-upstream --chmod=0755 /usr/bin/cilium-bugtool /usr/local/bin/cilium-bugtool
COPY --from=runner-runtime-cilium-upstream --chmod=0755 /usr/bin/cilium-health /usr/local/bin/cilium-health
COPY --from=runner-runtime-cilium-upstream --chmod=0755 /usr/bin/cilium-health-responder /usr/local/bin/cilium-health-responder
COPY --from=runner-runtime-cilium-upstream --chmod=0755 /usr/bin/cilium-mount /usr/local/bin/cilium-mount
COPY --from=runner-runtime-cilium-upstream --chmod=0755 /usr/bin/cilium-sysctlfix /usr/local/bin/cilium-sysctlfix
COPY --from=runner-runtime-cilium-upstream --chmod=0755 /usr/local/bin/clang /usr/local/bin/clang
COPY --from=runner-runtime-cilium-upstream --chmod=0755 /usr/local/bin/llc /usr/local/bin/llc
COPY --from=runner-runtime-cilium-upstream /var/lib/cilium/ /var/lib/cilium/
COPY --from=runner-runtime-calico-upstream --chmod=0755 /usr/bin/calico-node /usr/local/bin/calico-node
COPY --from=runner-runtime-calico-upstream /etc/calico/ /etc/calico/
COPY --from=runner-runtime-calico-upstream /usr/lib/calico/bpf/ /usr/lib/calico/bpf/
COPY --from=runner-runtime-calico-upstream /included-source/ /included-source/
COPY --from=runner-runtime-calico-upstream /usr/lib64/libpcap.so.1 /usr/local/lib/libpcap.so.1
COPY --from=runner-runtime-calico-upstream /usr/lib64/libpcap.so.1.9.1 /usr/local/lib/libpcap.so.1.9.1
COPY --chmod=0755 runner/scripts/bpfrejit-install /usr/local/bin/bpfrejit-install

RUN set -eux; \
    apt-get update; \
    apt-get install -y --no-install-recommends \
        etcd-server \
        nftables; \
    apt-get clean; \
    rm -rf /var/lib/apt/lists/*; \
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
    repo_artifact_root="/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}"; \
    mkdir -p \
        "${repo_artifact_root}/calico/bin" \
        "${repo_artifact_root}/cilium/bin" \
        "${repo_artifact_root}/otelcol-ebpf-profiler/bin"; \
    ln -sfn /usr/local/bin/calico-node "${repo_artifact_root}/calico/bin/calico-node"; \
    ln -sfn /usr/local/bin/cilium-agent "${repo_artifact_root}/cilium/bin/cilium-agent"; \
    ln -sfn /usr/local/bin/cilium-dbg "${repo_artifact_root}/cilium/bin/cilium-dbg"; \
    ln -sfn /usr/local/bin/otelcol-ebpf-profiler "${repo_artifact_root}/otelcol-ebpf-profiler/bin/otelcol-ebpf-profiler"

ENV BPFREJIT_IMAGE_WORKSPACE=${IMAGE_WORKSPACE} \
    BPFREJIT_REPO_ARTIFACT_ROOT=/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH} \
    PYTHONPATH=${IMAGE_WORKSPACE} \
    RUN_TARGET_ARCH=${RUN_TARGET_ARCH} \
    PATH=${IMAGE_WORKSPACE}/runner/build-llvmbpf:${IMAGE_WORKSPACE}/runner/build-arm64-llvmbpf:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

FROM runner-runtime AS runner-default
