#!/usr/bin/env python3
"""Post-hoc LEA kinsn corpus evaluation tables and figure for 2026-06-02.

This script intentionally lives under docs/tmp: it analyzes raw benchmark
artifacts after collection and does not participate in the benchmark framework.
"""

from __future__ import annotations

import importlib.util
import json
import math
import pathlib
import statistics
import sys
from collections import Counter, defaultdict
from typing import Any

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt


ROOT = pathlib.Path(__file__).resolve().parents[2]
RUN_DIR = ROOT / "corpus/results/x86_kvm_corpus_20260602_141656_778399"
FIG_DIR = ROOT / "docs" / "figures"
OUT_MD = ROOT / "docs" / "tmp" / "kinsn_eval_20260602_summary.md"
FIG_OUT = FIG_DIR / "eval-kinsn-lea-corpus-20260602.png"
PASS_NAME = "lea"


def load_base_module() -> Any:
    path = ROOT / "docs" / "tmp" / "kinsn_eval_20260531.py"
    spec = importlib.util.spec_from_file_location("kinsn_eval_20260531_base", path)
    if spec is None or spec.loader is None:
        raise RuntimeError(f"failed to load {path}")
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    module.RUN_DIR = RUN_DIR
    return module


base = load_base_module()
APPS = base.APPS


def geomean(values: list[float]) -> float:
    return math.exp(sum(math.log(value) for value in values) / len(values)) if values else math.nan


def wins_losses(values: list[float]) -> tuple[int, int, int]:
    wins = sum(1 for value in values if value < 1.0)
    losses = sum(1 for value in values if value > 1.0)
    ties = sum(1 for value in values if value == 1.0)
    return wins, losses, ties


def fmt_ratio(value: float) -> str:
    return "n/a" if math.isnan(value) else f"{value:.3f}x"


def workload_rows(expected_samples: int) -> list[Any]:
    rows: list[Any] = []
    for key, app_name, stem in APPS:
        app = base.load_app(stem)
        baseline = base.phase_samples(app, "baseline")
        post_rejit = base.phase_samples(app, "post_rejit")
        baseline_values = [sample[0] for sample in baseline]
        post_values = [sample[0] for sample in post_rejit]
        if len(baseline_values) != expected_samples or len(post_values) != expected_samples:
            raise RuntimeError(
                f"{stem} expected {expected_samples} baseline and post samples, "
                f"got {len(baseline_values)}/{len(post_values)}"
            )
        sample_ratios = [
            post_values[index] / baseline_values[index]
            for index in range(min(len(baseline_values), len(post_values)))
        ]
        rows.append(
            base.WorkloadRow(
                key=key,
                app=app_name,
                baseline=statistics.median(baseline_values),
                post_rejit=statistics.median(post_values),
                sample_ratios=sample_ratios,
                reported_errors=sum(sample[2] for sample in baseline + post_rejit),
            )
        )
    return rows


def loadtime_summary() -> tuple[dict[str, dict[str, Counter[str]]], dict[str, Counter[str]]]:
    summaries: dict[str, dict[str, Counter[str]]] = {}
    applied_names: dict[str, Counter[str]] = {}
    for key, _, stem in APPS:
        per_pass: dict[str, Counter[str]] = defaultdict(Counter)
        names: Counter[str] = Counter()
        path = RUN_DIR / "details" / "loadtime-reports" / f"{stem}.jsonl"
        for line in path.read_text().splitlines():
            if not line.strip():
                continue
            record = json.loads(line)
            report = record.get("report") or {}
            pass_name = report.get("pass") or record.get("step") or "<none>"
            sites = int(report.get("sites_applied") or 0)
            summary = per_pass[pass_name]
            summary["reports"] += 1
            summary["sites"] += sites
            summary["matched"] += int(report.get("sites_matched") or 0)
            summary["skipped"] += int(report.get("sites_skipped") or 0)
            if sites:
                summary["applied_programs"] += 1
                if record.get("prog_name"):
                    names[record["prog_name"]] += sites
            if report.get("error") or record.get("error"):
                summary["errors"] += 1
            for diagnostic in report.get("diagnostics") or []:
                summary[f"diag:{base.render_diagnostic(diagnostic)}"] += 1
        summaries[key] = dict(per_pass)
        applied_names[key] = names
    return summaries, applied_names


