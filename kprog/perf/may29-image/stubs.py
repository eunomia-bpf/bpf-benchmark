#!/usr/bin/env python3
"""Report tiny program candidates and whether they carried work.

Size alone cannot distinguish an intentional empty application function from
a fallback body. Tracee's empty_kprobe is one intentional example. Source or
disassembly establishes that distinction; this report retains every candidate.

For an established fallback, its invocation count quantifies affected work.
Tiny intentional functions also execute legitimately. Both remain reported.

Usage: stubs.py <run>... [--max-bytes N]

Each argument is a corpus result directory. Prints one line per (run, app, phase)
that has a candidate, then a summary.
"""
import argparse
import json
import pathlib
import sys

# Shape thresholds only: intentional empty functions can have the same sizes.
# A normal native stub's xlated size also does not describe the native body.
FALLBACK_BYTES = 40
FALLBACK_XLATED = 24


def phases(app: dict) -> dict[str, dict]:
    """The per-program records of one application, by phase."""
    out = {}
    for phase in ("baseline", "post_rejit"):
        bpf = app.get(phase, {}).get("bpf")
        if bpf:
            out[phase] = bpf
    return out


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("runs", nargs="+", type=pathlib.Path)
    parser.add_argument("--max-bytes", type=int, default=FALLBACK_BYTES,
                        help="report programs at or below this jited size")
    parser.add_argument("--max-xlated", type=int, default=FALLBACK_XLATED,
                        help="and at or below this many original bytes")
    args = parser.parse_args()

    stubbed = 0
    with_work = 0
    for run in args.runs:
        apps = run / "details" / "apps"
        if not apps.is_dir():
            sys.exit(f"{run}: no details/apps directory")
        for path in sorted(apps.glob("*.json")):
            app = json.loads(path.read_text())
            name = path.stem
            for phase, programs in phases(app).items():
                stubs = [v for v in programs.values()
                         if v.get("bytes_jited", 0) <= args.max_bytes
                         and v.get("bytes_xlated", 0) <= args.max_xlated]
                if not stubs:
                    continue
                runs = sum(v.get("run_cnt_delta", 0) for v in stubs)
                ns = sum(v.get("run_time_ns_delta", 0) for v in stubs)
                stubbed += len(stubs)
                with_work += sum(v.get("run_cnt_delta", 0) > 0 for v in stubs)
                kinds = sorted({(v["name"], v["bytes_jited"], v["bytes_xlated"])
                                for v in stubs})
                print(f"{run.name} {name} {phase}: {len(stubs)} tiny candidates, "
                      f"runs {runs}, ns {ns}")
                for kind_name, jited, xlated in kinds:
                    print(f"    {kind_name:20} jited {jited:4} xlated {xlated:4}")
    print(f"total {stubbed} tiny-program candidates, {with_work} of them carried work"
          " -- size alone does not establish a fallback or differing work")


if __name__ == "__main__":
    main()
