#!/bin/bash
set -euo pipefail
cd /workspaces/repository
raw=$1
mode=$2
install -d "$raw"
date -u +%FT%TZ > "$raw/started"
status=0
if [ "$mode" = host ]; then
    taskset -c 20-23 prlimit --as=8589934592 -- \
        make -f kprog/results/lpm-c-lto-20261120/Makefile post-b RAW="$raw" \
        STOCK=/workspaces/kprog-raw/perf/lpm-c-lto-20261120/stock-20261120T022137Z || status=$?
elif [ "$mode" = app ]; then
    make -C kprog/libnativeloader checked-corpus CHECKED_OUTPUT="$raw" \
        CHECKED_HOST_CPUS=20-23 CHECKED_VM_CPUS=4 CHECKED_VM_MEMORY=32G \
        CHECKED_VM_ADDRESS_SPACE=51539607552 || status=$?
else
    echo "unknown check: $mode" >&2
    status=2
fi
printf '%s\n' "$status" > "$raw/exit-code"
date -u +%FT%TZ > "$raw/finished"
exit "$status"
