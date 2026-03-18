#!/usr/bin/env python3
from __future__ import annotations

import argparse
import ctypes
import ctypes.util
import json
import math
import os
import platform
import re
import shutil
import signal
import statistics
import subprocess
import sys
import tempfile
import time
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Sequence

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

from directive_census import ProgramResult, analyze_object
from e2e.common.recompile import apply_recompile as apply_recompile_by_id, scan_programs as scan_programs_by_id

try:
    from orchestrator.commands import build_list_programs_command, build_runner_command
    from orchestrator.environment import ensure_build_steps, sudo_available
    from orchestrator.results import parse_last_json_line, parse_runner_sample
except ImportError:
    from micro.orchestrator.commands import build_list_programs_command, build_runner_command
    from micro.orchestrator.environment import ensure_build_steps, sudo_available
    from micro.orchestrator.results import parse_last_json_line, parse_runner_sample


ROOT_DIR = Path(__file__).resolve().parent.parent
DEFAULT_OUTPUT_JSON = ROOT_DIR / "docs" / "tmp" / "bpftrace-e2e-results.json"
DEFAULT_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "bpftrace-e2e-results.md"
DEFAULT_ARTIFACT_DIR = ROOT_DIR / "docs" / "tmp" / "bpftrace-artifacts"
DEFAULT_RUNNER = ROOT_DIR / "micro" / "build" / "runner" / "micro_exec"
DEFAULT_SCANNER = ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"
MIN_BPFTRACE_VERSION = (0, 16, 0)
BPF_STATS_RUN_TIME = 0
BPF_TAG_SIZE = 8
BPF_OBJ_NAME_LEN = 16


@dataclass(frozen=True)
class ScriptSpec:
    name: str
    description: str
    program_text: str
    workload_kind: str
    expected_programs: int


SCRIPTS: tuple[ScriptSpec, ...] = (
    ScriptSpec(
        name="open_latency",
        description="kprobe/kretprobe open latency histogram",
        program_text=(
            "kprobe:do_sys_openat2 { @start[tid] = nsecs; } "
            "kretprobe:do_sys_openat2 /@start[tid]/ "
            "{ @ns = hist(nsecs - @start[tid]); delete(@start[tid]); }"
        ),
        workload_kind="open_latency",
        expected_programs=2,
    ),
    ScriptSpec(
        name="exec_tracing",
        description="tracepoint execve counter",
        program_text="tracepoint:syscalls:sys_enter_execve { @[comm] = count(); }",
        workload_kind="exec_tracing",
        expected_programs=1,
    ),
    ScriptSpec(
        name="scheduler_latency",
        description="tracepoint sched wakeup/switch latency histogram",
        program_text=(
            "tracepoint:sched:sched_wakeup { @qtime[args->pid] = nsecs; } "
            "tracepoint:sched:sched_switch /@qtime[args->next_pid]/ "
            "{ @usecs = hist((nsecs - @qtime[args->next_pid]) / 1000); "
            "delete(@qtime[args->next_pid]); }"
        ),
        workload_kind="scheduler_latency",
        expected_programs=2,
    ),
    ScriptSpec(
        name="vfs_read_count",
        description="kprobe vfs_read counter",
        program_text="kprobe:vfs_read { @reads[comm] = count(); }",
        workload_kind="vfs_read_count",
        expected_programs=1,
    ),
    ScriptSpec(
        name="tcp_connect",
        description="kprobe tcp_v4_connect counter",
        program_text="kprobe:tcp_v4_connect { @connects = count(); }",
        workload_kind="tcp_connect",
        expected_programs=1,
    ),
)


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


class LibbpfHandle:
    def __init__(self) -> None:
        load_error: OSError | None = None
        self.lib: ctypes.CDLL | None = None
        for name in ("libbpf.so.1", "libbpf.so"):
            try:
                self.lib = ctypes.CDLL(name, use_errno=True)
                break
            except OSError as exc:
                load_error = exc
        if self.lib is None:
            raise RuntimeError(f"unable to load libbpf: {load_error}")

        self.lib.bpf_enable_stats.argtypes = [ctypes.c_int]
        self.lib.bpf_enable_stats.restype = ctypes.c_int
        self.lib.bpf_prog_get_fd_by_id.argtypes = [ctypes.c_uint]
        self.lib.bpf_prog_get_fd_by_id.restype = ctypes.c_int
        self.lib.bpf_prog_get_info_by_fd.argtypes = [
            ctypes.c_int,
            ctypes.POINTER(BpfProgInfo),
            ctypes.POINTER(ctypes.c_uint32),
        ]
        self.lib.bpf_prog_get_info_by_fd.restype = ctypes.c_int
        self.stats_fd = -1

    def enable_stats(self) -> None:
        self.stats_fd = int(self.lib.bpf_enable_stats(BPF_STATS_RUN_TIME))
        if self.stats_fd < 0:
            err = ctypes.get_errno()
            raise RuntimeError(f"bpf_enable_stats failed: {os.strerror(err)} (errno={err})")

    def close(self) -> None:
        if self.stats_fd >= 0:
            os.close(self.stats_fd)
            self.stats_fd = -1

    def prog_fd_by_id(self, prog_id: int) -> int:
        fd = int(self.lib.bpf_prog_get_fd_by_id(int(prog_id)))
        if fd < 0:
            err = ctypes.get_errno()
            raise OSError(err, f"bpf_prog_get_fd_by_id({prog_id}) failed")
        return fd

    def prog_info_by_fd(self, prog_fd: int) -> BpfProgInfo:
        info = BpfProgInfo()
        info_len = ctypes.c_uint32(ctypes.sizeof(info))
        rc = self.lib.bpf_prog_get_info_by_fd(prog_fd, ctypes.byref(info), ctypes.byref(info_len))
        if rc != 0:
            err = ctypes.get_errno()
            raise OSError(err, f"bpf_prog_get_info_by_fd({prog_fd}) failed")
        return info


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Run an end-to-end bpftrace benchmark suite with artifact emission, "
            "directive-site scanning, and live BPF stats sampling."
        )
    )
    parser.add_argument(
        "--output-json",
        default=str(DEFAULT_OUTPUT_JSON),
        help="Structured JSON output path.",
    )
    parser.add_argument(
        "--output-md",
        default=str(DEFAULT_OUTPUT_MD),
        help="Markdown summary output path.",
    )
    parser.add_argument(
        "--artifact-dir",
        default=str(DEFAULT_ARTIFACT_DIR),
        help="Directory for emitted bpftrace ELF artifacts.",
    )
    parser.add_argument(
        "--runner",
        default=str(DEFAULT_RUNNER),
        help="Path to micro_exec.",
    )
    parser.add_argument(
        "--scanner",
        default=str(DEFAULT_SCANNER),
        help="Path to bpf-jit-scanner.",
    )
    parser.add_argument(
        "--duration",
        type=int,
        default=3,
        help="Per-workload duration in seconds for full runs.",
    )
    parser.add_argument(
        "--smoke-duration",
        type=int,
        default=1,
        help="Per-workload duration in seconds for smoke runs.",
    )
    parser.add_argument(
        "--attach-timeout",
        type=int,
        default=15,
        help="Seconds to wait for bpftrace programs to appear in bpftool.",
    )
    parser.add_argument(
        "--script",
        action="append",
        dest="scripts",
        help="Only run the named script(s). Repeatable.",
    )
    parser.add_argument(
        "--smoke",
        action="store_true",
        help="Run a single short smoke benchmark (`exec_tracing`).",
    )
    parser.add_argument(
        "--skip-build",
        action="store_true",
        help="Do not rebuild micro artifacts when they already exist.",
    )
    parser.add_argument(
        "--skip-live",
        action="store_true",
        help="Only do artifact emission and scanning, skipping live attach+trigger.",
    )
    parser.add_argument(
        "--skip-artifact",
        action="store_true",
        help="Skip `--emit-elf` artifact generation.",
    )
    parser.add_argument(
        "--keep-temporary",
        action="store_true",
        help="Keep temporary script/log files under `/tmp` for debugging.",
    )
    return parser.parse_args()


