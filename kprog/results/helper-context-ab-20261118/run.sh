#!/bin/bash
# Coordinator 2026-11-18: OTel on the all-LTO image (3246e818) fell from 1.053x to 0.950x (stats off, frozen entry
# defaults) while every native entry now binds the original program's kernel helper functions (kernel_helper_context).
# This run separates that one change: same image, same entry, NATIVE_MANIFEST (an existing entry variable) points at a
# control manifest that differs from the shipped one only by dropping kernel_helper_context. Stats off with the entry
# defaults, then stats on 3 x 60 s. Waits for the all-LTO batch to log done and holds locks/batch.
set -u
cd /workspaces/repository
APPS=${*:-otelcol-ebpf-profiler/profiling}
R=kprog/results/helper-context-ab-20261118
T=kprog/results/flag-tuning-20261117
RAW=/workspaces/kprog-raw/helper-context-ab-20261118
C=corpus/results/helper-context-ab-20261118
mkdir -p "$RAW" "$C"
log() { echo "$(date -u +%FT%TZ) $*" >> "$RAW/progress.log"; }
load() { { echo "== $(date -u +%FT%TZ) $1"; cat /proc/loadavg; top -b -n 2 -d 2 -o %CPU | awk '/^top -/{n++} n==2' | sed -n '1,4p;7,14p'; } >> "$RAW/hostload.log"; }
until grep -Eq '^[0-9T:-]+Z done$' /workspaces/kprog-raw/lto-all-20261118/progress.log 2>/dev/null; do sleep 60; done
exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch; flock -x 7
log "start, image $(docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current)"
for app in $APPS; do
  dir=${app%%/*}; a=$(echo "$app" | tr / _)
  python3 - "$dir" "$C/$dir-control-manifest.json" <<'PY'
import json, sys
from pathlib import Path, PurePosixPath
d, out = sys.argv[1], Path(sys.argv[2])
m = json.loads(Path(f'vendor/build/native-bpf/x86/stage/{d}/manifest.json').read_text())
rt = PurePosixPath(f'/opt/bpf-benchmark/native-bpf/x86_64/{d}')
n = 0
for e in m['objects']:
    for k in ('native_object', 'source_bpf_object', 'kernel_kfunc_btf'):
        if k in e and not PurePosixPath(e[k]).is_absolute():
            e[k] = str(rt / e[k])
    n += bool(e.pop('kernel_helper_context', False))
out.write_text(json.dumps(m, indent=2) + '\n')
print(d, 'entries', len(m['objects']), 'kernel_helper_context dropped from', n)
PY
  for phase in off on; do
    ( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
      load "before control $phase $app"
      if [ $phase = off ]; then make -f kprog/perf/one-image/Makefile corpus APPS="$app" NATIVE_MANIFEST="/workspaces/repository/$C/$dir-control-manifest.json"
      else make -f kprog/perf/one-image/Makefile corpus APPS="$app" SAMPLES=3 WORKLOAD_DURATION=60 BPFREJIT_CORPUS_BPF_STATS=1 NATIVE_MANIFEST="/workspaces/repository/$C/$dir-control-manifest.json"; fi
      load "after control $phase $app" ) > "$RAW/${a}_control_$phase.log" 2>&1
    run=$(grep -o '"artifact_run_dir": "[^"]*"' "$RAW/${a}_control_$phase.log" | tail -1 | cut -d'"' -f4)
    log "control $phase $app run=$run"
    { echo "== control (helper context dropped) $phase $app $run"
      if [ -n "$run" ]; then
        if [ $phase = off ]; then python3 "$T/may29_ratio.py" "off=$run"; else python3 "$T/may29_ratio.py" "off=$run" "on=$run"; fi
        python3 "$T/inst.py" "$run"
        [ $phase = on ] && python3 kprog/results/arm-paths-20261116/paths.py "$run" | head -4
      fi; } >> "$RAW/summary.txt" 2>&1
    cp "$RAW/summary.txt" "$R/summary.txt"
    git add "$R/summary.txt" "$C/$dir-control-manifest.json"
    git commit -q -m "helper-context A/B: $app control (stats $phase)" -- "$R/summary.txt" "$C/$dir-control-manifest.json" && git push -q origin HEAD:master
  done
done
log "done"
