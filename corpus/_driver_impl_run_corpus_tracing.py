#!/usr/bin/env python3
from __future__ import annotations

import argparse
import ctypes
import ctypes.util
import json
import os
import socket
import subprocess
import sys
import tempfile
import threading
import time
from collections import Counter
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Callable

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

from benchmark_catalog import ROOT_DIR, load_suite
try:
    from orchestrator.corpus import (
        build_kernel_command,
        directive_scan_from_record,
        ensure_parent,
        format_ns,
        invocation_summary,
        markdown_table,
        normalize_section_root,
        run_command as orchestrator_run_command,
        summarize_stderr,
    )
    from orchestrator.inventory import discover_corpus_objects, discover_object_programs
except ImportError:
    from micro.orchestrator.corpus import (
        build_kernel_command,
        directive_scan_from_record,
        ensure_parent,
        format_ns,
        invocation_summary,
        markdown_table,
        normalize_section_root,
        run_command as orchestrator_run_command,
        summarize_stderr,
    )
    from micro.orchestrator.inventory import discover_corpus_objects, discover_object_programs
try:
    from common import (
        add_corpus_build_report_argument,
        add_filter_argument,
        add_max_programs_argument,
        add_output_json_argument,
        add_output_md_argument,
        add_repeat_argument,
        add_runner_argument,
        add_section_filter_argument,
        add_timeout_argument,
        require_minimum,
    )
except ImportError:
    from corpus.common import (
        add_corpus_build_report_argument,
        add_filter_argument,
        add_max_programs_argument,
        add_output_json_argument,
        add_output_md_argument,
        add_repeat_argument,
        add_runner_argument,
        add_section_filter_argument,
        add_timeout_argument,
        require_minimum,
    )


DEFAULT_TIMEOUT_SECONDS = 120


DEFAULT_REPEAT = 50
DEFAULT_OUTPUT_JSON = Path(__file__).resolve().parent.parent / "docs" / "tmp" / "corpus-tracing-results.json"
DEFAULT_OUTPUT_MD = Path(__file__).resolve().parent.parent / "docs" / "tmp" / "corpus-tracing-results.md"
BPF_STATS_RUN_TIME = 0
BPF_TAG_SIZE = 8
BPF_OBJ_NAME_LEN = 16
FAMILY_FIELDS = (
    ("CMOV", "cmov_sites"),
    ("WIDE", "wide_sites"),
    ("ROTATE", "rotate_sites"),
    ("LEA", "lea_sites"),
    ("EXTRACT", "bitfield_sites"),
    ("ZERO-EXT", "zero_ext_sites"),
    ("ENDIAN", "endian_sites"),
    ("BRANCH-FLIP", "branch_flip_sites"),
)
SUPPORTED_ROOTS = {
    "fentry",
    "fexit",
    "fmod_ret",
    "kprobe",
    "kretprobe",
    "ksyscall",
    "raw_tp",
    "raw_tracepoint",
    "tp",
    "tp_btf",
    "tracepoint",
}


def relpath(path: Path) -> str:
    return path.relative_to(ROOT_DIR).as_posix()


def runner_binary_from_config() -> Path:
    return load_suite().build.runner_binary


def list_programs(runner: Path, object_path: Path, timeout_seconds: int) -> dict[str, Any]:
    try:
        inventory = [
            {
                "name": entry.name,
                "section_name": entry.section_name,
                "insn_count": entry.insn_count,
                "prog_type": entry.prog_type,
                "expected_attach_type": entry.expected_attach_type,
                "prog_type_name": entry.prog_type_name,
                "attach_type_name": entry.attach_type_name,
            }
            for entry in discover_object_programs(runner, object_path, timeout_seconds=timeout_seconds)
        ]
        return {"ok": True, "stderr": "", "error": None, "inventory": inventory}
    except Exception as exc:
        return {"ok": False, "stderr": "", "error": str(exc), "inventory": []}


