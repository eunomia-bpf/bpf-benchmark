#!/usr/bin/env python3
"""Compare workload throughput between two groups of runs, against measured spread.

A pair of runs cannot show an effect: run-to-run spread on a 10 s sample is
several percent, so a difference has to be judged against the spread the same
configuration produces, not against zero. This groups runs into a baseline and a
treatment, prints each stressor's bogo ops/s (the workload throughput that
AGENTS.md calls the primary measurement), and gives the change in units of the
baseline's own standard deviation.

Usage: throughput.py --plain <run>... --treatment <run>...

Each run is a corpus result directory; only runs whose application status is ok
are used. Prints one line per stressor with the baseline mean, its standard
deviation, the treatment mean, the relative change, and z.
"""
import argparse
import json
import pathlib
import re
import statistics
import sys

# stress-ng's metric line:  name  bogo_ops  real  usr  sys  bogo/s(real)  bogo/s(usr+sys)
METRIC = re.compile(
    r"stress-ng: metrc: \[\d+\] (\w+)\s+(\d+)\s+[\d.]+\s+[\d.]+\s+[\d.]+\s+([\d.]+)")


def throughput(run: pathlib.Path) -> dict[str, float] | None:
    """The workload throughput each stressor reported, or None if the run failed."""
    apps = run / "details" / "apps"
    if not apps.is_dir():
        sys.exit(f"{run}: no details/apps directory")
    for path in sorted(apps.glob("*.json")):
        app = json.loads(path.read_text())
        if app.get("status") != "ok":
            continue
        found: dict[str, float] = {}
        for workload in app.get("post_rejit", {}).get("workloads") or []:
            for line in (workload.get("stdout") or "").splitlines():
                m = METRIC.match(line)
                if m:
                    found[m.group(1)] = float(m.group(3))
        if found:
            return found
    return None


def group(runs: list[pathlib.Path]) -> dict[str, list[float]]:
    out: dict[str, list[float]] = {}
    for run in runs:
        measured = throughput(run)
        if measured is None:
            print(f"{run.name}: skipped, status not ok or no metrics", file=sys.stderr)
            continue
        for name, value in measured.items():
            out.setdefault(name, []).append(value)
    return out


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--plain", nargs="+", required=True, type=pathlib.Path)
    parser.add_argument("--treatment", nargs="+", required=True, type=pathlib.Path)
    args = parser.parse_args()

    plain, treatment = group(args.plain), group(args.treatment)
    print(f"{'stressor':12} {'plain n':>7} {'mean':>10} {'sd':>9} "
          f"{'treat n':>7} {'mean':>10} {'delta':>8} {'z':>6}   ranges")
    # A z below 2 with overlapping arms is not an effect, and with a handful of
    # samples one outlier moves the mean as much as a real change: the ranges are
    # printed next to z so a reader can see which claim the data supports.
    for name in sorted(treatment):
        a, b = plain.get(name, []), treatment[name]
        if not a or not b:
            continue
        mean, spread = statistics.mean(a), (statistics.stdev(a) if len(a) > 1 else 0.0)
        treat = statistics.mean(b)
        change = treat - mean
        z = change / spread if spread else float("nan")
        lo, hi = min(a), max(a)
        tlo, thi = min(b), max(b)
        print(f"{name:12} {len(a):7} {mean:10.0f} {spread:9.0f} "
              f"{len(b):7} {treat:10.0f} {100 * change / mean:+7.1f}% {z:+6.1f}"
              f"   ranges {lo:.0f}-{hi:.0f} / {tlo:.0f}-{thi:.0f}")


if __name__ == "__main__":
    main()