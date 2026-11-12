#!/bin/bash
# Time one application with the load-time-specialized native objects, using the
# one image and the one base. The native configuration is one variable:
# NATIVE_MANIFEST points at a directory built by
# vendor/bpf/native_specialize_objects.py (corpus/results is mounted into the
# runtime container, so the directory lives there).
#
# Usage: specialized-timing.sh <app> <manifest-dir|image> <state-dir> <samples> <seconds> <cpus>
#   CMD=maps captures each program's .rodata map contents instead of timing: the
#   run then carries details/map-snapshots/<app>, the input
#   vendor/bpf/native_specialize_objects.py needs for that application.
# Example (functional check, CPUs 20-23):
#   specialized-timing.sh tracee/monitor corpus/results/spec-test/tracee \
#     /var/tmp/kprog-tmp/C/state 1 10 20-23
set -eu
APP=${1:?app}
MANIFEST=${2:?manifest directory, or the word image for the image manifest}
STATE=${3:?state directory of this lane}
SAMPLES_N=${4:-3}
SECONDS_N=${5:-180}
CPUS_N=${6:-0-7}
LOGS=${LOGS:-/workspaces/kprog-raw/one-image-runs}
ROOT=$(cd "$(dirname "$0")/../../../.." && pwd)
install -d "$LOGS"
TAG=$(date -u +%Y%m%dT%H%M%SZ)
LOG=$LOGS/$TAG-specialized-$(echo "$APP" | tr / _)-s$SAMPLES_N.log
cd "$ROOT"
if [ "$MANIFEST" = image ]; then
  NATIVE=/opt/bpf-benchmark/native-bpf/x86_64/$(echo "$APP" | cut -d/ -f1)/manifest.json
else
  NATIVE=$ROOT/$MANIFEST/manifest.json
fi
PASSES=
SKIP=norejit
[ "${CMD:-time}" = maps ] && { PASSES=map-only; SKIP=; }
taskset -c "$CPUS_N" make -f kprog/perf/one-image/Makefile corpus \
  APPS="$APP" SAMPLES="$SAMPLES_N" WORKLOAD_DURATION="$SECONDS_N" \
  BPFREJIT_CORPUS_BPF_STATS=1 CPUS="$CPUS_N" STATE="$STATE" \
  NATIVE_MANIFEST="$NATIVE" BENCH_PASSES="$PASSES" SKIP_REJIT_MODE="$SKIP" > "$LOG" 2>&1 || rc=$?
rc=${rc:-0}
run=$(grep -o '"artifact_run_dir": "[^"]*"' "$LOG" | tail -1 | cut -d'"' -f4)
echo "$(date -u +%FT%TZ) specialized app=$APP rc=$rc samples=$SAMPLES_N run=$run" >> "$LOGS/specialized.log"
echo "rc=$rc run=$run log=$LOG"
