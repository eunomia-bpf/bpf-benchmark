# syntax=docker/dockerfile:1.6
ARG RUN_TARGET_ARCH=x86_64

FROM docker.io/library/ubuntu:24.04 AS runner-runtime-runtime-base

ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        auditd \
        bash \
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
        libbz2-1.0 \
        libcap2 \
        libclang-cpp15t64 \
        libclang1-15t64 \
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
        libllvm15t64 \
        libllvm17t64 \
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
        nodejs \
        perl \
        php-cli \
        procps \
        python3 \
        python3-yaml \
        ruby \
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

FROM runner-runtime-runtime-base AS runner-runtime-artifacts

ARG IMAGE_BUILD_JOBS=4
ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
ARG RUN_TARGET_ARCH=x86_64
ARG VENDOR_BUILD_ARCH=x86
# Narrow build-contexts pointing at subdirs of the host kbuild O= dir to avoid
# shipping the full kbuild output (~6 GB) as Docker context. Set by the image rule:
#   x86_64 -> image-context = $(O)/arch/x86/boot   KERNEL_IMAGE_NAME=bzImage
#   arm64  -> image-context = $(O)/arch/arm64/boot KERNEL_IMAGE_NAME=vmlinuz.efi
# Manifest JSON is tiny (<200B) so we inline it as a build-arg instead of a context.
ARG KERNEL_IMAGE_NAME
ARG KERNEL_MANIFEST_JSON

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

COPY --link --chmod=0755 vendor/build/${VENDOR_BUILD_ARCH}/tracee/bin/tracee /artifacts/tracee/bin/tracee
COPY --link vendor/build/${VENDOR_BUILD_ARCH}/tetragon/ /artifacts/tetragon/

