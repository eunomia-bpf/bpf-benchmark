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
    from runner.libs.inventory import (
        discover_corpus_objects,
        discover_object_programs,
        load_packet_test_run_targets,
    )
    from runner.libs.results import parse_runner_samples
except ImportError:
    from runner.libs.inventory import (
        discover_corpus_objects,
        discover_object_programs,
        load_packet_test_run_targets,
    )
    from runner.libs.results import parse_runner_samples

from runner.libs.corpus import (
    add_filter_argument,
    add_max_programs_argument,
    add_corpus_build_report_argument,
    add_output_json_argument,
    add_output_md_argument,
    add_repeat_argument,
    add_runner_argument,
    add_daemon_argument,
    add_timeout_argument,
    directive_scan_from_record,
    ensure_parent,
    execution_plan,
    format_ns,
    format_ratio,
    geomean,
    infer_program_kind,
    markdown_table,
    materialize_dummy_context,
    materialize_dummy_packet,
    normalize_directive_scan as shared_normalize_directive_scan,
    require_minimum,
    run_command as shared_run_command,
    run_text_command as shared_run_text_command,
    summarize_text,
    write_json_output,
    write_text_output,
)
from runner.libs.commands import (
    build_runner_command as _build_runner_command,
)


ROOT_DIR = Path(__file__).resolve().parent.parent
SELF_RELATIVE = Path(__file__).resolve().relative_to(ROOT_DIR)
DEFAULT_INVENTORY_JSON = ROOT_DIR / "docs" / "tmp" / "corpus-runnability-results.json"
DEFAULT_OUTPUT_JSON = authoritative_output_path(ROOT_DIR / "corpus" / "results", "corpus_vm_batch")
DEFAULT_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "corpus-batch-recompile-results.md"
DEFAULT_RUNNER = ROOT_DIR / "runner" / "build" / "micro_exec"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_KERNEL_TREE = ROOT_DIR / "vendor" / "linux-framework"
DEFAULT_KERNEL_IMAGE = DEFAULT_KERNEL_TREE / "arch" / "x86" / "boot" / "bzImage"
DEFAULT_BTF_PATH = DEFAULT_KERNEL_TREE / "vmlinux"
DEFAULT_HOST_BTF_PATH = Path("/sys/kernel/btf/vmlinux")
DEFAULT_VNG = str(ROOT_DIR / "runner" / "scripts" / "vng-wrapper.sh")
DEFAULT_VNG_MEMORY = "4G"
DEFAULT_VNG_CPUS = "2"
DEFAULT_REPEAT = 200
DEFAULT_TIMEOUT_SECONDS = 240


DEFAULT_BUILD_TIMEOUT_SECONDS = 3600
DEFAULT_PERF_OUTPUT_JSON = authoritative_output_path(ROOT_DIR / "corpus" / "results", "corpus_perf")
DEFAULT_PERF_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "corpus-perf-results.md"
DEFAULT_TRACING_OUTPUT_JSON = authoritative_output_path(ROOT_DIR / "corpus" / "results", "corpus_tracing")
DEFAULT_TRACING_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "corpus-tracing-results.md"
DEFAULT_CODE_SIZE_OUTPUT_JSON = authoritative_output_path(ROOT_DIR / "corpus" / "results", "corpus_code_size")
DEFAULT_CODE_SIZE_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "corpus-code-size-results.md"
MODE_NAMES = ("packet", "tracing", "perf", "code-size")

FAMILY_FIELDS = (
    ("cmov", "cmov_sites"),
    ("wide", "wide_sites"),
    ("rotate", "rotate_sites"),
    ("lea", "lea_sites"),
    ("extract", "bitfield_sites"),
    ("endian", "endian_sites"),
    ("branch-flip", "branch_flip_sites"),
)
FAMILY_DISPLAY_NAMES = {
    "cmov": "CMOV",
    "wide": "WIDE",
    "rotate": "ROTATE",
    "lea": "LEA",
    "extract": "EXTRACT",
    "endian": "ENDIAN",
    "branch-flip": "BRANCH-FLIP",
}


