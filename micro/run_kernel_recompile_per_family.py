#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import platform
import shlex
import shutil
import statistics
import subprocess
import sys
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

REPO_ROOT = Path(__file__).resolve().parents[1]
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from corpus.policy_utils import canonical_policy_family_name, render_policy_v3_text
from micro.benchmark_catalog import CONFIG_PATH, ROOT_DIR, BenchmarkSpec, load_suite
from micro.orchestrator.benchmarks import resolve_memory_file, select_benchmarks
from micro.orchestrator.commands import build_micro_benchmark_command
from micro.orchestrator.environment import read_optional_text, read_required_text
from micro.orchestrator.results import (
    derive_perf_metrics,
    ns_summary,
    parse_runner_sample,
    summarize_named_counters,
    summarize_optional_ns,
    summarize_perf_counter_meta,
    summarize_phase_timings,
)


DEFAULT_ALL_APPLY_JSON = ROOT_DIR / "micro" / "results" / "kernel_recompile_strict_20260312.json"
DEFAULT_OUTPUT_JSON = ROOT_DIR / "micro" / "results" / "kernel_recompile_per_family_20260312.json"
DEFAULT_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "kernel-recompile-per-family-ablation.md"
DEFAULT_PER_BENCH_DIR = ROOT_DIR / "docs" / "tmp" / "kernel_recompile_per_family"
DEFAULT_KERNEL = ROOT_DIR / "vendor" / "linux-framework" / "arch" / "x86" / "boot" / "bzImage"
DEFAULT_SCANNER = ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"
POLICY_DIR = ROOT_DIR / "micro" / "policies" / "per_family"

FAMILY_ORDER = (
    "cmov",
    "wide",
    "rotate",
    "lea",
    "extract",
    "zero-ext",
    "endian",
    "branch-flip",
)

FAMILY_FOCUS = {
    "cmov": ("cmov_dense", "cmov_select"),
    "wide": ("load_word32", "packet_redundant_bounds"),
    "rotate": ("rotate64_hash", "packet_rss_hash"),
    "lea": ("stride_load_16", "multi_acc_8"),
    "extract": ("bitfield_extract", "bounds_check_heavy"),
    "zero-ext": ("alu32_64_pingpong",),
    "endian": ("packet_parse_vlans_tcpopts", "packet_parse"),
    "branch-flip": ("branch_dense", "large_mixed_1000"),
}


def policy_path_for_family(family: str) -> Path:
    return POLICY_DIR / f"{family}.yaml"


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Run framework-kernel microbenchmarks with single-family recompile policies."
    )
    parser.add_argument("--suite", default=str(CONFIG_PATH), help="Path to suite YAML.")
    parser.add_argument("--bench", action="append", dest="benches", help="Benchmark name.")
    parser.add_argument(
        "--family",
        action="append",
        dest="families",
        help="Family name to run (repeatable, default: all 8 families).",
    )
    parser.add_argument("--iterations", type=int, default=5, help="Measured iterations per benchmark.")
    parser.add_argument("--warmups", type=int, default=2, help="Warmup iterations per benchmark.")
    parser.add_argument("--repeat", type=int, default=200, help="Repeat count inside each helper sample.")
    parser.add_argument("--cpu", default="0", help="Pin guest child processes to a specific CPU via taskset.")
    parser.add_argument("--memory", default="4G", help="vng guest memory size.")
    parser.add_argument("--cpus", default="2", help="vng vCPU count.")
    parser.add_argument("--timeout", type=int, default=300, help="Per-VM timeout in seconds.")
    parser.add_argument("--kernel", default=str(DEFAULT_KERNEL), help="Kernel tree or bzImage passed to vng --run.")
    parser.add_argument("--scanner", default=str(DEFAULT_SCANNER), help="Path to bpf-jit-scanner used to generate benchmark-local family policies.")
    parser.add_argument("--vng", default="vng", help="vng executable to use.")
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON), help="Aggregate JSON output.")
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD), help="Markdown report output.")
    parser.add_argument(
        "--per-bench-dir",
        default=str(DEFAULT_PER_BENCH_DIR),
        help="Directory for per-benchmark guest artifacts.",
    )
    parser.add_argument(
        "--all-apply-json",
        default=str(DEFAULT_ALL_APPLY_JSON),
        help="Reference #118 blind all-apply JSON.",
    )
    parser.add_argument(
        "--guest-mode",
        action="store_true",
        help="Internal mode: run a single benchmark inside the guest.",
    )
    parser.add_argument(
        "--runtime",
        choices=["kernel", "kernel-recompile"],
        help="Guest-mode runtime to measure.",
    )
    parser.add_argument("--policy-file", help="Guest-mode policy file for kernel-recompile.")
    parser.add_argument("--output", help="Guest-mode JSON output.")
    return parser.parse_args(argv)


def run_command(command: list[str], cpu: str | None) -> subprocess.CompletedProcess[str]:
    full_command = command
    if cpu is not None:
        full_command = ["taskset", "-c", cpu, *command]
    return subprocess.run(
        full_command,
        capture_output=True,
        text=True,
    )


def parse_last_json_line(stdout: str, *, label: str) -> dict[str, Any]:
    lines = [line.strip() for line in stdout.splitlines() if line.strip()]
    if not lines:
        raise RuntimeError(f"{label} produced no JSON output")
    payload = json.loads(lines[-1])
    if not isinstance(payload, dict):
        raise RuntimeError(f"{label} did not produce a JSON object")
    return payload


def run_json_command(command: list[str], *, timeout_seconds: int, label: str) -> dict[str, Any]:
    completed = subprocess.run(
        command,
        cwd=ROOT_DIR,
        capture_output=True,
        text=True,
        timeout=timeout_seconds,
        check=False,
    )
    if completed.returncode != 0:
        detail = completed.stderr.strip() or completed.stdout.strip() or f"exit={completed.returncode}"
        raise RuntimeError(f"{label} failed: {' '.join(command)}\n{detail}")
    return parse_last_json_line(completed.stdout, label=label)


