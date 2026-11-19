#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=/workspaces/kprog-raw/perf/tracee-live-failures-20261119/recovery-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > /workspaces/kprog-raw/perf/tracee-live-failures-20261119/recovery-latest
exec > "$out/run.log" 2>&1
finish() { printf '%s\n' "$?" > "$out/exit-code"; date -u +%FT%TZ > "$out/finished"; }
trap finish EXIT
date -u +%FT%TZ > "$out/queued"
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/tracee-live-failures-20261119/Makefile recover \
    REQUESTS=/workspaces/kprog-raw/coordinator/lto-apps-20261119/tracee_monitor-20261119T133821Z/timing/state/session-x9mp5xyg/requests OUT="$out"
