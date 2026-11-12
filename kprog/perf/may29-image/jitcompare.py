#!/usr/bin/env python3
"""Compare the jited size of each program between two runs.

A specialized object is only useful if the smaller program is the one the guest
actually runs, and the object on disk is not that proof: the guest reports
bytes_jited per program in its own result, so the pair of runs settles it. The
build-time report (vendor/bpf/native_specialize_objects.py) says what clang
produced; this says what the kernel compiled, which is what a timing difference
can be attributed to.

Usage: jitcompare.py <plain-run> <specialized-run> [--min-runs N]

Each run is a corpus result directory. Prints one line per program present in
both, with the two jited sizes and the change, then the totals.
"""
import argparse
import json
import pathlib
import sys


def programs(run: pathlib.Path) -> dict[str, dict]:
    """Every program the run reports, keyed by name.

    A run records one entry per (app, program) under details/apps/<app>.json in
    the post_rejit phase. The name alone does not identify a program: cilium
    loads a dozen distinct programs whose label is truncated to the same 15
    characters, and neither the id nor the jited size carries across runs, so a
    name is compared as a group: how many programs the run compiled under it and
    the bytes they total.
    """
    found: dict[tuple, dict] = {}
    apps = run / "details" / "apps"
    if not apps.is_dir():
        sys.exit(f"{run}: no details/apps directory")
    for path in sorted(apps.glob("*.json")):
        app = json.loads(path.read_text())
        for entry in app.get("post_rejit", {}).get("bpf", {}).values():
            name = entry.get("name", "")
            if not name:
                continue
            key = (path.stem.split("__")[0], name)
            group = found.setdefault(key, {"programs": 0, "jited": 0,
                                           "runs": 0})
            group["programs"] += 1
            group["jited"] += entry.get("bytes_jited", 0)
            group["runs"] += entry.get("run_cnt_delta", 0)
    return found


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("plain", type=pathlib.Path)
    parser.add_argument("specialized", type=pathlib.Path)
    parser.add_argument("--min-runs", type=int, default=0,
                        help="only programs with at least this many runs")
    args = parser.parse_args()

    plain, specialized = programs(args.plain), programs(args.specialized)
    only_plain = sorted(set(plain) - set(specialized))
    only_spec = sorted(set(specialized) - set(plain))
    rows = []
    for key in sorted(set(plain) & set(specialized)):
        a, b = plain[key], specialized[key]
        if a["runs"] < args.min_runs:
            continue
        before = (a["programs"], a["jited"])
        after = (b["programs"], b["jited"])
        if before != after:
            rows.append((key, before, after))
    rows.sort(key=lambda row: row[2][1] - row[1][1])
    print(f"{'program':40} {'plain':>16} {'specialized':>16} {'delta':>8}")
    print(f"{'':40} {'n':>6} {'bytes':>9} {'n':>6} {'bytes':>9}")
    for key, before, after in rows:
        print(f"{key[1][:40]:40} {before[0]:6} {before[1]:9} "
              f"{after[0]:6} {after[1]:9} {after[1] - before[1]:+8}")
    total = (sum(row[1][1] for row in rows), sum(row[2][1] for row in rows))
    print(f"{'changed names':40} {sum(r[1][0] for r in rows):6} {total[0]:9} "
          f"{sum(r[2][0] for r in rows):6} {total[1]:9} {total[1] - total[0]:+8}")
    if only_plain or only_spec:
        print(f"not in both runs: {len(only_plain)} only plain, "
              f"{len(only_spec)} only specialized", file=sys.stderr)


if __name__ == "__main__":
    main()