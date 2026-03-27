#!/usr/bin/env bash
set -euo pipefail

/home/yunwei37/workspace/bpf-benchmark/module/load_all.sh 2>/dev/null || true
rm -rf /sys/fs/bpf/katran_dbg
mkdir -p /sys/fs/bpf/katran_dbg

bpftool prog loadall /home/yunwei37/workspace/bpf-benchmark/corpus/build/katran/balancer.bpf.o /sys/fs/bpf/katran_dbg type xdp
prog_id="$(bpftool prog show pinned /sys/fs/bpf/katran_dbg/balancer_ingress | sed -n 's/^\([0-9][0-9]*\):.*/\1/p' | head -1)"
export PROG_ID="$prog_id"

/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon serve --socket /tmp/bpfrejit-katran-debug.sock >/tmp/bpfrejit-katran-debug.log 2>&1 &
daemon_pid=$!
cleanup() {
  kill "$daemon_pid" >/dev/null 2>&1 || true
  wait "$daemon_pid" >/dev/null 2>&1 || true
  rm -rf /sys/fs/bpf/katran_dbg
}
trap cleanup EXIT
sleep 1

python3 - <<'PY'
import json
import os
import socket

prog_id = int(os.environ["PROG_ID"])
req = {"cmd": "optimize", "prog_id": prog_id}
s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
s.connect("/tmp/bpfrejit-katran-debug.sock")
s.sendall((json.dumps(req) + "\n").encode())
chunks = []
while True:
    data = s.recv(65536)
    if not data:
        break
    chunks.append(data)
    if b"\n" in data:
        break
resp = b"".join(chunks).split(b"\n", 1)[0]
out = "/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260327/katran_balancer_optimize_raw_20260327.json"
with open(out, "wb") as fh:
    fh.write(resp)
print(resp.decode())
PY
