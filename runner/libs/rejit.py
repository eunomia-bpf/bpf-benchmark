"""BpfReJIT v2 helpers for daemon-backed scan and optimize flows."""
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
_DEFAULT_PROFILE_INTERVAL_MS = 1000


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


def _benchmark_config_skeleton() -> dict[str, Any]:
    return {
        "defaults": {
            "iterations": 3,
            "warmups": 1,
            "repeat": _DEFAULT_BENCHMARK_REPEAT,
        },
        "passes": {},
        "policy": {
            "rules": [],
        },
        "profiles": {},
    }


@lru_cache(maxsize=1)
def _load_benchmark_root_config() -> tuple[dict[str, Any], bool]:
    root_config = _benchmark_config_skeleton()
    try:
        payload = yaml.safe_load(_BENCHMARK_CONFIG_PATH.read_text(encoding="utf-8"))
    except OSError as exc:
        raise SystemExit(f"benchmark config file not found: {_BENCHMARK_CONFIG_PATH}") from exc
    if payload is None:
        return root_config, True
    if not isinstance(payload, Mapping):
        raise SystemExit(f"benchmark config must be a YAML mapping: {_BENCHMARK_CONFIG_PATH}")
    return _deep_merge(root_config, payload), True


def load_benchmark_config(profile: str | None = None) -> dict[str, Any]:
    root_config, config_loaded = _load_benchmark_root_config()
    defaults = _mapping_dict(root_config.get("defaults"), field_name="defaults")
    passes = _mapping_dict(root_config.get("passes"), field_name="passes")
    policy = _mapping_dict(root_config.get("policy"), field_name="policy")
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

    effective = _deep_merge({**defaults, "passes": passes, "policy": policy}, profile_overrides)
    effective["passes"] = _mapping_dict(effective.get("passes"), field_name="passes")
    effective["policy"] = _mapping_dict(effective.get("policy"), field_name="policy")
    effective["profile"] = profile
    effective["config_path"] = _BENCHMARK_CONFIG_PATH if config_loaded else None
    effective["config_loaded"] = config_loaded
    effective["available_profiles"] = sorted(profiles)
    return effective


def _normalize_pass_list(raw: Any) -> list[str]:
    if not isinstance(raw, list):
        return []
    return [str(value).strip() for value in raw if str(value).strip()]


def _policy_pass_list(raw: Any, *, field_name: str) -> list[str] | None:
    if raw is None:
        return None
    if not isinstance(raw, list):
        raise SystemExit(f"invalid benchmark config field: {field_name} must be a sequence")
    return [str(value).strip() for value in raw if str(value).strip()]


def _policy_match_values(raw: Any, *, field_name: str) -> list[str]:
    if raw is None:
        return []
    if isinstance(raw, list):
        return [str(value).strip() for value in raw if str(value).strip()]
    if isinstance(raw, Mapping):
        raise SystemExit(f"invalid benchmark config field: {field_name} must be a scalar or sequence")
    text = str(raw).strip()
    return [text] if text else []


def _policy_context_text(context: Mapping[str, Any] | None, *field_names: str) -> str:
    payload = context or {}
    for field_name in field_names:
        text = str(payload.get(field_name) or "").strip()
        if text:
            return text
    return ""


def _site_count_for_pass(site_counts: Mapping[str, Any] | None, pass_name: str) -> int:
    if not site_counts:
        return 0
    candidates = [pass_name]
    field_name = _PASS_TO_SITE_FIELD.get(pass_name)
    if field_name:
        candidates.append(field_name)
    for key in candidates:
        try:
            return max(0, int(site_counts.get(key, 0) or 0))
        except (TypeError, ValueError):
            continue
    return 0


def _policy_rule_matches(
    match_config: Mapping[str, Any],
    *,
    context: Mapping[str, Any] | None,
    site_counts: Mapping[str, Any] | None,
    field_name: str,
) -> bool:
    text_fields = {
        "repo": ("repo",),
        "object": ("object", "object_basename"),
        "object_relpath": ("object_relpath",),
        "program": ("program", "program_name"),
        "section": ("section", "section_name"),
        "prog_type": ("prog_type", "prog_type_name"),
        "family": ("family",),
        "category": ("category",),
        "level": ("level",),
    }

    for key, raw_value in match_config.items():
        current_field = f"{field_name}.{key}"
        if key == "has_sites":
            required_sites = _policy_pass_list(raw_value, field_name=current_field) or []
            if any(_site_count_for_pass(site_counts, pass_name) <= 0 for pass_name in required_sites):
                return False
            continue
        aliases = text_fields.get(key)
        if aliases is None:
            raise SystemExit(f"invalid benchmark config field: {current_field} is unsupported")
        expected_values = {value.lower() for value in _policy_match_values(raw_value, field_name=current_field)}
        if not expected_values:
            return False
        actual_value = _policy_context_text(context, *aliases).lower()
        if not actual_value or actual_value not in expected_values:
            return False
    return True


