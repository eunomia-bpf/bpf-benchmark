#!/usr/bin/env python3
"""Post-hoc arm64 AWS kop follow-up for 2026-06-05.

This script intentionally lives under docs/tmp. It analyzes raw benchmark
artifacts after collection and does not participate in the benchmark framework.
"""

from __future__ import annotations

import argparse
import json
import math
import pathlib
import sys
from collections import Counter
from typing import Any

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt

ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "docs" / "tmp"))
import kop_eval_20260604 as kop_eval

FIG_OUT = ROOT / "docs" / "figures" / "eval-kop-arm64-aws-20260605.png"
SUMMARY_OUT = ROOT / "docs" / "tmp" / "kop_arm64_eval_20260605_summary.md"

APP_ORDER = [
    "bcc/set",
    "cilium/agent",
    "katran",
    "otelcol-ebpf-profiler/profiling",
    "tetragon/observer",
    "tracee/monitor",
]

APP_LABEL = {
    "bcc/set": "BCC",
    "cilium/agent": "Cilium",
    "katran": "Katran",
    "otelcol-ebpf-profiler/profiling": "OTel",
    "tetragon/observer": "Tetragon",
    "tracee/monitor": "Tracee",
}


def resolve(path: str) -> pathlib.Path:
    resolved = pathlib.Path(path)
    return resolved if resolved.is_absolute() else ROOT / resolved


def geomean(values: list[float]) -> float:
    return math.exp(sum(math.log(value) for value in values) / len(values)) if values else math.nan


def fmt_ratio(value: float) -> str:
    return "n/a" if math.isnan(value) else f"{value:.3f}x"


def fmt_error(value: Any, limit: int = 120) -> str:
    text = " ".join(str(value or "").split())
    if len(text) > limit:
        text = text[: limit - 3] + "..."
    return text


def read_apps(artifact: pathlib.Path) -> list[dict[str, Any]]:
    apps = []
    for path in sorted((artifact / "details" / "apps").glob("*.json")):
        apps.append(json.loads(path.read_text()))
    order = {app: idx for idx, app in enumerate(APP_ORDER)}
    apps.sort(key=lambda app: order.get(str(app.get("app")), 999))
    return apps


def workload_ratio(app: dict[str, Any]) -> tuple[float, list[float]]:
    baseline = [sample[0] for sample in kop_eval.phase_samples(app, "baseline")]
    post = [sample[0] for sample in kop_eval.phase_samples(app, "post_rejit")]
    if not baseline or not post:
        return math.nan, []
    paired = [post[index] / baseline[index] for index in range(min(len(baseline), len(post))) if baseline[index]]
    if not paired or not sum(baseline):
        return math.nan, paired
    return (sum(post) / len(post)) / (sum(baseline) / len(baseline)), paired


def bpf_ratio(app: dict[str, Any]) -> tuple[float, int, int, int, int]:
    if app.get("status") != "ok":
        return math.nan, 0, 0, 0, 0
    pairs = kop_eval.paired_bpf_rows(app)
    ratios = [pair.ratio for pair in pairs]
    wins = sum(1 for ratio in ratios if ratio < 1.0)
    losses = sum(1 for ratio in ratios if ratio > 1.0)
    ties = sum(1 for ratio in ratios if ratio == 1.0)
    return geomean(ratios), len(ratios), wins, losses, ties


def loadtime_counters(artifact: pathlib.Path) -> tuple[Counter[str], Counter[str], Counter[str]]:
    by_app: Counter[str] = Counter()
    by_name: Counter[str] = Counter()
    by_family: Counter[str] = Counter()
    report_dir = artifact / "details" / "loadtime-reports"
    for path in sorted(report_dir.glob("*.jsonl")):
        app_key = path.stem
        for line in path.read_text().splitlines():
            if not line.strip():
                continue
            record = json.loads(line)
            report = record.get("report") or {}
            sites = int(report.get("sites_applied") or 0)
            by_app[app_key] += sites
            by_name.update(report.get("kop_calls_by_name") or {})
            by_family.update(report.get("kop_calls_by_family") or {})
    return by_app, by_name, by_family


def app_key(app: dict[str, Any]) -> str:
    name = str(app.get("app") or "")
    if name == "bcc/set":
        return "bcc__set"
    if name == "cilium/agent":
        return "cilium__agent"
    if name == "otelcol-ebpf-profiler/profiling":
        return "otelcol-ebpf-profiler__profiling"
    if name == "tetragon/observer":
        return "tetragon__observer"
    if name == "tracee/monitor":
        return "tracee__monitor"
    return name


