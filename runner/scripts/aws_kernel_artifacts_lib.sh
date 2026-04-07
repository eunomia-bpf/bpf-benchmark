#!/usr/bin/env bash
set -euo pipefail

# Internal AWS host-side kernel/cache/build helpers.
# This file must be sourced only after:
# - aws_common_lib.sh
# - aws_prep_paths_lib.sh
#
# It expects shared helpers such as `die`, `log`, `ensure_dirs`,
# `with_locked_file`, `ssh_bash`, and `remote_kernel_release` to already exist.

elf_has_btf() {
    local elf_path="$1"
    readelf -S "$elf_path" 2>/dev/null | grep -F '.BTF' >/dev/null
}

snapshot_kinsn_module_source_tree() {
    local arch_dir_rel="$1"
    local dest_dir="$2"
    local parent_dir
    parent_dir="$(dirname "$dest_dir")"
    rm -rf "$dest_dir" "$parent_dir/include"
    mkdir -p "$parent_dir"
    snapshot_git_subtree "$ROOT_DIR" "module/include" "$parent_dir/include"
    snapshot_git_subtree "$ROOT_DIR" "$arch_dir_rel" "$dest_dir"
}

x86_cached_kinsn_modules_dir() {
    local cache_dir="$1"
    printf '%s\n' "$cache_dir/kinsn-modules/x86"
}

x86_cached_setup_config_fingerprint_path() {
    local cache_dir="$1"
    printf '%s\n' "$cache_dir/config.sha256"
}

x86_setup_config_fingerprint() {
    require_local_path "$KERNEL_DIR/.config" "x86 kernel config"
    sha256sum "$KERNEL_DIR/.config" | awk '{print $1}'
}

x86_cached_setup_matches_config() {
    local cache_dir="$1"
    local expected_fingerprint="$2"
    local fingerprint_path actual_fingerprint
    fingerprint_path="$(x86_cached_setup_config_fingerprint_path "$cache_dir")"
    [[ -f "$fingerprint_path" ]] || return 1
    actual_fingerprint="$(<"$fingerprint_path")"
    [[ -n "$actual_fingerprint" && "$actual_fingerprint" == "$expected_fingerprint" ]]
}

x86_write_cached_setup_fingerprint() {
    local cache_dir="$1"
    local fingerprint="$2"
    printf '%s\n' "$fingerprint" >"$(x86_cached_setup_config_fingerprint_path "$cache_dir")"
}

x86_cached_setup_artifacts_ready() {
    local cache_dir="$1"
    local kernel_release="$2"
    local kernel_image_filename="$3"
    local config_fingerprint="$4"
    cached_setup_artifacts_ready "$cache_dir" "$kernel_release" "$kernel_image_filename" \
        && x86_cached_setup_matches_config "$cache_dir" "$config_fingerprint"
}

x86_reuse_cached_setup_artifacts() {
    local cache_dir="$1"
    local kernel_release="$2"
    local kernel_image_filename="$3"
    local config_fingerprint="$4"
    x86_cached_setup_artifacts_ready "$cache_dir" "$kernel_release" "$kernel_image_filename" "$config_fingerprint" \
        || return 1
    link_cached_setup_artifacts "$cache_dir" "$kernel_release" "$kernel_image_filename"
    BUILD_KERNEL_RELEASE="$kernel_release"
    return 0
}

x86_cached_kinsn_modules_ready() {
    local cache_dir="$1"
    local kernel_release="$2"
    local module_dir module_path actual_release
    module_dir="$(x86_cached_kinsn_modules_dir "$cache_dir")"
    [[ -d "$module_dir" ]] || return 1
    find "$module_dir" -maxdepth 1 -type f -name '*.ko' -print -quit 2>/dev/null | grep -q . || return 1
    while IFS= read -r -d '' module_path; do
        actual_release="$(modinfo -F vermagic "$module_path" 2>/dev/null | awk '{print $1}')"
        [[ "$actual_release" == "$kernel_release" ]] || return 1
    done < <(find "$module_dir" -maxdepth 1 -type f -name '*.ko' -print0)
    return 0
}

