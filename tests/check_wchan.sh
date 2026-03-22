#!/bin/bash
RUNNER=/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem
echo 8 > /proc/sys/kernel/printk
sudo $RUNNER run-kernel --program $PROG --io-mode staged --repeat 1 \
    --memory $MEM --input-size 64 --rejit --compile-only &
RPID=$!
sleep 2
PID=$(pgrep -x micro_exec 2>/dev/null)
if [ -n "$PID" ]; then
    echo "micro_exec PID=$PID wchan=$(cat /proc/$PID/wchan 2>/dev/null)"
    echo "stack:"
    cat /proc/$PID/stack 2>/dev/null
fi
echo "DONE"
# Force poweroff
echo o > /proc/sysrq-trigger
sleep 2
