from __future__ import annotations

import json
import math
import subprocess
import time
from concurrent.futures import Future, ThreadPoolExecutor, as_completed
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Callable, Mapping, Sequence

from . import resolve_bpftool_binary, resolve_perf_binary, run_json_command, tail_text
from .metrics import compute_delta, sample_bpf_stats
from .recompile import scan_programs

DEFAULT_DAEMON = Path(__file__).resolve().parents[2] / "daemon" / "build" / "bpfrejit-daemon"
DEFAULT_PERF_EVENTS = ("cycles", "instructions", "branches", "branch-misses")


def list_live_programs() -> list[dict[str, Any]]:
    payload = run_json_command([resolve_bpftool_binary(), "-j", "-p", "prog", "show"], timeout=30)
    if not isinstance(payload, list):
        raise RuntimeError("bpftool prog show returned unexpected payload")
    records: list[dict[str, Any]] = []
    for record in payload:
        if not isinstance(record, Mapping):
            continue
        prog_id = int(record.get("id", 0) or 0)
        if prog_id <= 0:
            continue
        records.append(
            {
                "id": prog_id,
                "name": str(record.get("name", "")),
                "type": str(record.get("type", "")),
                "tag": str(record.get("tag", "")),
                "bytes_jited": int(record.get("bytes_jited", 0) or 0),
                "bytes_xlated": int(record.get("bytes_xlated", 0) or 0),
                "run_cnt": int(record.get("run_cnt", 0) or 0),
                "run_time_ns": int(record.get("run_time_ns", 0) or 0),
                "raw": dict(record),
            }
        )
    return records


def resolve_target_programs(
    *,
    prog_ids: Sequence[int] | None = None,
    name_contains: Sequence[str] | None = None,
    type_equals: Sequence[str] | None = None,
) -> list[dict[str, Any]]:
    requested_ids = {int(prog_id) for prog_id in (prog_ids or []) if int(prog_id) > 0}
    name_filters = [str(token).strip().lower() for token in (name_contains or []) if str(token).strip()]
    type_filters = {str(token).strip().lower() for token in (type_equals or []) if str(token).strip()}
    selected: list[dict[str, Any]] = []
    for record in list_live_programs():
        if requested_ids and int(record["id"]) not in requested_ids:
            continue
        if name_filters:
            name = str(record.get("name", "")).lower()
            if not any(token in name for token in name_filters):
                continue
        if type_filters:
            if str(record.get("type", "")).lower() not in type_filters:
                continue
        selected.append(record)
    if requested_ids and not selected:
        raise RuntimeError(f"no live BPF programs matched requested ids: {sorted(requested_ids)}")
    return selected


def _parse_perf_value(raw: str) -> int | float | None:
    text = raw.strip()
    if not text or text in {"<not counted>", "<not supported>", "not counted", "not supported"}:
        return None
    text = text.replace(" ", "")
    if text in {"nan", "-nan", "inf", "-inf"}:
        return None
    try:
        if any(token in text for token in (".", "e", "E")):
            return float(text)
        return int(text)
    except ValueError:
        return None


def _parse_perf_stat_csv(stderr: str, events: Sequence[str]) -> dict[str, Any]:
    parsed: dict[str, Any] = {}
    errors: list[str] = []
    event_set = {str(event) for event in events}
    for line in stderr.splitlines():
        text = line.strip()
        if not text:
            continue
        parts = [part.strip() for part in text.split(",")]
        event_name = next((part for part in parts if part in event_set), None)
        if event_name is None:
            lowered = text.lower()
            if "not supported" in lowered or "no such" in lowered or "failed" in lowered:
                errors.append(text)
            continue
        value = _parse_perf_value(parts[0] if parts else "")
        if value is None:
            errors.append(text)
            continue
        parsed[event_name] = value
    if errors:
        parsed["errors"] = errors
    return parsed


