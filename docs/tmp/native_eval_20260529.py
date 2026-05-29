#!/usr/bin/env python3
"""Post-hoc native-kernel evaluation tables and figures for 2026-05-29.

This script intentionally lives under docs/tmp: it analyzes raw benchmark
artifacts after collection and does not participate in the benchmark framework.
"""

from __future__ import annotations

import json
import math
import pathlib
import re
import statistics
from dataclasses import dataclass
from typing import Any

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt


ROOT = pathlib.Path(__file__).resolve().parents[2]
FIG_DIR = ROOT / "docs" / "figures"
OUT_MD = ROOT / "docs" / "tmp" / "native_eval_20260529_summary.md"

CORPUS = {
    "bcc": {
        "app": "bcc/set",
        "stats_on": "corpus/results/x86_kvm_corpus_20260529_005704_033715",
        "stats_off": "corpus/results/x86_kvm_corpus_20260529_012805_826766",
        "no_ebpf": "corpus/results/x86_kvm_corpus_20260529_015843_382681",
    },
    "otel": {
        "app": "otelcol-ebpf-profiler/profiling",
        "stats_on": "corpus/results/x86_kvm_corpus_20260529_021623_817446",
        "stats_off": "corpus/results/x86_kvm_corpus_20260529_024714_858694",
        "no_ebpf": "corpus/results/x86_kvm_corpus_20260529_031718_784847",
    },
    "cilium": {
        "app": "cilium/agent",
        "stats_on": "corpus/results/x86_kvm_corpus_20260529_033517_489159",
        "stats_off": "corpus/results/x86_kvm_corpus_20260529_040554_604387",
        "no_ebpf": "corpus/results/x86_kvm_corpus_20260529_043720_016160",
    },
    "tetragon": {
        "app": "tetragon/observer",
        "stats_on": "corpus/results/x86_kvm_corpus_20260529_045551_393389",
        "stats_off": "corpus/results/x86_kvm_corpus_20260529_052633_700199",
        "no_ebpf": "corpus/results/x86_kvm_corpus_20260529_055644_747412",
    },
    "katran": {
        "app": "katran",
        "stats_on": "corpus/results/x86_kvm_corpus_20260529_061439_040837",
        "stats_off": "corpus/results/x86_kvm_corpus_20260529_064444_673720",
        "no_ebpf": "corpus/results/x86_kvm_corpus_20260529_071439_317979",
    },
    "tracee": {
        "app": "tracee/monitor",
        "stats_on": "corpus/results/x86_kvm_corpus_20260529_073309_993570",
        "stats_off": "corpus/results/x86_kvm_corpus_20260529_080408_588450",
        "no_ebpf": "corpus/results/x86_kvm_corpus_20260529_083605_206833",
    },
}

MICRO = {
    "Pure bytecode": "micro/results/x86_kvm_micro_20260529_003919_048557",
    "With helpers/maps": "micro/results/x86_kvm_micro_20260529_004658_667642",
}

STRESS_RE = re.compile(
    r"stress-ng: metrc: \[\d+\]\s+([A-Za-z0-9_-]+)\s+(\d+)\s+([0-9.]+).*?\s+([0-9.]+)\s+([0-9.]+)\s*$"
)
OPS_RE = re.compile(r"^(python3|ruby|nodejs|perl|php) int_loop ops=(\d+) elapsed_s=([0-9.]+)")
PPS_RE = re.compile(r"\n\s*(\d+)pps\s+([0-9]+)Mb/sec .* errors: (\d+)")


@dataclass
class WorkloadRow:
    key: str
    app: str
    ebpf: float
    native: float
    no_ebpf: float
    sample_ratios: list[float]

    @property
    def native_over_ebpf(self) -> float:
        return self.native / self.ebpf

    @property
    def ebpf_over_no(self) -> float:
        return self.ebpf / self.no_ebpf

    @property
    def native_over_no(self) -> float:
        return self.native / self.no_ebpf

    @property
    def ratio_mean(self) -> float:
        return statistics.mean(self.sample_ratios)

    @property
    def ratio_cv(self) -> float:
        if len(self.sample_ratios) < 2:
            return 0.0
        return statistics.stdev(self.sample_ratios) / self.ratio_mean


@dataclass
class BpfRow:
    key: str
    ebpf_ns: float
    native_ns: float
    retained_ebpf: int
    retained_native: int
    records_ebpf: int
    records_native: int

    @property
    def speedup(self) -> float:
        return self.ebpf_ns / self.native_ns


def load_app(run_dir: str) -> tuple[dict[str, Any], pathlib.Path]:
    files = sorted((ROOT / run_dir / "details" / "apps").glob("*.json"))
    if len(files) != 1:
        raise RuntimeError(f"expected one app json under {run_dir}, found {files}")
    return json.loads(files[0].read_text()), files[0]


