#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=/workspaces/kprog-raw/perf/b-analysis-flags-20261119/production-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > /workspaces/kprog-raw/perf/b-analysis-flags-20261119/latest-production
exec > "$out/run.log" 2>&1
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
flock -s 9
date -u +%FT%TZ > "$out/started"
rc=0
taskset -c 19 prlimit --as=34359738368 -- make -f kprog/results/b-analysis-flags-20261119/Makefile compile OUT="$out" || rc=$?
printf '%s\n' "$rc" > "$out/exit-code"
date -u +%FT%TZ > "$out/finished"
exit "$rc"
