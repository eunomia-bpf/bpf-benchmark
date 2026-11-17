#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/array-arithmetic-20261117
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw/fixture" "$raw/tmp"
    trap 'status=$?; printf "%s host exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    printf '%s waiting timing SH then image EX raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
    flock -x 9
    ulimit -v 33554432
    export CARGO_BUILD_JOBS=1 NATIVE_LINK_PROBE_TEST_OUTPUT="$raw/fixture" TMPDIR="$raw/tmp"
    python3 kprog/results/array-arithmetic-20261117/apply.py
    git diff -- kprog/x86/native_lab/native_link/src/x86.rs > "$raw/source.patch"
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/cargo.log" 2>&1
    reference=/workspaces/kprog-raw/perf/constant-probe-size-20261117/copy-retry2-20261117T151059Z-2610649/fixture
    for before in "$reference"/*.bin "$reference"/*.sites; do
        name=${before##*/}
        cmp "$before" "$raw/fixture/$name" >> "$raw/payload-comparison.log" 2>&1
        printf 'identical %s\n' "$name" >> "$raw/payload-comparison.log"
    done
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git
    flock -x 7
    cp "$raw/cargo.log" kprog/results/array-arithmetic-20261117/host-output.txt
    cp "$raw/payload-comparison.log" kprog/results/array-arithmetic-20261117/payload-comparison.txt
    printf '%s raw=%s\n' "$(date -u +%FT%TZ)" "$raw" > kprog/results/array-arithmetic-20261117/host-location.txt
    printf '\n%s — Known ARRAY address arithmetic: positive non-power-of-two strides through 127 use 64-bit IMUL imm8. Nonzero value offsets fold both additions into one 64-bit LEA (disp8 when signed displacement fits); zero offset retains the shorter ADD. Existing SIB scales, bounds, masks, per-CPU loads and unsupported-stride behavior stay as before. Stride24/offset304 arithmetic is 16 to 12 local bytes and three to two instructions. Host tests cover wide products, signed displacements and lookup bounds; retained probe/clock/UID bytes are compared unchanged. Application per-call/body/helper/map and installed bytes remain pending Omp timing. Results: results/array-arithmetic-20261117; raw %s.\n' "$(date -u +%FT%TZ)" "$raw" >> kprog/docs/optimizations.md
    local paths=(kprog/x86/native_lab/native_link/src/x86.rs kprog/docs/optimizations.md \
        kprog/results/array-arithmetic-20261117/host-output.txt \
        kprog/results/array-arithmetic-20261117/payload-comparison.txt \
        kprog/results/array-arithmetic-20261117/host-location.txt)
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "compact known ARRAY multiply and pointer addition" -- "${paths[@]}" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
    printf '%s host tested committed pushed raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
}
main
