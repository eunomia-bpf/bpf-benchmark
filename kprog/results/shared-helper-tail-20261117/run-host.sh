#!/bin/bash
# Start after the pending batch-2 image snapshot, from the sole checkout.
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/shared-helper-tail-20261117
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    reference=/workspaces/kprog-raw/perf/leaf-batch2-20261117/host-20261117T121810Z-2564495/fixture
    install -d "$raw/fixture" "$raw/tmp"
    trap 'status=$?; printf "%s host exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    printf '%s host waiting timing SH raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    ulimit -v 33554432
    export CARGO_BUILD_JOBS=1
    export NATIVE_LINK_PROBE_TEST_OUTPUT="$raw/fixture"
    export TMPDIR="$raw/tmp"
    python3 kprog/results/shared-helper-tail-20261117/edit.py --apply
    git diff -- kprog/x86/native_lab/native_link/src > "$raw/source.patch"
    taskset -c 19 cargo test --release \
        --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/cargo.log" 2>&1
    # Successful pre-existing E8 leaf bodies and recovered-load metadata stay
    # identical. This is an experiment comparison, not a benchmark gate.
    for before in "$reference"/*.bin "$reference"/*.sites; do
        name=${before##*/}
        cmp "$before" "$raw/fixture/$name" >> "$raw/payload-comparison.log" 2>&1
        printf 'identical %s\n' "$name" >> "$raw/payload-comparison.log"
    done
}
main
