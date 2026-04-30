# syntax=docker/dockerfile:1.6
FROM docker.io/library/ubuntu:24.04 AS kernel-fork

ARG IMAGE_BUILD_JOBS=4
ARG RUN_TARGET_ARCH=x86_64

ENV DEBIAN_FRONTEND=noninteractive

RUN set -eux; \
    case "${RUN_TARGET_ARCH}" in x86_64|arm64) ;; *) echo "unsupported RUN_TARGET_ARCH: ${RUN_TARGET_ARCH}" >&2; exit 1 ;; esac; \
    apt-get update; \
    apt-get install -y --no-install-recommends \
        bash \
        bc \
        binutils \
        bison \
        bsdextrautils \
        build-essential \
        ca-certificates \
        cpio \
        dwarves \
        elfutils \
        file \
        findutils \
        flex \
        gcc \
        git \
        kmod \
        libdw-dev \
        libdwarf-dev \
        libelf-dev \
        libssl-dev \
        make \
        openssl \
        perl \
        pkg-config \
        python3 \
        rsync \
        xz-utils \
        zstd; \
    if [ "${RUN_TARGET_ARCH}" = "arm64" ]; then \
        apt-get install -y --no-install-recommends gcc-aarch64-linux-gnu; \
        aarch64-linux-gnu-gcc --version; \
    fi; \
    rm -rf /var/lib/apt/lists/*

WORKDIR /src

COPY vendor/bpfrejit_x86_defconfig vendor/bpfrejit_arm64_defconfig ./vendor/
COPY vendor/linux-framework ./vendor/linux-framework

RUN --mount=type=cache,target=/tmp/kernel-build,id=kernel-build-${RUN_TARGET_ARCH},sharing=locked <<'EOF'
set -eux

case "${IMAGE_BUILD_JOBS}" in
    ''|*[!0-9]*|0)
        echo "IMAGE_BUILD_JOBS must be a positive integer: ${IMAGE_BUILD_JOBS}" >&2
        exit 1
        ;;
esac

kernel_src=/src/vendor/linux-framework
build_dir=/tmp/kernel-build
artifact_root=/artifacts
module_install_root=/tmp/kernel-modules-install

case "${RUN_TARGET_ARCH}" in
    x86_64)
        kernel_arch=x86_64
        srcarch=x86
        cross_compile=
        target_cc=gcc
        defconfig=/src/vendor/bpfrejit_x86_defconfig
        build_targets="bzImage modules"
        kernel_image_path="${build_dir}/arch/x86/boot/bzImage"
        kernel_image_name=bzImage
        ;;
    arm64)
        kernel_arch=arm64
        srcarch=arm64
        cross_compile=aarch64-linux-gnu-
        target_cc=aarch64-linux-gnu-gcc
        defconfig=/src/vendor/bpfrejit_arm64_defconfig
        build_targets="Image vmlinuz.efi modules"
        kernel_image_path="${build_dir}/arch/arm64/boot/vmlinuz.efi"
        kernel_image_name=vmlinuz.efi
        ;;
    *)
        echo "unsupported RUN_TARGET_ARCH: ${RUN_TARGET_ARCH}" >&2
        exit 1
        ;;
esac

command -v "${target_cc}" >/dev/null
mkdir -p "${build_dir}" "${artifact_root}/kernel" "${artifact_root}/headers" "${artifact_root}/modules"
cp "${defconfig}" "${build_dir}/.config"

"${kernel_src}/scripts/config" --file "${build_dir}/.config" --enable BLK_DEV_LOOP
"${kernel_src}/scripts/config" --file "${build_dir}/.config" --enable VIRTIO_CONSOLE
"${kernel_src}/scripts/config" --file "${build_dir}/.config" --enable EXT4_FS
"${kernel_src}/scripts/config" --file "${build_dir}/.config" --enable JBD2
"${kernel_src}/scripts/config" --file "${build_dir}/.config" --enable FS_MBCACHE

make_args="ARCH=${kernel_arch}"
if [ -n "${cross_compile}" ]; then
    make_args="${make_args} CROSS_COMPILE=${cross_compile}"
fi

make -C "${kernel_src}" O="${build_dir}" ${make_args} olddefconfig
make -C "${kernel_src}" O="${build_dir}" ${make_args} ${build_targets} -j"${IMAGE_BUILD_JOBS}"

test -s "${kernel_image_path}"
test -s "${build_dir}/System.map"
test -s "${build_dir}/Module.symvers"
test -s "${build_dir}/.config"
test -f "${build_dir}/include/config/kernel.release"

kernel_release="$(tr -d '\n' < "${build_dir}/include/config/kernel.release")"
test -n "${kernel_release}"

install -m 0644 "${kernel_image_path}" "${artifact_root}/kernel/${kernel_image_name}"
install -m 0644 "${build_dir}/System.map" "${artifact_root}/kernel/System.map"
install -m 0644 "${build_dir}/Module.symvers" "${artifact_root}/kernel/Module.symvers"
install -m 0644 "${build_dir}/.config" "${artifact_root}/kernel/.config"

if [ "${RUN_TARGET_ARCH}" = "arm64" ]; then
    install -m 0644 "${build_dir}/arch/arm64/boot/Image" "${artifact_root}/kernel/Image"
fi

rm -rf "${module_install_root}"
make -C "${kernel_src}" O="${build_dir}" ${make_args} INSTALL_MOD_PATH="${module_install_root}" DEPMOD=true modules_install >/dev/null
depmod -b "${module_install_root}" "${kernel_release}" >/dev/null
cp -a "${module_install_root}/lib/modules/${kernel_release}" "${artifact_root}/modules/${kernel_release}"
rm -f "${artifact_root}/modules/${kernel_release}/build" "${artifact_root}/modules/${kernel_release}/source"
test -f "${artifact_root}/modules/${kernel_release}/kernel/drivers/block/null_blk/null_blk.ko"
test -f "${artifact_root}/modules/${kernel_release}/kernel/net/sched/sch_netem.ko"

make -C "${kernel_src}" O="${build_dir}" ${make_args} INSTALL_HDR_PATH="${artifact_root}/headers/usr" headers_install
(
    cd "${build_dir}"
    srctree="${kernel_src}" SRCARCH="${srcarch}" MAKE=make CC=gcc HOSTCC=gcc \
        "${kernel_src}/scripts/package/install-extmod-build" "${artifact_root}/headers"
)
install -m 0644 "${build_dir}/vmlinux" "${artifact_root}/headers/vmlinux"
test -f "${artifact_root}/headers/Makefile"
test -f "${artifact_root}/headers/Module.symvers"
test -s "${artifact_root}/headers/vmlinux"
test -f "${artifact_root}/headers/include/config/kernel.release"
test -d "${artifact_root}/headers/arch/${srcarch}/include"

printf '{\n  "kernel_release": "%s",\n  "target_arch": "%s",\n  "kernel_image": "%s"\n}\n' \
    "${kernel_release}" "${RUN_TARGET_ARCH}" "${kernel_image_name}" >"${artifact_root}/manifest.json"

rm -rf "${module_install_root}" "${kernel_src}"
EOF
