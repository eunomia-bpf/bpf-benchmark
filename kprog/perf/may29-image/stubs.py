#!/usr/bin/env python3
"""Report every program a run loaded as a stub, and whether it carried work.

A program whose jited size is a few dozen bytes is the JIT's fallback body, not
the program's own code: the native loader had no image for it, so the kernel
compiled r0 = 0. That is a fallback (AGENTS.md:105 forbids one), and an audit of
this project voided four applications' floor comparisons over it.

What decides whether a run's numbers are affected is not the stub's presence but
its work: a stub with zero executions contributes nothing to ns/inv, while one
that runs is measured in place of the real program. Both are reported.

Usage: stubs.py <run>... [--max-bytes N]

Each argument is a corpus result directory. Prints one line per (run, app, phase)
that has a stub, then a summary.
"""
import argparse
import json
import pathlib
import sys

# The fallback body the x86 JIT emits for a program with no instructions. A
# program that is genuinely tiny has a small original too (tracee's empty_kprobe
# loads 16 bytes of original and is called that), so the stub is identified by
# both: a small jited body OVER a small original. BCC's fentry_vfs_* are 40 bytes
# jited from 48 bytes of original, six real instructions, and are not stubs.
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
                        help="a program at or below this jited size is a stub")
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
                if runs:
                    with_work += len(stubs)
                kinds = sorted({(v["name"], v["bytes_jited"], v["bytes_xlated"])
                                for v in stubs})
                print(f"{run.name} {name} {phase}: {len(stubs)} stubs, "
                      f"runs {runs}, ns {ns}")
                for kind_name, jited, xlated in kinds:
                    print(f"    {kind_name:20} jited {jited:4} xlated {xlated:4}")
    print(f"total {stubbed} stub records, {with_work} of them carried work"
          + (" -- these distort the run" if with_work else
             " -- none affected any ns/inv figure"))


if __name__ == "__main__":
    main()