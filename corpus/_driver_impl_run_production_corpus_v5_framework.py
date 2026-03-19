#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import statistics
import subprocess
import sys
import tempfile
import time
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

from directive_census import analyze_object
try:
    from common import (
        add_filter_argument,
        add_max_programs_argument,
        add_output_json_argument,
        add_output_md_argument,
        add_repeat_argument,
        add_runner_argument,
        add_scanner_argument,
        add_timeout_argument,
        build_run_kernel_command,
        build_scanner_command,
        directive_scan_from_record,
        ensure_parent,
        execution_plan,
        extract_error,
        format_ns,
        format_pct,
        format_ratio,
        geomean,
        markdown_table,
        materialize_dummy_context,
        materialize_dummy_packet,
        normalize_section_root,
        parse_scanner_v5_output,
        run_command as shared_run_command,
        run_text_command as shared_run_text_command,
        summarize_stderr,
    )
except ImportError:
    from corpus.common import (
        add_filter_argument,
        add_max_programs_argument,
        add_output_json_argument,
        add_output_md_argument,
        add_repeat_argument,
        add_runner_argument,
        add_scanner_argument,
        add_timeout_argument,
        build_run_kernel_command,
        build_scanner_command,
        directive_scan_from_record,
        ensure_parent,
        execution_plan,
        extract_error,
        format_ns,
        format_pct,
        format_ratio,
        geomean,
        markdown_table,
        materialize_dummy_context,
        materialize_dummy_packet,
        normalize_section_root,
        parse_scanner_v5_output,
        run_command as shared_run_command,
        run_text_command as shared_run_text_command,
        summarize_stderr,
    )


ROOT_DIR = Path(__file__).resolve().parent.parent
DEFAULT_OUTPUT_JSON = ROOT_DIR / "docs" / "tmp" / "production-corpus-v5-results.json"
DEFAULT_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "production-corpus-v5-results.md"
DEFAULT_RUNNER = ROOT_DIR / "micro" / "build" / "runner" / "micro_exec"
DEFAULT_SCANNER = ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"
DEFAULT_PACKET_PATH = ROOT_DIR / "micro" / "generated-inputs" / "corpus_dummy_packet_64.bin"
DEFAULT_CONTEXT_PATH = ROOT_DIR / "micro" / "generated-inputs" / "corpus_dummy_context_64.bin"
DEFAULT_REPEAT = 100
DEFAULT_TIMEOUT_SECONDS = 180
DEFAULT_KERNEL_TREE = (
    ROOT_DIR / "vendor" / "linux"
    if (ROOT_DIR / "vendor" / "linux").exists()
    else ROOT_DIR / "vendor" / "linux-framework"
)
DEFAULT_BTF_CANDIDATES = (
    Path("/sys/kernel/btf/vmlinux"),
    DEFAULT_KERNEL_TREE / "vmlinux",
)
CORPUS_BUILD_DIR = ROOT_DIR / "corpus" / "build"
PRODUCTION_OBJECT_DIRS = tuple(
    CORPUS_BUILD_DIR / name
    for name in (
        "calico",
        "cilium",
        "katran",
        "loxilb",
        "netbird",
        "suricata",
        "systemd",
        "tubular",
        "xdp-tools",
        "xdp-tutorial",
    )
)
PERF_CAPABLE_ROOTS = {
    "classifier",
    "flow_dissector",
    "raw_tp",
    "raw_tracepoint",
    "sk_msg",
    "sk_skb",
    "socket",
    "tc",
    "xdp",
}
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
FALLBACK_SECTION_FIELDS = (
    ("CMOV", "cmov"),
    ("WIDE", "wide"),
    ("ROTATE", "rotate"),
    ("LEA", "lea"),
    ("EXTRACT", "extract"),
    ("ZERO-EXT", "zeroext"),
    ("ENDIAN", "endian"),
    ("BRANCH-FLIP", "bflip"),
)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Run the production BPF corpus on the framework kernel guest with "
            "baseline and v5 recompile, recording compile/load/runtime failures."
        )
    )
    add_output_json_argument(parser, DEFAULT_OUTPUT_JSON)
    add_output_md_argument(parser, DEFAULT_OUTPUT_MD)
    add_runner_argument(parser, DEFAULT_RUNNER, help_text="Path to micro_exec inside the shared repo mount.")
    add_scanner_argument(parser, DEFAULT_SCANNER, help_text="Path to the scanner CLI binary.")
    add_repeat_argument(parser, DEFAULT_REPEAT, help_text="Repeat count for measured runs.")
    add_timeout_argument(parser, DEFAULT_TIMEOUT_SECONDS, help_text="Per-invocation timeout in seconds.")
    add_filter_argument(parser, help_text="Only include objects or program names containing this substring. Repeatable.")
    parser.add_argument(
        "--max-objects",
        type=int,
        help="Optional cap for smoke testing by object count.",
    )
    add_max_programs_argument(parser, help_text="Optional cap for smoke testing by discovered program count.")
    return parser.parse_args(argv)


