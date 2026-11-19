#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=/workspaces/kprog-raw/perf/numeric-context-bridge-20261119/reproduce-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > /workspaces/kprog-raw/perf/numeric-context-bridge-20261119/latest
exec > "$out/run.log" 2>&1
date -u +%FT%TZ > "$out/queued"
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
flock -s 9
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
rc=0
taskset -c 18 make -f kprog/results/numeric-context-bridge-20261119/Makefile -n reproduce OUT="$out" > "$out/dry-run.txt" 2>&1 || rc=$?
if [ "$rc" -eq 0 ]; then
    taskset -c 18 prlimit --as=4294967296 -- make -f kprog/results/numeric-context-bridge-20261119/Makefile reproduce OUT="$out" || rc=$?
fi
printf '%s\n' "$rc" > "$out/exit-code"
date -u +%FT%TZ > "$out/finished"
exit "$rc"