def median(values: list[float]) -> float:
    return statistics.median(values)


def geomean(values: list[float]) -> float:
    return math.exp(sum(math.log(v) for v in values) / len(values))


def fmt_ratio(value: float) -> str:
    return "n/a" if math.isnan(value) else f"{value:.3f}x"


def text_metrics(text: str) -> tuple[float, dict[str, float], int]:
    total = 0.0
    by_name: dict[str, float] = {}
    errors = 0
    for line in text.splitlines():
        stress = STRESS_RE.search(line)
        if stress:
            value = float(stress.group(4))
            total += value
            by_name[stress.group(1)] = by_name.get(stress.group(1), 0.0) + value
        ops = OPS_RE.search(line)
        if ops:
            value = int(ops.group(2)) / float(ops.group(3))
            total += value
            by_name[ops.group(1)] = by_name.get(ops.group(1), 0.0) + value
    for pps in PPS_RE.finditer("\n" + text):
        value = float(pps.group(1))
        total += value
        by_name["pps"] = by_name.get("pps", 0.0) + value
        errors += int(pps.group(3))
    return total, by_name, errors


def workload_metric(workload: dict[str, Any]) -> tuple[float, dict[str, float], int]:
    total = 0.0
    by_name: dict[str, float] = {}
    errors = 0
    for component in workload.get("components") or []:
        value, sub_by_name, sub_errors = workload_metric(component)
        total += value
        errors += sub_errors
        for name, sub_value in sub_by_name.items():
            by_name[name] = by_name.get(name, 0.0) + sub_value
    text = (workload.get("stdout") or "") + "\n" + (workload.get("stderr") or "")
    value, sub_by_name, sub_errors = text_metrics(text)
    total += value
    errors += sub_errors
    for name, sub_value in sub_by_name.items():
        by_name[name] = by_name.get(name, 0.0) + sub_value
    return total, by_name, errors


def phase_samples(app: dict[str, Any], phase: str) -> list[tuple[float, dict[str, float], int]]:
    phase_obj = app.get(phase)
    if not isinstance(phase_obj, dict):
        return []
    return [workload_metric(workload) for workload in phase_obj.get("workloads", [])]


def bpf_aggregate(app: dict[str, Any], phase: str) -> tuple[float, int, int]:
    phase_obj = app.get(phase)
    if not isinstance(phase_obj, dict):
        return math.nan, 0, 0
    records = list((phase_obj.get("bpf") or {}).values())
    retained = [record for record in records if record.get("run_cnt_delta", 0) >= 100]
    runs = sum(record.get("run_cnt_delta", 0) for record in retained)
    elapsed = sum(record.get("run_time_ns_delta", 0) for record in retained)
    return (elapsed / runs if runs else math.nan), len(retained), len(records)


def corpus_rows() -> tuple[list[WorkloadRow], list[BpfRow], dict[str, dict[str, dict[str, float]]]]:
    workload_rows: list[WorkloadRow] = []
    bpf_rows: list[BpfRow] = []
    stressor_rows: dict[str, dict[str, dict[str, float]]] = {}
    for key, info in CORPUS.items():
        stats_off, _ = load_app(info["stats_off"])
        no_ebpf, _ = load_app(info["no_ebpf"])
        stats_on, _ = load_app(info["stats_on"])

        ebpf_samples = phase_samples(stats_off, "baseline")
        native_samples = phase_samples(stats_off, "post_rejit")
        no_samples = phase_samples(no_ebpf, "workload_only") or phase_samples(no_ebpf, "baseline")
        ebpf_values = [sample[0] for sample in ebpf_samples]
        native_values = [sample[0] for sample in native_samples]
        no_values = [sample[0] for sample in no_samples]
        ratios = [
            native_values[index] / ebpf_values[index]
            for index in range(min(len(ebpf_values), len(native_values)))
        ]
        workload_rows.append(
            WorkloadRow(
                key=key,
                app=info["app"],
                ebpf=median(ebpf_values),
                native=median(native_values),
                no_ebpf=median(no_values),
                sample_ratios=ratios,
            )
        )

        ebpf_ns, retained_ebpf, records_ebpf = bpf_aggregate(stats_on, "baseline")
        native_ns, retained_native, records_native = bpf_aggregate(stats_on, "post_rejit")
        bpf_rows.append(
            BpfRow(
                key=key,
                ebpf_ns=ebpf_ns,
                native_ns=native_ns,
                retained_ebpf=retained_ebpf,
                retained_native=retained_native,
                records_ebpf=records_ebpf,
                records_native=records_native,
            )
        )

        stressor_rows[key] = {}
        for phase, samples in [
            ("ebpf", ebpf_samples),
            ("native", native_samples),
            ("no_ebpf", no_samples),
        ]:
            accum: dict[str, list[float]] = {}
            for _, by_name, _ in samples:
                for name, value in by_name.items():
                    accum.setdefault(name, []).append(value)
            stressor_rows[key][phase] = {name: median(values) for name, values in accum.items()}
    return workload_rows, bpf_rows, stressor_rows


