#!/bin/bash
# Coordinator 2026-11-17: one compile-flag set for every app, chosen by measurement.
# Operator: "也得通过调优编译参数做到native 快 50%、代码量少一半. 必须要确保这样, 硬性要求", "编译参数所有 app 统一.",
# and 2026-11-16 (/goal): "接下来你来做, 不要叫其他人, 你来负责清理好并且自己去调性能参数".
# For each candidate: rebuild the one image with the frozen recipe and NATIVE_CFLAGS set on the command line,
# record executable bytes per app, then time five apps through the frozen corpus entry (stats on).
set -u
cd /workspaces/repository
R=kprog/results/flag-tuning-20261117
RAW=/workspaces/kprog-raw/flag-tuning-20261117
mkdir -p "$RAW"
REL=$(cat /workspaces/.agent-state/kprog-ck/build-x86/include/config/kernel.release)
COMMON="-g -fPIC -c -fomit-frame-pointer -march=native -mno-red-zone -mgeneral-regs-only -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables -Xclang -fembed-bitcode=all -Wno-unknown-attributes -Wno-compare-distinct-pointer-types"
declare -A F
F[O3]="-O3 $COMMON"
F[Os]="-Os $COMMON"
F[O2]="-O2 $COMMON"
F[O3-branch]="-O3 $COMMON -mllvm -x86-cmov-converter-force-all=true"
F[O3-nounroll]="-O3 $COMMON -fno-unroll-loops"
ORDER=${ORDER:-"O3 Os O2 O3-branch O3-nounroll O3"}
APPS=${APPS:-"otelcol-ebpf-profiler/profiling bcc/set cilium/agent tracee/monitor katran"}
SAMPLES=${SAMPLES:-3}
DUR=${DUR:-60}
i=0
for name in $ORDER; do
  i=$((i + 1)); tag="$i-$name"; out="$RAW/$tag"; mkdir -p "$out"
  echo "$(date -u +%FT%TZ) $tag build: ${F[$name]}" >> "$RAW/progress.log"
  if ! ( exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -x 9
         rm -rf "vendor/build/native-bpf/x86/$REL/native"
         taskset -c 8-23 make -f kprog/perf/one-image/Makefile image JOBS=16 NATIVE_CFLAGS="${F[$name]}" ) > "$out/image.log" 2>&1; then
    echo "$(date -u +%FT%TZ) $tag image FAILED" >> "$RAW/progress.log"; continue
  fi
  echo "flags: ${F[$name]}" > "$out/summary.txt"
  echo "image: $(docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current)" >> "$out/summary.txt"
  python3 "$R/textsize.py" vendor/build/native-bpf/x86/stage >> "$out/summary.txt"
  for app in $APPS; do
    a=$(echo "$app" | tr / _)
    ( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
      make -f kprog/perf/one-image/Makefile corpus APPS="$app" SAMPLES="$SAMPLES" WORKLOAD_DURATION="$DUR" BPFREJIT_CORPUS_BPF_STATS=1 ) > "$out/$a.log" 2>&1
    run=$(grep -o '"artifact_run_dir": "[^"]*"' "$out/$a.log" | tail -1 | cut -d'"' -f4)
    echo "$(date -u +%FT%TZ) $tag $app run=$run" >> "$RAW/progress.log"
    { echo "== $app $run"; [ -n "$run" ] && python3 "$R/may29_ratio.py" "off=$run" "on=$run" && python3 "$R/inst.py" "$run"; } >> "$out/summary.txt" 2>&1
  done
  cp "$out/summary.txt" "$R/$tag.txt"
  git add "$R/$tag.txt" && git commit -q -m "flag tuning: $tag" -- "$R/$tag.txt" && git push -q origin HEAD:master
done
echo "$(date -u +%FT%TZ) done" >> "$RAW/progress.log"
