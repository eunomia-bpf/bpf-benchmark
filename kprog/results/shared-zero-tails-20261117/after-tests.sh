#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/shared-zero-tails-20261117
    raw=/workspaces/kprog-raw/perf/shared-zero-tails-20261117/host-20261117T234518Z-2818089
    install -d "$raw/fixture" "$raw/lpm" "$raw/memory" "$raw/tmp"
    printf '%s\n' "$raw" > "$root/current-raw.txt"
    trap 'status=$?; printf "%s exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.txt"' EXIT
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9
    ulimit -v 33554432
    export CARGO_BUILD_JOBS=1 TMPDIR="$raw/tmp" PYTHONDONTWRITEBYTECODE=1
    export NATIVE_LINK_PROBE_TEST_OUTPUT="$raw/fixture" NATIVE_LINK_LPM_TEST_OUTPUT="$raw/lpm"
    export NATIVE_LINK_MEMORY_TEST_OUTPUT="$raw/memory"
    export NATIVE_LINK_TASK_LAYOUT=/workspaces/kprog-raw/perf/uid-packed-load-20261117/retry-20261117T171823Z-2677411/target-layout.json
    printf '%s continue completed host tests raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.txt"
    stat -c '%s %Y' kprog/x86/native_lab/native_link/target/release/native-link > "$raw/main-before.txt"
    taskset -c 19 python3 - "$raw" > "$raw/payload-comparison.txt" <<'COMPARE'
from pathlib import Path
import sys
raw=Path(sys.argv[1]);reference=Path('/workspaces/kprog-raw/perf/map-provenance-cfg-20261117/host-20261117T232351Z-2807862')
for group in ['fixture','lpm','memory']:
    for before in sorted((reference/group).iterdir()):
        if before.suffix not in ['.bin','.sites']:continue
        after=raw/group/before.name
        print('identical' if before.read_bytes()==after.read_bytes() else 'changed',group+'/'+before.name)
COMPARE
    printf '%s host tests complete; replaying production unit entry raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.txt"
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git; flock -x 7
    out=kprog/results/shared-zero-tails-20261117
    for name in before.txt after.txt payload-comparison.txt source.patch; do cp "$raw/$name" "$out/$name"; done
    STAMP="$(date -u +%FT%TZ)" RAW="$raw" python3 - <<'PY'
from pathlib import Path
import os
p=Path('kprog/results/shared-zero-tails-20261117/README.md')
p.write_text(p.read_text()+f"\n{os.environ['STAMP']} — Structural shared zero-tail source and full host tests completed; actual logs and source.patch committed. Raw: {os.environ['RAW']}. Production unit-entry build and captured-request emission follow; canonical CLI stays unchanged; installed/time results remain pending.\n")
p=Path('kprog/docs/optimizations.md')
p.write_text(p.read_text()+f"\n{os.environ['STAMP']} — Structural shared zero-tail host tests completed (results/shared-zero-tails-20261117). Identical error tails share one existing suffix with local success returns; policy/copy/cleanup and source-load metadata remain explicit. The full existing host matrix also executes a duplicate leaf through the shared suffix. No runtime selector, flag or helper is added. See actual before/after and unrelated-byte logs. Captured-request emission, installed bytes and body/helper/map/per-call/throughput remain pending.\n")
PY
    paths=(kprog/x86/native_lab/native_link/src/x86_probe_read.rs "$out" kprog/docs/optimizations.md)
    git status --short --branch --untracked-files=no > "$raw/source-git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "share read-error zero tails within each native image" -- "${paths[@]}" > "$raw/source-commit.txt" 2>&1
    git push origin master > "$raw/source-push.txt" 2>&1
    flock -u 7
    git rev-parse HEAD > "$raw/unit-source-commit.txt"
    git diff -- kprog/x86/native_lab/native_link/src > "$raw/unit-source.patch"
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        --no-run --message-format=json > "$raw/test-build.json" 2> "$raw/test-build.txt"
    python3 - "$raw" <<'PYCODE'
from pathlib import Path
import json,sys
raw=Path(sys.argv[1]);rows=[json.loads(line) for line in (raw/'test-build.json').read_text().splitlines()]
files=[r['executable'] for r in rows if r.get('reason')=='compiler-artifact' and r.get('profile',{}).get('test') and r.get('executable')]
assert len(files)==1,files
(raw/'test-executable.txt').write_text(files[0]+'\n')
PYCODE
    executable=$(cat "$raw/test-executable.txt")
    taskset -c 19 python3 kprog/results/link-entry-replay-20261117/replay.py --output "$raw/replay" --test-executable "$executable" > "$raw/replay-output.txt" 2>&1
    stat -c '%s %Y' kprog/x86/native_lab/native_link/target/release/native-link > "$raw/main-after.txt"
    cmp "$raw/main-before.txt" "$raw/main-after.txt"
    printf '%s replay complete raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.txt"
}
main
