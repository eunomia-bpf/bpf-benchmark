#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import os
import shlex
import statistics
import subprocess
import sys
import tempfile
from collections import Counter, defaultdict
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

try:
    from results_layout import authoritative_output_path, smoke_output_path
except ImportError:
    from corpus.results_layout import authoritative_output_path, smoke_output_path

try:
    from orchestrator.inventory import load_packet_test_run_targets
    from orchestrator.results import normalize_directive_scan, parse_json_lines as parse_json_payload_lines, parse_runner_sample
except ImportError:
    from micro.orchestrator.inventory import load_packet_test_run_targets
    from micro.orchestrator.results import normalize_directive_scan, parse_json_lines as parse_json_payload_lines, parse_runner_sample

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
        format_ns,
        format_pct,
        format_ratio,
        geomean,
        markdown_table,
        normalize_directive_scan as shared_normalize_directive_scan,
        parse_scanner_v5_output,
        relpath as shared_relpath,
        require_minimum,
        run_command as shared_run_command,
        run_text_command as shared_run_text_command,
        summarize_text,
        text_invocation_summary,
        write_json_output,
    )
    from policy_utils import POLICY_DIR as DEFAULT_POLICY_DIR, resolve_policy_path
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
        format_ns,
        format_pct,
        format_ratio,
        geomean,
        markdown_table,
        normalize_directive_scan as shared_normalize_directive_scan,
        parse_scanner_v5_output,
        relpath as shared_relpath,
        require_minimum,
        run_command as shared_run_command,
        run_text_command as shared_run_text_command,
        summarize_text,
        text_invocation_summary,
        write_json_output,
    )
    from corpus.policy_utils import POLICY_DIR as DEFAULT_POLICY_DIR, resolve_policy_path


ROOT_DIR = Path(__file__).resolve().parent.parent
SELF_RELATIVE = Path(__file__).resolve().relative_to(ROOT_DIR)
DEFAULT_INVENTORY_JSON = ROOT_DIR / "docs" / "tmp" / "corpus-runnability-results.json"
DEFAULT_OUTPUT_JSON = authoritative_output_path(ROOT_DIR / "corpus" / "results", "corpus_v5_vm_batch")
DEFAULT_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "corpus-batch-recompile-results.md"
DEFAULT_RUNNER = ROOT_DIR / "micro" / "build" / "runner" / "micro_exec"
DEFAULT_SCANNER = ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"
DEFAULT_KERNEL_TREE = ROOT_DIR / "vendor" / "linux-framework"
DEFAULT_KERNEL_IMAGE = DEFAULT_KERNEL_TREE / "arch" / "x86" / "boot" / "bzImage"
DEFAULT_BTF_PATH = DEFAULT_KERNEL_TREE / "vmlinux"
DEFAULT_HOST_BTF_PATH = Path("/sys/kernel/btf/vmlinux")
DEFAULT_VNG = "vng"
DEFAULT_VNG_MEMORY = "4G"
DEFAULT_VNG_CPUS = "2"
DEFAULT_REPEAT = 200
DEFAULT_TIMEOUT_SECONDS = 240
DEFAULT_BUILD_TIMEOUT_SECONDS = 3600

FAMILY_FIELDS = (
    ("cmov", "cmov_sites"),
    ("wide", "wide_sites"),
    ("rotate", "rotate_sites"),
    ("lea", "lea_sites"),
    ("extract", "bitfield_sites"),
    ("zero-ext", "zero_ext_sites"),
    ("endian", "endian_sites"),
    ("branch-flip", "branch_flip_sites"),
)
FAMILY_DISPLAY_NAMES = {
    "cmov": "CMOV",
    "wide": "WIDE",
    "rotate": "ROTATE",
    "lea": "LEA",
    "extract": "EXTRACT",
    "zero-ext": "ZERO-EXT",
    "endian": "ENDIAN",
    "branch-flip": "BRANCH-FLIP",
}


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Run the inventory-derived packet-test-run corpus v5 recompile batch on "
            "the framework kernel guest, with automatic host compile-only fallback."
        )
    )
    parser.add_argument(
        "--inventory-json",
        default=str(DEFAULT_INVENTORY_JSON),
        help="Inventory JSON used to select the paired packet-test-run targets.",
    )
    add_output_json_argument(parser, DEFAULT_OUTPUT_JSON)
    add_output_md_argument(parser, DEFAULT_OUTPUT_MD)
    add_runner_argument(parser, DEFAULT_RUNNER, help_text="Path to micro_exec.")
    add_scanner_argument(parser, DEFAULT_SCANNER, help_text="Path to bpf-jit-scanner.")
    parser.add_argument(
        "--kernel-tree",
        default=str(DEFAULT_KERNEL_TREE),
        help="Framework kernel tree used for `make bzImage`.",
    )
    parser.add_argument(
        "--kernel-image",
        default=str(DEFAULT_KERNEL_IMAGE),
        help="Kernel image passed to vng --run.",
    )
    parser.add_argument(
        "--btf-custom-path",
        default=str(DEFAULT_BTF_PATH),
        help="BTF path passed to guest micro_exec invocations.",
    )
    parser.add_argument(
        "--vng",
        default=DEFAULT_VNG,
        help="vng executable to use for strict guest runs.",
    )
    add_repeat_argument(parser, DEFAULT_REPEAT, help_text="Repeat count passed to each micro_exec invocation.")
    add_timeout_argument(parser, DEFAULT_TIMEOUT_SECONDS, help_text="Per-target timeout in seconds.")
    parser.add_argument(
        "--build-timeout",
        type=int,
        default=DEFAULT_BUILD_TIMEOUT_SECONDS,
        help="Kernel build timeout in seconds.",
    )
    add_filter_argument(
        parser,
        help_text="Only include targets whose object path, program name, or source contains this substring. Repeatable.",
    )
    add_max_programs_argument(parser, help_text="Optional cap for smoke testing.")
    parser.add_argument(
        "--skip-build",
        action="store_true",
        help="Skip `make -C vendor/linux-framework bzImage` and use the existing image.",
    )
    parser.add_argument(
        "--skip-families",
        action="append",
        help="Comma-separated recompile families to skip from the auto-generated v5 policy blob. Supported: cmov, wide, rotate, lea, extract, zero-ext, endian, branch-flip.",
    )
    parser.add_argument(
        "--blind-apply",
        action="store_true",
        help="Ignore per-program policies and force blind all-apply auto-scan recompile for debugging.",
    )
    parser.add_argument(
        "--force-host-fallback",
        action="store_true",
        help="Skip VM execution and run host compile-only + scanner fallback directly.",
    )
    parser.add_argument(
        "--use-policy",
        action="store_true",
        help="Prefer per-program version 3 policy files under corpus/policies/ when present; otherwise keep stock JIT.",
    )
    parser.add_argument(
        "--policy-dir",
        default=str(DEFAULT_POLICY_DIR),
        help="Policy directory searched when --use-policy is enabled.",
    )
    parser.add_argument(
        "--guest-info",
        action="store_true",
        help=argparse.SUPPRESS,
    )
    parser.add_argument(
        "--guest-target-json",
        help=argparse.SUPPRESS,
    )
    return parser.parse_args(argv)


