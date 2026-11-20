#!/bin/bash
# OMP: run the remaining LTO timing arms one at a time. The timing lock is taken and released per arm so the
# coordinator can interleave its own runs between two arms instead of waiting for the whole batch.
set -u
ROOT=/workspaces/repository
LOCK=/workspaces/.agent-state/kprog-lanes/locks/timing
MK=$ROOT/kprog/results/lto-apps-20261119/Makefile

for app in bcc/set tracee/monitor tetragon/observer; do
  name=${app%%/*}
  out=$ROOT/kprog/results/lto-apps-20261119/$name
  if [ -f "$out/timing-summary.txt" ]; then
    echo "$(date -u +%FT%TZ) skip $app (summary exists)"
    continue
  fi
  echo "$(date -u +%FT%TZ) start $app"
  flock -x "$LOCK" make -f "$MK" checked-timing APP="$app" OUT="$out" \
    >> "$ROOT/kprog/results/lto-apps-20261119/$name.log" 2>&1
  echo "$(date -u +%FT%TZ) end $app rc=$?"
done
echo "$(date -u +%FT%TZ) queue done"