#!/usr/bin/env python3
from __future__ import annotations

import argparse
import sys
from pathlib import Path

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from e2e.common import DEFAULT_VENV_ACTIVATE, ROOT_DIR, tail_text, write_json, write_text  # noqa: E402
from e2e.common.vm import run_in_vm, write_guest_script  # noqa: E402
from e2e.cases.bpftrace.case import (  # noqa: E402
    DEFAULT_OUTPUT_JSON as DEFAULT_BPFTRACE_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD as DEFAULT_BPFTRACE_OUTPUT_MD,
    DEFAULT_REPORT_MD as DEFAULT_BPFTRACE_REPORT_MD,
    build_markdown as build_bpftrace_markdown,
    build_report as build_bpftrace_report,
    run_case as run_bpftrace_case,
)
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
    parser.add_argument("case", choices=("tracee", "tetragon", "bpftrace", "scx"))
    parser.add_argument("--vm", action="store_true", help="Run the benchmark inside a virtme-ng guest.")
    parser.add_argument("--kernel", help="Kernel image used with --vm.")
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
    parser.add_argument("--runner", default=str(ROOT_DIR / "micro" / "build" / "runner" / "micro_exec"))
    parser.add_argument("--scanner", default=str(ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"))
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
    parser.add_argument("--bpftool-binary", default="/usr/local/sbin/bpftool")
    parser.add_argument("--bpftool", help="Explicit bpftool path for Tetragon runs.")
    parser.add_argument("--scheduler-extra-arg", action="append", default=[])
    parser.add_argument("--cpus", type=int, default=2, help="Guest CPU count for --vm runs.")
    parser.add_argument("--mem", default="4G", help="Guest memory size for --vm runs.")
    parser.add_argument("--timeout", type=int, default=2400, help="VM timeout in seconds.")
    parser.add_argument("--skip-setup", action="store_true", help=argparse.SUPPRESS)
    return parser


def run_tracee_vm(args: argparse.Namespace) -> int:
    if not args.kernel:
        raise SystemExit("--kernel is required with --vm")

    guest_command = [
        "python3",
        "e2e/run.py",
        "tracee",
        "--output-json",
        str(Path(args.output_json).resolve()),
        "--output-md",
        str(Path(args.output_md).resolve()),
        "--config",
        str(Path(args.config).resolve()),
        "--setup-script",
        str(Path(args.setup_script).resolve()),
        "--tracee-object",
        str(Path(args.tracee_object).resolve()),
        "--runner",
        str(Path(args.runner).resolve()),
        "--scanner",
        str(Path(args.scanner).resolve()),
        "--load-timeout",
        str(int(args.load_timeout)),
        "--skip-setup",
    ]
    if args.smoke:
        guest_command.append("--smoke")
    if args.duration is not None:
        guest_command.extend(["--duration", str(int(args.duration))])
    if args.tracee_binary:
        guest_command.extend(["--tracee-binary", str(Path(args.tracee_binary).resolve())])
    for extra_arg in args.tracee_extra_arg or []:
        guest_command.extend(["--tracee-extra-arg", extra_arg])

    guest_script = write_guest_script(
        [
            ["bash", str(Path(args.setup_script).resolve())],
            guest_command,
        ]
    )
    completed = run_in_vm(args.kernel, guest_script, args.cpus, args.mem, args.timeout)
    sys.stdout.write(completed.stdout)
    sys.stderr.write(completed.stderr)
    if completed.returncode != 0:
        raise SystemExit(
            f"vng run failed with exit {completed.returncode}: {tail_text(completed.stderr or completed.stdout)}"
        )
    return 0


def run_scx_vm(args: argparse.Namespace) -> int:
    if not args.kernel:
        raise SystemExit("--kernel is required with --vm")

    guest_command = [
        "python3",
        "e2e/run.py",
        "scx",
        "--output-json",
        str(Path(args.output_json).resolve()),
        "--output-md",
        str(Path(args.output_md).resolve()),
        "--scheduler-binary",
        str(Path(args.scheduler_binary).resolve()),
        "--scheduler-object",
        str(Path(args.scheduler_object).resolve()),
        "--scx-repo",
        str(Path(args.scx_repo).resolve()),
        "--scanner",
        str(Path(args.scanner).resolve()),
        "--bpftool-binary",
        str(Path(args.bpftool_binary).resolve()),
        "--load-timeout",
        str(int(args.load_timeout)),
    ]
    if args.smoke:
        guest_command.append("--smoke")
    if args.duration is not None:
        guest_command.extend(["--duration", str(int(args.duration))])
    for extra_arg in args.scheduler_extra_arg or []:
        guest_command.extend(["--scheduler-extra-arg", extra_arg])

    guest_script = write_guest_script([guest_command])
    completed = run_in_vm(args.kernel, guest_script, args.cpus, args.mem, args.timeout)
    sys.stdout.write(completed.stdout)
    sys.stderr.write(completed.stderr)
    if completed.returncode != 0:
        raise SystemExit(
            f"vng run failed with exit {completed.returncode}: {tail_text(completed.stderr or completed.stdout)}"
        )
    return 0


def persist_bpftrace_results(args: argparse.Namespace, payload: dict[str, object]) -> None:
    write_json(Path(args.output_json).resolve(), payload)
    write_text(Path(args.output_md).resolve(), build_bpftrace_markdown(payload) + "\n")
    write_text(Path(args.report_md).resolve(), build_bpftrace_report(payload) + "\n")


def apply_case_defaults(args: argparse.Namespace) -> None:
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
    apply_case_defaults(args)
    if args.vm:
        if args.case == "tracee":
            return run_tracee_vm(args)
        if args.case == "scx":
            return run_scx_vm(args)
        if args.case in {"tetragon", "bpftrace"}:
            raise SystemExit(f"--vm is not yet supported for {args.case}")
        raise SystemExit(f"unsupported e2e case: {args.case}")

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
    raise SystemExit(f"unsupported e2e case: {args.case}")


if __name__ == "__main__":
    raise SystemExit(main())
