#!/bin/bash
# Read the new compile commands without rebuilding P or changing the image.
set -euo pipefail
cd /workspaces/repository
root=/workspaces/kprog-raw/perf/leaf-batch2-20261117
raw="$root/producer-plan-$(date -u +%Y%m%dT%H%M%SZ)-$$"
install -d "$raw"
printf '%s producer plan waiting for timing SH raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
ulimit -v 2097152
printf '%s producer plan start raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
status=0
taskset -c 19 make -C vendor/bpf -n native-cilium > "$raw/make.log" 2>&1 || status=$?
printf '%s producer plan exit=%s raw=%s\n' "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"
exit "$status"
