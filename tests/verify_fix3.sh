#!/bin/bash
RUNNER=/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem

echo 8 > /proc/sys/kernel/printk

echo "=== full rejit run ==="
timeout 8 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 1 \
    --memory $MEM --input-size 64 --rejit
EC=$?
echo "Exit: $EC"

echo "DONE"
echo o > /proc/sysrq-trigger
sleep 2
