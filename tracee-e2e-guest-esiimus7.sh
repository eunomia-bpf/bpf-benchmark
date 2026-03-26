#!/bin/bash
set -eu
cd /home/yunwei37/workspace/bpf-benchmark
export PATH="/usr/local/sbin:$PATH"
mkdir -p /home/yunwei37/workspace/bpf-benchmark/docs/tmp/vm-tmp
export TMPDIR=/home/yunwei37/workspace/bpf-benchmark/docs/tmp/vm-tmp
. /home/yunwei37/workspace/.venv/bin/activate
cd "/home/yunwei37/workspace/bpf-benchmark" && source "/home/yunwei37/workspace/.venv/bin/activate" && "/home/yunwei37/workspace/bpf-benchmark/module/load_all.sh" 2>/dev/null || true; cd "/home/yunwei37/workspace/bpf-benchmark" && python3 -u tests/integration/scx_prog_show_race.py --mode bpftool-loop --iterations 0 --load-timeout 20
