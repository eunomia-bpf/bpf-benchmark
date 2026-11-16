#!/usr/bin/env python3
"""Decode a dumped OTel metrics map into per-counter totals.

The profiler keeps its counters in a per-CPU array indexed by the
`metricID_*` enum in `vendor/bpf/otel/support/ebpf/types.h`. The shim's own
snapshot refuses maps over 64 KiB, so at the eight CPUs the timing runs use
the map is dumped from inside the guest instead (`map-dump.sh`). This reads
that dump, sums every CPU's slot, and names the ids from the enum, which is
the only place the numbering is defined.

Usage: otel-metrics.py <map-dump.json> [<map-dump.json> ...]
With two or more dumps the last is reported as a delta against the first,
which is what a before/after check needs.
"""
import json
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parents[3]
TYPES_H = ROOT / "vendor/bpf/otel/support/ebpf/types.h"

# The counters a context/unwinding check reads, in the order they matter.
WATCHED = [
    "UnwindNativeAttempts",
    "UnwindNativeFrames",
    "UnwindCallInterpreter",
    "UnwindNativeErrReadKernelModeRegs",
    "ErrEmptyStack",
]


def metric_names() -> dict[int, str]:
    """Map metricID index to its name, honoring explicit `= N` initializers.

    The ids live in one anonymous enum that starts at
    `metricID_UnwindCallInterpreter = 0`; every other member is implicit.
    """
    text = TYPES_H.read_text()
    start = text.index("metricID_UnwindCallInterpreter = 0")
    start = text.rindex("enum", 0, start)
    body = text[text.index("{", start) + 1: text.index("}", start)]
    names: dict[int, str] = {}
    next_id = 0
    for line in body.splitlines():
        line = line.split("//", 1)[0].strip().rstrip(",")
        m = re.fullmatch(r"(metricID_\w+)(?:\s*=\s*(\d+))?", line)
        if not m:
            continue
        if m.group(2) is not None:
            next_id = int(m.group(2))
        names[next_id] = m.group(1)[len("metricID_"):]
        next_id += 1
    return names


def totals(path: str) -> dict[str, int]:
    rows = json.load(open(path))
    names = metric_names()
    out: dict[str, int] = {}
    for row in rows:
        idx = row["formatted"]["key"]
        name = names.get(idx, f"metricID_{idx}")
        out[name] = sum(v["value"] for v in row["formatted"]["values"])
    return out


def image_ids(paths: list[str]) -> set[str]:
    """Image IDs recorded beside each dump.

    otel-unwind-counters.sh writes image-id.txt next to the dumps. The sole
    image is swapped between the May reference and current source during a
    round, so two dumps of the same name taken across a swap belong to
    different systems and must not be subtracted.
    """
    ids = set()
    for p in paths:
        side = pathlib.Path(p).parent / "image-id.txt"
        if side.exists():
            ids.add(side.read_text().strip())
    return ids


def main() -> int:
    paths = sys.argv[1:]
    if not paths:
        print(__doc__, file=sys.stderr)
        return 2
    ids = image_ids(paths)
    if len(ids) > 1:
        print(f"dumps come from different images: {sorted(ids)}", file=sys.stderr)
        return 1
    series = [(p, totals(p)) for p in paths]
    if len(series) == 1:
        p, t = series[0]
        print(p)
        for name in WATCHED:
            print(f"  {name:36s} {t.get(name, 0):>15,}")
        return 0
    (p0, a), (p1, b) = series[0], series[-1]
    print(f"{p0}\n-> {p1}" + (f"\nimage {ids.pop()}" if ids else ""))
    for name in WATCHED:
        print(f"  {name:36s} {b.get(name, 0) - a.get(name, 0):>15,}")
    return 0


if __name__ == "__main__":
    sys.exit(main())