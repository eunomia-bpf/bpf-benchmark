#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/tail-short-encodings-20261117
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw/fixture" "$raw/lpm" "$raw/memory" "$raw/tmp"
    printf '%s\n' "$raw" > "$root/current-raw.txt"
    trap 'status=$?; printf "%s exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.txt"' EXIT
    printf '%s waiting prior replay and publisher raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.txt"
    tail --pid=2776222 -f /dev/null
    tail --pid=2776223 -f /dev/null
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -x 9
    ulimit -v 33554432
    export CARGO_BUILD_JOBS=1 TMPDIR="$raw/tmp" PYTHONDONTWRITEBYTECODE=1
    export NATIVE_LINK_PROBE_TEST_OUTPUT="$raw/fixture" NATIVE_LINK_LPM_TEST_OUTPUT="$raw/lpm"
    export NATIVE_LINK_MEMORY_TEST_OUTPUT="$raw/memory"
    export NATIVE_LINK_TASK_LAYOUT=/workspaces/kprog-raw/perf/uid-packed-load-20261117/retry-20261117T171823Z-2677411/target-layout.json
    printf '%s source/test stage raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.txt"
    python3 kprog/results/tail-short-encodings-20261117/apply.py test
    if taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        tail_count_patch_preserves_target_entry -- --nocapture > "$raw/before.txt" 2>&1;
        then baseline=0; else baseline=$?; fi
    printf '%s baseline rc=%s\n' "$(date -u +%FT%TZ)" "$baseline" >> "$root/progress.txt"
    python3 kprog/results/tail-short-encodings-20261117/apply.py fix
    git diff -- kprog/x86/native_lab/native_link/src/x86.rs > "$raw/source.patch"
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/after.txt" 2>&1
    reference=$(cat /workspaces/kprog-raw/perf/map-dispatch-fusion-20261117/current-raw.txt)
    for group in fixture lpm memory; do
        for before in "$reference/$group"/*.bin "$reference/$group"/*.sites; do
            [ -f "$before" ] || continue
            name=${before##*/}
            cmp "$before" "$raw/$group/$name" >> "$raw/payload-comparison.txt" 2>&1
            printf 'identical %s/%s\n' "$group" "$name" >> "$raw/payload-comparison.txt"
        done
    done
    printf '%s host tests complete; building canonical main raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.txt"
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git; flock -x 7
    out=kprog/results/tail-short-encodings-20261117
    for name in before.txt after.txt payload-comparison.txt source.patch; do cp "$raw/$name" "$out/$name"; done
    STAMP="$(date -u +%FT%TZ)" RAW="$raw" python3 - <<'PY'
from pathlib import Path
import os
p=Path('kprog/results/tail-short-encodings-20261117/README.md')
p.write_text(p.read_text()+f"\n{os.environ['STAMP']} — Tail encoding source and full host tests completed; actual logs and source.patch committed. Raw: {os.environ['RAW']}. Sole main build and captured-request emission follow; installed/time results remain pending.\n")
p=Path('kprog/docs/optimizations.md')
p.write_text(p.read_text()+f"\n{os.environ['STAMP']} — Tail short-encoding host tests completed (results/tail-short-encodings-20261117). Three local branch encodings and layout operands compact before opaque chunks; the physical kind10 field remains four bytes and maps after compaction. All live checks and target work stay. See actual before/after and unrelated-byte logs. Captured-request emission, installed bytes and body/helper/map/per-call/throughput remain pending.\n")
PY
    paths=(kprog/x86/native_lab/native_link/src/x86.rs "$out" kprog/docs/optimizations.md)
    git status --short --branch --untracked-files=no > "$raw/source-git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "compact native tail-transition encodings" -- "${paths[@]}" > "$raw/source-commit.txt" 2>&1
    git push origin master > "$raw/source-push.txt" 2>&1
    flock -u 7
    git rev-parse HEAD > "$raw/main-source-commit.txt"
    git diff -- kprog/x86/native_lab/native_link/src > "$raw/main-source.patch"
    taskset -c 19 cargo build --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml > "$raw/build.txt" 2>&1
    taskset -c 19 python3 kprog/results/current-link-capture-20261117/replay.py --output "$raw/replay" > "$raw/replay-output.txt" 2>&1
    printf '%s replay complete raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.txt"
}
main
