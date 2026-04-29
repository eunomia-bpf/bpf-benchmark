from __future__ import annotations

import json
import os
import shutil
import socket
import subprocess
import tempfile
import time
from dataclasses import dataclass, field
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
    "bounds_check_merge": "bounds_check_merge_sites",
    "bulk_memory": "bulk_memory_sites",
    "cond_select": "cmov_sites",
    "endian_fusion": "endian_sites",
    "extract": "extract_sites",
    "rotate": "rotate_sites",
    "skb_load_bytes_spec": "skb_load_bytes_spec_sites",
    "wide_mem": "wide_sites",
}
_TOTAL_SITE_FIELDS = (
    "map_inline_sites",
    "const_prop_sites",
    "dce_sites",
    "bounds_check_merge_sites",
    "bulk_memory_sites",
    "cmov_sites",
    "wide_sites",
    "rotate_sites",
    "lea_sites",
    "extract_sites",
    "endian_sites",
    "skb_load_bytes_spec_sites",
    "branch_flip_sites",
    "other_sites",
)

_BENCH_PASSES_ENV = "BPFREJIT_BENCH_PASSES"
_BENCHMARK_CONFIG_PATH = ROOT_DIR / "corpus" / "config" / "benchmark_config.yaml"
_APPLY_TIMEOUT_ENV = "BPFREJIT_DAEMON_REQUEST_TIMEOUT_S"
_FALLBACK_APPLY_TIMEOUT_SECONDS = 600.0
_DEFAULT_BENCHMARK_REPEAT = 200
_DEFAULT_PROFILE_INTERVAL_MS = 1000


def _default_apply_timeout_seconds() -> float:
    raw = os.environ.get(_APPLY_TIMEOUT_ENV, "").strip()
    if not raw:
        return _FALLBACK_APPLY_TIMEOUT_SECONDS
    try:
        value = float(raw)
    except ValueError as exc:
        raise RuntimeError(f"{_APPLY_TIMEOUT_ENV} must be a positive number, got {raw!r}") from exc
    if value <= 0.0:
        raise RuntimeError(f"{_APPLY_TIMEOUT_ENV} must be positive, got {raw!r}")
    return value


_DEFAULT_APPLY_TIMEOUT_SECONDS = _default_apply_timeout_seconds()


def _validate_daemon_runtime_root(candidate: Path, *, source: str) -> Path:
    try:
        candidate.mkdir(parents=True, exist_ok=True)
    except OSError as exc:
        raise RuntimeError(f"{source} is unusable at {candidate}: {exc}") from exc
    if not candidate.is_dir():
        raise RuntimeError(f"{source} is unusable at {candidate}: not a directory")
    if not os.access(candidate, os.W_OK | os.X_OK):
        raise RuntimeError(f"{source} is unusable at {candidate}: missing write/execute access")
    return candidate


def _daemon_runtime_root() -> Path:
    explicit = os.environ.get("BPFREJIT_DAEMON_TMPDIR", "").strip()
    if explicit:
        return _validate_daemon_runtime_root(
            Path(explicit).expanduser(),
            source="BPFREJIT_DAEMON_TMPDIR",
        )

    candidates: list[Path] = []
    for raw_candidate in (
        Path("/var/tmp/bpfrejit-daemon"),
        Path("/tmp/bpfrejit-daemon"),
        Path(tempfile.gettempdir()).expanduser() / "bpfrejit-daemon",
    ):
        candidate = raw_candidate.expanduser()
        if candidate not in candidates:
            candidates.append(candidate)

    errors: list[str] = []
    for candidate in candidates:
        try:
            return _validate_daemon_runtime_root(
                candidate,
                source="daemon runtime tmpdir candidate",
            )
        except RuntimeError as exc:
            errors.append(str(exc))
    raise RuntimeError("no usable daemon runtime tmpdir found: " + "; ".join(errors))


def _mapping_dict(value: Any, *, field_name: str) -> dict[str, Any]:
    if value is None:
        return {}
    if not isinstance(value, Mapping):
        raise SystemExit(f"invalid benchmark config field: {field_name} must be a mapping")
    return dict(value)


