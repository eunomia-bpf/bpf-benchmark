#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=/workspaces/kprog-raw/perf/numeric-context-bridge-20261119/fix-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > /workspaces/kprog-raw/perf/numeric-context-bridge-20261119/latest-fix
exec > "$out/run.log" 2>&1
date -u +%FT%TZ > "$out/queued"
exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch
flock -x 7
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
flock -x 9
finish() {
    printf '%s\n' "$?" > "$out/exit-code"
    date -u +%FT%TZ > "$out/finished"
}
trap finish EXIT
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
git apply --verbose kprog/results/numeric-context-bridge-20261119/fix-forward.patch
git diff -- kprog/stock-path/include/stock_native_input.h kprog/x86/compile_sim_ir.cpp > "$out/applied.patch"
taskset -c 18 prlimit --as=17179869184 -- make -C kprog/libnativeloader checked-sim-stage > "$out/build.log" 2>&1
taskset -c 18 make -f kprog/results/numeric-context-bridge-20261119/Makefile -n reproduce OUT="$out" > "$out/dry-run.txt"
taskset -c 18 prlimit --as=4294967296 -- make -f kprog/results/numeric-context-bridge-20261119/Makefile reproduce OUT="$out"
