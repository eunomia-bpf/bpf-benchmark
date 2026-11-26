#!/bin/bash
# A finite callback collects/publishes the guest job and wakes its stopped lane.
set -euo pipefail
cd /workspaces/repository
out=$PWD/kprog/results/hash-family-c-20261126
lane=/workspaces/.agent-state/kprog-lanes/perf
function wake_lane() {
    printf '\nP3 finite check callback ended (status %s). Read kprog/results/hash-family-c-20261126/guest-summary.json, publication.log and controller.log; inspect/commit the own cleanup-log line, record the actual six-app outcome in todo.md and COORDINATION.md, and fix any real functional failure. Full timing stays frozen.\n' "$?" >> "$lane/resume-msg.md"
    python3 - "$lane/STOP" <<'PY'
from pathlib import Path
import sys
p = Path(sys.argv[1])
if p.exists() and p.read_text().startswith('PERF P3 finite guest check:'):
    p.unlink()
PY
}
trap wake_lane EXIT
tail --pid="$1" --sleep-interval=5 -f /dev/null
make -C kprog/results/hash-family-c-20261126 collect > "$out/collect.log" 2>&1
mapfile -t raw < "$out/raw-paths.txt"
flock /workspaces/.agent-state/kprog-lanes/locks/git bash -eu -c '
    git status --short --branch --untracked-files=no > "$1/publication-status.txt"
    git add -f "$1" "${@:2}"
    git diff --cached --stat -- "$1" "${@:2}" > "$1/publication-stat.txt"
    git commit --only -m "Record hash-family six-app guest check outcomes" -- "$1" "${@:2}"
    git push origin master
' _ "$out" "${raw[@]}" > "$out/publication.log" 2>&1
