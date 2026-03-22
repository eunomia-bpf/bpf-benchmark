#!/bin/bash
RUNNER=/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem

echo 8 > /proc/sys/kernel/printk

# Test 1: compile-only with rejit
echo "=== Test 1: bpf_call_chain compile-only rejit ==="
timeout 10 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 1 \
    --memory $MEM --input-size 64 --rejit --compile-only
echo "Exit code: $?"

# Test 2: actual run with rejit (not compile-only)
echo "=== Test 2: bpf_call_chain actual run with rejit ==="
timeout 10 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 3 \
    --memory $MEM --input-size 64 --rejit
echo "Exit code: $?"

# Test 3: multiple back-to-back runs
echo "=== Test 3: back-to-back runs ==="
for i in 1 2 3; do
    timeout 5 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 1 \
        --memory $MEM --input-size 64 --rejit --compile-only
    echo "Run $i exit: $?"
done

dmesg | tail -20

echo "SCRIPT_DONE"
echo o > /proc/sysrq-trigger
sleep 2
