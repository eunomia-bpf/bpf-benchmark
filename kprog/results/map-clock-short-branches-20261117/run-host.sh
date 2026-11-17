#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/map-clock-short-branches-20261117
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
    python3 kprog/results/map-clock-short-branches-20261117/apply.py
    git diff -- kprog/x86/native_lab/native_link/src/x86_probe_read.rs \
        kprog/x86/native_lab/native_link/src/x86_lpm_lookup.rs kprog/x86/native_lab/native_link/src/x86_ktime.rs > "$raw/source.patch"
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/cargo.log" 2>&1
    reference=/workspaces/kprog-raw/perf/probe-short-branches-20261117/host-20261117T162945Z-2638683
    for before in "$reference"/fixture/*.bin "$reference"/fixture/*.sites; do
        name=${before##*/}
        case "$name" in ktime.bin) continue;; esac
        cmp "$before" "$raw/fixture/$name" >> "$raw/payload-comparison.log" 2>&1
        printf 'identical %s\n' "$name" >> "$raw/payload-comparison.log"
    done
    for before in "$reference"/memory/*.bin; do
        name=${before##*/}
        cmp "$before" "$raw/memory/$name" >> "$raw/memory-comparison.log" 2>&1
        printf 'identical %s\n' "$name" >> "$raw/memory-comparison.log"
    done
    wc -c "$reference/fixture/ktime.bin" "$raw/fixture/ktime.bin" \
        "$reference/lpm/lpm.bin" "$raw/lpm/lpm.bin" > "$raw/local-sizes.txt"
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git
    flock -x 7
    out=kprog/results/map-clock-short-branches-20261117
    cp "$raw/cargo.log" "$out/host-output.txt"
    cp "$raw/payload-comparison.log" "$out/payload-comparison.txt"
    cp "$raw/memory-comparison.log" "$out/memory-comparison.txt"
    cp "$raw/local-sizes.txt" "$out/local-sizes.txt"
    printf '%s raw=%s\n' "$(date -u +%FT%TZ)" "$raw" > "$out/host-location.txt"
    printf '\n%s — LPM and clock reuse the existing routine-local branch sizing step. Real external helper relocations are carried through sizing, then shifted once at shared-leaf append. LPM keeps its generic helper and stack ABI; clock keeps both preemption calls and the original fast-clock fallback. All external E8+zero slots, targets, branch behavior and live work remain intact. No new runtime check, refusal, option, fact, schema or module/kernel change. Full host suite, LPM trie/guard/prefix matrix, clock formula/preemption/fallback vectors and exact shared-slot contracts pass; probe and other leaf/memory payloads remain identical. Results: results/map-clock-short-branches-20261117; raw %s. Actual local sizes recorded separately; per-call/throughput and installed native/JIT remain pending Omp app batch, with all LTO on.\n' "$(date -u +%FT%TZ)" "$raw" >> kprog/docs/optimizations.md
    local paths=(kprog/x86/native_lab/native_link/src/x86_probe_read.rs \
        kprog/x86/native_lab/native_link/src/x86_lpm_lookup.rs kprog/x86/native_lab/native_link/src/x86_ktime.rs \
        kprog/docs/optimizations.md "$out/host-output.txt" "$out/payload-comparison.txt" \
        "$out/memory-comparison.txt" "$out/local-sizes.txt" "$out/host-location.txt")
    git status --short --branch --untracked-files=no > "$raw/git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "size LPM and clock branches with helper relocations" -- "${paths[@]}" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
    printf '%s host tested committed pushed raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
}
main
