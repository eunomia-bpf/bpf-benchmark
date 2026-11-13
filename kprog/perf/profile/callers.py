#!/usr/bin/env python3
"""Who calls a given symbol, per arm, from the phase profile's callchains.

The per-program table says where the CPU was; for an out-of-line kernel entry such
as memset it does not say who got there.  This walks each sample's callchain (the
phase profile records with -g) and reports the first caller below the named symbol,
so a cost that belongs to a BPF program's body shows up as that program, and a cost
that belongs to ordinary kernel work shows up as the kernel path.

Usage: callers.py <phase-profile run dir> <symbol> [rows]
"""

from __future__ import annotations

import collections
import pathlib
import re
import subprocess
import sys

PERF = pathlib.Path("/var/tmp/kprog-tmp/C/perf-build/perf")
PHASES = ("baseline", "post_rejit")


def chains(data: pathlib.Path) -> list[list[str]]:
    """Each sample's callchain, innermost first, symbols only."""
    done = subprocess.run(
        [str(PERF), "script", "-i", str(data), "-F", "ip,sym", "--no-inline"],
        capture_output=True, text=True)
    if done.returncode != 0:
        raise SystemExit(f"perf script failed: {done.stderr.strip()}")
    out: list[list[str]] = []
    current: list[str] = []
    for raw in done.stdout.splitlines():
        line = raw.rstrip()
        if not line:
            continue
        # perf script indents callchain frames; the sample line is unindented.
        if line.startswith("\t") or line.startswith("    "):
            token = line.strip()
            if token:
                current.append(token.split()[-1])
            continue
        if current:
            out.append(current)
        current = []
    if current:
        out.append(current)
    return out


def main(argv: list[str]) -> int:
    run = pathlib.Path(argv[1])
    symbol = argv[2]
    rows = int(argv[3]) if len(argv) > 3 else 15
    print(f"{'caller':44} {'eBPF':>9} {'native':>9} {'native/eBPF':>12}")
    per_phase = {}
    for phase in PHASES:
        counts: collections.Counter = collections.Counter()
        total = 0
        for chain in chains(run / f"{phase}.data"):
            total += 1
            if symbol not in chain:
                continue
            index = chain.index(symbol)
            caller = chain[index + 1] if index + 1 < len(chain) else "(no caller)"
            callsite = chain[index - 1] if index > 0 else ""
            key = f"{caller} <- {callsite}" if callsite else caller
            counts[key] += 1
        per_phase[phase] = (counts, total)
    names = set(per_phase["baseline"][0]) | set(per_phase["post_rejit"][0])
    ranked = sorted(names, key=lambda n: -per_phase["post_rejit"][0][n])[:rows]
    for name in ranked:
        base = per_phase["baseline"][0][name]
        native = per_phase["post_rejit"][0][name]
        ratio = f"{native / base:.2f}" if base else "-"
        print(f"{name[:44]:44} {base:>9} {native:>9} {ratio:>12}")
    for phase in PHASES:
        counts, total = per_phase[phase]
        print(f"{phase:11} {sum(counts.values()):7} of {total:7} samples are under {symbol}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))