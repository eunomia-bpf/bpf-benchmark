#!/bin/bash
set -euo pipefail
cd /workspaces/repository
mode=${1:?baseline or candidate}
case "$mode" in baseline|candidate) ;; *) exit 1 ;; esac
base=/workspaces/kprog-raw/perf/cilium-headlen-20261119
out=$base/edge-$mode-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > "$base/latest-edge-$mode"
exec > "$out/run.log" 2>&1
finish(){ printf '%s\n' "$?" > "$out/exit-code"; date -u +%FT%TZ > "$out/finished"; }
trap finish EXIT
date -u +%FT%TZ > "$out/queued"
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
if [ "$mode" = candidate ]; then
    make -n -f kprog/results/b-pointer-difference-20261119/Makefile rebuild > "$out/rebuild-dry-run.log"
    flock -x 9
    taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/b-pointer-difference-20261119/Makefile rebuild
    flock -s 9
else
    flock -s 9
fi
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
make -n -f kprog/results/cilium-headlen-20261119/Makefile check OUT="$out/fixture" MODE=after > "$out/check-dry-run.log"
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/cilium-headlen-20261119/Makefile check OUT="$out/fixture" MODE=after
make -n -f kprog/results/cilium-headlen-20261119/Makefile stock-probe stock OUT="$out/stock" FIXTURE="$out/fixture/fixture.bpf.o" > "$out/stock-dry-run.log"
taskset -c 19 make -f kprog/results/cilium-headlen-20261119/Makefile stock-probe
make -f kprog/results/cilium-headlen-20261119/Makefile stock OUT="$out/stock" FIXTURE="$out/fixture/fixture.bpf.o"
if [ "$mode" = candidate ]; then
    make -n -f kprog/results/cilium-headlen-20261119/Makefile replay OUT="$out/replay" > "$out/replay-dry-run.log"
    taskset -c 8-11 prlimit --as=8589934592 -- make -f kprog/results/cilium-headlen-20261119/Makefile replay OUT="$out/replay"
    make -n -C kprog/libnativeloader checked-corpus CHECKED_APP=cilium/agent CHECKED_OUTPUT="$out/cilium" CHECKED_HOST_CPUS=18-19 > "$out/app-dry-run.log"
    make -C kprog/libnativeloader checked-corpus CHECKED_APP=cilium/agent CHECKED_OUTPUT="$out/cilium" CHECKED_HOST_CPUS=18-19
fi
