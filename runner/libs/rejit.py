from __future__ import annotations

import base64
import json
import os
import platform
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


_BENCH_PASSES_ENV = "BPFREJIT_BENCH_PASSES"
_BENCHMARK_CONFIG_PATH = ROOT_DIR / "corpus" / "config" / "benchmark_config.yaml"
_DEFAULT_BENCHMARK_REPEAT = 200


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


def _require_non_empty_passes(raw_passes: Sequence[str], *, field_name: str) -> list[str]:
    passes = _ordered_unique_passes(raw_passes)
    if not passes:
        raise SystemExit(f"benchmark config field {field_name} must not be empty")
    return passes


def benchmark_config_enabled_passes(benchmark_config: Mapping[str, Any] | None) -> list[str]:
    policy_config = _mapping_dict((benchmark_config or {}).get("policy"), field_name="policy")
    platform_passes = _platform_policy_passes(policy_config)
    if platform_passes is not None:
        return _require_non_empty_passes(
            platform_passes,
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
        return [token.strip() for token in text.split(",") if token.strip()]
    return list(_cached_benchmark_config_enabled_passes())


def benchmark_run_provenance() -> dict[str, object]:
    return {
        "config": {"enabled_passes": benchmark_rejit_enabled_passes()},
    }

def _apply_result_from_response(
    response: dict[str, Any],
) -> dict[str, object]:
    result: dict[str, object] = dict(response)
    result["error"] = str(response.get("error_message") or "").strip()
    return result


def _write_failure_workdir_tar(
    prog_id: int,
    workdir_tar_b64: object,
    failure_artifacts_dir: Path | None,
) -> None:
    if workdir_tar_b64 is None:
        return
    if not isinstance(workdir_tar_b64, str):
        raise RuntimeError(f"daemon response field workdir_tar_b64 for prog {prog_id} must be a string")
    if failure_artifacts_dir is None:
        raise RuntimeError(f"daemon returned workdir_tar_b64 for prog {prog_id} without failure_artifacts_dir")
    failure_artifacts_dir.mkdir(parents=True, exist_ok=True)
    tar_path = failure_artifacts_dir / f"{prog_id}.tar.gz"
    tar_path.write_bytes(base64.b64decode(workdir_tar_b64, validate=True))


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


_DAEMON_SOCKET_PATH = Path("/var/tmp/bpfrejit-daemon.sock")


def _start_daemon_server(
    daemon_binary: Path | str,
    *,
    stdout_path: Path,
    stderr_path: Path,
) -> tuple[subprocess.Popen[str], Path, str]:
    socket_dir = tempfile.mkdtemp(prefix="bd-", dir=str(_daemon_runtime_root()))
    socket_path = _DAEMON_SOCKET_PATH
    stdout_path.parent.mkdir(parents=True, exist_ok=True)
    stderr_path.parent.mkdir(parents=True, exist_ok=True)
    cmd = [str(daemon_binary)]
    with stdout_path.open("w", encoding="utf-8") as out, stderr_path.open("w", encoding="utf-8") as err:
        proc = subprocess.Popen(cmd, stdout=out, stderr=err, text=True)
    deadline = time.monotonic() + 5.0
    while time.monotonic() < deadline:
        if socket_path.exists():
            return proc, socket_path, socket_dir
        if proc.poll() is not None:
            raise RuntimeError(f"daemon exited early (rc={proc.returncode}): {_daemon_log_tail(stdout_path, stderr_path)}")
        time.sleep(0.05)
    _kill_proc(proc, timeout=1)
    raise RuntimeError(f"timed out waiting for daemon socket: {_daemon_log_tail(stdout_path, stderr_path)}")


def _kill_proc(proc: subprocess.Popen[str], *, timeout: int) -> None:
    proc.terminate()
    try: proc.wait(timeout=timeout)
    except subprocess.TimeoutExpired: proc.kill(); proc.wait(timeout=timeout)


def _stop_daemon_server(proc: subprocess.Popen[str], socket_dir: str) -> None:
    _kill_proc(proc, timeout=5)
    _DAEMON_SOCKET_PATH.unlink(missing_ok=True)
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
    daemon_proc: subprocess.Popen[str] | None = None,
    stdout_path: Path | None = None, stderr_path: Path | None = None,
) -> dict[str, Any]:
    request = json.dumps(dict(payload)) + "\n"
    kw = {"daemon_proc": daemon_proc, "stdout_path": stdout_path, "stderr_path": stderr_path}
    with socket.socket(socket.AF_UNIX, socket.SOCK_STREAM) as client:
        try:
            client.connect(str(socket_path))
            client.sendall(request.encode())
            chunks: list[bytes] = []
            while True:
                chunk = client.recv(4096)
                if not chunk: break
                chunks.append(chunk)
                if b"\n" in chunk: break
        except OSError as exc:
            raise RuntimeError(_daemon_error_detail(f"daemon socket request failed: {exc}", **kw)) from exc
    line = b"".join(chunks).decode(errors="replace").strip()
    suffix = (f"\ndaemon log tail:\n{lt}" if (lt := _daemon_log_tail(stdout_path, stderr_path)) else "")
    if not line:
        raise RuntimeError(_daemon_error_detail("daemon socket returned an empty response", **kw))
    try:
        response = json.loads(line)
    except json.JSONDecodeError as exc:
        raise RuntimeError(f"daemon socket returned invalid JSON: {exc}: {line[:400]}{suffix}") from exc
    if not isinstance(response, Mapping):
        raise RuntimeError(f"daemon socket returned non-object JSON: {line[:400]}{suffix}")
    return dict(response)  # type: ignore[arg-type]


