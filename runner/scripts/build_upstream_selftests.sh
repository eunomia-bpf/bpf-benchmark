#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
UPSTREAM_SELFTEST_SOURCE_DIR="${UPSTREAM_SELFTEST_SOURCE_DIR:?UPSTREAM_SELFTEST_SOURCE_DIR is required}"
UPSTREAM_SELFTEST_OUTPUT_DIR="${UPSTREAM_SELFTEST_OUTPUT_DIR:?UPSTREAM_SELFTEST_OUTPUT_DIR is required}"
VMLINUX_BTF="${VMLINUX_BTF:?VMLINUX_BTF is required}"
JOBS="${JOBS:-1}"
UPSTREAM_SELFTEST_LLVM_SUFFIX="${UPSTREAM_SELFTEST_LLVM_SUFFIX:-}"
UPSTREAM_SELFTEST_SKEL_BLACKLIST="${UPSTREAM_SELFTEST_SKEL_BLACKLIST:-btf__% test_pinning_invalid.c test_sk_assign.c bpf_smc.c}"
COMPAT_DIR="${UPSTREAM_SELFTEST_COMPAT_DIR:-$ROOT_DIR/runner/compat/upstream_selftests}"
UPSTREAM_SELFTEST_ARCH="${UPSTREAM_SELFTEST_ARCH:-}"
UPSTREAM_SELFTEST_CROSS_COMPILE="${UPSTREAM_SELFTEST_CROSS_COMPILE:-}"
UPSTREAM_SELFTEST_SYSROOT_ROOT="${UPSTREAM_SELFTEST_SYSROOT_ROOT:-}"
UPSTREAM_SELFTEST_PKGCONFIG_LIBDIR="${UPSTREAM_SELFTEST_PKGCONFIG_LIBDIR:-}"
UPSTREAM_SELFTEST_TOOLCHAIN_DIR="${UPSTREAM_SELFTEST_TOOLCHAIN_DIR:-$UPSTREAM_SELFTEST_OUTPUT_DIR/toolchain}"

die() {
    printf '[build-upstream-selftests][ERROR] %s\n' "$*" >&2
    exit 1
}

blacklist_has_entry() {
    local needle="$1"
    local entry
    for entry in $UPSTREAM_SELFTEST_SKEL_BLACKLIST; do
        [[ "$entry" == "$needle" ]] && return 0
    done
    return 1
}

require_file() {
    local path="$1"
    [[ -f "$path" ]] || die "required file is missing: $path"
}

resolve_llvm_tool() {
    local base="$1"
    local suffix="${UPSTREAM_SELFTEST_LLVM_SUFFIX:-}"
    local candidate

    if [[ -n "$suffix" ]]; then
        for candidate in "${base}-${suffix}" "${base}${suffix}"; do
            if command -v "$candidate" >/dev/null 2>&1; then
                printf '%s\n' "$candidate"
                return 0
            fi
        done
    fi

    command -v "$base" >/dev/null 2>&1 || die "required LLVM tool is missing: ${base}"
    printf '%s\n' "$base"
}

