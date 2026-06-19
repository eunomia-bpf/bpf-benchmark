from __future__ import annotations

import os
import json
import shlex
import signal
import subprocess
import threading
import time
from collections import deque
from pathlib import Path
from typing import Any, Mapping, Sequence
from urllib.error import URLError
from urllib.request import urlopen

from .. import ROOT_DIR, run_command, tail_text
from ..agent import (
    start_agent,
    wait_healthy,
)
from ..rejit import (
    app_shim_has_programs,
    skip_rejit_disables_shim,
    wait_for_app_shim_programs,
)
from ..workload import (
    WorkloadResult,
    run_named_workload,
)
from .base import AppRunner
from .native_loader_env import native_loader_manifest_env
from .process_support import AgentSession
from .setup_support import pick_host_executable, repo_artifact_root


TRACEE_HEALTH_HOST = "127.0.0.1"
TRACEE_HEALTH_PORT = 3366
TRACEE_OUTPUT_MODE = "none"
TRACEE_EVENTS_ENV = "BPFREJIT_TRACEE_EVENTS"
TRACEE_EVENT_EXCLUSIONS = (
    "net_packet_raw",
    "print_mem_dump",
    "net_packet_ipv4",
    "net_packet_ipv6",
    "net_packet_tcp",
    "net_packet_udp",
    "net_packet_icmp",
    "net_packet_icmpv6",
    "net_packet_dns",
    "net_packet_dns_request",
    "net_packet_dns_response",
    "net_packet_http",
    "net_packet_http_request",
    "net_packet_http_response",
    "anti_debugging",
    "aslr_inspection",
    "cgroup_notify_on_release",
    "cgroup_release_agent",
    "core_pattern_modification",
    "default_loader_mod",
    "disk_mount",
    "docker_abuse",
    "dropped_executable",
    "dynamic_code_loading",
    # The current arm64 test kernel hard-reboots while cleaning up the
    # fd_install/filp_close/file_update_time kprobe links behind this event.
    "file_modification",
    "fileless_execution",
    "hidden_file_created",
    "hooked_seq_ops_detector",
    "hooked_syscall_detector",
    "illegitimate_shell",
    "k8s_service_account_token",
    "kernel_module_loading",
    "k8s_api_connection",
    "k8s_cert_theft",
    "ld_preload",
    # This self-test triggers Tracee's LSM support probe, which attaches a
    # transient kprobe to security_bpf outside the selected event set. On the
    # current arm64 benchmark kernel, Tracee teardown can hard-reboot while
    # cleaning up that probe path.
    "lsm_test",
    "proc_fops_hooking",
    "proc_kcore_read",
    "proc_mem_access",
    "proc_mem_code_injection",
    "process_vm_write_inject",
    "ptrace_code_injection",
    "rcd_modification",
    "sched_debug_recon",
    "scheduled_task_mod",
    # The current arm64 test kernel hard-reboots while closing Tracee's BPF
    # self-monitoring kprobe links during teardown.
    "bpf_attach",
    "security_bpf",
    "security_bpf_map",
    "security_bpf_prog",
    "stdio_over_socket",
    "sudoers_modification",
    "syscall_hooking",
    "system_request_key_mod",
)


def _tracee_runtime_dir() -> Path:
    if explicit := os.environ.get("BPFREJIT_TRACEE_RUNTIME_DIR", "").strip():
        candidate = Path(explicit).expanduser()
    else:
        tmpdir = os.environ.get("TMPDIR", "").strip()
        if not tmpdir:
            raise RuntimeError("TMPDIR is required for the Tracee runner")
        candidate = Path(tmpdir).expanduser() / "tracee"
    candidate.mkdir(parents=True, exist_ok=True)
    if not os.access(candidate, os.W_OK | os.X_OK):
        raise RuntimeError(f"Tracee runtime directory is not writable/executable: {candidate}")
    return candidate


def tracee_native_loader_env() -> dict[str, str]:
    return native_loader_manifest_env("tracee")


