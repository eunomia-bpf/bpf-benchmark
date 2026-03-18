#!/usr/bin/env python3
from __future__ import annotations

import argparse
import ctypes
import ctypes.util
import json
import os
import platform
import re
import shlex
import shutil
import socket
import subprocess
import sys
import tempfile
import textwrap
import threading
import time
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

from benchmark_catalog import ROOT_DIR, load_suite
from e2e.common.recompile import apply_recompile as apply_recompile_by_id, scan_programs as scan_programs_by_id
from orchestrator.environment import sudo_available
from run_corpus_perf import ensure_parent, markdown_table


DEFAULT_OUTPUT_JSON = ROOT_DIR / "docs" / "tmp" / "tetragon-e2e-results.json"
DEFAULT_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "tetragon-e2e-results.md"
DEFAULT_EXECVE_OBJECT = ROOT_DIR / "corpus" / "build" / "tetragon" / "bpf_execve_event.bpf.o"
DEFAULT_KPROBE_OBJECT = ROOT_DIR / "corpus" / "build" / "tetragon" / "bpf_generic_kprobe.bpf.o"
DEFAULT_BTF_PATH = Path("/sys/kernel/btf/vmlinux")
DEFAULT_SCANNER = ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"
SUPPORTED_TEST_RUN_TYPES = {
    "classifier",
    "cgroup_skb",
    "flow_dissector",
    "raw_tp",
    "raw_tracepoint",
    "sk_msg",
    "sk_skb",
    "socket",
    "tc",
    "xdp",
}
BPF_STATS_RUN_TIME = 0
BPF_TAG_SIZE = 8
BPF_OBJ_NAME_LEN = 16


def parse_args() -> argparse.Namespace:
    suite = load_suite()
    parser = argparse.ArgumentParser(
        description=(
            "Run an attach+trigger end-to-end benchmark for local Tetragon objects, "
            "and compare stock JIT against v5 BPF_PROG_JIT_RECOMPILE when available."
        )
    )
    parser.add_argument(
        "--output-json",
        default=str(DEFAULT_OUTPUT_JSON),
        help="Path for structured JSON results.",
    )
    parser.add_argument(
        "--output-md",
        default=str(DEFAULT_OUTPUT_MD),
        help="Path for markdown summary output.",
    )
    parser.add_argument(
        "--runner",
        default=str(suite.build.runner_binary),
        help="Path to the micro_exec runner.",
    )
    parser.add_argument(
        "--scanner",
        default=str(DEFAULT_SCANNER),
        help="Path to the scanner CLI used for v5 scan/apply.",
    )
    parser.add_argument(
        "--bpftool",
        default=str(suite.build.bpftool_binary),
        help="Path to the bpftool binary.",
    )
    parser.add_argument(
        "--tetragon-binary",
        help="Optional explicit Tetragon agent binary path.",
    )
    parser.add_argument(
        "--execve-object",
        default=str(DEFAULT_EXECVE_OBJECT),
        help="Path to the Tetragon execve object.",
    )
    parser.add_argument(
        "--kprobe-object",
        default=str(DEFAULT_KPROBE_OBJECT),
        help="Path to the Tetragon generic kprobe object.",
    )
    parser.add_argument(
        "--timeout",
        type=int,
        default=180,
        help="Per-command timeout in seconds.",
    )
    parser.add_argument(
        "--smoke",
        action="store_true",
        help="Run a reduced trigger mix for quick validation.",
    )
    parser.add_argument(
        "--force-direct",
        action="store_true",
        help="Skip Tetragon-daemon mode even if a Tetragon binary is present.",
    )
    return parser.parse_args()


def relpath(path: Path) -> str:
    try:
        return path.resolve().relative_to(ROOT_DIR).as_posix()
    except ValueError:
        return str(path.resolve())


def ensure_root() -> None:
    if os.geteuid() == 0:
        return
    if not sudo_available():
        raise SystemExit("passwordless sudo is required for Tetragon e2e benchmarking")
    os.execvp("sudo", ["sudo", "-n", sys.executable, str(Path(__file__).resolve()), *sys.argv[1:]])


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
        self.lib.bpf_object__next_program.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
        self.lib.bpf_object__next_program.restype = ctypes.c_void_p
        self.lib.bpf_object__find_program_by_name.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
        self.lib.bpf_object__find_program_by_name.restype = ctypes.c_void_p
        self.lib.bpf_program__name.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__name.restype = ctypes.c_char_p
        self.lib.bpf_program__section_name.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__section_name.restype = ctypes.c_char_p
        self.lib.bpf_program__fd.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__fd.restype = ctypes.c_int
        self.lib.bpf_program__attach_tracepoint.argtypes = [
            ctypes.c_void_p,
            ctypes.c_char_p,
            ctypes.c_char_p,
        ]
        self.lib.bpf_program__attach_tracepoint.restype = ctypes.c_void_p
        self.lib.bpf_program__attach_kprobe.argtypes = [
            ctypes.c_void_p,
            ctypes.c_bool,
            ctypes.c_char_p,
        ]
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
        self.lib.bpf_prog_get_fd_by_id.argtypes = [ctypes.c_uint]
        self.lib.bpf_prog_get_fd_by_id.restype = ctypes.c_int

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

    def prog_fd_by_id(self, prog_id: int) -> int:
        fd = int(self.lib.bpf_prog_get_fd_by_id(int(prog_id)))
        if fd < 0:
            err = ctypes.get_errno()
            raise RuntimeError(f"bpf_prog_get_fd_by_id({prog_id}) failed: {os.strerror(err)} (errno={err})")
        return fd


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


@dataclass(frozen=True)
class WorkloadSpec:
    name: str
    description: str


@dataclass(frozen=True)
class ManualAttachSpec:
    target_id: str
    object_path: Path
    object_label: str
    program_name: str
    section_name: str
    program_type: str
    attach_kind: str
    attach_target: str
    workloads: tuple[WorkloadSpec, ...]


