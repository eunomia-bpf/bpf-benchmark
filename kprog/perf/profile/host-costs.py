#!/usr/bin/env python3
"""Resolve host-recorded guest root samples against each arm's guest symbols.

Input is perf script --guestkallsyms PHASE.start.kallsyms -F
time,misc,ip,pid,tid,cpu,period --no-inline --hide-call-graph --ns. Without
--guestkallsyms perf script hides guest samples and prints only host VM exits.
Clock pairs translate the shim's guest monotonic windows to host monotonic time.
Root buckets are disjoint; they are not inclusive helper costs or caller attribution.
"""
import argparse
import bisect
from collections import Counter
import json
from pathlib import Path
import re

import symbolize


def parse_samples(text):
    pattern = re.compile(r"\s*(\d+)/(\d+)\s+\[(\d+)\]\s+(\S+)\s+"
                         r"(\d+)\.(\d{1,9}):\s+(\d+)\s+([0-9a-fA-F]+)")
    samples = []
    for line in text.splitlines():
        if not line.strip():
            continue
        match = pattern.fullmatch(line)
        if match is None:
            raise ValueError("unexpected perf root sample: " + line)
        pid, tid, cpu, misc, seconds, fraction, period, ip = match.groups()
        samples.append(dict(pid=int(pid), tid=int(tid), cpu=int(cpu), misc=misc,
                            time_ns=int(seconds) * 10**9 + int(fraction.ljust(9, "0")),
                            period=int(period), ip=int(ip, 16)))
    return samples


def clock_offset(clock):
    return clock["wall_ns"] - clock["monotonic_ns"]


def host_window(interval, guest_clock, host_clock):
    shift = clock_offset(guest_clock) - clock_offset(host_clock)
    return (round(interval["start_seconds"] * 10**9) + shift,
            round(interval["end_seconds"] * 10**9) + shift)


def root_category(symbol):
    if re.match(r"bpf_prog_[0-9a-f]+(?:_|$)", symbol):
        return "program_text"
    if symbol.startswith("bpf_probe_read_user"):
        return "probe_read_user_entry"
    if symbol.startswith("bpf_probe_read_kernel"):
        return "probe_read_kernel_entry"
    if symbol.startswith("copy_from_user_nofault"):
        return "user_nofault_copy"
    if symbol.startswith("copy_from_kernel_nofault"):
        return "kernel_nofault_copy"
    if symbol.startswith("trie_lookup_elem"):
        return "lpm_lookup"
    if symbol.startswith(("array_map_lookup_elem", "percpu_array_map_lookup_elem")):
        return "array_lookup"
    if symbol.startswith(("lookup_nulls_elem_raw", "htab_map_hash", "__htab_map_lookup_elem",
                          "htab_map_lookup_elem", "htab_lru_map_lookup_elem",
                          "htab_percpu_map_lookup_elem", "htab_of_map_lookup_elem")):
        return "hash_lookup"
    if symbol.startswith("bpf_map_lookup_elem"):
        return "generic_lookup_dispatch"
    if "tail_call" in symbol:
        return "tail_dispatch"
    return "other_guest_kernel"


def analyze(samples, table, first, last):
    addresses, names, _ = table
    symbols, cycles, categories, category_cycles, modes, pids = (Counter() for _ in range(6))
    for sample in samples:
        if not first <= sample["time_ns"] <= last:
            continue
        modes[sample["misc"]] += 1
        pids[str(sample["pid"])] += 1
        # The tool prints KGg for GUEST_USER (5), whose bits overlap K and G.
        if "G" not in sample["misc"] or "g" in sample["misc"]:
            continue
        ip = sample["ip"]
        index = bisect.bisect_right(addresses, ip) - 1
        symbol = (names[index] if index >= 0 and ip >= 0xffff800000000000
                  and ip - addresses[index] <= (1 << 21) else "[unknown-guest-kernel]")
        symbols[symbol] += 1
        cycles[symbol] += sample["period"]
        category = root_category(symbol)
        categories[category] += 1
        category_cycles[category] += sample["period"]
    return dict(host_start_ns=first, host_end_ns=last, modes=dict(modes), qemu_pids=dict(pids),
                guest_kernel_samples=sum(symbols.values()), sampled_cycles=sum(cycles.values()),
                root_symbols=dict(symbols.most_common()), root_symbol_cycles=dict(cycles.most_common()),
                root_categories=dict(categories), root_category_cycles=dict(category_cycles))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("directory", type=Path)
    parser.add_argument("--samples", type=Path, required=True)
    parser.add_argument("--observation", type=Path, required=True)
    args = parser.parse_args()
    samples = parse_samples(args.samples.read_text())
    observation = json.loads(args.observation.read_text())
    host = json.loads((args.directory / "host.start.clock.json").read_text())
    host_end = json.loads((args.directory / "host.end.clock.json").read_text())
    result = dict(scope="Actual host hardware guest root samples only. Cycles sum sample periods. "
                        "Leaf categories do not establish inclusive helper cost or caller ownership. "
                        "Inlined maps/tails remain program text; other guest activity stays included. "
                        "Clock pairs observe offsets/drift, not exact host/guest clock synchronization.",
                  sample_count=len(samples),
                  all_modes=dict(Counter(s["misc"] for s in samples)),
                  host_clock_offset_drift_ns=clock_offset(host_end) - clock_offset(host), phases={})
    for interval in observation["measurement_intervals"]:
        phase = interval["phase"]
        guest = json.loads((args.directory / (phase + ".start.clock.json")).read_text())
        guest_end = json.loads((args.directory / (phase + ".end.clock.json")).read_text())
        first, last = host_window(interval, guest, host)
        row = analyze(samples, symbolize.load_kallsyms(args.directory / (phase + ".start.kallsyms")),
                      first, last)
        row.update(interval=interval, guest_clock_offset_drift_ns=clock_offset(guest_end) - clock_offset(guest))
        result["phases"].setdefault(phase, []).append(row)
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
