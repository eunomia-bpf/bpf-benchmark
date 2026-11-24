#!/bin/bash
# Coordinator 2026-11-24T08:2xZ: Tetragon's three stats-off runs on 30e401e37 (0.459x, 0.880x, 1.882x) all had the
# lab host's E-cores busy; this runs Tetragon once more with the frozen entry and its defaults after the lanes'
# queued shared-lock jobs, recording the per-phase host load as for the others.
D=/workspaces/kprog-raw/coordinator/rerun-20261124
E=/workspaces/repository/kprog/perf/one-image
L=/workspaces/.agent-state/kprog-lanes/locks
s=$(date -u +%FT%TZ)
flock $L/timing make -C $E rotate LOGS=$D ORDER="tetragon/observer" > $D/rotate3.out 2>&1; rc=$?
echo "rotate3 tetragon queued $s start-of-wait end $(date -u +%FT%TZ) rc=$rc" >> $D/chain.done
