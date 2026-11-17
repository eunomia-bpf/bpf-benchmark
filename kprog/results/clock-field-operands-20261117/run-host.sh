#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/clock-field-operands-20261117
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw/fixture" "$raw/lpm" "$raw/memory" "$raw/tmp"
    trap 'status=$?; printf "%s exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    printf '%s waiting timing SH then image EX raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
    flock -x 9
    ulimit -v 33554432
    export CARGO_BUILD_JOBS=1 TMPDIR="$raw/tmp" PYTHONDONTWRITEBYTECODE=1
    export NATIVE_LINK_PROBE_TEST_OUTPUT="$raw/fixture" NATIVE_LINK_LPM_TEST_OUTPUT="$raw/lpm"
    export NATIVE_LINK_MEMORY_TEST_OUTPUT="$raw/memory"
    export NATIVE_LINK_TASK_LAYOUT=/workspaces/kprog-raw/perf/uid-packed-load-20261117/retry-20261117T171823Z-2677411/target-layout.json
    python3 kprog/results/clock-field-operands-20261117/apply.py
    git diff -- kprog/x86/native_lab/native_link/src/x86_ktime.rs > "$raw/source.patch"
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/cargo.log" 2>&1
    reference=/workspaces/kprog-raw/perf/runtime-array-operands-20261117/host-20261117T180906Z-2696608
    for before in "$reference"/fixture/*.bin "$reference"/fixture/*.sites; do
        name=${before##*/}
        case "$name" in ktime.bin) continue;; esac
        cmp "$before" "$raw/fixture/$name" >> "$raw/payload-comparison.txt" 2>&1
        printf 'identical %s\n' "$name" >> "$raw/payload-comparison.txt"
    done
    cmp "$reference/lpm/lpm.bin" "$raw/lpm/lpm.bin" >> "$raw/payload-comparison.txt" 2>&1
    printf 'identical lpm.bin\n' >> "$raw/payload-comparison.txt"
    for before in "$reference"/memory/*.bin; do
        name=${before##*/}
        cmp "$before" "$raw/memory/$name" >> "$raw/memory-comparison.txt" 2>&1
        printf 'identical %s\n' "$name" >> "$raw/memory-comparison.txt"
    done
    printf 'ktime before %s after %s\n' "$(stat -c %s "$reference/fixture/ktime.bin")" \
        "$(stat -c %s "$raw/fixture/ktime.bin")" > "$raw/local-sizes.txt"
    objdump -D -b binary -m i386:x86-64 -Mintel "$raw/fixture/ktime.bin" > "$raw/clock-disassembly.txt"
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git
    flock -x 7
    out=kprog/results/clock-field-operands-20261117
    cp "$raw/cargo.log" "$out/host-output.txt"
    cp "$raw/payload-comparison.txt" "$raw/memory-comparison.txt" "$raw/local-sizes.txt" "$raw/clock-disassembly.txt" "$out/"
    cp "$raw/fixture/ktime.relocs" "$out/clock-relocations.txt"
    printf '%s raw=%s\n' "$(date -u +%FT%TZ)" "$raw" > "$out/host-location.txt"
    printf '\n%s — Clock field ModRM operands reuse the existing memory displacement encoder; the old disp helper becomes the field wrapper, with the one nonmemory tkr_size immediate conversion kept inline. Same signed-offset acceptance, live loads, arithmetic, latch/version/preempt/stable/cycle checks, GS accesses and actual kernel fallback calls. No new runtime check, flag, limit, encoder or ABI. Full host suite, 102 field register/width/offset decoder cases and existing15 clock formula/preemption/fallback vectors pass; all3 actual-target E8 slots survive compaction and final shared offset once. Unrelated leaf/memory bytes identical. Results: results/clock-field-operands-20261117; raw %s. Only local size is measured; app per-call/body/helpers/maps/throughput and installed native/JIT remain for Omp timing with all LTO on.\n' "$(date -u +%FT%TZ)" "$raw" >> kprog/docs/optimizations.md
    local paths=(kprog/x86/native_lab/native_link/src/x86_ktime.rs kprog/docs/optimizations.md \
        "$out/host-output.txt" "$out/payload-comparison.txt" "$out/memory-comparison.txt" \
        "$out/local-sizes.txt" "$out/clock-disassembly.txt" "$out/clock-relocations.txt" "$out/host-location.txt")
    git status --short --branch --untracked-files=no > "$raw/git-status.txt"
    git diff --check -- "${paths[@]}"
    git diff --stat -- "${paths[@]}" > "$raw/diffstat.txt"
    git add -- "${paths[@]}"
    git commit --only -m "compact clock field operands without changing read semantics" -- "${paths[@]}" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
}
main
