from __future__ import annotations

import argparse
import json
import math
import re
from pathlib import Path
from typing import Any, Sequence

try:
    from results_layout import maybe_refresh_latest_alias
except ImportError:
    from corpus.results_layout import maybe_refresh_latest_alias

try:
    from orchestrator.commands import build_runner_command as build_base_runner_command
    from orchestrator.corpus import (
        directive_scan_from_record,
        ensure_parent,
        execution_plan,
        extract_error,
        format_ns,
        invocation_summary,
        markdown_table,
        materialize_dummy_context,
        materialize_dummy_packet,
        maybe_sudo_prefix,
        normalize_section_root,
        parse_runner_json,
        relpath,
        run_command as base_run_command,
        run_text_command as base_run_text_command,
        scanner_v5_command,
        summarize_stderr,
        summarize_text,
        text_invocation_summary,
    )
    from orchestrator.results import normalize_directive_scan
except ImportError:
    from micro.orchestrator.commands import build_runner_command as build_base_runner_command
    from micro.orchestrator.corpus import (
        directive_scan_from_record,
        ensure_parent,
        execution_plan,
        extract_error,
        format_ns,
        invocation_summary,
        markdown_table,
        materialize_dummy_context,
        materialize_dummy_packet,
        maybe_sudo_prefix,
        normalize_section_root,
        parse_runner_json,
        relpath,
        run_command as base_run_command,
        run_text_command as base_run_text_command,
        scanner_v5_command,
        summarize_stderr,
        summarize_text,
        text_invocation_summary,
    )
    from micro.orchestrator.results import normalize_directive_scan


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


def add_scanner_argument(
    parser: argparse.ArgumentParser,
    default: Path | str,
    *,
    help_text: str,
) -> None:
    parser.add_argument("--scanner", default=str(default), help=help_text)


def add_repeat_argument(
    parser: argparse.ArgumentParser,
    default: int | None = None,
    *,
    help_text: str,
) -> None:
    kwargs: dict[str, Any] = {
        "type": int,
        "help": help_text,
    }
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


def add_section_filter_argument(
    parser: argparse.ArgumentParser,
    *,
    help_text: str,
) -> None:
    parser.add_argument("--section-filter", action="append", dest="section_filters", help=help_text)


def require_minimum(value: int, minimum: int, flag: str) -> None:
    if value < minimum:
        raise SystemExit(f"{flag} must be >= {minimum}")


def run_command(
    command: list[str],
    timeout_seconds: int,
    *,
    cwd: Path,
    expect_json: bool = True,
) -> dict[str, Any]:
    try:
        return base_run_command(command, timeout_seconds, cwd=cwd, expect_json=expect_json)
    except OSError as exc:
        return {
            "ok": False,
            "command": command,
            "returncode": None,
            "timed_out": False,
            "duration_seconds": 0.0,
            "stdout": "",
            "stderr": "",
            "sample": None,
            "error": f"exec failed: {exc}",
        }


def run_text_command(
    command: list[str],
    timeout_seconds: int,
    *,
    cwd: Path,
) -> dict[str, Any]:
    result = run_command(command, timeout_seconds, cwd=cwd, expect_json=False)
    result.setdefault("sample", None)
    return result


def build_run_kernel_command(
    *,
    runner: Path | str,
    object_path: Path | str,
    program_name: str,
    io_mode: str,
    memory_path: Path | str | None,
    input_size: int,
    repeat: int,
    compile_only: bool,
    recompile_v5: bool,
    recompile_all: bool | None = None,
    skip_families: Sequence[str] = (),
    policy_file: Path | str | None = None,
    dump_xlated: Path | str | None = None,
    btf_custom_path: Path | str | None = None,
    use_sudo: bool = False,
) -> list[str]:
    if recompile_all is None:
        recompile_all = recompile_v5 and policy_file is None
    command = build_base_runner_command(
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
        recompile_v5=recompile_v5,
        recompile_all=recompile_all,
        skip_families=skip_families,
        policy_file=policy_file,
        dump_xlated=dump_xlated,
        btf_custom_path=btf_custom_path,
    )
    return [*maybe_sudo_prefix(use_sudo), *command]


def build_scanner_command(
    scanner: Path | str,
    xlated_path: Path | str,
    *,
    json_output: bool = False,
) -> list[str]:
    command = scanner_v5_command(Path(scanner), Path(xlated_path))
    if json_output:
        command.append("--json")
    return command


def parse_scanner_v5_output(stdout: str) -> dict[str, int]:
    counts = normalize_directive_scan({})
    for line in stdout.splitlines():
        stripped = line.strip()
        if not stripped:
            continue
        if stripped.startswith("{") and stripped.endswith("}"):
            try:
                payload = json.loads(stripped)
            except json.JSONDecodeError:
                continue
            if not isinstance(payload, dict):
                continue
            summary = payload.get("summary") if isinstance(payload.get("summary"), dict) else payload
            if isinstance(summary, dict):
                return normalize_directive_scan(summary)

    patterns = {
        "cmov_sites": re.compile(r"^\s*cmov:\s+(\d+)\s*$"),
        "wide_sites": re.compile(r"^\s*wide:\s+(\d+)\s*$"),
        "rotate_sites": re.compile(r"^\s*rotate:\s+(\d+)\s*$"),
        "lea_sites": re.compile(r"^\s*lea:\s+(\d+)\s*$"),
        "bitfield_sites": re.compile(r"^\s*extract:\s*(\d+)\s*$"),
        "zero_ext_sites": re.compile(r"^\s*zeroext:\s*(\d+)\s*$"),
        "endian_sites": re.compile(r"^\s*endian:\s*(\d+)\s*$"),
        "branch_flip_sites": re.compile(r"^\s*bflip:\s*(\d+)\s*$"),
    }
    accepted = False
    for line in stdout.splitlines():
        stripped = line.strip()
        if re.match(r"^Accepted\s+\d+\s+v5 site\(s\)\s*$", stripped):
            accepted = True
        for field, pattern in patterns.items():
            match = pattern.match(stripped)
            if match:
                counts[field] = int(match.group(1))
    counts["total_sites"] = sum(counts[field] for field in patterns)
    if not accepted and counts["total_sites"] == 0:
        raise RuntimeError("scanner did not emit a v5 summary")
    return counts


def write_json_output(path: Path, payload: Any) -> None:
    ensure_parent(path)
    path.write_text(json.dumps(payload, indent=2) + "\n")
    maybe_refresh_latest_alias(path)


def write_text_output(path: Path, text: str) -> None:
    ensure_parent(path)
    path.write_text(text)


def geomean(values: Sequence[float | int | None]) -> float | None:
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


__all__ = [
    "add_corpus_build_report_argument",
    "add_filter_argument",
    "add_max_programs_argument",
    "add_output_json_argument",
    "add_output_md_argument",
    "add_repeat_argument",
    "add_runner_argument",
    "add_scanner_argument",
    "add_section_filter_argument",
    "add_timeout_argument",
    "build_run_kernel_command",
    "build_scanner_command",
    "directive_scan_from_record",
    "ensure_parent",
    "execution_plan",
    "extract_error",
    "format_ns",
    "format_pct",
    "format_ratio",
    "geomean",
    "invocation_summary",
    "markdown_table",
    "materialize_dummy_context",
    "materialize_dummy_packet",
    "normalize_section_root",
    "normalize_directive_scan",
    "parse_runner_json",
    "parse_scanner_v5_output",
    "relpath",
    "require_minimum",
    "run_command",
    "run_text_command",
    "summarize_stderr",
    "summarize_text",
    "text_invocation_summary",
    "write_json_output",
    "write_text_output",
]
