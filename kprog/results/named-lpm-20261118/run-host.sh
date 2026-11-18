#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/named-lpm-20261118
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
    printf '%s source/test stage raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.txt"
    stat -c '%s %Y' kprog/x86/native_lab/native_link/target/release/native-link > "$raw/main-before.txt"
    python3 kprog/results/named-lpm-20261118/apply.py test
    if taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        named_lpm_shape_reaches_existing_native_dispatch -- --nocapture > "$raw/before.txt" 2>&1;
        then baseline=0; else baseline=$?; fi
    printf '%s baseline rc=%s\n' "$(date -u +%FT%TZ)" "$baseline" >> "$root/progress.txt"
    python3 kprog/results/named-lpm-20261118/apply.py fix
    git diff -- kprog/x86/native_lab/native_link/src/main.rs kprog/x86/native_lab/native_link/src/x86.rs kprog/libnativeloader/src/native_loader_link_schema.hpp > "$raw/source.patch"
    taskset -c 19 cargo test --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml \
        -- --test-threads=1 --nocapture > "$raw/after.txt" 2>&1
    taskset -c 19 c++ -std=c++20 -O1 -g0 -ffunction-sections -fdata-sections         -Ikprog/libnativeloader/include -Irunner/build-llvmbpf/vendor/libbpf/prefix/include         -Ivendor/libbpf/include -Ivendor/libbpf/include/uapi -Imicro/programs/build-x86         kprog/results/named-lpm-20261118/shape.cpp -Wl,--gc-sections         runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -pthread         -o "$raw/shape" > "$raw/shape-build.txt" 2>&1
    taskset -c 19 "$raw/shape" > "$raw/shape-output.txt" 2>&1
    reference=/workspaces/kprog-raw/perf/shared-zero-tails-20261117/host-20261117T234518Z-2818089
    for group in fixture lpm memory; do
        for before in "$reference/$group"/*.bin "$reference/$group"/*.sites; do
            [ -f "$before" ] || continue
            name=${before##*/}
            cmp "$before" "$raw/$group/$name" >> "$raw/payload-comparison.txt" 2>&1
            printf 'identical %s/%s\n' "$group" "$name" >> "$raw/payload-comparison.txt"
        done
    done
    printf '%s host tests complete; replaying production unit entry raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.txt"
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git; flock -x 7
    out=kprog/results/named-lpm-20261118
    for name in before.txt after.txt payload-comparison.txt source.patch shape-build.txt shape-output.txt; do cp "$raw/$name" "$out/$name"; done
    STAMP="$(date -u +%FT%TZ)" RAW="$raw" python3 - <<'PY'
from pathlib import Path
import os
p=Path('kprog/results/named-lpm-20261118/README.md')
p.write_text(p.read_text()+f"\n{os.environ['STAMP']} — Named LPM shape source and full host tests completed; actual logs and source.patch committed. Raw: {os.environ['RAW']}. Production unit-entry build and captured-request emission follow; canonical CLI stays unchanged; installed/time results remain pending.\n")
p=Path('kprog/docs/optimizations.md')
p.write_text(p.read_text()+f"\n{os.environ['STAMP']} — Named LPM host tests completed (results/named-lpm-20261118). Exact loaded LPM key shapes reuse existing shared trie code; other shapes retain current kernel targets. Loader translation-unit shape tests and actual ELF target binding cover activation; original captured plans supply compatibility coverage. Runtime guards stay, with no new helper identity, flag or refusal. See actual before/after and unrelated-byte logs. Captured-request emission, installed bytes and body/helper/map/per-call/throughput remain pending.\n")
PY
    paths=(kprog/x86/native_lab/native_link/src/main.rs kprog/x86/native_lab/native_link/src/x86.rs kprog/libnativeloader/src/native_loader_link_schema.hpp "$out" kprog/docs/optimizations.md)
    git status --short --branch --untracked-files=no > "$raw/source-git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "reuse native trie for exact loaded LPM key shapes" -- "${paths[@]}" > "$raw/source-commit.txt" 2>&1
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
