#!/bin/bash
set -euo pipefail
cd /workspaces/repository
base=/workspaces/kprog-raw/perf/sparse-stack-cache-20261119
out=$base/check-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > "$base/latest"
exec > "$out/run.log" 2>&1
finish() { printf '%s\n' "$?" > "$out/exit-code"; date -u +%FT%TZ > "$out/finished"; }
trap finish EXIT
date -u +%FT%TZ > "$out/queued"
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
flock -s 9
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
taskset -c 20 prlimit --as=8589934592 -- make -f kprog/results/sparse-stack-cache-20261119/Makefile check OUT="$out"
taskset -c 20 prlimit --as=4294967296 -- make -f kprog/results/tetragon-stack-liveness-20261119/Makefile cache-inventory OUT="$out/tetragon"