def build_manual_targets(execve_object: Path, kprobe_object: Path) -> tuple[ManualAttachSpec, ...]:
    return (
        ManualAttachSpec(
            target_id="execve-tracepoint",
            object_path=execve_object,
            object_label="execve tracepoint object",
            program_name="event_execve",
            section_name="tracepoint/sys_execve",
            program_type="tracepoint",
            attach_kind="tracepoint",
            attach_target="syscalls/sys_enter_execve",
            workloads=(
                WorkloadSpec("rapid-execve", "rapid execve loop"),
                WorkloadSpec("stress-exec", "stress-ng exec workload"),
            ),
        ),
        ManualAttachSpec(
            target_id="open-kprobe",
            object_path=kprobe_object,
            object_label="generic kprobe object",
            program_name="generic_kprobe_event",
            section_name="kprobe/generic_kprobe",
            program_type="kprobe",
            attach_kind="kprobe",
            attach_target="security_file_open",
            workloads=(
                WorkloadSpec("file-ops-dd", "dd file write workload"),
                WorkloadSpec("stress-open", "stress-ng open workload"),
            ),
        ),
        ManualAttachSpec(
            target_id="connect-kprobe",
            object_path=kprobe_object,
            object_label="generic kprobe object",
            program_name="generic_kprobe_event",
            section_name="kprobe/generic_kprobe",
            program_type="kprobe",
            attach_kind="kprobe",
            attach_target="security_socket_connect",
            workloads=(
                WorkloadSpec("connect-loopback", "loopback TCP connect storm"),
            ),
        ),
    )


def find_tetragon_binary(explicit: str | None) -> str | None:
    if explicit:
        path = Path(explicit)
        return str(path.resolve()) if path.exists() else None
    for candidate in ("tetragon",):
        resolved = shutil.which(candidate)
        if resolved:
            return resolved
    return None


def run_command(
    command: list[str],
    *,
    timeout_seconds: int,
    cwd: Path | None = None,
    pass_fds: tuple[int, ...] = (),
) -> dict[str, Any]:
    started = time.monotonic()
    try:
        completed = subprocess.run(
            command,
            cwd=cwd or ROOT_DIR,
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
            pass_fds=pass_fds,
        )
        timed_out = False
    except subprocess.TimeoutExpired as exc:
        completed = None
        timed_out = True
        stdout = exc.stdout or ""
        stderr = exc.stderr or ""
    duration_seconds = time.monotonic() - started
    if completed is not None:
        stdout = completed.stdout or ""
        stderr = completed.stderr or ""
        returncode = int(completed.returncode)
    else:
        returncode = None
    return {
        "command": command,
        "display_command": shlex.join(command),
        "stdout": stdout,
        "stderr": stderr,
        "returncode": returncode,
        "timed_out": timed_out,
        "duration_seconds": duration_seconds,
    }


def require_success(result: dict[str, Any], *, label: str) -> None:
    if result["timed_out"]:
        raise RuntimeError(f"{label} timed out after {result['duration_seconds']:.2f}s")
    if result["returncode"] != 0:
        details = result["stderr"].strip() or result["stdout"].strip()
        raise RuntimeError(f"{label} failed: {details or f'exit={result['returncode']}'}")


def bpftool_json(bpftool_binary: str, command: list[str], timeout_seconds: int) -> Any:
    result = run_command(
        [bpftool_binary, *command],
        timeout_seconds=timeout_seconds,
    )
    require_success(result, label=f"bpftool {' '.join(command)}")
    payload = (result["stdout"] or "").strip()
    if not payload:
        raise RuntimeError(f"bpftool {' '.join(command)} produced no JSON output")
    try:
        return json.loads(payload)
    except json.JSONDecodeError as exc:
        details = result["stderr"].strip() or payload[-4000:]
        raise RuntimeError(f"bpftool {' '.join(command)} returned non-JSON output: {details}") from exc


def program_info_by_id(bpftool_binary: str, prog_id: int, timeout_seconds: int) -> dict[str, Any]:
    payload = bpftool_json(bpftool_binary, ["-j", "-p", "prog", "show", "id", str(prog_id)], timeout_seconds)
    if isinstance(payload, list):
        if len(payload) != 1:
            raise RuntimeError(f"unexpected bpftool payload for prog id {prog_id}")
        payload = payload[0]
    if not isinstance(payload, dict):
        raise RuntimeError(f"unexpected prog payload type for id {prog_id}")
    return payload


def list_program_inventory(runner: Path, object_path: Path, timeout_seconds: int) -> dict[str, dict[str, Any]]:
    result = run_command(
        [str(runner), "list-programs", "--program", str(object_path)],
        timeout_seconds=timeout_seconds,
    )
    require_success(result, label=f"list-programs {relpath(object_path)}")
    lines = [line.strip() for line in result["stdout"].splitlines() if line.strip()]
    if not lines:
        return {}
    payload = json.loads(lines[-1])
    if not isinstance(payload, list):
        raise RuntimeError(f"list-programs for {relpath(object_path)} did not return a JSON array")
    records: dict[str, dict[str, Any]] = {}
    for entry in payload:
        if not isinstance(entry, dict):
            continue
        records[str(entry.get("name", ""))] = entry
    return records


def bpftool_autoattach_probe(
    *,
    bpftool_binary: str,
    object_path: Path,
    bpftool_type: str,
    timeout_seconds: int,
    btf_path: Path | None,
) -> dict[str, Any]:
    pin_dir = Path("/sys/fs/bpf") / f"tetragon_probe_{object_path.stem}_{os.getpid()}"
    run_command(["sudo", "-n", "rm", "-rf", str(pin_dir)], timeout_seconds=timeout_seconds)
    mkdir_result = run_command(["sudo", "-n", "mkdir", "-p", str(pin_dir)], timeout_seconds=timeout_seconds)
    if mkdir_result["returncode"] != 0:
        return {
            "ok": False,
            "pin_dir": str(pin_dir),
            "error": (mkdir_result["stderr"] or mkdir_result["stdout"]).strip() or "unable to create pin dir",
        }

    command = [
        "sudo",
        "-n",
        bpftool_binary,
        "prog",
        "loadall",
        str(object_path),
        str(pin_dir),
        "type",
        bpftool_type,
        "autoattach",
    ]
    if btf_path is not None and btf_path.exists():
        command.extend(["kernel_btf", str(btf_path)])
    load_result = run_command(command, timeout_seconds=timeout_seconds)

    attached: list[dict[str, Any]] = []
    pinned: list[dict[str, Any]] = []
    try:
        if pin_dir.exists():
            for path in sorted(pin_dir.iterdir()):
                probe_result = run_command(
                    [
                        "sudo",
                        "-n",
                        bpftool_binary,
                        "-j",
                        "-p",
                        "link",
                        "show",
                        "pinned",
                        str(path),
                    ],
                    timeout_seconds=timeout_seconds,
                )
                if probe_result["returncode"] == 0 and probe_result["stdout"].strip():
                    link_info = json.loads(probe_result["stdout"])
                    if isinstance(link_info, dict):
                        attached.append(
                            {
                                "pin_path": str(path),
                                "program_name": path.name,
                                "prog_id": int(link_info.get("prog_id", 0) or 0),
                                "link_id": int(link_info.get("id", 0) or 0),
                                "type": str(link_info.get("type", "")),
                                "attach_type": str(link_info.get("attach_type", "")),
                            }
                        )
                        continue
                prog_result = run_command(
                    [
                        "sudo",
                        "-n",
                        bpftool_binary,
                        "-j",
                        "-p",
                        "prog",
                        "show",
                        "pinned",
                        str(path),
                    ],
                    timeout_seconds=timeout_seconds,
                )
                if prog_result["returncode"] == 0 and prog_result["stdout"].strip():
                    prog_info = json.loads(prog_result["stdout"])
                    if isinstance(prog_info, list):
                        prog_info = prog_info[0] if prog_info else {}
                    if isinstance(prog_info, dict):
                        pinned.append(
                            {
                                "pin_path": str(path),
                                "program_name": path.name,
                                "prog_id": int(prog_info.get("id", 0) or 0),
                                "type": str(prog_info.get("type", "")),
                                "attach_type": str(prog_info.get("attach_type", "")),
                            }
                        )
    finally:
        run_command(["sudo", "-n", "rm", "-rf", str(pin_dir)], timeout_seconds=timeout_seconds)

    return {
        "ok": load_result["returncode"] == 0,
        "command": load_result["display_command"],
        "pin_dir": str(pin_dir),
        "stdout_tail": load_result["stdout"][-4000:],
        "stderr_tail": load_result["stderr"][-4000:],
        "attached_programs": attached,
        "pinned_programs": pinned,
        "fallback_needed": load_result["returncode"] != 0 or not attached,
    }


