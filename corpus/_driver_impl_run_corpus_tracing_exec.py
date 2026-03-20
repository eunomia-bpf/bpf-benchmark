#!/usr/bin/env python3
from __future__ import annotations

import argparse
import ctypes
import ctypes.util
import json
import mmap
import os
import re
import socket
import subprocess
import sys
import tempfile
import time
from collections import Counter
from dataclasses import asdict, dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Callable

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

try:
    from results_layout import authoritative_candidates, authoritative_output_path, smoke_output_path
except ImportError:
    from corpus.results_layout import authoritative_candidates, authoritative_output_path, smoke_output_path

from e2e.common import ensure_root, resolve_bpftool_binary, write_json, write_text
from e2e.common.recompile import apply_recompile, scan_programs
from e2e.common.vm import run_in_vm, write_guest_script
from directive_census import filter_bpf_paths

try:
    from _driver_impl_run_corpus_perf import markdown_table, runner_binary_from_config
    from _driver_impl_run_corpus_tracing import (
        BPF_STATS_RUN_TIME,
        BpfProgInfo,
        decode_c_string,
        generic_syscall_mix,
        libbpf_error_string,
        run_disk_io,
        run_execve,
        run_futex_activity,
        run_open_close,
        run_signal_syscalls,
        run_tcp_loopback,
        unlink_tempfile,
        write_devnull,
    )
except ImportError:
    from corpus._driver_impl_run_corpus_perf import (
        markdown_table,
        runner_binary_from_config,
    )
    from corpus._driver_impl_run_corpus_tracing import (
        BPF_STATS_RUN_TIME,
        BpfProgInfo,
        decode_c_string,
        generic_syscall_mix,
        libbpf_error_string,
        run_disk_io,
        run_execve,
        run_futex_activity,
        run_open_close,
        run_signal_syscalls,
        run_tcp_loopback,
        unlink_tempfile,
        write_devnull,
    )

try:
    from orchestrator.inventory import discover_object_programs
except ImportError:
    from micro.orchestrator.inventory import discover_object_programs
try:
    from common import (
        add_corpus_build_report_argument,
        add_filter_argument,
        add_max_programs_argument,
        add_output_json_argument,
        add_output_md_argument,
        add_repeat_argument,
        add_runner_argument,
        add_scanner_argument,
        add_section_filter_argument,
        add_timeout_argument,
        format_ratio,
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
        add_scanner_argument,
        add_section_filter_argument,
        add_timeout_argument,
        format_ratio,
        require_minimum,
    )


ROOT_DIR = REPO_ROOT
DEFAULT_OUTPUT_JSON = authoritative_output_path(ROOT_DIR / "corpus" / "results", "tracing_exec_driver")
DEFAULT_OUTPUT_MD = ROOT_DIR / "corpus" / "results" / "tracing_exec_driver.md"
DEFAULT_SCANNER = ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"
DEFAULT_VM_KERNEL = ROOT_DIR / "vendor" / "linux-framework"
DEFAULT_REPEAT = 100
DEFAULT_WARMUP_REPEAT = 10
DEFAULT_TIMEOUT_SECONDS = 120
DEFAULT_VM_TIMEOUT_SECONDS = 3600
DEFAULT_VM_CPUS = 2
DEFAULT_VM_MEM = "4G"
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
MPROTECT_READ = 1
MREMAP_PROT_EXEC = 4
PR_SET_NAME = 15
SYS_TRACE_EVENTS = (
    Path("/sys/kernel/tracing/events"),
    Path("/sys/kernel/debug/tracing/events"),
)

TARGET_SECTION_ROOTS = {
    "fentry",
    "fexit",
    "fmod_ret",
    "kprobe",
    "kretprobe",
    "ksyscall",
    "kretsyscall",
    "lsm",
    "raw_tp",
    "raw_tracepoint",
    "tp",
    "tp_btf",
    "tracepoint",
}

SYSCALL_PREFIXES = (
    "__x64_sys_",
    "__ia32_sys_",
    "__arm64_sys_",
    "__se_sys_",
    "__do_sys_",
    "__sys_",
    "sys_",
    "ksys_",
    "do_sys_",
)

PLACEHOLDER_SYMBOL_CANDIDATES = {
    "dummy_file_read": [
        "ext4_file_read_iter",
        "xfs_file_read_iter",
        "btrfs_file_read_iter",
        "f2fs_file_read_iter",
        "fuse_file_read_iter",
        "nfs_file_read",
        "bch2_read_iter",
        "zpl_iter_read",
    ],
    "dummy_file_write": [
        "ext4_file_write_iter",
        "xfs_file_write_iter",
        "btrfs_file_write_iter",
        "f2fs_file_write_iter",
        "fuse_file_write_iter",
        "nfs_file_write",
        "bch2_write_iter",
        "zpl_iter_write",
    ],
    "dummy_file_open": [
        "ext4_file_open",
        "xfs_file_open",
        "btrfs_file_open",
        "f2fs_file_open",
        "fuse_open",
        "nfs_file_open",
        "bch2_open",
        "zpl_open",
    ],
    "dummy_file_sync": [
        "ext4_sync_file",
        "xfs_file_fsync",
        "btrfs_sync_file",
        "f2fs_sync_file",
        "fuse_fsync",
        "nfs_file_fsync",
        "bch2_fsync",
        "zpl_fsync",
    ],
    "dummy_getattr": [
        "ext4_file_getattr",
        "f2fs_getattr",
        "nfs_getattr",
        "fuse_getattr",
        "bch2_getattr",
    ],
    "dummy_kprobe": [
        "__x64_sys_getpid",
        "__x64_sys_getuid",
        "__x64_sys_getpgid",
        "do_nanosleep",
        "vfs_read",
        "vfs_write",
    ],
    "dummy_kretprobe": [
        "__x64_sys_getpid",
        "__x64_sys_getuid",
        "__x64_sys_getpgid",
        "do_nanosleep",
        "vfs_read",
        "vfs_write",
    ],
    "dummy_fentry": [
        "__x64_sys_getpid",
        "__x64_sys_getuid",
        "__x64_sys_getpgid",
        "do_nanosleep",
        "vfs_read",
        "vfs_write",
    ],
    "dummy_fexit": [
        "__x64_sys_getpid",
        "__x64_sys_getuid",
        "__x64_sys_getpgid",
        "do_nanosleep",
        "vfs_read",
        "vfs_write",
    ],
    "foo": [
        "__x64_sys_getpid",
        "__x64_sys_getuid",
        "__x64_sys_getpgid",
        "do_nanosleep",
        "vfs_read",
        "vfs_write",
    ],
}


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Load corpus tracing-style BPF programs with libbpf, attach them to real "
            "kernel hooks, trigger workloads, and compare baseline vs v5 recompile "
            "using bpf_prog_info run_cnt/run_time_ns."
        )
    )
    add_output_json_argument(parser, DEFAULT_OUTPUT_JSON)
    add_output_md_argument(parser, DEFAULT_OUTPUT_MD)
    add_runner_argument(parser, help_text="Path to the micro_exec runner used for list-programs.")
    add_scanner_argument(parser, DEFAULT_SCANNER, help_text="Path to the bpf-jit-scanner binary.")
    add_corpus_build_report_argument(
        parser,
        help_text=(
            "Optional expanded corpus build JSON report. When omitted, "
            "the newest existing expanded_corpus_build authoritative JSON is used if present."
        ),
    )
    add_repeat_argument(parser, DEFAULT_REPEAT, help_text="Measurement workload iterations per phase.")
    parser.add_argument(
        "--warmup-repeat",
        type=int,
        default=DEFAULT_WARMUP_REPEAT,
        help="Warmup workload iterations before baseline and recompile phases.",
    )
    add_timeout_argument(parser, DEFAULT_TIMEOUT_SECONDS, help_text="Per-program timeout budget in seconds.")
    add_filter_argument(parser, help_text="Only include objects/programs containing this substring.")
    parser.add_argument("--source", action="append", dest="sources", help="Only include corpus/build/<source>/... objects.")
    add_section_filter_argument(parser, help_text="Only include matching section names.")
    parser.add_argument("--root", action="append", dest="roots", help="Only include canonical section roots.")
    add_max_programs_argument(parser, help_text="Optional cap for smoke tests.")
    parser.add_argument("--vm", action="store_true", help="Run inside a virtme-ng guest.")
    parser.add_argument("--kernel", default=str(DEFAULT_VM_KERNEL), help="Kernel tree or bzImage used with --vm.")
    parser.add_argument("--cpus", type=int, default=DEFAULT_VM_CPUS, help="Guest CPU count for --vm.")
    parser.add_argument("--mem", default=DEFAULT_VM_MEM, help="Guest memory size for --vm.")
    parser.add_argument("--vm-timeout", type=int, default=DEFAULT_VM_TIMEOUT_SECONDS, help="Wall-clock timeout for the vng guest.")
    parser.add_argument("--guest", action="store_true", help=argparse.SUPPRESS)
    return parser.parse_args(argv)


