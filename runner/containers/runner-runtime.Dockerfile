# syntax=docker/dockerfile:1.4
FROM docker.io/library/rockylinux:9@sha256:d7be1c094cc5845ee815d4632fe377514ee6ebcf8efaed6892889657e5ddaaa6

ENV BPFREJIT_REPO_ARTIFACT_ROOT=/opt/bpf-benchmark/repo-artifacts \
    BPFREJIT_WORKLOAD_TOOL_BIN_DIR=/opt/bpf-benchmark/workload-tools/bin \
    PATH=/opt/bpf-benchmark/bin:/opt/bpf-benchmark/repo-artifacts/bpftrace/bin:/opt/bpf-benchmark/workload-tools/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

RUN dnf -y install --setopt=install_weak_deps=False --nodocs \
        dnf-plugins-core \
        epel-release \
    && dnf config-manager --set-enabled crb \
    && dnf -y install --setopt=install_weak_deps=False --nodocs \
        bash \
        bpftool \
        boost \
        bzip2-libs \
        curl-minimal \
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
        libevent \
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

COPY --from=repo-artifacts /bcc /opt/bpf-benchmark/repo-artifacts/bcc
COPY --from=repo-artifacts /bpftrace /opt/bpf-benchmark/repo-artifacts/bpftrace
COPY --from=repo-artifacts /katran /opt/bpf-benchmark/repo-artifacts/katran
COPY --from=repo-artifacts /tracee /opt/bpf-benchmark/repo-artifacts/tracee
COPY --from=repo-artifacts /tetragon /opt/bpf-benchmark/repo-artifacts/tetragon
COPY --from=repo-artifacts /scx /opt/bpf-benchmark/repo-artifacts/scx
COPY --from=workload-tools / /opt/bpf-benchmark/workload-tools/
COPY --from=daemon-bin /bpfrejit-daemon /opt/bpf-benchmark/bin/bpfrejit-daemon
COPY --from=runner-bin /micro_exec /opt/bpf-benchmark/bin/micro_exec
COPY --from=micro-programs / /opt/bpf-benchmark/micro-programs/

WORKDIR /workspace