def scan_loaded_program(scanner_binary: Path, prog_id: int, program_name: str, timeout_seconds: int) -> dict[str, Any]:
    del program_name, timeout_seconds
    counts = {
        "total_sites": 0,
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
    }
    result = scan_programs_by_id([prog_id], scanner_binary).get(int(prog_id), {})
    counts.update(result.get("sites") or {})
    command = [str(scanner_binary), "enumerate", "--prog-id", str(prog_id), "--all", "--json"]
    return {
        "ok": not bool(result.get("error")),
        "command": shlex.join(command),
        "counts": counts,
        "stdout_tail": str(result.get("stdout_tail") or "")[-4000:],
        "stderr_tail": str(result.get("stderr_tail") or "")[-4000:],
        "error": str(result.get("error") or ""),
    }


def apply_recompile_v5(scanner_binary: Path, prog_id: int, program_name: str, timeout_seconds: int) -> dict[str, Any]:
    del program_name, timeout_seconds
    counts = {
        "total_sites": 0,
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
    }
    result = apply_recompile_by_id([prog_id], scanner_binary, blind_apply=True).get(int(prog_id), {})
    counts.update(result.get("counts") or {})
    applied = bool(result.get("applied"))
    error_text = str(result.get("error") or "")
    command = [str(scanner_binary), "enumerate", "--prog-id", str(prog_id), "--all", "--recompile", "--json"]
    return {
        "ok": applied and not error_text,
        "command": shlex.join(command),
        "counts": counts,
        "stdout_tail": str(result.get("stdout_tail") or "")[-4000:],
        "stderr_tail": str(result.get("stderr_tail") or "")[-4000:],
        "error": error_text,
    }


def info_to_dict(info: BpfProgInfo) -> dict[str, Any]:
    return {
        "id": int(info.id),
        "name": decode_c_string(info.name),
        "run_cnt": int(info.run_cnt),
        "run_time_ns": int(info.run_time_ns),
        "jited_prog_len": int(info.jited_prog_len),
        "xlated_prog_len": int(info.xlated_prog_len),
        "verified_insns": int(info.verified_insns),
        "attach_btf_obj_id": int(info.attach_btf_obj_id),
        "attach_btf_id": int(info.attach_btf_id),
    }


def compute_measurement(before: BpfProgInfo, after: BpfProgInfo, wall_seconds: float) -> dict[str, Any]:
    run_cnt_delta = int(after.run_cnt - before.run_cnt)
    run_time_ns_delta = int(after.run_time_ns - before.run_time_ns)
    avg_ns = (
        float(run_time_ns_delta) / float(run_cnt_delta)
        if run_cnt_delta > 0 and run_time_ns_delta >= 0
        else None
    )
    events_per_second = (
        float(run_cnt_delta) / wall_seconds
        if wall_seconds > 0 and run_cnt_delta >= 0
        else None
    )
    return {
        "run_cnt_before": int(before.run_cnt),
        "run_cnt_after": int(after.run_cnt),
        "run_cnt_delta": run_cnt_delta,
        "run_time_ns_before": int(before.run_time_ns),
        "run_time_ns_after": int(after.run_time_ns),
        "run_time_ns_delta": run_time_ns_delta,
        "avg_ns_per_run": avg_ns,
        "events_per_second": events_per_second,
        "total_cpu_time_ns": run_time_ns_delta if run_time_ns_delta >= 0 else None,
        "wall_seconds": wall_seconds,
    }


def run_shell_text(command_text: str, timeout_seconds: int) -> dict[str, Any]:
    started = time.monotonic()
    try:
        completed = subprocess.run(
            ["/bin/bash", "-lc", command_text],
            cwd=ROOT_DIR,
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
        )
        returncode = int(completed.returncode)
        stdout = completed.stdout or ""
        stderr = completed.stderr or ""
    except subprocess.TimeoutExpired as exc:
        completed = None
        returncode = 124
        stdout = exc.stdout or ""
        stderr = (exc.stderr or "") + f"\ncommand timed out after {timeout_seconds}s"
    wall_seconds = time.monotonic() - started
    return {
        "command": command_text,
        "returncode": returncode,
        "stdout_tail": stdout[-4000:],
        "stderr_tail": stderr[-4000:],
        "wall_seconds": wall_seconds,
    }


def run_connect_loopback(iterations: int) -> dict[str, Any]:
    ready = threading.Event()
    stop = threading.Event()
    errors: list[str] = []
    port_holder: list[int] = []

    def server() -> None:
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as listener:
                listener.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
                listener.bind(("127.0.0.1", 0))
                listener.listen()
                listener.settimeout(0.5)
                port_holder.append(int(listener.getsockname()[1]))
                ready.set()
                while not stop.is_set():
                    try:
                        conn, _ = listener.accept()
                    except TimeoutError:
                        continue
                    with conn:
                        conn.recv(1)
                        conn.sendall(b"1")
        except Exception as exc:
            errors.append(str(exc))
            ready.set()

    thread = threading.Thread(target=server, daemon=True)
    thread.start()
    started = time.monotonic()
    ready.wait(timeout=2.0)
    if errors:
        return {
            "command": "loopback-tcp-connect",
            "returncode": 1,
            "stdout_tail": "",
            "stderr_tail": errors[-1],
            "wall_seconds": time.monotonic() - started,
        }
    if not port_holder:
        return {
            "command": "loopback-tcp-connect",
            "returncode": 1,
            "stdout_tail": "",
            "stderr_tail": "loopback listener failed to start",
            "wall_seconds": time.monotonic() - started,
        }

    port = port_holder[0]
    try:
        for _ in range(max(1, iterations)):
            with socket.create_connection(("127.0.0.1", port), timeout=1.0) as client:
                client.sendall(b"x")
                client.recv(1)
    finally:
        stop.set()
        thread.join(timeout=1.0)

    return {
        "command": f"loopback-tcp-connect {iterations}",
        "returncode": 0,
        "stdout_tail": "",
        "stderr_tail": "",
        "wall_seconds": time.monotonic() - started,
    }


