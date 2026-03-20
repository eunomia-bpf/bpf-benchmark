#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import platform
import random
import shlex
import statistics
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

REPO_ROOT = Path(__file__).resolve().parent.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from benchmark_catalog import CONFIG_PATH, ROOT_DIR, BenchmarkSpec, load_suite
from runner.libs.results import parse_command_samples
try:
    from runner.libs.rigorous import (
        DEFAULT_BOOTSTRAP_SAMPLES,
        DEFAULT_HEAVY_PROCESS_SAMPLE_SECONDS,
        DEFAULT_HEAVY_PROCESS_THRESHOLD,
        DEFAULT_ITERATIONS,
        DEFAULT_REPEAT,
        DEFAULT_WARMUPS,
        QUICK_ITERATIONS,
        QUICK_REPEAT,
        QUICK_WARMUPS,
        ModeSpec,
        PinningSpec,
        benjamini_hochberg_adjust,
        build_base_command,
        choose_pinning_spec,
        detect_heavy_processes,
        disable_turbo,
        execute_build_commands,
        format_ci_range,
        format_float,
        governor_snapshot,
        kernel_mode_catalog,
        planned_build_commands,
        resolve_memory_file,
        resolve_runtime,
        run_checked,
        run_root_shell,
        set_governor_performance,
        summarize_exec,
        turbo_snapshot,
        wilcoxon_signed_rank,
    )
except ImportError:
    from runner.libs.rigorous import (
        DEFAULT_BOOTSTRAP_SAMPLES,
        DEFAULT_HEAVY_PROCESS_SAMPLE_SECONDS,
        DEFAULT_HEAVY_PROCESS_THRESHOLD,
        DEFAULT_ITERATIONS,
        DEFAULT_REPEAT,
        DEFAULT_WARMUPS,
        QUICK_ITERATIONS,
        QUICK_REPEAT,
        QUICK_WARMUPS,
        ModeSpec,
        PinningSpec,
        benjamini_hochberg_adjust,
        build_base_command,
        choose_pinning_spec,
        detect_heavy_processes,
        disable_turbo,
        execute_build_commands,
        format_ci_range,
        format_float,
        governor_snapshot,
        kernel_mode_catalog,
        planned_build_commands,
        resolve_memory_file,
        resolve_runtime,
        run_checked,
        run_root_shell,
        set_governor_performance,
        summarize_exec,
        turbo_snapshot,
        wilcoxon_signed_rank,
    )


MICRO_ROOT = Path(__file__).resolve().parent
DEFAULT_KERNEL_TARGET = ROOT_DIR / "vendor" / "linux-framework"
DEFAULT_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "rigorous-benchmark-results.md"
DEFAULT_OUTPUT_JSON = ROOT_DIR / "docs" / "tmp" / "rigorous-benchmark-results.json"
DEFAULT_TIMEOUT_SECONDS = 300


@dataclass(frozen=True)
class BenchmarkCase:
    benchmark_name: str
    mode_name: str
    note: str


@dataclass(frozen=True)
class CaseContext:
    benchmark: BenchmarkSpec
    compare_mode: ModeSpec
    note: str
    memory_file: Path | None


@dataclass(frozen=True)
class ManifestEntry:
    benchmark_name: str
    mode_name: str
    phase: str
    command: tuple[str, ...]


@dataclass(frozen=True)
class SystemMutationState:
    original_governor: dict[str, object]
    original_turbo: dict[str, object]
    changed_governor: bool
    changed_turbo: bool


