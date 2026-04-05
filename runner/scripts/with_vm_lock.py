#!/usr/bin/env python3
from __future__ import annotations

import argparse
import fcntl
import json
import os
import subprocess
import time
from pathlib import Path
from typing import Any

ROOT_DIR = Path(__file__).resolve().parents[2]
VM_LOCK_ROOT = ROOT_DIR / ".cache" / "runner" / "vm-locks"
VM_QUEUE_ROOT = ROOT_DIR / ".cache" / "runner" / "vm-queue"


def lock_path_for_scope(lock_scope: str) -> Path:
    VM_LOCK_ROOT.mkdir(parents=True, exist_ok=True)
    return VM_LOCK_ROOT / f"{lock_scope}.lock"


def queue_path_for_scope(lock_scope: str) -> Path:
    VM_QUEUE_ROOT.mkdir(parents=True, exist_ok=True)
    return VM_QUEUE_ROOT / f"{lock_scope}.json"


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run a VM-related command under the runner VM lock.")
    parser.add_argument("--action", help="Optional action name recorded in queue metadata.")
    parser.add_argument("--lock-scope", required=True, help="Explicit VM lock scope.")
    parser.add_argument("--machine-name", required=True, help="Explicit machine name for queue metadata.")
    parser.add_argument("--backend", required=True, help="Explicit VM backend for queue metadata.")
    parser.add_argument("--arch", required=True, help="Explicit VM architecture for queue metadata.")
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

    lock_path = lock_path_for_scope(args.lock_scope)
    queue_path = queue_path_for_scope(args.lock_scope)
    machine_name = args.machine_name
    backend = args.backend
    arch = args.arch
    lock_scope = args.lock_scope
    started_waiting = time.time()
    payload: dict[str, Any] = {
        "status": "queued",
        "pid": os.getpid(),
        "action": args.action,
        "machine": machine_name,
        "backend": backend,
        "arch": arch,
        "lock_scope": lock_scope,
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