def apply_daemon_rejit(
    prog_ids: list[int] | None = None,
    *,
    enabled_passes: Sequence[str] | None = None,
    daemon_socket_path: Path | None = None,
    daemon_proc: subprocess.Popen[str] | None = None,
    daemon_stdout_path: Path | None = None,
    daemon_stderr_path: Path | None = None,
    failure_artifacts_dir: Path | None = None,
) -> dict[str, object]:
    prog_ids = [int(v) for v in (prog_ids or []) if int(v) > 0]
    if not prog_ids:
        raise ValueError("apply_daemon_rejit requires at least one prog_id")
    if len(set(prog_ids)) != len(prog_ids):
        raise ValueError("apply_daemon_rejit requires unique prog_ids")
    if daemon_socket_path is None:
        raise ValueError("apply_daemon_rejit requires daemon_socket_path")
    normalized_enabled_passes = (
        _normalize_pass_list(list(enabled_passes))
        if enabled_passes is not None
        else None
    )
    per_program: dict[int, dict[str, object]] = {}
    errors: list[str] = []

    payload: dict[str, object] = {"cmd": "optimize", "prog_ids": prog_ids}
    if normalized_enabled_passes is not None:
        payload["enabled_passes"] = [str(n).strip() for n in normalized_enabled_passes if str(n).strip()]
    _resp = _daemon_request(daemon_socket_path, payload,
                            daemon_proc=daemon_proc, stdout_path=daemon_stdout_path,
                            stderr_path=daemon_stderr_path)
    if str(_resp.get("status") or "") != "ok":
        msg = str(_resp.get("error_message") or "optimize failed")
        return {
            "status": "error",
            "error": msg,
            "per_program": {int(pid): {"status": "error", "prog_id": int(pid),
                                       "error": msg}
                            for pid in prog_ids},
        }

    raw_per_program = _resp.get("per_program")
    if not isinstance(raw_per_program, Mapping):
        raise RuntimeError("daemon response field 'per_program' must be an object")
    records_by_prog_id = {str(key): value for key, value in raw_per_program.items()}
    requested_prog_ids = {str(prog_id) for prog_id in prog_ids}
    response_prog_ids = set(records_by_prog_id)
    if response_prog_ids != requested_prog_ids:
        missing = sorted(requested_prog_ids - response_prog_ids)
        unexpected = sorted(response_prog_ids - requested_prog_ids)
        raise RuntimeError(
            "daemon response field 'per_program' does not match requested prog_ids: "
            f"missing={missing}, unexpected={unexpected}"
        )

    for prog_id in prog_ids:
        record = records_by_prog_id[str(prog_id)]
        if not isinstance(record, Mapping):
            raise RuntimeError(f"daemon response field per_program[{prog_id!r}] must be an object")
        record_dict = dict(record)
        _write_failure_workdir_tar(
            prog_id,
            record_dict.pop("workdir_tar_b64", None),
            failure_artifacts_dir,
        )
        result = _apply_result_from_response(record_dict)
        per_program[prog_id] = result
        if error := str(result.get("error") or "").strip():
            errors.append(f"prog {prog_id}: {error}")
    error = "; ".join(errors)
    return {
        "status": "ok" if not error else "error",
        "per_program": per_program,
        "error": error,
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
    def start(
        cls,
        daemon_binary: Path | str,
        *,
        load_kinsn: bool = False,
        stdout_path: Path,
        stderr_path: Path,
    ) -> "DaemonSession":
        from .kinsn import prepare_kinsn_modules  # noqa: PLC0415
        binary = Path(daemon_binary).resolve()
        kinsn_metadata: dict[str, object] = dict(prepare_kinsn_modules()) if load_kinsn else {}
        proc, socket_path, socket_dir = _start_daemon_server(binary, stdout_path=stdout_path, stderr_path=stderr_path)
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
        _stop_daemon_server(self.proc, self.socket_dir)

    def apply_rejit(
        self,
        prog_ids: Sequence[int],
        *,
        enabled_passes: Sequence[str] | None = None,
        failure_artifacts_dir: Path | None = None,
    ) -> dict[str, object]:
        return apply_daemon_rejit([int(p) for p in prog_ids if int(p) > 0], enabled_passes=enabled_passes,
                                   daemon_socket_path=self.socket_path, daemon_proc=self.proc,
                                   daemon_stdout_path=self.stdout_path, daemon_stderr_path=self.stderr_path,
                                   failure_artifacts_dir=failure_artifacts_dir)
