#!/usr/bin/env python3
from __future__ import annotations

import argparse
import ctypes
import ctypes.util
import json
import os
import platform
import re
import shutil
import signal
import subprocess
import sys
import tempfile
import threading
import time
from collections import Counter, deque
from dataclasses import asdict, dataclass
from datetime import datetime, timezone
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from typing import Any, Iterable, Mapping, Sequence

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

try:
    from runner.libs.commands import build_runner_command
    from runner.libs.environment import read_optional_text, read_required_text
    from runner.libs.inventory import ProgramInventoryEntry, discover_object_programs
    from runner.libs.results import UnifiedResultRecord, float_summary, parse_runner_sample
except ImportError:
    from runner.libs.commands import build_runner_command
    from runner.libs.environment import read_optional_text, read_required_text
    from runner.libs.inventory import ProgramInventoryEntry, discover_object_programs
    from runner.libs.results import UnifiedResultRecord, float_summary, parse_runner_sample
from runner.libs import resolve_bpftool_binary
from runner.libs.recompile import apply_recompile as apply_recompile_by_id


ROOT_DIR = Path(__file__).resolve().parent.parent
DEFAULT_OBJECT = ROOT_DIR / "corpus" / "build" / "tracee" / "tracee.bpf.o"
DEFAULT_RUNNER = ROOT_DIR / "runner" / "build" / "micro_exec"
DEFAULT_SCANNER = ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"
DEFAULT_OUTPUT_JSON = ROOT_DIR / "docs" / "tmp" / "tracee-e2e-results.json"
DEFAULT_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "tracee-e2e-results.md"
DEFAULT_PACKET_PATH = ROOT_DIR / "micro" / "generated-inputs" / "corpus_dummy_packet_64.bin"
TRACEE_EVENTS = ("execve", "open", "security_file_open", "connect", "module_load")
TRACEE_STATS_PATTERN = re.compile(
    r"EventCount[:=]\s*(?P<events>\d+).*?LostEvCount[:=]\s*(?P<lost>\d+)(?:.*?LostWrCount[:=]\s*(?P<lost_writes>\d+))?",
    re.IGNORECASE,
)
BPF_STATS_RUN_TIME = 0
BPF_TAG_SIZE = 8
BPF_OBJ_NAME_LEN = 16


class BenchmarkError(RuntimeError):
    pass


@dataclass(frozen=True, slots=True)
class WorkloadSpec:
    name: str
    description: str
    event_names: tuple[str, ...]
    relevant_programs: tuple[str, ...]
    requested_ops: int


@dataclass(frozen=True, slots=True)
class ProgramHandle:
    name: str
    section_name: str
    prog_type_name: str
    prog_fd: int
    prog_id: int
    link_ptr: int | None = None


@dataclass(frozen=True, slots=True)
class ProgramSnapshot:
    prog_id: int
    run_cnt: int
    run_time_ns: int
    bytes_xlated: int
    bytes_jited: int
    prog_name: str


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Run an end-to-end Tracee attach+trigger benchmark and compare "
            "baseline stock JIT against post-load BpfReJIT."
        )
    )
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON), help="Structured JSON output path.")
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD), help="Markdown summary output path.")
    parser.add_argument("--object", default=str(DEFAULT_OBJECT), help="Tracee BPF object path.")
    parser.add_argument("--runner", default=str(DEFAULT_RUNNER), help="Path to micro_exec.")
    parser.add_argument("--scanner", default=str(DEFAULT_SCANNER), help="Path to bpf-jit-scanner.")
    parser.add_argument("--tracee-binary", help="Optional explicit path to the Tracee binary.")
    parser.add_argument(
        "--mode",
        choices=("auto", "tracee", "manual"),
        default="auto",
        help="Benchmark mode. `auto` prefers a Tracee binary and falls back to manual loading.",
    )
    parser.add_argument(
        "--recompile-mode",
        choices=("v4", "v5"),
        default="v5",
        help="Policy blob format to use for the BpfReJIT phase.",
    )
    parser.add_argument(
        "--tracee-extra-arg",
        action="append",
        dest="tracee_extra_args",
        default=[],
        help="Extra argument appended to the Tracee launch command. Repeatable.",
    )
    parser.add_argument("--load-timeout", type=int, default=20, help="Seconds to wait for programs to load.")
    parser.add_argument("--settle-ms", type=int, default=100, help="Sleep after each workload before sampling.")
    parser.add_argument("--process-ops", type=int, default=25, help="stress-ng exec operations.")
    parser.add_argument("--file-ops", type=int, default=12, help="dd file workload iterations.")
    parser.add_argument("--network-ops", type=int, default=12, help="HTTP connect iterations.")
    parser.add_argument("--module-ops", type=int, default=1, help="Kernel module load/unload cycles.")
    parser.add_argument(
        "--module-name",
        default="dummy",
        help="Module used to trigger module_load. Default loads `dummy` with numdummies=0.",
    )
    parser.add_argument("--cgroup-repeat", type=int, default=8, help="Repeat count for cgroup_skb test_run probes.")
    parser.add_argument(
        "--no-cgroup-test",
        action="store_true",
        help="Skip the cgroup_skb bpf_prog_test_run fallback measurements.",
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Resolve tools, inventory, and execution plan without running workloads.",
    )
    return parser.parse_args()


def ensure_root() -> None:
    if os.geteuid() == 0:
        return
    os.execvp("sudo", ["sudo", "-n", sys.executable, str(Path(__file__).resolve()), *sys.argv[1:]])


def chown_to_invoking_user(path: Path) -> None:
    uid_raw = os.environ.get("SUDO_UID")
    gid_raw = os.environ.get("SUDO_GID")
    if not uid_raw or not gid_raw:
        return
    try:
        os.chown(path, int(uid_raw), int(gid_raw))
    except OSError:
        return


def git_sha() -> str:
    try:
        return subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT_DIR, text=True).strip()
    except Exception:
        return "unknown"


def host_metadata() -> dict[str, object]:
    return {
        "hostname": platform.node(),
        "platform": platform.platform(),
        "python": sys.version.split()[0],
        "kernel_version": platform.release(),
        "git_sha": git_sha(),
        "kernel_cmdline": read_required_text("/proc/cmdline"),
        "cpu_governor": read_optional_text("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor"),
        "turbo_state": read_optional_text("/sys/devices/system/cpu/intel_pstate/no_turbo"),
        "perf_event_paranoid": read_optional_text("/proc/sys/kernel/perf_event_paranoid"),
    }


def ensure_parent(path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)


def run_command(
    command: Sequence[str],
    *,
    capture_output: bool = True,
    text: bool = True,
    check: bool = True,
    timeout: int | None = None,
    pass_fds: Sequence[int] = (),
    cwd: Path | None = None,
) -> subprocess.CompletedProcess[str]:
    completed = subprocess.run(
        list(command),
        cwd=cwd or ROOT_DIR,
        capture_output=capture_output,
        text=text,
        timeout=timeout,
        check=False,
        pass_fds=tuple(pass_fds),
    )
    if check and completed.returncode != 0:
        details = completed.stderr.strip() or completed.stdout.strip()
        raise BenchmarkError(f"command failed ({completed.returncode}): {' '.join(command)}\n{details}")
    return completed


def which(tool: str) -> str | None:
    return shutil.which(tool)


def maybe_install_tools(required_tools: Mapping[str, str | None]) -> dict[str, object]:
    packages: list[str] = []
    for package in ("stress-ng", "fio"):
        if required_tools.get(package) is None:
            packages.append(package)
    if not packages:
        return {"attempted": False, "installed": [], "error": None}

    try:
        run_command(["apt-get", "install", "-y", *packages], timeout=900)
        return {"attempted": True, "installed": packages, "error": None}
    except Exception as exc:
        return {"attempted": True, "installed": [], "error": str(exc)}


