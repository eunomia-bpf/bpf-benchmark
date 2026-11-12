#!/bin/bash
# Read an application's own map counters while an arm is still running.
#
# The shim snapshots maps when a program loads, so the per-CPU counters an
# equal-work check wants read zero in those snapshots; and a per-CPU map
# multiplies its JSON by the guest's CPU count, so a large one can also exceed
# the 64 KiB dump limit. The shim has an on-demand command the framework never
# calls at arm end: `snapshot_maps` with an output_dir, over the app's own socket
# at $BPFREJIT_SHIM_SOCK_DIR/shim-<pid>.sock (bpfopt/shim/libbpfrejit_shim.c:1466,
# default /var/run/bpfrejit).
#
# The app runs inside the runtime container, so its socket is inside that
# container's filesystem and a path in the guest will not see it. This enters the
# container with docker exec, finds the socket, and sends the command. /workspaces
# is mounted on both sides, so the snapshot lands where the host can read it.
#
# Usage (inside the guest): arm-end-counters.sh <app-name-substring> <output-dir> [timeout]
set -eu

NAME=${1:?application name substring, e.g. otelcol}
OUT=${2:?output directory, a path the host can read}
TIMEOUT=${3:-600}

deadline=$(( $(date +%s) + TIMEOUT ))
killed=0
while [ "$(date +%s)" -lt "$deadline" ]; do
    for cid in $(docker ps -q 2>/dev/null); do
        # The socket belongs to the app process inside this container.
        sock=$(docker exec "$cid" sh -c 'for d in "${BPFREJIT_SHIM_SOCK_DIR:-/var/run/bpfrejit}" /tmp; do
            ls "$d"/shim-*.sock 2>/dev/null | head -1 && break; done' 2>/dev/null | head -1)
        if [ -n "${sock:-}" ]; then
            echo "arm-end: container $cid socket $sock"
            docker exec "$cid" python3 - "$sock" "$OUT" <<'PYEOF'
import json, os, socket, sys

path, out = sys.argv[1], sys.argv[2]
os.makedirs(out, exist_ok=True)
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
text = reply.decode(errors="replace").strip()
print(text if text else "(empty reply)")
PYEOF
            rc=$?
            if [ "$rc" -ne 0 ]; then echo "arm-end: snapshot command failed rc=$rc" >&2; fi
            echo "arm-end: snapshot under $OUT"
            exit 0
        fi
    done
    sleep 1
done
echo "arm-end: no shim socket within ${TIMEOUT}s" >&2
exit 1
