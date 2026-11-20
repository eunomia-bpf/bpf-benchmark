#!/bin/bash
# OMP: the Tracee and Tetragon arms on the 3b5fa4b40 image, once the coordinator's rotation releases
# locks/timing. Each arm takes 25-35 min (Tetragon's load is ~600 s of guest time and each arm is 3 x 180 s).
set -u
ROOT=/workspaces/repository
LOCK=/workspaces/.agent-state/kprog-lanes/locks/timing
MK=$ROOT/kprog/results/lto-apps-20261119/Makefile

# Wait until the rotation's loop is gone, not merely until the lock looks free.
while pgrep -f "for s in 0 1" >/dev/null; do sleep 60; done
echo "$(date -u +%FT%TZ) rotation gone"

for app in tracee/monitor tetragon/observer; do
  name=${app%%/*}
  out=$ROOT/kprog/results/lto-apps-20261119/$name
  echo "$(date -u +%FT%TZ) start $app"
  flock -x "$LOCK" make -f "$MK" checked-timing APP="$app" OUT="$out" \
    >> "$ROOT/kprog/results/lto-apps-20261119/$name-final.log" 2>&1
  echo "$(date -u +%FT%TZ) end $app rc=$?"
done
echo "$(date -u +%FT%TZ) finalqueue done"