class TraceeOutputCollector:
    def __init__(self) -> None:
        self._lock = threading.Lock()
        self.stdout_tail: deque[str] = deque(maxlen=200)
        self.stderr_tail: deque[str] = deque(maxlen=200)

    def consume_stdout(self, pipe: Any) -> None:
        for raw_line in iter(pipe.readline, ""):
            line = raw_line.rstrip()
            with self._lock: self.stdout_tail.append(line)
        pipe.close()

    def consume_stderr(self, pipe: Any) -> None:
        for raw_line in iter(pipe.readline, ""):
            line = raw_line.rstrip()
            with self._lock: self.stderr_tail.append(line)
        pipe.close()

    def snapshot(self) -> dict[str, object]:
        with self._lock:
            return {
                "stdout_tail": list(self.stdout_tail),
                "stderr_tail": list(self.stderr_tail),
            }


class TraceeAgentSession(AgentSession):
    def __init__(self, commands: Sequence[Sequence[str]]) -> None:
        super().__init__()
        self.commands = [list(command) for command in commands]
        self.collector = TraceeOutputCollector()
        self.command_used: list[str] | None = None

    def __enter__(self) -> "TraceeAgentSession":
        failures: list[str] = []
        tracee_tmpdir = _tracee_runtime_dir()
        tracee_tmpdir.mkdir(parents=True, exist_ok=True)
        for command in self.commands:
            self.collector = TraceeOutputCollector()
            env = {
                "HOME": os.environ.get("HOME", str(ROOT_DIR)),
                "TMPDIR": str(tracee_tmpdir),
                "TMP": str(tracee_tmpdir),
                "TEMP": str(tracee_tmpdir),
            }
            env.update(tracee_native_loader_env())
            proc = start_agent(
                command[0],
                command[1:],
                env=env,
            )
            _tracee_event(
                "tracee_start",
                proc,
                parent_native_env_keys=_current_native_env_keys(),
                explicit_native_env_keys=_native_env_keys_from_mapping(env),
                **_process_native_env_snapshot(int(proc.pid)),
            )
            self.process = proc
            self.command_used = command
            self._start_io_threads()

            def _health_check() -> bool:
                return _tracee_healthz_ready(TRACEE_HEALTH_HOST, TRACEE_HEALTH_PORT) and (
                    skip_rejit_disables_shim() or app_shim_has_programs(int(proc.pid))
                )

            try:
                healthy = wait_healthy(proc, DEFAULT_STARTUP_TIMEOUT_S, _health_check)
            except Exception:
                self.close()
                raise
            if healthy:
                try:
                    wait_for_app_shim_programs(
                        app_pid=int(proc.pid),
                        process=proc,
                        snapshot=self.collector_snapshot,
                        process_name="Tracee",
                    )
                except Exception:
                    self.close()
                    raise
                self.programs = []
                return self
            failed_proc = proc
            self.close()
            snapshot = self.collector.snapshot()
            failures.append(_format_launch_failure(command, failed_proc, snapshot))
        if not failures:
            failures.append("Tracee never became healthy")
        raise RuntimeError(f"failed to launch Tracee: {' | '.join(failures)}")

    @property
    def pid(self) -> int | None:
        return None if self.process is None else self.process.pid

    def collector_snapshot(self) -> dict[str, object]:
        return self.collector.snapshot()

    def close(self) -> None:
        if self.process is not None:
            stop_tracee_agent(self.process); self.process = None
        self._join_io_threads()


def inspect_tracee_setup() -> dict[str, object]:
    artifact_binary = repo_artifact_root() / "tracee" / "bin" / "tracee"
    tracee_binary = pick_host_executable(artifact_binary)
    if tracee_binary is None:
        return {"returncode": 1, "tracee_binary": None, "stdout_tail": "",
                "stderr_tail": f"missing upstream Tracee container artifact under {artifact_binary}"}
    vp = run_command([str(tracee_binary), "--version"], check=False)
    if vp.returncode != 0:
        vp = run_command([str(tracee_binary), "version"], check=False)
    if vp.returncode != 0:
        return {"returncode": vp.returncode, "tracee_binary": str(tracee_binary),
                "stdout_tail": tail_text(vp.stdout or "", max_lines=40, max_chars=8000),
                "stderr_tail": tail_text(vp.stderr or "", max_lines=40, max_chars=8000)}
    tracee_ebpf = tracee_binary.parent / "tracee-ebpf"
    stdout_tail = f"TRACEE_BINARY={tracee_binary}"
    if tracee_ebpf.is_file():
        stdout_tail += f"\nTRACEE_EBPF_BINARY={tracee_ebpf}"
    return {"returncode": 0, "tracee_binary": str(tracee_binary),
            "stdout_tail": stdout_tail, "stderr_tail": ""}


