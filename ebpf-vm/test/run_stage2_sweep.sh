#!/bin/sh
# Stage 2 perf sweep: same 6 programs as run_stage2.sh, but with
# inner-repeat=1000 so the per-iteration native execution time is what
# gets reported in exec_ns (the single-shot inner-repeat=1 number is
# dominated by PROG_TEST_RUN syscall dispatch and obscures the actual
# program runtime).
set -eu

REPO=/home/yunwei37/workspace/bpf-benchmark
KO="$REPO/.cache/repo-build/host/kinsn/x86_64/bpf_x86_native_lab.ko"
MICRO_EXEC="$REPO/runner/build-llvmbpf/micro_exec"
LINKER="$REPO/ebpf-vm/x86/native_lab/native_link/target/release/native-link"
TEST_DIR="$REPO/ebpf-vm/test"
BUILD_DIR="$TEST_DIR/build"
INPUT_SIZE=64
INNER_REPEAT=${INNER_REPEAT:-100000}
SAMPLES=${SAMPLES:-15}

echo "[vm] kernel: $(uname -r)"
mount -t debugfs none /sys/kernel/debug 2>/dev/null || true
if ! lsmod | grep -q '^bpf_x86_native_lab\b'; then
    insmod "$KO"
fi

INPUT_BIN=/tmp/stage2_input.bin
dd if=/dev/zero of="$INPUT_BIN" bs=1 count=$INPUT_SIZE >/dev/null 2>&1

# 14 programs total: 6 original POC + 8 added 2026-05-17 to cover
# realistic shapes (LRU/PERCPU_HASH, multi-map chains, packet-driven
# struct keys, mixed helpers + maps). Sorted simple -> complex.
PROGS="
helper_only_ktime
helper_get_pid_tgid
helper_chain_simple
map_array_lookup
map_array_index_packet
map_hash_lookup
map_hash_str_key
map_percpu_array
map_lru_hash_counter
map_percpu_hash_counter
combined_helper_map
multi_map_policy
packet_5tuple_classify
stats_mixed_helpers
"

printf "%-30s  %12s  %12s  %12s\n" "program" "native_lab_ns" "kernel_jit_ns" "ratio"
printf -- "---------------------------------------------------------------------------\n"

for P in $PROGS; do
    NATIVE_O="$BUILD_DIR/${P}.native.o"
    BPF_O="$BUILD_DIR/${P}.bpf.o"
    [ -f "$NATIVE_O" ] || { echo "MISSING $NATIVE_O"; continue; }
    [ -f "$BPF_O" ] || { echo "MISSING $BPF_O"; continue; }

    # Collect $SAMPLES samples of each runtime, take the median by sort.
    NL_SAMPLES=""
    KJ_SAMPLES=""
    i=0
    while [ "$i" -lt "$SAMPLES" ]; do
        NL_JSON=$("$MICRO_EXEC" run-native-lab \
            --program "$NATIVE_O" \
            --native-lab-symbol "$P" \
            --native-lab-linker "$LINKER" \
            --memory "$INPUT_BIN" \
            --input-size "$INPUT_SIZE" \
            --inner-repeat "$INNER_REPEAT" 2>/dev/null) || NL_JSON=""
        NL=$(echo "$NL_JSON" | grep -o '"exec_ns":[0-9]*' | head -1 | cut -d: -f2)
        [ -n "$NL" ] && NL_SAMPLES="$NL_SAMPLES $NL"

        KJ_JSON=$("$MICRO_EXEC" test-run \
            --program "$BPF_O" \
            --memory "$INPUT_BIN" \
            --input-size "$INPUT_SIZE" \
            --inner-repeat "$INNER_REPEAT" \
            --io-mode packet 2>/dev/null) || KJ_JSON=""
        KJ=$(echo "$KJ_JSON" | grep -o '"exec_ns":[0-9]*' | head -1 | cut -d: -f2)
        [ -n "$KJ" ] && KJ_SAMPLES="$KJ_SAMPLES $KJ"

        i=$((i + 1))
    done

    NL_MED=$(echo $NL_SAMPLES | tr ' ' '\n' | sort -n | awk 'NF{a[NR]=$1} END{print a[int((NR+1)/2)]}')
    KJ_MED=$(echo $KJ_SAMPLES | tr ' ' '\n' | sort -n | awk 'NF{a[NR]=$1} END{print a[int((NR+1)/2)]}')
    if [ -n "$NL_MED" ] && [ -n "$KJ_MED" ] && [ "$KJ_MED" -gt 0 ]; then
        RATIO=$(awk -v n="$NL_MED" -v k="$KJ_MED" 'BEGIN{printf "%.3f", n/k}')
    else
        RATIO="?"
    fi
    printf "%-30s  %12s  %12s  %12s\n" "$P" "${NL_MED:-?}" "${KJ_MED:-?}" "$RATIO"
done
