#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/constant-probe-size-20261117
    raw="$root/copy-preview-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw"
    trap 'status=$?; printf "%s copy preview exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
    flock -s 9
    ulimit -v 2097152
    python3 kprog/results/constant-probe-size-20261117/edit-copy.py > "$raw/proposed.patch" 2> "$raw/stderr.txt"
}
main