def _deep_merge(base: Mapping[str, Any], override: Mapping[str, Any]) -> dict[str, Any]:
    merged = dict(base)
    for key, value in override.items():
        existing = merged.get(key)
        if isinstance(value, Mapping) and isinstance(existing, Mapping):
            merged[key] = _deep_merge(existing, value)
        else:
            merged[key] = value
    return merged


_CONFIG_SKELETON: dict[str, Any] = {
    "defaults": {
        "iterations": 3,
        "warmups": 1,
        "repeat": _DEFAULT_BENCHMARK_REPEAT,
    },
    "passes": {},
    "policy": {"rules": []},
    "profiles": {},
}


@lru_cache(maxsize=1)
def _load_benchmark_root_config() -> dict[str, Any]:
    try:
        payload = yaml.safe_load(_BENCHMARK_CONFIG_PATH.read_text(encoding="utf-8"))
    except OSError as exc:
        raise SystemExit(f"benchmark config file not found: {_BENCHMARK_CONFIG_PATH}") from exc
    if payload is None:
        return dict(_CONFIG_SKELETON)
    if not isinstance(payload, Mapping):
        raise SystemExit(f"benchmark config must be a YAML mapping: {_BENCHMARK_CONFIG_PATH}")
    return _deep_merge(_CONFIG_SKELETON, payload)


def load_benchmark_config(profile: str | None = None) -> dict[str, Any]:
    rc = _load_benchmark_root_config()
    defaults = _mapping_dict(rc.get("defaults"), field_name="defaults")
    passes = _mapping_dict(rc.get("passes"), field_name="passes")
    policy = _mapping_dict(rc.get("policy"), field_name="policy")
    profiles = _mapping_dict(rc.get("profiles"), field_name="profiles")

    profile_overrides: dict[str, Any] = {}
    if profile:
        if (raw_profile := profiles.get(profile)) is None:
            available = ", ".join(sorted(profiles))
            raise SystemExit(f"unknown benchmark profile: {profile}" + (f" (available: {available})" if available else ""))
        profile_overrides = _mapping_dict(raw_profile, field_name=f"profiles.{profile}")

    effective = _deep_merge({**defaults, "passes": passes, "policy": policy}, profile_overrides)
    effective["passes"] = _mapping_dict(effective.get("passes"), field_name="passes")
    effective["policy"] = _mapping_dict(effective.get("policy"), field_name="policy")
    effective.update(profile=profile, config_path=_BENCHMARK_CONFIG_PATH,
                     config_loaded=True, available_profiles=sorted(profiles))
    return effective


def _ordered_unique_passes(raw: Sequence[str] | Sequence[object]) -> list[str]:
    ordered: list[str] = []
    seen: set[str] = set()
    for value in raw:
        name = str(value).strip()
        if not name or name in seen:
            continue
        seen.add(name)
        ordered.append(name)
    return ordered


def _normalize_pass_list(raw: Any) -> list[str]:
    return _ordered_unique_passes(raw) if isinstance(raw, list) else []


def _strict_non_negative_int(value: object, *, field_name: str) -> int:
    if isinstance(value, bool) or not isinstance(value, int):
        raise RuntimeError(f"daemon response field {field_name!r} must be a non-negative integer")
    if value < 0:
        raise RuntimeError(f"daemon response field {field_name!r} must be a non-negative integer")
    return value


def _normalize_apply_passes(
    raw_passes: object,
    *,
    field_name: str = "passes",
) -> list[dict[str, object]]:
    if not isinstance(raw_passes, list):
        raise RuntimeError(f"daemon response field {field_name!r} must be a list")

    normalized: list[dict[str, object]] = []
    for index, item in enumerate(raw_passes):
        if not isinstance(item, Mapping):
            raise RuntimeError(f"daemon response field {field_name}[{index}] must be an object")
        pass_name = str(item.get("pass_name") or "").strip()
        if not pass_name:
            raise RuntimeError(
                f"daemon response field {field_name}[{index}].pass_name must be a non-empty string"
            )
        if pass_name not in _PASS_TO_SITE_FIELD:
            raise RuntimeError(
                f"daemon response field {field_name}[{index}].pass_name contains unknown pass "
                f"{pass_name!r}"
            )
        action = str(item.get("action") or "kept").strip()
        if action not in {"kept", "rolled_back"}:
            raise RuntimeError(
                f"daemon response field {field_name}[{index}].action must be 'kept' or 'rolled_back'"
            )
        normalized.append(
            {
                "pass_name": pass_name,
                "action": action,
                "sites_applied": _strict_non_negative_int(
                    item.get("sites_applied"),
                    field_name=f"{field_name}[{index}].sites_applied",
                ),
            }
        )
    return normalized

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