def benchmark_config_enabled_passes(benchmark_config: Mapping[str, Any] | None) -> list[str]:
    policy_config = _mapping_dict((benchmark_config or {}).get("policy"), field_name="policy")
    policy_default = _mapping_dict(policy_config.get("default"), field_name="policy.default")
    policy_default_passes = _policy_pass_list(
        policy_default.get("passes"),
        field_name="policy.default.passes",
    )
    if policy_default_passes is not None:
        return policy_default_passes

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


def benchmark_policy_required_site_passes(
    benchmark_config: Mapping[str, Any] | None,
) -> list[str]:
    policy_config = _mapping_dict((benchmark_config or {}).get("policy"), field_name="policy")
    raw_rules = policy_config.get("rules")
    if raw_rules is None:
        return []
    if not isinstance(raw_rules, list):
        raise SystemExit("invalid benchmark config field: policy.rules must be a sequence")

    required: list[str] = []
    seen: set[str] = set()
    for index, raw_rule in enumerate(raw_rules, start=1):
        if not isinstance(raw_rule, Mapping):
            raise SystemExit(f"invalid benchmark config field: policy.rules[{index}] must be a mapping")
        match_config = _mapping_dict(raw_rule.get("match"), field_name=f"policy.rules[{index}].match")
        for pass_name in _policy_pass_list(
            match_config.get("has_sites"),
            field_name=f"policy.rules[{index}].match.has_sites",
        ) or []:
            if pass_name in seen:
                continue
            seen.add(pass_name)
            required.append(pass_name)
    return required


def resolve_program_enabled_passes(
    benchmark_config: Mapping[str, Any] | None,
    *,
    context: Mapping[str, Any] | None = None,
    site_counts: Mapping[str, Any] | None = None,
) -> list[str]:
    policy_config = _mapping_dict((benchmark_config or {}).get("policy"), field_name="policy")
    default_config = _mapping_dict(policy_config.get("default"), field_name="policy.default")
    raw_rules = policy_config.get("rules")
    if raw_rules is None:
        raw_rules = []
    if not isinstance(raw_rules, list):
        raise SystemExit("invalid benchmark config field: policy.rules must be a sequence")

    default_passes = _policy_pass_list(
        default_config.get("passes"),
        field_name="policy.default.passes",
    )
    active_passes = list(
        default_passes
        if default_passes is not None
        else benchmark_config_enabled_passes(benchmark_config)
    )

    for index, raw_rule in enumerate(raw_rules, start=1):
        if not isinstance(raw_rule, Mapping):
            raise SystemExit(f"invalid benchmark config field: policy.rules[{index}] must be a mapping")
        rule = dict(raw_rule)
        match_config = _mapping_dict(rule.get("match"), field_name=f"policy.rules[{index}].match")
        if not _policy_rule_matches(
            match_config,
            context=context,
            site_counts=site_counts,
            field_name=f"policy.rules[{index}].match",
        ):
            continue

        replacement_passes = _policy_pass_list(
            rule.get("passes"),
            field_name=f"policy.rules[{index}].passes",
        )
        if replacement_passes is not None:
            active_passes = list(replacement_passes)

        for pass_name in _policy_pass_list(
            rule.get("enable"),
            field_name=f"policy.rules[{index}].enable",
        ) or []:
            if pass_name not in active_passes:
                active_passes.append(pass_name)

        disabled = set(
            _policy_pass_list(
                rule.get("disable"),
                field_name=f"policy.rules[{index}].disable",
            ) or []
        )
        if disabled:
            active_passes = [pass_name for pass_name in active_passes if pass_name not in disabled]

    return active_passes


