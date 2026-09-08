FROM mcr.microsoft.com/devcontainers/base:ubuntu-24.04@sha256:d94c97dd9cacf183d0a6fd12a8e87b526e9e928307674ae9c94139139c0c6eae

ARG DEBIAN_FRONTEND=noninteractive

RUN dpkg --add-architecture arm64 \
    && sed -i '/^Components:/a Architectures: amd64' /etc/apt/sources.list.d/ubuntu.sources \
    && printf '%s\n' \
        'Types: deb' \
        'URIs: http://ports.ubuntu.com/ubuntu-ports/' \
        'Suites: noble noble-updates noble-backports noble-security' \
        'Components: main restricted universe multiverse' \
        'Architectures: arm64' \
        'Signed-By: /usr/share/keyrings/ubuntu-archive-keyring.gpg' \
        > /etc/apt/sources.list.d/arm64-ports.sources \
    && rm -f /etc/apt/sources.list

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        build-essential cmake ninja-build pkg-config unzip jq file ca-certificates curl gnupg openssh-client \
        bc bison flex cpio kmod dwarves gawk zstd xz-utils perl rsync openssl elan busybox-static \
        udev \
        libelf-dev libssl-dev libcap-dev libzstd-dev zlib1g-dev libxml2-dev libedit-dev libbpf-dev \
        libyaml-cpp-dev libspdlog-dev libfmt-dev \
        clang-18 llvm-18 llvm-18-dev lld-18 libclang-18-dev \
        gcc-aarch64-linux-gnu g++-aarch64-linux-gnu \
        qemu-system-x86 qemu-system-arm qemu-user-static \
        python3 python3-pip python3-venv python3-yaml python3-argcomplete python3-requests python3-pyelftools \
    && rm -rf /var/lib/apt/lists/*

# Ubuntu's versioned LLVM packages do not install the unversioned tool names
# used by the repository Makefiles (clang, llvm-readelf, llvm-objdump, ...).
ENV PATH="/usr/lib/llvm-18/bin:${PATH}"

RUN install -d -m 0755 /etc/apt/keyrings \
    && curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc \
    && echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/ubuntu noble stable" \
        > /etc/apt/sources.list.d/docker.list \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
        docker-ce='5:29.8.0-1~ubuntu.24.04~noble' \
        docker-ce-cli='5:29.8.0-1~ubuntu.24.04~noble' \
        containerd.io='2.3.4-2~ubuntu.24.04~noble' \
        docker-buildx-plugin='0.37.0-1~ubuntu.24.04~noble' \
        docker-compose-plugin='5.5.1-1~ubuntu.24.04~noble' \
    && rm -rf /var/lib/apt/lists/*

ARG GO_VERSION=1.26.8
ARG GO_AMD64_SHA256=d0f743b33e8d8945e6b1f432edd15785c70507121d6e2a723b21285eddf8b57b
ARG GO_ARM64_SHA256=211ffced9dcb9633a55eac6364816ec0ddd951389a740e88fa8b3337971bdda0
RUN set -eu \
    && arch="$(dpkg --print-architecture)" \
    && case "${arch}" in \
        amd64) sha256="${GO_AMD64_SHA256}" ;; \
        arm64) sha256="${GO_ARM64_SHA256}" ;; \
        *) echo "unsupported Go architecture: ${arch}" >&2; exit 1 ;; \
    esac \
    && curl -fsSL "https://go.dev/dl/go${GO_VERSION}.linux-${arch}.tar.gz" -o /tmp/go.tgz \
    && echo "${sha256}  /tmp/go.tgz" | sha256sum -c - \
    && rm -rf /usr/local/go \
    && tar -C /usr/local -xzf /tmp/go.tgz \
    && rm /tmp/go.tgz

ENV RUSTUP_HOME=/usr/local/rustup \
    CARGO_HOME=/usr/local/cargo
ARG RUSTUP_VERSION=1.29.1
ARG RUST_VERSION=1.98.1
ARG RUSTUP_X86_64_SHA256=dda7234360b7f578ca8b0ddcb80145646fa61a67c1720a5abc7051b35c9fcb71
ARG RUSTUP_AARCH64_SHA256=15f6e4ce9f583b929c996c91562bad6d4454f3281de858b02cdfdef615fac433
RUN set -eu \
    && case "$(dpkg --print-architecture)" in \
        amd64) rust_arch=x86_64; sha256="${RUSTUP_X86_64_SHA256}" ;; \
        arm64) rust_arch=aarch64; sha256="${RUSTUP_AARCH64_SHA256}" ;; \
        *) echo "unsupported Rust architecture" >&2; exit 1 ;; \
    esac \
    && curl -fsSL "https://static.rust-lang.org/rustup/archive/${RUSTUP_VERSION}/${rust_arch}-unknown-linux-gnu/rustup-init" -o /tmp/rustup-init \
    && echo "${sha256}  /tmp/rustup-init" | sha256sum -c - \
    && chmod 0755 /tmp/rustup-init \
    && /tmp/rustup-init -y --profile minimal --component rustfmt --component clippy \
        --default-toolchain "${RUST_VERSION}" --target aarch64-unknown-linux-gnu \
    && rm /tmp/rustup-init

ARG AWS_CLI_VERSION=2.36.40
RUN curl -fsSL "https://awscli.amazonaws.com/awscli-exe-linux-$(case "$(dpkg --print-architecture)" in amd64) echo x86_64 ;; arm64) echo aarch64 ;; esac)-${AWS_CLI_VERSION}.zip" \
        -o /tmp/awscliv2.zip \
    && unzip -q /tmp/awscliv2.zip -d /tmp/awscliv2 \
    && /tmp/awscliv2/aws/install --update \
    && rm -rf /tmp/awscliv2 /tmp/awscliv2.zip

RUN python3 -m venv --system-site-packages /opt/virtme-ng \
    && /opt/virtme-ng/bin/pip install --no-cache-dir --no-deps 'virtme-ng==1.41' \
    && ln -s /opt/virtme-ng/bin/vng /usr/local/bin/vng

COPY bpf-vng-tmpfiles.conf /usr/lib/tmpfiles.d/bpf-vng.conf
COPY scripts/ensure-dockerd.sh /usr/local/bin/ensure-dockerd.sh
RUN chmod 0755 /usr/local/bin/ensure-dockerd.sh

ENV PATH="/opt/virtme-ng/bin:/usr/local/go/bin:/usr/local/cargo/bin:${PATH}" \
    RUSTUP_HOME=/usr/local/rustup \
    CARGO_HOME=/usr/local/cargo

USER root
