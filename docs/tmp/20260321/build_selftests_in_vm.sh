#!/bin/bash
set -e

SELFTESTS_DIR=/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/tools/testing/selftests/bpf
OUTPUT=/home/yunwei37/workspace/bpf-benchmark/docs/tmp/bpf_selftests_bin

mkdir -p "${OUTPUT}"

# Use /var/tmp as TMPDIR since /tmp is read-only in vng
export TMPDIR=/var/tmp

echo "=== VM kernel: $(uname -r) ==="
echo "=== BTF: $(ls /sys/kernel/btf/vmlinux 2>/dev/null && echo present || echo missing) ==="

cd "${SELFTESTS_DIR}"

# Step 1: Build test_verifier (simple, no BPF arena issues)
echo "--- Building test_verifier ---"
make -j$(nproc) \
    CLANG=clang-20 \
    OUTPUT="${OUTPUT}" \
    VMLINUX_BTF=/sys/kernel/btf/vmlinux \
    SKIP_DOCS=1 \
    "${OUTPUT}/test_verifier" 2>&1 | grep -v "^  CC\|^  GEN\|^  LD\|^  LINK\|^  HOSTCC\|^  MKDIR\|^  LIB\|^  BTF\|^  BINARY\|^  EXT-OBJ\|^  AR\|^  INSTALL\|^  MOD\|^  HOSTLD\|^  SIGN\|^  LIB-OBJ\|^  RESOLVE\|^  BTFIDS"

echo "test_verifier build exit: $?"
ls -la "${OUTPUT}/test_verifier" 2>/dev/null && echo "test_verifier OK" || echo "test_verifier FAILED"

# Step 2: Build test_progs with correct BTF from running VM
echo ""
echo "--- Building test_progs ---"
make -j$(nproc) \
    CLANG=clang-20 \
    OUTPUT="${OUTPUT}" \
    VMLINUX_BTF=/sys/kernel/btf/vmlinux \
    SKIP_DOCS=1 \
    "${OUTPUT}/test_progs" 2>&1 | grep -v "^  CC\|^  CLNG-BPF\|^  GEN-SKEL\|^  GEN \|^  LD\|^  LINK\|^  TEST-OBJ\|^  BTF\|^  HOSTCC\|^  HOSTLD\|^  MKDIR\|^  MOD\|^  LIB\|^  EXT-OBJ\|^  LIB-OBJ\|^  AR\|^  SIGN\|^  INSTALL\|^  CP\|^  BINARY\|^  RESOLVE\|^  BTFIDS"

echo "test_progs build exit: $?"
ls -la "${OUTPUT}/test_progs" 2>/dev/null && echo "test_progs OK" || echo "test_progs FAILED"