def resolve_tracee_binary(explicit: str | None, setup_result: Mapping[str, object]) -> str | None:
    if explicit:
        candidate = Path(explicit).resolve()
        if not candidate.exists():
            raise RuntimeError(f"Tracee binary not found: {candidate}")
        return str(candidate)
    scripted = str(setup_result.get("tracee_binary") or "").strip()
    if scripted:
        candidate = Path(scripted).resolve()
        if not candidate.exists():
            raise RuntimeError(f"Tracee setup reported a missing binary: {candidate}")
        return str(candidate)
    return None


def _tracee_signatures_dir() -> Path:
    sig_dir = _tracee_runtime_dir() / "signatures"
    sig_dir.mkdir(parents=True, exist_ok=True)
    return sig_dir


def _tracee_healthz_ready(host: str, port: int) -> bool:
    try:
        with urlopen(f"http://{host}:{int(port)}/healthz") as response:
            return int(getattr(response, "status", 0) or 0) == 200
    except (OSError, URLError):
        return False


def build_tracee_commands(binary: str, extra_args: Sequence[str] = ()) -> list[list[str]]:
    event_args: list[str]
    requested_events = os.environ.get(TRACEE_EVENTS_ENV, "").strip()
    if requested_events:
        event_args = ["--events", requested_events]
    else:
        excluded_events = ",".join(f"-{event_name}" for event_name in TRACEE_EVENT_EXCLUSIONS)
        event_args = ["--events", "*", "--events", excluded_events]
    # --capabilities bypass=true keeps CAP_BPF + CAP_PERFMON effective for the
    # whole tracee process lifetime. Default tracee parks them in a separate
    # "EBPF ring" and only enters that ring around its own BPF syscalls; the
    # bpfrejit shim performs BPF_PROG_LOAD inline from a runner-driven socket
    # request, which lands outside the ring and would otherwise EPERM at
    # kernel/bpf/syscall.c:2913 (bpf_token_capable check).
    return [[binary, *event_args,
             "--output", TRACEE_OUTPUT_MODE,
             "--server", "healthz", "--server", f"http-address=:{TRACEE_HEALTH_PORT}",
             "--signatures-dir", str(_tracee_signatures_dir()),
             "--capabilities", "bypass=true",
             *extra_args]]


def _format_launch_failure(command: Sequence[str], proc: subprocess.Popen[str] | None, snapshot: Mapping[str, object]) -> str:
    rendered = " ".join(shlex.quote(part) for part in command)
    combined = "\n".join(
        (snapshot.get("stderr_tail") or [])
        + (snapshot.get("stdout_tail") or [])
    )
    details = tail_text(combined, max_lines=40, max_chars=8000)
    if proc is not None and proc.poll() is not None:
        reason = f"command exited with code {proc.returncode}"
    else:
        reason = "command did not become healthy"
    if details:
        return f"{rendered}: {reason}: {details}"
    return f"{rendered}: {reason}"


def _env_bool(name: str) -> bool:
    raw = os.environ.get(name, "").strip().lower()
    return raw in {"1", "true", "yes", "on"}


_FTRACE_PROFILE_CONTROL_FILES = ("current_tracer", "function_profile_enabled", "set_ftrace_filter")
_KPROBE_PROFILE_CONTROL_FILES = ("kprobe_events", "kprobe_profile")


def _decode_mountinfo_path(raw: str) -> str:
    return (
        raw.replace("\\040", " ")
        .replace("\\011", "\t")
        .replace("\\012", "\n")
        .replace("\\134", "\\")
    )


def _mounted_tracefs_roots() -> list[Path]:
    roots: list[Path] = []
    try:
        lines = Path("/proc/self/mountinfo").read_text(encoding="utf-8", errors="replace").splitlines()
    except OSError:
        return roots
    for line in lines:
        fields = line.split()
        try:
            separator = fields.index("-")
        except ValueError:
            continue
        if separator + 1 >= len(fields) or fields[separator + 1] != "tracefs":
            continue
        if len(fields) > 4:
            roots.append(Path(_decode_mountinfo_path(fields[4])))
    return roots