def run_command(command: list[str], timeout_seconds: int) -> dict[str, Any]:
    return orchestrator_run_command(command, timeout_seconds, cwd=ROOT_DIR)
UNSUPPORTED_ROOTS = {
    "iter",
    "iter.s",
    "lsm",
    "lsm.s",
    "perf_event",
    "raw_tracepoint.w",
    "struct_ops",
    "syscall",
    "uprobe",
    "uprobe.multi",
    "uretprobe",
    "usdt",
}


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Attach tracing-style BPF programs, trigger matching workloads, "
            "and read run_cnt/run_time_ns from bpf_prog_info."
        )
    )
    add_output_json_argument(parser, DEFAULT_OUTPUT_JSON, help_text="Path for structured JSON results.")
    add_output_md_argument(parser, DEFAULT_OUTPUT_MD, help_text="Path for markdown summary output.")
    add_runner_argument(parser, help_text="Path to the micro_exec runner binary. Defaults to the suite config runner path.")
    add_repeat_argument(parser, DEFAULT_REPEAT, help_text="How many workload iterations to trigger per attached program.")
    add_timeout_argument(parser, DEFAULT_TIMEOUT_SECONDS, help_text="Per-invocation timeout in seconds for helper commands.")
    add_filter_argument(parser, help_text="Only include corpus object paths containing this substring. Repeatable.")
    add_section_filter_argument(parser, help_text="Only include section names containing this substring. Repeatable.")
    add_corpus_build_report_argument(
        parser,
        help_text=(
            "Optional expanded corpus build JSON report. When omitted, "
            "the newest existing expanded_corpus_build authoritative JSON is used if present."
        ),
    )
    parser.add_argument(
        "--skip-recompile-probe",
        action="store_true",
        help="Skip the compile-only --recompile-all probe used to collect directive-scan metadata.",
    )
    add_max_programs_argument(parser, help_text="Stop after processing this many discovered tracing programs.")
    return parser.parse_args(argv)


def ensure_root() -> None:
    if os.geteuid() == 0:
        return
    os.execvp("sudo", ["sudo", "-n", sys.executable, str(Path(__file__).resolve()), *sys.argv[1:]])


def decode_c_string(value: bytes | None) -> str:
    return value.decode("utf-8", "replace") if value else ""


def libbpf_error_string(err: int) -> str:
    code = -err if err < 0 else err
    try:
        return os.strerror(code)
    except ValueError:
        return f"error {err}"


@dataclass(frozen=True)
class TriggerPlan:
    name: str
    description: str
    execute: Callable[[Path, int], None]


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
        self.lib.bpf_object__close.argtypes = [ctypes.c_void_p]
        self.lib.bpf_object__close.restype = None
        self.lib.bpf_object__find_program_by_name.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
        self.lib.bpf_object__find_program_by_name.restype = ctypes.c_void_p
        self.lib.bpf_object__next_program.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
        self.lib.bpf_object__next_program.restype = ctypes.c_void_p
        self.lib.bpf_object__load.argtypes = [ctypes.c_void_p]
        self.lib.bpf_object__load.restype = ctypes.c_int
        self.lib.bpf_program__name.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__name.restype = ctypes.c_char_p
        self.lib.bpf_program__section_name.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__section_name.restype = ctypes.c_char_p
        self.lib.bpf_program__set_autoload.argtypes = [ctypes.c_void_p, ctypes.c_bool]
        self.lib.bpf_program__set_autoload.restype = ctypes.c_int
        self.lib.bpf_program__fd.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__fd.restype = ctypes.c_int
        self.lib.bpf_program__attach.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__attach.restype = ctypes.c_void_p
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


