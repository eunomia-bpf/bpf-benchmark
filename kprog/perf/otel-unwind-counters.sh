#!/bin/sh
# Read OTel's unwind counters in both arms of one run, without editing the
# timing entry (kprog/perf/one-image/Makefile).
#
# Why the run's own artifacts are not enough: a corpus run records per-program
# BPF stats (run_cnt/run_time per kernel prog), but OTel's unwind counters are
# not program stats - they live in a per-CPU array map named `metrics`, indexed
# by the metricID enum, and they are tail-call descendants' counters, which
# `bpf_prog->stats` does not even attribute. The shim's own map snapshot would
# capture the map, but it refuses anything over 64 KiB and this one is 68 KB at
# the eight CPUs the timing runs use, so the counters never reach the artifacts.
#
# So the map is dumped with bpftool inside the guest, in each phase, while the
# run is live. The guest mounts the repository read-write, so the dump lands
# directly under the output directory. Every guest setting below is the entry's
# own (`make -n corpus` shows the same values); the only difference is that the
# in-guest command is this script's dumper instead of `make guest`.
#
# Usage: otel-unwind-counters.sh <out-dir-under-repo>
#
# Decode the two dumps with otel-metrics.py; it prints the delta.
set -eu
O=${1:?output directory under the repository, e.g. corpus/results/otel-counters-DATE}
REPO=/workspaces/repository
KDIR=/workspaces/.agent-state/kprog-ck/build-x86
STATE=/var/tmp/kprog-tmp/one-image-otel-counters
PORT=${PORT:-0}
SETTLE=${SETTLE:-40}
LOCK=/workspaces/.agent-state/kprog-lanes/locks/timing
SAMPLES=${SAMPLES:-1}
DURATION=${DURATION:-120}

case "$O" in
    /*) ;;
    *) O="$REPO/$O" ;;
esac
install -d "$O" "$STATE/var-tmp"

# Pin the image the dumps belong to. The sole image is swapped between the May
# reference and the current source (several times a round), so a run started
# after a swap reads a different arm than the one a reader expects. Record the
# ID with the dumps; otel-metrics.py refuses a pair taken on different IDs.
IMAGE_ID=$(docker images --format '{{.ID}}' bpf-benchmark/kprog:current)
printf '%s\n' "$IMAGE_ID" > "$O/image-id.txt"
echo "image: $IMAGE_ID" >&2

ln -sfn "$REPO/.cache/container-images/x86_64-runner-runtime.image.tar" "$STATE/var-tmp/runtime.image.tar"
ln -sfn "$REPO/kinsn/module/x86/build/bpf_x86_native_lab.ko" "$STATE/var-tmp/bpf_x86_native_lab.ko"

exec 9>"$LOCK"
flock 9
echo "guest: $(date -u +%FT%TZ) samples=$SAMPLES duration=$DURATION" >&2
taskset -c 0-7 vng --run "$KDIR/arch/x86/boot/bzImage" --cwd "$REPO" \
  --rwdir "$REPO" --rwdir "/var/tmp=$STATE/var-tmp" \
  --overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local \
  --disable-monitor --cpus 8 --memory 64G \
  --append 'loglevel=4 panic=30 oops=panic' \
  --exec "sh $REPO/kprog/perf/otel-counters-guest.sh $O $SAMPLES $DURATION $SETTLE" \
  > "$O/guest-console.log" 2>&1