def _benchmark_int(
    benchmark_config: Mapping[str, Any] | None,
    key: str,
    *,
    default: int,
    minimum: int,
) -> int:
    value = (benchmark_config or {}).get(key)
    if value is None:
        return default
    try:
        parsed = int(value)
    except (TypeError, ValueError) as exc:
        raise SystemExit(f"invalid benchmark config field: {key} must be an integer") from exc
    if parsed < minimum:
        raise SystemExit(f"invalid benchmark config field: {key} must be >= {minimum}")
    return parsed


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
                counts[field_name] += int(item.get("sites_found") or item.get("sites_applied") or 0)
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
    return {
        "prog_id": int(prog_id),
        "sites": dict(counts),
        "counts": dict(counts),
        "error": "",
    }


def scan_programs(
    prog_ids: list[int],
    daemon: Path | str,
    *,
    prog_fds: dict[int, int] | None = None,
    timeout_seconds: int = 60,
    daemon_socket_path: Path | None = None,
    daemon_proc: subprocess.Popen[str] | None = None,
    daemon_stdout_path: Path | None = None,
    daemon_stderr_path: Path | None = None,
) -> dict[int, dict[str, Any]]:
    """Collect dry-run optimize summaries for the requested live prog_ids."""
    requested_ids = [int(prog_id) for prog_id in prog_ids if int(prog_id) > 0]
    if not requested_ids:
        return {}
    if prog_fds is not None:
        missing_prog_fds = [
            prog_id
            for prog_id in requested_ids
            if int(prog_fds.get(prog_id, 0) or 0) <= 0
        ]
        if missing_prog_fds:
            raise RuntimeError(
                "scan_programs requires loader-owned prog_fds for all requested programs: "
                + ", ".join(str(prog_id) for prog_id in missing_prog_fds)
            )
    if daemon_socket_path is None:
        raise ValueError("scan_programs requires daemon_socket_path")
    return _scan_programs_via_socket(
        requested_ids,
        daemon_socket_path,
        daemon_proc=daemon_proc,
        stdout_path=daemon_stdout_path,
        stderr_path=daemon_stderr_path,
        timeout_seconds=timeout_seconds,
    )


def _scan_programs_via_socket(
    requested_ids: list[int],
    socket_path: Path,
    *,
    daemon_proc: subprocess.Popen[str] | None = None,
    stdout_path: Path | None = None,
    stderr_path: Path | None = None,
    timeout_seconds: int = 60,
) -> dict[int, dict[str, Any]]:
    results: dict[int, dict[str, Any]] = {}
    for prog_id in requested_ids:
        response = _optimize_request(
            socket_path,
            prog_id,
            enabled_passes=None,
            dry_run=True,
            daemon_proc=daemon_proc,
            stdout_path=stdout_path,
            stderr_path=stderr_path,
            timeout_seconds=float(timeout_seconds),
        )
        if str(response.get("status") or "") != "ok":
            message = str(response.get("message") or response.get("error") or "scan failed").strip()
            raise RuntimeError(f"daemon scan failed for prog_id={prog_id}: {message}")
        results[prog_id] = _scan_record_from_optimize_response(prog_id, response)
    return results


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
    error_message = str(
        response.get("error_message")
        or response.get("message")
        or response.get("error")
        or ""
    ).strip()
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
) -> tuple[subprocess.Popen[str], Path, str, Path, Path]:
    socket_dir = tempfile.mkdtemp(prefix="bpfrejit-daemon-")
    socket_path = Path(socket_dir) / "daemon.sock"
    stdout_path = Path(socket_dir) / "daemon.stdout.log"
    stderr_path = Path(socket_dir) / "daemon.stderr.log"
    stdout_handle = stdout_path.open("w", encoding="utf-8")
    stderr_handle = stderr_path.open("w", encoding="utf-8")
    try:
        command = [str(daemon_binary), "serve", "--socket", str(socket_path)]
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


