#!/bin/bash
set -euo pipefail
cd /workspaces/repository
base=/workspaces/kprog-raw/perf/b-pointer-difference-20261119
out=$base/fix-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > "$base/latest-fix"
exec > "$out/run.log" 2>&1
finish() { printf '%s\n' "$?" > "$out/exit-code"; date -u +%FT%TZ > "$out/finished"; }
trap finish EXIT
date -u +%FT%TZ > "$out/queued"
# Host compiler work does not use the CPUs0-7 timing lock. Replace the sole
# compiler under image EX, then share it for the affected host checks.
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
flock -x 9
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/b-pointer-difference-20261119/Makefile rebuild
flock -s 9
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/b-pointer-difference-20261119/Makefile test OUT="$out/fixture" MODE=fixed
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/constant-alu32-20261119/Makefile test OUT="$out/constant-alu32" MODE=fixed
taskset -c 19 prlimit --as=8589934592 -- make -f kprog/results/b-pointer-difference-20261119/Makefile replay OUT="$out/katran" REQUEST=katran
