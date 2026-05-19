from __future__ import annotations

import json
import os
import platform
import socket
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


def _discover_shim_sockets() -> list[Path]:
    """Return every shim socket the runner can see. Multi-process apps (e.g.
    bpftrace/set spawns 5 children, each one's libbpf calls PROG_LOAD inside
    its own intercept layer) keep each sub-shim's state isolated by pid."""
    if not _SHIM_SOCK_DIR.is_dir():
        return []
    return sorted(_SHIM_SOCK_DIR.glob("shim-*.sock"))


def _build_prog_id_to_socket_map(
    sockets: Sequence[Path],
) -> dict[int, Path]:
    """Ask each shim for its tracked progs and build a prog_id → socket map.
    Later sockets win on duplicate prog_ids (kernel ids are globally unique
    so this should not actually happen, but defensive deduping costs nothing)."""
    mapping: dict[int, Path] = {}
    for sock in sockets:
        try:
            resp = _shim_request(sock, {"cmd": "list_progs"})
        except RuntimeError:
            continue
        if not resp.get("ok"):
            continue
        for entry in resp.get("progs", []) or []:
            try:
                pid = int(entry.get("id", 0) or 0)
            except (TypeError, ValueError):
                continue
            if pid > 0:
                mapping[pid] = sock
    return mapping


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


def _read_bpfopt_report(report_path: object) -> dict[str, Any]:
    if not isinstance(report_path, str) or not report_path:
        return {}
    try:
        with open(report_path, encoding="utf-8") as fh:
            data = json.load(fh)
    except (OSError, ValueError):
        return {}
    return dict(data) if isinstance(data, Mapping) else {}


def apply_daemon_rejit(
    prog_ids: list[int] | None = None,
    *,
    enabled_passes: Sequence[str] | None = None,
    app_pid: int,
    failure_artifacts_dir: Path | None = None,
    app_name: str | None = None,
    prog_names_by_id: Mapping[int, str] | None = None,
) -> dict[str, object]:
    """Drive optimization via per-pid shim socket (replaces the daemon path).

    For each prog and each pass step in `enabled_passes`, send `execute_step`
    to the shim hosting that prog. Build a `per_program` response in the
    shape the daemon used to return so existing consumers stay unchanged.
    """
    del failure_artifacts_dir  # accepted for API stability; shim path has no workdir tar payload
    prog_ids = [int(v) for v in (prog_ids or []) if int(v) > 0]
    if not prog_ids:
        raise ValueError("apply_daemon_rejit requires at least one prog_id")
    if len(set(prog_ids)) != len(prog_ids):
        raise ValueError("apply_daemon_rejit requires unique prog_ids")
    if int(app_pid) <= 0:
        raise ValueError("apply_daemon_rejit requires app_pid > 0")
    normalized_enabled_passes = (
        _normalize_pass_list(list(enabled_passes))
        if enabled_passes is not None
        else None
    )
    if not normalized_enabled_passes:
        raise ValueError("apply_daemon_rejit requires non-empty enabled_passes")
    payload = rejit_plan.build_execute_plan_payload(
        prog_ids,
        [str(n).strip() for n in normalized_enabled_passes if str(n).strip()],
        app_name=app_name,
        prog_names_by_id=prog_names_by_id,
    )
    # Locate the shim that owns each prog_id. For single-process apps the
    # app_pid-derived socket already has every prog; for multi-process apps
    # (bpftrace/set, bcc/set) each child shim only sees the progs its own
    # libbpf instance loaded, and prog_ids span all of them — we must scan.
    prog_id_to_socket = _build_prog_id_to_socket_map(_discover_shim_sockets())
    fallback_sock = _shim_socket_for_pid(int(app_pid))
    per_program: dict[str, Any] = {}
    for program in payload["programs"]:
        pid = int(program["prog_id"])
        sock = prog_id_to_socket.get(pid, fallback_sock)
        passes_detail: list[dict[str, Any]] = []
        all_ok = True
        for step in program["steps"]:
            req = {"cmd": "execute_step", "prog_id": pid, "command": step["command"]}
            try:
                resp = _shim_request(sock, req)
            except RuntimeError as exc:
                passes_detail.append({
                    "step": dict(step),
                    "status": "error",
                    "error": str(exc),
                    "bpfopt_summary": {},
                })
                all_ok = False
                break
            step_ok = bool(resp.get("ok"))
            report_data = _read_bpfopt_report(resp.get("report"))
            passes_detail.append({
                "step": dict(step),
                "status": "ok" if step_ok else "error",
                "error": None if step_ok else f"exit_code={resp.get('exit_code', -1)} error={resp.get('error', '')}",
                "bpfopt_summary": report_data,
            })
            if not step_ok:
                # Don't break: daemon's per-step loop keeps going so later
                # passes still get a chance against the last successful
                # bytecode/state. The shim mirrors this — its `cur` and
                # `verifier_states_in` only advance on success.
                all_ok = False
                continue
        per_program[str(pid)] = {
            "status": "ok" if all_ok else "error",
            "prog_id": pid,
            "program": {
                "prog_id": pid,
                "prog_name": (prog_names_by_id or {}).get(pid, "") if prog_names_by_id else "",
                "prog_type": 0,
                "orig_insn_count": 0,
                "final_insn_count": 0,
            },
            "passes": passes_detail,
            "error_message": None,
        }
    return {"status": "ok", "per_program": per_program}


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

    def apply_rejit(
        self,
        prog_ids: Sequence[int],
        *,
        app_pid: int,
        enabled_passes: Sequence[str] | None = None,
        failure_artifacts_dir: Path | None = None,
        app_name: str | None = None,
        prog_names_by_id: Mapping[int, str] | None = None,
    ) -> dict[str, object]:
        return apply_daemon_rejit(
            [int(p) for p in prog_ids if int(p) > 0],
            enabled_passes=enabled_passes,
            app_pid=int(app_pid),
            failure_artifacts_dir=failure_artifacts_dir,
            app_name=app_name,
            prog_names_by_id=prog_names_by_id,
        )
