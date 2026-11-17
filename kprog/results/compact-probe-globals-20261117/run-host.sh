#!/bin/bash
# Apply and validate only this LTO change in the canonical source/build.
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/compact-probe-globals-20261117
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw/fixture" "$raw/tmp"
    trap 'status=$?; printf "%s host exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    printf '%s host waiting timing SH raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
    flock -x 9
    ulimit -v 33554432
    export CARGO_BUILD_JOBS=1
    export NATIVE_LINK_PROBE_TEST_OUTPUT="$raw/fixture"
    export TMPDIR="$raw/tmp"
    printf '%s host applying and testing raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    bash -n kprog/results/compact-probe-globals-20261117/run-host.sh
    python3 kprog/results/compact-probe-globals-20261117/edit.py --apply
    git diff -- kprog/x86/native_lab/native_link/src/x86_probe_read.rs \
        kprog/x86/native_lab/native_link/fixtures/probe_read_driver.c > "$raw/source.patch"
    taskset -c 19 cargo test --release \
        --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/cargo.log" 2>&1
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git
    flock -x 7
    export KPROG_COMPACT_RAW="$raw"
    python3 - <<'PY'
from pathlib import Path
import json
import os
import subprocess
raw = Path(os.environ['KPROG_COMPACT_RAW'])
reference = Path('/workspaces/kprog-raw/perf/shared-helper-tail-20261117/host-20261117T135709Z-2591610/fixture')
out = Path('kprog/results/compact-probe-globals-20261117')
stamp = subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip()
payloads = []
for binary in sorted((raw/'fixture').glob('*.bin')):
    before = reference/binary.name
    payloads.append({'name': binary.name, 'before_bytes': before.stat().st_size if before.exists() else None,
                     'after_bytes': binary.stat().st_size})
(out/'host-output.txt').write_text((raw/'cargo.log').read_text())
(out/'host.json').write_text(json.dumps({
    'recorded_utc': stamp, 'raw': str(raw), 'cargo_exit': 0,
    'payloads': payloads,
    'scope': 'Host leaf/encoding/fault/policy tests and local payload bytes; no installed app size or per-call measurement.',
}, indent=2)+'\n')
with Path('kprog/docs/optimizations.md').open('a') as f:
    f.write(f'\n{stamp} — Compact live-global operands in probe-read leaves: signed-disp32 absolute SIB loads/TEST retain 64-bit address size and live USER_PTR_MAX, SMAP capability and virtual-width values. Wide addresses retain MOVABS and fold field displacements. Existing policy/recovery/cleanup logic stays; no module/schema/refusal or flag change. Full canonical linker suite passes under timing SH/image EX on CPU19, including wide and compact execution variants and signed-address boundary decoding. Local payload sizes and full output are in results/compact-probe-globals-20261117/host.json and host-output.txt; these are not installed app bytes or per-call/body/helper/map gains. Omp schedules image/check/app timing. Raw {raw}.\n')
PY
    local paths=(
        kprog/x86/native_lab/native_link/src/x86_probe_read.rs
        kprog/x86/native_lab/native_link/fixtures/probe_read_driver.c
        kprog/docs/optimizations.md
        kprog/results/compact-probe-globals-20261117/host-output.txt
        kprog/results/compact-probe-globals-20261117/host.json
    )
    git status --short --branch --untracked-files=no > "$raw/git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "compact live global operands in native probe-read leaves" -- "${paths[@]}" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
    printf '%s host tested, committed and pushed raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
}
main
