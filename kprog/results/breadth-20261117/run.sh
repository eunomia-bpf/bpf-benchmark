#!/bin/bash
# Coordinator 2026-11-17: breadth round on the current image (fc7c4707: O3, probe-read remainder, empty remainder, user
# and kernel leaves, compat dispatch) through the frozen corpus entry with its defaults (3 samples x 180 s, stats off),
# one app after another, to set every app beside its 2026-05-29 floor (audit 20261117T03Z decision 3). Host load is
# logged around each run; each app's ratio is committed when its run ends.
set -u
cd /workspaces/repository
R=kprog/results/breadth-20261117
T=kprog/results/flag-tuning-20261117
RAW=/workspaces/kprog-raw/breadth-20261117
mkdir -p "$RAW" "$R"
load() { { echo "== $(date -u +%FT%TZ) $1"; cat /proc/loadavg; ps -eo pcpu,pid,comm --sort=-pcpu | head -6; } >> "$RAW/hostload.log"; }
echo "$(date -u +%FT%TZ) start, image $(docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current)" >> "$RAW/progress.log"
for app in otelcol-ebpf-profiler/profiling bcc/set cilium/agent tetragon/observer tracee/monitor katran; do
  a=$(echo "$app" | tr / _)
  ( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
    load "before $app"
    make -f kprog/perf/one-image/Makefile corpus APPS="$app"
    load "after $app" ) > "$RAW/$a.log" 2>&1
  run=$(grep -o '"artifact_run_dir": "[^"]*"' "$RAW/$a.log" | tail -1 | cut -d'"' -f4)
  echo "$(date -u +%FT%TZ) $app run=$run" >> "$RAW/progress.log"
  { echo "== $app $run"; [ -n "$run" ] && python3 "$T/may29_ratio.py" "off=$run" && python3 "$T/inst.py" "$run"; } >> "$RAW/summary.txt" 2>&1
  cp "$RAW/summary.txt" "$R/summary.txt"
  git add "$R/summary.txt" && git commit -q -m "breadth round 2026-11-17: $app (stats off, 3 x 180 s)" -- "$R/summary.txt" && git push -q origin HEAD:master
done
echo "$(date -u +%FT%TZ) done" >> "$RAW/progress.log"