def parse_packet_args(argv: list[str] | None = None) -> argparse.Namespace:
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
    add_daemon_argument(parser, DEFAULT_DAEMON, help_text="Path to bpfrejit-daemon.")
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
        help="Comma-separated recompile families to skip from the auto-generated v5 policy blob. Supported: cmov, wide, rotate, lea, extract, endian, branch-flip.",
    )
    parser.add_argument(
        "--blind-apply",
        action="store_true",
        help="Ignore per-program policies and force blind all-apply auto-scan recompile for debugging.",
    )
    parser.add_argument(
        "--force-host-fallback",
        action="store_true",
        help="Skip VM execution and run host compile-only + daemon fallback directly.",
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
        "endian": "endian",
        "endian-fusion": "endian",
        "branch-flip": "branch-flip",
        "branchflip": "branch-flip",
        "bflip": "branch-flip",
    }
    if normalized not in mapping:
        raise SystemExit(
            f"unsupported family in --skip-families: {value} "
            "(expected cmov, wide, rotate, lea, extract, endian, or branch-flip)"
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
    payloads: list[dict[str, Any]] = []
    for line in stdout.splitlines():
        text = line.strip()
        if not text or not text.startswith("{"):
            continue
        try:
            payload = json.loads(text)
        except json.JSONDecodeError:
            continue
        if isinstance(payload, dict):
            payloads.append(payload)
    return payloads


def run_text_command(command: list[str], timeout_seconds: int) -> dict[str, Any]:
    return shared_run_text_command(command, timeout_seconds, cwd=ROOT_DIR)


def run_command(command: list[str], timeout_seconds: int) -> dict[str, Any]:
    return shared_run_command(command, timeout_seconds, cwd=ROOT_DIR)


def invocation_summary(result: dict[str, Any] | None) -> dict[str, Any] | None:
    if result is None:
        return None
    stderr = result.get("stderr") or ""
    stdout = result.get("stdout") or ""
    if isinstance(stderr, bytes):
        stderr = stderr.decode("utf-8", errors="replace")
    if isinstance(stdout, bytes):
        stdout = stdout.decode("utf-8", errors="replace")
    return {
        "ok": result["ok"],
        "returncode": result["returncode"],
        "timed_out": result["timed_out"],
        "duration_seconds": result["duration_seconds"],
        "error": result["error"],
        "stderr_tail": summarize_text(stderr),
        "stdout_tail": summarize_text(stdout),
        "sample": result.get("sample"),
    }


def paired_stock_invocation_summary(result: dict[str, Any] | None) -> dict[str, Any] | None:
    summary = invocation_summary(result)
    if not summary or not summary.get("ok"):
        return None

    all_samples = list(parse_runner_samples(str(result.get("stdout") or "")))

    stock_samples = [
        dict(sample)
        for sample in all_samples
        if sample.get("phase") == "stock"
    ]
    if stock_samples:
        summary["sample"] = stock_samples[-1]
        return summary

    # Fallback: when no rejit was requested, the runner emits a single sample
    # without a "phase" field.  Use it as the baseline measurement.
    vanilla_samples = [
        dict(sample)
        for sample in all_samples
        if sample.get("phase") is None and sample.get("exec_ns") is not None
    ]
    if vanilla_samples:
        summary["sample"] = vanilla_samples[-1]
        return summary

    return None


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
    blind_apply: bool,
    skip_families: list[str],
    recompile_all: bool = False,
    dump_xlated: Path | None = None,
    daemon_socket: str | None = None,
) -> list[str]:
    enable_rejit = blind_apply or (daemon_socket is not None)
    return _build_runner_command(
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
        dump_xlated=dump_xlated,
        btf_custom_path=btf_custom_path,
        rejit=enable_rejit,
        daemon_socket=daemon_socket if enable_rejit else None,
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
        "daemon_counts": normalize_scan(target.get("inventory_scan")),
        "daemon_cli": None,
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
    daemon: Path,
    repeat: int,
    timeout_seconds: int,
    execution_mode: str,
    btf_custom_path: Path | None,
    enable_recompile: bool,
    enable_exec: bool,
    skip_families: list[str],
    blind_apply: bool,
) -> dict[str, Any]:
    record = build_empty_record(target, execution_mode)
    object_path = ROOT_DIR / target["object_path"]
    memory_path = Path(target["memory_path"]) if target.get("memory_path") else None
    recompile_all = blind_apply
    policy_mode = "blind-apply-v5" if blind_apply else "daemon-auto"
    inventory_scan = normalize_scan(target.get("inventory_scan"))
    daemon_result = None
    scan_source = "inventory"
    daemon_counts = inventory_scan

    with tempfile.TemporaryDirectory(prefix="corpus-v5-batch-") as tmpdir:
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
                blind_apply=False,
                recompile_all=False,
                skip_families=[],
                dump_xlated=xlated_path,
            ),
            timeout_seconds,
        )
        if baseline_compile_raw["ok"]:
            baseline_scan = directive_scan_from_record(baseline_compile_raw)
            if baseline_scan["total_sites"] > 0:
                daemon_counts = baseline_scan
                scan_source = f"{execution_mode}_runner_scan"

        v5_compile_raw = None
        v5_run_raw = None
        daemon_proc = None
        daemon_socket: str | None = None
        if enable_recompile:
            daemon_socket = f"/tmp/bpfrejit-{os.getpid()}.sock"
            daemon_proc = subprocess.Popen(
                [str(daemon), "serve", "--socket", daemon_socket],
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
            )
            # Wait briefly for the socket to appear before runner connects.
            import time as _time
            _time.sleep(0.5)
            try:
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
                        blind_apply=blind_apply,
                        recompile_all=recompile_all,
                        skip_families=skip_families,
                        daemon_socket=daemon_socket,
                    ),
                    timeout_seconds,
                )
                if enable_exec and target.get("can_test_run") and v5_compile_raw and v5_compile_raw["ok"]:
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
                            blind_apply=blind_apply,
                            recompile_all=recompile_all,
                            skip_families=skip_families,
                            daemon_socket=daemon_socket,
                        ),
                        timeout_seconds,
                    )
            finally:
                daemon_proc.terminate()
                try:
                    daemon_proc.wait(timeout=5)
                except subprocess.TimeoutExpired:
                    daemon_proc.kill()
                    daemon_proc.wait()

    record["daemon_cli"] = text_invocation_summary(daemon_result)
    record["policy_path"] = None
    record["policy_mode"] = policy_mode
    record["scan_source"] = scan_source
    record["daemon_counts"] = daemon_counts
    record["eligible_families"] = families_from_scan(daemon_counts)
    record["baseline_compile"] = invocation_summary(baseline_compile_raw)
    record["v5_compile"] = invocation_summary(v5_compile_raw)
    record["v5_run"] = invocation_summary(v5_run_raw)
    record["baseline_run"] = paired_stock_invocation_summary(v5_run_raw)
    if (
        enable_exec
        and enable_recompile
        and target.get("can_test_run")
        and v5_run_raw
        and v5_run_raw.get("ok")
        and record["baseline_run"] is None
    ):
        record["record_error"] = "stock phase missing from run-kernel output"
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
    daemon = Path(args.daemon).resolve()
    btf_custom_path = Path(args.btf_custom_path).resolve() if args.btf_custom_path else None
    record = run_target_locally(
        target=target,
        runner=runner,
        daemon=daemon,
        repeat=args.repeat,
        timeout_seconds=args.timeout,
        execution_mode="vm",
        btf_custom_path=btf_custom_path,
        enable_recompile=True,
        enable_exec=bool(target.get("can_test_run")),
        skip_families=normalize_skip_families(args.skip_families),
        blind_apply=args.blind_apply,
    )
    print(json.dumps(record, sort_keys=True))
    return 0


