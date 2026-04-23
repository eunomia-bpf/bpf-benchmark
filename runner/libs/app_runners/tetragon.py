from __future__ import annotations

import os
import shlex
import socket
import tempfile
import time
from pathlib import Path
from typing import Any, Mapping, Sequence

from .. import ROOT_DIR, run_command, tail_text, which
from ..agent import bpftool_prog_show_records, start_agent, stop_agent, wait_healthy
from ..workload import WorkloadResult, run_connect_storm, run_exec_storm, run_file_io, run_open_storm
from .base import AppRunner
from .process_support import AgentSession, wait_until_program_set_stable
from .setup_support import missing_required_commands, pick_host_executable, repo_artifact_root


def current_programs() -> list[dict[str, object]]:
    return [dict(record) for record in bpftool_prog_show_records() if "id" in record]


def current_prog_ids() -> list[int]: return [int(r["id"]) for r in current_programs()]


class TetragonAgentSession(AgentSession):
    def __init__(self, command: Sequence[str], load_timeout: int) -> None:
        super().__init__(load_timeout); self.command = list(command); self.before_ids: set[int] = set()

    def _cleanup_err(self) -> Exception | None:
        try: self.close(); return None
        except Exception as exc: return exc

    def __enter__(self) -> "TetragonAgentSession":
        before_ids = set(current_prog_ids())
        self.before_ids = before_ids
        self.process = start_agent(self.command[0], self.command[1:], env={"HOME": os.environ.get("HOME", str(ROOT_DIR))})
        self._start_io_threads()
        try:
            healthy = wait_healthy(self.process, self.load_timeout,
                lambda: bool(self.refresh_programs()))
        except Exception:
            if (ce := self._cleanup_err()) is not None:
                raise RuntimeError(f"Tetragon health check failed and cleanup also failed: {ce}") from ce
            raise
        if not healthy:
            snapshot = self.collector.snapshot()
            details = tail_text("\n".join((snapshot.get("stderr_tail") or []) + (snapshot.get("stdout_tail") or [])), max_lines=40, max_chars=8000)
            ce = self._cleanup_err()
            msg = f"Tetragon failed to become healthy within {self.load_timeout}s: {details}"
            raise RuntimeError(msg if ce is None else f"{msg}\nCleanup error while stopping Tetragon: {ce}")
        self.programs = wait_until_program_set_stable(before_ids=self.before_ids, timeout_s=self.load_timeout)
        if not self.programs:
            ce = self._cleanup_err()
            msg = "Tetragon became healthy but no new BPF programs were found"
            raise RuntimeError(msg if ce is None else f"{msg}\nCleanup error while stopping Tetragon: {ce}")
        return self

    def refresh_programs(self) -> list[dict[str, object]]:
        programs = [dict(item) for item in current_programs() if int(item.get("id", -1)) not in self.before_ids]
        programs.sort(key=lambda item: int(item.get("id", 0) or 0))
        self.programs = programs
        return [dict(item) for item in self.programs]

    def close(self) -> None:
        stop_error: Exception | None = None
        if self.process is not None:
            try: stop_agent(self.process, timeout=8)
            except Exception as exc: stop_error = exc
            finally: self.process = None
        self._join_io_threads()
        if stop_error is not None: raise RuntimeError(f"failed to stop Tetragon process cleanly: {stop_error}") from stop_error


def describe_agent_exit(agent_name: str, process: Any | None, snapshot: Mapping[str, object]) -> str | None:
    if process is None: return f"{agent_name} process handle is unavailable"
    returncode = process.poll()
    if returncode is None: return None
    combined = "\n".join((snapshot.get("stderr_tail") or []) + (snapshot.get("stdout_tail") or []))
    details = tail_text(combined, max_lines=40, max_chars=8000)
    return f"{agent_name} exited with code {returncode}" + (f": {details}" if details else "")


def write_tetragon_policies(directory: Path) -> list[Path]:
    directory.mkdir(parents=True, exist_ok=True)
    tracepoint_path = directory / "tetragon-e2e-tracepoint.yaml"
    tracepoint_path.write_text("apiVersion: cilium.io/v1alpha1\nkind: TracingPolicy\nmetadata:\n  name: bpf-benchmark-tetragon-e2e-tracepoint\nspec:\n  tracepoints:\n    - subsystem: syscalls\n      event: sys_enter_execve\n")
    kprobe_path = directory / "tetragon-e2e-kprobes.yaml"
    kprobe_path.write_text("apiVersion: cilium.io/v1alpha1\nkind: TracingPolicy\nmetadata:\n  name: bpf-benchmark-tetragon-e2e-kprobes\nspec:\n  kprobes:\n    - call: security_bprm_check\n      syscall: false\n    - call: security_file_open\n      syscall: false\n    - call: tcp_connect\n      syscall: false\n")
    return [tracepoint_path, kprobe_path]


