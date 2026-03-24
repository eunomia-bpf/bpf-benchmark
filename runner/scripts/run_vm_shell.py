#!/usr/bin/env python3
from __future__ import annotations

import argparse
import sys
from pathlib import Path

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs.vm import run_in_vm, write_guest_script  # noqa: E402


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run a shell command inside a runner-managed VM.")
    parser.add_argument("--action", required=True, help="Machine action name from runner/machines.yaml.")
    parser.add_argument("--target", help="Optional machine target or alias override.")
    parser.add_argument("--kernel-image", required=True, help="Kernel image passed to the VM backend.")
    parser.add_argument("--cpus", type=int, help="Optional guest CPU count override.")
    parser.add_argument("--mem", help="Optional guest memory override.")
    parser.add_argument("--timeout", type=int, default=3600, help="End-to-end timeout in seconds.")
    parser.add_argument("--network", action="append", default=[], help="Repeatable VM network configuration.")
    parser.add_argument("--command", required=True, help="Shell command to run inside the guest.")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    guest_script = write_guest_script([args.command])
    completed = run_in_vm(
        args.kernel_image,
        guest_script,
        args.cpus,
        args.mem,
        args.timeout,
        target=args.target or None,
        action=args.action,
        networks=args.network or (),
    )
    if completed.stdout:
        sys.stdout.write(completed.stdout)
    if completed.stderr:
        sys.stderr.write(completed.stderr)
    return completed.returncode


if __name__ == "__main__":
    raise SystemExit(main())