class LoadedTracingProgram:
    def __init__(self, libbpf: Libbpf, object_path: Path, program_name: str) -> None:
        self.libbpf = libbpf
        self.object_path = object_path
        self.program_name = program_name
        self.object_ptr: int | None = None
        self.program_ptr: int | None = None
        self.link_ptr: int | None = None
        self.prog_fd = -1
        self.stats_fd = -1

    def __enter__(self) -> "LoadedTracingProgram":
        try:
            object_ptr = self.libbpf.lib.bpf_object__open_file(
                str(self.object_path).encode(),
                None,
            )
            open_error = self.libbpf.pointer_error(object_ptr)
            if open_error != 0:
                raise RuntimeError(
                    f"bpf_object__open_file failed: {libbpf_error_string(open_error)}"
                )
            self.object_ptr = object_ptr

            desired_name = self.program_name.encode()
            program_ptr = self.libbpf.lib.bpf_object__find_program_by_name(self.object_ptr, desired_name)
            if not program_ptr:
                raise RuntimeError(f"program not found in object: {self.program_name}")
            self.program_ptr = program_ptr

            current_ptr = ctypes.c_void_p()
            while True:
                current_ptr = ctypes.c_void_p(
                    self.libbpf.lib.bpf_object__next_program(self.object_ptr, current_ptr)
                )
                if not current_ptr.value:
                    break
                current_name = decode_c_string(self.libbpf.lib.bpf_program__name(current_ptr))
                rc = self.libbpf.lib.bpf_program__set_autoload(
                    current_ptr,
                    current_name == self.program_name,
                )
                if rc != 0:
                    raise RuntimeError(
                        f"bpf_program__set_autoload failed for {current_name}: {libbpf_error_string(rc)}"
                    )

            stats_fd = self.libbpf.lib.bpf_enable_stats(BPF_STATS_RUN_TIME)
            if stats_fd < 0:
                err = ctypes.get_errno()
                raise RuntimeError(f"bpf_enable_stats failed: {os.strerror(err)} (errno={err})")
            self.stats_fd = stats_fd

            rc = self.libbpf.lib.bpf_object__load(self.object_ptr)
            if rc != 0:
                raise RuntimeError(f"bpf_object__load failed: {libbpf_error_string(rc)}")

            self.prog_fd = int(self.libbpf.lib.bpf_program__fd(self.program_ptr))
            if self.prog_fd < 0:
                raise RuntimeError("bpf_program__fd failed")

            link_ptr = self.libbpf.lib.bpf_program__attach(self.program_ptr)
            attach_error = self.libbpf.pointer_error(link_ptr)
            if attach_error != 0:
                raise RuntimeError(f"bpf_program__attach failed: {libbpf_error_string(attach_error)}")
            self.link_ptr = link_ptr
            return self
        except Exception:
            self.__exit__(None, None, None)
            raise

    def __exit__(self, exc_type, exc, tb) -> None:
        if self.link_ptr:
            self.libbpf.lib.bpf_link__destroy(self.link_ptr)
            self.link_ptr = None
        if self.stats_fd >= 0:
            os.close(self.stats_fd)
            self.stats_fd = -1
        if self.object_ptr:
            self.libbpf.lib.bpf_object__close(self.object_ptr)
            self.object_ptr = None


def section_target(section_name: str) -> str:
    return section_name.split("/", 1)[1] if "/" in section_name else ""


def generic_syscall_mix(workdir: Path, repeat: int) -> None:
    for index in range(repeat):
        temp_path = workdir / f"generic_{index}.txt"
        temp_path.write_bytes(b"x")
        with open("/dev/null", "wb", buffering=0) as sink:
            sink.write(b"bench")
        with temp_path.open("rb") as handle:
            handle.read()
        os.kill(os.getpid(), 0)
        temp_path.unlink(missing_ok=True)


def write_devnull(workdir: Path, repeat: int) -> None:
    del workdir
    with open("/dev/null", "wb", buffering=0) as sink:
        for _ in range(repeat):
            sink.write(b"benchmark-write")


def unlink_tempfile(workdir: Path, repeat: int) -> None:
    for index in range(repeat):
        path = workdir / f"unlink_{index}.tmp"
        path.write_bytes(b"u")
        path.unlink(missing_ok=True)


def run_execve(workdir: Path, repeat: int) -> None:
    del workdir
    for _ in range(repeat):
        subprocess.run(
            ["/bin/true"],
            check=True,
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
        )


