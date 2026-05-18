#!/bin/sh
set -eu
REPO=/home/yunwei37/workspace/bpf-benchmark
KO="$REPO/.cache/repo-build/host/kinsn/x86_64/bpf_x86_native_lab.ko"
MICRO_EXEC="$REPO/runner/build-llvmbpf/micro_exec"
LINKER="$REPO/ebpf-vm/x86/native_lab/native_link/target/release/native-link"
NATIVE_O="$REPO/ebpf-vm/test/build/helper_only_ktime.native.o"

echo "[vm] kernel: $(uname -r)"
mount -t debugfs none /sys/kernel/debug 2>/dev/null || true
if ! lsmod | grep -q '^bpf_x86_native_lab\b'; then
    insmod "$KO"
fi

echo "=== debugfs entries ==="
ls -la /sys/kernel/debug/bpf_x86_native_lab/ | head -10

echo "=== manual link + upload ==="
"$LINKER" --input "$NATIVE_O" --symbol helper_only_ktime \
    --output /tmp/h.blob --output-relocs /tmp/h.relocs \
    --helper "bpf_ktime_get_ns=0x$(grep ' T bpf_ktime_get_ns' /proc/kallsyms | cut -d' ' -f1)"

echo "blob bytes:"
xxd /tmp/h.blob
echo "relocs bytes:"
xxd /tmp/h.relocs

echo "=== upload blob ==="
cat /tmp/h.blob > /sys/kernel/debug/bpf_x86_native_lab/blob0 && echo "blob upload OK"
echo "=== upload relocs ==="
cat /tmp/h.relocs > /sys/kernel/debug/bpf_x86_native_lab/blob0.relocs && echo "relocs upload OK"

echo "=== full micro_exec run with timeout ==="
INPUT_BIN=/tmp/in.bin
dd if=/dev/zero of=$INPUT_BIN bs=1 count=64 >/dev/null 2>&1
timeout 10 "$MICRO_EXEC" run-native-lab \
    --program "$NATIVE_O" \
    --native-lab-symbol helper_only_ktime \
    --native-lab-linker "$LINKER" \
    --memory "$INPUT_BIN" \
    --input-size 64 \
    --inner-repeat 1
echo "exit: $?"
