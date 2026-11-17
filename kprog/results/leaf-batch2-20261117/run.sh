#!/bin/bash
# OMP 2026-11-17: leaf batch 2 (coordinator 12:41:17Z handed it to omp; PERF applied and committed the source as
# 8b31e4533 / 3ff2ac946 / c91acf326). One image from the committed tree, the one-image functional check, then Tracee
# (uid_gid leaf, shorter kernel-string loop) and Cilium (agent's own compile switches on the loaded lxc/host/xdp
# objects) through the frozen corpus entry, stats on, 3 x 60 s. Holds locks/batch from image build to last timing;
# image build under locks/image, every timing step under locks/timing EX. Host load is logged around each run.
set -u
cd /workspaces/repository
RAW=/workspaces/kprog-raw/leaf-batch2-20261117
R=kprog/results/leaf-batch2-20261117
T=kprog/results/flag-tuning-20261117
INPUTS="kprog/x86/native_lab/native_link kprog/libnativeloader kprog/x86/perf_context_lto.cpp kprog/x86/link_embedded_ir.cpp vendor/bpf/Makefile bpfopt"
mkdir -p "$RAW"
while [ -n "$(git status --porcelain -- $INPUTS; ls vendor/bpf/*compat*.h | xargs git status --porcelain --)" ]; do
  echo "$(date -u +%FT%TZ) waiting for committed build inputs" >> "$RAW/progress.log"; sleep 60
done
exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch; flock -x 7
load() { { echo "== $(date -u +%FT%TZ) $1"; cat /proc/loadavg; ps -eo pcpu,pid,comm --sort=-pcpu | head -6; } >> "$RAW/hostload.log"; }
echo "$(date -u +%FT%TZ) build at $(git rev-parse --short HEAD)" >> "$RAW/progress.log"
if ! ( exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -x 9
       taskset -c 8-23 make -f kprog/perf/one-image/Makefile image JOBS=16 ) > "$RAW/image.log" 2>&1; then
  echo "$(date -u +%FT%TZ) image FAILED" >> "$RAW/progress.log"; exit 1
fi
echo "$(date -u +%FT%TZ) image ok" >> "$RAW/progress.log"
{ echo "image: $(docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current) at $(git rev-parse --short HEAD)"; } > "$RAW/summary.txt"
( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
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