def relpath(path: Path | str) -> str:
    return shared_relpath(path, ROOT_DIR)


def zero_scan() -> dict[str, int]:
    return {
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
        "bitfield_sites": 0,
        "zero_ext_sites": 0,
        "endian_sites": 0,
        "branch_flip_sites": 0,
        "total_sites": 0,
    }


def canonical_family_name(value: str) -> str:
    normalized = value.strip().lower().replace("_", "-")
    mapping = {
        "cmov": "cmov",
        "cond-select": "cmov",
        "wide": "wide",
        "wide-mem": "wide",
        "wide-load": "wide",
        "rotate": "rotate",
        "lea": "lea",
        "addr-calc": "lea",
        "addrcalc": "lea",
        "extract": "extract",
        "bitfield": "extract",
        "bitfield-extract": "extract",
        "bit-extract": "extract",
        "zero-ext": "zero-ext",
        "zeroext": "zero-ext",
        "zero-ext-elide": "zero-ext",
        "zext": "zero-ext",
        "endian": "endian",
        "endian-fusion": "endian",
        "branch-flip": "branch-flip",
        "branchflip": "branch-flip",
        "bflip": "branch-flip",
    }
    if normalized not in mapping:
        raise SystemExit(
            f"unsupported family in --skip-families: {value} "
            "(expected cmov, wide, rotate, lea, extract, zero-ext, endian, or branch-flip)"
        )
    return mapping[normalized]


def normalize_skip_families(values: list[str] | None) -> list[str]:
    normalized: list[str] = []
    seen: set[str] = set()
    for raw in values or []:
        for item in raw.split(","):
            if not item.strip():
                continue
            family = canonical_family_name(item)
            if family not in seen:
                seen.add(family)
                normalized.append(family)
    return normalized


def normalize_scan(scan: dict[str, Any] | None) -> dict[str, int]:
    return shared_normalize_directive_scan(scan)


def families_from_scan(scan: dict[str, Any] | None) -> list[str]:
    normalized = normalize_scan(scan)
    return [name for name, field in FAMILY_FIELDS if normalized[field] > 0]


def parse_json_lines(stdout: str) -> list[dict[str, Any]]:
    return [payload for payload in parse_json_payload_lines(stdout) if isinstance(payload, dict)]


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
        "stderr_tail": summarize_text(result["stderr"]),
        "stdout_tail": summarize_text(result["stdout"]),
        "sample": result.get("sample"),
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
        "stderr_tail": summarize_text(result["stderr"]),
        "stdout_tail": summarize_text(result["stdout"]),
    }


def build_runner_command(
    *,
    runner: Path,
    object_path: Path,
    program_name: str,
    io_mode: str,
    memory_path: Path | None,
    input_size: int,
    repeat: int,
    btf_custom_path: Path | None,
    compile_only: bool,
    recompile_v5: bool,
    skip_families: list[str],
    recompile_all: bool = False,
    policy_file: Path | None = None,
    dump_xlated: Path | None = None,
    use_sudo: bool = False,
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
        recompile_all=recompile_all,
        skip_families=skip_families,
        policy_file=policy_file,
        dump_xlated=dump_xlated,
        btf_custom_path=btf_custom_path,
        use_sudo=use_sudo,
    )


def size_ratio(
    baseline_record: dict[str, Any] | None,
    v5_record: dict[str, Any] | None,
) -> float | None:
    if not baseline_record or not v5_record:
        return None
    if not baseline_record.get("ok") or not v5_record.get("ok"):
        return None
    baseline_len = ((baseline_record.get("sample") or {}).get("jited_prog_len"))
    v5_len = ((v5_record.get("sample") or {}).get("jited_prog_len"))
    if not baseline_len or not v5_len:
        return None
    return float(baseline_len) / float(v5_len)


def size_delta_pct(
    baseline_record: dict[str, Any] | None,
    v5_record: dict[str, Any] | None,
) -> float | None:
    ratio = size_ratio(baseline_record, v5_record)
    if ratio is None:
        return None
    baseline_len = ((baseline_record.get("sample") or {}).get("jited_prog_len"))
    v5_len = ((v5_record.get("sample") or {}).get("jited_prog_len"))
    if baseline_len in (None, 0) or v5_len is None:
        return None
    return (float(v5_len) - float(baseline_len)) * 100.0 / float(baseline_len)


def speedup_ratio(
    baseline_record: dict[str, Any] | None,
    v5_record: dict[str, Any] | None,
) -> float | None:
    if not baseline_record or not v5_record:
        return None
    if not baseline_record.get("ok") or not v5_record.get("ok"):
        return None
    baseline_ns = ((baseline_record.get("sample") or {}).get("exec_ns"))
    v5_ns = ((v5_record.get("sample") or {}).get("exec_ns"))
    if not baseline_ns or not v5_ns:
        return None
    return float(baseline_ns) / float(v5_ns)