def _daemon_request(
    socket_path: Path,
    payload: Mapping[str, object],
    *,
    timeout_seconds: float,
    daemon_proc: subprocess.Popen[str] | None = None,
    stdout_path: Path | None = None,
    stderr_path: Path | None = None,
) -> dict[str, Any]:
    request = json.dumps(dict(payload)) + "\n"
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
            log_tail = _daemon_log_tail(stdout_path, stderr_path)
            details = [f"daemon socket request timed out after {timeout_seconds:.0f}s"]
            if daemon_proc is not None:
                returncode = daemon_proc.poll()
                details.append(
                    f"daemon serve rc={returncode}" if returncode is not None else "daemon serve still running"
                )
            if log_tail:
                details.append(f"daemon log tail:\n{log_tail}")
            raise RuntimeError("\n".join(details))
        except OSError as exc:
            log_tail = _daemon_log_tail(stdout_path, stderr_path)
            details = [f"daemon socket request failed: {exc}"]
            if daemon_proc is not None:
                returncode = daemon_proc.poll()
                details.append(
                    f"daemon serve rc={returncode}" if returncode is not None else "daemon serve still running"
                )
            if log_tail:
                details.append(f"daemon log tail:\n{log_tail}")
            raise RuntimeError("\n".join(details)) from exc

    line = b"".join(chunks).decode(errors="replace").strip()
    if not line:
        log_tail = _daemon_log_tail(stdout_path, stderr_path)
        detail = "daemon socket returned an empty response"
        if log_tail:
            detail += f"\ndaemon log tail:\n{log_tail}"
        raise RuntimeError(detail)
    try:
        response = json.loads(line)
    except json.JSONDecodeError as exc:
        log_tail = _daemon_log_tail(stdout_path, stderr_path)
        detail = f"daemon socket returned invalid JSON: {exc}: {line[:400]}"
        if log_tail:
            detail += f"\ndaemon log tail:\n{log_tail}"
        raise RuntimeError(detail) from exc
    if not isinstance(response, Mapping):
        log_tail = _daemon_log_tail(stdout_path, stderr_path)
        detail = f"daemon socket returned non-object JSON: {line[:400]}"
        if log_tail:
            detail += f"\ndaemon log tail:\n{log_tail}"
        raise RuntimeError(detail)
    return dict(response)


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
    response = _daemon_request(
        socket_path,
        payload,
        timeout_seconds=timeout_seconds,
        daemon_proc=daemon_proc,
        stdout_path=stdout_path,
        stderr_path=stderr_path,
    )
    return response


def _branch_flip_requested(enabled_passes: Sequence[str] | None) -> bool:
    if enabled_passes is None:
        return False
    return any(str(name).strip() == "branch_flip" for name in enabled_passes)


def _profile_request(
    socket_path: Path,
    payload: Mapping[str, object],
    *,
    daemon_proc: subprocess.Popen[str] | None = None,
    stdout_path: Path | None = None,
    stderr_path: Path | None = None,
    timeout_seconds: float = _DEFAULT_APPLY_TIMEOUT_SECONDS,
) -> dict[str, Any]:
    return _daemon_request(
        socket_path,
        payload,
        timeout_seconds=timeout_seconds,
        daemon_proc=daemon_proc,
        stdout_path=stdout_path,
        stderr_path=stderr_path,
    )


def _prepare_branch_flip_profile(
    socket_path: Path,
    *,
    daemon_proc: subprocess.Popen[str] | None = None,
    stdout_path: Path | None = None,
    stderr_path: Path | None = None,
    interval_ms: int = _DEFAULT_PROFILE_INTERVAL_MS,
    timeout_seconds: float = _DEFAULT_APPLY_TIMEOUT_SECONDS,
) -> dict[str, object] | None:
    start_response = _profile_request(
        socket_path,
        {
            "cmd": "profile-start",
            "interval_ms": int(interval_ms),
        },
        daemon_proc=daemon_proc,
        stdout_path=stdout_path,
        stderr_path=stderr_path,
        timeout_seconds=timeout_seconds,
    )
    if str(start_response.get("status") or "") != "ok":
        message = str(
            start_response.get("message")
            or start_response.get("error")
            or "profile-start failed"
        )
        return {
            "exit_code": 124 if "timed out" in message.lower() else 1,
            "output": json.dumps(start_response, sort_keys=True),
            "error": message,
        }

    time.sleep(interval_ms / 1000.0)

    stop_response = _profile_request(
        socket_path,
        {"cmd": "profile-stop"},
        daemon_proc=daemon_proc,
        stdout_path=stdout_path,
        stderr_path=stderr_path,
        timeout_seconds=timeout_seconds,
    )
    if str(stop_response.get("status") or "") != "ok":
        message = str(
            stop_response.get("message")
            or stop_response.get("error")
            or "profile-stop failed"
        )
        return {
            "exit_code": 124 if "timed out" in message.lower() else 1,
            "output": json.dumps(stop_response, sort_keys=True),
            "error": message,
        }

    return None


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
    prog_ids: list[int] | None = None,
    *,
    enabled_passes: Sequence[str] | None = None,
    daemon_socket_path: Path | None = None,
    daemon_proc: subprocess.Popen[str] | None = None,
    daemon_stdout_path: Path | None = None,
    daemon_stderr_path: Path | None = None,
) -> dict[str, object]:
    """Apply serve-mode optimize requests over an existing daemon socket."""
    requested_prog_ids = [int(value) for value in (prog_ids or []) if int(value) > 0]
    if not requested_prog_ids:
        raise ValueError("apply_daemon_rejit requires at least one prog_id")
    if daemon_socket_path is None:
        raise ValueError("apply_daemon_rejit requires daemon_socket_path")
    return _apply_daemon_rejit_via_socket(
        requested_prog_ids,
        daemon_socket_path,
        enabled_passes=enabled_passes,
        daemon_proc=daemon_proc,
        stdout_path=daemon_stdout_path,
        stderr_path=daemon_stderr_path,
    )


