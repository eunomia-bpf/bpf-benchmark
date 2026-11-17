#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/map-dispatch-fusion-20261117
    trap 'status=$?; printf "%s publication exit=%s\n" "$(date -u +%FT%TZ)" "$status" >> "$root/publication-progress.txt"' EXIT
    tail --pid="$1" -f /dev/null
    raw=$(cat "$root/current-raw.txt")
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    ulimit -v 33554432
    export PYTHONDONTWRITEBYTECODE=1
    taskset -c 19 python3 kprog/results/map-dispatch-fusion-20261117/compare.py "$raw" > "$root/comparison-output.txt" 2>&1
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git; flock -x 7
    out=kprog/results/map-dispatch-fusion-20261117
    for name in test-build.txt test-executable.txt unit-source-commit.txt unit-source.patch main-before.txt main-after.txt replay-output.txt; do cp "$raw/$name" "$out/$name"; done
    cp "$raw/replay/replay.json" "$out/replay.json"
    cp "$raw/replay/replay-summary.txt" "$out/replay-summary.txt"
    STAMP="$(date -u +%FT%TZ)" python3 - <<'PY'
from pathlib import Path
import json,os
p=Path('kprog/results/map-dispatch-fusion-20261117');j=json.loads((p/'comparison.json').read_text());stamp=os.environ['STAMP']
parts=[f"{app}: {s['passed']}/{s['requests']} emit, {s.get('fused_images',0)} fused, {s.get('before_bytes',0)} -> {s.get('after_bytes',0)} neutral B" for app,s in j['summary'].items()]
text=f"\n{stamp} — Actual ARRAY/LPM fusion emission: "+'; '.join(parts)+". All request/error records and helper/map/mask/recovery observations are retained in comparison.json; no installed/per-call/body/helper/map/throughput gain claimed. Owner image/check/affected-app timing remains pending with all LTO on.\n"
for file in [p/'README.md',Path('kprog/docs/optimizations.md')]:file.write_text(file.read_text()+text)
with Path('/workspaces/.agent-state/kprog-lanes/COORDINATION.md').open('a') as f:f.write(f"\n- LANE PERF {stamp}: ARRAY/LPM fusion host replay report completed. "+'; '.join(parts)+". Actual statuses and metadata comparisons retained; automatic own-path receipt publication follows. Installed/time metrics remain pending with Omp, all LTO on.\n")
PY
    paths=("$out" kprog/docs/optimizations.md)
    git status --short --branch --untracked-files=no > "$root/publication-git-status.txt"
    git diff --check -- "${paths[@]}"
    git add -- "${paths[@]}"
    git commit --only -m "record actual fused map dispatch emission" -- "${paths[@]}" > "$root/publication-commit.txt" 2>&1
    git push origin master > "$root/publication-push.txt" 2>&1
    printf '%s publication complete\n' "$(date -u +%FT%TZ)" >> "$root/publication-progress.txt"
}
main "$@"
