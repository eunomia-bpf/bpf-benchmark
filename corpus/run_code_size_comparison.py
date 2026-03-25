#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import platform
import statistics
import subprocess
import sys
import time
from collections import Counter, defaultdict
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

ROOT_DIR = Path(__file__).resolve().parent.parent
if str(ROOT_DIR) not in sys.path:
    sys.path.insert(0, str(ROOT_DIR))

from runner.libs.corpus import ensure_parent, summarize_text  # noqa: E402

DEFAULT_OUTPUT_JSON = ROOT_DIR / "docs" / "tmp" / "code-size-by-progtype.json"
DEFAULT_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "code-size-by-progtype.md"
DEFAULT_RUNNER = ROOT_DIR / "runner" / "build" / "micro_exec"
DEFAULT_PACKET_PATH = ROOT_DIR / "micro" / "generated-inputs" / "corpus_dummy_packet_64.bin"
DEFAULT_CONTEXT_PATH = ROOT_DIR / "micro" / "generated-inputs" / "corpus_dummy_context_64.bin"
DEFAULT_TIMEOUT_SECONDS = 180
DEFAULT_REFERENCE_INVENTORY = ROOT_DIR / "docs" / "tmp" / "corpus-runnability-results.json"
DEFAULT_VM_KERNEL_IMAGE = ROOT_DIR / "vendor" / "linux-framework" / "arch" / "x86" / "boot" / "bzImage"
DEFAULT_OBJECT_ROOT_CANDIDATES = (
    ROOT_DIR / "corpus" / "expanded_corpus",
    ROOT_DIR / "corpus" / "objects",
    ROOT_DIR / "corpus" / "build",
)
DEFAULT_BTF_CANDIDATES = (
    Path("/sys/kernel/btf/vmlinux"),
    ROOT_DIR / "vendor" / "linux-framework" / "vmlinux",
    ROOT_DIR / "vendor" / "linux" / "vmlinux",
)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Measure stock-vs-REJIT code size for every loadable corpus program, "
            "grouped by program type."
        )
    )
    parser.add_argument(
        "--output-json",
        default=str(DEFAULT_OUTPUT_JSON),
        help="Path for structured JSON output.",
    )
    parser.add_argument(
        "--output-md",
        default=str(DEFAULT_OUTPUT_MD),
        help="Path for markdown summary output.",
    )
    parser.add_argument(
        "--runner",
        default=str(DEFAULT_RUNNER),
        help="Path to micro_exec.",
    )
    parser.add_argument(
        "--object-root",
        action="append",
        dest="object_roots",
        help=(
            "Object root to scan recursively for .bpf.o files. "
            "Repeatable. Defaults to corpus/expanded_corpus, corpus/objects, and corpus/build."
        ),
    )
    parser.add_argument(
        "--btf-custom-path",
        default=None,
        help="Optional preferred BTF path for run-kernel. The harness still falls back on BTF-looking failures.",
    )
    parser.add_argument(
        "--timeout",
        type=int,
        default=DEFAULT_TIMEOUT_SECONDS,
        help="Per-invocation timeout in seconds.",
    )
    parser.add_argument(
        "--filter",
        action="append",
        dest="filters",
        help="Only include objects or program names containing this substring. Repeatable.",
    )
    parser.add_argument(
        "--max-objects",
        type=int,
        help="Optional cap for object-level smoke testing.",
    )
    parser.add_argument(
        "--max-programs",
        type=int,
        help="Optional cap for program-level smoke testing.",
    )
    parser.add_argument(
        "--reference-inventory",
        default=str(DEFAULT_REFERENCE_INVENTORY),
        help="Optional runnability JSON used only for report context.",
    )
    parser.add_argument(
        "--vm-kernel-image",
        default=str(DEFAULT_VM_KERNEL_IMAGE),
        help="Kernel image path used in the VM rerun command note.",
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Only perform baseline compile-only loadability inventory; skip REJIT measurements.",
    )
    return parser.parse_args(argv)



def relpath(path: Path | str) -> str:
    candidate = Path(path)
    try:
        return candidate.resolve().relative_to(ROOT_DIR).as_posix()
    except Exception:
        try:
            return candidate.relative_to(ROOT_DIR).as_posix()
        except Exception:
            return str(candidate)



def summarize_error(value: str | None) -> str:
    if not value:
        return "unknown error"
    first_line = value.splitlines()[0].strip()
    if len(value.splitlines()) > 1:
        return first_line + " ..."
    return first_line


def parse_last_json_line(stdout: str, *, label: str) -> Any:
    lines = [line.strip() for line in stdout.splitlines() if line.strip()]
    if not lines:
        raise RuntimeError(f"{label} produced no JSON output")
    return json.loads(lines[-1])


