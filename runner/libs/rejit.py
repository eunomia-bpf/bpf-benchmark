from __future__ import annotations

import base64
import binascii
import json
import os
import platform
import socket
import time
from functools import lru_cache
from pathlib import Path
from typing import Any, Mapping, Sequence

from . import rejit_plan

import yaml

from . import ROOT_DIR


_BENCH_PASSES_ENV = "BPFREJIT_BENCH_PASSES"
_SKIP_REJIT_ENV = "SKIP_REJIT"
_BENCHMARK_CONFIG_PATH = ROOT_DIR / "corpus" / "config" / "benchmark_config.yaml"
_DEFAULT_BENCHMARK_REPEAT = 200


def skip_rejit_mode(raw: str | None = None) -> str:
    value = (os.environ.get(_SKIP_REJIT_ENV, "") if raw is None else str(raw)).strip().lower()
    if value in ("", "0", "false", "no", "off"):
        return "off"
    if value == "norejit":
        return "norejit"
    if value == "all":
        return "all"
    raise ValueError("SKIP_REJIT must be empty, 0, norejit, or all")


def skip_rejit_enabled(raw: str | None = None) -> bool:
    return skip_rejit_mode(raw) != "off"


def skip_rejit_disables_shim(raw: str | None = None) -> bool:
    return skip_rejit_mode(raw) == "all"


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
    "policy": {},
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


def load_benchmark_config() -> dict[str, Any]:
    rc = _load_benchmark_root_config()
    defaults = _mapping_dict(rc.get("defaults"), field_name="defaults")
    passes = _mapping_dict(rc.get("passes"), field_name="passes")
    policy = _mapping_dict(rc.get("policy"), field_name="policy")

    effective = _deep_merge({**defaults, "passes": passes}, {"policy": policy})
    effective["passes"] = _mapping_dict(effective.get("passes"), field_name="passes")
    effective["policy"] = _mapping_dict(effective.get("policy"), field_name="policy")
    effective.update(config_path=_BENCHMARK_CONFIG_PATH, config_loaded=True)
    return effective


def _normalize_pass_list(raw: Any) -> list[str]:
    return (
        [str(p).strip() for p in raw if str(p).strip()] if isinstance(raw, list) else []
    )


def _policy_pass_list(raw: Any, *, field_name: str) -> list[str] | None:
    if raw is None:
        return None
    if not isinstance(raw, list):
        raise SystemExit(f"invalid benchmark config field: {field_name} must be a sequence")
    return [str(value).strip() for value in raw if str(value).strip()]


def _benchmark_policy_arch_keys() -> tuple[str, ...]:
    raw = os.environ.get("RUN_TARGET_ARCH", "").strip() or platform.machine().strip()
    normalized = raw.lower().replace("-", "_")
    if normalized in {"x86_64", "amd64", "x64", "x86"}:
        return ("x86_64", "x86")
    if normalized in {"arm64", "aarch64"}:
        return ("arm64", "aarch64")
    raise SystemExit(f"unsupported benchmark config architecture: {raw!r}")


def _platform_policy_passes(policy_config: Mapping[str, Any]) -> list[str] | None:
    platforms = _mapping_dict(policy_config.get("platforms"), field_name="policy.platforms")
    if not platforms:
        return None
    for arch_key in _benchmark_policy_arch_keys():
        if arch_key not in platforms:
            continue
        platform_policy = _mapping_dict(
            platforms.get(arch_key),
            field_name=f"policy.platforms.{arch_key}",
        )
        passes = _policy_pass_list(
            platform_policy.get("passes"),
            field_name=f"policy.platforms.{arch_key}.passes",
        )
        if passes is None:
            raise SystemExit(f"benchmark config must define policy.platforms.{arch_key}.passes")
        return passes
    arch_keys = ", ".join(_benchmark_policy_arch_keys())
    raise SystemExit(f"benchmark config does not define policy.platforms passes for {arch_keys}")