def default_cases() -> tuple[BenchmarkCase, ...]:
    return (
        BenchmarkCase("log2_fold", "recompile-v5-cmov", "policy-sensitivity case"),
        BenchmarkCase("rotate64_hash", "recompile-v5-all", "best perf improvement case"),
        BenchmarkCase("load_byte_recompose", "recompile-v5-wide", "byte-load recomposition case"),
        BenchmarkCase("stride_load_16", "recompile-v5-lea", "address-generation case"),
        BenchmarkCase("packet_rss_hash", "recompile-v5-rotate", "rotate lowering case"),
    )


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Run rigorous framework-kernel microbenchmarks inside a vng guest."
    )
    parser.add_argument("--suite", default=str(CONFIG_PATH), help="Path to suite YAML.")
    parser.add_argument(
        "--bench",
        action="append",
        dest="benches",
        help="Subset of default benchmark cases to run. Repeatable.",
    )
    parser.add_argument(
        "--iterations",
        type=int,
        help=f"Measured iterations per benchmark/mode pair (default: {DEFAULT_ITERATIONS}).",
    )
    parser.add_argument(
        "--warmups",
        type=int,
        help=f"Warmup iterations per benchmark/mode pair inside each guest boot (default: {DEFAULT_WARMUPS}).",
    )
    parser.add_argument(
        "--repeat",
        type=int,
        help=f"Repeats inside each micro_exec invocation (default: {DEFAULT_REPEAT}).",
    )
    parser.add_argument("--cpu", type=int, help="Host CPU used for the single pinned guest vCPU.")
    parser.add_argument(
        "--pin-tool",
        choices=["auto", "taskset", "numactl"],
        default="auto",
        help="Host pinning selector used to pick the default CPU.",
    )
    parser.add_argument(
        "--bootstrap-samples",
        type=int,
        default=DEFAULT_BOOTSTRAP_SAMPLES,
        help=f"Bootstrap resamples for confidence intervals (default: {DEFAULT_BOOTSTRAP_SAMPLES}).",
    )
    parser.add_argument("--seed", type=int, default=0, help="Random seed for benchmark-order shuffling.")
    parser.add_argument(
        "--heavy-process-threshold",
        type=float,
        default=DEFAULT_HEAVY_PROCESS_THRESHOLD,
        help="Fail if other host processes exceed this CPU percent of one core during preflight.",
    )
    parser.add_argument(
        "--heavy-process-sample-seconds",
        type=float,
        default=DEFAULT_HEAVY_PROCESS_SAMPLE_SECONDS,
        help="Sampling window for heavy-process detection.",
    )
    parser.add_argument(
        "--kernel",
        default=str(DEFAULT_KERNEL_TARGET),
        help="Kernel tree or bzImage passed to vng --run.",
    )
    parser.add_argument("--vng", default="vng", help="vng executable to use.")
    parser.add_argument(
        "--timeout",
        type=int,
        default=DEFAULT_TIMEOUT_SECONDS,
        help="Per-guest-boot timeout in seconds.",
    )
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD), help="Markdown output path.")
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON), help="JSON output path.")
    parser.add_argument("--skip-build", action="store_true", help="Skip building micro_exec and programs.")
    parser.add_argument(
        "--no-system-fixes",
        action="store_true",
        help="Do not try to force performance governor / disable turbo.",
    )
    parser.add_argument("--dry-run", action="store_true", help="Print the planned guest commands without running them.")
    parser.add_argument("--quick", action="store_true", help="Use a short smoke-test configuration.")
    return parser.parse_args(argv)


def select_cases(raw_names: list[str] | None) -> list[BenchmarkCase]:
    cases = list(default_cases())
    if not raw_names:
        return cases
    by_name = {case.benchmark_name: case for case in cases}
    selected: list[BenchmarkCase] = []
    for name in raw_names:
        case = by_name.get(name)
        if case is None:
            valid = ", ".join(case.benchmark_name for case in cases)
            raise SystemExit(f"unknown benchmark case '{name}'. Valid cases: {valid}")
        selected.append(case)
    return selected


def ensure_parent(path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)


def read_git_sha() -> str:
    return run_checked(["git", "rev-parse", "HEAD"], cwd=ROOT_DIR).stdout.strip()


def restore_governors(snapshot: dict[str, object]) -> None:
    per_cpu = snapshot.get("per_cpu")
    if not isinstance(per_cpu, dict) or not per_cpu:
        return
    lines = ["set -euo pipefail"]
    for cpu_text, governor in sorted(per_cpu.items(), key=lambda item: int(item[0])):
        lines.append(
            f"echo {shlex.quote(str(governor))} > /sys/devices/system/cpu/cpu{cpu_text}/cpufreq/scaling_governor"
        )
    run_root_shell("\n".join(lines) + "\n")


def restore_turbo(snapshot: dict[str, object]) -> None:
    interface = snapshot.get("interface")
    raw_value = snapshot.get("raw_value")
    if not isinstance(interface, str) or not interface:
        return
    if raw_value in (None, "unknown"):
        return
    run_root_shell(f"set -euo pipefail\necho {shlex.quote(str(raw_value))} > {shlex.quote(interface)}\n")


