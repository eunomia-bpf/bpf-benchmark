#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=$1
exec > "$out/build.log" 2>&1
finish() { printf '%s\n' "$?" > "$out/build-exit-code"; date -u +%FT%TZ > "$out/build-finished"; }
trap finish EXIT
date -u +%FT%TZ > "$out/build-started"
taskset -c 20-23 nice -n 19 prlimit --as=8589934592 -- \
    make -f kprog/results/runtime-profile-20261120/Makefile perf
