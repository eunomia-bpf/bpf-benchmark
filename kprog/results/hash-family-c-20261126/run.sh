#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=$PWD/kprog/results/hash-family-c-20261126
locks=/workspaces/.agent-state/kprog-lanes/locks
git rev-parse HEAD > "$out/image-source.txt"
old_image=$(docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current)
printf '%s\n' "$old_image" > "$out/image-before.txt"
flock -s "$locks/timing" flock -x "$locks/image" \
    taskset -c 18-19 prlimit --as=17179869184 -- \
    make -C kprog/perf/one-image image JOBS=2 > "$out/image.log" 2>&1
docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current > "$out/image-after.txt"
if [ "$old_image" != "$(cat "$out/image-after.txt")" ]; then
    docker image rm "$old_image" > "$out/image-cleanup.log" 2>&1
    printf '\n- %s PERF P3: removed superseded x86 runtime image %s after replacement by %s; raw logs retained in kprog/results/hash-family-c-20261126.\n' \
        "$(date -u +%FT%TZ)" "$old_image" "$(cat "$out/image-after.txt")" >> kprog/docs/cleanup-log.md
fi
flock -x "$locks/timing" flock -s "$locks/image" \
    make -C kprog/perf/one-image check LOGS="$out/guest" > "$out/guest-check.log" 2>&1
date -u +%FT%TZ > "$out/completed.txt"