def plot(artifact: pathlib.Path, apps: list[dict[str, Any]], by_app: Counter[str]) -> pathlib.Path:
    labels = [APP_LABEL.get(str(app.get("app")), str(app.get("app"))) for app in apps]
    workload = [workload_ratio(app)[0] for app in apps]
    bpf = [bpf_ratio(app)[0] for app in apps]
    sites = [by_app[app_key(app)] for app in apps]

    colors = ["#2f8fbd", "#42aa61", "#8e5ab0", "#d08a32", "#687c8f", "#b85c5c"]
    fig, axes = plt.subplots(1, 3, figsize=(15, 4), dpi=180)
    fig.suptitle("arm64 AWS kop follow-up (t4g.small, SAMPLES=3, 30s)", fontsize=13)

    for ax, values, title, ylabel, baseline in [
        (axes[0], workload, "Workload throughput", "post / baseline", 1.0),
        (axes[1], bpf, "BPF cost", "post / baseline ns/run", 1.0),
    ]:
        plotted = [0 if math.isnan(value) else value for value in values]
        bars = ax.bar(labels, plotted, color=colors[: len(labels)])
        ax.axhline(baseline, color="#333333", linewidth=0.8)
        ax.set_title(title)
        ax.set_ylabel(ylabel)
        ax.tick_params(axis="x", rotation=20)
        for bar, value in zip(bars, values):
            if math.isnan(value):
                ax.text(bar.get_x() + bar.get_width() / 2, 0.03, "n/a", ha="center", va="bottom", fontsize=8)
            else:
                ax.text(
                    bar.get_x() + bar.get_width() / 2,
                    value + 0.003,
                    f"{value:.3f}x",
                    ha="center",
                    va="bottom",
                    fontsize=8,
                )
        finite = [value for value in values if not math.isnan(value)]
        if finite:
            lower = min(0.92, min(finite) - 0.02)
            upper = max(1.08, max(finite) + 0.03)
            ax.set_ylim(lower, upper)

    bars = axes[2].bar(labels, sites, color=colors[: len(labels)])
    axes[2].set_title("Sites applied")
    axes[2].set_ylabel("count")
    axes[2].tick_params(axis="x", rotation=20)
    top = max(sites) if sites else 0
    axes[2].set_ylim(0, max(1, top) * 1.15)
    for bar, value in zip(bars, sites):
        axes[2].text(
            bar.get_x() + bar.get_width() / 2,
            value + max(1, top) * 0.015,
            str(value),
            ha="center",
            va="bottom",
            fontsize=8,
        )

    fig.subplots_adjust(left=0.06, right=0.98, bottom=0.22, top=0.84, wspace=0.32)
    FIG_OUT.parent.mkdir(parents=True, exist_ok=True)
    fig.savefig(FIG_OUT)
    plt.close(fig)
    return FIG_OUT


def write_summary(
    artifact: pathlib.Path,
    coverage_smoke: pathlib.Path | None,
    apps: list[dict[str, Any]],
    by_app: Counter[str],
    by_name: Counter[str],
    by_family: Counter[str],
    fig: pathlib.Path,
) -> pathlib.Path:
    lines: list[str] = []
    lines.append("# arm64 AWS kop follow-up 2026-06-05")
    lines.append("")
    lines.append(f"Artifact: `{artifact.relative_to(ROOT)}`")
    if coverage_smoke:
        lines.append(f"Coverage-smoke artifact: `{coverage_smoke.relative_to(ROOT)}`")
    lines.append(f"Figure: `{fig.relative_to(ROOT)}`")
    lines.append("")

    lines.append("## App status and performance")
    lines.append("")
    lines.append("| App | status | sites applied | workload ratio | BPF cost ratio | retained rows | wins/losses/ties | error |")
    lines.append("| --- | --- | ---: | ---: | ---: | ---: | --- | --- |")
    for app in apps:
        workload, samples = workload_ratio(app)
        bpf, retained, wins, losses, ties = bpf_ratio(app)
        lines.append(
            f"| `{app.get('app')}` | `{app.get('status')}` | {by_app[app_key(app)]} | "
            f"{fmt_ratio(workload)} | {fmt_ratio(bpf)} | {retained} | "
            f"{wins}/{losses}/{ties} | `{fmt_error(app.get('error'))}` |"
        )

    lines.append("")
    lines.append("## Applied families")
    lines.append("")
    lines.append("| Family | sites |")
    lines.append("| --- | ---: |")
    for family, count in by_family.most_common():
        lines.append(f"| `{family}` | {count} |")

    lines.append("")
    lines.append("## Applied names")
    lines.append("")
    lines.append("| KOperation | sites |")
    lines.append("| --- | ---: |")
    for name, count in by_name.most_common():
        lines.append(f"| `{name}` | {count} |")

    if coverage_smoke:
        smoke_app, smoke_name, smoke_family = loadtime_counters(coverage_smoke)
        lines.append("")
        lines.append("## Coverage-smoke upper bound")
        lines.append("")
        lines.append("| Family | sites |")
        lines.append("| --- | ---: |")
        for family, count in smoke_family.most_common():
            lines.append(f"| `{family}` | {count} |")
        lines.append("")
        lines.append("| KOperation | sites |")
        lines.append("| --- | ---: |")
        for name, count in smoke_name.most_common():
            lines.append(f"| `{name}` | {count} |")

    SUMMARY_OUT.write_text("\n".join(lines) + "\n")
    return SUMMARY_OUT


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--artifact", required=True)
    parser.add_argument("--coverage-smoke")
    args = parser.parse_args()

    artifact = resolve(args.artifact)
    coverage_smoke = resolve(args.coverage_smoke) if args.coverage_smoke else None
    apps = read_apps(artifact)
    by_app, by_name, by_family = loadtime_counters(artifact)
    fig = plot(artifact, apps, by_app)
    summary = write_summary(artifact, coverage_smoke, apps, by_app, by_name, by_family, fig)
    print(f"wrote {summary.relative_to(ROOT)}")
    print(f"wrote {fig.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
