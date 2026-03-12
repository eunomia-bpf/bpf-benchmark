#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import platform
import statistics
import subprocess
import sys
from collections import defaultdict
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

REPO_ROOT = Path(__file__).resolve().parents[2]
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

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


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Run stock-kernel vs kernel-recompile microbenchmarks and keep going across failures."
    )
    parser.add_argument("--suite", default=str(CONFIG_PATH), help="Path to suite YAML.")
    parser.add_argument("--bench", action="append", dest="benches", help="Benchmark name.")
    parser.add_argument("--iterations", type=int, default=10, help="Measured runs per pair.")
    parser.add_argument("--warmups", type=int, default=2, help="Warmup runs per pair.")
    parser.add_argument("--repeat", type=int, default=500, help="Repeat count inside each helper sample.")
    parser.add_argument("--cpu", default="0", help="Pin child processes to a specific CPU via taskset.")
    parser.add_argument(
        "--output-json",
        default=str(ROOT_DIR / "micro" / "results" / "kernel_recompile_strict_20260312.json"),
        help="Output JSON path.",
    )
    parser.add_argument(
        "--output-md",
        default=str(ROOT_DIR / "docs" / "tmp" / "kernel-recompile-micro-strict.md"),
        help="Output Markdown path.",
    )
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


def resolve_policy_inputs(benchmark: BenchmarkSpec) -> tuple[str | None, Path | None]:
    return None, benchmark.policy_file


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
    except Exception as exc:  # pragma: no cover - defensive logging
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
    if abs(float(value) - round(float(value))) < 1e-9:
        value = int(round(float(value)))
    if value >= 1_000_000:
        return f"{float(value) / 1_000_000:.3f} ms"
    if value >= 1_000:
        return f"{float(value) / 1_000:.3f} us"
    return f"{value} ns"


def benchmark_pair_summary(benchmark_record: dict[str, Any]) -> dict[str, Any]:
    by_runtime = {run["runtime"]: run for run in benchmark_record["runs"]}
    stock = by_runtime.get("kernel")
    recompile = by_runtime.get("kernel-recompile")
    stock_median = None
    recompile_median = None
    ratio = None
    if stock and stock.get("measurement_complete"):
        stock_median = stock.get("exec_ns", {}).get("median")
    if recompile and recompile.get("measurement_complete"):
        recompile_median = recompile.get("exec_ns", {}).get("median")
    if stock_median not in (None, 0) and recompile_median not in (None, 0):
        ratio = float(stock_median) / float(recompile_median)
    recompile_observation = recompile.get("recompile_observation", {}) if recompile else {}
    return {
        "stock_exec_ns_median": stock_median,
        "recompile_exec_ns_median": recompile_median,
        "ratio_stock_over_recompile": ratio,
        "ratio_status": ratio_status(ratio),
        "stock_complete": bool(stock and stock.get("measurement_complete")),
        "recompile_complete": bool(recompile and recompile.get("measurement_complete")),
        "recompile_applied": bool(recompile_observation.get("applied")),
        "recompile_total_sites": int(recompile_observation.get("total_sites", 0) or 0),
        "recompile_sites": {
            "cmov": int(recompile_observation.get("cmov_sites", 0) or 0),
            "wide": int(recompile_observation.get("wide_sites", 0) or 0),
            "rotate": int(recompile_observation.get("rotate_sites", 0) or 0),
            "lea": int(recompile_observation.get("lea_sites", 0) or 0),
            "bitfield_extract": int(recompile_observation.get("bitfield_sites", 0) or 0),
            "zero_ext": int(recompile_observation.get("zero_ext_sites", 0) or 0),
            "endian": int(recompile_observation.get("endian_sites", 0) or 0),
            "branch_flip": int(recompile_observation.get("branch_flip_sites", 0) or 0),
        },
        "stock_status": stock.get("status") if stock else "missing",
        "recompile_status": recompile.get("status") if recompile else "missing",
    }


