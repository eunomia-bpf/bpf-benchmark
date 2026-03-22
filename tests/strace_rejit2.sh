#!/bin/bash
RUNNER=/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec
PROG=/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o
MEM=/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/bpf_call_chain.mem

strace -f -e trace=bpf,close -o /run/strace.out sudo $RUNNER run-kernel --program $PROG \
    --io-mode staged --repeat 1 --memory $MEM --input-size 64 --rejit --compile-only &
RPID=$!
sleep 4
kill $RPID 2>/dev/null
wait $RPID 2>/dev/null
echo "=== Last 25 bpf/close syscalls ==="
grep -E 'bpf\(|close\(' /run/strace.out | tail -25
echo "DONE"
