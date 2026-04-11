from __future__ import annotations

import os
import shlex
import threading
import time
from pathlib import Path
from typing import Any, Mapping, Sequence

from .. import ROOT_DIR, resolve_bpftool_binary, run_command, run_json_command, tail_text, which
from ..agent import find_bpf_programs, start_agent, stop_agent, wait_healthy
from ..workload import WorkloadResult, run_connect_storm, run_exec_storm, run_file_io, run_open_storm
from .process_support import ProcessOutputCollector
from .setup_support import missing_required_commands, pick_host_executable, repo_artifact_root


def current_programs() -> list[dict[str, object]]:
    payload = run_json_command([resolve_bpftool_binary(), "-j", "-p", "prog", "show"], timeout=30)
    if not isinstance(payload, list):
        raise RuntimeError("bpftool prog show returned a non-list payload")
    return [dict(record) for record in payload if isinstance(record, dict) and "id" in record]


def current_prog_ids() -> list[int]:
    return [int(record["id"]) for record in current_programs()]


class TetragonAgentSession:
    def __init__(self, command: Sequence[str], load_timeout: int) -> None:
        self.command = list(command)
        self.load_timeout = load_timeout
        self.process: Any | None = None
        self.collector = ProcessOutputCollector()
        self.stdout_thread: threading.Thread | None = None
        self.stderr_thread: threading.Thread | None = None
        self.programs: list[dict[str, object]] = []

    def __enter__(self) -> "TetragonAgentSession":
        before_ids = set(current_prog_ids())
        self.process = start_agent(self.command[0], self.command[1:], env={"HOME": os.environ.get("HOME", str(ROOT_DIR))})
        assert self.process.stdout is not None
        assert self.process.stderr is not None
        self.stdout_thread = threading.Thread(target=self.collector.consume_stdout, args=(self.process.stdout,), daemon=True)
        self.stderr_thread = threading.Thread(target=self.collector.consume_stderr, args=(self.process.stderr,), daemon=True)
        self.stdout_thread.start()
        self.stderr_thread.start()

        try:
            healthy = wait_healthy(
                self.process,
                self.load_timeout,
                lambda: bool([item for item in find_bpf_programs(self.process.pid or 0) if int(item.get("id", -1)) not in before_ids]),
            )
        except Exception:
            cleanup_error: Exception | None = None
            try:
                self.close()
            except Exception as exc:
                cleanup_error = exc
            if cleanup_error is not None:
                raise RuntimeError(
                    f"Tetragon health check failed and cleanup also failed: {cleanup_error}"
                ) from cleanup_error
            raise
        if not healthy:
            snapshot = self.collector.snapshot()
            details = tail_text("\n".join((snapshot.get("stderr_tail") or []) + (snapshot.get("stdout_tail") or [])), max_lines=40, max_chars=8000)
            cleanup_error: Exception | None = None
            try:
                self.close()
            except Exception as exc:
                cleanup_error = exc
            message = f"Tetragon failed to become healthy within {self.load_timeout}s: {details}"
            if cleanup_error is not None:
                message = f"{message}\nCleanup error while stopping Tetragon: {cleanup_error}"
            raise RuntimeError(message)

        self.programs = [item for item in current_programs() if int(item.get("id", -1)) not in before_ids]
        if not self.programs:
            cleanup_error: Exception | None = None
            try:
                self.close()
            except Exception as exc:
                cleanup_error = exc
            message = "Tetragon became healthy but no new BPF programs were found"
            if cleanup_error is not None:
                message = f"{message}\nCleanup error while stopping Tetragon: {cleanup_error}"
            raise RuntimeError(message)
        return self

    @property
    def pid(self) -> int | None:
        return None if self.process is None else self.process.pid

    def collector_snapshot(self) -> dict[str, object]:
        return self.collector.snapshot()

    def close(self) -> None:
        stop_error: Exception | None = None
        if self.process is not None:
            try:
                stop_agent(self.process, timeout=8)
            except Exception as exc:
                stop_error = exc
            finally:
                self.process = None
        if self.stdout_thread is not None:
            self.stdout_thread.join(timeout=2.0)
            self.stdout_thread = None
        if self.stderr_thread is not None:
            self.stderr_thread.join(timeout=2.0)
            self.stderr_thread = None
        if stop_error is not None:
            raise RuntimeError(f"failed to stop Tetragon process cleanly: {stop_error}") from stop_error

    def __exit__(self, exc_type, exc, tb) -> None:
        self.close()


