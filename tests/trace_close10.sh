#!/bin/bash
RUNNER=/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem

echo 8 > /proc/sys/kernel/printk

timeout 6 sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 1 \
    --memory $MEM --input-size 64 --rejit &
RPID=$!

sleep 5

echo "=== dmesg after 5s ==="
dmesg | grep -E "bpf_prog_release|bpf_prog_put:|FINAL" | tail -20

kill -9 $RPID 2>/dev/null
echo "DONE"
echo o > /proc/sysrq-trigger
sleep 2
