#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    local root=/workspaces/kprog-raw/perf/lpm-body-20261118
    local raw=$root/candidate-$(date -u +%Y%m%dT%H%M%SZ)-$$
    install -d "$raw/fixture" "$raw/lpm" "$raw/memory" "$raw/tmp"
    printf '%s\n' "$raw"
    exec >"$raw/log" 2>&1
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9
    ulimit -v 33554432
    export CARGO_BUILD_JOBS=1 TMPDIR="$raw/tmp" PYTHONDONTWRITEBYTECODE=1
    export NATIVE_LINK_PROBE_TEST_OUTPUT="$raw/fixture" NATIVE_LINK_LPM_TEST_OUTPUT="$raw/lpm"
    export NATIVE_LINK_MEMORY_TEST_OUTPUT="$raw/memory"
    export NATIVE_LINK_TASK_LAYOUT=/workspaces/kprog-raw/perf/uid-packed-load-20261117/retry-20261117T171823Z-2677411/target-layout.json
    date -u +%FT%TZ >"$raw/started"
    stat -c '%s %Y' kprog/x86/native_lab/native_link/target/release/native-link >"$raw/main-before.txt"
    git diff -- kprog/x86/native_lab/native_link/src/x86_lpm_lookup.rs >"$raw/source.patch"
    local status=0
    taskset -c 19 make -f kprog/results/lpm-body-20261118/candidate.mk run OUT="$raw" || status=$?
    stat -c '%s %Y' kprog/x86/native_lab/native_link/target/release/native-link >"$raw/main-after.txt"
    cmp "$raw/main-before.txt" "$raw/main-after.txt" || status=$?
    printf '%s\n' "$status" >"$raw/exit-code"
    date -u +%FT%TZ >"$raw/finished"
    exit "$status"
}
main "$@"
