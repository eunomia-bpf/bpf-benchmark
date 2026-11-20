#!/bin/bash
# OMP: re-run the arm that failed on the stale base loader, one lock-hold each.
set -u
ROOT=/workspaces/repository
LOCK=/workspaces/.agent-state/kprog-lanes/locks/timing
MK=$ROOT/kprog/results/lto-apps-20261119/Makefile

# tetragon is already running from the direct invocation; wait for its service archive.
while pgrep -f "checked-timing APP=tetragon" >/dev/null; do sleep 30; done
for app in tracee/monitor; do
  name=${app%%/*}
  out=$ROOT/kprog/results/lto-apps-20261119/$name
  echo "$(date -u +%FT%TZ) start $app"
  flock -x "$LOCK" make -f "$MK" checked-timing APP="$app" OUT="$out" \
    >> "$ROOT/kprog/results/lto-apps-20261119/$name.log" 2>&1
  echo "$(date -u +%FT%TZ) end $app rc=$?"
done
echo "$(date -u +%FT%TZ) requeue done"
