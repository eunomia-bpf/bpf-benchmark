#!/bin/sh
# Count kernel memset calls per phase, with a kprobe counter, in the guest.
# Usage: memset-count.sh <out-dir> <manifest> <seconds>
set -u
O=$1 M=$2 SECS=$3
install -d "$O"
mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
D=/sys/kernel/debug/tracing
echo 0 > "$D/tracing_on" 2>>"$O/kprobe.log" || true
echo 'p:memset_count memset' >> "$D/kprobe_events" 2>>"$O/kprobe.log" || echo "kprobe add failed" >> "$O/kprobe.log"
echo 1 > "$D/events/kprobes/memset_count/enable" 2>>"$O/kprobe.log" || true
echo 1 > "$D/tracing_on" 2>>"$O/kprobe.log" || true
: > "$O/profile.log"
cd /workspaces/repository || exit 2
make -f kprog/perf/one-image/Makefile guest APPS=tracee/monitor SAMPLES=1 WORKLOAD_DURATION="$SECS" \
  BPFREJIT_CORPUS_BPF_STATS=1 BPFREJIT_SHIM_NATIVE_LOADER=post \
  NATIVE_MANIFEST="$M" BENCH_PASSES= SKIP_REJIT_MODE=norejit > "$O/guest.log" 2>&1 &
G=$!
for _ in $(seq 1 150); do grep -q '"event": "app_start"' "$O/guest.log" 2>/dev/null && break; sleep 2; done
for ph in baseline post_rejit; do
  for _ in $(seq 1 300); do
    grep -q "\"event\": \"measurement_start\", \"phase\": \"$ph\"" "$O/guest.log" 2>/dev/null && break
    sleep 2
  done
  hits0=$(awk '$1=="memset_count"{print $2}' "$D/kprobe_profile")
  for _ in $(seq 1 400); do
    grep -q "\"event\": \"measurement_done\", \"phase\": \"$ph\"" "$O/guest.log" 2>/dev/null && break
    sleep 2
  done
  hits1=$(awk '$1=="memset_count"{print $2}' "$D/kprobe_profile")
  echo "memset_count $ph $hits0 $hits1 $((hits1-hits0))" >> "$O/memset-counts.txt"
done
wait $G
echo "memset-count: done $(date -u +%FT%TZ)" >> "$O/profile.log"