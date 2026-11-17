#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/array-returns-20261117
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
    python3 kprog/results/array-returns-20261117/apply.py
    git diff -- kprog/x86/native_lab/native_link/src/x86.rs \
        kprog/x86/native_lab/native_link/src/x86_runtime_array.rs > "$raw/source.patch"
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/cargo.log" 2>&1
    reference=/workspaces/kprog-raw/perf/fixed-error-zeroing-20261117/host-20261117T174028Z-2683911
    for before in "$reference"/fixture/*.bin "$reference"/fixture/*.sites; do
        name=${before##*/}
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
    for name in known-array-max3 known-array-max4096 runtime-array; do
        printf '%s %s\n' "$name" "$(stat -c %s "$raw/fixture/$name.bin")" >> "$raw/local-sizes.txt"
        objdump -D -b binary -m i386:x86-64 -Mintel "$raw/fixture/$name.bin" >> "$raw/array-disassembly.txt"
    done
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git
    flock -x 7
    out=kprog/results/array-returns-20261117
    cp "$raw/cargo.log" "$out/host-output.txt"
    cp "$raw/payload-comparison.txt" "$raw/memory-comparison.txt" "$raw/local-sizes.txt" "$raw/array-disassembly.txt" "$out/"
    printf '%s raw=%s\n' "$(date -u +%FT%TZ)" "$raw" > "$out/host-location.txt"
    printf '\n%s — ARRAY lookup returns directly from success and miss paths instead of jumping to a shared RET. Known ARRAY/per-CPU bodies lose one hot success-path jump and one local byte; runtime ARRAY loses one success and one miss-path jump and three bytes. Generic non-ARRAY dispatch still uses its original aligned E8 helper CALL, including original arguments. No new check, flag, limit, layout fact or module/relocation ABI. Full host suite, real key/bounds/mask/wide-product/fallback execution, both CALL/JMP entry slots and decoder return assertions pass. Results: results/array-returns-20261117; raw %s. Local instruction/byte effects only; app per-call/body/helpers/maps/throughput and installed native/JIT remain for Omp timing with all LTO on.\n' "$(date -u +%FT%TZ)" "$raw" >> kprog/docs/optimizations.md
    local paths=(kprog/x86/native_lab/native_link/src/x86.rs \
        kprog/x86/native_lab/native_link/src/x86_runtime_array.rs kprog/docs/optimizations.md \
        "$out/host-output.txt" "$out/payload-comparison.txt" "$out/memory-comparison.txt" \
        "$out/local-sizes.txt" "$out/array-disassembly.txt" "$out/host-location.txt")
    git status --short --branch --untracked-files=no > "$raw/git-status.txt"
    git diff --check -- "${paths[@]}"
    git diff --stat -- "${paths[@]}" > "$raw/diffstat.txt"
    git add -- "${paths[@]}"
    git commit --only -m "return directly from ARRAY lookup success and miss paths" -- "${paths[@]}" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
}
main
