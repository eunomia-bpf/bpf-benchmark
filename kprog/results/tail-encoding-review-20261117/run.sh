#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    raw=/workspaces/kprog-raw/perf/tail-encoding-review-20261117
    install -d "$raw"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    ulimit -v 33554432
    export PYTHONDONTWRITEBYTECODE=1
    date -u +%FT%TZ > "$raw/time.txt"
    git rev-parse HEAD > "$raw/source-commit.txt"
    taskset -c 19 python3 kprog/results/tail-encoding-review-20261117/inspect.py "$raw" > "$raw/host-output.txt" 2>&1
}
main