def workload_parameters(smoke: bool) -> dict[str, int]:
    return {
        "rapid_execve_count": 250 if smoke else 10000,
        "dd_count": 32 if smoke else 1000,
        "stress_timeout_seconds": 1 if smoke else 3,
        "connect_iterations": 128 if smoke else 1000,
    }


def execute_workload(workload: WorkloadSpec, *, smoke: bool, timeout_seconds: int, workdir: Path) -> dict[str, Any]:
    params = workload_parameters(smoke)
    if workload.name == "rapid-execve":
        count = params["rapid_execve_count"]
        return run_shell_text(f"for i in $(seq 1 {count}); do /bin/true; done", timeout_seconds)
    if workload.name == "file-ops-dd":
        target = workdir / "tetragon-dd.bin"
        count = params["dd_count"]
        command = f"dd if=/dev/zero of={shlex.quote(str(target))} bs=4k count={count} oflag=dsync status=none && rm -f {shlex.quote(str(target))}"
        return run_shell_text(command, timeout_seconds)
    if workload.name == "stress-exec":
        secs = params["stress_timeout_seconds"]
        return run_shell_text(f"stress-ng --exec 1 --timeout {secs}s --metrics-brief --quiet", timeout_seconds)
    if workload.name == "stress-open":
        secs = params["stress_timeout_seconds"]
        return run_shell_text(f"stress-ng --open 1 --timeout {secs}s --metrics-brief --quiet", timeout_seconds)
    if workload.name == "connect-loopback":
        return run_connect_loopback(params["connect_iterations"])
    raise RuntimeError(f"unsupported workload {workload.name}")


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

    def loaded_programs(self, *, bpftool_binary: str, timeout_seconds: int) -> list[dict[str, Any]]:
        assert self.object_ptr is not None
        records: list[dict[str, Any]] = []
        current_ptr = ctypes.c_void_p()
        while True:
            current_ptr = ctypes.c_void_p(
                self.libbpf.lib.bpf_object__next_program(self.object_ptr, current_ptr)
            )
            if not current_ptr.value:
                break
            name = decode_c_string(self.libbpf.lib.bpf_program__name(current_ptr))
            section_name = decode_c_string(self.libbpf.lib.bpf_program__section_name(current_ptr))
            prog_fd = int(self.libbpf.lib.bpf_program__fd(current_ptr))
            if prog_fd < 0:
                continue
            info = self.libbpf.get_prog_info(prog_fd)
            try:
                bpftool_info = program_info_by_id(bpftool_binary, int(info.id), timeout_seconds)
            except Exception as exc:
                bpftool_info = {"error": str(exc), "id": int(info.id), "name": name}
            records.append(
                {
                    "name": name,
                    "section_name": section_name,
                    "prog_fd": prog_fd,
                    "prog_id": int(info.id),
                    "prog_info": info_to_dict(info),
                    "bpftool": bpftool_info,
                }
            )
        return records


def target_status_from_measurement(measurement: dict[str, Any] | None) -> str:
    if not measurement:
        return "not-run"
    if not measurement.get("ok"):
        return "failed"
    if int(((measurement.get("aggregate") or {}).get("run_cnt_delta", 0) or 0)) <= 0:
        return "zero-runs"
    return "ok"


def speedup_ratio(stock: dict[str, Any] | None, rejit: dict[str, Any] | None) -> float | None:
    if not stock or not rejit or not stock.get("ok") or not rejit.get("ok"):
        return None
    stock_avg = (stock.get("aggregate") or {}).get("avg_ns_per_run")
    rejit_avg = (rejit.get("aggregate") or {}).get("avg_ns_per_run")
    if stock_avg is None or rejit_avg is None or float(rejit_avg) <= 0:
        return None
    return float(stock_avg) / float(rejit_avg)


def format_float(value: float | None, digits: int = 2) -> str:
    if value is None:
        return "n/a"
    return f"{value:.{digits}f}"


def format_ratio(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.3f}x"


def format_int(value: int | None) -> str:
    if value is None:
        return "n/a"
    return str(int(value))


def should_attempt_test_run(program_type_name: str) -> bool:
    return program_type_name in SUPPORTED_TEST_RUN_TYPES


def parse_runner_sample(stdout: str) -> dict[str, Any]:
    lines = [line.strip() for line in stdout.splitlines() if line.strip()]
    if not lines:
        raise RuntimeError("micro_exec produced no JSON output")
    payload = json.loads(lines[-1])
    if not isinstance(payload, dict):
        raise RuntimeError("micro_exec payload was not a JSON object")
    return payload


def test_run_fallback(
    *,
    runner_binary: Path,
    spec: ManualAttachSpec,
    timeout_seconds: int,
    smoke: bool,
    recompile_v5: bool,
) -> dict[str, Any]:
    repeat = 32 if smoke else 200
    command = [
        "sudo",
        "-n",
        str(runner_binary),
        "run-kernel",
        "--program",
        str(spec.object_path),
        "--program-name",
        spec.program_name,
        "--io-mode",
        "context",
        "--input-size",
        "64",
        "--repeat",
        str(repeat),
    ]
    if recompile_v5:
        command.append("--recompile-v5")
    result = run_command(command, timeout_seconds=timeout_seconds)
    if result["returncode"] != 0 or result["timed_out"]:
        return {
            "ok": False,
            "mode": "test_run",
            "command": result["display_command"],
            "error": (result["stderr"] or result["stdout"]).strip() or "test_run failed",
            "stdout_tail": result["stdout"][-4000:],
            "stderr_tail": result["stderr"][-4000:],
        }
    sample = parse_runner_sample(result["stdout"])
    return {
        "ok": True,
        "mode": "test_run",
        "command": result["display_command"],
        "sample": sample,
        "aggregate": {
            "run_cnt_delta": None,
            "run_time_ns_delta": None,
            "avg_ns_per_run": float(sample.get("exec_ns", 0) or 0),
            "events_per_second": None,
            "total_cpu_time_ns": None,
            "wall_seconds": float(result["duration_seconds"]),
        },
        "stdout_tail": result["stdout"][-4000:],
        "stderr_tail": result["stderr"][-4000:],
    }