def build_vng_command(*, vng_binary: str, kernel_image: Path, guest_exec: str) -> list[str]:
    return [
        vng_binary,
        "--run",
        str(kernel_image),
        "--rwdir",
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
    # Load kinsn kernel modules before running the guest command so the daemon
    # can apply platform-specific rewrites (rotate, cond_select, extract).
    load_script = ROOT_DIR / "module" / "load_all.sh"
    kinsn_load = f"{shlex.quote(str(load_script))} 2>/dev/null || true; "
    main_cmd = " ".join(shlex.quote(part) for part in argv)
    return kinsn_load + main_cmd


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
    daemon: Path,
    kernel_image: Path,
    btf_custom_path: Path,
    repeat: int,
    timeout_seconds: int,
    vng_binary: str,
    skip_families: list[str],
    blind_apply: bool,
) -> dict[str, Any]:
    handle = tempfile.NamedTemporaryFile(
        mode="w",
        prefix="corpus-v5-vm-target-",
        suffix=".json",
        dir=ROOT_DIR,
        delete=False,
    )
    try:
        guest_target = {
            **target,
            "policy_mode": "blind-apply-v5" if blind_apply else "daemon-auto",
            "policy_path": None,
        }
        with handle:
            json.dump(guest_target, handle)
            handle.write("\n")
        target_path = Path(handle.name)
        guest_argv = [
            "python3",
            str(SELF_RELATIVE),
            "packet",
            "--guest-target-json",
            str(target_path),
            "--runner",
            str(runner),
            "--daemon",
            str(daemon),
            "--btf-custom-path",
            str(btf_custom_path),
            "--repeat",
            str(repeat),
            "--timeout",
            str(timeout_seconds),
        ]
        if skip_families:
            guest_argv.extend(["--skip-families", ",".join(skip_families)])
        if blind_apply:
            guest_argv.append("--blind-apply")
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
    guest_exec = build_guest_exec(["python3", str(SELF_RELATIVE), "packet", "--guest-info"])
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
        scan = normalize_scan(record.get("daemon_counts"))
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
            scan = normalize_scan(item.get("daemon_counts"))
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
        items = [record for record in records if normalize_scan(record.get("daemon_counts"))[field] > 0]
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
                "total_sites": sum(normalize_scan(item.get("daemon_counts"))[field] for item in items),
                "applied_sites": sum(normalize_scan(item.get("daemon_counts"))[field] for item in applied_items),
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
        f"- Daemon: `{data['daemon_binary']}`",
        "- Requested mode: `strict-vm`",
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
                    normalize_scan(record.get("daemon_counts"))["total_sites"],
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
            "- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current daemon pass determines whether v5 has any eligible families.",
            "- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.",
            "- Default steady-state semantics: the daemon is always started and tries to optimize each program; programs with no applicable sites stay on stock JIT.",
            "- `--blind-apply` forces the old debug/exploration path with `--recompile-v5 --recompile-all`.",
            "- `--skip-families` only applies together with `--blind-apply`; the family columns above report applied families, not just eligible sites.",
            "- Host fallback mode only does baseline compile-only plus offline daemon scan; it does not attempt recompile or runtime measurement.",
            "- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.",
        ]
    )
    return "\n".join(lines) + "\n"


