#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    raw=/workspaces/kprog-raw/perf/tail-short-encodings-20261117/layout-delta
    install -d "$raw"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    ulimit -v 33554432
    export PYTHONDONTWRITEBYTECODE=1
    date -u +%FT%TZ > "$raw/time.txt"
    taskset -c 19 python3 kprog/results/tail-short-encodings-20261117/layout-delta.py "$raw" > "$raw/host-output.txt" 2>&1
}
main
