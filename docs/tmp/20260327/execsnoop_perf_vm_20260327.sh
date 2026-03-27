#!/usr/bin/env bash
set -euo pipefail

REPO=/home/yunwei37/workspace/bpf-benchmark
DAEMON="$REPO/daemon/target/release/bpfrejit-daemon"
TOOL="$REPO/runner/repos/bcc/libbpf-tools/execsnoop"
SOCK=/tmp/bpfrejit.sock
RESULTS=/tmp/execsnoop_perf_results.jsonl

cleanup_mode() {
  set +e
  if [ -n "${TOOL_PID:-}" ]; then
    kill "$TOOL_PID" 2>/dev/null || true
    wait "$TOOL_PID" 2>/dev/null || true
    TOOL_PID=
  fi
  if [ -n "${DAEMON_PID:-}" ]; then
    kill "$DAEMON_PID" 2>/dev/null || true
    wait "$DAEMON_PID" 2>/dev/null || true
    DAEMON_PID=
  fi
  rm -f "$SOCK"
}

cleanup_all() {
  cleanup_mode
}
trap cleanup_all EXIT

TOOL_PID=
DAEMON_PID=
rm -f "$RESULTS" /tmp/execsnoop_perf_*.out /tmp/execsnoop_perf_*.err \
  /tmp/execsnoop_enumerate_before /tmp/execsnoop_enumerate_loaded

command -v setpriv >/dev/null
command -v stress-ng >/dev/null

wait_for_daemon() {
  python3 - <<'PY'
import json
import os
import socket
import sys
import time

sock = "/tmp/bpfrejit.sock"
for _ in range(300):
    if os.path.exists(sock):
        try:
            client = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
            client.connect(sock)
            client.sendall(b'{"cmd":"status"}\n')
            data = b""
            while True:
                chunk = client.recv(4096)
                if not chunk:
                    break
                data += chunk
                if b"\n" in chunk:
                    break
            client.close()
            payload = json.loads(data.decode().strip())
            if payload.get("status") == "ok":
                sys.exit(0)
        except OSError:
            time.sleep(0.1)
    else:
        time.sleep(0.1)
sys.exit("daemon socket never became ready")
PY
}

run_stress() {
  local mode="$1"
  local round="$2"
  local outfile="/tmp/execsnoop_perf_${mode}_${round}.out"
  cd /tmp
  setpriv --reuid 65534 --regid 65534 --clear-groups \
    stress-ng --exec 2 --exec-method execve --timeout 10 --metrics-brief \
    >"$outfile" 2>&1
  cd "$REPO"
  python3 - "$mode" "$round" "$outfile" <<'PY'
import json
import re
import sys
from pathlib import Path

mode = sys.argv[1]
round_id = int(sys.argv[2])
outfile = Path(sys.argv[3])
lines = outfile.read_text().splitlines()
row = None
for line in lines:
    if " metrc: " in line and " exec " in line:
        row = line
if row is None:
    raise SystemExit(f"missing stress-ng exec metrics in {outfile}")
match = re.search(
    r"exec\s+(\d+)\s+([0-9.]+)\s+([0-9.]+)\s+([0-9.]+)\s+([0-9.]+)\s+([0-9.]+)",
    row,
)
if match is None:
    raise SystemExit(f"unable to parse stress-ng row: {row}")
payload = {
    "mode": mode,
    "round": round_id,
    "bogo_ops": int(match.group(1)),
    "real_time_s": float(match.group(2)),
    "usr_time_s": float(match.group(3)),
    "sys_time_s": float(match.group(4)),
    "bogo_ops_per_real_s": float(match.group(5)),
    "bogo_ops_per_cpu_s": float(match.group(6)),
}
print(json.dumps(payload))
PY
}

start_stock_tool() {
  "$TOOL" -u 65534 >/dev/null 2>/tmp/execsnoop_perf_stock.err &
  TOOL_PID=$!
  sleep 2
}

