#!/usr/bin/env bash
set -euo pipefail

cd /home/yunwei37/workspace/bpf-benchmark

dmesg -w | rg --line-buffered 'rejit-scx-debug|MARK before_owner_prog|MARK after_owner_prog' &
DMESG_PID=$!
trap 'kill "$DMESG_PID" 2>/dev/null || true' EXIT

exec python3 -u docs/tmp/20260325/debug_scx_sequence.py \
  --mode manual-owner-id-loop \
  --find-iterations 1 \
  --load-timeout 20 \
  "$@"
