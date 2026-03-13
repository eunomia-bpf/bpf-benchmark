from __future__ import annotations

import json
import os
import subprocess
import time
from pathlib import Path
from typing import Any, Mapping

from .commands import build_runner_command
from .results import normalize_directive_scan, parse_json_lines, parse_runner_sample


def relpath(path: Path | str, root_dir: Path) -> str:
    candidate = Path(path)
    try:
        return candidate.relative_to(root_dir).as_posix()
    except ValueError:
        return str(candidate)


def ensure_parent(path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)


def _ipv4_checksum(header: bytes | bytearray) -> int:
    """Compute RFC 791 one's complement checksum over a 20-byte IPv4 header."""
    s = 0
    for i in range(0, len(header), 2):
        s += (header[i] << 8) + header[i + 1]
    while s >> 16:
        s = (s & 0xFFFF) + (s >> 16)
    return ~s & 0xFFFF


# Expected content of the canonical corpus dummy packet (version tag at bytes 0-5 of MAC dst).
# Bumping this sentinel forces regeneration when the packet layout is updated.
_CORPUS_PACKET_MAGIC = bytes.fromhex("ffffffffffff")  # broadcast dst MAC as version sentinel


def _build_corpus_packet() -> bytearray:
    """
    Build a 64-byte canonical Ethernet/IPv4/TCP packet for corpus measurements.

    Layout:
      Ethernet (14B): dst=ff:ff:ff:ff:ff:ff, src=00:11:22:33:44:55, EtherType=0x0800
      IPv4 (20B):     version=4, IHL=5, tot_len=50, proto=TCP(6),
                      src=10.0.0.1, dst=10.0.0.2, correct checksum
      TCP (20B):      src_port=12345, dst_port=80, seq=1, flags=SYN, data_offset=5
      Payload (10B):  0x41 ('A') * 10
    """
    packet = bytearray(64)

    # Ethernet header
    packet[0:6] = bytes.fromhex("ffffffffffff")   # dst MAC (broadcast)
    packet[6:12] = bytes.fromhex("001122334455")  # src MAC
    packet[12:14] = bytes.fromhex("0800")          # EtherType = IPv4

    # IPv4 header (checksum field zeroed first, then filled)
    packet[14] = 0x45        # version=4, IHL=5
    packet[15] = 0x00        # DSCP/ECN
    packet[16:18] = (50).to_bytes(2, "big")       # total length (20 IP + 20 TCP + 10 data)
    packet[18:20] = (0).to_bytes(2, "big")         # identification
    packet[20:22] = (0x4000).to_bytes(2, "big")    # flags=DF, frag_offset=0
    packet[22] = 64           # TTL
    packet[23] = 6            # protocol = TCP
    packet[24:26] = (0).to_bytes(2, "big")         # checksum placeholder
    packet[26:30] = bytes([10, 0, 0, 1])           # src IP = 10.0.0.1
    packet[30:34] = bytes([10, 0, 0, 2])           # dst IP = 10.0.0.2

    # Compute and fill IPv4 checksum over the 20-byte IP header
    chk = _ipv4_checksum(packet[14:34])
    packet[24:26] = chk.to_bytes(2, "big")

    # TCP header
    packet[34:36] = (12345).to_bytes(2, "big")     # src_port
    packet[36:38] = (80).to_bytes(2, "big")         # dst_port
    packet[38:42] = (1).to_bytes(4, "big")          # seq = 1
    packet[42:46] = (0).to_bytes(4, "big")          # ack = 0
    packet[46] = 0x50        # data_offset=5 (no options)
    packet[47] = 0x02        # flags = SYN
    packet[48:50] = (8192).to_bytes(2, "big")       # window
    packet[50:52] = (0).to_bytes(2, "big")          # TCP checksum (0; not verified by XDP)
    packet[52:54] = (0).to_bytes(2, "big")          # urgent pointer

    # Payload
    packet[54:64] = bytes([0x41] * 10)              # 'A' * 10

    return packet


def materialize_dummy_packet(path: Path) -> Path:
    ensure_parent(path)
    # Regenerate if the file is absent, wrong size, or does not start with the
    # current magic bytes (which change when the packet layout is updated).
    if path.exists() and path.stat().st_size == 64:
        existing = path.read_bytes()
        if existing[0:6] == _CORPUS_PACKET_MAGIC:
            return path

    packet = _build_corpus_packet()
    path.write_bytes(packet)
    return path