build_x86_kinsn_modules_into_cache() {
    local cache_dir="$1"
    local cached_module_dir
    snapshot_kinsn_module_source_tree "module/x86" "$X86_KINSN_MODULE_BUILD_SRC"
    make -C "$X86_KINSN_MODULE_BUILD_SRC" KDIR="$KERNEL_DIR" clean >/dev/null
    make -C "$X86_KINSN_MODULE_BUILD_SRC" KDIR="$KERNEL_DIR" >/dev/null
    cached_module_dir="$(x86_cached_kinsn_modules_dir "$cache_dir")"
    stage_module_binaries "$X86_KINSN_MODULE_BUILD_SRC" "$cached_module_dir"
}

arm64_cached_kinsn_modules_dir() {
    local cache_dir="$1"
    printf '%s\n' "$cache_dir/kinsn-modules/arm64"
}

arm64_cached_kinsn_modules_ready() {
    local cache_dir="$1"
    local kernel_release="$2"
    local module_dir module_path actual_release
    module_dir="$(arm64_cached_kinsn_modules_dir "$cache_dir")"
    [[ -d "$module_dir" ]] || return 1
    find "$module_dir" -maxdepth 1 -type f -name '*.ko' -print -quit 2>/dev/null | grep -q . || return 1
    while IFS= read -r -d '' module_path; do
        actual_release="$(modinfo -F vermagic "$module_path" 2>/dev/null | awk '{print $1}')"
        [[ "$actual_release" == "$kernel_release" ]] || return 1
    done < <(find "$module_dir" -maxdepth 1 -type f -name '*.ko' -print0)
    return 0
}

cached_setup_artifacts_ready() {
    local cache_dir="$1"
    local kernel_release="$2"
    local kernel_image_filename="$3"
    [[ -f "$cache_dir/vmlinux-$kernel_release" ]] \
        && [[ -f "$cache_dir/$kernel_image_filename" ]] \
        && [[ -f "$cache_dir/modules-$kernel_release.tar.gz" ]]
}

link_cached_setup_artifacts() {
    local cache_dir="$1"
    local kernel_release="$2"
    local kernel_image_filename="$3"
    rm -rf "$ARTIFACT_DIR"
    mkdir -p "$ARTIFACT_DIR"
    ln -sfn "$cache_dir/vmlinux-$kernel_release" "$ARTIFACT_DIR/vmlinux-$kernel_release"
    ln -sfn "$cache_dir/$kernel_image_filename" "$ARTIFACT_DIR/$kernel_image_filename"
    ln -sfn "$cache_dir/modules-$kernel_release.tar.gz" "$ARTIFACT_DIR/modules-$kernel_release.tar.gz"
}

reuse_cached_setup_artifacts() {
    local cache_dir="$1"
    local kernel_release="$2"
    local kernel_image_filename="$3"
    cached_setup_artifacts_ready "$cache_dir" "$kernel_release" "$kernel_image_filename" || return 1
    link_cached_setup_artifacts "$cache_dir" "$kernel_release" "$kernel_image_filename"
    BUILD_KERNEL_RELEASE="$kernel_release"
    return 0
}

with_x86_kernel_lock() {
    with_locked_file "$X86_KERNEL_BUILD_LOCK_FILE" "$@"
}

with_arm64_kernel_lock() {
    with_locked_file "$ARM64_KERNEL_BUILD_LOCK_FILE" "$@"
}

modules_tar_has_entry() {
    local modules_tar="$1"
    local pattern="$2"
    tar -tzf "$modules_tar" 2>/dev/null | grep -E "$pattern" >/dev/null
}

config_symbol_value() {
    local config_path="$1"
    local symbol="$2"
    if grep -Eq "^${symbol}=y$" "$config_path"; then printf 'y\n'; return 0; fi
    if grep -Eq "^${symbol}=m$" "$config_path"; then printf 'm\n'; return 0; fi
    if grep -Eq "^# ${symbol} is not set$" "$config_path"; then printf 'n\n'; return 0; fi
    printf 'unknown\n'
}

