from __future__ import annotations

from contextlib import contextmanager
from typing import Any

from . import resolve_bpftool_binary, run_json_command


def _bpftool_command() -> list[str]:
    return [resolve_bpftool_binary(), "-j", "-p", "prog", "show"]


@contextmanager
def enable_bpf_stats() -> Any:
    yield {"mode": "bpftool"}


def _prog_show_payload() -> list[dict[str, object]]:
    payload = run_json_command(_bpftool_command(), timeout=30)
    if not isinstance(payload, list):
        raise RuntimeError("bpftool prog show returned unexpected payload")
    return [dict(record) for record in payload if isinstance(record, dict)]


def list_program_ids() -> list[int]:
    return [
        int(record["id"])
        for record in _prog_show_payload()
        if "id" in record and int(record.get("id", -1)) > 0
    ]


def _record_to_stats(record: dict[str, object]) -> dict[str, object]:
    run_cnt = int(record.get("run_cnt", 0) or 0)
    run_time_ns = int(record.get("run_time_ns", 0) or 0)
    return {
        "id": int(record.get("id", 0) or 0),
        "name": str(record.get("name", "")),
        "type": str(record.get("type", "")),
        "run_cnt": run_cnt,
        "run_time_ns": run_time_ns,
        "exec_ns": (run_time_ns / run_cnt) if run_cnt > 0 else None,
        "bytes_jited": int(record.get("bytes_jited", 0) or 0),
        "bytes_xlated": int(record.get("bytes_xlated", 0) or 0),
    }


def read_program_stats(prog_ids: list[int] | tuple[int, ...]) -> dict[int, dict[str, object]]:
    wanted = {int(prog_id) for prog_id in prog_ids if int(prog_id) > 0}
    if not wanted:
        return {}

    stats: dict[int, dict[str, object]] = {}
    for record in _prog_show_payload():
        prog_id = int(record.get("id", -1) or -1)
        if prog_id not in wanted:
            continue
        stats[prog_id] = _record_to_stats(record)

    missing = sorted(int(prog_id) for prog_id in wanted if int(prog_id) not in stats)
    if missing:
        raise RuntimeError(
            "failed to read BPF stats for requested program ids: "
            + ", ".join(str(prog_id) for prog_id in missing)
        )
    return stats


def sample_bpf_stats(
    prog_ids: list[int] | tuple[int, ...],
    *,
    prog_fds: dict[int, int] | None = None,
) -> dict[int, dict[str, object]]:
    del prog_fds
    return read_program_stats(prog_ids)


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
    "list_program_ids",
    "sample_bpf_stats",
]
