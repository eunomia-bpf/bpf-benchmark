#!/usr/bin/env python3
"""Measure the entry-and-return floor of the native runner.

`simple` writes one constant, so what a run of it costs is the call path and
the runner's loop and nothing else.  Measuring it against programs that do
real work separates the fixed floor from the program's own body, which is the
entry and return bridge the candidate list names without a cost.

The floor converges as the repeat count grows, because the one-shot call
setup is amortized; the script reports three repeat counts so the
convergence is visible rather than assumed.
"""

import argparse
import json
import pathlib
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parents[2]
MICRO = ROOT / "runner/build-llvmbpf/micro_exec"
BUILD = ROOT / "micro/programs/build-x86"
INPUTS = ROOT / "micro/generated-inputs"


def measure(program, repeat, memory=""):
    """(cycles, instructions) for one program at one repeat count."""
    command = [str(MICRO), "run-native",
               "--program", str(BUILD / (program + ".bpf.o")),
               "--native-program", str(BUILD / (program + ".native.so")),
               "--inner-repeat", str(repeat), "--perf-counters"]
    if memory:
        command += ["--memory", memory, "--io-mode", "packet"]
    done = subprocess.run(command, capture_output=True, text=True)
    try:
        counters = json.loads(done.stdout)["perf_counters"]
    except (ValueError, KeyError):
        return None
    return counters.get("cycles"), counters.get("instructions")


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--floor", default="simple")
    ap.add_argument("--programs", default="simple,"
                    "katran_lb_consistent_hash_select,"
                    "packet_vlan_tcpopt_parser,flow_5tuple_rss_hash")
    args = ap.parse_args(argv[1:])

    rows = []
    for repeat in (10000, 100000, 1000000):
        got = measure(args.floor, repeat)
        if got:
            rows.append(dict(repeat=repeat, cycles=got[0],
                             instructions=got[1],
                             cycles_per=round(got[0] / repeat, 2),
                             instructions_per=round(got[1] / repeat, 2)))

    per_program = []
    for name in args.programs.split(","):
        memory = INPUTS / (name + ".mem")
        got = measure(name, 1000000, str(memory) if memory.exists() else "")
        if got:
            per_program.append(dict(
                program=name,
                cycles_per=round(got[0] / 1000000, 2),
                instructions_per=round(got[1] / 1000000, 2)))

    if not rows or not per_program:
        print("no counter collected", file=sys.stderr)
        return 1
    floor = rows[-1]
    for row in per_program:
        row["body_cycles"] = round(row["cycles_per"] - floor["cycles_per"], 2)
        row["body_instructions"] = round(
            row["instructions_per"] - floor["instructions_per"], 2)
    print(json.dumps(dict(floor=rows, programs=per_program), indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
