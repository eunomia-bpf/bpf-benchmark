#!/bin/sh
set -eu

cd /home/yunwei37/workspace/bpf-benchmark
timeout 120s python3 daemon/tests/static_verify.py \
  --mode micro \
  --filter rotate_dense \
  --max-objects 1 \
  --daemon-args=--no-rollback || true

echo "---DMESG---"
dmesg | egrep 'bpf_rejit|bpf_jit|kinsn|rotate|rejit|opcode|ldimm64' | tail -n 200 || true
