#!/bin/bash
# Parse the complete function before starting the long build.
publish_batch() {
    set -euo pipefail
    local root=/workspaces/repository
    local raw=/workspaces/kprog-raw/perf/20261116-lookup-batch-publication
    local locks=/workspaces/.agent-state/kprog-lanes/locks
    local wait_pid=$1 old_image new_image stamp
    trap 'rc=$?; printf "%s\n" "$rc" > /workspaces/kprog-raw/perf/20261116-lookup-batch-publication/exit-code; date -u +%FT%TZ > /workspaces/kprog-raw/perf/20261116-lookup-batch-publication/controller.finished' EXIT
    cd "$root"
    date -u +%FT%TZ > "$raw/started"
    printf '%s\n' "$wait_pid" > "$raw/waited-guest.pid"
    while [ -d "/proc/$wait_pid" ]; do sleep 5; done
    exec 9>"$locks/image"
    flock -x 9
    date -u +%FT%TZ > "$raw/image.started"
    git rev-parse HEAD > "$raw/source.commit"
    git -C vendor/linux-framework rev-parse HEAD > "$raw/kernel-source.commit"
    git status --short --untracked-files=no > "$raw/source-status.txt"
    old_image=$(docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current)
    printf '%s\n' "$old_image" > "$raw/old-image.id"
    make -f kprog/perf/one-image/Makefile image JOBS=8 > "$raw/image.log" 2>&1
    new_image=$(docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current)
    printf '%s\n' "$new_image" > "$raw/image.id"
    cat /workspaces/.agent-state/kprog-ck/build-x86/include/config/kernel.release > "$raw/kernel.release"
    if [ "$old_image" != "$new_image" ]; then
        docker image rm --no-prune "$old_image" > "$raw/image-cleanup.log" 2>&1
        stamp=$(date -u +%FT%TZ)
        printf '\n- %s PERF publication: replaced the one current image %s with %s and removed only the old image object; the base was rebuilt in place and all raw runs stay. Receipt %s.\n' \
            "$stamp" "$old_image" "$new_image" "$raw/image-cleanup.log" >> kprog/docs/cleanup-log.md
    fi
    date -u +%FT%TZ > "$raw/image.finished"
    flock -u 9
    date -u +%FT%TZ > "$raw/check.started"
    flock -s "$locks/image" flock -x "$locks/timing" \
        make -f kprog/perf/one-image/Makefile check LOGS="$raw/check" > "$raw/check.controller.log" 2>&1
    date -u +%FT%TZ > "$raw/check.finished"
    make -f kprog/results/lookup-batch-publication-20261116/Makefile summarize > "$raw/summary.log" 2>&1
    date -u +%FT%TZ > "$raw/finished"
}
publish_batch "$@"
