#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/current-link-capture-20261117
    raw="$root/replay-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw/tmp"
    trap 'status=$?; printf "%s replay exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    printf '%s replay waiting batch EX then timing SH/image EX raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch
    flock -x 7
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
    flock -x 9
    ulimit -v 33554432
    export CARGO_BUILD_JOBS=1 PYTHONDONTWRITEBYTECODE=1 TMPDIR="$raw/tmp"
    git rev-parse HEAD > "$raw/replay-build-input.txt"
    taskset -c 19 cargo build --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        --bin native-link > "$raw/replay-build.txt" 2>&1
    if taskset -c 19 python3 kprog/results/current-link-capture-20261117/replay.py \
        --output "$raw" > "$raw/replay-output.txt" 2>&1; then rc=0; else rc=$?; fi
    exec 6>/workspaces/.agent-state/kprog-lanes/locks/git
    flock -x 6
    out=kprog/results/current-link-capture-20261117
    cp "$raw/replay.json" "$raw/replay-summary.txt" "$raw/replay-build-input.txt" "$raw/replay-build.txt" "$raw/replay-output.txt" "$out/"
    printf '%s raw=%s returncode=%s\n' "$(date -u +%FT%TZ)" "$raw" "$rc" > "$out/replay-location.txt"
    local paths=("$out/replay.json" "$out/replay-summary.txt" "$out/replay-build-input.txt" \
        "$out/replay-build.txt" "$out/replay-output.txt" "$out/replay-location.txt")
    git status --short --branch --untracked-files=no > "$raw/git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "record current-linker replay of fresh paired app inputs" -- "${paths[@]}" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
    return "$rc"
}
main
