#!/bin/bash
# OMP 2026-11-21: Tetragon main configuration on the fixed image (3b5fa4b40 + fp-arithmetic pass + nofault bindings).
# Its first arm on this base was SIGTERM'd at 15:35Z (tetragon-final.log: "make ... Terminated", qemu "signal 15
# from pid 1597990") after 5 replaced programs at guest 5460 s; that raw runs directory stays as is and this run
# replaces it.
set -u
ROOT=/workspaces/repository
LOCK=/workspaces/.agent-state/kprog-lanes/locks/timing
MK=$ROOT/kprog/results/lto-apps-20261119/Makefile
out=$ROOT/kprog/results/lto-apps-20261119/tetragon

echo "$(date -u +%FT%TZ) start tetragon/observer (after 15:35Z SIGTERM)"
flock -x "$LOCK" make -f "$MK" checked-timing APP=tetragon/observer OUT="$out" \
  >> "$ROOT/kprog/results/lto-apps-20261119/tetragon-clean.log" 2>&1
echo "$(date -u +%FT%TZ) end tetragon/observer rc=$?"