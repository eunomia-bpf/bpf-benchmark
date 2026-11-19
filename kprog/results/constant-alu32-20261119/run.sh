#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=/workspaces/kprog-raw/perf/constant-alu32-20261119/replay-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > /workspaces/kprog-raw/perf/constant-alu32-20261119/latest
exec > "$out/run.log" 2>&1
date -u +%FT%TZ > "$out/queued"
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
rc=0
taskset -c 19 make -f kprog/results/constant-alu32-20261119/Makefile -n replay OUT="$out" > "$out/dry-run.txt" 2>&1 || rc=$?
if [ "$rc" -eq 0 ]; then
    taskset -c 19 prlimit --as=34359738368 -- make -f kprog/results/constant-alu32-20261119/Makefile replay OUT="$out" || rc=$?
fi
printf '%s\n' "$rc" > "$out/exit-code"
date -u +%FT%TZ > "$out/finished"
exit "$rc"