def _tracefs_candidates() -> list[Path]:
    candidates = [
        Path("/sys/kernel/debug/tracing"),
        Path("/sys/kernel/tracing"),
        *_mounted_tracefs_roots(),
    ]
    deduped: list[Path] = []
    seen: set[str] = set()
    for candidate in candidates:
        key = str(candidate)
        if key in seen:
            continue
        seen.add(key)
        deduped.append(candidate)
    return deduped


def _tracefs_root(required_files: Sequence[str] = _FTRACE_PROFILE_CONTROL_FILES) -> Path:
    # The runtime container bind-mounts /sys/kernel/debug explicitly. Prefer
    # that tracefs view over /sys/kernel/tracing, which may be mounted with
    # stricter permissions by the container runtime.
    failures: list[str] = []
    for candidate in _tracefs_candidates():
        if _tracefs_ready(candidate, required_files):
            return candidate
        try:
            candidate.mkdir(parents=True, exist_ok=True)
            proc = subprocess.run(
                ["mount", "-t", "tracefs", "tracefs", str(candidate)],
                check=False,
                capture_output=True,
                text=True,
            )
        except OSError as exc:
            failures.append(
                f"{candidate}: mount exec failed: {exc}; "
                f"{_tracefs_unready_reason(candidate, required_files)}"
            )
            continue
        if _tracefs_ready(candidate, required_files):
            return candidate
        detail = (proc.stderr or proc.stdout or "").strip()
        if detail:
            failures.append(
                f"{candidate}: {_tracefs_unready_reason(candidate, required_files)}; "
                f"mount exited {proc.returncode}: {detail}"
            )
        else:
            failures.append(
                f"{candidate}: {_tracefs_unready_reason(candidate, required_files)}; "
                f"mount exited {proc.returncode}"
            )
    joined = "; ".join(failures) if failures else "no tracefs candidates"
    raise RuntimeError(
        f"tracefs is not available for Tracee ftrace diagnostics: {joined}; "
        f"{_process_privilege_context()}"
    )


def _tracefs_ready(root: Path, required_files: Sequence[str]) -> bool:
    return all((root / name).exists() for name in required_files)


def _tracefs_unready_reason(root: Path, required_files: Sequence[str]) -> str:
    if not root.exists():
        return "root missing"
    if not root.is_dir():
        return "root is not a directory"
    missing = [name for name in required_files if not (root / name).exists()]
    if missing:
        return "missing " + ",".join(missing)
    return "control files present but tracefs is not ready"


def _process_privilege_context() -> str:
    parts = [f"euid={os.geteuid()}", f"egid={os.getegid()}"]
    try:
        status = Path("/proc/self/status").read_text(encoding="utf-8", errors="replace")
        for line in status.splitlines():
            if line.startswith(("Uid:", "Gid:", "CapEff:", "Seccomp:")):
                parts.append(line)
    except OSError as exc:
        parts.append(f"proc_status_error={exc}")
    return "; ".join(parts)


def _write_tracefs(path: Path, value: str) -> None:
    try:
        path.write_text(value, encoding="utf-8")
    except OSError as exc:
        raise RuntimeError(
            f"failed to write {path}: {exc}; {_process_privilege_context()}"
        ) from exc


def _append_tracefs(path: Path, value: str) -> None:
    try:
        with path.open("a", encoding="utf-8") as file:
            file.write(value)
    except OSError as exc:
        raise RuntimeError(
            f"failed to append {path} with {value!r}: {exc}; "
            f"{_process_privilege_context()}"
        ) from exc


def _read_tracefs(path: Path) -> str:
    try:
        return path.read_text(encoding="utf-8", errors="replace")
    except OSError as exc:
        raise RuntimeError(f"failed to read {path}: {exc}") from exc


def _requested_trace_functions(env_name: str) -> list[str]:
    raw = os.environ.get(env_name, "").strip()
    if not raw:
        raise RuntimeError(f"{env_name} is required when trace diagnostics are enabled")
    names = [part.strip() for part in raw.replace(",", " ").split() if part.strip()]
    if not names:
        raise RuntimeError(f"{env_name} did not contain any function names")
    return names


