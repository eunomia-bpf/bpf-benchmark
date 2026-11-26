#!/bin/bash
# Confirm the currently published image without rebuilding or changing settings.
set -euo pipefail
cd /workspaces/repository
out=$1
locks=/workspaces/.agent-state/kprog-lanes/locks
install -d "$out"
trap 'printf "%s\n" "$?" > "$out/controller-exit.txt"' EXIT
trap 'exit 143' TERM
trap 'exit 130' INT
trap 'exit 129' HUP
git rev-parse HEAD > "$out/check-source.txt"
(
flock -x 8
flock -s 9
docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current > "$out/check-image.txt"
prlimit --as=85899345920 -- \
    make -C kprog/perf/one-image check LOGS="$out/guest" > "$out/guest-check.log" 2>&1
) 8>"$locks/timing" 9>"$locks/image"
date -u +%FT%TZ > "$out/completed.txt"
