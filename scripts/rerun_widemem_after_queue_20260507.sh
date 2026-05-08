#!/bin/bash
# Watchdog: wait for bench queue (bkvnamooq) to finish, then re-run wide_mem-only 7-app.
# Triggered by user request after Q5 kernel panic. Re-run is best-effort; if it
# panics again, it confirms the bug is reliable and we capture a second trace.
set -uo pipefail

QUEUE_LOG="/home/yunwei37/workspace/bpf-benchmark/docs/tmp/bench_queue_post_refactor_20260507.log"
RUN_LOG="/home/yunwei37/workspace/bpf-benchmark/docs/tmp/widemem_rerun_20260507.log"

cd /home/yunwei37/workspace/bpf-benchmark
source /home/yunwei37/workspace/.venv/bin/activate

echo "[watchdog] $(date -u +%FT%TZ) waiting for P3 to end" >> "$RUN_LOG"
# Wait until P3 (last queue entry) END marker appears.
until grep -q "==== END   P3-skip-rejit-warmups3-7app" "$QUEUE_LOG" 2>/dev/null; do
  sleep 30
done
echo "[watchdog] $(date -u +%FT%TZ) queue ended, sleeping 30s for VM teardown" >> "$RUN_LOG"
sleep 30

echo "==== START WMRR-widemem-rerun-7app  $(date -u +%FT%TZ) ====" >> "$RUN_LOG"
PLATFORM=kvm ARCH=x86 SAMPLES=3 \
  BPFREJIT_BENCH_PASSES=wide_mem \
  KEEP_WORKDIRS=1 \
  make corpus >> "$RUN_LOG" 2>&1
rc=$?
echo "==== END   WMRR-widemem-rerun-7app  $(date -u +%FT%TZ) rc=$rc ====" >> "$RUN_LOG"
