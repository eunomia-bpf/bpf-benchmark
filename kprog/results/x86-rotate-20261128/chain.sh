#!/bin/bash
# Operator 2026-11-28 05:40Z: "x86 重新性能测试也可以? 还有没有和我们的涉及不符合的?"
# One x86 run of the frozen entry with its defaults (rotate: 3 x 180 s per arm, stats off then on, all six apps,
# breadth first) on the current image, after the native-eBPF alignment fixes e6d02b380, 2d006f5d8, cff33039a and
# 404dd3a1d and the six-app check of 2026-11-28 03:48Z-04:07Z (all app ok, 632 native installs, zero failures).
# Locks in the lanes' order: timing exclusive first, then image shared (no image rebuild during the run), then batch.
R=/workspaces/repository
E=$R/kprog/perf/one-image
L=/workspaces/.agent-state/kprog-lanes/locks
D=/workspaces/kprog-raw/coordinator/x86-rotate-20261128
O=$D/chain.done
mkdir -p $D
exec 7>$L/timing 8>$L/image 9>$L/batch
flock -x 7; flock -s 8; flock -x 9
echo "start $(date -u +%FT%TZ) $(git -C $R rev-parse --short HEAD) image $(docker images --no-trunc --format '{{.ID}} {{.CreatedAt}}' bpf-benchmark/kprog:current 2>/dev/null)" > $O
s=$(date -u +%FT%TZ)
make -C $E rotate LOGS=$D > $D/rotate.out 2>&1; rc=$?
echo "rotate start $s end $(date -u +%FT%TZ) rc=$rc" >> $O
