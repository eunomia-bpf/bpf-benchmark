#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=/workspaces/kprog-raw/perf/native-cohort-timing-20261119/batch-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > /workspaces/kprog-raw/perf/native-cohort-timing-20261119/latest
exec > "$out/run.log" 2>&1
exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch
flock -x 7
git rev-parse HEAD > "$out/source-commit"
progress() { printf '%s %s\n' "$(date -u +%FT%TZ)" "$1" >> "$out/progress.log"; }
batch() {
    progress 'image start'
    (
        exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
        exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -x 9
        taskset -c 8-23 prlimit --as=103079215104 -- make -f kprog/perf/one-image/Makefile image JOBS=16
    ) > "$out/image.log" 2>&1
    progress 'image done; check start'
    (
        exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
        exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9
        make -f kprog/perf/one-image/Makefile check LOGS="$out/check"
    ) > "$out/check.log" 2>&1
    progress 'check done; BCC checked timing start'
    (
        exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
        exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9
        make -f kprog/results/native-cohort-timing-20261119/Makefile checked-timing OUT="$out/timing"
    ) > "$out/timing.log" 2>&1
    progress 'batch done'
}
rc=0
set +e
( set -e; batch )
rc=$?
set -e
printf '%s\n' "$rc" > "$out/exit-code"
date -u +%FT%TZ > "$out/finished"
exit "$rc"