def canonical_section_root(section_name: str) -> str:
    raw_root = section_name.split("/", 1)[0] if section_name else ""
    alias_map = {
        "fentry.s": "fentry",
        "fexit.s": "fexit",
        "fmod_ret.s": "fmod_ret",
        "lsm.s": "lsm",
        "raw_tracepoint.w": "raw_tracepoint",
    }
    if raw_root in alias_map:
        return alias_map[raw_root]
    if raw_root.startswith("kprobe"):
        return "kprobe"
    if raw_root.startswith("kretprobe"):
        return "kretprobe"
    if raw_root.startswith("ksyscall"):
        return "ksyscall"
    if raw_root.startswith("kretsyscall"):
        return "kretsyscall"
    if raw_root.startswith("raw_tp"):
        return "raw_tp"
    return raw_root


def relpath(path: Path) -> str:
    try:
        return path.relative_to(ROOT_DIR).as_posix()
    except ValueError:
        return str(path)


def format_avg_ns(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.2f}"


def speedup_ratio(baseline_avg_ns: float | None, recompile_avg_ns: float | None) -> float | None:
    if baseline_avg_ns is None or recompile_avg_ns is None or recompile_avg_ns <= 0:
        return None
    return float(baseline_avg_ns) / float(recompile_avg_ns)


def section_target(section_name: str) -> str:
    return section_name.split("/", 1)[1] if "/" in section_name else ""


def split_tracepoint_target(target: str) -> tuple[str | None, str | None]:
    if not target or "/" not in target:
        return None, None
    category, name = target.split("/", 1)
    if not category or not name:
        return None, None
    return category, name


def infer_syscall_name(text: str) -> str | None:
    lowered = text.lower()
    for pattern in (
        r"(?:sys_enter_|sys_exit_)([a-z0-9_]+)$",
        r"(?:__x64_sys_|__ia32_sys_|__arm64_sys_|__se_sys_|__do_sys_|__sys_|sys_|ksys_|do_sys_)([a-z0-9_]+)$",
    ):
        match = re.search(pattern, lowered)
        if match:
            return match.group(1)
    if lowered in {
        "getpid",
        "getppid",
        "getuid",
        "geteuid",
        "getgid",
        "getegid",
        "getpgid",
        "open",
        "openat",
        "openat2",
        "close",
        "read",
        "write",
        "execve",
        "nanosleep",
        "kill",
        "tgkill",
        "futex",
        "statx",
        "newfstatat",
        "unlink",
        "unlinkat",
        "mkdir",
        "mkdirat",
    }:
        return lowered
    return None


def symbol_tokens(text: str) -> set[str]:
    lowered = re.sub(r"[^a-z0-9_]+", "_", text.lower())
    return {token for token in lowered.split("_") if token}


class KernelCatalog:
    def __init__(self) -> None:
        self._symbols = self._load_symbols()

    @staticmethod
    def _load_symbols() -> set[str]:
        path = Path("/proc/kallsyms")
        if not path.exists():
            return set()
        symbols: set[str] = set()
        try:
            with path.open("r", encoding="utf-8", errors="replace") as handle:
                for line in handle:
                    parts = line.strip().split()
                    if len(parts) >= 3:
                        symbols.add(parts[2])
        except OSError:
            return set()
        return symbols

    def pick_symbol(self, candidates: list[str]) -> str | None:
        for candidate in candidates:
            if candidate in self._symbols:
                return candidate
        return None

    def has_tracepoint(self, category: str, name: str) -> bool:
        for base in SYS_TRACE_EVENTS:
            try:
                if (base / category / name).exists():
                    return True
            except OSError:
                continue
        return False


@dataclass(frozen=True)
class ResolvedAttachTarget:
    section_root: str
    attach_kind: str
    target: str
    target_source: str
    category: str | None = None
    name: str | None = None
    retprobe: bool = False

    def to_dict(self) -> dict[str, Any]:
        return asdict(self)


@dataclass(frozen=True)
class WorkloadPlan:
    name: str
    description: str
    execute: Callable[[Path, int], None]


