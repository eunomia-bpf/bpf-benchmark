from __future__ import annotations

import os
import threading
import time
from collections.abc import Callable
from pathlib import Path

def _read_pid_ticks(pid: int) -> tuple[int, int]:
    try:
        fields = Path(f"/proc/{pid}/stat").read_text().split()
    except OSError as exc:
        raise RuntimeError(f"failed to read /proc/{pid}/stat: {exc}") from exc
    if len(fields) < 15:
        raise RuntimeError(f"/proc/{pid}/stat is truncated")
    return int(fields[13]), int(fields[14])


def sample_cpu_usage(pids: list[int] | tuple[int, ...], duration_s: int | float) -> dict[int, dict[str, float]]:
    clock_ticks = float(os.sysconf(os.sysconf_names["SC_CLK_TCK"]))
    requested = [int(pid) for pid in pids if int(pid) > 0]
    if not requested:
        return {}
    before = {pid: _read_pid_ticks(pid) for pid in requested}
    start = time.monotonic()
    time.sleep(max(0.0, float(duration_s)))
    elapsed = time.monotonic() - start
    if elapsed <= 0:
        raise RuntimeError(f"invalid cpu sampling interval: {elapsed}")

    samples: dict[int, dict[str, float]] = {}
    for pid in requested:
        start_ticks = before.get(pid)
        end_ticks = _read_pid_ticks(pid)
        if start_ticks is None or end_ticks is None:
            continue
        user_delta = max(0, end_ticks[0] - start_ticks[0])
        sys_delta = max(0, end_ticks[1] - start_ticks[1])
        samples[pid] = {
            "user_pct": (user_delta / clock_ticks) * 100.0 / elapsed,
            "sys_pct": (sys_delta / clock_ticks) * 100.0 / elapsed,
        }
    return samples


def _read_total_cpu() -> tuple[int, int]:
    try:
        line = Path("/proc/stat").read_text().splitlines()[0]
    except (IndexError, OSError) as exc:
        raise RuntimeError(f"failed to read /proc/stat: {exc}") from exc
    parts = line.split()
    if not parts or parts[0] != "cpu":
        raise RuntimeError("/proc/stat does not start with aggregate cpu counters")
    values = [int(value) for value in parts[1:]]
    idle = values[3] + (values[4] if len(values) > 4 else 0)
    total = sum(values)
    return idle, total


def sample_total_cpu_usage(duration_s: int | float) -> dict[str, float]:
    before = _read_total_cpu()
    time.sleep(max(0.0, float(duration_s)))
    after = _read_total_cpu()
    idle_delta = max(0, after[0] - before[0])
    total_delta = max(1, after[1] - before[1])
    return {"busy_pct": (1.0 - (idle_delta / total_delta)) * 100.0}


def start_sampler_thread(
    *,
    label: str,
    errors: list[str],
    target: Callable[[], None],
) -> threading.Thread:
    def run() -> None:
        try:
            target()
        except Exception as exc:
            errors.append(f"{label}: {exc}")

    thread = threading.Thread(target=run, daemon=True)
    thread.start()
    return thread