def benchmark_config_enabled_passes(benchmark_config: Mapping[str, Any] | None) -> list[str]:
    policy_config = _mapping_dict((benchmark_config or {}).get("policy"), field_name="policy")
    policy_default = _mapping_dict(policy_config.get("default"), field_name="policy.default")
    policy_default_passes = _policy_pass_list(policy_default.get("passes"), field_name="policy.default.passes")
    if policy_default_passes is not None:
        return _ordered_unique_passes(policy_default_passes)

    passes_config = _mapping_dict((benchmark_config or {}).get("passes"), field_name="passes")
    if active_list := _normalize_pass_list(passes_config.get("active_list")):
        return active_list
    raise SystemExit(
        "benchmark config must define policy.default.passes or passes.active_list "
        "when no explicit pass override is supplied"
    )


def _policy_exclusion_label(match_config: Mapping[str, Any], *, field_name: str) -> str:
    prog_types = _policy_match_values(
        match_config.get("prog_type"),
        field_name=f"{field_name}.prog_type",
    )
    other_keys = [key for key in match_config if key != "prog_type"]
    if len(prog_types) == 1 and not other_keys:
        return prog_types[0]

    parts: list[str] = []
    for key, raw_value in match_config.items():
        current_field = f"{field_name}.{key}"
        if key == "has_sites":
            values = _policy_pass_list(raw_value, field_name=current_field) or []
        else:
            values = _policy_match_values(raw_value, field_name=current_field)
        if values:
            parts.append(f"{key}=" + ",".join(values))
    return " & ".join(parts) if parts else "default"


def benchmark_policy_exclusions(benchmark_config: Mapping[str, Any] | None) -> dict[str, list[str]]:
    policy_config = _mapping_dict((benchmark_config or {}).get("policy"), field_name="policy")
    exclusions: dict[str, list[str]] = {}
    for index, raw_rule in enumerate(_policy_rules_list(policy_config), start=1):
        if not isinstance(raw_rule, Mapping):
            raise SystemExit(f"invalid benchmark config field: policy.rules[{index}] must be a mapping")
        disabled = _policy_pass_list(
            raw_rule.get("disable"),
            field_name=f"policy.rules[{index}].disable",
        ) or []
        if not disabled:
            continue
        match_config = _mapping_dict(
            raw_rule.get("match"),
            field_name=f"policy.rules[{index}].match",
        )
        label = _policy_exclusion_label(
            match_config,
            field_name=f"policy.rules[{index}].match",
        )
        current = exclusions.setdefault(label, [])
        for pass_name in disabled:
            if pass_name not in current:
                current.append(pass_name)
    return exclusions


def _policy_rules_list(policy_config: Mapping[str, Any]) -> list[Any]:
    raw_rules = policy_config.get("rules")
    if raw_rules is None: return []
    if not isinstance(raw_rules, list):
        raise SystemExit("invalid benchmark config field: policy.rules must be a sequence")
    return raw_rules


@lru_cache(maxsize=1)
def _cached_benchmark_config_enabled_passes() -> tuple[str, ...]:
    return tuple(benchmark_config_enabled_passes(load_benchmark_config()))


def _zero_site_counts() -> dict[str, int]:
    return dict.fromkeys(("total_sites", *_TOTAL_SITE_FIELDS, "bitfield_sites"), 0)

def benchmark_rejit_enabled_passes() -> list[str]:
    raw = os.environ.get(_BENCH_PASSES_ENV)
    if raw is not None:
        text = raw.strip()
        if text.lower() == "default":
            return list(_cached_benchmark_config_enabled_passes())
        return [token.strip() for token in text.split(",") if token.strip()]
    return list(_cached_benchmark_config_enabled_passes())


def benchmark_run_provenance() -> dict[str, object]:
    benchmark_config = load_benchmark_config()
    return {
        "config": {"enabled_passes": benchmark_rejit_enabled_passes()},
        "policy": {"exclusions": benchmark_policy_exclusions(benchmark_config)},
    }