def packet_main(argv: list[str] | None = None) -> int:
    args = parse_packet_args(argv)
    require_minimum(args.repeat, 1, "--repeat")
    skip_families = normalize_skip_families(args.skip_families)
    if skip_families and not args.blind_apply:
        raise SystemExit("--skip-families requires --blind-apply")

    if args.guest_info:
        return run_guest_info_mode()
    if args.guest_target_json:
        return run_guest_target_mode(args)

    inventory_json = Path(args.inventory_json).resolve()
    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.max_programs is not None:
        output_json = smoke_output_path(ROOT_DIR / "corpus" / "results", "corpus_vm_batch")
    else:
        output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    runner = Path(args.runner).resolve()
    daemon = Path(args.daemon).resolve()
    kernel_tree = Path(args.kernel_tree).resolve()
    kernel_image = Path(args.kernel_image).resolve()
    btf_custom_path = Path(args.btf_custom_path).resolve() if args.btf_custom_path else None

    if not inventory_json.exists():
        raise SystemExit(f"inventory JSON not found: {inventory_json}")
    if not runner.exists():
        raise SystemExit(f"runner not found: {runner}")
    if not daemon.exists():
        raise SystemExit(f"daemon not found: {daemon}")

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
                daemon=daemon,
                kernel_image=kernel_image,
                btf_custom_path=btf_custom_path,
                repeat=args.repeat,
                timeout_seconds=args.timeout,
                vng_binary=args.vng,
                skip_families=skip_families,
                blind_apply=args.blind_apply,
            )
        else:
            record = run_target_locally(
                target=target,
                runner=runner,
                daemon=daemon,
                repeat=args.repeat,
                timeout_seconds=args.timeout,
                execution_mode="host-fallback",
                btf_custom_path=host_btf_path,
                enable_recompile=False,
                enable_exec=False,
                skip_families=[],
                blind_apply=False,
            )
        records.append(record)

    summary = build_summary(records, effective_mode, fallback_reason)
    result = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "repo_root": str(ROOT_DIR),
        "inventory_json": str(inventory_json),
        "inventory_summary": inventory_summary,
        "runner_binary": str(runner),
        "daemon_binary": str(daemon),
        "kernel_tree": str(kernel_tree),
        "kernel_image": str(kernel_image),
        "btf_custom_path": str(btf_custom_path) if btf_custom_path is not None else None,
        "vng_binary": args.vng,
        "repeat": args.repeat,
        "timeout_seconds": args.timeout,
        "kernel_build": text_invocation_summary(kernel_build),
        "guest_smoke": guest_smoke,
        "skip_families": skip_families,
        "blind_apply": args.blind_apply,
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