def build_summary(results: dict[str, Any]) -> dict[str, Any]:
    benchmark_rows: list[dict[str, Any]] = []
    overall_ratios: list[float] = []
    applied_ratios: list[float] = []
    wins = 0
    losses = 0
    ties = 0
    invalid = 0
    per_family: dict[str, list[dict[str, Any]]] = defaultdict(list)

    for benchmark_record in results["benchmarks"]:
        pair = benchmark_pair_summary(benchmark_record)
        row = {
            "name": benchmark_record["name"],
            "category": benchmark_record["category"],
            "family": benchmark_record["family"],
            "io_mode": benchmark_record["io_mode"],
            **pair,
        }
        benchmark_rows.append(row)
        per_family[str(benchmark_record["family"])].append(row)
        ratio = row["ratio_stock_over_recompile"]
        if ratio is None:
            invalid += 1
            continue
        overall_ratios.append(float(ratio))
        if ratio > 1.0:
            wins += 1
        elif ratio < 1.0:
            losses += 1
        else:
            ties += 1
        if row["recompile_applied"]:
            applied_ratios.append(float(ratio))

    family_summary = []
    for family, rows in sorted(per_family.items()):
        valid_ratios = [float(row["ratio_stock_over_recompile"]) for row in rows if row["ratio_stock_over_recompile"] is not None]
        applied_valid_ratios = [
            float(row["ratio_stock_over_recompile"])
            for row in rows
            if row["ratio_stock_over_recompile"] is not None and row["recompile_applied"]
        ]
        family_summary.append(
            {
                "family": family,
                "benchmarks": len(rows),
                "valid_pairs": len(valid_ratios),
                "applied_pairs": len(applied_valid_ratios),
                "geomean_stock_over_recompile": geometric_mean(valid_ratios),
                "applied_only_geomean_stock_over_recompile": geometric_mean(applied_valid_ratios),
                "wins": sum(1 for value in valid_ratios if value > 1.0),
                "losses": sum(1 for value in valid_ratios if value < 1.0),
                "ties": sum(1 for value in valid_ratios if value == 1.0),
            }
        )

    return {
        "benchmark_rows": benchmark_rows,
        "overall": {
            "benchmarks_total": len(benchmark_rows),
            "valid_pairs": len(overall_ratios),
            "invalid_pairs": invalid,
            "applied_pairs": len(applied_ratios),
            "geomean_stock_over_recompile": geometric_mean(overall_ratios),
            "applied_only_geomean_stock_over_recompile": geometric_mean(applied_ratios),
            "wins": wins,
            "losses": losses,
            "ties": ties,
        },
        "family_breakdown": family_summary,
    }


def render_markdown(results: dict[str, Any]) -> str:
    summary = results["summary"]
    overall = summary["overall"]
    lines = [
        "# Kernel Recompile Micro Strict",
        "",
        "## Methodology",
        "",
        f"- Kernel: `{results['host']['kernel_version']}`",
        f"- Benchmarks: `{overall['benchmarks_total']}` from `config/micro_pure_jit.yaml`",
        f"- Runtimes: `kernel` vs `kernel-recompile`",
        f"- Warmups / iterations / repeat: `{results['defaults']['warmups']} / {results['defaults']['iterations']} / {results['defaults']['repeat']}`",
        f"- CPU pinning: `taskset -c {results['host']['cpu_affinity']}`",
        f"- CPU governor: `{results['host']['cpu_governor']}`",
        f"- Turbo state: `{results['host']['turbo_state']}`",
        "",
        "## Headline Numbers",
        "",
        f"- Overall geomean (stock / recompile, valid pairs only): `{format_ratio(overall['geomean_stock_over_recompile'])}`",
        f"- Applied-only geomean (stock / recompile): `{format_ratio(overall['applied_only_geomean_stock_over_recompile'])}`",
        f"- Wins / losses / ties: `{overall['wins']} / {overall['losses']} / {overall['ties']}`",
        f"- Valid / invalid pairs: `{overall['valid_pairs']} / {overall['invalid_pairs']}`",
        "",
        "## Per-Family Breakdown",
        "",
        "| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |",
        "| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |",
    ]
    for row in summary["family_breakdown"]:
        lines.append(
            "| {family} | {benchmarks} | {valid_pairs} | {applied_pairs} | {geo} | {applied_geo} | {wins} | {losses} | {ties} |".format(
                family=row["family"],
                benchmarks=row["benchmarks"],
                valid_pairs=row["valid_pairs"],
                applied_pairs=row["applied_pairs"],
                geo=format_ratio(row["geomean_stock_over_recompile"]),
                applied_geo=format_ratio(row["applied_only_geomean_stock_over_recompile"]),
                wins=row["wins"],
                losses=row["losses"],
                ties=row["ties"],
            )
        )

    lines.extend(
        [
            "",
            "## Per-Benchmark Table",
            "",
            "| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |",
            "| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |",
        ]
    )
    for row in summary["benchmark_rows"]:
        if row["ratio_stock_over_recompile"] is None:
            status = f"{row['stock_status']} / {row['recompile_status']}"
        else:
            status = row["ratio_status"]
        lines.append(
            "| {name} | {family} | {stock} | {recompile} | {ratio} | {applied} | {sites} | {status} |".format(
                name=row["name"],
                family=row["family"],
                stock=format_ns(row["stock_exec_ns_median"]),
                recompile=format_ns(row["recompile_exec_ns_median"]),
                ratio=format_ratio(row["ratio_stock_over_recompile"]),
                applied="yes" if row["recompile_applied"] else "no",
                sites=row["recompile_total_sites"],
                status=status,
            )
        )
    return "\n".join(lines) + "\n"


