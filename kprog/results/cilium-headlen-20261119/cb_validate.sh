#!/bin/bash
set -euo pipefail
cd /workspaces/repository
base=/workspaces/kprog-raw/perf/cilium-headlen-20261119
out=$base/cb-candidate-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > "$base/latest-cb-candidate"
exec > "$out/run.log" 2>&1
finish(){ printf '%s\n' "$?" > "$out/exit-code"; date -u +%FT%TZ > "$out/finished"; }
trap finish EXIT
date -u +%FT%TZ > "$out/queued"
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
make -n -f kprog/results/b-pointer-difference-20261119/Makefile rebuild > "$out/rebuild-dry-run.log"
flock -x 9
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/b-pointer-difference-20261119/Makefile rebuild
flock -s 9
make -n -f kprog/results/cilium-headlen-20261119/Makefile check OUT="$out/fixture" MODE=after > "$out/check-dry-run.log"
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/cilium-headlen-20261119/Makefile check OUT="$out/fixture" MODE=after
make -n -f kprog/results/cilium-headlen-20261119/Makefile replay OUT="$out/replay" > "$out/replay-dry-run.log"
taskset -c 8-11 prlimit --as=8589934592 -- make -f kprog/results/cilium-headlen-20261119/Makefile replay OUT="$out/replay"
make -n -f kprog/results/cilium-headlen-20261119/Makefile archive-prepare archive-stock OUT="$out/stock" REPLAY="$out/replay" > "$out/stock-dry-run.log"
make -f kprog/results/cilium-headlen-20261119/Makefile archive-prepare OUT="$out/stock" REPLAY="$out/replay"
make -f kprog/results/cilium-headlen-20261119/Makefile archive-stock OUT="$out/stock" REPLAY="$out/replay"
