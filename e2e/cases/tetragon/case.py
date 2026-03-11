#!/usr/bin/env python3
from __future__ import annotations

import argparse
import ctypes
import ctypes.util
import json
import os
import platform
import statistics
import sys
import tempfile
import threading
import time
from collections import deque
from contextlib import ExitStack
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from e2e.common import (  # noqa: E402
    ROOT_DIR,
    chown_to_invoking_user,
    ensure_root,
    resolve_bpftool_binary,
    run_command,
    run_json_command,
    tail_text,
    which,
    write_json,
    write_text,
)
from e2e.common.agent import find_bpf_programs, start_agent, stop_agent, wait_healthy  # noqa: E402
from e2e.common.metrics import compute_delta, sample_bpf_stats, sample_cpu_usage, sample_total_cpu_usage  # noqa: E402
from e2e.common.recompile import apply_recompile, scan_programs  # noqa: E402
from e2e.common.workload import (  # noqa: E402
    WorkloadResult,
    run_connect_storm,
    run_exec_storm,
    run_file_io,
    run_open_storm,
)


DEFAULT_SETUP_SCRIPT = Path(__file__).with_name("setup.sh")
DEFAULT_GUEST_SCRIPT = Path(__file__).with_name("guest_smoke.sh")
DEFAULT_OUTPUT_JSON = ROOT_DIR / "e2e" / "results" / "tetragon-real-e2e.json"
DEFAULT_OUTPUT_MD = ROOT_DIR / "e2e" / "results" / "tetragon-real-e2e.md"
DEFAULT_EXECVE_OBJECT = ROOT_DIR / "corpus" / "build" / "tetragon" / "bpf_execve_event.bpf.o"
DEFAULT_KPROBE_OBJECT = ROOT_DIR / "corpus" / "build" / "tetragon" / "bpf_generic_kprobe.bpf.o"
DEFAULT_SCANNER = ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"
DEFAULT_RUNNER = ROOT_DIR / "micro" / "build" / "runner" / "micro_exec"
DEFAULT_BPFTOOL = "/usr/local/sbin/bpftool"
DEFAULT_DURATION_S = 30
DEFAULT_SMOKE_DURATION_S = 8
DEFAULT_LOAD_TIMEOUT_S = 20
DEFAULT_TIMEOUT_S = 180
BPF_STATS_RUN_TIME = 0
BPF_TAG_SIZE = 8
BPF_OBJ_NAME_LEN = 16


@dataclass(frozen=True, slots=True)
class WorkloadSpec:
    name: str
    kind: str
    metric: str
    description: str
    value: int = 0


@dataclass(frozen=True, slots=True)
class ManualAttachSpec:
    target_id: str
    object_path: Path
    program_name: str
    section_name: str
    program_type: str
    attach_kind: str
    attach_target: str


DEFAULT_WORKLOADS = (
    WorkloadSpec(
        name="stress_exec",
        kind="exec_storm",
        metric="bogo-ops/s",
        description="stress-ng execve workload",
        value=2,
    ),
    WorkloadSpec(
        name="file_io",
        kind="file_io",
        metric="ops/s",
        description="fio or dd file workload",
    ),
    WorkloadSpec(
        name="open_storm",
        kind="open_storm",
        metric="bogo-ops/s",
        description="stress-ng open workload",
        value=2,
    ),
    WorkloadSpec(
        name="connect_storm",
        kind="connect_storm",
        metric="ops/s",
        description="rapid loopback TCP connect storm",
    ),
)


def relpath(path: Path) -> str:
    try:
        return path.resolve().relative_to(ROOT_DIR).as_posix()
    except ValueError:
        return str(path.resolve())


def bpftool_binary() -> str:
    try:
        return resolve_bpftool_binary()
    except RuntimeError:
        if Path(DEFAULT_BPFTOOL).exists():
            return DEFAULT_BPFTOOL
        return "bpftool"


def decode_c_string(value: bytes | None) -> str:
    return value.decode("utf-8", "replace") if value else ""


def libbpf_error_string(err: int) -> str:
    code = -err if err < 0 else err
    try:
        return os.strerror(code)
    except ValueError:
        return f"error {err}"


class BpfProgInfo(ctypes.Structure):
    _fields_ = [
        ("type", ctypes.c_uint32),
        ("id", ctypes.c_uint32),
        ("tag", ctypes.c_ubyte * BPF_TAG_SIZE),
        ("jited_prog_len", ctypes.c_uint32),
        ("xlated_prog_len", ctypes.c_uint32),
        ("jited_prog_insns", ctypes.c_uint64),
        ("xlated_prog_insns", ctypes.c_uint64),
        ("load_time", ctypes.c_uint64),
        ("created_by_uid", ctypes.c_uint32),
        ("nr_map_ids", ctypes.c_uint32),
        ("map_ids", ctypes.c_uint64),
        ("name", ctypes.c_char * BPF_OBJ_NAME_LEN),
        ("ifindex", ctypes.c_uint32),
        ("gpl_compatible", ctypes.c_uint32, 1),
        ("_bitfield_pad", ctypes.c_uint32, 31),
        ("netns_dev", ctypes.c_uint64),
        ("netns_ino", ctypes.c_uint64),
        ("nr_jited_ksyms", ctypes.c_uint32),
        ("nr_jited_func_lens", ctypes.c_uint32),
        ("jited_ksyms", ctypes.c_uint64),
        ("jited_func_lens", ctypes.c_uint64),
        ("btf_id", ctypes.c_uint32),
        ("func_info_rec_size", ctypes.c_uint32),
        ("func_info", ctypes.c_uint64),
        ("nr_func_info", ctypes.c_uint32),
        ("nr_line_info", ctypes.c_uint32),
        ("line_info", ctypes.c_uint64),
        ("jited_line_info", ctypes.c_uint64),
        ("nr_jited_line_info", ctypes.c_uint32),
        ("line_info_rec_size", ctypes.c_uint32),
        ("jited_line_info_rec_size", ctypes.c_uint32),
        ("nr_prog_tags", ctypes.c_uint32),
        ("prog_tags", ctypes.c_uint64),
        ("run_time_ns", ctypes.c_uint64),
        ("run_cnt", ctypes.c_uint64),
        ("recursion_misses", ctypes.c_uint64),
        ("verified_insns", ctypes.c_uint32),
        ("attach_btf_obj_id", ctypes.c_uint32),
        ("attach_btf_id", ctypes.c_uint32),
    ]


