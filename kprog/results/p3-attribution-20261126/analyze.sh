#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=$1
lane=/workspaces/.agent-state/kprog-lanes/perf
function wake_lane() {
    printf '\nP3 workload-window PMU analysis ended (status %s). Read %s/{tetragon-profile,tracee-profile}/phase-summary.json and analysis-publication.log. The corrected short-check collector448885 may still be running; inspect its journal. Determine the evidenced cause, record memset weight/denominator, and implement/verify only a within-design fix. Full timing stays frozen.\n' "$?" "$out" >> "$lane/resume-msg.md"
    python3 - "$lane/STOP" <<'PY'
from pathlib import Path
import sys
p = Path(sys.argv[1])
if p.exists() and p.read_text().startswith('PERF P3 attribution:'):
    p.unlink()
PY
}
trap wake_lane EXIT
python3 kprog/results/p3-attribution-20261126/profile_summary.py "$out/tetragon-profile" "$out/tracee-profile"
paths=("$out/tetragon-profile/phase-summary.json" "$out/tetragon-profile/summary-perf.log"
       "$out/tracee-profile/phase-summary.json" "$out/tracee-profile/summary-perf.log")
for f in "$out"/*/phase-summary-initial.json "$out/analysis-initial.log"; do
    if [ -f "$f" ]; then paths+=("$f"); fi
done
flock /workspaces/.agent-state/kprog-lanes/locks/git bash -eu -c '
    git status --short --branch --untracked-files=no
    git add -f -- "$@"
    git commit --only -m "Record workload-window PMU hash and memset sample weights" -- "$@"
    git push origin master
' _ "${paths[@]}" > "$out/analysis-publication.log" 2>&1