def run_sched_activity(workdir: Path, repeat: int) -> None:
    run_execve(workdir, repeat)


def run_signal_syscalls(workdir: Path, repeat: int) -> None:
    del workdir
    pid = os.getpid()
    for _ in range(repeat):
        os.kill(pid, 0)


def run_futex_activity(workdir: Path, repeat: int) -> None:
    del workdir
    cond = threading.Condition()
    state = {"ready": False, "seq": 0, "ack": 0, "stop": False}

    def worker() -> None:
        with cond:
            state["ready"] = True
            cond.notify_all()
        while True:
            with cond:
                cond.wait_for(lambda: state["stop"] or state["seq"] > state["ack"])
                if state["stop"]:
                    return
                state["ack"] = state["seq"]
                cond.notify_all()

    thread = threading.Thread(target=worker, daemon=True)
    thread.start()

    with cond:
        cond.wait_for(lambda: state["ready"])

    for _ in range(repeat):
        with cond:
            state["seq"] += 1
            cond.notify_all()
            cond.wait_for(lambda: state["ack"] == state["seq"], timeout=1.0)

    with cond:
        state["stop"] = True
        cond.notify_all()
    thread.join(timeout=1.0)


def run_disk_io(workdir: Path, repeat: int) -> None:
    payload = b"\0" * 4096
    read_path = workdir / "disk-read.bin"
    if not read_path.exists():
        read_path.write_bytes(payload * 256)

    for index in range(repeat):
        write_path = workdir / f"disk-write-{index}.bin"
        with write_path.open("wb", buffering=0) as handle:
            handle.write(payload)
            handle.flush()
            os.fsync(handle.fileno())
        with read_path.open("rb", buffering=0) as handle:
            while handle.read(65536):
                pass
        write_path.unlink(missing_ok=True)


def run_open_close(workdir: Path, repeat: int) -> None:
    path = workdir / "open-close.txt"
    path.write_bytes(b"open-close")
    for _ in range(repeat):
        with path.open("rb") as handle:
            handle.read(1)


def run_tcp_loopback(workdir: Path, repeat: int) -> None:
    del workdir
    ready = threading.Event()
    stop = threading.Event()
    errors: list[str] = []

    def server() -> None:
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as listener:
                listener.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
                listener.bind(("127.0.0.1", 0))
                listener.listen()
                port_holder.append(listener.getsockname()[1])
                ready.set()
                listener.settimeout(0.5)
                while not stop.is_set():
                    try:
                        conn, _ = listener.accept()
                    except TimeoutError:
                        continue
                    with conn:
                        conn.recv(64)
                        conn.sendall(b"ok")
        except Exception as exc:  # pragma: no cover - surfaced in JSON results
            errors.append(str(exc))
            ready.set()

    port_holder: list[int] = []
    thread = threading.Thread(target=server, daemon=True)
    thread.start()
    ready.wait(timeout=2.0)
    if errors:
        raise RuntimeError(errors[-1])
    if not port_holder:
        raise RuntimeError("loopback server failed to start")

    port = port_holder[0]
    for _ in range(repeat):
        with socket.create_connection(("127.0.0.1", port), timeout=1.0) as client:
            client.sendall(b"x")
            client.recv(2)

    stop.set()
    thread.join(timeout=1.0)


