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
            docker exec -i "$cid" python3 - "$sock" "$OUT" <<'PYEOF'
import json, os, socket, sys

path, out = sys.argv[1], sys.argv[2]
os.makedirs(out, exist_ok=True)


def ask(sock_path, payload, limit=1 << 22):
    """One command over the shim socket, with the reply it sends back."""
    s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    s.connect(sock_path)
    s.sendall((json.dumps(payload) + "\n").encode())
    buf = b""
    while True:
        chunk = s.recv(65536)
        if not chunk:
            break
        buf += chunk
        if b"\n" in buf or len(buf) > limit:
            break
    s.close()
    return buf.decode(errors="replace").strip()


# What does the shim hold right now? `dump_state` lists the program table, which
# is what snapshot_maps filters; asking first turns "nothing was written" into a
# countable answer.
state = ask(path, {"cmd": "dump_state"})
open(os.path.join(out, "dump_state.json"), "w").write(state + "\n")
print("state:", (state[:200] if state else "(empty)"))

reply = ask(path, {"cmd": "snapshot_maps", "output_dir": out})
print("snapshot:", (reply if reply else "(empty reply)"))
PYEOF
            rc=$?
            if [ "$rc" -ne 0 ]; then echo "arm-end: snapshot command failed rc=$rc" >&2; fi
            # Count what landed, so an empty reply is distinguishable from a
            # successful one that found no program to describe.
            echo "arm-end: $(find "$OUT" -name 'ref.json' 2>/dev/null | wc -l) program refs, $(find "$OUT" -name '*.dump.json' 2>/dev/null | wc -l) map dumps"
            echo "arm-end: snapshot under $OUT"
            exit 0
        fi
    done
    sleep 1
done
echo "arm-end: no shim socket within ${TIMEOUT}s" >&2
exit 1