class BpfKsyscallOpts(ctypes.Structure):
    _fields_ = [
        ("sz", ctypes.c_size_t),
        ("bpf_cookie", ctypes.c_uint64),
        ("retprobe", ctypes.c_bool),
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
        self.lib.bpf_program__set_attach_target.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_char_p]
        self.lib.bpf_program__set_attach_target.restype = ctypes.c_int
        self.lib.bpf_program__fd.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__fd.restype = ctypes.c_int
        self.lib.bpf_program__attach.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__attach.restype = ctypes.c_void_p
        self.lib.bpf_program__attach_lsm.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__attach_lsm.restype = ctypes.c_void_p
        self.lib.bpf_program__attach_kprobe.argtypes = [ctypes.c_void_p, ctypes.c_bool, ctypes.c_char_p]
        self.lib.bpf_program__attach_kprobe.restype = ctypes.c_void_p
        self.lib.bpf_program__attach_ksyscall.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.POINTER(BpfKsyscallOpts)]
        self.lib.bpf_program__attach_ksyscall.restype = ctypes.c_void_p
        self.lib.bpf_program__attach_tracepoint.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_char_p]
        self.lib.bpf_program__attach_tracepoint.restype = ctypes.c_void_p
        self.lib.bpf_program__attach_raw_tracepoint.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
        self.lib.bpf_program__attach_raw_tracepoint.restype = ctypes.c_void_p
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
    def __init__(
        self,
        libbpf: Libbpf,
        object_path: Path,
        program_name: str,
        attach_target: ResolvedAttachTarget,
    ) -> None:
        self.libbpf = libbpf
        self.object_path = object_path
        self.program_name = program_name
        self.attach_target = attach_target
        self.object_ptr: int | None = None
        self.program_ptr: int | None = None
        self.link_ptr: int | None = None
        self.prog_fd = -1
        self.stats_fd = -1
        self.prog_id = -1

    def __enter__(self) -> "LoadedTracingProgram":
        try:
            object_ptr = self.libbpf.lib.bpf_object__open_file(str(self.object_path).encode(), None)
            open_error = self.libbpf.pointer_error(object_ptr)
            if open_error != 0:
                raise RuntimeError(f"bpf_object__open_file failed: {libbpf_error_string(open_error)}")
            self.object_ptr = object_ptr

            desired_name = self.program_name.encode()
            program_ptr = self.libbpf.lib.bpf_object__find_program_by_name(self.object_ptr, desired_name)
            if not program_ptr:
                raise RuntimeError(f"program not found in object: {self.program_name}")
            self.program_ptr = program_ptr

            current_ptr = ctypes.c_void_p()
            while True:
                current_ptr = ctypes.c_void_p(self.libbpf.lib.bpf_object__next_program(self.object_ptr, current_ptr))
                if not current_ptr.value:
                    break
                current_name = decode_c_string(self.libbpf.lib.bpf_program__name(current_ptr))
                rc = self.libbpf.lib.bpf_program__set_autoload(current_ptr, current_name == self.program_name)
                if rc != 0:
                    raise RuntimeError(f"bpf_program__set_autoload failed for {current_name}: {libbpf_error_string(rc)}")

            if self.attach_target.attach_kind in {"trace", "lsm"}:
                rc = self.libbpf.lib.bpf_program__set_attach_target(
                    self.program_ptr,
                    0,
                    self.attach_target.target.encode(),
                )
                if rc != 0:
                    raise RuntimeError(f"bpf_program__set_attach_target failed: {libbpf_error_string(rc)}")

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
            self.prog_id = int(self.libbpf.get_prog_info(self.prog_fd).id)

            self.link_ptr = self._attach_program()
            return self
        except Exception:
            self.__exit__(None, None, None)
            raise

    def _attach_program(self) -> int:
        if self.attach_target.attach_kind == "kprobe":
            link_ptr = self.libbpf.lib.bpf_program__attach_kprobe(
                self.program_ptr,
                self.attach_target.retprobe,
                self.attach_target.target.encode(),
            )
        elif self.attach_target.attach_kind == "ksyscall":
            opts = BpfKsyscallOpts(
                sz=ctypes.sizeof(BpfKsyscallOpts),
                bpf_cookie=0,
                retprobe=self.attach_target.retprobe,
            )
            link_ptr = self.libbpf.lib.bpf_program__attach_ksyscall(
                self.program_ptr,
                self.attach_target.target.encode(),
                ctypes.byref(opts),
            )
        elif self.attach_target.attach_kind == "tracepoint":
            link_ptr = self.libbpf.lib.bpf_program__attach_tracepoint(
                self.program_ptr,
                (self.attach_target.category or "").encode(),
                (self.attach_target.name or "").encode(),
            )
        elif self.attach_target.attach_kind == "raw_tracepoint":
            link_ptr = self.libbpf.lib.bpf_program__attach_raw_tracepoint(
                self.program_ptr,
                self.attach_target.target.encode(),
            )
        elif self.attach_target.attach_kind == "lsm":
            link_ptr = self.libbpf.lib.bpf_program__attach_lsm(self.program_ptr)
        else:
            link_ptr = self.libbpf.lib.bpf_program__attach(self.program_ptr)

        attach_error = self.libbpf.pointer_error(link_ptr)
        if attach_error != 0:
            raise RuntimeError(f"attach failed: {libbpf_error_string(attach_error)}")
        return int(ctypes.cast(link_ptr, ctypes.c_void_p).value or 0)

    def prog_info(self) -> BpfProgInfo:
        return self.libbpf.get_prog_info(self.prog_fd)

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


def run_getpid_loop(workdir: Path, repeat: int) -> None:
    del workdir
    for _ in range(repeat):
        os.getpid()


def run_getuid_loop(workdir: Path, repeat: int) -> None:
    del workdir
    for _ in range(repeat):
        os.getuid()


def run_getpgid_loop(workdir: Path, repeat: int) -> None:
    del workdir
    for _ in range(repeat):
        os.getpgid(0)


def run_read_tempfile(workdir: Path, repeat: int) -> None:
    path = workdir / "read-source.bin"
    if not path.exists():
        path.write_bytes(b"read-source" * 512)
    for _ in range(repeat):
        with path.open("rb", buffering=0) as handle:
            while handle.read(8192):
                pass


def run_close_loop(workdir: Path, repeat: int) -> None:
    del workdir
    for _ in range(repeat):
        fd = os.open("/dev/null", os.O_RDONLY | os.O_CLOEXEC)
        os.close(fd)


def run_stat_tempfile(workdir: Path, repeat: int) -> None:
    path = workdir / "stat-target.bin"
    if not path.exists():
        path.write_bytes(b"stat-target")
    for _ in range(repeat):
        path.stat()


def run_create_unlink(workdir: Path, repeat: int) -> None:
    for index in range(repeat):
        path = workdir / f"create-{index}.tmp"
        with path.open("wb", buffering=0) as handle:
            handle.write(b"x")
        path.unlink(missing_ok=True)


def run_fsync_loop(workdir: Path, repeat: int) -> None:
    payload = b"\0" * 4096
    for index in range(repeat):
        path = workdir / f"fsync-{index}.bin"
        fd = os.open(path, os.O_CREAT | os.O_TRUNC | os.O_WRONLY | os.O_CLOEXEC, 0o600)
        try:
            os.write(fd, payload)
            os.fsync(fd)
        finally:
            os.close(fd)
        path.unlink(missing_ok=True)


