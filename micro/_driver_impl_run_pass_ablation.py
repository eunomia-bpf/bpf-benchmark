#!/usr/bin/env python3
"""LLVM pass ablation experiment for micro llvmbpf benchmarks."""
from __future__ import annotations

import argparse
import json
import math
import platform
import statistics
import subprocess
import sys
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

from benchmark_catalog import CONFIG_PATH, ROOT_DIR, BenchmarkSpec, SuiteSpec, load_suite
try:
    from orchestrator.benchmarks import resolve_memory_file, select_benchmarks as select_suite_benchmarks
    from orchestrator.commands import build_runner_command, maybe_prepend_taskset
    from orchestrator.environment import ensure_build_steps, read_optional_text, read_required_text
    from orchestrator.results import ns_summary, parse_runner_sample
except ImportError:
    from micro.orchestrator.benchmarks import (
        resolve_memory_file,
        select_benchmarks as select_suite_benchmarks,
    )
    from micro.orchestrator.commands import build_runner_command, maybe_prepend_taskset
    from micro.orchestrator.environment import ensure_build_steps, read_optional_text, read_required_text
    from micro.orchestrator.results import ns_summary, parse_runner_sample


ROOT = Path(__file__).resolve().parent
RUNNER = ROOT / "build" / "runner" / "micro_exec"
DEFAULT_OUTPUT = ROOT / "results" / "pass_ablation.json"
DEFAULT_REPORT = ROOT / "results" / "pass_ablation.md"
DEFAULT_AUTHORITATIVE_SOURCE = ROOT / "results" / "pure_jit_authoritative.json"
DEFAULT_ITERATIONS = 5
DEFAULT_WARMUPS = 0
DEFAULT_REPEAT = 200

CANDIDATE_PASSES = [
    "InstCombinePass",
    "GVNPass",
    "LICMPass",
    "LoopUnrollPass",
    "SROAPass",
    "JumpThreadingPass",
    "DSEPass",
    "SimplifyCFGPass",
    "ADCEPass",
]

ABLATION_BENCHMARKS = [
    "simple",
    "bitcount",
    "binary_search",
    "branch_layout",
    "switch_dispatch",
    "fibonacci_iter",
    "checksum",
    "stride_load_4",
    "nested_loop_3",
    "large_mixed_500",
    "bpf_call_chain",
]


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run LLVM pass ablation experiments for micro llvmbpf benchmarks.")
    parser.add_argument("--suite", default=str(CONFIG_PATH), help="Path to the benchmark suite YAML.")
    parser.add_argument(
        "--bench",
        action="append",
        dest="benches",
        help="Benchmark name to include. May be specified multiple times. Defaults to the curated ablation subset.",
    )
    parser.add_argument(
        "--pass",
        action="append",
        dest="passes",
        help="LLVM pass name to disable. May be specified multiple times. Defaults to the curated candidate list.",
    )
    parser.add_argument(
        "--benchmarks-from",
        help="Load benchmark names from an existing micro benchmark JSON payload's benchmarks[].name list.",
    )
    parser.add_argument(
        "--authoritative-benchmarks",
        action="store_true",
        help=f"Shortcut for --benchmarks-from {DEFAULT_AUTHORITATIVE_SOURCE}.",
    )
    parser.add_argument("--iterations", type=int, default=DEFAULT_ITERATIONS, help="Measured iterations per configuration.")
    parser.add_argument("--warmups", type=int, default=DEFAULT_WARMUPS, help="Warmup runs per configuration.")
    parser.add_argument("--repeat", type=int, default=DEFAULT_REPEAT, help="Repeat count inside each helper sample.")
    parser.add_argument("--output", default=str(DEFAULT_OUTPUT), help="Path to the JSON output payload.")
    parser.add_argument("--report", default=str(DEFAULT_REPORT), help="Path to the Markdown summary report.")
    parser.add_argument("--cpu", help="Pin child processes to a specific CPU via taskset.")
    parser.add_argument(
        "--regenerate-inputs",
        action="store_true",
        help="Force regeneration of generated benchmark inputs.",
    )
    parser.add_argument(
        "--skip-build",
        action="store_true",
        help="Skip the incremental make steps for the runner and benchmark objects.",
    )
    parser.add_argument(
        "--llvm-log-passes",
        action="store_true",
        help="Ask llvmbpf to log the pass pipeline while compiling each sample.",
    )
    return parser.parse_args(argv)


