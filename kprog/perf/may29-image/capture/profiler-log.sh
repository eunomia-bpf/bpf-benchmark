#!/bin/sh
# Run one OTel arm and sample the profiler's own reported profile counters.
#
# The profiler serves them on its telemetry endpoint (otelcol_* with data_type="profiles")
# at :8888. The framework keeps only the shim log, so this is the single place its own
# accounting is visible. Sampling starts once the app is up, not while the image installs.
O=$1
cd /workspaces/repository
make -f kprog/perf/one-image/Makefile guest APPS=otelcol-ebpf-profiler/profiling SAMPLES=1 \
  WORKLOAD_DURATION=120 BPFREJIT_CORPUS_BPF_STATS=1 BPFREJIT_SHIM_NATIVE_LOADER=post \
  NATIVE_MANIFEST=/opt/bpf-benchmark/native-bpf/x86_64/otelcol-ebpf-profiler/manifest.json \
  BENCH_PASSES= SKIP_REJIT_MODE=norejit > "$O/guest.log" 2>&1 &
G=$!
# wait for the app, not a fixed sleep
for _ in $(seq 1 90); do
  grep -q '"event": "app_start"' "$O/guest.log" 2>/dev/null && break
  sleep 5
done
for n in $(seq 1 40); do
  echo "--- sample $n $(date -u +%FT%TZ) $(grep -oE '"phase": "[a-z_]+"' "$O/guest.log" | tail -1)" >> "$O/counters.txt"
  kprog/perf/may29-image/capture/probe.sh >> "$O/counters.txt" 2>&1
  sleep 10
done
wait $G
