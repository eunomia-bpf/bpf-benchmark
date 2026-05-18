#!/bin/sh
set -eu
REPO=/home/yunwei37/workspace/bpf-benchmark
KO="$REPO/.cache/repo-build/host/kinsn/x86_64/bpf_x86_native_lab.ko"
MICRO_EXEC="$REPO/runner/build-llvmbpf/micro_exec"
LINKER="$REPO/ebpf-vm/x86/native_lab/native_link/target/release/native-link"
NATIVE_O="$REPO/ebpf-vm/test/build/map_array_lookup.native.o"

echo "[vm] kernel: $(uname -r)"
mount -t debugfs none /sys/kernel/debug 2>/dev/null || true
if ! lsmod | grep -q '^bpf_x86_native_lab\b'; then
    insmod "$KO"
fi

INPUT_BIN=/tmp/in.bin
dd if=/dev/zero of=$INPUT_BIN bs=1 count=64 >/dev/null 2>&1

echo "=== run-native-lab map_array_lookup ==="
"$MICRO_EXEC" run-native-lab \
    --program "$NATIVE_O" \
    --native-lab-symbol map_array_lookup \
    --native-lab-linker "$LINKER" \
    --memory "$INPUT_BIN" \
    --input-size 64 \
    --inner-repeat 1
echo "exit: $?"