_SKIP_IN_PASS_TOTAL = frozenset(("lea_sites", "other_sites"))


def _accumulate_pass_site_counts(
    raw_passes: object,
    counts: dict[str, int],
    *,
    also_found: bool = False,
    include_rolled_back: bool = True,
    field_name: str = "passes",
) -> None:
    if not isinstance(raw_passes, list):
        raise RuntimeError(f"daemon response field {field_name!r} must be a list")
    for index, item in enumerate(raw_passes):
        if not isinstance(item, Mapping):
            raise RuntimeError(f"daemon response field {field_name}[{index}] must be an object")
        pass_name = str(item.get("pass_name") or "").strip()
        if not pass_name:
            raise RuntimeError(
                f"daemon response field {field_name}[{index}].pass_name must be a non-empty string"
            )
        count_field = _PASS_TO_SITE_FIELD.get(pass_name)
        if count_field is None:
            raise RuntimeError(
                f"daemon response field {field_name}[{index}].pass_name contains unknown pass "
                f"{pass_name!r}"
            )
        action = str(item.get("action") or "kept").strip()
        if action not in {"kept", "rolled_back"}:
            raise RuntimeError(
                f"daemon response field {field_name}[{index}].action must be 'kept' or 'rolled_back'"
            )
        if not include_rolled_back and action == "rolled_back":
            continue
        count_key = "sites_applied"
        if also_found and "sites_found" in item:
            count_key = "sites_found"
        value = item.get(count_key)
        if value is None and also_found and count_key == "sites_found":
            count_key = "sites_applied"
            value = item.get(count_key)
        if isinstance(value, bool) or not isinstance(value, int):
            raise RuntimeError(
                f"daemon response field {field_name}[{index}].{count_key} must be a non-negative integer"
            )
        if value < 0:
            raise RuntimeError(
                f"daemon response field {field_name}[{index}].{count_key} must be a non-negative integer"
            )
        counts[count_field] += value


def _applied_site_totals_from_passes(raw_passes: object) -> dict[str, int]:
    counts = _zero_site_counts()
    _accumulate_pass_site_counts(raw_passes, counts, include_rolled_back=False, field_name="passes")
    counts["bitfield_sites"] = counts["extract_sites"]
    counts["total_sites"] = sum(counts[f] for f in _TOTAL_SITE_FIELDS if f not in _SKIP_IN_PASS_TOTAL)
    return counts


def applied_site_totals_from_rejit_result(result: Mapping[str, Any] | None) -> dict[str, int]:
    counts = _zero_site_counts()
    if not isinstance(result, Mapping):
        return counts

    per_program = result.get("per_program")
    if isinstance(per_program, Mapping):
        for record in per_program.values():
            pc = applied_site_totals_from_rejit_result(record if isinstance(record, Mapping) else None)
            for f in counts:
                counts[f] += int(pc.get(f, 0) or 0)
        return counts

    dbg_val = result.get("debug_result")
    debug_result: Mapping[str, Any] = dbg_val if isinstance(dbg_val, Mapping) else {}
    raw_passes = debug_result.get("passes")
    if raw_passes is None:
        raw_passes = result.get("passes")
    if raw_passes is not None:
        counts = _applied_site_totals_from_passes(raw_passes)
    elif isinstance(summary := result.get("summary"), Mapping):
        total_sites_applied = summary.get("total_sites_applied")
        if isinstance(total_sites_applied, bool) or not isinstance(total_sites_applied, int):
            raise RuntimeError(
                "daemon response field 'summary.total_sites_applied' must be a non-negative integer"
            )
        if total_sites_applied < 0:
            raise RuntimeError(
                "daemon response field 'summary.total_sites_applied' must be a non-negative integer"
            )
        counts["total_sites"] = total_sites_applied
    return counts


_ARTIFACT_REJIT_RESULT_KEYS = frozenset(
    {
        "applied",
        "changed",
        "debug_result",
        "enabled_passes",
        "error",
        "exit_code",
        "inlined_map_entries",
        "output",
        "passes",
        "per_program",
        "prog_id",
        "program_counts",
        "summary",
    }
)


