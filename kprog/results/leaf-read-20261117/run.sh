#!/bin/bash
# Coordinator 2026-11-17: the user probe read becomes a leaf (perf reviews 16c0758bd, 22de1e918): __access_ok as one
# compare against live USER_PTR_MAX, nmi_uaccess_okay inline, caller-saved registers only; the loader layout gains
# cpu_tlbstate, tlb_state.loaded_mm and task_struct.mm. Rebuild the one image with the frozen recipe, run the one-image
# check (the layout serves every app), then time OTel, BCC and Tracee through the frozen corpus entry, stats on,
# 3 x 60 s; compare with zero-remainder-20261117.
set -u
cd /workspaces/repository
R=kprog/results/leaf-read-20261117
T=kprog/results/flag-tuning-20261117
RAW=/workspaces/kprog-raw/leaf-read-20261117
mkdir -p "$RAW"
echo "$(date -u +%FT%TZ) build at $(git rev-parse --short HEAD)" >> "$RAW/progress.log"
if ! ( exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -x 9
       taskset -c 8-23 make -f kprog/perf/one-image/Makefile image JOBS=16 ) > "$RAW/image.log" 2>&1; then
  echo "$(date -u +%FT%TZ) image FAILED" >> "$RAW/progress.log"; exit 1
fi
echo "$(date -u +%FT%TZ) image ok" >> "$RAW/progress.log"
{ echo "image: $(docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current)"
  python3 "$T/textsize.py" vendor/build/native-bpf/x86/stage; } > "$RAW/summary.txt"
( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
  make -f kprog/perf/one-image/Makefile check ) > "$RAW/check.log" 2>&1
tail -6 /workspaces/kprog-raw/one-image-runs/check.log >> "$RAW/summary.txt"
echo "$(date -u +%FT%TZ) check finished" >> "$RAW/progress.log"
for app in otelcol-ebpf-profiler/profiling bcc/set tracee/monitor; do
  a=$(echo "$app" | tr / _)
  ( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
    make -f kprog/perf/one-image/Makefile corpus APPS="$app" SAMPLES=3 WORKLOAD_DURATION=60 BPFREJIT_CORPUS_BPF_STATS=1 ) > "$RAW/$a.log" 2>&1
  run=$(grep -o '"artifact_run_dir": "[^"]*"' "$RAW/$a.log" | tail -1 | cut -d'"' -f4)
  echo "$(date -u +%FT%TZ) $app run=$run" >> "$RAW/progress.log"
  { echo "== $app $run"; [ -n "$run" ] && python3 "$T/may29_ratio.py" "off=$run" "on=$run" && python3 "$T/inst.py" "$run" && python3 kprog/results/arm-paths-20261116/paths.py "$run" | head -3; } >> "$RAW/summary.txt" 2>&1
  cp "$RAW/summary.txt" "$R/summary.txt"
  git add "$R/summary.txt" && git commit -q -m "user probe read leaf: $app timing" -- "$R/summary.txt" && git push -q origin HEAD:master
done
echo "$(date -u +%FT%TZ) done" >> "$RAW/progress.log"
