#!/bin/bash
# Run one application in both native configurations once round e releases CPUs
# 0-7, so the two configurations are measured at the timing settings the
# evaluation uses (3x180 s, stats on) without competing with the coordinator.
#
# Usage: queue-timing.sh <app> <specialized-manifest-dir> [samples] [seconds]
set -eu
APP=${1:?app}
MANIFEST=${2:?specialized manifest directory}
SAMPLES_N=${3:-3}
SECONDS_N=${4:-180}
ROOT=$(cd "$(dirname "$0")/../../../.." && pwd)
LOGS=${LOGS:-/workspaces/kprog-raw/one-image-runs}
install -d "$LOGS"
while pgrep -f "one-image/Makefile rotate" > /dev/null 2>&1; do sleep 60; done
sleep 30
"$ROOT/kprog/perf/one-image/scripts/specialized-timing.sh" "$APP" image \
  /var/tmp/kprog-tmp/C/state "$SAMPLES_N" "$SECONDS_N" 0-7 > "$LOGS/queue-plain.out" 2>&1
"$ROOT/kprog/perf/one-image/scripts/specialized-timing.sh" "$APP" "$MANIFEST" \
  /var/tmp/kprog-tmp/C/state "$SAMPLES_N" "$SECONDS_N" 0-7 > "$LOGS/queue-spec.out" 2>&1
echo "$(date -u +%FT%TZ) queue-timing done app=$APP" >> "$LOGS/specialized.log"
