#!/usr/bin/env python3
from __future__ import annotations

import argparse
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

from micro.catalog import (
    DEFAULT_MICRO_MANIFEST as CONFIG_PATH,
    REPO_ROOT as ROOT_DIR,
    CatalogManifest as SuiteSpec,
    CatalogRuntime as RuntimeSpec,
    CatalogTarget,
    load_manifest as load_suite,
)
from runner.libs import run_command, tail_text
from runner.libs.benchmarks import resolve_memory_file, select_benchmarks
from runner.libs.environment import (
    require_existing_paths,
    read_optional_text,
    read_required_text,
    validate_publication_environment,
)
from runner.libs.results import parse_last_json_line
from runner.libs.statistics import (
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
    sanitize_artifact_token,
    summarize_benchmark_results,
)


DEFAULT_RUNTIME_ORDER_SEED = 0
RUNNER_TIMEOUT_SECONDS = 180


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run declarative micro benchmark suites.")
    parser.add_argument("--suite", default=str(CONFIG_PATH), help="Path to suite YAML.")
    parser.add_argument("--bench", action="append", dest="benches", help="Benchmark name.")
    parser.add_argument("--runtime", action="append", dest="runtimes", help="Runtime name.")
    parser.add_argument("--samples", type=int, help="Measured samples per runtime pair.")
    parser.add_argument("--warmups", type=int, help="Warmup runs per pair.")
    parser.add_argument("--inner-repeat", type=int, dest="inner_repeat", help="Repeat count inside each helper sample.")
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
        help="PMU scope: full_repeat_raw (default, raw totals) or full_repeat_avg (cumulative counters divided by inner repeat).",
    )
    parser.add_argument(
        "--regenerate-inputs",
        action="store_true",
        help="Force regeneration of generated inputs.",
    )
    parser.add_argument(
        "--write-details",
        action="store_true",
        help="Write per-sample live_samples detail artifacts. Disabled by default for faster runs.",
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
    samples: int,
    warmups: int,
    inner_repeat: int | None,
) -> dict[str, object]:
    linux_dir = ROOT_DIR / "vendor" / "linux-framework"
    kernel_commit = _git_rev_parse(linux_dir) if linux_dir.is_dir() else "unknown"
    repo_git_sha = _git_rev_parse(ROOT_DIR)
    repo_dirty = _git_is_dirty(ROOT_DIR)

    return {
        "kernel_commit": kernel_commit,
        "repo_git_sha": repo_git_sha,
        "repo_dirty": repo_dirty,
        "params": {
            "samples": samples,
            "warmups": warmups,
            "inner_repeat": inner_repeat,
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
    for runtime in suite.runtimes:
        aliases = f" (aliases: {', '.join(runtime.aliases)})" if runtime.aliases else ""
        print(f"{runtime.name:12} {runtime.label}{aliases}")


def select_runtimes(names: list[str] | None, suite: SuiteSpec) -> list[RuntimeSpec]:
    requested = names or list(suite.defaults.runtimes)
    runtimes_by_name = {runtime.name: runtime for runtime in suite.runtimes}
    selected: list[RuntimeSpec] = []
    for raw_name in requested:
        name = suite.runtime_aliases.get(raw_name, raw_name)
        if name not in runtimes_by_name:
            raise SystemExit(f"unknown runtime: {raw_name}")
        runtime = runtimes_by_name[name]
        if runtime.policy_mode != "stock":
            raise SystemExit(
                f"micro benchmark only supports stock runtimes under §5.6; got {runtime.name} ({runtime.mode})"
            )
        selected.append(runtime)
    return selected


def require_suite_artifacts(suite: SuiteSpec) -> None:
    required_paths = [suite.build.runner_binary]
    required_paths.extend(benchmark.object_path for benchmark in suite.benchmarks.values())
    require_existing_paths(required_paths)


def runner_help_text(runner_binary: Path) -> str:
    completed = run_command(
        [str(runner_binary), "--help"],
        cwd=ROOT_DIR,
        check=False,
        timeout=30,
    )
    return "\n".join([completed.stdout, completed.stderr])


def attach_baseline_adjustments(results: dict[str, object], baseline_benchmark: str | None) -> None:
    if not baseline_benchmark:
        return

    benchmarks = results.get("benchmarks", [])
    baseline_record = next((record for record in benchmarks if record.get("name") == baseline_benchmark), None)
    if baseline_record is None:
        raise RuntimeError(f"baseline benchmark not found in results: {baseline_benchmark}")

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
    run_type: str,
) -> dict[str, Any]:
    metadata = summarize_benchmark_results(results)
    metadata["run_type"] = run_type
    metadata["optimization_summary"]["daemon_debug_entries"] = 0
    return metadata


def _live_sample_relative_path(
    benchmark_name: str,
    runtime_name: str,
    *,
    sample_index: int,
) -> str:
    basename = (
        f"{sanitize_artifact_token(benchmark_name)}__"
        f"{sanitize_artifact_token(runtime_name)}__sample{sample_index:02d}.json"
    )
    return f"live_samples/{basename}"


def build_runner_command(
    *,
    runner_binary: Path,
    benchmark: CatalogTarget,
    runtime: RuntimeSpec,
    inner_repeat: int,
    memory_file: Path | None,
    perf_counters: bool,
    perf_scope: str,
    cpu: str | None,
) -> list[str]:
    if runtime.mode == "llvmbpf":
        command = [str(runner_binary), "run-llvmbpf"]
    elif runtime.mode == "kernel":
        command = [str(runner_binary), "test-run"]
    else:
        raise RuntimeError(f"unsupported micro runtime mode: {runtime.mode}")

    command.extend(["--program", str(benchmark.object_path)])
    if benchmark.program_names:
        command.extend(["--program-name", benchmark.program_names[0]])
    if memory_file is not None:
        command.extend(["--memory", str(memory_file)])
    if benchmark.io_mode:
        command.extend(["--io-mode", benchmark.io_mode])
    if benchmark.kernel_input_size > 0:
        command.extend(["--input-size", str(benchmark.kernel_input_size)])
    command.extend(["--inner-repeat", str(max(1, inner_repeat))])

    if perf_counters:
        command.append("--perf-counters")
        command.extend(["--perf-scope", perf_scope])

    if cpu:
        return ["taskset", "-c", str(cpu), *command]
    return command


def run_single_sample(
    command: list[str],
    *,
    cwd: Path,
) -> dict[str, Any]:
    completed = run_command(
        command,
        cwd=cwd,
        timeout=RUNNER_TIMEOUT_SECONDS,
    )
    try:
        payload = parse_last_json_line(completed.stdout, label="micro_exec")
    except Exception as exc:
        detail = tail_text(completed.stderr or completed.stdout or "")
        raise RuntimeError(
            f"micro_exec returned invalid JSON for {' '.join(command)}\n{detail}"
        ) from exc
    if not isinstance(payload, dict):
        raise RuntimeError(f"micro_exec returned non-object JSON for {' '.join(command)}")
    return dict(payload)


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
    if args.shuffle_seed is not None:
        random.Random(args.shuffle_seed).shuffle(benchmarks)
    runtime_order_seed = args.shuffle_seed if args.shuffle_seed is not None else DEFAULT_RUNTIME_ORDER_SEED

    samples = args.samples if args.samples is not None else suite.defaults.samples
    warmups = args.warmups if args.warmups is not None else suite.defaults.warmups
    default_inner_repeat = args.inner_repeat if args.inner_repeat is not None else suite.defaults.inner_repeat
    if args.output:
        output_path = Path(args.output).resolve()
    else:
        output_path = suite.defaults.output

    require_suite_artifacts(suite)
    runner_binary = Path(suite.build.runner_binary).resolve()
    if any(runtime.mode == "llvmbpf" for runtime in runtimes):
        runner_help = runner_help_text(runner_binary)
        if "run-llvmbpf" not in runner_help:
            detail = tail_text(runner_help, max_lines=20, max_chars=4000)
            detail_suffix = f"\n{detail}" if detail else ""
            raise RuntimeError(
                f"selected llvmbpf runtime but runner build does not expose run-llvmbpf: {runner_binary}"
                f"{detail_suffix}"
            )

    results: dict[str, Any] = {
        "suite": suite.suite_name,
        "manifest": str(suite.manifest_path),
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "provenance": collect_provenance(args, samples, warmups, default_inner_repeat),
        "host": {
            "hostname": platform.node(),
            "platform": platform.platform(),
            "python": sys.version.split()[0],
            "cpu_affinity": args.cpu,
            "git_sha": _git_rev_parse(ROOT_DIR),
            "kernel_version": platform.release(),
            "kernel_cmdline": read_required_text("/proc/cmdline"),
            "cpu_governor": read_optional_text("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor"),
            "turbo_state": read_optional_text("/sys/devices/system/cpu/intel_pstate/no_turbo"),
            "perf_event_paranoid": read_optional_text("/proc/sys/kernel/perf_event_paranoid"),
        },
        "toolchains": {
            name: {"root": str(spec.get("root"))}
            for name, spec in ((suite.metadata.get("toolchains") or {}).items())
            if isinstance(spec, dict)
        },
        "build": {
            "runner_binary": str(runner_binary),
        },
        "defaults": {
            "samples": samples,
            "warmups": warmups,
            "inner_repeat": default_inner_repeat,
            "perf_counters": args.perf_counters,
            "perf_scope": args.perf_scope,
            "shuffle_seed": args.shuffle_seed,
            "runtime_order_seed": runtime_order_seed,
        },
        "sample_runtime_orders": {},
        "benchmarks": [],
    }

    run_type = derive_run_type(output_path, results["suite"])
    current_benchmark_name: str | None = None
    current_benchmark_index: int | None = None
    current_benchmark_record: dict[str, Any] | None = None

    def build_artifact_metadata(
        status: str,
        started_at: str,
        updated_at: str,
        error_message: str | None,
    ) -> dict[str, Any]:
        attach_baseline_adjustments(results, suite.analysis.baseline_benchmark)
        artifact_metadata = build_run_metadata(
            results,
            run_type=run_type,
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

        for bench_idx, benchmark in enumerate(benchmarks):
            memory_file = resolve_memory_file(benchmark, args.regenerate_inputs)
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

            runtime_samples: dict[str, dict[str, object]] = {}
            for runtime in runtimes:
                inner_repeat = args.inner_repeat if args.inner_repeat is not None else runtime.default_inner_repeat
                runtime_samples[runtime.name] = {
                    "inner_repeat": inner_repeat,
                    "samples": [],
                }
                warmup_command = build_runner_command(
                    runner_binary=runner_binary,
                    benchmark=benchmark,
                    runtime=runtime,
                    inner_repeat=inner_repeat,
                    memory_file=memory_file,
                    perf_counters=args.perf_counters,
                    perf_scope=args.perf_scope,
                    cpu=args.cpu,
                )
                for _ in range(max(0, warmups)):
                    sample = run_single_sample(warmup_command, cwd=ROOT_DIR)
                    if benchmark.expected_result is not None and sample.get("result") != benchmark.expected_result:
                        raise RuntimeError(
                            f"{benchmark.name}/{runtime.name} warmup result mismatch: "
                            f"{sample.get('result')} != {benchmark.expected_result}"
                        )

            sample_runtime_orders: list[list[str]] = []
            for sample_idx in range(samples):
                if len(runtimes) == 2:
                    ordered = list(runtimes) if sample_idx % 2 == 0 else list(reversed(runtimes))
                else:
                    rng = random.Random(runtime_order_seed + sample_idx)
                    ordered = list(runtimes)
                    rng.shuffle(ordered)
                sample_runtime_orders.append([runtime.name for runtime in ordered])

                for runtime in ordered:
                    inner_repeat = int(runtime_samples[runtime.name]["inner_repeat"])
                    command = build_runner_command(
                        runner_binary=runner_binary,
                        benchmark=benchmark,
                        runtime=runtime,
                        inner_repeat=inner_repeat,
                        memory_file=memory_file,
                        perf_counters=args.perf_counters,
                        perf_scope=args.perf_scope,
                        cpu=args.cpu,
                    )
                    sample = run_single_sample(command, cwd=ROOT_DIR)
                    sample["sample_index"] = sample_idx

                    if benchmark.expected_result is not None and sample.get("result") != benchmark.expected_result:
                        raise RuntimeError(
                            f"{benchmark.name}/{runtime.name} result mismatch: "
                            f"{sample.get('result')} != {benchmark.expected_result}"
                        )

                    detail_payloads: dict[str, object] = {}
                    if args.write_details:
                        live_sample_path = _live_sample_relative_path(
                            benchmark.name,
                            runtime.name,
                            sample_index=sample_idx,
                        )
                        detail_payloads[live_sample_path] = sample

                    runtime_samples[runtime.name]["samples"].append(sample)
                    flush_sample_details(detail_payloads=detail_payloads)

            results["sample_runtime_orders"][benchmark.name] = sample_runtime_orders
            for runtime in runtimes:
                sample_entry = runtime_samples[runtime.name]
                run_samples = list(sample_entry["samples"])
                inner_repeat = int(sample_entry["inner_repeat"])
                compile_values = [sample["compile_ns"] for sample in run_samples]
                exec_values = [sample["exec_ns"] for sample in run_samples]
                result_values = [sample["result"] for sample in run_samples]
                perf_counter_summary = summarize_named_counters(run_samples, "perf_counters")
                wall_exec_summary = summarize_optional_ns(run_samples, "wall_exec_ns")
                timing_source = str(run_samples[0].get("timing_source", "unknown")) if run_samples else "unknown"

                run_record: dict[str, Any] = {
                    "runtime": runtime.name,
                    "label": runtime.label,
                    "mode": runtime.mode,
                    "inner_repeat": inner_repeat,
                    "samples": run_samples,
                    "compile_ns": ns_summary(compile_values),
                    "exec_ns": ns_summary(exec_values),
                    "timing_source": timing_source,
                    "phases_ns": summarize_phase_timings(run_samples),
                    "perf_counters": perf_counter_summary,
                    "perf_counters_meta": summarize_perf_counter_meta(run_samples),
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
