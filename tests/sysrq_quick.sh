#!/bin/bash
RUNNER=/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem
echo 8 > /proc/sys/kernel/printk
sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 1 \
    --memory $MEM --input-size 64 --rejit --compile-only &
sleep 2
echo t > /proc/sysrq-trigger
sleep 1
dmesg | grep -E 'micro_exec|sudo|sysrq' | head -5
dmesg | awk '/sudo|micro_exec/{p=1} p{print; if(/Call Trace|---\[ end|Hardware name/) p=0}' | head -30
echo "DONE"
kill %1 2>/dev/null
