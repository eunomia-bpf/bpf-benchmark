#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
UPSTREAM_SELFTEST_SOURCE_DIR="${UPSTREAM_SELFTEST_SOURCE_DIR:?UPSTREAM_SELFTEST_SOURCE_DIR is required}"
UPSTREAM_SELFTEST_OUTPUT_DIR="${UPSTREAM_SELFTEST_OUTPUT_DIR:?UPSTREAM_SELFTEST_OUTPUT_DIR is required}"
VMLINUX_BTF="${VMLINUX_BTF:?VMLINUX_BTF is required}"
JOBS="${JOBS:-1}"
UPSTREAM_SELFTEST_LLVM_SUFFIX="${UPSTREAM_SELFTEST_LLVM_SUFFIX:-}"
UPSTREAM_SELFTEST_HOST_PYTHON_BIN="${UPSTREAM_SELFTEST_HOST_PYTHON_BIN:-python3}"
UPSTREAM_SELFTEST_SELECTION_FILE="$ROOT_DIR/runner/config/upstream_selftests_selection.tsv"
UPSTREAM_SELFTEST_ARCH="${UPSTREAM_SELFTEST_ARCH:-}"
UPSTREAM_SELFTEST_CROSS_COMPILE="${UPSTREAM_SELFTEST_CROSS_COMPILE:-}"
UPSTREAM_SELFTEST_SYSROOT_ROOT="${UPSTREAM_SELFTEST_SYSROOT_ROOT:-}"
UPSTREAM_SELFTEST_PKGCONFIG_LIBDIR="${UPSTREAM_SELFTEST_PKGCONFIG_LIBDIR:-}"
UPSTREAM_SELFTEST_TOOLCHAIN_DIR="${UPSTREAM_SELFTEST_TOOLCHAIN_DIR:-$UPSTREAM_SELFTEST_OUTPUT_DIR/toolchain}"
GENERATED_INCLUDE_DIR="${UPSTREAM_SELFTEST_OUTPUT_DIR}/build-include"
KERNEL_SOURCE_ROOT="$(cd "$UPSTREAM_SELFTEST_SOURCE_DIR/../../../.." && pwd)"

declare -a UPSTREAM_SELFTEST_BUILD_TARGETS=()
declare -a UPSTREAM_SELFTEST_SOURCE_EXCLUDES=()

die() {
    printf '[build-upstream-selftests][ERROR] %s\n' "$*" >&2
    exit 1
}

require_file() {
    local path="$1"
    [[ -f "$path" ]] || die "required file is missing: $path"
}

join_by_space() {
    local out=""
    local item
    for item in "$@"; do
        if [[ -n "$out" ]]; then
            out+=" "
        fi
        out+="$item"
    done
    printf '%s\n' "$out"
}

load_selection_manifest() {
    local manifest="$UPSTREAM_SELFTEST_SELECTION_FILE"
    local line_no=0
    local raw_line=""
    local kind=""
    local value=""
    local reason=""
    declare -A seen=()

    require_file "$manifest"
    while IFS= read -r raw_line || [[ -n "$raw_line" ]]; do
        line_no=$((line_no + 1))
        [[ -z "$raw_line" ]] && continue
        [[ "$raw_line" =~ ^# ]] && continue
        IFS=$'\t' read -r kind value reason <<<"$raw_line"
        [[ -n "$kind" && -n "$value" && -n "$reason" ]] \
            || die "invalid selection entry at ${manifest}:${line_no}; expected <kind><TAB><value><TAB><reason>"
        if [[ -n "${seen["$kind:$value"]:-}" ]]; then
            die "duplicate selection entry at ${manifest}:${line_no}: ${kind} ${value}"
        fi
        seen["$kind:$value"]=1
        case "$kind" in
            make_target)
                UPSTREAM_SELFTEST_BUILD_TARGETS+=("$value")
                ;;
            source_exclude)
                UPSTREAM_SELFTEST_SOURCE_EXCLUDES+=("$value")
                ;;
            *)
                die "unknown selection kind at ${manifest}:${line_no}: ${kind}"
                ;;
        esac
    done <"$manifest"

    [[ "${#UPSTREAM_SELFTEST_BUILD_TARGETS[@]}" -gt 0 ]] \
        || die "selection manifest defines no build targets: ${manifest}"

    printf '[build-upstream-selftests] selection manifest: %s\n' "$manifest"
    printf '[build-upstream-selftests] build targets: %s\n' "$(join_by_space "${UPSTREAM_SELFTEST_BUILD_TARGETS[@]}")"
    if [[ "${#UPSTREAM_SELFTEST_SOURCE_EXCLUDES[@]}" -gt 0 ]]; then
        printf '[build-upstream-selftests] source excludes: %s\n' "$(join_by_space "${UPSTREAM_SELFTEST_SOURCE_EXCLUDES[@]}")"
    fi
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

normalize_kernel_arch() {
    local arch="${1:-}"
    case "$arch" in
        aarch64) printf '%s\n' arm64 ;;
        x86_64) printf '%s\n' x86 ;;
        amd64) printf '%s\n' x86 ;;
        *) printf '%s\n' "$arch" ;;
    esac
}

