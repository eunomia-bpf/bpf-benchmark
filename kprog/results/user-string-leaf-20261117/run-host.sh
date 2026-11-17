#!/bin/bash
# Exercise emitted user/compat strings and all existing probe-read cases.
set -euo pipefail
cd /workspaces/repository
root=/workspaces/kprog-raw/perf/user-string-leaf-20261117
raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
install -d "$raw"
printf '%s waiting for timing SH raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
ulimit -v 33554432
export CARGO_BUILD_JOBS=1
export NATIVE_LINK_PROBE_TEST_OUTPUT="$raw/fixture"
printf '%s start at %s raw=%s\n' "$(date -u +%FT%TZ)" "$(git rev-parse --short HEAD)" "$raw" >> "$root/progress.log"
status=0
taskset -c 19 cargo test --release \
    --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
    x86::probe_read::tests -- --nocapture > "$raw/host.log" 2>&1 || status=$?
printf '%s exit=%s raw=%s\n' "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"
exit "$status"