def _mode_defaults(mode_name: str) -> tuple[Path, Path]:
    if mode_name == "perf":
        return DEFAULT_PERF_OUTPUT_JSON, DEFAULT_PERF_OUTPUT_MD
    if mode_name == "tracing":
        return DEFAULT_TRACING_OUTPUT_JSON, DEFAULT_TRACING_OUTPUT_MD
    if mode_name == "code-size":
        return DEFAULT_CODE_SIZE_OUTPUT_JSON, DEFAULT_CODE_SIZE_OUTPUT_MD
    raise SystemExit(f"unsupported mode: {mode_name}")


def parse_linear_mode_args(mode_name: str, argv: list[str] | None = None) -> argparse.Namespace:
    default_output_json, default_output_md = _mode_defaults(mode_name)
    description = {
        "perf": "Measure corpus programs locally with stock vs recompile runs when test_run is supported.",
        "tracing": "Inspect tracing-style corpus programs with stock vs recompile compile-only passes.",
        "code-size": "Compare stock vs recompile code size for the discovered corpus programs.",
    }[mode_name]
    parser = argparse.ArgumentParser(description=description)
    add_output_json_argument(parser, default_output_json)
    add_output_md_argument(parser, default_output_md)
    add_runner_argument(parser, DEFAULT_RUNNER, help_text="Path to micro_exec.")
    add_daemon_argument(parser, DEFAULT_DAEMON, help_text="Path to bpfrejit-daemon.")
    add_repeat_argument(parser, DEFAULT_REPEAT, help_text="Repeat count passed to each micro_exec invocation.")
    add_timeout_argument(parser, DEFAULT_TIMEOUT_SECONDS, help_text="Per-target timeout in seconds.")
    add_filter_argument(
        parser,
        help_text="Only include targets whose object path, program name, or section name contains this substring. Repeatable.",
    )
    add_max_programs_argument(parser, help_text="Optional cap for smoke testing.")
    add_corpus_build_report_argument(
        parser,
        help_text="Optional expanded corpus build JSON report used to discover object files.",
    )
    parser.add_argument(
        "--kind",
        action="append",
        dest="kinds",
        help="Restrict processing to inferred program kinds such as xdp, tc, socket, tracing, or perf_event.",
    )
    parser.add_argument(
        "--btf-custom-path",
        default=str(DEFAULT_HOST_BTF_PATH) if DEFAULT_HOST_BTF_PATH.exists() else None,
        help="Host BTF path passed to micro_exec compile/load invocations when available.",
    )
    parser.add_argument(
        "--skip-families",
        action="append",
        help="Comma-separated recompile families to skip from blind auto-scan apply mode.",
    )
    parser.add_argument(
        "--blind-apply",
        action="store_true",
        help="Ignore per-program policies and force blind all-apply auto-scan recompile.",
    )
    return parser.parse_args(argv)


