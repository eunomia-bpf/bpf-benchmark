#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=${1:-$PWD/kprog/results/hash-family-c-20261126}
install -d "$out"
trap 'printf "%s\n" "$?" > "$out/controller-exit.txt"' EXIT
trap 'exit 143' TERM
trap 'exit 130' INT
trap 'exit 129' HUP
locks=/workspaces/.agent-state/kprog-lanes/locks
git rev-parse HEAD > "$out/image-source.txt"
(
flock -s 8
flock -x 9
old_image=$(docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current)
printf '%s\n' "$old_image" > "$out/image-before.txt"
taskset -c 18-19 prlimit --as=17179869184 -- \
    make -C kprog/perf/one-image image JOBS=2 > "$out/image.log" 2>&1
docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current > "$out/image-after.txt"
if [ "$old_image" != "$(cat "$out/image-after.txt")" ]; then
    images=$(docker image ls --no-trunc --quiet)
    case $'\n'"$images"$'\n' in
        *$'\n'"$old_image"$'\n'*) docker image rm "$old_image" > "$out/image-cleanup.log" 2>&1 ;;
        *) printf 'Previous image already absent: %s\n' "$old_image" > "$out/image-cleanup.log" ;;
    esac
    printf '\n- %s PERF P3: superseded x86 runtime image %s is absent after replacement by %s; raw cleanup outcome retained in kprog/results/hash-family-c-20261126.\n' \
        "$(date -u +%FT%TZ)" "$old_image" "$(cat "$out/image-after.txt")" >> kprog/docs/cleanup-log.md
fi
) 8>"$locks/timing" 9>"$locks/image"
bash kprog/results/hash-family-c-20261126/check.sh "$out"
