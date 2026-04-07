FROM amazonlinux:2023

RUN dnf install -y --setopt=install_weak_deps=False \
        binutils-devel \
        boost-devel \
        bzip2-devel \
        cargo \
        clang \
        clang20 \
        cmake \
        dnf-plugins-core \
        diffutils \
        elfutils-devel \
        elfutils-libelf-devel \
        file \
        gcc-c++ \
        git \
        golang \
        gzip \
        kernel6.18-libbpf-devel \
        libdwarf-devel \
        libmnl-devel \
        libunwind-devel \
        lz4-devel \
        llvm-devel \
        llvm20 \
        llvm20-devel \
        lld20 \
        make \
        ncurses-devel \
        ninja-build \
        openssl \
        openssl-devel \
        python3 \
        python3-pip \
        pkgconf-pkg-config \
        rust \
        sudo \
        tar \
        xz-devel \
        zlib-devel \
        libzstd-devel \
    && python3 -m pip install --no-cache-dir pyelftools PyYAML scons \
    && ln -sfn /etc/system-release /etc/redhat-release \
    && for tool in clang clang++ llc llvm-config llvm-objcopy llvm-strip; do \
           for candidate in "/usr/bin/${tool}-20" "/usr/bin/${tool}20"; do \
               if [ -x "${candidate}" ]; then \
                   ln -sfn "${candidate}" "/usr/local/bin/${tool}"; \
                   break; \
               fi; \
           done; \
       done \
    && for candidate in /usr/bin/ld.lld-20 /usr/bin/ld.lld20; do \
           if [ -x "${candidate}" ]; then \
               ln -sfn "${candidate}" /usr/local/bin/ld.lld; \
               break; \
           fi; \
       done \
    && dnf clean all \
    && rm -rf /var/cache/dnf
