#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=/workspaces/kprog-raw/perf/native-base-roots-20261119/arithmetic-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > /workspaces/kprog-raw/perf/native-base-roots-20261119/latest-arithmetic
exec > "$out/run.log" 2>&1
printf '%s waiting for timing SH\n' "$(date -u +%FT%TZ)" > "$out/progress.txt"
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
date -u +%FT%TZ > "$out/started"
rc=0
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/native-base-roots-20261119/Makefile inspect \
    INPUT=/workspaces/kprog-raw/perf/native-integer-identities-20261119/candidate-20261119T075305Z-233661/bcc-replay/17/checked-simulator.native.bc \
    OUT="$out/roots.tsv" || rc=$?
printf '%s\n' "$rc" > "$out/exit-code"
date -u +%FT%TZ > "$out/finished"
exit "$rc"
