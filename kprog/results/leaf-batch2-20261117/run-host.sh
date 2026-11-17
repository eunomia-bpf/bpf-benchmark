#!/bin/bash
# Apply scripts are run separately after the clock image snapshot. Check
# the resulting sources using their canonical builds, outside timing runs.
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/leaf-batch2-20261117
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw/fixture" "$raw/tmp"
    trap 'status=$?; printf "%s host exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    printf '%s waiting for timing SH raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    ulimit -v 33554432
    export CARGO_BUILD_JOBS=1
    export NATIVE_LINK_PROBE_TEST_OUTPUT="$raw/fixture"
    export TMPDIR="$raw/tmp"
    printf '%s cargo start at %s raw=%s\n' "$(date -u +%FT%TZ)" "$(git rev-parse --short HEAD)" "$raw" >> "$root/progress.log"
    taskset -c 19 cargo test --release \
        --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/cargo.log" 2>&1
    printf '%s loader start raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    taskset -c 19 cmake --build runner/build-llvmbpf \
        --target native_loader_shared -j1 > "$raw/loader.log" 2>&1
    printf '%s host complete raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
}
main