def ensure_root() -> None:
    if os.geteuid() == 0:
        return
    if not sudo_available():
        raise SystemExit("passwordless sudo is required for the bpftrace e2e runner")
    os.execvp("sudo", ["sudo", "-n", sys.executable, str(Path(__file__).resolve()), *sys.argv[1:]])


def invoking_uid_gid() -> tuple[int, int] | None:
    sudo_uid = os.environ.get("SUDO_UID")
    sudo_gid = os.environ.get("SUDO_GID")
    if sudo_uid is None or sudo_gid is None:
        return None
    try:
        return int(sudo_uid), int(sudo_gid)
    except ValueError:
        return None


def maybe_chown(path: Path) -> None:
    owner = invoking_uid_gid()
    if owner is None or not path.exists():
        return
    try:
        os.chown(path, owner[0], owner[1])
    except OSError:
        return


def ensure_parent(path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)


def tail_text(text: str, *, max_chars: int = 4000, max_lines: int = 30) -> str:
    lines = [line.rstrip() for line in text.splitlines() if line.strip()]
    if len(lines) > max_lines:
        lines = lines[-max_lines:]
    summary = "\n".join(lines)
    if len(summary) > max_chars:
        summary = summary[-max_chars:]
    return summary


def run_command(
    command: Sequence[str],
    *,
    timeout_seconds: int | None = None,
    pass_fds: Sequence[int] = (),
    cwd: Path = ROOT_DIR,
    env: dict[str, str] | None = None,
) -> dict[str, Any]:
    started = time.monotonic()
    try:
        completed = subprocess.run(
            list(command),
            cwd=cwd,
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
            pass_fds=tuple(pass_fds),
            env=env,
        )
        duration = time.monotonic() - started
        return {
            "ok": completed.returncode == 0,
            "returncode": completed.returncode,
            "timed_out": False,
            "duration_seconds": duration,
            "stdout": completed.stdout,
            "stderr": completed.stderr,
            "command": list(command),
            "error": "" if completed.returncode == 0 else tail_text(completed.stderr or completed.stdout),
        }
    except subprocess.TimeoutExpired as exc:
        duration = time.monotonic() - started
        return {
            "ok": False,
            "returncode": None,
            "timed_out": True,
            "duration_seconds": duration,
            "stdout": exc.stdout or "",
            "stderr": exc.stderr or "",
            "command": list(command),
            "error": f"timeout after {timeout_seconds}s",
        }


def parse_version(text: str) -> tuple[int, int, int] | None:
    match = re.search(r"(\d+)\.(\d+)(?:\.(\d+))?", text)
    if not match:
        return None
    major, minor, patch = match.groups()
    return int(major), int(minor), int(patch or 0)


def version_at_least(version: tuple[int, int, int] | None, minimum: tuple[int, int, int]) -> bool:
    if version is None:
        return False
    return version >= minimum


def install_packages(packages: Sequence[str]) -> None:
    if not packages:
        return
    completed = subprocess.run(["apt-get", "install", "-y", *packages], cwd=ROOT_DIR, text=True)
    if completed.returncode != 0:
        raise RuntimeError(f"failed to install required packages: {' '.join(packages)}")


def ensure_required_tools() -> dict[str, Any]:
    missing: list[str] = []
    if shutil.which("bpftrace") is None:
        missing.append("bpftrace")
    if shutil.which("stress-ng") is None:
        missing.append("stress-ng")
    if missing:
        install_packages(missing)

    bpftool_path = shutil.which("bpftool")
    if bpftool_path is None:
        raise RuntimeError("bpftool is required but not present in PATH")

    llvm_objcopy = shutil.which("llvm-objcopy")
    if llvm_objcopy is None:
        raise RuntimeError("llvm-objcopy is required but not present in PATH")

    version_result = run_command(["bpftrace", "--version"])
    if not version_result["ok"]:
        raise RuntimeError(version_result["error"] or "unable to determine bpftrace version")
    version = parse_version(version_result["stdout"] or version_result["stderr"])
    if not version_at_least(version, MIN_BPFTRACE_VERSION):
        raise RuntimeError(
            f"bpftrace {version_result['stdout'].strip()} does not meet "
            f"the required >= {MIN_BPFTRACE_VERSION[0]}.{MIN_BPFTRACE_VERSION[1]}"
        )

    stress_version = run_command(["stress-ng", "--version"])
    bpftool_version = run_command(["bpftool", "version"])

    return {
        "bpftrace_path": shutil.which("bpftrace"),
        "bpftrace_version_text": (version_result["stdout"] or version_result["stderr"]).strip(),
        "bpftrace_version": version,
        "stress_ng_path": shutil.which("stress-ng"),
        "stress_ng_version_text": (stress_version["stdout"] or stress_version["stderr"]).splitlines()[0].strip()
        if (stress_version["stdout"] or stress_version["stderr"]).strip()
        else "",
        "bpftool_path": bpftool_path,
        "bpftool_version_text": tail_text(bpftool_version["stdout"] or bpftool_version["stderr"], max_lines=3),
        "fio_path": shutil.which("fio"),
        "llvm_objcopy_path": llvm_objcopy,
    }


