#!/bin/bash
# Coordinator 2026-11-17: run.sh again at -O3. run.sh's image kept the O2 group's P objects for five apps
# (NATIVE_CFLAGS is outside Make's prerequisites; its stage executable bytes equal 3-O2.txt), so its runs stay
# in raw as a set-aside record. This run removes the native build outputs the way tune.sh does between groups,
# rebuilds the one image with the frozen recipe (P and load-time LTO at -O3; level plumbing and per-symbol proof
# rules removed), lists stage executable bytes beside the O3 group's, commits the source edit once the image
# builds, then runs the one-image check and times all six apps through the frozen corpus entry, stats on,
# 3 x 60 s, committing after each app.
set -u
cd /workspaces/repository
R=kprog/results/probe-tails-20261117
T=kprog/results/flag-tuning-20261117
RAW=/workspaces/kprog-raw/probe-tails-20261117/o3
mkdir -p "$RAW"
REL=$(cat /workspaces/.agent-state/kprog-ck/build-x86/include/config/kernel.release)
echo "$(date -u +%FT%TZ) clean native outputs, build at $(git rev-parse --short HEAD) plus the working-tree LTO edit" >> "$RAW/progress.log"
if ! ( exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -x 9
       python3 -c 'import shutil, sys; shutil.rmtree(sys.argv[1], ignore_errors=True)' "vendor/build/native-bpf/x86/$REL/native"
       rm -f vendor/build/native-bpf/x86/kprog-perf-context-lto.level
       taskset -c 8-23 make -f kprog/perf/one-image/Makefile image JOBS=16 ) > "$RAW/image.log" 2>&1; then
  echo "$(date -u +%FT%TZ) image FAILED" >> "$RAW/progress.log"; exit 1
fi
git commit -q -m "Load-time LTO at fixed -O3, the level P is compiled at; the -O level plumbing and the per-symbol proof build rules go (the loader and the trusted service produce their own proofs)" -- vendor/bpf/Makefile kprog/x86/perf_context_lto.cpp && git push -q origin HEAD:master
echo "$(date -u +%FT%TZ) image ok, source at $(git rev-parse --short HEAD)" >> "$RAW/progress.log"
{ echo "image: $(docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current)"
  python3 "$T/textsize.py" vendor/build/native-bpf/x86/stage
  echo "O3 group (1-O3.txt):"; grep exec_bytes "$T/1-O3.txt"; } > "$RAW/summary.txt"
( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
  make -f kprog/perf/one-image/Makefile check ) > "$RAW/check.log" 2>&1
tail -6 /workspaces/kprog-raw/one-image-runs/check.log >> "$RAW/summary.txt"
echo "$(date -u +%FT%TZ) check done" >> "$RAW/progress.log"
for app in otelcol-ebpf-profiler/profiling bcc/set cilium/agent tetragon/observer tracee/monitor katran; do
  a=$(echo "$app" | tr / _)
  ( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
    make -f kprog/perf/one-image/Makefile corpus APPS="$app" SAMPLES=3 WORKLOAD_DURATION=60 BPFREJIT_CORPUS_BPF_STATS=1 ) > "$RAW/$a.log" 2>&1
  run=$(grep -o '"artifact_run_dir": "[^"]*"' "$RAW/$a.log" | tail -1 | cut -d'"' -f4)
  echo "$(date -u +%FT%TZ) $app run=$run" >> "$RAW/progress.log"
  { echo "== $app $run"; [ -n "$run" ] && python3 "$T/may29_ratio.py" "off=$run" "on=$run" && python3 "$T/inst.py" "$run" && python3 kprog/results/arm-paths-20261116/paths.py "$run" | head -2; } >> "$RAW/summary.txt" 2>&1
  cp "$RAW/summary.txt" "$R/summary-o3.txt"
  git add "$R/summary-o3.txt" && git commit -q -m "probe-read remainder at O3: $app timing" -- "$R/summary-o3.txt" && git push -q origin HEAD:master
done
echo "$(date -u +%FT%TZ) done" >> "$RAW/progress.log"