def materialize_dummy_context(path: Path, size: int = 64) -> Path:
    ensure_parent(path)
    if path.exists() and path.stat().st_size == size:
        return path
    path.write_bytes(bytes(size))
    return path


def summarize_text(text: str, max_lines: int = 20, max_chars: int = 4000) -> str:
    lines = [line.rstrip() for line in text.splitlines() if line.strip()]
    if len(lines) > max_lines:
        lines = lines[-max_lines:]
    summary = "\n".join(lines)
    if len(summary) > max_chars:
        summary = summary[-max_chars:]
    return summary


def summarize_stderr(stderr: str, max_lines: int = 20, max_chars: int = 4000) -> str:
    return summarize_text(stderr, max_lines=max_lines, max_chars=max_chars)


def extract_error(stderr: str, stdout: str, returncode: int | None) -> str:
    for text in (stderr, stdout):
        lines = [line.strip() for line in text.splitlines() if line.strip()]
        if lines:
            return f"{lines[-1]} (exit={returncode})"
    return f"command failed (exit={returncode})"


def run_command(
    command: list[str],
    timeout_seconds: int,
    *,
    cwd: Path,
    expect_json: bool = True,
) -> dict[str, Any]:
    start = time.monotonic()
    try:
        completed = subprocess.run(
            command,
            cwd=cwd,
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
            "sample": None,
            "error": f"timeout after {timeout_seconds}s",
        }

    stdout = completed.stdout or ""
    stderr = completed.stderr or ""
    sample = None
    parse_error = None
    if completed.returncode == 0 and expect_json:
        try:
            sample = parse_runner_sample(stdout)
        except Exception as exc:  # pragma: no cover
            parse_error = str(exc)

    ok = completed.returncode == 0 and (sample is not None if expect_json else True)
    error = parse_error if parse_error is not None else None
    if not ok and error is None:
        error = extract_error(stderr, stdout, completed.returncode)

    return {
        "ok": ok,
        "command": command,
        "returncode": completed.returncode,
        "timed_out": False,
        "duration_seconds": time.monotonic() - start,
        "stdout": stdout,
        "stderr": stderr,
        "sample": sample,
        "error": error,
    }


def run_text_command(command: list[str], timeout_seconds: int, *, cwd: Path) -> dict[str, Any]:
    result = run_command(command, timeout_seconds, cwd=cwd, expect_json=False)
    result.setdefault("sample", None)
    return result


def parse_runner_json(stdout: str) -> dict[str, Any]:
    return dict(parse_runner_sample(stdout))


def maybe_sudo_prefix(enabled: bool) -> list[str]:
    if not enabled or os.geteuid() == 0:
        return []
    return ["sudo", "-n"]


def build_kernel_command(
    runner: Path,
    object_path: Path,
    program_name: str,
    io_mode: str,
    memory_path: Path | None,
    input_size: int,
    repeat: int,
    *,
    compile_only: bool,
    recompile_all: bool,
    recompile_v5: bool = False,
    skip_families: list[str] | tuple[str, ...] = (),
    dump_xlated: Path | None = None,
    btf_custom_path: Path | None = None,
    use_sudo: bool = True,
) -> list[str]:
    command = build_runner_command(
        runner,
        "run-kernel",
        program=object_path,
        program_name=program_name,
        io_mode=io_mode,
        repeat=max(1, repeat),
        memory=memory_path,
        input_size=input_size,
        raw_packet=(io_mode == "packet"),
        compile_only=compile_only,
        recompile_all=recompile_all,
        recompile_v5=recompile_v5,
        skip_families=skip_families,
        dump_xlated=dump_xlated,
        btf_custom_path=btf_custom_path,
    )
    return [*maybe_sudo_prefix(use_sudo), *command]


def invocation_summary(result: Mapping[str, Any] | None) -> dict[str, Any] | None:
    if result is None:
        return None
    return {
        "ok": bool(result.get("ok")),
        "returncode": result.get("returncode"),
        "timed_out": bool(result.get("timed_out")),
        "duration_seconds": result.get("duration_seconds"),
        "error": result.get("error"),
        "stderr_tail": summarize_stderr(str(result.get("stderr", ""))),
        "sample": result.get("sample"),
    }


