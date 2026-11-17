#!/bin/bash
# Coordinator 2026-11-17: kernel probe reads become leaves (perf reviews 16c0758bd, db9526a6e):
# copy_from_kernel_nofault_allowed inline (below live USER_PTR_MAX + PAGE_SIZE, the vsyscall page, non-canonical at
# boot_cpu_data.x86_virt_bits; width zero allows), caller-saved registers only. Waits for the user-leaf batch, rebuilds
# the one image with the frozen recipe, runs the one-image check, then times BCC, Tetragon and Tracee (the kernel-read
# users) through the frozen corpus entry, stats on, 3 x 60 s; compare with leaf-read-20261117 and probe-tails run2.
# Host load is logged before and after each corpus run (audit 20261117T03Z decision 3).
set -u
cd /workspaces/repository
R=kprog/results/kernel-leaf-20261117
T=kprog/results/flag-tuning-20261117
RAW=/workspaces/kprog-raw/kernel-leaf-20261117
mkdir -p "$RAW"
until grep -Eq '^[0-9T:-]+Z done$' /workspaces/kprog-raw/leaf-read-20261117/progress.log; do sleep 60; done
load() { { echo "== $(date -u +%FT%TZ) $1"; cat /proc/loadavg; ps -eo pcpu,pid,comm --sort=-pcpu | head -6; } >> "$RAW/hostload.log"; }
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
for app in bcc/set tetragon/observer tracee/monitor; do
  a=$(echo "$app" | tr / _)
  ( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
    load "before $app"
    make -f kprog/perf/one-image/Makefile corpus APPS="$app" SAMPLES=3 WORKLOAD_DURATION=60 BPFREJIT_CORPUS_BPF_STATS=1
    load "after $app" ) > "$RAW/$a.log" 2>&1
  run=$(grep -o '"artifact_run_dir": "[^"]*"' "$RAW/$a.log" | tail -1 | cut -d'"' -f4)
  echo "$(date -u +%FT%TZ) $app run=$run" >> "$RAW/progress.log"
  { echo "== $app $run"; [ -n "$run" ] && python3 "$T/may29_ratio.py" "off=$run" "on=$run" && python3 "$T/inst.py" "$run" && python3 kprog/results/arm-paths-20261116/paths.py "$run" | head -3; } >> "$RAW/summary.txt" 2>&1
  cp "$RAW/summary.txt" "$R/summary.txt"
  git add "$R/summary.txt" && git commit -q -m "kernel probe read leaf: $app timing" -- "$R/summary.txt" && git push -q origin HEAD:master
done
echo "$(date -u +%FT%TZ) done" >> "$RAW/progress.log"
