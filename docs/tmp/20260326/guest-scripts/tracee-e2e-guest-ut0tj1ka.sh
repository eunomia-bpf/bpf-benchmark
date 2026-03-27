#!/bin/bash
set -eu
cd /home/yunwei37/workspace/bpf-benchmark
export PATH="/usr/local/sbin:$PATH"
mkdir -p /home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260326/vm-tmp
export TMPDIR=/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260326/vm-tmp
. /home/yunwei37/workspace/.venv/bin/activate
/home/yunwei37/workspace/bpf-benchmark/module/load_all.sh 2>/dev/null || true; python3 corpus/driver.py --guest-target-json /home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260326/corpus-rejit-batch/corpus-rejit-vm-batch-hgjvc3gn.json --guest-result-json /home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260326/corpus-rejit-batch/corpus-rejit-vm-batch-result-h3s2y1cf.json --runner /home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec --daemon /home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon --btf-custom-path /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/vmlinux --repeat 50 --timeout 240 --passes map_inline,const_prop,dce,wide_mem,rotate,cond_select,extract,endian_fusion,bulk_memory,bounds_check_merge,skb_load_bytes,branch_flip
