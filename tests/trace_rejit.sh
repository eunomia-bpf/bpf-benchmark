#!/bin/bash
RUNNER=/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem
echo 8 > /proc/sys/kernel/printk
sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 1 --memory $MEM --input-size 64 --rejit --compile-only &
RPID=$!
sleep 6
dmesg | grep bpf_rejit
echo "DMESG_DONE"
kill $RPID 2>/dev/null
wait $RPID 2>/dev/null
echo "SCRIPT_DONE"
