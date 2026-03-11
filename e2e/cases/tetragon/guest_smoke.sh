#!/usr/bin/env bash
set -eu

cd /home/yunwei37/workspace/bpf-benchmark
export PATH="/usr/local/sbin:$PATH"
export BPFTOOL_BIN="/usr/local/sbin/bpftool"
if [ -f /home/yunwei37/workspace/.venv/bin/activate ]; then
  set +u
  . /home/yunwei37/workspace/.venv/bin/activate
  set -u
fi
export PYTHONPATH="micro${PYTHONPATH:+:$PYTHONPATH}"

python3 e2e/cases/tetragon/case.py \
  --smoke \
  --bpftool "${BPFTOOL_BIN}" \
  --output-json /home/yunwei37/workspace/bpf-benchmark/e2e/results/tetragon-real-e2e.json \
  --output-md /home/yunwei37/workspace/bpf-benchmark/e2e/results/tetragon-real-e2e.md