def apply_host_preflight(
    *,
    pinning: PinningSpec,
    allow_system_fixes: bool,
    heavy_process_threshold: float,
    heavy_process_sample_seconds: float,
) -> tuple[dict[str, object], SystemMutationState]:
    original_governor = governor_snapshot()
    original_turbo = turbo_snapshot()
    changed_governor = False
    changed_turbo = False

    if allow_system_fixes and not original_governor["all_performance"]:
        set_governor_performance()
        changed_governor = True
    if allow_system_fixes and turbo_snapshot()["disabled"] is False:
        disable_turbo()
        changed_turbo = True

    governor = governor_snapshot()
    turbo = turbo_snapshot()
    heavy = detect_heavy_processes(heavy_process_threshold, heavy_process_sample_seconds)
    checks = [
        {"name": "cpu_governor", "status": "pass" if governor["all_performance"] else "fail", "detail": governor},
        {
            "name": "turbo_boost",
            "status": "pass" if turbo["disabled"] is not False else "fail",
            "detail": turbo,
        },
        {
            "name": "cpu_pinning",
            "status": "pass",
            "detail": {
                "cpu": pinning.cpu,
                "tool": "vng --cpus 1 --pin",
                "source": pinning.source,
                "is_isolated": pinning.is_isolated,
                "isolated_cpus": list(pinning.isolated_cpus),
                "online_cpus": list(pinning.online_cpus),
            },
        },
        {
            "name": "heavy_processes",
            "status": "pass" if not heavy["heavy_processes"] else "fail",
            "detail": heavy,
        },
    ]
    ok = all(check["status"] == "pass" for check in checks)
    publication_ready = (
        governor["all_performance"]
        and (turbo["disabled"] is not False)
        and not heavy["heavy_processes"]
        and pinning.is_isolated
    )
    host_system = {
        "hostname": platform.node(),
        "platform": platform.platform(),
        "kernel_version": platform.release(),
        "cpu_model": next(
            (
                line.split(":", 1)[1].strip()
                for line in Path("/proc/cpuinfo").read_text().splitlines()
                if line.lower().startswith("model name")
            ),
            "unknown",
        ),
        "governor": governor,
        "turbo": turbo,
        "selected_cpu": pinning.cpu,
        "selected_cpu_source": pinning.source,
        "selected_cpu_isolated": pinning.is_isolated,
        "isolated_cpus": list(pinning.isolated_cpus),
        "online_cpus": list(pinning.online_cpus),
        "git_sha": read_git_sha(),
    }
    mutation_state = SystemMutationState(
        original_governor=original_governor,
        original_turbo=original_turbo,
        changed_governor=changed_governor,
        changed_turbo=changed_turbo,
    )
    return {
        "ok": ok,
        "publication_ready": publication_ready,
        "checks": checks,
        "host_system": host_system,
    }, mutation_state


def parse_json_lines(stdout: str) -> list[dict[str, Any]]:
    return [dict(sample) for sample in parse_command_samples(stdout)]


def summarize_stderr(stderr: str, max_lines: int = 20) -> str:
    lines = [line.rstrip() for line in stderr.splitlines() if line.strip()]
    if not lines:
        return ""
    return "\n".join(lines[-max_lines:])


def build_vng_command(
    *,
    vng_binary: str,
    kernel_target: Path,
    pinning: PinningSpec,
    guest_exec: str,
) -> list[str]:
    return [
        vng_binary,
        "--run",
        str(kernel_target),
        "--cwd",
        str(ROOT_DIR),
        "--disable-monitor",
        "--cpus",
        "1",
        "--pin",
        str(pinning.cpu),
        "--exec",
        guest_exec,
    ]


def write_guest_script(commands: list[list[str]], extra_python_json: str | None = None) -> Path:
    handle = tempfile.NamedTemporaryFile(
        mode="w",
        prefix="rigorous-framework-vm-",
        suffix=".sh",
        dir=ROOT_DIR,
        delete=False,
    )
    with handle:
        handle.write("#!/bin/sh\nset -eu\n")
        handle.write(f"cd {shlex.quote(str(ROOT_DIR))}\n")
        if extra_python_json is not None:
            handle.write("python3 - <<'PY'\n")
            handle.write(extra_python_json)
            if not extra_python_json.endswith("\n"):
                handle.write("\n")
            handle.write("PY\n")
        for command in commands:
            handle.write(" ".join(shlex.quote(part) for part in command) + "\n")
    path = Path(handle.name)
    path.chmod(0o755)
    return path


def run_guest_script(
    *,
    vng_binary: str,
    kernel_target: Path,
    pinning: PinningSpec,
    guest_script: Path,
    timeout_seconds: int,
) -> subprocess.CompletedProcess[str]:
    guest_path = f"./{guest_script.relative_to(ROOT_DIR).as_posix()}"
    command = build_vng_command(
        vng_binary=vng_binary,
        kernel_target=kernel_target,
        pinning=pinning,
        guest_exec=guest_path,
    )
    try:
        return subprocess.run(
            command,
            cwd=ROOT_DIR,
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
        )
    finally:
        guest_script.unlink(missing_ok=True)


