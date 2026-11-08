#!/usr/bin/env python3
"""Which arm moved between the 2026-05-29 reference and the current runs.

The workload ratios say the current native arm is slower than the reference
one, but not which arm moved.  Each corpus run records per-program
`run_cnt_delta` and `run_time_ns_delta` for both arms -- `baseline` is the
JIT arm and `post_rejit` the native arm of the same run -- so the two runs
can be compared program by program on the same field.

`ns_per_run` is the invariant: it does not depend on how many invocations
the workload happened to make, so a difference in it names the arm.
"""

import argparse
import json
import pathlib
import statistics
import sys


def programs(path, arm):
    """`{name: (run_cnt, run_time_ns)}` for one arm of one run."""
    data = json.loads(pathlib.Path(path).read_text())[arm]["bpf"]
    out = {}
    for entry in data.values():
        runs = entry.get("run_cnt_delta") or 0
        if runs <= 0:
            continue
        name = entry.get("name") or str(entry.get("id"))
        count, total = out.get(name, (0, 0))
        total += entry.get("run_time_ns_delta") or 0
        out[name] = (count + runs, total)
    return out


def ns_per_run(table):
    return {name: total / runs for name, (runs, total) in table.items()}


def compare(old_path, new_path, label):
    rows = []
    for arm in ("baseline", "post_rejit"):
        old = ns_per_run(programs(old_path, arm))
        new = ns_per_run(programs(new_path, arm))
        shared = sorted(set(old) & set(new))
        if not shared:
            continue
        ratio = statistics.median(new[n] / old[n] for n in shared
                                  if old[n] > 0)
        rows.append(dict(arm=arm, programs=len(shared),
                         median_ns_per_run_ratio=round(ratio, 3),
                         heavier=sum(1 for n in shared if new[n] > old[n])))
    return dict(app=label, arms=rows)


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--old", required=True, help="archived app JSON")
    ap.add_argument("--new", required=True, help="current app JSON")
    ap.add_argument("--app", required=True)
    args = ap.parse_args(argv[1:])
    print(json.dumps(compare(args.old, args.new, args.app), indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))