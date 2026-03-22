#!/bin/bash
RUNNER=/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem

echo 8 > /proc/sys/kernel/printk

echo "=== Test: bpf_call_chain actual run with rejit ==="
timeout 8 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 3 \
    --memory $MEM --input-size 64 --rejit
EC=$?
echo "Exit code: $EC"

dmesg | grep -E "bpf_prog_release|bpf_prog_put_deferred|__bpf_prog_put_noref|bpf_rejit:" | head -30

echo "SCRIPT_DONE"
echo o > /proc/sysrq-trigger
sleep 2