TRIGGERS: dict[str, TriggerPlan] = {
    "disk-io": TriggerPlan(
        name="disk-io",
        description="write/fsync/read a temporary file",
        execute=run_disk_io,
    ),
    "execve": TriggerPlan(
        name="execve",
        description="spawn `/bin/true` repeatedly",
        execute=run_execve,
    ),
    "futex": TriggerPlan(
        name="futex",
        description="ping-pong a condition variable between two threads",
        execute=run_futex_activity,
    ),
    "generic-syscalls": TriggerPlan(
        name="generic-syscalls",
        description="mix open/read/write/unlink/kill syscalls",
        execute=generic_syscall_mix,
    ),
    "open-close": TriggerPlan(
        name="open-close",
        description="open and read a temporary file repeatedly",
        execute=run_open_close,
    ),
    "sched": TriggerPlan(
        name="sched",
        description="spawn short-lived processes to force scheduler activity",
        execute=run_sched_activity,
    ),
    "signal": TriggerPlan(
        name="signal",
        description="issue signal syscalls against the current process",
        execute=run_signal_syscalls,
    ),
    "tcp-loopback": TriggerPlan(
        name="tcp-loopback",
        description="connect/send/recv over a localhost TCP socket",
        execute=run_tcp_loopback,
    ),
    "unlink": TriggerPlan(
        name="unlink",
        description="create and unlink temporary files",
        execute=unlink_tempfile,
    ),
    "write-devnull": TriggerPlan(
        name="write-devnull",
        description="write a small buffer to /dev/null repeatedly",
        execute=write_devnull,
    ),
}


def choose_trigger(section_name: str, program_name: str) -> tuple[TriggerPlan | None, str | None]:
    root = normalize_section_root(section_name)
    if root in UNSUPPORTED_ROOTS:
        return None, f"unsupported section root `{root}`"
    if root not in SUPPORTED_ROOTS:
        return None, f"unsupported section root `{root}`"

    target = section_target(section_name).lower()
    if not target:
        return None, "missing attach target in section name"
    if "dummy_" in target:
        return None, "dynamic attach target placeholder"

    if any(token in target for token in ("unlink", "do_unlinkat")):
        return TRIGGERS["unlink"], None
    if "futex" in target:
        return TRIGGERS["futex"], None
    if any(token in target for token in ("execve", "sched_process_exec", "sched_process_exit", "security_bprm_check")):
        return TRIGGERS["execve"], None
    if any(token in target for token in ("sched_switch", "sched_wakeup", "sched_wakeup_new")):
        return TRIGGERS["sched"], None
    if any(token in target for token in ("kill", "tgkill")):
        return TRIGGERS["signal"], None
    if any(token in target for token in ("write", "vfs_write", "sys_enter_write")):
        return TRIGGERS["write-devnull"], None
    if any(token in target for token in ("open", "openat", "getattr")):
        return TRIGGERS["open-close"], None
    if any(token in target for token in ("tcp_", "sock", "connect", "accept")):
        return TRIGGERS["tcp-loopback"], None
    if any(
        token in target
        for token in (
            "block_",
            "bio",
            "folio",
            "page_cache",
            "filemap",
            "readahead",
            "mark_page_accessed",
        )
    ):
        return TRIGGERS["disk-io"], None
    if any(token in target for token in ("sys_enter", "sys_exit")):
        return TRIGGERS["generic-syscalls"], None
    if root in {"tracepoint", "tp", "raw_tracepoint", "raw_tp", "tp_btf"}:
        return TRIGGERS["generic-syscalls"], None

    return None, f"no trigger heuristic for section `{section_name}` / program `{program_name}`"


def run_recompile_probe(
    runner: Path,
    object_path: Path,
    program_name: str,
    timeout_seconds: int,
) -> dict[str, Any]:
    result = run_command(
        build_kernel_command(
            runner,
            object_path,
            program_name,
            "context",
            None,
            0,
            1,
            compile_only=True,
            recompile_all=True,
        ),
        timeout_seconds,
    )
    summary = invocation_summary(result)
    summary["directive_scan"] = directive_scan_from_record(summary)
    recompile = (summary.get("sample") or {}).get("recompile") or {}
    summary["recompile_applied"] = bool(recompile.get("applied"))
    summary["recompile_requested"] = bool(recompile.get("requested"))
    summary["recompile_error"] = recompile.get("error")
    return summary


def format_avg_ns(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.2f}"


