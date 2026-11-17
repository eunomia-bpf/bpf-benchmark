#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/zero-tail-inventory-20261117
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw"
    trap 'status=$?; printf "%s exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    ulimit -v 33554432
    export PYTHONDONTWRITEBYTECODE=1
    taskset -c 19 python3 kprog/results/zero-tail-inventory-20261117/inventory.py \
        --output "$raw" > "$raw/output.txt" 2>&1
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git
    flock -x 7
    out=kprog/results/zero-tail-inventory-20261117
    cp "$raw/inventory.json" "$raw/summary.txt" "$out/"
    cp "$raw/output.txt" "$out/host-output.txt"
    printf '%s raw=%s\n' "$(date -u +%FT%TZ)" "$raw" > "$out/host-location.txt"
    local paths=("$out/inventory.json" "$out/summary.txt" "$out/host-output.txt" "$out/host-location.txt")
    git status --short --branch --untracked-files=no > "$raw/git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "record retained helper combinations and zero-tail size bounds" -- "${paths[@]}" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
}
main