def _requested_ftrace_functions() -> list[str]:
    return _requested_trace_functions("BPFREJIT_FTRACE_FUNCTIONS")


def _requested_kprobe_functions() -> list[str]:
    return _requested_trace_functions("BPFREJIT_KPROBE_FUNCTIONS")


def _read_function_profile(root: Path) -> str:
    stat_dir = root / "trace_stat"
    parts: list[str] = []
    for path in sorted(stat_dir.glob("function*")):
        parts.append(f"--- {path.name} ---\n{_read_tracefs(path)}")
    if not parts:
        raise RuntimeError(f"ftrace function profiler did not expose {stat_dir}/function*")
    return "\n".join(parts)


def _kprobe_event_name(index: int, function: str) -> str:
    suffix = "".join(ch if ch.isalnum() else "_" for ch in function)
    suffix = suffix.strip("_")[:32] or "fn"
    return f"bpfrejit_{os.getpid()}_{index}_{suffix}"


def _read_kprobe_profile(root: Path, events: Sequence[str]) -> str:
    wanted = set(events)
    lines = []
    for line in _read_tracefs(root / "kprobe_profile").splitlines():
        fields = line.split()
        if fields and fields[0] in wanted:
            lines.append(line)
    if len(lines) != len(wanted):
        seen = {line.split()[0] for line in lines if line.split()}
        missing = ",".join(event for event in events if event not in seen)
        raise RuntimeError(f"kprobe_profile missing event(s): {missing}")
    return "\n".join(lines)


def _run_workload_with_kprobe_counts(kind: str, duration_s: int) -> WorkloadResult:
    root = _tracefs_root(_KPROBE_PROFILE_CONTROL_FILES)
    functions = _requested_kprobe_functions()
    kprobe_events = root / "kprobe_events"
    created: list[tuple[str, str]] = []
    enabled: list[str] = []
    workload: WorkloadResult | None = None
    profile = ""
    profile_error = ""
    cleanup_errors: list[str] = []
    try:
        for index, function in enumerate(functions):
            event = _kprobe_event_name(index, function)
            try:
                _append_tracefs(kprobe_events, f"p:{event} {function}\n")
            except Exception as exc:
                raise RuntimeError(
                    f"failed to create kprobe event {event} for {function}: {exc}"
                ) from exc
            created.append((event, function))
        for event, _function in created:
            _write_tracefs(root / "events" / "kprobes" / event / "enable", "1\n")
            enabled.append(event)
        workload = run_named_workload(kind, duration_s)
    finally:
        for event in reversed(enabled):
            try:
                _write_tracefs(root / "events" / "kprobes" / event / "enable", "0\n")
            except Exception as exc:
                cleanup_errors.append(str(exc))
        if created:
            try:
                profile = _read_kprobe_profile(root, [event for event, _function in created])
            except Exception as exc:
                profile_error = str(exc)
        for event, _function in reversed(created):
            try:
                _append_tracefs(kprobe_events, f"-:kprobes/{event}\n")
            except Exception as exc:
                cleanup_errors.append(str(exc))

    if profile_error or cleanup_errors:
        detail = "; ".join([part for part in (profile_error, *cleanup_errors) if part])
        raise RuntimeError(detail)
    if workload is None:
        raise RuntimeError("Tracee kprobe diagnostic workload did not run")

    diag_parts = ["BPFREJIT_KPROBE_FUNCTION_COUNTS_BEGIN"]
    for event, function in created:
        diag_parts.append(f"{event}\t{function}")
    if profile:
        diag_parts.append(profile.rstrip())
    diag_parts.append("BPFREJIT_KPROBE_FUNCTION_COUNTS_END")
    stderr = "\n".join(part for part in (workload.stderr or "", "\n".join(diag_parts)) if part)
    return WorkloadResult(
        workload_name=workload.workload_name,
        command=workload.command,
        returncode=workload.returncode,
        duration_s=workload.duration_s,
        stdout=workload.stdout,
        stderr=stderr,
        config=workload.config,
        components=workload.components,
    )


