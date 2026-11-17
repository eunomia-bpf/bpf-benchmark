#!/bin/bash
# Focused regression: BTF current-task must execute the same full-width GS
# load as current-task. Use the sole linker build and wait for timing gaps.
set -euo pipefail
cd /workspaces/repository
raw=/workspaces/kprog-raw/perf/task-btf-inline-20261117
install -d "$raw"
printf '%s waiting for timing SH\n' "$(date -u +%FT%TZ)" >> "$raw/progress.log"
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
ulimit -v 33554432
export CARGO_BUILD_JOBS=1
export NATIVE_LINK_PROBE_TEST_OUTPUT="$raw/fixture"
printf '%s test start at %s\n' "$(date -u +%FT%TZ)" "$(git rev-parse --short HEAD)" >> "$raw/progress.log"
status=0
taskset -c 19 cargo test --release \
    --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
    emitted_probe_reads_execute_success_fault_partial_zero_policy_and_nesting \
    -- --nocapture > "$raw/host.log" 2>&1 || status=$?
printf '%s test exit %s\n' "$(date -u +%FT%TZ)" "$status" >> "$raw/progress.log"
exit "$status"