def _source_name_for_object(relative_object_path: str) -> str:
    path = Path(relative_object_path)
    parts = path.parts
    if len(parts) >= 3 and parts[0] == "corpus" and parts[1] == "build":
        return parts[2]
    if len(parts) >= 3 and parts[0] == "corpus" and parts[1] in {"repos", "bcf"}:
        return parts[2]
    return path.parent.name or "corpus"


def discover_linear_targets(
    *,
    runner: Path,
    mode_name: str,
    filters: list[str] | None,
    kinds: list[str] | None,
    max_programs: int | None,
    corpus_build_report: Path | None,
) -> tuple[list[dict[str, Any]], dict[str, Any]]:
    packet_path = materialize_dummy_packet(ROOT_DIR / "corpus" / "inputs" / "macro_dummy_packet_64.bin")
    context_path = materialize_dummy_context(ROOT_DIR / "corpus" / "inputs" / "macro_dummy_context_64.bin")
    lowered_filters = [item.lower() for item in filters or []]
    requested_kinds = {item.lower() for item in kinds or []}
    discovery = discover_corpus_objects(ROOT_DIR, corpus_build_report=corpus_build_report)
    targets: list[dict[str, Any]] = []
    inventory_failures: list[dict[str, Any]] = []

    for object_path in discovery.corpus_paths:
        rel_object = object_path.relative_to(ROOT_DIR).as_posix()
        try:
            programs = discover_object_programs(runner, object_path)
        except Exception as exc:
            inventory_failures.append({"object_path": rel_object, "error": str(exc)})
            continue

        for program in programs:
            kind = infer_program_kind(program.section_name)
            if mode_name == "tracing":
                if kind != "tracing":
                    continue
            elif mode_name == "perf" and kind == "tracing":
                continue
            if requested_kinds and kind not in requested_kinds:
                continue
            haystack = " ".join(
                [
                    rel_object.lower(),
                    program.name.lower(),
                    program.section_name.lower(),
                    kind.lower(),
                ]
            )
            if lowered_filters and not any(item in haystack for item in lowered_filters):
                continue

            plan = execution_plan(program.section_name, packet_path, context_path)
            can_test_run = kind not in {"tracing", "perf_event", "iter", "struct_ops", "syscall"}
            targets.append(
                {
                    "object_path": rel_object,
                    "source_name": _source_name_for_object(rel_object),
                    "program_name": program.name,
                    "section_name": program.section_name,
                    "section_root": program.section_name.split("/", 1)[0],
                    "prog_type_name": program.prog_type_name,
                    "io_mode": str(plan["io_mode"]),
                    "input_size": int(plan["input_size"]),
                    "memory_path": str(plan["memory_path"]) if plan["memory_path"] is not None else None,
                    "can_test_run": can_test_run,
                    "inventory_scan": {},
                }
            )
            if max_programs is not None and len(targets) >= max_programs:
                return targets, {
                    "discovery_source": discovery.corpus_source,
                    "inventory_failures": inventory_failures,
                    "skipped_non_bpf": list(discovery.skipped_non_bpf),
                }

    return targets, {
        "discovery_source": discovery.corpus_source,
        "inventory_failures": inventory_failures,
        "skipped_non_bpf": list(discovery.skipped_non_bpf),
    }