def _compact_single_rejit_result_for_artifact(result: Mapping[str, Any]) -> dict[str, object]:
    compact: dict[str, object] = {}

    for key in ("prog_id", "applied", "changed", "exit_code"):
        if key in result:
            compact[key] = result.get(key)

    if "error" in result:
        compact["error"] = str(result.get("error") or "")

    enabled_passes = result.get("enabled_passes")
    if isinstance(enabled_passes, Sequence) and not isinstance(enabled_passes, (str, bytes, bytearray)):
        compact["enabled_passes"] = [str(name).strip() for name in enabled_passes if str(name).strip()]

    for key in ("summary", "program_counts"):
        value = result.get(key)
        if isinstance(value, Mapping):
            compact[key] = dict(value)

    raw_per_program = result.get("per_program")
    if isinstance(raw_per_program, Mapping):
        error_programs: list[dict[str, object]] = []
        for prog_id, record in raw_per_program.items():
            if not isinstance(record, Mapping):
                continue
            error = str(record.get("error") or "")
            exit_code = int(record.get("exit_code", 0) or 0)
            applied = bool(record.get("applied", False))
            if not error and exit_code == 0:
                continue
            error_programs.append(
                {
                    "prog_id": int(record.get("prog_id", prog_id) or prog_id),
                    "applied": applied,
                    "changed": bool(record.get("changed", False)),
                    "exit_code": exit_code,
                    "error": error,
                }
            )
        if error_programs:
            compact["error_programs"] = error_programs

    return compact


def compact_rejit_result_for_artifact(result: Mapping[str, Any] | None) -> dict[str, object] | None:
    if not isinstance(result, Mapping):
        return None
    if any(str(key) in _ARTIFACT_REJIT_RESULT_KEYS for key in result.keys()):
        return _compact_single_rejit_result_for_artifact(result)
    return {
        key: compact_rejit_result_for_artifact(value if isinstance(value, Mapping) else None) if isinstance(value, Mapping) else value
        for key, value in result.items()
    }


def compact_rejit_results_for_artifact(payload: Any) -> Any:
    if isinstance(payload, Mapping):
        compacted: dict[str, Any] = {}
        for key, value in payload.items():
            if str(key) == "rejit_result":
                compacted[key] = compact_rejit_result_for_artifact(
                    value if isinstance(value, Mapping) else None
                )
            else:
                compacted[key] = compact_rejit_results_for_artifact(value)
        return compacted
    if isinstance(payload, list):
        return [compact_rejit_results_for_artifact(item) for item in payload]
    return payload


def _apply_result_from_response(
    response: dict[str, Any],
    *,
    output: str,
    exit_code: int,
    enabled_passes: Sequence[str] | None,
) -> dict[str, object]:
    status = str(response.get("status") or "").strip()
    summary_value = response.get("summary")
    summary: dict[str, Any] = dict(summary_value) if isinstance(summary_value, Mapping) else {}
    error = str(response.get("error_message") or "").strip()
    normalized_enabled_passes = (
        _normalize_pass_list(list(enabled_passes))
        if enabled_passes is not None
        else None
    )
    passes: list[dict[str, object]] = []

    applied = False
    changed = False
    if status == "ok":
        try:
            if not isinstance(summary_value, Mapping):
                raise RuntimeError("daemon response field 'summary' must be an object")
            summary_applied = summary.get("applied")
            if not isinstance(summary_applied, bool):
                raise RuntimeError("daemon response field 'summary.applied' must be a boolean")
            changed = response.get("changed")
            if not isinstance(changed, bool):
                raise RuntimeError("daemon response field 'changed' must be a boolean")
            total_sites_applied = summary.get("total_sites_applied")
            total_sites_applied = _strict_non_negative_int(
                total_sites_applied,
                field_name="summary.total_sites_applied",
            )
            passes_executed = _strict_non_negative_int(
                summary.get("passes_executed"),
                field_name="summary.passes_executed",
            )
            passes = _normalize_apply_passes(response.get("passes"), field_name="passes")
            if passes_executed != len(passes):
                raise RuntimeError(
                    "daemon response fields 'summary.passes_executed' and 'passes' length disagree"
                )
            pass_sites_applied = sum(
                int(item["sites_applied"])
                for item in passes
                if str(item.get("action") or "kept") != "rolled_back"
            )
            if total_sites_applied != pass_sites_applied:
                raise RuntimeError(
                    "daemon response fields 'summary.total_sites_applied' and "
                    "'passes[].sites_applied' disagree"
                )
            applied = exit_code == 0 and summary_applied
            changed = exit_code == 0 and changed
        except RuntimeError as exc:
            exit_code = 1
            error = str(exc)
            changed = False
            passes = []

    return {
        "applied": applied,
        "changed": changed,
        "output": output,
        "exit_code": exit_code,
        "enabled_passes": normalized_enabled_passes,
        "passes": passes,
        "debug_result": dict(response),
        "inlined_map_entries": [dict(e) for e in (response.get("inlined_map_entries") or []) if isinstance(e, Mapping)],
        "summary": dict(summary),
        "error": error,
    }


