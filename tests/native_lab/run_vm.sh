#!/bin/sh
# In-VM driver script: load module + run poc.
# This file is --exec'd by vng. It must be self-contained (no project
# Python venv etc.); just shell + the .ko + the poc binary.
set -eu

KO=/home/yunwei37/workspace/bpf-benchmark/.cache/repo-build/host/kinsn/x86_64/bpf_x86_native_lab.ko
POC=/home/yunwei37/workspace/bpf-benchmark/tests/native_lab/poc

echo "[vm] kernel: $(uname -r)"

if [ ! -f "$KO" ]; then
    echo "[vm] FAIL: module .ko missing at $KO" >&2
    exit 1
fi
if [ ! -x "$POC" ]; then
    echo "[vm] FAIL: poc binary missing or not executable at $POC" >&2
    exit 1
fi

echo "[vm] mounting debugfs"
mount -t debugfs none /sys/kernel/debug 2>/dev/null || true

echo "[vm] insmod $KO"
insmod "$KO"

echo "[vm] running poc (single-chunk default blob: mov eax, 42)"
"$POC"
single_rc=$?
echo "[vm] single-chunk poc exited $single_rc"

# Multi-chunk test: 195 NOPs + `mov eax, 7` (B8 07 00 00 00) = 200 bytes.
# At chunk_count = ceil(200/128) = 2 chunks (128 + 72 B), the JIT splats them
# back-to-back so the surviving rax value is 7.
TMP_BLOB=$(mktemp)
python3 -c "
import sys
data = b'\x90' * 195 + bytes([0xB8, 0x07, 0x00, 0x00, 0x00])
open('$TMP_BLOB','wb').write(data)
"
echo "[vm] running poc (multi-chunk blob: 200B, expected retval=7)"
"$POC" "$TMP_BLOB" 7
multi_rc=$?
rm -f "$TMP_BLOB"
echo "[vm] multi-chunk poc exited $multi_rc"

if [ "$single_rc" -ne 0 ] || [ "$multi_rc" -ne 0 ]; then
    exit 1
fi
