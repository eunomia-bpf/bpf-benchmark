#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=/workspaces/kprog-raw/perf/b-pointer-difference-20261119/test-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > /workspaces/kprog-raw/perf/b-pointer-difference-20261119/latest
exec > "$out/run.log" 2>&1
finish() { printf '%s\n' "$?" > "$out/exit-code"; date -u +%FT%TZ > "$out/finished"; }
trap finish EXIT
date -u +%FT%TZ > "$out/queued"
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
flock -s 9
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
make -n -f kprog/results/b-pointer-difference-20261119/Makefile test OUT="$out" > "$out/dry-run.log"
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/b-pointer-difference-20261119/Makefile test OUT="$out"
