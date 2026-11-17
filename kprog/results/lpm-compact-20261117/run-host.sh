#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/lpm-compact-20261117
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw/fixture" "$raw/lpm" "$raw/tmp"
    trap 'status=$?; printf "%s host exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    printf '%s waiting timing SH then image EX raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
    flock -x 9
    ulimit -v 33554432
    export CARGO_BUILD_JOBS=1 NATIVE_LINK_PROBE_TEST_OUTPUT="$raw/fixture" NATIVE_LINK_LPM_TEST_OUTPUT="$raw/lpm" TMPDIR="$raw/tmp"
    python3 kprog/results/lpm-compact-20261117/apply.py
    git diff -- kprog/x86/native_lab/native_link/src/x86_lpm_lookup.rs > "$raw/source.patch"
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/cargo.log" 2>&1
    reference=/workspaces/kprog-raw/perf/array-arithmetic-20261117/host-20261117T153243Z-2617474/fixture
    for before in "$reference"/*.bin "$reference"/*.sites; do
        name=${before##*/}
        cmp "$before" "$raw/fixture/$name" >> "$raw/payload-comparison.log" 2>&1
        printf 'identical %s\n' "$name" >> "$raw/payload-comparison.log"
    done
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git
    flock -x 7
    cp "$raw/cargo.log" kprog/results/lpm-compact-20261117/host-output.txt
    cp "$raw/payload-comparison.log" kprog/results/lpm-compact-20261117/payload-comparison.txt
    printf '%s raw=%s\n' "$(date -u +%FT%TZ)" "$raw" > kprog/results/lpm-compact-20261117/host-location.txt
    wc -c /workspaces/kprog-raw/perf/array-arithmetic-20261117/host-20261117T153243Z-2617474/tmp/lpm-lookup-2617761/lpm.bin "$raw/lpm/lpm.bin" > kprog/results/lpm-compact-20261117/local-sizes.txt
    printf '\n%s — LPM encoding: the existing nonzero BSR paths use XOR63/XOR95 instead of NEG/ADD; the clamp CMP still supplies subsequent flags. Memory operands use disp8 when the existing signed offset fits, with explicit ModRM positions preserving SIB. No new runtime checks, facts, limits, flags or module/schema changes. Full host suite, all differing-bit/prefix/flag cases, compact/wide layouts, memory operand decodes, compressed-trie fixture and generic call ABI pass; previous probe/ARRAY/clock/UID files stay identical. Results: results/lpm-compact-20261117; raw %s. Local bytes are recorded separately; app per-call/body/helper/map and installed bytes await Omp batch.\n' "$(date -u +%FT%TZ)" "$raw" >> kprog/docs/optimizations.md
    local paths=(kprog/x86/native_lab/native_link/src/x86_lpm_lookup.rs kprog/docs/optimizations.md \
        kprog/results/lpm-compact-20261117/host-output.txt kprog/results/lpm-compact-20261117/payload-comparison.txt \
        kprog/results/lpm-compact-20261117/host-location.txt kprog/results/lpm-compact-20261117/local-sizes.txt)
    git status --short --branch --untracked-files=no > "$raw/git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "compact LPM prefix arithmetic and memory displacements" -- "${paths[@]}" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
    printf '%s host tested committed pushed raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
}
main
