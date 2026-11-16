#!/bin/bash
set -uo pipefail
cd /workspaces/repository
raw=${1:-/workspaces/kprog-raw/perf/20261116-cilium-cb-frame}
target=${2:-host}
make -f kprog/results/cilium-cb-frame-20261116/Makefile "$target" RAW="$raw"
status=$?
printf '%s\n' "$status" > "$raw/exit-code"
date -u +%FT%TZ > "$raw/controller-finished"
exit "$status"