def ensure_micro_artifacts(runner: Path, scanner: Path, *, skip_build: bool) -> None:
    if not skip_build:
        ensure_build_steps(
            {
                "micro_exec": ("make", "-C", "micro", "micro_exec"),
                "programs": ("make", "-C", "micro", "programs"),
            },
            root_dir=ROOT_DIR,
            build_order=("micro_exec", "programs"),
        )

    if not runner.exists():
        raise RuntimeError(f"micro_exec not found: {runner}")

    if scanner.exists():
        return

    cmake_configure = subprocess.run(
        ["cmake", "-S", "scanner", "-B", "scanner/build", "-DCMAKE_BUILD_TYPE=Release"],
        cwd=ROOT_DIR,
        text=True,
    )
    if cmake_configure.returncode != 0:
        raise RuntimeError("failed to configure scanner build")
    cmake_build = subprocess.run(
        ["cmake", "--build", "scanner/build", "--target", "bpf-jit-scanner", "-j"],
        cwd=ROOT_DIR,
        text=True,
    )
    if cmake_build.returncode != 0:
        raise RuntimeError("failed to build bpf-jit-scanner")
    if not scanner.exists():
        raise RuntimeError(f"scanner not found after build: {scanner}")


def selected_scripts(args: argparse.Namespace) -> list[ScriptSpec]:
    if args.smoke:
        return [next(spec for spec in SCRIPTS if spec.name == "exec_tracing")]
    if not args.scripts:
        return list(SCRIPTS)
    allowed = {name.strip() for name in args.scripts if name.strip()}
    return [spec for spec in SCRIPTS if spec.name in allowed]


def format_float(value: float | None, digits: int = 2) -> str:
    if value is None:
        return "n/a"
    return f"{value:.{digits}f}"


def format_ratio(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.3f}x"


def geomean(values: Sequence[float]) -> float | None:
    positive = [value for value in values if value > 0]
    if not positive:
        return None
    return math.exp(statistics.mean(math.log(value) for value in positive))


def markdown_table(headers: Sequence[str], rows: Sequence[Sequence[Any]]) -> list[str]:
    lines = [
        "| " + " | ".join(headers) + " |",
        "| " + " | ".join("---" for _ in headers) + " |",
    ]
    for row in rows:
        lines.append("| " + " | ".join(str(cell) for cell in row) + " |")
    return lines


def summarize_raw_scan(scan: ProgramResult) -> dict[str, Any]:
    return {
        "cmov_sites": scan.cmov,
        "wide_sites": scan.wide,
        "rotate_sites": scan.rotate,
        "lea_sites": scan.lea,
        "total_sites": scan.total,
        "insn_count": scan.insn_count,
        "exec_section_count": scan.exec_section_count,
        "sections": [
            {
                "name": section.name,
                "insn_count": section.insn_count,
                "cmov_sites": section.cmov,
                "wide_sites": section.wide,
                "rotate_sites": section.rotate,
                "lea_sites": section.lea,
                "total_sites": section.total,
            }
            for section in scan.sections
        ],
    }


def list_program_inventory(runner: Path, object_path: Path) -> dict[str, Any]:
    result = run_command(build_list_programs_command(runner, object_path))
    payload: list[dict[str, Any]] = []
    if result["ok"]:
        try:
            parsed = parse_last_json_line(result["stdout"], label="list-programs")
            if isinstance(parsed, list):
                payload = [item for item in parsed if isinstance(item, dict)]
            else:
                result["ok"] = False
                result["error"] = "list-programs did not return a JSON array"
        except Exception as exc:
            result["ok"] = False
            result["error"] = str(exc)
    return {
        "ok": result["ok"],
        "error": result["error"],
        "inventory": payload,
        "stderr_tail": tail_text(result["stderr"]),
        "stdout_tail": tail_text(result["stdout"]),
        "command": result["command"],
    }


def canonicalize_bpftrace_section(section_name: str) -> str | None:
    if not section_name.startswith("s_"):
        return None
    base = re.sub(r"_\d+$", "", section_name[2:])
    if base.startswith("kprobe:"):
        return "kprobe/" + base[len("kprobe:"):]
    if base.startswith("kretprobe:"):
        return "kretprobe/" + base[len("kretprobe:"):]
    if base.startswith("tracepoint:"):
        return "tracepoint/" + base[len("tracepoint:"):].replace(":", "/")
    if base.startswith("raw_tracepoint:"):
        return "raw_tracepoint/" + base[len("raw_tracepoint:"):].replace(":", "/")
    if base.startswith("raw_tp:"):
        return "raw_tp/" + base[len("raw_tp:"):].replace(":", "/")
    if base.startswith("uprobe:"):
        return "uprobe/" + base[len("uprobe:"):]
    if base.startswith("uretprobe:"):
        return "uretprobe/" + base[len("uretprobe:"):]
    return base.replace(":", "/")


