from __future__ import annotations

import os
import shutil
import tempfile
from pathlib import Path
from typing import Mapping

from .. import ROOT_DIR
from ..workload import WorkloadResult, run_otel_profiler_cpu_mix_workload
from .process_support import NativeProcessRunner
from .setup_support import optional_repo_artifact_path


_MINIMAL_CONFIG = """receivers:
  profiling:

exporters:
  debug:

service:
  telemetry:
    logs:
      level: info
  pipelines:
    profiles:
      receivers: [profiling]
      exporters: [debug]
"""


def _runtime_tmp_root() -> Path:
    for env_name in ("TMPDIR", "TMP", "TEMP"):
        raw = os.environ.get(env_name, "").strip()
        if not raw:
            continue
        candidate = Path(raw).expanduser()
        try:
            candidate.mkdir(parents=True, exist_ok=True)
        except OSError:
            continue
        if os.access(candidate, os.W_OK | os.X_OK):
            return candidate
    for candidate in (Path("/var/tmp"), Path("/tmp")):
        try:
            candidate.mkdir(parents=True, exist_ok=True)
        except OSError:
            continue
        if os.access(candidate, os.W_OK | os.X_OK):
            return candidate
    raise RuntimeError("no writable temporary directory is available for the otel profiler runner")


class OtelProfilerRunner(NativeProcessRunner):
    def __init__(
        self,
        *,
        feature_gates: str | None = "+service.profilesSupport",
        **kwargs: object,
    ) -> None:
        super().__init__(**kwargs)
        self.feature_gates = str(feature_gates or "").strip()
        self._runtime_dir: Path | None = None
        self._config_path: Path | None = None

    def _default_binary_candidates(self) -> tuple[Path, ...]:
        return tuple(
            candidate
            for candidate in (
                optional_repo_artifact_path("otelcol-ebpf-profiler", "bin", "otelcol-ebpf-profiler"),
                optional_repo_artifact_path("opentelemetry-ebpf-profiler", "bin", "otelcol-ebpf-profiler"),
                ROOT_DIR / "corpus" / "build" / "opentelemetry-ebpf-profiler" / "bin" / "otelcol-ebpf-profiler",
                ROOT_DIR / "runner" / "repos" / "opentelemetry-ebpf-profiler" / "bin" / "otelcol-ebpf-profiler",
                ROOT_DIR / "runner" / "repos" / "opentelemetry-ebpf-profiler" / "otelcol-ebpf-profiler",
                Path("/usr/local/bin/otelcol-ebpf-profiler"),
            )
            if candidate is not None
        )

    def _ensure_runtime_dir(self) -> Path:
        if self._runtime_dir is not None:
            return self._runtime_dir
        runtime_dir = Path(tempfile.mkdtemp(prefix="otelcol-ebpf-profiler-", dir=str(_runtime_tmp_root()))).resolve()
        config_path = runtime_dir / "config.yaml"
        config_path.write_text(_MINIMAL_CONFIG, encoding="utf-8")
        self._runtime_dir = runtime_dir
        self._config_path = config_path
        return runtime_dir

    def _command(self, binary: Path) -> list[str]:
        self._ensure_runtime_dir()
        assert self._config_path is not None
        command = [str(binary)]
        if self.feature_gates:
            command.append(f"--feature-gates={self.feature_gates}")
        command.extend(["--config", str(self._config_path), *self.loader_args])
        return command

    def _command_cwd(self) -> Path | None:
        return self._runtime_dir or ROOT_DIR

    def _run_workload(self, seconds: float) -> WorkloadResult:
        requested_kind = self.workload_kind or "exec_storm"
        if requested_kind == "exec_storm":
            return run_otel_profiler_cpu_mix_workload(seconds)
        return super()._run_workload(seconds)

    def run_workload_spec(
        self,
        workload_spec: Mapping[str, object],
        seconds: float,
    ) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError(f"{type(self).__name__} is not running")
        requested_kind = str(workload_spec.get("kind") or workload_spec.get("name") or self.workload_kind or "").strip()
        if requested_kind == "exec_storm":
            return run_otel_profiler_cpu_mix_workload(seconds)
        return super().run_workload_spec(workload_spec, seconds)

    def start(self) -> list[int]:
        try:
            programs = super().start()
        except Exception:
            self._cleanup_runtime_dir()
            raise
        if self._config_path is not None:
            self.artifacts["config_path"] = str(self._config_path)
        return programs

    def stop(self) -> None:
        try:
            super().stop()
        finally:
            self._cleanup_runtime_dir()

    def _cleanup_runtime_dir(self) -> None:
        runtime_dir = self._runtime_dir
        self._config_path = None
        self._runtime_dir = None
        if runtime_dir is None:
            return
        shutil.rmtree(runtime_dir, ignore_errors=True)
