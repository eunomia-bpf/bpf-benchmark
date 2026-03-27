"""BpfReJIT v2 helpers for live enumeration and apply flows."""
from __future__ import annotations

import json
import subprocess
from functools import lru_cache
from pathlib import Path
from typing import Any, Mapping, Sequence


_PASS_TO_SITE_FIELD = {
    "branch_flip": "branch_flip_sites",
    "cond_select": "cmov_sites",
    "endian_fusion": "endian_sites",
    "extract": "extract_sites",
    "rotate": "rotate_sites",
    "wide_mem": "wide_sites",
}

PERFORMANCE_PASSES = 'map_inline,const_prop,dce,wide_mem,rotate,cond_select,extract,endian_fusion,bulk_memory,bounds_check_merge,skb_load_bytes,branch_flip'
DEFAULT_BENCHMARK_CONFIG = Path(__file__).resolve().parents[2] / "corpus" / "config" / "benchmark_config.yaml"


def _zero_site_counts() -> dict[str, int]:
    return {
        "total_sites": 0,
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
        "extract_sites": 0,
        "bitfield_sites": 0,
        "endian_sites": 0,
        "branch_flip_sites": 0,
    }


def _parse_last_json_object(text: str) -> dict[str, Any] | None:
    for line in reversed(text.splitlines()):
        payload = line.strip()
        if not payload or not payload.startswith("{"):
            continue
        try:
            parsed = json.loads(payload)
        except json.JSONDecodeError:
            continue
        if isinstance(parsed, dict):
            return parsed
    return None


def _parse_site_summary(site_summary: str) -> dict[str, int]:
    counts = _zero_site_counts()
    text = site_summary.strip()
    if not text or text == "-":
        return counts

    for token in text.split():
        pass_name, separator, raw_value = token.partition("=")
        if separator != "=":
            continue
        field_name = _PASS_TO_SITE_FIELD.get(pass_name)
        if field_name is None:
            continue
        try:
            counts[field_name] += int(raw_value)
        except ValueError:
            continue

    counts["bitfield_sites"] = counts["extract_sites"]
    counts["total_sites"] = sum(
        counts[field_name]
        for field_name in (
            "cmov_sites",
            "wide_sites",
            "rotate_sites",
            "lea_sites",
            "extract_sites",
            "endian_sites",
            "branch_flip_sites",
        )
    )
    return counts


@lru_cache(maxsize=1)
def benchmark_performance_passes() -> tuple[str, ...]:
    import yaml

    payload = yaml.safe_load(DEFAULT_BENCHMARK_CONFIG.read_text())
    if not isinstance(payload, Mapping):
        raise RuntimeError(f"invalid benchmark config payload in {DEFAULT_BENCHMARK_CONFIG}")

    passes = payload.get("passes")
    if not isinstance(passes, Mapping):
        raise RuntimeError(f"missing passes section in {DEFAULT_BENCHMARK_CONFIG}")

    active_group = passes.get("active")
    if not isinstance(active_group, str) or not active_group:
        raise RuntimeError(f"invalid active pass group in {DEFAULT_BENCHMARK_CONFIG}")

    selected = passes.get(active_group)
    if not isinstance(selected, list) or not selected:
        raise RuntimeError(f"missing active pass list '{active_group}' in {DEFAULT_BENCHMARK_CONFIG}")

    pass_names: list[str] = []
    for value in selected:
        if not isinstance(value, str) or not value:
            raise RuntimeError(f"invalid pass name in {DEFAULT_BENCHMARK_CONFIG}: {value!r}")
        pass_names.append(value)
    return tuple(pass_names)


def _daemon_command(
    daemon: Path | str,
    subcommand: str,
    *subcommand_args: object,
    passes: str | None = None,
    pass_names: Sequence[str] | None = None,
) -> list[str]:
    command = [str(daemon)]
    if pass_names is not None:
        normalized_pass_names = [str(name) for name in (pass_names or ()) if str(name)]
        if normalized_pass_names:
            command.extend(["--passes", ",".join(normalized_pass_names)])
    elif passes is not None:
        command.extend(["--passes", str(passes)])
    command.append(subcommand)
    command.extend(str(arg) for arg in subcommand_args)
    return command