def generate_family_policy_file(
    *,
    scanner: Path,
    benchmark: BenchmarkSpec,
    family: str,
    output_path: Path,
    timeout_seconds: int,
) -> Path:
    payload = run_json_command(
        [
            str(scanner),
            "scan",
            str(benchmark.program_object.resolve()),
            "--all",
            "--json",
        ],
        timeout_seconds=timeout_seconds,
        label=f"scanner:{benchmark.name}:{family}",
    )
    program_name = str((payload.get("program") or {}).get("name", benchmark.base_name))
    sites: list[dict[str, Any]] = []
    for entry in payload.get("sites") or []:
        if not isinstance(entry, dict):
            continue
        entry_family = canonical_policy_family_name(str(entry.get("family", "")))
        if entry_family != family:
            continue
        insn = int(entry.get("insn", entry.get("start_insn", -1)))
        pattern_kind = str(entry.get("pattern_kind", "")).strip()
        if insn < 0 or not pattern_kind:
            continue
        sites.append(
            {
                "insn": insn,
                "family": entry_family,
                "pattern_kind": pattern_kind,
            }
        )
    sites.sort(
        key=lambda item: (
            int(item["insn"]),
            str(item["family"]),
            str(item["pattern_kind"]),
        )
    )
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(
        render_policy_v3_text(
            program_name=program_name,
            sites=sites,
            comments=[
                "Auto-generated by micro/run_kernel_recompile_per_family.py.",
                f"Benchmark: {benchmark.name}",
                f"Family: {family}",
                f"Program object: {benchmark.program_object}",
            ],
        )
    )
    return output_path


def tail_text(text: str, *, lines: int = 20, chars: int = 4000) -> str:
    stripped = text.strip()
    if not stripped:
        return ""
    line_tail = "\n".join(stripped.splitlines()[-lines:])
    if len(line_tail) <= chars:
        return line_tail
    return line_tail[-chars:]


def read_git_sha() -> str:
    try:
        completed = subprocess.run(
            ["git", "rev-parse", "HEAD"],
            cwd=ROOT_DIR,
            capture_output=True,
            text=True,
            check=False,
        )
    except OSError:
        return "unknown"
    if completed.returncode != 0:
        return "unknown"
    return completed.stdout.strip() or "unknown"


def geometric_mean(values: list[float]) -> float | None:
    positive = [value for value in values if value > 0.0]
    if not positive:
        return None
    return math.exp(statistics.mean(math.log(value) for value in positive))


def ratio_status(ratio: float | None) -> str:
    if ratio is None:
        return "n/a"
    if ratio > 1.0:
        return "win"
    if ratio < 1.0:
        return "loss"
    return "tie"


def format_ratio(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.3f}x"


def format_ns(value: float | int | None) -> str:
    if value is None:
        return "n/a"
    numeric = float(value)
    if abs(numeric - round(numeric)) < 1e-9:
        value = int(round(numeric))
    if numeric >= 1_000_000:
        return f"{numeric / 1_000_000:.3f} ms"
    if numeric >= 1_000:
        return f"{numeric / 1_000:.3f} us"
    return f"{value} ns"


