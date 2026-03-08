#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Compare VM 7.0-rc2 kernel results against llvmbpf.")
    parser.add_argument(
        "--vm-kernel",
        default=str(REPO_ROOT / "tmp" / "vm_authoritative.json"),
        help="Path to VM kernel-only results.",
    )
    parser.add_argument(
        "--llvmbpf",
        help="Path to llvmbpf results. Defaults to tmp/vm_llvmbpf.json if present, else tmp/host_llvmbpf_for_vm_comparison.json.",
    )
    parser.add_argument(
        "--host-authoritative",
        default=str(REPO_ROOT / "micro" / "results" / "pure_jit_authoritative.json"),
        help="Path to host authoritative L/K results.",
    )
    parser.add_argument(
        "--output",
        default=str(REPO_ROOT / "tmp" / "vm_lk_comparison.md"),
        help="Markdown output path.",
    )
    return parser.parse_args()


def load_json(path: Path) -> dict[str, object]:
    return json.loads(path.read_text())


def choose_llvmbpf_path(raw_path: str | None) -> Path:
    if raw_path:
        return Path(raw_path).resolve()
    candidates = [
        REPO_ROOT / "tmp" / "vm_llvmbpf.json",
        REPO_ROOT / "tmp" / "host_llvmbpf_for_vm_comparison.json",
    ]
    for candidate in candidates:
        if candidate.exists():
            return candidate.resolve()
    raise FileNotFoundError(
        "No llvmbpf result file found. Expected tmp/vm_llvmbpf.json or tmp/host_llvmbpf_for_vm_comparison.json."
    )


def geomean(values: list[float]) -> float | None:
    positives = [value for value in values if value > 0]
    if not positives:
        return None
    return math.exp(sum(math.log(value) for value in positives) / len(positives))


def format_ratio(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.3f}x"


def format_ns(value: float | None) -> str:
    if value is None:
        return "n/a"
    if abs(value - round(value)) < 1e-9:
        value = float(int(round(value)))
    return f"{value:.1f}"


def benchmark_runs(results: dict[str, object]) -> dict[str, dict[str, object]]:
    mapping: dict[str, dict[str, object]] = {}
    for benchmark in results.get("benchmarks", []):
        runs = {
            run["runtime"]: run
            for run in benchmark.get("runs", [])
        }
        mapping[benchmark["name"]] = {
            "benchmark": benchmark,
            "runs": runs,
        }
    return mapping


def median_exec(run: dict[str, object] | None) -> float | None:
    if not run:
        return None
    exec_summary = run.get("exec_ns", {})
    value = exec_summary.get("median")
    if value is None:
        return None
    return float(value)


def host_ratio_for_benchmark(benchmark: dict[str, object]) -> float | None:
    runtime_comparison = benchmark.get("runtime_comparison", {})
    value = runtime_comparison.get("llvmbpf_over_kernel_exec_ratio")
    if value is not None:
        return float(value)

    runs = {
        run["runtime"]: run
        for run in benchmark.get("runs", [])
    }
    llvm_exec = median_exec(runs.get("llvmbpf"))
    kernel_exec = median_exec(runs.get("kernel"))
    if llvm_exec is None or kernel_exec in (None, 0.0):
        return None
    return llvm_exec / kernel_exec


def describe_gap(vm_gap: float | None, host_gap: float | None) -> str:
    if vm_gap is None or host_gap is None:
        return "no host baseline"
    if abs(vm_gap - host_gap) < 1e-12:
        return "unchanged"
    if vm_gap < host_gap:
        return "closer to parity"
    return "farther from parity"


def render_top_list(rows: list[dict[str, object]], title: str) -> list[str]:
    lines = [title]
    if not rows:
        lines.append("- none")
        return lines
    for row in rows:
        lines.append(
            "- "
            f"`{row['name']}`: VM L/K {format_ratio(row['vm_ratio'])}, "
            f"host L/K {format_ratio(row['host_ratio'])}, "
            f"parity gap {row['host_gap']:.3f} -> {row['vm_gap']:.3f}"
        )
    return lines


