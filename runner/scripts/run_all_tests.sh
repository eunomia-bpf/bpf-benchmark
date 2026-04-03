#!/bin/bash
# Unified VM test runner: kernel selftests + unittest suite + upstream BPF selftests.
# Usage: run_all_tests.sh <ROOT_DIR> [--skip-selftest] [--skip-unittest] [--skip-upstream]
#
# Environment variables:
#   BPF_SELFTEST_FILTER  - space-separated test_progs -t filter (default: "verifier jit")
set -eu -o pipefail

ROOT_DIR="${1:?Usage: run_all_tests.sh <ROOT_DIR>}"
shift

# Parse flags
SKIP_SELFTEST=0
SKIP_UNITTEST=0
SKIP_NEGATIVE=0
SKIP_UPSTREAM=0
for arg in "$@"; do
    case "$arg" in
        --skip-selftest) SKIP_SELFTEST=1 ;;
        --skip-unittest) SKIP_UNITTEST=1 ;;
        --skip-negative) SKIP_NEGATIVE=1 ;;
        --skip-upstream) SKIP_UPSTREAM=1 ;;
        *) echo "Unknown flag: $arg"; exit 1 ;;
    esac
done

KERNEL_TEST_DIR="${ROOT_DIR}/tests/kernel"
KERNEL_SELFTEST="${KERNEL_TEST_DIR}/build/test_recompile"
UNITTEST_DIR="${ROOT_DIR}/tests/unittest"
UNITTEST_BUILD_DIR="${UNITTEST_DIR}/build"
UPSTREAM_BIN_DIR="${ROOT_DIR}/.cache/upstream-bpf-selftests"
BPF_SELFTEST_FILTER="${BPF_SELFTEST_FILTER:-verifier jit}"

cd "$ROOT_DIR"

PASS=0
FAIL=0

LOAD_SCRIPT="${ROOT_DIR}/module/load_all.sh"

run_section() {
    echo ""
    echo "========================================"
    echo "  $1"
    echo "========================================"
}

ensure_kinsn_modules_loaded() {
    if [ ! -x "$LOAD_SCRIPT" ]; then
        echo "ERROR: module/load_all.sh not found or not executable: $LOAD_SCRIPT"
        exit 1
    fi
    "$LOAD_SCRIPT"
}

# --- Part 1: Kernel selftest (test_recompile) ---
if [ "$SKIP_SELFTEST" -eq 0 ] && [ -f "$KERNEL_SELFTEST" ]; then
    run_section "Kernel selftest (test_recompile)"
    if "$KERNEL_SELFTEST"; then
        PASS=$((PASS + 1))
    else
        FAIL=$((FAIL + 1))
        echo "FAIL: test_recompile"
    fi
else
    [ "$SKIP_SELFTEST" -eq 0 ] && echo "SKIP: test_recompile not found at $KERNEL_SELFTEST"
fi

# --- Part 2: unittest suite ---
if [ "$SKIP_UNITTEST" -eq 0 ]; then
    run_section "Loading kinsn modules"
    ensure_kinsn_modules_loaded

    run_section "Running tests/unittest/ suite (pre-built)"
    cd "$UNITTEST_DIR"
    for t in $(find "$UNITTEST_BUILD_DIR" -maxdepth 1 -name 'rejit_*' -executable -printf '%f\n' 2>/dev/null | sort); do
        echo "--- $t ---"
        if [ ! -x "${UNITTEST_BUILD_DIR}/$t" ]; then
            echo "  ERROR: binary not found: ${UNITTEST_BUILD_DIR}/$t"
            FAIL=$((FAIL + 1))
            continue
        fi
        if "${UNITTEST_BUILD_DIR}/$t" "${UNITTEST_BUILD_DIR}/progs"; then
            PASS=$((PASS + 1))
        else
            FAIL=$((FAIL + 1))
            echo "FAIL: $t"
        fi
    done
    cd "$ROOT_DIR"
fi