def run_text_command(
    command: list[str],
    *,
    timeout_seconds: int,
    cwd: Path | None = None,
) -> dict[str, Any]:
    start = time.monotonic()
    try:
        completed = subprocess.run(
            command,
            cwd=cwd or ROOT_DIR,
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
        )
    except subprocess.TimeoutExpired as exc:
        return {
            "ok": False,
            "command": command,
            "returncode": None,
            "timed_out": True,
            "duration_seconds": time.monotonic() - start,
            "stdout": exc.stdout or "",
            "stderr": exc.stderr or "",
            "error": f"timeout after {timeout_seconds}s",
        }
    except OSError as exc:
        return {
            "ok": False,
            "command": command,
            "returncode": None,
            "timed_out": False,
            "duration_seconds": time.monotonic() - start,
            "stdout": "",
            "stderr": "",
            "error": f"exec failed: {exc}",
        }

    stdout = completed.stdout or ""
    stderr = completed.stderr or ""
    if completed.returncode == 0:
        return {
            "ok": True,
            "command": command,
            "returncode": completed.returncode,
            "timed_out": False,
            "duration_seconds": time.monotonic() - start,
            "stdout": stdout,
            "stderr": stderr,
            "error": None,
        }

    error_lines = [line.strip() for line in (stderr or stdout).splitlines() if line.strip()]
    error = error_lines[-1] if error_lines else f"command failed (exit={completed.returncode})"
    return {
        "ok": False,
        "command": command,
        "returncode": completed.returncode,
        "timed_out": False,
        "duration_seconds": time.monotonic() - start,
        "stdout": stdout,
        "stderr": stderr,
        "error": error,
    }


def run_runner_command(command: list[str], *, timeout_seconds: int) -> dict[str, Any]:
    result = run_text_command(command, timeout_seconds=timeout_seconds, cwd=ROOT_DIR)
    sample = None
    if result["ok"]:
        try:
            sample = parse_last_json_line(result["stdout"], label="runner")
        except Exception as exc:  # pragma: no cover - runtime parse guard
            result["ok"] = False
            result["error"] = str(exc)
    result["sample"] = sample
    return result


def likely_btf_issue(result: dict[str, Any]) -> bool:
    haystack = "\n".join([result.get("stdout", ""), result.get("stderr", "")]).lower()
    needles = (
        "co-re",
        "core reloc",
        "btf",
        "target btf",
        "perform core relocations",
    )
    return any(needle in haystack for needle in needles)


