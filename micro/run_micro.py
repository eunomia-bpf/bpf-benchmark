#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import os
import platform
import statistics
import subprocess
import sys
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path

from benchmark_catalog import CONFIG_PATH, ROOT_DIR, SuiteSpec, load_suite
from input_generators import materialize_input


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run declarative micro benchmark suites.")
    parser.add_argument("--suite", default=str(CONFIG_PATH), help="Path to suite YAML.")
    parser.add_argument("--bench", action="append", dest="benches", help="Benchmark name.")
    parser.add_argument("--runtime", action="append", dest="runtimes", help="Runtime name.")
    parser.add_argument("--iterations", type=int, help="Measured runs per pair.")
    parser.add_argument("--warmups", type=int, help="Warmup runs per pair.")
    parser.add_argument("--repeat", type=int, help="Repeat count inside each helper sample.")
    parser.add_argument("--output", help="Override JSON output path.")
    parser.add_argument("--cpu", help="Pin child processes to a specific CPU via taskset.")
    parser.add_argument(
        "--regenerate-inputs",
        action="store_true",
        help="Force regeneration of generated inputs.",
    )
    parser.add_argument(
        "--build-bpftool",
        action="store_true",
        help="Build vendored bpftool in addition to the runner and program artifacts.",
    )
    parser.add_argument("--list", action="store_true", help="List benchmarks and runtimes.")
    return parser.parse_args()


def ns_summary(values: list[int]) -> dict[str, float | int | None]:
    if not values:
        return {
            "count": 0,
            "mean": None,
            "median": None,
            "min": None,
            "max": None,
            "p95": None,
            "stdev": None,
        }

    sorted_values = sorted(values)
    p95_index = min(len(sorted_values) - 1, math.ceil(len(sorted_values) * 0.95) - 1)
    return {
        "count": len(values),
        "mean": statistics.mean(values),
        "median": statistics.median(values),
        "min": sorted_values[0],
        "max": sorted_values[-1],
        "p95": sorted_values[p95_index],
        "stdev": statistics.stdev(values) if len(values) > 1 else 0,
    }


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


def run_command(command: list[str], cpu: str | None) -> subprocess.CompletedProcess[str]:
    full_command = command
    if cpu is not None:
        full_command = ["taskset", "-c", cpu, *command]

    completed = subprocess.run(
        full_command,
        capture_output=True,
        text=True,
    )
    if completed.returncode != 0:
        details = completed.stderr.strip() or completed.stdout.strip()
        raise RuntimeError(f"command failed ({completed.returncode}): {' '.join(full_command)}\n{details}")
    return completed


def list_suite(suite: SuiteSpec) -> None:
    print("Benchmarks")
    print("----------")
    for benchmark in suite.benchmarks.values():
        tags = ",".join(benchmark.tags)
        print(f"{benchmark.name:16} {benchmark.category:24} {tags}")

    print()
    print("Runtimes")
    print("--------")
    for runtime in suite.runtimes.values():
        aliases = f" (aliases: {', '.join(runtime.aliases)})" if runtime.aliases else ""
        print(f"{runtime.name:12} {runtime.label}{aliases}")


def select_benchmarks(names: list[str] | None, suite: SuiteSpec):
    if not names:
        return list(suite.benchmarks.values())

    selected = []
    for name in names:
        if name not in suite.benchmarks:
            raise SystemExit(f"unknown benchmark: {name}")
        selected.append(suite.benchmarks[name])
    return selected


def select_runtimes(names: list[str] | None, suite: SuiteSpec):
    requested = names or list(suite.defaults.runtimes)
    selected = []
    for raw_name in requested:
        name = suite.runtime_aliases.get(raw_name, raw_name)
        if name not in suite.runtimes:
            raise SystemExit(f"unknown runtime: {raw_name}")
        selected.append(suite.runtimes[name])
    return selected


def ensure_artifacts_built(suite: SuiteSpec, build_bpftool: bool) -> None:
    build_order = ["micro_exec", "programs"]
    if build_bpftool:
        build_order.append("bpftool")

    for step in build_order:
        command = list(suite.build.commands[step])
        print(f"[build] {step}: {' '.join(command)}")
        completed = subprocess.run(command, cwd=ROOT_DIR, text=True)
        if completed.returncode != 0:
            raise RuntimeError(f"build step failed: {step}")


