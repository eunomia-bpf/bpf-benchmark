#!/usr/bin/env python3
"""Compare Tetragon's per-event-type counters between the eBPF and native phases.

Native code installs only at post_rejit (the run's baseline shim log shows 0
"replaced prog=", post_rejit shows the replacement count), so one corpus run holds both
arms. tg_stats_map is u64 sent_failed[256][7] indexed by msg_op x errno and is written
only when ringbuf_output() fails, so it counts events that met a full ring, per type.

Pass two dumps per phase; the script reports the delta across each phase so the two
windows are comparable.

Usage: tetragon-phase-counters.py <run-dir>
"""
from __future__ import annotations

import collections
import json
import struct
import sys
from pathlib import Path

# vendor/bpf/tetragon/bpf/lib/msg_types.h
MSG_OP = {
    0: "UNDEF", 5: "EXECVE", 7: "EXIT", 13: "GENERIC_KPROBE",
    14: "GENERIC_TRACEPOINT", 15: "GENERIC_UPROBE", 16: "GENERIC_LSM",
    23: "CLONE", 24: "DATA", 25: "CGROUP", 26: "LOADER", 27: "THROTTLE",
    28: "GENERIC_USDT",
}
# vendor/bpf/tetragon/bpf/lib/process.h: SENT_FAILED_*
ERRNO = {0: "UNKNOWN", 1: "ENOENT", 2: "E2BIG", 3: "EBUSY", 4: "EINVAL",
         5: "ENOSPC", 6: "EAGAIN"}
SLOTS = 7
VALUE_BYTES = 256 * SLOTS * 8


def read_dump(path: Path) -> collections.Counter:
    text = path.read_text()
    entry = json.loads(text[: text.rfind("]") + 1])[0]
    totals: collections.Counter = collections.Counter()
    for cpu in entry["values"]:
        raw = bytes(int(x, 16) for x in cpu["value"])
        if len(raw) != VALUE_BYTES:
            raise ValueError(f"{path}: {len(raw)} value bytes, expected {VALUE_BYTES}")
        for offset in range(0, len(raw), 8):
            count = struct.unpack("<Q", raw[offset : offset + 8])[0]
            if count:
                cell = offset // 8
                totals[(cell // SLOTS, cell % SLOTS)] += count
    return totals


def phase_deltas(run: Path, phase: str) -> collections.Counter | None:
    dumps = sorted(run.glob(f"{phase}-*/tg_stats_map.json"))
    if len(dumps) < 2:
        return None
    first, last = read_dump(dumps[0]), read_dump(dumps[-1])
    return collections.Counter({k: last[k] - first.get(k, 0) for k in last})


def main() -> int:
    if len(sys.argv) != 2:
        print(__doc__.strip().splitlines()[-1])
        return 2
    run = Path(sys.argv[1])
    ebpf, native = phase_deltas(run, "baseline"), phase_deltas(run, "post_rejit")
    if ebpf is None or native is None:
        print("need two dumps per phase: <phase>-1, <phase>-2", file=sys.stderr)
        return 1

    print(f'{"type/errno":32} {"eBPF":>14} {"native":>14} {"ratio":>8}')
    for key in sorted(set(ebpf) | set(native), key=lambda k: -max(ebpf[k], native[k])):
        a, b = ebpf[key], native[key]
        label = f"{MSG_OP.get(key[0], key[0])}/{ERRNO.get(key[1], key[1])}"
        ratio = f"{b / a:.3f}" if a else "--"
        print(f"{label:32} {a:14,} {b:14,} {ratio:>8}")

    # Erasure check: a counter whose writer was replaced cannot be compared. Report it
    # rather than let the ratio be read as measured.
    print("\nA type produced by a REPLACED program has its counter written by code the")
    print("replacement removed. Check the run's shim log before quoting any ratio:")
    print(f"  grep -c 'replaced prog=' {run}/../*/details/shim-logs/*post_rejit.log")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
