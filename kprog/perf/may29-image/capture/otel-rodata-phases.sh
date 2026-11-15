#!/bin/sh
# Read the live .rodata.var map in both phases of one OTel run, and dump the metrics map
# in each phase too, so a nonzero rodata read can be tied to a working unwind.
O=$1
cd /workspaces/repository
make -f kprog/perf/one-image/Makefile guest APPS=otelcol-ebpf-profiler/profiling SAMPLES=1 \
  WORKLOAD_DURATION=120 BPFREJIT_CORPUS_BPF_STATS=1 BPFREJIT_SHIM_NATIVE_LOADER=post \
  NATIVE_MANIFEST=/opt/bpf-benchmark/native-bpf/x86_64/otelcol-ebpf-profiler/manifest.json \
  BENCH_PASSES= SKIP_REJIT_MODE=norejit > "$O/guest.log" 2>&1 &
G=$!
for _ in $(seq 1 150); do
  grep -q '"event": "app_start"' "$O/guest.log" 2>/dev/null && break
  sleep 5
done
for ph in baseline post_rejit; do
  for _ in $(seq 1 120); do
    grep -q "\"event\": \"measurement_start\", \"phase\": \"$ph\"" "$O/guest.log" 2>/dev/null && break
    sleep 5
  done
  sleep 40
  kprog/perf/may29-image/capture/rodata-read.sh > "$O/$ph-rodata.txt" 2>&1
  kprog/perf/may29-image/map-dump.sh metrics "$O/$ph" 200 20 >> "$O/map.log" 2>&1
  echo "$ph $(date -u +%FT%TZ)" >> "$O/dump-times.txt"
done
wait $G