def micro_summary() -> dict[str, dict[str, float]]:
    summary: dict[str, dict[str, float]] = {}
    for suite, run_dir in MICRO.items():
        result = json.loads((ROOT / run_dir / "details" / "result.json").read_text())
        ratios_by_runtime: dict[str, list[float]] = {}
        size_by_runtime: dict[str, list[float]] = {}
        bad = 0
        for bench in result["benchmarks"]:
            runtime_exec: dict[str, float] = {}
            runtime_size: dict[str, float] = {}
            for run in bench["runs"]:
                runtime = run["runtime"]
                samples = run["samples"]
                runtime_exec[runtime] = median([float(sample["exec_ns"]) for sample in samples])
                sizes = []
                for sample in samples:
                    code_size = sample.get("code_size") or {}
                    if "native_code_bytes" in code_size:
                        sizes.append(float(code_size["native_code_bytes"]))
                    elif "jited_prog_len" in sample:
                        sizes.append(float(sample["jited_prog_len"]))
                if sizes:
                    runtime_size[runtime] = median(sizes)
                for sample in samples:
                    if sample.get("result") != bench.get("expected_result") or sample.get(
                        "retval"
                    ) != bench.get("expected_retval"):
                        bad += 1
            kernel_exec = runtime_exec["kernel"]
            kernel_size = runtime_size.get("kernel")
            for runtime, value in runtime_exec.items():
                ratios_by_runtime.setdefault(runtime, []).append(value / kernel_exec)
            if kernel_size:
                for runtime, value in runtime_size.items():
                    size_by_runtime.setdefault(runtime, []).append(value / kernel_size)
        suite_summary: dict[str, float] = {"benchmarks": float(len(result["benchmarks"])), "bad": float(bad)}
        for runtime, ratios in ratios_by_runtime.items():
            suite_summary[f"runtime_{runtime}"] = geomean(ratios)
        for runtime, ratios in size_by_runtime.items():
            suite_summary[f"size_{runtime}"] = geomean(ratios)
        summary[suite] = suite_summary
    return summary


def plot_corpus(workload_rows: list[WorkloadRow], bpf_rows: list[BpfRow]) -> pathlib.Path:
    FIG_DIR.mkdir(parents=True, exist_ok=True)
    out = FIG_DIR / "eval-native-corpus-20260529.png"
    labels = [row.key for row in workload_rows]
    x = list(range(len(labels)))
    width = 0.36
    fig, axes = plt.subplots(1, 2, figsize=(13.5, 4.7), dpi=180)

    ax = axes[0]
    ax.bar([i - width / 2 for i in x], [row.ebpf_over_no for row in workload_rows], width, label="Kernel eBPF")
    ax.bar([i + width / 2 for i in x], [row.native_over_no for row in workload_rows], width, label="Kernel native")
    ax.axhline(1.0, color="0.25", linestyle="--", linewidth=1.0)
    ax.set_title("Workload throughput")
    ax.set_ylabel("Throughput / no-eBPF")
    ax.set_xticks(x)
    ax.set_xticklabels(labels, rotation=28, ha="right")
    ax.legend(frameon=False, loc="upper left")
    ax.grid(axis="y", color="0.9")

    ax = axes[1]
    bpf_by_key = {row.key: row for row in bpf_rows}
    ax.bar([i - width / 2 for i in x], [bpf_by_key[key].ebpf_ns for key in labels], width, label="Kernel eBPF")
    ax.bar([i + width / 2 for i in x], [bpf_by_key[key].native_ns for key in labels], width, label="Kernel native")
    ax.set_title("BPF per-run cost")
    ax.set_ylabel("Aggregate ns/run")
    ax.set_xticks(x)
    ax.set_xticklabels(labels, rotation=28, ha="right")
    ax.set_yscale("log")
    ax.legend(frameon=False, loc="upper right")
    ax.grid(axis="y", color="0.9", which="both")

    fig.suptitle("Native kernel execution on x86 KVM corpus apps", fontsize=16)
    fig.tight_layout(rect=(0, 0.03, 1, 0.94))
    fig.savefig(out, bbox_inches="tight")
    plt.close(fig)
    return out


