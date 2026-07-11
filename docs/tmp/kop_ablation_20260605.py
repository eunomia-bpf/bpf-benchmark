#!/usr/bin/env python3
"""Post-hoc kop ablation plots for 2026-06-05.

This script analyzes already-collected corpus artifacts only. It intentionally
lives under docs/tmp and is not part of the benchmark framework.
"""

from __future__ import annotations

import json
import math
import pathlib
import sys
from collections import Counter
from dataclasses import dataclass
from typing import Any

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt


ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "docs" / "tmp"))
import kop_eval_20260604 as kop_eval

RESULTS = ROOT / "corpus" / "results"
FIG_OUT = ROOT / "docs" / "figures" / "eval-kop-ablation-20260605.png"
SUMMARY_OUT = ROOT / "docs" / "tmp" / "kop_ablation_20260605_summary.md"

APP_ORDER = [
    "bcc/set",
    "cilium/agent",
    "katran",
    "otelcol-ebpf-profiler/profiling",
    "tetragon/observer",
    "tracee/monitor",
]
PLOT_APPS = ["bcc/set", "cilium/agent", "katran", "tracee/monitor"]
APP_LABEL = {
    "bcc/set": "BCC",
    "cilium/agent": "Cilium",
    "katran": "Katran",
    "otelcol-ebpf-profiler/profiling": "OTel",
    "tetragon/observer": "Tetragon",
    "tracee/monitor": "Tracee",
}

X86_VARIANTS = [
    ("x86_full", "Full", ("kop_all_prefetch",), "x86_kvm_corpus"),
    ("x86_no_prefetch", "No prefetch", ("kop_all_no_prefetch",), "x86_kvm_corpus"),
    (
        "x86_no_bulk_prefetch",
        "No bulk",
        ("kop_all_no_bulk_prefetch",),
        "x86_kvm_corpus",
    ),
    (
        "x86_no_bulk_no_prefetch",
        "No bulk/pref",
        ("kop_all_no_bulk_no_prefetch",),
        "x86_kvm_corpus",
    ),
]

ARM64_VARIANTS = [
    ("arm64_conservative", "Conservative", ("kop",), "aws_arm64_corpus"),
    (
        "arm64_all",
        "All selectors",
        ("rotate", "extract", "endian_fusion", "bulk_memory", "prefetch", "cond_select", "ccmp"),
        "aws_arm64_corpus",
    ),
    ("arm64_no_prefetch", "No prefetch", ("kop_all_no_prefetch",), "aws_arm64_corpus"),
    (
        "arm64_no_bulk_prefetch",
        "No bulk",
        ("kop_all_no_bulk_prefetch",),
        "aws_arm64_corpus",
    ),
    (
        "arm64_no_bulk_no_prefetch",
        "No bulk/pref",
        ("kop_all_no_bulk_no_prefetch",),
        "aws_arm64_corpus",
    ),
]

FAMILY_ORDER = [
    "lea",
    "bulk_memory",
    "prefetch",
    "endian_fusion",
    "cond_select",
    "extract",
    "rotate",
    "ldp",
    "stp",
    "ccmp",
]
COLORS = {
    "Full": "#2f8fbd",
    "No prefetch": "#42aa61",
    "No bulk": "#d08a32",
    "No bulk/pref": "#8e5ab0",
    "Conservative": "#2f8fbd",
    "All selectors": "#8e5ab0",
}
FAMILY_COLORS = {
    "lea": "#4c78a8",
    "bulk_memory": "#f58518",
    "prefetch": "#e45756",
    "endian_fusion": "#72b7b2",
    "cond_select": "#54a24b",
    "extract": "#b279a2",
    "rotate": "#ff9da6",
    "ldp": "#9d755d",
    "stp": "#bab0ac",
    "ccmp": "#17becf",
    "other": "#777777",
}


@dataclass
class AppMetric:
    app: str
    status: str
    workload: float
    bpf: float
    retained: int
    wins: int
    losses: int
    ties: int
    sites: int
    error: str


