"""BpfReJIT v2 helpers for live enumeration and apply flows."""
from __future__ import annotations

import json
import os
import shutil
import socket
import subprocess
import tempfile
import time
from functools import lru_cache
from pathlib import Path
from typing import Any, Mapping, Sequence

import yaml

from . import ROOT_DIR, tail_text


_PASS_TO_SITE_FIELD = {
    "map_inline": "map_inline_sites",
    "const_prop": "const_prop_sites",
    "dce": "dce_sites",
    "branch_flip": "branch_flip_sites",
    "cond_select": "cmov_sites",
    "endian_fusion": "endian_sites",
    "extract": "extract_sites",
    "rotate": "rotate_sites",
    "wide_mem": "wide_sites",
}
_DEFAULT_REJIT_ENABLED_PASSES = ("map_inline", "const_prop", "dce")
_BENCH_PASSES_ENV = "BPFREJIT_BENCH_PASSES"
_BENCHMARK_CONFIG_PATH = ROOT_DIR / "corpus" / "config" / "benchmark_config.yaml"
_DEFAULT_APPLY_TIMEOUT_SECONDS = 120.0
_DEFAULT_BENCHMARK_REPEAT = 200


def _mapping_dict(value: Any, *, field_name: str) -> dict[str, Any]:
    if value is None:
        return {}
    if not isinstance(value, Mapping):
        raise SystemExit(f"invalid benchmark config field: {field_name} must be a mapping")
    return dict(value)


def _deep_merge(base: Mapping[str, Any], override: Mapping[str, Any]) -> dict[str, Any]:
    merged = dict(base)
    for key, value in override.items():
        if isinstance(value, Mapping) and isinstance(merged.get(key), Mapping):
            merged[key] = _deep_merge(
                _mapping_dict(merged[key], field_name=str(key)),
                value,
            )
            continue
        merged[key] = value
    return merged


def _fallback_benchmark_config() -> dict[str, Any]:
    return {
        "defaults": {
            "iterations": 3,
            "warmups": 1,
            "repeat": _DEFAULT_BENCHMARK_REPEAT,
        },
        "passes": {},
        "profiles": {},
    }


@lru_cache(maxsize=1)
def _load_benchmark_root_config() -> tuple[dict[str, Any], bool]:
    root_config = _fallback_benchmark_config()
    config_loaded = False
    try:
        payload = yaml.safe_load(_BENCHMARK_CONFIG_PATH.read_text(encoding="utf-8"))
    except OSError:
        return root_config, config_loaded
    if payload is None:
        return root_config, True
    if not isinstance(payload, Mapping):
        raise SystemExit(f"benchmark config must be a YAML mapping: {_BENCHMARK_CONFIG_PATH}")
    return _deep_merge(root_config, payload), True


def load_benchmark_config(profile: str | None = None) -> dict[str, Any]:
    root_config, config_loaded = _load_benchmark_root_config()
    if profile and not config_loaded:
        raise SystemExit(
            f"benchmark profile requested but config file not found: {_BENCHMARK_CONFIG_PATH}"
        )

    defaults = _mapping_dict(root_config.get("defaults"), field_name="defaults")
    passes = _mapping_dict(root_config.get("passes"), field_name="passes")
    profiles = _mapping_dict(root_config.get("profiles"), field_name="profiles")

    profile_overrides: dict[str, Any] = {}
    if profile:
        available = ", ".join(sorted(profiles))
        raw_profile = profiles.get(profile)
        if raw_profile is None:
            message = f"unknown benchmark profile: {profile}"
            if available:
                message += f" (available: {available})"
            raise SystemExit(message)
        profile_overrides = _mapping_dict(raw_profile, field_name=f"profiles.{profile}")

    effective = _deep_merge({**defaults, "passes": passes}, profile_overrides)
    effective["passes"] = _mapping_dict(effective.get("passes"), field_name="passes")
    effective["profile"] = profile
    effective["config_path"] = _BENCHMARK_CONFIG_PATH if config_loaded else None
    effective["config_loaded"] = config_loaded
    effective["available_profiles"] = sorted(profiles)
    return effective