def normalize_bpftrace_artifact(source: Path, destination: Path, raw_scan: ProgramResult) -> dict[str, Any]:
    ensure_parent(destination)
    shutil.copy2(source, destination)
    rename_pairs: list[tuple[str, str]] = []
    for section in raw_scan.sections:
        renamed = canonicalize_bpftrace_section(section.name)
        if renamed and renamed != section.name:
            rename_pairs.append((section.name, renamed))
    if rename_pairs:
        command = ["llvm-objcopy"]
        for old, new in rename_pairs:
            command.extend(["--rename-section", f"{old}={new}"])
        command.append(str(destination))
        result = run_command(command)
    else:
        result = {
            "ok": True,
            "returncode": 0,
            "timed_out": False,
            "duration_seconds": 0.0,
            "stdout": "",
            "stderr": "",
            "command": [],
            "error": "",
        }
    maybe_chown(destination)
    return {
        "ok": result["ok"],
        "error": result["error"],
        "rename_pairs": [{"old": old, "new": new} for old, new in rename_pairs],
        "command": result["command"],
        "stderr_tail": tail_text(result["stderr"]),
    }


def probe_normalized_load(runner: Path, object_path: Path, inventory: Sequence[dict[str, Any]]) -> dict[str, Any]:
    records: list[dict[str, Any]] = []
    for program in inventory:
        program_name = str(program.get("name", ""))
        command = build_runner_command(
            runner,
            "run-kernel",
            program=object_path,
            program_name=program_name,
            io_mode="context",
            repeat=1,
            compile_only=True,
        )
        result = run_command(command)
        sample = None
        if result["ok"]:
            try:
                sample = parse_runner_sample(result["stdout"])
            except Exception as exc:
                result["ok"] = False
                result["error"] = str(exc)
        records.append(
            {
                "program_name": program_name,
                "ok": result["ok"],
                "error": result["error"],
                "stderr_tail": tail_text(result["stderr"]),
                "stdout_tail": tail_text(result["stdout"]),
                "sample": sample,
                "command": result["command"],
            }
        )
    return {
        "attempted": bool(inventory),
        "successes": sum(1 for record in records if record["ok"]),
        "records": records,
    }


def emit_bpftrace_artifact(spec: ScriptSpec, runner: Path, artifact_dir: Path) -> dict[str, Any]:
    artifact_dir.mkdir(parents=True, exist_ok=True)
    artifact_path = artifact_dir / f"{spec.name}.bpf.o"
    if artifact_path.exists():
        artifact_path.unlink()

    emit = run_command(["bpftrace", "--emit-elf", str(artifact_path), "-e", spec.program_text], timeout_seconds=90)
    result: dict[str, Any] = {
        "artifact_path": str(artifact_path),
        "emit": {
            "ok": emit["ok"] and artifact_path.exists() and artifact_path.stat().st_size > 0,
            "error": emit["error"],
            "command": emit["command"],
            "stderr_tail": tail_text(emit["stderr"]),
            "stdout_tail": tail_text(emit["stdout"]),
            "returncode": emit["returncode"],
        },
        "raw_scan": None,
        "raw_inventory": None,
        "normalized_artifact_path": None,
        "normalized_inventory": None,
        "normalize": None,
        "load_probe": None,
    }
    if not result["emit"]["ok"]:
        return result

    maybe_chown(artifact_path)
    raw_scan = analyze_object(artifact_path, "bpftrace", ROOT_DIR)
    raw_inventory = list_program_inventory(runner, artifact_path)
    normalized_path = artifact_dir / f"{spec.name}.libbpf.bpf.o"
    normalize = normalize_bpftrace_artifact(artifact_path, normalized_path, raw_scan)
    normalized_inventory = list_program_inventory(runner, normalized_path) if normalize["ok"] else {
        "ok": False,
        "error": normalize["error"],
        "inventory": [],
        "stderr_tail": "",
        "stdout_tail": "",
        "command": [],
    }
    load_probe = probe_normalized_load(runner, normalized_path, normalized_inventory["inventory"]) if normalize["ok"] else {
        "attempted": False,
        "successes": 0,
        "records": [],
    }

    result["raw_scan"] = summarize_raw_scan(raw_scan)
    result["raw_inventory"] = raw_inventory
    result["normalized_artifact_path"] = str(normalized_path)
    result["normalize"] = normalize
    result["normalized_inventory"] = normalized_inventory
    result["load_probe"] = load_probe
    return result


def bpftool_prog_show() -> list[dict[str, Any]]:
    payload = run_command(["bpftool", "-j", "prog", "show"], timeout_seconds=30)
    if not payload["ok"]:
        raise RuntimeError(payload["error"] or "bpftool prog show failed")
    data = json.loads(payload["stdout"])
    if not isinstance(data, list):
        raise RuntimeError("bpftool prog show did not return a JSON array")
    return [item for item in data if isinstance(item, dict)]


def filter_new_bpftrace_programs(
    payload: Sequence[dict[str, Any]],
    before_ids: set[int],
) -> list[dict[str, Any]]:
    matches: list[dict[str, Any]] = []
    for item in payload:
        try:
            prog_id = int(item["id"])
        except (KeyError, TypeError, ValueError):
            continue
        if prog_id in before_ids:
            continue
        pids = item.get("pids") or []
        if not any(isinstance(pid_record, dict) and pid_record.get("comm") == "bpftrace" for pid_record in pids):
            continue
        matches.append(item)
    return sorted(matches, key=lambda item: int(item.get("id", 0)))


def wait_for_bpftrace_programs(
    process: subprocess.Popen[str],
    *,
    before_ids: set[int],
    expected_count: int,
    timeout_seconds: int,
) -> list[dict[str, Any]]:
    deadline = time.monotonic() + timeout_seconds
    last_nonempty: list[dict[str, Any]] = []
    stable_ids: tuple[int, ...] | None = None
    stable_rounds = 0
    while time.monotonic() < deadline:
        if process.poll() is not None and not last_nonempty:
            break
        matches = filter_new_bpftrace_programs(bpftool_prog_show(), before_ids)
        if matches:
            last_nonempty = matches
            ids = tuple(int(item["id"]) for item in matches)
            if ids == stable_ids:
                stable_rounds += 1
            else:
                stable_ids = ids
                stable_rounds = 1
            if len(matches) >= expected_count and stable_rounds >= 2:
                return matches
        time.sleep(0.5)
    return last_nonempty


