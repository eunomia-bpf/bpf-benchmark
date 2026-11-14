#!/usr/bin/env python3
"""Attribute BPF time to the program body and to the helpers it is running.

`phase-profile.py report` resolves each sample's root IP against the guest's
kallsyms.  That only names a sample that lands in the program's own text when
`bpf_prog_<tag>_<name>` made it into kallsyms, and it counts a sample taken
inside an out-of-line helper as "not BPF".  This script answers the two
questions the limits table needs, from the same capture:

  * the BPF denominator: samples whose callchain contains at least one frame
    inside a JIT'd program, from that phase's `jit-lines.json` ranges;
  * of those, the sample's own root frame, named by the guest's kallsyms
    (`--kallsyms` is the guest's, so host symbols never appear), split into
    `program_text` (root inside the program) and one bucket per helper symbol.

Callchains also name the JIT'd program, so the same run reports each
program's share of the BPF denominator, including the samples spent inside its
callees.

Usage: bpf-attribution.py <phase-profile dir> [--json out.json]
"""

from __future__ import annotations

import argparse
import bisect
import collections
import json
import pathlib
import subprocess
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parents[2] / "perf" / "profile"))
import symbolize  # noqa: E402

PERF = pathlib.Path("/var/tmp/kprog-tmp/C/perf-build/perf")
PHASES = ("baseline", "post_rejit")

# A perf tracepoint/kprobe entry wrapper is what *runs* the program; a sample on
# it is BPF work with the program text already returned, not a helper call.
ENTRY = {
    "trace_call_bpf", "perf_call_bpf_enter", "perf_call_bpf_exit", "bpf_prog_run",
    "__bpf_prog_enter", "__bpf_prog_exit", "__bpf_prog_enter_sleepable",
    "__bpf_prog_exit_sleepable", "__bpf_prog_enter_recur", "__bpf_prog_exit_recur",
    "__bpf_prog_enter_lsm_cgroup", "bpf_prog_run_pin_on_cpu",
}


def jit_ranges(directory: pathlib.Path, phase: str):
    data = json.loads((directory / f"{phase}.jit-lines.json").read_text())
    ranges = sorted(
        (f["address"], f["address"] + f["length"], p["name"] or f"tag:{p['tag'][:8]}")
        for p in data["programs"] for f in p["functions"])
    return ranges, [r[0] for r in ranges]


def program_at(ranges, starts, ip: int) -> str | None:
    i = bisect.bisect_right(starts, ip) - 1
    if i >= 0 and ranges[i][0] <= ip < ranges[i][1]:
        return ranges[i][2]
    return None


def chains(directory: pathlib.Path, phase: str) -> list[list[int]]:
    done = subprocess.run(
        [str(PERF), "script", "-i", str(directory / f"{phase}.data"),
         "-F", "ip", "--no-inline"],
        capture_output=True, text=True)
    if done.returncode != 0:
        raise SystemExit(f"perf script failed for {phase}: {done.stderr.strip()}")
    blocks = []
    for block in done.stdout.split("\n\n"):
        ips = []
        for line in block.splitlines():
            text = line.strip()
            if text:
                ips.append(int(text, 16))
        if ips:
            blocks.append(ips)
    return blocks


def attach_chains(directory: pathlib.Path, phase: str) -> list[list[int]]:
    """Samples recorded with `-g`: one IP list per sample."""
    return chains(directory, phase)