def tracee_apt_available() -> bool:
    try:
        completed = run_command(["apt-cache", "policy", "tracee"], capture_output=True, check=False)
    except Exception:
        return False
    text = (completed.stdout or "") + "\n" + (completed.stderr or "")
    return "Candidate:" in text and "Candidate: (none)" not in text


def resolve_tracee_binary(explicit_path: str | None) -> tuple[str | None, dict[str, object]]:
    probes: list[str] = []
    if explicit_path:
        path = str(Path(explicit_path).resolve())
        return (path if Path(path).exists() else None), {"explicit": explicit_path, "apt_attempted": False, "error": None}

    for candidate in ("tracee", "tracee-ebpf"):
        found = which(candidate)
        if found:
            return found, {"explicit": None, "apt_attempted": False, "error": None}
        probes.append(candidate)

    if not tracee_apt_available():
        return None, {"explicit": None, "apt_attempted": False, "error": "tracee package not available via apt"}

    try:
        run_command(["apt-get", "install", "-y", "tracee"], timeout=1800)
    except Exception as exc:
        return None, {"explicit": None, "apt_attempted": True, "error": str(exc)}

    for candidate in probes:
        found = which(candidate)
        if found:
            return found, {"explicit": None, "apt_attempted": True, "error": None}
    return None, {"explicit": None, "apt_attempted": True, "error": "tracee install completed but binary not found"}


def _ipv4_checksum(header: bytes | bytearray) -> int:
    """Compute RFC 791 one's complement checksum over a 20-byte IPv4 header."""
    s = 0
    for i in range(0, len(header), 2):
        s += (header[i] << 8) + header[i + 1]
    while s >> 16:
        s = (s & 0xFFFF) + (s >> 16)
    return ~s & 0xFFFF


def materialize_dummy_packet(path: Path) -> Path:
    ensure_parent(path)
    # Regenerate if absent, wrong size, or missing broadcast-dst sentinel (version marker).
    _MAGIC = bytes.fromhex("ffffffffffff")
    if path.exists() and path.stat().st_size == 64:
        if path.read_bytes()[0:6] == _MAGIC:
            return path

    packet = bytearray(64)

    # Ethernet header
    packet[0:6] = _MAGIC                              # dst MAC (broadcast sentinel)
    packet[6:12] = bytes.fromhex("001122334455")      # src MAC
    packet[12:14] = bytes.fromhex("0800")              # EtherType = IPv4

    # IPv4 header (checksum filled after construction)
    packet[14] = 0x45        # version=4, IHL=5
    packet[15] = 0x00        # DSCP/ECN
    packet[16:18] = (50).to_bytes(2, "big")            # total length (20+20+10)
    packet[18:20] = (0).to_bytes(2, "big")             # identification
    packet[20:22] = (0x4000).to_bytes(2, "big")        # flags=DF, frag_offset=0
    packet[22] = 64           # TTL
    packet[23] = 6            # protocol = TCP
    packet[24:26] = (0).to_bytes(2, "big")             # checksum placeholder
    packet[26:30] = bytes([10, 0, 0, 1])               # src IP = 10.0.0.1
    packet[30:34] = bytes([10, 0, 0, 2])               # dst IP = 10.0.0.2
    chk = _ipv4_checksum(packet[14:34])
    packet[24:26] = chk.to_bytes(2, "big")

    # TCP header
    packet[34:36] = (12345).to_bytes(2, "big")         # src_port
    packet[36:38] = (80).to_bytes(2, "big")            # dst_port
    packet[38:42] = (1).to_bytes(4, "big")             # seq = 1
    packet[42:46] = (0).to_bytes(4, "big")             # ack = 0
    packet[46] = 0x50        # data_offset=5
    packet[47] = 0x02        # flags = SYN
    packet[48:50] = (8192).to_bytes(2, "big")          # window
    packet[50:52] = (0).to_bytes(2, "big")             # TCP checksum (0)
    packet[52:54] = (0).to_bytes(2, "big")             # urgent pointer

    # Payload
    packet[54:64] = bytes([0x41] * 10)                 # 'A' * 10

    path.write_bytes(packet)
    return path


def relpath(path: Path) -> str:
    try:
        return path.resolve().relative_to(ROOT_DIR).as_posix()
    except Exception:
        return str(path)


def proc_cpu_time_seconds(pid: int) -> float | None:
    try:
        fields = Path(f"/proc/{pid}/stat").read_text().split()
    except OSError:
        return None
    if len(fields) < 15:
        return None
    clock_ticks = os.sysconf(os.sysconf_names["SC_CLK_TCK"])
    utime = int(fields[13])
    stime = int(fields[14])
    return float(utime + stime) / float(clock_ticks)


def process_cpu_percent(pid: int, start: float | None, end: float | None, wall_seconds: float) -> float | None:
    if start is None or end is None or wall_seconds <= 0:
        return None
    return 100.0 * max(end - start, 0.0) / wall_seconds


class _SilentHandler(BaseHTTPRequestHandler):
    def do_GET(self) -> None:  # noqa: N802
        payload = b"tracee-benchmark\n"
        self.send_response(200)
        self.send_header("Content-Type", "text/plain")
        self.send_header("Content-Length", str(len(payload)))
        self.end_headers()
        self.wfile.write(payload)

    def log_message(self, format: str, *args: object) -> None:
        del format, args


class LocalHttpServer:
    def __init__(self) -> None:
        self.server = ThreadingHTTPServer(("127.0.0.1", 0), _SilentHandler)
        self.thread = threading.Thread(target=self.server.serve_forever, daemon=True)

    @property
    def url(self) -> str:
        host, port = self.server.server_address
        return f"http://{host}:{port}/"

    def __enter__(self) -> "LocalHttpServer":
        self.thread.start()
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        self.server.shutdown()
        self.thread.join(timeout=2.0)
        self.server.server_close()


def run_process_workload(spec: WorkloadSpec) -> dict[str, object]:
    command = [
        which("stress-ng") or "stress-ng",
        "--exec",
        "1",
        "--exec-method",
        "execve",
        "--exec-ops",
        str(max(1, spec.requested_ops)),
        "--timeout",
        f"{max(10, spec.requested_ops)}s",
        "--metrics-brief",
    ]
    start = time.monotonic()
    completed = run_command(command, timeout=max(30, spec.requested_ops + 10))
    duration = time.monotonic() - start
    return {
        "command": command,
        "stdout_tail": tail_text(completed.stdout),
        "stderr_tail": tail_text(completed.stderr),
        "completed_ops": spec.requested_ops,
        "duration_seconds": duration,
        "ops_per_sec": float(spec.requested_ops) / duration if duration > 0 else None,
    }


def run_file_workload(spec: WorkloadSpec) -> dict[str, object]:
    with tempfile.TemporaryDirectory(prefix="tracee-file-") as tempdir:
        workdir = Path(tempdir)
        start = time.monotonic()
        for index in range(spec.requested_ops):
            path = workdir / f"file-{index}.bin"
            run_command(
                [
                    which("dd") or "dd",
                    "if=/dev/zero",
                    f"of={path}",
                    "bs=4096",
                    "count=32",
                    "conv=fdatasync",
                    "status=none",
                ],
                capture_output=True,
                timeout=30,
            )
            run_command(
                [
                    which("dd") or "dd",
                    f"if={path}",
                    "of=/dev/null",
                    "bs=4096",
                    "status=none",
                ],
                capture_output=True,
                timeout=30,
            )
            path.unlink(missing_ok=True)
        duration = time.monotonic() - start
    return {
        "command": ["dd", "loop"],
        "completed_ops": spec.requested_ops,
        "duration_seconds": duration,
        "ops_per_sec": float(spec.requested_ops) / duration if duration > 0 else None,
        "stdout_tail": "",
        "stderr_tail": "",
    }


