#!/usr/bin/env bash
# Publish the requested reference linker after the existing breadth round,
# measure through the frozen entry, then rebuild the sole current linker.
set -euo pipefail
comparison_root=/workspaces/repository
comparison_output=/workspaces/kprog-raw/perf/20261116-reference-linker-timing
comparison_reference=/workspaces/kprog-raw/paper-tree-untracked/native-sim/x86/native_lab/native_link/target/release/native-link
comparison_locks=/workspaces/.agent-state/kprog-lanes/locks

publish_linker() {
    flock -x "$comparison_locks/image" taskset -c 8-11 prlimit --as=34359738368 -- \
        make -C "$comparison_root/kprog/libnativeloader" shared-base-refresh \
        REFRESH_OPERATION="$1" REFRESH_LINKER_INPUT="$comparison_reference" \
        REFRESH_OUTPUT="$comparison_output/$2"
}

measure_reference() {
    flock -x "$comparison_locks/timing" flock -s "$comparison_locks/image" \
        make -f "$comparison_root/kprog/perf/one-image/Makefile" corpus \
        APPS=katran BPFREJIT_CORPUS_BPF_STATS="$1"
}

if [[ ${1:-} == --dry-run ]]; then
    declare -f publish_linker measure_reference
    printf '%s\n' 'Wait for locks/timing, then release it before image publication.' \
        'publish_linker --linker-input reference-image' \
        'measure_reference 0' 'measure_reference 1' \
        'publish_linker --linker-rebuild current-image'
    exit 0
fi

install -d "$comparison_output"
date -u +%FT%TZ > "$comparison_output/waiting"
# The rotate job holds timing for its whole round. Releasing this wait before
# publication keeps image builds outside the timing resource's critical section.
flock -x "$comparison_locks/timing" true
printf -- '- LANE PERF %s: The queued Katran reference comparison acquired timing after the breadth round. Publishing the preserved reference linker under image EX, then running corpus Katran with its unchanged defaults at stats 0 and 1. Current source will rebuild into the sole image afterward. Raw: %s.\n' \
    "$(date -u +%FT%TZ)" "$comparison_output" >> /workspaces/.agent-state/kprog-lanes/COORDINATION.md

# Successful and failed timed Make invocations both rebuild current source.
rebuild_current() {
    comparison_status=$?
    trap - EXIT
    if publish_linker --linker-rebuild current-image > "$comparison_output/current-image.log" 2>&1; then
        date -u +%FT%TZ > "$comparison_output/current-rebuilt"
    else
        comparison_status=1
    fi
    printf '%s\n' "$comparison_status" > "$comparison_output/exit-code"
    date -u +%FT%TZ > "$comparison_output/finished"
    exit "$comparison_status"
}
trap rebuild_current EXIT
publish_linker --linker-input reference-image > "$comparison_output/reference-image.log" 2>&1
comparison_failed=0
for comparison_stats in 0 1; do
    if measure_reference "$comparison_stats" > "$comparison_output/stats-$comparison_stats.log" 2>&1; then
        comparison_rc=0
    else
        comparison_rc=$?
        comparison_failed=1
    fi
    printf '%s\t%s\n' "$comparison_stats" "$comparison_rc" >> "$comparison_output/run-codes.tsv"
done
exit "$comparison_failed"
