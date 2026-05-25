from __future__ import annotations

import os
import shutil
import tempfile
from pathlib import Path
from typing import Mapping

from .. import ROOT_DIR
from .native_loader_env import native_loader_manifest_env
from .process_support import NativeProcessRunner
from .setup_support import optional_repo_artifact_path


# Multi-language interpreter sampling load is now a workload, not runner-
# internal state: see `runner/libs/workload.py:run_otel_mixed_workload`,
# which spawns Python/Ruby/Node/Perl/PHP integer loops plus stress-ng cpu
# concurrently for the measurement window. The catalog wires that workload
# (`workload="otel_mixed_workload"`) so `.baseline.workloads[]` /
# `.post_rejit.workloads[]` carry per-language raw stderr ("<lang> int_loop
# ops=N elapsed_s=T") in components; interpretation stays outside the framework.
#
# IMPORTANT: BPF tail-called programs (perf_unwind_python, perf_unwind_php,
# ...) are entered through `bpf_func + X86_TAIL_CALL_OFFSET` which skips
# the prologue that increments `bpf_prog->stats.cnt`/`nsecs`. As a result,
# `bpftool prog show` and the corpus framework's per-program run_cnt_delta
# stay 0 for every tail-called program, even though the program executes
# every time `native_tracer_entry` dispatches into it. Coverage of these
# programs must be confirmed via the OTEL debug exporter sample dump
# (interpreter frame names) or via external inspection of the per-language
# ops/s in the workload result, not via run_cnt. See CLAUDE.md "Tail-call
# accounting caveat" for the full list of affected programs.


_MINIMAL_CONFIG = """receivers:
  profiling:
    samples_per_second: 100000
    # `tracers: all` enables every interpreter tracer (python, php, ruby, v8,
    # perl, hotspot, dotnet, beam, labels). Without this, perf_unwind_<lang>
    # programs are loaded but never routed to: native_tracer_entry queries
    # the per-language procs maps (py_procs/php_procs/...) which stay empty
    # because IsMapEnabled() returns false when the corresponding tracer is
    # not enabled. See tracer/types/parse.go.
    tracers: all
    # Reduce process-info synchronization period from the 5s default so the
    # interpreter offsets map is populated within the corpus measurement
    # window (5s baseline / 5s post_rejit). Without this, the interpreter
    # processes spawned by `otel_mixed_workload` may not yet be attached
    # when sampling begins, so native_tracer_entry sees them as native-only
    # frames.
    monitor_interval: 1s

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

    def _command_env(self) -> Mapping[str, str] | None:
        env = native_loader_manifest_env("otelcol-ebpf-profiler")
        return env or None

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
