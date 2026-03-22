#!/bin/bash
RUNNER=/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem

echo 8 > /proc/sys/kernel/printk

echo "=== Test 1: full rejit run ==="
timeout 10 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 3 \
    --memory $MEM --input-size 64 --rejit
echo "Exit1: $?"

echo "=== Test 2: second full rejit run ==="
timeout 10 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 3 \
    --memory $MEM --input-size 64 --rejit
echo "Exit2: $?"

echo "=== Test 3: third run ==="
timeout 10 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 3 \
    --memory $MEM --input-size 64 --rejit
echo "Exit3: $?"

echo "SCRIPT_DONE"
echo o > /proc/sysrq-trigger
sleep 2