def run_socket_create(workdir: Path, repeat: int) -> None:
    del workdir
    for _ in range(repeat):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.close()


def run_socket_bind(workdir: Path, repeat: int) -> None:
    del workdir
    for _ in range(repeat):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            sock.bind(("127.0.0.1", 0))
        finally:
            sock.close()


def run_nanosleep_loop(workdir: Path, repeat: int) -> None:
    del workdir
    libc = ctypes.CDLL(ctypes.util.find_library("c") or "libc.so.6", use_errno=True)

    class Timespec(ctypes.Structure):
        _fields_ = [("tv_sec", ctypes.c_long), ("tv_nsec", ctypes.c_long)]

    req = Timespec(0, 1)
    rem = Timespec(0, 0)
    libc.nanosleep.argtypes = [ctypes.POINTER(Timespec), ctypes.POINTER(Timespec)]
    libc.nanosleep.restype = ctypes.c_int
    for _ in range(repeat):
        libc.nanosleep(ctypes.byref(req), ctypes.byref(rem))


def run_prctl_set_name(workdir: Path, repeat: int) -> None:
    del workdir
    libc = ctypes.CDLL(ctypes.util.find_library("c") or "libc.so.6", use_errno=True)
    libc.prctl.argtypes = [
        ctypes.c_int,
        ctypes.c_ulong,
        ctypes.c_ulong,
        ctypes.c_ulong,
        ctypes.c_ulong,
    ]
    libc.prctl.restype = ctypes.c_int
    for index in range(repeat):
        name = f"jit{index % 10000}".encode()
        buffer = ctypes.create_string_buffer(name)
        rc = libc.prctl(PR_SET_NAME, ctypes.cast(buffer, ctypes.c_void_p).value or 0, 0, 0, 0)
        if rc != 0:
            err = ctypes.get_errno()
            raise RuntimeError(f"prctl(PR_SET_NAME) failed: {os.strerror(err)}")


def run_mprotect_loop(workdir: Path, repeat: int) -> None:
    del workdir
    page_size = mmap.PAGESIZE
    mm = mmap.mmap(-1, page_size, prot=mmap.PROT_READ | mmap.PROT_WRITE)
    libc = ctypes.CDLL(ctypes.util.find_library("c") or "libc.so.6", use_errno=True)
    libc.mprotect.argtypes = [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_int]
    libc.mprotect.restype = ctypes.c_int
    base = ctypes.addressof(ctypes.c_char.from_buffer(mm))
    try:
        for _ in range(repeat):
            for prot in (mmap.PROT_READ, mmap.PROT_READ | mmap.PROT_WRITE):
                rc = libc.mprotect(base, page_size, prot)
                if rc != 0:
                    err = ctypes.get_errno()
                    raise RuntimeError(f"mprotect failed: {os.strerror(err)}")
    finally:
        mm.close()


def run_bpftool_show(workdir: Path, repeat: int) -> None:
    del workdir
    bpftool = resolve_bpftool_binary()
    for _ in range(repeat):
        completed = subprocess.run(
            [bpftool, "prog", "show"],
            capture_output=True,
            text=True,
            check=False,
            timeout=30,
        )
        if completed.returncode != 0:
            tail = (completed.stderr or completed.stdout).strip()[-4000:]
            raise RuntimeError(f"bpftool prog show failed: {tail}")


def run_bpftool_map_show(workdir: Path, repeat: int) -> None:
    del workdir
    bpftool = resolve_bpftool_binary()
    for _ in range(repeat):
        completed = subprocess.run(
            [bpftool, "map", "show"],
            capture_output=True,
            text=True,
            check=False,
            timeout=30,
        )
        if completed.returncode != 0:
            tail = (completed.stderr or completed.stdout).strip()[-4000:]
            raise RuntimeError(f"bpftool map show failed: {tail}")


def run_cgroup_mkdir(workdir: Path, repeat: int) -> None:
    del workdir
    base = Path("/sys/fs/cgroup")
    if not base.exists():
        raise RuntimeError("/sys/fs/cgroup is unavailable")
    for index in range(repeat):
        path = base / f"tracing-exec-{os.getpid()}-{index}"
        path.mkdir()
        path.rmdir()


WORKLOADS = {
    "bpf-show": WorkloadPlan("bpf-show", "run `bpftool prog show` repeatedly", run_bpftool_show),
    "bpf-map-show": WorkloadPlan("bpf-map-show", "run `bpftool map show` repeatedly", run_bpftool_map_show),
    "cgroup-mkdir": WorkloadPlan("cgroup-mkdir", "create and remove cgroup directories", run_cgroup_mkdir),
    "close": WorkloadPlan("close", "open and close /dev/null repeatedly", run_close_loop),
    "create-unlink": WorkloadPlan("create-unlink", "create temporary files and unlink them", run_create_unlink),
    "disk-io": WorkloadPlan("disk-io", "write/fsync/read temporary files", run_disk_io),
    "execve": WorkloadPlan("execve", "spawn `/bin/true` repeatedly", run_execve),
    "fsync": WorkloadPlan("fsync", "fsync temporary files repeatedly", run_fsync_loop),
    "futex": WorkloadPlan("futex", "ping-pong a condition variable between threads", run_futex_activity),
    "generic-syscalls": WorkloadPlan("generic-syscalls", "mix open/read/write/unlink/kill syscalls", generic_syscall_mix),
    "getpgid": WorkloadPlan("getpgid", "call getpgid(0) repeatedly", run_getpgid_loop),
    "getpid": WorkloadPlan("getpid", "call getpid() repeatedly", run_getpid_loop),
    "getuid": WorkloadPlan("getuid", "call getuid() repeatedly", run_getuid_loop),
    "mprotect": WorkloadPlan("mprotect", "mprotect an anonymous mapping repeatedly", run_mprotect_loop),
    "nanosleep": WorkloadPlan("nanosleep", "call nanosleep() repeatedly", run_nanosleep_loop),
    "open-close": WorkloadPlan("open-close", "open and read a temporary file repeatedly", run_open_close),
    "prctl-set-name": WorkloadPlan("prctl-set-name", "change the current task name repeatedly", run_prctl_set_name),
    "read": WorkloadPlan("read", "read a temporary file repeatedly", run_read_tempfile),
    "signal": WorkloadPlan("signal", "issue signal syscalls against the current process", run_signal_syscalls),
    "socket-bind": WorkloadPlan("socket-bind", "create sockets and bind them to loopback", run_socket_bind),
    "socket-create": WorkloadPlan("socket-create", "create and close sockets repeatedly", run_socket_create),
    "stat": WorkloadPlan("stat", "stat a temporary file repeatedly", run_stat_tempfile),
    "tcp-loopback": WorkloadPlan("tcp-loopback", "connect/send/recv over a localhost TCP socket", run_tcp_loopback),
    "unlink": WorkloadPlan("unlink", "create and unlink temporary files", unlink_tempfile),
    "write": WorkloadPlan("write", "write a buffer to /dev/null repeatedly", write_devnull),
}