def snapshot_from_info(info: BpfProgInfo) -> dict[str, Any]:
    return {
        "id": int(info.id),
        "name": bytes(info.name).split(b"\0", 1)[0].decode("utf-8", "replace"),
        "run_cnt": int(info.run_cnt),
        "run_time_ns": int(info.run_time_ns),
        "jited_prog_len": int(info.jited_prog_len),
        "xlated_prog_len": int(info.xlated_prog_len),
        "tag": bytes(info.tag).hex(),
        "btf_id": int(info.btf_id),
        "verified_insns": int(info.verified_insns),
    }


def scan_live_program(scanner: Path, prog_id: int, program_name: str) -> dict[str, Any]:
    del program_name
    counts = {
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
        "total_sites": 0,
    }
    result = scan_programs_by_id([prog_id], scanner).get(int(prog_id), {})
    counts.update(result.get("sites") or {})
    command = [str(scanner), "enumerate", "--prog-id", str(prog_id), "--all", "--json"]
    return {
        "ok": not bool(result.get("error")),
        "error": str(result.get("error") or ""),
        "counts": counts,
        "stdout_tail": tail_text(str(result.get("stdout_tail") or "")),
        "stderr_tail": tail_text(str(result.get("stderr_tail") or "")),
        "command": command,
    }


def apply_live_recompile(scanner: Path, prog_id: int, program_name: str) -> dict[str, Any]:
    del program_name
    counts = {
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
        "total_sites": 0,
    }
    result = apply_recompile_by_id([prog_id], scanner, blind_apply=True).get(int(prog_id), {})
    counts.update(result.get("counts") or {})
    applied = bool(result.get("applied"))
    error = str(result.get("error") or "")
    command = [str(scanner), "enumerate", "--prog-id", str(prog_id), "--all", "--recompile", "--json"]
    return {
        "ok": applied and not error,
        "applied": applied,
        "error": error,
        "counts": counts,
        "stdout_tail": tail_text(str(result.get("stdout_tail") or "")),
        "stderr_tail": tail_text(str(result.get("stderr_tail") or "")),
        "command": command,
        "returncode": 0 if applied and not error else 1,
    }


def aggregate_site_counts(items: Sequence[dict[str, Any]]) -> dict[str, int]:
    totals = {
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
        "total_sites": 0,
    }
    for item in items:
        counts = item.get("counts") or {}
        for field in totals:
            totals[field] += int(counts.get(field, 0) or 0)
    return totals


def aggregate_avg_exec(before: dict[int, dict[str, Any]], after: dict[int, dict[str, Any]]) -> dict[str, Any]:
    run_cnt_delta = 0
    run_time_ns_delta = 0
    per_program: list[dict[str, Any]] = []
    for prog_id, before_snapshot in before.items():
        after_snapshot = after.get(prog_id)
        if after_snapshot is None:
            continue
        delta_cnt = max(0, int(after_snapshot["run_cnt"]) - int(before_snapshot["run_cnt"]))
        delta_time = max(0, int(after_snapshot["run_time_ns"]) - int(before_snapshot["run_time_ns"]))
        avg_exec_ns = None if delta_cnt == 0 else delta_time / delta_cnt
        run_cnt_delta += delta_cnt
        run_time_ns_delta += delta_time
        per_program.append(
            {
                "prog_id": prog_id,
                "name": after_snapshot["name"],
                "run_cnt_delta": delta_cnt,
                "run_time_ns_delta": delta_time,
                "avg_exec_ns": avg_exec_ns,
            }
        )
    avg_exec_ns = None if run_cnt_delta == 0 else run_time_ns_delta / run_cnt_delta
    return {
        "run_cnt_delta": run_cnt_delta,
        "run_time_ns_delta": run_time_ns_delta,
        "avg_exec_ns": avg_exec_ns,
        "per_program": per_program,
    }


def prepare_read_file(path: Path, size_mb: int = 16) -> None:
    if path.exists() and path.stat().st_size >= size_mb * 1024 * 1024:
        return
    ensure_parent(path)
    with path.open("wb") as handle:
        chunk = b"\0" * 1024 * 1024
        for _ in range(size_mb):
            handle.write(chunk)


def build_workload_command(spec: ScriptSpec, workdir: Path, duration_seconds: int) -> tuple[list[str], str]:
    if spec.workload_kind == "open_latency":
        command = [
            "stress-ng",
            "--open",
            "4",
            "--timeout",
            f"{max(1, duration_seconds)}s",
            "--metrics-brief",
            "--temp-path",
            str(workdir),
        ]
        return command, "stress-ng open/close storm"
    if spec.workload_kind == "exec_tracing":
        command = [
            "stress-ng",
            "--exec",
            "2",
            "--exec-method",
            "execve",
            "--timeout",
            f"{max(1, duration_seconds)}s",
            "--metrics-brief",
        ]
        return command, "stress-ng execve storm"
    if spec.workload_kind == "scheduler_latency":
        command = [
            "stress-ng",
            "--switch",
            "4",
            "--switch-method",
            "pipe",
            "--timeout",
            f"{max(1, duration_seconds)}s",
            "--metrics-brief",
        ]
        return command, "stress-ng context-switch storm"
    if spec.workload_kind == "vfs_read_count":
        fio_path = shutil.which("fio")
        read_file = workdir / "fio-read-target.bin"
        prepare_read_file(read_file)
        if fio_path is not None:
            command = [
                fio_path,
                "--name=vfsread",
                f"--filename={read_file}",
                "--rw=read",
                "--bs=4k",
                "--ioengine=psync",
                "--iodepth=1",
                "--numjobs=1",
                "--time_based=1",
                f"--runtime={max(1, duration_seconds)}",
                "--size=16m",
                "--group_reporting",
            ]
            return command, "fio sequential reads"
        command = [
            "dd",
            f"if={read_file}",
            "of=/dev/null",
            "bs=4k",
            "status=none",
        ]
        return command, "dd fallback sequential reads"
    if spec.workload_kind == "tcp_connect":
        command = [
            "stress-ng",
            "--sock",
            "4",
            "--sock-domain",
            "ipv4",
            "--sock-type",
            "stream",
            "--timeout",
            f"{max(1, duration_seconds)}s",
            "--metrics-brief",
        ]
        return command, "stress-ng TCP socket churn"
    raise RuntimeError(f"unsupported workload kind: {spec.workload_kind}")


