#!/bin/bash
# Source/anchor preview only; leave pending image inputs intact.
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/shared-helper-tail-20261117
    raw="$root/preview-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw"
    trap 'status=$?; printf "%s preview exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    printf '%s preview waiting timing SH raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    ulimit -v 2097152
    taskset -c 19 python3 kprog/results/shared-helper-tail-20261117/edit.py > "$raw/proposed.patch" 2> "$raw/stderr.txt"
}
main
