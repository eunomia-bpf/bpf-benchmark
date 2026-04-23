from __future__ import annotations

import os
import signal
import subprocess
import time
from typing import Callable, Sequence

from . import ROOT_DIR, resolve_bpftool_binary, run_json_command


def start_agent(
    binary: str,
    args: Sequence[str] = (),
    env: dict[str, str] | None = None,
) -> subprocess.Popen[str]:
    merged_env = os.environ.copy()
    if env:
        merged_env.update(env)
    return subprocess.Popen(
        [binary, *args],
        cwd=ROOT_DIR,
        env=merged_env,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        bufsize=1,
    )


def wait_healthy(
    proc: subprocess.Popen[str],
    timeout: int | float,
    health_check_fn: Callable[[], bool],
) -> bool:
    deadline = time.monotonic() + float(timeout)
    while time.monotonic() < deadline:
        if proc.poll() is not None:
            return False
        if health_check_fn():
            return True
        time.sleep(0.5)
    return proc.poll() is None and health_check_fn()


def stop_agent(proc: subprocess.Popen[str], timeout: int | float = 10) -> int:
    if proc.poll() is None:
        proc.send_signal(signal.SIGINT)
        try:
            return proc.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            proc.terminate()
            try:
                return proc.wait(timeout=timeout)
            except subprocess.TimeoutExpired:
                proc.kill()
                return proc.wait(timeout=max(float(timeout), 10.0))
    return int(proc.returncode or 0)
def _payload_preview(payload: object, *, limit: int = 240) -> str:
    text = repr(payload)
    return text if len(text) <= limit else f"{text[:limit]}..."


def bpftool_prog_show_records() -> list[dict[str, object]]:
    payload = run_json_command([resolve_bpftool_binary(), "-j", "-p", "prog", "show"], timeout=30)
    if not isinstance(payload, list):
        raise RuntimeError(
            "bpftool prog show returned unexpected payload type "
            f"{type(payload).__name__}: {_payload_preview(payload)}"
        )
    records: list[dict[str, object]] = []
    for index, record in enumerate(payload):
        if not isinstance(record, dict):
            raise RuntimeError(
                "bpftool prog show returned unexpected record type "
                f"at index {index}: {type(record).__name__}: {_payload_preview(record)}"
            )
        records.append(dict(record))
    return records


__all__ = [
    "bpftool_prog_show_records",
    "start_agent",
    "stop_agent",
    "wait_healthy",
]