def resolve_memory_file(benchmark, regenerate_inputs: bool) -> Path | None:
    if benchmark.input_generator is None:
        return None
    path, _ = materialize_input(benchmark.input_generator, force=regenerate_inputs)
    return path


def parse_helper_output(stdout: str) -> dict[str, int]:
    payload = stdout.strip().splitlines()
    if not payload:
        raise RuntimeError("helper produced no output")
    return json.loads(payload[-1])


def resolve_helper_command(suite: SuiteSpec, runtime, benchmark, memory_file: Path | None, repeat: int) -> list[str]:
    binary = str(suite.build.runner_binary)
    if runtime.mode == "llvmbpf":
        command = [
            binary,
            "run-llvmbpf",
            "--program",
            str(benchmark.program_object),
            "--repeat",
            str(repeat),
        ]
        if memory_file is not None:
            command.extend(["--memory", str(memory_file)])
        return command

    if runtime.mode == "kernel":
        command = [
            binary,
            "run-kernel",
            "--program",
            str(benchmark.program_object),
            "--repeat",
            str(repeat),
            "--input-size",
            str(benchmark.kernel_input_size),
        ]
        if memory_file is not None:
            command.extend(["--memory", str(memory_file)])
        if runtime.require_sudo:
            return ["sudo", "-n", *command]
        return command

    raise RuntimeError(f"unsupported runtime mode: {runtime.mode}")


def main() -> int:
    args = parse_args()
    suite = load_suite(Path(args.suite))

    if args.list:
        list_suite(suite)
        return 0

    benchmarks = select_benchmarks(args.benches, suite)
    runtimes = select_runtimes(args.runtimes, suite)

    iterations = args.iterations or suite.defaults.iterations
    warmups = args.warmups or suite.defaults.warmups
    output_path = Path(args.output).resolve() if args.output else suite.defaults.output

    ensure_artifacts_built(suite, args.build_bpftool)

    results = {
        "suite": suite.manifest_path.stem,
        "manifest": str(suite.manifest_path),
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "host": {
            "hostname": platform.node(),
            "platform": platform.platform(),
            "python": sys.version.split()[0],
            "cpu_affinity": args.cpu,
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
            "repeat": args.repeat or suite.defaults.repeat,
        },
        "benchmarks": [],
    }

    for benchmark in benchmarks:
        memory_file = resolve_memory_file(benchmark, args.regenerate_inputs)
        benchmark_record = {
            "name": benchmark.name,
            "description": benchmark.description,
            "category": benchmark.category,
            "tags": list(benchmark.tags),
            "expected_result": benchmark.expected_result,
            "input": str(memory_file) if memory_file else None,
            "runs": [],
        }

        print(f"[bench] {benchmark.name}")
        for runtime in runtimes:
            repeat = args.repeat or runtime.default_repeat
            command = resolve_helper_command(suite, runtime, benchmark, memory_file, repeat)

            for _ in range(warmups):
                parse_helper_output(run_command(command, args.cpu).stdout)

            samples = []
            for _ in range(iterations):
                sample = parse_helper_output(run_command(command, args.cpu).stdout)
                if benchmark.expected_result is not None and sample["result"] != benchmark.expected_result:
                    raise RuntimeError(
                        f"{benchmark.name}/{runtime.name} result mismatch: "
                        f"{sample['result']} != {benchmark.expected_result}"
                    )
                samples.append(sample)

            compile_values = [sample["compile_ns"] for sample in samples]
            exec_values = [sample["exec_ns"] for sample in samples]
            result_values = [sample["result"] for sample in samples]

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
                "result_distribution": dict(Counter(str(value) for value in result_values)),
            }
            benchmark_record["runs"].append(run_record)

            print(
                f"  {runtime.name:10} "
                f"compile median {format_ns(run_record['compile_ns']['median'])} | "
                f"exec median {format_ns(run_record['exec_ns']['median'])} | "
                f"result {result_values[-1]}"
            )

        results["benchmarks"].append(benchmark_record)

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(json.dumps(results, indent=2))
    print(f"[done] wrote {output_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
