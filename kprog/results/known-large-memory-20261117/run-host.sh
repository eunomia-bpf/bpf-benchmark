#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/known-large-memory-20261117
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw/fixture" "$raw/lpm" "$raw/memory-before" "$raw/memory" "$raw/tmp"
    trap 'status=$?; printf "%s host exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    printf '%s waiting timing SH then image EX raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
    flock -x 9
    ulimit -v 33554432
    export CARGO_BUILD_JOBS=1 TMPDIR="$raw/tmp"
    export NATIVE_LINK_MEMORY_TEST_OUTPUT="$raw/memory-before"
    python3 kprog/results/known-large-memory-20261117/apply.py --capture
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        memory_routines_execute_unaligned_boundaries_fill_and_return -- --test-threads=1 --nocapture > "$raw/before.log" 2>&1
    python3 kprog/results/known-large-memory-20261117/apply.py --change
    export NATIVE_LINK_MEMORY_TEST_OUTPUT="$raw/memory"
    export NATIVE_LINK_PROBE_TEST_OUTPUT="$raw/fixture" NATIVE_LINK_LPM_TEST_OUTPUT="$raw/lpm"
    git diff -- kprog/x86/native_lab/native_link/src/x86_memory.rs > "$raw/source.patch"
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/cargo.log" 2>&1
    reference=/workspaces/kprog-raw/perf/lpm-compact-20261117/host-20261117T153941Z-2620871
    for before in "$reference"/fixture/*.bin "$reference"/fixture/*.sites; do
        name=${before##*/}
        cmp "$before" "$raw/fixture/$name" >> "$raw/payload-comparison.log" 2>&1
        printf 'identical %s\n' "$name" >> "$raw/payload-comparison.log"
    done
    cmp "$reference/lpm/lpm.bin" "$raw/lpm/lpm.bin" >> "$raw/payload-comparison.log" 2>&1
    printf 'identical lpm.bin\n' >> "$raw/payload-comparison.log"
    for before in "$raw"/memory-before/*.bin; do
        name=${before##*/}
        cmp "$before" "$raw/memory/$name" >> "$raw/memory-comparison.log" 2>&1
        printf 'identical %s\n' "$name" >> "$raw/memory-comparison.log"
    done
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git
    flock -x 7
    cp "$raw/cargo.log" kprog/results/known-large-memory-20261117/host-output.txt
    cp "$raw/before.log" kprog/results/known-large-memory-20261117/before-output.txt
    cp "$raw/payload-comparison.log" kprog/results/known-large-memory-20261117/payload-comparison.txt
    cp "$raw/memory-comparison.log" kprog/results/known-large-memory-20261117/memory-comparison.txt
    cp "$raw/memory/sizes.txt" kprog/results/known-large-memory-20261117/local-sizes.txt
    printf '%s raw=%s\n' "$(date -u +%FT%TZ)" "$raw" > kprog/results/known-large-memory-20261117/host-location.txt
    printf '\n%s — Known large memory counts: Routine retains the full u64 RDX count independently of the existing512-byte unroll policy. Larger known counts emit a counted32-byte GPR loop with fixed remainder; unknown counts keep the original dynamic body and small known counts keep their original unrolled bytes. No per-call length dispatch, new limit, refusal, flag, schema or module change. Full host suite and large exact-tail/guard/unaligned/return checks pass; full-width counters including u64::MAX are decoded without impossible allocations. Old small/dynamic memory payloads and other leaf/ARRAY/LPM bytes compare unchanged. Results: results/known-large-memory-20261117; raw %s. Local sizes are not app per-call or installed native/JIT bytes; Omp schedules the target-app batch.\n' "$(date -u +%FT%TZ)" "$raw" >> kprog/docs/optimizations.md
    local paths=(kprog/x86/native_lab/native_link/src/x86_memory.rs kprog/docs/optimizations.md \
        kprog/results/known-large-memory-20261117/host-output.txt kprog/results/known-large-memory-20261117/before-output.txt \
        kprog/results/known-large-memory-20261117/payload-comparison.txt kprog/results/known-large-memory-20261117/memory-comparison.txt \
        kprog/results/known-large-memory-20261117/local-sizes.txt kprog/results/known-large-memory-20261117/host-location.txt)
    git status --short --branch --untracked-files=no > "$raw/git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "retain large known memory counts in compact loops" -- "${paths[@]}" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
    printf '%s host tested committed pushed raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
}
main
