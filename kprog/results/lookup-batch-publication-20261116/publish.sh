#!/bin/bash
# Parse the complete function before starting the long build.
publish_batch() {
    set -euo pipefail
    local root=/workspaces/repository
    local raw=$2
    local locks=/workspaces/.agent-state/kprog-lanes/locks
    local wait_pid=$1 old_image new_image candidate
    trap 'rc=$?; printf "%s\n" "$rc" > "$kprog_publication_raw/exit-code"; date -u +%FT%TZ > "$kprog_publication_raw/controller.finished"' EXIT
    cd "$root"
    date -u +%FT%TZ > "$raw/started"
    printf '%s\n' "$wait_pid" > "$raw/waited-guest.pid"
    while [ -d "/proc/$wait_pid" ]; do sleep 5; done
    exec 8>"$locks/timing"
    flock -s 8
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
    docker image ls --all --no-trunc --format '{{.ID}}' > "$raw/image-inventory.txt"
    while IFS= read -r candidate; do
        if [ "$candidate" = "$old_image" ] && [ "$old_image" != "$new_image" ]; then
            docker image rm --no-prune "$old_image" > "$raw/image-cleanup.log" 2>&1
            printf '\n- %s PERF publication: removed superseded image %s after replacement by %s; one base rebuilt in place and all raw kept. Receipt %s.\n' \
                "$(date -u +%FT%TZ)" "$old_image" "$new_image" "$raw/image-cleanup.log" >> kprog/docs/cleanup-log.md
        fi
    done < "$raw/image-inventory.txt"
    cat /workspaces/.agent-state/kprog-ck/build-x86/include/config/kernel.release > "$raw/kernel.release"
    date -u +%FT%TZ > "$raw/image.finished"
    flock -u 9
    flock -u 8
    make -f kprog/results/lookup-batch-publication-20261116/Makefile check RAW="$raw"
    date -u +%FT%TZ > "$raw/finished"
}
kprog_publication_raw=$2
publish_batch "$@"
