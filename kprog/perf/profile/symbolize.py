#!/usr/bin/env python3
"""Symbolize phase-profile samples against the guest's own kallsyms.

`perf report --kallsyms` resolves kernel-text addresses but leaves JIT'd BPF text
(module space, ffffffffc...) as `[unknown]`, and with the module column kept it names
samples after unrelated host modules.  Every sample carries its instruction pointer,
and the guest half of phase-profile.py snapshots /proc/kallsyms while each phase's
programs are loaded, so the table here is built from those two files directly: an IP
is named by the nearest preceding symbol, and a `bpf_prog_<tag>_<name>` symbol names
the program whose text the CPU was in.

Usage: symbolize.py <phase-profile run dir> [rows]
"""

from __future__ import annotations

import bisect
import collections
import json
import pathlib
import re
import subprocess
import sys

PERF = pathlib.Path("/var/tmp/kprog-tmp/C/perf-build/perf")
PHASES = ("baseline", "post_rejit")
KERNEL_BASE = 0xFFFFFFFF80000000


def load_kallsyms(path: pathlib.Path) -> tuple[list[int], list[str], list[str]]:
    """`(addresses, names, modules)` sorted by address."""
    rows = []
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        parts = line.split()
        if len(parts) < 3:
            continue
        try:
            address = int(parts[0], 16)
        except ValueError:
            continue
        module = parts[3].strip("[]") if len(parts) > 3 else ""
        rows.append((address, parts[2], module))
    rows.sort()
    return [r[0] for r in rows], [r[1] for r in rows], [r[2] for r in rows]


def samples(data: pathlib.Path) -> list[int]:
    done = subprocess.run(
        [str(PERF), "script", "-i", str(data), "-F", "ip", "--no-inline", "--hide-call-graph"],
        capture_output=True, text=True)
    if done.returncode != 0:
        raise SystemExit(f"perf script failed: {done.stderr.strip()}")
    return parse_root_ips(done.stdout)


def parse_root_ips(text: str) -> list[int]:
    """One IP per sample with --hide-call-graph; unexpected output is an error."""
    return [int(line.strip(), 16) for line in text.splitlines() if line.strip()]


def resolve(ips: list[int], addresses: list[int], names: list[str],
            modules: list[str]) -> collections.Counter:
    """`{symbol}` per sample, retaining unknown IPs in the denominator."""
    out: collections.Counter = collections.Counter()
    for ip in ips:
        if ip == 0:
            out["[zero-ip]"] += 1
            continue
        index = bisect.bisect_right(addresses, ip) - 1
        if index < 0:
            out["[below-kernel]"] += 1
            continue
        if ip - addresses[index] > (1 << 21):
            out["[far]"] += 1
            continue
        out[names[index]] += 1
    return out


def program_of(symbol: str) -> str | None:
    match = re.match(r"bpf_prog_[0-9a-f]{16}_(.+)$", symbol)
    return match.group(1) if match else None


def main(argv: list[str]) -> int:
    run = pathlib.Path(argv[1])
    rows = int(argv[2]) if len(argv) > 2 else 20
    tables = {}
    for phase in PHASES:
        tables[phase] = load_kallsyms(run / f"{phase}.kallsyms")
    counts = {}
    for phase in PHASES:
        ip_list = samples(run / f"{phase}.data")
        counts[phase] = resolve(ip_list, *tables[phase])
        print(f"{phase}: {len(ip_list)} samples", file=sys.stderr)

    totals = {p: sum(counts[p].values()) or 1 for p in PHASES}
    program_counts = {}
    for phase in PHASES:
        program_counts[phase] = collections.Counter()
        for symbol, n in counts[phase].items():
            name = program_of(symbol)
            if name:
                program_counts[phase][name] += n

    lines = []
    for phase in PHASES:
        bpf = sum(program_counts[phase].values())
        lines.append(f"{phase:11} {totals[phase]:7} samples; in bpf_prog_* text: "
                     f"{bpf:7} ({100 * bpf / totals[phase]:5.2f}%)")
    lines.append("")
    lines.append(f"{'program':40} {'eBPF':>8} {'native':>8} {'native/eBPF':>12} "
                 f"{'eBPF%':>7} {'nativ%':>7}")
    names = set(program_counts["baseline"]) | set(program_counts["post_rejit"])
    ranked = sorted(names, key=lambda n: -program_counts["post_rejit"][n])[:rows]
    for name in ranked:
        b = program_counts["baseline"][name]
        n = program_counts["post_rejit"][name]
        ratio = f"{n / b:.3f}" if b else "-"
        lines.append(f"{name[:40]:40} {b:>8} {n:>8} {ratio:>12} "
                     f"{100 * b / totals['baseline']:>6.2f} {100 * n / totals['post_rejit']:>6.2f}")

    lines.append("")
    lines.append("Top non-program symbols (helpers, map code, scheduler, user space):")
    lines.append(f"{'symbol':48} {'eBPF%':>7} {'nativ%':>7} {'native/eBPF':>12}")
    symbols = set(counts["baseline"]) | set(counts["post_rejit"])
    ranked = sorted(symbols, key=lambda s: -(counts["baseline"][s]
                                             + counts["post_rejit"][s]))[:rows]
    for symbol in ranked:
        if program_of(symbol):
            continue
        b = counts["baseline"][symbol]
        n = counts["post_rejit"][symbol]
        ratio = f"{n / b:.2f}" if b else "-"
        lines.append(f"{symbol[:48]:48} {100 * b / totals['baseline']:>6.2f} "
                     f"{100 * n / totals['post_rejit']:>6.2f} {ratio:>12}")
    text = "\n".join(lines) + "\n"
    (run / "summary.txt").write_text(text, encoding="utf-8")
    print(text)
    (run / "counts.json").write_text(
        json.dumps({phase: dict(counts[phase]) for phase in PHASES},
                   indent=1, sort_keys=True) + "\n", encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
