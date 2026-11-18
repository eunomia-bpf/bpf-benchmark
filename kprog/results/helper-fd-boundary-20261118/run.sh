#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/helper-fd-boundary-20261118
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw"
    printf '%s\n' "$raw" > "$root/current-raw.txt"
    trap 'status=$?; printf "%s exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.txt"' EXIT
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    ulimit -v 4194304
    taskset -c 19 python3 kprog/results/helper-fd-boundary-20261118/prepare.py \
        --output "$raw" \
        --service-log /workspaces/kprog-raw/verified/20261117-checked-hot/tracee/state/session-l8nw5lav/service.log \
        > "$raw/output.txt" 2>&1
}
main
