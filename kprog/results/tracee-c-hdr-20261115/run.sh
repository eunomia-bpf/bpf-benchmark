#!/bin/bash
# Tracee on the compile-flag/header route.
# Protocol (coordinator 2026-11-15T14:03, from the operator's "A/A 一次"): one A/A run
# (both arms eBPF) and one A/B run (first arm eBPF, second arm native), 3x180 s each,
# BPF stats on, CPUs 0-7, per-call time primary. `check` is the 10 s functional start.
# Per-CPU busy time of CPUs 0-7 is recorded around every sample so contention is visible.
set -eu
ROOT=/workspaces/repository
RAW=/workspaces/kprog-raw/C/tracee-c-hdr-20261115
MAN=$ROOT/corpus/results/tracee-c-hdr-20261115/objects/manifest.json
MK="make -r -f $ROOT/kprog/perf/one-image/Makefile corpus APPS=tracee/monitor SAMPLES=3 WORKLOAD_DURATION=180 BPFREJIT_CORPUS_BPF_STATS=1 SKIP_REJIT_MODE=norejit CPUS=0-7"
stage=$1

cpu_busy() {  # current busy and total jiffies of CPUs 0-7
  grep -E '^cpu[0-7] ' /proc/stat | awk '{b=$2+$3+$4+$7+$8+$9; t=b+$5+$6; print b, t}'
}

one() {  # one <mode> <tag> <samples> <seconds>
  local mode=$1 tag=$2 n=$3 secs=$4
  local state=/var/tmp/kprog-tmp/C/tracee-c-hdr/$tag
  local logs=$RAW/$stage/logs
  rm -rf "$state" && install -d "$state" "$logs"
  local before after
  before=$(cpu_busy)
  echo "$(date -u +%FT%TZ) start $tag mode=$mode samples=$n secs=$secs"
  local rc=0
  $MK SAMPLES=$n WORKLOAD_DURATION=$secs NATIVE_LOADER_MODE=$mode NATIVE_MANIFEST=$MAN \
      STATE=$state LOGS=$logs > "$RAW/$stage/$tag.log" 2>&1 || rc=$?
  after=$(cpu_busy)
  echo "$before" > "$RAW/$stage/$tag.cpu-before"
  echo "$after" > "$RAW/$stage/$tag.cpu-after"
  echo "$(date -u +%FT%TZ) end $tag rc=$rc run=$(grep -o '"artifact_run_dir": "[^"]*"' "$RAW/$stage/$tag.log" | tail -1 | cut -d'"' -f4)"
  rm -f "$state"/*.tar "$state"/*.img 2>/dev/null || true
}

if [ "$stage" = check ]; then
  one post check 1 10
elif [ "$stage" = ab1 ]; then
  # A/A is already measured (batch x86_kvm_corpus_20261115_203638_295992, 1.007 drift),
  # so the loader fix needs only the A/B half re-run.
  one post ab1 3 180
else
  one 0 aa1 3 180
  one post ab1 3 180
fi