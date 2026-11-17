#!/bin/bash
# Serialize the canonical host build with image publication in the sole tree.
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/constant-probe-size-20261117
    raw="$root/copy-retry2-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    reference=/workspaces/kprog-raw/perf/compact-probe-globals-20261117/host-20261117T141057Z-2595751/fixture
    install -d "$raw/fixture" "$raw/tmp"
    trap 'status=$?; printf "%s host exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    printf '%s host waiting timing SH raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    printf '%s host waiting image EX raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
    flock -x 9
    ulimit -v 33554432
    export CARGO_BUILD_JOBS=1
    export NATIVE_LINK_PROBE_TEST_OUTPUT="$raw/fixture"
    export TMPDIR="$raw/tmp"
    printf '%s host applying and testing raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    bash -n kprog/results/constant-probe-size-20261117/run-host-copy-retry2.sh
    python3 kprog/results/constant-probe-size-20261117/fix-tail-consumption.py --apply
    git diff -- kprog/x86/native_lab/native_link/src kprog/x86/native_lab/native_link/fixtures/probe_read_driver.c > "$raw/source.patch"
    taskset -c 19 cargo test --release \
        --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/cargo.log" 2>&1
    # Successful pre-existing E8 leaf bodies and recovered-load metadata stay
    # identical. This is an experiment comparison, not a benchmark gate.
    for before in "$reference"/*.bin "$reference"/*.sites; do
        name=${before##*/}
        cmp "$before" "$raw/fixture/$name" >> "$raw/payload-comparison.log" 2>&1
        printf 'identical %s\n' "$name" >> "$raw/payload-comparison.log"
    done
    # Keep the image lock until the tested source and receipts are committed,
    # so the next publisher sees complete inputs rather than a host-test WIP.
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git
    flock -x 7
    export KPROG_TAIL_RAW="$raw"
    python3 - <<'PY'
from pathlib import Path
import json
import os
import subprocess
raw = Path(os.environ['KPROG_TAIL_RAW'])
out = Path('kprog/results/constant-probe-size-20261117')
stamp = subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip()
(out/'copy-host-output.txt').write_text((raw/'cargo.log').read_text())
(out/'copy-payload-comparison.txt').write_text((raw/'payload-comparison.log').read_text())
(out/'copy-host.json').write_text(json.dumps({
    'recorded_utc': stamp, 'raw': str(raw), 'cargo_exit': 0,
    'payload_comparison_exit': 0,
    'scope': 'Canonical host linker tests and existing leaf/recovery metadata byte comparisons; no image, guest or app timing.',
}, indent=2)+'\n')
with Path('kprog/docs/optimizations.md').open('a') as f:
    f.write(f'\n{stamp} — Constant-size scalar probe reads: each existing domain leaf uses a fixed count only when all direct and compat callers agree on the low-u32 RSI value. Internal helper branch metadata preserves the fact through layout, conditional tails and numeric joins. Known terminal helper branches retain their original-site facts. Counted qword loops and fixed tails preserve load/fault/store order and full-size zeroing, without cloning policy bodies or adding a per-call check, size limit, switch or public schema. Full canonical linker suite and retained generic payload/recovery comparisons pass under timing SH/image EX; actual count/width/policy/SMAP/zero/fault and helper-binding cases are in results/constant-probe-size-20261117/copy-host-output.txt. Host sizes are not installed app bytes or per-call effects; Omp schedules image/check/timing. Raw {raw}.\n')
PY
    local paths=(
        kprog/x86/native_lab/native_link/src/x86.rs
        kprog/x86/native_lab/native_link/src/x86_memory.rs
        kprog/x86/native_lab/native_link/src/x86_probe_read.rs
        kprog/x86/native_lab/native_link/fixtures/probe_read_driver.c
        kprog/docs/optimizations.md
        kprog/results/constant-probe-size-20261117/copy-host-output.txt
        kprog/results/constant-probe-size-20261117/copy-payload-comparison.txt
        kprog/results/constant-probe-size-20261117/copy-host.json
    )
    git status --short --branch --untracked-files=no > "$raw/git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "specialize shared scalar reads at one proven count" -- "${paths[@]}" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
    printf '%s host tested, committed and pushed raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
}
main