def run_workload(spec: ScriptSpec, workdir: Path, duration_seconds: int) -> dict[str, Any]:
    command, description = build_workload_command(spec, workdir, duration_seconds)
    result = run_command(command, timeout_seconds=max(30, duration_seconds * 10), cwd=workdir)
    return {
        "description": description,
        "command": result["command"],
        "ok": result["ok"],
        "returncode": result["returncode"],
        "timed_out": result["timed_out"],
        "duration_seconds": result["duration_seconds"],
        "stdout_tail": tail_text(result["stdout"]),
        "stderr_tail": tail_text(result["stderr"]),
        "error": result["error"],
    }


def stop_bpftrace_process(process: subprocess.Popen[str]) -> dict[str, Any]:
    status = {
        "signal": "SIGINT",
        "returncode": None,
        "timed_out": False,
    }
    if process.poll() is None:
        process.send_signal(signal.SIGINT)
        try:
            process.wait(timeout=5)
        except subprocess.TimeoutExpired:
            status["timed_out"] = True
            process.terminate()
            try:
                process.wait(timeout=3)
            except subprocess.TimeoutExpired:
                process.kill()
                process.wait(timeout=3)
    status["returncode"] = process.returncode
    return status


def live_benchmark_with_process_tail(
    spec: ScriptSpec,
    libbpf: LibbpfHandle,
    scanner: Path,
    *,
    duration_seconds: int,
    attach_timeout: int,
    keep_temporary: bool,
) -> dict[str, Any]:
    temp_dir_obj = tempfile.TemporaryDirectory(prefix=f"bpftrace-{spec.name}-", dir="/tmp")
    temp_dir = Path(temp_dir_obj.name)
    script_path = temp_dir / f"{spec.name}.bt"
    stdout_path = temp_dir / f"{spec.name}.stdout.log"
    stderr_path = temp_dir / f"{spec.name}.stderr.log"
    script_path.write_text(f'BEGIN {{ printf("BPFTRACE_READY\\n"); }}\n{spec.program_text}\n')
    maybe_chown(script_path)

    before_ids = {int(item["id"]) for item in bpftool_prog_show() if "id" in item}
    stdout_handle = stdout_path.open("w")
    stderr_handle = stderr_path.open("w")
    process = subprocess.Popen(
        ["bpftrace", str(script_path)],
        cwd=ROOT_DIR,
        stdout=stdout_handle,
        stderr=stderr_handle,
        text=True,
    )

    program_records: list[dict[str, Any]] = []
    result: dict[str, Any] = {
        "ok": False,
        "error": "",
        "programs": [],
        "baseline_workload": None,
        "rejit_workload": None,
        "baseline_aggregate": None,
        "rejit_aggregate": None,
        "site_totals": {
            "cmov_sites": 0,
            "wide_sites": 0,
            "rotate_sites": 0,
            "lea_sites": 0,
            "total_sites": 0,
        },
        "program_type": "",
        "recompile": {
            "attempted_programs": 0,
            "eligible_programs": 0,
            "applied_programs": 0,
            "errors": [],
        },
        "bpftrace_process": {},
    }

    try:
        programs = wait_for_bpftrace_programs(
            process,
            before_ids=before_ids,
            expected_count=spec.expected_programs,
            timeout_seconds=attach_timeout,
        )
        if not programs:
            result["error"] = "no bpftrace-owned programs became visible in bpftool"
            return result

        for item in programs:
            prog_id = int(item["id"])
            prog_fd = libbpf.prog_fd_by_id(prog_id)
            scan = scan_live_program(scanner, prog_id, str(item.get("name", "")))
            info = libbpf.prog_info_by_fd(prog_fd)
            program_records.append(
                {
                    "id": prog_id,
                    "fd": prog_fd,
                    "name": str(item.get("name", "")),
                    "type": str(item.get("type", "")),
                    "bpftool": item,
                    "scan": scan,
                    "baseline_before": snapshot_from_info(info),
                    "baseline_after": None,
                    "rejit_before": None,
                    "rejit_after": None,
                    "recompile": None,
                }
            )

        baseline_workload = run_workload(spec, temp_dir, duration_seconds)
        baseline_before = {record["id"]: record["baseline_before"] for record in program_records}
        baseline_after: dict[int, dict[str, Any]] = {}
        for record in program_records:
            info = libbpf.prog_info_by_fd(record["fd"])
            record["baseline_after"] = snapshot_from_info(info)
            baseline_after[record["id"]] = record["baseline_after"]
        baseline_aggregate = aggregate_avg_exec(baseline_before, baseline_after)

        attempted_programs = 0
        eligible_programs = 0
        applied_programs = 0
        recompile_errors: list[str] = []
        for record in program_records:
            counts = record["scan"]["counts"]
            if counts["total_sites"] <= 0:
                continue
            eligible_programs += 1
            attempted_programs += 1
            apply = apply_live_recompile(scanner, int(record["id"]), str(record["name"]))
            record["recompile"] = apply
            if apply["applied"]:
                applied_programs += 1
            elif apply["error"]:
                recompile_errors.append(f"{record['name']}: {apply['error']}")

        rejit_workload = None
        rejit_aggregate = None
        if applied_programs > 0:
            rejit_before: dict[int, dict[str, Any]] = {}
            for record in program_records:
                info = libbpf.prog_info_by_fd(record["fd"])
                record["rejit_before"] = snapshot_from_info(info)
                rejit_before[record["id"]] = record["rejit_before"]
            rejit_workload = run_workload(spec, temp_dir, duration_seconds)
            rejit_after: dict[int, dict[str, Any]] = {}
            for record in program_records:
                info = libbpf.prog_info_by_fd(record["fd"])
                record["rejit_after"] = snapshot_from_info(info)
                rejit_after[record["id"]] = record["rejit_after"]
            rejit_aggregate = aggregate_avg_exec(rejit_before, rejit_after)

        result = {
            "ok": True,
            "error": "",
            "programs": [
                {
                    key: value
                    for key, value in record.items()
                    if key != "fd"
                }
                for record in program_records
            ],
            "baseline_workload": baseline_workload,
            "rejit_workload": rejit_workload,
            "baseline_aggregate": baseline_aggregate,
            "rejit_aggregate": rejit_aggregate,
            "site_totals": aggregate_site_counts([record["scan"] for record in program_records]),
            "program_type": ",".join(sorted({record["type"] for record in program_records if record["type"]})),
            "recompile": {
                "attempted_programs": attempted_programs,
                "eligible_programs": eligible_programs,
                "applied_programs": applied_programs,
                "errors": recompile_errors,
            },
            "bpftrace_process": {},
        }
        return result
    finally:
        for record in program_records:
            fd = record.get("fd")
            if isinstance(fd, int) and fd >= 0:
                try:
                    os.close(fd)
                except OSError:
                    pass
        process_status = stop_bpftrace_process(process)
        stdout_handle.close()
        stderr_handle.close()
        stdout_text = stdout_path.read_text() if stdout_path.exists() else ""
        stderr_text = stderr_path.read_text() if stderr_path.exists() else ""
        result["bpftrace_process"] = {
            "returncode": process_status["returncode"],
            "timed_out": process_status["timed_out"],
            "stdout_tail": tail_text(stdout_text),
            "stderr_tail": tail_text(stderr_text),
        }
        if keep_temporary:
            maybe_chown(script_path)
            maybe_chown(stdout_path)
            maybe_chown(stderr_path)
        else:
            temp_dir_obj.cleanup()


