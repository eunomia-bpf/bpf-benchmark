#!/bin/bash
set -u -o pipefail

outdir="docs/tmp/20260326/rejit_hotswap_vm_20260326_140538"
progs_dir="./tests/unittest/build/progs"
summary_tsv="$outdir/summary.tsv"
all_log="$outdir/all.log"
runtime_log="$outdir/runtime_check.log"

types=(
  tracepoint
  kprobe
  perf_event
  fentry
  lsm
  xdp
  socket_filter
  sched_cls
  cgroup_skb
  struct_ops
  ext
  sk_lookup
)

classify_status() {
  local log_path="$1"
  local rc="$2"

  if [[ "$rc" -eq 124 || "$rc" -eq 137 ]]; then
    echo "TIMEOUT"
    return
  fi

  if grep -q '^  SKIP  ' "$log_path"; then
    echo "SKIP"
    return
  fi

  if [[ "$rc" -eq 0 ]] && grep -q '^  PASS  ' "$log_path"; then
    echo "PASS"
    return
  fi

  echo "FAIL"
}

mkdir -p "$outdir"

{
  echo "timestamp: $(date -Is)"
  echo "pwd: $(pwd)"
  echo
  echo "[uname]"
  uname -a
  echo
  echo "[lsm]"
  if [[ -r /sys/kernel/security/lsm ]]; then
    cat /sys/kernel/security/lsm
  else
    echo "<missing>"
  fi
  echo
  echo "[kernel_config]"
  if [[ -r /proc/config.gz ]]; then
    zgrep -E '^(CONFIG_BPF_LSM|CONFIG_LSM=)' /proc/config.gz || true
  elif [[ -r "/boot/config-$(uname -r)" ]]; then
    grep -E '^(CONFIG_BPF_LSM|CONFIG_LSM=)' "/boot/config-$(uname -r)" || true
  else
    echo "<unavailable>"
  fi
} >"$runtime_log" 2>&1

: >"$all_log"
{
  echo "=== runtime_check ==="
  cat "$runtime_log"
  echo
} >>"$all_log"

printf "test\tstatus\trc\tlog\n" >"$summary_tsv"

for t in "${types[@]}"; do
  bin="./tests/unittest/build/rejit_hotswap_${t}"
  log="$outdir/rejit_hotswap_${t}.log"

  (
    echo "command: $bin $progs_dir"
    echo "started_at: $(date -Is)"
    timeout 120s "$bin" "$progs_dir"
    rc=$?
    echo
    echo "finished_at: $(date -Is)"
    echo "exit_code: $rc"
    exit "$rc"
  ) >"$log" 2>&1
  rc=$?
  status="$(classify_status "$log" "$rc")"

  printf "%s\t%s\t%s\t%s\n" "$t" "$status" "$rc" "$log" >>"$summary_tsv"

  {
    echo "=== $t ==="
    cat "$log"
    echo
    echo "status: $status"
    echo
  } >>"$all_log"

  echo "=== $t ==="
  cat "$log"
  echo
  echo "status: $status"
  echo
done

echo "=== summary ==="
cat "$summary_tsv"
