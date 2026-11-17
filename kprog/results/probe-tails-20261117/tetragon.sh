#!/bin/bash
# Coordinator 2026-11-17: Tetragon on the same probe-tails image after the five-app series in run.sh
# (Tetragon loads every program since 603cacfb; its last breadth-round runs ended with errors).
set -u
cd /workspaces/repository
R=kprog/results/probe-tails-20261117
T=kprog/results/flag-tuning-20261117
RAW=/workspaces/kprog-raw/probe-tails-20261117
until grep -q ' done$' "$RAW/progress.log"; do sleep 60; done
app=tetragon/observer; a=tetragon_observer
( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
  make -f kprog/perf/one-image/Makefile corpus APPS="$app" SAMPLES=3 WORKLOAD_DURATION=60 BPFREJIT_CORPUS_BPF_STATS=1 ) > "$RAW/$a.log" 2>&1
run=$(grep -o '"artifact_run_dir": "[^"]*"' "$RAW/$a.log" | tail -1 | cut -d'"' -f4)
echo "$(date -u +%FT%TZ) $app run=$run" >> "$RAW/progress.log"
{ echo "== $app $run"; [ -n "$run" ] && python3 "$T/may29_ratio.py" "off=$run" "on=$run" && python3 "$T/inst.py" "$run" && python3 kprog/results/arm-paths-20261116/paths.py "$run" | head -2; } >> "$RAW/summary.txt" 2>&1
cp "$RAW/summary.txt" "$R/summary.txt"
git add "$R" && git commit -q -m "probe-read remainder: Tetragon timing on the same image" -- "$R" && git push -q origin HEAD:master
echo "$(date -u +%FT%TZ) tetragon done" >> "$RAW/progress.log"
