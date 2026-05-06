from __future__ import annotations

import os
import shutil
import subprocess
import tempfile
from pathlib import Path
from typing import Sequence

from .. import ROOT_DIR, which
from .process_support import NativeProcessRunner
from .setup_support import optional_repo_artifact_path


_LANGUAGE_RUNTIME_PROBES: tuple[tuple[str, tuple[str, ...]], ...] = (
    ("python3", ("-c", "x=0\nwhile True:\n    x+=1")),
    ("ruby", ("-e", "x=0; loop { x+=1 }")),
    ("nodejs", ("-e", "let x=0; while(true){x++;}")),
    ("perl", ("-e", "my $x=0; while(1){$x++;}")),
    ("php", ("-r", "$x=0; while(true){$x++;}")),
)


_MINIMAL_CONFIG = """receivers:
  profiling:
    samples_per_second: 99

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
        self._language_idlers: list[subprocess.Popen[bytes]] = []

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

    def start(self) -> list[int]:
        try:
            programs = super().start()
        except Exception:
            self._cleanup_runtime_dir()
            raise
        if self._config_path is not None:
            self.artifacts["config_path"] = str(self._config_path)
        # Pre-spawn long-running language interpreters so otel's periodic /proc
        # scan identifies each runtime well before workload measurement starts.
        # Each interpreter runs an idle CPU loop and is sampled by perf_event,
        # which routes the sample to the matching perf_unwind_<lang> program.
        self._spawn_language_idlers()
        return programs

    def stop(self) -> None:
        try:
            self._kill_language_idlers()
            super().stop()
        finally:
            self._cleanup_runtime_dir()

    def _spawn_language_idlers(self) -> None:
        spawned: list[str] = []
        for tool, args in _LANGUAGE_RUNTIME_PROBES:
            binary = which(tool)
            if binary is None:
                continue
            proc = subprocess.Popen(
                [binary, *args],
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
                stdin=subprocess.DEVNULL,
            )
            self._language_idlers.append(proc)
            spawned.append(tool)
        self.artifacts["language_idlers"] = spawned

    def _kill_language_idlers(self) -> None:
        for proc in self._language_idlers:
            if proc.poll() is None:
                proc.terminate()
        for proc in self._language_idlers:
            try:
                proc.wait(timeout=20)
            except subprocess.TimeoutExpired:
                proc.kill()
                try:
                    proc.wait(timeout=20)
                except subprocess.TimeoutExpired:
                    pass
        self._language_idlers.clear()

    def _cleanup_runtime_dir(self) -> None:
        runtime_dir = self._runtime_dir
        self._config_path = None
        self._runtime_dir = None
        if runtime_dir is None:
            return
        shutil.rmtree(runtime_dir, ignore_errors=True)
