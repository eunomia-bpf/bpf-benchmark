#!/bin/sh
# In-VM smoke test: integrate native-link + native_lab kinsn + micro_exec.
set -eu

PROG="${1:-bitmap_popcount_scan}"
SYM="${2:-${PROG}_xdp}"
INPUT_SIZE="${3:-2056}"
REPEAT="${4:-1000}"

REPO=/home/yunwei37/workspace/bpf-benchmark
NATIVE_SO="$REPO/micro/programs/${PROG}.native.so"
MEM="$REPO/micro/generated-inputs/${PROG}.mem"
LINKER="$REPO/ebpf-vm/x86/native_lab/native_link/target/release/native-link"
MICRO_EXEC="$REPO/runner/build-llvmbpf/micro_exec"
KO="$REPO/.cache/repo-build/host/kinsn/x86_64/bpf_x86_native_lab.ko"
BLOB="/tmp/${PROG}.native.bin"

echo "[vm] kernel: $(uname -r)"
mount -t debugfs none /sys/kernel/debug 2>/dev/null || true

if ! lsmod | grep -q '^bpf_x86_native_lab\b'; then
    echo "[vm] insmod $KO"
    insmod "$KO"
fi

echo "[vm] link: $NATIVE_SO ($SYM) -> $BLOB"
"$LINKER" --input "$NATIVE_SO" --symbol "$SYM" --output "$BLOB"

echo
echo "[vm] === run-native-lab ==="
"$MICRO_EXEC" run-native-lab \
    --program "$BLOB" \
    --memory "$MEM" \
    --input-size "$INPUT_SIZE" \
    --inner-repeat "$REPEAT"

echo
echo "[vm] === test-run (baseline BPF JIT) ==="
"$MICRO_EXEC" test-run \
    --program "$REPO/micro/programs/${PROG}.bpf.o" \
    --memory "$MEM" \
    --input-size "$INPUT_SIZE" \
    --inner-repeat "$REPEAT" \
    --io-mode staged
