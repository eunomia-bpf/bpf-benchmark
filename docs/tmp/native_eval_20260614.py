#!/usr/bin/env python3
"""Post-hoc native-kernel corpus evaluation tables and figures for 2026-06-14.

This script intentionally lives under docs/tmp: it analyzes raw benchmark
artifacts after collection and does not participate in the benchmark framework.
"""

from __future__ import annotations

import json
import math
import pathlib
import statistics
from typing import Any

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt

import native_eval_20260529 as base


ROOT = pathlib.Path(__file__).resolve().parents[2]
FIG_DIR = ROOT / "docs" / "figures"
OUT_MD = ROOT / "docs" / "tmp" / "native_eval_20260614_summary.md"

APP_ORDER = ["bcc", "otel", "cilium", "tetragon", "katran", "tracee"]

CORPUS_BY_PLATFORM = {
    "x86 KVM": base.CORPUS,
    "arm64 AWS": {
        "bcc": {
            "app": "bcc/set",
            "stats_on": "corpus/results/aws_arm64_corpus_20260614_023819_952378",
            "stats_off": "corpus/results/aws_arm64_corpus_20260614_031732_059541",
            "no_ebpf": "corpus/results/aws_arm64_corpus_20260614_035318_089504",
        },
        "otel": {
            "app": "otelcol-ebpf-profiler/profiling",
            "stats_on": "corpus/results/aws_arm64_corpus_20260614_041820_542790",
            "stats_off": "corpus/results/aws_arm64_corpus_20260614_045513_431087",
            "no_ebpf": "corpus/results/aws_arm64_corpus_20260614_053111_825457",
        },
        "cilium": {
            "app": "cilium/agent",
            "stats_on": "corpus/results/aws_arm64_corpus_20260614_055518_602472",
            "stats_off": "corpus/results/aws_arm64_corpus_20260614_063218_115994",
            "no_ebpf": "corpus/results/aws_arm64_corpus_20260614_070813_221543",
        },
        "tetragon": {
            "app": "tetragon/observer",
            "stats_on": "corpus/results/aws_arm64_corpus_20260614_073219_040724",
            "stats_off": "corpus/results/aws_arm64_corpus_20260614_080917_564524",
            "no_ebpf": "corpus/results/aws_arm64_corpus_20260614_084524_401395",
        },
        "katran": {
            "app": "katran",
            "stats_on": "corpus/results/aws_arm64_corpus_20260614_090824_742980",
            "stats_off": "corpus/results/aws_arm64_corpus_20260614_094513_587379",
            "no_ebpf": "corpus/results/aws_arm64_corpus_20260614_183519_766267",
        },
        "tracee": {
            "app": "tracee/monitor",
            "stats_on": "corpus/results/aws_arm64_corpus_20260614_185921_546771",
            "stats_off": "corpus/results/aws_arm64_corpus_20260614_195421_306838",
            "no_ebpf": "corpus/results/aws_arm64_corpus_20260614_203128_076343",
        },
    },
}

NON_AUTHORITATIVE = {
    "arm64 AWS tracee stats-off failed attempt": (
        "corpus/results/aws_arm64_corpus_20260614_193625_357345"
    ),
}


def geomean(values: list[float]) -> float:
    return math.exp(sum(math.log(value) for value in values) / len(values))


def fmt(value: float, suffix: str = "") -> str:
    return "n/a" if math.isnan(value) else f"{value:.3f}{suffix}"


def fmt1(value: float) -> str:
    return "n/a" if math.isnan(value) else f"{value:.1f}"


def load_metadata(run_dir: str) -> dict[str, Any]:
    path = ROOT / run_dir / "metadata.json"
    return json.loads(path.read_text())


def corpus_rows(
    corpus: dict[str, dict[str, str]],
) -> tuple[list[base.WorkloadRow], list[base.BpfRow]]:
    workload_rows: list[base.WorkloadRow] = []
    bpf_rows: list[base.BpfRow] = []
    for key in APP_ORDER:
        info = corpus[key]
        stats_off, _ = base.load_app(info["stats_off"])
        no_ebpf, _ = base.load_app(info["no_ebpf"])
        stats_on, _ = base.load_app(info["stats_on"])

        ebpf_samples = base.phase_samples(stats_off, "baseline")
        native_samples = base.phase_samples(stats_off, "post_rejit")
        no_samples = base.phase_samples(no_ebpf, "workload_only") or base.phase_samples(no_ebpf, "baseline")
        ebpf_values = [sample[0] for sample in ebpf_samples]
        native_values = [sample[0] for sample in native_samples]
        no_values = [sample[0] for sample in no_samples]
        ratios = [
            native_values[index] / ebpf_values[index]
            for index in range(min(len(ebpf_values), len(native_values)))
        ]
        workload_rows.append(
            base.WorkloadRow(
                key=key,
                app=info["app"],
                ebpf=statistics.median(ebpf_values),
                native=statistics.median(native_values),
                no_ebpf=statistics.median(no_values),
                sample_ratios=ratios,
            )
        )

        ebpf_ns, retained_ebpf, records_ebpf = base.bpf_aggregate(stats_on, "baseline")
        native_ns, retained_native, records_native = base.bpf_aggregate(stats_on, "post_rejit")
        bpf_rows.append(
            base.BpfRow(
                key=key,
                ebpf_ns=ebpf_ns,
                native_ns=native_ns,
                retained_ebpf=retained_ebpf,
                retained_native=retained_native,
                records_ebpf=records_ebpf,
                records_native=records_native,
            )
        )
    return workload_rows, bpf_rows