def plot_corpus(workloads: list[Any], bpf: list[Any], apply: dict[str, dict[str, Counter[str]]]) -> pathlib.Path:
    FIG_DIR.mkdir(parents=True, exist_ok=True)
    labels = [row.key for row in workloads]
    x = list(range(len(labels)))
    fig, axes = plt.subplots(1, 3, figsize=(15.7, 4.7), dpi=180)

    ax = axes[0]
    workload_values = [row.post_over_baseline for row in workloads]
    ax.bar(x, workload_values, color="#4e79a7", width=0.58)
    ax.axhline(1.0, color="0.25", linestyle="--", linewidth=1.0)
    ax.set_title("Workload throughput")
    ax.set_ylabel("post_rejit / baseline")
    ax.set_xticks(x)
    ax.set_xticklabels(labels, rotation=28, ha="right")
    ax.set_ylim(min(0.9, min(workload_values) * 0.96), max(1.6, max(workload_values) * 1.04))
    ax.grid(axis="y", color="0.9")
    for index, value in enumerate(workload_values):
        ax.text(index, value + 0.018, f"{value:.2f}x", ha="center", va="bottom", fontsize=8)

    ax = axes[1]
    bpf_by_key = {row.key: row for row in bpf}
    bpf_values = [bpf_by_key[key].qualified_geomean for key in labels]
    ax.bar(x, bpf_values, color="#f28e2b", width=0.58, label="All qualified")
    direct_x = []
    direct_y = []
    for index, key in enumerate(labels):
        value = bpf_by_key[key].direct_geomean
        if not math.isnan(value):
            direct_x.append(index)
            direct_y.append(value)
    if direct_x:
        ax.scatter(direct_x, direct_y, marker="D", s=52, color="#59a14f", label="Direct applied")
    ax.axhline(1.0, color="0.25", linestyle="--", linewidth=1.0)
    ax.set_title("BPF per-program cost")
    ax.set_ylabel("post_rejit ns/run / baseline ns/run")
    ax.set_xticks(x)
    ax.set_xticklabels(labels, rotation=28, ha="right")
    ax.set_ylim(min(0.4, min(bpf_values + direct_y) * 0.92), max(1.25, max(bpf_values + direct_y) * 1.05))
    ax.grid(axis="y", color="0.9")
    ax.legend(frameon=False, loc="upper center", bbox_to_anchor=(0.5, 1.18), ncol=2)
    for index, key in enumerate(labels):
        row = bpf_by_key[key]
        ax.text(index, bpf_values[index] + 0.018, f"n={len(row.qualified)}", ha="center", va="bottom", fontsize=8)

    ax = axes[2]
    sites = [apply[key].get(PASS_NAME, Counter()).get("sites", 0) for key in labels]
    programs = [apply[key].get(PASS_NAME, Counter()).get("applied_programs", 0) for key in labels]
    ax.bar(x, sites, color="#76b7b2", width=0.58)
    ax.set_title("LEA apply coverage")
    ax.set_ylabel("sites applied")
    ax.set_xticks(x)
    ax.set_xticklabels(labels, rotation=28, ha="right")
    ax.set_ylim(0, max(1.0, max(sites) * 1.28))
    ax.grid(axis="y", color="0.9")
    for index, (site_count, program_count) in enumerate(zip(sites, programs)):
        label = f"{site_count}\n{program_count} prog" if site_count else "0"
        ax.text(
            index,
            site_count + max(sites) * 0.025 if max(sites) else 0.05,
            label,
            ha="center",
            va="bottom",
            fontsize=8,
        )

    fig.suptitle("x86 KVM LEA kinsn corpus evaluation", fontsize=16)
    fig.tight_layout(rect=(0, 0.03, 1, 0.93))
    fig.savefig(FIG_OUT, bbox_inches="tight")
    plt.close(fig)
    return FIG_OUT


def raw_counter_caveats(bpf: list[Any]) -> list[tuple[str, Any]]:
    caveats: list[tuple[str, Any]] = []
    for row in bpf:
        for pair in row.qualified:
            if pair.ratio >= 1000:
                caveats.append((row.key, pair))
    return caveats