def benchmark_manual_target(
    *,
    libbpf: Libbpf,
    scanner_binary: Path,
    bpftool_binary: str,
    runner_binary: Path,
    spec: ManualAttachSpec,
    timeout_seconds: int,
    smoke: bool,
    recompile_v5: bool,
    inventory_entry: dict[str, Any] | None,
) -> dict[str, Any]:
    measurement: dict[str, Any] = {
        "ok": False,
        "mode": "attach",
        "recompile_requested": recompile_v5,
        "target_id": spec.target_id,
        "object_path": relpath(spec.object_path),
        "program_name": spec.program_name,
        "attach_kind": spec.attach_kind,
        "attach_target": spec.attach_target,
        "inventory_entry": inventory_entry,
    }
    try:
        with LoadedBpfObject(libbpf, spec.object_path) as loaded:
            loaded_programs = loaded.loaded_programs(bpftool_binary=bpftool_binary, timeout_seconds=timeout_seconds)
            measurement["loaded_programs"] = loaded_programs
            target_fd = loaded.program_fd(spec.program_name)
            measurement["target_fd"] = target_fd

            target_info = libbpf.get_prog_info(target_fd)
            measurement["target_prog_id"] = int(target_info.id)
            measurement["target_prog_info"] = info_to_dict(target_info)
            measurement["target_bpftool"] = program_info_by_id(
                bpftool_binary,
                int(target_info.id),
                timeout_seconds,
            )

            scan = scan_loaded_program(scanner_binary, int(target_info.id), spec.program_name, timeout_seconds)
            measurement["directive_scan"] = scan

            link_ptr = loaded.attach(spec)
            try:
                if recompile_v5:
                    if scan["counts"]["total_sites"] <= 0:
                        measurement["error"] = "no directive sites to recompile"
                        measurement["recompile"] = {
                            "ok": False,
                            "error": measurement["error"],
                        }
                        return measurement
                    apply = apply_recompile_v5(scanner_binary, int(target_info.id), spec.program_name, timeout_seconds)
                    measurement["recompile"] = apply
                    if not apply["ok"]:
                        measurement["error"] = apply["error"] or "BPF_PROG_JIT_RECOMPILE failed"
                        return measurement
                else:
                    measurement["recompile"] = {
                        "ok": False,
                        "error": "",
                    }

                with tempfile.TemporaryDirectory(prefix=f"tetragon-{spec.target_id}-") as tempdir:
                    workdir = Path(tempdir)
                    overall_before = libbpf.get_prog_info(target_fd)
                    workload_results: list[dict[str, Any]] = []
                    for workload in spec.workloads:
                        before = libbpf.get_prog_info(target_fd)
                        trigger = execute_workload(
                            workload,
                            smoke=smoke,
                            timeout_seconds=timeout_seconds,
                            workdir=workdir,
                        )
                        time.sleep(0.05)
                        after = libbpf.get_prog_info(target_fd)
                        per_workload = compute_measurement(before, after, float(trigger["wall_seconds"]))
                        workload_results.append(
                            {
                                "name": workload.name,
                                "description": workload.description,
                                "trigger": trigger,
                                "measurement": per_workload,
                            }
                        )
                        if trigger["returncode"] != 0:
                            measurement["error"] = (
                                trigger["stderr_tail"] or trigger["stdout_tail"] or f"{workload.name} failed"
                            )
                            measurement["workloads"] = workload_results
                            return measurement
                    overall_after = libbpf.get_prog_info(target_fd)
                total_wall_seconds = sum(
                    float(item["trigger"]["wall_seconds"])
                    for item in workload_results
                )
                measurement["aggregate"] = compute_measurement(overall_before, overall_after, total_wall_seconds)
                measurement["workloads"] = workload_results
                measurement["ok"] = True
                measurement["error"] = ""
                return measurement
            finally:
                if link_ptr:
                    libbpf.lib.bpf_link__destroy(link_ptr)
    except Exception as exc:
        measurement["error"] = str(exc)

    fallback_allowed = bool(inventory_entry and should_attempt_test_run(str(inventory_entry.get("prog_type_name", ""))))
    if fallback_allowed:
        fallback = test_run_fallback(
            runner_binary=runner_binary,
            spec=spec,
            timeout_seconds=timeout_seconds,
            smoke=smoke,
            recompile_v5=recompile_v5,
        )
        measurement["fallback"] = fallback
        if fallback["ok"]:
            return fallback
    else:
        measurement["fallback"] = {
            "ok": False,
            "mode": "test_run",
            "error": "program type does not support honest test_run fallback",
        }
    return measurement


def discover_manual_inventory(
    runner_binary: Path,
    timeout_seconds: int,
    targets: tuple[ManualAttachSpec, ...],
) -> dict[str, dict[str, dict[str, Any]]]:
    records: dict[str, dict[str, dict[str, Any]]] = {}
    for object_path in {spec.object_path for spec in targets}:
        records[str(object_path.resolve())] = list_program_inventory(runner_binary, object_path, timeout_seconds)
    return records


def build_manual_results(
    *,
    libbpf: Libbpf,
    scanner_binary: Path,
    bpftool_binary: str,
    runner_binary: Path,
    execve_object: Path,
    kprobe_object: Path,
    timeout_seconds: int,
    smoke: bool,
    btf_path: Path | None,
) -> dict[str, Any]:
    manual_targets = build_manual_targets(execve_object, kprobe_object)
    inventory = discover_manual_inventory(runner_binary, timeout_seconds, manual_targets)
    bpftool_probe_cache: dict[str, dict[str, Any]] = {}
    target_records: list[dict[str, Any]] = []
    for spec in manual_targets:
        object_key = str(spec.object_path.resolve())
        if object_key not in bpftool_probe_cache:
            bpftool_probe_cache[object_key] = bpftool_autoattach_probe(
                bpftool_binary=bpftool_binary,
                object_path=spec.object_path,
                bpftool_type=spec.program_type,
                timeout_seconds=timeout_seconds,
                btf_path=btf_path,
            )

        inventory_entry = inventory.get(object_key, {}).get(spec.program_name)
        stock = benchmark_manual_target(
            libbpf=libbpf,
            scanner_binary=scanner_binary,
            bpftool_binary=bpftool_binary,
            runner_binary=runner_binary,
            spec=spec,
            timeout_seconds=timeout_seconds,
            smoke=smoke,
            recompile_v5=False,
            inventory_entry=inventory_entry,
        )
        rejit = benchmark_manual_target(
            libbpf=libbpf,
            scanner_binary=scanner_binary,
            bpftool_binary=bpftool_binary,
            runner_binary=runner_binary,
            spec=spec,
            timeout_seconds=timeout_seconds,
            smoke=smoke,
            recompile_v5=True,
            inventory_entry=inventory_entry,
        )
        target_records.append(
            {
                "target_id": spec.target_id,
                "object_path": relpath(spec.object_path),
                "object_label": spec.object_label,
                "program_name": spec.program_name,
                "section_name": spec.section_name,
                "program_type": spec.program_type,
                "attach_kind": spec.attach_kind,
                "attach_target": spec.attach_target,
                "workloads": [workload.name for workload in spec.workloads],
                "bpftool_probe": bpftool_probe_cache[object_key],
                "stock": stock,
                "rejit": rejit,
                "speedup": speedup_ratio(stock, rejit),
            }
        )

    return {
        "mode": "direct-objects",
        "targets": target_records,
        "inventory": inventory,
        "bpftool_probes": bpftool_probe_cache,
    }


