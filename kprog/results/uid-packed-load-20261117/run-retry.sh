#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/uid-packed-load-20261117
    raw="$root/retry-$(date -u +%Y%m%dT%H%M%SZ)-$$"
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
    export NATIVE_LINK_MEMORY_TEST_OUTPUT="$raw/memory" NATIVE_LINK_TASK_LAYOUT="$raw/target-layout.json"
    taskset -c 19 python3 kprog/results/uid-packed-load-20261117/target-layout.py \
        --output "$raw/target-layout.json" > "$raw/layout.log" 2>&1
    python3 kprog/results/uid-packed-load-20261117/fix-fixture.py
    git diff -- kprog/x86/native_lab/native_link/src/x86_task.rs \
        kprog/x86/native_lab/native_link/src/x86_memory.rs \
        kprog/x86/native_lab/native_link/src/x86_probe_read.rs \
        kprog/x86/native_lab/native_link/fixtures/task_driver.c > "$raw/source.patch"
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/cargo.log" 2>&1
    reference=/workspaces/kprog-raw/perf/map-clock-short-branches-20261117/host-20261117T164250Z-2668290
    for before in "$reference"/fixture/*.bin "$reference"/fixture/*.sites; do
        name=${before##*/}
        case "$name" in uid-gid.bin) continue;; esac
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
    out=kprog/results/uid-packed-load-20261117
    cp "$raw/cargo.log" "$out/host-output.txt"
    cp "$raw/payload-comparison.log" "$out/payload-comparison.txt"
    cp "$raw/memory-comparison.log" "$out/memory-comparison.txt"
    cp "$raw/target-layout.json" "$out/target-layout.json"
    cp "$raw/fixture/uid-gid-sizes.txt" "$out/local-sizes.txt"
    printf '%s raw=%s\n' "$(date -u +%FT%TZ)" "$raw" > "$out/host-location.txt"
    printf '\n%s — UID/GID leaf: the existing u32 BTF facts and published-credential immutability permit one qword load when UID immediately precedes GID on x86; nonadjacent layouts retain independent fields. Existing operand encoding and local sizing shorten field displacements and the null-current branch. Live IDs, original null -EINVAL, caller lifetime and packing semantics remain intact; no new per-call layout/namespace check, flag, refusal, limit or module/schema change. Full host suite and guard/read-only/unaligned/random/sentinel cases use nine synthetic layouts plus the sole kernel actual BTF. Other leaf and memory bytes compare unchanged. Results: results/uid-packed-load-20261117; raw %s. Actual local sizes recorded separately; app per-call/throughput and installed native/JIT remain pending Omp timing, with all LTO on.\n' "$(date -u +%FT%TZ)" "$raw" >> kprog/docs/optimizations.md
    local paths=(kprog/x86/native_lab/native_link/src/x86_task.rs \
        kprog/x86/native_lab/native_link/src/x86_memory.rs \
        kprog/x86/native_lab/native_link/src/x86_probe_read.rs \
        kprog/x86/native_lab/native_link/fixtures/task_driver.c kprog/docs/optimizations.md \
        "$out/host-output.txt" "$out/payload-comparison.txt" "$out/memory-comparison.txt" \
        "$out/local-sizes.txt" "$out/target-layout.json" "$out/host-location.txt")
    git status --short --branch --untracked-files=no > "$raw/git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}" kprog/results/uid-packed-load-20261117/apply.py
    git commit --only -m "load adjacent immutable UID and GID as one packed word" -- "${paths[@]}" kprog/results/uid-packed-load-20261117/apply.py > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
    printf '%s host tested committed pushed raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
}
main