prepare_cross_toolchain() {
    local cross_bin_dir="$UPSTREAM_SELFTEST_TOOLCHAIN_DIR"
    local cross_cc="${UPSTREAM_SELFTEST_CROSS_COMPILE}gcc"
    local cross_cxx="${UPSTREAM_SELFTEST_CROSS_COMPILE}g++"
    local cross_ld="${UPSTREAM_SELFTEST_CROSS_COMPILE}ld"
    local cross_ar="${UPSTREAM_SELFTEST_CROSS_COMPILE}ar"

    [[ -n "$UPSTREAM_SELFTEST_ARCH" ]] || die "UPSTREAM_SELFTEST_ARCH is required in cross mode"
    [[ -n "$UPSTREAM_SELFTEST_CROSS_COMPILE" ]] || die "UPSTREAM_SELFTEST_CROSS_COMPILE is required in cross mode"
    [[ -n "$UPSTREAM_SELFTEST_SYSROOT_ROOT" ]] || die "UPSTREAM_SELFTEST_SYSROOT_ROOT is required in cross mode"
    [[ -n "$UPSTREAM_SELFTEST_PKGCONFIG_LIBDIR" ]] || die "UPSTREAM_SELFTEST_PKGCONFIG_LIBDIR is required in cross mode"
    command -v "$cross_cc" >/dev/null 2>&1 || die "missing cross compiler: $cross_cc"
    command -v "$cross_cxx" >/dev/null 2>&1 || die "missing cross compiler: $cross_cxx"
    command -v "$cross_ld" >/dev/null 2>&1 || die "missing cross linker: $cross_ld"
    command -v "$cross_ar" >/dev/null 2>&1 || die "missing cross archiver: $cross_ar"

    rm -rf "$cross_bin_dir"
    mkdir -p "$cross_bin_dir"

    cat >"$cross_bin_dir/cc" <<EOF
#!/usr/bin/env bash
exec "$cross_cc" --sysroot="$UPSTREAM_SELFTEST_SYSROOT_ROOT" "\$@"
EOF
    cat >"$cross_bin_dir/cxx" <<EOF
#!/usr/bin/env bash
exec "$cross_cxx" --sysroot="$UPSTREAM_SELFTEST_SYSROOT_ROOT" "\$@"
EOF
    cat >"$cross_bin_dir/ld" <<EOF
#!/usr/bin/env bash
exec "$cross_ld" --sysroot="$UPSTREAM_SELFTEST_SYSROOT_ROOT" "\$@"
EOF
    cat >"$cross_bin_dir/pkg-config" <<EOF
#!/usr/bin/env bash
export PKG_CONFIG_SYSROOT_DIR="$UPSTREAM_SELFTEST_SYSROOT_ROOT"
export PKG_CONFIG_LIBDIR="$UPSTREAM_SELFTEST_PKGCONFIG_LIBDIR"
exec pkg-config "\$@"
EOF
    chmod +x "$cross_bin_dir/cc" "$cross_bin_dir/cxx" "$cross_bin_dir/ld" "$cross_bin_dir/pkg-config"
}

sanitize_generated_vmlinux_header() {
    local header="$UPSTREAM_SELFTEST_OUTPUT_DIR/tools/include/vmlinux.h"
    [[ -f "$header" ]] || die "expected generated vmlinux header is missing: $header"

    python3 - "$header" <<'PY'
import pathlib
import sys

header = pathlib.Path(sys.argv[1])
targets = (
    "bpf_arena_alloc_pages(",
    "bpf_arena_free_pages(",
    "bpf_arena_reserve_pages(",
    "bpf_path_d_path(",
)
lines = header.read_text().splitlines()
filtered = [line for line in lines if not any(t in line for t in targets)]
header.write_text("\n".join(filtered) + "\n")
PY
}