def collect_perf_stat_for_program(
    prog_id: int,
    duration_s: int | float,
    *,
    events: Sequence[str] = DEFAULT_PERF_EVENTS,
    perf_binary: str | None = None,
) -> dict[str, Any]:
    binary = perf_binary or resolve_perf_binary(required=True)
    command = [
        binary,
        "stat",
        "-x,",
        "--no-big-num",
        "--bpf-prog",
        str(int(prog_id)),
        "-e",
        ",".join(str(event) for event in events),
        "--",
        "sleep",
        str(max(0.0, float(duration_s))),
    ]
    completed = subprocess.run(
        command,
        capture_output=True,
        text=True,
        check=False,
        timeout=max(20, int(float(duration_s) * 3) + 20),
    )
    parsed = _parse_perf_stat_csv(completed.stderr or "", events)
    result: dict[str, Any] = {
        "prog_id": int(prog_id),
        "perf_binary": binary,
        "command": command,
        "returncode": int(completed.returncode),
        "stdout_tail": tail_text(completed.stdout or "", max_lines=20, max_chars=4000),
        "stderr_tail": tail_text(completed.stderr or "", max_lines=40, max_chars=8000),
        "events": {event: parsed.get(event) for event in events if event in parsed},
        "errors": list(parsed.get("errors") or []),
    }
    if completed.returncode != 0 and not result["errors"]:
        result["errors"] = [result["stderr_tail"] or result["stdout_tail"] or "perf stat failed"]
    branches = result["events"].get("branches")
    branch_misses = result["events"].get("branch-misses")
    if isinstance(branches, (int, float)) and float(branches) > 0 and isinstance(branch_misses, (int, float)):
        result["branch_miss_rate"] = float(branch_misses) / float(branches)
    else:
        result["branch_miss_rate"] = None
    return result


def _run_perf_collection(
    prog_ids: Sequence[int],
    duration_s: int | float,
    *,
    events: Sequence[str],
    max_workers: int,
) -> dict[int, dict[str, Any]]:
    if not prog_ids:
        return {}
    results: dict[int, dict[str, Any]] = {}
    worker_count = max(1, min(max_workers, len(prog_ids)))
    with ThreadPoolExecutor(max_workers=worker_count) as executor:
        futures: dict[Future[dict[str, Any]], int] = {
            executor.submit(
                collect_perf_stat_for_program,
                int(prog_id),
                duration_s,
                events=events,
            ): int(prog_id)
            for prog_id in prog_ids
        }
        for future in as_completed(futures):
            prog_id = futures[future]
            try:
                results[prog_id] = future.result()
            except Exception as exc:
                results[prog_id] = {
                    "prog_id": int(prog_id),
                    "events": {},
                    "errors": [str(exc)],
                    "branch_miss_rate": None,
                }
    return results


def _hotness_labels(records: list[dict[str, Any]]) -> dict[int, str]:
    active = [
        record
        for record in records
        if int(record.get("run_cnt", 0) or 0) > 0 or int(record.get("run_time_ns", 0) or 0) > 0
    ]
    if not active:
        return {}
    ordered = sorted(
        active,
        key=lambda record: (
            int(record.get("run_time_ns", 0) or 0),
            int(record.get("run_cnt", 0) or 0),
            -int(record.get("prog_id", 0) or 0),
        ),
        reverse=True,
    )
    hot_cutoff = max(1, math.ceil(len(ordered) * 0.2))
    warm_cutoff = max(hot_cutoff, math.ceil(len(ordered) * 0.5))
    labels: dict[int, str] = {}
    for index, record in enumerate(ordered, start=1):
        prog_id = int(record["prog_id"])
        if index <= hot_cutoff:
            labels[prog_id] = "hot"
        elif index <= warm_cutoff:
            labels[prog_id] = "warm"
        else:
            labels[prog_id] = "cold"
    return labels


def _site_summary_totals(records: Sequence[Mapping[str, Any]]) -> dict[str, int]:
    totals = {
        "total_sites": 0,
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
        "bitfield_sites": 0,
        "endian_sites": 0,
        "branch_flip_sites": 0,
    }
    for record in records:
        summary = record.get("site_summary")
        if not isinstance(summary, Mapping):
            continue
        for key in totals:
            totals[key] += int(summary.get(key, 0) or 0)
    return totals


