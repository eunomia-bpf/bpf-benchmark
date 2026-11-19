#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=/workspaces/kprog-raw/perf/skb-numeric-integration-20261119/fix-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > /workspaces/kprog-raw/perf/skb-numeric-integration-20261119/fix-latest
exec > "$out/run.log" 2>&1
finish() { printf '%s\n' "$?" > "$out/exit-code"; date -u +%FT%TZ > "$out/finished"; }
trap finish EXIT
date -u +%FT%TZ > "$out/queued"
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
flock -x 9
git rev-parse HEAD > "$out/source-commit"
git diff -- kprog/x86/compile_sim_ir.cpp > "$out/source-change.diff"
date -u +%FT%TZ > "$out/started"
taskset -c 18 prlimit --as=8589934592 -- make -C kprog/libnativeloader checked-sim-stage
taskset -c 18 prlimit --as=4294967296 -- make -f kprog/results/skb-numeric-integration-20261119/Makefile test OUT="$out/skb"
taskset -c 18 prlimit --as=4294967296 -- make -f kprog/results/numeric-context-bridge-20261119/Makefile reproduce OUT="$out/numeric"