class Libbpf:
    def __init__(self) -> None:
        path = ctypes.util.find_library("bpf") or "libbpf.so.1"
        self.lib = ctypes.CDLL(path, use_errno=True)
        self.lib.bpf_object__open_file.argtypes = [ctypes.c_char_p, ctypes.c_void_p]
        self.lib.bpf_object__open_file.restype = ctypes.c_void_p
        self.lib.bpf_object__load.argtypes = [ctypes.c_void_p]
        self.lib.bpf_object__load.restype = ctypes.c_int
        self.lib.bpf_object__close.argtypes = [ctypes.c_void_p]
        self.lib.bpf_object__close.restype = None
        self.lib.bpf_object__find_program_by_name.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
        self.lib.bpf_object__find_program_by_name.restype = ctypes.c_void_p
        self.lib.bpf_program__fd.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__fd.restype = ctypes.c_int
        self.lib.bpf_program__attach_tracepoint.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_char_p]
        self.lib.bpf_program__attach_tracepoint.restype = ctypes.c_void_p
        self.lib.bpf_program__attach_kprobe.argtypes = [ctypes.c_void_p, ctypes.c_bool, ctypes.c_char_p]
        self.lib.bpf_program__attach_kprobe.restype = ctypes.c_void_p
        self.lib.bpf_link__destroy.argtypes = [ctypes.c_void_p]
        self.lib.bpf_link__destroy.restype = ctypes.c_int
        self.lib.libbpf_get_error.argtypes = [ctypes.c_void_p]
        self.lib.libbpf_get_error.restype = ctypes.c_long
        self.lib.bpf_enable_stats.argtypes = [ctypes.c_int]
        self.lib.bpf_enable_stats.restype = ctypes.c_int
        self.lib.bpf_prog_get_info_by_fd.argtypes = [
            ctypes.c_int,
            ctypes.POINTER(BpfProgInfo),
            ctypes.POINTER(ctypes.c_uint32),
        ]
        self.lib.bpf_prog_get_info_by_fd.restype = ctypes.c_int

    def pointer_error(self, ptr: ctypes.c_void_p | int | None) -> int:
        return int(self.lib.libbpf_get_error(ctypes.c_void_p(ptr or 0)))

    def get_prog_info(self, prog_fd: int) -> BpfProgInfo:
        info = BpfProgInfo()
        info_len = ctypes.c_uint32(ctypes.sizeof(info))
        rc = self.lib.bpf_prog_get_info_by_fd(prog_fd, ctypes.byref(info), ctypes.byref(info_len))
        if rc != 0:
            err = ctypes.get_errno()
            raise RuntimeError(f"bpf_prog_get_info_by_fd failed: {os.strerror(err)} (errno={err})")
        return info


class RuntimeStatsHandle:
    def __init__(self, libbpf: Libbpf) -> None:
        self.libbpf = libbpf
        self.fd = -1

    def __enter__(self) -> "RuntimeStatsHandle":
        fd = int(self.libbpf.lib.bpf_enable_stats(BPF_STATS_RUN_TIME))
        if fd < 0:
            err = ctypes.get_errno()
            raise RuntimeError(f"bpf_enable_stats failed: {os.strerror(err)} (errno={err})")
        self.fd = fd
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        if self.fd >= 0:
            os.close(self.fd)
            self.fd = -1