def inspect_tetragon_setup() -> dict[str, object]:
    artifact_root = repo_artifact_root() / "tetragon"; tetragon_artifact_binary = artifact_root / "bin" / "tetragon"
    _fail = {"returncode": 1, "tetragon_binary": None, "tetragon_bpf_lib_dir": None, "stdout_tail": ""}
    if missing_tools := missing_required_commands(("stress-ng", "fio", "curl", "tar")):
        return {**_fail, "stderr_tail": f"missing required Tetragon workload tools: {' '.join(missing_tools)}"}
    tetragon_binary = pick_host_executable(tetragon_artifact_binary)
    if tetragon_binary is None:
        return {**_fail, "stderr_tail": f"missing upstream Tetragon container artifact under {tetragon_artifact_binary}"}
    bpf_lib_dir = artifact_root if artifact_root.is_dir() else None
    if bpf_lib_dir is None or not any(bpf_lib_dir.glob("*.o")) and not any(bpf_lib_dir.glob("*.bpf.o")):
        return {"returncode": 1, "tetragon_binary": str(tetragon_binary), "tetragon_bpf_lib_dir": None,
                "stdout_tail": "", "stderr_tail": f"missing Tetragon .bpf.o artifacts under {artifact_root}"}
    help_probe = run_command(["timeout", "5s", str(tetragon_binary), "--help"], check=False, timeout=15)
    if help_probe.returncode != 0:
        return {"returncode": help_probe.returncode, "tetragon_binary": str(tetragon_binary), "tetragon_bpf_lib_dir": str(bpf_lib_dir),
                "stdout_tail": tail_text(help_probe.stdout or "", max_lines=60, max_chars=12000),
                "stderr_tail": tail_text(help_probe.stderr or "", max_lines=60, max_chars=12000)}
    return {"returncode": 0, "tetragon_binary": str(tetragon_binary), "tetragon_bpf_lib_dir": str(bpf_lib_dir),
            "stdout_tail": f"TETRAGON_BINARY={tetragon_binary}\nTETRAGON_BPF_LIB_DIR={bpf_lib_dir}\nSTRESS_NG_BINARY={which('stress-ng') or ''}",
            "stderr_tail": ""}


def resolve_tetragon_binary(explicit: str | None, setup_result: Mapping[str, object]) -> str | None:
    for path_str, errmsg in ((explicit, "Tetragon binary not found"), (str(setup_result.get("tetragon_binary") or "").strip(), "Tetragon setup reported a missing binary")):
        if path_str:
            candidate = Path(path_str).resolve()
            if not candidate.exists(): raise RuntimeError(f"{errmsg}: {candidate}")
            return str(candidate)
    return None