def platform_rows() -> dict[str, tuple[list[base.WorkloadRow], list[base.BpfRow]]]:
    return {platform: corpus_rows(corpus) for platform, corpus in CORPUS_BY_PLATFORM.items()}


def plot_corpus(rows_by_platform: dict[str, tuple[list[base.WorkloadRow], list[base.BpfRow]]]) -> pathlib.Path:
    FIG_DIR.mkdir(parents=True, exist_ok=True)
    out = FIG_DIR / "eval-native-corpus-20260614.png"
    fig, axes = plt.subplots(len(rows_by_platform), 2, figsize=(14.0, 8.2), dpi=180)
    if len(rows_by_platform) == 1:
        axes = [axes]  # type: ignore[assignment]
    width = 0.36
    for row_index, (platform, (workload_rows, bpf_rows)) in enumerate(rows_by_platform.items()):
        labels = [row.key for row in workload_rows]
        x = list(range(len(labels)))

        ax = axes[row_index][0]
        ax.bar([i - width / 2 for i in x], [row.ebpf_over_no for row in workload_rows], width, label="Kernel eBPF")
        ax.bar([i + width / 2 for i in x], [row.native_over_no for row in workload_rows], width, label="Kernel native")
        ax.axhline(1.0, color="0.25", linestyle="--", linewidth=1.0)
        ax.set_title(f"{platform}: workload throughput")
        ax.set_ylabel("Throughput / no-eBPF")
        ax.set_xticks(x)
        ax.set_xticklabels(labels, rotation=28, ha="right")
        ax.grid(axis="y", color="0.9")
        if row_index == 0:
            ax.legend(frameon=False, loc="upper left")

        ax = axes[row_index][1]
        bpf_by_key = {row.key: row for row in bpf_rows}
        ax.bar([i - width / 2 for i in x], [bpf_by_key[key].ebpf_ns for key in labels], width, label="Kernel eBPF")
        ax.bar([i + width / 2 for i in x], [bpf_by_key[key].native_ns for key in labels], width, label="Kernel native")
        ax.set_title(f"{platform}: BPF per-run cost")
        ax.set_ylabel("Aggregate ns/run")
        ax.set_xticks(x)
        ax.set_xticklabels(labels, rotation=28, ha="right")
        ax.set_yscale("log")
        ax.grid(axis="y", color="0.9", which="both")
        if row_index == 0:
            ax.legend(frameon=False, loc="upper right")
    fig.suptitle("Native kernel execution corpus results", fontsize=16)
    fig.tight_layout(rect=(0, 0.02, 1, 0.95))
    fig.savefig(out, bbox_inches="tight")
    plt.close(fig)
    return out


def write_platform_tables(lines: list[str], platform: str, rows: tuple[list[base.WorkloadRow], list[base.BpfRow]]) -> None:
    workload_rows, bpf_rows = rows
    bpf_by_key = {row.key: row for row in bpf_rows}
    lines.append(f"## {platform} Corpus Workload")
    lines.append("")
    lines.append(f"- Native/eBPF workload geomean: `{geomean([row.native_over_ebpf for row in workload_rows]):.3f}x`")
    lines.append("")
    lines.append("| App | eBPF throughput | Native throughput | no-eBPF throughput | native/eBPF | eBPF/no-eBPF | native/no-eBPF | sample ratios |")
    lines.append("| --- | ---: | ---: | ---: | ---: | ---: | ---: | --- |")
    for row in workload_rows:
        samples = ", ".join(f"{value:.3f}x" for value in row.sample_ratios)
        lines.append(
            f"| `{row.key}` | {row.ebpf:.2f} | {row.native:.2f} | {row.no_ebpf:.2f} | "
            f"{row.native_over_ebpf:.3f}x | {row.ebpf_over_no:.3f}x | {row.native_over_no:.3f}x | {samples} |"
        )
    lines.append("")
    lines.append(f"## {platform} Corpus BPF Counters")
    lines.append("")
    lines.append("| App | eBPF ns/run | native ns/run | native/eBPF cost | speedup | retained eBPF/native | records eBPF/native |")
    lines.append("| --- | ---: | ---: | ---: | ---: | ---: | ---: |")
    for key in APP_ORDER:
        row = bpf_by_key[key]
        cost = row.native_ns / row.ebpf_ns if row.ebpf_ns and not math.isnan(row.ebpf_ns) else math.nan
        lines.append(
            f"| `{key}` | {fmt1(row.ebpf_ns)} | {fmt1(row.native_ns)} | {fmt(cost, 'x')} | "
            f"{fmt(row.speedup, 'x')} | {row.retained_ebpf}/{row.retained_native} | "
            f"{row.records_ebpf}/{row.records_native} |"
        )
    lines.append("")