def trim_text(value: str, limit: int = 4000) -> str:
    value = value.strip()
    if len(value) <= limit:
        return value
    return value[: limit - 3] + "..."


def format_int(value: int | float | None) -> str:
    if value is None:
        return "n/a"
    return str(int(round(float(value))))


def format_pct(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:+.1f}%"


def format_ratio(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.3f}x"


def parse_json_output(stdout: str) -> dict[str, Any]:
    return dict(parse_runner_sample(stdout))


def run_command(command: list[str], cpu: str | None) -> dict[str, Any]:
    full_command = maybe_prepend_taskset(command, cpu)
    completed = subprocess.run(
        full_command,
        capture_output=True,
        text=True,
    )
    if completed.returncode != 0:
        details = completed.stderr.strip() or completed.stdout.strip() or "command failed"
        raise RuntimeError(
            f"command failed ({completed.returncode}): {' '.join(full_command)}\n{details}"
        )
    return parse_json_output(completed.stdout)


def read_required_file(path: str) -> str:
    return read_required_text(path)


def read_optional_file(path: str) -> str:
    return read_optional_text(path)


def ensure_artifacts_built(suite: SuiteSpec) -> None:
    ensure_build_steps(
        suite.build.commands,
        root_dir=ROOT_DIR,
        build_order=("micro_exec", "programs"),
    )


def select_benchmarks(requested: list[str] | None, suite: SuiteSpec) -> list[BenchmarkSpec]:
    return select_suite_benchmarks(requested, suite, default_names=ABLATION_BENCHMARKS)


def select_passes(requested: list[str] | None) -> list[str]:
    selected = requested or CANDIDATE_PASSES
    deduped: list[str] = []
    seen: set[str] = set()
    for name in selected:
        if name in seen:
            continue
        seen.add(name)
        deduped.append(name)
    return deduped


def load_benchmark_names_from_results(path: Path) -> list[str]:
    try:
        payload = json.loads(path.read_text())
    except OSError as error:
        raise SystemExit(f"failed to read benchmark source: {path}: {error}") from error
    except json.JSONDecodeError as error:
        raise SystemExit(f"invalid benchmark source JSON: {path}: {error}") from error

    records = payload.get("benchmarks")
    if not isinstance(records, list):
        raise SystemExit(f"benchmark source missing benchmarks[] list: {path}")

    names: list[str] = []
    for index, record in enumerate(records):
        if not isinstance(record, dict):
            raise SystemExit(f"benchmark source has non-object benchmarks[{index}] in {path}")
        name = record.get("name")
        if not isinstance(name, str) or not name:
            raise SystemExit(f"benchmark source missing benchmarks[{index}].name in {path}")
        names.append(name)

    if not names:
        raise SystemExit(f"benchmark source has no benchmark names: {path}")
    return names


def config_key(disabled_pass: str | None) -> str:
    return "baseline" if disabled_pass is None else f"disabled_{disabled_pass}"


def config_label(disabled_pass: str | None) -> str:
    return "baseline" if disabled_pass is None else f"-{disabled_pass}"


def build_command(
    benchmark: BenchmarkSpec,
    runner: Path,
    repeat: int,
    memory_file: Path | None,
    disabled_pass: str | None,
    log_passes: bool,
) -> list[str]:
    disabled_passes = [disabled_pass] if disabled_pass is not None else []
    return build_runner_command(
        runner,
        "run-llvmbpf",
        program=benchmark.program_object,
        program_name=f"{benchmark.base_name}_xdp",
        io_mode=benchmark.io_mode,
        repeat=repeat,
        memory=memory_file,
        input_size=benchmark.kernel_input_size,
        disabled_passes=disabled_passes,
        log_passes=log_passes,
    )


def extract_native_code_bytes(sample: dict[str, Any]) -> int | None:
    code_size = sample.get("code_size")
    if isinstance(code_size, dict):
        native_code_bytes = code_size.get("native_code_bytes")
        if native_code_bytes is not None:
            return int(native_code_bytes)
    native_code_size = sample.get("native_code_size")
    if native_code_size is not None:
        return int(native_code_size)
    return None