@dataclass
class RunMetric:
    key: str
    label: str
    artifact: pathlib.Path
    apps: list[AppMetric]
    families: Counter[str]
    names: Counter[str]
    total_sites: int


def geomean(values: list[float]) -> float:
    return math.exp(sum(math.log(value) for value in values) / len(values)) if values else math.nan


def fmt_ratio(value: float) -> str:
    return "n/a" if math.isnan(value) else f"{value:.3f}x"


def short_error(text: str, limit: int = 96) -> str:
    compact = " ".join((text or "").split())
    return compact if len(compact) <= limit else compact[: limit - 3] + "..."


def pass_tuple(artifact: pathlib.Path) -> tuple[str, ...]:
    metadata = json.loads((artifact / "metadata.json").read_text())
    return tuple((metadata.get("config") or {}).get("enabled_passes") or ())


def latest_artifacts() -> dict[tuple[str, tuple[str, ...]], pathlib.Path]:
    found: dict[tuple[str, tuple[str, ...]], pathlib.Path] = {}
    for artifact in sorted(RESULTS.glob("*_corpus_*")):
        if not (artifact / "metadata.json").exists():
            continue
        try:
            passes = pass_tuple(artifact)
        except (json.JSONDecodeError, OSError):
            continue
        prefix = "aws_arm64_corpus" if artifact.name.startswith("aws_arm64_corpus") else ""
        if artifact.name.startswith("x86_kvm_corpus"):
            prefix = "x86_kvm_corpus"
        if not prefix:
            continue
        found[(prefix, passes)] = artifact
    return found


def app_key(app: str) -> str:
    return app.replace("/", "__")


def loadtime_counters(artifact: pathlib.Path) -> tuple[Counter[str], Counter[str], Counter[str]]:
    by_app: Counter[str] = Counter()
    by_name: Counter[str] = Counter()
    by_family: Counter[str] = Counter()
    report_dir = artifact / "details" / "loadtime-reports"
    for path in sorted(report_dir.glob("*.jsonl")):
        for line in path.read_text().splitlines():
            if not line.strip():
                continue
            report = (json.loads(line).get("report") or {})
            by_app[path.stem] += int(report.get("sites_applied") or 0)
            by_name.update(report.get("kop_calls_by_name") or {})
            by_family.update(report.get("kop_calls_by_family") or {})
    return by_app, by_name, by_family


def workload_ratio(app: dict[str, Any]) -> float:
    baseline = [sample[0] for sample in kop_eval.phase_samples(app, "baseline")]
    post = [sample[0] for sample in kop_eval.phase_samples(app, "post_rejit")]
    if not baseline or not post or not sum(baseline):
        return math.nan
    return (sum(post) / len(post)) / (sum(baseline) / len(baseline))


def bpf_ratio(app: dict[str, Any]) -> tuple[float, int, int, int, int]:
    if app.get("status") != "ok":
        return math.nan, 0, 0, 0, 0
    pairs = kop_eval.paired_bpf_rows(app)
    ratios = [pair.ratio for pair in pairs]
    wins = sum(1 for ratio in ratios if ratio < 1.0)
    losses = sum(1 for ratio in ratios if ratio > 1.0)
    ties = sum(1 for ratio in ratios if ratio == 1.0)
    return geomean(ratios), len(ratios), wins, losses, ties


