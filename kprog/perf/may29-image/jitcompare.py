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
    characters, and the number of instances varies run to run (tetragon attaches
    13 to 18 of each), so what is counted is the SET of jited sizes under a name:
    each distinct size is one kind of program, and its instances are incidental.
    A kind present at the same size in both runs did not change; a kind that
    shrinks is the specialization reaching the guest.
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
            group = found.setdefault(key, {"sizes": [], "runs": 0,
                                           "instances": 0})
            size = entry.get("bytes_jited", 0)
            if size not in group["sizes"]:
                group["sizes"].append(size)
            group["instances"] += 1
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
        before, after = sorted(a["sizes"]), sorted(b["sizes"])
        if before != after:
            rows.append((key, before, after))
    rows.sort(key=lambda row: sum(row[2]) - sum(row[1]))
    print(f"{'program':30} {'plain jited sizes':<32} "
          f"{'specialized jited sizes':<32} {'delta':>8}")
    for key, before, after in rows:
        print(f"{key[1][:30]:30} {str(before)[:32]:<32} {str(after)[:32]:<32} "
              f"{sum(after) - sum(before):+8}")
    total = (sum(map(sum, (row[1] for row in rows))),
             sum(map(sum, (row[2] for row in rows))))
    print(f"{'changed names':30} {len(rows)} names, {total[0]} -> {total[1]} "
          f"bytes over the distinct kinds")
    if only_plain or only_spec:
        print(f"not in both runs: {len(only_plain)} only plain, "
              f"{len(only_spec)} only specialized", file=sys.stderr)


if __name__ == "__main__":
    main()