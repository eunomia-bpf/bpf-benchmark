#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import statistics
import subprocess
import sys
from pathlib import Path
from typing import Any

REPO_ROOT = Path(__file__).resolve().parents[2]
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from micro.benchmark_catalog import CONFIG_PATH, load_suite
from micro.orchestrator.benchmarks import resolve_memory_file


MODE_FLAGS = {
    "stock": [],
    "wide": ["--recompile-wide"],
    "rotate": ["--recompile-rotate"],
    "rotate-rorx": ["--recompile-rotate-rorx"],
    "lea": ["--recompile-lea"],
    "extract": ["--recompile-extract"],
    "cmov": ["--recompile-cmov"],
}

LLVMBPF_MODE_FLAGS = {
    "llvmbpf": [],
    "llvmbpf-nobmi": ["--llvm-target-features", "-bmi,-bmi2"],
}


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Run a single micro benchmark across selected modes and save medians."
    )
    parser.add_argument("--bench", required=True, help="Benchmark name from config/micro_pure_jit.yaml.")
    parser.add_argument(
        "--mode",
        action="append",
        dest="modes",
        required=True,
        help="Mode to run: llvmbpf, llvmbpf-nobmi, stock, wide, rotate, rotate-rorx, lea, extract, cmov.",
    )
    parser.add_argument("--iterations", type=int, default=10)
    parser.add_argument("--warmups", type=int, default=3)
    parser.add_argument("--repeat", type=int, default=1000)
    parser.add_argument("--cpu", help="Optional taskset CPU to apply to each child command.")
    parser.add_argument("--output", required=True, help="Output JSON path.")
    parser.add_argument(
        "--stdout-json",
        action="store_true",
        help="Print the full output JSON to stdout after writing it.",
    )
    return parser.parse_args()


def run_command(command: list[str], cpu: str | None) -> dict[str, Any]:
    if cpu is not None:
        command = ["taskset", "-c", cpu, *command]
    completed = subprocess.run(
        command,
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )
    lines = [line.strip() for line in completed.stdout.splitlines() if line.strip()]
    if not lines:
        raise RuntimeError(f"no JSON output from: {' '.join(command)}")
    payload = json.loads(lines[-1])
    if not isinstance(payload, dict):
        raise RuntimeError(f"unexpected payload type from: {' '.join(command)}")
    return payload


def summarize_samples(samples: list[dict[str, Any]]) -> dict[str, Any]:
    exec_values = [int(sample["exec_ns"]) for sample in samples]
    native_values = [
        int(sample["code_size"]["native_code_bytes"])
        for sample in samples
        if isinstance(sample.get("code_size"), dict)
        and "native_code_bytes" in sample["code_size"]
    ]
    summary = {
        "exec_ns": {
            "samples": exec_values,
            "median": statistics.median(exec_values),
            "min": min(exec_values),
            "max": max(exec_values),
        },
    }
    if native_values:
        summary["native_code_bytes"] = {
            "samples": native_values,
            "median": statistics.median(native_values),
            "min": min(native_values),
            "max": max(native_values),
        }
    return summary


def main() -> int:
    args = parse_args()
    suite = load_suite(CONFIG_PATH)
    benchmark = suite.benchmarks[args.bench]
    memory = resolve_memory_file(benchmark, False)
    if memory is None:
        raise SystemExit(f"benchmark {args.bench} has no generated input")

    modes: dict[str, Any] = {}
    for mode in args.modes:
        if mode in LLVMBPF_MODE_FLAGS:
            command = [
                str(REPO_ROOT / "micro" / "build" / "runner" / "micro_exec"),
                "run-llvmbpf",
            ]
            command.extend(LLVMBPF_MODE_FLAGS[mode])
        else:
            if mode not in MODE_FLAGS:
                raise SystemExit(f"unsupported mode: {mode}")
            command = [
                str(REPO_ROOT / "micro" / "build" / "runner" / "micro_exec"),
                "run-kernel",
            ]
        command.extend(
            [
                "--program",
                str(benchmark.program_object),
                "--memory",
                str(memory),
                "--input-size",
                str(benchmark.kernel_input_size),
                "--io-mode",
                benchmark.io_mode,
                "--repeat",
                str(args.repeat),
            ]
        )
        if benchmark.io_mode == "packet":
            command.append("--raw-packet")
        if mode not in LLVMBPF_MODE_FLAGS:
            command.extend(MODE_FLAGS[mode])

        samples: list[dict[str, Any]] = []
        for _ in range(args.warmups):
            payload = run_command(command, args.cpu)
            if int(payload.get("result", 0)) != int(benchmark.expected_result):
                raise RuntimeError(
                    f"{args.bench}:{mode} warmup result mismatch: "
                    f"{payload.get('result')} != {benchmark.expected_result}"
                )
        for iteration in range(args.iterations):
            payload = run_command(command, args.cpu)
            if int(payload.get("result", 0)) != int(benchmark.expected_result):
                raise RuntimeError(
                    f"{args.bench}:{mode} iteration {iteration} result mismatch: "
                    f"{payload.get('result')} != {benchmark.expected_result}"
                )
            payload["iteration_index"] = iteration
            samples.append(payload)

        entry: dict[str, Any] = {
            "command": command,
            "samples": samples,
            **summarize_samples(samples),
        }
        if mode not in LLVMBPF_MODE_FLAGS:
            last_recompile = samples[-1].get("recompile", {})
            entry["recompile"] = {
                key: last_recompile.get(key)
                for key in (
                    "requested",
                    "mode",
                    "applied",
                    "cmov_sites",
                    "wide_sites",
                    "rotate_sites",
                    "lea_sites",
                    "bitfield_sites",
                    "total_sites",
                    "error",
                )
            }
        modes[mode] = entry

    output = {
        "benchmark": args.bench,
        "program": str(benchmark.program_object),
        "memory": str(memory),
        "io_mode": benchmark.io_mode,
        "iterations": args.iterations,
        "warmups": args.warmups,
        "repeat": args.repeat,
        "cpu": args.cpu,
        "modes": modes,
    }
    output_path = Path(args.output)
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(json.dumps(output, indent=2))
    if args.stdout_json:
        print(json.dumps(output))
    else:
        print(json.dumps({name: data["exec_ns"]["median"] for name, data in modes.items()}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