def summarize_failure_reason(record: dict[str, Any] | None) -> str:
    if not record:
        return "n/a"
    error = record.get("error")
    if error:
        return str(error)
    sample = record.get("sample") or {}
    recompile = sample.get("recompile") or {}
    if recompile.get("error"):
        return str(recompile["error"])
    return "unknown"


def program_label(record: dict[str, Any]) -> str:
    return f"{record['object_path']}:{record['program_name']}"


def recompile_metadata(record: dict[str, Any] | None) -> dict[str, Any]:
    if not record or not record.get("ok"):
        return {}
    return ((record.get("sample") or {}).get("recompile") or {})


def effective_applied_families(
    requested_families: list[str],
    eligible_families: list[str],
    applied: bool,
) -> list[str]:
    if not applied:
        return []
    if not requested_families:
        return list(eligible_families)
    eligible_set = set(eligible_families)
    return [family for family in requested_families if family in eligible_set]


def build_empty_record(target: dict[str, Any], execution_mode: str) -> dict[str, Any]:
    return {
        **target,
        "execution_mode": execution_mode,
        "policy_path": target.get("policy_path"),
        "policy_mode": str(target.get("policy_mode", "stock")),
        "scan_source": "inventory",
        "scanner_counts": normalize_scan(target.get("inventory_scan")),
        "scanner_cli": None,
        "baseline_compile": None,
        "v5_compile": None,
        "baseline_run": None,
        "v5_run": None,
        "v5_compile_applied": False,
        "v5_run_applied": False,
        "eligible_families": families_from_scan(target.get("inventory_scan")),
        "requested_families_compile": [],
        "requested_families_run": [],
        "applied_families_compile": [],
        "applied_families_run": [],
        "size_ratio": None,
        "size_delta_pct": None,
        "speedup_ratio": None,
        "record_error": None,
        "guest_invocation": None,
    }


def run_target_locally(
    *,
    target: dict[str, Any],
    runner: Path,
    scanner: Path,
    repeat: int,
    timeout_seconds: int,
    execution_mode: str,
    btf_custom_path: Path | None,
    use_sudo: bool,
    enable_recompile: bool,
    enable_exec: bool,
    skip_families: list[str],
    use_policy: bool,
    blind_apply: bool,
    policy_dir: Path,
) -> dict[str, Any]:
    record = build_empty_record(target, execution_mode)
    object_path = ROOT_DIR / target["object_path"]
    memory_path = Path(target["memory_path"]) if target.get("memory_path") else None
    policy_path = resolve_policy_path(
        object_path,
        policy_dir,
        program_name=target["program_name"],
    ) if use_policy else None
    active_policy_path = None if blind_apply else policy_path
    recompile_v5 = blind_apply
    recompile_all = blind_apply
    policy_mode = "blind-apply-v5" if blind_apply else ("policy-file" if active_policy_path is not None else "stock")
    inventory_scan = normalize_scan(target.get("inventory_scan"))
    scanner_result = None
    scan_source = "inventory"
    scanner_counts = inventory_scan

    with tempfile.TemporaryDirectory(prefix="corpus-v5-batch-", dir=ROOT_DIR) as tmpdir:
        xlated_path = Path(tmpdir) / "program.xlated"
        baseline_compile_raw = run_command(
            build_runner_command(
                runner=runner,
                object_path=object_path,
                program_name=target["program_name"],
                io_mode=target["io_mode"],
                memory_path=memory_path,
                input_size=int(target["input_size"]),
                repeat=repeat,
                btf_custom_path=btf_custom_path,
                compile_only=True,
                recompile_v5=False,
                recompile_all=False,
                skip_families=[],
                policy_file=None,
                dump_xlated=xlated_path,
                use_sudo=use_sudo,
            ),
            timeout_seconds,
        )
        if baseline_compile_raw["ok"] and scanner.exists() and xlated_path.exists():
            scanner_result = run_text_command(build_scanner_command(scanner, xlated_path), timeout_seconds)
            if scanner_result["ok"]:
                try:
                    scanner_counts = parse_scanner_v5_output(scanner_result["stdout"])
                    scan_source = f"{execution_mode}_scanner"
                except Exception as exc:
                    scanner_result["ok"] = False
                    scanner_result["error"] = str(exc)
        elif baseline_compile_raw["ok"]:
            baseline_scan = directive_scan_from_record(baseline_compile_raw)
            if baseline_scan["total_sites"] > 0:
                scanner_counts = baseline_scan
                scan_source = f"{execution_mode}_runner_scan"

        v5_compile_raw = None
        baseline_run_raw = None
        v5_run_raw = None
        if enable_recompile:
            v5_compile_raw = run_command(
                build_runner_command(
                    runner=runner,
                    object_path=object_path,
                    program_name=target["program_name"],
                    io_mode=target["io_mode"],
                    memory_path=memory_path,
                    input_size=int(target["input_size"]),
                    repeat=repeat,
                    btf_custom_path=btf_custom_path,
                    compile_only=True,
                    recompile_v5=recompile_v5,
                    recompile_all=recompile_all,
                    skip_families=skip_families,
                    policy_file=active_policy_path,
                    use_sudo=use_sudo,
                ),
                timeout_seconds,
            )
        if enable_exec and target.get("can_test_run") and baseline_compile_raw["ok"]:
            baseline_run_raw = run_command(
                build_runner_command(
                    runner=runner,
                    object_path=object_path,
                    program_name=target["program_name"],
                    io_mode=target["io_mode"],
                    memory_path=memory_path,
                    input_size=int(target["input_size"]),
                    repeat=repeat,
                    btf_custom_path=btf_custom_path,
                    compile_only=False,
                    recompile_v5=False,
                    recompile_all=False,
                    skip_families=[],
                    policy_file=None,
                    use_sudo=use_sudo,
                ),
                timeout_seconds,
            )
        if enable_exec and enable_recompile and target.get("can_test_run") and v5_compile_raw and v5_compile_raw["ok"]:
            v5_run_raw = run_command(
                build_runner_command(
                    runner=runner,
                    object_path=object_path,
                    program_name=target["program_name"],
                    io_mode=target["io_mode"],
                    memory_path=memory_path,
                    input_size=int(target["input_size"]),
                    repeat=repeat,
                    btf_custom_path=btf_custom_path,
                    compile_only=False,
                    recompile_v5=recompile_v5,
                    recompile_all=recompile_all,
                    skip_families=skip_families,
                    policy_file=active_policy_path,
                    use_sudo=use_sudo,
                ),
                timeout_seconds,
            )

    record["scanner_cli"] = text_invocation_summary(scanner_result)
    record["policy_path"] = str(active_policy_path) if active_policy_path is not None else None
    record["policy_mode"] = policy_mode
    record["scan_source"] = scan_source
    record["scanner_counts"] = scanner_counts
    record["eligible_families"] = families_from_scan(scanner_counts)
    record["baseline_compile"] = invocation_summary(baseline_compile_raw)
    record["v5_compile"] = invocation_summary(v5_compile_raw)
    record["baseline_run"] = invocation_summary(baseline_run_raw)
    record["v5_run"] = invocation_summary(v5_run_raw)
    record["v5_compile_applied"] = bool((((record["v5_compile"] or {}).get("sample") or {}).get("recompile") or {}).get("applied"))
    record["v5_run_applied"] = bool((((record["v5_run"] or {}).get("sample") or {}).get("recompile") or {}).get("applied"))
    record["requested_families_compile"] = list(recompile_metadata(record["v5_compile"]).get("requested_families") or [])
    record["requested_families_run"] = list(recompile_metadata(record["v5_run"]).get("requested_families") or [])
    record["applied_families_compile"] = effective_applied_families(
        record["requested_families_compile"],
        record["eligible_families"],
        record["v5_compile_applied"],
    )
    record["applied_families_run"] = effective_applied_families(
        record["requested_families_run"],
        record["eligible_families"],
        record["v5_run_applied"],
    )
    record["size_ratio"] = size_ratio(record["baseline_compile"], record["v5_compile"])
    record["size_delta_pct"] = size_delta_pct(record["baseline_compile"], record["v5_compile"])
    record["speedup_ratio"] = speedup_ratio(record["baseline_run"], record["v5_run"])
    return record


