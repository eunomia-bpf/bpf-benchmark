#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/dead-helper-ids-20261117
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw/fixture" "$raw/lpm" "$raw/memory" "$raw/tmp"
    trap 'status=$?; printf "%s exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    printf '%s waiting timing SH/image EX raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -x 9
    ulimit -v 33554432
    export CARGO_BUILD_JOBS=1 TMPDIR="$raw/tmp" PYTHONDONTWRITEBYTECODE=1
    export NATIVE_LINK_PROBE_TEST_OUTPUT="$raw/fixture" NATIVE_LINK_LPM_TEST_OUTPUT="$raw/lpm"
    export NATIVE_LINK_MEMORY_TEST_OUTPUT="$raw/memory"
    export NATIVE_LINK_TASK_LAYOUT=/workspaces/kprog-raw/perf/uid-packed-load-20261117/retry-20261117T171823Z-2677411/target-layout.json
    python3 kprog/results/dead-helper-ids-20261117/apply.py test
    if taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        bound_helpers_drop_only_dead_adjacent_rax_ids_and_keep_proof_and_tail_state -- --nocapture > "$raw/before.txt" 2>&1;
        then baseline=0; else baseline=$?; fi
    printf '%s baseline rc=%s\n' "$(date -u +%FT%TZ)" "$baseline" >> "$root/progress.log"
    python3 kprog/results/dead-helper-ids-20261117/apply.py fix
    git diff -- kprog/x86/native_lab/native_link/src/x86.rs > "$raw/source.patch"
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/after.txt" 2>&1
    printf '%s full tests pass\n' "$(date -u +%FT%TZ)" >> "$root/progress.log"
    reference=/workspaces/kprog-raw/perf/inline-helper-labels-20261117/host-20261117T204206Z-2750151
    for group in fixture lpm memory; do
        for before in "$reference/$group"/*.bin "$reference/$group"/*.sites; do
            [ -f "$before" ] || continue
            name=${before##*/}
            cmp "$before" "$raw/$group/$name" >> "$raw/payload-comparison.txt" 2>&1
            printf 'identical %s/%s\n' "$group" "$name" >> "$raw/payload-comparison.txt"
        done
    done
    taskset -c 19 cargo build --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml > "$raw/build.txt" 2>&1
    taskset -c 19 python3 kprog/results/current-link-capture-20261117/replay.py --output "$raw/replay" > "$raw/replay-output.txt" 2>&1
    printf '%s host complete raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
}
main
