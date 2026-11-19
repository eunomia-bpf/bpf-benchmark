#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=/workspaces/kprog-raw/perf/tetragon-stack-liveness-20261119/inspect-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > /workspaces/kprog-raw/perf/tetragon-stack-liveness-20261119/latest
exec > "$out/run.log" 2>&1
date -u +%FT%TZ > "$out/queued"
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
input_dir=/workspaces/kprog-raw/perf/b-analysis-flags-20261119/production-20261119T063707Z-211523/tetragon6
rc=0
for stage in before packed; do
    input=$input_dir/trusted_x86.bpf.$stage.mir
    taskset -c 19 make -f kprog/results/tetragon-stack-liveness-20261119/Makefile -n inspect INPUT="$input" OUT="$out/$stage.json" > "$out/$stage-dry-run.txt" 2>&1 || rc=$?
    if [ "$rc" -eq 0 ]; then
        taskset -c 19 prlimit --as=8589934592 -- make -f kprog/results/tetragon-stack-liveness-20261119/Makefile inspect INPUT="$input" OUT="$out/$stage.json" || rc=$?
    fi
    if [ "$rc" -ne 0 ]; then break; fi
done
printf '%s\n' "$rc" > "$out/exit-code"
date -u +%FT%TZ > "$out/finished"
exit "$rc"
