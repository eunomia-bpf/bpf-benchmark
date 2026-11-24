#!/bin/bash
# Coordinator 2026-11-24T04:3xZ: the rerun's Tetragon stats-off run (03:35-04:00Z) had the lab host's E-cores 3.5-10.7
# busy in both halves; after rerun-20261124/chain.sh ends, Tetragon runs once more with the frozen entry and its
# defaults (stats off then on), and its per-phase host load is recorded as for the others.
D=/workspaces/kprog-raw/coordinator/rerun-20261124
R=/workspaces/repository
E=$R/kprog/perf/one-image
L=/workspaces/.agent-state/kprog-lanes/locks
O=$D/chain.done
until grep -q "^rotate " $O 2>/dev/null; do sleep 60; done
s=$(date -u +%FT%TZ)
flock $L/timing make -C $E rotate LOGS=$D ORDER="tetragon/observer" > $D/rotate2.out 2>&1; rc=$?
echo "rotate2 tetragon start $s end $(date -u +%FT%TZ) rc=$rc" >> $O