def _daemon_log_tail(stdout_path: Path | None, stderr_path: Path | None) -> str:
    def _read(p: Path | None) -> str:
        if p is None:
            return ""
        try:
            return p.read_text(encoding="utf-8", errors="replace")
        except OSError:
            return ""
    text = "\n".join(t for p in (stderr_path, stdout_path) if (t := _read(p)).strip())
    return tail_text(text, max_lines=80, max_chars=8000)


def _start_daemon_server(daemon_binary: Path | str) -> tuple[subprocess.Popen[str], Path, str, Path, Path]:
    socket_dir = tempfile.mkdtemp(prefix="bd-", dir=str(_daemon_runtime_root()))
    socket_path = Path(socket_dir) / "daemon.sock"
    stdout_path = Path(socket_dir) / "daemon.stdout.log"
    stderr_path = Path(socket_dir) / "daemon.stderr.log"
    with stdout_path.open("w", encoding="utf-8") as out, stderr_path.open("w", encoding="utf-8") as err:
        proc = subprocess.Popen([str(daemon_binary), "serve", "--socket", str(socket_path)], stdout=out, stderr=err, text=True)
    deadline = time.monotonic() + 5.0
    while time.monotonic() < deadline:
        if socket_path.exists():
            return proc, socket_path, socket_dir, stdout_path, stderr_path
        if proc.poll() is not None:
            raise RuntimeError(f"daemon serve exited early (rc={proc.returncode}): {_daemon_log_tail(stdout_path, stderr_path)}")
        time.sleep(0.05)
    _kill_proc(proc, timeout=1)
    raise RuntimeError(f"timed out waiting for daemon socket: {_daemon_log_tail(stdout_path, stderr_path)}")


def _kill_proc(proc: subprocess.Popen[str], *, timeout: int) -> None:
    proc.terminate()
    try: proc.wait(timeout=timeout)
    except subprocess.TimeoutExpired: proc.kill(); proc.wait(timeout=timeout)


def _stop_daemon_server(proc: subprocess.Popen[str], socket_path: Path, socket_dir: str) -> None:
    _kill_proc(proc, timeout=5)
    socket_path.unlink(missing_ok=True)
    shutil.rmtree(socket_dir, ignore_errors=True)


def _daemon_error_detail(lead: str, *, daemon_proc: subprocess.Popen[str] | None, stdout_path: Path | None, stderr_path: Path | None) -> str:
    parts = [lead]
    if daemon_proc is not None:
        rc = daemon_proc.poll()
        parts.append(f"daemon serve rc={rc}" if rc is not None else "daemon serve still running")
    if log_tail := _daemon_log_tail(stdout_path, stderr_path):
        parts.append(f"daemon log tail:\n{log_tail}")
    return "\n".join(parts)


