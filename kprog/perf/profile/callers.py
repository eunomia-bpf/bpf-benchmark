#!/usr/bin/env python3
"""Who calls a given symbol, per arm, from the phase profile's callchains.

The per-program table says where the CPU was; for an out-of-line kernel entry such
as memset it does not say who got there.  This walks each sample's callchain (the
phase profile records with -g) and reports the frames below the named symbol, so a
cost that belongs to a BPF program's body shows up as that program, and a cost that
belongs to ordinary kernel work shows up as the kernel path.

Frames are resolved from the guest's own kallsyms: perf leaves module-space frames
(BPF text lives there) and every userspace frame unnamed, and the kallsyms snapshot
the profile already captured names the kernel and JIT'd BPF ones.

Usage: callers.py <phase-profile run dir> <symbol> [rows]
"""

from __future__ import annotations

import bisect
import collections
import pathlib
import re
import subprocess
import sys

PERF = pathlib.Path("/var/tmp/kprog-tmp/C/perf-build/perf")
PHASES = ("baseline", "post_rejit")
KERNEL_FLOOR = 0xFFFF800000000000


def _kallsyms(path: pathlib.Path) -> tuple[list[int], list[str]]:
    rows = []
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        parts = line.split()
        if len(parts) < 3:
            continue
        try:
            rows.append((int(parts[0], 16), parts[2]))
        except ValueError:
            continue
    rows.sort()
    return [r[0] for r in rows], [r[1] for r in rows]


def _resolve(ip: int, addrs: list[int], names: list[str]) -> str:
    if ip < KERNEL_FLOOR:
        return "user"
    index = bisect.bisect_right(addrs, ip) - 1
    if index < 0 or ip - addrs[index] > (1 << 21):
        return "[unknown]"
    return names[index]


def chains(data: pathlib.Path) -> list[list[int]]:
    """Each sample's callchain as IPs, innermost first."""
    done = subprocess.run([str(PERF), "script", "-i", str(data), "-F", "ip", "--no-inline"],
                          capture_output=True, text=True)
    if done.returncode != 0:
        raise SystemExit(f"perf script failed: {done.stderr.strip()}")
    out: list[list[int]] = []
    current: list[int] = []
    for raw in done.stdout.splitlines():
        token = raw.strip()
        if not token:
            if current:
                out.append(current)
                current = []
            continue
        try:
            current.append(int(token, 16))
        except ValueError:
            continue
    if current:
        out.append(current)
    return out


def main(argv: list[str]) -> int:
    run = pathlib.Path(argv[1])
    symbol = argv[2]
    rows = int(argv[3]) if len(argv) > 3 else 15
    per_phase = {}
    for phase in PHASES:
        addrs, names = _kallsyms(run / f"{phase}.kallsyms")
        counts: collections.Counter = collections.Counter()
        total = hits = 0
        for chain in chains(run / f"{phase}.data"):
            total += 1
            resolved = [_resolve(ip, addrs, names) for ip in chain]
            if symbol not in resolved:
                continue
            hits += 1
            index = resolved.index(symbol)
            below = resolved[index + 1:]
            key = " <- ".join(below[:3]) if below else "(no caller recorded)"
            counts[key] += 1
        per_phase[phase] = (counts, total, hits)

    names_set = set(per_phase["baseline"][0]) | set(per_phase["post_rejit"][0])
    ranked = sorted(names_set, key=lambda n: -per_phase["post_rejit"][0][n])[:rows]
    print(f"{'frames below ' + symbol:60} {'eBPF':>8} {'native':>8}")
    for name in ranked:
        print(f"{name[:60]:60} {per_phase['baseline'][0][name]:>8} "
              f"{per_phase['post_rejit'][0][name]:>8}")
    for phase in PHASES:
        _, total, hits = per_phase[phase]
        print(f"{phase:11} {hits:7} of {total:7} samples have {symbol} on the stack")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))