#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=/workspaces/kprog-raw/perf/b-analysis-flags-20261119/resume-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > /workspaces/kprog-raw/perf/b-analysis-flags-20261119/latest-resume
exec > "$out/run.log" 2>&1
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
rc=0
taskset -c 18 prlimit --as=17179869184 -- make -f kprog/results/b-analysis-flags-20261119/Makefile resume-post-contracts OUT="$out" || rc=$?
printf '%s\n' "$rc" > "$out/exit-code"
date -u +%FT%TZ > "$out/finished"
exit "$rc"