def guest_info_payload() -> dict[str, Any]:
    return {
        "kind": "guest_info",
        "kernel_release": subprocess.run(
            ["uname", "-r"],
            cwd=ROOT_DIR,
            capture_output=True,
            text=True,
            check=False,
        ).stdout.strip(),
        "cwd": str(Path.cwd()),
        "runner_exists": DEFAULT_RUNNER.exists(),
        "btf_exists": DEFAULT_BTF_PATH.exists(),
        "uid": os.geteuid(),
    }


def run_guest_info_mode() -> int:
    print(json.dumps(guest_info_payload(), sort_keys=True))
    return 0


def run_guest_target_mode(args: argparse.Namespace) -> int:
    target_path = Path(args.guest_target_json).resolve()
    target = json.loads(target_path.read_text())
    runner = Path(args.runner).resolve()
    scanner = Path(args.scanner).resolve()
    btf_custom_path = Path(args.btf_custom_path).resolve() if args.btf_custom_path else None
    policy_dir = Path(args.policy_dir).resolve()
    record = run_target_locally(
        target=target,
        runner=runner,
        scanner=scanner,
        repeat=args.repeat,
        timeout_seconds=args.timeout,
        execution_mode="vm",
        btf_custom_path=btf_custom_path,
        use_sudo=False,
        enable_recompile=True,
        enable_exec=bool(target.get("can_test_run")),
        skip_families=normalize_skip_families(args.skip_families),
        use_policy=args.use_policy,
        blind_apply=args.blind_apply,
        policy_dir=policy_dir,
    )
    print(json.dumps(record, sort_keys=True))
    return 0


def build_vng_command(*, vng_binary: str, kernel_image: Path, guest_exec: str) -> list[str]:
    return [
        vng_binary,
        "--run",
        str(kernel_image),
        "--cwd",
        str(ROOT_DIR),
        "--disable-monitor",
        "--memory",
        DEFAULT_VNG_MEMORY,
        "--cpus",
        DEFAULT_VNG_CPUS,
        "--exec",
        guest_exec,
    ]


def build_guest_exec(argv: list[str]) -> str:
    return " ".join(shlex.quote(part) for part in argv)


def load_targets(
    inventory_json: Path,
    filters: list[str] | None,
    max_programs: int | None,
) -> tuple[list[dict[str, Any]], dict[str, Any]]:
    return load_packet_test_run_targets(
        inventory_json,
        filters=filters,
        max_programs=max_programs,
        require_inventory_sites=False,
    )


def build_result_from_guest_run(
    *,
    target: dict[str, Any],
    invocation: dict[str, Any],
) -> dict[str, Any]:
    parsed = parse_json_lines(invocation["stdout"])
    if invocation["ok"] and parsed:
        record = parsed[-1]
        record["guest_invocation"] = text_invocation_summary(invocation)
        return record

    record = build_empty_record(target, "vm")
    record["record_error"] = invocation["error"] or "guest target failed"
    record["guest_invocation"] = text_invocation_summary(invocation)
    return record


