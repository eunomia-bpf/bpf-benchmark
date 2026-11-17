#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/fixed-error-zeroing-20261117
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw/fixture" "$raw/lpm" "$raw/memory" "$raw/tmp"
    trap 'status=$?; printf "%s host exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    printf '%s waiting timing SH then image EX raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
    flock -x 9
    ulimit -v 33554432
    export CARGO_BUILD_JOBS=1 TMPDIR="$raw/tmp" PYTHONDONTWRITEBYTECODE=1
    export NATIVE_LINK_PROBE_TEST_OUTPUT="$raw/fixture" NATIVE_LINK_LPM_TEST_OUTPUT="$raw/lpm"
    export NATIVE_LINK_MEMORY_TEST_OUTPUT="$raw/memory"
    reference=/workspaces/kprog-raw/perf/uid-packed-load-20261117/retry-20261117T171823Z-2677411
    export NATIVE_LINK_TASK_LAYOUT="$reference/target-layout.json"
    python3 kprog/results/fixed-error-zeroing-20261117/apply.py
    git diff -- kprog/x86/native_lab/native_link/src/x86_probe_read.rs > "$raw/source.patch"
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/cargo.log" 2>&1
    taskset -c 19 python3 kprog/results/probe-short-branches-20261117/compare.py \
        --before "$reference/fixture" --after "$raw/fixture" --output "$raw" > "$raw/load-comparison.log" 2>&1
    for before in "$reference"/fixture/*.bin "$reference"/fixture/*.sites; do
        name=${before##*/}
        case "$name" in *-fixed-*) continue;; esac
        cmp "$before" "$raw/fixture/$name" >> "$raw/payload-comparison.log" 2>&1
        printf 'identical %s\n' "$name" >> "$raw/payload-comparison.log"
    done
    cmp "$reference/lpm/lpm.bin" "$raw/lpm/lpm.bin" >> "$raw/payload-comparison.log" 2>&1
    printf 'identical lpm.bin\n' >> "$raw/payload-comparison.log"
    for before in "$reference"/memory/*.bin; do
        name=${before##*/}
        cmp "$before" "$raw/memory/$name" >> "$raw/memory-comparison.log" 2>&1
        printf 'identical %s\n' "$name" >> "$raw/memory-comparison.log"
    done
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git
    flock -x 7
    out=kprog/results/fixed-error-zeroing-20261117
    cp "$raw/cargo.log" "$out/host-output.txt"
    cp "$raw/payload-comparison.log" "$out/payload-comparison.txt"
    cp "$raw/memory-comparison.log" "$out/memory-comparison.txt"
    cp "$raw/sizes.txt" "$raw/sizes-and-loads.json" "$out/"
    cp "$raw/load-comparison.log" "$out/load-comparison.txt"
    printf '%s raw=%s\n' "$(date -u +%FT%TZ)" "$raw" > "$out/host-location.txt"
    printf '\n%s — Known scalar probe-read error zeroing retains the existing full original count: zero count emits no stores, other constants use a bounded qword loop and fixed 4/2/1 tail, with RAX error and original destination preserved after partial faults. Unknown scalar/string paths remain byte-identical; no new check, flag, limit, policy clone, helper identity or ABI. Existing execution/fault/policy cases and full-u32 bounded-loop decoding pass; source-load bytes/lengths/R11 metadata retain their meaning after local sizing. Results: results/fixed-error-zeroing-20261117; raw %s. Local byte savings are not whole-app installed/per-call/body/helper/map/throughput results; those remain for Omp with all LTO on.\n' "$(date -u +%FT%TZ)" "$raw" >> kprog/docs/optimizations.md
    local paths=(kprog/x86/native_lab/native_link/src/x86_probe_read.rs kprog/docs/optimizations.md \
        "$out/host-output.txt" "$out/payload-comparison.txt" "$out/memory-comparison.txt" \
        "$out/sizes.txt" "$out/sizes-and-loads.json" "$out/load-comparison.txt" "$out/host-location.txt")
    git status --short --branch --untracked-files=no > "$raw/git-status.txt"
    git diff --check -- "${paths[@]}"
    git diff --stat -- "${paths[@]}" > "$raw/diffstat.txt"
    git add -- "${paths[@]}"
    git commit --only -m "retain known probe counts when zeroing error destinations" -- "${paths[@]}" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
    printf '%s host tested committed pushed raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
}
main