def checkpoint_results(results: dict[str, Any], output_json: Path, output_md: Path) -> None:
    results["summary"] = build_summary(results)
    output_json.parent.mkdir(parents=True, exist_ok=True)
    output_md.parent.mkdir(parents=True, exist_ok=True)
    output_json.write_text(json.dumps(results, indent=2) + "\n")
    output_md.write_text(render_markdown(results))


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    suite = load_suite(Path(args.suite))
    benchmarks = select_benchmarks(args.benches, suite)
    runtimes = [suite.runtimes["kernel"], suite.runtimes["kernel-recompile"]]
    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()

    results: dict[str, Any] = {
        "suite": suite.suite_name,
        "manifest": str(suite.manifest_path),
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "host": {
            "hostname": platform.node(),
            "platform": platform.platform(),
            "python": sys.version.split()[0],
            "cpu_affinity": args.cpu,
            "git_sha": read_git_sha(),
            "kernel_version": platform.release(),
            "kernel_cmdline": read_required_text("/proc/cmdline"),
            "cpu_governor": read_optional_text("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor") or "unknown",
            "turbo_state": read_optional_text("/sys/devices/system/cpu/intel_pstate/no_turbo") or "unknown",
            "perf_event_paranoid": read_optional_text("/proc/sys/kernel/perf_event_paranoid"),
        },
        "defaults": {
            "iterations": args.iterations,
            "warmups": args.warmups,
            "repeat": args.repeat,
            "cpu": args.cpu,
        },
        "benchmarks": [],
    }

    for benchmark in benchmarks:
        print(f"[bench] {benchmark.name}", flush=True)
        memory_file = resolve_memory_file(benchmark, False)
        benchmark_record: dict[str, Any] = {
            "name": benchmark.name,
            "description": benchmark.description,
            "category": benchmark.category,
            "family": benchmark.family,
            "level": benchmark.level,
            "io_mode": benchmark.io_mode,
            "tags": list(benchmark.tags),
            "expected_result": benchmark.expected_result,
            "input": str(memory_file) if memory_file is not None else None,
            "policy": dict(benchmark.policy) if benchmark.policy is not None else None,
            "policy_file": str(benchmark.policy_file) if benchmark.policy_file else None,
            "runs": [],
        }

        for runtime in runtimes:
            inline_policy: str | None = None
            policy_file: Path | None = None
            if runtime.mode in {"kernel-recompile", "kernel_recompile"}:
                inline_policy, policy_file = resolve_policy_inputs(benchmark)
            command = build_micro_benchmark_command(
                suite.build.runner_binary,
                runtime_mode=runtime.mode,
                program=benchmark.program_object,
                io_mode=benchmark.io_mode,
                repeat=args.repeat,
                memory=memory_file,
                input_size=benchmark.kernel_input_size,
                policy=inline_policy,
                policy_file=policy_file,
                perf_counters=False,
                perf_scope="full_repeat_raw",
                require_sudo=runtime.require_sudo,
            )

            run_record: dict[str, Any] = {
                "runtime": runtime.name,
                "label": runtime.label,
                "mode": runtime.mode,
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
            benchmark_record["runs"].append(run_record)
            median_exec = run_record.get("exec_ns", {}).get("median")
            applied = run_record.get("recompile_observation", {}).get("applied")
            print(
                "  {runtime:16} status={status:16} exec={exec} applied={applied}".format(
                    runtime=runtime.name,
                    status=run_record["status"],
                    exec=format_ns(median_exec),
                    applied=applied if runtime.name == "kernel-recompile" else "-",
                ),
                flush=True,
            )

        results["benchmarks"].append(benchmark_record)
        checkpoint_results(results, output_json, output_md)

    checkpoint_results(results, output_json, output_md)
    print(f"[done] wrote {output_json}", flush=True)
    print(f"[done] wrote {output_md}", flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
