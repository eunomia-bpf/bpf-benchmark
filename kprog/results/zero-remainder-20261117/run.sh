#!/bin/bash
# Coordinator 2026-11-17: probe reads send an empty remainder straight to success (perf review 5e9b2badc: after
# c03737bf4, multiples of eight paid two extra compares). P stays at -O3; the linker changes. Rebuild the one image
# with the frozen recipe, list stage executable bytes, and time OTel, BCC and Tracee (the probe-read users) through
# the frozen corpus entry, stats on, 3 x 60 s; compare with run2 in probe-tails-20261117/summary-o3.txt.
set -u
cd /workspaces/repository
R=kprog/results/zero-remainder-20261117
T=kprog/results/flag-tuning-20261117
RAW=/workspaces/kprog-raw/zero-remainder-20261117
mkdir -p "$RAW"
echo "$(date -u +%FT%TZ) build at $(git rev-parse --short HEAD)" >> "$RAW/progress.log"
if ! ( exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -x 9
       taskset -c 8-23 make -f kprog/perf/one-image/Makefile image JOBS=16 ) > "$RAW/image.log" 2>&1; then
  echo "$(date -u +%FT%TZ) image FAILED" >> "$RAW/progress.log"; exit 1
fi
echo "$(date -u +%FT%TZ) image ok" >> "$RAW/progress.log"
{ echo "image: $(docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current)"
  python3 "$T/textsize.py" vendor/build/native-bpf/x86/stage; } > "$RAW/summary.txt"
for app in otelcol-ebpf-profiler/profiling bcc/set tracee/monitor; do
  a=$(echo "$app" | tr / _)
  ( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
    make -f kprog/perf/one-image/Makefile corpus APPS="$app" SAMPLES=3 WORKLOAD_DURATION=60 BPFREJIT_CORPUS_BPF_STATS=1 ) > "$RAW/$a.log" 2>&1
  run=$(grep -o '"artifact_run_dir": "[^"]*"' "$RAW/$a.log" | tail -1 | cut -d'"' -f4)
  echo "$(date -u +%FT%TZ) $app run=$run" >> "$RAW/progress.log"
  { echo "== $app $run"; [ -n "$run" ] && python3 "$T/may29_ratio.py" "off=$run" "on=$run" && python3 "$T/inst.py" "$run" && python3 kprog/results/arm-paths-20261116/paths.py "$run" | head -3; } >> "$RAW/summary.txt" 2>&1
  cp "$RAW/summary.txt" "$R/summary.txt"
  git add "$R/summary.txt" && git commit -q -m "probe-read empty remainder: $app timing" -- "$R/summary.txt" && git push -q origin HEAD:master
done
echo "$(date -u +%FT%TZ) done" >> "$RAW/progress.log"
