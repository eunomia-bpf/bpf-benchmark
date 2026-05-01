# syntax=docker/dockerfile:1.4
FROM docker.io/library/ubuntu:24.04 AS katran-artifacts-build

ARG IMAGE_BUILD_JOBS=4
ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
ARG RUN_TARGET_ARCH=auto
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
        flex \
        g++ \
        gcc \
        git \
        iproute2 \
        kmod \
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
        libgrpc++-dev \
        libiberty-dev \
        liblz4-dev \
        liblzma-dev \
        libmnl-dev \
        libprotobuf-dev \
        libre2-dev \
        libsodium-dev \
        libsnappy-dev \
        libssl-dev \
        libtool \
        libtool-bin \
        libltdl-dev \
        libunwind-dev \
        libzstd-dev \
        llvm \
        llvm-dev \
        make \
        openssl \
        perl \
        pkg-config \
        procps \
        protobuf-compiler \
        protobuf-compiler-grpc \
        python3 \
        python3-bpfcc \
        rsync \
        scons \
        tar \
        unzip \
        xz-utils \
        xxd \
        zlib1g-dev \
        zstd \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p "${IMAGE_WORKSPACE}"
WORKDIR ${IMAGE_WORKSPACE}

COPY Makefile ./Makefile
COPY runner/mk ./runner/mk
COPY runner/repos ./runner/repos
COPY vendor/linux-framework/Makefile ./vendor/linux-framework/Makefile
COPY vendor/linux-framework/include ./vendor/linux-framework/include
COPY vendor/linux-framework/arch/arm64/include/uapi/asm ./vendor/linux-framework/arch/arm64/include/uapi/asm
COPY vendor/linux-framework/scripts ./vendor/linux-framework/scripts
COPY vendor/linux-framework/kernel/bpf/disasm.c ./vendor/linux-framework/kernel/bpf/disasm.c
COPY vendor/linux-framework/kernel/bpf/disasm.h ./vendor/linux-framework/kernel/bpf/disasm.h
COPY vendor/linux-framework/tools/arch ./vendor/linux-framework/tools/arch
COPY vendor/linux-framework/tools/bpf/bpftool ./vendor/linux-framework/tools/bpf/bpftool
COPY vendor/linux-framework/tools/build ./vendor/linux-framework/tools/build
COPY vendor/linux-framework/tools/include ./vendor/linux-framework/tools/include
COPY vendor/linux-framework/tools/lib ./vendor/linux-framework/tools/lib
COPY vendor/linux-framework/tools/scripts ./vendor/linux-framework/tools/scripts

RUN --mount=type=cache,target=/tmp/bpf-benchmark-build,id=katran-build-${RUN_TARGET_ARCH},sharing=locked \
    set -eux; \
    target_arch="${RUN_TARGET_ARCH}"; \
    if [ -z "${target_arch}" ] || [ "${target_arch}" = "auto" ]; then \
        case "${TARGETARCH}" in \
            amd64|x86_64) target_arch=x86_64 ;; \
            arm64|aarch64) target_arch=arm64 ;; \
            *) echo "unsupported Katran target arch: ${TARGETARCH}" >&2; exit 1 ;; \
        esac; \
    fi; \
    katran_cache_install="/tmp/bpf-benchmark-build/katran-install-${target_arch}"; \
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
    make -C vendor/linux-framework/tools/bpf/bpftool \
        VMLINUX_BTF= \
        feature-llvm=0 \
        feature-libbfd=0 \
        feature-libbfd-liberty=0 \
        feature-libbfd-liberty-z=0 \
        -j"${IMAGE_BUILD_JOBS}"; \
    install -m 0755 vendor/linux-framework/tools/bpf/bpftool/bpftool /usr/local/bin/bpftool; \
    bpftool version; \
    command -v grpc_cpp_plugin >/dev/null; \
    make image-katran-artifacts \
        RUN_TARGET_ARCH="${target_arch}" \
        REPO_KATRAN_ROOT="${katran_cache_install}" \
        BPFREJIT_IMAGE_BUILD=1 \
        JOBS="${IMAGE_BUILD_JOBS}"; \
    rm -rf /artifacts/katran; \
    mkdir -p /artifacts; \
    cp -a "${katran_cache_install}" /artifacts/katran; \
    test -x /artifacts/katran/bin/katran_server_grpc; \
    test -d /artifacts/katran/lib; \
    test -f /artifacts/katran/bpf/balancer.bpf.o; \
    test -f /artifacts/katran/bpf/healthchecking_ipip.bpf.o; \
    test -f /artifacts/katran/bpf/xdp_root.bpf.o

FROM scratch AS katran-artifacts
COPY --from=katran-artifacts-build /artifacts/katran /artifacts/katran
