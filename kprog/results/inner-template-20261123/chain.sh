#!/bin/bash
# 30e401e37 (a lookup on an inner map takes the outer map's inner-template form) on top of 77908203a
# (LPM tries call trie_lookup_elem). The rotate of chain.sh stops after OTel stats 0 (STOP file); this
# rebuilds the one x86 image with the frozen entry, runs the six-app check, then the frozen rotate on the
# apps either change reaches: OTel, Cilium, Tetragon, Tracee (LPM tries) and Katran, Cilium, Tetragon,
# Tracee (maps of maps). Progress in /workspaces/kprog-raw/coordinator/inner-20261123/chain.done.
D=/workspaces/kprog-raw/coordinator/inner-20261123
T=/workspaces/kprog-raw/coordinator/trie-20261123
R=/workspaces/repository
E=$R/kprog/perf/one-image
L=/workspaces/.agent-state/kprog-lanes/locks
O=$D/chain.done
mkdir -p $D
until grep -q "^rotate " $T/chain.done 2>/dev/null; do sleep 60; done
echo "start $(date -u +%FT%TZ) $(git -C $R rev-parse --short HEAD)" > $O
s=$(date -u +%FT%TZ)
flock $L/image nice -n 5 taskset -c 8-23 make -C $E image IMAGE_BUILD_JOBS=16 JOBS=16 > $D/image.log 2>&1; rc=$?
echo "image start $s end $(date -u +%FT%TZ) rc=$rc" >> $O
[ $rc = 0 ] || exit 0
s=$(date -u +%FT%TZ)
flock $L/timing make -C $E check LOGS=$D > $D/check.out 2>&1; rc=$?
echo "check start $s end $(date -u +%FT%TZ) rc=$rc" >> $O
s=$(date -u +%FT%TZ)
flock $L/timing make -C $E rotate LOGS=$D \
  ORDER="otelcol-ebpf-profiler/profiling cilium/agent tetragon/observer tracee/monitor katran" > $D/rotate.out 2>&1; rc=$?
echo "rotate start $s end $(date -u +%FT%TZ) rc=$rc" >> $O