def collect_guest_info(
    *,
    vng_binary: str,
    kernel_target: Path,
    pinning: PinningSpec,
    timeout_seconds: int,
) -> dict[str, Any]:
    python_payload = """import json, pathlib, platform
def read(path):
    candidate = pathlib.Path(path)
    if not candidate.exists():
        return None
    return candidate.read_text().strip()
cpu_model = "unknown"
for line in pathlib.Path("/proc/cpuinfo").read_text().splitlines():
    if line.lower().startswith("model name"):
        cpu_model = line.split(":", 1)[1].strip()
        break
print(json.dumps({
    "kind": "guest_info",
    "kernel_version": platform.release(),
    "platform": platform.platform(),
    "cpu_model": cpu_model,
    "guest_cpus": read("/sys/devices/system/cpu/online"),
    "governor_cpu0": read("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor"),
    "intel_no_turbo": read("/sys/devices/system/cpu/intel_pstate/no_turbo"),
    "cpufreq_boost": read("/sys/devices/system/cpu/cpufreq/boost"),
    "cmdline": read("/proc/cmdline"),
}))
"""
    guest_script = write_guest_script([], extra_python_json=python_payload)
    completed = run_guest_script(
        vng_binary=vng_binary,
        kernel_target=kernel_target,
        pinning=pinning,
        guest_script=guest_script,
        timeout_seconds=timeout_seconds,
    )
    if completed.returncode != 0:
        raise RuntimeError(
            "guest info collection failed\n"
            f"stdout:\n{completed.stdout}\n"
            f"stderr:\n{summarize_stderr(completed.stderr)}"
        )
    payloads = parse_json_lines(completed.stdout)
    if len(payloads) != 1 or payloads[0].get("kind") != "guest_info":
        raise RuntimeError(f"unexpected guest info output:\n{completed.stdout}")
    return payloads[0]


def prepare_case_contexts(suite_path: Path, cases: list[BenchmarkCase]) -> tuple[Any, list[CaseContext]]:
    suite = load_suite(suite_path)
    runtime = resolve_runtime("kernel", suite)
    catalog = kernel_mode_catalog()
    contexts: list[CaseContext] = []
    for case in cases:
        benchmark = suite.benchmarks.get(case.benchmark_name)
        if benchmark is None:
            raise SystemExit(f"benchmark missing from suite: {case.benchmark_name}")
        compare_mode = catalog.get(case.mode_name)
        if compare_mode is None:
            raise SystemExit(f"mode missing from catalog: {case.mode_name}")
        memory_file = resolve_memory_file(benchmark, regenerate_inputs=False)
        contexts.append(
            CaseContext(
                benchmark=benchmark,
                compare_mode=compare_mode,
                note=case.note,
                memory_file=memory_file.resolve() if memory_file is not None else None,
            )
        )
    return runtime, contexts


def build_iteration_plan(
    *,
    suite: Any,
    runtime: Any,
    contexts: list[CaseContext],
    repeat: int,
    warmups: int,
    seed: int,
    iteration_index: int,
) -> tuple[list[list[str]], list[ManifestEntry], list[str], dict[str, list[str]]]:
    rng = random.Random(seed + iteration_index)
    ordered_contexts = list(contexts)
    rng.shuffle(ordered_contexts)

    commands: list[list[str]] = []
    manifest: list[ManifestEntry] = []
    benchmark_order: list[str] = [context.benchmark.name for context in ordered_contexts]
    mode_orders: dict[str, list[str]] = {}
    stock_mode = kernel_mode_catalog()["stock"]

    for context in ordered_contexts:
        mode_sequence = [stock_mode, context.compare_mode]
        if iteration_index % 2 == 1:
            mode_sequence.reverse()
        mode_orders[context.benchmark.name] = [mode.name for mode in mode_sequence]

        base_commands = {
            mode.name: build_base_command(
                suite=suite,
                runtime=runtime,
                benchmark=context.benchmark,
                repeat=repeat,
                memory_file=context.memory_file,
                mode=mode,
            )
            for mode in mode_sequence
        }

        for _ in range(warmups):
            for mode in mode_sequence:
                command = list(base_commands[mode.name])
                commands.append(command)
                manifest.append(
                    ManifestEntry(
                        benchmark_name=context.benchmark.name,
                        mode_name=mode.name,
                        phase="warmup",
                        command=tuple(command),
                    )
                )

        for mode in mode_sequence:
            command = list(base_commands[mode.name])
            commands.append(command)
            manifest.append(
                ManifestEntry(
                    benchmark_name=context.benchmark.name,
                    mode_name=mode.name,
                    phase="measure",
                    command=tuple(command),
                )
            )

    return commands, manifest, benchmark_order, mode_orders


