#!/bin/sh
# Dump Tetragon's tg_stats_map in BOTH phases of one run.
#
# Native code installs only at post_rejit (baseline shim log: 0 "replaced prog=",
# post_rejit: 13 for OTel; the same rule holds for every app), so one run holds both
# arms: baseline is eBPF, post_rejit is native. tg_stats_map is u64 sent_failed[256][7]
# indexed by msg_op x errno, so it counts events per type -- under back-pressure, since
# it is only written when a send fails with EAGAIN.
O=$1
cd /workspaces/repository
make -f kprog/perf/one-image/Makefile guest APPS=tetragon/observer SAMPLES=1 \
  WORKLOAD_DURATION=120 BPFREJIT_CORPUS_BPF_STATS=1 BPFREJIT_SHIM_NATIVE_LOADER=post \
  NATIVE_MANIFEST=/opt/bpf-benchmark/native-bpf/x86_64/tetragon/manifest.json \
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
  for k in 1 2; do
    sleep 35
    kprog/perf/may29-image/map-dump.sh tg_stats_map "$O/$ph-$k" 200 10 >> "$O/map.log" 2>&1
    echo "$ph-$k $(date -u +%FT%TZ)" >> "$O/dump-times.txt"
  done
done
wait $G