def main() -> int:
    args = parse_args()
    vm_kernel_path = Path(args.vm_kernel).resolve()
    llvmbpf_path = choose_llvmbpf_path(args.llvmbpf)
    host_path = Path(args.host_authoritative).resolve()
    output_path = Path(args.output).resolve()

    vm_kernel = load_json(vm_kernel_path)
    llvmbpf = load_json(llvmbpf_path)
    host = load_json(host_path)

    vm_kernel_runs = benchmark_runs(vm_kernel)
    llvmbpf_runs = benchmark_runs(llvmbpf)
    host_benchmarks = {
        benchmark["name"]: benchmark
        for benchmark in host.get("benchmarks", [])
    }

    rows: list[dict[str, object]] = []
    vm_ratios_all: list[float] = []
    overlap_vm_ratios: list[float] = []
    overlap_host_ratios: list[float] = []
    ratio_shift_values: list[float] = []
    gap_change_values: list[float] = []
    closer_count = 0
    farther_count = 0
    unchanged_count = 0
    vm_only: list[str] = []

    for name in sorted(set(vm_kernel_runs) & set(llvmbpf_runs)):
        kernel_exec = median_exec(vm_kernel_runs[name]["runs"].get("kernel"))
        llvm_exec = median_exec(llvmbpf_runs[name]["runs"].get("llvmbpf"))
        if kernel_exec in (None, 0.0) or llvm_exec is None:
            continue

        vm_ratio = llvm_exec / kernel_exec
        vm_gap = abs(vm_ratio - 1.0)
        vm_ratios_all.append(vm_ratio)

        host_benchmark = host_benchmarks.get(name)
        host_ratio = host_ratio_for_benchmark(host_benchmark) if host_benchmark else None
        host_gap = abs(host_ratio - 1.0) if host_ratio is not None else None
        ratio_shift = (vm_ratio / host_ratio) if host_ratio not in (None, 0.0) else None
        gap_change = None
        if host_gap is not None:
            if abs(host_gap) < 1e-12:
                gap_change = 0.0 if abs(vm_gap) < 1e-12 else None
            else:
                gap_change = vm_gap / host_gap

        if host_ratio is None:
            vm_only.append(name)
        else:
            overlap_vm_ratios.append(vm_ratio)
            overlap_host_ratios.append(host_ratio)
            if ratio_shift is not None:
                ratio_shift_values.append(ratio_shift)
            if gap_change is not None:
                gap_change_values.append(gap_change)
            if host_gap is not None:
                if vm_gap < host_gap:
                    closer_count += 1
                elif vm_gap > host_gap:
                    farther_count += 1
                else:
                    unchanged_count += 1

        rows.append(
            {
                "name": name,
                "llvm_exec": llvm_exec,
                "kernel_exec": kernel_exec,
                "vm_ratio": vm_ratio,
                "host_ratio": host_ratio,
                "vm_gap": vm_gap,
                "host_gap": host_gap,
                "ratio_shift": ratio_shift,
                "gap_change": gap_change,
                "gap_description": describe_gap(vm_gap, host_gap),
            }
        )

    gap_ranked = [row for row in rows if row["host_gap"] is not None]
    largest_closures = sorted(
        gap_ranked,
        key=lambda row: float(row["host_gap"]) - float(row["vm_gap"]),
        reverse=True,
    )[:5]
    largest_widenings = sorted(
        gap_ranked,
        key=lambda row: float(row["host_gap"]) - float(row["vm_gap"]),
    )[:5]

    vm_geomean_all = geomean(vm_ratios_all)
    vm_geomean_overlap = geomean(overlap_vm_ratios)
    host_geomean_overlap = geomean(overlap_host_ratios)
    ratio_shift_geomean = geomean(ratio_shift_values)
    gap_change_geomean = geomean(gap_change_values)

    lines: list[str] = []
    lines.append("# VM 7.0-rc2 L/K Comparison")
    lines.append("")
    lines.append("## Run metadata")
    lines.append("")
    lines.append(f"- VM kernel results: `{vm_kernel_path}`")
    lines.append(f"- llvmbpf results: `{llvmbpf_path}`")
    lines.append(f"- Host authoritative results: `{host_path}`")
    lines.append(f"- VM kernel version: `{vm_kernel['host']['kernel_version']}`")
    lines.append(f"- llvmbpf source host/kernel: `{llvmbpf['host']['platform']}`")
    lines.append(f"- Host authoritative kernel: `{host['host']['kernel_version']}`")
    lines.append(
        "- Metric: median `exec_ns`; `L/K` means `llvmbpf_exec_ns / kernel_exec_ns`, so larger values mean the kernel is faster relative to llvmbpf."
    )
    lines.append("")
    lines.append("## Summary")
    lines.append("")
    lines.append(f"- Benchmarks with both VM kernel and llvmbpf data: `{len(rows)}`")
    lines.append(f"- Overlap with host authoritative L/K data: `{len(overlap_host_ratios)}`")
    lines.append(f"- VM 7.0-rc2 geomean L/K across all available benchmarks: `{format_ratio(vm_geomean_all)}`")
    lines.append(f"- VM 7.0-rc2 geomean L/K on host-overlap subset: `{format_ratio(vm_geomean_overlap)}`")
    lines.append(f"- Host authoritative geomean L/K on the same subset: `{format_ratio(host_geomean_overlap)}`")
    lines.append(
        f"- Geomean VM/Host L/K shift on overlap subset: `{format_ratio(ratio_shift_geomean)}`; values above `1.0x` mean 7.0-rc2 is faster relative to llvmbpf than the host baseline."
    )
    lines.append(
        f"- Geomean parity-gap change (`VM gap / host gap`): `{format_ratio(gap_change_geomean)}`"
    )
    lines.append(f"- Benchmarks closer to parity on 7.0-rc2: `{closer_count}`")
    lines.append(f"- Benchmarks farther from parity on 7.0-rc2: `{farther_count}`")
    lines.append(f"- Benchmarks unchanged vs host parity gap: `{unchanged_count}`")
    if vm_only:
        lines.append(f"- VM-only benchmarks without host authoritative L/K baseline: `{', '.join(sorted(vm_only))}`")
    lines.append("")
    lines.extend(render_top_list(largest_closures, "Largest parity-gap closures:"))
    lines.append("")
    lines.extend(render_top_list(largest_widenings, "Largest parity-gap widenings:"))
    lines.append("")
    lines.append("## Per-benchmark Ratios")
    lines.append("")
    lines.append("| Benchmark | llvmbpf exec median | VM kernel exec median | VM L/K | Host L/K | VM/Host L/K shift | Parity gap change | Interpretation |")
    lines.append("| --- | ---: | ---: | ---: | ---: | ---: | ---: | --- |")
    for row in rows:
        gap_change = row["gap_change"]
        if gap_change is None:
            gap_change_text = "n/a"
        else:
            gap_change_text = f"{gap_change:.3f}x"
        lines.append(
            "| "
            f"`{row['name']}` | "
            f"{format_ns(row['llvm_exec'])} | "
            f"{format_ns(row['kernel_exec'])} | "
            f"{format_ratio(row['vm_ratio'])} | "
            f"{format_ratio(row['host_ratio'])} | "
            f"{format_ratio(row['ratio_shift'])} | "
            f"{gap_change_text} | "
            f"{row['gap_description']} |"
        )

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text("\n".join(lines) + "\n")
    print(f"[done] wrote {output_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