def display_path(path: Path) -> str:
    try:
        return path.relative_to(ROOT_DIR).as_posix()
    except ValueError:
        return str(path)


def parse_program_inventory(stdout: str) -> list[dict[str, Any]]:
    lines = [line.strip() for line in stdout.splitlines() if line.strip()]
    if not lines:
        raise RuntimeError("list-programs produced no JSON output")
    payload = json.loads(lines[-1])
    if not isinstance(payload, list):
        raise RuntimeError("list-programs did not return a JSON array")
    return payload


def run_text_command(command: list[str], timeout_seconds: int) -> dict[str, Any]:
    return shared_run_text_command(command, timeout_seconds, cwd=ROOT_DIR)


def run_command(command: list[str], timeout_seconds: int) -> dict[str, Any]:
    return shared_run_command(command, timeout_seconds, cwd=ROOT_DIR)


def invocation_summary(result: dict[str, Any] | None) -> dict[str, Any] | None:
    if result is None:
        return None
    return {
        "ok": result["ok"],
        "returncode": result["returncode"],
        "timed_out": result["timed_out"],
        "duration_seconds": result["duration_seconds"],
        "error": result["error"],
        "stderr_tail": summarize_stderr(result["stderr"]),
        "sample": result["sample"],
        "btf_path_used": result.get("btf_path_used"),
        "btf_attempts": result.get("btf_attempts", []),
    }


def text_invocation_summary(result: dict[str, Any] | None) -> dict[str, Any] | None:
    if result is None:
        return None
    return {
        "ok": result["ok"],
        "returncode": result["returncode"],
        "timed_out": result["timed_out"],
        "duration_seconds": result["duration_seconds"],
        "error": result["error"],
        "stdout": result["stdout"],
        "stderr_tail": summarize_stderr(result["stderr"]),
    }


def is_perf_capable(section_name: str) -> bool:
    return normalize_section_root(section_name) in PERF_CAPABLE_ROOTS


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


def build_runner_command(
    runner: Path,
    object_path: Path,
    program_name: str,
    io_mode: str,
    memory_path: Path | None,
    input_size: int,
    repeat: int,
    btf_custom_path: Path | None,
    *,
    compile_only: bool,
    recompile_v5: bool,
    dump_xlated: Path | None = None,
) -> list[str]:
    return build_run_kernel_command(
        runner=runner,
        object_path=object_path,
        program_name=program_name,
        io_mode=io_mode,
        memory_path=memory_path,
        input_size=input_size,
        repeat=repeat,
        compile_only=compile_only,
        recompile_v5=recompile_v5,
        dump_xlated=dump_xlated,
        btf_custom_path=btf_custom_path,
        use_sudo=True,
    )