def _normalize_pass_list(raw: Any) -> list[str]:
    if not isinstance(raw, list):
        return []
    return [str(value).strip() for value in raw if str(value).strip()]


def benchmark_config_enabled_passes(benchmark_config: Mapping[str, Any] | None) -> list[str]:
    passes_config = _mapping_dict((benchmark_config or {}).get("passes"), field_name="passes")

    active_list = _normalize_pass_list(passes_config.get("active_list"))
    if active_list:
        return active_list

    active_name = str(passes_config.get("active") or "").strip()
    if active_name:
        named_list = _normalize_pass_list(passes_config.get(active_name))
        if named_list:
            return named_list

    performance_list = _normalize_pass_list(passes_config.get("performance"))
    if performance_list:
        return performance_list

    return list(_DEFAULT_REJIT_ENABLED_PASSES)


def _benchmark_int(
    benchmark_config: Mapping[str, Any] | None,
    key: str,
    *,
    default: int,
    minimum: int,
) -> int:
    value = (benchmark_config or {}).get(key)
    try:
        return max(minimum, int(value))
    except (TypeError, ValueError):
        return default


def benchmark_config_iterations(benchmark_config: Mapping[str, Any] | None) -> int:
    return _benchmark_int(benchmark_config, "iterations", default=3, minimum=1)


def benchmark_config_warmups(benchmark_config: Mapping[str, Any] | None) -> int:
    return _benchmark_int(benchmark_config, "warmups", default=0, minimum=0)


def benchmark_config_repeat(benchmark_config: Mapping[str, Any] | None) -> int:
    return _benchmark_int(
        benchmark_config,
        "repeat",
        default=_DEFAULT_BENCHMARK_REPEAT,
        minimum=1,
    )


def _parse_enabled_passes(raw: str | None) -> list[str]:
    text = str(raw or "").strip()
    if not text:
        return []
    if text.lower() in {"default", "benchmark-default"}:
        return list(_DEFAULT_REJIT_ENABLED_PASSES)
    return [token.strip() for token in text.split(",") if token.strip()]


@lru_cache(maxsize=1)
def _benchmark_config_enabled_passes() -> list[str]:
    return benchmark_config_enabled_passes(load_benchmark_config())