def write_tetragon_policy(path: Path) -> None:
    policy = textwrap.dedent(
        """
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
        """
    ).strip()
    path.write_text(policy + "\n")


def snapshot_programs(bpftool_binary: str, timeout_seconds: int) -> dict[int, dict[str, Any]]:
    payload = bpftool_json(bpftool_binary, ["-j", "-p", "prog", "show"], timeout_seconds)
    if isinstance(payload, dict):
        payload = [payload]
    programs: dict[int, dict[str, Any]] = {}
    if not isinstance(payload, list):
        return programs
    for entry in payload:
        if not isinstance(entry, dict):
            continue
        prog_id = int(entry.get("id", 0) or 0)
        if prog_id <= 0:
            continue
        programs[prog_id] = entry
    return programs


def daemon_measurement_for_programs(
    *,
    libbpf: Libbpf,
    scanner_binary: Path,
    bpftool_binary: str,
    timeout_seconds: int,
    smoke: bool,
    program_infos: dict[int, dict[str, Any]],
    recompile_v5: bool,
) -> dict[str, Any]:
    scan_cache: dict[int, dict[str, Any]] = {}
    apply_cache: dict[int, dict[str, Any]] = {}
    before: dict[int, BpfProgInfo] = {}
    fds: dict[int, int] = {}
    for prog_id, info in program_infos.items():
        fd = libbpf.prog_fd_by_id(prog_id)
        fds[prog_id] = fd
        before[prog_id] = libbpf.get_prog_info(fd)
        scan_cache[prog_id] = scan_loaded_program(scanner_binary, prog_id, str(info.get("name", f"id-{prog_id}")), timeout_seconds)
        if recompile_v5 and scan_cache[prog_id]["counts"]["total_sites"] > 0:
            apply_cache[prog_id] = apply_recompile_v5(scanner_binary, prog_id, str(info.get("name", f"id-{prog_id}")), timeout_seconds)
            if not apply_cache[prog_id]["ok"]:
                for close_fd in fds.values():
                    os.close(close_fd)
                return {
                    "ok": False,
                    "error": apply_cache[prog_id]["error"] or "BPF_PROG_JIT_RECOMPILE failed",
                    "directive_scan": scan_cache,
                    "recompile": apply_cache,
                }

    workload_sequence = (
        WorkloadSpec("rapid-execve", "rapid execve loop"),
        WorkloadSpec("file-ops-dd", "dd file write workload"),
        WorkloadSpec("stress-exec", "stress-ng exec workload"),
        WorkloadSpec("stress-open", "stress-ng open workload"),
        WorkloadSpec("connect-loopback", "loopback TCP connect storm"),
    )

    with tempfile.TemporaryDirectory(prefix="tetragon-daemon-") as tempdir:
        workdir = Path(tempdir)
        workload_results: list[dict[str, Any]] = []
        for workload in workload_sequence:
            before_snapshot = {prog_id: libbpf.get_prog_info(fd) for prog_id, fd in fds.items()}
            trigger = execute_workload(workload, smoke=smoke, timeout_seconds=timeout_seconds, workdir=workdir)
            time.sleep(0.05)
            after_snapshot = {prog_id: libbpf.get_prog_info(fd) for prog_id, fd in fds.items()}
            per_program = {
                prog_id: compute_measurement(
                    before_snapshot[prog_id],
                    after_snapshot[prog_id],
                    float(trigger["wall_seconds"]),
                )
                for prog_id in fds
            }
            workload_results.append(
                {
                    "name": workload.name,
                    "description": workload.description,
                    "trigger": trigger,
                    "per_program": per_program,
                }
            )
            if trigger["returncode"] != 0:
                for fd in fds.values():
                    os.close(fd)
                return {
                    "ok": False,
                    "error": trigger["stderr_tail"] or trigger["stdout_tail"] or f"{workload.name} failed",
                    "directive_scan": scan_cache,
                    "recompile": apply_cache,
                    "workloads": workload_results,
                }

    total_wall_seconds = sum(float(item["trigger"]["wall_seconds"]) for item in workload_results)
    after = {prog_id: libbpf.get_prog_info(fd) for prog_id, fd in fds.items()}
    per_program_aggregate = {
        prog_id: compute_measurement(before[prog_id], after[prog_id], total_wall_seconds)
        for prog_id in fds
    }
    for fd in fds.values():
        os.close(fd)
    return {
        "ok": True,
        "directive_scan": scan_cache,
        "recompile": apply_cache,
        "workloads": workload_results,
        "aggregate": per_program_aggregate,
    }


