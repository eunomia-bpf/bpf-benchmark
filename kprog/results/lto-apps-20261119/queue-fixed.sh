#!/bin/bash
# OMP: the two arms that need the 3b5fa4b40 image (Tracee panicked and Tetragon was mis-covered before it).
set -u
ROOT=/workspaces/repository
LOCK=/workspaces/.agent-state/kprog-lanes/locks/timing
MK=$ROOT/kprog/results/lto-apps-20261119/Makefile

for app in tetragon/observer tracee/monitor; do
  name=${app%%/*}
  out=$ROOT/kprog/results/lto-apps-20261119/$name
  echo "$(date -u +%FT%TZ) start $app"
  flock -x "$LOCK" make -f "$MK" checked-timing APP="$app" OUT="$out" \
    >> "$ROOT/kprog/results/lto-apps-20261119/$name-fixed.log" 2>&1
  echo "$(date -u +%FT%TZ) end $app rc=$?"
done
echo "$(date -u +%FT%TZ) fixedqueue done"