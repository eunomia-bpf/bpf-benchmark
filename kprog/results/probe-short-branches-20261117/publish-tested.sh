#!/bin/bash
# Publish the already successful host job after correcting an ignored receipt name.
set -euo pipefail
main() {
    cd /workspaces/repository
    raw=/workspaces/kprog-raw/perf/probe-short-branches-20261117/host-20261117T162945Z-2638683
    out=kprog/results/probe-short-branches-20261117
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
    flock -x 9
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git
    flock -x 7
    cp "$raw/load-comparison.log" "$out/load-comparison.txt"
    local paths=(kprog/x86/native_lab/native_link/src/x86_probe_read.rs kprog/docs/optimizations.md \
        "$out/host-output.txt" "$out/payload-comparison.txt" "$out/memory-comparison.txt" \
        "$out/sizes.txt" "$out/sizes-and-loads.json" "$out/load-comparison.txt" "$out/host-location.txt")
    git status --short --branch --untracked-files=no > "$raw/publication-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "size local probe branches with recovery offset remapping" -- "${paths[@]}" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
    printf '%s successful host source committed and pushed after receipt filename repair raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> /workspaces/kprog-raw/perf/probe-short-branches-20261117/progress.log
}
main