def _apply_daemon_rejit_via_socket(
    requested_prog_ids: list[int],
    socket_path: Path,
    *,
    enabled_passes: Sequence[str] | None = None,
    daemon_proc: subprocess.Popen[str] | None = None,
    stdout_path: Path | None = None,
    stderr_path: Path | None = None,
) -> dict[str, object]:
    per_program: dict[int, dict[str, object]] = {}
    outputs: list[str] = []
    exit_code = 0
    applied_any = False
    all_applied = True
    total_sites = 0
    applied_sites = 0
    errors: list[str] = []

    if _branch_flip_requested(enabled_passes):
        profile_error = _prepare_branch_flip_profile(
            socket_path,
            daemon_proc=daemon_proc,
            stdout_path=stdout_path,
            stderr_path=stderr_path,
        )
        if profile_error is not None:
            return {
                "applied": False,
                "applied_any": False,
                "all_applied": False,
                "output": str(profile_error.get("output") or ""),
                "exit_code": int(profile_error.get("exit_code", 1) or 1),
                "per_program": {},
                "counts": {
                    "total_sites": 0,
                    "applied_sites": 0,
                },
                "program_counts": {
                    "requested": len(requested_prog_ids),
                    "applied": 0,
                    "not_applied": len(requested_prog_ids),
                },
                "error": str(profile_error.get("error") or "profile collection failed"),
            }
    for prog_id in requested_prog_ids:
        result = _apply_one_via_socket(
            socket_path,
            prog_id,
            enabled_passes,
            daemon_proc=daemon_proc,
            stdout_path=stdout_path,
            stderr_path=stderr_path,
        )
        per_program[prog_id] = result
        outputs.append(str(result.get("output") or ""))
        exit_code = max(exit_code, int(result.get("exit_code", 0) or 0))
        applied_any = applied_any or bool(result.get("applied", False))
        all_applied = all_applied and bool(result.get("applied", False))

        counts = result.get("counts") if isinstance(result.get("counts"), Mapping) else {}
        total_sites += int((counts or {}).get("total_sites", 0) or 0)
        applied_sites += int((counts or {}).get("applied_sites", 0) or 0)

        error = str(result.get("error") or "").strip()
        if error:
            errors.append(f"prog {prog_id}: {error}")

    return {
        "applied": applied_any,
        "applied_any": applied_any,
        "all_applied": all_applied,
        "output": "\n".join(output for output in outputs if output),
        "exit_code": exit_code,
        "per_program": per_program,
        "counts": {
            "total_sites": total_sites,
            "applied_sites": applied_sites,
        },
        "program_counts": {
            "requested": len(requested_prog_ids),
            "applied": sum(1 for record in per_program.values() if bool(record.get("applied", False))),
            "not_applied": sum(1 for record in per_program.values() if not bool(record.get("applied", False))),
        },
        "error": "; ".join(errors),
    }


__all__ = [
    "apply_daemon_rejit",
    "benchmark_config_enabled_passes",
    "benchmark_config_iterations",
    "benchmark_policy_required_site_passes",
    "benchmark_config_repeat",
    "benchmark_config_warmups",
    "benchmark_rejit_enabled_passes",
    "load_benchmark_config",
    "resolve_program_enabled_passes",
    "scan_programs",
]