def summarize_samples(samples: list[dict[str, Any]]) -> dict[str, Any]:
    compile_values = [int(sample["compile_ns"]) for sample in samples if sample.get("compile_ns") is not None]
    exec_values = [int(sample["exec_ns"]) for sample in samples if sample.get("exec_ns") is not None]
    code_size_values = [
        native_code_bytes
        for sample in samples
        if (native_code_bytes := extract_native_code_bytes(sample)) is not None
    ]
    result_values = [sample.get("result") for sample in samples if sample.get("result") is not None]
    compile_summary = ns_summary(compile_values)
    exec_summary = ns_summary(exec_values)
    code_size_summary = ns_summary(code_size_values)
    code_size_value = code_size_summary["median"]
    if code_size_value is not None:
        code_size_value = int(round(float(code_size_value)))
    return {
        "samples": samples,
        "compile_ns": compile_values,
        "compile_ns_summary": compile_summary,
        "exec_ns": exec_values,
        "exec_ns_summary": exec_summary,
        "code_size": code_size_value,
        "code_size_samples": code_size_values,
        "code_size_summary": code_size_summary,
        "timing_source": str(samples[0].get("timing_source", "unknown")) if samples else "unknown",
        "result_distribution": dict(Counter(str(value) for value in result_values)),
    }


def run_configuration(
    benchmark: BenchmarkSpec,
    runner: Path,
    repeat: int,
    iterations: int,
    warmups: int,
    memory_file: Path | None,
    disabled_pass: str | None,
    expected_result: int | None,
    cpu: str | None,
    log_passes: bool,
) -> dict[str, Any]:
    command = build_command(
        benchmark=benchmark,
        runner=runner,
        repeat=repeat,
        memory_file=memory_file,
        disabled_pass=disabled_pass,
        log_passes=log_passes,
    )
    samples: list[dict[str, Any]] = []
    try:
        for warmup_index in range(warmups):
            warmup_sample = run_command(command, cpu)
            if expected_result is not None and warmup_sample.get("result") != expected_result:
                raise RuntimeError(
                    f"warmup result mismatch on iteration {warmup_index}: "
                    f"{warmup_sample.get('result')} != {expected_result}"
                )
        for iteration_index in range(iterations):
            sample = run_command(command, cpu)
            sample["iteration_index"] = iteration_index
            if expected_result is not None and sample.get("result") != expected_result:
                raise RuntimeError(
                    f"result mismatch on iteration {iteration_index}: "
                    f"{sample.get('result')} != {expected_result}"
                )
            samples.append(sample)
    except Exception as error:  # noqa: BLE001
        payload = summarize_samples(samples)
        payload.update(
            {
                "status": "error",
                "error": trim_text(str(error)),
            }
        )
    else:
        payload = summarize_samples(samples)
        payload.update(
            {
                "status": "ok",
                "error": None,
            }
        )

    payload.update(
        {
            "disabled_passes": [] if disabled_pass is None else [disabled_pass],
            "command": command,
            "warmups_requested": warmups,
            "iterations_requested": iterations,
            "iterations_completed": len(samples),
        }
    )
    return payload


def median_exec_ns(record: dict[str, Any]) -> float | None:
    summary = record.get("exec_ns_summary", {})
    value = summary.get("median")
    if value is None:
        return None
    return float(value)


def code_size_value(record: dict[str, Any]) -> int | None:
    value = record.get("code_size")
    if value is None:
        return None
    return int(value)


def exec_delta_pct(baseline: dict[str, Any], candidate: dict[str, Any]) -> float | None:
    baseline_median = median_exec_ns(baseline)
    candidate_median = median_exec_ns(candidate)
    if baseline_median in (None, 0.0) or candidate_median is None:
        return None
    return ((candidate_median / baseline_median) - 1.0) * 100.0


def size_ratio(baseline: dict[str, Any], candidate: dict[str, Any]) -> float | None:
    baseline_size = code_size_value(baseline)
    candidate_size = code_size_value(candidate)
    if baseline_size in (None, 0) or candidate_size is None:
        return None
    return candidate_size / baseline_size


def geometric_mean(values: list[float]) -> float | None:
    positives = [value for value in values if value > 0.0]
    if not positives:
        return None
    return math.exp(sum(math.log(value) for value in positives) / len(positives))


