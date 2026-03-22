#!/bin/bash
RUNNER=/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem

echo 8 > /proc/sys/kernel/printk

echo "=== Test A: stock run only (no rejit) ==="
timeout 5 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 3 \
    --memory $MEM --input-size 64
echo "ExitA: $?"

echo "=== Test B: compile-only with rejit ==="
timeout 5 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 1 \
    --memory $MEM --input-size 64 --rejit --compile-only
echo "ExitB: $?"

dmesg | grep -E "bpf_prog_release|bpf_prog_put_deferred|__bpf_prog_put_noref" | head -20
echo "=== done ==="
echo o > /proc/sysrq-trigger
sleep 2
