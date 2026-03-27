#!/usr/bin/env bash
set -euo pipefail

cd /home/yunwei37/workspace/bpf-benchmark
./module/load_all.sh 2>/dev/null || true
python3 docs/tmp/20260327/tracee_targeted_perf_probe.py > docs/tmp/20260327/tracee_targeted_perf_probe_20260327.log 2>&1
