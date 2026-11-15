#!/usr/bin/env python3
"""Compare the two arms' bcc/set tool output.

Input is the directory `kprog/perf/one-image/scripts/bcc-tool-output.sh`
writes: `baseline/<tool>.{out,err}` and `post/<tool>.{out,err}` for the eight
tools of BCC_SET_TOOL_SPECS (runner/libs/app_runners/bcc_set.py:33-42), taken
against the frozen `stress_ng_bcc_hook_hot` workload with the environment the
runner gives each child.

Why this exists: the corpus driver keeps only a 40-line, 8000-char tail of each
tool and never writes it to the run directory, so a timed run cannot show
whether the two arms made the tools see the same events. A native replacement
that silently drops, duplicates or changes events would keep the throughput and
still be wrong; this is the check that catches it.

The tools emit an event stream, so identity is the event's kind, not its
timestamp, pid or measured latency. Each tool below names the columns that
identify an event; the rest are per-arm noise. Counter-style tools (vfsstat,
syscount, runqlat) print aggregates, so they are compared on column totals and
on their label sets rather than on row identity.

Usage: tool-output-compare.py <dir holding baseline/ and post/>
"""

import sys
from collections import Counter
from pathlib import Path

# Per tool: the header columns that identify one event. Everything else
# (timestamps, pids, latencies, byte counters) varies between arms by
# construction. An empty tuple means "compare aggregates, not rows".
EVENT_KEYS = {
    # TIME UID PID COMM CAP NAME AUDIT VERDICT
    "capable": ("CAP", "NAME", "AUDIT", "VERDICT"),
    # TIME(s) COMM PID DISK T SECTOR BYTES LAT(ms)
    "biosnoop": ("COMM", "DISK", "T", "BYTES"),
    # TIME(s) PID COMM FD ERR PATH
    "opensnoop": ("COMM", "ERR", "PATH"),
    # PID COMM IP SADDR DADDR DPORT
    "tcpconnect": ("IP", "DPORT"),
    # PID COMM LADDR LPORT RADDR RPORT TX_KB RX_KB MS
    "tcplife": ("IP", "DPORT") if False else ("COMM", "LPORT", "RPORT"),
    # TIME READ/s WRITE/s FSYNC/s OPEN/s CREATE/s
    "vfsstat": (),
    # NAME COUNT (syscount -L -i 1)
    "syscount": ("NAME",),
    # usecs : count distribution
    "runqlat": (),
}

TOOLS = list(EVENT_KEYS)


def parse(path: Path) -> tuple[list[str], list[list[str]]]:
    """The header row and the data rows of one tool's stdout."""
    if not path.is_file():
        return [], []
    lines = [line for line in path.read_text(errors="replace").splitlines() if line.strip()]
    if not lines:
        return [], []
    return lines[0].split(), [line.split() for line in lines[1:]]


def event_keys(tool: str, header: list[str], rows: list[list[str]]) -> Counter:
    """The multiset of event kinds in one arm."""
    wanted = EVENT_KEYS[tool]
    if not wanted:
        return Counter()
    slots = [header.index(name) for name in wanted if name in header]
    if len(slots) != len(wanted):
        # A tool whose header this script does not know: fall back to the whole
        # row, which still compares something rather than silently nothing.
        return Counter(" ".join(row) for row in rows)
    keys: Counter = Counter()
    for row in rows:
        if len(row) > max(slots):
            keys[" ".join(row[slot] for slot in slots)] += 1
    return keys


def column_totals(tool: str, header: list[str], rows: list[list[str]]) -> dict[str, float]:
    """Per-column sums for the counter-style tools."""
    totals: dict[str, float] = {}
    for index, name in enumerate(header):
        if name in {"TIME", "TIME(s)", "usecs"} or ":" in name or "->" in name:
            continue
        values = []
        for row in rows:
            if len(row) <= index:
                continue
            try:
                values.append(float(row[index].strip("|")))
            except ValueError:
                break
        if values and len(values) == len(rows):
            totals[name] = sum(values)
    return totals


def main() -> int:
    root = Path(sys.argv[1])
    print(f"{'tool':11} {'rows base':>10} {'rows post':>10} {'kinds':>6} "
          f"{'base only':>9} {'post only':>9} {'shared':>7} {'err base':>9} {'err post':>9}")
    for tool in TOOLS:
        header_b, rows_b = parse(root / "baseline" / f"{tool}.out")
        header_p, rows_p = parse(root / "post" / f"{tool}.out")
        keys_b = event_keys(tool, header_b, rows_b)
        keys_p = event_keys(tool, header_p, rows_p)
        err_b = len((root / "baseline" / f"{tool}.err").read_text(errors="replace").splitlines()) \
            if (root / "baseline" / f"{tool}.err").is_file() else 0
        err_p = len((root / "post" / f"{tool}.err").read_text(errors="replace").splitlines()) \
            if (root / "post" / f"{tool}.err").is_file() else 0
        print(f"{tool:11} {len(rows_b):10d} {len(rows_p):10d} {len(keys_b | keys_p):6d} "
              f"{len(keys_b - keys_p):9d} {len(keys_p - keys_b):9d} "
              f"{len(keys_b & keys_p):7d} {err_b:9d} {err_p:9d}")

    for tool in TOOLS:
        if EVENT_KEYS[tool]:
            continue
        header_b, rows_b = parse(root / "baseline" / f"{tool}.out")
        header_p, rows_p = parse(root / "post" / f"{tool}.out")
        totals_b = column_totals(tool, header_b, rows_b)
        totals_p = column_totals(tool, header_p, rows_p)
        if not totals_b and not totals_p:
            continue
        print(f"\n=== {tool}: column totals (aggregates; rows: {len(rows_b)} base, {len(rows_p)} post)")
        for name in sorted(set(totals_b) | set(totals_p)):
            base = totals_b.get(name, 0.0)
            post = totals_p.get(name, 0.0)
            ratio = f"{post / base:.4f}x" if base else "n/a"
            print(f"  {name:12} {base:14.1f} {post:14.1f} {ratio:>10}")

    for tool in TOOLS:
        if not EVENT_KEYS[tool]:
            continue
        header_b, rows_b = parse(root / "baseline" / f"{tool}.out")
        header_p, rows_p = parse(root / "post" / f"{tool}.out")
        keys_b = event_keys(tool, header_b, rows_b)
        keys_p = event_keys(tool, header_p, rows_p)
        only_b, only_p = keys_b - keys_p, keys_p - keys_b
        if not only_b and not only_p:
            continue
        print(f"\n=== {tool}: {len(only_b)} event kinds only in baseline, "
              f"{len(only_p)} only in post; top 5 each")
        for label, keys, counts in (("base", only_b, keys_b), ("post", only_p, keys_p)):
            for key in sorted(keys, key=lambda k: -counts[k])[:5]:
                print(f"  {label} {counts[key]:9d}  {key[:110]}")
    return 0


if __name__ == "__main__":
    sys.exit(main())