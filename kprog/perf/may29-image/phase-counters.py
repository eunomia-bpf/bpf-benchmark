#!/usr/bin/env python3
"""Compare OTel's metrics map between the eBPF and native phases of one run.

Native code installs only at post_rejit (baseline shim log: 0 "replaced prog=",
post_rejit: 13), so one corpus run holds both arms: baseline is eBPF, post_rejit is
native. This prints the counters side by side and flags the signature of an arm that
stopped unwinding (zero attempts with a rising error count).

Usage: phase-counters.py <run-dir-with-baseline-and-post_rejit-dumps>
"""
from __future__ import annotations

import json
import sys
from pathlib import Path

METRIC_IDS = Path("/tmp/otel-metric-ids.json")

# The counters that answer "did this arm do work", as opposed to "did it run".
QUESTION = (
    "UnwindNativeAttempts",
    "UnwindNativeFrames",
    "UnwindCallInterpreter",
    "UnwindV8Frames",
    "UnwindPHPFrames",
    "UnwindRubyFrames",
    "UnwindNativeErrReadKernelModeRegs",
    "ErrEmptyStack",
    "MaxTailCalls",
)


def load_ids() -> dict[str, str]:
    if METRIC_IDS.exists():
        return json.loads(METRIC_IDS.read_text())
    types_h = Path(__file__).resolve().parents[2] / "vendor/bpf/otel/support/ebpf/types.h"
    ids: dict[str, str] = {}
    next_id = 0
    for line in types_h.read_text().splitlines():
        line = line.strip().rstrip(",")
        if line.startswith("metricID_"):
            ids[str(next_id)] = line
            next_id += 1
    return ids


def read_dump(path: Path, ids: dict[str, str]) -> dict[str, int]:
    text = path.read_text()
    entries = json.loads(text[: text.rfind("]") + 1])
    totals: dict[str, int] = {}
    for entry in entries:
        key = int("".join(reversed([x.replace("0x", "") for x in entry["key"]])), 16)
        value = sum(
            int("".join(reversed([x.replace("0x", "") for x in cpu["value"]])), 16)
            for cpu in entry["values"]
        )
        totals[ids.get(str(key), str(key))] = value
    return totals


def main() -> int:
    if len(sys.argv) != 2:
        print(__doc__.strip().splitlines()[-1])
        return 2
    run = Path(sys.argv[1])

    # Two dumps per phase is the normal shape; take the last of each.
    phase_dumps = {}
    for phase in ("baseline", "post_rejit"):
        cands = sorted(run.glob(f"{phase}*/metrics.json"))
        if cands:
            phase_dumps[phase] = cands[-1]
    missing = [p for p in ("baseline", "post_rejit") if p not in phase_dumps]
    if missing:
        print(f"missing dumps for: {', '.join(missing)}", file=sys.stderr)
        return 1

    ids = load_ids()
    ebpf = read_dump(phase_dumps["baseline"], ids)
    native = read_dump(phase_dumps["post_rejit"], ids)

    print(f"eBPF   {phase_dumps['baseline']}")
    print(f"native {phase_dumps['post_rejit']}")
    print(f'\n{"metric":36} {"eBPF":>14} {"native":>14} {"ratio":>8}')
    for name in QUESTION:
        key = f"metricID_{name}"
        a, b = ebpf.get(key, 0), native.get(key, 0)
        ratio = f"{b / a:.3f}" if a else ("--" if not b else "inf")
        print(f"{name:36} {a:14,} {b:14,} {ratio:>8}")

    attempts = native.get("metricID_UnwindNativeAttempts", 0)
    empty = native.get("metricID_ErrEmptyStack", 0)
    if attempts == 0 and empty:
        print(
            f"\nWARNING: the native arm pushed no frames and logged {empty:,} empty stacks."
            "\n         It ran, but it did not unwind. Counts here are not comparable"
            "\n         work for work."
        )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
