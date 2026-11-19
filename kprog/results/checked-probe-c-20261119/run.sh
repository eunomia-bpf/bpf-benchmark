#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=/workspaces/kprog-raw/perf/checked-probe-c-20261119/host-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > /workspaces/kprog-raw/perf/checked-probe-c-20261119/latest
exec > "$out/run.log" 2>&1
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
flock -x 9
date -u +%FT%TZ > "$out/started"
rc=0
taskset -c 19 prlimit --as=17179869184 -- make -C kprog/libnativeloader checked-sim-stage > "$out/stage.log" 2>&1 || rc=$?
if [ "$rc" = 0 ]; then
 taskset -c 19 prlimit --as=17179869184 -- make -C kprog/libnativeloader trusted-service BUILD_DIR=/workspaces/.agent-state/kprog-ck/verified-loader > "$out/loader.log" 2>&1 || rc=$?
fi
if [ "$rc" = 0 ]; then
 taskset -c 19 prlimit --as=17179869184 -- make -f kprog/results/checked-probe-c-20261119/Makefile test OUT="$out" || rc=$?
fi
printf '%s\n' "$rc" > "$out/exit-code"
date -u +%FT%TZ > "$out/finished"
exit "$rc"
