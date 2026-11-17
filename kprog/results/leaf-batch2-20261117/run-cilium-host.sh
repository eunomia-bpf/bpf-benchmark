#!/bin/bash
# Compile the changed producer configuration in the one canonical object set.
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/leaf-batch2-20261117
    raw="$root/cilium-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw/tmp"
    trap 'status=$?; printf "%s Cilium host exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    printf '%s Cilium host waiting for timing SH raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
    flock -x 9
    ulimit -v 33554432
    export TMPDIR="$raw/tmp"
    printf '%s Cilium host start raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    taskset -c 19 make -C vendor/bpf native-cilium -j1 > "$raw/make.log" 2>&1
    printf '%s Cilium host complete raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
}
main