prepare_filtered_source_dir() {
    if ! blacklist_has_entry "bpf_smc.c"; then
        printf '%s\n' "$UPSTREAM_SELFTEST_SOURCE_DIR"
        return 0
    fi

    local source_root
    local selftests_root
    local kernel_root
    local entry
    local base
    local filtered_root="${UPSTREAM_SELFTEST_OUTPUT_DIR}.source-tree"
    local filtered_dir="$filtered_root/tools/testing/selftests/bpf"

    source_root="$(cd "$UPSTREAM_SELFTEST_SOURCE_DIR/../../.." && pwd)"
    selftests_root="$source_root/testing/selftests"
    kernel_root="$(cd "$UPSTREAM_SELFTEST_SOURCE_DIR/../../../.." && pwd)"

    rm -rf "$filtered_root"
    mkdir -p "$filtered_root/tools/testing/selftests"
    ln -s "$kernel_root/include" "$filtered_root/include"
    ln -s "$kernel_root/arch" "$filtered_root/arch"
    ln -s "$source_root/build" "$filtered_root/tools/build"
    ln -s "$source_root/scripts" "$filtered_root/tools/scripts"
    ln -s "$source_root/lib" "$filtered_root/tools/lib"
    ln -s "$source_root/include" "$filtered_root/tools/include"
    ln -s "$source_root/arch" "$filtered_root/tools/arch"
    ln -s "$source_root/bpf" "$filtered_root/tools/bpf"
    ln -s "$kernel_root/kernel" "$filtered_root/kernel"
    ln -s "$kernel_root/scripts" "$filtered_root/scripts"
    for entry in "$selftests_root"/*; do
        base="$(basename "$entry")"
        [[ "$base" == "bpf" ]] && continue
        ln -s "$entry" "$filtered_root/tools/testing/selftests/$base"
    done
    cp -a "$UPSTREAM_SELFTEST_SOURCE_DIR/." "$filtered_dir/"
    rm -f "$filtered_dir/progs/bpf_smc.c" "$filtered_dir/prog_tests/test_bpf_smc.c"
    printf '%s\n' "$filtered_dir"
}

require_file "$VMLINUX_BTF"
require_file "$COMPAT_DIR/bpf_smc.skel.h"
require_file "$COMPAT_DIR/remote_selftest_compat.h"
require_file "$COMPAT_DIR/linux/kasan-checks.h"
[[ -d "$UPSTREAM_SELFTEST_SOURCE_DIR" ]] || die "selftest source dir is missing: $UPSTREAM_SELFTEST_SOURCE_DIR"

clang_bin="$(resolve_llvm_tool clang)"
cxx_bin="$(resolve_llvm_tool clang++)"
ld_bin="$(resolve_llvm_tool ld.lld)"
host_ar_bin="$(resolve_llvm_tool llvm-ar)"
llc_bin="$(resolve_llvm_tool llc)"
llvm_config="$(resolve_llvm_tool llvm-config)"
llvm_objcopy="$(resolve_llvm_tool llvm-objcopy)"
llvm_strip="$(resolve_llvm_tool llvm-strip)"

rm -rf "$UPSTREAM_SELFTEST_OUTPUT_DIR"
mkdir -p "$UPSTREAM_SELFTEST_OUTPUT_DIR"
cp "$COMPAT_DIR/bpf_smc.skel.h" "$UPSTREAM_SELFTEST_OUTPUT_DIR/bpf_smc.skel.h"
cp "$COMPAT_DIR/remote_selftest_compat.h" "$UPSTREAM_SELFTEST_OUTPUT_DIR/remote_selftest_compat.h"
SOURCE_DIR="$(prepare_filtered_source_dir)"

make_args=(
    -C "$SOURCE_DIR"
    -j"$JOBS"
    LLVM=1
    CLANG="$clang_bin"
    LLC="$llc_bin"
    LLVM_CONFIG="$llvm_config"
    LLVM_OBJCOPY="$llvm_objcopy"
    LLVM_STRIP="$llvm_strip"
    HOSTCC="$clang_bin"
    HOSTCXX="$cxx_bin"
    HOSTLD="$ld_bin"
    HOSTAR="$host_ar_bin"
    VMLINUX_BTF="$VMLINUX_BTF"
    OUTPUT="$UPSTREAM_SELFTEST_OUTPUT_DIR"
    TEST_KMODS=
    SKIP_DOCS=1
    "SKEL_BLACKLIST=$UPSTREAM_SELFTEST_SKEL_BLACKLIST"
)

if [[ -n "$UPSTREAM_SELFTEST_CROSS_COMPILE" ]]; then
    prepare_cross_toolchain
    make_args+=(
        ARCH="$UPSTREAM_SELFTEST_ARCH"
        CROSS_COMPILE="$UPSTREAM_SELFTEST_CROSS_COMPILE"
        CC="$UPSTREAM_SELFTEST_TOOLCHAIN_DIR/cc"
        CXX="$UPSTREAM_SELFTEST_TOOLCHAIN_DIR/cxx"
        LD="$UPSTREAM_SELFTEST_TOOLCHAIN_DIR/ld"
        AR="${UPSTREAM_SELFTEST_CROSS_COMPILE}ar"
        PKG_CONFIG="$UPSTREAM_SELFTEST_TOOLCHAIN_DIR/pkg-config"
        "USERCFLAGS=-I${COMPAT_DIR}"
        "EXTRA_CFLAGS=-include ${UPSTREAM_SELFTEST_OUTPUT_DIR}/remote_selftest_compat.h -I${COMPAT_DIR} -D__GLIBC_USE_DEPRECATED_SCANF=1 -D__GLIBC_USE_C2X_STRTOL=0"
    )
else
    make_args+=(
        CC="$clang_bin"
        CXX="$cxx_bin"
        LD="$ld_bin"
        AR="$host_ar_bin"
        "USERCFLAGS=-I${COMPAT_DIR}"
        "EXTRA_CFLAGS=-include ${UPSTREAM_SELFTEST_OUTPUT_DIR}/remote_selftest_compat.h -I${COMPAT_DIR}"
    )
fi

make "${make_args[@]}" "$UPSTREAM_SELFTEST_OUTPUT_DIR/tools/include/vmlinux.h"
sanitize_generated_vmlinux_header
make "${make_args[@]}" test_verifier test_progs
