#!/bin/sh
# In-guest half: run OTel through the entry's `guest` target, and in each phase
# dump the `metrics` map while the counters are live.
#
# Run by otel-unwind-counters.sh, which has already linked the native-lab module
# into /var/tmp and given the guest the repository. Output must be under the
# repository: it is the only host path the guest has.
set -eu
O=$1
SAMPLES=${2:-1}
DURATION=${3:-120}
SETTLE=${4:-40}
REPO=/workspaces/repository
cd "$REPO"

make -f kprog/perf/one-image/Makefile guest \
  APPS=otelcol-ebpf-profiler/profiling SAMPLES="$SAMPLES" WORKLOAD_DURATION="$DURATION" \
  BPFREJIT_CORPUS_BPF_STATS=1 BPFREJIT_SHIM_NATIVE_LOADER=post \
  NATIVE_MANIFEST=/opt/bpf-benchmark/native-bpf/x86_64/otelcol-ebpf-profiler/manifest.json \
  BENCH_PASSES= SKIP_REJIT_MODE=norejit > "$O/guest.log" 2>&1 &
G=$!

for ph in baseline post_rejit; do
    for _ in $(seq 1 240); do
        grep -q "\"event\": \"measurement_start\", \"phase\": \"$ph\"" "$O/guest.log" 2>/dev/null && break
        sleep 5
    done
    # The map exists from load, but the counters need the workload to run.
    sleep "$SETTLE"
    sh kprog/perf/may29-image/map-dump.sh metrics "$O/$ph" 300 0 >> "$O/map.log" 2>&1
    cp "$O/guest.log" "$O/$ph-guest.log"
    echo "$ph $(date -u +%FT%TZ)" >> "$O/dump-times.txt"
done
wait $G
echo "guest run finished rc=$?" >> "$O/map.log"