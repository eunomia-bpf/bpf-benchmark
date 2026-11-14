#!/usr/bin/env python3
"""Resolve recorded callchains within shim measurement clocks, offline only.

Shares overlap: a probe-read sample may also be on a BPF stack. Neither root
nor inclusive sample shares estimate time in code that the event cannot sample.
"""
import argparse
import bisect
from collections import Counter
import json
from pathlib import Path
import re
import subprocess

import symbolize


def parse_chains(text):
    records = []
    time = None
    ips = []
    for line in text.splitlines() + [""]:
        if not line.strip():
            if time is not None:
                if not ips:
                    raise ValueError("sample timestamp has no instruction pointers")
                records.append((time, ips))
            time, ips = None, []
        elif match := re.fullmatch(r"\s*([0-9]+\.[0-9]+):\s*", line):
            if time is not None:
                raise ValueError("sample has no separating blank line")
            time = float(match[1])
        else:
            if time is None:
                raise ValueError("instruction pointer has no sample timestamp")
            ips.append(int(line.strip(), 16))
    return records


def category(symbol):
    if re.match(r"bpf_prog_[0-9a-f]+(?:_|$)", symbol):
        return "program_text"
    if symbol.startswith("bpf_probe_read_user"):
        return "probe_read_user"
    if symbol.startswith("bpf_probe_read_kernel"):
        return "probe_read_kernel"
    if symbol.startswith(("bpf_map_lookup_elem", "htab_map_lookup", "__htab_map_lookup",
                          "htab_lru_map_lookup", "htab_percpu_map_lookup", "array_map_lookup",
                          "percpu_array_map_lookup")):
        return "map_lookup"
    if "tail_call" in symbol:
        return "tail_dispatch"
    return None


def analyze(records, table):
    addrs, names, _ = table
    def resolve(ip):
        if ip < 0xffff800000000000:
            return "[user-or-low-ip]"
        index = bisect.bisect_right(addrs, ip) - 1
        if index < 0 or ip - addrs[index] > (1 << 21):
            return "[unknown-kernel]"
        return names[index]
    roots, inclusive, root_classes = Counter(), Counter(), Counter()
    kernel_roots = 0
    for _, chain in records:
        kernel_roots += chain[0] >= 0xffff800000000000
        syms = [resolve(ip) for ip in chain]
        roots[syms[0]] += 1
        if kind := category(syms[0]):
            root_classes[kind] += 1
        inclusive.update({kind for sym in syms if (kind := category(sym))})
    return dict(samples=len(records), kernel_root_samples=kernel_roots,
                first_seconds=records[0][0] if records else None,
                last_seconds=records[-1][0] if records else None,
                root_symbols=dict(roots.most_common()),
                root_categories=dict(root_classes), inclusive_categories=dict(inclusive))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("directory", type=Path)
    parser.add_argument("--observation", type=Path, required=True)
    parser.add_argument("--perf", type=Path, required=True)
    args = parser.parse_args()
    intervals = json.loads(args.observation.read_text())["measurement_intervals"]
    output = dict(scope="Offline CPU samples; inclusive categories overlap. Inlined helper/"
                       "tail code remains program text. Absent samples do not imply absent work.",
                  phases={})
    for phase in ("baseline", "post_rejit"):
        table = symbolize.load_kallsyms(args.directory / (phase + ".kallsyms"))
        results = []
        for interval in (r for r in intervals if r["phase"] == phase):
            first, last = interval["start_seconds"], interval["end_seconds"]
            command = [str(args.perf), "script", "-i", str(args.directory / (phase + ".data")),
                       "-F", "time,ip", "--no-inline", "--time", f"{first},{last}"]
            done = subprocess.run(command, capture_output=True, text=True, check=True)
            results.append(dict(interval=interval, command=command,
                                **analyze(parse_chains(done.stdout), table)))
        output["phases"][phase] = results
    print(json.dumps(output, indent=2))


if __name__ == "__main__":
    main()
