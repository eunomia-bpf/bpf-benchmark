#!/bin/bash
set -eu
cd /home/yunwei37/workspace/bpf-benchmark
export PATH="/usr/local/sbin:$PATH"
mkdir -p /home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260326/vm-tmp
export TMPDIR=/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260326/vm-tmp
. /home/yunwei37/workspace/.venv/bin/activate
cd "/home/yunwei37/workspace/bpf-benchmark" && source "/home/yunwei37/workspace/.venv/bin/activate" && "/home/yunwei37/workspace/bpf-benchmark/module/load_all.sh" 2>/dev/null || true; for t in tracepoint kprobe perf_event fentry lsm xdp socket_filter sched_cls cgroup_skb struct_ops ext sk_lookup; do echo ===  ===; timeout 120 ./tests/unittest/build/rejit_hotswap_ ./tests/unittest/build/progs 2>&1; echo exit_code=; echo; done
