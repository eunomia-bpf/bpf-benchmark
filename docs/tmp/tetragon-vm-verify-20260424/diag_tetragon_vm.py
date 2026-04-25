#!/usr/bin/env python3
from __future__ import annotations

import json
import os
import socket
import subprocess
import sys
import threading
import time
from collections import deque
from datetime import datetime, timezone
from pathlib import Path

IMPORT_ROOT = Path(
    os.environ.get(
        "BPFREJIT_IMPORT_ROOT",
        str(Path(__file__).resolve().parents[3]),
    )
).resolve()
HOST_RESULTS_DIR = Path(
    os.environ.get(
        "BPFREJIT_HOST_RESULTS_DIR",
        str(IMPORT_ROOT / "e2e" / "results"),
    )
).resolve()

if str(IMPORT_ROOT) not in sys.path:
    sys.path.insert(0, str(IMPORT_ROOT))

from runner.libs import ROOT_DIR  # type: ignore  # noqa: E402
from runner.libs.agent import stop_agent  # type: ignore  # noqa: E402
from runner.libs.app_runners.process_support import programs_after  # type: ignore  # noqa: E402
from runner.libs.app_runners.tetragon import (  # type: ignore  # noqa: E402
    current_prog_ids,
    inspect_tetragon_setup,
    resolve_tetragon_binary,
    resolve_tetragon_policy_dir,
)


class TailCollector:
    def __init__(self) -> None:
        self.stdout: deque[str] = deque(maxlen=400)
        self.stderr: deque[str] = deque(maxlen=400)
        self._lock = threading.Lock()

    def pump(self, pipe: object, target: deque[str]) -> None:
        for line in iter(pipe.readline, ""):  # type: ignore[attr-defined]
            with self._lock:
                target.append(str(line).rstrip())
        pipe.close()  # type: ignore[attr-defined]

    def snapshot(self) -> dict[str, list[str]]:
        with self._lock:
            return {"stdout": list(self.stdout), "stderr": list(self.stderr)}


def free_addr() -> str:
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.bind(("127.0.0.1", 0))
        return f"127.0.0.1:{sock.getsockname()[1]}"


STAMP = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%SZ")
LOG_PATH = HOST_RESULTS_DIR / f"tetragon_manual_diag_{STAMP}.log"
HOST_RESULTS_DIR.mkdir(parents=True, exist_ok=True)


def log(*parts: object) -> None:
    text = " ".join(str(part) for part in parts)
    print(text, flush=True)
    with LOG_PATH.open("a", encoding="utf-8") as handle:
        handle.write(text + "\n")


def main() -> int:
    setup = inspect_tetragon_setup()
    log("SETUP", json.dumps(setup, indent=2, sort_keys=True))

    policy_dir_override = os.environ.get("BPFREJIT_POLICY_DIR", "").strip()
    policy_dir = Path(policy_dir_override or resolve_tetragon_policy_dir())
    policy_count = sum(1 for _ in policy_dir.rglob("*.yaml")) + sum(1 for _ in policy_dir.rglob("*.yml"))
    log("POLICY_DIR", policy_dir)
    log("POLICY_COUNT", policy_count)
    for path in sorted(policy_dir.rglob("*.y*ml")):
        log("POLICY", path.relative_to(policy_dir))

    binary = resolve_tetragon_binary(None, setup)
    if binary is None:
        log("ERROR", "no tetragon binary resolved")
        return 2

    command = [
        binary,
        "--server-address",
        free_addr(),
        "--health-server-address",
        free_addr(),
        "--tracing-policy-dir",
        str(policy_dir),
        "--log-level",
        "debug",
        "--verbose",
        "1",
    ]
    bpf_lib = str(setup.get("tetragon_bpf_lib_dir") or "").strip()
    if bpf_lib:
        command.extend(["--bpf-lib", bpf_lib])
    log("COMMAND", json.dumps(command))

    before_ids = set(current_prog_ids())
    log("BEFORE_IDS_COUNT", len(before_ids))

    proc = subprocess.Popen(
        command,
        cwd=ROOT_DIR,
        env={**os.environ, "HOME": os.environ.get("HOME", str(ROOT_DIR))},
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        bufsize=1,
    )
    assert proc.stdout is not None
    assert proc.stderr is not None

    collector = TailCollector()
    threads = [
        threading.Thread(target=collector.pump, args=(proc.stdout, collector.stdout), daemon=True),
        threading.Thread(target=collector.pump, args=(proc.stderr, collector.stderr), daemon=True),
    ]
    for thread in threads:
        thread.start()

    deadline = time.monotonic() + 120.0
    stable_window_s = float(os.environ.get("BPFREJIT_STABLE_WINDOW_S", "5"))
    break_on_stable = os.environ.get("BPFREJIT_BREAK_ON_STABLE", "").strip() == "1"
    last_count: int | None = None
    last_ids: list[int] | None = None
    last_change_at: float | None = None
    try:
        while time.monotonic() < deadline:
            programs = programs_after(before_ids)
            ids = [int(program.get("id", 0) or 0) for program in programs]
            if len(programs) != last_count or ids != last_ids:
                preview = [
                    (
                        int(program.get("id", 0) or 0),
                        str(program.get("type", "")),
                        str(program.get("name", "")),
                    )
                    for program in programs[:40]
                ]
                elapsed = int(round(120.0 - max(0.0, deadline - time.monotonic())))
                log(f"T+{elapsed:03d}s", "PROGRAMS", len(programs), json.dumps(preview))
                last_count = len(programs)
                last_ids = ids
                last_change_at = time.monotonic()
            elif break_on_stable and programs and last_change_at is not None and (time.monotonic() - last_change_at) >= stable_window_s:
                log("PROGRAM_SET_STABLE", len(programs), f"window_s={stable_window_s}")
                break

            returncode = proc.poll()
            if returncode is not None:
                log("PROCESS_EXIT", returncode)
                break
            time.sleep(0.5)
        else:
            log("TIMEOUT_WAITING", 120)
    finally:
        snapshot = collector.snapshot()
        final_programs = programs_after(before_ids)
        final_preview = [
            (
                int(program.get("id", 0) or 0),
                str(program.get("type", "")),
                str(program.get("name", "")),
            )
            for program in final_programs[:80]
        ]
        log("FINAL_PROGRAMS", len(final_programs), json.dumps(final_preview))

        log("STDERR_TAIL_BEGIN")
        for line in snapshot["stderr"][-200:]:
            log(line)
        log("STDERR_TAIL_END")

        log("STDOUT_TAIL_BEGIN")
        for line in snapshot["stdout"][-200:]:
            log(line)
        log("STDOUT_TAIL_END")

        if proc.poll() is None:
            log("STOPPING_PROCESS")
            stop_agent(proc, timeout=8)
        for thread in threads:
            thread.join(timeout=1.0)

    log("LOG_PATH", LOG_PATH)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
