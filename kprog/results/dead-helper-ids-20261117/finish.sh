#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/dead-helper-ids-20261117
    raw="$root/host-20261117T211219Z-2760806"
    trap 'status=$?; printf "%s publisher exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/publication-progress.txt"' EXIT
    printf '%s waiting own host2760806\n' "$(date -u +%FT%TZ)" >> "$root/publication-progress.txt"
    tail --pid=2760806 -f /dev/null
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    ulimit -v 33554432
    export PYTHONDONTWRITEBYTECODE=1
    taskset -c 19 python3 kprog/results/dead-helper-ids-20261117/compare.py "$raw" > "$root/comparison-output.txt" 2>&1
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git; flock -x 7
    out=kprog/results/dead-helper-ids-20261117
    for name in build.txt main-source-commit.txt main-source.patch replay-output.txt; do cp "$raw/$name" "$out/$name"; done
    cp "$raw/replay/replay-summary.txt" "$out/replay-summary.txt"
    cp "$raw/replay/replay.json" "$out/replay.json"
    STAMP="$(date -u +%FT%TZ)" python3 - <<'PY'
from pathlib import Path
import json,os
out=Path('kprog/results/dead-helper-ids-20261117');j=json.loads((out/'comparison.json').read_text())
stamp=os.environ['STAMP'];s=j['summary']
parts=[f"{app}: {v['passed']}/{v['requests']} emit, {v.get('before_bytes',0)} -> {v.get('after_bytes',0)} neutral B" for app,v in s.items()]
text=f"\n{stamp} — Dead helper-ID source 2c46d5c52 actual host comparison: "+'; '.join(parts)+". All actual request statuses and index errors are in comparison.json; target/map/mask/recovery observations are separate from payload layout. This uses the post-label-fix baseline, not the old pre-label output. Installed native/JIT and app per-call/body/helper/map/throughput still require owner image/check/timing with all LTO on. No raw request or prior run is discarded.\n"
p=Path('kprog/docs/optimizations.md');p.write_text(p.read_text()+text)
p=out/'README.md';p.write_text(p.read_text()+text+"\nThe main source commit/patch and build log are committed with this receipt. This publication adds no production code or repeated source test; the queued canonical build/replay supplies the actual emitter result.\n")
with Path('/workspaces/.agent-state/kprog-lanes/COORDINATION.md').open('a') as f:
 f.write(f"\n- LANE PERF {stamp}: Dead helper-ID queued build/replay has a completed report. "+'; '.join(parts)+". Actual helper target/map/mask/recovery differences remain visible in comparison.json; no installed or speed claim. Automatic own-path publication now commits these receipts with optimization records. Owner image/check/target timing remains pending, all LTO on.\n")
PY
    local paths=("$out" kprog/docs/optimizations.md)
    git status --short --branch --untracked-files=no > "$root/publication-git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "record actual dead helper-ID emission results" -- "${paths[@]}" > "$root/publication-commit.txt" 2>&1
    git push origin master > "$root/publication-push.txt" 2>&1
    printf '%s publication complete\n' "$(date -u +%FT%TZ)" >> "$root/publication-progress.txt"
}
main