def _run_workload_with_ftrace_profile(kind: str, duration_s: int) -> WorkloadResult:
    if not _env_bool("BPFREJIT_FTRACE_FUNCTION_PROFILE"):
        return run_named_workload(kind, duration_s)

    root = _tracefs_root()
    functions = _requested_ftrace_functions()
    current_tracer = root / "current_tracer"
    set_filter = root / "set_ftrace_filter"
    profile_enabled = root / "function_profile_enabled"

    previous_tracer = _read_tracefs(current_tracer).strip()
    previous_filter = _read_tracefs(set_filter)
    workload: WorkloadResult | None = None
    profile = ""
    profile_error = ""
    restore_error = ""
    try:
        _write_tracefs(profile_enabled, "0\n")
        _write_tracefs(current_tracer, "nop\n")
        _write_tracefs(set_filter, "\n")
        _write_tracefs(set_filter, "\n".join(functions) + "\n")
        _write_tracefs(current_tracer, "function\n")
        _write_tracefs(profile_enabled, "1\n")
        workload = run_named_workload(kind, duration_s)
    finally:
        try:
            _write_tracefs(profile_enabled, "0\n")
            profile = _read_function_profile(root)
        except Exception as exc:  # diagnostics must not hide cleanup
            profile_error = str(exc)
        try:
            _write_tracefs(current_tracer, "nop\n")
            _write_tracefs(set_filter, "\n")
            if previous_filter.strip():
                _write_tracefs(set_filter, previous_filter)
            if previous_tracer:
                _write_tracefs(current_tracer, previous_tracer + "\n")
        except Exception as exc:  # diagnostics must surface restore failures
            restore_error = str(exc)

    if profile_error or restore_error:
        raise RuntimeError(profile_error or restore_error)
    if workload is None:
        raise RuntimeError("Tracee ftrace diagnostic workload did not run")

    diag_parts = ["BPFREJIT_FTRACE_FUNCTION_PROFILE_BEGIN"]
    if profile:
        diag_parts.append(profile.rstrip())
    diag_parts.append("BPFREJIT_FTRACE_FUNCTION_PROFILE_END")
    stderr = "\n".join(part for part in (workload.stderr or "", "\n".join(diag_parts)) if part)
    return WorkloadResult(
        workload_name=workload.workload_name,
        command=workload.command,
        returncode=workload.returncode,
        duration_s=workload.duration_s,
        stdout=workload.stdout,
        stderr=stderr,
        config=workload.config,
        components=workload.components,
    )


def _run_workload_with_trace_diagnostics(kind: str, duration_s: int) -> WorkloadResult:
    if _env_bool("BPFREJIT_KPROBE_FUNCTION_COUNTS"):
        return _run_workload_with_kprobe_counts(kind, duration_s)
    return _run_workload_with_ftrace_profile(kind, duration_s)


def run_tracee_workload(spec: Mapping[str, object], duration_s: int) -> WorkloadResult:
    kind = str(spec.get("kind", spec.get("name", "")))
    if kind.startswith("stress_ng_") or kind in ("fio_randrw", "fio"):
        return _run_workload_with_trace_diagnostics(kind, duration_s)
    raise RuntimeError(f"unsupported workload kind: {kind}")

DEFAULT_STARTUP_SETTLE_S = 5.0
DEFAULT_STARTUP_TIMEOUT_S = 300.0
DEFAULT_GRACEFUL_STOP_TIMEOUT_S = 10.0
DEFAULT_KILL_STOP_TIMEOUT_S = 30.0
TRACEE_STOP_MODE_ENV = "BPFREJIT_TRACEE_STOP_MODE"
TRACEE_STOP_MODE_KILL = "kill"
TRACEE_STOP_MODE_GRACEFUL = "graceful"
_NATIVE_ENV_KEY_PREFIXES = (
    "BPFREJIT_CORPUS_NATIVE",
    "BPFREJIT_NATIVE",
    "BPFREJIT_SHIM_NATIVE",
)


def _is_native_env_key(key: str) -> bool:
    return any(key.startswith(prefix) for prefix in _NATIVE_ENV_KEY_PREFIXES)


def _native_env_keys_from_mapping(env: Mapping[str, object]) -> list[str]:
    return sorted(key for key in env if _is_native_env_key(key))


def _current_native_env_keys() -> list[str]:
    return _native_env_keys_from_mapping(os.environ)