# --- Part 2b: negative / adversarial tests ---
NEGATIVE_DIR="${ROOT_DIR}/tests/negative"
NEGATIVE_BUILD_DIR="${NEGATIVE_DIR}/build"
SCX_PROG_SHOW_RACE_MODE="${SCX_PROG_SHOW_RACE_MODE:-bpftool-loop}"
SCX_PROG_SHOW_RACE_ITERATIONS="${SCX_PROG_SHOW_RACE_ITERATIONS:-20}"
SCX_PROG_SHOW_RACE_LOAD_TIMEOUT="${SCX_PROG_SHOW_RACE_LOAD_TIMEOUT:-20}"
SCX_PROG_SHOW_RACE_ARGS=(
    "$ROOT_DIR"
    --mode "$SCX_PROG_SHOW_RACE_MODE"
    --iterations "$SCX_PROG_SHOW_RACE_ITERATIONS"
    --load-timeout "$SCX_PROG_SHOW_RACE_LOAD_TIMEOUT"
)

if [ "${SCX_PROG_SHOW_RACE_SKIP_PROBE:-0}" = "1" ]; then
    SCX_PROG_SHOW_RACE_ARGS+=(--skip-probe)
fi

if [ "$SKIP_NEGATIVE" -eq 0 ] && [ -d "$NEGATIVE_DIR" ]; then
    run_section "Building tests/negative/"
    make -C "$NEGATIVE_DIR" clean all

    run_section "Running tests/negative/ adversarial suite"
    echo "--- adversarial_rejit ---"
    if "${NEGATIVE_BUILD_DIR}/adversarial_rejit"; then
        PASS=$((PASS + 1))
    else
        FAIL=$((FAIL + 1))
        echo "FAIL: adversarial_rejit"
    fi

    echo "--- fuzz_rejit (1000 rounds) ---"
    if "${NEGATIVE_BUILD_DIR}/fuzz_rejit" 1000; then
        PASS=$((PASS + 1))
    else
        FAIL=$((FAIL + 1))
        echo "FAIL: fuzz_rejit"
    fi

    echo "--- scx_prog_show_race (${SCX_PROG_SHOW_RACE_MODE}) ---"
    if "${NEGATIVE_BUILD_DIR}/scx_prog_show_race" "${SCX_PROG_SHOW_RACE_ARGS[@]}"; then
        PASS=$((PASS + 1))
    else
        FAIL=$((FAIL + 1))
        echo "FAIL: scx_prog_show_race"
    fi
fi

# --- Part 3: upstream test_verifier ---
if [ "$SKIP_UPSTREAM" -eq 0 ] && [ -f "${UPSTREAM_BIN_DIR}/test_verifier" ]; then
    run_section "Upstream test_verifier"
    cd "$UPSTREAM_BIN_DIR"
    if ./test_verifier 2>&1; then
        PASS=$((PASS + 1))
    else
        FAIL=$((FAIL + 1))
        echo "FAIL: test_verifier"
    fi
    cd "$ROOT_DIR"
else
    [ "$SKIP_UPSTREAM" -eq 0 ] && echo "SKIP: test_verifier not found at ${UPSTREAM_BIN_DIR}/test_verifier"
fi

# --- Part 4: upstream test_progs ---
if [ "$SKIP_UPSTREAM" -eq 0 ] && [ -f "${UPSTREAM_BIN_DIR}/test_progs" ]; then
    run_section "Upstream test_progs (filter: ${BPF_SELFTEST_FILTER})"
    cd "$UPSTREAM_BIN_DIR"
    FILTER_FLAGS=""
    for t in $BPF_SELFTEST_FILTER; do
        FILTER_FLAGS="$FILTER_FLAGS -t $t"
    done
    if ./test_progs $FILTER_FLAGS 2>&1; then
        PASS=$((PASS + 1))
    else
        FAIL=$((FAIL + 1))
        echo "FAIL: test_progs"
    fi
    cd "$ROOT_DIR"
else
    [ "$SKIP_UPSTREAM" -eq 0 ] && echo "SKIP: test_progs not found at ${UPSTREAM_BIN_DIR}/test_progs"
fi

# --- Summary ---
echo ""
echo "========================================"
echo "  RESULTS: ${PASS} passed, ${FAIL} failed"
echo "========================================"

if [ "$FAIL" -gt 0 ]; then
    exit 1
fi
echo "vm-test: ALL PASSED"
