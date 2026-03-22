#!/usr/bin/env python3
from __future__ import annotations

import argparse
import sys
from pathlib import Path

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from runner.libs import (  # noqa: E402
    ROOT_DIR,
    prepare_bpftool_environment,
    write_json,
    write_text,
)
from e2e.cases.bpftrace.case import (  # noqa: E402
    DEFAULT_OUTPUT_JSON as DEFAULT_BPFTRACE_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD as DEFAULT_BPFTRACE_OUTPUT_MD,
    DEFAULT_REPORT_MD as DEFAULT_BPFTRACE_REPORT_MD,
    build_markdown as build_bpftrace_markdown,
    build_report as build_bpftrace_report,
    run_case as run_bpftrace_case,
)
from e2e.cases.katran.case import (  # noqa: E402
    DEFAULT_KATRAN_OBJECT as DEFAULT_KATRAN_CASE_OBJECT,
    DEFAULT_OUTPUT_JSON as DEFAULT_KATRAN_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD as DEFAULT_KATRAN_OUTPUT_MD,
    DEFAULT_SETUP_SCRIPT as DEFAULT_KATRAN_SETUP_SCRIPT,
    persist_results as persist_katran_results,
    run_katran_case,
)
DEFAULT_KATRAN_POLICY_FILE = ROOT_DIR / "e2e" / "cases" / "katran" / "balancer_ingress.e2e.policy.yaml"
from e2e.cases.scx.case import (  # noqa: E402
    DEFAULT_OUTPUT_JSON as DEFAULT_SCX_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD as DEFAULT_SCX_OUTPUT_MD,
    run_scx_case,
    persist_results as persist_scx_results,
)
from e2e.cases.tetragon.case import (  # noqa: E402
    DEFAULT_EXECVE_OBJECT as DEFAULT_TETRAGON_EXECVE_OBJECT,
    DEFAULT_KPROBE_OBJECT as DEFAULT_TETRAGON_KPROBE_OBJECT,
    DEFAULT_OUTPUT_JSON as DEFAULT_TETRAGON_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD as DEFAULT_TETRAGON_OUTPUT_MD,
    DEFAULT_SETUP_SCRIPT as DEFAULT_TETRAGON_SETUP_SCRIPT,
    persist_results as persist_tetragon_results,
    run_tetragon_case,
)
from e2e.cases.tracee.case import (  # noqa: E402
    DEFAULT_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD,
    DEFAULT_SETUP_SCRIPT as DEFAULT_TRACEE_SETUP_SCRIPT,
    run_tracee_case,
    persist_results,
)


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Unified entrypoint for repository end-to-end benchmarks.")
    parser.add_argument("case", choices=("tracee", "tetragon", "bpftrace", "scx", "katran"))
    parser.add_argument("--smoke", action="store_true", help="Run the smoke-sized configuration.")
    parser.add_argument("--dry-run", action="store_true", help="Resolve the execution plan without running the live workload.")
    parser.add_argument("--duration", type=int, help="Override the per-workload duration in seconds.")
    parser.add_argument("--tracee-binary", help="Explicit Tracee binary path.")
    parser.add_argument("--tetragon-binary", help="Explicit Tetragon binary path.")
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--report-md", default=str(DEFAULT_BPFTRACE_REPORT_MD))
    parser.add_argument("--config", default=str(ROOT_DIR / "e2e" / "cases" / "tracee" / "config.yaml"))
    parser.add_argument("--setup-script", default=str(DEFAULT_TRACEE_SETUP_SCRIPT))
    parser.add_argument("--tracee-object", default=str(ROOT_DIR / "corpus" / "build" / "tracee" / "tracee.bpf.o"))
    parser.add_argument("--execve-object", default=str(DEFAULT_TETRAGON_EXECVE_OBJECT))
    parser.add_argument("--kprobe-object", default=str(DEFAULT_TETRAGON_KPROBE_OBJECT))
    parser.add_argument("--runner", default=str(ROOT_DIR / "runner" / "build" / "micro_exec"))
    parser.add_argument("--daemon", default=str(ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"))
    parser.add_argument("--load-timeout", type=int, default=20)
    parser.add_argument("--attach-timeout", type=int, default=20)
    parser.add_argument("--smoke-duration", type=int, default=5)
    parser.add_argument("--tracee-extra-arg", action="append", default=[])
    parser.add_argument("--script", action="append", dest="scripts")
    parser.add_argument("--skip-build", action="store_true")
    parser.add_argument("--force-direct", action="store_true")
    parser.add_argument("--scheduler-binary", default=str(ROOT_DIR / "corpus" / "repos" / "scx" / "target" / "release" / "scx_rusty"))
    parser.add_argument("--scheduler-object", default=str(ROOT_DIR / "corpus" / "build" / "scx" / "scx_rusty_main.bpf.o"))
    parser.add_argument("--scx-repo", default=str(ROOT_DIR / "corpus" / "repos" / "scx"))
    parser.add_argument("--katran-object", default=str(DEFAULT_KATRAN_CASE_OBJECT))
    parser.add_argument("--katran-policy", default=str(DEFAULT_KATRAN_POLICY_FILE))
    parser.add_argument("--katran-server-binary", help="Explicit Katran server binary path.")
    parser.add_argument("--katran-iface", default="katran0")
    parser.add_argument("--katran-router-peer-iface")
    parser.add_argument("--katran-packet-repeat", type=int)
    parser.add_argument("--katran-use-wrk", action="store_true")
    parser.add_argument("--katran-wrk-connections", type=int)
    parser.add_argument("--katran-wrk-threads", type=int)
    parser.add_argument("--katran-warmup-duration", type=float)
    parser.add_argument("--katran-samples", type=int)
    parser.add_argument("--katran-skip-attach", action="store_true")
    parser.add_argument("--kernel-config", default=str(ROOT_DIR / "vendor" / "linux-framework" / ".config"))
    parser.add_argument("--bpftool-binary", default="/usr/local/sbin/bpftool")
    parser.add_argument("--bpftool", help="Explicit bpftool path for Tetragon runs.")
    parser.add_argument("--scheduler-extra-arg", action="append", default=[])
    parser.add_argument("--skip-setup", action="store_true", help=argparse.SUPPRESS)
    return parser


def persist_bpftrace_results(args: argparse.Namespace, payload: dict[str, object]) -> None:
    write_json(Path(args.output_json).resolve(), payload)
    write_text(Path(args.output_md).resolve(), build_bpftrace_markdown(payload) + "\n")
    write_text(Path(args.report_md).resolve(), build_bpftrace_report(payload) + "\n")


def apply_case_defaults(args: argparse.Namespace) -> None:
    if args.case == "katran":
        if args.output_json == str(DEFAULT_OUTPUT_JSON):
            args.output_json = str(DEFAULT_KATRAN_OUTPUT_JSON)
        if args.output_md == str(DEFAULT_OUTPUT_MD):
            args.output_md = str(DEFAULT_KATRAN_OUTPUT_MD)
        if args.setup_script == str(DEFAULT_TRACEE_SETUP_SCRIPT):
            args.setup_script = str(DEFAULT_KATRAN_SETUP_SCRIPT)
        return

    if args.case == "scx":
        if args.output_json == str(DEFAULT_OUTPUT_JSON):
            args.output_json = str(DEFAULT_SCX_OUTPUT_JSON)
        if args.output_md == str(DEFAULT_OUTPUT_MD):
            args.output_md = str(DEFAULT_SCX_OUTPUT_MD)
        return

    if args.case == "tetragon":
        if args.output_json == str(DEFAULT_OUTPUT_JSON):
            args.output_json = str(DEFAULT_TETRAGON_OUTPUT_JSON)
        if args.output_md == str(DEFAULT_OUTPUT_MD):
            args.output_md = str(DEFAULT_TETRAGON_OUTPUT_MD)
        if args.setup_script == str(DEFAULT_TRACEE_SETUP_SCRIPT):
            args.setup_script = str(DEFAULT_TETRAGON_SETUP_SCRIPT)
        if not args.bpftool:
            args.bpftool = args.bpftool_binary
        return

    if args.case == "bpftrace":
        if args.output_json == str(DEFAULT_OUTPUT_JSON):
            args.output_json = str(DEFAULT_BPFTRACE_OUTPUT_JSON)
        if args.output_md == str(DEFAULT_OUTPUT_MD):
            args.output_md = str(DEFAULT_BPFTRACE_OUTPUT_MD)


def main(argv: list[str] | None = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)
    prepare_bpftool_environment()
    apply_case_defaults(args)

    if args.case == "tracee":
        payload = run_tracee_case(args)
        persist_results(payload, Path(args.output_json).resolve(), Path(args.output_md).resolve())
        return 0
    if args.case == "tetragon":
        payload = run_tetragon_case(args)
        persist_tetragon_results(payload, Path(args.output_json).resolve(), Path(args.output_md).resolve())
        return 0
    if args.case == "bpftrace":
        payload = run_bpftrace_case(args)
        persist_bpftrace_results(args, payload)
        return 0
    if args.case == "scx":
        payload = run_scx_case(args)
        persist_scx_results(payload, Path(args.output_json).resolve(), Path(args.output_md).resolve())
        return 0
    if args.case == "katran":
        payload = run_katran_case(args)
        persist_katran_results(payload, Path(args.output_json).resolve(), Path(args.output_md).resolve())
        return 0
    raise SystemExit(f"unsupported e2e case: {args.case}")


if __name__ == "__main__":
    raise SystemExit(main())