def measure_attached_program(
    libbpf: Libbpf,
    object_path: Path,
    program_name: str,
    trigger: TriggerPlan,
    repeat: int,
) -> dict[str, Any]:
    with tempfile.TemporaryDirectory(prefix="bpf-tracing-") as tempdir:
        workdir = Path(tempdir)
        attach_start = time.monotonic()
        with LoadedTracingProgram(libbpf, object_path, program_name) as program:
            attach_seconds = time.monotonic() - attach_start
            before = libbpf.get_prog_info(program.prog_fd)
            workload_start = time.monotonic()
            trigger.execute(workdir, repeat)
            workload_seconds = time.monotonic() - workload_start
            time.sleep(0.05)
            after = libbpf.get_prog_info(program.prog_fd)

    run_cnt_delta = int(after.run_cnt - before.run_cnt)
    run_time_ns_delta = int(after.run_time_ns - before.run_time_ns)
    avg_ns_per_run = (
        float(run_time_ns_delta) / float(run_cnt_delta)
        if run_cnt_delta > 0 and run_time_ns_delta >= 0
        else None
    )
    return {
        "ok": True,
        "attach_seconds": attach_seconds,
        "workload_seconds": workload_seconds,
        "run_cnt_before": int(before.run_cnt),
        "run_cnt_after": int(after.run_cnt),
        "run_cnt_delta": run_cnt_delta,
        "run_time_ns_before": int(before.run_time_ns),
        "run_time_ns_after": int(after.run_time_ns),
        "run_time_ns_delta": run_time_ns_delta,
        "average_ns_per_run": avg_ns_per_run,
        "prog_fd": int(program.prog_fd),
    }


def build_summary(records: list[dict[str, Any]]) -> dict[str, Any]:
    measured = [record for record in records if (record.get("measurement") or {}).get("ok")]
    positive_runs = [record for record in measured if record["measurement"]["run_cnt_delta"] > 0]
    zero_runs = [record for record in measured if record["measurement"]["run_cnt_delta"] == 0]
    attach_failures = [
        record for record in records
        if record.get("measurement") and not record["measurement"]["ok"]
    ]
    skipped = [record for record in records if record.get("skip_reason")]
    directive_bearing = [record for record in records if record["directive_scan"]["total_sites"] > 0]
    directive_bearing_measured = [
        record for record in positive_runs if record["directive_scan"]["total_sites"] > 0
    ]

    avg_values = [
        record["measurement"]["average_ns_per_run"]
        for record in positive_runs
        if record["measurement"]["average_ns_per_run"] is not None
    ]

    failure_reasons = Counter()
    for record in records:
        if record.get("skip_reason"):
            failure_reasons[record["skip_reason"]] += 1
            continue
        measurement = record.get("measurement")
        if measurement and not measurement.get("ok"):
            failure_reasons[measurement.get("error") or "measurement failed"] += 1

    return {
        "programs_found": len(records),
        "supported_programs": len(records) - len(skipped),
        "measured_programs": len(measured),
        "programs_with_positive_runs": len(positive_runs),
        "zero_run_programs": len(zero_runs),
        "attach_failures": len(attach_failures),
        "skipped_programs": len(skipped),
        "directive_bearing_programs": len(directive_bearing),
        "directive_bearing_measured_programs": len(directive_bearing_measured),
        "average_ns_per_run_min": min(avg_values) if avg_values else None,
        "average_ns_per_run_max": max(avg_values) if avg_values else None,
        "failure_reasons": dict(failure_reasons.most_common(12)),
    }