def profile_programs(
    prog_ids: Sequence[int],
    *,
    duration_s: int | float,
    daemon_binary: str | Path | None = None,
    prog_fds: dict[int, int] | None = None,
    include_sites: bool = True,
    collect_perf: bool = True,
    perf_events: Sequence[str] = DEFAULT_PERF_EVENTS,
    perf_max_workers: int = 8,
    activity: Callable[[float], Any] | None = None,
    metadata: Mapping[str, Any] | None = None,
) -> dict[str, Any]:
    selected_ids = [int(prog_id) for prog_id in prog_ids if int(prog_id) > 0]
    if not selected_ids:
        raise RuntimeError("no BPF program ids were provided for profiling")
    before = sample_bpf_stats(selected_ids, prog_fds=prog_fds)
    perf_results: dict[int, dict[str, Any]] = {}
    perf_requested = bool(collect_perf)
    perf_supported = False
    perf_error = ""
    perf_binary = ""
    perf_futures_started = False
    perf_executor: ThreadPoolExecutor | None = None
    perf_futures: dict[Future[dict[str, Any]], int] = {}
    try:
        if collect_perf:
            resolved_perf = resolve_perf_binary()
            if not resolved_perf:
                perf_error = "perf is not installed"
                collect_perf = False
            else:
                perf_binary = resolved_perf
                worker_count = max(1, min(int(perf_max_workers), len(selected_ids)))
                perf_executor = ThreadPoolExecutor(max_workers=worker_count)
                perf_futures = {
                    perf_executor.submit(
                        collect_perf_stat_for_program,
                        prog_id,
                        duration_s,
                        events=perf_events,
                        perf_binary=perf_binary,
                    ): prog_id
                    for prog_id in selected_ids
                }
                perf_futures_started = True
        if activity is not None:
            activity(float(duration_s))
        else:
            time.sleep(max(0.0, float(duration_s)))
    finally:
        if perf_executor is not None:
            for future in as_completed(perf_futures):
                prog_id = perf_futures[future]
                try:
                    perf_results[prog_id] = future.result()
                except Exception as exc:
                    perf_results[prog_id] = {
                        "prog_id": int(prog_id),
                        "events": {},
                        "errors": [str(exc)],
                        "branch_miss_rate": None,
                    }
            perf_executor.shutdown(wait=True)
    after = sample_bpf_stats(selected_ids, prog_fds=prog_fds)
    delta = compute_delta(before, after)
    scan_results = (
        scan_programs(selected_ids, daemon_binary or DEFAULT_DAEMON, prog_fds=prog_fds)
        if include_sites
        else {}
    )

    base_records: list[dict[str, Any]] = []
    total_run_cnt = 0
    total_run_time_ns = 0
    for prog_id in selected_ids:
        program_delta = dict((delta.get("programs") or {}).get(int(prog_id), {}))
        program_before = dict(before.get(int(prog_id), {}))
        program_after = dict(after.get(int(prog_id), {}))
        perf_record = dict(perf_results.get(int(prog_id), {}))
        scan_record = dict(scan_results.get(int(prog_id), {}))
        run_cnt = max(0, int(program_delta.get("run_cnt_delta", 0) or 0))
        run_time_ns = max(0, int(program_delta.get("run_time_ns_delta", 0) or 0))
        total_run_cnt += run_cnt
        total_run_time_ns += run_time_ns
        live_sites = []
        if include_sites:
            enumerate_record = scan_record.get("enumerate_record")
            if isinstance(enumerate_record, Mapping):
                raw_sites = enumerate_record.get("sites")
                if isinstance(raw_sites, list):
                    live_sites = [dict(entry) for entry in raw_sites if isinstance(entry, Mapping)]
        base_records.append(
            {
                "prog_id": int(prog_id),
                "name": str(program_after.get("name") or program_before.get("name") or f"id-{prog_id}"),
                "type": str(program_after.get("type") or program_before.get("type") or ""),
                "run_cnt": run_cnt,
                "run_time_ns": run_time_ns,
                "avg_ns": (run_time_ns / run_cnt) if run_cnt > 0 else None,
                "run_cnt_before": int(program_before.get("run_cnt", 0) or 0),
                "run_cnt_after": int(program_after.get("run_cnt", 0) or 0),
                "run_time_ns_before": int(program_before.get("run_time_ns", 0) or 0),
                "run_time_ns_after": int(program_after.get("run_time_ns", 0) or 0),
                "bytes_jited": int(program_after.get("bytes_jited", 0) or program_before.get("bytes_jited", 0) or 0),
                "bytes_xlated": int(program_after.get("bytes_xlated", 0) or program_before.get("bytes_xlated", 0) or 0),
                "site_summary": dict(scan_record.get("sites") or {}),
                "sites": live_sites,
                "enumerate_error": str(scan_record.get("error") or ""),
                "perf": {
                    "events": dict(perf_record.get("events") or {}),
                    "errors": list(perf_record.get("errors") or []),
                    "branch_miss_rate": perf_record.get("branch_miss_rate"),
                },
            }
        )

    run_cnt_ranks = {
        int(record["prog_id"]): index
        for index, record in enumerate(
            sorted(
                base_records,
                key=lambda record: (
                    int(record.get("run_cnt", 0) or 0),
                    int(record.get("run_time_ns", 0) or 0),
                    -int(record.get("prog_id", 0) or 0),
                ),
                reverse=True,
            ),
            start=1,
        )
    }
    run_time_ranks = {
        int(record["prog_id"]): index
        for index, record in enumerate(
            sorted(
                base_records,
                key=lambda record: (
                    int(record.get("run_time_ns", 0) or 0),
                    int(record.get("run_cnt", 0) or 0),
                    -int(record.get("prog_id", 0) or 0),
                ),
                reverse=True,
            ),
            start=1,
        )
    }
    hotness = _hotness_labels(base_records)
    programs: list[dict[str, Any]] = []
    for record in sorted(
        base_records,
        key=lambda entry: (
            int(entry.get("run_time_ns", 0) or 0),
            int(entry.get("run_cnt", 0) or 0),
            -int(entry.get("prog_id", 0) or 0),
        ),
        reverse=True,
    ):
        prog_id = int(record["prog_id"])
        perf_events_record = dict(((record.get("perf") or {}).get("events") or {}))
        output = dict(record)
        output["run_cnt_rank"] = run_cnt_ranks.get(prog_id)
        output["run_time_rank"] = run_time_ranks.get(prog_id)
        output["run_cnt_share_pct"] = (float(record["run_cnt"]) * 100.0 / total_run_cnt) if total_run_cnt > 0 else 0.0
        output["run_time_share_pct"] = (
            float(record["run_time_ns"]) * 100.0 / total_run_time_ns
        ) if total_run_time_ns > 0 else 0.0
        output["hotness"] = hotness.get(prog_id, "cold")
        output["cycles"] = perf_events_record.get("cycles")
        output["instructions"] = perf_events_record.get("instructions")
        output["branches"] = perf_events_record.get("branches")
        output["branch_misses"] = perf_events_record.get("branch-misses")
        output["branch_miss_rate"] = (record.get("perf") or {}).get("branch_miss_rate")
        programs.append(output)

    perf_errors = [
        error
        for record in perf_results.values()
        for error in list(record.get("errors") or [])
        if str(error).strip()
    ]
    if perf_errors:
        perf_supported = any(not list(record.get("errors") or []) for record in perf_results.values())
        if not perf_error and not perf_supported:
            perf_error = perf_errors[0]
    elif perf_futures_started:
        perf_supported = True

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "duration_s": float(duration_s),
        "window": "delta",
        "metadata": dict(metadata or {}),
        "summary": {
            "program_count": len(programs),
            "active_program_count": sum(
                1 for record in programs if int(record.get("run_cnt", 0) or 0) > 0 or int(record.get("run_time_ns", 0) or 0) > 0
            ),
            "total_run_cnt": total_run_cnt,
            "total_run_time_ns": total_run_time_ns,
            "avg_ns_per_run": (total_run_time_ns / total_run_cnt) if total_run_cnt > 0 else None,
            "site_totals": _site_summary_totals(programs),
        },
        "perf": {
            "requested": perf_requested,
            "supported": perf_supported,
            "events": list(perf_events),
            "binary": perf_binary or None,
            "error": perf_error,
        },
        "programs": programs,
    }
    return payload