def read_run(key: str, label: str, artifact: pathlib.Path) -> RunMetric:
    by_app, by_name, by_family = loadtime_counters(artifact)
    apps: list[AppMetric] = []
    app_dir = artifact / "details" / "apps"
    for app_path in sorted(app_dir.glob("*.json")):
        app = json.loads(app_path.read_text())
        app_name = str(app.get("app") or app_path.stem)
        bpf, retained, wins, losses, ties = bpf_ratio(app)
        apps.append(
            AppMetric(
                app=app_name,
                status=str(app.get("status") or ""),
                workload=workload_ratio(app),
                bpf=bpf,
                retained=retained,
                wins=wins,
                losses=losses,
                ties=ties,
                sites=by_app[app_key(app_name)],
                error=short_error(str(app.get("error") or "")),
            )
        )
    order = {name: idx for idx, name in enumerate(APP_ORDER)}
    apps.sort(key=lambda metric: order.get(metric.app, 999))
    return RunMetric(
        key=key,
        label=label,
        artifact=artifact,
        apps=apps,
        families=by_family,
        names=by_name,
        total_sites=sum(by_family.values()),
    )


def collect(variants: list[tuple[str, str, tuple[str, ...], str]]) -> list[RunMetric]:
    latest = latest_artifacts()
    runs: list[RunMetric] = []
    for key, label, passes, prefix in variants:
        artifact = latest.get((prefix, passes))
        if artifact:
            runs.append(read_run(key, label, artifact))
    return runs


def app_lookup(run: RunMetric, app: str) -> AppMetric | None:
    for metric in run.apps:
        if metric.app == app:
            return metric
    return None


def grouped_bars(ax: plt.Axes, runs: list[RunMetric], attr: str, title: str, ylabel: str) -> None:
    apps = PLOT_APPS
    width = 0.8 / max(1, len(runs))
    x_positions = list(range(len(apps)))
    for run_index, run in enumerate(runs):
        offset = (run_index - (len(runs) - 1) / 2) * width
        values = []
        for app in apps:
            metric = app_lookup(run, app)
            values.append(getattr(metric, attr) if metric else math.nan)
        bars = ax.bar(
            [pos + offset for pos in x_positions],
            [0.0 if math.isnan(value) else value for value in values],
            width=width,
            label=run.label,
            color=COLORS.get(run.label),
        )
        for bar, value in zip(bars, values):
            if math.isnan(value):
                continue
            y_offset = 0.003 if value >= 1.0 else -0.012
            va = "bottom" if value >= 1.0 else "top"
            ax.text(
                bar.get_x() + bar.get_width() / 2,
                value + y_offset,
                f"{value:.3f}",
                ha="center",
                va=va,
                fontsize=6,
                rotation=90,
            )
    ax.axhline(1.0, color="#333333", linewidth=0.8)
    ax.set_xticks(x_positions)
    ax.set_xticklabels([APP_LABEL[app] for app in apps])
    ax.set_title(title)
    ax.set_ylabel(ylabel)
    finite = [
        getattr(metric, attr)
        for run in runs
        for metric in run.apps
        if metric.app in apps and not math.isnan(getattr(metric, attr))
    ]
    if finite:
        ax.set_ylim(min(0.88, min(finite) - 0.03), max(1.14, max(finite) + 0.04))
    ax.grid(axis="y", color="#dddddd", linewidth=0.5)


def family_stack(ax: plt.Axes, runs: list[RunMetric], title: str) -> None:
    labels = [run.label for run in runs]
    bottoms = [0] * len(runs)
    families = list(FAMILY_ORDER)
    seen = set(families)
    other_values = []
    for run in runs:
        other_values.append(sum(count for family, count in run.families.items() if family not in seen))
    for family in families:
        values = [run.families.get(family, 0) for run in runs]
        if not any(values):
            continue
        ax.bar(labels, values, bottom=bottoms, label=family, color=FAMILY_COLORS.get(family))
        bottoms = [bottom + value for bottom, value in zip(bottoms, values)]
    if any(other_values):
        ax.bar(labels, other_values, bottom=bottoms, label="other", color=FAMILY_COLORS["other"])
        bottoms = [bottom + value for bottom, value in zip(bottoms, other_values)]
    for index, total in enumerate(bottoms):
        ax.text(index, total + max(bottoms or [1]) * 0.015, str(total), ha="center", va="bottom", fontsize=8)
    ax.set_title(title)
    ax.set_ylabel("sites applied")
    ax.tick_params(axis="x", rotation=15)
    ax.set_ylim(0, max(bottoms or [1]) * 1.18)
    ax.grid(axis="y", color="#dddddd", linewidth=0.5)


