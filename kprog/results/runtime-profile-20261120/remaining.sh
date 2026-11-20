#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=$1 first=$2
exec > "$out/batch.log" 2>&1
while [ ! -f "$first/exit-code" ]; do
    kill -0 "$(cat "$first/pid")"
    sleep 2
done
for app in bcc/set katran cilium/agent; do
    directory=$out/${app%%/*}
    install -d "$directory"
    date -u +%FT%TZ > "$directory/started"
    make -n -f kprog/results/runtime-profile-20261120/Makefile capture OUT="$directory" APP="$app" > "$directory/dry-run.log"
    if make -f kprog/results/runtime-profile-20261120/Makefile capture OUT="$directory" APP="$app" > "$directory/make.log" 2>&1; then
        rc=0
    else
        rc=$?
    fi
    printf '%s\n' "$rc" > "$directory/make-exit-code"
    date -u +%FT%TZ > "$directory/finished"
done
date -u +%FT%TZ > "$out/finished"