def write_summary(
    workloads: list[Any],
    bpf: list[Any],
    apply: dict[str, dict[str, Counter[str]]],
    applied_names: dict[str, Counter[str]],
    fig: pathlib.Path,
) -> None:
    metadata = json.loads((RUN_DIR / "metadata.json").read_text())
    all_bpf_ratios = [pair.ratio for row in bpf for pair in row.qualified]
    direct_bpf_ratios = [pair.ratio for row in bpf for pair in row.direct_applied]
    workload_ratios = [row.post_over_baseline for row in workloads]

    lines: list[str] = []
    lines.append("# LEA Kinsn Corpus Evaluation Summary, 2026-06-02")
    lines.append("")
    lines.append("Generated by `docs/tmp/kinsn_eval_20260602.py` from raw artifacts.")
    lines.append("")
    lines.append(f"- Artifact: `{RUN_DIR.relative_to(ROOT)}`")
    lines.append(f"- Figure: `{fig.relative_to(ROOT)}`")
    lines.append(f"- Enabled passes: `{', '.join(metadata['config']['enabled_passes'])}`")
    lines.append(f"- Samples: `{metadata['samples']}`")
    lines.append(f"- Workload seconds: `{metadata['workload_seconds']:.0f}`")
    lines.append(f"- Workload post/baseline geomean: `{geomean(workload_ratios):.3f}x`")
    lines.append(f"- BPF all-qualified per-program geomean: `{geomean(all_bpf_ratios):.3f}x`")
    lines.append(f"- BPF direct-self-applied per-program geomean: `{fmt_ratio(geomean(direct_bpf_ratios))}`")
    lines.append("")
    lines.append("## Workload Throughput")
    lines.append("")
    lines.append("| App | Baseline throughput | post_rejit throughput | post/baseline | sample ratios | reported errors |")
    lines.append("| --- | ---: | ---: | ---: | --- | ---: |")
    for row in workloads:
        samples = ", ".join(f"{value:.3f}x" for value in row.sample_ratios)
        lines.append(
            f"| `{row.key}` | {row.baseline:.2f} | {row.post_rejit:.2f} | "
            f"{row.post_over_baseline:.3f}x | {samples} | {row.reported_errors} |"
        )

    lines.append("")
    lines.append("## BPF Per-Program Counters")
    lines.append("")
    lines.append("| App | all-qualified n | all-qualified geomean | wins/losses/ties | direct applied n | direct applied geomean | direct wins/losses/ties |")
    lines.append("| --- | ---: | ---: | ---: | ---: | ---: | ---: |")
    for row in bpf:
        all_values = [pair.ratio for pair in row.qualified]
        direct_values = [pair.ratio for pair in row.direct_applied]
        all_wlt = wins_losses(all_values)
        direct_wlt = wins_losses(direct_values)
        lines.append(
            f"| `{row.key}` | {len(row.qualified)} | {fmt_ratio(row.qualified_geomean)} | "
            f"{all_wlt[0]}/{all_wlt[1]}/{all_wlt[2]} | {len(row.direct_applied)} | "
            f"{fmt_ratio(row.direct_geomean)} | {direct_wlt[0]}/{direct_wlt[1]}/{direct_wlt[2]} |"
        )

    lines.append("")
    lines.append("## Direct Self-Applied Qualified Rows")
    lines.append("")
    lines.append("| App | Program | Type | baseline ns/run | post ns/run | post/baseline | baseline/post runs |")
    lines.append("| --- | --- | --- | ---: | ---: | ---: | ---: |")
    for row in bpf:
        for pair in row.direct_applied:
            lines.append(
                f"| `{row.key}` | `{pair.name}` | `{pair.prog_type}` | "
                f"{pair.baseline_ns_per_run:.2f} | {pair.post_ns_per_run:.2f} | "
                f"{pair.ratio:.3f}x | {pair.baseline_runs}/{pair.post_runs} |"
            )

    lines.append("")
    lines.append("## Loadtime Apply")
    lines.append("")
    lines.append("| App | reports | applied programs | sites applied | sites matched | errors | diagnostics |")
    lines.append("| --- | ---: | ---: | ---: | ---: | ---: | --- |")
    for key, _, _ in APPS:
        summary = apply[key].get(PASS_NAME, Counter())
        diagnostics = ", ".join(
            f"{name.removeprefix('diag:')}={count}"
            for name, count in sorted(summary.items())
            if name.startswith("diag:")
        )
        lines.append(
            f"| `{key}` | {summary.get('reports', 0)} | "
            f"{summary.get('applied_programs', 0)} | {summary.get('sites', 0)} | "
            f"{summary.get('matched', 0)} | {summary.get('errors', 0)} | {diagnostics or ''} |"
        )

    lines.append("")
    lines.append("## Top Applied Programs")
    lines.append("")
    lines.append("| App | Applied programs by site count |")
    lines.append("| --- | --- |")
    for key, _, _ in APPS:
        rendered = ", ".join(f"`{name}`={count}" for name, count in applied_names[key].most_common(12))
        lines.append(f"| `{key}` | {rendered or 'none'} |")

    caveats = raw_counter_caveats(bpf)
    if caveats:
        lines.append("")
        lines.append("## Raw Counter Caveats")
        lines.append("")
        lines.append("| App | Program | Type | baseline ns/run | post ns/run | post/baseline | baseline/post runs |")
        lines.append("| --- | --- | --- | ---: | ---: | ---: | ---: |")
        for key, pair in caveats:
            lines.append(
                f"| `{key}` | `{pair.name}` | `{pair.prog_type}` | "
                f"{pair.baseline_ns_per_run:.2f} | {pair.post_ns_per_run:.2f} | "
                f"{pair.ratio:.3f}x | {pair.baseline_runs}/{pair.post_runs} |"
            )

    lines.append("")
    OUT_MD.write_text("\n".join(lines))


def main() -> None:
    metadata = json.loads((RUN_DIR / "metadata.json").read_text())
    if metadata.get("status") != "completed":
        raise RuntimeError(f"unexpected run metadata: {metadata}")
    if metadata.get("config", {}).get("enabled_passes") != [PASS_NAME]:
        raise RuntimeError(f"unexpected enabled passes: {metadata.get('config')}")
    expected_samples = int(metadata.get("samples") or 0)
    workloads = workload_rows(expected_samples)
    apply, applied_names = loadtime_summary()
    bpf = base.bpf_rows(applied_names)
    fig = plot_corpus(workloads, bpf, apply)
    write_summary(workloads, bpf, apply, applied_names, fig)
    print(f"wrote {OUT_MD.relative_to(ROOT)}")
    print(f"wrote {fig.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