def _process_native_env_snapshot(pid: int) -> dict[str, object]:
    try:
        raw = Path(f"/proc/{int(pid)}/environ").read_bytes()
    except OSError as exc:
        return {"child_native_env_error": str(exc)}
    keys: set[str] = set()
    for item in raw.split(b"\0"):
        if not item:
            continue
        key = item.split(b"=", 1)[0].decode("utf-8", errors="replace")
        if _is_native_env_key(key):
            keys.add(key)
    return {"child_native_env_keys": sorted(keys)}


def _tracee_event(event: str, proc: subprocess.Popen[str], **fields: object) -> None:
    payload = {
        "event": event,
        "pid": int(proc.pid),
    }
    payload.update(fields)
    print(json.dumps(payload, sort_keys=True), flush=True)


def _tracee_stop_event(proc: subprocess.Popen[str], mode: str, step: str, **fields: object) -> None:
    payload = {
        "event": "tracee_stop",
        "mode": mode,
        "pid": int(proc.pid),
        "step": step,
    }
    payload.update(fields)
    print(json.dumps(payload, sort_keys=True), flush=True)


def tracee_stop_mode() -> str:
    raw = os.environ.get(TRACEE_STOP_MODE_ENV, TRACEE_STOP_MODE_KILL).strip().lower()
    if raw not in {TRACEE_STOP_MODE_KILL, TRACEE_STOP_MODE_GRACEFUL}:
        raise RuntimeError(
            f"{TRACEE_STOP_MODE_ENV} must be one of "
            f"{TRACEE_STOP_MODE_KILL!r}, {TRACEE_STOP_MODE_GRACEFUL!r}; got {raw!r}"
        )
    return raw


def stop_tracee_agent(proc: subprocess.Popen[str], *, mode: str | None = None) -> int:
    mode = tracee_stop_mode() if mode is None else mode
    if proc.poll() is not None:
        _tracee_stop_event(proc, mode, "already_exited", returncode=int(proc.returncode or 0))
        return int(proc.returncode or 0)

    _tracee_stop_event(
        proc,
        mode,
        "pre_signal_env",
        parent_native_env_keys=_current_native_env_keys(),
        **_process_native_env_snapshot(int(proc.pid)),
    )
    if mode == TRACEE_STOP_MODE_KILL:
        _tracee_stop_event(proc, mode, "send_signal", signal="SIGKILL")
        proc.kill()
        _tracee_stop_event(proc, mode, "signal_sent", signal="SIGKILL")
        try:
            rc = proc.wait(timeout=DEFAULT_KILL_STOP_TIMEOUT_S)
            _tracee_stop_event(proc, mode, "wait_done", returncode=int(rc or 0))
            return rc
        except subprocess.TimeoutExpired as exc:
            _tracee_stop_event(proc, mode, "wait_timeout", timeout_s=DEFAULT_KILL_STOP_TIMEOUT_S)
            raise RuntimeError(
                "Tracee did not exit after SIGKILL "
                f"within {DEFAULT_KILL_STOP_TIMEOUT_S:.1f}s"
            ) from exc
    if mode != TRACEE_STOP_MODE_GRACEFUL:
        raise RuntimeError(
            f"unsupported Tracee stop mode {mode!r}; expected "
            f"{TRACEE_STOP_MODE_KILL!r} or {TRACEE_STOP_MODE_GRACEFUL!r}"
        )

    _tracee_stop_event(proc, mode, "send_signal", signal="SIGINT")
    proc.send_signal(signal.SIGINT)
    try:
        rc = proc.wait(timeout=DEFAULT_GRACEFUL_STOP_TIMEOUT_S)
        _tracee_stop_event(proc, mode, "wait_done", returncode=int(rc or 0), signal="SIGINT")
        return rc
    except subprocess.TimeoutExpired:
        _tracee_stop_event(proc, mode, "wait_timeout", signal="SIGINT", timeout_s=DEFAULT_GRACEFUL_STOP_TIMEOUT_S)
        pass

    _tracee_stop_event(proc, mode, "send_signal", signal="SIGTERM")
    proc.terminate()
    try:
        rc = proc.wait(timeout=DEFAULT_GRACEFUL_STOP_TIMEOUT_S)
        _tracee_stop_event(proc, mode, "wait_done", returncode=int(rc or 0), signal="SIGTERM")
        return rc
    except subprocess.TimeoutExpired:
        _tracee_stop_event(proc, mode, "wait_timeout", signal="SIGTERM", timeout_s=DEFAULT_GRACEFUL_STOP_TIMEOUT_S)
        pass

    _tracee_stop_event(proc, mode, "send_signal", signal="SIGKILL")
    proc.kill()
    try:
        rc = proc.wait(timeout=DEFAULT_KILL_STOP_TIMEOUT_S)
        _tracee_stop_event(proc, mode, "wait_done", returncode=int(rc or 0), signal="SIGKILL")
        return rc
    except subprocess.TimeoutExpired as exc:
        _tracee_stop_event(proc, mode, "wait_timeout", signal="SIGKILL", timeout_s=DEFAULT_KILL_STOP_TIMEOUT_S)
        raise RuntimeError(
            "Tracee did not exit after SIGINT/SIGTERM/SIGKILL "
            f"within {DEFAULT_KILL_STOP_TIMEOUT_S:.1f}s"
        ) from exc


