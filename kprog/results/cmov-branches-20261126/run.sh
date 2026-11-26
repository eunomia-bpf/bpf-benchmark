#!/bin/bash
# Build and link the common flag candidate in place, then use the frozen image/check entry.
set -euo pipefail
cd /workspaces/repository
out=$1
install -d "$out"
trap 'printf "%s\n" "$?" > "$out/controller-exit.txt"' EXIT
trap 'exit 143' TERM
trap 'exit 130' INT
trap 'exit 129' HUP
git rev-parse HEAD > "$out/producer-source.txt"
locks=/workspaces/.agent-state/kprog-lanes/locks
(
flock -s 8
flock -x 9
taskset -c 18-19 prlimit --as=17179869184 -- \
    make -C kprog/results/cmov-branches-20261126 produce RESULT="$out" > "$out/producer.log" 2>&1
taskset -c 18-19 prlimit --as=8589934592 -- \
    make -C kprog/results/cmov-branches-20261126 offline RESULT="$out" > "$out/offline.log" 2>&1
) 8>"$locks/timing" 9>"$locks/image"
bash kprog/results/hash-family-c-20261126/run.sh "$out"
