#!/bin/bash
# Helper script for `make vm-selftest`.
# Runs pre-built tests/unittest/ suite + tests/negative/ adversarial suite.
# Binaries are built on the host by `make unittest-build` and `make negative-build`
# (runner/Makefile).
#
# Usage:
#   vm-selftest.sh <ROOT_DIR> <UNITTEST_DIR> <KINSN_MODULE_DIR> <NEGATIVE_DIR>
#                 [FUZZ_ROUNDS] [UNITTEST_BUILD_DIR] [NEGATIVE_BUILD_DIR]
set -eu

ROOT_DIR="$1"
UNITTEST_DIR="$2"
KINSN_MODULE_DIR="$3"
NEGATIVE_DIR="$4"
FUZZ_ROUNDS="${5:-1000}"
BUILD_DIR="${6:-${UNITTEST_DIR}/build}"
NEGATIVE_BUILD_DIR="${7:-${NEGATIVE_DIR}/build}"

cd "$ROOT_DIR"

export BPFREJIT_PROGS_DIR="${BUILD_DIR}/progs"
export BPFREJIT_DAEMON_PATH="${BPFREJIT_DAEMON_PATH:-${ROOT_DIR}/daemon/target/release/bpfrejit-daemon}"

# Load kinsn modules via the unified loader.
LOAD_SCRIPT="${ROOT_DIR}/module/load_all.sh"
if [ ! -x "$LOAD_SCRIPT" ]; then
    echo "ERROR: module/load_all.sh not found or not executable: $LOAD_SCRIPT"
    exit 1
fi
"$LOAD_SCRIPT" "$KINSN_MODULE_DIR"

PASS=0
FAIL=0

# Part 1: run pre-built tests/unittest/ suite.
echo "=== Running tests/unittest/ (pre-built) ==="

# Auto-discover all rejit_* test binaries from the build directory.
TESTS=$(find "$BUILD_DIR" -maxdepth 1 -name 'rejit_*' -executable -printf '%f\n' 2>/dev/null | sort)
if [ -z "$TESTS" ]; then
    echo "ERROR: no rejit_* test binaries found in $BUILD_DIR"
    FAIL=$((FAIL + 1))
fi

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

# Part 2: run pre-built tests/negative/ adversarial suite.
echo ""
echo "=== Running tests/negative/ (pre-built) ==="

echo "--- adversarial_rejit ---"
if [ ! -x "${NEGATIVE_BUILD_DIR}/adversarial_rejit" ]; then
    echo "  ERROR: binary not found: ${NEGATIVE_BUILD_DIR}/adversarial_rejit"
    FAIL=$((FAIL + 1))
elif "${NEGATIVE_BUILD_DIR}/adversarial_rejit"; then
    PASS=$((PASS + 1))
else
    FAIL=$((FAIL + 1))
    echo "  FAIL: adversarial_rejit"
fi

echo "--- fuzz_rejit (${FUZZ_ROUNDS} rounds) ---"
if [ ! -x "${NEGATIVE_BUILD_DIR}/fuzz_rejit" ]; then
    echo "  ERROR: binary not found: ${NEGATIVE_BUILD_DIR}/fuzz_rejit"
    FAIL=$((FAIL + 1))
elif "${NEGATIVE_BUILD_DIR}/fuzz_rejit" "$FUZZ_ROUNDS"; then
    PASS=$((PASS + 1))
else
    FAIL=$((FAIL + 1))
    echo "  FAIL: fuzz_rejit"
fi

# scx_bad_rejit_replay and scx_prog_show_race require a running scx scheduler;
# they are integration tests and run separately via `make vm-negative-test`.

echo ""
echo "=== vm-selftest: ${PASS} passed, ${FAIL} failed ==="
if [ "$FAIL" -gt 0 ]; then
    exit 1
fi
echo "=== vm-selftest: ALL PASSED ==="