def run_target_in_guest(
    *,
    target: dict[str, Any],
    runner: Path,
    scanner: Path,
    kernel_image: Path,
    btf_custom_path: Path,
    repeat: int,
    timeout_seconds: int,
    vng_binary: str,
    skip_families: list[str],
    use_policy: bool,
    blind_apply: bool,
    policy_dir: Path,
) -> dict[str, Any]:
    handle = tempfile.NamedTemporaryFile(
        mode="w",
        prefix="corpus-v5-vm-target-",
        suffix=".json",
        dir=ROOT_DIR,
        delete=False,
    )
    try:
        policy_path = resolve_policy_path(
            ROOT_DIR / str(target["object_path"]),
            policy_dir,
            program_name=str(target["program_name"]),
        ) if use_policy and not blind_apply else None
        guest_target = {
            **target,
            "policy_mode": "blind-apply-v5" if blind_apply else ("policy-file" if policy_path is not None else "stock"),
            "policy_path": str(policy_path) if policy_path is not None else None,
        }
        with handle:
            json.dump(guest_target, handle)
            handle.write("\n")
        target_path = Path(handle.name)
        guest_argv = [
            "python3",
            str(SELF_RELATIVE),
            "--guest-target-json",
            str(target_path),
            "--runner",
            str(runner),
            "--scanner",
            str(scanner),
            "--btf-custom-path",
            str(btf_custom_path),
            "--repeat",
            str(repeat),
            "--timeout",
            str(timeout_seconds),
            "--policy-dir",
            str(policy_dir),
        ]
        if skip_families:
            guest_argv.extend(["--skip-families", ",".join(skip_families)])
        if blind_apply:
            guest_argv.append("--blind-apply")
        if use_policy:
            guest_argv.append("--use-policy")
        guest_exec = build_guest_exec(guest_argv)
        invocation = run_text_command(
            build_vng_command(
                vng_binary=vng_binary,
                kernel_image=kernel_image,
                guest_exec=guest_exec,
            ),
            (timeout_seconds * 4) + 120,
        )
        return build_result_from_guest_run(target=target, invocation=invocation)
    finally:
        Path(handle.name).unlink(missing_ok=True)


def collect_guest_info(
    *,
    vng_binary: str,
    kernel_image: Path,
    timeout_seconds: int,
) -> dict[str, Any]:
    guest_exec = build_guest_exec(["python3", str(SELF_RELATIVE), "--guest-info"])
    invocation = run_text_command(
        build_vng_command(
            vng_binary=vng_binary,
            kernel_image=kernel_image,
            guest_exec=guest_exec,
        ),
        timeout_seconds,
    )
    payloads = parse_json_lines(invocation["stdout"])
    return {
        "invocation": text_invocation_summary(invocation),
        "payload": payloads[-1] if invocation["ok"] and payloads else None,
    }


def run_kernel_build(kernel_tree: Path, timeout_seconds: int) -> dict[str, Any]:
    jobs = os.cpu_count() or 1
    return run_text_command(
        ["make", "-C", str(kernel_tree), f"-j{jobs}", "bzImage"],
        timeout_seconds,
    )