prepare_x86_aws_config_locked() {
    local config_file="$KERNEL_DIR/.config"
    local config_script="$KERNEL_DIR/scripts/config"
    require_local_path "$KERNEL_DEFCONFIG_SRC" "x86 kernel defconfig"
    require_local_path "$config_script" "x86 kernel config helper"
    cp "$KERNEL_DEFCONFIG_SRC" "$config_file"
    "$config_script" --file "$config_file" \
        --enable UNWINDER_ORC \
        --disable UNWINDER_FRAME_POINTER \
        --disable DEBUG_INFO_BTF_MODULES \
        --set-str SYSTEM_TRUSTED_KEYS "" \
        --set-str SYSTEM_REVOCATION_KEYS "" \
        --enable NET_VENDOR_AMAZON \
        --enable ENA_ETHERNET \
        --module NVME_CORE \
        --module BLK_DEV_NVME \
        --module XFS_FS \
        --module EXT4_FS \
        --enable VIRTIO_NET \
        --enable VIRTIO_PCI \
        --module VIRTIO_BLK
    rm -f "$KERNEL_CONFIG_STAMP_FILE"
    make -C "$KERNEL_DIR" olddefconfig >/dev/null
}

build_x86_kernel_artifacts_locked() {
    local kernel_release modules_root cached_dir cached_stage config_fingerprint
    BUILD_KERNEL_RELEASE=""
    prepare_x86_aws_config_locked
    config_fingerprint="$(x86_setup_config_fingerprint)"
    log "Building x86 AWS kernel image and modules"
    make -C "$KERNEL_DIR" -j"$(nproc)" bzImage modules_prepare >/dev/null
    if [[ -f "$KERNEL_DIR/vmlinux.symvers" ]]; then
        cp "$KERNEL_DIR/vmlinux.symvers" "$KERNEL_DIR/Module.symvers"
    fi

    kernel_release="$(<"$KERNEL_DIR/include/config/kernel.release")"
    [[ -n "$kernel_release" ]] || die "x86 kernel release is empty"
    cached_dir="$X86_SETUP_ARTIFACT_ROOT/$kernel_release"
    if x86_reuse_cached_setup_artifacts "$cached_dir" "$kernel_release" "bzImage-$kernel_release" "$config_fingerprint"; then
        modules_tar_has_entry "$cached_dir/modules-$kernel_release.tar.gz" '/modules\.dep$' \
            || rm -rf "$cached_dir"
    fi
    if x86_reuse_cached_setup_artifacts "$cached_dir" "$kernel_release" "bzImage-$kernel_release" "$config_fingerprint"; then
        x86_cached_kinsn_modules_ready "$cached_dir" "$kernel_release" || rm -rf "$cached_dir"
    fi
    if x86_reuse_cached_setup_artifacts "$cached_dir" "$kernel_release" "bzImage-$kernel_release" "$config_fingerprint"; then
        return 0
    fi
    cached_stage="$cached_dir/modules-stage"
    rm -rf "$cached_dir"
    mkdir -p "$cached_dir" "$cached_stage"
    make -C "$KERNEL_DIR" -j"$(nproc)" modules >/dev/null
    make -C "$KERNEL_DIR" INSTALL_MOD_PATH="$cached_stage" modules_install >/dev/null
    rm -f "$cached_stage/lib/modules/$kernel_release/build" "$cached_stage/lib/modules/$kernel_release/source"
    modules_root="$cached_stage/lib/modules/$kernel_release"
    require_local_path "$modules_root/kernel/drivers/nvme/host/nvme-core.ko" "x86 nvme-core module"
    require_local_path "$modules_root/kernel/drivers/nvme/host/nvme.ko" "x86 nvme module"
    require_local_path "$modules_root/kernel/fs/ext4/ext4.ko" "x86 ext4 module"
    require_local_path "$modules_root/kernel/fs/xfs/xfs.ko" "x86 xfs module"
    require_local_path "$modules_root/kernel/drivers/block/virtio_blk.ko" "x86 virtio_blk module"
    cp "$X86_VMLINUX" "$cached_dir/vmlinux-$kernel_release"
    cp "$X86_BZIMAGE" "$cached_dir/bzImage-$kernel_release"
    tar -C "$cached_stage" -czf "$cached_dir/modules-$kernel_release.tar.gz" lib/modules
    rm -rf "$cached_stage"
    modules_tar_has_entry "$cached_dir/modules-$kernel_release.tar.gz" '/modules\.dep$' \
        || die "generated x86 modules archive is invalid"
    build_x86_kinsn_modules_into_cache "$cached_dir"
    x86_cached_kinsn_modules_ready "$cached_dir" "$kernel_release" \
        || die "generated x86 kinsn module cache is invalid"
    x86_write_cached_setup_fingerprint "$cached_dir" "$config_fingerprint"
    link_cached_setup_artifacts "$cached_dir" "$kernel_release" "bzImage-$kernel_release"
    BUILD_KERNEL_RELEASE="$kernel_release"
}