def _expand_groups(passes: Sequence[str], policy: Mapping[str, Any]) -> list[str]:
    """Single-level group expansion; duplicates preserved."""
    groups = _mapping_dict(policy.get("groups"), field_name="policy.groups")
    return [
        str(p).strip()
        for name in passes
        for p in (groups[name] if isinstance(groups.get(name), list) else [name])
        if str(p).strip()
    ]


def _require_non_empty_passes(raw_passes: Sequence[str], *, field_name: str) -> list[str]:
    passes = [str(p).strip() for p in raw_passes if str(p).strip()]
    if not passes:
        raise SystemExit(f"benchmark config field {field_name} must not be empty")
    return passes


def benchmark_config_enabled_passes(benchmark_config: Mapping[str, Any] | None) -> list[str]:
    policy_config = _mapping_dict((benchmark_config or {}).get("policy"), field_name="policy")
    platform_passes = _platform_policy_passes(policy_config)
    if platform_passes is not None:
        return _require_non_empty_passes(
            _expand_groups(platform_passes, policy_config),
            field_name="policy.platforms.<arch>.passes",
        )
    policy_default = _mapping_dict(policy_config.get("default"), field_name="policy.default")
    policy_default_passes = _policy_pass_list(
        policy_default.get("passes"),
        field_name="policy.default.passes",
    )
    if policy_default_passes is not None:
        return _require_non_empty_passes(policy_default_passes, field_name="policy.default.passes")

    passes_config = _mapping_dict((benchmark_config or {}).get("passes"), field_name="passes")
    if active_list := _normalize_pass_list(passes_config.get("active_list")):
        return active_list
    raise SystemExit(
        "benchmark config must define policy.platforms, policy.default.passes, or passes.active_list "
        "when no explicit pass override is supplied"
    )


@lru_cache(maxsize=1)
def _cached_benchmark_config_enabled_passes() -> tuple[str, ...]:
    return tuple(benchmark_config_enabled_passes(load_benchmark_config()))


def benchmark_rejit_enabled_passes() -> list[str]:
    raw = os.environ.get(_BENCH_PASSES_ENV)
    if raw is not None:
        text = raw.strip()
        if text.lower() == "default":
            return list(_cached_benchmark_config_enabled_passes())
        tokens = [token.strip() for token in text.split(",") if token.strip()]
        return _expand_groups(tokens, load_benchmark_config().get("policy") or {})
    return list(_cached_benchmark_config_enabled_passes())


def benchmark_run_provenance() -> dict[str, object]:
    return {
        "config": {"enabled_passes": benchmark_rejit_enabled_passes()},
    }

_SHIM_SOCK_DIR = Path("/var/run/bpfrejit")
_SHIM_PROGRAM_STABLE_SECONDS = 2.0
_LOADTIME_SHIM_PROGRAM_STABLE_SECONDS = 15.0


def _shim_socket_for_pid(app_pid: int) -> Path:
    return _SHIM_SOCK_DIR / f"shim-{int(app_pid)}.sock"


def _normalize_app_pids(
    *,
    app_pid: int | None = None,
    app_pids: Sequence[int] | None = None,
) -> list[int]:
    raw = list(app_pids or ([] if app_pid is None else [app_pid]))
    result: list[int] = []
    seen: set[int] = set()
    for value in raw:
        pid = int(value)
        if pid <= 0:
            continue
        if pid not in seen:
            seen.add(pid)
            result.append(pid)
    if not result:
        raise ValueError("app shim operation requires at least one app pid")
    return result


