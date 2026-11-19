#!/bin/bash
set -euo pipefail
cd /workspaces/repository
base=/workspaces/kprog-raw/perf/b-pointer-difference-20261119
out=$base/confirm-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > "$base/latest-confirm"
exec > "$out/run.log" 2>&1
finish() { printf '%s\n' "$?" > "$out/exit-code"; date -u +%FT%TZ > "$out/finished"; }
trap finish EXIT
date -u +%FT%TZ > "$out/queued"
exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch
flock -x 7
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
flock -s 9
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/b-pointer-difference-20261119/Makefile stock-probe
make -n -f kprog/results/b-pointer-difference-20261119/Makefile stock OUT="$out/stock" > "$out/dry-run.log"
make -f kprog/results/b-pointer-difference-20261119/Makefile stock OUT="$out/stock"
taskset -c 19 prlimit --as=34359738368 -- make -f kprog/results/b-pointer-difference-20261119/Makefile replay OUT="$out/tracee30" REQUEST=30
