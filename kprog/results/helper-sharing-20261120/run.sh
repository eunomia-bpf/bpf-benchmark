#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=$1
install -d "$out/lpm" "$out/hash" "$out/compatibility"
date -u +%FT%TZ > "$out/started"
finish() { printf '%s\n' "$?" > "$out/exit-code"; date -u +%FT%TZ > "$out/finished"; }
trap finish EXIT
make -f kprog/results/lpm-c-lto-20261120/Makefile post-b RAW="$out/lpm" \
    STOCK=/workspaces/kprog-raw/perf/lpm-c-lto-20261120/stock-20261120T022137Z
cp /workspaces/kprog-raw/perf/hash-c-lto-20261120/production-20261120T041613Z/stock-result.json "$out/hash/stock-result.json"
make -f kprog/results/hash-c-lto-20261120/Makefile native OUT="$out/hash"
make -f kprog/results/lpm-c-lto-20261120/Makefile compatibility RAW="$out/compatibility"
make -f kprog/results/helper-sharing-20261120/Makefile replay OUT="$out"
