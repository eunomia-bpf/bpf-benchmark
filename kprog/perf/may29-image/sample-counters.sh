#!/bin/bash
# Sample an application's own map counters several times during one arm.
#
# The counters that answer "did both arms do the same work" live in the app's
# per-CPU maps and are only meaningful while the arm is running, so one snapshot
# has to land at the right moment: a snapshot taken during the baseline phase says
# nothing about the native phase, and the two phases are seconds apart. Waiting a
# fixed time and hoping is what made four earlier attempts produce baseline
# readings labelled as native ones.
#
# This samples on an interval instead, into one directory per sample, so the
# phase each sample belongs to can be decided afterwards from the counts rather
# than from a sleep.
#
# Usage (inside the guest): sample-counters.sh <app-name-substring> <out-root> \
#                            [samples] [interval-seconds]
set -eu

NAME=${1:?application name substring}
OUT=${2:?output root, a path the host can read}
SAMPLES_N=${3:-12}
INTERVAL=${4:-15}

install -d "$OUT"
for n in $(seq 1 "$SAMPLES_N"); do
    # A failing snapshot (the native object set can leave dead map ids behind)
    # must not stop the series: later samples can still land cleanly.
    timeout 120 "$(dirname "$0")/arm-end-counters.sh" "$NAME" "$OUT/sample-$n" 900 \
        > "$OUT/sample-$n.log" 2>&1 || echo "sample $n: rc=$?" >> "$OUT/sample-$n.log"
    sleep "$INTERVAL"
done
echo "sample-counters: $SAMPLES_N samples under $OUT"