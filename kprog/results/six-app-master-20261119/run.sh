#!/bin/bash
# Six apps on current master through the frozen timing entry (kprog/perf/one-image/Makefile rotate:
# stats off then on, three 180 s samples per app, breadth first), on the sole image as built at 12:27 UTC.
# Starts after perf's numeric repair worker 407693 has exited, then holds batch EX for the whole rotation.
set -euo pipefail
cd /workspaces/repository
base=/workspaces/kprog-raw/coordinator/six-app-master-20261119
out=$base/batch-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > "$base/latest"
exec > "$out/run.log" 2>&1
progress() { printf '%s %s\n' "$(date -u +%FT%TZ)" "$1" >> "$out/progress.log"; }
progress 'waiting for perf numeric repair worker 407693'
while kill -0 407693 2>/dev/null; do sleep 60; done
exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch
flock -x 7
git rev-parse HEAD > "$out/source-commit"
docker images --format '{{.Repository}}:{{.Tag}} {{.ID}} {{.CreatedAt}}' | grep kprog > "$out/image" || true
progress "rotation start at $(cat "$out/source-commit")"
rc=0
set +e
(
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9
    make -f kprog/perf/one-image/Makefile rotate LOGS="$out/rotate"
) > "$out/rotate.log" 2>&1
rc=$?
set -e
printf '%s\n' "$rc" > "$out/exit-code"
date -u +%FT%TZ > "$out/finished"
progress "rotation done rc=$rc"
exit "$rc"
