#!/bin/bash
set -euo pipefail
cd /workspaces/repository
base=/workspaces/kprog-raw/perf/sparse-stack-cache-20261119
out=$base/tetragon-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > "$base/latest-tetragon"
exec > "$out/run.log" 2>&1
finish() { printf '%s\n' "$?" > "$out/exit-code"; date -u +%FT%TZ > "$out/finished"; }
trap finish EXIT
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
make -n -f kprog/results/sparse-stack-cache-20261119/Makefile tetragon OUT="$out" > "$out/dry-run.log"
taskset -c 20 prlimit --as=34359738368 -- make -f kprog/results/sparse-stack-cache-20261119/Makefile tetragon OUT="$out"