def describe_agent_exit(agent_name: str, process: Any | None, snapshot: Mapping[str, object]) -> str | None:
    if process is None:
        return f"{agent_name} process handle is unavailable"
    returncode = process.poll()
    if returncode is None:
        return None
    combined = "\n".join((snapshot.get("stderr_tail") or []) + (snapshot.get("stdout_tail") or []))
    details = tail_text(combined, max_lines=40, max_chars=8000)
    if details:
        return f"{agent_name} exited with code {returncode}: {details}"
    return f"{agent_name} exited with code {returncode}"


def write_tetragon_policies(directory: Path) -> list[Path]:
    directory.mkdir(parents=True, exist_ok=True)
    tracepoint_path = directory / "tetragon-e2e-tracepoint.yaml"
    tracepoint_path.write_text(
        """
apiVersion: cilium.io/v1alpha1
kind: TracingPolicy
metadata:
  name: bpf-benchmark-tetragon-e2e-tracepoint
spec:
  tracepoints:
    - subsystem: syscalls
      event: sys_enter_execve
""".strip()
        + "\n"
    )
    kprobe_path = directory / "tetragon-e2e-kprobes.yaml"
    kprobe_path.write_text(
        """
apiVersion: cilium.io/v1alpha1
kind: TracingPolicy
metadata:
  name: bpf-benchmark-tetragon-e2e-kprobes
spec:
  kprobes:
    - call: security_bprm_check
      syscall: false
    - call: security_file_open
      syscall: false
    - call: tcp_connect
      syscall: false
""".strip()
        + "\n"
    )
    return [tracepoint_path, kprobe_path]


def inspect_tetragon_setup() -> dict[str, object]:
    bundled_root = repo_artifact_root() / "tetragon"
    bundled_tetragon_binary = bundled_root / "bin" / "tetragon"
    bundled_bpf_dir = bundled_root

    missing_tools = missing_required_commands(("stress-ng", "fio", "curl", "tar"))
    if missing_tools:
        return {
            "returncode": 1,
            "tetragon_binary": None,
            "tetragon_bpf_lib_dir": None,
            "stdout_tail": "",
            "stderr_tail": f"missing required Tetragon workload tools: {' '.join(missing_tools)}",
        }

    tetragon_binary = pick_host_executable(bundled_tetragon_binary)
    if tetragon_binary is None:
        return {
            "returncode": 1,
            "tetragon_binary": None,
            "tetragon_bpf_lib_dir": None,
            "stdout_tail": "",
            "stderr_tail": f"missing repo-managed Tetragon binary under {bundled_tetragon_binary}",
        }

    bpf_lib_dir = bundled_bpf_dir if bundled_bpf_dir.is_dir() else None
    if bpf_lib_dir is None or not any(bpf_lib_dir.glob("*.o")) and not any(bpf_lib_dir.glob("*.bpf.o")):
        return {
            "returncode": 1,
            "tetragon_binary": str(tetragon_binary),
            "tetragon_bpf_lib_dir": None,
            "stdout_tail": "",
            "stderr_tail": f"missing bundled Tetragon .bpf.o files under {bundled_bpf_dir}",
        }

    help_probe = run_command(["timeout", "5s", str(tetragon_binary), "--help"], check=False, timeout=15)
    if help_probe.returncode != 0:
        return {
            "returncode": help_probe.returncode,
            "tetragon_binary": str(tetragon_binary),
            "tetragon_bpf_lib_dir": str(bpf_lib_dir),
            "stdout_tail": tail_text(help_probe.stdout or "", max_lines=60, max_chars=12000),
            "stderr_tail": tail_text(help_probe.stderr or "", max_lines=60, max_chars=12000),
        }

    stress_ng = which("stress-ng")
    return {
        "returncode": 0,
        "tetragon_binary": str(tetragon_binary),
        "tetragon_bpf_lib_dir": str(bpf_lib_dir),
        "stdout_tail": "\n".join(
            [
                f"TETRAGON_BINARY={tetragon_binary}",
                f"TETRAGON_BPF_LIB_DIR={bpf_lib_dir}",
                f"STRESS_NG_BINARY={stress_ng or ''}",
            ]
        ),
        "stderr_tail": "",
    }


