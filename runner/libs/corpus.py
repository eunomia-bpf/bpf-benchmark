from __future__ import annotations

import argparse
import json
import math
import subprocess
import time
from pathlib import Path
from typing import Any, Mapping

from . import ensure_parent
from .commands import build_runner_command
from .results import normalize_directive_scan, parse_runner_sample


def relpath(path: Path | str, root_dir: Path) -> str:
    candidate = Path(path)
    try:
        return candidate.relative_to(root_dir).as_posix()
    except ValueError:
        return str(candidate)



def add_output_json_argument(
    parser: argparse.ArgumentParser,
    default: Path | str,
    *,
    help_text: str = "Path for structured JSON output.",
) -> None:
    parser.add_argument("--output-json", default=str(default), help=help_text)


def add_output_md_argument(
    parser: argparse.ArgumentParser,
    default: Path | str,
    *,
    help_text: str = "Path for markdown output.",
) -> None:
    parser.add_argument("--output-md", default=str(default), help=help_text)


def add_runner_argument(
    parser: argparse.ArgumentParser,
    default: Path | str | None = None,
    *,
    help_text: str,
) -> None:
    kwargs: dict[str, Any] = {"help": help_text}
    if default is not None:
        kwargs["default"] = str(default)
    parser.add_argument("--runner", **kwargs)


def add_daemon_argument(
    parser: argparse.ArgumentParser,
    default: Path | str,
    *,
    help_text: str,
) -> None:
    parser.add_argument("--daemon", default=str(default), help=help_text)


def add_repeat_argument(
    parser: argparse.ArgumentParser,
    default: int | None = None,
    *,
    help_text: str,
) -> None:
    kwargs: dict[str, Any] = {"type": int, "help": help_text}
    if default is not None:
        kwargs["default"] = default
    parser.add_argument("--repeat", **kwargs)


def add_timeout_argument(
    parser: argparse.ArgumentParser,
    default: int,
    *,
    help_text: str,
) -> None:
    parser.add_argument("--timeout", type=int, default=default, help=help_text)


def add_filter_argument(
    parser: argparse.ArgumentParser,
    *,
    help_text: str,
) -> None:
    parser.add_argument("--filter", action="append", dest="filters", help=help_text)


def add_max_programs_argument(
    parser: argparse.ArgumentParser,
    *,
    help_text: str,
) -> None:
    parser.add_argument("--max-programs", type=int, help=help_text)


def add_corpus_build_report_argument(
    parser: argparse.ArgumentParser,
    *,
    help_text: str,
) -> None:
    parser.add_argument("--corpus-build-report", help=help_text)


def require_minimum(value: int, minimum: int, flag: str) -> None:
    if value < minimum:
        raise SystemExit(f"{flag} must be >= {minimum}")


def _ipv4_checksum(header: bytes | bytearray) -> int:
    """Compute RFC 791 one's complement checksum over a 20-byte IPv4 header."""
    s = 0
    for i in range(0, len(header), 2):
        s += (header[i] << 8) + header[i + 1]
    while s >> 16:
        s = (s & 0xFFFF) + (s >> 16)
    return ~s & 0xFFFF


def _checksum16(data: bytes | bytearray) -> int:
    blob = bytes(data)
    if len(blob) % 2:
        blob += b"\x00"
    total = 0
    for i in range(0, len(blob), 2):
        total += (blob[i] << 8) + blob[i + 1]
    while total >> 16:
        total = (total & 0xFFFF) + (total >> 16)
    return ~total & 0xFFFF


def _tcp_ipv4_checksum(src_ip: bytes, dst_ip: bytes, segment: bytes | bytearray) -> int:
    pseudo_header = bytearray(12)
    pseudo_header[0:4] = src_ip
    pseudo_header[4:8] = dst_ip
    pseudo_header[9] = 6
    pseudo_header[10:12] = len(segment).to_bytes(2, "big")
    return _checksum16(pseudo_header + bytes(segment))


# Expected content of the canonical corpus dummy packet (version tag at bytes 0-5 of MAC dst).
# Bumping this sentinel forces regeneration when the packet layout is updated.
_CORPUS_PACKET_MAGIC = bytes.fromhex("ffffffffffff")  # broadcast dst MAC as version sentinel
_KATRAN_PACKET_MAGIC = bytes.fromhex("02000000000a")  # Katran LB MAC as version sentinel

# Keep these values in sync with e2e/cases/katran/case.py.
_KATRAN_CLIENT_IP = bytes([10, 0, 0, 2])
_KATRAN_VIP_IP = bytes([10, 100, 1, 1])
_KATRAN_CLIENT_MAC = bytes.fromhex("02000000001c")
_KATRAN_LB_MAC = bytes.fromhex("02000000000a")
_KATRAN_SRC_PORT = 31337
_KATRAN_DST_PORT = 8080
_KATRAN_TCP_ACK = 0x10
_KATRAN_PAYLOAD = b"KATRANVIP!"


