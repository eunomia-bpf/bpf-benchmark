#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import platform
import random
import subprocess
import sys
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

REPO_ROOT = Path(__file__).resolve().parent.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

try:
    from benchmark_catalog import CONFIG_PATH, ROOT_DIR, RuntimeSpec, SuiteSpec, load_suite
except ImportError:
    from micro.benchmark_catalog import CONFIG_PATH, ROOT_DIR, RuntimeSpec, SuiteSpec, load_suite

from runner.libs import smoke_output_path
from runner.libs.batch_runner import run_batch_runner
from runner.libs.benchmarks import resolve_memory_file, select_benchmarks
from runner.libs.environment import (
    require_existing_paths,
    read_optional_text,
    read_required_text,
    validate_publication_environment,
)
from runner.libs.results import (
    derive_perf_metrics,
    ns_summary,
    summarize_named_counters,
    summarize_optional_ns,
    summarize_perf_counter_meta,
    summarize_phase_timings,
)

from runner.libs.run_artifacts import (
    ArtifactSession,
    derive_run_type,
    externalize_sample_daemon_debug,
    repo_relative_path,
    sanitize_artifact_token,
    summarize_benchmark_results,
)


DEFAULT_RUNTIME_ORDER_SEED = 0


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run declarative micro benchmark suites.")
    parser.add_argument("--suite", default=str(CONFIG_PATH), help="Path to suite YAML.")
    parser.add_argument("--bench", action="append", dest="benches", help="Benchmark name.")
    parser.add_argument("--runtime", action="append", dest="runtimes", help="Runtime name.")
    parser.add_argument("--iterations", type=int, help="Measured runs per pair.")
    parser.add_argument("--warmups", type=int, help="Warmup runs per pair.")
    parser.add_argument("--repeat", type=int, help="Repeat count inside each helper sample.")
    parser.add_argument(
        "--rejit",
        action="store_true",
        help="Enable REJIT same-bytecode mode for kernel-rejit runtimes.",
    )
    parser.add_argument(
        "--daemon-socket",
        default=None,
        help=(
            "Path to a Unix socket for a running bpfrejit-daemon serve instance. "
            "When set, micro_exec connects to the daemon over the socket instead of "
            "forking a new process for each optimization."
        ),
    )
    parser.add_argument("--output", help="Override JSON output path.")
    parser.add_argument("--cpu", help="Pin child processes to a specific CPU via taskset.")
    parser.add_argument(
        "--strict-env",
        action="store_true",
        help="Fail if environment is not publication-grade",
    )
    parser.add_argument(
        "--shuffle-seed",
        type=int,
        help="Shuffle benchmark order with a reproducible seed.",
    )
    parser.add_argument(
        "--perf-counters",
        action="store_true",
        help="Collect perf_event counters across the full repeated run when available.",
    )
    parser.add_argument(
        "--perf-scope",
        default="full_repeat_raw",
        choices=["full_repeat_raw", "full_repeat_avg"],
        help="PMU scope: full_repeat_raw (default, raw totals) or full_repeat_avg (cumulative counters divided by repeat).",
    )
    parser.add_argument(
        "--regenerate-inputs",
        action="store_true",
        help="Force regeneration of generated inputs.",
    )
    parser.add_argument(
        "--pgo-warmup-repeat",
        type=int,
        default=10,
        help=(
            "Repeat count for the PGO warmup run before kernel-rejit optimization. "
            "A short kernel-only execution lets the daemon collect PMU profiling data. "
            "Set to 0 to disable PGO warmup. Default: 10."
        ),
    )
    parser.add_argument(
        "--write-details",
        action="store_true",
        help="Write per-sample live_samples/daemon_debug detail artifacts. Disabled by default for faster runs.",
    )
    parser.add_argument("--list", action="store_true", help="List benchmarks and runtimes.")
    return parser.parse_args(sys.argv[1:] if argv is None else argv)


def format_ns(value: float | int | None) -> str:
    if value is None:
        return "n/a"
    if abs(value - round(value)) < 1e-9:
        value = int(round(value))
    if value >= 1_000_000:
        return f"{value / 1_000_000:.3f} ms"
    if value >= 1_000:
        return f"{value / 1_000:.3f} us"
    return f"{value} ns"


