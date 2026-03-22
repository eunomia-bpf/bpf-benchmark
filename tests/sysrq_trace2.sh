#!/bin/bash
RUNNER=/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem

echo 8 > /proc/sys/kernel/printk

sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 1 \
    --memory $MEM --input-size 64 --rejit --compile-only &
RPID=$!

sleep 3

PID=$(pgrep -x micro_exec 2>/dev/null || echo "")
if [ -n "$PID" ]; then
    echo "=== Runner PID=$PID still running, dumping stack ==="
    echo t > /proc/sysrq-trigger
    sleep 0.5
    dmesg | grep -A 20 "micro_exec\|Pid:.*131"
fi

kill -9 $RPID 2>/dev/null
echo "DONE"
