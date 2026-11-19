#!/bin/bash
# BCC in the LTO configuration (checked-sim-c) after the native side freezes private unknown inputs (2eb36bad9).
# Starts once the request-time inputs (simulator headers, generator, service, loader) have no uncommitted edits,
# then installs the checked-sim compiler tools from HEAD and times BCC with the existing recipe.
set -euo pipefail
cd /workspaces/repository
base=/workspaces/kprog-raw/coordinator/lto-freeze-20261119
out=$base/batch-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > "$base/latest"
exec > "$out/run.log" 2>&1
progress() { printf '%s %s\n' "$(date -u +%FT%TZ)" "$1" >> "$out/progress.log"; }
inputs='kprog/x86 kprog/trusted_generation.py kprog/trusted_service.py kprog/trusted_compile.py kprog/libnativeloader kprog/stock-path kprog/formal/generated'
progress 'waiting for committed request-time inputs'
while [ -n "$(git status --porcelain -- $inputs)" ]; do sleep 120; done
exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch
flock -x 7
git rev-parse HEAD > "$out/source-commit"
git status --porcelain -- $inputs > "$out/inputs-status-start"
progress "batch start at $(cat "$out/source-commit")"
rc=0
set +e
(
    set -e
    (
        exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
        exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -x 9
        taskset -c 8-23 make -C kprog/libnativeloader checked-sim-stage
    ) > "$out/tools.log" 2>&1
    progress 'tools installed; BCC checked timing start'
    (
        exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
        exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9
        make -f kprog/results/native-cohort-timing-20261119/Makefile checked-timing OUT="$out/timing"
    ) > "$out/timing.log" 2>&1
    progress 'timing done'
)
rc=$?
set -e
git status --porcelain -- $inputs > "$out/inputs-status-end"
printf '%s\n' "$rc" > "$out/exit-code"
date -u +%FT%TZ > "$out/finished"
progress "batch done rc=$rc"
exit "$rc"
