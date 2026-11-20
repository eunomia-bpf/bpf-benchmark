#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=$1
install -d "$out" "$out/compatibility" "$out/lpm"
date -u +%FT%TZ > "$out/started"
finish() { printf '%s\n' "$?" > "$out/exit-code"; date -u +%FT%TZ > "$out/finished"; }
trap finish EXIT
make -f kprog/results/hash-c-lto-20261120/Makefile generation stock native OUT="$out"
make -f kprog/results/lpm-c-lto-20261120/Makefile compatibility RAW="$out/compatibility"
make -f kprog/results/lpm-c-lto-20261120/Makefile post-b RAW="$out/lpm" \
    STOCK=/workspaces/kprog-raw/perf/lpm-c-lto-20261120/stock-20261120T022137Z