def resolve_placeholder_target(
    catalog: KernelCatalog,
    section_root: str,
    raw_target: str,
) -> tuple[str | None, str | None]:
    chosen = catalog.pick_symbol(PLACEHOLDER_SYMBOL_CANDIDATES.get(raw_target, []))
    if chosen:
        return chosen, f"placeholder `{raw_target}` -> `{chosen}`"
    if raw_target.startswith("dummy_"):
        return None, f"no kernel symbol candidate resolved for placeholder `{raw_target}`"
    return None, f"dynamic target placeholder `{raw_target}` is unsupported"


def resolve_attach_target(
    catalog: KernelCatalog,
    object_path: Path,
    program_name: str,
    section_name: str,
) -> tuple[ResolvedAttachTarget | None, str | None]:
    del object_path, program_name
    section_root = canonical_section_root(section_name)
    if section_root not in TARGET_SECTION_ROOTS:
        return None, f"unsupported section root `{section_root}`"

    raw_target = section_target(section_name)
    if not raw_target:
        return None, "missing attach target in section name"

    target = raw_target
    target_source = "section"
    if raw_target.startswith("dummy_") or raw_target == "foo":
        target, reason = resolve_placeholder_target(catalog, section_root, raw_target)
        if target is None:
            return None, reason
        target_source = "placeholder"

    if section_root in {"tracepoint", "tp"}:
        category, name = split_tracepoint_target(target)
        if category is None or name is None:
            return None, f"invalid tracepoint target `{target}`"
        if not catalog.has_tracepoint(category, name):
            return None, f"tracepoint `{category}/{name}` is unavailable on this kernel"
        return ResolvedAttachTarget(
            section_root=section_root,
            attach_kind="tracepoint",
            target=target,
            target_source=target_source,
            category=category,
            name=name,
        ), None

    if section_root in {"raw_tp", "raw_tracepoint"}:
        return ResolvedAttachTarget(
            section_root=section_root,
            attach_kind="raw_tracepoint",
            target=target,
            target_source=target_source,
        ), None

    if section_root in {"kprobe", "kretprobe"}:
        return ResolvedAttachTarget(
            section_root=section_root,
            attach_kind="kprobe",
            target=target,
            target_source=target_source,
            retprobe=section_root == "kretprobe",
        ), None

    if section_root in {"ksyscall", "kretsyscall"}:
        syscall_name = infer_syscall_name(target)
        if syscall_name is None:
            return None, f"could not infer syscall name from `{target}`"
        return ResolvedAttachTarget(
            section_root=section_root,
            attach_kind="ksyscall",
            target=syscall_name,
            target_source=target_source,
            retprobe=section_root == "kretsyscall",
        ), None

    if section_root == "lsm":
        return ResolvedAttachTarget(
            section_root=section_root,
            attach_kind="lsm",
            target=target,
            target_source=target_source,
        ), None

    return ResolvedAttachTarget(
        section_root=section_root,
        attach_kind="trace",
        target=target,
        target_source=target_source,
    ), None


def workload_for_syscall(syscall_name: str) -> WorkloadPlan | None:
    mapping = {
        "close": WORKLOADS["close"],
        "execve": WORKLOADS["execve"],
        "futex": WORKLOADS["futex"],
        "getgid": WORKLOADS["getuid"],
        "getegid": WORKLOADS["getuid"],
        "geteuid": WORKLOADS["getuid"],
        "getpgid": WORKLOADS["getpgid"],
        "getpid": WORKLOADS["getpid"],
        "getppid": WORKLOADS["getpid"],
        "getuid": WORKLOADS["getuid"],
        "mkdir": WORKLOADS["create-unlink"],
        "mkdirat": WORKLOADS["create-unlink"],
        "nanosleep": WORKLOADS["nanosleep"],
        "newfstatat": WORKLOADS["stat"],
        "open": WORKLOADS["open-close"],
        "openat": WORKLOADS["open-close"],
        "openat2": WORKLOADS["open-close"],
        "read": WORKLOADS["read"],
        "statx": WORKLOADS["stat"],
        "tgkill": WORKLOADS["signal"],
        "unlink": WORKLOADS["unlink"],
        "unlinkat": WORKLOADS["unlink"],
        "write": WORKLOADS["write"],
    }
    return mapping.get(syscall_name)


def choose_workload(
    attach_target: ResolvedAttachTarget,
    program_name: str,
    section_name: str,
) -> tuple[WorkloadPlan | None, str | None]:
    raw_target = attach_target.target.lower()
    program_lower = program_name.lower()
    category = (attach_target.category or "").lower()
    name = (attach_target.name or "").lower()
    combined = f"{raw_target} {program_lower} {category} {name}"
    tokens = symbol_tokens(combined)

    syscall_name = infer_syscall_name(raw_target) or infer_syscall_name(name)
    if syscall_name:
        plan = workload_for_syscall(syscall_name)
        if plan is not None:
            return plan, None

    if category == "syscalls" and name in {"sys_enter", "sys_exit"}:
        return WORKLOADS["generic-syscalls"], None
    if category == "raw_syscalls":
        return WORKLOADS["generic-syscalls"], None
    if category == "sched" and name in {"sched_process_exec", "sched_process_exit", "sched_process_fork"}:
        return WORKLOADS["execve"], None
    if category == "sched" and name in {"sched_switch", "sched_wakeup", "sched_wakeup_new"}:
        return WORKLOADS["execve"], None
    if category == "sock":
        return WORKLOADS["tcp-loopback"], None
    if category == "block":
        return WORKLOADS["disk-io"], None
    if category == "cgroup" and name == "cgroup_mkdir":
        return WORKLOADS["cgroup-mkdir"], None

    if raw_target in {"sys_enter", "sys_exit"}:
        return WORKLOADS["generic-syscalls"], None
    if "consume" in tokens and "skb" in tokens:
        return WORKLOADS["tcp-loopback"], None
    if "inet" in tokens and "state" in tokens:
        return WORKLOADS["tcp-loopback"], None

    if "set" in tokens and "task" in tokens and "comm" in tokens:
        return WORKLOADS["prctl-set-name"], None
    if "nanosleep" in tokens:
        return WORKLOADS["nanosleep"], None
    if "futex" in tokens:
        return WORKLOADS["futex"], None
    if "mprotect" in tokens:
        return WORKLOADS["mprotect"], None
    if "bpf" in tokens and "map" in tokens:
        return WORKLOADS["bpf-map-show"], None
    if attach_target.section_root == "lsm" and raw_target == "bpf":
        return WORKLOADS["bpf-show"], None
    if "bprm" in tokens or "exec" in tokens or "task" in tokens and ("newtask" in tokens or "free" in tokens):
        return WORKLOADS["execve"], None
    if "sched" in tokens and {"switch", "wakeup"} & tokens:
        return WORKLOADS["execve"], None
    if "kill" in tokens or "tgkill" in tokens:
        return WORKLOADS["signal"], None
    if "socket" in tokens and "post" in tokens and "create" in tokens:
        return WORKLOADS["socket-create"], None
    if "socket" in tokens and "bind" in tokens:
        return WORKLOADS["socket-bind"], None
    if "socket" in tokens or "tcp" in tokens or "connect" in tokens or "accept" in tokens or "sock" in tokens:
        return WORKLOADS["tcp-loopback"], None
    if "cgroup" in tokens and "mkdir" in tokens:
        return WORKLOADS["cgroup-mkdir"], None
    if "unlink" in tokens:
        return WORKLOADS["unlink"], None
    if "create" in tokens or "mkdir" in tokens:
        return WORKLOADS["create-unlink"], None
    if "getattr" in tokens or "stat" in tokens:
        return WORKLOADS["stat"], None
    if "open" in tokens:
        return WORKLOADS["open-close"], None
    if "permission" in tokens:
        return WORKLOADS["read"], None
    if "read" in tokens:
        return WORKLOADS["read"], None
    if "write" in tokens:
        return WORKLOADS["write"], None
    if "fsync" in tokens or "sync" in tokens:
        return WORKLOADS["fsync"], None
    if {
        "block",
        "bio",
        "folio",
        "filemap",
        "readahead",
        "page",
        "cache",
        "blk",
    } & tokens:
        return WORKLOADS["disk-io"], None

    return None, f"no workload heuristic for section `{section_name}` / program `{program_name}`"