def _parse_enumerate_table(stdout: str) -> dict[int, dict[str, Any]]:
    records: dict[int, dict[str, Any]] = {}
    for line in stdout.splitlines():
        text = line.rstrip()
        if not text or text.startswith("ID") or set(text) == {"-"}:
            continue

        fields = text.split(None, 4)
        if len(fields) < 4 or not fields[0].isdigit():
            continue

        prog_id = int(fields[0])
        prog_type = int(fields[1])
        insn_count = int(fields[2])
        prog_name = fields[3]
        site_summary = fields[4] if len(fields) >= 5 else "-"
        site_counts = _parse_site_summary(site_summary)

        records[prog_id] = {
            "prog_id": prog_id,
            "prog_type": prog_type,
            "type": prog_type,
            "name": prog_name,
            "insn_count": insn_count,
            "site_summary": site_summary,
            "sites": dict(site_counts),
            "counts": dict(site_counts),
            "total_sites": int(site_counts["total_sites"]),
        }
    return records


def _run_enumerate(
    daemon: Path | str,
    *,
    timeout_seconds: int,
    pass_names: Sequence[str] | None = None,
) -> dict[int, dict[str, Any]]:
    command = _daemon_command(daemon, "enumerate", pass_names=pass_names)
    completed = subprocess.run(
        command,
        capture_output=True,
        text=True,
        timeout=timeout_seconds,
    )
    if completed.returncode != 0:
        detail = (completed.stderr or completed.stdout or "").strip()
        raise RuntimeError(f"enumerate failed (rc={completed.returncode}): {detail}")

    stdout = completed.stdout.strip()
    if not stdout:
        raise RuntimeError("enumerate produced no output")

    records = _parse_enumerate_table(stdout)
    if not records:
        raise RuntimeError(f"enumerate output did not contain any program records:\n{stdout[:2000]}")
    return records


def enumerate_program_record(
    daemon: Path | str,
    prog_id: int,
    *,
    timeout_seconds: int = 60,
    pass_names: Sequence[str] | None = None,
) -> dict[str, Any]:
    """Return the parsed daemon enumerate record for a specific live prog_id."""
    records = _run_enumerate(daemon, timeout_seconds=timeout_seconds, pass_names=pass_names)
    try:
        return records[int(prog_id)]
    except KeyError as exc:
        raise RuntimeError(f"prog {prog_id} not found in daemon enumerate output") from exc


def scan_programs(
    prog_ids: list[int],
    daemon: Path | str,
    *,
    prog_fds: dict[int, int] | None = None,
    timeout_seconds: int = 60,
    pass_names: Sequence[str] | None = None,
) -> dict[int, dict[str, Any]]:
    """Collect enumerate site summaries for the requested live prog_ids."""
    del prog_fds

    requested_ids = [int(prog_id) for prog_id in prog_ids if int(prog_id) > 0]
    if not requested_ids:
        return {}

    try:
        records = _run_enumerate(daemon, timeout_seconds=timeout_seconds, pass_names=pass_names)
    except Exception as exc:
        error = str(exc)
        return {
            prog_id: {
                "enumerate_record": None,
                "sites": _zero_site_counts(),
                "counts": _zero_site_counts(),
                "error": error,
            }
            for prog_id in requested_ids
        }

    results: dict[int, dict[str, Any]] = {}
    for prog_id in requested_ids:
        record = records.get(prog_id)
        if record is None:
            zero = _zero_site_counts()
            results[prog_id] = {
                "enumerate_record": None,
                "sites": dict(zero),
                "counts": dict(zero),
                "error": f"prog {prog_id} not found in daemon enumerate output",
            }
            continue

        site_counts = dict(record.get("sites") or _zero_site_counts())
        results[prog_id] = {
            "enumerate_record": dict(record),
            "sites": dict(site_counts),
            "counts": dict(site_counts),
            "error": "",
        }
    return results


