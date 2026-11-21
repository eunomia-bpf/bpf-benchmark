#!/bin/bash
# OMP: after the coordinator's rotation ends, rebuild the base compiler in place (the fp-arithmetic pass change
# landed mid-rotation), then run the Tracee and Tetragon arms on the 3b5fa4b40 image.
set -u
ROOT=/workspaces/repository
LOCK=/workspaces/.agent-state/kprog-lanes/locks/timing
MK=$ROOT/kprog/results/lto-apps-20261119/Makefile
COMPILER=/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds

while pgrep -f "for s in 0 1" >/dev/null; do sleep 60; done
echo "$(date -u +%FT%TZ) rotation gone"

before=$(md5sum "$COMPILER" | cut -d' ' -f1)
echo "$(date -u +%FT%TZ) packet-bounds before $before"
make -C "$ROOT/kprog/libnativeloader" checked-sim-stage >> "$ROOT/kprog/results/lto-apps-20261119/compiler-rebuild.log" 2>&1
after=$(md5sum "$COMPILER" | cut -d' ' -f1)
echo "$(date -u +%FT%TZ) packet-bounds after  $after"

for app in tracee/monitor tetragon/observer; do
  name=${app%%/*}
  out=$ROOT/kprog/results/lto-apps-20261119/$name
  echo "$(date -u +%FT%TZ) start $app"
  flock -x "$LOCK" make -f "$MK" checked-timing APP="$app" OUT="$out" \
    >> "$ROOT/kprog/results/lto-apps-20261119/$name-final.log" 2>&1
  echo "$(date -u +%FT%TZ) end $app rc=$?"
done
echo "$(date -u +%FT%TZ) finalqueue done"