def summarize_script_result(script: ScriptSpec, artifact: dict[str, Any] | None, live: dict[str, Any] | None) -> dict[str, Any]:
    live_sites = ((live or {}).get("site_totals") or {}).get("total_sites")
    artifact_sites = ((artifact or {}).get("raw_scan") or {}).get("total_sites")
    sites = int(live_sites or artifact_sites or 0)
    stock_ns = None
    rejit_ns = None
    program_type = ""
    if live:
        baseline = live.get("baseline_aggregate") or {}
        rejit = live.get("rejit_aggregate") or {}
        stock_ns = baseline.get("avg_exec_ns")
        rejit_ns = rejit.get("avg_exec_ns")
        program_type = str(live.get("program_type", ""))
    if not program_type and artifact:
        normalized_inventory = ((artifact.get("normalized_inventory") or {}).get("inventory") or [])
        raw_inventory = ((artifact.get("raw_inventory") or {}).get("inventory") or [])
        inventory = normalized_inventory or raw_inventory
        types = {
            str(item.get("prog_type_name", "")).strip()
            for item in inventory
            if str(item.get("prog_type_name", "")).strip()
        }
        program_type = ",".join(sorted(types))
    speedup = None
    if stock_ns and rejit_ns:
        speedup = float(stock_ns) / float(rejit_ns)
    return {
        "name": script.name,
        "description": script.description,
        "program_type": program_type or "unknown",
        "sites": sites,
        "stock_ns": stock_ns,
        "rejit_ns": rejit_ns,
        "speedup": speedup,
    }


def compact_note(text: str, *, max_chars: int = 180) -> str:
    lines = [line.strip() for line in text.splitlines() if line.strip()]
    source = lines[-1] if lines else text.strip()
    single_line = " ".join(source.split())
    if len(single_line) <= max_chars:
        return single_line
    return single_line[: max_chars - 3] + "..."


def script_note(record: dict[str, Any]) -> str:
    live = record.get("live") or {}
    artifact = record.get("artifact") or {}
    if live.get("error"):
        return compact_note(str(live["error"]))
    if live and live.get("recompile", {}).get("errors"):
        return compact_note(live["recompile"]["errors"][0])
    load_probe = artifact.get("load_probe") or {}
    probe_records = load_probe.get("records") or []
    if probe_records and all(not item.get("ok") for item in probe_records):
        error = probe_records[0].get("error") or "artifact load probe failed"
        return compact_note(error)
    if not artifact:
        return ""
    if not ((artifact.get("emit") or {}).get("ok")):
        error = (artifact.get("emit") or {}).get("error") or "emit-elf failed"
        return compact_note(error)
    return ""


def build_markdown_report(data: dict[str, Any]) -> str:
    lines = [
        "# bpftrace E2E Results",
        "",
        f"- Generated: `{data['generated_at']}`",
        f"- Host: `{data['host']['kernel']}`",
        f"- bpftrace: `{data['tool_versions']['bpftrace_version_text']}`",
        f"- stress-ng: `{data['tool_versions']['stress_ng_version_text']}`",
        f"- bpftool: `{data['tool_versions']['bpftool_version_text']}`",
        f"- Runner: `{data['runner']}`",
        f"- Scanner: `{data['scanner']}`",
        f"- Artifact dir: `{data['artifact_dir']}`",
        "",
        "## Summary",
        "",
    ]

    summary = data["summary"]
    lines.extend(
        [
            f"- Scripts run: {summary['scripts_run']}",
            f"- `--emit-elf` successes: {summary['emit_successes']}",
            f"- Artifact load-probe successes: {summary['artifact_load_successes']}",
            f"- Live attach successes: {summary['live_successes']}",
            f"- Live recompile successes: {summary['live_recompile_successes']}",
            f"- Aggregate sites: {summary['site_totals']['total_sites']} "
            f"(cmov={summary['site_totals']['cmov_sites']}, "
            f"wide={summary['site_totals']['wide_sites']}, "
            f"rotate={summary['site_totals']['rotate_sites']}, "
            f"lea={summary['site_totals']['lea_sites']})",
            f"- Geomean speedup: {format_ratio(summary['speedup_geomean'])}",
            "",
            "## Per-Script",
            "",
        ]
    )

    table_rows = []
    for record in data["records"]:
        summary_record = record["summary"]
        table_rows.append(
            [
                summary_record["name"],
                summary_record["program_type"],
                summary_record["sites"],
                format_float(summary_record["stock_ns"]),
                format_float(summary_record["rejit_ns"]),
                format_ratio(summary_record["speedup"]),
                "yes" if ((record.get("artifact") or {}).get("emit") or {}).get("ok") else "no",
                "yes" if (record.get("live") or {}).get("ok") else "no",
                script_note(record) or "ok",
            ]
        )
    lines.extend(
        markdown_table(
            ["Script", "Program Type", "Sites", "Stock ns", "ReJIT ns", "Speedup", "ELF", "Live", "Notes"],
            table_rows,
        )
    )
    lines.append("")
    lines.append("## Notes")
    lines.append("")
    lines.append("- `Sites` prefer live scanner counts on loaded programs; when live attach fails, the report falls back to raw emitted-ELF candidate sites.")
    lines.append("- The artifact-first path emits `.bpf.o` files, scans them, renames sections into libbpf-like forms, and then attempts `micro_exec run-kernel --compile-only` as a generic load probe.")
    lines.append("- `Stock ns` and `ReJIT ns` are weighted averages derived from `delta(run_time_ns) / delta(run_cnt)` across the bpftrace-owned programs for the same script.")
    lines.append("- If the running kernel returns `BPF_PROG_JIT_RECOMPILE: EINVAL`, the script records the failure and leaves `ReJIT ns` / `Speedup` as `n/a` instead of reporting a fake comparison.")
    lines.append("")
    return "\n".join(lines)


