#!/usr/bin/env python3
from __future__ import annotations

import json
import platform
import random
import subprocess
import sys
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
MICRO_DIR = REPO_ROOT / "micro"
sys.path.insert(0, str(MICRO_DIR))

import run_micro as rm  # noqa: E402
from benchmark_catalog import load_suite  # noqa: E402


def resolve_git_sha() -> str:
    try:
        return subprocess.check_output(
            ["git", "rev-parse", "HEAD"],
            cwd=rm.ROOT_DIR,
            stderr=subprocess.DEVNULL,
        ).decode().strip()
    except (OSError, subprocess.CalledProcessError):
        return "unknown"


def main() -> int:
    args = rm.parse_args()
    suite = load_suite(Path(args.suite))

    if args.list:
        rm.list_suite(suite)
        return 0

    benchmarks = rm.select_benchmarks(args.benches, suite)
    runtimes = rm.select_runtimes(args.runtimes, suite)
    if args.shuffle_seed is not None:
        random.Random(args.shuffle_seed).shuffle(benchmarks)
    runtime_order_seed = (
        args.shuffle_seed if args.shuffle_seed is not None else rm.DEFAULT_RUNTIME_ORDER_SEED
    )

    iterations = args.iterations if args.iterations is not None else suite.defaults.iterations
    warmups = args.warmups if args.warmups is not None else suite.defaults.warmups
    output_path = Path(args.output).resolve() if args.output else suite.defaults.output

    print("[skip-build] using existing artifacts")

    results = {
        "suite": suite.suite_name,
        "manifest": str(suite.manifest_path),
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "host": {
            "hostname": platform.node(),
            "platform": platform.platform(),
            "python": sys.version.split()[0],
            "cpu_affinity": args.cpu,
            "git_sha": resolve_git_sha(),
            "kernel_version": platform.release(),
            "kernel_cmdline": rm.read_required_file("/proc/cmdline"),
            "cpu_governor": rm.read_optional_file("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor"),
            "turbo_state": rm.read_optional_file("/sys/devices/system/cpu/intel_pstate/no_turbo"),
            "perf_event_paranoid": rm.read_optional_file("/proc/sys/kernel/perf_event_paranoid"),
        },
        "toolchains": {
            name: {"root": str(toolchain.root)}
            for name, toolchain in suite.toolchains.items()
        },
        "build": {
            "runner_binary": str(suite.build.runner_binary),
            "bpftool_binary": str(suite.build.bpftool_binary),
        },
        "defaults": {
            "iterations": iterations,
            "warmups": warmups,
            "repeat": args.repeat if args.repeat is not None else suite.defaults.repeat,
            "perf_counters": args.perf_counters,
            "perf_scope": args.perf_scope,
            "shuffle_seed": args.shuffle_seed,
            "runtime_order_seed": runtime_order_seed,
        },
        "iteration_runtime_orders": {},
        "benchmarks": [],
    }

    rm.validate_environment(results["host"], args, args.strict_env)

    for benchmark in benchmarks:
        memory_file = rm.resolve_memory_file(benchmark, args.regenerate_inputs)
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

        print(f"[bench] {benchmark.name}")
        runtime_samples: dict[str, dict[str, object]] = {}
        iteration_runtime_orders: list[list[str]] = []
        for runtime in runtimes:
            repeat = args.repeat if args.repeat is not None else runtime.default_repeat
            command = rm.resolve_helper_command(
                suite,
                runtime,
                benchmark,
                memory_file,
                repeat,
                args.perf_counters,
                args.perf_scope,
            )

            for _ in range(warmups):
                rm.parse_helper_output(rm.run_command(command, args.cpu).stdout)

            runtime_samples[runtime.name] = {
                "repeat": repeat,
                "command": command,
                "samples": [],
            }

        for iteration_idx in range(iterations):
            if len(runtimes) == 2:
                ordered = list(runtimes) if iteration_idx % 2 == 0 else list(reversed(runtimes))
            else:
                rng = random.Random(runtime_order_seed + iteration_idx)
                ordered = list(runtimes)
                rng.shuffle(ordered)
            iteration_runtime_orders.append([runtime.name for runtime in ordered])

            for runtime in ordered:
                sample_entry = runtime_samples[runtime.name]
                sample = rm.parse_helper_output(rm.run_command(sample_entry["command"], args.cpu).stdout)
                sample["iteration_index"] = iteration_idx
                if benchmark.expected_result is not None and sample["result"] != benchmark.expected_result:
                    raise RuntimeError(
                        f"{benchmark.name}/{runtime.name} result mismatch: "
                        f"{sample['result']} != {benchmark.expected_result}"
                    )
                sample_entry["samples"].append(sample)

        results["iteration_runtime_orders"][benchmark.name] = iteration_runtime_orders
        for runtime in runtimes:
            sample_entry = runtime_samples[runtime.name]
            samples = sample_entry["samples"]
            repeat = sample_entry["repeat"]
            compile_values = [sample["compile_ns"] for sample in samples]
            exec_values = [sample["exec_ns"] for sample in samples]
            result_values = [sample["result"] for sample in samples]
            perf_counter_summary = rm.summarize_named_counters(samples, "perf_counters")
            wall_exec_summary = rm.summarize_optional_ns(samples, "wall_exec_ns")
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
                "compile_ns": rm.ns_summary(compile_values),
                "exec_ns": rm.ns_summary(exec_values),
                "timing_source": timing_source,
                "phases_ns": rm.summarize_phase_timings(samples),
                "perf_counters": perf_counter_summary,
                "perf_counters_meta": rm.summarize_perf_counter_meta(samples),
                "derived_metrics": rm.derive_perf_metrics(perf_counter_summary),
                "result_distribution": dict(Counter(str(value) for value in result_values)),
            }
            if wall_exec_summary is not None:
                run_record["wall_exec_ns"] = wall_exec_summary
            benchmark_record["runs"].append(run_record)

            print(
                f"  {runtime.name:10} "
                f"compile median {rm.format_ns(run_record['compile_ns']['median'])} | "
                f"exec median {rm.format_ns(run_record['exec_ns']['median'])} | "
                f"result {result_values[-1]}"
            )

        results["benchmarks"].append(benchmark_record)

    rm.attach_baseline_adjustments(results, suite.analysis.baseline_benchmark)

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(json.dumps(results, indent=2))
    print(f"[done] wrote {output_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
