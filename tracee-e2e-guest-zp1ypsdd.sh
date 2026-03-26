#!/bin/bash
set -eu
cd /home/yunwei37/workspace/bpf-benchmark
export PATH="/usr/local/sbin:$PATH"
mkdir -p /home/yunwei37/workspace/bpf-benchmark/docs/tmp/vm-tmp
export TMPDIR=/home/yunwei37/workspace/bpf-benchmark/docs/tmp/vm-tmp
. /home/yunwei37/workspace/.venv/bin/activate
cd "/home/yunwei37/workspace/bpf-benchmark" && source "/home/yunwei37/workspace/.venv/bin/activate" && "/home/yunwei37/workspace/bpf-benchmark/module/load_all.sh" 2>/dev/null || true; cd /home/yunwei37/workspace/bpf-benchmark && ./tests/unittest/build/rejit_rollback_tests && ./tests/unittest/build/rejit_struct_ops_multi_callsite_tests ./tests/unittest/build/progs && ./tests/unittest/build/rejit_struct_ops_rollback_tests ./tests/unittest/build/progs
