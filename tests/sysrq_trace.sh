#!/bin/bash
RUNNER=/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem

echo 8 > /proc/sys/kernel/printk

# Run rejit to get REJIT applied, then close the fd
sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 1 \
    --memory $MEM --input-size 64 --rejit --compile-only &
RPID=$!

# Wait for it to reach the hang
sleep 3

# Get the runner's kernel stack
PID=$(pgrep -x micro_exec 2>/dev/null || echo "")
if [ -n "$PID" ]; then
    echo "=== Runner PID=$PID still running ==="
    cat /proc/sysrq-trigger
    echo l > /proc/sysrq-trigger
    echo t > /proc/sysrq-trigger
    sleep 1
    dmesg | tail -80
fi

kill -9 $RPID 2>/dev/null
echo "DONE"