def build_summary(records: list[dict[str, Any]], effective_mode: str, fallback_reason: str | None) -> dict[str, Any]:
    compile_pairs = [
        record
        for record in records
        if record.get("baseline_compile") and record["baseline_compile"].get("ok")
        and record.get("v5_compile") and record["v5_compile"].get("ok")
    ]
    measured_pairs = [
        record
        for record in records
        if record.get("baseline_run") and record["baseline_run"].get("ok")
        and record.get("v5_run") and record["v5_run"].get("ok")
    ]
    applied_programs = [
        record
        for record in records
        if record.get("v5_compile_applied") or record.get("v5_run_applied")
    ]
    family_totals = Counter()
    for record in records:
        scan = normalize_scan(record.get("scanner_counts"))
        for _, field in FAMILY_FIELDS:
            family_totals[field] += scan[field]

    failure_reasons = Counter()
    recompile_failures = Counter()
    for record in records:
        if record.get("record_error"):
            failure_reasons[str(record["record_error"])] += 1
            continue
        baseline_compile = record.get("baseline_compile")
        v5_compile = record.get("v5_compile")
        baseline_run = record.get("baseline_run")
        v5_run = record.get("v5_run")
        if baseline_compile and not baseline_compile.get("ok"):
            failure_reasons[summarize_failure_reason(baseline_compile)] += 1
        if v5_compile and not v5_compile.get("ok"):
            failure_reasons[summarize_failure_reason(v5_compile)] += 1
        if baseline_run and not baseline_run.get("ok"):
            failure_reasons[summarize_failure_reason(baseline_run)] += 1
        if v5_run and not v5_run.get("ok"):
            failure_reasons[summarize_failure_reason(v5_run)] += 1
        if v5_compile and v5_compile.get("ok"):
            recompile = ((v5_compile.get("sample") or {}).get("recompile") or {})
            if recompile.get("requested") and not recompile.get("applied") and recompile.get("error"):
                recompile_failures[str(recompile["error"])] += 1
        if v5_run and v5_run.get("ok"):
            recompile = ((v5_run.get("sample") or {}).get("recompile") or {})
            if recompile.get("requested") and not recompile.get("applied") and recompile.get("error"):
                recompile_failures[str(recompile["error"])] += 1

    size_ratios = [record["size_ratio"] for record in compile_pairs if record.get("size_ratio") is not None]
    exec_ratios = [record["speedup_ratio"] for record in measured_pairs if record.get("speedup_ratio") is not None]
    regressions = [record for record in measured_pairs if (record.get("speedup_ratio") or 0) < 1.0]
    improvements = [record for record in measured_pairs if (record.get("speedup_ratio") or 0) > 1.0]

    by_source: list[dict[str, Any]] = []
    grouped_sources: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for record in records:
        grouped_sources[record["source_name"]].append(record)
    for source_name, items in grouped_sources.items():
        source_compile = [item for item in items if item in compile_pairs]
        source_measured = [item for item in items if item in measured_pairs]
        source_size = [item["size_ratio"] for item in source_compile if item.get("size_ratio") is not None]
        source_exec = [item["speedup_ratio"] for item in source_measured if item.get("speedup_ratio") is not None]
        counts = Counter()
        for item in items:
            scan = normalize_scan(item.get("scanner_counts"))
            for _, field in FAMILY_FIELDS:
                counts[field] += scan[field]
        source_row = {
            "source_name": source_name,
            "programs": len(items),
            "compile_pairs": len(source_compile),
            "measured_pairs": len(source_measured),
            "applied_programs": sum(1 for item in items if item.get("v5_compile_applied") or item.get("v5_run_applied")),
            "total_sites": sum(counts[field] for _, field in FAMILY_FIELDS),
            "code_size_ratio_geomean": geomean(source_size),
            "exec_ratio_geomean": geomean(source_exec),
            "wins": sum(1 for item in source_measured if (item.get("speedup_ratio") or 0) > 1.0),
            "regressions": sum(1 for item in source_measured if (item.get("speedup_ratio") or 0) < 1.0),
        }
        for _, field in FAMILY_FIELDS:
            source_row[field] = counts[field]
        by_source.append(source_row)
    by_source.sort(key=lambda item: (-item["programs"], item["source_name"]))

    by_family: list[dict[str, Any]] = []
    for family_name, field in FAMILY_FIELDS:
        items = [record for record in records if normalize_scan(record.get("scanner_counts"))[field] > 0]
        family_compile = [item for item in items if item in compile_pairs]
        family_measured = [item for item in items if item in measured_pairs]
        family_size = [item["size_ratio"] for item in family_compile if item.get("size_ratio") is not None]
        family_exec = [item["speedup_ratio"] for item in family_measured if item.get("speedup_ratio") is not None]
        applied_items = [
            item
            for item in items
            if family_name in item.get("applied_families_compile", [])
            or family_name in item.get("applied_families_run", [])
        ]
        by_family.append(
            {
                "family_name": family_name,
                "programs": len(items),
                "compile_pairs": len(family_compile),
                "measured_pairs": len(family_measured),
                "applied_programs": len(applied_items),
                "total_sites": sum(normalize_scan(item.get("scanner_counts"))[field] for item in items),
                "applied_sites": sum(normalize_scan(item.get("scanner_counts"))[field] for item in applied_items),
                "code_size_ratio_geomean": geomean(family_size),
                "exec_ratio_geomean": geomean(family_exec),
                "wins": sum(1 for item in family_measured if (item.get("speedup_ratio") or 0) > 1.0),
                "regressions": sum(1 for item in family_measured if (item.get("speedup_ratio") or 0) < 1.0),
            }
        )
    by_family.sort(key=lambda item: (-item["total_sites"], item["family_name"]))

    top_speedups = sorted(
        improvements,
        key=lambda item: (-(item.get("speedup_ratio") or 0), item["source_name"], program_label(item)),
    )[:10]
    top_regressions = sorted(
        regressions,
        key=lambda item: ((item.get("speedup_ratio") or math.inf), item["source_name"], program_label(item)),
    )[:10]
    top_code_shrinks = sorted(
        [record for record in compile_pairs if (record.get("size_ratio") or 0) > 1.0],
        key=lambda item: (-(item.get("size_ratio") or 0), item["source_name"], program_label(item)),
    )[:10]

    return {
        "effective_mode": effective_mode,
        "fallback_reason": fallback_reason,
        "targets_attempted": len(records),
        "compile_pairs": len(compile_pairs),
        "measured_pairs": len(measured_pairs),
        "applied_programs": len(applied_programs),
        "code_size_ratio_geomean": geomean(size_ratios),
        "code_size_delta_median_pct": statistics.median([record["size_delta_pct"] for record in compile_pairs if record.get("size_delta_pct") is not None]) if compile_pairs else None,
        "exec_ratio_geomean": geomean(exec_ratios),
        "exec_ratio_median": statistics.median(exec_ratios) if exec_ratios else None,
        "exec_ratio_min": min(exec_ratios) if exec_ratios else None,
        "exec_ratio_max": max(exec_ratios) if exec_ratios else None,
        "improvements": len(improvements),
        "regressions": len(regressions),
        "family_totals": dict(family_totals),
        "failure_reasons": dict(failure_reasons.most_common(16)),
        "recompile_failure_reasons": dict(recompile_failures.most_common(16)),
        "by_source": by_source,
        "by_family": by_family,
        "top_speedups": [
            {
                "program": program_label(record),
                "source_name": record["source_name"],
                "prog_type_name": record["prog_type_name"],
                "speedup_ratio": record.get("speedup_ratio"),
                "families": record.get("applied_families_run") or record.get("eligible_families", []),
            }
            for record in top_speedups
        ],
        "top_regressions": [
            {
                "program": program_label(record),
                "source_name": record["source_name"],
                "prog_type_name": record["prog_type_name"],
                "speedup_ratio": record.get("speedup_ratio"),
                "families": record.get("applied_families_run") or record.get("eligible_families", []),
            }
            for record in top_regressions
        ],
        "top_code_shrinks": [
            {
                "program": program_label(record),
                "source_name": record["source_name"],
                "prog_type_name": record["prog_type_name"],
                "size_ratio": record.get("size_ratio"),
                "families": record.get("applied_families_compile") or record.get("eligible_families", []),
            }
            for record in top_code_shrinks
        ],
    }