def profile_current_programs(
    *,
    prog_ids: Sequence[int] | None = None,
    duration_s: int | float,
    daemon_binary: str | Path | None = None,
    name_contains: Sequence[str] | None = None,
    type_equals: Sequence[str] | None = None,
    include_sites: bool = True,
    collect_perf: bool = True,
    perf_events: Sequence[str] = DEFAULT_PERF_EVENTS,
    perf_max_workers: int = 8,
    activity: Callable[[float], Any] | None = None,
    metadata: Mapping[str, Any] | None = None,
) -> dict[str, Any]:
    targets = resolve_target_programs(
        prog_ids=prog_ids,
        name_contains=name_contains,
        type_equals=type_equals,
    )
    if not targets:
        raise RuntimeError("no live BPF programs matched the requested filters")
    payload = profile_programs(
        [int(record["id"]) for record in targets],
        duration_s=duration_s,
        daemon_binary=daemon_binary,
        include_sites=include_sites,
        collect_perf=collect_perf,
        perf_events=perf_events,
        perf_max_workers=perf_max_workers,
        activity=activity,
        metadata=metadata,
    )
    payload["target_programs"] = targets
    return payload


def render_profile_json(payload: Mapping[str, Any]) -> str:
    return json.dumps(payload, indent=2, sort_keys=True) + "\n"


__all__ = [
    "DEFAULT_PERF_EVENTS",
    "DEFAULT_DAEMON",
    "collect_perf_stat_for_program",
    "list_live_programs",
    "profile_current_programs",
    "profile_programs",
    "render_profile_json",
    "resolve_target_programs",
]