def _shim_request(socket_path: Path, payload: Mapping[str, object]) -> dict[str, Any]:
    request = json.dumps(dict(payload)) + "\n"
    with socket.socket(socket.AF_UNIX, socket.SOCK_STREAM) as client:
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
        except OSError as exc:
            raise RuntimeError(f"shim socket {socket_path} request failed: {exc}") from exc
    line = b"".join(chunks).decode(errors="replace").strip()
    if not line:
        raise RuntimeError(f"shim socket {socket_path} returned empty response")
    try:
        response = json.loads(line)
    except json.JSONDecodeError as exc:
        raise RuntimeError(f"shim socket {socket_path} returned invalid JSON: {exc}: {line[:400]}") from exc
    if not isinstance(response, Mapping):
        raise RuntimeError(f"shim socket {socket_path} returned non-object JSON: {line[:400]}")
    return dict(response)  # type: ignore[arg-type]


def _failure_artifact_name(raw_key: object) -> str:
    name = str(raw_key).strip()
    if not name:
        raise RuntimeError("empty failure artifact key")
    safe = "".join(c if c.isalnum() or c in "._-" else "_" for c in name)
    if safe in {".", ".."}:
        raise RuntimeError(f"invalid failure artifact key: {name!r}")
    return safe


def _persist_failure_artifacts(
    response: dict[str, Any],
    failure_artifacts_dir: Path | None,
) -> None:
    per_program = response.get("per_program")
    if not isinstance(per_program, Mapping):
        return
    for key, raw_result in per_program.items():
        if not isinstance(raw_result, dict):
            continue
        encoded = raw_result.pop("workdir_tar_b64", None)
        if encoded is None:
            continue
        if failure_artifacts_dir is None:
            continue
        if not isinstance(encoded, str):
            raise RuntimeError(f"invalid workdir_tar_b64 for artifact {key!r}")
        try:
            data = base64.b64decode(encoded, validate=True)
        except binascii.Error as exc:
            raise RuntimeError(f"invalid workdir_tar_b64 for artifact {key!r}: {exc}") from exc
        failure_artifacts_dir.mkdir(parents=True, exist_ok=True)
        (failure_artifacts_dir / f"{_failure_artifact_name(key)}.tar.gz").write_bytes(data)


def app_shim_has_programs(app_pid: int) -> bool:
    if int(app_pid) <= 0:
        return False
    try:
        resp = _shim_request(_shim_socket_for_pid(int(app_pid)), {"cmd": "has_programs"})
    except RuntimeError:
        return False
    return str(resp.get("status") or "error") == "ok"


def _list_app_shim_program_ids(app_pid: int) -> tuple[int, ...]:
    resp = _shim_request(_shim_socket_for_pid(int(app_pid)), {"cmd": "list_progs"})
    if not bool(resp.get("ok")):
        raise RuntimeError(str(resp.get("error") or "list_progs failed"))
    programs = resp.get("progs")
    if not isinstance(programs, Sequence) or isinstance(programs, (str, bytes, bytearray)):
        raise RuntimeError("list_progs returned invalid progs payload")
    ids: list[int] = []
    for item in programs:
        if not isinstance(item, Mapping):
            continue
        prog_id = int(item.get("id", 0) or 0)
        if prog_id > 0:
            ids.append(prog_id)
    return tuple(sorted(set(ids)))


