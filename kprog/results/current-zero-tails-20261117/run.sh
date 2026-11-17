#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/current-zero-tails-20261117
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw"
    printf '%s\n' "$raw" > "$root/current-raw.txt"
    trap 'status=$?; printf "%s exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.txt"' EXIT
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    ulimit -v 4194304
    taskset -c 19 python3 kprog/results/current-zero-tails-20261117/inventory.py \
        --replay /workspaces/kprog-raw/perf/map-provenance-cfg-20261117/host-20261117T232351Z-2807862/replay/replay.json \
        --output "$raw" > "$raw/output.txt" 2>&1
}
main
