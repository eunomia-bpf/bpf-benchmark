#!/bin/bash
# Test: daemon serve mode with a live BPF program.
set -e
ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
cd "$ROOT_DIR"

PASS=0
FAIL=0
TOTAL=0
DAEMON_PID=""
HOLD_PID=""
SOCKET_DIR=""
DAEMON_SOCKET=""

report() {
    local name="$1" status="$2" detail="${3:-}"
    TOTAL=$((TOTAL + 1))
    if [ "$status" = "PASS" ]; then
        PASS=$((PASS + 1))
        echo "  [$status] $name"
    else
        FAIL=$((FAIL + 1))
        echo "  [$status] $name: $detail"
    fi
}

cleanup() {
    if [ -n "$DAEMON_PID" ] && kill -0 "$DAEMON_PID" 2>/dev/null; then
        kill "$DAEMON_PID"
        wait "$DAEMON_PID" || true
    fi
    if [ -n "$HOLD_PID" ] && kill -0 "$HOLD_PID" 2>/dev/null; then
        kill "$HOLD_PID"
        wait "$HOLD_PID" || true
    fi
    if [ -n "$SOCKET_DIR" ] && [ -d "$SOCKET_DIR" ]; then
        rm -rf "$SOCKET_DIR"
    fi
}
trap cleanup EXIT

daemon_request() {
    local payload="$1"
    python3 - "$DAEMON_SOCKET" "$payload" <<'PY'
import socket
import sys

socket_path = sys.argv[1]
payload = sys.argv[2]
client = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
client.connect(socket_path)
client.sendall((payload + "\n").encode())
chunks = []
while True:
    chunk = client.recv(4096)
    if not chunk:
        break
    chunks.append(chunk)
    if b"\n" in chunk:
        break
client.close()
sys.stdout.write(b"".join(chunks).decode().strip())
PY
}

echo "================================================================"
echo "=== BpfReJIT v2 Serve Integration Tests ==="
echo "================================================================"

echo "--- Loading load_byte_recompose.bpf.o and holding it ---"
HOLD_PROG="${ROOT_DIR}/tests/helpers/build/hold_bpf_prog"
"$HOLD_PROG" "${ROOT_DIR}/micro/programs/load_byte_recompose.bpf.o" 120 &
HOLD_PID=$!
sleep 2

if kill -0 "$HOLD_PID" 2>/dev/null; then
    report "0: BPF program stays loaded" "PASS"
else
    report "0: BPF program stays loaded" "FAIL" "process exited"
    exit 1
fi

SOCKET_DIR="$(mktemp -d)"
DAEMON_SOCKET="$SOCKET_DIR/bpfrejit.sock"

echo "--- Starting daemon serve ---"
./daemon/target/release/bpfrejit-daemon serve --socket "$DAEMON_SOCKET" &
DAEMON_PID=$!
sleep 1

if [ ! -S "$DAEMON_SOCKET" ]; then
    report "1: daemon serve starts" "FAIL" "socket not created"
    exit 1
fi
report "1: daemon serve starts" "PASS"

echo "--- daemon status ---"
STATUS_OUTPUT="$(daemon_request '{"cmd":"status"}')"
echo "$STATUS_OUTPUT"
if printf '%s\n' "$STATUS_OUTPUT" | python3 -c 'import json,sys; payload=json.load(sys.stdin); raise SystemExit(0 if payload.get("status")=="ok" else 1)'; then
    report "2: daemon status request" "PASS"
else
    report "2: daemon status request" "FAIL" "$STATUS_OUTPUT"
fi

PROG_ID="$(bpftool -j -p prog show | python3 -c 'import json,sys; payload=json.load(sys.stdin); ids=[int(entry.get("id", 0)) for entry in payload if isinstance(entry, dict) and int(entry.get("id", 0)) > 0]; print(max(ids) if ids else "")')"
if [ -z "$PROG_ID" ]; then
    report "3: locate live prog_id" "FAIL" "bpftool returned no live program ids"
    exit 1
fi
report "3: locate live prog_id=$PROG_ID" "PASS"

echo "--- daemon optimize dry-run ---"
DRY_RUN_OUTPUT="$(daemon_request "{\"cmd\":\"optimize\",\"prog_id\":${PROG_ID},\"dry_run\":true}")"
echo "$DRY_RUN_OUTPUT"
if printf '%s\n' "$DRY_RUN_OUTPUT" | python3 -c 'import json,sys; payload=json.load(sys.stdin); summary=payload.get("summary") or {}; ok=payload.get("status")=="ok" and "total_sites_applied" in summary; raise SystemExit(0 if ok else 1)'; then
    report "4: daemon dry-run optimize request" "PASS"
else
    report "4: daemon dry-run optimize request" "FAIL" "$DRY_RUN_OUTPUT"
fi

echo "--- daemon optimize dry-run with explicit enabled_passes ---"
PASS_OUTPUT="$(daemon_request "{\"cmd\":\"optimize\",\"prog_id\":${PROG_ID},\"dry_run\":true,\"enabled_passes\":[\"wide_mem\"]}")"
echo "$PASS_OUTPUT"
if printf '%s\n' "$PASS_OUTPUT" | python3 -c 'import json,sys; payload=json.load(sys.stdin); raise SystemExit(0 if payload.get("status")=="ok" else 1)'; then
    report "5: daemon request accepts enabled_passes override" "PASS"
else
    report "5: daemon request accepts enabled_passes override" "FAIL" "$PASS_OUTPUT"
fi

WARNINGS=$(dmesg | grep -c -E "WARNING|BUG|Oops" || true)
if [ "$WARNINGS" -eq 0 ] 2>/dev/null; then
    report "6: no kernel warnings" "PASS"
else
    WARN_DETAIL=$(dmesg | grep -E "WARNING|BUG|Oops" | head -3)
    report "6: no kernel warnings" "FAIL" "$WARN_DETAIL"
fi

echo ""
echo "================================================================"
echo "=== SUMMARY: $PASS/$TOTAL passed, $FAIL failed ==="
echo "================================================================"

if [ $FAIL -gt 0 ]; then
    exit 1
fi