def run_tetragon_daemon_mode(
    *,
    libbpf: Libbpf,
    scanner_binary: Path,
    bpftool_binary: str,
    tetragon_binary: str,
    timeout_seconds: int,
    smoke: bool,
) -> dict[str, Any]:
    before_programs = snapshot_programs(bpftool_binary, timeout_seconds)
    with tempfile.TemporaryDirectory(prefix="tetragon-policy-") as tempdir:
        tempdir_path = Path(tempdir)
        policy_path = tempdir_path / "tetragon-e2e-policy.yaml"
        stdout_path = tempdir_path / "tetragon.stdout.log"
        stderr_path = tempdir_path / "tetragon.stderr.log"
        write_tetragon_policy(policy_path)

        with stdout_path.open("w") as stdout_handle, stderr_path.open("w") as stderr_handle:
            command = ["sudo", "-n", tetragon_binary, "--tracing-policy", str(policy_path)]
            process = subprocess.Popen(
                command,
                cwd=ROOT_DIR,
                stdout=stdout_handle,
                stderr=stderr_handle,
                text=True,
            )
        try:
            time.sleep(5.0)
            returncode = process.poll()
            if returncode is not None:
                stdout_text = stdout_path.read_text() if stdout_path.exists() else ""
                stderr_text = stderr_path.read_text() if stderr_path.exists() else ""
                raise RuntimeError(
                    f"Tetragon exited early (exit={returncode}): {(stderr_text or stdout_text).strip()[-4000:]}"
                )

            after_programs = snapshot_programs(bpftool_binary, timeout_seconds)
            new_program_ids = sorted(set(after_programs) - set(before_programs))
            traced_programs = {
                prog_id: info
                for prog_id, info in after_programs.items()
                if prog_id in new_program_ids and str(info.get("type", "")) in {"kprobe", "tracepoint", "tracing"}
            }
            if not traced_programs:
                raise RuntimeError("Tetragon started but no new tracing/kprobe/tracepoint programs were discovered")

            stock = daemon_measurement_for_programs(
                libbpf=libbpf,
                scanner_binary=scanner_binary,
                bpftool_binary=bpftool_binary,
                timeout_seconds=timeout_seconds,
                smoke=smoke,
                program_infos=traced_programs,
                recompile_v5=False,
            )
            rejit = daemon_measurement_for_programs(
                libbpf=libbpf,
                scanner_binary=scanner_binary,
                bpftool_binary=bpftool_binary,
                timeout_seconds=timeout_seconds,
                smoke=smoke,
                program_infos=traced_programs,
                recompile_v5=True,
            )

            targets = []
            for prog_id, info in traced_programs.items():
                stock_program = stock.get("aggregate", {}).get(prog_id) if stock.get("ok") else None
                rejit_program = rejit.get("aggregate", {}).get(prog_id) if rejit.get("ok") else None
                targets.append(
                    {
                        "target_id": f"daemon-prog-{prog_id}",
                        "object_path": None,
                        "object_label": "tetragon-daemon",
                        "program_name": str(info.get("name", f"id-{prog_id}")),
                        "section_name": "",
                        "program_type": str(info.get("type", "")),
                        "attach_kind": "managed-by-tetragon",
                        "attach_target": "managed-by-tetragon",
                        "workloads": ["rapid-execve", "file-ops-dd", "stress-exec", "stress-open", "connect-loopback"],
                        "bpftool_probe": {},
                        "stock": {
                            "ok": stock.get("ok", False),
                            "directive_scan": stock.get("directive_scan", {}).get(prog_id, {}),
                            "aggregate": stock_program,
                            "error": stock.get("error", ""),
                            "target_bpftool": info,
                        },
                        "rejit": {
                            "ok": rejit.get("ok", False),
                            "directive_scan": rejit.get("directive_scan", {}).get(prog_id, {}),
                            "aggregate": rejit_program,
                            "error": rejit.get("error", ""),
                            "target_bpftool": info,
                            "recompile": rejit.get("recompile", {}).get(prog_id, {}),
                        },
                        "speedup": speedup_ratio(
                            {"ok": stock.get("ok", False), "aggregate": stock_program},
                            {"ok": rejit.get("ok", False), "aggregate": rejit_program},
                        ),
                    }
                )
            return {
                "mode": "tetragon-daemon",
                "command": shlex.join(command),
                "policy_path": str(policy_path),
                "stdout_log": str(stdout_path),
                "stderr_log": str(stderr_path),
                "targets": targets,
            }
        finally:
            process.terminate()
            try:
                process.wait(timeout=10)
            except subprocess.TimeoutExpired:
                process.kill()
                process.wait(timeout=10)


def build_summary(targets: list[dict[str, Any]]) -> dict[str, Any]:
    measured_stock = [target for target in targets if target_status_from_measurement(target.get("stock")) == "ok"]
    measured_rejit = [target for target in targets if target_status_from_measurement(target.get("rejit")) == "ok"]
    positive_speedups = [target["speedup"] for target in targets if target.get("speedup") is not None]
    return {
        "targets": len(targets),
        "stock_ok": len(measured_stock),
        "rejit_ok": len(measured_rejit),
        "comparisons": len(positive_speedups),
        "best_speedup": max(positive_speedups) if positive_speedups else None,
        "worst_speedup": min(positive_speedups) if positive_speedups else None,
        "stock_failures": len([target for target in targets if target_status_from_measurement(target.get("stock")) == "failed"]),
        "rejit_failures": len([target for target in targets if target_status_from_measurement(target.get("rejit")) == "failed"]),
    }