build_x86_kernel_artifacts() {
    ensure_dirs
    with_x86_kernel_lock build_x86_kernel_artifacts_locked
}

arm64_build_config_matches_aws_base() {
    local current_config="$ARM64_AWS_BUILD_DIR/.config"
    local symbol base_value current_value
    [[ -f "$ARM64_AWS_BASE_CONFIG" && -f "$current_config" ]] || return 1
    for symbol in CONFIG_MODVERSIONS CONFIG_MODULE_SIG CONFIG_MODULE_SIG_ALL CONFIG_LOCALVERSION_AUTO; do
        base_value="$(config_symbol_value "$ARM64_AWS_BASE_CONFIG" "$symbol")"
        current_value="$(config_symbol_value "$current_config" "$symbol")"
        [[ "$base_value" == "$current_value" ]] || return 1
    done
    return 0
}

refresh_aws_arm64_base_config() {
    local ip="$1"
    local remote_release tmp_config
    remote_release="$(remote_kernel_release "$ip")"
    if [[ "$remote_release" != *.amzn2023.aarch64 ]]; then
        if [[ -f "$ARM64_AWS_BASE_CONFIG" ]]; then
            log "Keeping cached AWS ARM64 base config; current remote kernel is ${remote_release}"
            return 0
        fi
        die "cannot seed AWS ARM64 base config from non-stock kernel ${remote_release}; relaunch a fresh AL2023 instance"
    fi
    tmp_config="$(mktemp "${TARGET_CACHE_DIR}/config-al2023-arm64.XXXXXX")"
    if ! ssh_bash "$ip" <<'EOF' >"$tmp_config"
set -euo pipefail
release="$(uname -r)"
if [[ -r "/boot/config-$release" ]]; then
    cat "/boot/config-$release"
    exit 0
fi
if command -v zcat >/dev/null 2>&1 && [[ -r /proc/config.gz ]]; then
    zcat /proc/config.gz
    exit 0
fi
exit 1
EOF
    then
        rm -f "$tmp_config"
        die "failed to capture AWS ARM64 base kernel config from ${ip}"
    fi
    grep -F 'CONFIG_ARM64=y' "$tmp_config" >/dev/null || die "captured AWS ARM64 base config is invalid: ${tmp_config}"
    mv "$tmp_config" "$ARM64_AWS_BASE_CONFIG"
}

rebuild_arm64_kinsn_modules() {
    snapshot_kinsn_module_source_tree "module/arm64" "$ARM64_KINSN_MODULE_BUILD_SRC"
    make -C "$ARM64_WORKTREE_DIR" O="$ARM64_AWS_BUILD_DIR" \
        ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
        modules_prepare >/dev/null
    make -C "$ARM64_WORKTREE_DIR" O="$ARM64_AWS_BUILD_DIR" \
        ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
        M="$ARM64_KINSN_MODULE_BUILD_SRC" modules >/dev/null
}

build_arm64_kinsn_modules_into_cache() {
    local cache_dir="$1"
    local cached_module_dir
    rebuild_arm64_kinsn_modules
    cached_module_dir="$(arm64_cached_kinsn_modules_dir "$cache_dir")"
    stage_module_binaries "$ARM64_KINSN_MODULE_BUILD_SRC" "$cached_module_dir"
}

