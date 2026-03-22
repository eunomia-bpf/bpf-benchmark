#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import write_json  # noqa: E402
from runner.libs.profiler import DEFAULT_PERF_EVENTS, DEFAULT_DAEMON, profile_current_programs  # noqa: E402


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Collect runtime BPF program profile data from live programs."
    )
    parser.add_argument("--prog-id", action="append", dest="prog_ids", type=int, help="Repeatable live prog_id filter.")
    parser.add_argument(
        "--name-contains",
        action="append",
        default=[],
        help="Repeatable substring filter for live program names.",
    )
    parser.add_argument(
        "--type",
        action="append",
        dest="types",
        default=[],
        help="Repeatable exact-match filter for bpftool program types.",
    )
    parser.add_argument("--duration", type=float, default=30.0, help="Profiling window in seconds.")
    parser.add_argument(
        "--daemon",
        default=str(DEFAULT_DAEMON),
        help="Path to bpfrejit-daemon used for live enumerate.",
    )
    parser.add_argument(
        "--output",
        help="Optional JSON output path. Defaults to stdout when omitted.",
    )
    parser.add_argument(
        "--perf-events",
        default=",".join(DEFAULT_PERF_EVENTS),
        help="Comma-separated perf stat events. Default: cycles,instructions,branches,branch-misses",
    )
    parser.add_argument(
        "--perf-max-workers",
        type=int,
        default=8,
        help="Maximum parallel perf stat workers.",
    )
    parser.add_argument(
        "--no-sites",
        action="store_true",
        help="Skip daemon enumerate site census collection.",
    )
    parser.add_argument(
        "--no-perf",
        action="store_true",
        help="Skip perf stat collection.",
    )
    return parser


def parse_csv_tokens(value: str) -> list[str]:
    return [token.strip() for token in str(value).split(",") if token.strip()]


def main(argv: list[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    payload = profile_current_programs(
        prog_ids=args.prog_ids,
        duration_s=float(args.duration),
        daemon_binary=Path(args.daemon).resolve(),
        name_contains=args.name_contains,
        type_equals=args.types,
        include_sites=not bool(args.no_sites),
        collect_perf=not bool(args.no_perf),
        perf_events=parse_csv_tokens(args.perf_events),
        perf_max_workers=max(1, int(args.perf_max_workers)),
        metadata={"tool": "runner/scripts/bpf_profiler.py"},
    )
    if args.output:
        write_json(Path(args.output).resolve(), payload)
        return 0
    sys.stdout.write(json.dumps(payload, indent=2, sort_keys=True) + "\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
