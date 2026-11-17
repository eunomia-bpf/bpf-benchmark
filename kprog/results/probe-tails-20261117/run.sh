#!/bin/bash
# Coordinator 2026-11-17: measure the probe-read remainder change (and the shim keep-eBPF deletion) against the
# flag study's O3 group (same flags, previous code): rebuild the one image with the frozen recipe, run the
# one-image check, then time the five apps through the frozen corpus entry with stats on, 3 x 60 s.
set -u
cd /workspaces/repository
R=kprog/results/probe-tails-20261117
T=kprog/results/flag-tuning-20261117
RAW=/workspaces/kprog-raw/probe-tails-20261117
mkdir -p "$RAW"
echo "$(date -u +%FT%TZ) build at $(git rev-parse --short HEAD)" >> "$RAW/progress.log"
if ! ( exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -x 9
       taskset -c 8-23 make -f kprog/perf/one-image/Makefile image JOBS=16 ) > "$RAW/image.log" 2>&1; then
  echo "$(date -u +%FT%TZ) image FAILED" >> "$RAW/progress.log"; exit 1
fi
{ echo "image: $(docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current)"; python3 "$T/textsize.py" vendor/build/native-bpf/x86/stage; } > "$RAW/summary.txt"
( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
  make -f kprog/perf/one-image/Makefile check ) > "$RAW/check.log" 2>&1
tail -6 /workspaces/kprog-raw/one-image-runs/check.log >> "$RAW/summary.txt"
echo "$(date -u +%FT%TZ) check done" >> "$RAW/progress.log"
for app in otelcol-ebpf-profiler/profiling bcc/set cilium/agent tracee/monitor katran; do
  a=$(echo "$app" | tr / _)
  ( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
    make -f kprog/perf/one-image/Makefile corpus APPS="$app" SAMPLES=3 WORKLOAD_DURATION=60 BPFREJIT_CORPUS_BPF_STATS=1 ) > "$RAW/$a.log" 2>&1
  run=$(grep -o '"artifact_run_dir": "[^"]*"' "$RAW/$a.log" | tail -1 | cut -d'"' -f4)
  echo "$(date -u +%FT%TZ) $app run=$run" >> "$RAW/progress.log"
  { echo "== $app $run"; [ -n "$run" ] && python3 "$T/may29_ratio.py" "off=$run" "on=$run" && python3 "$T/inst.py" "$run" && python3 kprog/results/arm-paths-20261116/paths.py "$run" | head -2; } >> "$RAW/summary.txt" 2>&1
done
mkdir -p "$R"; cp "$RAW/summary.txt" "$R/summary.txt"
git add "$R" && git commit -q -m "probe-read remainder: image, check and five-app timing" -- "$R" && git push -q origin HEAD:master
echo "$(date -u +%FT%TZ) done" >> "$RAW/progress.log"
