#!/usr/bin/env python3
"""Post-hoc kinsn corpus evaluation tables and figure for 2026-05-31.

This script intentionally lives under docs/tmp: it analyzes raw benchmark
artifacts after collection and does not participate in the benchmark framework.
"""

from __future__ import annotations

import json
import math
import pathlib
import re
import statistics
from collections import Counter, defaultdict
from dataclasses import dataclass
from typing import Any

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt


ROOT = pathlib.Path(__file__).resolve().parents[2]
RUN_DIR = ROOT / "corpus/results/x86_kvm_corpus_20260531_093716_580979"
FIG_DIR = ROOT / "docs" / "figures"
OUT_MD = ROOT / "docs" / "tmp" / "kinsn_eval_20260531_summary.md"
FIG_OUT = FIG_DIR / "eval-kinsn-corpus-20260531.png"

APPS = [
    ("bcc", "bcc/set", "bcc__set"),
    ("otel", "otelcol-ebpf-profiler/profiling", "otelcol-ebpf-profiler__profiling"),
    ("cilium", "cilium/agent", "cilium__agent"),
    ("tetragon", "tetragon/observer", "tetragon__observer"),
    ("katran", "katran", "katran"),
    ("tracee", "tracee/monitor", "tracee__monitor"),
]

STRESS_RE = re.compile(
    r"stress-ng: metrc: \[\d+\]\s+([A-Za-z0-9_-]+)\s+(\d+)\s+([0-9.]+).*?\s+([0-9.]+)\s+([0-9.]+)\s*$"
)
OPS_RE = re.compile(r"^(python3|ruby|nodejs|perl|php) int_loop ops=(\d+) elapsed_s=([0-9.]+)")
PPS_RE = re.compile(r"\n\s*(\d+)pps\s+([0-9]+)Mb/sec .* errors: (\d+)")


@dataclass
class WorkloadRow:
    key: str
    app: str
    baseline: float
    post_rejit: float
    sample_ratios: list[float]
    reported_errors: int

    @property
    def post_over_baseline(self) -> float:
        return self.post_rejit / self.baseline

    @property
    def ratio_mean(self) -> float:
        return statistics.mean(self.sample_ratios)

    @property
    def ratio_cv(self) -> float:
        if len(self.sample_ratios) < 2:
            return 0.0
        return statistics.stdev(self.sample_ratios) / self.ratio_mean


@dataclass
class BpfPair:
    name: str
    prog_type: str
    occurrence: int
    baseline_runs: int
    post_runs: int
    baseline_ns_per_run: float
    post_ns_per_run: float
    ratio: float


@dataclass
class BpfRow:
    key: str
    app: str
    qualified: list[BpfPair]
    direct_applied: list[BpfPair]

    @property
    def qualified_geomean(self) -> float:
        return geomean([pair.ratio for pair in self.qualified])

    @property
    def direct_geomean(self) -> float:
        return geomean([pair.ratio for pair in self.direct_applied])


def median(values: list[float]) -> float:
    return statistics.median(values)


def geomean(values: list[float]) -> float:
    return math.exp(sum(math.log(value) for value in values) / len(values)) if values else math.nan


def wins_losses(values: list[float]) -> tuple[int, int, int]:
    wins = sum(1 for value in values if value < 1.0)
    losses = sum(1 for value in values if value > 1.0)
    ties = sum(1 for value in values if value == 1.0)
    return wins, losses, ties


def fmt_ratio(value: float) -> str:
    return "n/a" if math.isnan(value) else f"{value:.3f}x"


def app_path(stem: str) -> pathlib.Path:
    return RUN_DIR / "details" / "apps" / f"{stem}.json"


def load_app(stem: str) -> dict[str, Any]:
    app = json.loads(app_path(stem).read_text())
    if app.get("status") != "ok" or app.get("error"):
        raise RuntimeError(f"{stem} did not finish cleanly: {app.get('status')} {app.get('error')!r}")
    return app


def text_metrics(text: str) -> tuple[float, dict[str, float], int]:
    total = 0.0
    by_name: Counter[str] = Counter()
    errors = 0
    for line in text.splitlines():
        stress = STRESS_RE.search(line)
        if stress:
            value = float(stress.group(4))
            total += value
            by_name[stress.group(1)] += value
        ops = OPS_RE.search(line)
        if ops:
            value = int(ops.group(2)) / float(ops.group(3))
            total += value
            by_name[ops.group(1)] += value
    for pps in PPS_RE.finditer("\n" + text):
        value = float(pps.group(1))
        total += value
        by_name["pps"] += value
        errors += int(pps.group(3))
    return total, dict(by_name), errors


