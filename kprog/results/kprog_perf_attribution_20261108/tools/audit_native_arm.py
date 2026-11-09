"""Audit a corpus run before its numbers go into a table.

Three failures produced near-miss results in this report, and each is
detectable from the run directory alone:

1. The shim was off, so both arms ran the same eBPF code.  The arms then
   record identical ``bytes_jited`` per program.
2. The runner recorded ``status: ok`` while an arm never completed.  Only one
   of ``baseline`` / ``post_rejit`` is present.
3. The run was short.  Every table row must be SAMPLES=3 at 180 s, which is
   a per-arm duration of about 540 s.

Usage: python3 tools/audit_native_arm.py <run-dir> [<run-dir> ...]

Exits 1 if any app in any run fails a check, so it can gate a table.
"""
from __future__ import annotations

import glob
import json
import sys

EXPECTED_SAMPLES = 3
EXPECTED_SECONDS = 540.0
# A warmup pass can pad an arm past 540 s by a few seconds; a short run
# misses by a whole sample (180 s), so a 15-second window separates them.
TOLERANCE = 15.0


def _arm_seconds(arm: dict) -> float | None:
    """Sum an arm's measured seconds, from workloads or their components.

    Corpus runners record duration on the workload for pktgen workloads and
    on the individual components for multi-process ones, so accept either.
    """
    total = 0.0
    for workload in arm["workloads"]:
        if "duration_s" in workload:
            total += workload["duration_s"]
        else:
            # Components of one sample run concurrently, so the sample lasts
            # as long as its longest component, not their sum.
            total += max((c.get("duration_s", 0.0)
                          for c in workload.get("components", [])), default=0.0)
    return total or None


def audit(path: str) -> tuple[str, str]:
    """Return (verdict, detail) for one per-app result file."""
    result = json.load(open(path))
    if result.get("status") != "ok":
        return "bad-status", str(result.get("status"))

    baseline, native = result.get("baseline"), result.get("post_rejit")
    if not (baseline and native):
        return "missing-arm", "baseline" if not baseline else "post_rejit"

    samples = [len(baseline["workloads"]), len(native["workloads"])]
    if any(count != EXPECTED_SAMPLES for count in samples):
        return "short-run", f"samples {samples}"

    seconds = [_arm_seconds(arm) for arm in (baseline, native)]
    if any(value is not None and abs(value - EXPECTED_SECONDS) > TOLERANCE
           for value in seconds):
        return "short-run", f"durations {[round(s, 1) for s in seconds]}"

    jit_bytes = sorted(v["bytes_jited"] for v in baseline["bpf"].values())
    native_bytes = sorted(v["bytes_jited"] for v in native["bpf"].values())
    if not jit_bytes or not native_bytes:
        return "no-programs", f"{len(jit_bytes)} vs {len(native_bytes)}"
    if jit_bytes == native_bytes:
        return "same-code", f"{len(jit_bytes)} programs, identical bytes"

    return "native", f"{len(jit_bytes)} vs {len(native_bytes)} programs"


def main(argv: list[str]) -> int:
    if not argv:
        print(__doc__.strip().splitlines()[-2], file=sys.stderr)
        return 2
    bad = 0
    for run in argv:
        for path in sorted(glob.glob(f"{run}/details/apps/*.json")):
            verdict, detail = audit(path)
            name = path.rsplit("/", 1)[-1]
            print(f"{name:32s} {verdict:12s} {detail}")
            if verdict != "native":
                bad += 1
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))