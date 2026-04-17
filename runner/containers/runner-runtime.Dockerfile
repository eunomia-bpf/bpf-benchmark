# syntax=docker/dockerfile:1.4
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
        python3-yaml \
        rsync \
        rustc \
        scons \
        stress-ng \
        tar \
        unzip \
        util-linux \
        xz-utils \
        xxd \
        zlib1g-dev \
        zstd \
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

FROM --platform=$BUILDPLATFORM docker.io/library/ubuntu:24.04 AS runner-runtime-tracee-bpf

ARG IMAGE_BUILD_JOBS=4
ARG RUN_TARGET_ARCH=x86_64

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        bash \
        ca-certificates \
        clang \
        gcc \
        libelf-dev \
        make \
        pkg-config \
        zlib1g-dev \
    && rm -rf /var/lib/apt/lists/*

RUN --mount=type=bind,source=.,target=/src,readonly \
    set -eux; \
    repo_root="/work/tracee"; \
    dist_root="${repo_root}/dist"; \
    output_root="/tracee-bpf-artifacts"; \
    case "${RUN_TARGET_ARCH}" in \
        arm64) uname_m=aarch64; tracee_arch=arm64; linux_arch=arm64; go_arch=arm64 ;; \
        x86_64) uname_m=x86_64; tracee_arch=x86_64; linux_arch=x86; go_arch=amd64 ;; \
        *) echo "unsupported Tracee BPF target arch: ${RUN_TARGET_ARCH}" >&2; exit 1 ;; \
    esac; \
    mkdir -p /work "${output_root}/lsm_support"; \
    cp -a /src/runner/repos/tracee "${repo_root}"; \
    rm -rf "${dist_root}" \
        "${repo_root}/.build_libbpf" \
        "${repo_root}/.build_libbpf_fix" \
        "${repo_root}/.eval_goenv" \
        "${repo_root}/.checklib_libbpf" \
        "${repo_root}/goenv.mk"; \
    make -C "${repo_root}" -j"${IMAGE_BUILD_JOBS}" \
        OUTPUT_DIR="${dist_root}" \
        UNAME_M="${uname_m}" \
        ARCH="${tracee_arch}" \
        LINUX_ARCH="${linux_arch}" \
        GO_ARCH="${go_arch}" \
        CMD_GCC=gcc \
        CMD_CLANG=clang \
        CMD_GO=/bin/false \
        bpf; \
    install -m 0644 "${dist_root}/tracee.bpf.o" "${output_root}/tracee.bpf.o"; \
    install -m 0644 "${dist_root}/lsm_support/kprobe_check.bpf.o" "${output_root}/lsm_support/kprobe_check.bpf.o"; \
    install -m 0644 "${dist_root}/lsm_support/lsm_check.bpf.o" "${output_root}/lsm_support/lsm_check.bpf.o"

FROM runner-runtime-build-base AS runner-runtime-userspace

ARG IMAGE_BUILD_JOBS=4
ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
ARG RUN_TARGET_ARCH=x86_64

RUN --mount=type=bind,source=.,target=/src,readonly \
    --mount=type=bind,from=runner-runtime-tracee-bpf,source=/tracee-bpf-artifacts,target=/prebuilt-tracee-bpf,readonly \
    set -eux; \
    cp -a /src/Makefile ./Makefile; \
    mkdir -p ./runner ./vendor ./vendor/linux-framework; \
    rsync -a /src/runner/mk ./runner/; \
    rsync -a /src/runner/repos ./runner/; \
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
        tools/sched_ext/include \
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
    rm -rf \
        ./runner/repos/workload-tools/sysbench/third_party/concurrency_kit/include \
        ./runner/repos/workload-tools/sysbench/third_party/concurrency_kit/lib \
        ./runner/repos/workload-tools/sysbench/third_party/concurrency_kit/share \
        ./runner/repos/workload-tools/sysbench/third_party/concurrency_kit/tmp \
        ./runner/repos/workload-tools/sysbench/third_party/luajit/bin \
        ./runner/repos/workload-tools/sysbench/third_party/luajit/lib \
        ./runner/repos/workload-tools/sysbench/third_party/luajit/share \
        ./runner/repos/workload-tools/sysbench/third_party/luajit/tmp \
        ./runner/repos/workload-tools/wrk/obj \
        ./runner/repos/workload-tools/wrk/wrk; \
    find ./runner/repos/workload-tools/sysbench -type f \( -name '*.a' -o -name '*.la' -o -name '*.lo' -o -name '*.o' \) -delete; \
    make image-bcc-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    make image-bpftrace-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    make image-katran-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    make image-tracee-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}" PREBUILT_TRACEE_BPF_ROOT=/prebuilt-tracee-bpf; \
    make image-tetragon-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    make image-scx-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    make image-workload-tools-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    rm -rf \
        /tmp/bpf-benchmark-build \
        /root/.cache/go-build \
        /root/go \
        ./Makefile \
        ./runner/mk \
        ./vendor \
        ./runner/repos

FROM runner-runtime-build-base AS runner-runtime-kernel-artifacts

ARG IMAGE_BUILD_JOBS=4
ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
ARG RUN_TARGET_ARCH=x86_64

RUN --mount=type=bind,source=.,target=/src,readonly \
    set -eux; \
    cp -a /src/Makefile ./Makefile; \
    mkdir -p ./runner ./vendor /artifacts; \
    rsync -a /src/runner/mk ./runner/; \
    ln -sfn /src/vendor/linux-framework ./vendor/linux-framework; \
    cp -a /src/vendor/bpfrejit_x86_defconfig /src/vendor/bpfrejit_arm64_defconfig ./vendor/; \
    rsync -a /src/module ./; \
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

RUN --mount=type=bind,source=.,target=/src,readonly \
    set -eux; \
    cp -a /src/Makefile ./Makefile; \
    mkdir -p ./runner ./vendor ./vendor/linux-framework ./micro ./corpus ./e2e ./tests; \
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
        tools/sched_ext/include \
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
    rsync -a /src/micro/generated-inputs ./micro/; \
    rsync -a /src/corpus/bcf ./corpus/; \
    rsync -a /src/corpus/inputs ./corpus/; \
    rsync -a /src/micro/config ./micro/; \
    find /src/micro -maxdepth 1 -type f -name '*.py' -exec cp -a {} ./micro/ \;; \
    rsync -a /src/corpus/config ./corpus/; \
    find /src/corpus -maxdepth 1 -type f -name '*.py' -exec cp -a {} ./corpus/ \;; \
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
    find ./daemon/target -type d \( -name build -o -name deps -o -name incremental -o -name .fingerprint \) -prune -exec rm -rf {} +; \
    rm -rf \
        /tmp/bpf-benchmark-build \
        /root/.cache/go-build \
        /root/go \
        /usr/local/go \
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
    mkdir -p micro/results corpus/results e2e/results tests/results; \
    apt-get purge -y \
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
        rustc \
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
COPY --chmod=0755 runner/scripts/bpfrejit-install /usr/local/bin/bpfrejit-install

ENV BPFREJIT_IMAGE_WORKSPACE=${IMAGE_WORKSPACE} \
    BPFREJIT_REPO_ARTIFACT_ROOT=/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH} \
    BPFREJIT_WORKLOAD_TOOL_BIN_DIR=/artifacts/user/workload-tools/${RUN_TARGET_ARCH}/bin \
    PYTHONPATH=${IMAGE_WORKSPACE} \
    RUN_TARGET_ARCH=${RUN_TARGET_ARCH} \
    PATH=${IMAGE_WORKSPACE}/runner/build-llvmbpf:${IMAGE_WORKSPACE}/runner/build-arm64-llvmbpf:/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}/bpftrace/bin:/artifacts/user/workload-tools/${RUN_TARGET_ARCH}/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

FROM runner-runtime AS runner-default
