#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/zero-tail-inventory-20261117
    raw="$root/emitted-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw/tmp"
    trap 'status=$?; printf "%s emitted exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    printf '%s emitted waiting timing SH then image EX raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
    flock -x 9
    ulimit -v 33554432
    export PYTHONDONTWRITEBYTECODE=1 CARGO_BUILD_JOBS=1 TMPDIR="$raw/tmp"
    git rev-parse HEAD > "$raw/build-input.txt"
    taskset -c 19 cargo build --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        --bin native-link > "$raw/build.txt" 2>&1
    if taskset -c 19 python3 kprog/results/zero-tail-inventory-20261117/replay.py \
        --output "$raw" > "$raw/emitted-host-output.txt" 2>&1; then status=0; else status=$?; fi
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git
    flock -x 7
    out=kprog/results/zero-tail-inventory-20261117
    cp "$raw/emitted-inventory.json" "$raw/emitted-summary.txt" "$raw/emitted-host-output.txt" "$out/"
    cp "$raw/build.txt" "$raw/build-input.txt" "$out/"
    printf '%s raw=%s returncode=%s\n' "$(date -u +%FT%TZ)" "$raw" "$status" > "$out/emitted-host-location.txt"
    local paths=("$out/emitted-inventory.json" "$out/emitted-summary.txt" "$out/emitted-host-output.txt" \
        "$out/build.txt" "$out/build-input.txt" "$out/emitted-host-location.txt")
    git status --short --branch --untracked-files=no > "$raw/git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "inventory emitted zero tails across captured program requests" -- "${paths[@]}" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
    return "$status"
}
main
