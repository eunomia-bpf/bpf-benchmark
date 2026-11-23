#!/bin/bash
# arm64 after 77908203a (the loader both ISAs use gives a known LPM trie a direct trie_lookup_elem call):
# waits for the x86 rotate of kprog/results/trie-direct-20261123/chain.sh, then rebuilds the arm64 image
# with the frozen entry and runs its six-app function check holding the timing lock.
# Progress in /workspaces/kprog-raw/coordinator/trie-20261123/arm64.done.
D=/workspaces/kprog-raw/coordinator/trie-20261123
R=/workspaces/repository
E=$R/kprog/perf/one-image-arm64
L=/workspaces/.agent-state/kprog-lanes/locks
O=$D/arm64.done
until grep -q "^rotate " $D/chain.done 2>/dev/null; do sleep 60; done
echo "start $(date -u +%FT%TZ) $(git -C $R rev-parse --short HEAD)" > $O
s=$(date -u +%FT%TZ)
flock $L/image nice -n 5 taskset -c 8-23 make -C $E image IMAGE_BUILD_JOBS=16 JOBS=16 > $D/arm64-image.log 2>&1; rc=$?
echo "image start $s end $(date -u +%FT%TZ) rc=$rc" >> $O
[ $rc = 0 ] || exit 0
s=$(date -u +%FT%TZ)
flock $L/timing make -C $E check LOGS=$D/arm64 > $D/arm64-check.out 2>&1; rc=$?
echo "check start $s end $(date -u +%FT%TZ) rc=$rc" >> $O
