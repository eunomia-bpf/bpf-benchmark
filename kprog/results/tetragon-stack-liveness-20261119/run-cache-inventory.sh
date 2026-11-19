#!/bin/bash
set -euo pipefail
cd /workspaces/repository
base=/workspaces/kprog-raw/perf/tetragon-cache-inventory-20261119
out=$base/inventory-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > "$base/latest"
exec > "$out/run.log" 2>&1
finish() { printf '%s\n' "$?" > "$out/exit-code"; date -u +%FT%TZ > "$out/finished"; }
trap finish EXIT
date -u +%FT%TZ > "$out/queued"
# Focused read-only CPU20 inventory: the broad host-work lock is relaxed
# for this diagnostic, as recorded in COORDINATION on 2026-11-19.
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
taskset -c 20 prlimit --as=4294967296 -- make -f kprog/results/tetragon-stack-liveness-20261119/Makefile cache-inventory OUT="$out"
