#!/bin/bash
set -euo pipefail

mountpoint -q /sys/fs/bpf || mount -t bpf bpf /sys/fs/bpf
sysctl -w kernel.bpf_stats_enabled=1 >/dev/null

ROOT=/sys/fs/bpf/bpftool_feasibility_$$
PROG_DIR="$ROOT/progs"
PACKET="$TMPDIR/simple.packet"
BPFTOOL_BIN="${BPFTOOL:-bpftool}"

mkdir -p "$PROG_DIR"
dd if=/dev/zero of="$PACKET" bs=1 count=72 status=none

cleanup() {
    rm -rf "$ROOT"
    rm -f "$PACKET"
}
trap cleanup EXIT

"$BPFTOOL_BIN" prog loadall micro/programs/simple.bpf.o "$PROG_DIR" \
    kernel_btf /sys/kernel/btf/vmlinux

echo '=== PINNED_BEFORE ==='
"$BPFTOOL_BIN" -j -p prog show pinned "$PROG_DIR/simple_xdp"

PROG_ID="$(
    "$BPFTOOL_BIN" -j -p prog show pinned "$PROG_DIR/simple_xdp" |
        python3 -c 'import json,sys; payload=json.load(sys.stdin); record=payload[0] if isinstance(payload,list) else payload; print(int(record["id"]))'
)"

echo '=== ID_AFTER_LOAD ==='
"$BPFTOOL_BIN" -j -p prog show id "$PROG_ID"

echo '=== RUN_JSON ==='
"$BPFTOOL_BIN" -j -p prog run pinned "$PROG_DIR/simple_xdp" \
    data_in "$PACKET" \
    repeat 100

echo '=== PINNED_AFTER_RUN ==='
"$BPFTOOL_BIN" -j -p prog show pinned "$PROG_DIR/simple_xdp"

echo '=== PROG_ARRAY_JSON ==='
"$BPFTOOL_BIN" map create "$ROOT/prog_array" type prog_array key 4 value 4 entries 1 name demo_prog_array
"$BPFTOOL_BIN" map update pinned "$ROOT/prog_array" key hex 00 00 00 00 value pinned "$PROG_DIR/simple_xdp"
"$BPFTOOL_BIN" -j -p map dump pinned "$ROOT/prog_array"

echo '=== MAP_OF_MAPS_JSON ==='
"$BPFTOOL_BIN" map create "$ROOT/inner" type array key 4 value 8 entries 1 name demo_inner
"$BPFTOOL_BIN" map update pinned "$ROOT/inner" key hex 00 00 00 00 value hex 2e 16 00 00 00 00 00 00
"$BPFTOOL_BIN" map create "$ROOT/outer" type array_of_maps key 4 value 4 entries 1 name demo_outer inner_map pinned "$ROOT/inner"
"$BPFTOOL_BIN" map update pinned "$ROOT/outer" key hex 00 00 00 00 value pinned "$ROOT/inner"
"$BPFTOOL_BIN" -j -p map dump pinned "$ROOT/outer"

echo '=== RUN_OVERHEAD ==='
export PIN_PATH="$PROG_DIR/simple_xdp"
export PACKET_PATH="$PACKET"
export BPFTOOL_BIN
python3 - <<'PY'
import json
import os
import statistics
import subprocess
import time

cmd = [
    os.environ["BPFTOOL_BIN"],
    "-j",
    "-p",
    "prog",
    "run",
    "pinned",
    os.environ["PIN_PATH"],
    "data_in",
    os.environ["PACKET_PATH"],
    "repeat",
    "1",
]

samples = []
for _ in range(20):
    start = time.perf_counter_ns()
    completed = subprocess.run(cmd, capture_output=True, text=True, check=True)
    end = time.perf_counter_ns()
    payload = json.loads(completed.stdout)
    wall_ns = end - start
    prog_ns = int(payload["duration"])
    samples.append((wall_ns, prog_ns))

wall = [sample[0] for sample in samples]
prog = [sample[1] for sample in samples]
overhead = [max(0, sample[0] - sample[1]) for sample in samples]

print(
    json.dumps(
        {
            "iterations": len(samples),
            "wall_ns_min": min(wall),
            "wall_ns_mean": statistics.fmean(wall),
            "wall_ns_max": max(wall),
            "prog_duration_ns_min": min(prog),
            "prog_duration_ns_mean": statistics.fmean(prog),
            "prog_duration_ns_max": max(prog),
            "approx_user_overhead_ns_min": min(overhead),
            "approx_user_overhead_ns_mean": statistics.fmean(overhead),
            "approx_user_overhead_ns_max": max(overhead),
        },
        indent=2,
    )
)
PY
