#!/bin/sh
# Run one OTel arm and record its reported profile count over time.
#
# otelcol_exporter_queue_batch_send_size_sum on :8888 is the number of profiles the
# profiler has exported, i.e. its reported trace count. The framework keeps only the shim
# log, so this samples the endpoint while the app runs. The delta across an arm's phases
# is the count for that phase.
O=$1
cd /workspaces/repository
make -f kprog/perf/one-image/Makefile guest APPS=otelcol-ebpf-profiler/profiling SAMPLES=1 \
  WORKLOAD_DURATION=120 BPFREJIT_CORPUS_BPF_STATS=1 BPFREJIT_SHIM_NATIVE_LOADER=post \
  NATIVE_MANIFEST=/opt/bpf-benchmark/native-bpf/x86_64/otelcol-ebpf-profiler/manifest.json \
  BENCH_PASSES= SKIP_REJIT_MODE=norejit > "$O/guest.log" 2>&1 &
G=$!
for _ in $(seq 1 120); do
  grep -q '"event": "app_start"' "$O/guest.log" 2>/dev/null && break
  sleep 5
done
for n in $(seq 1 60); do
  echo "--- sample $n $(date -u +%FT%TZ) $(grep -oE '"phase": "[a-z_]+"' "$O/guest.log" | tail -1)" >> "$O/counters.txt"
  kprog/perf/may29-image/capture/probe.sh >> "$O/counters.txt" 2>&1
  sleep 8
done
wait $G