def build_linear_summary(
    records: list[dict[str, Any]],
    *,
    mode_name: str,
    enable_exec: bool,
) -> dict[str, Any]:
    compile_pairs = sum(
        1
        for record in records
        if (record.get("baseline_compile") or {}).get("ok")
        and (record.get("v5_compile") or {}).get("ok")
    )
    measured_pairs = sum(
        1
        for record in records
        if enable_exec
        and (record.get("baseline_run") or {}).get("ok")
        and (record.get("v5_run") or {}).get("ok")
    )
    applied_programs = sum(
        1 for record in records if record.get("v5_compile_applied") or record.get("v5_run_applied")
    )
    size_ratios = [float(record["size_ratio"]) for record in records if record.get("size_ratio")]
    speedup_ratios = [float(record["speedup_ratio"]) for record in records if record.get("speedup_ratio")]
    errors = Counter(
        str(record.get("record_error") or "")
        for record in records
        if record.get("record_error")
    )
    return {
        "mode": mode_name,
        "targets_attempted": len(records),
        "compile_pairs": compile_pairs,
        "measured_pairs": measured_pairs,
        "applied_programs": applied_programs,
        "size_ratio_geomean": geomean(size_ratios),
        "speedup_ratio_geomean": geomean(speedup_ratios) if enable_exec else None,
        "record_errors": dict(errors),
    }


def build_linear_markdown(
    payload: dict[str, Any],
    *,
    mode_name: str,
    enable_exec: bool,
) -> str:
    summary = payload["summary"]
    title = {
        "perf": "Corpus Perf Mode",
        "tracing": "Corpus Tracing Mode",
        "code-size": "Corpus Code-Size Mode",
    }[mode_name]
    lines = [
        f"# {title}",
        "",
        f"- Generated: `{payload['generated_at']}`",
        f"- Runner: `{payload['runner_binary']}`",
        f"- Daemon: `{payload['daemon_binary']}`",
        f"- Targets attempted: `{summary['targets_attempted']}`",
        f"- Compile pairs: `{summary['compile_pairs']}`",
        f"- Measured pairs: `{summary['measured_pairs']}`",
        f"- Applied programs: `{summary['applied_programs']}`",
        f"- Native code size geomean ratio: `{format_ratio(summary['size_ratio_geomean'])}`",
    ]
    if enable_exec:
        lines.append(f"- Exec speedup geomean: `{format_ratio(summary['speedup_ratio_geomean'])}`")
    else:
        lines.append("- Exec speedup geomean: `n/a`")
    if mode_name == "tracing":
        lines.append("- Tracing mode uses compile-only inspection in the consolidated driver.")

    rows = []
    for record in payload["programs"]:
        rows.append(
            [
                record["source_name"],
                record["program_name"],
                record["section_name"],
                format_ratio(record.get("size_ratio")),
                format_ratio(record.get("speedup_ratio")) if enable_exec else "n/a",
                "yes" if record.get("v5_compile_applied") or record.get("v5_run_applied") else "no",
                record.get("record_error") or "",
            ]
        )

    if rows:
        lines.extend(
            [
                "",
                "## Records",
                "",
                *markdown_table(
                    ["Source", "Program", "Section", "Size Ratio", "Speedup", "Applied", "Error"],
                    rows,
                ),
            ]
        )

    if summary["record_errors"]:
        lines.extend(["", "## Record Errors", ""])
        lines.extend(
            markdown_table(
                ["Reason", "Count"],
                [[reason, count] for reason, count in summary["record_errors"].items()],
            )
        )

    return "\n".join(lines) + "\n"


