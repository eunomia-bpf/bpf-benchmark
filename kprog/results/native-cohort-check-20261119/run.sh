#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=/workspaces/kprog-raw/perf/native-cohort-check-20261119/bcc-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > /workspaces/kprog-raw/perf/native-cohort-check-20261119/latest
exec > "$out/run.log" 2>&1
exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch
flock -x 7
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/host-started"
rc=0
make -C kprog/libnativeloader checked-corpus CHECKED_APP=bcc/set \
    CHECKED_HOST_CPUS=20-21 CHECKED_OUTPUT="$out" || rc=$?
printf '%s\n' "$rc" > "$out/host-exit-code"
date -u +%FT%TZ > "$out/host-finished"
exit "$rc"