def build_markdown(data: dict[str, Any]) -> str:
    lines = [
        "# Tetragon End-to-End Benchmark Results",
        "",
        f"- Generated: {data['generated_at']}",
        f"- Mode: `{data['mode']}`",
        f"- Smoke run: `{data['smoke']}`",
        f"- Runner: `{data['runner_binary']}`",
        f"- Scanner: `{data['scanner_binary']}`",
        f"- bpftool: `{data['bpftool_binary']}`",
        f"- Tetragon binary: `{data['tetragon_binary'] or 'not found'}`",
        "",
        "## Preflight",
        "",
    ]
    preflight_rows = [
        ["sudo -n true", data["preflight"]["sudo_n_true"]],
        ["bpftool", data["preflight"]["bpftool"]],
        ["stress-ng", data["preflight"]["stress_ng"]],
        ["scanner", data["preflight"]["scanner"]],
        ["micro_exec", data["preflight"]["runner"]],
        ["execve object", data["preflight"]["execve_object"]],
        ["kprobe object", data["preflight"]["kprobe_object"]],
        ["BTF", data["preflight"]["btf"]],
        ["kernel", data["preflight"]["kernel_release"]],
    ]
    lines.extend(markdown_table(["Check", "Value"], preflight_rows))
    lines.extend(
        [
            "",
            "## Summary",
            "",
        ]
    )
    summary_rows = [
        ["Targets", data["summary"]["targets"]],
        ["Stock OK", data["summary"]["stock_ok"]],
        ["ReJIT OK", data["summary"]["rejit_ok"]],
        ["Comparable speedups", data["summary"]["comparisons"]],
        ["Best speedup", format_ratio(data["summary"]["best_speedup"])],
        ["Worst speedup", format_ratio(data["summary"]["worst_speedup"])],
    ]
    lines.extend(markdown_table(["Metric", "Value"], summary_rows))
    lines.extend(["", "## Per-Program", ""])

    rows: list[list[Any]] = []
    for target in data["targets"]:
        stock = target.get("stock") or {}
        rejit = target.get("rejit") or {}
        stock_agg = stock.get("aggregate") or {}
        rejit_agg = rejit.get("aggregate") or {}
        scan_counts = ((stock.get("directive_scan") or {}).get("counts") or {})
        rows.append(
            [
                target["program_name"],
                target["attach_target"],
                target["program_type"],
                int(scan_counts.get("total_sites", 0) or 0),
                format_float(stock_agg.get("avg_ns_per_run")),
                format_float(rejit_agg.get("avg_ns_per_run")),
                format_ratio(target.get("speedup")),
                format_float(stock_agg.get("events_per_second")),
                format_float(rejit_agg.get("events_per_second")),
                format_int(stock_agg.get("total_cpu_time_ns")),
                format_int(rejit_agg.get("total_cpu_time_ns")),
                target_status_from_measurement(stock),
                target_status_from_measurement(rejit),
            ]
        )
    lines.extend(
        markdown_table(
            [
                "Program",
                "Attach Target",
                "Type",
                "Sites",
                "Stock Avg ns",
                "ReJIT Avg ns",
                "Speedup",
                "Stock events/s",
                "ReJIT events/s",
                "Stock CPU ns",
                "ReJIT CPU ns",
                "Stock",
                "ReJIT",
            ],
            rows,
        )
    )

    failures = []
    for target in data["targets"]:
        stock = target.get("stock") or {}
        rejit = target.get("rejit") or {}
        if stock.get("error"):
            failures.append([target["program_name"], "stock", stock["error"]])
        if rejit.get("error"):
            failures.append([target["program_name"], "rejit", rejit["error"]])

    if failures:
        lines.extend(["", "## Failures", ""])
        lines.extend(markdown_table(["Program", "Phase", "Error"], failures))

    lines.extend(
        [
            "",
            "## Notes",
            "",
            "- Direct-object mode first probes `bpftool prog loadall ... autoattach`; when that cannot create links for the local Tetragon objects, the harness falls back to whole-object libbpf load plus explicit attach targets.",
            "- Directive census uses `scanner/build/bpf-jit-scanner scan --v5` against loaded program FDs.",
            "- Recompile uses `scanner/build/bpf-jit-scanner apply --v5`, so kernel support for `BPF_PROG_JIT_RECOMPILE` is required for comparable stock vs recompiled numbers.",
            "- Programs that cannot be honestly attached are only sent through `micro_exec` `test_run` when their type is known to support that path; otherwise they are reported as skipped/failed instead of being misrepresented.",
        ]
    )
    return "\n".join(lines) + "\n"


def build_preflight(
    *,
    runner_binary: Path,
    scanner_binary: Path,
    execve_object: Path,
    kprobe_object: Path,
    bpftool_binary: str,
    tetragon_binary: str | None,
) -> dict[str, Any]:
    return {
        "sudo_n_true": "yes" if sudo_available() else "no",
        "bpftool": bpftool_binary if shutil.which(bpftool_binary) or Path(bpftool_binary).exists() else "missing",
        "stress_ng": shutil.which("stress-ng") or "missing",
        "scanner": relpath(scanner_binary) if scanner_binary.exists() else "missing",
        "runner": relpath(runner_binary) if runner_binary.exists() else "missing",
        "execve_object": relpath(execve_object) if execve_object.exists() else "missing",
        "kprobe_object": relpath(kprobe_object) if kprobe_object.exists() else "missing",
        "btf": str(DEFAULT_BTF_PATH) if DEFAULT_BTF_PATH.exists() else "missing",
        "kernel_release": platform.release(),
        "tetragon_binary": tetragon_binary or "not found",
    }


def main() -> int:
    args = parse_args()
    ensure_root()

    runner_binary = Path(args.runner).resolve()
    scanner_binary = Path(args.scanner).resolve()
    bpftool_binary = args.bpftool
    execve_object = Path(args.execve_object).resolve()
    kprobe_object = Path(args.kprobe_object).resolve()
    tetragon_binary = None if args.force_direct else find_tetragon_binary(args.tetragon_binary)

    preflight = build_preflight(
        runner_binary=runner_binary,
        scanner_binary=scanner_binary,
        execve_object=execve_object,
        kprobe_object=kprobe_object,
        bpftool_binary=bpftool_binary,
        tetragon_binary=tetragon_binary,
    )
    ensure_parent(Path(args.output_json))
    ensure_parent(Path(args.output_md))

    libbpf = Libbpf()
    with RuntimeStatsHandle(libbpf):
        if tetragon_binary:
            try:
                mode_results = run_tetragon_daemon_mode(
                    libbpf=libbpf,
                    scanner_binary=scanner_binary,
                    bpftool_binary=bpftool_binary,
                    tetragon_binary=tetragon_binary,
                    timeout_seconds=args.timeout,
                    smoke=args.smoke,
                )
            except Exception as exc:
                mode_results = {
                    "mode": "direct-objects",
                    "fallback_reason": str(exc),
                    **build_manual_results(
                        libbpf=libbpf,
                        scanner_binary=scanner_binary,
                        bpftool_binary=bpftool_binary,
                        runner_binary=runner_binary,
                        execve_object=execve_object,
                        kprobe_object=kprobe_object,
                        timeout_seconds=args.timeout,
                        smoke=args.smoke,
                        btf_path=DEFAULT_BTF_PATH if DEFAULT_BTF_PATH.exists() else None,
                    ),
                }
        else:
            mode_results = build_manual_results(
                libbpf=libbpf,
                scanner_binary=scanner_binary,
                bpftool_binary=bpftool_binary,
                runner_binary=runner_binary,
                execve_object=execve_object,
                kprobe_object=kprobe_object,
                timeout_seconds=args.timeout,
                smoke=args.smoke,
                btf_path=DEFAULT_BTF_PATH if DEFAULT_BTF_PATH.exists() else None,
            )

    data = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "mode": mode_results["mode"],
        "smoke": bool(args.smoke),
        "runner_binary": relpath(runner_binary),
        "scanner_binary": relpath(scanner_binary),
        "bpftool_binary": bpftool_binary,
        "tetragon_binary": tetragon_binary,
        "preflight": preflight,
        "targets": mode_results["targets"],
        "summary": build_summary(mode_results["targets"]),
        "details": {key: value for key, value in mode_results.items() if key not in {"targets", "mode"}},
    }

    output_json = Path(args.output_json)
    output_md = Path(args.output_md)
    output_json.write_text(json.dumps(data, indent=2) + "\n")
    output_md.write_text(build_markdown(data))
    print(json.dumps({"output_json": str(output_json), "output_md": str(output_md), "mode": data["mode"]}))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