class TraceeRunner(AppRunner):
    def __init__(
        self,
        *,
        tracee_binary: Path | str | None = None,
        extra_args: Sequence[str] = (),
        workload_spec: Mapping[str, object] | None = None,
    ) -> None:
        super().__init__()
        self.tracee_binary = None if tracee_binary is None else Path(tracee_binary).resolve()
        self.extra_args = tuple(str(arg) for arg in extra_args)
        self.session: Any | None = None
        self.setup_result: dict[str, object] = {"returncode": 0, "tracee_binary": None, "stdout_tail": "", "stderr_tail": ""}
        self.workload_spec: Mapping[str, object] = {} if workload_spec is None else dict(workload_spec)

    @property
    def pid(self) -> int | None:
        return None if self.session is None else self.session.pid

    @property
    def collector(self) -> TraceeOutputCollector | None:
        return None if self.session is None else self.session.collector

    def _resolve_binary(self) -> str:
        resolved = resolve_tracee_binary(None if self.tracee_binary is None else str(self.tracee_binary), self.setup_result)
        if resolved is None:
            self.setup_result = inspect_tracee_setup()
            if int(self.setup_result.get("returncode", 0) or 0) != 0:
                details = str(self.setup_result.get("stderr_tail") or self.setup_result.get("stdout_tail") or self.setup_result)
                raise RuntimeError(f"Tracee setup failed: {details}")
            resolved = resolve_tracee_binary(
                None if self.tracee_binary is None else str(self.tracee_binary),
                self.setup_result,
            )
        if resolved is None:
            raise RuntimeError("Tracee binary not found; provide --tracee-binary or prepare the upstream Tracee container artifact")
        return resolved

    def start(self) -> list[int]:
        if self.session is not None:
            raise RuntimeError("TraceeRunner is already running")

        tracee_binary = self._resolve_binary()
        commands = build_tracee_commands(tracee_binary, self.extra_args)
        session = TraceeAgentSession(commands)
        session.__enter__()
        self.session = session
        self.command_used = list(session.command_used or [])
        self.tracee_binary = Path(tracee_binary).resolve()
        self.programs = []
        if DEFAULT_STARTUP_SETTLE_S > 0.0:
            time.sleep(DEFAULT_STARTUP_SETTLE_S)
        return []

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError("TraceeRunner is not running")
        if not self.workload_spec:
            raise RuntimeError("TraceeRunner run_workload() requires workload_spec")
        return run_tracee_workload(self.workload_spec, max(1, int(round(seconds))))

    def run_workload_spec(self, workload_spec: Mapping[str, object], seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError("TraceeRunner is not running")
        return run_tracee_workload(workload_spec, max(1, int(round(seconds))))

    def stop(self) -> None:
        if self.session is None: return
        session, self.session = self.session, None
        snapshot = session.collector_snapshot()
        process = session.process
        session.close()
        self.process_output = {"returncode": None if process is None else process.returncode,
                               "stdout_tail": "\n".join(snapshot.get("stdout_tail") or []),
                               "stderr_tail": "\n".join(snapshot.get("stderr_tail") or [])}