def wait_for_app_shim_programs(
    *,
    app_pid: int,
    process: object | None = None,
    snapshot: object | None = None,
    process_name: str = "process",
    stable_seconds_override: float | None = None,
    min_programs: int = 1,
) -> None:
    if skip_rejit_disables_shim():
        return
    if stable_seconds_override is None:
        stable_seconds = (
            _LOADTIME_SHIM_PROGRAM_STABLE_SECONDS
            if os.environ.get("BPFREJIT_SHIM_LOADTIME_PLAN", "").strip()
            else _SHIM_PROGRAM_STABLE_SECONDS
        )
    else:
        stable_seconds = max(0.0, float(stable_seconds_override))
    stable_ids: tuple[int, ...] = ()
    stable_since: float | None = None
    while True:
        poll = getattr(process, "poll", None)
        if callable(poll) and poll() is not None:
            detail = ""
            if callable(snapshot):
                snap = snapshot()
                if isinstance(snap, Mapping):
                    lines = list(snap.get("stderr_tail") or []) + list(snap.get("stdout_tail") or [])
                    detail = "\n" + "\n".join(str(line) for line in lines[-40:]) if lines else ""
            raise RuntimeError(f"{process_name} exited before BPF programs were tracked by shim{detail}")
        try:
            ids = _list_app_shim_program_ids(int(app_pid))
        except RuntimeError:
            ids = ()
        if ids and len(ids) >= max(1, int(min_programs)) and stable_seconds <= 0.0:
            return
        if ids and len(ids) >= max(1, int(min_programs)) and ids == stable_ids:
            if stable_since is not None and time.monotonic() - stable_since >= stable_seconds:
                return
        elif ids and len(ids) >= max(1, int(min_programs)):
            stable_ids = ids
            stable_since = time.monotonic()
        else:
            stable_ids = ()
            stable_since = None
        time.sleep(0.2)


def apply_app_rejit(
    *,
    app_pid: int | None = None,
    app_pids: Sequence[int] | None = None,
    enabled_passes: Sequence[str] | None = None,
    app_name: str | None = None,
    failure_artifacts_dir: Path | None = None,
) -> dict[str, object]:
    pids = _normalize_app_pids(app_pid=app_pid, app_pids=app_pids)
    normalized_enabled_passes = (
        _normalize_pass_list(list(enabled_passes))
        if enabled_passes is not None
        else None
    )
    if not normalized_enabled_passes:
        raise ValueError("apply_app_rejit requires non-empty enabled_passes")
    payload = rejit_plan.build_execute_all_payload(
        [str(n).strip() for n in normalized_enabled_passes if str(n).strip()],
        app_name=app_name,
    )
    responses: list[dict[str, object]] = []
    for pid in pids:
        resp = _shim_request(_shim_socket_for_pid(pid), payload)
        if str(resp.get("status") or "error") != "ok":
            raise RuntimeError(str(resp.get("error_message") or resp.get("error") or "ReJIT failed"))
        _persist_failure_artifacts(resp, failure_artifacts_dir)
        responses.append({"pid": pid, "response": dict(resp)})
    return dict(responses[0]["response"]) if len(responses) == 1 else {"status": "ok", "shim_responses": responses}


def measure_app_phase(
    *,
    app_pid: int | None = None,
    app_pids: Sequence[int] | None = None,
    runner: object,
    workload_seconds: float,
    samples: int,
    warmups: int = 0,
) -> dict[str, object]:
    if skip_rejit_disables_shim():
        for _ in range(max(0, int(warmups))):
            runner.run_workload(workload_seconds)
        workloads = [
            runner.run_workload(workload_seconds).to_dict()
            for _ in range(samples)
        ]
        return {"workloads": workloads, "bpf": {}}

    pids = _normalize_app_pids(app_pid=app_pid, app_pids=app_pids)
    for _ in range(max(0, int(warmups))):
        runner.run_workload(workload_seconds)
    for pid in pids:
        start = _shim_request(_shim_socket_for_pid(pid), {"cmd": "measure_start"})
        if str(start.get("status") or "error") != "ok":
            raise RuntimeError(str(start.get("error") or "measure_start failed"))
    workloads: list[dict[str, object]] = []
    for _ in range(samples):
        workloads.append(runner.run_workload(workload_seconds).to_dict())
    bpf: dict[str, object] = {}
    for pid in pids:
        finish = _shim_request(_shim_socket_for_pid(pid), {"cmd": "measure_finish"})
        if str(finish.get("status") or "error") != "ok":
            raise RuntimeError(str(finish.get("error") or "measure_finish failed"))
        if isinstance(finish.get("bpf"), Mapping):
            bpf.update(dict(finish["bpf"]))  # type: ignore[index]
    return {
        "workloads": workloads,
        "bpf": bpf,
    }
