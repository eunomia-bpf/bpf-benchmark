#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=$1
exec > "$out/worker.log" 2>&1
finish() { printf '%s\n' "$?" > "$out/exit-code"; date -u +%FT%TZ > "$out/finished"; }
trap finish EXIT
date -u +%FT%TZ > "$out/started"
exec 9>/workspaces/.agent-state/kprog-lanes/locks/build-c
flock -x 9
taskset -c 20-23 nice -n 19 prlimit --as=8589934592 -- \
    make -f kprog/results/lpm-c-lto-20261120/Makefile compiler
taskset -c 20-23 nice -n 19 prlimit --as=8589934592 -- \
    make -f kprog/results/lpm-c-lto-20261120/Makefile check compatibility syntax RAW="$out"
