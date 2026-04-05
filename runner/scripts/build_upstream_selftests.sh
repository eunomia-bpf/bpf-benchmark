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

die() {
    printf '[build-upstream-selftests][ERROR] %s\n' "$*" >&2
    exit 1
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

require_file "$VMLINUX_BTF"
require_file "$COMPAT_DIR/bpf_smc.skel.h"
require_file "$COMPAT_DIR/remote_selftest_compat.h"
[[ -d "$UPSTREAM_SELFTEST_SOURCE_DIR" ]] || die "selftest source dir is missing: $UPSTREAM_SELFTEST_SOURCE_DIR"

clang_bin="$(resolve_llvm_tool clang)"
cxx_bin="$(resolve_llvm_tool clang++)"
ld_bin="$(resolve_llvm_tool ld.lld)"
llc_bin="$(resolve_llvm_tool llc)"
llvm_config="$(resolve_llvm_tool llvm-config)"
llvm_objcopy="$(resolve_llvm_tool llvm-objcopy)"
llvm_strip="$(resolve_llvm_tool llvm-strip)"

rm -rf "$UPSTREAM_SELFTEST_OUTPUT_DIR"
mkdir -p "$UPSTREAM_SELFTEST_OUTPUT_DIR"
cp "$COMPAT_DIR/bpf_smc.skel.h" "$UPSTREAM_SELFTEST_OUTPUT_DIR/bpf_smc.skel.h"
cp "$COMPAT_DIR/remote_selftest_compat.h" "$UPSTREAM_SELFTEST_OUTPUT_DIR/remote_selftest_compat.h"

make -C "$UPSTREAM_SELFTEST_SOURCE_DIR" -j"$JOBS" \
    CC="$clang_bin" \
    CXX="$cxx_bin" \
    HOSTCC="$clang_bin" \
    HOSTCXX="$cxx_bin" \
    LD="$ld_bin" \
    HOSTLD="$ld_bin" \
    LLVM=1 \
    CLANG="$clang_bin" \
    LLC="$llc_bin" \
    LLVM_CONFIG="$llvm_config" \
    LLVM_OBJCOPY="$llvm_objcopy" \
    LLVM_STRIP="$llvm_strip" \
    VMLINUX_BTF="$VMLINUX_BTF" \
    OUTPUT="$UPSTREAM_SELFTEST_OUTPUT_DIR" \
    TEST_KMODS= \
    SKIP_DOCS=1 \
    "EXTRA_CFLAGS=-include ${UPSTREAM_SELFTEST_OUTPUT_DIR}/remote_selftest_compat.h" \
    "SKEL_BLACKLIST=$UPSTREAM_SELFTEST_SKEL_BLACKLIST" \
    test_verifier test_progs