prepare_generated_include_dir() {
    local kernel_arch="${UPSTREAM_SELFTEST_ARCH:-$(uname -m)}"
    local alt_header=""
    kernel_arch="$(normalize_kernel_arch "$kernel_arch")"

    rm -rf "$GENERATED_INCLUDE_DIR"
    mkdir -p "$GENERATED_INCLUDE_DIR"

    mkdir -p "$GENERATED_INCLUDE_DIR/linux"
    cp "$KERNEL_SOURCE_ROOT/include/linux/kasan-checks.h" "$GENERATED_INCLUDE_DIR/linux/kasan-checks.h"

    alt_header="$KERNEL_SOURCE_ROOT/arch/${kernel_arch}/include/asm/alternative-macros.h"
    if [[ -f "$alt_header" ]]; then
        mkdir -p "$GENERATED_INCLUDE_DIR/asm"
        cp "$alt_header" "$GENERATED_INCLUDE_DIR/asm/alternative-macros.h"
    fi
}

sanitize_generated_vmlinux_header() {
    local header="$UPSTREAM_SELFTEST_OUTPUT_DIR/tools/include/vmlinux.h"
    [[ -f "$header" ]] || die "expected generated vmlinux header is missing: $header"
    command -v "$UPSTREAM_SELFTEST_HOST_PYTHON_BIN" >/dev/null 2>&1 \
        || die "required host python is missing: ${UPSTREAM_SELFTEST_HOST_PYTHON_BIN}"

    "$UPSTREAM_SELFTEST_HOST_PYTHON_BIN" - "$header" <<'PY'
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

prepare_selected_source_dir() {
    if [[ "${#UPSTREAM_SELFTEST_SOURCE_EXCLUDES[@]}" -eq 0 ]]; then
        printf '%s\n' "$UPSTREAM_SELFTEST_SOURCE_DIR"
        return 0
    fi

    local source_root
    local selftests_root
    local kernel_root
    local entry
    local base
    local rel_path
    local selected_root="${UPSTREAM_SELFTEST_OUTPUT_DIR}.source-tree"
    local selected_dir="$selected_root/tools/testing/selftests/bpf"
    local excluded_csv=","

    source_root="$(cd "$UPSTREAM_SELFTEST_SOURCE_DIR/../../.." && pwd)"
    selftests_root="$source_root/testing/selftests"
    kernel_root="$(cd "$UPSTREAM_SELFTEST_SOURCE_DIR/../../../.." && pwd)"

    rm -rf "$selected_root"
    mkdir -p "$selected_root/tools/testing/selftests"
    ln -s "$kernel_root/include" "$selected_root/include"
    ln -s "$kernel_root/arch" "$selected_root/arch"
    ln -s "$source_root/build" "$selected_root/tools/build"
    ln -s "$source_root/scripts" "$selected_root/tools/scripts"
    ln -s "$source_root/lib" "$selected_root/tools/lib"
    ln -s "$source_root/include" "$selected_root/tools/include"
    ln -s "$source_root/arch" "$selected_root/tools/arch"
    ln -s "$source_root/bpf" "$selected_root/tools/bpf"
    ln -s "$kernel_root/kernel" "$selected_root/kernel"
    ln -s "$kernel_root/scripts" "$selected_root/scripts"
    for rel_path in "${UPSTREAM_SELFTEST_SOURCE_EXCLUDES[@]}"; do
        [[ -e "$UPSTREAM_SELFTEST_SOURCE_DIR/$rel_path" ]] \
            || die "selection manifest excludes missing upstream selftest source: $rel_path"
        excluded_csv+="${rel_path},"
    done

    for entry in "$selftests_root"/*; do
        base="$(basename "$entry")"
        [[ "$base" == "bpf" ]] && continue
        ln -s "$entry" "$selected_root/tools/testing/selftests/$base"
    done
    mkdir -p "$selected_dir"
    while IFS= read -r -d '' entry; do
        rel_path="${entry#$UPSTREAM_SELFTEST_SOURCE_DIR/}"
        case "$excluded_csv" in
            *,"${rel_path}",*)
                continue
                ;;
        esac
        if [[ -d "$entry" ]]; then
            mkdir -p "$selected_dir/$rel_path"
            continue
        fi
        mkdir -p "$(dirname "$selected_dir/$rel_path")"
        cp -a "$entry" "$selected_dir/$rel_path"
    done < <(find "$UPSTREAM_SELFTEST_SOURCE_DIR" -mindepth 1 -print0)
    for rel_path in "${UPSTREAM_SELFTEST_SOURCE_EXCLUDES[@]}"; do
        [[ ! -e "$selected_dir/$rel_path" ]] \
            || die "selected upstream selftest exclusion leaked into selected source view: $rel_path"
    done
    printf '%s\n' "$selected_dir"
}

require_file "$VMLINUX_BTF"
[[ -d "$UPSTREAM_SELFTEST_SOURCE_DIR" ]] || die "selftest source dir is missing: $UPSTREAM_SELFTEST_SOURCE_DIR"
load_selection_manifest

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
prepare_generated_include_dir
SOURCE_DIR="$(prepare_selected_source_dir)"

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
        "USERCFLAGS=-I${GENERATED_INCLUDE_DIR}"
        "EXTRA_CFLAGS=-I${GENERATED_INCLUDE_DIR} -D__GLIBC_USE_DEPRECATED_SCANF=1 -D__GLIBC_USE_C2X_STRTOL=0"
    )
else
    make_args+=(
        CC="$clang_bin"
        CXX="$cxx_bin"
        LD="$ld_bin"
        AR="$host_ar_bin"
        "USERCFLAGS=-I${GENERATED_INCLUDE_DIR}"
        "EXTRA_CFLAGS=-I${GENERATED_INCLUDE_DIR}"
    )
fi

make "${make_args[@]}" "$UPSTREAM_SELFTEST_OUTPUT_DIR/tools/include/vmlinux.h"
sanitize_generated_vmlinux_header
make "${make_args[@]}" "${UPSTREAM_SELFTEST_BUILD_TARGETS[@]}"
