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
# The coordinator owns the current image/check/timing batch. Replace the sole
# compiler only after its batch, then keep that compiler stable for the tests.
exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch
flock -x 7
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
flock -x 9
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/b-pointer-difference-20261119/Makefile rebuild
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/b-pointer-difference-20261119/Makefile test OUT="$out/fixture" MODE=fixed
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/constant-alu32-20261119/Makefile test OUT="$out/constant-alu32" MODE=fixed
taskset -c 19 prlimit --as=34359738368 -- make -f kprog/results/b-pointer-difference-20261119/Makefile replay OUT="$out/tracee27"
