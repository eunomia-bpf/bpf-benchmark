#!/bin/bash
# Helper script for `make vm-selftest`.
# Runs kernel REJIT selftest + pre-built tests/unittest/ suite.
# Binaries are built on the host by `make unittest-build` (runner/Makefile).
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

# Part 2: run pre-built tests/unittest/ suite.
# Binaries were built on the host; no in-VM compilation needed.
echo "=== Running tests/unittest/ (pre-built) ==="

PASS=0
FAIL=0

# All tests to run.  Must match tests/unittest/Makefile TESTS variable.
TESTS="rejit_poc rejit_safety_tests rejit_regression rejit_tail_call
       rejit_spectre rejit_kinsn
       rejit_verifier_negative_tests
       rejit_prog_types rejit_audit_tests rejit_swap_tests
       rejit_struct_ops_rollback_tests
       rejit_struct_ops_multi_callsite_tests"

for t in $TESTS; do
    echo "--- $t ---"
    if [ ! -x "${BUILD_DIR}/$t" ]; then
        echo "  ERROR: binary not found: ${BUILD_DIR}/$t"
        FAIL=$((FAIL + 1))
        continue
    fi
    if "${BUILD_DIR}/$t" "${BUILD_DIR}/progs"; then
        PASS=$((PASS + 1))
    else
        FAIL=$((FAIL + 1))
        echo "  FAIL: $t"
    fi
done

echo ""
echo "=== vm-selftest: ${PASS} passed, ${FAIL} failed ==="
if [ "$FAIL" -gt 0 ]; then
    exit 1
fi
echo "=== vm-selftest: ALL PASSED ==="
