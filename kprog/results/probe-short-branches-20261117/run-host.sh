#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/probe-short-branches-20261117
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw/fixture" "$raw/lpm" "$raw/memory" "$raw/tmp"
    trap 'status=$?; printf "%s host exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    printf '%s waiting timing SH then image EX raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
    flock -x 9
    ulimit -v 33554432
    export CARGO_BUILD_JOBS=1 TMPDIR="$raw/tmp" NATIVE_LINK_PROBE_TEST_OUTPUT="$raw/fixture"
    export NATIVE_LINK_LPM_TEST_OUTPUT="$raw/lpm" NATIVE_LINK_MEMORY_TEST_OUTPUT="$raw/memory"
    python3 kprog/results/probe-short-branches-20261117/apply.py
    git diff -- kprog/x86/native_lab/native_link/src/x86_probe_read.rs > "$raw/source.patch"
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/cargo.log" 2>&1
    reference=/workspaces/kprog-raw/perf/lru-displacements-20261117/host-20261117T161644Z-2634254
    taskset -c 19 python3 kprog/results/probe-short-branches-20261117/compare.py \
        --before "$reference/fixture" --after "$raw/fixture" --output "$raw" > "$raw/load-comparison.log" 2>&1
    for before in "$reference"/fixture/*.bin; do
        name=${before##*/}
        case "$name" in kernel*|user*|compat*) continue;; esac
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
    out=kprog/results/probe-short-branches-20261117
    cp "$raw/cargo.log" "$out/host-output.txt"
    cp "$raw/payload-comparison.log" "$out/payload-comparison.txt"
    cp "$raw/memory-comparison.log" "$out/memory-comparison.txt"
    cp "$raw/sizes.txt" "$raw/sizes-and-loads.json" "$out/"
    cp "$raw/load-comparison.log" "$out/load-comparison.txt"
    printf '%s raw=%s\n' "$(date -u +%FT%TZ)" "$raw" > "$out/host-location.txt"
    printf '\n%s — Probe routine-local branch sizing uses the existing iced-x86 encoder before user/kernel scalar/string builders return bytes and recovery metadata. Instruction-offset maps move protected load sites and nested helper relocations together; existing append shifts to global offsets once. External E8 slots, protected-load lengths/R11 destination and all read policy/fault/zeroing behavior stay intact. Compat dispatch external jumps are unchanged. No new runtime check, limit, flag, resolver or module/schema change. Full host suite and 24 synthetic branch/call/load/append cases pass; mapped source-load bytes are compared against retained forms, with other leaves and memory bodies identical. Results: results/probe-short-branches-20261117; raw %s. Local sizes are not app installed bytes or per-call gains; Omp schedules image/check/target timing with all LTO on.\n' "$(date -u +%FT%TZ)" "$raw" >> kprog/docs/optimizations.md
    local paths=(kprog/x86/native_lab/native_link/src/x86_probe_read.rs kprog/docs/optimizations.md \
        "$out/host-output.txt" "$out/payload-comparison.txt" "$out/memory-comparison.txt" \
        "$out/sizes.txt" "$out/sizes-and-loads.json" "$out/load-comparison.txt" "$out/host-location.txt")
    git status --short --branch --untracked-files=no > "$raw/git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "size local probe branches with recovery offset remapping" -- "${paths[@]}" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
    printf '%s host tested committed pushed raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
}
main
