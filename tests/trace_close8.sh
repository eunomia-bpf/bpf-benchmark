#!/bin/bash
RUNNER=/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem

echo 8 > /proc/sys/kernel/printk

echo "=== Test: full rejit run ==="
timeout 8 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 1 \
    --memory $MEM --input-size 64 --rejit &
RPID=$!

# Background monitor
(sleep 4 && echo "=== dmesg after 4s ===" && dmesg | grep -E "bpf_test_run|bpf_rejit:|bpf_prog_release" | tail -30) &
MPID=$!

wait $RPID
EC=$?
kill $MPID 2>/dev/null
echo "ExitFull: $EC"

echo "=== final dmesg ==="
dmesg | grep -E "bpf_test_run|bpf_rejit:|bpf_prog_release" | tail -30
echo "DONE"
echo o > /proc/sysrq-trigger
sleep 2
