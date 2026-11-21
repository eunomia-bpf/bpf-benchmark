#!/bin/bash
# OMP: after the current queue finishes, re-run Tracee once more. Its arm was loading programs when the base
# loader gained the nofault symbols, so its coverage is ambiguous; Tetragon runs after that point and is clean.
set -u
ROOT=/workspaces/repository
LOCK=/workspaces/.agent-state/kprog-lanes/locks/timing
MK=$ROOT/kprog/results/lto-apps-20261119/Makefile
out=$ROOT/kprog/results/lto-apps-20261119/tracee

while pgrep -f "queue-final.sh" >/dev/null; do sleep 60; done
echo "$(date -u +%FT%TZ) queue-final gone"
flock -x "$LOCK" make -f "$MK" checked-timing APP=tracee/monitor OUT="$out" \
  >> "$ROOT/kprog/results/lto-apps-20261119/tracee-clean.log" 2>&1
echo "$(date -u +%FT%TZ) end tracee/observer rc=$?"