def run_exec_storm_in_cgroup(duration_s: int | float, rate: int) -> WorkloadResult:
    stress_ng = which("stress-ng")
    if stress_ng is None: raise RuntimeError("stress-ng is required for the tetragon cgroup-rate exec workload")
    cgroup_root = Path("/sys/fs/cgroup")
    if not cgroup_root.is_dir(): raise RuntimeError(f"cgroup v2 root is unavailable: {cgroup_root}")
    if not (cgroup_root / "cgroup.procs").exists(): raise RuntimeError(f"cgroup root is missing cgroup.procs: {cgroup_root / 'cgroup.procs'}")
    if os.geteuid() != 0: raise RuntimeError("tetragon cgroup-rate exec workload requires root to create and join a cgroup")

    command: list[str] = [stress_ng, "--exec", str(max(1, int(rate))), "--exec-method", "execve",
                          "--temp-path", "/tmp", "--timeout", f"{max(1, int(duration_s))}s", "--metrics-brief"]
    setpriv = which("setpriv")
    if setpriv is None: raise RuntimeError("setpriv is required for the tetragon cgroup-rate exec workload")
    command = [setpriv, "--reuid", "65534", "--regid", "65534", "--clear-groups", *command]

    cgroup_path = cgroup_root / f"bpf-benchmark-tetragon-exec-{os.getpid()}-{time.monotonic_ns()}"
    script = """
set -euo pipefail
ROOT_CGROUP="/sys/fs/cgroup"
CGROUP_PATH="$1"
shift
mkdir -p "$CGROUP_PATH"
if ! echo $$ > "$CGROUP_PATH/cgroup.procs"; then
  echo "failed to join cgroup.procs at $CGROUP_PATH" >&2
  rmdir "$CGROUP_PATH" 2>/dev/null || true
  exit 77
fi
set +e
"$@"
status=$?
set -e
if ! echo $$ > "$ROOT_CGROUP/cgroup.procs"; then
  echo "failed to return to root cgroup.procs at $ROOT_CGROUP" >&2
fi
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
    completed = run_command(["bash", "-lc", script, "bash", str(cgroup_path), *command],
        check=False, cwd=Path("/tmp"), timeout=max(float(duration_s) + 30, float(duration_s) * 12))
    elapsed = time.monotonic() - start
    if completed.returncode != 0:
        details = tail_text(completed.stderr or completed.stdout or "", max_lines=60, max_chars=12000)
        try:
            cgroup_path.rmdir()
        except OSError:
            pass
        cgroup_join_error = "cgroup.procs" in details or "echo: write error:" in details
        cgroup_unavailable = (
            "No such file or directory" in details
            or "No such file" in details
            or "Permission denied" in details
            or "Read-only file system" in details
        )
        if cgroup_join_error and cgroup_unavailable:
            fallback = run_exec_storm(duration_s, rate)
            note = f"cgroup exec workload unavailable, fell back to exec_storm: {details}"
            return WorkloadResult(
                ops_total=fallback.ops_total,
                ops_per_sec=fallback.ops_per_sec,
                duration_s=fallback.duration_s,
                stdout=fallback.stdout,
                stderr=tail_text("\n".join(item for item in (note, fallback.stderr) if item), max_lines=60, max_chars=12000),
            )
        rendered = shlex.join(command)
        raise RuntimeError(f"tetragon cgroup-rate exec workload failed ({completed.returncode}) for {rendered}: {details}")

    from runner.libs.workload import parse_stress_ng_bogo_ops  # noqa: PLC0415

    combined = (completed.stdout or "") + "\n" + (completed.stderr or "")
    ops_total_value = parse_stress_ng_bogo_ops(combined, stressor="exec") or max(1.0, elapsed * max(1, int(rate)))
    return WorkloadResult(ops_total=float(ops_total_value),
        ops_per_sec=(float(ops_total_value) / elapsed) if elapsed > 0 else None, duration_s=elapsed,
        stdout=tail_text(completed.stdout or "", max_lines=40, max_chars=8000),
        stderr=tail_text(completed.stderr or "", max_lines=40, max_chars=8000))


def run_tetragon_workload(spec: Mapping[str, object], duration_s: int, *, exec_workload_cgroup: bool) -> WorkloadResult:
    kind = str(spec.get("kind", "")); value = int(spec.get("value", 0) or 0)
    if kind == "exec_storm": return run_exec_storm_in_cgroup(duration_s, value or 2) if exec_workload_cgroup else run_exec_storm(duration_s, value or 2)
    if kind == "file_io": return run_file_io(duration_s)
    if kind == "open_storm": return run_open_storm(duration_s)
    if kind == "connect_storm": return run_connect_storm(duration_s)
    raise RuntimeError(f"unsupported workload kind: {kind}")


DEFAULT_LOAD_TIMEOUT_S = 20
DEFAULT_TETRAGON_EXTRA_ARGS = ("--cgroup-rate", "1000,1s")


def _has_option(args: Sequence[str], name: str) -> bool:
    return any(arg == name or arg.startswith(f"{name}=") for arg in args)


def _free_loopback_address() -> str:
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.bind(("127.0.0.1", 0))
        return f"127.0.0.1:{sock.getsockname()[1]}"


class TetragonRunner(AppRunner):
    def __init__(self, *, tetragon_binary: Path | str | None = None, tetragon_extra_args: Sequence[str] | None = None,
                 load_timeout_s: int = DEFAULT_LOAD_TIMEOUT_S, workload_spec: Mapping[str, object] | None = None) -> None:
        super().__init__()
        self.tetragon_binary = None if tetragon_binary is None else Path(tetragon_binary).resolve()
        resolved_extra_args = (
            DEFAULT_TETRAGON_EXTRA_ARGS
            if tetragon_extra_args is None
            else tuple(str(arg).strip() for arg in tetragon_extra_args if str(arg).strip())
        )
        self.tetragon_extra_args = tuple(str(arg) for arg in resolved_extra_args if str(arg).strip())
        self.load_timeout_s = int(load_timeout_s); self.setup_result: dict[str, object] | None = None
        self.tempdir: tempfile.TemporaryDirectory[str] | None = None; self.policy_paths: list[Path] = []
        self.command: list[str] = []; self.session: Any | None = None
        self.workload_spec: Mapping[str, object] = dict(workload_spec or {"kind": "exec_storm", "value": 2})
        self.exec_workload_cgroup = any(arg == "--cgroup-rate" for arg in self.tetragon_extra_args)

    @property
    def pid(self) -> int | None: return None if self.session is None else self.session.pid

    def _resolve_binary(self) -> str:
        if self.setup_result is None: self.setup_result = inspect_tetragon_setup()
        if int(self.setup_result.get("returncode", 0) or 0) != 0:
            details = str(self.setup_result.get("stderr_tail") or self.setup_result.get("stdout_tail") or self.setup_result)
            raise RuntimeError(f"Tetragon setup failed: {details}")
        resolved = resolve_tetragon_binary(None if self.tetragon_binary is None else str(self.tetragon_binary), self.setup_result)
        if resolved is None: raise RuntimeError("Tetragon binary not found; provide --tetragon-binary or prepare the upstream Tetragon container artifact")
        return resolved

    def start(self) -> list[int]:
        if self.session is not None: raise RuntimeError("TetragonRunner is already running")
        tetragon_binary = self._resolve_binary()
        self.tempdir = tempfile.TemporaryDirectory(prefix="tetragon-policy-")
        policy_dir = Path(self.tempdir.name)
        self.policy_paths = write_tetragon_policies(policy_dir)
        self.command = [tetragon_binary, *self.tetragon_extra_args]
        if not _has_option(self.tetragon_extra_args, "--server-address"):
            self.command.extend(["--server-address", _free_loopback_address()])
        if not _has_option(self.tetragon_extra_args, "--health-server-address"):
            self.command.extend(["--health-server-address", _free_loopback_address()])
        if tetragon_bpf_lib_dir := str((self.setup_result or {}).get("tetragon_bpf_lib_dir") or "").strip():
            self.command.extend(["--bpf-lib", tetragon_bpf_lib_dir])
        self.command.extend(["--tracing-policy-dir", str(policy_dir)]); self.command_used = list(self.command)
        session = TetragonAgentSession(self.command, self.load_timeout_s)
        try: session.__enter__()
        except Exception: self.tempdir.cleanup(); self.tempdir = None; raise
        self.session = session; self.tetragon_binary = Path(tetragon_binary).resolve()
        programs = [dict(program) for program in session.programs]
        if not programs: self._fail_start("Tetragon did not attach any BPF programs")
        self.programs = programs
        return [int(p["id"]) for p in programs if int(p.get("id", 0) or 0) > 0]

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None: raise RuntimeError("TetragonRunner is not running")
        return run_tetragon_workload(self.workload_spec, max(1, int(round(seconds))), exec_workload_cgroup=self.exec_workload_cgroup)

    def run_workload_spec(self, workload_spec: Mapping[str, object], seconds: float) -> WorkloadResult:
        if self.session is None: raise RuntimeError("TetragonRunner is not running")
        exec_workload_cgroup = workload_spec.get("exec_workload_cgroup")
        if exec_workload_cgroup is None: use_exec_workload_cgroup = self.exec_workload_cgroup
        elif isinstance(exec_workload_cgroup, bool): use_exec_workload_cgroup = exec_workload_cgroup
        else: raise RuntimeError("Tetragon workload spec field 'exec_workload_cgroup' must be a boolean when provided")
        return run_tetragon_workload(workload_spec, max(1, int(round(seconds))), exec_workload_cgroup=use_exec_workload_cgroup)

    def refresh_programs(self) -> list[dict[str, object]]:
        if self.session is None: raise RuntimeError("TetragonRunner is not running")
        self.programs = [dict(program) for program in self.session.refresh_programs()]
        return [dict(program) for program in self.programs]

    def stop(self) -> None:
        if self.session is None and self.tempdir is None: return
        errors: list[str] = []
        if self.session is not None:
            session, self.session = self.session, None
            self.process_output = session.collector_snapshot()
            try: session.close()
            except Exception as exc: errors.append(str(exc))
        if self.tempdir is not None:
            try: self.tempdir.cleanup()
            except Exception as exc: errors.append(str(exc))
            self.tempdir = None
        if errors: raise RuntimeError("; ".join(errors))
