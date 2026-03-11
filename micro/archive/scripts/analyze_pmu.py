#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
from pathlib import Path

import numpy as np
from scipy.stats import pearsonr, spearmanr


ROOT = Path(__file__).resolve().parent.parent.parent
DEFAULT_INPUT = ROOT / "results" / "pmu_authoritative.json"
DEFAULT_OUTPUT = ROOT / "results" / "pmu_analysis.md"
RUNTIMES = ("llvmbpf", "kernel")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Analyze PMU counters vs execution ratio.")
    parser.add_argument("input", nargs="?", default=str(DEFAULT_INPUT), help="Input result JSON.")
    parser.add_argument("--output", default=str(DEFAULT_OUTPUT), help="Markdown output path.")
    return parser.parse_args()


def load_json(path: Path) -> dict[str, object]:
    return json.loads(path.read_text())


def stat_mean(value: object) -> float | None:
    if isinstance(value, dict):
        value = value.get("mean")
    try:
        return None if value is None else float(value)
    except (TypeError, ValueError):
        return None


def averaged_counter(run: dict[str, object], name: str) -> float | None:
    value = stat_mean((run.get("perf_counters") or {}).get(name))
    if value is not None:
        return value
    samples = [stat_mean((sample.get("perf_counters") or {}).get(name)) for sample in run.get("samples", [])]
    values = [value for value in samples if value is not None]
    return float(np.mean(values)) if values else None


def exec_mean(run: dict[str, object]) -> float | None:
    value = stat_mean(run.get("exec_ns"))
    if value is not None:
        return value
    values = [stat_mean(sample.get("exec_ns")) for sample in run.get("samples", [])]
    values = [value for value in values if value is not None]
    return float(np.mean(values)) if values else None


def safe_ratio(num: float | None, den: float | None, scale: float = 1.0) -> float | None:
    if num is None or den is None or den <= 0:
        return None
    return scale * num / den


def runtime_metrics(run: dict[str, object]) -> dict[str, float | None]:
    cycles = averaged_counter(run, "cycles")
    instructions = averaged_counter(run, "instructions")
    branches = averaged_counter(run, "branches")
    branch_misses = averaged_counter(run, "branch_misses")
    cache_refs = averaged_counter(run, "cache_references")
    cache_misses = averaged_counter(run, "cache_misses")
    return {
        "ipc": safe_ratio(instructions, cycles),
        "branch_miss_pct": safe_ratio(branch_misses, branches, scale=100.0),
        "cache_miss_pct": safe_ratio(cache_misses, cache_refs, scale=100.0),
    }


def format_value(value: float | None, precision: int) -> str:
    return "n/a" if value is None or not math.isfinite(value) else f"{value:.{precision}f}"


def build_report(results: dict[str, object]) -> str:
    rows: list[dict[str, object]] = []
    ipc_deltas: list[float] = []
    exec_ratios: list[float] = []
    for benchmark in results.get("benchmarks", []):
        runs = {run.get("runtime"): run for run in benchmark.get("runs", [])}
        metrics = {runtime: runtime_metrics(runs[runtime]) for runtime in RUNTIMES if runtime in runs}
        if not any(value is not None for item in metrics.values() for value in item.values()):
            continue
        llvmbpf = metrics.get("llvmbpf", {})
        kernel = metrics.get("kernel", {})
        rows.append(
            {
                "benchmark": benchmark.get("name", "<unknown>"),
                "ipc_l": llvmbpf.get("ipc"),
                "ipc_k": kernel.get("ipc"),
                "branch_l": llvmbpf.get("branch_miss_pct"),
                "branch_k": kernel.get("branch_miss_pct"),
                "cache_l": llvmbpf.get("cache_miss_pct"),
                "cache_k": kernel.get("cache_miss_pct"),
            }
        )
        lhs_exec = exec_mean(runs["llvmbpf"]) if "llvmbpf" in runs else None
        rhs_exec = exec_mean(runs["kernel"]) if "kernel" in runs else None
        exec_ratio = safe_ratio(lhs_exec, rhs_exec)
        if exec_ratio is not None and llvmbpf.get("ipc") is not None and kernel.get("ipc") is not None:
            ipc_deltas.append(float(llvmbpf["ipc"] - kernel["ipc"]))
            exec_ratios.append(float(exec_ratio))

    pearson = spearman = math.nan
    if len(ipc_deltas) >= 2 and not np.allclose(ipc_deltas, ipc_deltas[0]) and not np.allclose(exec_ratios, exec_ratios[0]):
        pearson = float(pearsonr(ipc_deltas, exec_ratios).statistic)
        spearman = float(spearmanr(ipc_deltas, exec_ratios).statistic)

    lines = [
        "# PMU Analysis",
        "",
        "L = llvmbpf, K = kernel.",
        "",
        "| Benchmark | IPC (L) | IPC (K) | Branch Miss% (L) | Branch Miss% (K) | Cache Miss% (L) | Cache Miss% (K) |",
        "| --- | ---: | ---: | ---: | ---: | ---: | ---: |",
    ]
    for row in rows:
        lines.append(
            f"| {row['benchmark']} | {format_value(row['ipc_l'], 3)} | {format_value(row['ipc_k'], 3)} | "
            f"{format_value(row['branch_l'], 2)} | {format_value(row['branch_k'], 2)} | "
            f"{format_value(row['cache_l'], 2)} | {format_value(row['cache_k'], 2)} |"
        )
    lines.extend(
        [
            "",
            "## Correlation",
            "",
            f"Benchmarks used: {len(ipc_deltas)}",
            "",
            f"- Pearson r (IPC diff vs exec ratio): {format_value(pearson, 4)}",
            f"- Spearman rho (IPC diff vs exec ratio): {format_value(spearman, 4)}",
        ]
    )
    return "\n".join(lines) + "\n"


def main() -> None:
    args = parse_args()
    report = build_report(load_json(Path(args.input)))
    output = Path(args.output)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(report)
if __name__ == "__main__":
    main()
