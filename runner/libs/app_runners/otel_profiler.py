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


_PY_SHA256 = """\
import hashlib, sys, time
buf = b"x" * 1024
n = 0
t0 = time.monotonic()
while True:
    hashlib.sha256(buf).digest()
    n += 1
    if (n & 4095) == 0:
        sys.stderr.write(f"python3 sha256 ops={n} elapsed_s={time.monotonic()-t0:.6f}\\n")
        sys.stderr.flush()
"""
_RB_SHA256 = """\
require "digest"
buf = "x" * 1024
n = 0
t0 = Process.clock_gettime(Process::CLOCK_MONOTONIC)
loop do
  Digest::SHA256.digest(buf)
  n += 1
  if (n & 4095) == 0
    elapsed = Process.clock_gettime(Process::CLOCK_MONOTONIC) - t0
    STDERR.puts "ruby sha256 ops=#{n} elapsed_s=#{format("%.6f", elapsed)}"
    STDERR.flush
  end
end
"""
_NODE_SHA256 = """\
const crypto = require("crypto");
const buf = Buffer.alloc(1024, 120);
let n = 0;
const t0 = process.hrtime.bigint();
while (true) {
  crypto.createHash("sha256").update(buf).digest();
  n++;
  if ((n & 4095) === 0) {
    const dt = Number(process.hrtime.bigint() - t0) / 1e9;
    process.stderr.write(`nodejs sha256 ops=${n} elapsed_s=${dt.toFixed(6)}\\n`);
  }
}
"""
_PERL_SHA256 = """\
use Digest::SHA qw(sha256);
use Time::HiRes qw(clock_gettime CLOCK_MONOTONIC);
my $buf = "x" x 1024;
my $n = 0;
my $t0 = clock_gettime(CLOCK_MONOTONIC);
while (1) {
  sha256($buf);
  $n++;
  if (($n & 4095) == 0) {
    my $dt = clock_gettime(CLOCK_MONOTONIC) - $t0;
    printf STDERR ("perl sha256 ops=%d elapsed_s=%.6f\\n", $n, $dt);
  }
}
"""
_PHP_SHA256 = """\
$buf = str_repeat("x", 1024);
$n = 0;
$t0 = hrtime(true);
while (true) {
  hash("sha256", $buf, true);
  $n++;
  if (($n & 4095) === 0) {
    $dt = (hrtime(true) - $t0) / 1e9;
    fwrite(STDERR, sprintf("php sha256 ops=%d elapsed_s=%.6f\\n", $n, $dt));
  }
}
"""

# Per-language stdlib SHA-256 hash loops. Each iteration hashes a 1 KiB
# buffer; even though the SHA-256 math itself is in a C extension the
# `while True:` driver runs in the interpreter (LOAD_*/CALL/STORE bytecode
# in CPython's _PyEval_EvalFrameDefault, equivalent dispatch in other
# runtimes), so a measurable fraction of perf-event samples lands in
# interpreter PC ranges. Verified locally: with samples_per_second=999 and
# a single Python idler the OTEL profiler emitted Python `<module>` frames
# in 1669 of 1570 sample records, confirming perf_unwind_python tail-calls
# fire even though the interpreter's hot path is non-trivial native code.
#
# Each idler reports ops + elapsed seconds to stderr every 4096 hashes;
# offline analysis derives ops/sec from those lines and the corpus
# baseline-vs-post_rejit per-language throughput delta is paper-quotable.
#
# IMPORTANT: BPF tail-called programs (perf_unwind_python, perf_unwind_php,
# ...) are entered through `bpf_func + X86_TAIL_CALL_OFFSET` which skips
# the prologue that increments `bpf_prog->stats.cnt`/`nsecs`. As a result,
# `bpftool prog show` and the corpus framework's per-program run_cnt_delta
# stay 0 for every tail-called program, even though the program executes
# every time `native_tracer_entry` dispatches into it. Coverage of these
# programs must be confirmed via the OTEL debug exporter sample dump
# (interpreter frame names) or via offline analysis of the per-language
# `ops/s` reported by the idlers, not via run_cnt.
_LANGUAGE_INTERPRETER_LOOPS: tuple[tuple[str, tuple[str, ...]], ...] = (
    ("python3", ("-u", "-c", _PY_SHA256)),
    ("ruby",    ("-e", _RB_SHA256)),
    ("nodejs",  ("-e", _NODE_SHA256)),
    ("perl",    ("-e", _PERL_SHA256)),
    ("php",     ("-r", _PHP_SHA256)),
)