def run_warmup(plan: WorkloadPlan, workdir: Path, repeat: int) -> None:
    if repeat <= 0:
        return
    plan.execute(workdir, repeat)


def measure_phase(
    loaded: LoadedTracingProgram,
    workdir: Path,
    plan: WorkloadPlan,
    repeat: int,
    warmup_repeat: int,
) -> dict[str, Any]:
    run_warmup(plan, workdir, warmup_repeat)
    before = loaded.prog_info()
    workload_start = time.monotonic()
    plan.execute(workdir, repeat)
    workload_seconds = time.monotonic() - workload_start
    time.sleep(0.02)
    after = loaded.prog_info()

    run_cnt_delta = int(after.run_cnt - before.run_cnt)
    run_time_ns_delta = int(after.run_time_ns - before.run_time_ns)
    average_ns_per_run = (
        float(run_time_ns_delta) / float(run_cnt_delta)
        if run_cnt_delta > 0 and run_time_ns_delta >= 0
        else None
    )
    return {
        "ok": True,
        "workload_seconds": workload_seconds,
        "run_cnt_before": int(before.run_cnt),
        "run_cnt_after": int(after.run_cnt),
        "run_cnt_delta": run_cnt_delta,
        "run_time_ns_before": int(before.run_time_ns),
        "run_time_ns_after": int(after.run_time_ns),
        "run_time_ns_delta": run_time_ns_delta,
        "average_ns_per_run": average_ns_per_run,
        "bytes_jited_after": int(after.jited_prog_len),
        "bytes_xlated_after": int(after.xlated_prog_len),
    }


def scanner_entry(
    program_results: dict[int, dict[str, object]],
    prog_id: int,
) -> dict[str, object]:
    return dict(
        program_results.get(
            int(prog_id),
            {
                "program_name": f"id-{prog_id}",
                "sites": {
                    "total_sites": 0,
                    **{field: 0 for _, field in FAMILY_FIELDS},
                },
                "error": "no scanner result",
                "stdout_tail": "",
                "stderr_tail": "",
            },
        )
    )


def summarize_program(record: dict[str, Any]) -> None:
    baseline = record.get("baseline_measurement") or {}
    recompile = record.get("recompile_measurement") or {}
    record["baseline_avg_ns"] = baseline.get("average_ns_per_run")
    record["recompile_avg_ns"] = recompile.get("average_ns_per_run")
    record["speedup"] = speedup_ratio(record["baseline_avg_ns"], record["recompile_avg_ns"])


def run_program(
    libbpf: Libbpf,
    object_path: Path,
    record: dict[str, Any],
    scanner_binary: Path,
    repeat: int,
    warmup_repeat: int,
) -> dict[str, Any]:
    attach_target = ResolvedAttachTarget(**record["attach_target"])
    plan = WORKLOADS[record["workload"]["name"]]
    with tempfile.TemporaryDirectory(prefix="tracing-exec-") as tempdir:
        workdir = Path(tempdir)
        attach_started = time.monotonic()
        with LoadedTracingProgram(libbpf, object_path, record["program_name"], attach_target) as loaded:
            record["attach_seconds"] = time.monotonic() - attach_started
            record["prog_id"] = int(loaded.prog_id)
            prog_fds = {int(loaded.prog_id): int(loaded.prog_fd)}

            record["scan"] = scanner_entry(scan_programs([loaded.prog_id], scanner_binary, prog_fds=prog_fds), loaded.prog_id)
            record["baseline_measurement"] = measure_phase(loaded, workdir, plan, repeat, warmup_repeat)
            record["recompile"] = scanner_entry(apply_recompile([loaded.prog_id], scanner_binary, prog_fds=prog_fds), loaded.prog_id)
            record["recompile_measurement"] = measure_phase(loaded, workdir, plan, repeat, warmup_repeat)

    summarize_program(record)
    if record["recompile"].get("applied") and record["recompile"]["counts"].get("total_sites", 0) > 0:
        record["status"] = "paired_applied"
    elif record["recompile"].get("applied"):
        record["status"] = "paired_no_sites"
    else:
        record["status"] = "paired_apply_failed"
    return record