def _zero_site_counts() -> dict[str, int]:
    return {
        "total_sites": 0,
        "map_inline_sites": 0,
        "const_prop_sites": 0,
        "dce_sites": 0,
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
            "map_inline_sites",
            "const_prop_sites",
            "dce_sites",
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


def _daemon_command(
    daemon: Path | str,
    subcommand: str,
    *subcommand_args: object,
) -> list[str]:
    command = [str(daemon)]
    command.append(subcommand)
    command.extend(str(arg) for arg in subcommand_args)
    return command


def benchmark_rejit_enabled_passes() -> list[str]:
    if _BENCH_PASSES_ENV in os.environ:
        raw = os.environ.get(_BENCH_PASSES_ENV)
        text = str(raw or "").strip().lower()
        if text in {"default", "benchmark-default"}:
            return list(_benchmark_config_enabled_passes())
        return _parse_enabled_passes(raw)
    return list(_benchmark_config_enabled_passes())


def _site_summary_from_counts(counts: Mapping[str, Any]) -> str:
    parts: list[str] = []
    for pass_name, field_name in _PASS_TO_SITE_FIELD.items():
        value = int(counts.get(field_name, 0) or 0)
        if value > 0:
            parts.append(f"{pass_name}={value}")
    return " ".join(parts) if parts else "-"


def _site_counts_from_optimize_response(response: Mapping[str, Any]) -> dict[str, int]:
    counts = _zero_site_counts()
    passes = response.get("passes")
    if isinstance(passes, list):
        for item in passes:
            if not isinstance(item, Mapping):
                continue
            pass_name = str(item.get("pass_name") or "").strip()
            field_name = _PASS_TO_SITE_FIELD.get(pass_name)
            if field_name is None:
                continue
            try:
                counts[field_name] += int(item.get("sites_applied") or 0)
            except (TypeError, ValueError):
                continue
    counts["bitfield_sites"] = counts["extract_sites"]
    counts["total_sites"] = sum(
        counts[field_name]
        for field_name in (
            "map_inline_sites",
            "const_prop_sites",
            "dce_sites",
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


def _scan_record_from_optimize_response(prog_id: int, response: Mapping[str, Any]) -> dict[str, Any]:
    counts = _site_counts_from_optimize_response(response)
    program = response.get("program") if isinstance(response, Mapping) else {}
    if not isinstance(program, Mapping):
        program = {}
    prog_type = int(program.get("prog_type") or 0)
    prog_name = str(program.get("prog_name") or "")
    insn_count = int(program.get("orig_insn_count") or 0)
    enumerate_record = {
        "prog_id": int(prog_id),
        "prog_type": prog_type,
        "type": prog_type,
        "name": prog_name,
        "insn_count": insn_count,
        "site_summary": _site_summary_from_counts(counts),
        "sites": dict(counts),
        "counts": dict(counts),
        "total_sites": int(counts["total_sites"]),
    }
    return {
        "enumerate_record": enumerate_record,
        "sites": dict(counts),
        "counts": dict(counts),
        "error": "",
    }


def enumerate_program_record(
    daemon: Path | str,
    prog_id: int,
    *,
    timeout_seconds: int = 60,
) -> dict[str, Any]:
    """Return the parsed daemon dry-run optimize record for a specific live prog_id."""
    records = scan_programs([prog_id], daemon, timeout_seconds=timeout_seconds)
    record = records.get(int(prog_id))
    if not isinstance(record, Mapping):
        raise RuntimeError(f"prog {prog_id} not found in daemon scan output")
    error = str(record.get("error") or "").strip()
    if error:
        raise RuntimeError(error)
    enumerate_record = record.get("enumerate_record")
    if not isinstance(enumerate_record, Mapping):
        raise RuntimeError(f"prog {prog_id} scan output was missing enumerate_record")
    return dict(enumerate_record)


def scan_programs(
    prog_ids: list[int],
    daemon: Path | str,
    *,
    prog_fds: dict[int, int] | None = None,
    timeout_seconds: int = 60,
) -> dict[int, dict[str, Any]]:
    """Collect dry-run optimize summaries for the requested live prog_ids."""
    del prog_fds

    requested_ids = [int(prog_id) for prog_id in prog_ids if int(prog_id) > 0]
    if not requested_ids:
        return {}

    zero = _zero_site_counts()
    results: dict[int, dict[str, Any]] = {}
    daemon_proc = None
    daemon_socket_path = None
    daemon_socket_dir = None
    daemon_stdout_path = None
    daemon_stderr_path = None

    try:
        (
            daemon_proc,
            daemon_socket_path,
            daemon_socket_dir,
            daemon_stdout_path,
            daemon_stderr_path,
        ) = _start_daemon_server(daemon)
        for prog_id in requested_ids:
            response = _optimize_request(
                daemon_socket_path,
                prog_id,
                enabled_passes=None,
                dry_run=True,
                daemon_proc=daemon_proc,
                stdout_path=daemon_stdout_path,
                stderr_path=daemon_stderr_path,
                timeout_seconds=float(timeout_seconds),
            )
            if str(response.get("status") or "") != "ok":
                results[prog_id] = {
                    "enumerate_record": None,
                    "sites": dict(zero),
                    "counts": dict(zero),
                    "error": str(response.get("message") or response.get("error") or "scan failed"),
                }
                continue
            results[prog_id] = _scan_record_from_optimize_response(prog_id, response)
    except Exception as exc:
        error = str(exc)
        for prog_id in requested_ids:
            results[prog_id] = {
                "enumerate_record": None,
                "sites": dict(zero),
                "counts": dict(zero),
                "error": error,
            }
    finally:
        if daemon_proc is not None and daemon_socket_path is not None and daemon_socket_dir is not None:
            _stop_daemon_server(daemon_proc, daemon_socket_path, daemon_socket_dir)

    return results


def _apply_one(
    daemon_binary: Path | str,
    prog_id: int,
    *,
    timeout_seconds: float = _DEFAULT_APPLY_TIMEOUT_SECONDS,
) -> dict[str, object]:
    daemon_proc = None
    daemon_socket_path = None
    daemon_socket_dir = None
    daemon_stdout_path = None
    daemon_stderr_path = None
    try:
        (
            daemon_proc,
            daemon_socket_path,
            daemon_socket_dir,
            daemon_stdout_path,
            daemon_stderr_path,
        ) = _start_daemon_server(daemon_binary)
        return _apply_one_via_socket(
            daemon_socket_path,
            prog_id,
            None,
            daemon_proc=daemon_proc,
            stdout_path=daemon_stdout_path,
            stderr_path=daemon_stderr_path,
            timeout_seconds=timeout_seconds,
        )
    finally:
        if daemon_proc is not None and daemon_socket_path is not None and daemon_socket_dir is not None:
            _stop_daemon_server(daemon_proc, daemon_socket_path, daemon_socket_dir)


def _apply_result_from_response(
    response: Mapping[str, Any],
    *,
    output: str,
    exit_code: int,
) -> dict[str, object]:
    summary = response.get("summary") if isinstance(response, Mapping) else {}
    program = response.get("program") if isinstance(response, Mapping) else {}
    raw_inlined_entries = response.get("inlined_map_entries") if isinstance(response, Mapping) else []
    if not isinstance(raw_inlined_entries, list):
        raw_inlined_entries = []
    inlined_map_entries = [
        dict(entry) for entry in raw_inlined_entries if isinstance(entry, Mapping)
    ]
    applied_sites = int((summary or {}).get("total_sites_applied", 0) or 0)
    error_message = str(response.get("error_message") or response.get("message") or "").strip()
    return {
        "applied": exit_code == 0 and bool((summary or {}).get("applied", True)),
        "output": output,
        "exit_code": exit_code,
        "debug_result": dict(response),
        "kernel_prog_name": str((program or {}).get("prog_name") or ""),
        "inlined_map_entries": inlined_map_entries,
        "summary": dict(summary) if isinstance(summary, Mapping) else {},
        "counts": {
            "total_sites": applied_sites,
            "applied_sites": applied_sites,
        },
        "error": error_message,
    }


def _socket_error_result(
    prog_id: int,
    detail: str,
    *,
    exit_code: int = 1,
    daemon_proc: subprocess.Popen[str] | None = None,
    stdout_path: Path | None = None,
    stderr_path: Path | None = None,
) -> dict[str, object]:
    notes: list[str] = [detail]
    if daemon_proc is not None:
        returncode = daemon_proc.poll()
        notes.append(
            f"daemon serve rc={returncode}" if returncode is not None else "daemon serve still running"
        )

    log_tail = _daemon_log_tail(stdout_path, stderr_path)
    if log_tail:
        notes.append(f"daemon log tail:\n{log_tail}")

    message = "\n".join(notes)
    return {
        "applied": False,
        "output": log_tail,
        "exit_code": exit_code,
        "debug_result": {},
        "kernel_prog_name": "",
        "inlined_map_entries": [],
        "summary": {},
        "counts": {
            "total_sites": 0,
            "applied_sites": 0,
        },
        "error": message,
    }


def _daemon_log_tail(stdout_path: Path | None, stderr_path: Path | None) -> str:
    fragments: list[str] = []
    for path in (stderr_path, stdout_path):
        if path is None:
            continue
        try:
            text = path.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        if text.strip():
            fragments.append(text)
    return tail_text("\n".join(fragments), max_lines=80, max_chars=8000)


def _start_daemon_server(
    daemon_binary: Path | str,
    *,
    pgo: bool = False,
) -> tuple[subprocess.Popen[str], Path, str, Path, Path]:
    socket_dir = tempfile.mkdtemp(prefix="bpfrejit-daemon-")
    socket_path = Path(socket_dir) / "daemon.sock"
    stdout_path = Path(socket_dir) / "daemon.stdout.log"
    stderr_path = Path(socket_dir) / "daemon.stderr.log"
    stdout_handle = stdout_path.open("w", encoding="utf-8")
    stderr_handle = stderr_path.open("w", encoding="utf-8")
    try:
        command = [str(daemon_binary)]
        if pgo:
            command.append("--pgo")
        command.extend(["serve", "--socket", str(socket_path)])
        proc = subprocess.Popen(
            command,
            stdout=stdout_handle,
            stderr=stderr_handle,
            text=True,
        )
    finally:
        stdout_handle.close()
        stderr_handle.close()

    deadline = time.monotonic() + 5.0
    while time.monotonic() < deadline:
        if socket_path.exists():
            return proc, socket_path, socket_dir, stdout_path, stderr_path
        if proc.poll() is not None:
            raise RuntimeError(
                f"daemon serve exited early (rc={proc.returncode}): "
                f"{_daemon_log_tail(stdout_path, stderr_path)}"
            )
        time.sleep(0.05)
    proc.terminate()
    try:
        proc.wait(timeout=1)
    except subprocess.TimeoutExpired:
        proc.kill()
        proc.wait(timeout=1)
    raise RuntimeError(
        f"timed out waiting for daemon socket: {_daemon_log_tail(stdout_path, stderr_path)}"
    )


def _stop_daemon_server(proc: subprocess.Popen[str], socket_path: Path, socket_dir: str) -> None:
    proc.terminate()
    try:
        proc.wait(timeout=5)
    except subprocess.TimeoutExpired:
        proc.kill()
        proc.wait(timeout=5)
    socket_path.unlink(missing_ok=True)
    shutil.rmtree(socket_dir, ignore_errors=True)


def _optimize_request(
    socket_path: Path,
    prog_id: int,
    *,
    enabled_passes: Sequence[str] | None,
    dry_run: bool,
    daemon_proc: subprocess.Popen[str] | None = None,
    stdout_path: Path | None = None,
    stderr_path: Path | None = None,
    timeout_seconds: float = _DEFAULT_APPLY_TIMEOUT_SECONDS,
) -> dict[str, Any]:
    payload: dict[str, object] = {
        "cmd": "optimize",
        "prog_id": int(prog_id),
    }
    if dry_run:
        payload["dry_run"] = True
    if enabled_passes is not None:
        payload["enabled_passes"] = [str(name).strip() for name in enabled_passes if str(name).strip()]
    request = json.dumps(payload) + "\n"
    with socket.socket(socket.AF_UNIX, socket.SOCK_STREAM) as client:
        client.settimeout(timeout_seconds)
        try:
            client.connect(str(socket_path))
            client.sendall(request.encode())
            chunks: list[bytes] = []
            while True:
                chunk = client.recv(4096)
                if not chunk:
                    break
                chunks.append(chunk)
                if b"\n" in chunk:
                    break
        except socket.timeout:
            return _socket_error_result(
                prog_id,
                f"socket optimize timed out after {timeout_seconds:.0f}s for prog {prog_id}",
                exit_code=124,
                daemon_proc=daemon_proc,
                stdout_path=stdout_path,
                stderr_path=stderr_path,
            )
        except OSError as exc:
            return _socket_error_result(
                prog_id,
                f"socket optimize failed for prog {prog_id}: {exc}",
                daemon_proc=daemon_proc,
                stdout_path=stdout_path,
                stderr_path=stderr_path,
            )

    line = b"".join(chunks).decode(errors="replace").strip()
    if not line:
        return _socket_error_result(
            prog_id,
            f"daemon socket returned an empty response for prog {prog_id}",
            daemon_proc=daemon_proc,
            stdout_path=stdout_path,
            stderr_path=stderr_path,
        )
    try:
        response = json.loads(line)
    except json.JSONDecodeError as exc:
        return _socket_error_result(
            prog_id,
            f"daemon socket returned invalid JSON for prog {prog_id}: {exc}: {line[:400]}",
            daemon_proc=daemon_proc,
            stdout_path=stdout_path,
            stderr_path=stderr_path,
        )
    if not isinstance(response, Mapping):
        return _socket_error_result(
            prog_id,
            f"daemon socket returned non-object JSON for prog {prog_id}: {line[:400]}",
            daemon_proc=daemon_proc,
            stdout_path=stdout_path,
            stderr_path=stderr_path,
        )
    return dict(response)


def _branch_flip_requested(enabled_passes: Sequence[str] | None) -> bool:
    if enabled_passes is None:
        return False
    return any(str(name).strip() == "branch_flip" for name in enabled_passes)


def _apply_one_via_socket(
    socket_path: Path,
    prog_id: int,
    enabled_passes: Sequence[str] | None,
    *,
    dry_run: bool = False,
    daemon_proc: subprocess.Popen[str] | None = None,
    stdout_path: Path | None = None,
    stderr_path: Path | None = None,
    timeout_seconds: float = _DEFAULT_APPLY_TIMEOUT_SECONDS,
) -> dict[str, object]:
    response = _optimize_request(
        socket_path,
        prog_id,
        enabled_passes=enabled_passes,
        dry_run=dry_run,
        daemon_proc=daemon_proc,
        stdout_path=stdout_path,
        stderr_path=stderr_path,
        timeout_seconds=timeout_seconds,
    )
    output = json.dumps(response, sort_keys=True)
    if str(response.get("status") or "") != "ok":
        return _apply_result_from_response(response, output=output, exit_code=1)
    return _apply_result_from_response(response, output=output, exit_code=0)


def apply_daemon_rejit(
    daemon_binary: Path | str,
    prog_ids: list[int] | None = None,
    *,
    enabled_passes: Sequence[str] | None = None,
) -> dict[str, object]:
    """Call daemon optimize or optimize-all via serve and return a canonical ReJIT summary."""
    if prog_ids:
        per_program: dict[int, dict[str, object]] = {}
        outputs: list[str] = []
        exit_code = 0
        all_applied = True
        total_sites = 0
        applied_sites = 0
        errors: list[str] = []
        daemon_proc = None
        daemon_socket_path = None
        daemon_socket_dir = None
        daemon_stdout_path = None
        daemon_stderr_path = None

        try:
            (
                daemon_proc,
                daemon_socket_path,
                daemon_socket_dir,
                daemon_stdout_path,
                daemon_stderr_path,
            ) = _start_daemon_server(
                daemon_binary,
                pgo=_branch_flip_requested(enabled_passes),
            )
            for prog_id in [int(value) for value in prog_ids if int(value) > 0]:
                assert daemon_socket_path is not None
                result = _apply_one_via_socket(
                    daemon_socket_path,
                    prog_id,
                    enabled_passes,
                    daemon_proc=daemon_proc,
                    stdout_path=daemon_stdout_path,
                    stderr_path=daemon_stderr_path,
                )
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
        finally:
            if daemon_proc is not None and daemon_socket_path is not None and daemon_socket_dir is not None:
                _stop_daemon_server(daemon_proc, daemon_socket_path, daemon_socket_dir)

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

    daemon_proc = None
    daemon_socket_path = None
    daemon_socket_dir = None
    daemon_stdout_path = None
    daemon_stderr_path = None
    try:
        (
            daemon_proc,
            daemon_socket_path,
            daemon_socket_dir,
            daemon_stdout_path,
            daemon_stderr_path,
        ) = _start_daemon_server(
            daemon_binary,
            pgo=_branch_flip_requested(enabled_passes),
        )
        request_payload: dict[str, object] = {"cmd": "optimize-all"}
        if enabled_passes is not None:
            request_payload["enabled_passes"] = [str(name).strip() for name in enabled_passes if str(name).strip()]
        response = _daemon_request(
            daemon_socket_path,
            request_payload,
            timeout_seconds=_DEFAULT_APPLY_TIMEOUT_SECONDS,
            daemon_proc=daemon_proc,
            stdout_path=daemon_stdout_path,
            stderr_path=daemon_stderr_path,
        )
        output = json.dumps(response, sort_keys=True)
        error_message = str(response.get("message") or response.get("error") or "").strip()
        return {
            "applied": str(response.get("status") or "") == "ok",
            "output": output,
            "exit_code": 0 if str(response.get("status") or "") == "ok" else 1,
            "error": error_message,
        }
    finally:
        if daemon_proc is not None and daemon_socket_path is not None and daemon_socket_dir is not None:
            _stop_daemon_server(daemon_proc, daemon_socket_path, daemon_socket_dir)


__all__ = [
    "apply_daemon_rejit",
    "benchmark_config_enabled_passes",
    "benchmark_config_iterations",
    "benchmark_config_repeat",
    "benchmark_config_warmups",
    "benchmark_rejit_enabled_passes",
    "enumerate_program_record",
    "load_benchmark_config",
    "scan_programs",
]
