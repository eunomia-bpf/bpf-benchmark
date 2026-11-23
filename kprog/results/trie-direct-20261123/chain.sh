#!/bin/bash
# 77908203a (a lookup on a known LPM trie calls trie_lookup_elem): the one image rebuilt by the frozen
# entry, the six-app function check, a host-PMU profile of OTel (profile-host.sh) to see the effect, then
# the frozen rotate on the apps with LPM tries (OTel's pid_page_to_mapping_info, Cilium's ipcache,
# Tetragon and Tracee list LPM maps in their manifests): 3 samples x 180 s per arm, stats off then on.
# Progress in /workspaces/kprog-raw/coordinator/trie-20261123/chain.done.
D=/workspaces/kprog-raw/coordinator/trie-20261123
R=/workspaces/repository
E=$R/kprog/perf/one-image
L=/workspaces/.agent-state/kprog-lanes/locks
O=$D/chain.done
mkdir -p $D
echo "start $(date -u +%FT%TZ) $(git -C $R rev-parse --short HEAD)" > $O
s=$(date -u +%FT%TZ)
flock $L/image nice -n 5 taskset -c 8-23 make -C $E image IMAGE_BUILD_JOBS=16 JOBS=16 > $D/image.log 2>&1; rc=$?
echo "image start $s end $(date -u +%FT%TZ) rc=$rc" >> $O
[ $rc = 0 ] || exit 0
s=$(date -u +%FT%TZ)
flock $L/timing make -C $E check LOGS=$D > $D/check.out 2>&1; rc=$?
echo "check start $s end $(date -u +%FT%TZ) rc=$rc" >> $O
s=$(date -u +%FT%TZ)
bash $R/kprog/results/profile-20261123/profile-host.sh otelcol-ebpf-profiler/profiling \
  /workspaces/kprog-raw/coordinator/profile-20261123/otel-host-77908203a perf_unwind_nat > $D/profile.log 2>&1
echo "profile start $s end $(date -u +%FT%TZ)" >> $O
s=$(date -u +%FT%TZ)
flock $L/timing make -C $E rotate LOGS=$D \
  ORDER="otelcol-ebpf-profiler/profiling cilium/agent tetragon/observer tracee/monitor" > $D/rotate.out 2>&1; rc=$?
echo "rotate start $s end $(date -u +%FT%TZ) rc=$rc" >> $O
