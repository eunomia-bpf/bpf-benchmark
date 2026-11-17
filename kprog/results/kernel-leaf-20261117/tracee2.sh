#!/bin/bash
# Coordinator 2026-11-17: Tracee again on the same image (c0ff0b4c). Run 075401_648119 has per-sample throughput ratios
# 1.279 / 1.217 / 1.226 (a 5.1 % spread), so a second 3 x 60 s run stands beside it.
set -u
cd /workspaces/repository
R=kprog/results/kernel-leaf-20261117
T=kprog/results/flag-tuning-20261117
RAW=/workspaces/kprog-raw/kernel-leaf-20261117
app=tracee/monitor; a=tracee_monitor_2
( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
  make -f kprog/perf/one-image/Makefile corpus APPS="$app" SAMPLES=3 WORKLOAD_DURATION=60 BPFREJIT_CORPUS_BPF_STATS=1 ) > "$RAW/$a.log" 2>&1
run=$(grep -o '"artifact_run_dir": "[^"]*"' "$RAW/$a.log" | tail -1 | cut -d'"' -f4)
echo "$(date -u +%FT%TZ) $app second run=$run" >> "$RAW/progress.log"
{ echo "== $app second run $run"; [ -n "$run" ] && python3 "$T/may29_ratio.py" "off=$run" "on=$run" && python3 "$T/inst.py" "$run" && python3 kprog/results/arm-paths-20261116/paths.py "$run" | head -3; } >> "$RAW/summary.txt" 2>&1
cp "$RAW/summary.txt" "$R/summary.txt"
git add "$R/summary.txt" && git commit -q -m "kernel probe read leaf: second Tracee timing" -- "$R/summary.txt" && git push -q origin HEAD:master
echo "$(date -u +%FT%TZ) tracee second done" >> "$RAW/progress.log"