def build_markdown(data: dict[str, Any]) -> str:
    summary = data["summary"]
    records = data["programs"]
    measured = [
        record for record in records
        if (record.get("measurement") or {}).get("ok")
        and record["measurement"]["run_cnt_delta"] > 0
    ]
    measured.sort(
        key=lambda item: (
            -item["directive_scan"]["total_sites"],
            item["measurement"]["average_ns_per_run"] or float("inf"),
            item["object_path"],
            item["program_name"],
        )
    )
    attach_failures = [
        record for record in records
        if record.get("measurement") and not record["measurement"]["ok"]
    ]
    attach_failures.sort(key=lambda item: (item["object_path"], item["program_name"]))
    skipped = [record for record in records if record.get("skip_reason")]
    skipped.sort(key=lambda item: (item["object_path"], item["program_name"]))

    lines: list[str] = [
        "# Corpus Tracing Runtime Results",
        "",
        f"- Generated: {data['generated_at']}",
        f"- Runner: `{data['runner_binary']}`",
        f"- Corpus source: {data['corpus_source']}",
        f"- Objects discovered: {data['objects_found']}",
        f"- Programs found: {summary['programs_found']}",
        f"- Supported by harness: {summary['supported_programs']}",
        f"- Measured programs: {summary['measured_programs']}",
        f"- Programs with positive run_cnt delta: {summary['programs_with_positive_runs']}",
        f"- Zero-run programs: {summary['zero_run_programs']}",
        f"- Attach failures: {summary['attach_failures']}",
        f"- Skipped programs: {summary['skipped_programs']}",
        f"- Directive-bearing programs: {summary['directive_bearing_programs']}",
        f"- Directive-bearing measured programs: {summary['directive_bearing_measured_programs']}",
        "",
        "## Summary Statistics",
        "",
    ]
    lines.extend(
        markdown_table(
            ["Metric", "Value"],
            [
                ["Average ns/run min", format_avg_ns(summary["average_ns_per_run_min"])],
                ["Average ns/run max", format_avg_ns(summary["average_ns_per_run_max"])],
            ],
        )
    )
    lines.append("")

    if measured:
        rows = []
        for record in measured:
            probe = record.get("recompile_probe") or {}
            rows.append(
                [
                    f"{record['object_path']}:{record['program_name']}",
                    record["section_name"],
                    record["trigger_name"],
                record["measurement"]["run_cnt_delta"],
                format_ns(record["measurement"]["run_time_ns_delta"]),
                format_avg_ns(record["measurement"]["average_ns_per_run"]),
                "yes" if probe.get("recompile_applied") else "no",
                *[record["directive_scan"].get(field, 0) for _, field in FAMILY_FIELDS],
            ]
        )
        lines.extend(
            [
                "## Measured Programs",
                "",
            ]
        )
        lines.extend(
            markdown_table(
                [
                    "Program",
                    "Section",
                    "Trigger",
                    "Runs",
                    "Run time ns",
                    "Avg ns/run",
                    "Recompile Applied",
                    *[label for label, _ in FAMILY_FIELDS],
                ],
                rows,
            )
        )
        lines.append("")

    if attach_failures:
        rows = [
            [
                f"{record['object_path']}:{record['program_name']}",
                record["section_name"],
                record["trigger_name"] or "n/a",
                record["measurement"]["error"],
            ]
            for record in attach_failures
        ]
        lines.extend(
            [
                "## Attach Or Measurement Failures",
                "",
            ]
        )
        lines.extend(markdown_table(["Program", "Section", "Trigger", "Failure"], rows))
        lines.append("")

    if skipped:
        rows = [
            [
                f"{record['object_path']}:{record['program_name']}",
                record["section_name"],
                record["skip_reason"],
            ]
            for record in skipped
        ]
        lines.extend(
            [
                "## Skipped Programs",
                "",
            ]
        )
        lines.extend(markdown_table(["Program", "Section", "Reason"], rows))
        lines.append("")

    if summary["failure_reasons"]:
        lines.extend(
            [
                "## Top Failure Reasons",
                "",
            ]
        )
        rows = [[reason, count] for reason, count in summary["failure_reasons"].items()]
        lines.extend(markdown_table(["Reason", "Count"], rows))
        lines.append("")

    lines.extend(
        [
            "## Notes",
            "",
            "- This harness measures tracing-style programs through load + attach + trigger, then reads `run_cnt` and `run_time_ns` from `bpf_prog_info`.",
            "- `--recompile-all` is probed separately through `micro_exec run-kernel --compile-only`; attached re-JIT plus re-measure is not implemented in this script yet.",
            "- Programs with placeholder section targets such as `kprobe/dummy_*` are skipped because the attach target is supplied dynamically by their original user-space tool.",
            "",
        ]
    )
    return "\n".join(lines)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    require_minimum(args.repeat, 1, "--repeat")

    ensure_root()

    runner = Path(args.runner).resolve() if args.runner else runner_binary_from_config()
    if not runner.exists():
        raise SystemExit(f"runner binary not found: {runner}")

    corpus_build_report = (
        Path(args.corpus_build_report).resolve() if args.corpus_build_report else None
    )
    inputs = discover_corpus_objects(ROOT_DIR, corpus_build_report=corpus_build_report)
    corpus_objects = list(inputs.corpus_paths)
    if args.filters:
        corpus_objects = [
            path for path in corpus_objects
            if any(token in relpath(path) for token in args.filters)
        ]

    libbpf = Libbpf()
    program_records: list[dict[str, Any]] = []
    inventory_failures: list[dict[str, Any]] = []

    for object_path in corpus_objects:
        inventory = list_programs(runner, object_path, args.timeout)
        if not inventory["ok"]:
            inventory_failures.append(
                {
                    "object_path": relpath(object_path),
                    "error": inventory["error"],
                    "stderr_tail": summarize_stderr(inventory["stderr"]),
                }
            )
            continue

        for program in inventory.get("inventory", []):
            section_name = str(program.get("section_name", ""))
            if args.section_filters and not any(token in section_name for token in args.section_filters):
                continue
            root = normalize_section_root(section_name)
            if root not in SUPPORTED_ROOTS and root not in UNSUPPORTED_ROOTS:
                continue

            record: dict[str, Any] = {
                "object_path": relpath(object_path),
                "program_name": str(program.get("name", "")),
                "section_name": section_name,
                "section_root": root,
                "insn_count": int(program.get("insn_count", 0)),
            }
            trigger, skip_reason = choose_trigger(section_name, record["program_name"])
            record["trigger_name"] = trigger.name if trigger else None
            record["trigger_description"] = trigger.description if trigger else None
            record["skip_reason"] = skip_reason

            if args.skip_recompile_probe:
                record["recompile_probe"] = None
                record["directive_scan"] = {
                    **{field: 0 for _, field in FAMILY_FIELDS},
                    "total_sites": 0,
                }
            else:
                probe = run_recompile_probe(runner, object_path, record["program_name"], args.timeout)
                record["recompile_probe"] = probe
                record["directive_scan"] = probe["directive_scan"]

            if trigger is None:
                record["measurement"] = None
                program_records.append(record)
                if args.max_programs is not None and len(program_records) >= args.max_programs:
                    break
                continue

            try:
                record["measurement"] = measure_attached_program(
                    libbpf,
                    object_path,
                    record["program_name"],
                    trigger,
                    args.repeat,
                )
            except Exception as exc:  # pragma: no cover - surfaced in result JSON
                record["measurement"] = {
                    "ok": False,
                    "error": str(exc),
                }

            program_records.append(record)
            if args.max_programs is not None and len(program_records) >= args.max_programs:
                break

        if args.max_programs is not None and len(program_records) >= args.max_programs:
            break

    summary = build_summary(program_records)

    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    ensure_parent(output_json)
    ensure_parent(output_md)

    data = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "repo_root": str(Path(__file__).resolve().parent.parent),
        "runner_binary": str(runner),
        "corpus_source": inputs.corpus_source,
        "repeat": args.repeat,
        "objects_found": len(corpus_objects),
        "inventory_failures": inventory_failures,
        "summary": summary,
        "programs": program_records,
    }

    output_json.write_text(json.dumps(data, indent=2) + "\n")
    output_md.write_text(build_markdown(data) + "\n")

    print(f"Wrote {output_json}")
    print(f"Wrote {output_md}")
    print(
        f"Programs found={summary['programs_found']} "
        f"measured={summary['measured_programs']} "
        f"positive_runs={summary['programs_with_positive_runs']}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