def run_network_workload(spec: WorkloadSpec) -> dict[str, object]:
    curl = which("curl")
    if curl is None:
        raise BenchmarkError("curl is required for the connect workload")

    with LocalHttpServer() as server:
        start = time.monotonic()
        for _ in range(spec.requested_ops):
            run_command([curl, "-fsS", "--max-time", "2", server.url], timeout=5)
        duration = time.monotonic() - start
    return {
        "command": [curl, "loop", server.url if "server" in locals() else "http://127.0.0.1/"],
        "completed_ops": spec.requested_ops,
        "duration_seconds": duration,
        "ops_per_sec": float(spec.requested_ops) / duration if duration > 0 else None,
        "stdout_tail": "",
        "stderr_tail": "",
    }


def run_module_workload(spec: WorkloadSpec, module_name: str) -> dict[str, object]:
    completed_ops = 0
    command = ["modprobe", module_name]
    start = time.monotonic()
    try:
        run_command(["modprobe", "-r", module_name], check=False, timeout=20)
        for _ in range(spec.requested_ops):
            args = ["modprobe", module_name]
            if module_name == "dummy":
                args.append("numdummies=0")
            run_command(args, timeout=30)
            run_command(["modprobe", "-r", module_name], timeout=30)
            completed_ops += 1
    finally:
        run_command(["modprobe", "-r", module_name], check=False, timeout=20)
    duration = time.monotonic() - start
    return {
        "command": command,
        "completed_ops": completed_ops,
        "duration_seconds": duration,
        "ops_per_sec": float(completed_ops) / duration if duration > 0 else None,
        "stdout_tail": "",
        "stderr_tail": "",
    }


def tail_text(text: str, *, max_lines: int = 10, max_chars: int = 2000) -> str:
    lines = [line.rstrip() for line in text.splitlines() if line.strip()]
    if len(lines) > max_lines:
        lines = lines[-max_lines:]
    summary = "\n".join(lines)
    if len(summary) > max_chars:
        summary = summary[-max_chars:]
    return summary


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
        self.lib.bpf_object__next_program.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
        self.lib.bpf_object__next_program.restype = ctypes.c_void_p
        self.lib.bpf_program__name.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__name.restype = ctypes.c_char_p
        self.lib.bpf_program__section_name.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__section_name.restype = ctypes.c_char_p
        self.lib.bpf_program__set_autoload.argtypes = [ctypes.c_void_p, ctypes.c_bool]
        self.lib.bpf_program__set_autoload.restype = ctypes.c_int
        self.lib.bpf_object__load.argtypes = [ctypes.c_void_p]
        self.lib.bpf_object__load.restype = ctypes.c_int
        self.lib.bpf_program__attach.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__attach.restype = ctypes.c_void_p
        self.lib.bpf_program__fd.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__fd.restype = ctypes.c_int
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
        self.lib.bpf_prog_get_fd_by_id.argtypes = [ctypes.c_uint32]
        self.lib.bpf_prog_get_fd_by_id.restype = ctypes.c_int

    def pointer_error(self, ptr: ctypes.c_void_p | int | None) -> int:
        return int(self.lib.libbpf_get_error(ctypes.c_void_p(ptr or 0)))

    def enable_stats(self) -> int:
        fd = int(self.lib.bpf_enable_stats(BPF_STATS_RUN_TIME))
        if fd < 0:
            err = ctypes.get_errno()
            raise BenchmarkError(f"bpf_enable_stats failed: {os.strerror(err)} (errno={err})")
        return fd

    def get_prog_info(self, prog_fd: int) -> BpfProgInfo:
        info = BpfProgInfo()
        info_len = ctypes.c_uint32(ctypes.sizeof(info))
        rc = self.lib.bpf_prog_get_info_by_fd(prog_fd, ctypes.byref(info), ctypes.byref(info_len))
        if rc != 0:
            err = ctypes.get_errno()
            raise BenchmarkError(f"bpf_prog_get_info_by_fd failed: {os.strerror(err)} (errno={err})")
        return info

    def get_fd_by_id(self, prog_id: int) -> int:
        fd = int(self.lib.bpf_prog_get_fd_by_id(prog_id))
        if fd < 0:
            err = ctypes.get_errno()
            raise BenchmarkError(f"bpf_prog_get_fd_by_id({prog_id}) failed: {os.strerror(err)} (errno={err})")
        return fd


def decode_program_name(raw_name: bytes | str) -> str:
    if isinstance(raw_name, bytes):
        return raw_name.split(b"\0", 1)[0].decode("utf-8", "replace")
    return str(raw_name)


def snapshot_from_info(info: BpfProgInfo) -> ProgramSnapshot:
    return ProgramSnapshot(
        prog_id=int(info.id),
        run_cnt=int(info.run_cnt),
        run_time_ns=int(info.run_time_ns),
        bytes_xlated=int(info.xlated_prog_len),
        bytes_jited=int(info.jited_prog_len),
        prog_name=decode_program_name(bytes(info.name)),
    )


class ManualTraceeSession:
    def __init__(self, libbpf: Libbpf, object_path: Path, selected: Sequence[ProgramInventoryEntry]) -> None:
        self.libbpf = libbpf
        self.object_path = object_path
        self.selected = {entry.name: entry for entry in selected}
        self.object_ptr: int | None = None
        self.stats_fd = -1
        self.program_handles: dict[str, ProgramHandle] = {}

    def __enter__(self) -> "ManualTraceeSession":
        try:
            self.stats_fd = self.libbpf.enable_stats()
            object_ptr = self.libbpf.lib.bpf_object__open_file(str(self.object_path).encode(), None)
            open_error = self.libbpf.pointer_error(object_ptr)
            if open_error != 0:
                raise BenchmarkError(f"bpf_object__open_file failed: errno={open_error}")
            self.object_ptr = int(object_ptr)

            program_ptrs: dict[str, int] = {}
            current_ptr = ctypes.c_void_p()
            while True:
                current_ptr = ctypes.c_void_p(self.libbpf.lib.bpf_object__next_program(self.object_ptr, current_ptr))
                if not current_ptr.value:
                    break
                name = decode_program_name(self.libbpf.lib.bpf_program__name(current_ptr))
                keep = name in self.selected
                rc = self.libbpf.lib.bpf_program__set_autoload(current_ptr, keep)
                if rc != 0:
                    raise BenchmarkError(f"bpf_program__set_autoload failed for {name}: rc={rc}")
                if keep:
                    program_ptrs[name] = int(current_ptr.value)

            missing = sorted(set(self.selected) - set(program_ptrs))
            if missing:
                raise BenchmarkError(f"manual selection missing programs: {', '.join(missing)}")

            rc = self.libbpf.lib.bpf_object__load(self.object_ptr)
            if rc != 0:
                raise BenchmarkError(f"bpf_object__load failed: rc={rc}")

            for name, entry in self.selected.items():
                program_ptr = program_ptrs[name]
                prog_fd = int(self.libbpf.lib.bpf_program__fd(program_ptr))
                if prog_fd < 0:
                    raise BenchmarkError(f"bpf_program__fd failed for {name}")
                link_ptr = self.libbpf.lib.bpf_program__attach(program_ptr)
                attach_error = self.libbpf.pointer_error(link_ptr)
                if attach_error != 0:
                    raise BenchmarkError(f"bpf_program__attach failed for {name}: errno={attach_error}")
                info = self.libbpf.get_prog_info(prog_fd)
                self.program_handles[name] = ProgramHandle(
                    name=name,
                    section_name=entry.section_name,
                    prog_type_name=entry.prog_type_name,
                    prog_fd=prog_fd,
                    prog_id=int(info.id),
                    link_ptr=int(link_ptr),
                )
            return self
        except Exception:
            self.__exit__(None, None, None)
            raise

    def snapshot(self) -> dict[str, ProgramSnapshot]:
        return {
            name: snapshot_from_info(self.libbpf.get_prog_info(handle.prog_fd))
            for name, handle in self.program_handles.items()
        }

    def __exit__(self, exc_type, exc, tb) -> None:
        for handle in self.program_handles.values():
            if handle.link_ptr:
                self.libbpf.lib.bpf_link__destroy(handle.link_ptr)
        self.program_handles.clear()
        if self.stats_fd >= 0:
            os.close(self.stats_fd)
            self.stats_fd = -1
        if self.object_ptr:
            self.libbpf.lib.bpf_object__close(self.object_ptr)
            self.object_ptr = None