def extract_native_code_bytes(sample: dict[str, Any]) -> float:
    code_size = sample.get("code_size")
    if isinstance(code_size, dict) and code_size.get("native_code_bytes") is not None:
        return float(code_size["native_code_bytes"])
    if sample.get("jited_prog_len") is not None:
        return float(sample["jited_prog_len"])
    return math.nan


def summarize_scalar(values: list[float]) -> dict[str, float]:
    return {
        "n": len(values),
        "median": float(statistics.median(values)),
        "mean": float(statistics.fmean(values)),
        "stdev": float(statistics.stdev(values)) if len(values) > 1 else 0.0,
        "min": float(min(values)),
        "max": float(max(values)),
    }


def verify_sample(context_by_name: dict[str, CaseContext], entry: ManifestEntry, sample: dict[str, Any]) -> None:
    context = context_by_name[entry.benchmark_name]
    expected = context.benchmark.expected_result
    if expected is not None and int(sample.get("result")) != expected:
        raise RuntimeError(
            f"{entry.benchmark_name}/{entry.mode_name} returned {sample.get('result')} != expected {expected}"
        )

    if entry.mode_name == "stock":
        return

    recompile = sample.get("recompile") or {}
    if not recompile.get("applied"):
        error = recompile.get("error") or "recompile not applied"
        raise RuntimeError(f"{entry.benchmark_name}/{entry.mode_name} did not apply recompile: {error}")


def run_iteration(
    *,
    vng_binary: str,
    kernel_target: Path,
    pinning: PinningSpec,
    suite: Any,
    runtime: Any,
    contexts: list[CaseContext],
    repeat: int,
    warmups: int,
    seed: int,
    iteration_index: int,
    timeout_seconds: int,
) -> dict[str, Any]:
    commands, manifest, benchmark_order, mode_orders = build_iteration_plan(
        suite=suite,
        runtime=runtime,
        contexts=contexts,
        repeat=repeat,
        warmups=warmups,
        seed=seed,
        iteration_index=iteration_index,
    )
    guest_script = write_guest_script(commands)
    completed = run_guest_script(
        vng_binary=vng_binary,
        kernel_target=kernel_target,
        pinning=pinning,
        guest_script=guest_script,
        timeout_seconds=timeout_seconds,
    )
    if completed.returncode != 0:
        raise RuntimeError(
            f"iteration {iteration_index} failed with exit {completed.returncode}\n"
            f"stdout:\n{completed.stdout}\n"
            f"stderr:\n{summarize_stderr(completed.stderr)}"
        )

    parsed = parse_json_lines(completed.stdout)
    if len(parsed) != len(manifest):
        raise RuntimeError(
            f"iteration {iteration_index} expected {len(manifest)} JSON objects but parsed {len(parsed)}\n"
            f"stdout:\n{completed.stdout}\n"
            f"stderr:\n{summarize_stderr(completed.stderr)}"
        )

    context_by_name = {context.benchmark.name: context for context in contexts}
    measured: list[dict[str, Any]] = []
    for entry, sample in zip(manifest, parsed, strict=True):
        verify_sample(context_by_name, entry, sample)
        if entry.phase != "measure":
            continue
        measured.append(
            {
                "benchmark": entry.benchmark_name,
                "mode": entry.mode_name,
                "iteration_index": iteration_index,
                "command": list(entry.command),
                "sample": sample,
            }
        )

    return {
        "iteration_index": iteration_index,
        "benchmark_order": benchmark_order,
        "mode_orders": mode_orders,
        "stderr_summary": summarize_stderr(completed.stderr),
        "measured": measured,
    }


