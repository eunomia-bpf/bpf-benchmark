#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/context-and-globals-20261118
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw"
    printf '%s\n' "$raw" > "$root/current-raw.txt"
    trap 'status=$?; printf "%s exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.txt"' EXIT
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    ulimit -v 4194304
    taskset -c 19 python3 kprog/results/context-and-globals-20261118/inventory.py \
        --replay /workspaces/kprog-raw/perf/named-lpm-20261118/host-20261118T001244Z-2827763/replay/replay.json \
        --output "$raw" > "$raw/output.txt" 2>&1
}
main
