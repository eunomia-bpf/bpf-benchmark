#!/bin/bash
# Sequential isolated-pass 7-app SAMPLES=3 30s ablation.
# 1) kinsn 5-pass  (rotate, cond_select, extract, endian_fusion, bulk_memory)
# 2) kinsn 6-pass  (above + prefetch)
# 3) all-bytecode-rewriting (no map_inline): noop, wide_mem, const_prop, dce, bounds_check_merge, skb_load_bytes_spec
# Note (3) includes wide_mem which has a known kernel-panic risk on tetragon (Q5);
# KEEP_WORKDIRS=1 captures workdir tarballs if it triggers again.
set -uo pipefail

LOG=/home/yunwei37/workspace/bpf-benchmark/docs/tmp/isolated_passes_queue_20260508.log
cd /home/yunwei37/workspace/bpf-benchmark
source /home/yunwei37/workspace/.venv/bin/activate

run_one () {
  local label="$1"
  local passes="$2"
  echo "==== START ${label}  $(date -u +%FT%TZ) ====" >> "$LOG"
  PLATFORM=kvm ARCH=x86 SAMPLES=3 \
    BPFREJIT_BENCH_PASSES="$passes" \
    KEEP_WORKDIRS=1 \
    make corpus >> "$LOG" 2>&1
  rc=$?
  echo "==== END   ${label}  $(date -u +%FT%TZ) rc=$rc ====" >> "$LOG"
}

run_one "K5-kinsn-5pass-7app" \
        "rotate,cond_select,extract,endian_fusion,bulk_memory"

run_one "K6-kinsn-with-prefetch-7app" \
        "rotate,cond_select,extract,endian_fusion,bulk_memory,prefetch"

run_one "BR-all-bytecode-rewriting-7app" \
        "noop,wide_mem,const_prop,dce,bounds_check_merge,skb_load_bytes_spec"
