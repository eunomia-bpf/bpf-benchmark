#!/bin/sh
# Dump OTel's metrics map twice inside EACH phase of one run.
#
# Native code installs only at post_rejit (baseline shim log: 0 replacements; post_rejit:
# 13), so one run contains both arms. Two dumps per phase, 40 s apart, means at least one
# lands while the counters are warm even though the app restarts at the phase boundary.
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
  # wait for this phase's measurement to begin
  for _ in $(seq 1 120); do
    grep -q "\"event\": \"measurement_start\", \"phase\": \"$ph\"" "$O/guest.log" 2>/dev/null && break
    sleep 5
  done
  for k in 1 2; do
    sleep 35
    kprog/perf/may29-image/map-dump.sh metrics "$O/$ph-$k" 200 10 >> "$O/map.log" 2>&1
    echo "$ph-$k $(date -u +%FT%TZ)" >> "$O/dump-times.txt"
  done
done
wait $G
