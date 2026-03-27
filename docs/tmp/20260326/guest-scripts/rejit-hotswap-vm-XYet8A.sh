#!/bin/bash
set -eu
cd /home/yunwei37/workspace/bpf-benchmark
export PATH="/usr/local/sbin:$PATH"
mkdir -p /home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260326/vm-tmp
export TMPDIR=/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260326/vm-tmp
. /home/yunwei37/workspace/.venv/bin/activate
/home/yunwei37/workspace/bpf-benchmark/module/load_all.sh 2>/dev/null || true
bash /tmp/rejit_hotswap_vm_loop.sh
