#!/bin/bash
RUNNER=/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec

echo 8 > /proc/sys/kernel/printk

# Test 1: bpf_call_chain (multi-function, real_func_cnt=4)
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem
echo "=== Test 1: bpf_call_chain with rejit ==="
timeout 10 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 1 \
    --memory $MEM --input-size 64 --rejit
echo "Exit1: $?"

# Test 2: cmov_select (single-function) - this was Pattern 1
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/cmov_select.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/cmov_select.mem
echo "=== Test 2: cmov_select double run (Pattern 1) ==="
timeout 10 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 3 \
    --memory $MEM --input-size 64 --rejit
echo "Exit2a: $?"
timeout 10 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 3 \
    --memory $MEM --input-size 64 --rejit
echo "Exit2b: $?"

# Test 3: bpf_call_chain x3 sequential (Pattern 2)
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem
echo "=== Test 3: bpf_call_chain x3 sequential ==="
for i in 1 2 3; do
    timeout 10 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 1 \
        --memory $MEM --input-size 64 --rejit
    echo "Exit3_$i: $?"
done

echo "ALL TESTS DONE"
echo o > /proc/sysrq-trigger
sleep 2