def build_summary(records: list[dict[str, Any]], inventory_failures: list[dict[str, Any]]) -> dict[str, Any]:
    attached = [record for record in records if record.get("status", "").startswith("paired")]
    paired = [
        record for record in attached
        if record.get("baseline_avg_ns") is not None and record.get("recompile_avg_ns") is not None
    ]
    paired_applied = [
        record for record in paired
        if (record.get("recompile") or {}).get("applied")
        and ((record.get("recompile") or {}).get("counts") or {}).get("total_sites", 0) > 0
    ]
    skipped = [record for record in records if record.get("status") == "skipped"]
    failures = [record for record in records if record.get("status") == "failed"]
    zero_run = [
        record for record in attached
        if (record.get("baseline_measurement") or {}).get("run_cnt_delta", 0) == 0
        or (record.get("recompile_measurement") or {}).get("run_cnt_delta", 0) == 0
    ]

    speedups = [float(record["speedup"]) for record in paired if record.get("speedup") is not None]
    applied_speedups = [float(record["speedup"]) for record in paired_applied if record.get("speedup") is not None]

    failure_reasons = Counter()
    for record in skipped:
        failure_reasons[record.get("skip_reason") or "skipped"] += 1
    for record in failures:
        failure_reasons[record.get("error") or "failed"] += 1
    for failure in inventory_failures:
        failure_reasons[f"inventory failed: {failure.get('error') or 'unknown'}"] += 1

    def geomean(values: list[float]) -> float | None:
        import math
        import statistics

        positive = [value for value in values if value > 0]
        if not positive:
            return None
        return math.exp(statistics.mean(math.log(value) for value in positive))

    return {
        "programs_considered": len(records),
        "inventory_failures": len(inventory_failures),
        "skipped_programs": len(skipped),
        "attach_failures": len(failures),
        "attached_programs": len(attached),
        "paired_measurements": len(paired),
        "paired_applied_measurements": len(paired_applied),
        "zero_run_programs": len(zero_run),
        "speedup_geomean": geomean(speedups),
        "applied_speedup_geomean": geomean(applied_speedups),
        "failure_reasons": dict(failure_reasons.most_common(20)),
    }


def build_markdown(data: dict[str, Any]) -> str:
    summary = data["summary"]
    records = data["programs"]
    paired = [
        record
        for record in records
        if record.get("baseline_avg_ns") is not None and record.get("recompile_avg_ns") is not None
    ]
    paired.sort(
        key=lambda item: (
            -(item.get("scan") or {}).get("sites", {}).get("total_sites", 0),
            item.get("object_path", ""),
            item.get("program_name", ""),
        )
    )
    skipped = [record for record in records if record.get("status") == "skipped"]
    failures = [record for record in records if record.get("status") == "failed"]

    lines: list[str] = [
        "# Tracing Corpus Exec Driver Results",
        "",
        f"- Generated: {data['generated_at']}",
        f"- Mode: `{data['mode']}`",
        f"- Runner: `{data['runner_binary']}`",
        f"- Scanner: `{data['scanner_binary']}`",
        f"- Corpus source: {data['corpus_source']}",
        f"- Objects discovered: {data['objects_found']}",
        f"- Programs considered: {summary['programs_considered']}",
        f"- Attached programs: {summary['attached_programs']}",
        f"- Paired measurements: {summary['paired_measurements']}",
        f"- Paired measurements with applied v5 sites: {summary['paired_applied_measurements']}",
        f"- Attach failures: {summary['attach_failures']}",
        f"- Skipped programs: {summary['skipped_programs']}",
        f"- Zero-run programs: {summary['zero_run_programs']}",
        f"- Speedup geomean (baseline/recompile): {format_ratio(summary['speedup_geomean'])}",
        f"- Applied-only speedup geomean: {format_ratio(summary['applied_speedup_geomean'])}",
        "",
        "## Summary Statistics",
        "",
    ]
    lines.extend(
        markdown_table(
            ["Metric", "Value"],
            [
                ["Inventory failures", summary["inventory_failures"]],
                ["Failure reason buckets", len(summary["failure_reasons"])],
            ],
        )
    )
    lines.append("")

    if paired:
        rows = []
        for record in paired:
            scan_sites = ((record.get("scan") or {}).get("sites") or {})
            recompile = record.get("recompile") or {}
            rows.append(
                [
                    f"{record['object_path']}:{record['program_name']}",
                    record["section_name"],
                    record["workload"]["name"],
                    format_avg_ns(record.get("baseline_avg_ns")),
                    format_avg_ns(record.get("recompile_avg_ns")),
                    format_ratio(record.get("speedup")),
                    "yes" if recompile.get("applied") else "no",
                    scan_sites.get("total_sites", 0),
                    *[scan_sites.get(field, 0) for _, field in FAMILY_FIELDS],
                ]
            )
        lines.extend(["## Paired Measurements", ""])
        lines.extend(
            markdown_table(
                [
                    "Program",
                    "Section",
                    "Workload",
                    "Baseline ns",
                    "Recompile ns",
                    "Speedup",
                    "Applied",
                    "Sites",
                    *[label for label, _ in FAMILY_FIELDS],
                ],
                rows,
            )
        )
        lines.append("")

    if failures:
        rows = [
            [
                f"{record['object_path']}:{record['program_name']}",
                record["section_name"],
                record.get("workload", {}).get("name") or "n/a",
                record.get("error") or "unknown error",
            ]
            for record in failures
        ]
        lines.extend(["## Attach Or Measurement Failures", ""])
        lines.extend(markdown_table(["Program", "Section", "Workload", "Failure"], rows))
        lines.append("")

    if skipped:
        rows = [
            [
                f"{record['object_path']}:{record['program_name']}",
                record["section_name"],
                record.get("skip_reason") or "skipped",
            ]
            for record in skipped
        ]
        lines.extend(["## Skipped Programs", ""])
        lines.extend(markdown_table(["Program", "Section", "Reason"], rows))
        lines.append("")

    if summary["failure_reasons"]:
        rows = [[reason, count] for reason, count in summary["failure_reasons"].items()]
        lines.extend(["## Top Failure Reasons", ""])
        lines.extend(markdown_table(["Reason", "Count"], rows))
        lines.append("")

    lines.extend(
        [
            "## Notes",
            "",
            "- Each attached program is measured twice in one load session: baseline workload, then `scanner apply --all --v5`, then post-recompile workload.",
            "- Average exec time is derived from `bpf_prog_info.run_time_ns / run_cnt` deltas around each workload phase.",
            "- Programs that can be loaded but not matched to an attach target or workload are recorded with explicit skip reasons.",
            "",
        ]
    )
    return "\n".join(lines)


def apply_filters(
    corpus_objects: list[Path],
    *,
    sources: list[str] | None,
    filters: list[str] | None,
) -> list[Path]:
    selected = list(corpus_objects)
    if sources:
        wanted = {source.lower() for source in sources}
        selected = [
            path for path in selected
            if len(path.relative_to(ROOT_DIR / "corpus" / "build").parts) > 0
            and path.relative_to(ROOT_DIR / "corpus" / "build").parts[0].lower() in wanted
        ]
    if filters:
        lowered = [token.lower() for token in filters]
        selected = [
            path for path in selected
            if any(token in relpath(path).lower() for token in lowered)
        ]
    return selected