class TraceeOutputCollector:
    def __init__(self) -> None:
        self._lock = threading.Lock()
        self.stdout_tail: deque[str] = deque(maxlen=200)
        self.stderr_tail: deque[str] = deque(maxlen=200)
        self.event_counts: Counter[str] = Counter()
        self.total_events = 0
        self.latest_stats: dict[str, int] = {}

    def consume_stdout(self, pipe: Any) -> None:
        for raw_line in iter(pipe.readline, ""):
            line = raw_line.rstrip()
            with self._lock:
                self.stdout_tail.append(line)
            self._parse_event_line(line)
        pipe.close()

    def consume_stderr(self, pipe: Any) -> None:
        for raw_line in iter(pipe.readline, ""):
            line = raw_line.rstrip()
            with self._lock:
                self.stderr_tail.append(line)
            self._parse_stats_line(line)
        pipe.close()

    def _parse_event_line(self, line: str) -> None:
        try:
            payload = json.loads(line)
        except json.JSONDecodeError:
            self._parse_stats_line(line)
            return
        if not isinstance(payload, Mapping):
            return
        event_name = payload.get("eventName") or payload.get("event_name")
        if not event_name:
            return
        with self._lock:
            self.event_counts[str(event_name)] += 1
            self.total_events += 1

    def _parse_stats_line(self, line: str) -> None:
        match = TRACEE_STATS_PATTERN.search(line)
        if not match:
            return
        stats = {
            "event_count": int(match.group("events")),
            "lost_event_count": int(match.group("lost")),
            "lost_write_count": int(match.group("lost_writes") or 0),
        }
        with self._lock:
            self.latest_stats = stats

    def snapshot(self) -> dict[str, object]:
        with self._lock:
            return {
                "event_counts": dict(self.event_counts),
                "total_events": self.total_events,
                "latest_stats": dict(self.latest_stats),
                "stdout_tail": list(self.stdout_tail),
                "stderr_tail": list(self.stderr_tail),
            }


class TraceeProcessSession:
    def __init__(
        self,
        libbpf: Libbpf,
        tracee_binary: str,
        tracee_command: Sequence[str],
        inventory_by_name: Mapping[str, ProgramInventoryEntry],
        load_timeout: int,
    ) -> None:
        self.libbpf = libbpf
        self.tracee_binary = tracee_binary
        self.tracee_command = list(tracee_command)
        self.inventory_by_name = inventory_by_name
        self.load_timeout = load_timeout
        self.collector = TraceeOutputCollector()
        self.process: subprocess.Popen[str] | None = None
        self.stdout_thread: threading.Thread | None = None
        self.stderr_thread: threading.Thread | None = None
        self.stats_fd = -1
        self.program_handles: dict[str, ProgramHandle] = {}

    def __enter__(self) -> "TraceeProcessSession":
        try:
            before_ids = set(bpftool_programs().keys())
            self.stats_fd = self.libbpf.enable_stats()
            self.process = subprocess.Popen(
                self.tracee_command,
                cwd=ROOT_DIR,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
            )
            assert self.process.stdout is not None
            assert self.process.stderr is not None
            self.stdout_thread = threading.Thread(target=self.collector.consume_stdout, args=(self.process.stdout,), daemon=True)
            self.stderr_thread = threading.Thread(target=self.collector.consume_stderr, args=(self.process.stderr,), daemon=True)
            self.stdout_thread.start()
            self.stderr_thread.start()

            deadline = time.monotonic() + self.load_timeout
            loaded_ids: list[int] = []
            while time.monotonic() < deadline:
                if self.process.poll() is not None:
                    raise BenchmarkError(
                        f"Tracee exited before BPF programs were detected: {tail_text(' '.join(self.collector.snapshot()['stderr_tail']))}"
                    )
                current = bpftool_programs()
                loaded_ids = [
                    prog_id
                    for prog_id, record in current.items()
                    if prog_id not in before_ids and str(record.get("name", "")) in self.inventory_by_name
                ]
                if loaded_ids:
                    break
                time.sleep(0.5)
            if not loaded_ids:
                raise BenchmarkError("timed out waiting for Tracee to load BPF programs")

            current = bpftool_programs()
            for prog_id in loaded_ids:
                record = current.get(prog_id, {})
                name = str(record.get("name", ""))
                if name not in self.inventory_by_name:
                    continue
                prog_fd = self.libbpf.get_fd_by_id(prog_id)
                entry = self.inventory_by_name[name]
                self.program_handles[name] = ProgramHandle(
                    name=name,
                    section_name=entry.section_name,
                    prog_type_name=str(record.get("type", entry.prog_type_name)),
                    prog_fd=prog_fd,
                    prog_id=prog_id,
                    link_ptr=None,
                )

            if not self.program_handles:
                raise BenchmarkError("Tracee loaded programs, but no matching inventory entries were discovered")
            return self
        except Exception:
            self.__exit__(None, None, None)
            raise

    def snapshot(self) -> dict[str, ProgramSnapshot]:
        return {
            name: snapshot_from_info(self.libbpf.get_prog_info(handle.prog_fd))
            for name, handle in self.program_handles.items()
        }

    @property
    def pid(self) -> int | None:
        return None if self.process is None else self.process.pid

    def collector_snapshot(self) -> dict[str, object]:
        return self.collector.snapshot()

    def __exit__(self, exc_type, exc, tb) -> None:
        for handle in self.program_handles.values():
            try:
                os.close(handle.prog_fd)
            except OSError:
                pass
        self.program_handles.clear()

        if self.process is not None:
            if self.process.poll() is None:
                self.process.send_signal(signal.SIGINT)
                try:
                    self.process.wait(timeout=5)
                except subprocess.TimeoutExpired:
                    self.process.terminate()
                    try:
                        self.process.wait(timeout=3)
                    except subprocess.TimeoutExpired:
                        self.process.kill()
            self.process = None
        if self.stdout_thread is not None:
            self.stdout_thread.join(timeout=2.0)
            self.stdout_thread = None
        if self.stderr_thread is not None:
            self.stderr_thread.join(timeout=2.0)
            self.stderr_thread = None
        if self.stats_fd >= 0:
            os.close(self.stats_fd)
            self.stats_fd = -1


def bpftool_programs() -> dict[int, dict[str, object]]:
    completed = run_command([resolve_bpftool_binary(), "prog", "show", "--json"])
    payload = json.loads(completed.stdout)
    if isinstance(payload, list):
        return {int(record["id"]): record for record in payload if isinstance(record, Mapping) and "id" in record}
    return {}


