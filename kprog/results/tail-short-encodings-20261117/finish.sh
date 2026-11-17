#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/tail-short-encodings-20261117
    trap 'status=$?; printf "%s publication exit=%s\n" "$(date -u +%FT%TZ)" "$status" >> "$root/publication-progress.txt"' EXIT
    tail --pid="$1" -f /dev/null
    raw=$(cat "$root/current-raw.txt")
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git; flock -x 7
    ulimit -v 33554432
    export PYTHONDONTWRITEBYTECODE=1
    STAMP="$(date -u +%FT%TZ)" taskset -c 19 python3 kprog/results/tail-short-encodings-20261117/finish.py "$raw" > "$root/comparison-output.txt" 2>&1
    out=kprog/results/tail-short-encodings-20261117
    for name in test-build.txt test-executable.txt unit-source-commit.txt unit-source.patch main-before.txt main-after.txt replay-output.txt; do cp "$raw/$name" "$out/$name"; done
    cp "$raw/replay/replay.json" "$out/replay.json"
    cp "$raw/replay/replay-summary.txt" "$out/replay-summary.txt"
    paths=("$out" kprog/docs/optimizations.md)
    git status --short --branch --untracked-files=no > "$root/publication-git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "record actual tail-transition encoding results" -- "${paths[@]}" > "$root/publication-commit.txt" 2>&1
    git push origin master > "$root/publication-push.txt" 2>&1
    printf '%s publication complete\n' "$(date -u +%FT%TZ)" >> "$root/publication-progress.txt"
}
main "$@"
