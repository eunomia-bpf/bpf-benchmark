#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/link-entry-replay-20261117
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
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
    stat -c '%s %Y' kprog/x86/native_lab/native_link/target/release/native-link > "$raw/main-before.txt"
    printf '%s entry refactor/tests raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.txt"
    python3 kprog/results/link-entry-replay-20261117/apply.py
    git diff -- kprog/x86/native_lab/native_link/src/main.rs > "$raw/source.patch"
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        --no-run --message-format=json > "$raw/test-build.json" 2> "$raw/test-build.txt"
    python3 - "$raw" <<'PY'
from pathlib import Path
import json,sys
raw=Path(sys.argv[1]);rows=[json.loads(line) for line in (raw/'test-build.json').read_text().splitlines()]
files=[r['executable'] for r in rows if r.get('reason')=='compiler-artifact' and r.get('profile',{}).get('test') and r.get('executable')]
assert len(files)==1,files
(raw/'test-executable.txt').write_text(files[0]+'\n')
PY
    executable=$(cat "$raw/test-executable.txt")
    taskset -c 19 "$executable" --test-threads=1 --nocapture > "$raw/tests.txt" 2>&1
    taskset -c 19 python3 kprog/results/link-entry-replay-20261117/replay.py --output "$raw/replay" --test-executable "$executable" > "$raw/replay-output.txt" 2>&1
    stat -c '%s %Y' kprog/x86/native_lab/native_link/target/release/native-link > "$raw/main-after.txt"
    cmp "$raw/main-before.txt" "$raw/main-after.txt"
    printf '%s full tests/replay complete, canonical CLI unchanged raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.txt"
}
main
