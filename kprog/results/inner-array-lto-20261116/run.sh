#!/bin/bash
set -u
raw=${1:-/workspaces/kprog-raw/perf/20261116-inner-array-lto}
target=${2:-host}
install -d "$raw"
date -u +%FT%TZ > "$raw/started"
make -f /workspaces/repository/kprog/results/inner-array-lto-20261116/Makefile "$target" RAW="$raw"
status=$?
printf '%s\n' "$status" > "$raw/exit-code"
date -u +%FT%TZ > "$raw/finished"
exit "$status"
