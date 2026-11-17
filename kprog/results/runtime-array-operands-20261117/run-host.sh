#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/runtime-array-operands-20261117
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
    python3 kprog/results/runtime-array-operands-20261117/apply.py
    git diff -- kprog/x86/native_lab/native_link/src/x86_runtime_array.rs > "$raw/source.patch"
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/cargo.log" 2>&1
    reference=/workspaces/kprog-raw/perf/array-returns-20261117/host-20261117T175955Z-2692136
    for before in "$reference"/fixture/*.bin "$reference"/fixture/*.sites; do
        name=${before##*/}
        case "$name" in runtime-array.bin) continue;; esac
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
    printf 'runtime-array before %s after %s\n' "$(stat -c %s "$reference/fixture/runtime-array.bin")" \
        "$(stat -c %s "$raw/fixture/runtime-array.bin")" > "$raw/local-sizes.txt"
    objdump -D -b binary -m i386:x86-64 -Mintel "$raw/fixture/runtime-array.bin" > "$raw/array-disassembly.txt"
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git
    flock -x 7
    out=kprog/results/runtime-array-operands-20261117
    cp "$raw/cargo.log" "$out/host-output.txt"
    cp "$raw/payload-comparison.txt" "$raw/memory-comparison.txt" "$raw/local-sizes.txt" "$raw/array-disassembly.txt" "$out/"
    printf '%s raw=%s\n' "$(date -u +%FT%TZ)" "$raw" > "$out/host-location.txt"
    printf '\n%s — Runtime ARRAY field encoding reuses the existing displacement encoder for map_type/max_entries/index_mask/elem_size, and selects imm8 for positive type constants through 127. Other types retain all32bits; the existing i32 offset acceptance stays. Live u32 field reads, key/mask/bounds, wide product, direct returns and generic aligned E8 helper/arguments stay intact. No new runtime check, flag, limit, layout fact, encoder or ABI. Host tests include36 offset/type decoder cases plus existing lookup/fallback and relocation execution; unrelated leaf/memory files compare identical. Results: results/runtime-array-operands-20261117; raw %s. Only local bytes change, not instruction or map/helper counts; app per-call/body/helpers/maps/throughput and installed native/JIT remain for Omp measurement with all LTO on.\n' "$(date -u +%FT%TZ)" "$raw" >> kprog/docs/optimizations.md
    local paths=(kprog/x86/native_lab/native_link/src/x86_runtime_array.rs kprog/docs/optimizations.md \
        "$out/host-output.txt" "$out/payload-comparison.txt" "$out/memory-comparison.txt" \
        "$out/local-sizes.txt" "$out/array-disassembly.txt" "$out/host-location.txt")
    git status --short --branch --untracked-files=no > "$raw/git-status.txt"
    git diff --check -- "${paths[@]}"
    git diff --stat -- "${paths[@]}" > "$raw/diffstat.txt"
    git add -- "${paths[@]}"
    git commit --only -m "compact runtime ARRAY field operands with existing encodings" -- "${paths[@]}" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
}
main