def workload_metric(workload: dict[str, Any]) -> tuple[float, dict[str, float], int]:
    total = 0.0
    by_name: Counter[str] = Counter()
    errors = 0
    for component in workload.get("components") or []:
        value, sub_by_name, sub_errors = workload_metric(component)
        total += value
        errors += sub_errors
        by_name.update(sub_by_name)
    text = (workload.get("stdout") or "") + "\n" + (workload.get("stderr") or "")
    value, sub_by_name, sub_errors = text_metrics(text)
    total += value
    errors += sub_errors
    by_name.update(sub_by_name)
    return total, dict(by_name), errors


def phase_samples(app: dict[str, Any], phase: str) -> list[tuple[float, dict[str, float], int]]:
    phase_obj = app.get(phase)
    if not isinstance(phase_obj, dict):
        return []
    return [workload_metric(workload) for workload in phase_obj.get("workloads", [])]


def workload_rows() -> list[WorkloadRow]:
    rows: list[WorkloadRow] = []
    for key, app_name, stem in APPS:
        app = load_app(stem)
        baseline = phase_samples(app, "baseline")
        post_rejit = phase_samples(app, "post_rejit")
        baseline_values = [sample[0] for sample in baseline]
        post_values = [sample[0] for sample in post_rejit]
        if len(baseline_values) != 3 or len(post_values) != 3:
            raise RuntimeError(f"{stem} expected 3 baseline and 3 post samples")
        sample_ratios = [
            post_values[index] / baseline_values[index]
            for index in range(min(len(baseline_values), len(post_values)))
        ]
        rows.append(
            WorkloadRow(
                key=key,
                app=app_name,
                baseline=median(baseline_values),
                post_rejit=median(post_values),
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
                summary[f"diag:{str(diagnostic).split(':', 1)[0]}"] += 1
        summaries[key] = dict(per_pass)
        applied_names[key] = names
    return summaries, applied_names


def bpf_groups(app: dict[str, Any], phase: str) -> dict[tuple[str, str], list[tuple[int, dict[str, Any]]]]:
    groups: dict[tuple[str, str], list[tuple[int, dict[str, Any]]]] = defaultdict(list)
    for prog_id, record in ((app.get(phase) or {}).get("bpf") or {}).items():
        groups[(record.get("name") or "", record.get("type") or "")].append((int(prog_id), record))
    for records in groups.values():
        records.sort(key=lambda item: item[0])
    return groups


def paired_bpf_rows(app: dict[str, Any]) -> list[BpfPair]:
    baseline = bpf_groups(app, "baseline")
    post_rejit = bpf_groups(app, "post_rejit")
    rows: list[BpfPair] = []
    for key in sorted(set(baseline) & set(post_rejit)):
        count = min(len(baseline[key]), len(post_rejit[key]))
        for occurrence in range(count):
            _, base = baseline[key][occurrence]
            _, post = post_rejit[key][occurrence]
            base_runs = int(base.get("run_cnt_delta") or 0)
            post_runs = int(post.get("run_cnt_delta") or 0)
            base_time = int(base.get("run_time_ns_delta") or 0)
            post_time = int(post.get("run_time_ns_delta") or 0)
            if min(base_runs, post_runs) < 100:
                continue
            if base_time <= 0 or post_time <= 0:
                continue
            base_ns = base_time / base_runs
            post_ns = post_time / post_runs
            rows.append(
                BpfPair(
                    name=key[0],
                    prog_type=key[1],
                    occurrence=occurrence,
                    baseline_runs=base_runs,
                    post_runs=post_runs,
                    baseline_ns_per_run=base_ns,
                    post_ns_per_run=post_ns,
                    ratio=post_ns / base_ns,
                )
            )
    return rows


def is_direct_self_applied(pair: BpfPair, applied_names: Counter[str]) -> bool:
    if not pair.name:
        return False
    # bpftool names are 15-byte truncated; compare stable prefixes both ways.
    pair_prefix = pair.name[:14]
    return any(pair.name.startswith(name[:14]) or name.startswith(pair_prefix) for name in applied_names)


def bpf_rows(applied_names: dict[str, Counter[str]]) -> list[BpfRow]:
    rows: list[BpfRow] = []
    for key, app_name, stem in APPS:
        app = load_app(stem)
        qualified = paired_bpf_rows(app)
        direct = [pair for pair in qualified if is_direct_self_applied(pair, applied_names[key])]
        rows.append(BpfRow(key=key, app=app_name, qualified=qualified, direct_applied=direct))
    return rows


def plot_corpus(workloads: list[WorkloadRow], bpf: list[BpfRow], apply: dict[str, dict[str, Counter[str]]]) -> pathlib.Path:
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
    ax.set_ylim(min(0.9, min(workload_values) * 0.96), max(1.05, max(workload_values) * 1.04))
    ax.grid(axis="y", color="0.9")
    for index, value in enumerate(workload_values):
        ax.text(index, value + 0.006, f"{value:.2f}x", ha="center", va="bottom", fontsize=8)

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
    ax.set_ylim(min(0.9, min(bpf_values + direct_y) * 0.96), max(1.2, max(bpf_values + direct_y) * 1.05))
    ax.grid(axis="y", color="0.9")
    ax.legend(frameon=False, loc="upper left")
    for index, key in enumerate(labels):
        row = bpf_by_key[key]
        ax.text(index, bpf_values[index] + 0.012, f"n={len(row.qualified)}", ha="center", va="bottom", fontsize=8)

    ax = axes[2]
    sites = [apply[key].get("cond_select", Counter()).get("sites", 0) for key in labels]
    programs = [apply[key].get("cond_select", Counter()).get("applied_programs", 0) for key in labels]
    ax.bar(x, sites, color="#76b7b2", width=0.58)
    ax.set_title("kinsn apply coverage")
    ax.set_ylabel("cond_select sites applied")
    ax.set_xticks(x)
    ax.set_xticklabels(labels, rotation=28, ha="right")
    ax.set_ylim(0, max(1.0, max(sites) * 1.28))
    ax.grid(axis="y", color="0.9")
    for index, (site_count, program_count) in enumerate(zip(sites, programs)):
        label = f"{site_count}\n{program_count} prog" if site_count else "0"
        ax.text(index, site_count + max(sites) * 0.025 if max(sites) else 0.05, label, ha="center", va="bottom", fontsize=8)

    fig.suptitle("x86 KVM kinsn-6 corpus evaluation", fontsize=16)
    fig.tight_layout(rect=(0, 0.03, 1, 0.93))
    fig.savefig(FIG_OUT, bbox_inches="tight")
    plt.close(fig)
    return FIG_OUT


def write_summary(
    workloads: list[WorkloadRow],
    bpf: list[BpfRow],
    apply: dict[str, dict[str, Counter[str]]],
    applied_names: dict[str, Counter[str]],
    fig: pathlib.Path,
) -> None:
    metadata = json.loads((RUN_DIR / "metadata.json").read_text())
    all_bpf_ratios = [pair.ratio for row in bpf for pair in row.qualified]
    direct_bpf_ratios = [pair.ratio for row in bpf for pair in row.direct_applied]
    workload_ratios = [row.post_over_baseline for row in workloads]
    lines: list[str] = []
    lines.append("# Kinsn Corpus Evaluation Summary, 2026-05-31")
    lines.append("")
    lines.append("Generated by `docs/tmp/kinsn_eval_20260531.py` from raw artifacts.")
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
    lines.append("| App | Pass | reports | applied programs | sites applied | sites matched | errors | diagnostics |")
    lines.append("| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |")
    for key, _, _ in APPS:
        for pass_name in ["rotate", "cond_select", "extract", "endian_fusion", "bulk_memory", "prefetch"]:
            summary = apply[key].get(pass_name, Counter())
            diagnostics = ", ".join(
                f"{name.removeprefix('diag:')}={count}"
                for name, count in sorted(summary.items())
                if name.startswith("diag:")
            )
            lines.append(
                f"| `{key}` | `{pass_name}` | {summary.get('reports', 0)} | "
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
    lines.append("")
    OUT_MD.write_text("\n".join(lines) + "\n")


def main() -> None:
    metadata = json.loads((RUN_DIR / "metadata.json").read_text())
    if metadata.get("status") != "completed" or metadata.get("samples") != 3:
        raise RuntimeError(f"unexpected run metadata: {metadata}")
    workloads = workload_rows()
    apply, applied_names = loadtime_summary()
    bpf = bpf_rows(applied_names)
    fig = plot_corpus(workloads, bpf, apply)
    write_summary(workloads, bpf, apply, applied_names, fig)
    print(f"wrote {OUT_MD.relative_to(ROOT)}")
    print(f"wrote {fig.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