def choose_manual_programs(inventory: Mapping[str, ProgramInventoryEntry]) -> list[ProgramInventoryEntry]:
    selected_names = [
        "tracepoint__sched__sched_process_exec",
        "trace_security_file_open",
        "trace_security_socket_connect",
        "tracepoint__module__module_load",
        "lsm_file_open_test",
    ]
    missing = [name for name in selected_names if name not in inventory]
    if missing:
        raise BenchmarkError(f"missing expected Tracee programs in object inventory: {', '.join(missing)}")
    return [inventory[name] for name in selected_names]


def build_workload_specs(args: argparse.Namespace) -> list[WorkloadSpec]:
    specs: list[WorkloadSpec] = [
        WorkloadSpec(
            name="process-exec",
            description="stress-ng exec workload for execve coverage",
            event_names=("execve",),
            relevant_programs=("tracepoint__sched__sched_process_exec",),
            requested_ops=max(0, args.process_ops),
        ),
        WorkloadSpec(
            name="file-open",
            description="dd write/read loop for security_file_open coverage",
            event_names=("open", "security_file_open"),
            relevant_programs=("trace_security_file_open", "lsm_file_open_test"),
            requested_ops=max(0, args.file_ops),
        ),
        WorkloadSpec(
            name="network-connect",
            description="curl loop against a localhost HTTP server",
            event_names=("connect",),
            relevant_programs=("trace_security_socket_connect",),
            requested_ops=max(0, args.network_ops),
        ),
        WorkloadSpec(
            name="module-load",
            description=f"modprobe cycle for kernel module `{args.module_name}`",
            event_names=("module_load",),
            relevant_programs=("tracepoint__module__module_load",),
            requested_ops=max(0, args.module_ops),
        ),
    ]
    return [spec for spec in specs if spec.requested_ops > 0]


def run_named_workload(spec: WorkloadSpec, *, module_name: str) -> dict[str, object]:
    if spec.name == "process-exec":
        return run_process_workload(spec)
    if spec.name == "file-open":
        return run_file_workload(spec)
    if spec.name == "network-connect":
        return run_network_workload(spec)
    if spec.name == "module-load":
        return run_module_workload(spec, module_name)
    raise BenchmarkError(f"unsupported workload: {spec.name}")


def delta_program_snapshots(
    before: Mapping[str, ProgramSnapshot],
    after: Mapping[str, ProgramSnapshot],
    relevant_programs: Iterable[str] | None = None,
) -> list[dict[str, object]]:
    names = set(before) & set(after)
    if relevant_programs is not None:
        names &= set(relevant_programs)
    deltas: list[dict[str, object]] = []
    for name in sorted(names):
        before_snapshot = before[name]
        after_snapshot = after[name]
        run_cnt_delta = int(after_snapshot.run_cnt - before_snapshot.run_cnt)
        run_time_delta = int(after_snapshot.run_time_ns - before_snapshot.run_time_ns)
        average_ns = float(run_time_delta) / float(run_cnt_delta) if run_cnt_delta > 0 else None
        deltas.append(
            {
                "name": name,
                "prog_id": after_snapshot.prog_id,
                "run_cnt_delta": run_cnt_delta,
                "run_time_ns_delta": run_time_delta,
                "average_ns_per_run": average_ns,
                "bytes_xlated": after_snapshot.bytes_xlated,
                "bytes_jited": after_snapshot.bytes_jited,
            }
        )
    return deltas


def summarize_event_counts_from_deltas(workload_deltas: Sequence[Mapping[str, object]]) -> tuple[int, float | None]:
    total_events = sum(int(delta.get("run_cnt_delta", 0) or 0) for delta in workload_deltas)
    average_ns_values = [
        float(delta["average_ns_per_run"])
        for delta in workload_deltas
        if delta.get("average_ns_per_run") is not None
    ]
    return total_events, (sum(average_ns_values) / len(average_ns_values) if average_ns_values else None)


def recompile_programs(
    scanner_binary: Path,
    program_handles: Mapping[str, ProgramHandle],
    directive_scan: Mapping[str, Mapping[str, object]],
    *,
    mode: str,
) -> dict[str, object]:
    recompile_details: list[dict[str, object]] = []
    applied = 0
    skipped = 0
    system_error: str | None = None
    for name, handle in program_handles.items():
        scan_summary = directive_scan.get(name) or {}
        total_sites = int(scan_summary.get("total_sites", 0) or 0)
        if total_sites <= 0:
            skipped += 1
            recompile_details.append(
                {
                    "program": name,
                    "prog_id": handle.prog_id,
                    "attempted": False,
                    "applied": False,
                    "reason": "no directive sites",
                }
            )
            continue
        if system_error is not None:
            skipped += 1
            recompile_details.append(
                {
                    "program": name,
                    "prog_id": handle.prog_id,
                    "attempted": False,
                    "applied": False,
                    "reason": system_error,
                }
            )
            continue
        result = apply_recompile_by_id([handle.prog_id], scanner_binary, blind_apply=True).get(int(handle.prog_id), {})
        error_message = str(result.get("error") or "") or None
        applied_ok = bool(result.get("applied"))

        detail = {
            "program": name,
            "prog_id": handle.prog_id,
            "attempted": True,
            "applied": applied_ok,
            "stdout_tail": tail_text(str(result.get("stdout_tail") or "")),
            "stderr_tail": tail_text(str(result.get("stderr_tail") or "")),
            "error": error_message,
        }
        recompile_details.append(detail)
        if applied_ok:
            applied += 1
        else:
            if error_message and "Invalid argument" in error_message:
                system_error = error_message

    return {
        "requested": True,
        "mode": mode,
        "requested_programs": len(program_handles),
        "applied_programs": applied,
        "skipped_programs": skipped,
        "applied": applied > 0,
        "error": system_error,
        "details": recompile_details,
    }


def probe_directive_scan(
    runner_binary: Path,
    object_path: Path,
    entry: ProgramInventoryEntry,
    packet_path: Path,
    *,
    mode: str,
) -> dict[str, object]:
    io_mode = "packet" if entry.section_name.startswith("cgroup_skb/") else "context"
    memory_path = packet_path if io_mode == "packet" else None
    command = build_runner_command(
        runner_binary,
        "run-kernel",
        program=object_path,
        program_name=entry.name,
        io_mode=io_mode,
        memory=memory_path,
        repeat=1,
        compile_only=True,
        recompile_all=True,
        recompile_v5=(mode == "v5"),
    )
    completed = run_command(command, capture_output=True, timeout=180, check=False)
    if completed.returncode != 0:
        return {
            "performed": False,
            "error": tail_text(completed.stderr or completed.stdout),
            "cmov_sites": 0,
            "wide_sites": 0,
            "rotate_sites": 0,
            "lea_sites": 0,
            "total_sites": 0,
        }
    sample = parse_runner_sample(completed.stdout)
    directive_scan = dict(sample.get("directive_scan") or {})
    directive_scan["performed"] = bool(directive_scan.get("performed", False))
    return directive_scan


def run_cgroup_fallback(
    runner_binary: Path,
    object_path: Path,
    packet_path: Path,
    repeat: int,
    *,
    mode: str,
) -> dict[str, object]:
    results: list[dict[str, object]] = []
    for program_name in ("cgroup_skb_ingress", "cgroup_skb_egress"):
        baseline_command = build_runner_command(
            runner_binary,
            "run-kernel",
            program=object_path,
            program_name=program_name,
            io_mode="packet",
            memory=packet_path,
            repeat=max(1, repeat),
        )
        rejit_command = build_runner_command(
            runner_binary,
            "run-kernel",
            program=object_path,
            program_name=program_name,
            io_mode="packet",
            memory=packet_path,
            repeat=max(1, repeat),
            recompile_all=True,
            recompile_v5=(mode == "v5"),
        )
        baseline = run_command(baseline_command, capture_output=True, check=False, timeout=180)
        rejit = run_command(rejit_command, capture_output=True, check=False, timeout=180)
        record: dict[str, object] = {"program": program_name}
        if baseline.returncode == 0:
            record["baseline"] = parse_runner_sample(baseline.stdout)
        else:
            record["baseline_error"] = tail_text(baseline.stderr or baseline.stdout)
        if rejit.returncode == 0:
            record["rejit"] = parse_runner_sample(rejit.stdout)
        else:
            record["rejit_error"] = tail_text(rejit.stderr or rejit.stdout)
        results.append(record)
    return {"repeat": repeat, "records": results}