def _build_ipv4_tcp_packet(
    *,
    dst_mac: bytes,
    src_mac: bytes,
    src_ip: bytes,
    dst_ip: bytes,
    src_port: int,
    dst_port: int,
    payload: bytes,
    tcp_flags: int,
) -> bytearray:
    ip_total_length = 20 + 20 + len(payload)
    packet = bytearray(max(64, 14 + ip_total_length))

    packet[0:6] = dst_mac
    packet[6:12] = src_mac
    packet[12:14] = bytes.fromhex("0800")

    packet[14] = 0x45
    packet[15] = 0x00
    packet[16:18] = ip_total_length.to_bytes(2, "big")
    packet[18:20] = (0).to_bytes(2, "big")
    packet[20:22] = (0x4000).to_bytes(2, "big")
    packet[22] = 64
    packet[23] = 6
    packet[24:26] = (0).to_bytes(2, "big")
    packet[26:30] = src_ip
    packet[30:34] = dst_ip
    packet[24:26] = _ipv4_checksum(packet[14:34]).to_bytes(2, "big")

    packet[34:36] = int(src_port).to_bytes(2, "big")
    packet[36:38] = int(dst_port).to_bytes(2, "big")
    packet[38:42] = (1).to_bytes(4, "big")
    packet[42:46] = (0).to_bytes(4, "big")
    packet[46] = 0x50
    packet[47] = int(tcp_flags & 0xFF)
    packet[48:50] = (8192).to_bytes(2, "big")
    packet[50:52] = (0).to_bytes(2, "big")
    packet[52:54] = (0).to_bytes(2, "big")
    packet[54 : 54 + len(payload)] = payload
    packet[50:52] = _tcp_ipv4_checksum(src_ip, dst_ip, packet[34 : 54 + len(payload)]).to_bytes(2, "big")
    return packet


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


def _build_katran_packet() -> bytearray:
    return _build_ipv4_tcp_packet(
        dst_mac=_KATRAN_LB_MAC,
        src_mac=_KATRAN_CLIENT_MAC,
        src_ip=_KATRAN_CLIENT_IP,
        dst_ip=_KATRAN_VIP_IP,
        src_port=_KATRAN_SRC_PORT,
        dst_port=_KATRAN_DST_PORT,
        payload=_KATRAN_PAYLOAD,
        tcp_flags=_KATRAN_TCP_ACK,
    )


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


def materialize_katran_packet(path: Path) -> Path:
    ensure_parent(path)
    if path.exists() and path.stat().st_size == 64:
        existing = path.read_bytes()
        if existing[0:6] == _KATRAN_PACKET_MAGIC:
            return path

    packet = _build_katran_packet()
    path.write_bytes(packet)
    return path


def materialize_dummy_context(path: Path, size: int = 64) -> Path:
    ensure_parent(path)
    if path.exists() and path.stat().st_size == size:
        return path
    path.write_bytes(bytes(size))
    return path


def summarize_text(text: str | bytes, max_lines: int = 20, max_chars: int = 4000) -> str:
    if isinstance(text, bytes):
        text = text.decode("utf-8", errors="replace")
    lines = [line.rstrip() for line in text.splitlines() if line.strip()]
    if len(lines) > max_lines:
        lines = lines[-max_lines:]
    summary = "\n".join(lines)
    if len(summary) > max_chars:
        summary = summary[-max_chars:]
    return summary



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
        # exc.stdout/stderr may be bytes even with text=True
        raw_stdout = exc.stdout or ""
        raw_stderr = exc.stderr or ""
        if isinstance(raw_stdout, bytes):
            raw_stdout = raw_stdout.decode("utf-8", errors="replace")
        if isinstance(raw_stderr, bytes):
            raw_stderr = raw_stderr.decode("utf-8", errors="replace")
        return {
            "ok": False,
            "command": command,
            "returncode": None,
            "timed_out": True,
            "duration_seconds": time.monotonic() - start,
            "stdout": raw_stdout,
            "stderr": raw_stderr,
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


def write_json_output(path: Path, payload: Any) -> None:
    ensure_parent(path)
    path.write_text(json.dumps(payload, indent=2) + "\n")


def write_text_output(path: Path, text: str) -> None:
    ensure_parent(path)
    path.write_text(text)


def parse_runner_json(stdout: str) -> dict[str, Any]:
    return dict(parse_runner_sample(stdout))


def invocation_summary(result: Mapping[str, Any] | None) -> dict[str, Any] | None:
    if result is None:
        return None
    return {
        "ok": bool(result.get("ok")),
        "returncode": result.get("returncode"),
        "timed_out": bool(result.get("timed_out")),
        "duration_seconds": result.get("duration_seconds"),
        "error": result.get("error"),
        "stderr_tail": summarize_text(str(result.get("stderr", ""))),
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


def geomean(values: list[float | int | None]) -> float | None:
    filtered = [float(value) for value in values if value is not None and float(value) > 0.0]
    if not filtered:
        return None
    return math.exp(sum(math.log(value) for value in filtered) / len(filtered))


def format_ratio(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.3f}x"


def format_pct(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:+.1f}%"


def summarize_failure_reason(record: Mapping[str, Any] | None) -> str:
    if not record:
        return "n/a"
    error = record.get("error")
    if error:
        return str(error)
    sample = record.get("sample") or {}
    rejit = sample.get("rejit") if isinstance(sample, Mapping) else {}
    if isinstance(rejit, Mapping) and rejit.get("error"):
        return str(rejit["error"])
    return "unknown"


__all__ = [
    "add_corpus_build_report_argument",
    "add_filter_argument",
    "add_max_programs_argument",
    "add_output_json_argument",
    "add_output_md_argument",
    "add_repeat_argument",
    "add_runner_argument",
    "add_daemon_argument",
    "add_timeout_argument",
    "directive_scan_from_record",
    "ensure_parent",
    "execution_plan",
    "extract_error",
    "format_pct",
    "format_ratio",
    "format_ns",
    "geomean",
    "infer_program_kind",
    "invocation_summary",
    "markdown_table",
    "materialize_dummy_context",
    "materialize_dummy_packet",
    "materialize_katran_packet",
    "normalize_section_root",
    "parse_runner_json",
    "program_label",
    "require_minimum",
    "relpath",
    "run_command",
    "run_text_command",
    "summarize_failure_reason",
    "summarize_text",
    "text_invocation_summary",
    "write_json_output",
    "write_text_output",
]
