#!/bin/bash
set -eu
cd /home/yunwei37/workspace/bpf-benchmark
export PATH="/usr/local/sbin:$PATH"
mkdir -p /home/yunwei37/workspace/bpf-benchmark/docs/tmp/vm-tmp
export TMPDIR=/home/yunwei37/workspace/bpf-benchmark/docs/tmp/vm-tmp
. /home/yunwei37/workspace/.venv/bin/activate
cd "/home/yunwei37/workspace/bpf-benchmark" && source "/home/yunwei37/workspace/.venv/bin/activate" && "/home/yunwei37/workspace/bpf-benchmark/module/load_all.sh" 2>/dev/null || true; python3 "/home/yunwei37/workspace/bpf-benchmark/daemon/tests/static_verify.py" --daemon-binary "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon" --daemon-args="" --output "/home/yunwei37/workspace/bpf-benchmark/daemon/tests/results/static_verify.json"
