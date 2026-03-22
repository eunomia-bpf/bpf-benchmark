#!/bin/bash
RUNNER=/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem

echo 8 > /proc/sys/kernel/printk

# Run with timeout - the runner will hang, timeout kills it
timeout 8 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 1 \
    --memory $MEM --input-size 64 --rejit --compile-only &
RPID=$!

# Wait for it to start and potentially hang
sleep 5

# Check if still running (hung)
if kill -0 $RPID 2>/dev/null; then
    echo "=== Runner hung after 5s, dumping dmesg ==="
    dmesg | tail -60
    echo "=== killing ==="
    kill -9 $RPID 2>/dev/null
else
    echo "=== Runner exited within 5s ==="
    dmesg | tail -30
fi

echo "SCRIPT_DONE"
# Force poweroff
echo o > /proc/sysrq-trigger
sleep 2