def plot(x86_runs: list[RunMetric], arm64_runs: list[RunMetric]) -> pathlib.Path:
    fig, axes = plt.subplots(2, 3, figsize=(17, 8.6), dpi=180)
    fig.suptitle("kop ablation follow-up (SAMPLES=3, 30s)", fontsize=14)

    grouped_bars(axes[0][0], x86_runs, "workload", "x86 KVM workload throughput", "post / baseline")
    grouped_bars(axes[0][1], x86_runs, "bpf", "x86 KVM BPF cost", "post / baseline ns/run")
    family_stack(axes[0][2], x86_runs, "x86 applied families")

    grouped_bars(axes[1][0], arm64_runs, "workload", "arm64 AWS workload throughput", "post / baseline")
    grouped_bars(axes[1][1], arm64_runs, "bpf", "arm64 AWS BPF cost", "post / baseline ns/run")
    family_stack(axes[1][2], arm64_runs, "arm64 applied families")

    axes[0][0].legend(loc="upper left", fontsize=8)
    axes[1][0].legend(loc="upper left", fontsize=8)
    axes[0][2].legend(loc="upper left", fontsize=7, ncols=2)
    axes[1][2].legend(loc="upper left", fontsize=7, ncols=2)
    fig.subplots_adjust(left=0.06, right=0.98, bottom=0.08, top=0.91, wspace=0.28, hspace=0.45)
    FIG_OUT.parent.mkdir(parents=True, exist_ok=True)
    fig.savefig(FIG_OUT)
    plt.close(fig)
    return FIG_OUT


def write_summary(x86_runs: list[RunMetric], arm64_runs: list[RunMetric], fig: pathlib.Path) -> pathlib.Path:
    lines: list[str] = []
    lines.append("# kop ablation follow-up 2026-06-05")
    lines.append("")
    lines.append(f"Figure: `{fig.relative_to(ROOT)}`")
    lines.append("")
    for title, runs in [("x86 KVM", x86_runs), ("arm64 AWS", arm64_runs)]:
        lines.append(f"## {title}")
        lines.append("")
        if not runs:
            lines.append("No matching artifacts found.")
            lines.append("")
            continue
        lines.append("| Variant | Artifact | total sites | top families |")
        lines.append("| --- | --- | ---: | --- |")
        for run in runs:
            top = ", ".join(f"{name}={count}" for name, count in run.families.most_common(5))
            lines.append(
                f"| {run.label} | `{run.artifact.relative_to(ROOT)}` | {run.total_sites} | {top} |"
            )
        lines.append("")
        lines.append("| Variant | App | status | sites | workload | BPF cost | retained | wins/losses/ties | error |")
        lines.append("| --- | --- | --- | ---: | ---: | ---: | ---: | --- | --- |")
        for run in runs:
            for metric in run.apps:
                lines.append(
                    f"| {run.label} | `{metric.app}` | `{metric.status}` | {metric.sites} | "
                    f"{fmt_ratio(metric.workload)} | {fmt_ratio(metric.bpf)} | {metric.retained} | "
                    f"{metric.wins}/{metric.losses}/{metric.ties} | `{metric.error}` |"
                )
        lines.append("")
    SUMMARY_OUT.write_text("\n".join(lines) + "\n")
    return SUMMARY_OUT


def main() -> None:
    x86_runs = collect(X86_VARIANTS)
    arm64_runs = collect(ARM64_VARIANTS)
    fig = plot(x86_runs, arm64_runs)
    summary = write_summary(x86_runs, arm64_runs, fig)
    print(fig.relative_to(ROOT))
    print(summary.relative_to(ROOT))


if __name__ == "__main__":
    main()