class LoadedBpfObject:
    def __init__(self, libbpf: Libbpf, object_path: Path) -> None:
        self.libbpf = libbpf
        self.object_path = object_path
        self.object_ptr: int | None = None
        self._program_cache: dict[str, ctypes.c_void_p] = {}

    def __enter__(self) -> "LoadedBpfObject":
        object_ptr = self.libbpf.lib.bpf_object__open_file(str(self.object_path).encode(), None)
        open_error = self.libbpf.pointer_error(object_ptr)
        if open_error != 0:
            raise RuntimeError(f"bpf_object__open_file failed: {libbpf_error_string(open_error)}")
        self.object_ptr = object_ptr
        rc = self.libbpf.lib.bpf_object__load(self.object_ptr)
        if rc != 0:
            raise RuntimeError(f"bpf_object__load failed: {libbpf_error_string(rc)}")
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        if self.object_ptr:
            self.libbpf.lib.bpf_object__close(self.object_ptr)
            self.object_ptr = None
        self._program_cache.clear()

    def find_program(self, program_name: str) -> ctypes.c_void_p:
        cached = self._program_cache.get(program_name)
        if cached is not None:
            return cached
        assert self.object_ptr is not None
        prog_ptr = self.libbpf.lib.bpf_object__find_program_by_name(self.object_ptr, program_name.encode())
        if not prog_ptr:
            raise RuntimeError(f"program not found in {self.object_path.name}: {program_name}")
        wrapped = ctypes.c_void_p(prog_ptr)
        self._program_cache[program_name] = wrapped
        return wrapped

    def program_fd(self, program_name: str) -> int:
        prog_ptr = self.find_program(program_name)
        prog_fd = int(self.libbpf.lib.bpf_program__fd(prog_ptr))
        if prog_fd < 0:
            raise RuntimeError(f"bpf_program__fd failed for {program_name}")
        return prog_fd

    def attach(self, spec: ManualAttachSpec) -> ctypes.c_void_p:
        prog_ptr = self.find_program(spec.program_name)
        if spec.attach_kind == "tracepoint":
            subsystem, event = spec.attach_target.split("/", 1)
            link_ptr = self.libbpf.lib.bpf_program__attach_tracepoint(
                prog_ptr,
                subsystem.encode(),
                event.encode(),
            )
        elif spec.attach_kind == "kprobe":
            link_ptr = self.libbpf.lib.bpf_program__attach_kprobe(
                prog_ptr,
                False,
                spec.attach_target.encode(),
            )
        else:
            raise RuntimeError(f"unsupported attach kind {spec.attach_kind}")
        attach_error = self.libbpf.pointer_error(link_ptr)
        if attach_error != 0:
            raise RuntimeError(f"{spec.program_name} attach failed: {libbpf_error_string(attach_error)}")
        return ctypes.c_void_p(link_ptr)


class ManualProgramSession:
    def __init__(self, libbpf: Libbpf, spec: ManualAttachSpec) -> None:
        self.libbpf = libbpf
        self.spec = spec
        self.loaded: LoadedBpfObject | None = None
        self.link_ptr: ctypes.c_void_p | None = None
        self.prog_fd: int | None = None
        self.prog_id: int | None = None

    def __enter__(self) -> "ManualProgramSession":
        try:
            self.loaded = LoadedBpfObject(self.libbpf, self.spec.object_path).__enter__()
            self.prog_fd = self.loaded.program_fd(self.spec.program_name)
            self.link_ptr = self.loaded.attach(self.spec)
            info = self.libbpf.get_prog_info(self.prog_fd)
            self.prog_id = int(info.id)
            return self
        except Exception:
            self.__exit__(None, None, None)
            raise

    def metadata(self) -> dict[str, object]:
        return {
            "id": int(self.prog_id or 0),
            "name": self.spec.program_name,
            "type": self.spec.program_type,
            "section_name": self.spec.section_name,
            "attach_kind": self.spec.attach_kind,
            "attach_target": self.spec.attach_target,
            "target_id": self.spec.target_id,
            "object_path": relpath(self.spec.object_path),
        }

    def __exit__(self, exc_type, exc, tb) -> None:
        if self.link_ptr:
            self.libbpf.lib.bpf_link__destroy(self.link_ptr)
            self.link_ptr = None
        if self.loaded is not None:
            self.loaded.__exit__(exc_type, exc, tb)
            self.loaded = None


class ProcessOutputCollector:
    def __init__(self) -> None:
        self._lock = threading.Lock()
        self.stdout_tail: deque[str] = deque(maxlen=200)
        self.stderr_tail: deque[str] = deque(maxlen=200)

    def consume_stdout(self, pipe: Any) -> None:
        for raw_line in iter(pipe.readline, ""):
            with self._lock:
                self.stdout_tail.append(raw_line.rstrip())
        pipe.close()

    def consume_stderr(self, pipe: Any) -> None:
        for raw_line in iter(pipe.readline, ""):
            with self._lock:
                self.stderr_tail.append(raw_line.rstrip())
        pipe.close()

    def snapshot(self) -> dict[str, object]:
        with self._lock:
            return {
                "stdout_tail": list(self.stdout_tail),
                "stderr_tail": list(self.stderr_tail),
            }


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

        healthy = wait_healthy(
            self.process,
            self.load_timeout,
            lambda: bool([item for item in find_bpf_programs(self.process.pid or 0) if int(item.get("id", -1)) not in before_ids]),
        )
        if not healthy:
            snapshot = self.collector.snapshot()
            details = tail_text(
                "\n".join((snapshot.get("stderr_tail") or []) + (snapshot.get("stdout_tail") or [])),
                max_lines=40,
                max_chars=8000,
            )
            self.close()
            raise RuntimeError(f"Tetragon failed to become healthy: {details}")

        self.programs = [
            item
            for item in find_bpf_programs(self.process.pid or 0)
            if int(item.get("id", -1)) not in before_ids
        ]
        if not self.programs:
            self.close()
            raise RuntimeError("Tetragon became healthy but no new BPF programs were found")
        return self

    @property
    def pid(self) -> int | None:
        return None if self.process is None else self.process.pid

    def collector_snapshot(self) -> dict[str, object]:
        return self.collector.snapshot()

    def close(self) -> None:
        if self.process is not None:
            stop_agent(self.process, timeout=8)
            self.process = None
        if self.stdout_thread is not None:
            self.stdout_thread.join(timeout=2.0)
            self.stdout_thread = None
        if self.stderr_thread is not None:
            self.stderr_thread.join(timeout=2.0)
            self.stderr_thread = None

    def __exit__(self, exc_type, exc, tb) -> None:
        self.close()


