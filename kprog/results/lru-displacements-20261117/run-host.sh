#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/lru-displacements-20261117
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
    python3 kprog/results/lru-displacements-20261117/apply.py
    git diff -- kprog/x86/native_lab/native_link/src/x86.rs > "$raw/source.patch"
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/cargo.log" 2>&1
    reference=/workspaces/kprog-raw/perf/known-large-memory-20261117/host-20261117T154720Z-2625131
    for before in "$reference"/fixture/*.bin "$reference"/fixture/*.sites; do
        name=${before##*/}
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
    out=kprog/results/lru-displacements-20261117
    cp "$raw/cargo.log" "$out/host-output.txt"
    cp "$raw/payload-comparison.log" "$out/payload-comparison.txt"
    cp "$raw/memory-comparison.log" "$out/memory-comparison.txt"
    wc -c "$raw"/fixture/lru-ref*.post.bin > "$out/local-sizes.txt"
    printf '%s raw=%s\n' "$(date -u +%FT%TZ)" "$raw" > "$out/host-location.txt"
    printf '\n%s — LRU reference-byte CMP/MOV operands use zero displacement or signed disp8 when fitting; other offsets keep disp32. One common emitter replaces two duplicate emitters. Existing null guard, conditional zero-to-one reference update, value-pointer arithmetic and flags remain intact. Offset35 saves6 local bytes (same-shape postprocess25→19B), with no instruction-count gain or new per-call check, flag, limit, resolver or module change. Full host suite includes signed operand decodes, null/state/idempotence and read-only nonzero-reference execution. Existing probe/ARRAY/LPM/clock/UID and memory payloads compare identical. Results: results/lru-displacements-20261117; raw %s. App per-call and installed bytes remain pending Omp batch; all LTO stays on.\n' "$(date -u +%FT%TZ)" "$raw" >> kprog/docs/optimizations.md
    local paths=(kprog/x86/native_lab/native_link/src/x86.rs kprog/docs/optimizations.md \
        "$out/host-output.txt" "$out/payload-comparison.txt" "$out/memory-comparison.txt" \
        "$out/local-sizes.txt" "$out/host-location.txt")
    git status --short --branch --untracked-files=no > "$raw/git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "compact LRU reference-byte displacements" -- "${paths[@]}" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
    printf '%s host tested committed pushed raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
}
main