def analyse(directory: pathlib.Path, phase: str) -> dict:
    ranges, starts = jit_ranges(directory, phase)
    addresses, names, _ = symbolize.load_kallsyms(directory / f"{phase}.kallsyms")

    def ksym(ip: int) -> str:
        i = bisect.bisect_right(addresses, ip) - 1
        if i < 0 or ip - addresses[i] > (1 << 21):
            return "[unknown]"
        return names[i].split("+")[0]

    samples = attach_chains(directory, phase)
    buckets: collections.Counter = collections.Counter()
    categories: collections.Counter = collections.Counter()
    per_program: collections.Counter = collections.Counter()
    bpf = 0
    for ips in samples:
        programs = {p for p in (program_at(ranges, starts, ip) for ip in ips) if p}
        if not programs:
            continue
        bpf += 1
        for name in programs:
            per_program[name] += 1
        # Frames run leaf-first.  The innermost program frame is the one whose
        # text the caller returned from, so the frame just above it is the
        # helper it called: `memcmp` inside `htab_map_hash` inside
        # `bpf_map_lookup_elem` is a map lookup, and the sample's own root
        # (`pvclock_clocksource_read_nowd` inlined into `ktime_get_mono_fast_ns`)
        # is not a separate helper.
        inner = max(i for i, ip in enumerate(ips) if program_at(ranges, starts, ip))
        if inner == 0:
            buckets["program_text"] += 1
            categories["program_text"] += 1
            continue
        name = ksym(ips[inner - 1])
        if name in ENTRY:
            buckets["program_text"] += 1
            categories["program_text"] += 1
            continue
        buckets[name] += 1
        categories[category_of(name)] += 1
    return {
        "samples": len(samples),
        "bpf_samples": bpf,
        "bpf_share_of_all": bpf / len(samples) if samples else 0.0,
        "buckets": {k: (v, v / bpf if bpf else 0.0) for k, v in buckets.most_common()},
        "categories": {k: (v, v / bpf if bpf else 0.0) for k, v in categories.most_common()},
        "per_program_inclusive": {k: (v, v / bpf if bpf else 0.0)
                                   for k, v in per_program.most_common()},
    }


def category_of(helper: str) -> str:
    """Group a helper symbol by the work it does, for the limits table."""
    if "map_lookup" in helper or helper in {
            "__htab_map_lookup_elem", "htab_map_hash", "lookup_nulls_elem_raw",
            "htab_lru_map_lookup_elem", "bpf_map_lookup_elem"}:
        return "map_lookup"
    if "map_update" in helper or "map_delete" in helper:
        return "map_update"
    if "probe_read" in helper or "nofault" in helper or helper in {
            "strncpy_from_user", "strnlen", "sized_strscpy", "jhash"}:
        return "probe_read"
    if "perf_event_output" in helper or helper in {
            "perf_output_begin", "perf_output_end", "perf_output_put_handle",
            "irq_work_queue", "arch_irq_work_raise", "native_apic_msr_write",
            "perf_output_sample"}:
        return "perf_event_output"
    if "ktime" in helper or "clock" in helper or helper in {
            "pvclock_clocksource_read_nowd", "ktime_get_mono_fast_ns",
            "kvm_clock_get_cycles"}:
        return "ktime_get_ns"
    if "tail_call" in helper:
        return "tail_call"
    return "other_helper"


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("directory", type=pathlib.Path)
    parser.add_argument("--json", type=pathlib.Path)
    args = parser.parse_args(argv)

    out = {phase: analyse(args.directory, phase) for phase in PHASES}
    for phase, row in out.items():
        print(f"{phase}: {row['bpf_samples']} of {row['samples']} samples are BPF "
              f"({100 * row['bpf_share_of_all']:.2f}% of guest CPU time)")
        print(f"  {'category':24} {'samples':>8} {'% of BPF':>9}")
        for name, (count, share) in row["categories"].items():
            print(f"  {name:24} {count:8} {100 * share:8.2f}%")
        print(f"  {'helper symbol':46} {'samples':>8} {'% of BPF':>9}")
        for name, (count, share) in row["buckets"].items():
            print(f"  {name:46} {count:8} {100 * share:8.2f}%")
        print("  program (inclusive of its callees)")
        for name, (count, share) in row["per_program_inclusive"].items():
            print(f"  {name:46} {count:8} {100 * share:8.2f}%")
        print()
    if args.json:
        args.json.write_text(json.dumps(out, indent=1), encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))