def _apply_one(
    daemon_binary: Path | str,
    prog_id: int,
    *,
    passes: str | None = PERFORMANCE_PASSES,
    pass_names: Sequence[str] | None = None,
) -> dict[str, object]:
    result = subprocess.run(
        _daemon_command(daemon_binary, "apply", prog_id, passes=passes, pass_names=pass_names),
        capture_output=True,
        text=True,
    )
    combined_output = result.stdout + result.stderr
    debug_result = _parse_last_json_object(f"{result.stderr}\n{result.stdout}")
    summary = debug_result.get("summary") if isinstance(debug_result, Mapping) else {}
    program = debug_result.get("program") if isinstance(debug_result, Mapping) else {}
    raw_inlined_entries = (
        debug_result.get("inlined_map_entries") if isinstance(debug_result, Mapping) else []
    )
    inlined_map_entries = [
        dict(entry) for entry in raw_inlined_entries if isinstance(entry, Mapping)
    ]
    applied_sites = int((summary or {}).get("total_sites_applied", 0) or 0)
    error_message = ""
    if isinstance(debug_result, Mapping):
        error_message = str(debug_result.get("error_message") or "")
    if not error_message and result.returncode != 0:
        error_message = combined_output.strip()

    return {
        "applied": result.returncode == 0 and bool((summary or {}).get("applied", True)),
        "output": combined_output,
        "exit_code": result.returncode,
        "debug_result": debug_result,
        "kernel_prog_name": str((program or {}).get("prog_name") or ""),
        "inlined_map_entries": inlined_map_entries,
        "summary": dict(summary) if isinstance(summary, Mapping) else {},
        "counts": {
            "total_sites": applied_sites,
            "applied_sites": applied_sites,
        },
        "error": error_message,
    }


def apply_daemon_rejit(
    daemon_binary: Path | str,
    prog_ids: list[int] | None = None,
    *,
    passes: str | None = PERFORMANCE_PASSES,
    pass_names: Sequence[str] | None = None,
) -> dict[str, object]:
    """Call daemon apply or apply-all and return a canonical ReJIT summary."""
    if prog_ids:
        per_program: dict[int, dict[str, object]] = {}
        outputs: list[str] = []
        exit_code = 0
        all_applied = True
        total_sites = 0
        applied_sites = 0
        errors: list[str] = []

        for prog_id in [int(value) for value in prog_ids if int(value) > 0]:
            result = _apply_one(daemon_binary, prog_id, passes=passes, pass_names=pass_names)
            per_program[prog_id] = result
            outputs.append(str(result.get("output") or ""))
            exit_code = max(exit_code, int(result.get("exit_code", 0) or 0))
            all_applied = all_applied and bool(result.get("applied", False))

            counts = result.get("counts") if isinstance(result.get("counts"), Mapping) else {}
            total_sites += int((counts or {}).get("total_sites", 0) or 0)
            applied_sites += int((counts or {}).get("applied_sites", 0) or 0)

            error = str(result.get("error") or "").strip()
            if error:
                errors.append(f"prog {prog_id}: {error}")

        return {
            "applied": all_applied,
            "output": "\n".join(output for output in outputs if output),
            "exit_code": exit_code,
            "per_program": per_program,
            "counts": {
                "total_sites": total_sites,
                "applied_sites": applied_sites,
            },
            "error": "; ".join(errors),
        }

    result = subprocess.run(
        _daemon_command(daemon_binary, "apply-all", passes=passes, pass_names=pass_names),
        capture_output=True,
        text=True,
    )
    combined_output = result.stdout + result.stderr
    return {
        "applied": result.returncode == 0,
        "output": combined_output,
        "exit_code": result.returncode,
        "error": combined_output.strip() if result.returncode != 0 else "",
    }


__all__ = [
    "PERFORMANCE_PASSES",
    "apply_daemon_rejit",
    "benchmark_performance_passes",
    "enumerate_program_record",
    "scan_programs",
]