def _daemon_request(
    socket_path: Path, payload: Mapping[str, object], *,
    timeout_seconds: float, daemon_proc: subprocess.Popen[str] | None = None,
    stdout_path: Path | None = None, stderr_path: Path | None = None,
) -> dict[str, Any]:
    request = json.dumps(dict(payload)) + "\n"
    kw = {"daemon_proc": daemon_proc, "stdout_path": stdout_path, "stderr_path": stderr_path}
    with socket.socket(socket.AF_UNIX, socket.SOCK_STREAM) as client:
        client.settimeout(timeout_seconds)
        try:
            client.connect(str(socket_path))
            client.sendall(request.encode())
            chunks: list[bytes] = []
            while True:
                chunk = client.recv(4096)
                if not chunk: break
                chunks.append(chunk)
                if b"\n" in chunk: break
        except socket.timeout:
            raise RuntimeError(_daemon_error_detail(f"daemon socket request timed out after {timeout_seconds:.0f}s", **kw))
        except OSError as exc:
            raise RuntimeError(_daemon_error_detail(f"daemon socket request failed: {exc}", **kw)) from exc
    line = b"".join(chunks).decode(errors="replace").strip()
    suffix = (f"\ndaemon log tail:\n{lt}" if (lt := _daemon_log_tail(stdout_path, stderr_path)) else "")
    if not line:
        raise RuntimeError("daemon socket returned an empty response" + suffix)
    try:
        response = json.loads(line)
    except json.JSONDecodeError as exc:
        raise RuntimeError(f"daemon socket returned invalid JSON: {exc}: {line[:400]}{suffix}") from exc
    if not isinstance(response, Mapping):
        raise RuntimeError(f"daemon socket returned non-object JSON: {line[:400]}{suffix}")
    return dict(response)  # type: ignore[arg-type]


def _optimize_request(
    socket_path: Path, prog_id: int, *, enabled_passes: Sequence[str] | None, dry_run: bool,
    daemon_proc: subprocess.Popen[str] | None = None, stdout_path: Path | None = None,
    stderr_path: Path | None = None, timeout_seconds: float = _DEFAULT_APPLY_TIMEOUT_SECONDS,
) -> dict[str, Any]:
    payload: dict[str, object] = {"cmd": "optimize", "prog_id": int(prog_id)}
    if dry_run:
        payload["dry_run"] = True
    if enabled_passes is not None:
        payload["enabled_passes"] = [str(n).strip() for n in enabled_passes if str(n).strip()]
    return _daemon_request(socket_path, payload, timeout_seconds=timeout_seconds,
                           daemon_proc=daemon_proc, stdout_path=stdout_path, stderr_path=stderr_path)


def _prepare_branch_flip_profile(
    socket_path: Path,
    *,
    daemon_proc: subprocess.Popen[str] | None = None,
    stdout_path: Path | None = None,
    stderr_path: Path | None = None,
    interval_ms: int = _DEFAULT_PROFILE_INTERVAL_MS,
    timeout_seconds: float = _DEFAULT_APPLY_TIMEOUT_SECONDS,
) -> dict[str, object] | None:
    kw: dict[str, Any] = {"timeout_seconds": timeout_seconds, "daemon_proc": daemon_proc,
                          "stdout_path": stdout_path, "stderr_path": stderr_path}

    def _profile_cmd(payload: dict[str, object], default_msg: str) -> dict[str, object] | None:
        resp = _daemon_request(socket_path, payload, **kw)
        if str(resp.get("status") or "") != "ok":
            msg = str(resp.get("error_message") or default_msg)
            return {"exit_code": 124 if "timed out" in msg.lower() else 1,
                    "output": json.dumps(resp, sort_keys=True), "error": msg}
        return None

    err = _profile_cmd({"cmd": "profile-start", "interval_ms": int(interval_ms)}, "profile-start failed")
    if err is not None:
        return err
    time.sleep(interval_ms / 1000.0)
    return _profile_cmd({"cmd": "profile-stop"}, "profile-stop failed")