def render_markdown(payload: dict[str, Any]) -> str:
    passes: list[str] = payload["parameters"]["passes"]
    benchmarks: list[str] = payload["parameters"]["benchmarks"]
    results: dict[str, dict[str, Any]] = payload["ablation_results"]

    lines: list[str] = [
        "# LLVM Pass Ablation",
        "",
        f"- Generated at: `{payload['generated_at']}`",
        f"- Suite manifest: `{payload['manifest']}`",
        f"- Runner: `{payload['runner_binary']}`",
        f"- Benchmarks: `{', '.join(benchmarks)}`",
        f"- Candidate passes: `{', '.join(passes)}`",
        f"- Runtime: `llvmbpf` only",
        f"- Iterations per configuration: `{payload['parameters']['iterations']}`",
        f"- Warmups per configuration: `{payload['parameters']['warmups']}`",
        f"- Repeat per sample: `{payload['parameters']['repeat']}`",
        "",
        "## Benchmark Summary",
        "",
    ]

    table_header = ["Benchmark", "Baseline size"]
    table_header.extend(f"-{pass_name} size" for pass_name in passes)
    table_header.extend(f"-{pass_name} exec%" for pass_name in passes)
    lines.append("| " + " | ".join(table_header) + " |")
    lines.append("| " + " | ".join(["---"] * len(table_header)) + " |")

    for benchmark_name in benchmarks:
        benchmark_results = results[benchmark_name]
        baseline = benchmark_results["baseline"]
        row = [benchmark_name]
        row.append(format_int(code_size_value(baseline)) if baseline.get("status") == "ok" else "ERR")
        for pass_name in passes:
            candidate = benchmark_results[config_key(pass_name)]
            row.append(format_int(code_size_value(candidate)) if candidate.get("status") == "ok" else "ERR")
        for pass_name in passes:
            candidate = benchmark_results[config_key(pass_name)]
            if candidate.get("status") != "ok" or baseline.get("status") != "ok":
                row.append("ERR")
            else:
                row.append(format_pct(exec_delta_pct(baseline, candidate)))
        lines.append("| " + " | ".join(row) + " |")

    lines.extend(
        [
            "",
            "## Configuration Summary",
            "",
            "| Configuration | Successful benchmarks | Median size ratio | Geomean exec ratio | Median exec delta |",
            "| --- | ---: | ---: | ---: | ---: |",
        ]
    )

    for disabled_pass in [None, *passes]:
        label = config_label(disabled_pass)
        key = config_key(disabled_pass)
        success_count = 0
        size_ratios: list[float] = []
        exec_ratios: list[float] = []
        exec_deltas: list[float] = []
        for benchmark_name in benchmarks:
            benchmark_results = results[benchmark_name]
            baseline = benchmark_results["baseline"]
            record = benchmark_results[key]
            if record.get("status") != "ok":
                continue
            success_count += 1
            if disabled_pass is None:
                size_ratios.append(1.0)
                exec_ratios.append(1.0)
                exec_deltas.append(0.0)
                continue
            ratio = size_ratio(baseline, record)
            if ratio is not None:
                size_ratios.append(ratio)
            baseline_exec = median_exec_ns(baseline)
            record_exec = median_exec_ns(record)
            if baseline_exec not in (None, 0.0) and record_exec is not None:
                exec_ratios.append(record_exec / baseline_exec)
            delta = exec_delta_pct(baseline, record)
            if delta is not None:
                exec_deltas.append(delta)
        median_size_ratio = statistics.median(size_ratios) if size_ratios else None
        geomean_exec_ratio = geometric_mean(exec_ratios)
        median_exec_delta = statistics.median(exec_deltas) if exec_deltas else None
        lines.append(
            f"| {label} | {success_count}/{len(benchmarks)} | {format_ratio(median_size_ratio)} | "
            f"{format_ratio(geomean_exec_ratio)} | {format_pct(median_exec_delta)} |"
        )

    failures: list[tuple[str, str, str]] = []
    for benchmark_name in benchmarks:
        for disabled_pass in [None, *passes]:
            record = results[benchmark_name][config_key(disabled_pass)]
            if record.get("status") == "ok":
                continue
            failures.append((benchmark_name, config_label(disabled_pass), str(record.get("error") or "unknown error")))

    lines.extend(
        [
            "",
            "## Notes",
            "",
            f"- `code_size` is the median `native_code_bytes` across the `{payload['parameters']['iterations']}` llvmbpf samples for that configuration.",
            "- `exec%` is the percent change in median `exec_ns` versus the same benchmark's baseline.",
            "- `ERR` means the configuration failed to compile or execute for that benchmark.",
            "",
            "## Failures",
            "",
        ]
    )

    if not failures:
        lines.append("- None.")
    else:
        for benchmark_name, label, error in failures:
            lines.append(f"- `{benchmark_name}` / `{label}`: {error}")

    return "\n".join(lines) + "\n"


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    if args.authoritative_benchmarks and args.benchmarks_from:
        raise SystemExit("choose either --benchmarks-from or --authoritative-benchmarks, not both")

    suite = load_suite(Path(args.suite))
    requested_benchmarks = args.benches
    if args.authoritative_benchmarks:
        requested_benchmarks = load_benchmark_names_from_results(DEFAULT_AUTHORITATIVE_SOURCE)
    elif args.benchmarks_from:
        requested_benchmarks = load_benchmark_names_from_results(Path(args.benchmarks_from))

    selected_benchmarks = select_benchmarks(requested_benchmarks, suite)
    selected_passes = select_passes(args.passes)
    output_path = Path(args.output).resolve()
    report_path = Path(args.report).resolve()
    runner = suite.build.runner_binary.resolve() if suite.build.runner_binary.exists() else RUNNER.resolve()

    if not args.skip_build:
        ensure_artifacts_built(suite)

    if not runner.exists():
        raise SystemExit(f"runner binary not found: {runner}")

    host = {
        "hostname": platform.node(),
        "platform": platform.platform(),
        "python": sys.version.split()[0],
        "cpu_affinity": args.cpu,
        "git_sha": subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT_DIR).decode().strip(),
        "kernel_version": platform.release(),
        "kernel_cmdline": read_required_file("/proc/cmdline"),
        "cpu_governor": read_optional_file("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor"),
        "turbo_state": read_optional_file("/sys/devices/system/cpu/intel_pstate/no_turbo"),
    }

    payload: dict[str, Any] = {
        "dataset": "pass_ablation",
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "suite": suite.suite_name,
        "manifest": str(suite.manifest_path),
        "runner_binary": str(runner),
        "host": host,
        "parameters": {
            "runtime": "llvmbpf",
            "iterations": args.iterations,
            "warmups": args.warmups,
            "repeat": args.repeat,
            "benchmarks": [benchmark.name for benchmark in selected_benchmarks],
            "passes": selected_passes,
            "llvm_log_passes": args.llvm_log_passes,
        },
        "benchmark_specs": {},
        "ablation_results": {},
    }

    configurations = [None, *selected_passes]
    for benchmark in selected_benchmarks:
        print(f"[bench] {benchmark.name}")
        if not benchmark.program_object.exists():
            raise SystemExit(f"program object not found: {benchmark.program_object}")
        memory_file = resolve_memory_file(benchmark, args.regenerate_inputs)
        payload["benchmark_specs"][benchmark.name] = {
            "description": benchmark.description,
            "category": benchmark.category,
            "base_name": benchmark.base_name,
            "program_object": str(benchmark.program_object),
            "program_name": f"{benchmark.base_name}_xdp",
            "io_mode": benchmark.io_mode,
            "kernel_input_size": benchmark.kernel_input_size,
            "input_generator": benchmark.input_generator,
            "input_file": str(memory_file) if memory_file is not None else None,
            "expected_result": benchmark.expected_result,
        }
        benchmark_results: dict[str, Any] = {}
        for disabled_pass in configurations:
            label = config_label(disabled_pass)
            record = run_configuration(
                benchmark=benchmark,
                runner=runner,
                repeat=args.repeat,
                iterations=args.iterations,
                warmups=args.warmups,
                memory_file=memory_file,
                disabled_pass=disabled_pass,
                expected_result=benchmark.expected_result,
                cpu=args.cpu,
                log_passes=args.llvm_log_passes,
            )
            benchmark_results[config_key(disabled_pass)] = record
            if record["status"] == "ok":
                print(
                    f"  {label:24} "
                    f"exec median {format_int(record['exec_ns_summary']['median'])} ns | "
                    f"size {format_int(record['code_size'])} B"
                )
            else:
                print(f"  {label:24} error {record['error']}")
        payload["ablation_results"][benchmark.name] = benchmark_results

    output_path.parent.mkdir(parents=True, exist_ok=True)
    report_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(json.dumps(payload, indent=2))
    report_path.write_text(render_markdown(payload))

    print(f"[done] wrote {output_path}")
    print(f"[done] wrote {report_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