def build_markdown(data: dict[str, Any]) -> str:
    summary = data["summary"]
    records = sorted(data["programs"], key=lambda item: (item["source_name"], item["object_path"], item["program_name"]))
    build_summary_data = data.get("kernel_build") or {}
    guest_info = (data.get("guest_smoke") or {}).get("payload")
    family_headers = [FAMILY_DISPLAY_NAMES[name] for name, _ in FAMILY_FIELDS]
    lines: list[str] = [
        "# Corpus Batch Recompile Results",
        "",
        f"- Generated: {data['generated_at']}",
        f"- Inventory: `{data['inventory_json']}`",
        f"- Runner: `{data['runner_binary']}`",
        f"- Scanner: `{data['scanner_binary']}`",
        f"- Requested mode: `strict-vm`",
        f"- Effective mode: `{summary['effective_mode']}`",
        f"- Repeat: {data['repeat']}",
        f"- Skip families: `{', '.join(data.get('skip_families') or []) or 'none'}`",
        f"- Target programs: {summary['targets_attempted']}",
        f"- Compile pairs: {summary['compile_pairs']}",
        f"- Measured pairs: {summary['measured_pairs']}",
        f"- Recompile applied programs: {summary['applied_programs']}",
        f"- Code-size ratio geomean (baseline/v5): {format_ratio(summary['code_size_ratio_geomean'])}",
        f"- Exec-time ratio geomean (baseline/v5): {format_ratio(summary['exec_ratio_geomean'])}",
        f"- Total sites: {sum(summary['family_totals'].get(field, 0) for _, field in FAMILY_FIELDS)}",
        *[
            f"- {FAMILY_DISPLAY_NAMES[name]} sites: {summary['family_totals'].get(field, 0)}"
            for name, field in FAMILY_FIELDS
        ],
    ]
    if summary.get("fallback_reason"):
        lines.append(f"- Fallback reason: {summary['fallback_reason']}")
    if build_summary_data:
        lines.append(
            f"- Kernel build: {'ok' if build_summary_data.get('ok') else 'failed'} "
            f"({build_summary_data.get('duration_seconds', 0):.2f}s)"
        )
    if guest_info:
        lines.append(f"- Guest kernel: `{guest_info.get('kernel_release', 'unknown')}`")
    lines.append("")

    lines.extend(["## By Project", ""])
    lines.extend(
        markdown_table(
            [
                "Project",
                "Programs",
                "Compile Pairs",
                "Measured Pairs",
                "Applied",
                *family_headers,
                "Code Ratio",
                "Exec Ratio",
                "Regressions",
            ],
            [
                [
                    row["source_name"],
                    row["programs"],
                    row["compile_pairs"],
                    row["measured_pairs"],
                    row["applied_programs"],
                    *[row[field] for _, field in FAMILY_FIELDS],
                    format_ratio(row["code_size_ratio_geomean"]),
                    format_ratio(row["exec_ratio_geomean"]),
                    row["regressions"],
                ]
                for row in summary["by_source"]
            ],
        )
    )
    lines.append("")

    lines.extend(["## By Family", ""])
    lines.extend(
        markdown_table(
            ["Family", "Programs", "Applied", "Sites", "Applied Sites", "Compile Pairs", "Measured Pairs", "Code Ratio", "Exec Ratio", "Regressions"],
            [
                [
                    row["family_name"],
                    row["programs"],
                    row["applied_programs"],
                    row["total_sites"],
                    row["applied_sites"],
                    row["compile_pairs"],
                    row["measured_pairs"],
                    format_ratio(row["code_size_ratio_geomean"]),
                    format_ratio(row["exec_ratio_geomean"]),
                    row["regressions"],
                ]
                for row in summary["by_family"]
            ],
        )
    )
    lines.append("")

    if summary["top_speedups"]:
        lines.extend(["## Top Speedups", ""])
        lines.extend(
            markdown_table(
                ["Program", "Project", "Type", "Exec Ratio", "Families"],
                [
                    [
                        row["program"],
                        row["source_name"],
                        row["prog_type_name"],
                        format_ratio(row["speedup_ratio"]),
                        ", ".join(row["families"]),
                    ]
                    for row in summary["top_speedups"]
                ],
            )
        )
        lines.append("")

    if summary["top_regressions"]:
        lines.extend(["## Regressions", ""])
        lines.extend(
            markdown_table(
                ["Program", "Project", "Type", "Exec Ratio", "Families"],
                [
                    [
                        row["program"],
                        row["source_name"],
                        row["prog_type_name"],
                        format_ratio(row["speedup_ratio"]),
                        ", ".join(row["families"]),
                    ]
                    for row in summary["top_regressions"]
                ],
            )
        )
        lines.append("")

    if summary["top_code_shrinks"]:
        lines.extend(["## Largest Code Shrinks", ""])
        lines.extend(
            markdown_table(
                ["Program", "Project", "Type", "Code Ratio", "Families"],
                [
                    [
                        row["program"],
                        row["source_name"],
                        row["prog_type_name"],
                        format_ratio(row["size_ratio"]),
                        ", ".join(row["families"]),
                    ]
                    for row in summary["top_code_shrinks"]
                ],
            )
        )
        lines.append("")

    lines.extend(["## Per-Program Results", ""])
    lines.extend(
        markdown_table(
            [
                "Program",
                "Project",
                "Type",
                "Sites",
                "Applied Families",
                "Baseline JIT",
                "v5 JIT",
                "Code Ratio",
                "Baseline ns",
                "v5 ns",
                "Exec Ratio",
                "Note",
            ],
            [
                [
                    program_label(record),
                    record["source_name"],
                    record["prog_type_name"],
                    normalize_scan(record.get("scanner_counts"))["total_sites"],
                    ", ".join(record.get("applied_families_run") or record.get("applied_families_compile") or []),
                    format_ns(((record.get("baseline_compile") or {}).get("sample") or {}).get("jited_prog_len")),
                    format_ns(((record.get("v5_compile") or {}).get("sample") or {}).get("jited_prog_len")),
                    format_ratio(record.get("size_ratio")),
                    format_ns(((record.get("baseline_run") or {}).get("sample") or {}).get("exec_ns")),
                    format_ns(((record.get("v5_run") or {}).get("sample") or {}).get("exec_ns")),
                    format_ratio(record.get("speedup_ratio")),
                    record.get("record_error")
                    or (
                        summarize_failure_reason(record.get("v5_compile"))
                        if record.get("v5_compile") and not record["v5_compile"].get("ok")
                        else ""
                    ),
                ]
                for record in records
            ],
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
            "- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current scanner pass determines whether v5 has any eligible families.",
            "- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.",
            "- Default steady-state semantics are stock: without `--use-policy` or `--blind-apply`, the v5 lane does not request recompile.",
            "- `--use-policy` only considers per-program version 3 policy files under `corpus/policies/`; if no match exists, the driver stays on stock JIT.",
            "- `--blind-apply` forces the old debug/exploration path with `--recompile-v5 --recompile-all`.",
            "- `--skip-families` only applies together with `--blind-apply`; the family columns above report applied families, not just eligible sites.",
            "- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.",
            "- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.",
        ]
    )
    return "\n".join(lines) + "\n"


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    require_minimum(args.repeat, 1, "--repeat")
    skip_families = normalize_skip_families(args.skip_families)
    if args.use_policy and args.blind_apply:
        raise SystemExit("--use-policy cannot be combined with --blind-apply")
    if skip_families and not args.blind_apply:
        raise SystemExit("--skip-families requires --blind-apply")

    if args.guest_info:
        return run_guest_info_mode()
    if args.guest_target_json:
        return run_guest_target_mode(args)

    inventory_json = Path(args.inventory_json).resolve()
    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.max_programs is not None:
        output_json = smoke_output_path(ROOT_DIR / "corpus" / "results", "corpus_v5_vm_batch")
    else:
        output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    runner = Path(args.runner).resolve()
    scanner = Path(args.scanner).resolve()
    kernel_tree = Path(args.kernel_tree).resolve()
    kernel_image = Path(args.kernel_image).resolve()
    btf_custom_path = Path(args.btf_custom_path).resolve() if args.btf_custom_path else None
    policy_dir = Path(args.policy_dir).resolve()

    if not inventory_json.exists():
        raise SystemExit(f"inventory JSON not found: {inventory_json}")
    if not runner.exists():
        raise SystemExit(f"runner not found: {runner}")
    if not scanner.exists():
        raise SystemExit(f"scanner not found: {scanner}")

    targets, inventory_summary = load_targets(
        inventory_json=inventory_json,
        filters=args.filters,
        max_programs=args.max_programs,
    )

    kernel_build = None
    guest_smoke: dict[str, Any] | None = None
    effective_mode = "vm"
    fallback_reason = None

    if args.force_host_fallback:
        effective_mode = "host-fallback"
        fallback_reason = "forced by --force-host-fallback"
    else:
        if args.skip_build:
            kernel_build = {
                "ok": kernel_image.exists(),
                "command": ["make", "-C", str(kernel_tree), f"-j{os.cpu_count() or 1}", "bzImage"],
                "returncode": 0 if kernel_image.exists() else None,
                "timed_out": False,
                "duration_seconds": 0.0,
                "stdout": "",
                "stderr": "",
                "error": None if kernel_image.exists() else "kernel image missing",
            }
        else:
            kernel_build = run_kernel_build(kernel_tree, args.build_timeout)
        if not kernel_build["ok"]:
            effective_mode = "host-fallback"
            fallback_reason = f"kernel build failed: {kernel_build['error']}"
        elif not kernel_image.exists():
            effective_mode = "host-fallback"
            fallback_reason = f"kernel image missing after build: {kernel_image}"
        elif btf_custom_path is None or not btf_custom_path.exists():
            effective_mode = "host-fallback"
            fallback_reason = f"btf path missing: {btf_custom_path}"
        else:
            guest_smoke = collect_guest_info(
                vng_binary=args.vng,
                kernel_image=kernel_image,
                timeout_seconds=args.timeout,
            )
            if not ((guest_smoke.get("invocation") or {}).get("ok") and guest_smoke.get("payload")):
                effective_mode = "host-fallback"
                smoke_error = (guest_smoke.get("invocation") or {}).get("error") or "guest smoke failed"
                fallback_reason = f"vm unavailable: {smoke_error}"

    records: list[dict[str, Any]] = []
    host_btf_path = DEFAULT_HOST_BTF_PATH if DEFAULT_HOST_BTF_PATH.exists() else None
    for index, target in enumerate(targets, start=1):
        print(
            f"[{index}/{len(targets)}] {target['source_name']} {target['object_path']}:{target['program_name']}",
            file=sys.stderr,
            flush=True,
        )
        if effective_mode == "vm":
            record = run_target_in_guest(
                target=target,
                runner=runner,
                scanner=scanner,
                kernel_image=kernel_image,
                btf_custom_path=btf_custom_path,
                repeat=args.repeat,
                timeout_seconds=args.timeout,
                vng_binary=args.vng,
                skip_families=skip_families,
                use_policy=args.use_policy,
                blind_apply=args.blind_apply,
                policy_dir=policy_dir,
            )
        else:
            record = run_target_locally(
                target=target,
                runner=runner,
                scanner=scanner,
                repeat=args.repeat,
                timeout_seconds=args.timeout,
                execution_mode="host-fallback",
                btf_custom_path=host_btf_path,
                use_sudo=True,
                enable_recompile=False,
                enable_exec=False,
                skip_families=[],
                use_policy=args.use_policy,
                blind_apply=False,
                policy_dir=policy_dir,
            )
        records.append(record)

    summary = build_summary(records, effective_mode, fallback_reason)
    result = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "repo_root": str(ROOT_DIR),
        "inventory_json": str(inventory_json),
        "inventory_summary": inventory_summary,
        "runner_binary": str(runner),
        "scanner_binary": str(scanner),
        "kernel_tree": str(kernel_tree),
        "kernel_image": str(kernel_image),
        "btf_custom_path": str(btf_custom_path) if btf_custom_path is not None else None,
        "vng_binary": args.vng,
        "repeat": args.repeat,
        "timeout_seconds": args.timeout,
        "kernel_build": text_invocation_summary(kernel_build),
        "guest_smoke": guest_smoke,
        "skip_families": skip_families,
        "use_policy": args.use_policy,
        "blind_apply": args.blind_apply,
        "policy_dir": str(policy_dir),
        "summary": summary,
        "programs": records,
    }

    ensure_parent(output_json)
    ensure_parent(output_md)
    write_json_output(output_json, result)
    output_md.write_text(build_markdown(result))

    print(f"Wrote {output_json}")
    print(f"Wrote {output_md}")
    print(
        f"mode={summary['effective_mode']} "
        f"targets={summary['targets_attempted']} "
        f"compile_pairs={summary['compile_pairs']} "
        f"measured_pairs={summary['measured_pairs']} "
        f"applied={summary['applied_programs']}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