rebuild_arm64_upstream_test_kmods() {
    require_local_path "$ARM64_UPSTREAM_TEST_KMODS_SOURCE_DIR" "ARM64 upstream selftest kmod source dir"
    rm -rf "$ARM64_UPSTREAM_TEST_KMODS_DIR"
    mkdir -p "$(dirname "$ARM64_UPSTREAM_TEST_KMODS_DIR")"
    cp -a "$ARM64_UPSTREAM_TEST_KMODS_SOURCE_DIR" "$ARM64_UPSTREAM_TEST_KMODS_DIR"
    rm -f \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR"/*.ko \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR"/*.o \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR"/*.mod \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR"/*.mod.c \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR"/.*.cmd \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR"/.module-common.o \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR"/Module.symvers \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR"/modules.order
    make -C "$ARM64_WORKTREE_DIR" O="$ARM64_AWS_BUILD_DIR" \
        ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
        M="$ARM64_UPSTREAM_TEST_KMODS_DIR" modules >/dev/null
}

efi_binary_is_valid() {
    local image_path="$1"
    [[ -f "$image_path" ]] || return 1
    file "$image_path" 2>/dev/null | grep -F 'EFI application' >/dev/null
}

build_arm64_kernel_artifacts_locked() {
    local kernel_release cached_dir cached_stage
    BUILD_KERNEL_RELEASE=""
    rm -f \
        "$ARM64_AWS_BUILD_DIR/.config" \
        "$ARM64_AWS_BUILD_DIR/arch/arm64/boot/Image" \
        "$ARM64_AWS_BUILD_DIR/arch/arm64/boot/vmlinuz" \
        "$ARM64_AWS_BUILD_DIR/arch/arm64/boot/vmlinuz.efi" \
        "$ARM64_AWS_BUILD_DIR/arch/arm64/boot/vmlinuz.efi.elf" \
        "$ARM64_AWS_BUILD_DIR/vmlinux"
    log "Building ARM64 AWS kernel image and modules"
    ARM64_AWS_BUILD_DIR="$ARM64_AWS_BUILD_DIR" ARM64_AWS_BASE_CONFIG="$ARM64_AWS_BASE_CONFIG" \
        make -C "$ROOT_DIR" kernel-arm64-aws >/dev/null
    kernel_release="$(<"$ARM64_AWS_BUILD_DIR/include/config/kernel.release")"
    [[ -n "$kernel_release" ]] || die "ARM64 kernel release is empty"
    cached_dir="$ARM64_SETUP_ARTIFACT_ROOT/$kernel_release"
    if reuse_cached_setup_artifacts "$cached_dir" "$kernel_release" "vmlinuz-$kernel_release.efi"; then
        elf_has_btf "$cached_dir/vmlinux-$kernel_release" || die "cached ARM64 vmlinux is missing .BTF"
        efi_binary_is_valid "$cached_dir/vmlinuz-$kernel_release.efi" || die "cached ARM64 EFI kernel image is invalid"
        modules_tar_has_entry "$cached_dir/modules-$kernel_release.tar.gz" '/modules\.dep$' || die "cached ARM64 modules archive is missing modules.dep"
        return 0
    fi
    make -C "$ARM64_WORKTREE_DIR" O="$ARM64_AWS_BUILD_DIR" \
        ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
        modules -j"$(nproc)" >/dev/null
    cached_stage="$cached_dir/modules-stage"
    rm -rf "$cached_dir"
    mkdir -p "$cached_dir" "$cached_stage"
    make -C "$ARM64_WORKTREE_DIR" O="$ARM64_AWS_BUILD_DIR" \
        ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
        INSTALL_MOD_PATH="$cached_stage" modules_install >/dev/null
    rm -f "$cached_stage/lib/modules/$kernel_release/build" "$cached_stage/lib/modules/$kernel_release/source"
    require_local_path "$ARM64_AWS_BUILD_DIR/vmlinux" "ARM64 vmlinux"
    require_local_path "$ARM64_AWS_BUILD_DIR/arch/arm64/boot/vmlinuz.efi" "ARM64 EFI kernel image"
    cp "$ARM64_AWS_BUILD_DIR/vmlinux" "$cached_dir/vmlinux-$kernel_release"
    cp "$ARM64_AWS_BUILD_DIR/arch/arm64/boot/vmlinuz.efi" "$cached_dir/vmlinuz-$kernel_release.efi"
    tar -C "$cached_stage" -czf "$cached_dir/modules-$kernel_release.tar.gz" lib/modules
    rm -rf "$cached_stage"
    elf_has_btf "$cached_dir/vmlinux-$kernel_release" || die "generated ARM64 vmlinux is missing .BTF"
    efi_binary_is_valid "$cached_dir/vmlinuz-$kernel_release.efi" || die "generated ARM64 EFI kernel image is invalid"
    modules_tar_has_entry "$cached_dir/modules-$kernel_release.tar.gz" '/modules\.dep$' || die "generated ARM64 modules archive is missing modules.dep"
    link_cached_setup_artifacts "$cached_dir" "$kernel_release" "vmlinuz-$kernel_release.efi"
    BUILD_KERNEL_RELEASE="$kernel_release"
}

build_arm64_kernel_artifacts() {
    ensure_dirs
    with_arm64_kernel_lock build_arm64_kernel_artifacts_locked
}
