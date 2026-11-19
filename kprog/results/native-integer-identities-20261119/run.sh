#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=/workspaces/kprog-raw/perf/native-integer-identities-20261119/candidate-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > /workspaces/kprog-raw/perf/native-integer-identities-20261119/latest-candidate
exec > "$out/run.log" 2>&1
exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch
flock -x 7
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
flock -x 9
validate() {
    date -u +%FT%TZ > "$out/started"
    git apply --check kprog/results/native-integer-identities-20261119/implementation.patch
    git apply kprog/results/native-integer-identities-20261119/implementation.patch
    taskset -c 19 prlimit --as=17179869184 -- make -C kprog/libnativeloader checked-sim-stage > "$out/stage.log" 2>&1
    taskset -c 19 prlimit --as=17179869184 -- make -f kprog/results/native-integer-identities-20261119/Makefile test OUT="$out"
    taskset -c 19 prlimit --as=17179869184 -- make -f kprog/results/native-verified-paths-20261119/Makefile test OUT="$out/verified"
    taskset -c 19 prlimit --as=17179869184 -- make -f kprog/results/checked-probe-c-20261119/Makefile replay OUT="$out" > "$out/bcc-replay.log" 2>&1
    taskset -c 19 prlimit --as=17179869184 -- make -f kprog/results/checked-probe-c-20261119/Makefile test OUT="$out/probe" > "$out/probe.log" 2>&1
    taskset -c 19 prlimit --as=17179869184 -- make -f kprog/results/checked-array-c-20261119/Makefile test pipeline OUT="$out/array" > "$out/array.log" 2>&1
}
rc=0
set +e
( set -e; validate )
rc=$?
set -e
printf '%s\n' "$rc" > "$out/exit-code"
date -u +%FT%TZ > "$out/finished"
exit "$rc"