def discover_corpus_bpf_objects(corpus_build_report: Path | None) -> tuple[list[Path], list[str], str]:
    report_path = corpus_build_report
    if report_path is None:
        for candidate in authoritative_candidates(ROOT_DIR / "corpus" / "results", "expanded_corpus_build"):
            if candidate.exists():
                report_path = candidate
                break

    if report_path is not None and report_path.exists():
        payload = json.loads(report_path.read_text())
        summary = payload.get("summary") or {}
        raw_paths = summary.get("compiled_objects") or []
        if not raw_paths:
            raw_paths = [
                record["object_path"]
                for record in payload.get("records", [])
                if record.get("status") == "ok" and record.get("object_path")
            ]
        paths = [Path(item).resolve() for item in raw_paths if Path(item).exists()]
        kept, skipped = filter_bpf_paths(sorted(set(paths)), ROOT_DIR)
        return kept, skipped, f"expanded build report `{report_path}`"

    raw_paths = sorted((ROOT_DIR / "corpus" / "build").rglob("*.bpf.o"))
    kept, skipped = filter_bpf_paths(raw_paths, ROOT_DIR)
    return kept, skipped, "filesystem scan under `corpus/build`"


def run_vm_mode(args: argparse.Namespace) -> int:
    guest_command = [
        "python3",
        "micro/driver.py",
        "corpus",
        "tracing-exec",
        "--guest",
        "--output-json",
        str(Path(args.output_json).resolve()),
        "--output-md",
        str(Path(args.output_md).resolve()),
        "--scanner",
        str(Path(args.scanner).resolve()),
        "--repeat",
        str(int(args.repeat)),
        "--warmup-repeat",
        str(int(args.warmup_repeat)),
        "--timeout",
        str(int(args.timeout)),
    ]
    if args.runner:
        guest_command.extend(["--runner", str(Path(args.runner).resolve())])
    if args.corpus_build_report:
        guest_command.extend(["--corpus-build-report", str(Path(args.corpus_build_report).resolve())])
    if args.max_programs is not None:
        guest_command.extend(["--max-programs", str(int(args.max_programs))])
    for value in args.filters or []:
        guest_command.extend(["--filter", value])
    for value in args.sources or []:
        guest_command.extend(["--source", value])
    for value in args.section_filters or []:
        guest_command.extend(["--section-filter", value])
    for value in args.roots or []:
        guest_command.extend(["--root", value])

    guest_script = write_guest_script([guest_command])
    completed = run_in_vm(args.kernel, guest_script, args.cpus, args.mem, args.vm_timeout)
    sys.stdout.write(completed.stdout)
    sys.stderr.write(completed.stderr)
    if completed.returncode != 0:
        tail = (completed.stderr or completed.stdout).strip()[-4000:]
        raise SystemExit(f"vng run failed with exit {completed.returncode}: {tail}")
    return 0


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    require_minimum(args.repeat, 1, "--repeat")
    if args.warmup_repeat < 0:
        raise SystemExit("--warmup-repeat must be >= 0")

    if args.vm and not args.guest:
        return run_vm_mode(args)

    ensure_root(argv=[str(Path(__file__).resolve()), *list(argv or sys.argv[1:])])

    runner = Path(args.runner).resolve() if args.runner else runner_binary_from_config()
    if not runner.exists():
        raise SystemExit(f"runner binary not found: {runner}")

    scanner_binary = Path(args.scanner).resolve()
    if not scanner_binary.exists():
        raise SystemExit(f"scanner binary not found: {scanner_binary}")

    corpus_build_report = Path(args.corpus_build_report).resolve() if args.corpus_build_report else None
    corpus_bpf_objects, skipped_non_bpf, corpus_source = discover_corpus_bpf_objects(corpus_build_report)
    corpus_objects = apply_filters(
        corpus_bpf_objects,
        sources=args.sources,
        filters=args.filters,
    )

    selected_roots = {root.lower() for root in args.roots} if args.roots else None
    catalog = KernelCatalog()
    libbpf = Libbpf()
    records: list[dict[str, Any]] = []
    inventory_failures: list[dict[str, Any]] = []
    lowered_filters = [token.lower() for token in (args.filters or [])]

    for object_path in corpus_objects:
        try:
            inventory = discover_object_programs(runner, object_path, timeout_seconds=args.timeout)
        except Exception as exc:
            inventory_failures.append({"object_path": relpath(object_path), "error": str(exc)})
            continue

        for program in inventory:
            section_name = program.section_name
            if lowered_filters and not any(
                token in relpath(object_path).lower()
                or token in program.name.lower()
                or token in section_name.lower()
                for token in lowered_filters
            ):
                continue
            if args.section_filters and not any(token in section_name for token in args.section_filters):
                continue

            section_root = canonical_section_root(section_name)
            if section_root not in TARGET_SECTION_ROOTS:
                continue
            if selected_roots and section_root not in selected_roots:
                continue

            record: dict[str, Any] = {
                "object_path": relpath(object_path),
                "program_name": program.name,
                "section_name": section_name,
                "section_root": section_root,
                "insn_count": int(program.insn_count),
                "prog_type_name": str(program.prog_type_name),
                "attach_type_name": str(program.attach_type_name),
            }

            attach_target, skip_reason = resolve_attach_target(catalog, object_path, program.name, section_name)
            if attach_target is None:
                record["status"] = "skipped"
                record["skip_reason"] = skip_reason
                records.append(record)
                if args.max_programs is not None and len(records) >= args.max_programs:
                    break
                continue
            record["attach_target"] = attach_target.to_dict()

            workload, skip_reason = choose_workload(attach_target, program.name, section_name)
            if workload is None:
                record["status"] = "skipped"
                record["skip_reason"] = skip_reason
                records.append(record)
                if args.max_programs is not None and len(records) >= args.max_programs:
                    break
                continue
            record["workload"] = {"name": workload.name, "description": workload.description}

            try:
                run_program(
                    libbpf,
                    object_path,
                    record,
                    scanner_binary,
                    args.repeat,
                    args.warmup_repeat,
                )
            except Exception as exc:
                record["status"] = "failed"
                record["error"] = str(exc)
                summarize_program(record)
            records.append(record)

            if args.max_programs is not None and len(records) >= args.max_programs:
                break

        if args.max_programs is not None and len(records) >= args.max_programs:
            break

    summary = build_summary(records, inventory_failures)
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "mode": "vm-guest" if args.guest else "host",
        "repo_root": str(ROOT_DIR),
        "runner_binary": str(runner),
        "scanner_binary": str(scanner_binary),
        "corpus_source": corpus_source,
        "objects_found": len(corpus_objects),
        "skipped_non_bpf": skipped_non_bpf,
        "repeat": args.repeat,
        "warmup_repeat": args.warmup_repeat,
        "inventory_failures": inventory_failures,
        "summary": summary,
        "programs": records,
    }

    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.max_programs is not None:
        output_json = smoke_output_path(ROOT_DIR / "corpus" / "results", "tracing_exec_driver")
    else:
        output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    write_json(output_json, payload)
    write_text(output_md, build_markdown(payload) + "\n")
    print(f"Wrote {output_json}")
    print(f"Wrote {output_md}")
    print(
        f"considered={summary['programs_considered']} "
        f"attached={summary['attached_programs']} "
        f"paired={summary['paired_measurements']} "
        f"applied={summary['paired_applied_measurements']}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