def apply_daemon_rejit(
    prog_ids: list[int] | None = None,
    *,
    enabled_passes: Sequence[str] | None = None,
    daemon_socket_path: Path | None = None,
    daemon_proc: subprocess.Popen[str] | None = None,
    daemon_stdout_path: Path | None = None,
    daemon_stderr_path: Path | None = None,
) -> dict[str, object]:
    prog_ids = [int(v) for v in (prog_ids or []) if int(v) > 0]
    if not prog_ids:
        raise ValueError("apply_daemon_rejit requires at least one prog_id")
    if daemon_socket_path is None:
        raise ValueError("apply_daemon_rejit requires daemon_socket_path")
    normalized_enabled_passes = (
        _normalize_pass_list(list(enabled_passes))
        if enabled_passes is not None
        else None
    )
    per_program: dict[int, dict[str, object]] = {}
    outputs: list[str] = []
    exit_code = 0
    applied = False
    changed = False
    errors: list[str] = []
    if normalized_enabled_passes and "branch_flip" in normalized_enabled_passes:
        profile_error = _prepare_branch_flip_profile(daemon_socket_path, daemon_proc=daemon_proc,
                                                      stdout_path=daemon_stdout_path, stderr_path=daemon_stderr_path)
        if profile_error is not None:
            ec = int(profile_error.get("exit_code", 1) or 1)
            out = str(profile_error.get("output") or "")
            msg = str(profile_error.get("error") or "profile collection failed")
            return {
                "applied": False,
                "changed": False,
                "output": out, "exit_code": ec, "error": msg,
                "enabled_passes": normalized_enabled_passes,
                "passes": [],
                "per_program": {int(pid): {"prog_id": int(pid), "applied": False, "changed": False,
                                           "output": out, "exit_code": ec, "error": msg,
                                           "enabled_passes": normalized_enabled_passes, "passes": []}
                                for pid in prog_ids},
                "program_counts": {"requested": len(prog_ids), "applied": 0, "not_applied": len(prog_ids)},
            }
    for prog_id in prog_ids:
        _resp = _optimize_request(daemon_socket_path, prog_id, enabled_passes=normalized_enabled_passes, dry_run=False,
                                   daemon_proc=daemon_proc, stdout_path=daemon_stdout_path, stderr_path=daemon_stderr_path)
        result = _apply_result_from_response(_resp, output=json.dumps(_resp, sort_keys=True),
                                              exit_code=0 if str(_resp.get("status") or "") == "ok" else 1,
                                              enabled_passes=normalized_enabled_passes)
        per_program[prog_id] = result
        outputs.append(str(result.get("output") or ""))
        exit_code = max(exit_code, int(result.get("exit_code", 0) or 0))
        applied = applied or bool(result.get("applied", False))
        changed = changed or bool(result.get("changed", False))
        if error := str(result.get("error") or "").strip():
            errors.append(f"prog {prog_id}: {error}")
    n_applied = sum(1 for r in per_program.values() if r.get("applied", False))
    return {
        "applied": applied,
        "changed": changed,
        "output": "\n".join(o for o in outputs if o), "exit_code": exit_code, "per_program": per_program,
        "enabled_passes": normalized_enabled_passes,
        "program_counts": {"requested": len(prog_ids), "applied": n_applied, "not_applied": len(prog_ids) - n_applied},
        "error": "; ".join(errors),
    }


@dataclass
class DaemonSession:
    daemon_binary: Path
    proc: object
    socket_path: Path
    socket_dir: str
    stdout_path: Path
    stderr_path: Path
    kinsn_metadata: dict[str, object] = field(default_factory=dict)
    load_kinsn: bool = False
    _closed: bool = False

    @classmethod
    def start(cls, daemon_binary: Path | str, *, load_kinsn: bool = False) -> "DaemonSession":
        from .kinsn import prepare_kinsn_modules  # noqa: PLC0415
        binary = Path(daemon_binary).resolve()
        kinsn_metadata: dict[str, object] = dict(prepare_kinsn_modules()) if load_kinsn else {}
        proc, socket_path, socket_dir, stdout_path, stderr_path = _start_daemon_server(binary)
        if load_kinsn:
            kinsn_metadata["daemon_binary"] = str(binary)
        return cls(daemon_binary=binary, proc=proc, socket_path=socket_path, socket_dir=socket_dir,
                   stdout_path=stdout_path, stderr_path=stderr_path,
                   kinsn_metadata=kinsn_metadata, load_kinsn=bool(load_kinsn))

    def __enter__(self) -> "DaemonSession":
        return self

    def __exit__(self, exc_type: object, exc: object, tb: object) -> None:
        del exc_type, exc, tb
        self.close()

    def close(self) -> None:
        if self._closed:
            return
        self._closed = True
        _stop_daemon_server(self.proc, self.socket_path, self.socket_dir)

    def apply_rejit(self, prog_ids: Sequence[int], *, enabled_passes: Sequence[str] | None = None) -> dict[str, object]:
        return apply_daemon_rejit([int(p) for p in prog_ids if int(p) > 0], enabled_passes=enabled_passes,
                                   daemon_socket_path=self.socket_path, daemon_proc=self.proc,
                                   daemon_stdout_path=self.stdout_path, daemon_stderr_path=self.stderr_path)