def build_tracee_commands(binary: str, extra_args: Sequence[str]) -> list[list[str]]:
    events = ",".join(TRACEE_EVENTS)
    candidates = [
        [binary, "--events", events, "--output", "destinations.stdout.format=json", *extra_args],
        [binary, "--events", events, "--output", "json", *extra_args],
        [binary, "--events", events, "--output", "format:json", *extra_args],
    ]
    deduped: list[list[str]] = []
    seen: set[tuple[str, ...]] = set()
    for command in candidates:
        key = tuple(command)
        if key in seen:
            continue
        deduped.append(command)
        seen.add(key)
    return deduped


def run_variant(
    variant_name: str,
    session: Any,
    workloads: Sequence[WorkloadSpec],
    *,
    scanner_binary: Path,
    recompile_mode: str,
    directive_scan: Mapping[str, Mapping[str, object]],
    module_name: str,
    settle_seconds: float,
) -> dict[str, object]:
    recompile_summary = {
        "requested": False,
        "mode": "stock",
        "requested_programs": len(session.program_handles),
        "applied_programs": 0,
        "skipped_programs": 0,
        "applied": False,
        "error": None,
        "details": [],
    }
    if variant_name != "stock":
        recompile_summary = recompile_programs(
            scanner_binary,
            session.program_handles,
            directive_scan,
            mode=recompile_mode,
        )

    workload_records: list[dict[str, object]] = []
    for spec in workloads:
        before_programs = session.snapshot()
        before_tracee = session.collector_snapshot() if hasattr(session, "collector_snapshot") else None
        pid = session.pid if hasattr(session, "pid") else None
        cpu_before = proc_cpu_time_seconds(pid) if pid is not None else None
        workload_result = run_named_workload(spec, module_name=module_name)
        time.sleep(settle_seconds)
        cpu_after = proc_cpu_time_seconds(pid) if pid is not None else None
        after_programs = session.snapshot()
        after_tracee = session.collector_snapshot() if hasattr(session, "collector_snapshot") else None

        relevant_deltas = delta_program_snapshots(before_programs, after_programs, spec.relevant_programs)
        all_deltas = delta_program_snapshots(before_programs, after_programs)
        total_events, average_ns = summarize_event_counts_from_deltas(relevant_deltas)
        duration = float(workload_result["duration_seconds"])
        event_counts: dict[str, int] = {}
        drop_counters: dict[str, int] | None = None
        if before_tracee is not None and after_tracee is not None:
            before_counts = Counter(before_tracee.get("event_counts") or {})
            after_counts = Counter(after_tracee.get("event_counts") or {})
            for event_name in spec.event_names:
                event_counts[event_name] = int(after_counts.get(event_name, 0) - before_counts.get(event_name, 0))
            after_stats = after_tracee.get("latest_stats") or {}
            before_stats = before_tracee.get("latest_stats") or {}
            drop_counters = {
                key: int(after_stats.get(key, 0)) - int(before_stats.get(key, 0))
                for key in ("event_count", "lost_event_count", "lost_write_count")
            }
            total_events = sum(event_counts.values())
        else:
            if spec.name == "file-open":
                event_counts["security_file_open"] = sum(
                    int(delta.get("run_cnt_delta", 0) or 0)
                    for delta in relevant_deltas
                    if delta["name"] in {"trace_security_file_open", "lsm_file_open_test"}
                )
            else:
                event_counts[spec.event_names[0]] = total_events
        cpu_percent = process_cpu_percent(pid or -1, cpu_before, cpu_after, duration) if pid is not None else None
        workload_records.append(
            {
                "name": spec.name,
                "description": spec.description,
                "event_names": list(spec.event_names),
                "requested_ops": spec.requested_ops,
                "completed_ops": int(workload_result["completed_ops"]),
                "duration_seconds": duration,
                "ops_per_sec": workload_result["ops_per_sec"],
                "events_captured": event_counts,
                "events_per_sec": {
                    event_name: (float(count) / duration if duration > 0 else None)
                    for event_name, count in event_counts.items()
                },
                "total_events": total_events,
                "total_events_per_sec": float(total_events) / duration if duration > 0 else None,
                "agent_cpu_percent": cpu_percent,
                "drop_counters": drop_counters,
                "relevant_program_deltas": relevant_deltas,
                "all_program_deltas": all_deltas,
                "average_ns_per_run": average_ns,
                "command": workload_result["command"],
                "stdout_tail": workload_result["stdout_tail"],
                "stderr_tail": workload_result["stderr_tail"],
                "unsupported_events": [],
            }
        )
        if before_tracee is None and spec.name == "file-open":
            workload_records[-1]["unsupported_events"] = ["open"]

    return {"variant": variant_name, "recompile": recompile_summary, "workloads": workload_records}


def summarize_variant(variant_result: Mapping[str, object]) -> dict[str, object]:
    workloads = list(variant_result.get("workloads") or [])
    ops_rates = [float(record["ops_per_sec"]) for record in workloads if record.get("ops_per_sec") is not None]
    total_event_rates = [
        float(record["total_events_per_sec"])
        for record in workloads
        if record.get("total_events_per_sec") is not None
    ]
    average_ns_values = [
        float(record["average_ns_per_run"])
        for record in workloads
        if record.get("average_ns_per_run") is not None
    ]
    agent_cpu = [
        float(record["agent_cpu_percent"])
        for record in workloads
        if record.get("agent_cpu_percent") is not None
    ]
    event_totals: Counter[str] = Counter()
    for record in workloads:
        event_totals.update(record.get("events_captured") or {})
    return {
        "workload_ops_per_sec": float_summary(ops_rates),
        "events_per_sec": float_summary(total_event_rates),
        "average_ns_per_run": float_summary(average_ns_values),
        "agent_cpu_percent": float_summary(agent_cpu),
        "event_totals": dict(event_totals),
    }


def summarize_directive_scan(scan_map: Mapping[str, Mapping[str, object]]) -> dict[str, object]:
    summary = {"performed": True, "cmov_sites": 0, "wide_sites": 0, "rotate_sites": 0, "lea_sites": 0, "total_sites": 0}
    for scan in scan_map.values():
        for key in ("cmov_sites", "wide_sites", "rotate_sites", "lea_sites", "total_sites"):
            summary[key] += int(scan.get(key, 0) or 0)
    return summary


def aggregate_program_metrics(variant_result: Mapping[str, object]) -> dict[str, dict[str, object]]:
    aggregated: dict[str, dict[str, object]] = {}
    for workload in variant_result.get("workloads") or []:
        for delta in workload.get("all_program_deltas") or []:
            record = aggregated.setdefault(
                delta["name"],
                {
                    "prog_id": delta["prog_id"],
                    "total_run_cnt_delta": 0,
                    "total_run_time_ns_delta": 0,
                    "average_ns_values": [],
                },
            )
            record["total_run_cnt_delta"] += int(delta["run_cnt_delta"])
            record["total_run_time_ns_delta"] += int(delta["run_time_ns_delta"])
            if delta.get("average_ns_per_run") is not None:
                record["average_ns_values"].append(float(delta["average_ns_per_run"]))
    for record in aggregated.values():
        values = record.pop("average_ns_values")
        record["average_ns_per_run"] = (sum(values) / len(values)) if values else None
    return aggregated