def artifact_failure(spec: ScriptSpec, artifact_dir: Path, error: str) -> dict[str, Any]:
    return {
        "artifact_path": str(artifact_dir / f"{spec.name}.bpf.o"),
        "emit": {
            "ok": False,
            "error": error,
            "command": [],
            "stderr_tail": error,
            "stdout_tail": "",
            "returncode": None,
        },
        "raw_scan": None,
        "raw_inventory": None,
        "normalized_artifact_path": None,
        "normalized_inventory": None,
        "normalize": None,
        "load_probe": None,
    }


def live_failure(error: str) -> dict[str, Any]:
    return {
        "ok": False,
        "error": error,
        "programs": [],
        "baseline_workload": None,
        "rejit_workload": None,
        "baseline_aggregate": None,
        "rejit_aggregate": None,
        "site_totals": {
            "cmov_sites": 0,
            "wide_sites": 0,
            "rotate_sites": 0,
            "lea_sites": 0,
            "total_sites": 0,
        },
        "program_type": "",
        "recompile": {
            "attempted_programs": 0,
            "eligible_programs": 0,
            "applied_programs": 0,
            "errors": [],
        },
        "bpftrace_process": {},
    }


def main() -> None:
    args = parse_args()
    ensure_root()

    runner = Path(args.runner).resolve()
    scanner = Path(args.scanner).resolve()
    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    artifact_dir = Path(args.artifact_dir).resolve()

    tool_versions = ensure_required_tools()
    ensure_micro_artifacts(runner, scanner, skip_build=args.skip_build)

    scripts = selected_scripts(args)
    if not scripts:
        raise SystemExit("no scripts selected")

    artifact_dir.mkdir(parents=True, exist_ok=True)
    maybe_chown(artifact_dir)
    duration_seconds = args.smoke_duration if args.smoke else args.duration

    host = {
        "kernel": platform.platform(),
        "uname": " ".join(platform.uname()),
        "hostname": platform.node(),
        "cwd": str(ROOT_DIR),
    }

    libbpf = LibbpfHandle()
    libbpf.enable_stats()

    records: list[dict[str, Any]] = []
    try:
        for spec in scripts:
            artifact = None
            live = None
            if not args.skip_artifact:
                try:
                    artifact = emit_bpftrace_artifact(spec, runner, artifact_dir)
                except Exception as exc:
                    artifact = artifact_failure(spec, artifact_dir, str(exc))
            if not args.skip_live:
                try:
                    live = live_benchmark_with_process_tail(
                        spec,
                        libbpf,
                        scanner,
                        duration_seconds=duration_seconds,
                        attach_timeout=args.attach_timeout,
                        keep_temporary=args.keep_temporary,
                    )
                except Exception as exc:
                    live = live_failure(str(exc))
            summary = summarize_script_result(spec, artifact, live)
            records.append(
                {
                    "name": spec.name,
                    "description": spec.description,
                    "script": spec.program_text,
                    "artifact": artifact,
                    "live": live,
                    "summary": summary,
                }
            )
    finally:
        libbpf.close()

    site_totals = {
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
        "total_sites": 0,
    }
    speedups: list[float] = []
    emit_successes = 0
    artifact_load_successes = 0
    live_successes = 0
    live_recompile_successes = 0
    for record in records:
        artifact = record.get("artifact") or {}
        live = record.get("live") or {}
        if ((artifact.get("emit") or {}).get("ok")):
            emit_successes += 1
        load_probe = artifact.get("load_probe") or {}
        if int(load_probe.get("successes", 0) or 0) > 0:
            artifact_load_successes += 1
        if live.get("ok"):
            live_successes += 1
        if int(((live.get("recompile") or {}).get("applied_programs", 0) or 0) > 0):
            live_recompile_successes += 1
        counts = (live.get("site_totals") or {}) if live.get("ok") else ((artifact.get("raw_scan") or {}) if artifact else {})
        for field in site_totals:
            site_totals[field] += int(counts.get(field, 0) or 0)
        speedup = record["summary"].get("speedup")
        if isinstance(speedup, (float, int)) and speedup > 0:
            speedups.append(float(speedup))

    summary = {
        "scripts_run": len(records),
        "emit_successes": emit_successes,
        "artifact_load_successes": artifact_load_successes,
        "live_successes": live_successes,
        "live_recompile_successes": live_recompile_successes,
        "site_totals": site_totals,
        "speedup_geomean": geomean(speedups),
    }

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "host": host,
        "tool_versions": tool_versions,
        "runner": str(runner),
        "scanner": str(scanner),
        "artifact_dir": str(artifact_dir),
        "settings": {
            "duration_seconds": duration_seconds,
            "attach_timeout_seconds": args.attach_timeout,
            "smoke": args.smoke,
            "skip_live": args.skip_live,
            "skip_artifact": args.skip_artifact,
            "selected_scripts": [spec.name for spec in scripts],
        },
        "records": records,
        "summary": summary,
    }

    ensure_parent(output_json)
    ensure_parent(output_md)
    output_json.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n")
    output_md.write_text(build_markdown_report(payload) + "\n")
    maybe_chown(output_json)
    maybe_chown(output_md)
    maybe_chown(artifact_dir)

    print(f"[ok] wrote {output_json}")
    print(f"[ok] wrote {output_md}")


if __name__ == "__main__":
    main()
