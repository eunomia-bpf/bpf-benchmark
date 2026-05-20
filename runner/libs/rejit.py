from __future__ import annotations

import json
import os
import platform
import socket
import time
from dataclasses import dataclass, field
from functools import lru_cache
from pathlib import Path
from typing import Any, Mapping, Sequence

from . import rejit_plan

import yaml

from . import ROOT_DIR


_BENCH_PASSES_ENV = "BPFREJIT_BENCH_PASSES"
_BENCHMARK_CONFIG_PATH = ROOT_DIR / "corpus" / "config" / "benchmark_config.yaml"
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


def app_shim_has_programs(app_pid: int) -> bool:
    if int(app_pid) <= 0:
        return False
    try:
        resp = _shim_request(_shim_socket_for_pid(int(app_pid)), {"cmd": "has_programs"})
    except RuntimeError:
        return False
    return str(resp.get("status") or "error") == "ok"


def wait_for_app_shim_programs(
    *,
    app_pid: int,
    timeout_s: int | float,
    process: object | None = None,
    snapshot: object | None = None,
    process_name: str = "process",
) -> None:
    deadline = time.monotonic() + max(0.0, float(timeout_s))
    while time.monotonic() < deadline:
        poll = getattr(process, "poll", None)
        if callable(poll) and poll() is not None:
            detail = ""
            if callable(snapshot):
                snap = snapshot()
                if isinstance(snap, Mapping):
                    lines = list(snap.get("stderr_tail") or []) + list(snap.get("stdout_tail") or [])
                    detail = "\n" + "\n".join(str(line) for line in lines[-40:]) if lines else ""
            raise RuntimeError(f"{process_name} exited before BPF programs were tracked by shim{detail}")
        if app_shim_has_programs(int(app_pid)):
            return
        time.sleep(0.2)
    raise RuntimeError(
        f"{process_name} did not load any shim-tracked BPF programs within {float(timeout_s):.1f}s"
    )


def apply_app_rejit(
    *,
    app_pid: int | None = None,
    app_pids: Sequence[int] | None = None,
    enabled_passes: Sequence[str] | None = None,
    app_name: str | None = None,
    failure_artifacts_dir: Path | None = None,
) -> dict[str, object]:
    del failure_artifacts_dir
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


@dataclass
class DaemonSession:
    """Compat shim — keeps callers stable across the daemon → LD_PRELOAD shim
    migration. There is no daemon process now; the per-app shim lifecycle is
    managed by app startup (LD_PRELOAD). `start()` / `close()` are no-ops.
    Name kept to avoid churn in callers."""
    daemon_binary: Path
    stdout_path: Path
    stderr_path: Path
    kinsn_metadata: dict[str, object] = field(default_factory=dict)

    # Compat: callers probe `daemon_session.proc.poll()` to detect a crashed
    # daemon. There is no daemon process now; expose a stub whose poll()
    # always returns None ("still alive"). A real shim crash surfaces as a
    # socket-connection error during apply_rejit, not here.
    class _AlwaysAliveProc:
        def poll(self) -> None:
            return None
    proc: object = field(default_factory=_AlwaysAliveProc)

    @classmethod
    def start(
        cls,
        daemon_binary: Path | str,
        *,
        stdout_path: Path,
        stderr_path: Path,
    ) -> "DaemonSession":
        stdout_path.parent.mkdir(parents=True, exist_ok=True)
        stderr_path.parent.mkdir(parents=True, exist_ok=True)
        return cls(
            daemon_binary=Path(daemon_binary).resolve(),
            stdout_path=stdout_path,
            stderr_path=stderr_path,
            kinsn_metadata={},
        )

    def __enter__(self) -> "DaemonSession":
        return self

    def __exit__(self, exc_type: object, exc: object, tb: object) -> None:
        del exc_type, exc, tb
        self.close()

    def close(self) -> None:
        # Library-mode shim: no daemon process to terminate. Kept as a
        # method so context-manager users (`with DaemonSession(...) as s`)
        # still work; callers may rely on the symbol existing even though
        # there's nothing to release.
        return

    def apply_rejit_for_app(
        self,
        *,
        app_pid: int | None = None,
        app_pids: Sequence[int] | None = None,
        enabled_passes: Sequence[str] | None = None,
        failure_artifacts_dir: Path | None = None,
        app_name: str | None = None,
    ) -> dict[str, object]:
        return apply_app_rejit(
            app_pid=app_pid,
            app_pids=app_pids,
            enabled_passes=enabled_passes,
            failure_artifacts_dir=failure_artifacts_dir,
            app_name=app_name,
        )

    def measure_phase(
        self,
        *,
        app_pid: int | None = None,
        app_pids: Sequence[int] | None = None,
        runner: object,
        workload_seconds: float,
        samples: int,
        warmups: int = 0,
    ) -> dict[str, object]:
        return measure_app_phase(
            app_pid=app_pid,
            app_pids=app_pids,
            runner=runner,
            workload_seconds=workload_seconds,
            samples=samples,
            warmups=warmups,
        )
