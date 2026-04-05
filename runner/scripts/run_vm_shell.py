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
    parser.add_argument("--action", required=True, help="Logical suite action name for queue metadata.")
    parser.add_argument("--vm-backend", required=True, help="Explicit VM backend for execution.")
    parser.add_argument("--vm-lock-scope", required=True, help="Explicit VM lock scope.")
    parser.add_argument("--vm-machine-name", required=True, help="Explicit VM machine name for queue metadata.")
    parser.add_argument("--vm-machine-arch", required=True, help="Explicit VM architecture for queue metadata.")
    parser.add_argument("--kernel-image", required=True, help="Kernel image passed to the VM backend.")
    parser.add_argument("--cpus", type=int, help="Optional guest CPU count override.")
    parser.add_argument("--mem", help="Optional guest memory override.")
    parser.add_argument("--nofile", type=int, help="Optional guest RLIMIT_NOFILE soft/hard value.")
    parser.add_argument(
        "--vm-executable",
        required=True,
        help="Backend executable path (for example a custom vng binary).",
    )
    parser.add_argument("--timeout", type=int, default=3600, help="End-to-end timeout in seconds.")
    parser.add_argument("--network", action="append", default=[], help="Repeatable VM network configuration.")
    parser.add_argument("--command", required=True, help="Shell command to run inside the guest.")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    guest_script = write_guest_script([args.command], nofile=args.nofile)
    completed = run_in_vm(
        args.kernel_image,
        guest_script,
        args.cpus,
        args.mem,
        args.timeout,
        vm_executable=args.vm_executable,
        action=args.action,
        machine_backend=args.vm_backend,
        machine_lock_scope=args.vm_lock_scope,
        machine_name=args.vm_machine_name,
        machine_arch=args.vm_machine_arch,
        networks=args.network or (),
    )
    if completed.stdout:
        sys.stdout.write(completed.stdout)
    if completed.stderr:
        sys.stderr.write(completed.stderr)
    return completed.returncode


if __name__ == "__main__":
    raise SystemExit(main())
