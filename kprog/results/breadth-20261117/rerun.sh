#!/bin/bash
# Coordinator 2026-11-17: Tracee and Katran again through the frozen entry with its defaults (3 x 180 s, stats off).
# Their breadth rows each have one native sample far below the rest (0.719 and 0.754 of eBPF) while unlocked host work
# ran. This run follows the ktime batch on its image (cb4bd4d8, source 53d6c80ce), holds locks/batch, and logs host load.
set -u
cd /workspaces/repository
R=kprog/results/breadth-20261117
T=kprog/results/flag-tuning-20261117
RAW=/workspaces/kprog-raw/breadth-20261117
until grep -Eq '^[0-9T:-]+Z done$' /workspaces/kprog-raw/ktime-leaf-20261117/progress.log; do sleep 60; done
exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch; flock -x 7
load() { { echo "== $(date -u +%FT%TZ) $1"; cat /proc/loadavg; ps -eo pcpu,pid,comm --sort=-pcpu | head -6; } >> "$RAW/hostload.log"; }
echo "$(date -u +%FT%TZ) rerun start, image $(docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current)" >> "$RAW/progress.log"
for app in tracee/monitor katran; do
  a=$(echo "$app" | tr / _)
  ( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
    load "before rerun $app"
    make -f kprog/perf/one-image/Makefile corpus APPS="$app"
    load "after rerun $app" ) > "$RAW/${a}_rerun.log" 2>&1
  run=$(grep -o '"artifact_run_dir": "[^"]*"' "$RAW/${a}_rerun.log" | tail -1 | cut -d'"' -f4)
  echo "$(date -u +%FT%TZ) rerun $app run=$run" >> "$RAW/progress.log"
  { echo "== rerun $app $run"; [ -n "$run" ] && python3 "$T/may29_ratio.py" "off=$run" && python3 "$T/inst.py" "$run"; } >> "$RAW/summary.txt" 2>&1
  cp "$RAW/summary.txt" "$R/summary.txt"
  git add "$R/summary.txt" && git commit -q -m "breadth round 2026-11-17: $app rerun on the ktime image (stats off, 3 x 180 s)" -- "$R/summary.txt" && git push -q origin HEAD:master
done
echo "$(date -u +%FT%TZ) rerun done" >> "$RAW/progress.log"
