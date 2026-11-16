#!/bin/bash
set -u
target=${1:?audit or profile}
raw=${2:-/workspaces/kprog-raw/perf/20261116-otel-regression}
install -d "$raw"
date -u +%FT%TZ > "$raw/$target.started"
make -f /workspaces/repository/kprog/results/otel-regression-20261116/Makefile "$target" RAW="$raw"
status=$?
printf '%s\n' "$status" > "$raw/$target.exit-code"
date -u +%FT%TZ > "$raw/$target.finished"
exit "$status"
