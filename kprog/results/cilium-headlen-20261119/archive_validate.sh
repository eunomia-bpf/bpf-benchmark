#!/bin/bash
set -euo pipefail
cd /workspaces/repository
base=/workspaces/kprog-raw/perf/cilium-headlen-20261119
out=$base/archive-stock-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > "$base/latest-archive-stock"
exec > "$out/run.log" 2>&1
finish(){ printf '%s\n' "$?" > "$out/exit-code"; date -u +%FT%TZ > "$out/finished"; }
trap finish EXIT
date -u +%FT%TZ > "$out/queued"
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
flock -s 9
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
make -n -f kprog/results/cilium-headlen-20261119/Makefile archive-probe archive-prepare archive-stock OUT="$out" > "$out/dry-run.log"
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/cilium-headlen-20261119/Makefile archive-probe
make -f kprog/results/cilium-headlen-20261119/Makefile archive-prepare OUT="$out"
make -f kprog/results/cilium-headlen-20261119/Makefile archive-stock OUT="$out"
