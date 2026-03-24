#!/usr/bin/env python3
from __future__ import annotations

import argparse
import fcntl
import json
import os
import subprocess
import sys
import time
from pathlib import Path
from typing import Any

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs.machines import lock_path_for_machine, queue_path_for_machine, resolve_machine  # noqa: E402


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run a VM-related command under the runner VM lock.")
    parser.add_argument("--target", help="Machine target or alias from runner/machines.yaml.")
    parser.add_argument("--action", help="Optional action name used to resolve the default machine.")
    parser.add_argument("command", nargs=argparse.REMAINDER, help="Command to execute after --.")
    return parser.parse_args()


def _update_queue_state(queue_path: Path, payload: dict[str, Any]) -> None:
    queue_path.parent.mkdir(parents=True, exist_ok=True)
    queue_path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n")


def main() -> int:
    args = parse_args()
    command = list(args.command)
    if command and command[0] == "--":
        command = command[1:]
    if not command:
        raise SystemExit("with_vm_lock.py requires a command after --")

    machine = resolve_machine(target=args.target, action=args.action)
    lock_path = lock_path_for_machine(target=args.target, action=args.action)
    queue_path = queue_path_for_machine(target=args.target, action=args.action)
    started_waiting = time.time()
    payload: dict[str, Any] = {
        "status": "queued",
        "pid": os.getpid(),
        "action": args.action,
        "target": args.target,
        "machine": machine.name,
        "backend": machine.backend,
        "arch": machine.arch,
        "lock_scope": machine.lock_scope,
        "lock_path": str(lock_path),
        "command": command,
        "queued_at": started_waiting,
    }
    _update_queue_state(queue_path, payload)
    with lock_path.open("a+") as handle:
        fcntl.flock(handle.fileno(), fcntl.LOCK_EX)
        payload["status"] = "running"
        payload["started_at"] = time.time()
        payload["wait_seconds"] = max(0.0, payload["started_at"] - started_waiting)
        _update_queue_state(queue_path, payload)
        completed = subprocess.run(command, check=False)
        payload["status"] = "completed"
        payload["finished_at"] = time.time()
        payload["returncode"] = completed.returncode
        payload["run_seconds"] = max(0.0, payload["finished_at"] - payload["started_at"])
        _update_queue_state(queue_path, payload)
        return completed.returncode


if __name__ == "__main__":
    raise SystemExit(main())
