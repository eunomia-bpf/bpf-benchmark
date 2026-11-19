#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=/workspaces/kprog-raw/perf/lock-prefix-review-20261119/reproduce-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > /workspaces/kprog-raw/perf/lock-prefix-review-20261119/latest
exec > "$out/run.log" 2>&1
printf '%s waiting for timing SH\n' "$(date -u +%FT%TZ)" > "$out/progress.txt"
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
rc=0
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/lock-prefix-review-20261119/Makefile reproduce OUT="$out" || rc=$?
printf '%s\n' "$rc" > "$out/exit-code"
date -u +%FT%TZ > "$out/finished"
exit "$rc"
