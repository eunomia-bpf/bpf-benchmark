#!/bin/bash
# Dump a named map from inside the app's container, bypassing the shim's 64 KiB cap.
#
# The shim's map snapshot refuses any dump over 64 KiB
# (bpfopt/shim/shim_snapshot.h:583). A per-CPU map of 99 entries is 34 KB at four
# CPUs and 68 KB at eight, so at the VM_CPUS=8 the timing runs use, OTel's metrics
# map is skipped and the counters never reach the artifacts. bpftool has no such
# limit, and the app's maps are in the guest's own BPF namespace, so this finds the
# map by name inside the container and dumps it directly.
#
# Usage (inside the guest): map-dump.sh <map-name> <out-dir> [timeout-seconds]
set -eu

MAP_NAME=${1:?map name, e.g. metrics}
OUT=${2:?output directory the host can read}
TIMEOUT=${3:-900}

install -d "$OUT"
deadline=$(( $(date +%s) + TIMEOUT ))
while [ "$(date +%s)" -lt "$deadline" ]; do
    for cid in $(docker ps -q 2>/dev/null); do
        # The application's maps exist only while it is running.
        if docker exec "$cid" python3 -c "import sys; sys.exit(0)" 2>/dev/null; then
            got=$(docker exec "$cid" sh -c "
                bt=\$(command -v bpftool || true)
                [ -n \"\$bt\" ] || bt=/usr/local/sbin/bpftool
                [ -x \"\$bt\" ] || bt=/usr/sbin/bpftool
                [ -x \"\$bt\" ] || exit 2
                for m in \$(\$bt -j map show 2>/dev/null | python3 -c '
import json,sys
try: maps=json.load(sys.stdin)
except Exception: sys.exit(0)
for m in maps:
    if m.get(\"name\")==\"$MAP_NAME\": print(m.get(\"id\"))
'); do
                    \$bt map dump id \$m --json && exit 0
                done
                exit 1" 2>/dev/null) || true
            if [ -n "${got:-}" ]; then
                printf '%s\n' "$got" > "$OUT/$MAP_NAME.json"
                echo "map-dump: wrote $OUT/$MAP_NAME.json ($(printf '%s' "$got" | wc -c) bytes)"
                exit 0
            fi
        fi
    done
    sleep 2
done
echo "map-dump: $MAP_NAME not found within ${TIMEOUT}s" >&2
exit 1