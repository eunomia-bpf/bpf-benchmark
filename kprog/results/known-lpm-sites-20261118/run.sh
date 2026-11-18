#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/known-lpm-sites-20261118
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw"
    printf '%s\n' "$raw" > "$root/current-raw.txt"
    trap 'status=$?; printf "%s exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.txt"' EXIT
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    ulimit -v 4194304
    taskset -c 19 python3 kprog/results/known-lpm-sites-20261118/inventory.py \
        --replay /workspaces/kprog-raw/perf/shared-zero-tails-20261117/host-20261117T234518Z-2818089/replay/replay.json \
        --system-map /workspaces/.agent-state/kprog-ck/build-x86/System.map \
        --output "$raw" > "$raw/output.txt" 2>&1
}
main