def extract_recompile_observation(run_record: dict[str, Any]) -> dict[str, Any]:
    sample_sources: list[dict[str, Any]] = []
    for sample in run_record.get("samples", []):
        recompile = sample.get("recompile")
        if isinstance(recompile, dict):
            sample_sources.append(recompile)
    for failure in run_record.get("failures", []):
        sample = failure.get("sample")
        if isinstance(sample, dict):
            recompile = sample.get("recompile")
            if isinstance(recompile, dict):
                sample_sources.append(recompile)

    if not sample_sources:
        return {
            "requested": False,
            "applied": False,
            "requested_families": [],
            "skipped_families": [],
            "cmov_sites": 0,
            "wide_sites": 0,
            "rotate_sites": 0,
            "lea_sites": 0,
            "bitfield_sites": 0,
            "zero_ext_sites": 0,
            "endian_sites": 0,
            "branch_flip_sites": 0,
            "total_sites": 0,
            "errors": [],
        }

    requested_families: set[str] = set()
    skipped_families: set[str] = set()
    errors: list[str] = []
    aggregates = {
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
    requested = False
    applied = False
    for recompile in sample_sources:
        requested = requested or bool(recompile.get("requested"))
        applied = applied or bool(recompile.get("applied"))
        requested_families.update(str(value) for value in recompile.get("requested_families", []))
        skipped_families.update(str(value) for value in recompile.get("skipped_families", []))
        for key in aggregates:
            try:
                aggregates[key] = max(aggregates[key], int(recompile.get(key, 0) or 0))
            except (TypeError, ValueError):
                continue
        error_text = str(recompile.get("error", "") or "").strip()
        if error_text:
            errors.append(error_text)

    return {
        "requested": requested,
        "applied": applied,
        "requested_families": sorted(requested_families),
        "skipped_families": sorted(skipped_families),
        **aggregates,
        "errors": sorted(set(errors)),
    }


def summarize_run(run_record: dict[str, Any]) -> None:
    samples = run_record.get("samples", [])
    if not samples:
        run_record["compile_ns"] = ns_summary([])
        run_record["exec_ns"] = ns_summary([])
        run_record["phases_ns"] = {}
        run_record["perf_counters"] = {}
        run_record["perf_counters_meta"] = {"requested": False, "collected": False}
        run_record["derived_metrics"] = {}
        run_record["wall_exec_ns"] = None
        run_record["timing_source"] = "unknown"
        run_record["recompile_observation"] = extract_recompile_observation(run_record)
        return

    compile_values = [int(sample["compile_ns"]) for sample in samples]
    exec_values = [int(sample["exec_ns"]) for sample in samples]
    run_record["compile_ns"] = ns_summary(compile_values)
    run_record["exec_ns"] = ns_summary(exec_values)
    run_record["phases_ns"] = summarize_phase_timings(samples)
    run_record["perf_counters"] = summarize_named_counters(samples, "perf_counters")
    run_record["perf_counters_meta"] = summarize_perf_counter_meta(samples)
    run_record["derived_metrics"] = derive_perf_metrics(run_record["perf_counters"])
    run_record["wall_exec_ns"] = summarize_optional_ns(samples, "wall_exec_ns")
    run_record["timing_source"] = str(samples[0].get("timing_source", "unknown"))
    run_record["recompile_observation"] = extract_recompile_observation(run_record)


def execute_sample(
    *,
    command: list[str],
    cpu: str | None,
    expected_result: int | None,
    phase: str,
    iteration_index: int | None,
) -> tuple[dict[str, Any] | None, dict[str, Any] | None]:
    completed = run_command(command, cpu)
    if completed.returncode != 0:
        return None, {
            "phase": phase,
            "iteration_index": iteration_index,
            "reason": "command-failed",
            "returncode": completed.returncode,
            "stdout_tail": tail_text(completed.stdout),
            "stderr_tail": tail_text(completed.stderr),
        }
    try:
        sample = parse_runner_sample(completed.stdout)
    except Exception as exc:
        return None, {
            "phase": phase,
            "iteration_index": iteration_index,
            "reason": "parse-failed",
            "error": str(exc),
            "stdout_tail": tail_text(completed.stdout),
            "stderr_tail": tail_text(completed.stderr),
        }

    if expected_result is not None and sample.get("result") != expected_result:
        return sample, {
            "phase": phase,
            "iteration_index": iteration_index,
            "reason": "result-mismatch",
            "expected_result": expected_result,
            "actual_result": sample.get("result"),
            "stdout_tail": tail_text(completed.stdout),
            "stderr_tail": tail_text(completed.stderr),
            "sample": sample,
        }

    sample["stdout_tail"] = tail_text(completed.stdout)
    if completed.stderr.strip():
        sample["stderr_tail"] = tail_text(completed.stderr)
    return sample, None


def run_median(run_record: dict[str, Any] | None) -> float | None:
    if not isinstance(run_record, dict):
        return None
    if not run_record.get("measurement_complete"):
        return None
    exec_ns = run_record.get("exec_ns")
    if not isinstance(exec_ns, dict):
        return None
    median = exec_ns.get("median")
    if median in (None, 0):
        return None
    return float(median)


def benchmark_metadata(benchmark: BenchmarkSpec) -> dict[str, Any]:
    memory_file = resolve_memory_file(benchmark, False)
    return {
        "name": benchmark.name,
        "description": benchmark.description,
        "category": benchmark.category,
        "family": benchmark.family,
        "level": benchmark.level,
        "io_mode": benchmark.io_mode,
        "tags": list(benchmark.tags),
        "expected_result": benchmark.expected_result,
        "input": str(memory_file) if memory_file is not None else None,
        "program_object": str(benchmark.program_object),
    }


def guest_host_snapshot(cpu_affinity: str | None) -> dict[str, Any]:
    return {
        "hostname": platform.node(),
        "platform": platform.platform(),
        "python": sys.version.split()[0],
        "cpu_affinity": cpu_affinity,
        "git_sha": read_git_sha(),
        "kernel_version": platform.release(),
        "kernel_cmdline": read_required_text("/proc/cmdline"),
        "cpu_governor": read_optional_text("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor") or "unknown",
        "turbo_state": read_optional_text("/sys/devices/system/cpu/intel_pstate/no_turbo") or "unknown",
        "perf_event_paranoid": read_optional_text("/proc/sys/kernel/perf_event_paranoid"),
    }


def empty_failure_run_record(
    *,
    benchmark: BenchmarkSpec,
    runtime_name: str,
    runtime_mode: str,
    repeat: int,
    status: str,
    failure: dict[str, Any],
    policy_file: Path | None = None,
) -> dict[str, Any]:
    requested = runtime_mode in {"kernel-recompile", "kernel_recompile"}
    return {
        "runtime": runtime_name,
        "label": runtime_name,
        "mode": runtime_mode,
        "repeat": repeat,
        "command": [],
        "measurement_complete": False,
        "status": status,
        "failures": [failure],
        "samples": [],
        "artifacts": {
            "program_object": str(benchmark.program_object),
            "policy_file": str(policy_file) if policy_file is not None else None,
        },
        "compile_ns": ns_summary([]),
        "exec_ns": ns_summary([]),
        "phases_ns": {},
        "perf_counters": {},
        "perf_counters_meta": {"requested": False, "collected": False},
        "derived_metrics": {},
        "wall_exec_ns": None,
        "timing_source": "unknown",
        "recompile_observation": {
            "requested": requested,
            "applied": False,
            "requested_families": [],
            "skipped_families": [],
            "cmov_sites": 0,
            "wide_sites": 0,
            "rotate_sites": 0,
            "lea_sites": 0,
            "bitfield_sites": 0,
            "zero_ext_sites": 0,
            "endian_sites": 0,
            "branch_flip_sites": 0,
            "total_sites": 0,
            "errors": [],
        },
    }


def load_all_apply_reference(path: Path) -> dict[str, Any]:
    data = json.loads(path.read_text())
    benchmark_lookup: dict[str, dict[str, Any]] = {}
    for benchmark in data.get("benchmarks", []):
        by_runtime = {run["runtime"]: run for run in benchmark.get("runs", [])}
        stock_run = by_runtime.get("kernel")
        recompile_run = by_runtime.get("kernel-recompile")
        recompile_obs = recompile_run.get("recompile_observation", {}) if isinstance(recompile_run, dict) else {}
        benchmark_lookup[str(benchmark["name"])] = {
            "stock_exec_ns_median": run_median(stock_run),
            "recompile_exec_ns_median": run_median(recompile_run),
            "ratio_stock_over_recompile": (
                float(run_median(stock_run)) / float(run_median(recompile_run))
                if run_median(stock_run) not in (None, 0) and run_median(recompile_run) not in (None, 0)
                else None
            ),
            "stock_status": stock_run.get("status") if isinstance(stock_run, dict) else "missing",
            "recompile_status": recompile_run.get("status") if isinstance(recompile_run, dict) else "missing",
            "recompile_applied": bool(recompile_obs.get("applied")),
            "total_sites": int(recompile_obs.get("total_sites", 0) or 0),
            "site_counts": {
                "cmov": int(recompile_obs.get("cmov_sites", 0) or 0),
                "wide": int(recompile_obs.get("wide_sites", 0) or 0),
                "rotate": int(recompile_obs.get("rotate_sites", 0) or 0),
                "lea": int(recompile_obs.get("lea_sites", 0) or 0),
                "extract": int(recompile_obs.get("bitfield_sites", 0) or 0),
                "zero-ext": int(recompile_obs.get("zero_ext_sites", 0) or 0),
                "endian": int(recompile_obs.get("endian_sites", 0) or 0),
                "branch-flip": int(recompile_obs.get("branch_flip_sites", 0) or 0),
            },
        }
    return {
        "path": str(path.resolve()),
        "summary": data.get("summary", {}),
        "benchmarks": benchmark_lookup,
    }


def select_families(raw_names: list[str] | None) -> list[str]:
    if not raw_names:
        return list(FAMILY_ORDER)
    valid = set(FAMILY_ORDER)
    selected: list[str] = []
    for raw_name in raw_names:
        normalized = raw_name.strip().lower()
        if normalized not in valid:
            raise SystemExit(f"unknown family '{raw_name}' (expected one of: {', '.join(FAMILY_ORDER)})")
        if normalized not in selected:
            selected.append(normalized)
    return selected


def load_or_initialize_results(
    *,
    output_json: Path,
    suite,
    families: list[str],
    args: argparse.Namespace,
    all_apply_reference: dict[str, Any],
) -> dict[str, Any]:
    if output_json.exists():
        results = json.loads(output_json.read_text())
    else:
        results = {
            "suite": suite.suite_name,
            "manifest": str(suite.manifest_path),
            "generated_at": datetime.now(timezone.utc).isoformat(),
            "host_controller": {
                "hostname": platform.node(),
                "platform": platform.platform(),
                "python": sys.version.split()[0],
                "git_sha": read_git_sha(),
            },
            "vm": {
                "kernel": str(Path(args.kernel).resolve()),
                "memory": str(args.memory),
                "cpus": str(args.cpus),
                "vng": shutil.which(args.vng) or args.vng,
            },
            "defaults": {
                "iterations": args.iterations,
                "warmups": args.warmups,
                "repeat": args.repeat,
                "cpu": args.cpu,
            },
            "families": [],
            "all_apply_reference": {
                "path": all_apply_reference["path"],
                "summary": all_apply_reference["summary"],
            },
            "guest_host": None,
            "benchmarks": [],
            "summary": {},
        }

    results["families"] = [
        {
            "name": family,
            "policy_file": str(policy_path_for_family(family)),
            "policy_mode": "benchmark-local-v3",
            "focus_benchmarks": list(FAMILY_FOCUS.get(family, ())),
        }
        for family in families
    ]
    results.setdefault("benchmarks", [])
    results.setdefault("summary", {})
    return results


def ensure_benchmark_entry(
    *,
    results: dict[str, Any],
    benchmark: BenchmarkSpec,
    all_apply_reference: dict[str, Any],
) -> dict[str, Any]:
    for entry in results["benchmarks"]:
        if entry["name"] == benchmark.name:
            entry.setdefault("family_runs", {})
            if "all_apply_reference" not in entry:
                entry["all_apply_reference"] = all_apply_reference["benchmarks"].get(benchmark.name)
            return entry

    entry = {
        **benchmark_metadata(benchmark),
        "stock_run": None,
        "family_runs": {},
        "all_apply_reference": all_apply_reference["benchmarks"].get(benchmark.name),
    }
    results["benchmarks"].append(entry)
    return entry


def guest_output_path(base_dir: Path, runtime_label: str, benchmark_name: str) -> Path:
    return base_dir / runtime_label / f"{benchmark_name}.json"


def guest_log_path(base_dir: Path, runtime_label: str, benchmark_name: str) -> Path:
    return base_dir / runtime_label / f"{benchmark_name}.log"


def build_guest_exec(
    *,
    benchmark_name: str,
    runtime_mode: str,
    output_path: Path,
    log_path: Path,
    args: argparse.Namespace,
    policy_file: Path | None = None,
) -> str:
    inner = [
        "set -euo pipefail",
        "if [ -d /sys/devices/system/cpu ]; then "
        "for f in /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor; do "
        "[ -f \"$f\" ] || continue; echo performance > \"$f\" || true; done; fi",
        f"cd {shlex.quote(str(ROOT_DIR))}",
    ]

    command = [
        "python3",
        "-u",
        "micro/run_kernel_recompile_per_family.py",
        "--guest-mode",
        "--suite",
        str(Path(args.suite).resolve()),
        "--bench",
        benchmark_name,
        "--runtime",
        runtime_mode,
        "--iterations",
        str(args.iterations),
        "--warmups",
        str(args.warmups),
        "--repeat",
        str(args.repeat),
        "--cpu",
        str(args.cpu),
        "--output",
        str(output_path),
    ]
    if policy_file is not None:
        command.extend(["--policy-file", str(policy_file)])

    inner.append(
        f"taskset -c {shlex.quote(str(args.cpu))} "
        + " ".join(shlex.quote(part) for part in command)
        + f" 2>&1 | tee {shlex.quote(str(log_path))}"
    )
    return f"bash -lc {shlex.quote('; '.join(inner))}"


def run_vm(exec_script: str, args: argparse.Namespace) -> subprocess.CompletedProcess[str]:
    vng = shutil.which(args.vng) or args.vng
    command = [
        vng,
        "--run",
        str(Path(args.kernel).resolve()),
        "--cwd",
        str(ROOT_DIR),
        "--disable-monitor",
        "--memory",
        str(args.memory),
        "--cpus",
        str(args.cpus),
        "--rwdir",
        str(ROOT_DIR / "micro" / "results"),
        "--rwdir",
        str(ROOT_DIR / "docs" / "tmp"),
        "--exec",
        exec_script,
    ]
    return subprocess.run(
        command,
        cwd=ROOT_DIR,
        capture_output=True,
        text=True,
        timeout=args.timeout,
        check=False,
    )


def integrate_guest_payload(
    *,
    entry: dict[str, Any],
    runtime_mode: str,
    family: str | None,
    payload: dict[str, Any],
    results: dict[str, Any],
) -> None:
    run_record = payload["benchmark"]["run"]
    if runtime_mode == "kernel":
        entry["stock_run"] = run_record
    else:
        assert family is not None
        entry["family_runs"][family] = run_record
    if results.get("guest_host") is None:
        results["guest_host"] = payload.get("host")


def synthesize_failure_from_vm(
    *,
    benchmark: BenchmarkSpec,
    runtime_mode: str,
    repeat: int,
    completed: subprocess.CompletedProcess[str] | None,
    log_path: Path,
    policy_file: Path | None = None,
    timed_out: bool = False,
) -> dict[str, Any]:
    status = "timeout" if timed_out else "vm-crash"
    failure = {
        "phase": "vm",
        "iteration_index": None,
        "reason": status,
        "returncode": None if completed is None else completed.returncode,
        "stdout_tail": "" if completed is None else tail_text(completed.stdout),
        "stderr_tail": "" if completed is None else tail_text(completed.stderr),
        "guest_log_tail": tail_text(log_path.read_text(errors="replace")) if log_path.exists() else "",
    }
    return empty_failure_run_record(
        benchmark=benchmark,
        runtime_name="kernel" if runtime_mode == "kernel" else "kernel-recompile",
        runtime_mode=runtime_mode,
        repeat=repeat,
        status=status,
        failure=failure,
        policy_file=policy_file,
    )


def summarize_focus_rows(rows_by_name: dict[str, dict[str, Any]], focus_names: tuple[str, ...]) -> list[str]:
    notes: list[str] = []
    for name in focus_names:
        row = rows_by_name.get(name)
        if row is None:
            continue
        ratio = format_ratio(row["ratio_stock_over_recompile"])
        blind = format_ratio(row["ratio_all_apply_exec_over_recompile"])
        status = row["recompile_status"] if row["ratio_stock_over_recompile"] is None else row["ratio_status"]
        notes.append(
            f"`{name}` stock/family `{ratio}`, blind/family `{blind}`, status `{status}`, sites `{row['recompile_total_sites']}`"
        )
    return notes


def build_summary(results: dict[str, Any]) -> dict[str, Any]:
    family_order = [entry["name"] for entry in results.get("families", [])]
    family_rows: dict[str, list[dict[str, Any]]] = {family: [] for family in family_order}
    interaction_rows: list[dict[str, Any]] = []
    best_single_counter: Counter[str] = Counter()

    for benchmark in results.get("benchmarks", []):
        stock_run = benchmark.get("stock_run")
        stock_median = run_median(stock_run)
        stock_status = stock_run.get("status") if isinstance(stock_run, dict) else "missing"
        reference = benchmark.get("all_apply_reference") or {}
        all_apply_median = reference.get("recompile_exec_ns_median")
        all_apply_site_counts = reference.get("site_counts") or {}
        candidate_families = [
            family for family in family_order if int(all_apply_site_counts.get(family, 0) or 0) > 0
        ]

        per_benchmark_rows: list[dict[str, Any]] = []
        for family in family_order:
            run_record = (benchmark.get("family_runs") or {}).get(family)
            recompile_median = run_median(run_record)
            recompile_obs = run_record.get("recompile_observation", {}) if isinstance(run_record, dict) else {}
            ratio_stock = None
            if stock_median not in (None, 0) and recompile_median not in (None, 0):
                ratio_stock = float(stock_median) / float(recompile_median)
            ratio_blind = None
            if all_apply_median not in (None, 0) and recompile_median not in (None, 0):
                ratio_blind = float(all_apply_median) / float(recompile_median)
            row = {
                "name": benchmark["name"],
                "benchmark_family": benchmark.get("family"),
                "family": family,
                "stock_exec_ns_median": stock_median,
                "recompile_exec_ns_median": recompile_median,
                "all_apply_exec_ns_median": all_apply_median,
                "ratio_stock_over_recompile": ratio_stock,
                "ratio_all_apply_exec_over_recompile": ratio_blind,
                "ratio_status": ratio_status(ratio_stock),
                "stock_status": stock_status,
                "recompile_status": run_record.get("status") if isinstance(run_record, dict) else "missing",
                "all_apply_status": reference.get("recompile_status", "missing"),
                "recompile_applied": bool(recompile_obs.get("applied")),
                "recompile_total_sites": int(recompile_obs.get("total_sites", 0) or 0),
                "eligible_sites_in_all_apply": int(all_apply_site_counts.get(family, 0) or 0),
                "candidate_families_in_all_apply": candidate_families,
            }
            family_rows[family].append(row)
            if ratio_stock is not None:
                per_benchmark_rows.append(row)

        applied_rows = [row for row in per_benchmark_rows if row["recompile_applied"]]
        if len(candidate_families) >= 2 and all_apply_median not in (None, 0) and applied_rows:
            best_single = max(applied_rows, key=lambda row: float(row["ratio_stock_over_recompile"]))
            best_single_counter[best_single["family"]] += 1
            best_exec = best_single["recompile_exec_ns_median"]
            if best_exec not in (None, 0):
                all_apply_over_best_single = float(best_exec) / float(all_apply_median)
                best_single_over_all_apply = float(all_apply_median) / float(best_exec)
                interaction_rows.append(
                    {
                        "name": benchmark["name"],
                        "benchmark_family": benchmark.get("family"),
                        "best_single_family": best_single["family"],
                        "best_single_stock_over_recompile": best_single["ratio_stock_over_recompile"],
                        "all_apply_stock_over_recompile": reference.get("ratio_stock_over_recompile"),
                        "best_single_exec_ns_median": best_exec,
                        "all_apply_exec_ns_median": all_apply_median,
                        "all_apply_over_best_single": all_apply_over_best_single,
                        "best_single_over_all_apply": best_single_over_all_apply,
                        "candidate_families_in_all_apply": candidate_families,
                    }
                )

    family_summaries: list[dict[str, Any]] = []
    for family in family_order:
        rows = family_rows[family]
        rows_by_name = {row["name"]: row for row in rows}
        applied_rows = [row for row in rows if row["recompile_applied"]]
        valid_stock_ratios = [
            float(row["ratio_stock_over_recompile"])
            for row in rows
            if row["ratio_stock_over_recompile"] is not None
        ]
        valid_blind_ratios = [
            float(row["ratio_all_apply_exec_over_recompile"])
            for row in rows
            if row["ratio_all_apply_exec_over_recompile"] is not None
        ]
        wins = sum(1 for row in rows if row["ratio_stock_over_recompile"] is not None and row["ratio_stock_over_recompile"] > 1.0)
        losses = sum(1 for row in rows if row["ratio_stock_over_recompile"] is not None and row["ratio_stock_over_recompile"] < 1.0)
        ties = sum(1 for row in rows if row["ratio_stock_over_recompile"] == 1.0)
        top_wins = sorted(
            [
                row
                for row in applied_rows
                if row["ratio_stock_over_recompile"] is not None and row["ratio_stock_over_recompile"] > 1.0
            ],
            key=lambda row: float(row["ratio_stock_over_recompile"]),
            reverse=True,
        )[:5]
        top_losses = sorted(
            [
                row
                for row in applied_rows
                if row["ratio_stock_over_recompile"] is not None and row["ratio_stock_over_recompile"] < 1.0
            ],
            key=lambda row: float(row["ratio_stock_over_recompile"]),
        )[:5]
        better_than_blind = sorted(
            [
                row
                for row in applied_rows
                if row["ratio_all_apply_exec_over_recompile"] is not None and row["ratio_all_apply_exec_over_recompile"] > 1.0
            ],
            key=lambda row: float(row["ratio_all_apply_exec_over_recompile"]),
            reverse=True,
        )[:5]
        worse_than_blind = sorted(
            [
                row
                for row in applied_rows
                if row["ratio_all_apply_exec_over_recompile"] is not None and row["ratio_all_apply_exec_over_recompile"] < 1.0
            ],
            key=lambda row: float(row["ratio_all_apply_exec_over_recompile"]),
        )[:5]
        family_summaries.append(
            {
                "family": family,
                "benchmarks": len(rows),
                "valid_pairs": len(valid_stock_ratios),
                "applied_pairs": sum(
                    1
                    for row in rows
                    if row["ratio_stock_over_recompile"] is not None and row["recompile_applied"]
                ),
                "site_positive_benchmarks": sum(
                    1 for row in rows if row["eligible_sites_in_all_apply"] > 0
                ),
                "selected_total_sites": sum(int(row["recompile_total_sites"]) for row in rows),
                "geomean_stock_over_recompile": geometric_mean(valid_stock_ratios),
                "geomean_all_apply_exec_over_recompile": geometric_mean(valid_blind_ratios),
                "wins": wins,
                "losses": losses,
                "ties": ties,
                "top_wins": top_wins,
                "top_losses": top_losses,
                "better_than_blind_all_apply": better_than_blind,
                "worse_than_blind_all_apply": worse_than_blind,
                "focus_notes": summarize_focus_rows(rows_by_name, FAMILY_FOCUS.get(family, ())),
                "best_single_benchmark_count": int(best_single_counter.get(family, 0)),
            }
        )

    positive_interactions = sorted(
        [row for row in interaction_rows if row["all_apply_over_best_single"] > 1.0],
        key=lambda row: float(row["all_apply_over_best_single"]),
        reverse=True,
    )[:10]
    negative_interactions = sorted(
        [row for row in interaction_rows if row["best_single_over_all_apply"] > 1.0],
        key=lambda row: float(row["best_single_over_all_apply"]),
        reverse=True,
    )[:10]

    return {
        "families": family_summaries,
        "interaction": {
            "benchmarks_compared": len(interaction_rows),
            "best_single_benchmark_count": dict(best_single_counter),
            "positive_complementarity": positive_interactions,
            "negative_interference": negative_interactions,
        },
    }


def render_compact_rows(
    rows: list[dict[str, Any]],
    *,
    ratio_key: str,
    limit: int = 3,
) -> str:
    if not rows:
        return "n/a"
    return ", ".join(
        f"`{row['name']}` {format_ratio(row[ratio_key])}"
        for row in rows[:limit]
    )


def render_markdown(results: dict[str, Any]) -> str:
    summary = results.get("summary", {})
    family_summaries = summary.get("families", [])
    interaction = summary.get("interaction", {})
    all_apply_summary = (results.get("all_apply_reference") or {}).get("summary", {})

    lines = [
        "# Kernel Recompile Per-Family Ablation",
        "",
        "## Methodology",
        "",
        f"- Family policies: `{', '.join(entry['name'] for entry in results.get('families', []))}` via benchmark-local v3 allowlists generated from scanner manifests",
        f"- Benchmarks: `{len(results.get('benchmarks', []))}` from `config/micro_pure_jit.yaml`",
        f"- Stock sampling: `{results['defaults']['warmups']} / {results['defaults']['iterations']} / {results['defaults']['repeat']}` (warmups / iterations / repeat)",
        f"- Guest kernel: `{(results.get('guest_host') or {}).get('kernel_version', 'unknown')}`",
        f"- Guest CPU pinning: `taskset -c {results['defaults']['cpu']}`",
        f"- VM command shape: `vng --run {results['vm']['kernel']} --memory {results['vm']['memory']} --cpus {results['vm']['cpus']} --exec ...`",
        f"- Blind all-apply reference: `{results['all_apply_reference']['path']}` (`{format_ratio(all_apply_summary.get('overall', {}).get('geomean_stock_over_recompile'))}` stock/recompile, strict `2/10/500`)",
        f"- Blind/family ratios below are `all-apply exec / single-family exec`; values `>1` mean the single-family run is faster than blind all-apply.",
        "",
        "## Per-Family Geomean",
        "",
        "| Family | Site-Positive Benches | Applied | Stock/Family | Blind/Fam Exec | Wins | Losses | Ties | Best-Single Wins |",
        "| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |",
    ]

    for row in family_summaries:
        lines.append(
            "| {family} | {site_positive_benchmarks} | {applied_pairs} | {stock_geo} | {blind_geo} | {wins} | {losses} | {ties} | {best_single_benchmark_count} |".format(
                family=row["family"],
                site_positive_benchmarks=row["site_positive_benchmarks"],
                applied_pairs=row["applied_pairs"],
                stock_geo=format_ratio(row["geomean_stock_over_recompile"]),
                blind_geo=format_ratio(row["geomean_all_apply_exec_over_recompile"]),
                wins=row["wins"],
                losses=row["losses"],
                ties=row["ties"],
                best_single_benchmark_count=row["best_single_benchmark_count"],
            )
        )

    lines.extend(
        [
            "",
            "## Top Wins / Losses",
            "",
        ]
    )

    for row in family_summaries:
        lines.extend(
            [
                f"### `{row['family']}`",
                "",
                f"- Headline: stock/family geomean `{format_ratio(row['geomean_stock_over_recompile'])}`, blind/family exec geomean `{format_ratio(row['geomean_all_apply_exec_over_recompile'])}`, applied `{row['applied_pairs']}` benches, selected `{row['selected_total_sites']}` sites.",
                f"- Focus: {'; '.join(row['focus_notes']) if row['focus_notes'] else 'n/a'}",
                f"- Top wins vs stock: {render_compact_rows(row['top_wins'], ratio_key='ratio_stock_over_recompile')}",
                f"- Top losses vs stock: {render_compact_rows(row['top_losses'], ratio_key='ratio_stock_over_recompile')}",
                f"- Faster than blind all-apply: {render_compact_rows(row['better_than_blind_all_apply'], ratio_key='ratio_all_apply_exec_over_recompile')}",
                f"- Slower than blind all-apply: {render_compact_rows(row['worse_than_blind_all_apply'], ratio_key='ratio_all_apply_exec_over_recompile')}",
                "",
            ]
        )

    lines.extend(
        [
            "## Family Interaction Analysis",
            "",
            f"- Benchmarks with at least one valid single-family run and a valid blind all-apply reference: `{interaction.get('benchmarks_compared', 0)}`",
        ]
    )

    best_single_counts = interaction.get("best_single_benchmark_count", {})
    if best_single_counts:
        ranking = ", ".join(
            f"`{family}` {count}"
            for family, count in sorted(best_single_counts.items(), key=lambda item: (-int(item[1]), item[0]))
        )
        lines.append(f"- Best single-family winner count: {ranking}")
    else:
        lines.append("- Best single-family winner count: n/a")

    positive_rows = interaction.get("positive_complementarity", [])
    if positive_rows:
        lines.append("- Strongest positive complementarity (blind all-apply faster than the best single family):")
        for row in positive_rows[:5]:
            lines.append(
                f"  - `{row['name']}`: blind beat best-single `{row['best_single_family']}` by `{format_ratio(row['all_apply_over_best_single'])}`; candidate families `{', '.join(row['candidate_families_in_all_apply']) or '-'}`."
            )
    else:
        lines.append("- Strongest positive complementarity: none")

    negative_rows = interaction.get("negative_interference", [])
    if negative_rows:
        lines.append("- Strongest negative interference (best single family faster than blind all-apply):")
        for row in negative_rows[:5]:
            lines.append(
                f"  - `{row['name']}`: best-single `{row['best_single_family']}` beat blind by `{format_ratio(row['best_single_over_all_apply'])}`; candidate families `{', '.join(row['candidate_families_in_all_apply']) or '-'}`."
            )
    else:
        lines.append("- Strongest negative interference: none")

    lines.append("")
    return "\n".join(lines)


def checkpoint(results: dict[str, Any], output_json: Path, output_md: Path) -> None:
    results["summary"] = build_summary(results)
    output_json.parent.mkdir(parents=True, exist_ok=True)
    output_md.parent.mkdir(parents=True, exist_ok=True)
    output_json.write_text(json.dumps(results, indent=2) + "\n")
    output_md.write_text(render_markdown(results))


def run_guest_mode(args: argparse.Namespace) -> int:
    if not args.benches or len(args.benches) != 1:
        raise SystemExit("--guest-mode requires exactly one --bench")
    if not args.runtime:
        raise SystemExit("--guest-mode requires --runtime")
    if not args.output:
        raise SystemExit("--guest-mode requires --output")

    suite = load_suite(Path(args.suite))
    benchmark = select_benchmarks(args.benches, suite)[0]
    memory_file = resolve_memory_file(benchmark, False)
    policy_file = Path(args.policy_file).resolve() if args.policy_file else None

    command = build_micro_benchmark_command(
        suite.build.runner_binary,
        runtime_mode=args.runtime,
        program=benchmark.program_object,
        io_mode=benchmark.io_mode,
        repeat=args.repeat,
        memory=memory_file,
        input_size=benchmark.kernel_input_size,
        policy_file=policy_file,
        perf_counters=False,
        perf_scope="full_repeat_raw",
        require_sudo=True,
    )

    run_record: dict[str, Any] = {
        "runtime": "kernel" if args.runtime == "kernel" else "kernel-recompile",
        "label": "kernel" if args.runtime == "kernel" else "kernel-recompile",
        "mode": args.runtime,
        "repeat": args.repeat,
        "command": command,
        "measurement_complete": False,
        "status": "pending",
        "failures": [],
        "samples": [],
        "artifacts": {
            "program_object": str(benchmark.program_object),
            "policy_file": str(policy_file) if policy_file is not None else None,
        },
    }

    failed = False
    for warmup_index in range(args.warmups):
        sample, failure = execute_sample(
            command=command,
            cpu=args.cpu,
            expected_result=benchmark.expected_result,
            phase="warmup",
            iteration_index=warmup_index,
        )
        if failure is not None:
            run_record["status"] = failure["reason"]
            run_record["failures"].append(failure)
            if sample is not None:
                run_record["samples"].append(sample)
            failed = True
            break

    if not failed:
        for iteration_index in range(args.iterations):
            sample, failure = execute_sample(
                command=command,
                cpu=args.cpu,
                expected_result=benchmark.expected_result,
                phase="measure",
                iteration_index=iteration_index,
            )
            if sample is not None:
                sample["iteration_index"] = iteration_index
                run_record["samples"].append(sample)
            if failure is not None:
                run_record["status"] = failure["reason"]
                run_record["failures"].append(failure)
                failed = True
                break

    if not failed and len(run_record["samples"]) == args.iterations:
        run_record["measurement_complete"] = True
        run_record["status"] = "ok"

    summarize_run(run_record)
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "host": guest_host_snapshot(args.cpu),
        "defaults": {
            "iterations": args.iterations,
            "warmups": args.warmups,
            "repeat": args.repeat,
            "cpu": args.cpu,
        },
        "benchmark": {
            **benchmark_metadata(benchmark),
            "run": run_record,
        },
    }

    output_path = Path(args.output).resolve()
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(json.dumps(payload, indent=2) + "\n")
    median = run_record.get("exec_ns", {}).get("median")
    applied = run_record.get("recompile_observation", {}).get("applied")
    print(
        f"[guest] {benchmark.name} runtime={args.runtime} status={run_record['status']} exec={format_ns(median)} applied={applied}",
        flush=True,
    )
    print(f"[guest] wrote {output_path}", flush=True)
    return 0