_MINIMAL_CONFIG = """receivers:
  profiling:
    samples_per_second: 99
    # `tracers: all` enables every interpreter tracer (python, php, ruby, v8,
    # perl, hotspot, dotnet, beam, labels). Without this, perf_unwind_<lang>
    # programs are loaded but never routed to: native_tracer_entry queries
    # the per-language procs maps (py_procs/php_procs/...) which stay empty
    # because IsMapEnabled() returns false when the corresponding tracer is
    # not enabled. See tracer/types/parse.go.
    tracers: all
    # Reduce process-info synchronization period from the 5s default so the
    # interpreter offsets map is populated within the corpus measurement
    # window (5s baseline / 5s post_rejit). Without this, idle interpreter
    # processes spawned in start() are not yet attached when sampling
    # begins, so native_tracer_entry sees them as native-only frames.
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
        # tuples of (tool, Popen, stderr_file_handle, stderr_log_path).
        self._language_idlers: list[tuple[str, "subprocess.Popen[bytes]", "object", Path]] = []

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
        spawned: list[dict[str, object]] = []
        runtime_dir = self._ensure_runtime_dir()
        idlers_dir = runtime_dir / "idlers"
        idlers_dir.mkdir(exist_ok=True)
        for tool, args in _LANGUAGE_INTERPRETER_LOOPS:
            binary = which(tool)
            if binary is None:
                continue
            stderr_path = idlers_dir / f"{tool}.stderr.log"
            stderr_fh = open(stderr_path, "wb")
            proc = subprocess.Popen(
                [binary, *args],
                stdout=subprocess.DEVNULL,
                stderr=stderr_fh,
                stdin=subprocess.DEVNULL,
            )
            self._language_idlers.append((tool, proc, stderr_fh, stderr_path))
            spawned.append({"tool": tool, "pid": proc.pid, "stderr_log": str(stderr_path)})
        self.artifacts["language_idlers"] = spawned

    def _kill_language_idlers(self) -> None:
        # Drain stderr logs into artifacts before tearing down so the raw ops
        # counters land in result.json. Each line: "<tool> sha256 ops=N elapsed_s=T".
        snapshots: list[dict[str, object]] = []
        for tool, proc, stderr_fh, stderr_path in self._language_idlers:
            if proc.poll() is None:
                proc.terminate()
        for tool, proc, stderr_fh, stderr_path in self._language_idlers:
            try:
                proc.wait(timeout=20)
            except subprocess.TimeoutExpired:
                proc.kill()
                try:
                    proc.wait(timeout=20)
                except subprocess.TimeoutExpired:
                    pass
            try:
                stderr_fh.close()
            except OSError:
                pass
            try:
                raw = stderr_path.read_text(encoding="utf-8", errors="replace")
            except OSError:
                raw = ""
            tail = "\n".join(raw.splitlines()[-200:])
            snapshots.append({"tool": tool, "stderr_tail": tail, "returncode": proc.returncode})
        self.artifacts["language_idler_logs"] = snapshots
        # Surface idler log snapshots into the corpus per-app result.json by
        # piggy-backing on the result_details pathway that corpus/driver.py
        # already reads (driver.py:163).
        existing = self.artifacts.get("result_details") or {}
        if not isinstance(existing, dict):
            existing = {}
        existing["language_idler_logs"] = snapshots
        self.artifacts["result_details"] = existing
        self._language_idlers.clear()

    def _cleanup_runtime_dir(self) -> None:
        runtime_dir = self._runtime_dir
        self._config_path = None
        self._runtime_dir = None
        if runtime_dir is None:
            return
        shutil.rmtree(runtime_dir, ignore_errors=True)