def build_results(
    *,
    contexts: list[CaseContext],
    collected: dict[str, dict[str, list[dict[str, Any]]]],
    bootstrap_samples: int,
    seed: int,
) -> list[dict[str, Any]]:
    results: list[dict[str, Any]] = []
    for context_index, context in enumerate(contexts):
        samples_by_mode = collected[context.benchmark.name]
        stock_samples = sorted(samples_by_mode["stock"], key=lambda item: item["iteration_index"])
        variant_samples = sorted(samples_by_mode[context.compare_mode.name], key=lambda item: item["iteration_index"])
        stock_exec = [float(item["sample"]["exec_ns"]) for item in stock_samples]
        variant_exec = [float(item["sample"]["exec_ns"]) for item in variant_samples]
        stock_code = [extract_native_code_bytes(item["sample"]) for item in stock_samples]
        variant_code = [extract_native_code_bytes(item["sample"]) for item in variant_samples]

        comparison = {
            "paired_iterations": [int(item["iteration_index"]) for item in stock_samples],
            "wilcoxon": wilcoxon_signed_rank(stock_exec, variant_exec),
            "median_ratio_stock_over_variant": (
                float(statistics.median([left / right for left, right in zip(stock_exec, variant_exec) if right != 0]))
                if variant_exec
                else math.nan
            ),
            "mean_ratio_stock_over_variant": (
                float(statistics.fmean(stock_exec) / statistics.fmean(variant_exec))
                if variant_exec and statistics.fmean(variant_exec) != 0
                else math.nan
            ),
            "mean_delta_ns_stock_minus_variant": float(
                statistics.fmean([left - right for left, right in zip(stock_exec, variant_exec)])
            ),
            "wins_variant": sum(1 for left, right in zip(stock_exec, variant_exec) if right < left),
            "wins_stock": sum(1 for left, right in zip(stock_exec, variant_exec) if left < right),
            "ties": sum(1 for left, right in zip(stock_exec, variant_exec) if left == right),
        }
        results.append(
            {
                "name": context.benchmark.name,
                "note": context.note,
                "compare_mode": context.compare_mode.name,
                "modes": {
                    "stock": {
                        "samples": stock_samples,
                        "exec_stats": summarize_exec(stock_exec, bootstrap_samples, seed + (context_index * 17)),
                        "code_size_stats": summarize_scalar(stock_code),
                    },
                    context.compare_mode.name: {
                        "samples": variant_samples,
                        "exec_stats": summarize_exec(
                            variant_exec,
                            bootstrap_samples,
                            seed + (context_index * 17) + 1,
                        ),
                        "code_size_stats": summarize_scalar(variant_code),
                    },
                },
                "comparison": comparison,
            }
        )

    adjusted = benjamini_hochberg_adjust(
        [float(benchmark["comparison"]["wilcoxon"]["pvalue"]) for benchmark in results]
    )
    for benchmark, adjusted_value in zip(results, adjusted, strict=True):
        benchmark["comparison"]["pvalue_adjusted_bh"] = adjusted_value
        benchmark["comparison"]["significant_bh_0_05"] = (
            adjusted_value is not None and adjusted_value <= 0.05
        )
    return results


def print_dry_run(
    *,
    suite: Any,
    runtime: Any,
    contexts: list[CaseContext],
    repeat: int,
    warmups: int,
    seed: int,
    pinning: PinningSpec,
    kernel_target: Path,
    vng_binary: str,
) -> None:
    print("[dry-run] configuration")
    print(
        json.dumps(
            {
                "kernel_target": str(kernel_target),
                "vng": vng_binary,
                "repeat": repeat,
                "warmups": warmups,
                "pinning": {
                    "cpu": pinning.cpu,
                    "source": pinning.source,
                    "isolated": pinning.is_isolated,
                },
                "benchmarks": [
                    {"benchmark": context.benchmark.name, "mode": context.compare_mode.name}
                    for context in contexts
                ],
            },
            indent=2,
        )
    )
    commands, manifest, benchmark_order, mode_orders = build_iteration_plan(
        suite=suite,
        runtime=runtime,
        contexts=contexts,
        repeat=repeat,
        warmups=warmups,
        seed=seed,
        iteration_index=0,
    )
    print("[dry-run] iteration-0 benchmark order")
    print("  " + ", ".join(benchmark_order))
    print("[dry-run] iteration-0 mode order")
    for benchmark_name in benchmark_order:
        print(f"  {benchmark_name}: {', '.join(mode_orders[benchmark_name])}")
    print("[dry-run] guest command")
    guest_path = "./tmp-generated-guest-script.sh"
    print(
        "  "
        + " ".join(
            shlex.quote(part)
            for part in build_vng_command(
                vng_binary=vng_binary,
                kernel_target=kernel_target,
                pinning=pinning,
                guest_exec=guest_path,
            )
        )
    )
    print("[dry-run] guest workload")
    for entry in manifest:
        print(f"  [{entry.phase}] {entry.benchmark_name}/{entry.mode_name}: {' '.join(entry.command)}")
    print("[dry-run] total commands:", len(commands))