def micro_batch_parallel_jobs() -> int:
    return max(1, int((os.cpu_count() or 1) * 0.8))


def runtime_supports_prepared_state(runtime_mode: str) -> bool:
    return runtime_mode in {"kernel", "kernel-rejit", "kernel_rejit"}

def build_micro_batch_job(
    *,
    job_id: str,
    runtime_mode: str,
    program: Path | str,
    io_mode: str,
    repeat: int,
    memory: Path | str | None = None,
    input_size: int | None = None,
    perf_counters: bool = False,
    perf_scope: str = "full_repeat_raw",
    daemon_socket: str | None = None,
    compile_only: bool = False,
    prepared_key: str | None = None,
    prepared_ref: str | None = None,
    prepared_group: str | None = None,
) -> dict[str, Any]:
    job: dict[str, Any] = {
        "id": job_id,
        "type": "test_run",
        "execution": "parallel" if compile_only else "serial",
        "runtime": runtime_mode,
        "program": str(program),
        "io_mode": io_mode,
        "repeat": max(1, repeat),
        "compile_only": compile_only,
    }
    if memory is not None:
        job["memory"] = str(memory)
    if input_size is not None and input_size > 0:
        job["input_size"] = input_size
    if perf_counters:
        job["perf_counters"] = True
        job["perf_scope"] = perf_scope
    if daemon_socket is not None:
        job["daemon_socket"] = daemon_socket
    if prepared_key is not None:
        job["prepared_key"] = prepared_key
    if prepared_ref is not None:
        job["prepared_ref"] = prepared_ref
    if prepared_group is not None:
        job["prepared_group"] = prepared_group
    return job


def read_git_sha() -> str:
    try:
        return subprocess.check_output(
            ["git", "rev-parse", "HEAD"],
            cwd=ROOT_DIR,
            stderr=subprocess.DEVNULL,
        ).decode().strip()
    except (FileNotFoundError, subprocess.CalledProcessError):
        return "unknown"


def _git_rev_parse(repo_dir: Path, short: bool = False) -> str:
    args = ["git", "rev-parse", "--short", "HEAD"] if short else ["git", "rev-parse", "HEAD"]
    try:
        return subprocess.check_output(args, cwd=repo_dir, stderr=subprocess.DEVNULL).decode().strip()
    except (FileNotFoundError, subprocess.CalledProcessError):
        return "unknown"


def _git_is_dirty(repo_dir: Path) -> bool:
    try:
        completed = subprocess.run(
            ["git", "status", "--porcelain"],
            cwd=repo_dir,
            capture_output=True,
            text=True,
            check=False,
        )
    except OSError:
        return False
    if completed.returncode != 0:
        return False
    return bool(completed.stdout.strip())


def _read_cpu_model() -> str:
    try:
        for line in Path("/proc/cpuinfo").read_text().splitlines():
            if line.startswith("model name"):
                return line.split(":", 1)[1].strip()
    except OSError:
        pass
    return platform.processor() or "unknown"


def _detect_environment() -> str:
    indicators = [
        "/sys/class/dmi/id/sys_vendor",
        "/sys/class/dmi/id/product_name",
        "/sys/class/dmi/id/board_vendor",
    ]
    vm_keywords = {"kvm", "qemu", "vmware", "virtualbox", "xen", "vng", "virtio", "bochs", "hyper-v"}
    for path in indicators:
        try:
            value = Path(path).read_text().lower()
            if any(keyword in value for keyword in vm_keywords):
                return "vm"
        except OSError:
            pass
    try:
        for line in Path("/proc/cpuinfo").read_text().splitlines():
            if line.startswith("flags") and "hypervisor" in line:
                return "vm"
    except OSError:
        pass
    return "bare-metal"


