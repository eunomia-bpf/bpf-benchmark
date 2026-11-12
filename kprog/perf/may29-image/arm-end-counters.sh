#!/bin/bash
# Read an application's own map counters at the END of a measurement arm.
#
# The shim snapshots maps when a program loads, so the per-CPU counters an
# equal-work check wants are all zero in those snapshots -- and the bigger ones
# are dropped anyway, because the shim refuses a dump over 64 KiB
# (bpfopt/shim/shim_snapshot.h:583) and a per-CPU map multiplies by the CPU count.
#
# The shim already has an on-demand command for this, so nothing in the framework
# changes: send `snapshot_maps` to the app's shim socket, which is
# /tmp/bpfrejit-shim-<pid>.sock inside the guest.
#
# Usage (inside the guest): arm-end-counters.sh <app-pid> <output-dir>
set -eu

PID=${1:?application pid}
OUT=${2:?output directory}
SOCK=/tmp/bpfrejit-shim-$PID.sock

if [ ! -S "$SOCK" ]; then
    # The shim falls back to a directory of its own when it cannot use /tmp; find
    # the socket for this pid anywhere it could have landed.
    SOCK=$(ls /tmp/bpfrejit-shim-$PID.sock /run/*/shim-$PID.sock 2>/dev/null | head -1 || true)
fi
if [ ! -S "${SOCK:-}" ]; then
    echo "arm-end: no shim socket for pid $PID" >&2
    exit 1
fi

install -d "$OUT"
printf '{"cmd":"snapshot_maps","output_dir":"%s"}\n' "$OUT" | \
    socat - "UNIX-CONNECT:$SOCK" 2>/dev/null || \
    python3 - "$SOCK" "$OUT" <<'PY'
import json, socket, sys

path, out = sys.argv[1], sys.argv[2]
sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
sock.connect(path)
sock.sendall((json.dumps({"cmd": "snapshot_maps", "output_dir": out}) + "\n").encode())
reply = b""
while True:
    chunk = sock.recv(4096)
    if not chunk:
        break
    reply += chunk
    if b"\n" in reply:
        break
sock.close()
print(reply.decode(errors="replace").strip())
PY

echo "arm-end: snapshot written under $OUT"