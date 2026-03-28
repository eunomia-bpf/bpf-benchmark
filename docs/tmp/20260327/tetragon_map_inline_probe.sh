#!/bin/bash
set -euo pipefail

cd /home/yunwei37/workspace/bpf-benchmark

dmesg -C >/dev/null 2>&1 || true

python3 e2e/run.py tetragon \
  --config /home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/config_execve_rate.yaml \
  --duration 3 \
  --rejit-passes map_inline \
  --output-json /tmp/tetragon_map_inline_probe.json \
  --output-md /tmp/tetragon_map_inline_probe.md || true

echo "=== RESULT JSON ==="
python3 - <<'PY'
import json
from pathlib import Path

path = Path("/tmp/tetragon_map_inline_probe.json")
if not path.exists():
    print("missing /tmp/tetragon_map_inline_probe.json")
    raise SystemExit(0)

payload = json.loads(path.read_text())
rejit = payload.get("rejit_result", {})
per_program = rejit.get("per_program", {})
for prog_id, info in sorted(per_program.items(), key=lambda item: int(item[0])):
    debug = info.get("debug_result") or {}
    program = debug.get("program") or {}
    attempts = debug.get("attempts") or []
    first = attempts[0] if attempts else {}
    print(
        json.dumps(
            {
                "prog_id": prog_id,
                "prog_name": program.get("prog_name"),
                "result": first.get("result"),
                "attributed_pass": first.get("attributed_pass"),
                "final_disabled_passes": (debug.get("summary") or {}).get(
                    "final_disabled_passes"
                ),
            },
            ensure_ascii=False,
        )
    )
PY

echo "=== DMESG ==="
dmesg | tail -n 120
