#!/bin/bash
# OMPa: Tetragon again, after Tracee's arm in queue-fixed.sh finishes (its post arm hung once).
set -u
ROOT=/workspaces/repository
LOCK=/workspaces/.agent-state/kprog-lanes/locks/timing
MK=$ROOT/kprog/results/lto-apps-20261119/Makefile
out=$ROOT/kprog/results/lto-apps-20261119/tetragon

while pgrep -f "checked-timing APP=tracee" >/dev/null; do sleep 30; done
echo "$(date -u +%FT%TZ) start tetragon/observer (retry)"
flock -x "$LOCK" make -f "$MK" checked-timing APP=tetragon/observer OUT="$out" \
  >> "$ROOT/kprog/results/lto-apps-20261119/tetragon-fixed.log" 2>&1
echo "$(date -u +%FT%TZ) end tetragon/observer rc=$?"