def build_manual_targets(execve_object: Path, kprobe_object: Path) -> tuple[ManualAttachSpec, ...]:
    return (
        ManualAttachSpec(
            target_id="execve-tracepoint",
            object_path=execve_object,
            program_name="event_execve",
            section_name="tracepoint/sys_execve",
            program_type="tracepoint",
            attach_kind="tracepoint",
            attach_target="syscalls/sys_enter_execve",
        ),
        ManualAttachSpec(
            target_id="open-kprobe",
            object_path=kprobe_object,
            program_name="generic_kprobe_event",
            section_name="kprobe/generic_kprobe",
            program_type="kprobe",
            attach_kind="kprobe",
            attach_target="security_file_open",
        ),
        ManualAttachSpec(
            target_id="connect-kprobe",
            object_path=kprobe_object,
            program_name="generic_kprobe_event",
            section_name="kprobe/generic_kprobe",
            program_type="kprobe",
            attach_kind="kprobe",
            attach_target="security_socket_connect",
        ),
    )


def write_tetragon_policy(path: Path) -> None:
    policy = """
apiVersion: cilium.io/v1alpha1
kind: TracingPolicy
metadata:
  name: bpf-benchmark-tetragon-e2e
spec:
  tracepoints:
    - subsystem: syscalls
      event: sys_enter_execve
  kprobes:
    - call: security_bprm_check
      syscall: false
    - call: security_file_open
      syscall: false
    - call: security_socket_connect
      syscall: false
""".strip()
    path.write_text(policy + "\n")


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
    - call: security_socket_connect
      syscall: false