def run_with_btf_fallback(
    *,
    runner: Path,
    object_path: Path,
    program_name: str,
    io_mode: str,
    memory_path: Path | None,
    input_size: int,
    repeat: int,
    compile_only: bool,
    recompile_v5: bool,
    timeout_seconds: int,
    preferred_btf_path: Path | None = None,
    dump_xlated: Path | None = None,
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
        result = run_command(
            build_runner_command(
                runner,
                object_path,
                program_name,
                io_mode,
                memory_path,
                input_size,
                repeat,
                btf_path,
                compile_only=compile_only,
                recompile_v5=recompile_v5,
                dump_xlated=dump_xlated,
            ),
            timeout_seconds,
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


def discover_programs(runner: Path, object_path: Path, timeout_seconds: int) -> dict[str, Any]:
    start = time.monotonic()
    try:
        completed = subprocess.run(
            [str(runner), "list-programs", "--program", str(object_path)],
            cwd=ROOT_DIR,
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
        )
        stdout = completed.stdout or ""
        stderr = completed.stderr or ""
        ok = completed.returncode == 0
        returncode = completed.returncode
    except subprocess.TimeoutExpired as exc:
        stdout = exc.stdout or ""
        stderr = exc.stderr or ""
        ok = False
        returncode = None
        error = f"timeout after {timeout_seconds}s"
    except OSError as exc:
        stdout = ""
        stderr = ""
        ok = False
        returncode = None
        error = f"exec failed: {exc}"

    programs: list[dict[str, Any]] = []
    error = locals().get("error")
    if ok:
        try:
            programs = parse_program_inventory(stdout)
        except Exception as exc:  # pragma: no cover - runtime parse guard
            ok = False
            error = str(exc)
    if not ok and error is None:
        error = extract_error(stderr, stdout, returncode)

    fallback_scan = analyze_object(object_path, "production-corpus", ROOT_DIR)
    return {
        "ok": ok,
        "duration_seconds": time.monotonic() - start,
        "programs": programs,
        "error": error,
        "stderr_tail": summarize_stderr(stderr),
        "fallback_section_scan": [
            {
                "name": section.name,
                "insn_count": section.insn_count,
                "cmov": section.cmov,
                "wide": section.wide,
                "rotate": section.rotate,
                "lea": section.lea,
                "extract": section.extract,
                "zeroext": section.zeroext,
                "endian": section.endian,
                "bflip": section.bflip,
                "total": section.total,
            }
            for section in fallback_scan.sections
        ],
        "fallback_totals": {
            "cmov": fallback_scan.cmov,
            "wide": fallback_scan.wide,
            "rotate": fallback_scan.rotate,
            "lea": fallback_scan.lea,
            "extract": fallback_scan.extract,
            "zeroext": fallback_scan.zeroext,
            "endian": fallback_scan.endian,
            "bflip": fallback_scan.bflip,
            "total": fallback_scan.total,
            "insn_count": fallback_scan.insn_count,
            "exec_section_count": fallback_scan.exec_section_count,
        },
    }


def size_ratio(baseline_record: dict[str, Any] | None, v5_record: dict[str, Any] | None) -> float | None:
    if not baseline_record or not v5_record:
        return None
    if not baseline_record.get("ok") or not v5_record.get("ok"):
        return None
    baseline_len = (baseline_record.get("sample") or {}).get("jited_prog_len")
    v5_len = (v5_record.get("sample") or {}).get("jited_prog_len")
    if not baseline_len or not v5_len:
        return None
    return float(baseline_len) / float(v5_len)


def size_delta_pct(baseline_record: dict[str, Any] | None, v5_record: dict[str, Any] | None) -> float | None:
    if not baseline_record or not v5_record:
        return None
    if not baseline_record.get("ok") or not v5_record.get("ok"):
        return None
    baseline_len = (baseline_record.get("sample") or {}).get("jited_prog_len")
    v5_len = (v5_record.get("sample") or {}).get("jited_prog_len")
    if baseline_len is None or v5_len is None or baseline_len == 0:
        return None
    return (float(v5_len) - float(baseline_len)) * 100.0 / float(baseline_len)


def speedup_ratio(baseline_record: dict[str, Any] | None, v5_record: dict[str, Any] | None) -> float | None:
    if not baseline_record or not v5_record:
        return None
    if not baseline_record.get("ok") or not v5_record.get("ok"):
        return None
    baseline_ns = (baseline_record.get("sample") or {}).get("exec_ns")
    v5_ns = (v5_record.get("sample") or {}).get("exec_ns")
    if not baseline_ns or not v5_ns:
        return None
    return float(baseline_ns) / float(v5_ns)


def summarize_failure_reason(record: dict[str, Any] | None) -> str:
    if not record:
        return "n/a"
    if record.get("error"):
        return str(record["error"])
    sample = record.get("sample") or {}
    recompile = sample.get("recompile") or {}
    if recompile.get("error"):
        return str(recompile["error"])
    return "unknown"


def collect_object_paths(filters: list[str] | None, max_objects: int | None) -> list[Path]:
    objects: list[Path] = []
    for directory in PRODUCTION_OBJECT_DIRS:
        objects.extend(sorted(directory.rglob("*.bpf.o")))

    if filters:
        lowered = [item.lower() for item in filters]
        objects = [
            path
            for path in objects
            if any(needle in path.relative_to(ROOT_DIR).as_posix().lower() for needle in lowered)
        ]
    if max_objects is not None:
        objects = objects[:max_objects]
    return objects


def infer_source(relpath: str) -> str:
    prefix = "corpus/build/"
    if relpath.startswith(prefix):
        remainder = relpath[len(prefix):]
        if remainder:
            return remainder.split("/", 1)[0]
    return "unknown"


def detect_kernel_metadata(kernel_tree: Path) -> dict[str, str]:
    def read_git(*args: str) -> str:
        completed = subprocess.run(
            ["git", "-C", str(kernel_tree), *args],
            cwd=ROOT_DIR,
            capture_output=True,
            text=True,
            check=False,
        )
        return (completed.stdout or "").strip()

    uname = subprocess.run(
        ["uname", "-r"],
        cwd=ROOT_DIR,
        capture_output=True,
        text=True,
        check=False,
    )
    return {
        "kernel_release": (uname.stdout or "").strip(),
        "kernel_tree": str(kernel_tree),
        "kernel_branch": read_git("branch", "--show-current"),
        "kernel_commit": read_git("rev-parse", "--short", "HEAD"),
    }


def run_target(
    runner: Path,
    scanner: Path,
    packet_path: Path,
    context_path: Path,
    target: dict[str, Any],
    repeat: int,
    timeout_seconds: int,
) -> dict[str, Any]:
    object_path = ROOT_DIR / target["object_path"]
    plan = execution_plan(target["section_name"], packet_path, context_path)
    scanner_raw: dict[str, Any] | None = None

    with tempfile.TemporaryDirectory(prefix="production-corpus-") as tmpdir:
        xlated_path = Path(tmpdir) / "program.xlated"
        baseline_compile_raw = run_with_btf_fallback(
            runner=runner,
            object_path=object_path,
            program_name=target["program_name"],
            io_mode=plan["io_mode"],
            memory_path=plan["memory_path"],
            input_size=plan["input_size"],
            repeat=1,
            compile_only=True,
            recompile_v5=False,
            timeout_seconds=timeout_seconds,
            dump_xlated=xlated_path,
        )
        if baseline_compile_raw["ok"]:
            scanner_raw = run_text_command(
                build_scanner_command(scanner, xlated_path, json_output=True),
                timeout_seconds,
            )
        v5_compile_raw = run_with_btf_fallback(
            runner=runner,
            object_path=object_path,
            program_name=target["program_name"],
            io_mode=plan["io_mode"],
            memory_path=plan["memory_path"],
            input_size=plan["input_size"],
            repeat=1,
            compile_only=True,
            recompile_v5=True,
            timeout_seconds=timeout_seconds,
            preferred_btf_path=Path(baseline_compile_raw["btf_path_used"])
            if baseline_compile_raw.get("btf_path_used")
            else None,
        )

        baseline_run_raw: dict[str, Any] | None = None
        v5_run_raw: dict[str, Any] | None = None
        if target["perf_capable"] and baseline_compile_raw["ok"]:
            baseline_run_raw = run_with_btf_fallback(
                runner=runner,
                object_path=object_path,
                program_name=target["program_name"],
                io_mode=plan["io_mode"],
                memory_path=plan["memory_path"],
                input_size=plan["input_size"],
                repeat=repeat,
                compile_only=False,
                recompile_v5=False,
                timeout_seconds=timeout_seconds,
                preferred_btf_path=Path(baseline_compile_raw["btf_path_used"])
                if baseline_compile_raw.get("btf_path_used")
                else None,
            )
        if target["perf_capable"] and v5_compile_raw["ok"]:
            v5_run_raw = run_with_btf_fallback(
                runner=runner,
                object_path=object_path,
                program_name=target["program_name"],
                io_mode=plan["io_mode"],
                memory_path=plan["memory_path"],
                input_size=plan["input_size"],
                repeat=repeat,
                compile_only=False,
                recompile_v5=True,
                timeout_seconds=timeout_seconds,
                preferred_btf_path=Path(v5_compile_raw["btf_path_used"])
                if v5_compile_raw.get("btf_path_used")
                else None,
            )

    baseline_compile = invocation_summary(baseline_compile_raw)
    v5_compile = invocation_summary(v5_compile_raw)
    baseline_run = invocation_summary(baseline_run_raw)
    v5_run = invocation_summary(v5_run_raw)
    scanner_cli = text_invocation_summary(scanner_raw)
    scanner_counts = (
        parse_scanner_v5_output(scanner_raw["stdout"])
        if scanner_raw is not None and scanner_raw["ok"]
        else directive_scan_from_record(v5_compile_raw)
    )

    return {
        **target,
        "io_mode": plan["io_mode"],
        "input_size": plan["input_size"],
        "memory_path": str(plan["memory_path"]) if plan["memory_path"] is not None else None,
        "scanner_cli": scanner_cli,
        "scanner_counts": scanner_counts,
        "baseline_compile": baseline_compile,
        "v5_compile": v5_compile,
        "baseline_run": baseline_run,
        "v5_run": v5_run,
        "v5_compile_applied": bool(((v5_compile or {}).get("sample") or {}).get("recompile", {}).get("applied")),
        "v5_run_applied": bool(((v5_run or {}).get("sample") or {}).get("recompile", {}).get("applied")),
        "size_ratio": size_ratio(baseline_compile_raw, v5_compile_raw),
        "size_delta_pct": size_delta_pct(baseline_compile_raw, v5_compile_raw),
        "speedup_ratio": speedup_ratio(baseline_run_raw, v5_run_raw),
    }


def build_summary(programs: list[dict[str, Any]], objects: list[dict[str, Any]]) -> dict[str, Any]:
    compile_pairs = [
        record
        for record in programs
        if record["baseline_compile"] and record["baseline_compile"]["ok"]
        and record["v5_compile"] and record["v5_compile"]["ok"]
    ]
    measured_pairs = [
        record
        for record in programs
        if record["baseline_run"] and record["baseline_run"]["ok"]
        and record["v5_run"] and record["v5_run"]["ok"]
    ]
    framework_detected = [
        record for record in programs if record["scanner_counts"]["total_sites"] > 0
    ]
    recompile_applied = [
        record for record in programs if record["v5_compile_applied"] or record["v5_run_applied"]
    ]
    discovery_failures = [record for record in objects if not record["discovery"]["ok"]]

    speedups = [record["speedup_ratio"] for record in measured_pairs if record["speedup_ratio"] is not None]
    size_ratios = [record["size_ratio"] for record in compile_pairs if record["size_ratio"] is not None]
    size_deltas = [record["size_delta_pct"] for record in compile_pairs if record["size_delta_pct"] is not None]

    family_totals = Counter()
    for record in framework_detected:
        for _, field in FAMILY_FIELDS:
            family_totals[field] += record["scanner_counts"].get(field, 0)

    failure_reasons = Counter()
    recompile_failures = Counter()
    for record in discovery_failures:
        failure_reasons[record["discovery"]["error"] or "unknown discovery failure"] += 1
    for record in programs:
        if not (record["baseline_compile"] and record["baseline_compile"]["ok"]):
            failure_reasons[summarize_failure_reason(record["baseline_compile"])] += 1
            continue
        if not (record["v5_compile"] and record["v5_compile"]["ok"]):
            failure_reasons[summarize_failure_reason(record["v5_compile"])] += 1
            continue
        v5_compile_recompile = ((record["v5_compile"] or {}).get("sample") or {}).get("recompile") or {}
        if v5_compile_recompile.get("requested") and not v5_compile_recompile.get("applied") and v5_compile_recompile.get("error"):
            recompile_failures[str(v5_compile_recompile["error"])] += 1
        if record["perf_capable"] and record["baseline_run"] and not record["baseline_run"]["ok"]:
            failure_reasons[summarize_failure_reason(record["baseline_run"])] += 1
            continue
        if record["perf_capable"] and record["v5_run"] and not record["v5_run"]["ok"]:
            failure_reasons[summarize_failure_reason(record["v5_run"])] += 1

    return {
        "objects_attempted": len(objects),
        "objects_discovered": sum(1 for record in objects if record["discovery"]["ok"]),
        "objects_with_discovery_failures": len(discovery_failures),
        "programs_attempted": len(programs),
        "perf_capable_targets": sum(1 for record in programs if record["perf_capable"]),
        "compile_only_targets": sum(1 for record in programs if not record["perf_capable"]),
        "baseline_compile_successes": sum(1 for record in programs if record["baseline_compile"] and record["baseline_compile"]["ok"]),
        "v5_compile_successes": sum(1 for record in programs if record["v5_compile"] and record["v5_compile"]["ok"]),
        "scanner_successes": sum(1 for record in programs if record["scanner_cli"] and record["scanner_cli"]["ok"]),
        "framework_detected_programs": len(framework_detected),
        "framework_recompile_applied_programs": len(recompile_applied),
        "framework_recompile_failures": sum(recompile_failures.values()),
        "compile_pairs": len(compile_pairs),
        "measured_pairs": len(measured_pairs),
        "speedup_geomean": geomean([value for value in speedups if value is not None]),
        "speedup_median": statistics.median(speedups) if speedups else None,
        "speedup_min": min(speedups) if speedups else None,
        "speedup_max": max(speedups) if speedups else None,
        "code_size_ratio_geomean": geomean([value for value in size_ratios if value is not None]),
        "code_size_delta_median_pct": statistics.median(size_deltas) if size_deltas else None,
        "code_size_delta_min_pct": min(size_deltas) if size_deltas else None,
        "code_size_delta_max_pct": max(size_deltas) if size_deltas else None,
        "family_totals": dict(family_totals),
        "failure_reasons": dict(failure_reasons.most_common(16)),
        "recompile_failure_reasons": dict(recompile_failures.most_common(16)),
    }


def build_markdown(data: dict[str, Any]) -> str:
    summary = data["summary"]
    objects = sorted(data["objects"], key=lambda item: item["object_path"])
    programs = sorted(data["programs"], key=lambda item: (item["object_path"], item["program_name"]))
    measured_rows = [
        record
        for record in programs
        if record["baseline_run"] and record["baseline_run"]["ok"]
        and record["v5_run"] and record["v5_run"]["ok"]
    ]
    discovery_failures = [record for record in objects if not record["discovery"]["ok"]]
    kernel_tree_display = display_path(Path(data["kernel_tree"]))
    kernel_btf_display = display_path(Path(data["kernel_tree"]) / "vmlinux")

    lines: list[str] = [
        "# Production Corpus v5 Results",
        "",
        f"- Generated: {data['generated_at']}",
        f"- Repo root: `{data['repo_root']}`",
        f"- Kernel release: `{data['kernel_release']}`",
        f"- Kernel tree: `{data['kernel_tree']}`",
        f"- Kernel branch: `{data['kernel_branch']}`",
        f"- Kernel commit: `{data['kernel_commit']}`",
        f"- Runner: `{data['runner_binary']}`",
        f"- Scanner: `{data['scanner_binary']}`",
        "- BTF candidates: "
        + ", ".join(f"`{item}`" for item in data["btf_candidates"]),
        f"- Repeat: {data['repeat']}",
        "",
        "## Summary",
        "",
    ]
    lines.extend(
        markdown_table(
            ["Metric", "Value"],
            [
                ["Objects attempted", summary["objects_attempted"]],
                ["Objects discovered via libbpf", summary["objects_discovered"]],
                ["Objects with discovery failures", summary["objects_with_discovery_failures"]],
                ["Programs attempted", summary["programs_attempted"]],
                ["Perf-capable targets", summary["perf_capable_targets"]],
                ["Compile-only targets", summary["compile_only_targets"]],
                ["Baseline compile successes", summary["baseline_compile_successes"]],
                ["v5 compile successes", summary["v5_compile_successes"]],
                ["Scanner successes", summary["scanner_successes"]],
                ["Programs with framework-detected sites", summary["framework_detected_programs"]],
                ["Programs with recompile applied", summary["framework_recompile_applied_programs"]],
                ["Programs with recompile syscall failures", summary["framework_recompile_failures"]],
                ["Compile-only size pairs", summary["compile_pairs"]],
                ["Measured runtime pairs", summary["measured_pairs"]],
                ["Speedup geomean", format_ratio(summary["speedup_geomean"])],
                ["Speedup median", format_ratio(summary["speedup_median"])],
                ["Speedup min", format_ratio(summary["speedup_min"])],
                ["Speedup max", format_ratio(summary["speedup_max"])],
                ["Code-size ratio geomean (baseline/v5)", format_ratio(summary["code_size_ratio_geomean"])],
                ["Code-size median delta", format_pct(summary["code_size_delta_median_pct"])],
                ["Code-size min delta", format_pct(summary["code_size_delta_min_pct"])],
                ["Code-size max delta", format_pct(summary["code_size_delta_max_pct"])],
                *[
                    [f"Framework {label} sites", summary["family_totals"].get(field, 0)]
                    for label, field in FAMILY_FIELDS
                ],
            ],
        )
    )

    lines.extend(["", "## Objects", ""])
    object_rows: list[list[Any]] = []
    for record in objects:
        discovered_programs = len(record["discovery"]["programs"])
        tested_programs = sum(1 for program in programs if program["object_path"] == record["object_path"])
        compile_successes = sum(
            1
            for program in programs
            if program["object_path"] == record["object_path"]
            and program["baseline_compile"]
            and program["baseline_compile"]["ok"]
        )
        measured = sum(
            1
            for program in programs
            if program["object_path"] == record["object_path"]
            and program["baseline_run"]
            and program["baseline_run"]["ok"]
            and program["v5_run"]
            and program["v5_run"]["ok"]
        )
        object_rows.append(
            [
                record["object_path"],
                record["source"],
                "yes" if record["discovery"]["ok"] else "no",
                discovered_programs,
                tested_programs,
                compile_successes,
                measured,
                record["discovery"]["error"] or "",
            ]
        )
    lines.extend(
        markdown_table(
            ["Object", "Source", "Discovery", "Discovered Programs", "Tested Programs", "Compile Successes", "Measured", "Note"],
            object_rows,
        )
    )

    lines.extend(["", "## Per-Program Results", ""])
    program_rows: list[list[Any]] = []
    for record in programs:
        baseline_sample = (record["baseline_compile"] or {}).get("sample") or {}
        v5_sample = (record["v5_compile"] or {}).get("sample") or {}
        scanner_counts = record["scanner_counts"]
        recompile = v5_sample.get("recompile") or {}
        note = (
            summarize_failure_reason(record["v5_compile"])
            if not (record["v5_compile"] and record["v5_compile"]["ok"])
            else (str(recompile.get("error")) if recompile.get("error") else "")
        )
        program_rows.append(
            [
                f"{record['object_path']}:{record['program_name']}",
                record["section_name"],
                "yes" if record["perf_capable"] else "no",
                "yes" if record["baseline_compile"] and record["baseline_compile"]["ok"] else "no",
                "yes" if record["v5_compile"] and record["v5_compile"]["ok"] else "no",
                *[scanner_counts.get(field, 0) for _, field in FAMILY_FIELDS],
                "yes" if record["v5_compile_applied"] or record["v5_run_applied"] else "no",
                baseline_sample.get("jited_prog_len", "n/a"),
                v5_sample.get("jited_prog_len", "n/a"),
                format_pct(record["size_delta_pct"]),
                note,
            ]
        )
    lines.extend(
        markdown_table(
            [
                "Program",
                "Section",
                "Perf-capable",
                "Baseline Load",
                "v5 Load",
                *[label for label, _ in FAMILY_FIELDS],
                "Applied",
                "Baseline JIT Bytes",
                "v5 JIT Bytes",
                "Code Delta",
                "Note",
            ],
            program_rows,
        )
    )

    if measured_rows:
        lines.extend(["", "## Runtime Comparison", ""])
        runtime_rows = [
            [
                f"{record['object_path']}:{record['program_name']}",
                record["section_name"],
                format_ns(((record["baseline_run"] or {}).get("sample") or {}).get("exec_ns")),
                format_ns(((record["v5_run"] or {}).get("sample") or {}).get("exec_ns")),
                format_ratio(record["speedup_ratio"]),
                ((record["baseline_run"] or {}).get("sample") or {}).get("jited_prog_len", "n/a"),
                ((record["v5_run"] or {}).get("sample") or {}).get("jited_prog_len", "n/a"),
            ]
            for record in measured_rows
        ]
        lines.extend(
            markdown_table(
                ["Program", "Section", "Baseline ns", "v5 ns", "Speedup", "Baseline JIT Bytes", "v5 JIT Bytes"],
                runtime_rows,
            )
        )

    if discovery_failures:
        lines.extend(["", "## Discovery Failures", ""])
        lines.extend(
            markdown_table(
                [
                    "Object",
                    "Error",
                    *[f"Fallback {label}" for label, _ in FALLBACK_SECTION_FIELDS],
                    "Exec Sections",
                ],
                [
                    [
                        record["object_path"],
                        record["discovery"]["error"] or "unknown",
                        *[
                            record["discovery"]["fallback_totals"].get(field, 0)
                            for _, field in FALLBACK_SECTION_FIELDS
                        ],
                        record["discovery"]["fallback_totals"]["exec_section_count"],
                    ]
                    for record in discovery_failures
                ],
            )
        )
        for record in discovery_failures:
            lines.extend(
                [
                    "",
                    f"### {record['object_path']}",
                    "",
                ]
            )
            section_rows = [
                [
                    section["name"],
                    section["insn_count"],
                    *[section.get(field, 0) for _, field in FALLBACK_SECTION_FIELDS],
                    section["total"],
                ]
                for section in record["discovery"]["fallback_section_scan"]
                if section["total"] > 0
            ]
            if not section_rows:
                section_rows = [
                    [
                        section["name"],
                        section["insn_count"],
                        *[section.get(field, 0) for _, field in FALLBACK_SECTION_FIELDS],
                        section["total"],
                    ]
                    for section in record["discovery"]["fallback_section_scan"]
                ]
            lines.extend(
                markdown_table(
                    ["Section", "Insns", *[label for label, _ in FALLBACK_SECTION_FIELDS], "Total"],
                    section_rows,
                )
            )

    if summary["failure_reasons"]:
        lines.extend(["", "## Top Failure Reasons", ""])
        lines.extend(
            markdown_table(
                ["Reason", "Count"],
                [[reason, count] for reason, count in summary["failure_reasons"].items()],
            )
        )

    if summary["recompile_failure_reasons"]:
        lines.extend(["", "## Recompile Failures", ""])
        lines.extend(
            markdown_table(
                ["Reason", "Count"],
                [[reason, count] for reason, count in summary["recompile_failure_reasons"].items()],
            )
        )

    lines.extend(
        [
            "",
            "## Notes",
            "",
            f"- These results were collected inside the guest booted from `{kernel_tree_display}`.",
            "- Site counts come from the scanner CLI run on dumped post-verifier xlated bytecode. When that scan fails, the report falls back to the runner's `directive_scan` summary.",
            f"- The harness tries `/sys/kernel/btf/vmlinux` first and retries with the shared build-tree `{kernel_btf_display}` only for BTF/CO-RE-looking failures.",
            "- Objects that libbpf could not enumerate are still included through compile-time section census fallback so their directive-bearing sections are documented.",
        ]
    )
    return "\n".join(lines) + "\n"


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    runner = Path(args.runner).resolve()
    scanner = Path(args.scanner).resolve()
    packet_path = materialize_dummy_packet(DEFAULT_PACKET_PATH)
    context_path = materialize_dummy_context(DEFAULT_CONTEXT_PATH)

    if not runner.exists():
        raise SystemExit(f"runner not found: {runner}")
    if not scanner.exists():
        raise SystemExit(f"scanner not found: {scanner}")

    object_paths = collect_object_paths(args.filters, args.max_objects)
    objects: list[dict[str, Any]] = []
    programs: list[dict[str, Any]] = []

    for object_path in object_paths:
        relpath = object_path.relative_to(ROOT_DIR).as_posix()
        source = infer_source(relpath)

        discovery = discover_programs(runner, object_path, args.timeout)
        object_record = {
            "object_path": relpath,
            "source": source,
            "discovery": discovery,
        }
        objects.append(object_record)

        if not discovery["ok"]:
            continue

        for program in discovery["programs"]:
            program_name = str(program.get("name") or "")
            if args.filters:
                haystacks = [relpath.lower(), program_name.lower()]
                lowered = [item.lower() for item in args.filters]
                if not any(any(needle in haystack for haystack in haystacks) for needle in lowered):
                    continue

            target = {
                "object_path": relpath,
                "source": source,
                "program_name": program_name,
                "section_name": str(program.get("section_name") or ""),
                "insn_count": int(program.get("insn_count") or 0),
                "perf_capable": is_perf_capable(str(program.get("section_name") or "")),
            }
            programs.append(run_target(runner, scanner, packet_path, context_path, target, args.repeat, args.timeout))
            if args.max_programs is not None and len(programs) >= args.max_programs:
                break
        if args.max_programs is not None and len(programs) >= args.max_programs:
            break

    metadata = detect_kernel_metadata(DEFAULT_KERNEL_TREE)
    result = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "repo_root": str(ROOT_DIR),
        "runner_binary": str(runner),
        "scanner_binary": str(scanner),
        "btf_candidates": [str(path) for path in DEFAULT_BTF_CANDIDATES if path.exists()],
        "repeat": args.repeat,
        **metadata,
        "objects": objects,
        "programs": programs,
    }
    result["summary"] = build_summary(programs, objects)

    output_json = Path(args.output_json)
    output_md = Path(args.output_md)
    ensure_parent(output_json)
    ensure_parent(output_md)
    output_json.write_text(json.dumps(result, indent=2) + "\n")
    output_md.write_text(build_markdown(result))
    print(f"Wrote {output_json}")
    print(f"Wrote {output_md}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