def write_micro_table(lines: list[str], micro: dict[str, dict[str, float]]) -> None:
    lines.append("## Micro")
    lines.append("")
    lines.append("Micro artifacts are the 2026-05-29 x86 KVM runs; this 2026-06-14 refresh adds arm64 corpus artifacts only.")
    lines.append("")
    lines.append("| Suite | benchmarks | kernel native runtime | userspace eBPF runtime | userspace native runtime | kernel native code size |")
    lines.append("| --- | ---: | ---: | ---: | ---: | ---: |")
    for suite, values in micro.items():
        lines.append(
            f"| {suite} | {int(values['benchmarks'])} | {base.fmt_ratio(values.get('runtime_native_kernel', math.nan))} | "
            f"{base.fmt_ratio(values.get('runtime_llvmbpf', math.nan))} | {base.fmt_ratio(values.get('runtime_native', math.nan))} | "
            f"{base.fmt_ratio(values.get('size_native_kernel', math.nan))} |"
        )
    lines.append("")


def write_artifacts(lines: list[str]) -> None:
    lines.append("## Artifact Manifest")
    lines.append("")
    lines.append("| Platform | App | Mode | Status | Generated at (UTC) | Artifact |")
    lines.append("| --- | --- | --- | --- | --- | --- |")
    for platform, corpus in CORPUS_BY_PLATFORM.items():
        for key in APP_ORDER:
            info = corpus[key]
            for mode in ["stats_on", "stats_off", "no_ebpf"]:
                run_dir = info[mode]
                metadata = load_metadata(run_dir)
                generated = str(metadata.get("completed_at") or metadata.get("started_at") or "")
                lines.append(
                    f"| {platform} | `{info['app']}` | {mode} | {metadata.get('status', '')} | "
                    f"{generated} | `{run_dir}/metadata.json` |"
                )
    lines.append("")
    lines.append("Non-authoritative failed/interrupted attempts preserved for debugging:")
    lines.append("")
    for name, run_dir in NON_AUTHORITATIVE.items():
        metadata = load_metadata(run_dir)
        lines.append(f"- {name}: `{run_dir}/metadata.json` (`{metadata.get('status', '')}`)")
    lines.append("")


def write_summary(
    rows_by_platform: dict[str, tuple[list[base.WorkloadRow], list[base.BpfRow]]],
    micro: dict[str, dict[str, float]],
    corpus_fig: pathlib.Path,
) -> None:
    lines: list[str] = []
    lines.append("# Native Kernel Evaluation Summary, 2026-06-14")
    lines.append("")
    lines.append("Generated by `docs/tmp/native_eval_20260614.py` from raw artifacts.")
    lines.append("")
    lines.append(f"- Corpus figure: `{corpus_fig.relative_to(ROOT)}`")
    lines.append("- Micro figure: `docs/figures/eval-native-micro-20260529.png`")
    for platform, (workload_rows, _) in rows_by_platform.items():
        lines.append(
            f"- {platform} native/eBPF workload geomean: "
            f"`{geomean([row.native_over_ebpf for row in workload_rows]):.3f}x`"
        )
    lines.append("")
    for platform, rows in rows_by_platform.items():
        write_platform_tables(lines, platform, rows)
    write_micro_table(lines, micro)
    write_artifacts(lines)
    OUT_MD.write_text("\n".join(lines) + "\n")


def main() -> None:
    rows_by_platform = platform_rows()
    micro = base.micro_summary()
    corpus_fig = plot_corpus(rows_by_platform)
    write_summary(rows_by_platform, micro, corpus_fig)
    print(f"wrote {OUT_MD.relative_to(ROOT)}")
    print(f"wrote {corpus_fig.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