def build_record(
    variant_result: Mapping[str, object],
    *,
    benchmark_mode: str,
    object_path: Path,
    tracee_binary: str | None,
    runner_binary: Path,
    scanner_binary: Path,
    host: Mapping[str, object],
    inventory: Sequence[ProgramInventoryEntry],
    directive_scan: Mapping[str, Mapping[str, object]],
    recompile_mode: str,
    tracee_install: Mapping[str, object],
) -> UnifiedResultRecord:
    policy_mode = "stock" if variant_result["variant"] == "stock" else f"{recompile_mode}-all"
    statistics = summarize_variant(variant_result)
    inventory_payload = {
        "selected_program_count": len(inventory),
        "selected_programs": [
            {
                "name": entry.name,
                "section_name": entry.section_name,
                "prog_type_name": entry.prog_type_name,
                "attach_type_name": entry.attach_type_name,
            }
            for entry in inventory
        ],
        "aggregated_program_metrics": aggregate_program_metrics(variant_result),
    }
    metadata = {
        "benchmark_mode": benchmark_mode,
        "tracee_install": dict(tracee_install),
        "requested_events": list(TRACEE_EVENTS),
    }
    return UnifiedResultRecord(
        suite="tracee_e2e",
        target={
            "name": "tracee",
            "object_path": str(object_path),
            "events": list(TRACEE_EVENTS),
        },
        backend="kernel",
        policy_mode=policy_mode,
        host=host,
        inventory=inventory_payload,
        artifacts={
            "tracee_object": str(object_path),
            "tracee_binary": tracee_binary,
            "runner_binary": str(runner_binary),
            "scanner_binary": str(scanner_binary),
        },
        execution={
            "variant": variant_result["variant"],
            "workloads": variant_result["workloads"],
        },
        directive_scan={
            "programs": {name: dict(scan) for name, scan in directive_scan.items()},
            "summary": summarize_directive_scan(directive_scan),
        },
        recompile=variant_result["recompile"],
        statistics=statistics,
        correctness={
            "comparable": bool(variant_result["variant"] == "stock" or variant_result["recompile"].get("applied")),
            "applied": bool(variant_result["recompile"].get("applied")),
        },
        metadata=metadata,
    )


def build_comparison(records: Sequence[Mapping[str, object]]) -> dict[str, object]:
    by_policy = {record["policy_mode"]: record for record in records if isinstance(record, Mapping)}
    baseline = by_policy.get("stock")
    rejit = next((record for key, record in by_policy.items() if key != "stock"), None)
    if baseline is None or rejit is None:
        return {"comparable": False, "reason": "missing baseline or rejit record"}
    baseline_recompile = rejit.get("recompile") or {}
    if not baseline_recompile.get("applied"):
        return {
            "comparable": False,
            "reason": baseline_recompile.get("error") or "BpfReJIT phase did not apply successfully",
        }

    def median_value(record: Mapping[str, object], field: str) -> float | None:
        stats = record.get("statistics") or {}
        summary = stats.get(field) or {}
        value = summary.get("median")
        return None if value is None else float(value)

    baseline_events = median_value(baseline, "events_per_sec")
    rejit_events = median_value(rejit, "events_per_sec")
    baseline_ops = median_value(baseline, "workload_ops_per_sec")
    rejit_ops = median_value(rejit, "workload_ops_per_sec")
    baseline_avg = median_value(baseline, "average_ns_per_run")
    rejit_avg = median_value(rejit, "average_ns_per_run")
    return {
        "comparable": True,
        "events_per_sec_speedup": None if not baseline_events or not rejit_events else rejit_events / baseline_events,
        "workload_ops_per_sec_speedup": None if not baseline_ops or not rejit_ops else rejit_ops / baseline_ops,
        "average_ns_per_run_ratio": None if not baseline_avg or not rejit_avg else rejit_avg / baseline_avg,
    }


def build_markdown_report(payload: Mapping[str, object]) -> str:
    lines: list[str] = [
        "# Tracee E2E Benchmark Results",
        "",
        f"- Generated: {payload['generated_at']}",
        f"- Mode selected: `{payload['mode_selected']}`",
        f"- Tracee binary: `{payload['tracee_binary'] or 'not available'}`",
        f"- Tracee object: `{payload['tracee_object']}`",
        f"- Runner: `{payload['runner_binary']}`",
        f"- Scanner: `{payload['scanner_binary']}`",
        "",
        "## Tooling",
        "",
    ]
    for tool, path in sorted((payload.get("tooling") or {}).items()):
        lines.append(f"- {tool}: `{path or 'missing'}`")
    lines.extend(["", "## Variant Summary", ""])

    for record in payload.get("records", []):
        execution = record.get("execution") or {}
        lines.append(f"### {record['policy_mode']}")
        lines.append("")
        recompile = record.get("recompile") or {}
        lines.append(f"- Recompile applied: `{recompile.get('applied')}`")
        if recompile.get("error"):
            lines.append(f"- Recompile error: `{recompile['error']}`")
        stats = record.get("statistics") or {}
        workload_summary = stats.get("workload_ops_per_sec") or {}
        event_summary = stats.get("events_per_sec") or {}
        avg_summary = stats.get("average_ns_per_run") or {}
        lines.append(f"- Workload ops/s median: `{workload_summary.get('median')}`")
        lines.append(f"- Event rate median: `{event_summary.get('median')}`")
        lines.append(f"- Avg BPF ns/run median: `{avg_summary.get('median')}`")
        lines.append("")
        for workload in execution.get("workloads", []):
            unsupported = workload.get("unsupported_events") or []
            suffix = f" unsupported={unsupported}" if unsupported else ""
            lines.append(
                f"- {workload['name']}: ops/s={workload.get('ops_per_sec')} "
                f"total_events/s={workload.get('total_events_per_sec')} events={workload.get('events_captured')}{suffix}"
            )
        lines.append("")

    comparison = payload.get("comparison") or {}
    lines.extend(["## Comparison", ""])
    if comparison.get("comparable"):
        lines.append(f"- Event-rate speedup: `{comparison.get('events_per_sec_speedup')}`")
        lines.append(f"- Workload-throughput speedup: `{comparison.get('workload_ops_per_sec_speedup')}`")
        lines.append(f"- Avg BPF ns/run ratio: `{comparison.get('average_ns_per_run_ratio')}`")
    else:
        lines.append("- Comparable: `False`")
        lines.append(f"- Reason: `{comparison.get('reason', 'unknown')}`")
    lines.append("")

    cgroup = payload.get("cgroup_test_run")
    if cgroup:
        lines.extend(["## cgroup_skb Fallback", ""])
        lines.append(f"- Repeat: `{cgroup['repeat']}`")
        for record in cgroup.get("records", []):
            baseline = record.get("baseline") or {}
            rejit = record.get("rejit") or {}
            lines.append(
                f"- {record['program']}: baseline_exec_ns={baseline.get('exec_ns')} "
                f"rejit_exec_ns={rejit.get('exec_ns')} rejit_error={((rejit.get('recompile') or {}).get('error') if rejit else record.get('rejit_error'))}"
            )
        lines.append("")

    notes = payload.get("notes") or []
    if notes:
        lines.extend(["## Notes", ""])
        for note in notes:
            lines.append(f"- {note}")
        lines.append("")
    return "\n".join(lines)


