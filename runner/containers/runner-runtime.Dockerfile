# syntax=docker/dockerfile:1.6
ARG RUN_TARGET_ARCH=x86_64

FROM docker.io/library/ubuntu:24.04 AS runner-runtime-runtime-base

ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
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
        libboost-context1.83.0 \
        libboost-filesystem1.83.0 \
        libboost-program-options1.83.0 \
        libboost-regex1.83.0 \
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

ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
ARG RUN_TARGET_ARCH=x86_64
ARG VENDOR_BUILD_ARCH=x86
ARG RUNNER_BUILD_DIR_NAME=build-llvmbpf
ARG TEST_BUILD_DIR=build
# Narrow build-contexts pointing at subdirs of the host kbuild O= dir to avoid
# shipping the full kbuild output (~6 GB) as Docker context. Set by the image rule:
#   x86_64 -> image-context = $(O)/arch/x86/boot   KERNEL_IMAGE_NAME=bzImage
#   arm64  -> image-context = $(O)/arch/arm64/boot KERNEL_IMAGE_NAME=vmlinuz.efi
# Manifest JSON is tiny (<200B) so we inline it as a build-arg instead of a context.
ARG KERNEL_IMAGE_NAME
ARG KERNEL_MANIFEST_JSON

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

RUN set -eux; \
    for tool in capable biosnoop vfsstat opensnoop syscount tcpconnect tcplife runqlat; do \
        ln -sfn "/usr/local/share/bcc/tools/${tool}" "/usr/local/bin/${tool}"; \
        ln -sfn "/usr/local/share/bcc/tools/${tool}" "/usr/local/bin/${tool}-bpfcc"; \
    done; \
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

COPY micro/programs ./micro/programs
COPY --link --from=runner-runtime-host-runner-build /micro_exec ${IMAGE_WORKSPACE}/runner/${RUNNER_BUILD_DIR_NAME}/micro_exec
COPY --link --from=runner-runtime-host-micro-programs / /artifacts/user/micro-programs/${RUN_TARGET_ARCH}/
COPY --link --from=runner-runtime-host-stage2-programs / /artifacts/user/stage2-programs/${RUN_TARGET_ARCH}/
COPY --link --from=runner-runtime-host-unittest /rejit_*[^d] ${IMAGE_WORKSPACE}/tests/unittest/${TEST_BUILD_DIR}/
COPY --link --from=runner-runtime-host-unittest /progs/*.bpf.o ${IMAGE_WORKSPACE}/tests/unittest/${TEST_BUILD_DIR}/progs/
COPY --link --from=runner-runtime-host-negative /adversarial_rejit /fuzz_rejit ${IMAGE_WORKSPACE}/tests/negative/${TEST_BUILD_DIR}/

FROM runner-runtime-runtime-base AS runner-runtime

ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
ARG RUN_TARGET_ARCH=x86_64
ARG DAEMON_HOST_BIN_DIR=daemon/target/release
ARG BPFOPT_HOST_BIN_DIR=bpfopt/target/release
ARG NATIVE_LINK_HOST_BIN=native-sim/x86/native_lab/native_link/target/release/native-link

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
COPY --link --from=runner-runtime-artifacts ${IMAGE_WORKSPACE}/runner ${IMAGE_WORKSPACE}/runner
COPY --link --from=runner-runtime-artifacts ${IMAGE_WORKSPACE}/micro/programs ${IMAGE_WORKSPACE}/micro/programs
COPY --link --from=runner-runtime-artifacts /artifacts/user/micro-programs /artifacts/user/micro-programs
COPY --link --from=runner-runtime-artifacts /artifacts/user/stage2-programs /artifacts/user/stage2-programs
COPY --link --from=runner-runtime-artifacts ${IMAGE_WORKSPACE}/tests ${IMAGE_WORKSPACE}/tests
COPY --link --chmod=0755 ${DAEMON_HOST_BIN_DIR}/bpfrejit-daemon ${IMAGE_WORKSPACE}/${DAEMON_HOST_BIN_DIR}/bpfrejit-daemon
COPY --link --chmod=0755 \
    ${BPFOPT_HOST_BIN_DIR}/bpfopt \
    ${BPFOPT_HOST_BIN_DIR}/kinsnprober \
    ${NATIVE_LINK_HOST_BIN} \
    /usr/local/bin/

RUN set -eux; \
    mkdir -p /opt; \
    ln -sfn /artifacts/user /opt/bpf-benchmark; \
    ln -sfn "${IMAGE_WORKSPACE}/${DAEMON_HOST_BIN_DIR}/bpfrejit-daemon" /usr/local/bin/bpfrejit-daemon; \
    # bcc tools shipped by the host build use `#!/usr/bin/env python`
    # shebangs; modern Ubuntu doesn't symlink python -> python3, so the
    # env lookup fails.
    ln -sfn /usr/bin/python3 /usr/bin/python; \
    ldconfig

COPY --link --from=runner-runtime-host-kinsn-artifacts / /artifacts/kinsn

# LD_PRELOAD shim installed at a fixed runtime path for glibc-linked apps.
COPY --link --from=runner-runtime-host-shim /libbpfrejit_shim.so /usr/local/lib/bpfrejit/libbpfrejit_shim.so
COPY --chmod=0755 runner/scripts/bpfrejit-install /usr/local/bin/bpfrejit-install
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
COPY --link runner/assets ./runner/assets

RUN set -eux; \
    find ./runner ./micro ./corpus -type d -name __pycache__ -prune -exec rm -rf {} +; \
    mkdir -p micro/results corpus/results tests/results /var/tmp/bpfrejit-runtime

ENV BPFREJIT_IMAGE_WORKSPACE=${IMAGE_WORKSPACE} \
    BPFREJIT_REPO_ARTIFACT_ROOT=/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH} \
    PYTHONPATH=${IMAGE_WORKSPACE}:/usr/local/lib/python3/dist-packages \
    RUN_TARGET_ARCH=${RUN_TARGET_ARCH} \
    PATH=${IMAGE_WORKSPACE}/runner/build-llvmbpf:${IMAGE_WORKSPACE}/runner/build-arm64-llvmbpf:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
