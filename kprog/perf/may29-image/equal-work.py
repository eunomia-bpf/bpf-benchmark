#!/usr/bin/env python3
"""Compare what each arm actually did, not just how long it took.

An improvement measured per invocation is only an improvement if both arms did the
same work. OTel's native_tracer_entry showing 18x fewer ns per entry, or
tetragon's generic_kprobe 15x, could be cheaper work or could be less work -- the
two arms run the same workload for the same wall time, so a faster kernel can
simply complete more of it, and then the per-invocation ratio compares a full
invocation against one that did less.

This reads the work each arm's own artifacts recorded, without touching the
framework:

  - the workload's own counters, per arm. For OTel that is each interpreter's
    `int_loop ops=` line, which is the number of interpreted loops the tracer
    actually unwound; for tetragon the stress-ng bogo ops.
  - run_cnt of every BPF program in both arms, from the run's own counters.
  - which programs are tail-call targets, and therefore report run_cnt 0 even
    though they execute: the tail-call entry point skips the prologue that
    updates bpf_prog->stats.

Usage: equal-work.py <run> [<run>...]

Each argument is a corpus result directory. Prints, per application and phase,
the workload counters side by side and the per-program run counts.
"""
import json
import pathlib
import re
import sys

# OTel's tracer prints one line per interpreter process per workload arm.
INTERPRETER_LINE = re.compile(r"(\w+) int_loop ops=(\d+) elapsed_s=([\d.]+)")
# stress-ng's metric line: name bogo_ops real usr sys bogo/s(real) bogo/s(cpu)
STRESS_NG_LINE = re.compile(
    r"stress-ng: metrc: \[\d+\] (\w+)\s+(\d+)\s+[\d.]+\s+[\d.]+\s+[\d.]+\s+([\d.]+)")


def workload_counters(workloads: list[dict]) -> dict[str, int]:
    """The work an arm's workload reported, by the workload's own accounting."""
    out: dict[str, int] = {}
    for workload in workloads:
        for component in workload.get("components") or ():
            for line in (component.get("stderr") or "").splitlines():
                match = INTERPRETER_LINE.search(line)
                if match:
                    key = f"{match.group(1)}:int_loop"
                    out[key] = out.get(key, 0) + int(match.group(2))
            for line in (component.get("stdout") or "").splitlines():
                match = STRESS_NG_LINE.match(line)
                if match:
                    out[match.group(1)] = out.get(match.group(1), 0) + int(match.group(2))
        for line in (workload.get("stdout") or "").splitlines():
            match = STRESS_NG_LINE.match(line)
            if match:
                out[match.group(1)] = out.get(match.group(1), 0) + int(match.group(2))
    return out


def programs(app: dict, phase: str) -> dict[str, dict]:
    return (app.get(phase) or {}).get("bpf") or {}


def main() -> None:
    runs = [pathlib.Path(arg) for arg in sys.argv[1:]]
    if not runs:
        sys.exit("usage: equal-work.py <run> [<run>...]")

    for run in runs:
        apps = run / "details" / "apps"
        if not apps.is_dir():
            sys.exit(f"{run}: no details/apps directory")
        for path in sorted(apps.glob("*.json")):
            app = json.loads(path.read_text())
            name = path.stem
            phases = [p for p in ("baseline", "post_rejit") if programs(app, p)]
            if len(phases) < 2:
                print(f"{run.name} {name}: only {phases}, nothing to compare")
                continue
            print(f"== {run.name} {name} status={app.get('status')}")

            # Workload side: what the application itself counted.
            counts = {}
            for phase in phases:
                workloads = (app.get(phase) or {}).get("workloads") or []
                counts[phase] = workload_counters(workloads)
            keys = sorted({k for c in counts.values() for k in c})
            if keys:
                print(f"   {'work counter':24} {'baseline':>14} {'post_rejit':>14} {'ratio':>7}")
                for key in keys[:14]:
                    base, post = counts["baseline"].get(key, 0), counts["post_rejit"].get(key, 0)
                    ratio = f"{post / base:.3f}" if base else "-"
                    print(f"   {key:24} {base:14} {post:14} {ratio:>7}")
                tb = sum(counts["baseline"].values())
                tp = sum(counts["post_rejit"].values())
                print(f"   {'TOTAL':24} {tb:14} {tp:14} "
                      f"{(tp / tb if tb else 0):7.3f}")

            # BPF side: run counts, with the tail-call caveat stated.
            base_phase, post_phase = phases[0], phases[1]
            bp, qp = programs(app, base_phase), programs(app, post_phase)
            base_runs = sum(v.get("run_cnt_delta", 0) for v in bp.values())
            post_runs = sum(v.get("run_cnt_delta", 0) for v in qp.values())
            print(f"   {'run_cnt total':24} {base_runs:14} {post_runs:14} "
                  f"{(post_runs / base_runs if base_runs else 0):7.3f}")
            zero = [v for v in qp.values() if v.get("run_cnt_delta", 0) == 0]
            print(f"   programs reporting run_cnt 0 in post_rejit: {len(zero)} of {len(qp)}"
                  " (a tail-call target skips the prologue that counts, so 0 is"
                  " not evidence of not running)")


if __name__ == "__main__":
    main()