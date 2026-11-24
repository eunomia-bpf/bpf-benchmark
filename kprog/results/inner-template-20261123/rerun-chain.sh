#!/bin/bash
# Operator 2026-11-24 03:2x UTC: "你要想办法每个程序确保用到最好的版本, 比如说这样的性能. 代码要是这样的."
# The 11-23 x86 rotate on 30e401e37 timed Tetragon (both stats modes), Cilium and OTel (stats on) while the
# lab host's E-cores carried 3-13 busy cores; this reruns those apps plus BCC on the same image with the
# frozen entry and its defaults. Progress in /workspaces/kprog-raw/coordinator/rerun-20261124/chain.done.
D=/workspaces/kprog-raw/coordinator/rerun-20261124
R=/workspaces/repository
E=$R/kprog/perf/one-image
L=/workspaces/.agent-state/kprog-lanes/locks
O=$D/chain.done
mkdir -p $D
echo "start $(date -u +%FT%TZ) $(git -C $R rev-parse --short HEAD) image $(docker images --format '{{.CreatedAt}}' bpf-benchmark/kprog:current 2>/dev/null)" > $O
s=$(date -u +%FT%TZ)
flock $L/timing make -C $E rotate LOGS=$D \
  ORDER="tetragon/observer cilium/agent otelcol-ebpf-profiler/profiling bcc/set" > $D/rotate.out 2>&1; rc=$?
echo "rotate start $s end $(date -u +%FT%TZ) rc=$rc" >> $O