""".strip()
        + "\n"
    )
    return [tracepoint_path, kprobe_path]


def current_prog_ids() -> list[int]:
    payload = run_json_command([bpftool_binary(), "-j", "-p", "prog", "show"], timeout=30)
    if not isinstance(payload, list):
        return []
    return [int(record["id"]) for record in payload if isinstance(record, dict) and "id" in record]


def git_sha() -> str:
    completed = run_command(["git", "rev-parse", "HEAD"], check=False, timeout=15)
    return completed.stdout.strip() if completed.returncode == 0 else "unknown"


def host_metadata() -> dict[str, object]:
    return {
        "hostname": platform.node(),
        "platform": platform.platform(),
        "kernel": platform.release(),
        "python": sys.version.split()[0],
        "git_sha": git_sha(),
    }


def summarize_numbers(values: Sequence[float | int | None]) -> dict[str, float | int | None]:
    filtered = [float(value) for value in values if value is not None]
    if not filtered:
        return {"count": 0, "mean": None, "median": None, "min": None, "max": None}
    return {
        "count": len(filtered),
        "mean": statistics.mean(filtered),
        "median": statistics.median(filtered),
        "min": min(filtered),
        "max": max(filtered),
    }


def percent_delta(before: object, after: object) -> float | None:
    if before in (None, 0) or after is None:
        return None
    return ((float(after) - float(before)) / float(before)) * 100.0


def speedup_ratio(before_avg_ns: object, after_avg_ns: object) -> float | None:
    if before_avg_ns is None or after_avg_ns is None:
        return None
    if float(after_avg_ns) <= 0:
        return None
    return float(before_avg_ns) / float(after_avg_ns)


def ensure_artifacts(runner_binary: Path, scanner_binary: Path) -> None:
    if not runner_binary.exists():
        run_command(["make", "-C", "micro", "micro_exec", "programs"], timeout=1800)
    if not scanner_binary.exists():
        run_command(
            ["cmake", "-S", "scanner", "-B", "scanner/build", "-DCMAKE_BUILD_TYPE=Release"],
            timeout=600,
        )
        run_command(
            ["cmake", "--build", "scanner/build", "--target", "bpf-jit-scanner", "-j"],
            timeout=1800,
        )


def run_setup_script(setup_script: Path) -> dict[str, object]:
    completed = run_command(["bash", str(setup_script)], check=False, timeout=1800)
    result = {
        "returncode": completed.returncode,
        "tetragon_binary": None,
        "tetra_binary": None,
        "stdout_tail": tail_text(completed.stdout or "", max_lines=60, max_chars=12000),
        "stderr_tail": tail_text(completed.stderr or "", max_lines=60, max_chars=12000),
    }
    for line in (completed.stdout or "").splitlines():
        if line.startswith("TETRAGON_BINARY="):
            value = line.split("=", 1)[1].strip()
            result["tetragon_binary"] = value or None
        if line.startswith("TETRA_BINARY="):
            value = line.split("=", 1)[1].strip()
            result["tetra_binary"] = value or None
    return result


def resolve_tetragon_binary(explicit: str | None, setup_result: Mapping[str, object]) -> str | None:
    if explicit:
        candidate = Path(explicit).resolve()
        if candidate.exists():
            return str(candidate)
    scripted = str(setup_result.get("tetragon_binary") or "").strip()
    if scripted and Path(scripted).exists():
        return scripted
    resolved = which("tetragon")
    if resolved:
        return resolved
    return None


def run_workload(spec: WorkloadSpec, duration_s: int) -> WorkloadResult:
    if spec.kind == "exec_storm":
        return run_exec_storm(duration_s, spec.value or 2)
    if spec.kind == "file_io":
        return run_file_io(duration_s)
    if spec.kind == "open_storm":
        return run_open_storm(duration_s)
    if spec.kind == "connect_storm":
        return run_connect_storm(duration_s)
    raise RuntimeError(f"unsupported workload kind: {spec.kind}")


def measure_workload(
    workload_spec: WorkloadSpec,
    duration_s: int,
    prog_ids: list[int],
    *,
    agent_pid: int | None,
) -> dict[str, object]:
    before_bpf = sample_bpf_stats(prog_ids)
    cpu_holder: dict[int, dict[str, float]] = {}
    system_cpu_holder: dict[str, float] = {}
    threads: list[threading.Thread] = []

    if agent_pid is not None:
        cpu_thread = threading.Thread(
            target=lambda: cpu_holder.update(sample_cpu_usage([agent_pid], duration_s)),
            daemon=True,
        )
        cpu_thread.start()
        threads.append(cpu_thread)

    system_thread = threading.Thread(
        target=lambda: system_cpu_holder.update(sample_total_cpu_usage(duration_s)),
        daemon=True,
    )
    system_thread.start()
    threads.append(system_thread)

    workload_result = run_workload(workload_spec, duration_s)

    for thread in threads:
        thread.join()

    after_bpf = sample_bpf_stats(prog_ids)
    bpf_delta = compute_delta(before_bpf, after_bpf)
    total_events = int((bpf_delta.get("summary") or {}).get("total_events", 0) or 0)
    agent_cpu = cpu_holder.get(agent_pid or -1) if agent_pid is not None else None
    agent_total = None
    if agent_cpu is not None:
        agent_total = float(agent_cpu["user_pct"]) + float(agent_cpu["sys_pct"])

    return {
        "name": workload_spec.name,
        "kind": workload_spec.kind,
        "metric": workload_spec.metric,
        "description": workload_spec.description,
        "app_throughput": workload_result.ops_per_sec,
        "ops_total": workload_result.ops_total,
        "ops_per_sec": workload_result.ops_per_sec,
        "duration_s": workload_result.duration_s,
        "events_total": total_events,
        "events_per_sec": (total_events / workload_result.duration_s) if workload_result.duration_s > 0 else None,
        "agent_cpu": {
            "user_pct": None if agent_cpu is None else agent_cpu["user_pct"],
            "sys_pct": None if agent_cpu is None else agent_cpu["sys_pct"],
            "total_pct": agent_total,
        },
        "system_cpu": system_cpu_holder,
        "bpf": bpf_delta,
        "stdout_tail": workload_result.stdout,
        "stderr_tail": workload_result.stderr,
    }


def summarize_phase(workloads: Sequence[Mapping[str, object]]) -> dict[str, object]:
    return {
        "app_throughput": summarize_numbers([record.get("app_throughput") for record in workloads]),
        "events_per_sec": summarize_numbers([record.get("events_per_sec") for record in workloads]),
        "agent_cpu_total_pct": summarize_numbers(
            [
                ((record.get("agent_cpu") or {}).get("total_pct") if isinstance(record.get("agent_cpu"), Mapping) else None)
                for record in workloads
            ]
        ),
        "system_cpu_busy_pct": summarize_numbers(
            [
                ((record.get("system_cpu") or {}).get("busy_pct") if isinstance(record.get("system_cpu"), Mapping) else None)
                for record in workloads
            ]
        ),
        "bpf_avg_ns_per_run": summarize_numbers(
            [
                ((record.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run"))
                for record in workloads
            ]
        ),
    }


def run_phase(
    workloads: Sequence[WorkloadSpec],
    duration_s: int,
    prog_ids: list[int],
    *,
    agent_pid: int | None,
) -> dict[str, object]:
    records = [measure_workload(spec, duration_s, prog_ids, agent_pid=agent_pid) for spec in workloads]
    return {"workloads": records, "summary": summarize_phase(records)}


def aggregate_programs(phase: Mapping[str, object]) -> dict[str, dict[str, object]]:
    aggregated: dict[str, dict[str, object]] = {}
    for workload in phase.get("workloads") or []:
        programs = ((workload.get("bpf") or {}).get("programs") or {})
        for prog_id, record in programs.items():
            key = str(prog_id)
            target = aggregated.setdefault(
                key,
                {
                    "id": int(record.get("id", prog_id)),
                    "name": str(record.get("name", f"id-{prog_id}")),
                    "type": str(record.get("type", "")),
                    "run_cnt_delta": 0,
                    "run_time_ns_delta": 0,
                },
            )
            target["run_cnt_delta"] += int(record.get("run_cnt_delta", 0) or 0)
            target["run_time_ns_delta"] += int(record.get("run_time_ns_delta", 0) or 0)
    for record in aggregated.values():
        run_cnt = int(record["run_cnt_delta"])
        run_time = int(record["run_time_ns_delta"])
        record["avg_ns_per_run"] = (run_time / run_cnt) if run_cnt > 0 else None
    return aggregated


def build_program_summary(
    scan_results: Mapping[int, Mapping[str, object]],
    baseline: Mapping[str, object],
    post: Mapping[str, object] | None,
) -> list[dict[str, object]]:
    baseline_programs = aggregate_programs(baseline)
    post_programs = aggregate_programs(post or {})
    rows: list[dict[str, object]] = []
    for prog_id in sorted(set(baseline_programs) | set(post_programs), key=int):
        before = baseline_programs.get(prog_id, {})
        after = post_programs.get(prog_id, {})
        scan = scan_results.get(int(prog_id), {}) if isinstance(scan_results, dict) else {}
        sites = ((scan.get("sites") or {}).get("total_sites"))
        stock_avg = before.get("avg_ns_per_run")
        rejit_avg = after.get("avg_ns_per_run")
        rows.append(
            {
                "id": int(prog_id),
                "name": str(after.get("name") or before.get("name") or f"id-{prog_id}"),
                "type": str(after.get("type") or before.get("type") or ""),
                "sites": int(sites or 0),
                "stock_avg_ns": stock_avg,
                "rejit_avg_ns": rejit_avg,
                "speedup": speedup_ratio(stock_avg, rejit_avg),
                "stock_events": before.get("run_cnt_delta"),
                "rejit_events": after.get("run_cnt_delta"),
            }
        )
    return rows


def compare_phases(baseline: Mapping[str, object], post: Mapping[str, object] | None) -> dict[str, object]:
    if not post:
        return {"comparable": False, "reason": "recompile did not apply successfully"}

    baseline_by_name = {record["name"]: record for record in baseline.get("workloads") or []}
    post_by_name = {record["name"]: record for record in post.get("workloads") or []}
    workload_rows: list[dict[str, object]] = []
    for name in sorted(set(baseline_by_name) & set(post_by_name)):
        before = baseline_by_name[name]
        after = post_by_name[name]
        workload_rows.append(
            {
                "name": name,
                "baseline_ops_per_sec": before.get("ops_per_sec"),
                "post_ops_per_sec": after.get("ops_per_sec"),
                "app_throughput_delta_pct": percent_delta(before.get("ops_per_sec"), after.get("ops_per_sec")),
                "baseline_events_per_sec": before.get("events_per_sec"),
                "post_events_per_sec": after.get("events_per_sec"),
                "events_per_sec_delta_pct": percent_delta(before.get("events_per_sec"), after.get("events_per_sec")),
                "baseline_agent_cpu_pct": ((before.get("agent_cpu") or {}).get("total_pct")),
                "post_agent_cpu_pct": ((after.get("agent_cpu") or {}).get("total_pct")),
                "agent_cpu_delta_pct": percent_delta(
                    ((before.get("agent_cpu") or {}).get("total_pct")),
                    ((after.get("agent_cpu") or {}).get("total_pct")),
                ),
                "bpf_avg_ns_delta_pct": percent_delta(
                    ((before.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run")),
                    ((after.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run")),
                ),
            }
        )
    return {"comparable": True, "workloads": workload_rows}


def build_markdown(payload: Mapping[str, object]) -> str:
    baseline = payload["baseline"]
    post = payload.get("post_rejit")
    comparison = payload.get("comparison") or {}
    lines = [
        "# Tetragon Real End-to-End Benchmark",
        "",
        f"- Generated: {payload['generated_at']}",
        f"- Mode: `{payload['mode']}`",
        f"- Smoke: `{payload['smoke']}`",
        f"- Duration per workload: `{payload['duration_s']}s`",
        f"- Tetragon binary: `{payload.get('tetragon_binary') or 'unavailable'}`",
        "",
        "## Setup",
        "",
        f"- Setup return code: `{payload['setup']['returncode']}`",
        f"- Setup tetragon binary: `{payload['setup'].get('tetragon_binary') or 'missing'}`",
    ]
    fallback_reason = payload.get("fallback_reason")
    if fallback_reason:
        lines.append(f"- Fallback reason: `{fallback_reason}`")
    lines.extend(
        [
            "",
            "## Baseline",
            "",
            f"- Application throughput mean: `{baseline['summary']['app_throughput']['mean']}` ops/s",
            f"- Events/s mean: `{baseline['summary']['events_per_sec']['mean']}`",
            f"- Agent CPU mean: `{baseline['summary']['agent_cpu_total_pct']['mean']}`%",
            f"- BPF avg ns mean: `{baseline['summary']['bpf_avg_ns_per_run']['mean']}`",
            "",
        ]
    )
    for workload in baseline["workloads"]:
        lines.append(
            f"- {workload['name']}: ops/s={workload.get('ops_per_sec')}, "
            f"events/s={workload.get('events_per_sec')}, "
            f"agent_cpu={((workload.get('agent_cpu') or {}).get('total_pct'))}, "
            f"bpf_avg_ns={((workload.get('bpf') or {}).get('summary', {}).get('avg_ns_per_run'))}"
        )

    lines.extend(
        [
            "",
            "## Recompile",
            "",
            f"- Applied programs: `{payload['recompile_summary']['applied_programs']}` / `{payload['recompile_summary']['requested_programs']}`",
            f"- Applied successfully: `{payload['recompile_summary']['applied']}`",
            "",
            "## Per-Program",
            "",
        ]
    )
    for program in payload.get("programs") or []:
        lines.append(
            f"- {program['name']} ({program['type']}): sites={program['sites']}, "
            f"stock_avg_ns={program['stock_avg_ns']}, rejit_avg_ns={program['rejit_avg_ns']}, "
            f"speedup={program['speedup']}"
        )

    if post:
        lines.extend(
            [
                "",
                "## Post-ReJIT",
                "",
                f"- Application throughput mean: `{post['summary']['app_throughput']['mean']}` ops/s",
                f"- Events/s mean: `{post['summary']['events_per_sec']['mean']}`",
                f"- Agent CPU mean: `{post['summary']['agent_cpu_total_pct']['mean']}`%",
                f"- BPF avg ns mean: `{post['summary']['bpf_avg_ns_per_run']['mean']}`",
                "",
            ]
        )
        for workload in post["workloads"]:
            lines.append(
                f"- {workload['name']}: ops/s={workload.get('ops_per_sec')}, "
                f"events/s={workload.get('events_per_sec')}, "
                f"agent_cpu={((workload.get('agent_cpu') or {}).get('total_pct'))}, "
                f"bpf_avg_ns={((workload.get('bpf') or {}).get('summary', {}).get('avg_ns_per_run'))}"
            )

    lines.extend(["", "## Comparison", ""])
    if comparison.get("comparable"):
        for workload in comparison.get("workloads", []):
            lines.append(
                f"- {workload['name']}: baseline_ops/s={workload.get('baseline_ops_per_sec')}, "
                f"post_ops/s={workload.get('post_ops_per_sec')}, "
                f"app_delta={workload.get('app_throughput_delta_pct')}%, "
                f"baseline_cpu={workload.get('baseline_agent_cpu_pct')}, "
                f"post_cpu={workload.get('post_agent_cpu_pct')}, "
                f"cpu_delta={workload.get('agent_cpu_delta_pct')}%"
            )
    else:
        lines.append(f"- Comparable: `False`")
        lines.append(f"- Reason: `{comparison.get('reason', 'unknown')}`")

    limitations = payload.get("limitations") or []
    if limitations:
        lines.extend(["", "## Limitations", ""])
        for limitation in limitations:
            lines.append(f"- {limitation}")
    lines.append("")
    return "\n".join(lines)


def manual_fallback_payload(
    *,
    libbpf: Libbpf,
    scanner_binary: Path,
    execve_object: Path,
    kprobe_object: Path,
    duration_s: int,
    smoke: bool,
    setup_result: Mapping[str, object],
    limitations: list[str],
) -> dict[str, object]:
    targets = build_manual_targets(execve_object, kprobe_object)
    opened: list[ManualProgramSession] = []
    manual_failures: list[dict[str, str]] = []
    with ExitStack() as stack:
        for spec in targets:
            try:
                opened.append(stack.enter_context(ManualProgramSession(libbpf, spec)))
            except Exception as exc:
                manual_failures.append({"target_id": spec.target_id, "error": str(exc)})
        if not opened:
            raise RuntimeError(f"manual fallback failed to load any targets: {manual_failures}")

        prog_ids = [int(session.prog_id or 0) for session in opened if session.prog_id]
        programs = [session.metadata() for session in opened]
        baseline = run_phase(DEFAULT_WORKLOADS, duration_s, prog_ids, agent_pid=os.getpid())
        scan_results = scan_programs(prog_ids, scanner_binary)
        recompile_results = apply_recompile(prog_ids, scanner_binary)
        applied = sum(1 for record in recompile_results.values() if record.get("applied"))
        post = run_phase(DEFAULT_WORKLOADS, duration_s, prog_ids, agent_pid=os.getpid()) if applied > 0 else None

    if manual_failures:
        limitations.append(f"Some manual fallback targets failed to load: {manual_failures}")
    limitations.append(
        "events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters."
    )
    limitations.append(
        "Manual fallback uses directly loaded Tetragon BPF objects; agent CPU therefore reflects the benchmark controller process rather than a real Tetragon daemon."
    )
    if applied == 0:
        limitations.append("BPF_PROG_JIT_RECOMPILE did not apply to any manual-fallback program; post-ReJIT measurement was skipped.")

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "mode": "manual_fallback",
        "smoke": smoke,
        "duration_s": duration_s,
        "tetragon_binary": None,
        "setup": dict(setup_result),
        "host": host_metadata(),
        "tetragon_programs": programs,
        "manual_failures": manual_failures,
        "baseline": baseline,
        "scan_results": {str(key): value for key, value in scan_results.items()},
        "recompile_results": {str(key): value for key, value in recompile_results.items()},
        "recompile_summary": {
            "requested_programs": len(prog_ids),
            "applied_programs": applied,
            "applied": applied > 0,
            "errors": sorted({record.get("error", "") for record in recompile_results.values() if record.get("error")}),
        },
        "post_rejit": post,
        "programs": build_program_summary(scan_results, baseline, post),
        "comparison": compare_phases(baseline, post),
        "limitations": limitations,
    }
    return payload


def daemon_payload(
    *,
    libbpf: Libbpf,
    scanner_binary: Path,
    tetragon_binary: str,
    duration_s: int,
    smoke: bool,
    load_timeout: int,
    setup_result: Mapping[str, object],
    limitations: list[str],
) -> dict[str, object]:
    with tempfile.TemporaryDirectory(prefix="tetragon-policy-") as tempdir:
        policy_dir = Path(tempdir)
        policy_paths = write_tetragon_policies(policy_dir)
        command = [tetragon_binary, "--tracing-policy-dir", str(policy_dir)]
        with TetragonAgentSession(command, load_timeout) as session:
            prog_ids = [int(program["id"]) for program in session.programs]
            baseline = run_phase(DEFAULT_WORKLOADS, duration_s, prog_ids, agent_pid=session.pid)
            scan_results = scan_programs(prog_ids, scanner_binary)
            recompile_results = apply_recompile(prog_ids, scanner_binary)
            applied = sum(1 for record in recompile_results.values() if record.get("applied"))
            limitations.append(
                "events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters."
            )
            if applied == 0:
                limitations.append("BPF_PROG_JIT_RECOMPILE did not apply to any Tetragon-owned program; post-ReJIT measurement was skipped.")
            post = run_phase(DEFAULT_WORKLOADS, duration_s, prog_ids, agent_pid=session.pid) if applied > 0 else None
            payload = {
                "generated_at": datetime.now(timezone.utc).isoformat(),
                "mode": "tetragon_daemon",
                "smoke": smoke,
                "duration_s": duration_s,
                "tetragon_binary": tetragon_binary,
                "setup": dict(setup_result),
                "host": host_metadata(),
                "tetragon_launch_command": command,
                "policy_dir": str(policy_dir),
                "policy_paths": [str(path) for path in policy_paths],
                "tetragon_programs": session.programs,
                "agent_logs": session.collector_snapshot(),
                "baseline": baseline,
                "scan_results": {str(key): value for key, value in scan_results.items()},
                "recompile_results": {str(key): value for key, value in recompile_results.items()},
                "recompile_summary": {
                    "requested_programs": len(prog_ids),
                    "applied_programs": applied,
                    "applied": applied > 0,
                    "errors": sorted({record.get("error", "") for record in recompile_results.values() if record.get("error")}),
                },
                "post_rejit": post,
                "programs": build_program_summary(scan_results, baseline, post),
                "comparison": compare_phases(baseline, post),
                "limitations": limitations,
            }
            return payload


def run_tetragon_case(args: argparse.Namespace) -> dict[str, object]:
    ensure_root([str(Path(sys.argv[0]).resolve()), *sys.argv[1:]])

    bpftool = str(Path(args.bpftool).resolve()) if Path(args.bpftool).exists() else str(args.bpftool)
    os.environ["BPFTOOL_BIN"] = bpftool
    if Path(bpftool).exists():
        os.environ["PATH"] = f"{Path(bpftool).parent}:{os.environ.get('PATH', '')}"

    duration_s = int(args.duration or (DEFAULT_SMOKE_DURATION_S if args.smoke else DEFAULT_DURATION_S))
    runner_binary = Path(args.runner).resolve()
    scanner_binary = Path(args.scanner).resolve()
    execve_object = Path(args.execve_object).resolve()
    kprobe_object = Path(args.kprobe_object).resolve()
    ensure_artifacts(runner_binary, scanner_binary)

    setup_result = {
        "returncode": 0,
        "tetragon_binary": None,
        "tetra_binary": None,
        "stdout_tail": "",
        "stderr_tail": "",
    }
    if not args.skip_setup:
        setup_result = run_setup_script(Path(args.setup_script).resolve())

    tetragon_binary = None if args.force_direct else resolve_tetragon_binary(args.tetragon_binary, setup_result)
    limitations: list[str] = []
    if setup_result["returncode"] != 0:
        limitations.append("Setup script returned non-zero; benchmark continued with whatever tools were already available.")

    libbpf = Libbpf()
    with RuntimeStatsHandle(libbpf):
        if tetragon_binary:
            try:
                return daemon_payload(
                    libbpf=libbpf,
                    scanner_binary=scanner_binary,
                    tetragon_binary=tetragon_binary,
                    duration_s=duration_s,
                    smoke=bool(args.smoke),
                    load_timeout=int(args.load_timeout),
                    setup_result=setup_result,
                    limitations=limitations,
                )
            except Exception as exc:
                limitations.append(f"Daemon mode failed and manual fallback was used instead: {exc}")
                return {
                    **manual_fallback_payload(
                        libbpf=libbpf,
                        scanner_binary=scanner_binary,
                        execve_object=execve_object,
                        kprobe_object=kprobe_object,
                        duration_s=duration_s,
                        smoke=bool(args.smoke),
                        setup_result=setup_result,
                        limitations=limitations,
                    ),
                    "fallback_reason": str(exc),
                }

        limitations.append("Tetragon binary was unavailable, so the benchmark used direct object loading as the fallback path.")
        return manual_fallback_payload(
            libbpf=libbpf,
            scanner_binary=scanner_binary,
            execve_object=execve_object,
            kprobe_object=kprobe_object,
            duration_s=duration_s,
            smoke=bool(args.smoke),
            setup_result=setup_result,
            limitations=limitations,
        )


def persist_results(payload: Mapping[str, object], output_json: Path, output_md: Path) -> None:
    write_json(output_json, payload)
    write_text(output_md, build_markdown(payload))
    chown_to_invoking_user(output_md)


def build_case_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run the Tetragon real end-to-end benchmark.")
    parser.add_argument("--setup-script", default=str(DEFAULT_SETUP_SCRIPT))
    parser.add_argument("--guest-script", default=str(DEFAULT_GUEST_SCRIPT))
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--tetragon-binary")
    parser.add_argument("--execve-object", default=str(DEFAULT_EXECVE_OBJECT))
    parser.add_argument("--kprobe-object", default=str(DEFAULT_KPROBE_OBJECT))
    parser.add_argument("--runner", default=str(DEFAULT_RUNNER))
    parser.add_argument("--scanner", default=str(DEFAULT_SCANNER))
    parser.add_argument("--bpftool", default=DEFAULT_BPFTOOL)
    parser.add_argument("--duration", type=int)
    parser.add_argument("--smoke", action="store_true")
    parser.add_argument("--force-direct", action="store_true")
    parser.add_argument("--load-timeout", type=int, default=DEFAULT_LOAD_TIMEOUT_S)
    parser.add_argument("--timeout", type=int, default=DEFAULT_TIMEOUT_S)
    parser.add_argument("--skip-setup", action="store_true")
    return parser


def main(argv: Sequence[str] | None = None) -> int:
    parser = build_case_parser()
    args = parser.parse_args(argv)
    payload = run_tetragon_case(args)
    persist_results(payload, Path(args.output_json).resolve(), Path(args.output_md).resolve())
    print(json.dumps(payload, indent=2, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
