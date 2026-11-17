#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    local root=/workspaces/kprog-raw/perf/ir-barrier-inventory-20261117
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw"
    trap 'status=$?; printf "%s exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> /workspaces/kprog-raw/perf/ir-barrier-inventory-20261117/progress.log' EXIT
    printf '%s waiting timing SH then image SH raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9
    ulimit -v 33554432
    export PYTHONDONTWRITEBYTECODE=1
    git rev-parse HEAD > "$raw/source-commit.txt"
    taskset -c 19 python3 kprog/results/ir-barrier-inventory-20261117/inspect.py "$raw" > "$raw/host-output.txt" 2>&1
    printf '%s completed raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
}
main
