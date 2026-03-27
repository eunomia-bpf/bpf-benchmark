#!/usr/bin/env bash
set -euo pipefail

REPO_ROOT="/home/yunwei37/workspace/bpf-benchmark"
OUT_DIR="$REPO_ROOT/docs/tmp/20260326/probe_outputs"
OBJ="$REPO_ROOT/docs/tmp/20260326/map_inline_array_positive_probe.bpf.o"
DAEMON="$REPO_ROOT/daemon/target/release/bpfrejit-daemon"
PIN_ROOT="/sys/fs/bpf/map_inline_array_positive_probe"

mkdir -p "$OUT_DIR"
rm -rf "$PIN_ROOT"
mkdir -p "$PIN_ROOT/progs" "$PIN_ROOT/maps"

bpftool prog loadall "$OBJ" "$PIN_ROOT/progs" type xdp pinmaps "$PIN_ROOT/maps"
bpftool map update pinned "$PIN_ROOT/maps/cfg_map" \
	key hex 00 00 00 00 \
	value hex 11 11 11 11 00 00 00 00 22 22 22 22 00 00 00 00
bpftool map lookup pinned "$PIN_ROOT/maps/cfg_map" key hex 00 00 00 00 \
	>"$OUT_DIR/map_inline_array_positive_probe.map_lookup.txt"

PROG_PIN="$(find "$PIN_ROOT/progs" -maxdepth 1 -type f | sort | head -n 1)"
if [[ -z "$PROG_PIN" ]]; then
	echo "no pinned program found under $PIN_ROOT/progs" >&2
	exit 1
fi

PROG_ID="$(bpftool prog show pinned "$PROG_PIN" | awk -F: 'NR==1 { gsub(/^[[:space:]]+/, "", $1); print $1 }')"
if [[ -z "$PROG_ID" ]]; then
	echo "failed to resolve prog_id for $PROG_PIN" >&2
	exit 1
fi

{
	echo "object=$OBJ"
	echo "prog_pin=$PROG_PIN"
	echo "prog_id=$PROG_ID"
} >"$OUT_DIR/map_inline_array_positive_probe.meta.txt"

"$DAEMON" apply "$PROG_ID" \
	>"$OUT_DIR/map_inline_array_positive_probe.apply.stdout" \
	2>"$OUT_DIR/map_inline_array_positive_probe.apply.stderr"

"$DAEMON" apply-all \
	>"$OUT_DIR/map_inline_array_positive_probe.apply_all.stdout" \
	2>"$OUT_DIR/map_inline_array_positive_probe.apply_all.stderr"

bpftool prog show pinned "$PROG_PIN" >"$OUT_DIR/map_inline_array_positive_probe.prog_show.txt"

rm -rf "$PIN_ROOT"
