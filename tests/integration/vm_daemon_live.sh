#!/bin/bash
# Test: daemon enumerate/rewrite/apply with a live BPF program
set -e
ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
cd "$ROOT_DIR"

PASS=0
FAIL=0
TOTAL=0

report() {
    local name="$1" status="$2" detail="$3"
    TOTAL=$((TOTAL + 1))
    if [ "$status" = "PASS" ]; then
        PASS=$((PASS + 1))
        echo "  [$status] $name"
    else
        FAIL=$((FAIL + 1))
        echo "  [$status] $name: $detail"
    fi
}

echo "================================================================"
echo "=== BpfReJIT v2 Live Daemon Integration Tests ==="
echo "================================================================"

# Hold a BPF program loaded in background
echo "--- Loading load_byte_recompose.bpf.o and holding it ---"
HOLD_PROG="${ROOT_DIR}/tests/helpers/build/hold_bpf_prog"
"$HOLD_PROG" "${ROOT_DIR}/micro/programs/load_byte_recompose.bpf.o" 120 &
BGPID=$!
sleep 2

if kill -0 $BGPID 2>/dev/null; then
    echo "hold_bpf_prog running (pid=$BGPID)"
else
    echo "hold_bpf_prog already exited"
    report "0: BPF program stays loaded" "FAIL" "process exited"
    exit 1
fi

# Test 1: daemon enumerate sees the live program
echo ""
echo "--- daemon enumerate ---"
ENUM_OUTPUT=$(./daemon/target/release/bpfrejit-daemon enumerate 2>&1)
echo "$ENUM_OUTPUT"

PROG_LINES=$(echo "$ENUM_OUTPUT" | grep -E "^\s+[0-9]+" || true)
PROG_COUNT=$(echo "$PROG_LINES" | grep -c -E "[0-9]" || true)
echo "Found $PROG_COUNT programs"

if [ "$PROG_COUNT" -gt 0 ]; then
    report "1: daemon enumerate finds live programs ($PROG_COUNT)" "PASS"

    PROG_ID=$(echo "$PROG_LINES" | head -1 | awk '{print $1}')
    echo "Using prog_id=$PROG_ID"

    # Check if it has wide_mem sites
    HAS_WIDE=$(echo "$PROG_LINES" | head -1 | grep -o "wide_mem=[0-9]*" || echo "none")
    echo "Sites: $HAS_WIDE"

    # Test 2: daemon rewrite
    echo ""
    echo "--- daemon rewrite $PROG_ID ---"
    REWRITE_OUTPUT=$(./daemon/target/release/bpfrejit-daemon rewrite "$PROG_ID" 2>&1)
    echo "$REWRITE_OUTPUT"

    if echo "$REWRITE_OUTPUT" | grep -qE "found [0-9]+ rewrite sites"; then
        SITES=$(echo "$REWRITE_OUTPUT" | grep -o "found [0-9]* rewrite" | grep -o "[0-9]*")
        report "2: daemon rewrite finds $SITES optimization sites" "PASS"
    elif echo "$REWRITE_OUTPUT" | grep -q "nothing to rewrite\|no original"; then
        report "2: daemon rewrite (no wide_mem sites)" "PASS" "(program may not have wide_mem patterns)"
    elif echo "$REWRITE_OUTPUT" | grep -q "original instructions"; then
        report "2: daemon rewrite (read program)" "PASS"
    else
        report "2: daemon rewrite" "FAIL" "unexpected output"
    fi

    # Test 3: daemon apply
    echo ""
    echo "--- daemon apply $PROG_ID ---"
    APPLY_OUTPUT=$(./daemon/target/release/bpfrejit-daemon apply "$PROG_ID" 2>&1)
    APPLY_EXIT=$?
    echo "$APPLY_OUTPUT"

    if echo "$APPLY_OUTPUT" | grep -q "REJIT successful"; then
        report "3: daemon apply REJIT successful" "PASS"
    elif echo "$APPLY_OUTPUT" | grep -q "no optimization sites\|no transforms"; then
        report "3: daemon apply (no sites)" "PASS" "(no wide_mem patterns found)"
    elif [ $APPLY_EXIT -eq 0 ]; then
        report "3: daemon apply completed" "PASS"
    else
        report "3: daemon apply" "FAIL" "$APPLY_OUTPUT"
    fi

    # Test 4: daemon apply-all
    echo ""
    echo "--- daemon apply-all ---"
    APPLYALL_OUTPUT=$(./daemon/target/release/bpfrejit-daemon apply-all 2>&1)
    echo "$APPLYALL_OUTPUT"

    if echo "$APPLYALL_OUTPUT" | grep -q "apply-all:"; then
        APPLIED=$(echo "$APPLYALL_OUTPUT" | grep -o "applied [0-9]*" | grep -o "[0-9]*" || echo "0")
        report "4: daemon apply-all (applied=$APPLIED)" "PASS"
    else
        report "4: daemon apply-all" "FAIL" "$APPLYALL_OUTPUT"
    fi
else
    report "1: daemon enumerate" "FAIL" "no programs found"
    report "2: daemon rewrite" "FAIL" "skipped"
    report "3: daemon apply" "FAIL" "skipped"
    report "4: daemon apply-all" "FAIL" "skipped"
fi

# Clean up
echo ""
echo "--- Cleaning up ---"
kill $BGPID 2>/dev/null || true
wait $BGPID 2>/dev/null || true

# Check dmesg
WARNINGS=$(dmesg | grep -c -E "WARNING|BUG|Oops" || true)
if [ "$WARNINGS" -eq 0 ] 2>/dev/null; then
    report "5: no kernel warnings" "PASS"
else
    WARN_DETAIL=$(dmesg | grep -E "WARNING|BUG|Oops" | head -3)
    report "5: no kernel warnings" "FAIL" "$WARN_DETAIL"
fi

echo ""
echo "================================================================"
echo "=== SUMMARY: $PASS/$TOTAL passed, $FAIL failed ==="
echo "================================================================"

if [ $FAIL -gt 0 ]; then
    exit 1
fi
