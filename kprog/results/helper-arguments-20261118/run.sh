#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    local raw=/workspaces/kprog-raw/perf/helper-arguments-20261118/host-$(date -u +%Y%m%dT%H%M%SZ)-$$
    install -d "$raw"
    printf '%s\n' "$raw"
    exec >"$raw/log" 2>&1
    local status=0
    date -u +%FT%TZ >"$raw/started"
    flock -s /workspaces/.agent-state/kprog-lanes/locks/timing \
        flock -s /workspaces/.agent-state/kprog-lanes/locks/image \
        taskset -c 19 prlimit --as=4294967296 -- \
        make -f kprog/results/helper-arguments-20261118/Makefile run OUT="$raw" || status=$?
    printf '%s\n' "$status" >"$raw/exit-code"
    date -u +%FT%TZ >"$raw/finished"
    exit "$status"
}
main "$@"