def prepare_tracee_session(
    args: argparse.Namespace,
    libbpf: Libbpf,
    inventory_by_name: Mapping[str, ProgramInventoryEntry],
) -> tuple[str, Any, str | None, dict[str, object]]:
    tracee_binary, tracee_install = resolve_tracee_binary(args.tracee_binary)
    if args.mode == "tracee" and not tracee_binary:
        raise BenchmarkError(tracee_install.get("error") or "Tracee binary unavailable")
    if args.mode != "manual" and tracee_binary:
        launch_errors: list[str] = []
        for command in build_tracee_commands(tracee_binary, args.tracee_extra_args):
            try:
                session = TraceeProcessSession(
                    libbpf,
                    tracee_binary,
                    command,
                    inventory_by_name,
                    args.load_timeout,
                )
                session.__enter__()
                return "tracee", session, tracee_binary, tracee_install
            except Exception as exc:
                launch_errors.append(f"{' '.join(command)} :: {exc}")
        tracee_install = dict(tracee_install)
        tracee_install["error"] = "; ".join(launch_errors[-3:])
        if args.mode == "tracee":
            raise BenchmarkError(tracee_install["error"])
    selected = choose_manual_programs(inventory_by_name)
    session = ManualTraceeSession(libbpf, Path(args.object), selected)
    session.__enter__()
    return "manual", session, tracee_binary, tracee_install


def close_session(session: Any) -> None:
    try:
        session.__exit__(None, None, None)
    except Exception:
        return


def main() -> int:
    args = parse_args()
    ensure_root()

    object_path = Path(args.object).resolve()
    runner_binary = Path(args.runner).resolve()
    scanner_binary = Path(args.scanner).resolve()
    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    ensure_parent(output_json)
    ensure_parent(output_md)
    packet_path = materialize_dummy_packet(DEFAULT_PACKET_PATH)
    bpftool_binary = resolve_bpftool_binary()

    tooling = {
        "bpftool": bpftool_binary,
        "stress-ng": which("stress-ng"),
        "fio": which("fio"),
        "wrk": which("wrk"),
        "tracee": which("tracee") or which("tracee-ebpf"),
        "curl": which("curl"),
        "dd": which("dd"),
    }
    install_result = maybe_install_tools(tooling)
    bpftool_binary = resolve_bpftool_binary()
    tooling = {
        "bpftool": bpftool_binary,
        "stress-ng": which("stress-ng"),
        "fio": which("fio"),
        "wrk": which("wrk"),
        "tracee": which("tracee") or which("tracee-ebpf"),
        "curl": which("curl"),
        "dd": which("dd"),
    }

    if not object_path.exists():
        raise BenchmarkError(f"Tracee object not found: {object_path}")
    if not runner_binary.exists():
        raise BenchmarkError(f"micro_exec not found: {runner_binary}")
    if not scanner_binary.exists():
        raise BenchmarkError(f"bpf-jit-scanner not found: {scanner_binary}")
    if tooling["bpftool"] is None:
        raise BenchmarkError("bpftool is required")
    if tooling["stress-ng"] is None:
        raise BenchmarkError("stress-ng is required")
    if tooling["curl"] is None:
        raise BenchmarkError("curl is required for the connect workload")
    if tooling["dd"] is None:
        raise BenchmarkError("dd is required for the file workload")

    host = host_metadata()
    inventory = discover_object_programs(runner_binary, object_path)
    inventory_by_name = {entry.name: entry for entry in inventory}
    selected_inventory = choose_manual_programs(inventory_by_name)
    workloads = build_workload_specs(args)
    notes: list[str] = []
    if args.mode != "manual" and tooling["tracee"] is None:
        notes.append("Tracee binary was not available on PATH; the benchmark will use the manual object-loader fallback.")
    if tooling["wrk"] is None:
        notes.append("wrk is not installed; the connect workload uses a curl loop against a localhost HTTP server.")

    directive_scan = {
        entry.name: probe_directive_scan(runner_binary, object_path, entry, packet_path, mode=args.recompile_mode)
        for entry in selected_inventory
    }

    records: list[UnifiedResultRecord] = []
    tracee_binary: str | None = None
    mode_selected: str = "dry-run"
    tracee_install: dict[str, object] = {"attempted": False, "error": None}

    if not args.dry_run:
        libbpf = Libbpf()
        mode_selected, session, tracee_binary, tracee_install = prepare_tracee_session(args, libbpf, inventory_by_name)
        try:
            stock_variant = run_variant(
                "stock",
                session,
                workloads,
                scanner_binary=scanner_binary,
                recompile_mode=args.recompile_mode,
                directive_scan=directive_scan,
                module_name=args.module_name,
                settle_seconds=float(args.settle_ms) / 1000.0,
            )
        finally:
            close_session(session)

        mode_selected, session, tracee_binary, tracee_install = prepare_tracee_session(args, libbpf, inventory_by_name)
        try:
            rejit_variant = run_variant(
                "bpfrejit",
                session,
                workloads,
                scanner_binary=scanner_binary,
                recompile_mode=args.recompile_mode,
                directive_scan=directive_scan,
                module_name=args.module_name,
                settle_seconds=float(args.settle_ms) / 1000.0,
            )
        finally:
            close_session(session)

        records = [
            build_record(
                stock_variant,
                benchmark_mode=mode_selected,
                object_path=object_path,
                tracee_binary=tracee_binary,
                runner_binary=runner_binary,
                scanner_binary=scanner_binary,
                host=host,
                inventory=selected_inventory,
                directive_scan=directive_scan,
                recompile_mode=args.recompile_mode,
                tracee_install=tracee_install,
            ),
            build_record(
                rejit_variant,
                benchmark_mode=mode_selected,
                object_path=object_path,
                tracee_binary=tracee_binary,
                runner_binary=runner_binary,
                scanner_binary=scanner_binary,
                host=host,
                inventory=selected_inventory,
                directive_scan=directive_scan,
                recompile_mode=args.recompile_mode,
                tracee_install=tracee_install,
            ),
        ]
    else:
        tracee_binary, tracee_install = resolve_tracee_binary(args.tracee_binary)
        mode_selected = "tracee" if tracee_binary and args.mode != "manual" else "manual"
        records = []

    cgroup_test_run = None
    if not args.no_cgroup_test and not args.dry_run:
        cgroup_test_run = run_cgroup_fallback(
            runner_binary,
            object_path,
            packet_path,
            args.cgroup_repeat,
            mode=args.recompile_mode,
        )

    if mode_selected == "manual":
        notes.append(
            "Manual fallback does not isolate Tracee's high-level `open` user event from the monolithic object; "
            "the file workload reports `security_file_open` and marks `open` as unsupported."
        )

    record_payloads = [asdict(record) for record in records]
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "mode_requested": args.mode,
        "mode_selected": mode_selected,
        "tracee_binary": tracee_binary,
        "tracee_object": str(object_path),
        "runner_binary": str(runner_binary),
        "scanner_binary": str(scanner_binary),
        "tooling": tooling,
        "tool_install": install_result,
        "host": host,
        "requested_events": list(TRACEE_EVENTS),
        "selected_programs": [
            {
                "name": entry.name,
                "section_name": entry.section_name,
                "prog_type_name": entry.prog_type_name,
                "attach_type_name": entry.attach_type_name,
            }
            for entry in selected_inventory
        ],
        "directive_scan": {name: dict(scan) for name, scan in directive_scan.items()},
        "records": record_payloads,
        "comparison": build_comparison(record_payloads),
        "cgroup_test_run": cgroup_test_run,
        "tracee_install": tracee_install,
        "notes": notes,
        "dry_run": args.dry_run,
    }

    output_json.write_text(json.dumps(payload, indent=2))
    output_md.write_text(build_markdown_report(payload))
    chown_to_invoking_user(output_json)
    chown_to_invoking_user(output_md)
    print(f"[done] wrote {output_json}")
    print(f"[done] wrote {output_md}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