def run_linear_mode(mode_name: str, argv: list[str] | None = None) -> int:
    args = parse_linear_mode_args(mode_name, argv)
    require_minimum(args.repeat, 1, "--repeat")
    skip_families = normalize_skip_families(args.skip_families)
    if skip_families and not args.blind_apply:
        raise SystemExit("--skip-families requires --blind-apply")

    runner = Path(args.runner).resolve()
    daemon = Path(args.daemon).resolve()
    if not runner.exists():
        raise SystemExit(f"runner not found: {runner}")
    if not daemon.exists():
        raise SystemExit(f"daemon not found: {daemon}")

    btf_custom_path = Path(args.btf_custom_path).resolve() if args.btf_custom_path else None
    corpus_build_report = Path(args.corpus_build_report).resolve() if args.corpus_build_report else None
    targets, discovery_summary = discover_linear_targets(
        runner=runner,
        mode_name=mode_name,
        filters=args.filters,
        kinds=args.kinds,
        max_programs=args.max_programs,
        corpus_build_report=corpus_build_report,
    )

    enable_exec = mode_name == "perf"
    records: list[dict[str, Any]] = []
    for index, target in enumerate(targets, start=1):
        print(
            f"[{index}/{len(targets)}] {target['source_name']} {target['object_path']}:{target['program_name']}",
            file=sys.stderr,
            flush=True,
        )
        record = run_target_locally(
            target=target,
            runner=runner,
            daemon=daemon,
            repeat=args.repeat,
            timeout_seconds=args.timeout,
            execution_mode=mode_name,
            btf_custom_path=btf_custom_path,
            enable_recompile=True,
            enable_exec=enable_exec,
            skip_families=skip_families,
            blind_apply=args.blind_apply,
        )
        records.append(record)

    summary = build_linear_summary(records, mode_name=mode_name, enable_exec=enable_exec)
    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "mode": mode_name,
        "repo_root": str(ROOT_DIR),
        "runner_binary": str(runner),
        "daemon_binary": str(daemon),
        "btf_custom_path": str(btf_custom_path) if btf_custom_path is not None else None,
        "repeat": args.repeat,
        "timeout_seconds": args.timeout,
        "skip_families": skip_families,
        "blind_apply": args.blind_apply,
        "corpus_build_report": str(corpus_build_report) if corpus_build_report is not None else None,
        "discovery": discovery_summary,
        "summary": summary,
        "programs": records,
    }

    ensure_parent(output_json)
    ensure_parent(output_md)
    write_json_output(output_json, payload)
    write_text_output(output_md, build_linear_markdown(payload, mode_name=mode_name, enable_exec=enable_exec))
    print(f"Wrote {output_json}")
    print(f"Wrote {output_md}")
    return 0


def main(argv: list[str] | None = None) -> int:
    forwarded = list(argv if argv is not None else sys.argv[1:])
    if not forwarded or forwarded[0] in {"-h", "--help"}:
        raise SystemExit("corpus mode required: packet | tracing | perf | code-size")
    mode_name, *remaining = forwarded
    if mode_name == "packet":
        return packet_main(remaining)
    if mode_name in {"tracing", "perf", "code-size"}:
        return run_linear_mode(mode_name, remaining)
    raise SystemExit(f"unknown corpus mode: {mode_name}\nAvailable modes: {' | '.join(MODE_NAMES)}")


if __name__ == "__main__":
    raise SystemExit(main())