start_optimized_tool() {
  "$DAEMON" serve --socket "$SOCK" >/tmp/execsnoop_perf_daemon.err 2>&1 &
  DAEMON_PID=$!
  wait_for_daemon
  "$DAEMON" enumerate >/tmp/execsnoop_enumerate_before
  "$TOOL" -u 65534 >/dev/null 2>/tmp/execsnoop_perf_opt.err &
  TOOL_PID=$!
  sleep 2
  "$DAEMON" enumerate >/tmp/execsnoop_enumerate_loaded
  python3 - <<'PY'
import json
import socket
from pathlib import Path

def parse(path: str):
    records = {}
    for line in Path(path).read_text().splitlines():
        text = line.rstrip()
        if not text or text.startswith("ID") or set(text) == {"-"}:
            continue
        fields = text.split(None, 4)
        if len(fields) < 4 or not fields[0].isdigit():
            continue
        prog_id = int(fields[0])
        records[prog_id] = {
            "prog_id": prog_id,
            "prog_type": int(fields[1]),
            "insn_count": int(fields[2]),
            "name": fields[3],
            "site_summary": fields[4] if len(fields) >= 5 else "-",
        }
    return records

before = parse("/tmp/execsnoop_enumerate_before")
loaded = parse("/tmp/execsnoop_enumerate_loaded")
new_ids = sorted(set(loaded) - set(before))
if not new_ids:
    raise SystemExit("no new execsnoop program ids found")
results = []
for prog_id in new_ids:
    payload = {
        "cmd": "optimize",
        "prog_id": prog_id,
        "enabled_passes": ["map_inline", "const_prop", "dce"],
    }
    client = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    client.connect("/tmp/bpfrejit.sock")
    client.sendall((json.dumps(payload) + "\n").encode())
    data = b""
    while True:
        chunk = client.recv(65536)
        if not chunk:
            break
        data += chunk
        if b"\n" in chunk:
            break
    client.close()
    line = data.decode().strip()
    results.append(json.loads(line))

for result in results:
    if result.get("status") != "ok":
        raise SystemExit(f"optimize failed: {result}")
PY
  sleep 1
}

for round in 1 2 3 4 5; do
  run_stress "no_trace" "$round" | tee -a "$RESULTS"

  cleanup_mode
  start_stock_tool
  run_stress "stock" "$round" | tee -a "$RESULTS"

  cleanup_mode
  start_optimized_tool
  run_stress "optimized" "$round" | tee -a "$RESULTS"

  cleanup_mode
done

python3 - "$RESULTS" <<'PY'
import json
import statistics
import sys
from pathlib import Path

records = [json.loads(line) for line in Path(sys.argv[1]).read_text().splitlines() if line.strip()]
by_mode = {}
for record in records:
    by_mode.setdefault(record["mode"], []).append(record)

summary = {"samples": records, "modes": {}}
for mode, items in by_mode.items():
    real = [item["bogo_ops_per_real_s"] for item in items]
    cpu = [item["bogo_ops_per_cpu_s"] for item in items]
    ops = [item["bogo_ops"] for item in items]
    steady_items = [item for item in items if int(item["round"]) >= 2]
    steady_real = [item["bogo_ops_per_real_s"] for item in steady_items]
    steady_cpu = [item["bogo_ops_per_cpu_s"] for item in steady_items]
    steady_ops = [item["bogo_ops"] for item in steady_items]
    summary["modes"][mode] = {
        "count": len(items),
        "bogo_ops": ops,
        "bogo_ops_per_real_s": real,
        "bogo_ops_per_cpu_s": cpu,
        "mean_bogo_ops": statistics.mean(ops),
        "mean_bogo_ops_per_real_s": statistics.mean(real),
        "stdev_bogo_ops_per_real_s": statistics.stdev(real) if len(real) > 1 else 0.0,
        "mean_bogo_ops_per_cpu_s": statistics.mean(cpu),
        "steady_state_rounds": [item["round"] for item in steady_items],
        "steady_state_mean_bogo_ops": statistics.mean(steady_ops),
        "steady_state_mean_bogo_ops_per_real_s": statistics.mean(steady_real),
        "steady_state_stdev_bogo_ops_per_real_s": (
            statistics.stdev(steady_real) if len(steady_real) > 1 else 0.0
        ),
        "steady_state_mean_bogo_ops_per_cpu_s": statistics.mean(steady_cpu),
    }

stock = summary["modes"]["stock"]["mean_bogo_ops_per_real_s"]
opt = summary["modes"]["optimized"]["mean_bogo_ops_per_real_s"]
base = summary["modes"]["no_trace"]["mean_bogo_ops_per_real_s"]
steady_stock = summary["modes"]["stock"]["steady_state_mean_bogo_ops_per_real_s"]
steady_opt = summary["modes"]["optimized"]["steady_state_mean_bogo_ops_per_real_s"]
steady_base = summary["modes"]["no_trace"]["steady_state_mean_bogo_ops_per_real_s"]

summary["comparisons"] = {
    "optimized_vs_stock_pct": ((opt / stock) - 1.0) * 100.0,
    "stock_vs_no_trace_pct": ((stock / base) - 1.0) * 100.0,
    "optimized_vs_no_trace_pct": ((opt / base) - 1.0) * 100.0,
    "steady_state_optimized_vs_stock_pct": ((steady_opt / steady_stock) - 1.0) * 100.0,
    "steady_state_stock_vs_no_trace_pct": ((steady_stock / steady_base) - 1.0) * 100.0,
    "steady_state_optimized_vs_no_trace_pct": ((steady_opt / steady_base) - 1.0) * 100.0,
}

print(json.dumps(summary, indent=2))
PY
