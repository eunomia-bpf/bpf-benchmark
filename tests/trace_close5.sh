#!/bin/bash
RUNNER=/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem

echo 8 > /proc/sys/kernel/printk

echo "=== Test A: stock run (no rejit) ==="
timeout 5 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 3 \
    --memory $MEM --input-size 64
echo "ExitA: $?"

dmesg | tail -5
echo "DONE"
echo o > /proc/sysrq-trigger
sleep 2
