#!/bin/bash
set -u
raw=${1:-/workspaces/kprog-raw/perf/20261116-known-lookup-targets}
install -d "$raw"
date -u +%FT%TZ > "$raw/started"
make -f /workspaces/repository/kprog/results/known-lookup-targets-20261116/Makefile host RAW="$raw"
status=$?
printf '%s\n' "$status" > "$raw/exit-code"
date -u +%FT%TZ > "$raw/finished"
exit "$status"
