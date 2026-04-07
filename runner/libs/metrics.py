from __future__ import annotations

import os
import threading
import time
from collections.abc import Callable
from pathlib import Path

from .bpf_stats import enable_bpf_stats, sample_bpf_stats


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


def compute_delta(
    before: dict[int, dict[str, object]],
    after: dict[int, dict[str, object]],
) -> dict[str, object]:
    program_deltas: dict[int, dict[str, object]] = {}
    total_run_cnt = 0
    total_run_time_ns = 0
    for prog_id in sorted(set(before) | set(after)):
        previous = before.get(prog_id, {})
        current = after.get(prog_id, {})
        run_cnt_delta = int(current.get("run_cnt", 0) or 0) - int(previous.get("run_cnt", 0) or 0)
        run_time_delta = int(current.get("run_time_ns", 0) or 0) - int(previous.get("run_time_ns", 0) or 0)
        total_run_cnt += max(0, run_cnt_delta)
        total_run_time_ns += max(0, run_time_delta)
        program_deltas[prog_id] = {
            "id": prog_id,
            "name": str(current.get("name") or previous.get("name") or f"id-{prog_id}"),
            "type": str(current.get("type") or previous.get("type") or ""),
            "run_cnt_delta": run_cnt_delta,
            "run_time_ns_delta": run_time_delta,
            "avg_ns_per_run": (run_time_delta / run_cnt_delta) if run_cnt_delta > 0 else None,
            "bytes_jited": int(current.get("bytes_jited", 0) or previous.get("bytes_jited", 0) or 0),
            "bytes_xlated": int(current.get("bytes_xlated", 0) or previous.get("bytes_xlated", 0) or 0),
        }
    return {
        "programs": program_deltas,
        "summary": {
            "total_events": total_run_cnt,
            "total_run_time_ns": total_run_time_ns,
            "avg_ns_per_run": (total_run_time_ns / total_run_cnt) if total_run_cnt > 0 else None,
            "active_programs": sum(1 for record in program_deltas.values() if int(record["run_cnt_delta"]) > 0),
        },
    }


__all__ = [
    "compute_delta",
    "enable_bpf_stats",
    "sample_bpf_stats",
    "sample_cpu_usage",
    "sample_total_cpu_usage",
    "start_sampler_thread",
]