def canonical_section_root(section_name: str) -> str:
    raw_root = section_name.split("/", 1)[0] if section_name else ""
    alias_map = {
        "fentry.s": "fentry",
        "fexit.s": "fexit",
        "fmod_ret.s": "fmod_ret",
        "iter.s": "iter",
        "lsm.s": "lsm",
        "raw_tracepoint.w": "raw_tracepoint",
        "struct_ops.s": "struct_ops",
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
    if raw_root.startswith("uprobe"):
        return "uprobe"
    if raw_root.startswith("uretprobe"):
        return "uretprobe"
    if raw_root.startswith("usdt"):
        return "usdt"
    if raw_root.startswith("xdp"):
        return "xdp"
    if raw_root == "tcx" or raw_root.startswith("tc_") or raw_root.startswith("tcx") or raw_root.startswith("tc_packet_hook"):
        return "tc"
    return raw_root


def fallback_prog_type_name(section_name: str) -> str:
    root = canonical_section_root(section_name)
    if root == "xdp":
        return "xdp"
    if root == "tc":
        return "sched_cls"
    if root == "cgroup_skb":
        return "cgroup_skb"
    if root == "socket":
        return "socket_filter"
    if root in {"sk_skb", "sk_msg", "flow_dissector", "perf_event", "netfilter", "sk_lookup", "sockops"}:
        return {"sockops": "sock_ops"}.get(root, root)
    if root in {"kprobe", "kretprobe", "uprobe", "uretprobe", "usdt", "ksyscall", "kretsyscall"}:
        return "kprobe"
    if root in {"tracepoint", "tp"}:
        return "tracepoint"
    if root in {"raw_tp", "raw_tracepoint"}:
        return "raw_tracepoint"
    if root in {"fentry", "fexit", "fmod_ret", "lsm", "iter", "freplace"}:
        return "tracing"
    return "unknown"


def grouped_prog_type(section_name: str, prog_type_name: str) -> str:
    root = canonical_section_root(section_name)
    root_overrides = {
        "tc": "sched_cls",
        "tp": "tracepoint",
        "tracepoint": "tracepoint",
        "raw_tp": "raw_tracepoint",
        "raw_tracepoint": "raw_tracepoint",
        "fentry": "fentry",
        "fexit": "fexit",
        "fmod_ret": "fmod_ret",
        "lsm": "lsm",
        "iter": "iter",
        "struct_ops": "struct_ops",
        "kprobe": "kprobe",
        "kretprobe": "kretprobe",
        "ksyscall": "kprobe",
        "kretsyscall": "kretprobe",
        "uprobe": "uprobe",
        "uretprobe": "uretprobe",
        "usdt": "usdt",
        "xdp": "xdp",
    }
    if root in root_overrides:
        return root_overrides[root]
    if prog_type_name and prog_type_name not in {"tracing", "unknown"}:
        return prog_type_name
    fallback = fallback_prog_type_name(section_name)
    if fallback != "unknown":
        return fallback
    return root or "unknown"


def source_name_for_path(path: Path, object_root: Path) -> str:
    try:
        parts = path.resolve().relative_to(object_root.resolve()).parts
    except Exception:
        parts = ()
    return parts[0] if parts else "unknown"


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


def materialize_dummy_context(path: Path, *, size: int = 64) -> Path:
    ensure_parent(path)
    if path.exists() and path.stat().st_size == size:
        return path
    path.write_bytes(bytes(size))
    return path


def execution_plan(section_name: str, packet_path: Path, context_path: Path) -> dict[str, Any]:
    root = canonical_section_root(section_name)
    if root in {"xdp", "socket", "classifier", "tc", "flow_dissector", "sk_skb", "sk_msg"}:
        return {
            "io_mode": "packet",
            "memory_path": packet_path,
            "input_size": 64,
        }
    if root in {"raw_tracepoint", "raw_tp"}:
        return {
            "io_mode": "context",
            "memory_path": context_path,
            "input_size": 64,
        }
    return {
        "io_mode": "context",
        "memory_path": None,
        "input_size": 0,
    }


def default_object_roots(requested: list[str] | None) -> tuple[list[Path], list[Path], list[Path]]:
    if requested:
        resolved = [Path(item).resolve() for item in requested]
        used = [path for path in resolved if path.exists()]
        missing = [path for path in resolved if not path.exists()]
        return resolved, used, missing

    requested_paths = [path.resolve() for path in DEFAULT_OBJECT_ROOT_CANDIDATES]
    used_paths = [path for path in requested_paths if path.exists()]
    missing_paths = [path for path in requested_paths if not path.exists()]
    return requested_paths, used_paths, missing_paths


def collect_object_paths(
    object_roots: list[Path],
    *,
    filters: list[str] | None,
    max_objects: int | None,
) -> list[tuple[Path, Path]]:
    lowered = [item.lower() for item in filters or []]
    seen: set[Path] = set()
    discovered: list[tuple[Path, Path]] = []
    for root in object_roots:
        for path in sorted(root.rglob("*.bpf.o")):
            resolved = path.resolve()
            if resolved in seen:
                continue
            rel = relpath(resolved).lower()
            if lowered and not any(needle in rel for needle in lowered):
                continue
            seen.add(resolved)
            discovered.append((root.resolve(), resolved))
    discovered.sort(key=lambda item: relpath(item[1]))
    if max_objects is not None:
        discovered = discovered[:max_objects]
    return discovered


def build_runner_command(
    *,
    runner: Path,
    object_path: Path,
    program_name: str,
    io_mode: str,
    memory_path: Path | None,
    input_size: int,
    btf_custom_path: Path | None,
    compile_only: bool,
) -> list[str]:
    command = [
        str(runner),
        "run-kernel",
        "--program",
        str(object_path),
        "--program-name",
        program_name,
        "--io-mode",
        io_mode,
        "--repeat",
        "1",
    ]
    if io_mode == "packet":
        command.append("--raw-packet")
    if memory_path is not None:
        command.extend(["--memory", str(memory_path)])
    if input_size > 0:
        command.extend(["--input-size", str(input_size)])
    if btf_custom_path is not None:
        command.extend(["--btf-custom-path", str(btf_custom_path)])
    if compile_only:
        command.append("--compile-only")
    return command


def run_with_btf_fallback(
    *,
    runner: Path,
    object_path: Path,
    program_name: str,
    io_mode: str,
    memory_path: Path | None,
    input_size: int,
    compile_only: bool,
    timeout_seconds: int,
    preferred_btf_path: Path | None,
) -> dict[str, Any]:
    candidate_paths: list[Path | None] = []
    if preferred_btf_path is not None:
        candidate_paths.append(preferred_btf_path)
    for candidate in DEFAULT_BTF_CANDIDATES:
        if candidate.exists() and candidate not in candidate_paths:
            candidate_paths.append(candidate)
    if not candidate_paths:
        candidate_paths.append(None)

    attempts: list[dict[str, Any]] = []
    last_result: dict[str, Any] | None = None
    for index, btf_path in enumerate(candidate_paths):
        result = run_runner_command(
            build_runner_command(
                runner=runner,
                object_path=object_path,
                program_name=program_name,
                io_mode=io_mode,
                memory_path=memory_path,
                input_size=input_size,
                btf_custom_path=btf_path,
                compile_only=compile_only,
            ),
            timeout_seconds=timeout_seconds,
        )
        attempts.append(
            {
                "btf_path": str(btf_path) if btf_path is not None else None,
                "ok": result["ok"],
                "error": result["error"],
            }
        )
        result["btf_path_used"] = str(btf_path) if btf_path is not None else None
        result["btf_attempts"] = attempts
        last_result = result
        if result["ok"]:
            return result
        if index + 1 >= len(candidate_paths):
            break
        if not likely_btf_issue(result):
            break

    assert last_result is not None
    return last_result


def invocation_summary(result: dict[str, Any] | None) -> dict[str, Any] | None:
    if result is None:
        return None
    sample = result.get("sample") or {}
    sample_summary = None
    if sample:
        sample_summary = {
            "compile_ns": sample.get("compile_ns"),
            "jited_prog_len": sample.get("jited_prog_len"),
            "xlated_prog_len": sample.get("xlated_prog_len"),
            "code_size": sample.get("code_size") or {},
            "rejit": sample.get("rejit") or {},
        }
    return {
        "ok": result["ok"],
        "returncode": result["returncode"],
        "timed_out": result["timed_out"],
        "duration_seconds": result["duration_seconds"],
        "error": result["error"],
        "stderr_tail": summarize_text(result["stderr"]),
        "sample": sample_summary,
        "btf_path_used": result.get("btf_path_used"),
        "btf_attempts": result.get("btf_attempts", []),
    }


def discover_programs(runner: Path, object_path: Path, timeout_seconds: int) -> dict[str, Any]:
    result = run_text_command(
        [str(runner), "list-programs", "--program", str(object_path)],
        timeout_seconds=timeout_seconds,
        cwd=ROOT_DIR,
    )
    programs: list[dict[str, Any]] = []
    if result["ok"]:
        try:
            payload = parse_last_json_line(result["stdout"], label="list-programs")
            if not isinstance(payload, list):
                raise RuntimeError("list-programs output was not a JSON array")
            for item in payload:
                if not isinstance(item, dict):
                    continue
                section_name = str(item.get("section_name") or "")
                prog_type_name = str(item.get("prog_type_name") or "")
                programs.append(
                    {
                        "name": str(item.get("name") or ""),
                        "section_name": section_name,
                        "insn_count": int(item.get("insn_count", 0) or 0),
                        "prog_type_name": prog_type_name,
                        "attach_type_name": str(item.get("attach_type_name") or ""),
                        "grouped_prog_type": grouped_prog_type(section_name, prog_type_name),
                    }
                )
        except Exception as exc:  # pragma: no cover - runtime parse guard
            result["ok"] = False
            result["error"] = str(exc)

    return {
        "ok": result["ok"],
        "duration_seconds": result["duration_seconds"],
        "error": result["error"],
        "stderr_tail": summarize_text(result["stderr"]),
        "programs": programs,
    }


def stock_jitted_len(record: dict[str, Any]) -> int | None:
    sample = ((record.get("stock_compile") or {}).get("sample") or {})
    return sample.get("jited_prog_len")


def rejit_compile_result(record: dict[str, Any]) -> dict[str, Any] | None:
    return record.get("rejit_compile")


def rejit_jitted_len(record: dict[str, Any]) -> int | None:
    sample = ((rejit_compile_result(record) or {}).get("sample") or {})
    return sample.get("jited_prog_len")


def rejit_meta(record: dict[str, Any]) -> dict[str, Any]:
    return (((rejit_compile_result(record) or {}).get("sample") or {}).get("rejit") or {})


def is_loadable(record: dict[str, Any]) -> bool:
    return bool((record.get("stock_compile") or {}).get("ok"))


def has_rejit_error(record: dict[str, Any]) -> bool:
    if not (rejit_compile_result(record) or {}).get("ok"):
        return True
    return bool(rejit_meta(record).get("error"))


def compile_pair_ok(record: dict[str, Any]) -> bool:
    if not is_loadable(record):
        return False
    if not (rejit_compile_result(record) or {}).get("ok"):
        return False
    if has_rejit_error(record):
        return False
    stock_len = stock_jitted_len(record)
    rejit_len = rejit_jitted_len(record)
    return bool(stock_len and rejit_len)


def ratio_rejit_over_stock(record: dict[str, Any]) -> float | None:
    if not compile_pair_ok(record):
        return None
    stock_len = stock_jitted_len(record)
    rejit_len = rejit_jitted_len(record)
    if not stock_len or not rejit_len:
        return None
    return float(rejit_len) / float(stock_len)


def delta_bytes(record: dict[str, Any]) -> int | None:
    ratio_ok = compile_pair_ok(record)
    if not ratio_ok:
        return None
    stock_len = stock_jitted_len(record)
    rejit_len = rejit_jitted_len(record)
    if stock_len is None or rejit_len is None:
        return None
    return int(rejit_len) - int(stock_len)


def delta_pct(record: dict[str, Any]) -> float | None:
    if not compile_pair_ok(record):
        return None
    stock_len = stock_jitted_len(record)
    rejit_len = rejit_jitted_len(record)
    if stock_len in (None, 0) or rejit_len is None:
        return None
    return (float(rejit_len) - float(stock_len)) * 100.0 / float(stock_len)


def measurement_status(record: dict[str, Any], *, dry_run: bool) -> str:
    if not is_loadable(record):
        return "load_failed"
    if dry_run:
        return "loadable_inventory"
    if not (rejit_compile_result(record) or {}).get("ok"):
        return "rejit_load_failed"
    meta = rejit_meta(record)
    if meta.get("error"):
        return "rejit_failed"
    if int(meta.get("total_sites", 0) or 0) == 0:
        return "no_sites"
    if meta.get("applied"):
        return "applied"
    return "not_applied"


def geomean(values: list[float]) -> float | None:
    positive = [value for value in values if value > 0.0]
    if not positive:
        return None
    return math.exp(statistics.mean(math.log(value) for value in positive))


def format_ratio(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.3f}x"


def format_pct(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:+.1f}%"


def markdown_table(headers: list[str], rows: list[list[Any]]) -> list[str]:
    lines = [
        "| " + " | ".join(headers) + " |",
        "| " + " | ".join("---" for _ in headers) + " |",
    ]
    for row in rows:
        lines.append("| " + " | ".join(str(cell) for cell in row) + " |")
    return lines


def load_reference_inventory(path: Path) -> dict[str, Any] | None:
    if not path.exists():
        return None
    try:
        payload = json.loads(path.read_text())
    except Exception:  # pragma: no cover - best effort context only
        return None
    summary = payload.get("summary")
    if not isinstance(summary, dict):
        return None
    return {
        "path": str(path),
        "programs_found": summary.get("programs_found"),
        "loadable_programs": summary.get("loadable_programs"),
        "packet_runnable_programs": summary.get("packet_runnable_programs"),
        "true_runnable_programs": summary.get("true_runnable_programs"),
    }


def detect_support_status(programs: list[dict[str, Any]], *, dry_run: bool) -> str:
    if dry_run:
        return "not_attempted"
    site_positive = [
        record
        for record in programs
        if is_loadable(record) and int(rejit_meta(record).get("total_sites", 0) or 0) > 0
    ]
    if any(bool(rejit_meta(record).get("applied")) for record in site_positive):
        return "supported"
    if site_positive and all(bool(rejit_meta(record).get("error")) for record in site_positive):
        return "unavailable"
    if any((rejit_compile_result(record) or {}).get("ok") for record in programs):
        return "unknown"
    return "not_attempted"


def per_prog_type_summary(
    programs: list[dict[str, Any]],
    *,
    dry_run: bool,
    ratios_enabled: bool,
) -> list[dict[str, Any]]:
    grouped: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for record in programs:
        grouped[record["grouped_prog_type"]].append(record)

    rows: list[dict[str, Any]] = []
    for prog_type, prog_records in grouped.items():
        ratios = [ratio_rejit_over_stock(item) for item in prog_records]
        deltas = [delta_pct(item) for item in prog_records]
        row = {
            "prog_type": prog_type,
            "programs_discovered": len(prog_records),
            "loadable_programs": sum(1 for item in prog_records if is_loadable(item)),
            "compile_pairs": sum(1 for item in prog_records if compile_pair_ok(item)),
            "site_positive_programs": sum(
                1 for item in prog_records if int(rejit_meta(item).get("total_sites", 0) or 0) > 0
            ),
            "rejit_applied_programs": sum(
                1 for item in prog_records if bool(rejit_meta(item).get("applied"))
            ),
            "rejit_failed_programs": sum(
                1 for item in prog_records
                if measurement_status(item, dry_run=dry_run) in {"rejit_failed", "rejit_load_failed", "not_applied"}
            ),
            "ratio_geomean": geomean([value for value in ratios if value is not None]) if ratios_enabled else None,
            "delta_pct_median": statistics.median([value for value in deltas if value is not None])
            if ratios_enabled and any(value is not None for value in deltas)
            else None,
        }
        rows.append(row)

    rows.sort(key=lambda item: (-item["loadable_programs"], -item["programs_discovered"], item["prog_type"]))
    return rows


def build_summary(
    *,
    objects: list[dict[str, Any]],
    programs: list[dict[str, Any]],
    dry_run: bool,
    support_status: str,
) -> dict[str, Any]:
    ratios_enabled = support_status == "supported" and not dry_run
    program_ratios = [ratio_rejit_over_stock(record) for record in programs] if ratios_enabled else []
    program_deltas = [delta_pct(record) for record in programs] if ratios_enabled else []

    object_discovery_failures = Counter()
    load_failures = Counter()
    rejit_failures = Counter()
    for record in objects:
        if not record["discovery"]["ok"]:
            object_discovery_failures[summarize_error(record["discovery"]["error"])] += 1
    for record in programs:
        if not is_loadable(record):
            load_failures[summarize_error((record.get("stock_compile") or {}).get("error"))] += 1
            continue
        if dry_run:
            continue
        status = measurement_status(record, dry_run=dry_run)
        if status == "rejit_load_failed":
            rejit_failures[summarize_error((rejit_compile_result(record) or {}).get("error"))] += 1
        elif status in {"rejit_failed", "not_applied"}:
            rejit_failures[summarize_error(rejit_meta(record).get("error"))] += 1

    return {
        "objects_scanned": len(objects),
        "objects_discovered": sum(1 for item in objects if item["discovery"]["ok"]),
        "objects_with_discovery_failures": sum(1 for item in objects if not item["discovery"]["ok"]),
        "programs_discovered": len(programs),
        "loadable_programs": sum(1 for item in programs if is_loadable(item)),
        "compile_pairs": sum(1 for item in programs if compile_pair_ok(item)),
        "site_positive_programs": sum(
            1 for item in programs if int(rejit_meta(item).get("total_sites", 0) or 0) > 0
        ),
        "rejit_applied_programs": sum(
            1 for item in programs if bool(rejit_meta(item).get("applied"))
        ),
        "rejit_failed_programs": sum(
            1 for item in programs
            if measurement_status(item, dry_run=dry_run) in {"rejit_failed", "rejit_load_failed", "not_applied"}
        ),
        "overall_ratio_geomean": geomean([value for value in program_ratios if value is not None]) if ratios_enabled else None,
        "overall_delta_pct_median": statistics.median([value for value in program_deltas if value is not None])
        if ratios_enabled and any(value is not None for value in program_deltas)
        else None,
        "support_status": support_status,
        "object_discovery_failure_reasons": dict(object_discovery_failures.most_common(16)),
        "load_failure_reasons": dict(load_failures.most_common(16)),
        "rejit_failure_reasons": dict(rejit_failures.most_common(16)),
    }


def top_ratio_rows(programs: list[dict[str, Any]], *, reverse: bool, limit: int = 15) -> list[dict[str, Any]]:
    rows = [
        {
            "program": f"{record['object_path']}:{record['program_name']}",
            "prog_type": record["grouped_prog_type"],
            "stock_jited_len": stock_jitted_len(record),
            "rejit_jited_len": rejit_jitted_len(record),
            "ratio_rejit_over_stock": ratio_rejit_over_stock(record),
            "delta_pct": delta_pct(record),
            "rejit_applied": bool(rejit_meta(record).get("applied")),
            "site_count": int(rejit_meta(record).get("total_sites", 0) or 0),
        }
        for record in programs
        if compile_pair_ok(record) and ratio_rejit_over_stock(record) is not None
    ]
    rows.sort(
        key=lambda item: (
            item["ratio_rejit_over_stock"],
            item["program"],
        ),
        reverse=reverse,
    )
    return rows[:limit]


def build_markdown(payload: dict[str, Any]) -> str:
    summary = payload["summary"]
    ratios_enabled = summary["support_status"] == "supported" and not payload["dry_run"]
    vm_command = payload["vm_command"]
    type_rows = payload["by_prog_type"]

    lines = [
        "# Code Size by Program Type",
        "",
        f"- Generated: {payload['generated_at']}",
        f"- Mode: `{'dry-run inventory' if payload['dry_run'] else 'actual measurement attempt'}`",
        f"- Kernel release: `{payload['host']['kernel_release']}`",
        f"- Host: `{payload['host']['hostname']}`",
        f"- Runner: `{payload['runner_binary']}`",
        "- Object roots requested: " + ", ".join(f"`{item}`" for item in payload["object_roots"]["requested"]),
        "- Object roots used: " + ", ".join(f"`{item}`" for item in payload["object_roots"]["used"]),
    ]
    if payload["object_roots"]["missing"]:
        lines.append(
            "- Missing object roots skipped: "
            + ", ".join(f"`{item}`" for item in payload["object_roots"]["missing"])
        )
    if payload.get("reference_inventory"):
        ref = payload["reference_inventory"]
        lines.append(
            f"- Reference runnability inventory: `{relpath(ref['path'])}` "
            f"(programs_found={ref.get('programs_found')}, loadable_programs={ref.get('loadable_programs')})"
        )
    lines.extend(
        [
            f"- REJIT support status: `{summary['support_status']}`",
            "",
            "## Summary",
            "",
        ]
    )
    summary_rows: list[list[Any]] = [
        ["Objects scanned", summary["objects_scanned"]],
        ["Objects with successful program discovery", summary["objects_discovered"]],
        ["Objects with discovery failures", summary["objects_with_discovery_failures"]],
        ["Programs discovered", summary["programs_discovered"]],
        ["Loadable programs", summary["loadable_programs"]],
        ["Compile pairs with usable stock/REJIT code size", summary["compile_pairs"]],
    ]
    if not payload["dry_run"]:
        summary_rows.extend(
            [
                ["Programs with REJIT-detected sites", summary["site_positive_programs"]],
                ["Programs with REJIT applied", summary["rejit_applied_programs"]],
                ["Programs with REJIT failures", summary["rejit_failed_programs"]],
                ["Overall geomean code-size ratio (rejit/stock)", format_ratio(summary["overall_ratio_geomean"])],
                ["Overall median code-size delta", format_pct(summary["overall_delta_pct_median"])],
            ]
        )
    lines.extend(markdown_table(["Metric", "Value"], summary_rows))

    lines.extend(["", "## By Program Type", ""])
    type_table_rows: list[list[Any]] = []
    for row in type_rows:
        type_table_rows.append(
            [
                row["prog_type"],
                row["programs_discovered"],
                row["loadable_programs"],
                row["compile_pairs"],
                row["site_positive_programs"],
                row["rejit_applied_programs"],
                row["rejit_failed_programs"],
                format_ratio(row["ratio_geomean"]) if ratios_enabled else "n/a",
                format_pct(row["delta_pct_median"]) if ratios_enabled else "n/a",
            ]
        )
    lines.extend(
        markdown_table(
            [
                "Prog Type",
                "Programs",
                "Loadable",
                "Compile Pairs",
                "Site+",
                "Applied",
                "REJIT Failures",
                "Geomean R/S",
                "Median Delta",
            ],
            type_table_rows,
        )
    )

    if ratios_enabled and payload["top_shrinks"]:
        lines.extend(["", "## Largest Shrinks", ""])
        lines.extend(
            markdown_table(
                ["Program", "Prog Type", "Stock JIT", "REJIT JIT", "R/S", "Delta", "Applied", "Sites"],
                [
                    [
                        row["program"],
                        row["prog_type"],
                        row["stock_jited_len"],
                        row["rejit_jited_len"],
                        format_ratio(row["ratio_rejit_over_stock"]),
                        format_pct(row["delta_pct"]),
                        "yes" if row["rejit_applied"] else "no",
                        row["site_count"],
                    ]
                    for row in payload["top_shrinks"]
                ],
            )
        )

    if ratios_enabled and payload["top_growths"]:
        lines.extend(["", "## Largest Growths", ""])
        lines.extend(
            markdown_table(
                ["Program", "Prog Type", "Stock JIT", "REJIT JIT", "R/S", "Delta", "Applied", "Sites"],
                [
                    [
                        row["program"],
                        row["prog_type"],
                        row["stock_jited_len"],
                        row["rejit_jited_len"],
                        format_ratio(row["ratio_rejit_over_stock"]),
                        format_pct(row["delta_pct"]),
                        "yes" if row["rejit_applied"] else "no",
                        row["site_count"],
                    ]
                    for row in payload["top_growths"]
                ],
            )
        )

    if summary["object_discovery_failure_reasons"]:
        lines.extend(["", "## Object Discovery Failures", ""])
        lines.extend(
            markdown_table(
                ["Reason", "Count"],
                [[reason, count] for reason, count in summary["object_discovery_failure_reasons"].items()],
            )
        )

    if summary["load_failure_reasons"]:
        lines.extend(["", "## Load Failures", ""])
        lines.extend(
            markdown_table(
                ["Reason", "Count"],
                [[reason, count] for reason, count in summary["load_failure_reasons"].items()],
            )
        )

    rejit_failure_reasons = summary["rejit_failure_reasons"] or {}
    if rejit_failure_reasons:
        lines.extend(["", "## REJIT Failures", ""])
        lines.extend(
            markdown_table(
                ["Reason", "Count"],
                [[reason, count] for reason, count in rejit_failure_reasons.items()],
            )
        )

    lines.extend(
        [
            "",
            "## Notes",
            "",
            "- The harness enumerates programs with `micro_exec list-programs`, then runs `run-kernel --compile-only` to measure stock kernel JIT compilation time.",
            "- Program-type grouping refines generic libbpf `prog_type_name` using section roots so `fentry`, `fexit`, `lsm`, `raw_tracepoint`, and `sched_cls` remain separate buckets.",
            "- When the older `corpus/expanded_corpus` and `corpus/objects` paths are absent, the harness falls back to the current canonical `corpus/build` tree from `corpus/config/corpus_manifest.yaml`.",
        ]
    )
    if summary["support_status"] != "supported":
        lines.extend(
            [
                "- This host did not provide usable REJIT measurements, so the report should be treated as loadability inventory plus failure diagnostics.",
                f"- VM rerun command: `{vm_command}`",
            ]
        )
    else:
        lines.extend(
            [
                "- Ratios are `rejit_jited_len / stock_jited_len`; values below `1.0x` mean smaller native code after REJIT.",
                f"- Equivalent VM rerun command: `{vm_command}`",
            ]
        )
    return "\n".join(lines) + "\n"


def build_vm_command(args: argparse.Namespace) -> str:
    guest_argv = [
        "python3",
        "corpus/run_code_size_comparison.py",
        "--output-json",
        relpath(Path(args.output_json).resolve()),
        "--output-md",
        relpath(Path(args.output_md).resolve()),
    ]
    if args.timeout != DEFAULT_TIMEOUT_SECONDS:
        guest_argv.extend(["--timeout", str(args.timeout)])
    if args.max_objects is not None:
        guest_argv.extend(["--max-objects", str(args.max_objects)])
    if args.max_programs is not None:
        guest_argv.extend(["--max-programs", str(args.max_programs)])
    for root in args.object_roots or []:
        guest_argv.extend(["--object-root", root])
    for needle in args.filters or []:
        guest_argv.extend(["--filter", needle])
    if args.btf_custom_path:
        guest_argv.extend(["--btf-custom-path", args.btf_custom_path])
    rwdirs: list[str] = []
    for path in {Path(args.output_json).resolve().parent, Path(args.output_md).resolve().parent}:
        path_str = str(path)
        if path_str not in rwdirs:
            rwdirs.append(path_str)

    command = [
        "vng",
        "--run",
        relpath(Path(args.vm_kernel_image).resolve()),
        "--cwd",
        str(ROOT_DIR),
        "--disable-monitor",
        "--cpus",
        "1",
    ]
    for rwdir in rwdirs:
        command.extend(["--rwdir", rwdir])
    command.extend(
        [
            "--exec",
            "'" + " ".join(guest_argv).replace("'", "'\"'\"'") + "'",
        ]
    )
    return " ".join(command)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    runner = Path(args.runner).resolve()
    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    reference_inventory = load_reference_inventory(Path(args.reference_inventory).resolve())

    if not runner.exists():
        raise SystemExit(f"runner not found: {runner}")

    requested_roots, used_roots, missing_roots = default_object_roots(args.object_roots)
    if not used_roots:
        missing = ", ".join(str(path) for path in requested_roots)
        raise SystemExit(f"no object roots found: {missing}")

    packet_path = materialize_dummy_packet(DEFAULT_PACKET_PATH)
    context_path = materialize_dummy_context(DEFAULT_CONTEXT_PATH)
    object_entries = collect_object_paths(
        used_roots,
        filters=args.filters,
        max_objects=args.max_objects,
    )
    if not object_entries:
        raise SystemExit("no .bpf.o objects matched the selected roots/filters")

    object_records: list[dict[str, Any]] = []
    program_records: list[dict[str, Any]] = []
    stop_after_program = args.max_programs is not None and args.max_programs <= 0
    preferred_btf_path = Path(args.btf_custom_path).resolve() if args.btf_custom_path else None

    for index, (object_root, object_path) in enumerate(object_entries, start=1):
        discovery = discover_programs(runner, object_path, args.timeout)
        object_record = {
            "object_path": relpath(object_path),
            "source_name": source_name_for_path(object_path, object_root),
            "object_root": relpath(object_root),
            "discovery": discovery,
        }
        object_records.append(object_record)

        print(
            f"[{index:03}/{len(object_entries):03}] {relpath(object_path)} "
            f"programs={'?' if not discovery['ok'] else len(discovery['programs'])}"
        )
        if not discovery["ok"]:
            continue

        for program in discovery["programs"]:
            if stop_after_program:
                break

            plan = execution_plan(program["section_name"], packet_path, context_path)
            baseline_raw = run_with_btf_fallback(
                runner=runner,
                object_path=object_path,
                program_name=program["name"],
                io_mode=plan["io_mode"],
                memory_path=plan["memory_path"],
                input_size=plan["input_size"],
                compile_only=True,
                timeout_seconds=args.timeout,
                preferred_btf_path=preferred_btf_path,
            )
            stock_compile = invocation_summary(baseline_raw)
            rejit_compile = None

            record = {
                "object_path": relpath(object_path),
                "object_root": relpath(object_root),
                "source_name": source_name_for_path(object_path, object_root),
                "program_name": program["name"],
                "section_name": program["section_name"],
                "attach_type_name": program["attach_type_name"],
                "insn_count": program["insn_count"],
                "prog_type_name": program["prog_type_name"] or fallback_prog_type_name(program["section_name"]),
                "grouped_prog_type": program["grouped_prog_type"],
                "io_mode": plan["io_mode"],
                "input_size": plan["input_size"],
                "stock_compile": stock_compile,
                "rejit_compile": rejit_compile,
            }
            record["measurement_status"] = measurement_status(record, dry_run=args.dry_run)
            record["stock_jited_len"] = stock_jitted_len(record)
            record["rejit_jited_len"] = rejit_jitted_len(record)
            record["ratio_rejit_over_stock"] = ratio_rejit_over_stock(record)
            record["delta_bytes"] = delta_bytes(record)
            record["delta_pct"] = delta_pct(record)
            program_records.append(record)

            print(
                "  "
                f"{program['grouped_prog_type']:<16} {program['name']:<32} "
                f"status={record['measurement_status']}"
            )
            if args.max_programs is not None and len(program_records) >= args.max_programs:
                stop_after_program = True
                break

        if stop_after_program:
            break

    support_status = detect_support_status(program_records, dry_run=args.dry_run)
    by_prog_type = per_prog_type_summary(
        program_records,
        dry_run=args.dry_run,
        ratios_enabled=support_status == "supported" and not args.dry_run,
    )
    summary = build_summary(
        objects=object_records,
        programs=program_records,
        dry_run=args.dry_run,
        support_status=support_status,
    )
    payload = {
        "dataset": "corpus_code_size_by_prog_type",
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "mode": "dry_run_inventory" if args.dry_run else "actual_measurement_attempt",
        "dry_run": args.dry_run,
        "repo_root": str(ROOT_DIR),
        "runner_binary": str(runner),
        "object_roots": {
            "requested": [relpath(path) for path in requested_roots],
            "used": [relpath(path) for path in used_roots],
            "missing": [relpath(path) for path in missing_roots],
        },
        "reference_inventory": reference_inventory,
        "host": {
            "hostname": platform.node(),
            "platform": platform.platform(),
            "kernel_release": platform.release(),
            "python": platform.python_version(),
        },
        "filters": {
            "substrings": list(args.filters or []),
            "max_objects": args.max_objects,
            "max_programs": args.max_programs,
            "timeout_seconds": args.timeout,
        },
        "summary": summary,
        "by_prog_type": by_prog_type,
        "objects": object_records,
        "programs": program_records,
        "top_shrinks": top_ratio_rows(program_records, reverse=False),
        "top_growths": top_ratio_rows(program_records, reverse=True),
        "vm_command": build_vm_command(args),
    }

    ensure_parent(output_json)
    ensure_parent(output_md)
    output_json.write_text(json.dumps(payload, indent=2))
    output_md.write_text(build_markdown(payload))

    print(f"[done] wrote {output_json}")
    print(f"[done] wrote {output_md}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