def run_host_mode(args: argparse.Namespace) -> int:
    families = select_families(args.families)
    scanner = Path(args.scanner).resolve()
    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    per_bench_dir = Path(args.per_bench_dir).resolve()
    per_bench_dir.mkdir(parents=True, exist_ok=True)
    if not scanner.exists():
        raise SystemExit(f"scanner not found: {scanner}")

    all_apply_reference = load_all_apply_reference(Path(args.all_apply_json).resolve())
    suite = load_suite(Path(args.suite))
    benchmarks = select_benchmarks(args.benches, suite)
    results = load_or_initialize_results(
        output_json=output_json,
        suite=suite,
        families=families,
        args=args,
        all_apply_reference=all_apply_reference,
    )

    completed_stock = sum(1 for entry in results.get("benchmarks", []) if entry.get("stock_run"))
    print(
        f"[host] benchmarks={len(benchmarks)} families={len(families)} existing-stock={completed_stock}",
        flush=True,
    )

    for benchmark in benchmarks:
        entry = ensure_benchmark_entry(
            results=results,
            benchmark=benchmark,
            all_apply_reference=all_apply_reference,
        )

        if not entry.get("stock_run"):
            stock_json = guest_output_path(per_bench_dir, "stock", benchmark.name)
            stock_log = guest_log_path(per_bench_dir, "stock", benchmark.name)
            stock_json.parent.mkdir(parents=True, exist_ok=True)
            stock_log.parent.mkdir(parents=True, exist_ok=True)
            stock_json.unlink(missing_ok=True)
            stock_log.unlink(missing_ok=True)
            print(f"[stock] {benchmark.name}", flush=True)
            try:
                completed = run_vm(
                    build_guest_exec(
                        benchmark_name=benchmark.name,
                        runtime_mode="kernel",
                        output_path=stock_json,
                        log_path=stock_log,
                        args=args,
                    ),
                    args,
                )
            except subprocess.TimeoutExpired:
                entry["stock_run"] = synthesize_failure_from_vm(
                    benchmark=benchmark,
                    runtime_mode="kernel",
                    repeat=args.repeat,
                    completed=None,
                    log_path=stock_log,
                    timed_out=True,
                )
            else:
                if stock_json.exists():
                    integrate_guest_payload(
                        entry=entry,
                        runtime_mode="kernel",
                        family=None,
                        payload=json.loads(stock_json.read_text()),
                        results=results,
                    )
                    print(f"  [ok] vm exit={completed.returncode}", flush=True)
                else:
                    entry["stock_run"] = synthesize_failure_from_vm(
                        benchmark=benchmark,
                        runtime_mode="kernel",
                        repeat=args.repeat,
                        completed=completed,
                        log_path=stock_log,
                    )
                    print(f"  [warn] no guest JSON (vm exit={completed.returncode})", flush=True)
            checkpoint(results, output_json, output_md)

        for family in families:
            family_runs = entry.setdefault("family_runs", {})
            if family in family_runs:
                continue

            policy_file = (
                per_bench_dir
                / "generated_policies"
                / family
                / f"{benchmark.name}.yaml"
            )
            generate_family_policy_file(
                scanner=scanner,
                benchmark=benchmark,
                family=family,
                output_path=policy_file,
                timeout_seconds=args.timeout,
            )
            family_json = guest_output_path(per_bench_dir, family, benchmark.name)
            family_log = guest_log_path(per_bench_dir, family, benchmark.name)
            family_json.parent.mkdir(parents=True, exist_ok=True)
            family_log.parent.mkdir(parents=True, exist_ok=True)
            family_json.unlink(missing_ok=True)
            family_log.unlink(missing_ok=True)

            print(f"[family] {family} {benchmark.name}", flush=True)
            try:
                completed = run_vm(
                    build_guest_exec(
                        benchmark_name=benchmark.name,
                        runtime_mode="kernel-recompile",
                        output_path=family_json,
                        log_path=family_log,
                        args=args,
                        policy_file=policy_file,
                    ),
                    args,
                )
            except subprocess.TimeoutExpired:
                family_runs[family] = synthesize_failure_from_vm(
                    benchmark=benchmark,
                    runtime_mode="kernel-recompile",
                    repeat=args.repeat,
                    completed=None,
                    log_path=family_log,
                    policy_file=policy_file,
                    timed_out=True,
                )
            else:
                if family_json.exists():
                    integrate_guest_payload(
                        entry=entry,
                        runtime_mode="kernel-recompile",
                        family=family,
                        payload=json.loads(family_json.read_text()),
                        results=results,
                    )
                    print(f"  [ok] vm exit={completed.returncode}", flush=True)
                else:
                    family_runs[family] = synthesize_failure_from_vm(
                        benchmark=benchmark,
                        runtime_mode="kernel-recompile",
                        repeat=args.repeat,
                        completed=completed,
                        log_path=family_log,
                        policy_file=policy_file,
                    )
                    print(f"  [warn] no guest JSON (vm exit={completed.returncode})", flush=True)

            checkpoint(results, output_json, output_md)
            family_run = family_runs[family]
            median = family_run.get("exec_ns", {}).get("median")
            applied = family_run.get("recompile_observation", {}).get("applied")
            print(
                f"  [summary] status={family_run['status']} exec={format_ns(median)} applied={applied}",
                flush=True,
            )

    checkpoint(results, output_json, output_md)
    print(f"[done] wrote {output_json}", flush=True)
    print(f"[done] wrote {output_md}", flush=True)
    return 0


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    if args.guest_mode:
        return run_guest_mode(args)
    return run_host_mode(args)


if __name__ == "__main__":
    raise SystemExit(main())