def resolve_tetragon_binary(explicit: str | None, setup_result: Mapping[str, object]) -> str | None:
    if explicit:
        candidate = Path(explicit).resolve()
        if not candidate.exists():
            raise RuntimeError(f"Tetragon binary not found: {candidate}")
        return str(candidate)
    scripted = str(setup_result.get("tetragon_binary") or "").strip()
    if scripted:
        candidate = Path(scripted).resolve()
        if not candidate.exists():
            raise RuntimeError(f"Tetragon setup reported a missing binary: {candidate}")
        return str(candidate)
    return None


def run_exec_storm_in_cgroup(duration_s: int | float, rate: int) -> WorkloadResult:
    stress_ng = which("stress-ng")
    if stress_ng is None:
        raise RuntimeError("stress-ng is required for the tetragon cgroup-rate exec workload")
    cgroup_root = Path("/sys/fs/cgroup")
    if not cgroup_root.is_dir():
        raise RuntimeError(f"cgroup v2 root is unavailable: {cgroup_root}")
    if not (cgroup_root / "cgroup.procs").exists():
        raise RuntimeError(f"cgroup root is missing cgroup.procs: {cgroup_root / 'cgroup.procs'}")
    if os.geteuid() != 0:
        raise RuntimeError("tetragon cgroup-rate exec workload requires root to create and join a cgroup")

    command: list[str] = [
        stress_ng,
        "--exec",
        str(max(1, int(rate))),
        "--exec-method",
        "execve",
        "--temp-path",
        "/tmp",
        "--timeout",
        f"{max(1, int(duration_s))}s",
        "--metrics-brief",
    ]
    setpriv = which("setpriv")
    if setpriv is None:
        raise RuntimeError("setpriv is required for the tetragon cgroup-rate exec workload")
    command = [setpriv, "--reuid", "65534", "--regid", "65534", "--clear-groups", *command]

    cgroup_path = cgroup_root / f"bpf-benchmark-tetragon-exec-{os.getpid()}-{time.monotonic_ns()}"
    script = """
set -euo pipefail
ROOT_CGROUP="/sys/fs/cgroup"
CGROUP_PATH="$1"
shift
mkdir -p "$CGROUP_PATH"
echo $$ > "$CGROUP_PATH/cgroup.procs"
set +e
"$@"
status=$?
set -e
echo $$ > "$ROOT_CGROUP/cgroup.procs"
for _ in $(seq 1 20); do
  if [[ ! -s "$CGROUP_PATH/cgroup.procs" ]]; then
    break
  fi
  sleep 0.1
done
rmdir "$CGROUP_PATH"
exit "$status"
""".strip()

    start = time.monotonic()
    completed = run_command(
        ["bash", "-lc", script, "bash", str(cgroup_path), *command],
        check=False,
        cwd=Path("/tmp"),
        timeout=max(float(duration_s) + 30, float(duration_s) * 12),
    )
    elapsed = time.monotonic() - start
    if completed.returncode != 0:
        details = tail_text(completed.stderr or completed.stdout or "", max_lines=60, max_chars=12000)
        rendered = shlex.join(command)
        raise RuntimeError(f"tetragon cgroup-rate exec workload failed ({completed.returncode}) for {rendered}: {details}")

    from runner.libs.workload import parse_stress_ng_bogo_ops  # noqa: PLC0415

    combined = (completed.stdout or "") + "\n" + (completed.stderr or "")
    ops_total_value = parse_stress_ng_bogo_ops(combined, stressor="exec")
    if ops_total_value is None:
        ops_total_value = max(1.0, elapsed * max(1, int(rate)))
    return WorkloadResult(
        ops_total=float(ops_total_value),
        ops_per_sec=(float(ops_total_value) / elapsed) if elapsed > 0 else None,
        duration_s=elapsed,
        stdout=tail_text(completed.stdout or "", max_lines=40, max_chars=8000),
        stderr=tail_text(completed.stderr or "", max_lines=40, max_chars=8000),
    )


def run_tetragon_workload(spec: Mapping[str, object], duration_s: int, *, exec_workload_cgroup: bool) -> WorkloadResult:
    kind = str(spec.get("kind", ""))
    value = int(spec.get("value", 0) or 0)
    if kind == "exec_storm":
        if exec_workload_cgroup:
            return run_exec_storm_in_cgroup(duration_s, value or 2)
        return run_exec_storm(duration_s, value or 2)
    if kind == "file_io":
        return run_file_io(duration_s)
    if kind == "open_storm":
        return run_open_storm(duration_s)
    if kind == "connect_storm":
        return run_connect_storm(duration_s)
    raise RuntimeError(f"unsupported workload kind: {kind}")
