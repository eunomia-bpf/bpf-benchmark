#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/map-dispatch-review-20261117
    raw="$root/preflight-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw"
    trap 'status=$?; printf "%s exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/preflight-progress.txt"' EXIT
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    ulimit -v 33554432
    export PYTHONDONTWRITEBYTECODE=1
    git rev-parse HEAD > "$raw/source-commit.txt"
    taskset -c 19 python3 kprog/results/map-dispatch-review-20261117/preflight.py "$raw" > "$raw/host-output.txt" 2>&1
}
main
