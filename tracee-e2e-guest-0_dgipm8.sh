#!/bin/bash
set -eu
cd /home/yunwei37/workspace/bpf-benchmark
export PATH="/usr/local/sbin:$PATH"
mkdir -p /home/yunwei37/workspace/bpf-benchmark/docs/tmp/vm-tmp
export TMPDIR=/home/yunwei37/workspace/bpf-benchmark/docs/tmp/vm-tmp
. /home/yunwei37/workspace/.venv/bin/activate
source "/home/yunwei37/workspace/.venv/bin/activate" && "/home/yunwei37/workspace/bpf-benchmark/module/load_all.sh" 2>/dev/null || true; "/home/yunwei37/workspace/bpf-benchmark/runner/scripts/vm-selftest.sh" "/home/yunwei37/workspace/bpf-benchmark" "/home/yunwei37/workspace/bpf-benchmark/tests/kernel/build/test_recompile" "/home/yunwei37/workspace/bpf-benchmark/tests/unittest" "/home/yunwei37/workspace/bpf-benchmark/module/x86"