def collect_provenance(
    args: argparse.Namespace,
    iterations: int,
    warmups: int,
) -> dict[str, object]:
    linux_dir = ROOT_DIR / "vendor" / "linux-framework"
    kernel_commit = _git_rev_parse(linux_dir) if linux_dir.is_dir() else "unknown"

    daemon_dir = ROOT_DIR / "daemon"
    daemon_commit = _git_rev_parse(daemon_dir) if daemon_dir.is_dir() else "unknown"

    repo_git_sha = _git_rev_parse(ROOT_DIR)
    repo_dirty = _git_is_dirty(ROOT_DIR)

    return {
        "kernel_commit": kernel_commit,
        "daemon_commit": daemon_commit,
        "repo_git_sha": repo_git_sha,
        "repo_dirty": repo_dirty,
        "params": {
            "iterations": iterations,
            "warmups": warmups,
            "repeat": args.repeat,
        },
        "cpu_model": _read_cpu_model(),
        "environment": _detect_environment(),
        "timestamp": datetime.now(timezone.utc).isoformat(),
    }


def list_suite(suite: SuiteSpec) -> None:
    print("Benchmarks")
    print("----------")
    for benchmark in suite.benchmarks.values():
        tags = ",".join(benchmark.tags)
        family = benchmark.family or "-"
        level = benchmark.level or "-"
        print(f"{benchmark.name:20} {benchmark.category:18} {benchmark.io_mode:8} {family:16} {level:8} {tags}")

    print()
    print("Runtimes")
    print("--------")
    for runtime in suite.runtimes.values():
        aliases = f" (aliases: {', '.join(runtime.aliases)})" if runtime.aliases else ""
        print(f"{runtime.name:12} {runtime.label}{aliases}")


def select_runtimes(names: list[str] | None, suite: SuiteSpec) -> list[RuntimeSpec]:
    requested = names or list(suite.defaults.runtimes)
    selected: list[RuntimeSpec] = []
    for raw_name in requested:
        name = suite.runtime_aliases.get(raw_name, raw_name)
        if name not in suite.runtimes:
            raise SystemExit(f"unknown runtime: {raw_name}")
        selected.append(suite.runtimes[name])
    return selected


def require_suite_artifacts(suite: SuiteSpec) -> None:
    required_paths = [suite.build.runner_binary]
    required_paths.extend(benchmark.program_object for benchmark in suite.benchmarks.values())
    require_existing_paths(required_paths)


def attach_baseline_adjustments(results: dict[str, object], baseline_benchmark: str | None) -> None:
    if not baseline_benchmark:
        return

    benchmarks = results.get("benchmarks", [])
    baseline_record = next((record for record in benchmarks if record.get("name") == baseline_benchmark), None)
    if baseline_record is None:
        return

    baseline_io_mode = baseline_record.get("io_mode")
    runtime_baselines: dict[str, float] = {}
    for run in baseline_record.get("runs", []):
        median = run.get("exec_ns", {}).get("median")
        if median is not None:
            runtime_baselines[str(run["runtime"])] = float(median)

    for benchmark in benchmarks:
        benchmark_io_mode = benchmark.get("io_mode")
        baseline_applies = benchmark_io_mode == baseline_io_mode
        for run in benchmark.get("runs", []):
            baseline_exec = runtime_baselines.get(str(run["runtime"])) if baseline_applies else None
            median_exec = run.get("exec_ns", {}).get("median")
            adjusted = None
            ratio = None
            if baseline_exec is not None and median_exec is not None:
                adjusted = max(float(median_exec) - baseline_exec, 0.0)
                if baseline_exec != 0:
                    ratio = float(median_exec) / baseline_exec
            run["baseline_adjustment"] = {
                "baseline_benchmark": baseline_benchmark,
                "baseline_io_mode": baseline_io_mode,
                "applied": baseline_applies,
                "baseline_exec_ns": baseline_exec,
                "median_minus_baseline_ns": adjusted,
                "median_over_baseline_ratio": ratio,
            }
            if not baseline_applies:
                run["baseline_adjustment"]["reason"] = (
                    f"skipped: benchmark io_mode {benchmark_io_mode} does not match baseline io_mode {baseline_io_mode}"
                )

    for benchmark in benchmarks:
        runtime_runs = {str(run["runtime"]): run for run in benchmark.get("runs", [])}
        llvm = runtime_runs.get("llvmbpf")
        kernel = runtime_runs.get("kernel")
        if llvm is None or kernel is None:
            continue

        llvm_exec = llvm.get("exec_ns", {}).get("median")
        kernel_exec = kernel.get("exec_ns", {}).get("median")
        llvm_adjusted = llvm.get("baseline_adjustment", {}).get("median_minus_baseline_ns")
        kernel_adjusted = kernel.get("baseline_adjustment", {}).get("median_minus_baseline_ns")

        raw_ratio = None
        adjusted_ratio = None
        if llvm_exec not in (None, 0) and kernel_exec not in (None, 0):
            raw_ratio = float(llvm_exec) / float(kernel_exec)
        if llvm_adjusted not in (None, 0) and kernel_adjusted not in (None, 0):
            adjusted_ratio = float(llvm_adjusted) / float(kernel_adjusted)

        benchmark["runtime_comparison"] = {
            "llvmbpf_over_kernel_exec_ratio": raw_ratio,
            "llvmbpf_over_kernel_adjusted_exec_ratio": adjusted_ratio,
        }


