#!/bin/sh
# Stage 2 POC smoke test driver. Run inside the BpfReJIT VM via vng.
#
# For each .bpf.c source under ebpf-vm/test:
#   * native_lab path: run-native-lab with the .native.o ELF; the runner
#     invokes native-link to resolve helper relocations against
#     /proc/kallsyms and uploads blob + side-band relocs.
#   * kernel_jit baseline: test-run on the .bpf.o, libbpf does the load
#     normally.
# Both should produce the same retval and packet result. Prints a
# per-program OK/FAIL table at the end.
set -eu

REPO=/home/yunwei37/workspace/bpf-benchmark
KO="$REPO/.cache/repo-build/host/kinsn/x86_64/bpf_x86_native_lab.ko"
MICRO_EXEC="$REPO/runner/build-llvmbpf/micro_exec"
LINKER="$REPO/ebpf-vm/x86/native_lab/native_link/target/release/native-link"
TEST_DIR="$REPO/ebpf-vm/test"
BUILD_DIR="$TEST_DIR/build"
INPUT_SIZE=64

echo "[vm] kernel: $(uname -r)"
mount -t debugfs none /sys/kernel/debug 2>/dev/null || true
if ! lsmod | grep -q '^bpf_x86_native_lab\b'; then
    insmod "$KO"
fi

# Each test program produces a u64 result the program writes to data[0..8].
# We compare retval + result between native_lab and kernel_jit. For
# helpers that read state (ktime, pid, smp_id), the values can differ
# slightly between two consecutive runs -- those are smoke-tested with
# "nonzero" / "retval==XDP_PASS" only.
PROGS="helper_only_ktime helper_get_pid_tgid map_array_lookup map_hash_lookup map_percpu_array combined_helper_map"

# Per-program smoke check spec: strict | loose.
# strict = result + retval must match across runtimes.
# loose  = retval must be XDP_PASS on both; result just non-zero on native_lab.
# All currently use strict for retval and loose for result (ktime/pid are
# nondeterministic), except helper_get_pid_tgid which IS deterministic
# under the test_run caller process.
declare_check() { :; } # placeholder for shells that don't have associative arrays

# Generate a packet input for each program. We just use a zero-filled
# buffer; the test programs read ctx->data (which test_run fills with
# the data_in buffer) and write their result into the first 8 bytes.

INPUT_BIN=/tmp/stage2_input.bin
dd if=/dev/zero of="$INPUT_BIN" bs=1 count=$INPUT_SIZE >/dev/null 2>&1

FAILS=0
echo
printf "%-30s  %15s  %15s  %s\n" "program" "native_lab_ret" "kernel_jit_ret" "status"
printf -- "------------------------------------------------------------------------------\n"

for P in $PROGS; do
    NATIVE_O="$BUILD_DIR/${P}.native.o"
    BPF_O="$BUILD_DIR/${P}.bpf.o"
    if [ ! -f "$NATIVE_O" ] || [ ! -f "$BPF_O" ]; then
        printf "%-30s  %15s  %15s  %s\n" "$P" "-" "-" "MISSING ARTIFACTS"
        FAILS=$((FAILS + 1))
        continue
    fi

    NATIVE_JSON=$("$MICRO_EXEC" run-native-lab \
        --program "$NATIVE_O" \
        --native-lab-symbol "$P" \
        --native-lab-linker "$LINKER" \
        --memory "$INPUT_BIN" \
        --input-size "$INPUT_SIZE" \
        --inner-repeat 1 2>&1) || {
            echo "[FAIL] native_lab $P:"
            echo "$NATIVE_JSON" | sed 's/^/  /' | tail -30
            FAILS=$((FAILS + 1))
            continue
        }
    NATIVE_RETVAL=$(echo "$NATIVE_JSON" | grep -o '"retval":[0-9]*' | head -1 | cut -d: -f2)
    NATIVE_RESULT=$(echo "$NATIVE_JSON" | grep -o '"result":[0-9]*' | head -1 | cut -d: -f2)
    NATIVE_NS=$(echo "$NATIVE_JSON" | grep -o '"exec_ns":[0-9]*' | head -1 | cut -d: -f2)

    KERNEL_JSON=$("$MICRO_EXEC" test-run \
        --program "$BPF_O" \
        --memory "$INPUT_BIN" \
        --input-size "$INPUT_SIZE" \
        --inner-repeat 1 \
        --io-mode packet 2>&1) || {
            echo "[FAIL] kernel_jit $P:"
            echo "$KERNEL_JSON" | sed 's/^/  /' | tail -30
            FAILS=$((FAILS + 1))
            continue
        }
    KERNEL_RETVAL=$(echo "$KERNEL_JSON" | grep -o '"retval":[0-9]*' | head -1 | cut -d: -f2)
    KERNEL_RESULT=$(echo "$KERNEL_JSON" | grep -o '"result":[0-9]*' | head -1 | cut -d: -f2)
    KERNEL_NS=$(echo "$KERNEL_JSON" | grep -o '"exec_ns":[0-9]*' | head -1 | cut -d: -f2)

    STATUS="OK"
    # XDP_PASS = 2
    if [ "$NATIVE_RETVAL" != "2" ] || [ "$KERNEL_RETVAL" != "2" ]; then
        STATUS="RETVAL_BAD"
    fi
    case "$P" in
        helper_get_pid_tgid|helper_only_ktime|combined_helper_map)
            # Programs whose result depends on per-run state (ktime,
            # pid_tgid, CPU index) -- both runtimes observe in their own
            # subprocess at different wall times, so values legitimately
            # differ. Smoke check: both retvals are XDP_PASS and results
            # are non-zero.
            if [ "$NATIVE_RESULT" = "0" ] || [ "$KERNEL_RESULT" = "0" ]; then
                STATUS="ZERO_RESULT"
            fi
            ;;
        map_*)
            # Map-mediated lookup of a freshly-written deterministic value.
            # Both runtimes must produce the exact same u64.
            if [ "$NATIVE_RESULT" != "$KERNEL_RESULT" ]; then
                STATUS="RESULT_MISMATCH"
            fi
            ;;
    esac

    printf "%-30s  %15s  %15s  %s (nl_ns=%s kj_ns=%s nl_res=%s kj_res=%s)\n" \
        "$P" "$NATIVE_RETVAL" "$KERNEL_RETVAL" "$STATUS" "$NATIVE_NS" "$KERNEL_NS" \
        "$NATIVE_RESULT" "$KERNEL_RESULT"
    if [ "$STATUS" != "OK" ]; then
        FAILS=$((FAILS + 1))
    fi
done

echo
if [ "$FAILS" -eq 0 ]; then
    echo "[OK] all Stage 2 programs passed"
    exit 0
else
    echo "[FAIL] $FAILS program(s) failed"
    exit 1
fi