def normalize_section_root(section_name: str) -> str:
    if not section_name:
        return "unknown"
    root = section_name.split("/", 1)[0]
    if root.startswith("kprobe"):
        return "kprobe"
    if root.startswith("kretprobe"):
        return "kretprobe"
    if root.startswith("raw_tp"):
        return "raw_tp"
    return root


def infer_program_kind(section_name: str) -> str:
    root = normalize_section_root(section_name)
    if root in {"xdp", "socket", "classifier", "tc", "flow_dissector", "sk_skb", "sk_msg"}:
        return root
    if root in {"kprobe", "kretprobe", "tracepoint", "raw_tracepoint", "raw_tp"}:
        return "tracing"
    if root in {"fentry", "fexit", "fmod_ret", "lsm"}:
        return "tracing"
    if root in {"uprobe", "uretprobe", "usdt"}:
        return "tracing"
    if root in {"perf_event", "iter", "syscall", "struct_ops"}:
        return root
    return root


def execution_plan(section_name: str, packet_path: Path, context_path: Path) -> dict[str, Any]:
    root = normalize_section_root(section_name)
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


def directive_scan_from_record(record: Mapping[str, Any] | None) -> dict[str, int]:
    sample = record.get("sample") if record else None
    scan = sample.get("directive_scan") if isinstance(sample, Mapping) else None
    return normalize_directive_scan(scan)


def parse_json_lines_payloads(stdout: str) -> list[dict[str, Any]]:
    payloads = parse_json_lines(stdout)
    return [dict(payload) for payload in payloads if isinstance(payload, Mapping)]


def text_invocation_summary(result: Mapping[str, Any] | None) -> dict[str, Any] | None:
    if result is None:
        return None
    payload = invocation_summary(result)
    if payload is None:
        return None
    payload["stdout_tail"] = summarize_text(str(result.get("stdout", "")))
    return payload


def program_label(record: Mapping[str, Any]) -> str:
    return f"{record['object_path']}:{record['program_name']}"


def scanner_v5_command(scanner: Path, xlated_path: Path) -> list[str]:
    return [str(scanner), "scan", "--xlated", str(xlated_path), "--all", "--v5"]


def parse_scanner_v5_output(stdout: str) -> dict[str, int]:
    counts = normalize_directive_scan({})
    accepted = False
    for line in stdout.splitlines():
        stripped = line.strip()
        if not stripped:
            continue
        if stripped.startswith("{") and stripped.endswith("}"):
            try:
                payload = json.loads(stripped)
            except json.JSONDecodeError:
                continue
            if not isinstance(payload, Mapping):
                continue
            summary = payload.get("summary")
            if isinstance(summary, Mapping):
                accepted = True
                counts = normalize_directive_scan(summary)
                break
    if not accepted and counts["total_sites"] == 0:
        raise RuntimeError("scanner did not emit a v5 summary")
    return counts


def markdown_table(headers: list[str], rows: list[list[Any]]) -> list[str]:
    lines = [
        "| " + " | ".join(headers) + " |",
        "| " + " | ".join("---" for _ in headers) + " |",
    ]
    for row in rows:
        lines.append("| " + " | ".join(str(cell) for cell in row) + " |")
    return lines


def format_ns(value: Any) -> str:
    if value is None:
        return "n/a"
    return str(int(value))


def summarize_failure_reason(record: Mapping[str, Any] | None) -> str:
    if not record:
        return "n/a"
    error = record.get("error")
    if error:
        return str(error)
    sample = record.get("sample") or {}
    recompile = sample.get("recompile") if isinstance(sample, Mapping) else {}
    if isinstance(recompile, Mapping) and recompile.get("error"):
        return str(recompile["error"])
    return "unknown"


__all__ = [
    "build_kernel_command",
    "directive_scan_from_record",
    "ensure_parent",
    "execution_plan",
    "extract_error",
    "format_ns",
    "infer_program_kind",
    "invocation_summary",
    "markdown_table",
    "materialize_dummy_context",
    "materialize_dummy_packet",
    "maybe_sudo_prefix",
    "normalize_section_root",
    "parse_json_lines_payloads",
    "parse_runner_json",
    "parse_scanner_v5_output",
    "program_label",
    "relpath",
    "run_command",
    "run_text_command",
    "scanner_v5_command",
    "summarize_failure_reason",
    "summarize_stderr",
    "summarize_text",
    "text_invocation_summary",
]