COPY --link --chmod=0755 vendor/binary/katran/${RUN_TARGET_ARCH}/bin/katran_server_grpc /artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}/katran/bin/katran_server_grpc
COPY --link vendor/build/${VENDOR_BUILD_ARCH}/katran/bpf/*.bpf.o /artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}/katran/bpf/

COPY --link vendor/repos/cilium/bpf/ /var/lib/cilium/bpf/
COPY --link vendor/build/${VENDOR_BUILD_ARCH}/bcc/ /usr/local/
COPY --link --chmod=0755 \
    vendor/build/${VENDOR_BUILD_ARCH}/cilium/bin/cilium-agent \
    vendor/build/${VENDOR_BUILD_ARCH}/otelcol-ebpf-profiler/bin/otelcol-ebpf-profiler \
    vendor/build/${VENDOR_BUILD_ARCH}/bpftool/bin/bpftool \
    vendor/build/${VENDOR_BUILD_ARCH}/bpftrace/bin/bpftrace \
    vendor/build/${VENDOR_BUILD_ARCH}/bpftrace/bin/bpftrace-aotrt \
    /usr/local/bin/

COPY --chmod=0755 runner/scripts/bpfrejit-install /usr/local/bin/bpfrejit-install

RUN set -eux; \
    ldconfig; \
    for tool in capable biosnoop vfsstat opensnoop syscount tcpconnect tcplife runqlat; do \
        ln -sfn "/usr/local/share/bcc/tools/${tool}" "/usr/local/bin/${tool}"; \
        ln -sfn "/usr/local/share/bcc/tools/${tool}" "/usr/local/bin/${tool}-bpfcc"; \
    done; \
    # host-built bcc tools ship with `#!/usr/bin/env python` shebangs (legacy
    # python2-era); modern Ubuntu doesn't symlink python -> python3, so the
    # env lookup fails with `/usr/bin/env: 'python': No such file or directory`
    # at exec time. Add the symlink so the BPF wrappers spawn correctly under
    # the shim's LD_PRELOAD.
    ln -sfn /usr/bin/python3 /usr/bin/python; \
    mkdir -p /opt; \
    ln -sfn /artifacts/user /opt/bpf-benchmark; \
    repo_artifact_root="/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}"; \
    mkdir -p \
        "${repo_artifact_root}" \
        "${repo_artifact_root}/cilium/bin" \
        "${repo_artifact_root}/otelcol-ebpf-profiler/bin"; \
    ln -sfn /artifacts/tracee "${repo_artifact_root}/tracee"; \
    ln -sfn /artifacts/tetragon "${repo_artifact_root}/tetragon"; \
    ln -sfn /artifacts/tracee/bin/tracee /usr/local/bin/tracee; \
    ln -sfn /artifacts/tetragon/bin/tetragon /usr/local/bin/tetragon; \
    ln -sfn /usr/local/bin/cilium-agent "${repo_artifact_root}/cilium/bin/cilium-agent"; \
    ln -sfn /usr/local/bin/otelcol-ebpf-profiler "${repo_artifact_root}/otelcol-ebpf-profiler/bin/otelcol-ebpf-profiler"

COPY --link --from=runner-runtime-host-kernel-image /${KERNEL_IMAGE_NAME} /artifacts/kernel/${KERNEL_IMAGE_NAME}
COPY --link --from=runner-runtime-host-kernel-offsets /kernel_offsets.h /artifacts/kernel/kernel_offsets.h
COPY --link --from=runner-runtime-host-kernel-modules / /artifacts/modules
RUN mkdir -p /artifacts && printf '%s\n' "${KERNEL_MANIFEST_JSON}" > /artifacts/manifest.json

COPY Makefile ./Makefile
COPY runner/mk ./runner/mk
COPY vendor/libbpf ./vendor/libbpf
COPY vendor/llvmbpf ./vendor/llvmbpf
COPY vendor/linux-framework/include ./vendor/linux-framework/include
COPY runner/CMakeLists.txt ./runner/CMakeLists.txt
COPY runner/include ./runner/include
COPY runner/src ./runner/src
COPY micro/programs ./micro/programs
COPY native-sim/test ./native-sim/test
COPY tests/unittest ./tests/unittest
COPY tests/negative ./tests/negative

RUN set -eux; \
    make image-runner-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    CLANG=/usr/bin/clang make image-micro-program-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    CLANG=/usr/bin/clang make image-stage2-program-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    PATH="/usr/bin:${PATH}" make image-test-artifacts RUN_TARGET_ARCH="${RUN_TARGET_ARCH}" BPFREJIT_IMAGE_BUILD=1 JOBS="${IMAGE_BUILD_JOBS}"; \
    rm -rf \
        /tmp/bpf-benchmark-build \
        ./vendor \
        ./runner/src \
        ./runner/include \
        ./runner/CMakeLists.txt \
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

FROM scratch AS runner-runtime-kinsn-artifacts

COPY --link --from=runner-runtime-host-kinsn-artifacts / /artifacts/kinsn

FROM runner-runtime-runtime-base AS runner-runtime-daemon-artifact

# DAEMON_HOST_BIN_DIR is the host-relative directory containing the pre-built
# bpfrejit-daemon binary (x86_64 from daemon/target/release/, arm64 from
# daemon/target/aarch64-unknown-linux-gnu/release/). Both arches build on host.
# The runner Python (workspace_layout.py) reads the daemon from this same path
# inside the image workspace, so the binary is staged at both /usr/local/bin and
# /artifacts/rust/${DAEMON_HOST_BIN_DIR}.
ARG DAEMON_HOST_BIN_DIR=daemon/target/release

COPY ${DAEMON_HOST_BIN_DIR}/bpfrejit-daemon /tmp/bpfrejit-daemon
RUN set -eux; \
    install -d /artifacts/rust/usr-local-bin "/artifacts/rust/${DAEMON_HOST_BIN_DIR}"; \
    install -m 0755 /tmp/bpfrejit-daemon /artifacts/rust/usr-local-bin/bpfrejit-daemon; \
    install -m 0755 /tmp/bpfrejit-daemon "/artifacts/rust/${DAEMON_HOST_BIN_DIR}/bpfrejit-daemon"; \
    rm /tmp/bpfrejit-daemon

FROM runner-runtime-runtime-base AS runner-runtime-bpfopt-artifacts

# BPFOPT_HOST_BIN_DIR is the host-relative directory containing pre-built bpfopt
# CLI + kinsnprober (x86_64 from bpfopt/target/release/, arm64 from
# bpfopt/target/aarch64-unknown-linux-gnu/release/). kinsnprober is the
# stock-kernel BTF prober — shim execs it once at startup to populate
# target.json; daemon path doesn't use it.
ARG BPFOPT_HOST_BIN_DIR=bpfopt/target/release
# NATIVE_LINK_HOST_BIN is the host-built native-link binary. It lives under
# native-sim/x86/native_lab/native_link/target/release/ regardless of target
# arch (native-link runs as an x86 host-side build tool inside the runtime
# container, not on the target architecture).
ARG NATIVE_LINK_HOST_BIN=native-sim/x86/native_lab/native_link/target/release/native-link

COPY \
    ${BPFOPT_HOST_BIN_DIR}/bpfopt \
    ${BPFOPT_HOST_BIN_DIR}/kinsnprober \
    ${NATIVE_LINK_HOST_BIN} \
    /tmp/
RUN set -eux; \
    install -d /artifacts/rust/usr-local-bin; \
    install -m 0755 /tmp/bpfopt /artifacts/rust/usr-local-bin/; \
    install -m 0755 /tmp/kinsnprober /artifacts/rust/usr-local-bin/; \
    install -m 0755 /tmp/native-link /artifacts/rust/usr-local-bin/; \
    rm /tmp/bpfopt /tmp/kinsnprober /tmp/native-link

FROM runner-runtime-runtime-base AS runner-runtime

ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
ARG RUN_TARGET_ARCH=x86_64

ENV PYTHONPATH=/usr/local/lib/python3/dist-packages

COPY --link --from=runner-runtime-artifacts /artifacts/tracee /artifacts/tracee
COPY --link --from=runner-runtime-artifacts /artifacts/tetragon /artifacts/tetragon
COPY --link --from=runner-runtime-artifacts /artifacts/user/repo-artifacts /artifacts/user/repo-artifacts
COPY --link --from=runner-runtime-artifacts /usr/local/bin/ /usr/local/bin/
COPY --link --from=runner-runtime-artifacts /usr/local/lib/ /usr/local/lib/
COPY --link --from=runner-runtime-artifacts /usr/local/share/bcc /usr/local/share/bcc
COPY --link --from=runner-runtime-artifacts /var/lib/cilium /var/lib/cilium
COPY --link --from=runner-runtime-artifacts /artifacts/kernel /artifacts/kernel
COPY --link --from=runner-runtime-artifacts /artifacts/modules /artifacts/modules
COPY --link --from=runner-runtime-artifacts /artifacts/manifest.json /artifacts/manifest.json
COPY --link --from=runner-runtime-kinsn-artifacts /artifacts/kinsn /artifacts/kinsn
COPY --link --from=runner-runtime-artifacts ${IMAGE_WORKSPACE}/runner ${IMAGE_WORKSPACE}/runner
COPY --link --from=runner-runtime-artifacts ${IMAGE_WORKSPACE}/micro/programs ${IMAGE_WORKSPACE}/micro/programs
COPY --link --from=runner-runtime-artifacts /artifacts/user/micro-programs /artifacts/user/micro-programs
COPY --link --from=runner-runtime-artifacts /artifacts/user/stage2-programs /artifacts/user/stage2-programs
COPY --link --from=runner-runtime-artifacts ${IMAGE_WORKSPACE}/tests ${IMAGE_WORKSPACE}/tests
COPY --link --from=runner-runtime-daemon-artifact /artifacts/rust/usr-local-bin/bpfrejit-daemon /usr/local/bin/bpfrejit-daemon
COPY --link --from=runner-runtime-daemon-artifact /artifacts/rust/daemon/ ${IMAGE_WORKSPACE}/daemon/
COPY --link --from=runner-runtime-bpfopt-artifacts /artifacts/rust/usr-local-bin/ /usr/local/bin/

RUN set -eux; \
    mkdir -p /opt; \
    ln -sfn /artifacts/user /opt/bpf-benchmark; \
    # bcc tools shipped by the host build use `#!/usr/bin/env python`
    # shebangs; modern Ubuntu doesn't symlink python -> python3, so the
    # env lookup fails. The artifacts stage symlinks it, but the final
    # runtime stage doesn't inherit /usr/bin from there, so add it again.
    ln -sfn /usr/bin/python3 /usr/bin/python; \
    ldconfig

# LD_PRELOAD shim installed at a fixed runtime path for glibc-linked apps.
RUN mkdir -p /usr/local/lib/bpfrejit
COPY --link bpfopt/shim/libbpfrejit_shim.so /usr/local/lib/bpfrejit/libbpfrejit_shim.so
COPY runner/__init__.py ./runner/
COPY runner/config ./runner/config
COPY runner/libs ./runner/libs
COPY runner/suites ./runner/suites
COPY runner/targets ./runner/targets
COPY micro/*.py ./micro/
COPY micro/config ./micro/config
COPY corpus/*.py ./corpus/
COPY corpus/config ./corpus/config
COPY corpus/inputs ./corpus/inputs
COPY --link corpus/bcf ./corpus/bcf
COPY --link runner/assets ./runner/assets

RUN set -eux; \
    find ./runner ./micro ./corpus -type d -name __pycache__ -prune -exec rm -rf {} +; \
    find ./runner/assets/tetragon_policies -type f \( -name '*.yaml' -o -name '*.yml' \) | grep -q .; \
    mkdir -p micro/results corpus/results tests/results /var/tmp/bpfrejit-runtime

RUN printf '#!/usr/bin/env bash\nexec "$@"\n' > /usr/local/bin/bpfrejit-runtime-entrypoint && \
    chmod +x /usr/local/bin/bpfrejit-runtime-entrypoint

ENV BPFREJIT_IMAGE_WORKSPACE=${IMAGE_WORKSPACE} \
    BPFREJIT_REPO_ARTIFACT_ROOT=/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH} \
    PYTHONPATH=${IMAGE_WORKSPACE}:/usr/local/lib/python3/dist-packages \
    RUN_TARGET_ARCH=${RUN_TARGET_ARCH} \
    PATH=${IMAGE_WORKSPACE}/runner/build-llvmbpf:${IMAGE_WORKSPACE}/runner/build-arm64-llvmbpf:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

ENTRYPOINT ["/usr/local/bin/bpfrejit-runtime-entrypoint"]

FROM runner-runtime AS runner-default
