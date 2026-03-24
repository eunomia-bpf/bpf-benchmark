#!/bin/bash
# Helper script for `make vm-selftest`.
# Runs kernel recompile selftest + builds and runs tests/unittest/ suite.
#
# Usage: vm-selftest.sh <ROOT_DIR> <KERNEL_SELFTEST> <UNITTEST_DIR> <KINSN_MODULE_DIR>
set -eu

ROOT_DIR="$1"
KERNEL_SELFTEST="$2"
UNITTEST_DIR="$3"
KINSN_MODULE_DIR="$4"
BUILD_DIR="${UNITTEST_DIR}/build"

cd "$ROOT_DIR"

# Load kinsn modules via the unified loader (best-effort).
LOAD_SCRIPT="${ROOT_DIR}/module/load_all.sh"
if [ -x "$LOAD_SCRIPT" ]; then
    "$LOAD_SCRIPT" || true
else
    echo "WARN: module/load_all.sh not found, loading modules manually"
    for ko in "${KINSN_MODULE_DIR}/bpf_rotate.ko" \
              "${KINSN_MODULE_DIR}/bpf_select.ko" \
              "${KINSN_MODULE_DIR}/bpf_extract.ko"; do
        if [ -f "$ko" ]; then
            insmod "$ko" 2>/dev/null || true
        fi
    done
    loaded=$(ls /sys/kernel/btf/bpf_rotate /sys/kernel/btf/bpf_select /sys/kernel/btf/bpf_extract 2>/dev/null | wc -l)
    echo "kinsn modules: ${loaded}/3 loaded"
fi

# Part 1: kernel selftest (test_recompile).
echo "=== Running kernel selftest ==="
"$KERNEL_SELFTEST"

# Part 2: build tests/unittest/ inside VM.
echo "=== Building tests/unittest/ inside VM ==="
make -C "$UNITTEST_DIR" clean all

# Part 3: run tests/unittest/ suite.
echo "=== Running tests/unittest/ ==="
cd "$UNITTEST_DIR"
for t in rejit_poc rejit_safety_tests rejit_regression rejit_tail_call \
         rejit_spectre rejit_kinsn \
         rejit_prog_types rejit_audit_tests; do
    echo "=== $t ==="
    "${BUILD_DIR}/$t" "${BUILD_DIR}/progs" || exit 1
done

echo "=== vm-selftest: ALL PASSED ==="
