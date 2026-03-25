#!/bin/sh
set -eu

cd /home/yunwei37/workspace/bpf-benchmark

OUT_DIR=/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260324/static_verify_prefix
mkdir -p "$OUT_DIR"
rm -f "$OUT_DIR"/*.json "$OUT_DIR"/*.log 2>/dev/null || true

for n in 1 2 4 8 12 16 20 24 28 32 40 48 56 62; do
	echo "=== static_verify prefix max_objects=$n ==="
	out="$OUT_DIR/max_${n}.json"
	log="$OUT_DIR/max_${n}.daemon.log"
	if PYTHONFAULTHANDLER=1 python3 /home/yunwei37/workspace/bpf-benchmark/daemon/tests/static_verify.py \
		--daemon-binary /home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon \
		--output "$out" \
		--daemon-log "$log" \
		--mode micro \
		--max-objects "$n"; then
		echo "PASS max_objects=$n"
	else
		rc=$?
		echo "FAIL max_objects=$n rc=$rc"
		exit "$rc"
	fi
done