def build_run_metadata(
    results: dict[str, Any],
    *,
    output_hint: Path,
    run_type: str,
    daemon_debug_entries: int,
) -> dict[str, Any]:
    metadata = summarize_benchmark_results(results)
    metadata["run_type"] = run_type
    metadata["output_hint"] = repo_relative_path(output_hint)
    metadata["paper_summary"]["daemon_debug_entries"] = daemon_debug_entries
    return metadata


def _live_sample_relative_path(
    benchmark_name: str,
    runtime_name: str,
    *,
    iteration_index: int | None,
    sample_index: int,
) -> str:
    iter_suffix = (
        f"iter{iteration_index:02d}"
        if isinstance(iteration_index, int)
        else f"sample{sample_index:02d}"
    )
    basename = (
        f"{sanitize_artifact_token(benchmark_name)}__"
        f"{sanitize_artifact_token(runtime_name)}__{iter_suffix}.json"
    )
    return f"live_samples/{basename}"


def build_micro_batch_plan(
    *,
    benchmarks: list[Any],
    runtimes: list[RuntimeSpec],
    suite: SuiteSpec,
    args: argparse.Namespace,
    runtime_order_seed: int,
    warmups: int,
) -> tuple[dict[str, Any], dict[str, dict[str, Any]], dict[str, Path | None]]:
    jobs: list[dict[str, Any]] = []
    plans: dict[str, dict[str, Any]] = {}
    memory_files: dict[str, Path | None] = {}
    parallel_jobs = micro_batch_parallel_jobs()
    measurement_entries: list[dict[str, Any]] = []

    for benchmark in benchmarks:
        memory_file = resolve_memory_file(benchmark, args.regenerate_inputs)
        memory_files[benchmark.name] = memory_file
        bench_plan = {
            "iteration_runtime_orders": [],
            "measurement_job_ids": {runtime.name: [] for runtime in runtimes},
        }

        for runtime in runtimes:
            repeat = args.repeat if args.repeat is not None else runtime.default_repeat
            is_rejit_runtime = runtime.mode in {"kernel-rejit", "kernel_rejit"}
            daemon_socket = getattr(args, "daemon_socket", None)
            pgo_warmup_repeat = getattr(args, "pgo_warmup_repeat", 10)

            for warmup_index in range(warmups):
                jobs.append(
                    build_micro_batch_job(
                        job_id=f"{benchmark.name}::{runtime.name}::warmup::{warmup_index}",
                        runtime_mode=runtime.mode,
                        program=benchmark.program_object,
                        io_mode=benchmark.io_mode,
                        repeat=repeat,
                        memory=memory_file,
                        input_size=benchmark.kernel_input_size,
                        perf_counters=args.perf_counters,
                        perf_scope=args.perf_scope,
                        daemon_socket=daemon_socket if is_rejit_runtime else None,
                    )
                )

        iterations = args.iterations if args.iterations is not None else suite.defaults.iterations
        for iteration_idx in range(iterations):
            if len(runtimes) == 2:
                ordered = list(runtimes) if iteration_idx % 2 == 0 else list(reversed(runtimes))
            else:
                rng = random.Random(runtime_order_seed + iteration_idx)
                ordered = list(runtimes)
                rng.shuffle(ordered)
            bench_plan["iteration_runtime_orders"].append([runtime.name for runtime in ordered])
            for runtime in ordered:
                repeat = args.repeat if args.repeat is not None else runtime.default_repeat
                is_rejit_runtime = runtime.mode in {"kernel-rejit", "kernel_rejit"}
                daemon_socket = getattr(args, "daemon_socket", None)
                pgo_warmup_repeat = getattr(args, "pgo_warmup_repeat", 10)
                job_id = f"{benchmark.name}::{runtime.name}::measure::{iteration_idx}"
                measurement_entries.append(
                    {
                        "job_id": job_id,
                        "runtime_mode": runtime.mode,
                        "program": benchmark.program_object,
                        "io_mode": benchmark.io_mode,
                        "repeat": repeat,
                        "memory": memory_file,
                        "input_size": benchmark.kernel_input_size,
                        "daemon_socket": daemon_socket if is_rejit_runtime else None,
                        "perf_counters": args.perf_counters,
                        "perf_scope": args.perf_scope,
                        "pgo_job": (
                            build_micro_batch_job(
                                job_id=f"{benchmark.name}::{runtime.name}::pgo",
                                runtime_mode="kernel",
                                program=benchmark.program_object,
                                io_mode=benchmark.io_mode,
                                repeat=pgo_warmup_repeat,
                                memory=memory_file,
                                input_size=benchmark.kernel_input_size,
                            )
                            if is_rejit_runtime
                            and daemon_socket
                            and pgo_warmup_repeat > 0
                            and iteration_idx == 0
                            else None
                        ),
                    }
                )
                bench_plan["measurement_job_ids"][runtime.name].append(job_id)

        plans[benchmark.name] = bench_plan

    for window_start in range(0, len(measurement_entries), parallel_jobs):
        window = measurement_entries[window_start : window_start + parallel_jobs]
        window_group = f"window-{window_start // parallel_jobs:04d}"
        prepared_entries = [
            entry for entry in window if runtime_supports_prepared_state(entry["runtime_mode"])
        ]
        direct_entries = [
            entry for entry in window if not runtime_supports_prepared_state(entry["runtime_mode"])
        ]

        for entry in window:
            if entry["pgo_job"] is not None:
                jobs.append(dict(entry["pgo_job"]))

        for entry in prepared_entries:
            jobs.append(
                build_micro_batch_job(
                    job_id=f"{entry['job_id']}::prepare",
                    runtime_mode=entry["runtime_mode"],
                    program=entry["program"],
                    io_mode=entry["io_mode"],
                    repeat=entry["repeat"],
                    memory=entry["memory"],
                    input_size=entry["input_size"],
                    daemon_socket=entry["daemon_socket"],
                    compile_only=True,
                    prepared_key=f"{entry['job_id']}::prepared",
                    prepared_group=window_group,
                )
            )

        for entry in prepared_entries:
            jobs.append(
                build_micro_batch_job(
                    job_id=entry["job_id"],
                    runtime_mode=entry["runtime_mode"],
                    program=entry["program"],
                    io_mode=entry["io_mode"],
                    repeat=entry["repeat"],
                    memory=entry["memory"],
                    input_size=entry["input_size"],
                    perf_counters=entry["perf_counters"],
                    perf_scope=entry["perf_scope"],
                    daemon_socket=entry["daemon_socket"],
                    prepared_ref=f"{entry['job_id']}::prepared",
                    prepared_group=window_group,
                )
            )

        for entry in direct_entries:
            jobs.append(
                build_micro_batch_job(
                    job_id=entry["job_id"],
                    runtime_mode=entry["runtime_mode"],
                    program=entry["program"],
                    io_mode=entry["io_mode"],
                    repeat=entry["repeat"],
                    memory=entry["memory"],
                    input_size=entry["input_size"],
                    perf_counters=entry["perf_counters"],
                    perf_scope=entry["perf_scope"],
                    daemon_socket=entry["daemon_socket"],
                )
            )

    return {
        "schema_version": 1,
        "retain_daemon_debug": bool(args.write_details),
        "scheduler": {"max_parallel_jobs": parallel_jobs},
        "jobs": jobs,
    }, plans, memory_files