def plot_micro(summary: dict[str, dict[str, float]]) -> pathlib.Path:
    FIG_DIR.mkdir(parents=True, exist_ok=True)
    out = FIG_DIR / "eval-native-micro-20260529.png"
    fig, axes = plt.subplots(1, 2, figsize=(10.5, 4.2), dpi=180)
    colors = {"native_kernel": "#4e79a7", "llvmbpf": "#b07aa1", "native": "#59a14f"}
    labels = {"native_kernel": "Kernel native", "llvmbpf": "Userspace eBPF", "native": "Userspace native"}
    for ax, suite in zip(axes, ["Pure bytecode", "With helpers/maps"]):
        runtimes = [runtime for runtime in ["native_kernel", "llvmbpf", "native"] if f"runtime_{runtime}" in summary[suite]]
        values = [summary[suite][f"runtime_{runtime}"] for runtime in runtimes]
        ax.bar(range(len(runtimes)), values, color=[colors[runtime] for runtime in runtimes], width=0.58)
        ax.axhline(1.0, color="0.25", linestyle="--", linewidth=1.0)
        ax.set_title(suite)
        ax.set_ylabel("Runtime / kernel eBPF")
        ax.set_xticks(range(len(runtimes)))
        ax.set_xticklabels([labels[runtime] for runtime in runtimes], rotation=20, ha="right")
        ax.set_ylim(0, max(1.08, max(values) * 1.18))
        for idx, value in enumerate(values):
            ax.text(idx, value + 0.02, f"{value:.2f}x", ha="center", va="bottom", fontsize=10)
        ax.grid(axis="y", color="0.9")
    fig.suptitle("Microbenchmark runtime normalized to kernel eBPF", fontsize=16)
    fig.tight_layout(rect=(0, 0.03, 1, 0.93))
    fig.savefig(out, bbox_inches="tight")
    plt.close(fig)
    return out


def write_summary(
    workload_rows: list[WorkloadRow],
    bpf_rows: list[BpfRow],
    stressor_rows: dict[str, dict[str, dict[str, float]]],
    micro: dict[str, dict[str, float]],
    corpus_fig: pathlib.Path,
    micro_fig: pathlib.Path,
) -> None:
    bpf_by_key = {row.key: row for row in bpf_rows}
    lines: list[str] = []
    lines.append("# Native Kernel Evaluation Summary, 2026-05-29")
    lines.append("")
    lines.append("Generated by `docs/tmp/native_eval_20260529.py` from raw artifacts.")
    lines.append("")
    lines.append(f"- Corpus figure: `{corpus_fig.relative_to(ROOT)}`")
    lines.append(f"- Micro figure: `{micro_fig.relative_to(ROOT)}`")
    lines.append(f"- Corpus native/eBPF workload geomean: `{geomean([row.native_over_ebpf for row in workload_rows]):.3f}x`")
    lines.append("")
    lines.append("## Corpus Workload")
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
    lines.append("## Corpus BPF Counters")
    lines.append("")
    lines.append("| App | eBPF ns/run | native ns/run | speedup | retained eBPF/native | records eBPF/native |")
    lines.append("| --- | ---: | ---: | ---: | ---: | ---: |")
    for row in bpf_rows:
        lines.append(
            f"| `{row.key}` | {row.ebpf_ns:.1f} | {row.native_ns:.1f} | {row.speedup:.2f}x | "
            f"{row.retained_ebpf}/{row.retained_native} | {row.records_ebpf}/{row.records_native} |"
        )
    lines.append("")
    lines.append("## Micro")
    lines.append("")
    lines.append("| Suite | benchmarks | kernel native runtime | userspace eBPF runtime | userspace native runtime | kernel native code size |")
    lines.append("| --- | ---: | ---: | ---: | ---: | ---: |")
    for suite, values in micro.items():
        lines.append(
            f"| {suite} | {int(values['benchmarks'])} | {fmt_ratio(values.get('runtime_native_kernel', math.nan))} | "
            f"{fmt_ratio(values.get('runtime_llvmbpf', math.nan))} | {fmt_ratio(values.get('runtime_native', math.nan))} | "
            f"{fmt_ratio(values.get('size_native_kernel', math.nan))} |"
        )
    lines.append("")
    lines.append("## Per-Stressor Medians")
    lines.append("")
    for key in CORPUS:
        lines.append(f"### {key}")
        for phase in ["ebpf", "native", "no_ebpf"]:
            values = stressor_rows[key][phase]
            rendered = ", ".join(f"{name}={value:.2f}" for name, value in sorted(values.items()))
            lines.append(f"- {phase}: {rendered}")
        lines.append("")
    OUT_MD.write_text("\n".join(lines) + "\n")


def main() -> None:
    workload_rows, bpf_rows, stressor_rows = corpus_rows()
    micro = micro_summary()
    corpus_fig = plot_corpus(workload_rows, bpf_rows)
    micro_fig = plot_micro(micro)
    write_summary(workload_rows, bpf_rows, stressor_rows, micro, corpus_fig, micro_fig)
    print(f"wrote {OUT_MD.relative_to(ROOT)}")
    print(f"wrote {corpus_fig.relative_to(ROOT)}")
    print(f"wrote {micro_fig.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
