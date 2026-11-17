#!/bin/bash
# OMP 2026-11-17: leaf batch 2 continuation. The first runner (run.sh) built the one image at 9b87a12ad
# (image 55c1c443, image.log retained) and was killed before writing "image ok"; this script continues from
# that image with the same locks, check and the two timings, so no second image is built.
set -u
cd /workspaces/repository
RAW=/workspaces/kprog-raw/leaf-batch2-20261117
R=kprog/results/leaf-batch2-20261117
T=kprog/results/flag-tuning-20261117
exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch; flock -x 7
load() { { echo "== $(date -u +%FT%TZ) $1"; cat /proc/loadavg; ps -eo pcpu,pid,comm --sort=-pcpu | head -6; } >> "$RAW/hostload.log"; }
img=$(docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current)
echo "$(date -u +%FT%TZ) continuing on image $img built at $(git rev-parse --short HEAD)" >> "$RAW/progress.log"
{ echo "image: $img at $(git rev-parse --short HEAD)"; } > "$RAW/summary.txt"
( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
  load "before check"
  make -f kprog/perf/one-image/Makefile check ) > "$RAW/check.log" 2>&1
tail -8 /workspaces/kprog-raw/one-image-runs/check.log >> "$RAW/summary.txt"
echo "$(date -u +%FT%TZ) check finished" >> "$RAW/progress.log"
for app in tracee/monitor cilium/agent; do
  a=$(echo "$app" | tr / _)
  ( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
    load "before $app"
    make -f kprog/perf/one-image/Makefile corpus APPS="$app" SAMPLES=3 WORKLOAD_DURATION=60 BPFREJIT_CORPUS_BPF_STATS=1
    load "after $app" ) > "$RAW/$a.log" 2>&1
  run=$(grep -o '"artifact_run_dir": "[^"]*"' "$RAW/$a.log" | tail -1 | cut -d'"' -f4)
  echo "$(date -u +%FT%TZ) $app run=$run" >> "$RAW/progress.log"
  { echo "== $app $run"; [ -n "$run" ] && python3 "$T/may29_ratio.py" "off=$run" "on=$run" && python3 "$T/inst.py" "$run" && python3 kprog/results/arm-paths-20261116/paths.py "$run"; } >> "$RAW/summary.txt" 2>&1
  cp "$RAW/summary.txt" "$R/summary.txt"
  git add "$R/summary.txt" && git commit -q -m "leaf batch2: $app timing" -- "$R/summary.txt" && git push -q origin HEAD:master
done
echo "$(date -u +%FT%TZ) done" >> "$RAW/progress.log"