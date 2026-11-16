#!/bin/bash
# Parsed before execution; never edit this file while the controller runs.
run_profiles() {
    set -u
    local root=/workspaces/repository
    local raw=/workspaces/kprog-raw/perf/20261116-shared-hash-regression
    local case_name app mode rc
    cd "$root" || return 2
    for case_name in katran-shared katran-copy otel-shared otel-copy; do
        app=katran
        [[ $case_name == otel-* ]] && app=otelcol-ebpf-profiler/profiling
        mode=${case_name##*-}
        date -u +%FT%TZ > "$raw/$case_name.started"
        make -f kprog/results/shared-hash-regression-20261116/Makefile profile \
            "CASE=$case_name" "APP=$app" "MODE=$mode" > "$raw/$case_name.controller.log" 2>&1
        rc=$?
        printf '%s\n' "$rc" > "$raw/$case_name.exit-code"
        date -u +%FT%TZ > "$raw/$case_name.finished"
    done
}
run_profiles