def write_markdown(
    path: Path,
    payload: dict[str, Any],
) -> None:
    ensure_parent(path)
    lines: list[str] = []
    lines.append("# Rigorous Framework-VM Benchmark Results")
    lines.append("")
    lines.append(f"- Generated at: `{payload['generated_at']}`")
    lines.append(f"- Kernel target: `{payload['kernel_target']}`")
    lines.append(f"- Git SHA: `{payload['host_system']['git_sha']}`")
    lines.append(
        f"- Methodology: `{payload['methodology']['iterations']}` measured iterations, "
        f"`{payload['methodology']['warmups']}` warmups, "
        f"`{payload['methodology']['repeat']}` repeats per `micro_exec` invocation"
    )
    lines.append(
        f"- Pinning: single guest vCPU pinned to host CPU `{payload['host_system']['selected_cpu']}` via `vng --cpus 1 --pin`"
    )
    lines.append("")
    lines.append("## System Configuration")
    lines.append("")
    lines.append(f"- Host CPU: `{payload['host_system']['cpu_model']}`")
    lines.append(f"- Host kernel: `{payload['host_system']['kernel_version']}`")
    lines.append(
        f"- Host governor: `{', '.join(payload['host_system']['governor']['unique']) or 'unknown'}`"
    )
    lines.append(
        f"- Host turbo disabled: `{payload['host_system']['turbo']['disabled']}` via "
        f"`{payload['host_system']['turbo']['interface'] or 'unavailable'}`"
    )
    lines.append(f"- Guest kernel: `{payload['guest_system']['kernel_version']}`")
    lines.append(f"- Guest CPU: `{payload['guest_system']['cpu_model']}`")
    lines.append(f"- Guest governor cpu0: `{payload['guest_system']['governor_cpu0']}`")
    guest_turbo = payload["guest_system"]["intel_no_turbo"]
    if guest_turbo is None:
        guest_turbo = payload["guest_system"]["cpufreq_boost"]
    lines.append(f"- Guest turbo interface raw value: `{guest_turbo}`")
    lines.append(
        f"- Publication-ready host environment: `{payload['preflight']['publication_ready']}` "
        "(false here means the host lacks isolated CPUs even though governor/turbo/pinning were controlled)"
    )
    lines.append("")
    lines.append("## Preflight")
    lines.append("")
    for check in payload["preflight"]["checks"]:
        lines.append(f"- `{check['name']}`: `{check['status']}`")
    lines.append("")

    for benchmark in payload["benchmarks"]:
        mode_name = benchmark["compare_mode"]
        stock = benchmark["modes"]["stock"]
        variant = benchmark["modes"][mode_name]
        comparison = benchmark["comparison"]
        lines.append(f"## {benchmark['name']}")
        lines.append("")
        lines.append(f"- Comparison: `stock` vs `{mode_name}`")
        lines.append(f"- Case: {benchmark['note']}")
        lines.append("")
        lines.append("| Mode | N | Median exec_ns | Mean exec_ns | Stdev | 95% CI (mean) | Median code bytes | Mean code bytes |")
        lines.append("| --- | ---: | ---: | ---: | ---: | --- | ---: | ---: |")
        for label, record in (("stock", stock), (mode_name, variant)):
            exec_stats = record["exec_stats"]
            code_stats = record["code_size_stats"]
            lines.append(
                f"| {label} | {exec_stats['n']} | {format_float(exec_stats['median'])} | "
                f"{format_float(exec_stats['mean'])} | {format_float(exec_stats['stdev'])} | "
                f"{format_ci_range(exec_stats['ci95_mean']['low'], exec_stats['ci95_mean']['high'])} | "
                f"{format_float(code_stats['median'])} | {format_float(code_stats['mean'])} |"
            )
        lines.append("")
        stock_code = stock["code_size_stats"]["median"]
        variant_code = variant["code_size_stats"]["median"]
        code_delta = variant_code - stock_code
        code_pct = (code_delta / stock_code) * 100.0 if stock_code else math.nan
        lines.append(
            f"- Wilcoxon signed-rank: `p={format_float(comparison['wilcoxon']['pvalue'], 4)}` "
            f"(BH-adjusted `q={format_float(comparison['pvalue_adjusted_bh'], 4)}`)"
        )
        lines.append(
            f"- Median speedup (`stock / {mode_name}`): `{format_float(comparison['median_ratio_stock_over_variant'], 3)}x`"
        )
        lines.append(
            f"- Mean delta (`stock - {mode_name}`): `{format_float(comparison['mean_delta_ns_stock_minus_variant'])}` ns"
        )
        lines.append(
            f"- Code size delta (`{mode_name} - stock`): `{format_float(code_delta)}` bytes "
            f"(`{format_float(code_pct, 2)}%`)"
        )
        lines.append(
            f"- Iteration wins: `{mode_name}={comparison['wins_variant']}`, "
            f"`stock={comparison['wins_stock']}`, `ties={comparison['ties']}`"
        )
        lines.append("")

    path.write_text("\n".join(lines) + "\n")


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)

    iterations = QUICK_ITERATIONS if args.quick else (args.iterations or DEFAULT_ITERATIONS)
    warmups = QUICK_WARMUPS if args.quick else (args.warmups or DEFAULT_WARMUPS)
    repeat = QUICK_REPEAT if args.quick else (args.repeat or DEFAULT_REPEAT)
    if iterations <= 0 or warmups < 0 or repeat <= 0:
        raise SystemExit("iterations/repeat must be positive and warmups must be non-negative")

    suite = load_suite(Path(args.suite))
    runtime, contexts = prepare_case_contexts(Path(args.suite), select_cases(args.benches))
    kernel_target = Path(args.kernel).resolve()
    if not kernel_target.exists():
        raise SystemExit(f"kernel target does not exist: {kernel_target}")

    pinning = choose_pinning_spec(args.cpu, args.pin_tool)
    preflight, mutation_state = apply_host_preflight(
        pinning=pinning,
        allow_system_fixes=not args.no_system_fixes,
        heavy_process_threshold=args.heavy_process_threshold,
        heavy_process_sample_seconds=args.heavy_process_sample_seconds,
    )
    if not preflight["ok"]:
        print(json.dumps(preflight, indent=2), file=sys.stderr)
        raise SystemExit("host preflight failed")

    if args.dry_run:
        print_dry_run(
            suite=suite,
            runtime=runtime,
            contexts=contexts,
            repeat=repeat,
            warmups=warmups,
            seed=args.seed,
            pinning=pinning,
            kernel_target=kernel_target,
            vng_binary=args.vng,
        )
        return 0

    try:
        execute_build_commands(planned_build_commands(suite), args.skip_build)
        guest_info = collect_guest_info(
            vng_binary=args.vng,
            kernel_target=kernel_target,
            pinning=pinning,
            timeout_seconds=args.timeout,
        )

        collected: dict[str, dict[str, list[dict[str, Any]]]] = {}
        for context in contexts:
            collected[context.benchmark.name] = {
                "stock": [],
                context.compare_mode.name: [],
            }

        iteration_records: list[dict[str, Any]] = []
        for iteration_index in range(iterations):
            print(f"[iteration] {iteration_index + 1}/{iterations}")
            record = run_iteration(
                vng_binary=args.vng,
                kernel_target=kernel_target,
                pinning=pinning,
                suite=suite,
                runtime=runtime,
                contexts=contexts,
                repeat=repeat,
                warmups=warmups,
                seed=args.seed,
                iteration_index=iteration_index,
                timeout_seconds=args.timeout,
            )
            iteration_records.append(record)
            for measured in record["measured"]:
                collected[measured["benchmark"]][measured["mode"]].append(measured)
    finally:
        if mutation_state.changed_turbo:
            restore_turbo(mutation_state.original_turbo)
        if mutation_state.changed_governor:
            restore_governors(mutation_state.original_governor)

    benchmark_results = build_results(
        contexts=contexts,
        collected=collected,
        bootstrap_samples=args.bootstrap_samples,
        seed=args.seed,
    )
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "run_id": datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%SZ"),
        "kernel_target": str(kernel_target),
        "methodology": {
            "iterations": iterations,
            "warmups": warmups,
            "repeat": repeat,
            "bootstrap_samples": args.bootstrap_samples,
            "seed": args.seed,
            "paired_test": "Wilcoxon signed-rank",
            "code_size_metric": "native_code_bytes / jited_prog_len fallback",
        },
        "host_system": preflight["host_system"],
        "guest_system": guest_info,
        "preflight": {
            "checks": preflight["checks"],
            "publication_ready": preflight["publication_ready"],
        },
        "iterations": iteration_records,
        "benchmarks": benchmark_results,
    }

    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    ensure_parent(output_json)
    ensure_parent(output_md)
    output_json.write_text(json.dumps(payload, indent=2) + "\n")
    write_markdown(output_md, payload)

    print(f"[done] wrote {output_json}")
    print(f"[done] wrote {output_md}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
