#!/bin/bash
# The coordinator's one A/A plus one A/B, through the unchanged timing entry.
set -euo pipefail
root=/workspaces/repository
output=$1
install -d "$output"
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -x 8
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
flock -s 9
date -u +%FT%TZ > "$output/timing-started"
status=0
for tag in aa ab; do
    mode=0
    if [[ $tag == ab ]]; then mode=post; fi
    install -d "$output/$tag"
    command=(make -r -f "$root/kprog/perf/one-image/Makefile" corpus
        APPS=katran SAMPLES=3 WORKLOAD_DURATION=180 BPFREJIT_CORPUS_BPF_STATS=1
        SKIP_REJIT_MODE=norejit NATIVE_LOADER_MODE="$mode" CPUS=0-7 VM_CPUS=8 VM_MEM=64G
        STATE=/var/tmp/kprog-tmp/perf/katran-fixed-frequency LOGS="$output/$tag"
        "VNG_FLAGS=--rwdir $output")
    printf '%q ' "${command[@]}" > "$output/$tag/command.txt"
    date -u +%FT%TZ > "$output/$tag/started"
    current=0
    PATH="$root/kprog/perf/one-image/observe-bin:$PATH" KPROG_TIMING_CAPTURE_DIR="$output/$tag" \
        "${command[@]}" > "$output/$tag/make.log" 2>&1 || current=$?
    printf '%s\n' "$current" > "$output/$tag/exit-code"
    date -u +%FT%TZ > "$output/$tag/finished"
    if [[ $current != 0 ]]; then status=$current; fi
done
date -u +%FT%TZ > "$output/timing-finished"
exit "$status"