def batch_result_map(batch_payload: dict[str, Any] | None) -> dict[str, dict[str, Any]]:
    if not isinstance(batch_payload, dict):
        return {}
    jobs = batch_payload.get("jobs")
    if not isinstance(jobs, list):
        return {}
    result: dict[str, dict[str, Any]] = {}
    for job in jobs:
        if not isinstance(job, dict):
            continue
        job_id = job.get("id")
        if isinstance(job_id, str) and job_id:
            result[job_id] = dict(job)
    return result


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    suite_path = Path(args.suite)
    try:
        suite = load_suite(suite_path)
    except Exception as exc:
        raise SystemExit(f"failed to load micro suite manifest {suite_path}: {exc}") from exc

    if args.list:
        list_suite(suite)
        return 0

    benchmarks = select_benchmarks(args.benches, suite)
    runtimes = select_runtimes(args.runtimes, suite)
    if args.rejit and not any(runtime.mode in {"kernel-rejit", "kernel_rejit"} for runtime in runtimes):
        raise SystemExit("--rejit requires --runtime kernel-rejit")
    if args.shuffle_seed is not None:
        random.Random(args.shuffle_seed).shuffle(benchmarks)
    runtime_order_seed = args.shuffle_seed if args.shuffle_seed is not None else DEFAULT_RUNTIME_ORDER_SEED

    iterations = args.iterations if args.iterations is not None else suite.defaults.iterations
    warmups = args.warmups if args.warmups is not None else suite.defaults.warmups
    if args.output:
        output_path = Path(args.output).resolve()
    else:
        output_path = suite.defaults.output
        default_runtime_names = set(suite.defaults.runtimes)
        selected_runtime_names = {runtime.name for runtime in runtimes}
        full_benchmark_selection = len(benchmarks) == len(suite.benchmarks)
        authoritative_run = full_benchmark_selection and default_runtime_names.issubset(selected_runtime_names)
        if not authoritative_run:
            output_path = smoke_output_path(output_path.parent, "pure_jit")

    require_suite_artifacts(suite)

    results = {
        "suite": suite.suite_name,
        "manifest": str(suite.manifest_path),
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "provenance": collect_provenance(args, iterations, warmups),
        "host": {
            "hostname": platform.node(),
            "platform": platform.platform(),
            "python": sys.version.split()[0],
            "cpu_affinity": args.cpu,
            "git_sha": read_git_sha(),
            "kernel_version": platform.release(),
            "kernel_cmdline": read_required_text("/proc/cmdline"),
            "cpu_governor": read_optional_text("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor"),
            "turbo_state": read_optional_text("/sys/devices/system/cpu/intel_pstate/no_turbo"),
            "perf_event_paranoid": read_optional_text("/proc/sys/kernel/perf_event_paranoid"),
        },
        "toolchains": {name: {"root": str(toolchain.root)} for name, toolchain in suite.toolchains.items()},
        "build": {
            "runner_binary": str(suite.build.runner_binary),
            "bpftool_binary": str(suite.build.bpftool_binary),
        },
        "defaults": {
            "iterations": iterations,
            "warmups": warmups,
            "repeat": args.repeat if args.repeat is not None else suite.defaults.repeat,
            "rejit": args.rejit,
            "perf_counters": args.perf_counters,
            "perf_scope": args.perf_scope,
            "shuffle_seed": args.shuffle_seed,
            "runtime_order_seed": runtime_order_seed,
        },
        "iteration_runtime_orders": {},
        "benchmarks": [],
    }

    run_type = derive_run_type(output_path, results["suite"])
    current_benchmark_name: str | None = None
    current_benchmark_index: int | None = None
    current_benchmark_record: dict[str, Any] | None = None
    daemon_debug_index: list[dict[str, Any]] = []

    def build_artifact_metadata(
        status: str,
        started_at: str,
        updated_at: str,
        error_message: str | None,
    ) -> dict[str, Any]:
        attach_baseline_adjustments(results, suite.analysis.baseline_benchmark)
        artifact_metadata = build_run_metadata(
            results,
            output_hint=output_path,
            run_type=run_type,
            daemon_debug_entries=len(daemon_debug_index),
        )
        artifact_metadata["status"] = status
        artifact_metadata["started_at"] = started_at
        artifact_metadata["last_updated_at"] = updated_at
        artifact_metadata["progress"] = {
            "total_benchmarks": len(benchmarks),
            "completed_benchmarks": len(results["benchmarks"]),
            "current_benchmark_index": current_benchmark_index,
            "current_benchmark": current_benchmark_name,
        }
        if error_message:
            artifact_metadata["error_message"] = error_message
        return artifact_metadata

    session = ArtifactSession(
        output_path=output_path,
        run_type=run_type,
        generated_at=str(results["generated_at"]),
        metadata_builder=build_artifact_metadata,
    )
    artifact_dir = session.run_dir

    def flush_artifact(status: str, *, error_message: str | None = None) -> None:
        artifact_details: dict[str, object] = {
            "daemon_debug/index.json": daemon_debug_index,
        } if daemon_debug_index else {}
        progress_payload = {
            "status": status,
            "total_benchmarks": len(benchmarks),
            "completed_benchmarks": len(results["benchmarks"]),
            "current_benchmark_index": current_benchmark_index,
            "current_benchmark": current_benchmark_name,
            "current_benchmark_record": current_benchmark_record,
        }
        if error_message:
            progress_payload["error_message"] = error_message
        session.write(
            status=status,
            progress_payload=progress_payload,
            result_payload=results,
            detail_payloads=artifact_details,
            error_message=error_message,
        )

    def flush_sample_details(*, detail_payloads: dict[str, object]) -> None:
        if not detail_payloads:
            return
        session.write(status="running", detail_payloads=detail_payloads)

    flush_artifact("running")

    try:
        validate_publication_environment(
            results["host"],
            cpu=args.cpu,
            strict=args.strict_env,
        )

        batch_spec, benchmark_plans, memory_files = build_micro_batch_plan(
            benchmarks=benchmarks,
            runtimes=runtimes,
            suite=suite,
            args=args,
            runtime_order_seed=runtime_order_seed,
            warmups=warmups,
        )
        batch_result = run_batch_runner(
            suite.build.runner_binary,
            spec_payload=batch_spec,
            cwd=ROOT_DIR,
        )
        if not batch_result["ok"]:
            raise RuntimeError(batch_result["error"] or "micro batch runner failed")
        batch_results = batch_result_map(batch_result.get("result"))

        for bench_idx, benchmark in enumerate(benchmarks):
            memory_file = memory_files[benchmark.name]
            benchmark_record = {
                "name": benchmark.name,
                "description": benchmark.description,
                "category": benchmark.category,
                "family": benchmark.family,
                "level": benchmark.level,
                "hypothesis": benchmark.hypothesis,
                "io_mode": benchmark.io_mode,
                "tags": list(benchmark.tags),
                "expected_result": benchmark.expected_result,
                "input": str(memory_file) if memory_file else None,
                "runs": [],
            }

            current_benchmark_name = benchmark.name
            current_benchmark_index = bench_idx + 1
            current_benchmark_record = benchmark_record
            flush_artifact("running")

            print(f"[bench] ({bench_idx+1}/{len(benchmarks)}) {benchmark.name}", flush=True)
            bench_plan = benchmark_plans[benchmark.name]
            iteration_runtime_orders = list(bench_plan["iteration_runtime_orders"])
            runtime_samples: dict[str, dict[str, object]] = {}
            for runtime in runtimes:
                runtime_samples[runtime.name] = {
                    "repeat": args.repeat if args.repeat is not None else runtime.default_repeat,
                    "samples": [],
                }

            for runtime in runtimes:
                measurement_job_ids = list(bench_plan["measurement_job_ids"][runtime.name])
                sample_entry = runtime_samples[runtime.name]
                for sample_index, job_id in enumerate(measurement_job_ids):
                    job_result = batch_results.get(job_id)
                    if not job_result:
                        raise RuntimeError(f"missing batch result for {job_id}")
                    if not job_result.get("ok"):
                        raise RuntimeError(
                            f"{benchmark.name}/{runtime.name} failed: {job_result.get('error') or 'unknown error'}"
                        )
                    job_samples = job_result.get("samples") or []
                    if not isinstance(job_samples, list) or not job_samples:
                        raise RuntimeError(f"{benchmark.name}/{runtime.name} produced no samples")
                    sample = dict(job_samples[-1])
                    sample["iteration_index"] = sample_index
                    detail_payloads: dict[str, object] = {}
                    if args.write_details:
                        live_sample_path = _live_sample_relative_path(
                            benchmark.name,
                            runtime.name,
                            iteration_index=sample_index,
                            sample_index=sample_index,
                        )
                        daemon_debug_detail = externalize_sample_daemon_debug(
                            benchmark_name=benchmark.name,
                            runtime_name=runtime.name,
                            sample_index=sample_index,
                            sample=sample,
                        )
                        detail_payloads[live_sample_path] = sample
                        if daemon_debug_detail is not None:
                            daemon_debug_path, daemon_debug_payload, daemon_debug_entry = daemon_debug_detail
                            detail_payloads[daemon_debug_path] = daemon_debug_payload
                            daemon_debug_index.append(daemon_debug_entry)
                            detail_payloads["daemon_debug/index.json"] = daemon_debug_index
                    sample_entry["samples"].append(sample)
                    flush_sample_details(detail_payloads=detail_payloads)
                    if benchmark.expected_result is not None and sample["result"] != benchmark.expected_result:
                        raise RuntimeError(
                            f"{benchmark.name}/{runtime.name} result mismatch: "
                            f"{sample['result']} != {benchmark.expected_result}"
                        )

            results["iteration_runtime_orders"][benchmark.name] = iteration_runtime_orders
            for runtime in runtimes:
                sample_entry = runtime_samples[runtime.name]
                samples = sample_entry["samples"]
                repeat = sample_entry["repeat"]
                compile_values = [sample["compile_ns"] for sample in samples]
                exec_values = [sample["exec_ns"] for sample in samples]
                result_values = [sample["result"] for sample in samples]
                perf_counter_summary = summarize_named_counters(samples, "perf_counters")
                wall_exec_summary = summarize_optional_ns(samples, "wall_exec_ns")
                timing_source = str(samples[0].get("timing_source", "unknown")) if samples else "unknown"

                run_record = {
                    "runtime": runtime.name,
                    "label": runtime.label,
                    "mode": runtime.mode,
                    "repeat": repeat,
                    "artifacts": {
                        "program_object": str(benchmark.program_object),
                    },
                    "samples": samples,
                    "compile_ns": ns_summary(compile_values),
                    "exec_ns": ns_summary(exec_values),
                    "timing_source": timing_source,
                    "phases_ns": summarize_phase_timings(samples),
                    "perf_counters": perf_counter_summary,
                    "perf_counters_meta": summarize_perf_counter_meta(samples),
                    "derived_metrics": derive_perf_metrics(perf_counter_summary),
                    "result_distribution": dict(Counter(str(value) for value in result_values)),
                }
                if wall_exec_summary is not None:
                    run_record["wall_exec_ns"] = wall_exec_summary
                benchmark_record["runs"].append(run_record)

                print(
                    f"  {runtime.name:10} "
                    f"compile median {format_ns(run_record['compile_ns']['median'])} | "
                    f"exec median {format_ns(run_record['exec_ns']['median'])} | "
                    f"result {result_values[-1]}"
                )
                flush_artifact("running")

            runtime_results: dict[str, int | None] = {}
            for run in benchmark_record["runs"]:
                samples = run.get("samples", [])
                if samples:
                    result_counts = Counter(sample["result"] for sample in samples)
                    modal_result = result_counts.most_common(1)[0][0]
                    runtime_results[run["runtime"]] = modal_result
                else:
                    runtime_results[run["runtime"]] = None

            kernel_result = runtime_results.get("kernel")
            rejit_result = runtime_results.get("kernel-rejit")
            if kernel_result is not None and rejit_result is not None and kernel_result != rejit_result:
                print(
                    f"  WARNING: correctness mismatch for {benchmark.name}: "
                    f"kernel={kernel_result}, kernel-rejit={rejit_result}"
                )
                benchmark_record["correctness_mismatch"] = True
            else:
                benchmark_record["correctness_mismatch"] = False

            results["benchmarks"].append(benchmark_record)
            current_benchmark_record = None
            flush_artifact("running")

        current_benchmark_name = None
        current_benchmark_index = None
        flush_artifact("completed")
    except Exception as exc:
        flush_artifact("error", error_message=str(exc))
        raise

    print(f"[done] wrote {artifact_dir / 'metadata.json'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
