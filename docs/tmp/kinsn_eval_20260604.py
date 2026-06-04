#!/usr/bin/env python3
"""Post-hoc kinsn corpus evaluation tables and figures for 2026-06-04.

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
FIG_DIR = ROOT / "docs" / "figures"
OUT_MD = ROOT / "docs" / "tmp" / "kinsn_eval_20260604_summary.md"
FIG_OUT = FIG_DIR / "eval-kinsn-corpus-20260604.png"

CORPUS = {
    "bcc": {
        "app": "bcc/set",
        "stem": "bcc__set",
        "stats_on": "corpus/results/x86_kvm_corpus_20260604_060059_192193",
        "stats_off": "corpus/results/x86_kvm_corpus_20260604_090456_427289",
    },
    "otel": {
        "app": "otelcol-ebpf-profiler/profiling",
        "stem": "otelcol-ebpf-profiler__profiling",
        "stats_on": "corpus/results/x86_kvm_corpus_20260604_063237_481303",
        "stats_off": "corpus/results/x86_kvm_corpus_20260604_093627_878868",
    },
    "cilium": {
        "app": "cilium/agent",
        "stem": "cilium__agent",
        "stats_on": "corpus/results/x86_kvm_corpus_20260604_070210_639497",
        "stats_off": "corpus/results/x86_kvm_corpus_20260604_100557_313063",
    },
    "tetragon": {
        "app": "tetragon/observer",
        "stem": "tetragon__observer",
        "stats_on": "corpus/results/x86_kvm_corpus_20260604_073221_306100",
        "stats_off": "corpus/results/x86_kvm_corpus_20260604_103609_366182",
    },
    "katran": {
        "app": "katran",
        "stem": "katran",
        "stats_on": "corpus/results/x86_kvm_corpus_20260604_080246_742228",
        "stats_off": "corpus/results/x86_kvm_corpus_20260604_110614_563901",
    },
    "tracee": {
        "app": "tracee/monitor",
        "stem": "tracee__monitor",
        "stats_on": "corpus/results/x86_kvm_corpus_20260604_083301_316989",
        "stats_off": "corpus/results/x86_kvm_corpus_20260604_113548_863406",
    },
}

KINSN_FAMILIES = [
    "lea",
    "cond_select",
    "rotate",
    "extract",
    "endian_fusion",
    "bulk_memory",
    "prefetch",
    "other",
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


@dataclass
class ApplySummary:
    reports: int
    applied_programs: int
    sites: int
    matched: int
    skipped: int
    errors: int
    diagnostics: Counter[str]


def resolve(path: str) -> pathlib.Path:
    if path == "TODO":
        raise RuntimeError("fill CORPUS artifact paths before running this script")
    resolved = pathlib.Path(path)
    return resolved if resolved.is_absolute() else ROOT / resolved


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


def fmt_number(value: float) -> str:
    return f"{value:.2f}"


def app_json(run_dir: pathlib.Path, stem: str) -> dict[str, Any]:
    path = run_dir / "details" / "apps" / f"{stem}.json"
    if not path.exists():
        files = sorted((run_dir / "details" / "apps").glob("*.json"))
        if len(files) != 1:
            raise RuntimeError(f"expected {path} or one app json under {run_dir}, found {files}")
        path = files[0]
    app = json.loads(path.read_text())
    if app.get("status") != "ok" or app.get("error"):
        raise RuntimeError(f"{path} did not finish cleanly: {app.get('status')} {app.get('error')!r}")
    return app


def metadata(run_dir: pathlib.Path) -> dict[str, Any]:
    return json.loads((run_dir / "metadata.json").read_text())


def text_metrics(text: str) -> tuple[float, Counter[str], int]:
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
    return total, by_name, errors


def workload_metric(workload: dict[str, Any]) -> tuple[float, Counter[str], int]:
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
    return total, by_name, errors


def phase_samples(app: dict[str, Any], phase: str) -> list[tuple[float, Counter[str], int]]:
    phase_obj = app.get(phase)
    if not isinstance(phase_obj, dict):
        return []
    return [workload_metric(workload) for workload in phase_obj.get("workloads", [])]


def workload_rows() -> list[WorkloadRow]:
    rows: list[WorkloadRow] = []
    for key, info in CORPUS.items():
        run_dir = resolve(info["stats_off"])
        app = app_json(run_dir, info["stem"])
        baseline = phase_samples(app, "baseline")
        post_rejit = phase_samples(app, "post_rejit")
        baseline_values = [sample[0] for sample in baseline]
        post_values = [sample[0] for sample in post_rejit]
        if len(baseline_values) != 3 or len(post_values) != 3:
            raise RuntimeError(
                f"{run_dir}: expected 3 baseline and 3 post samples, got "
                f"{len(baseline_values)}/{len(post_values)}"
            )
        sample_ratios = [
            post_values[index] / baseline_values[index]
            for index in range(min(len(baseline_values), len(post_values)))
        ]
        rows.append(
            WorkloadRow(
                key=key,
                app=info["app"],
                baseline=median(baseline_values),
                post_rejit=median(post_values),
                sample_ratios=sample_ratios,
                reported_errors=sum(sample[2] for sample in baseline + post_rejit),
            )
        )
    return rows


def render_diagnostic(diagnostic: object) -> str:
    return str(diagnostic).split(":", 1)[0]


def loadtime_path(run_dir: pathlib.Path, stem: str) -> pathlib.Path:
    path = run_dir / "details" / "loadtime-reports" / f"{stem}.jsonl"
    if path.exists():
        return path
    files = sorted((run_dir / "details" / "loadtime-reports").glob("*.jsonl"))
    if len(files) != 1:
        raise RuntimeError(f"expected {path} or one loadtime report under {run_dir}, found {files}")
    return files[0]


def loadtime_rows() -> tuple[
    dict[str, ApplySummary],
    dict[str, Counter[str]],
    dict[str, Counter[str]],
    dict[str, Counter[str]],
]:
    summaries: dict[str, ApplySummary] = {}
    applied_programs: dict[str, Counter[str]] = {}
    kinsn_names: dict[str, Counter[str]] = {}
    kinsn_families: dict[str, Counter[str]] = {}
    for key, info in CORPUS.items():
        run_dir = resolve(info["stats_on"])
        summary = ApplySummary(0, 0, 0, 0, 0, 0, Counter())
        app_programs: Counter[str] = Counter()
        app_names: Counter[str] = Counter()
        app_families: Counter[str] = Counter()
        for line in loadtime_path(run_dir, info["stem"]).read_text().splitlines():
            if not line.strip():
                continue
            record = json.loads(line)
            report = record.get("report") or {}
            sites = int(report.get("sites_applied") or 0)
            summary.reports += 1
            summary.sites += sites
            summary.matched += int(report.get("sites_matched") or 0)
            summary.skipped += int(report.get("sites_skipped") or 0)
            if sites:
                summary.applied_programs += 1
                if record.get("prog_name"):
                    app_programs[str(record["prog_name"])] += sites
            if report.get("error") or record.get("error"):
                summary.errors += 1
            for diagnostic in report.get("diagnostics") or []:
                summary.diagnostics[render_diagnostic(diagnostic)] += 1

            names = Counter({str(name): int(count) for name, count in (report.get("kinsn_calls_by_name") or {}).items()})
            families = Counter(
                {str(name): int(count) for name, count in (report.get("kinsn_calls_by_family") or {}).items()}
            )
            if sites and sum(names.values()) != sites:
                raise RuntimeError(
                    f"{run_dir}: {record.get('prog_name')} has sites_applied={sites}, "
                    f"but kinsn_calls_by_name totals {sum(names.values())}"
                )
            if sites and sum(families.values()) != sites:
                raise RuntimeError(
                    f"{run_dir}: {record.get('prog_name')} has sites_applied={sites}, "
                    f"but kinsn_calls_by_family totals {sum(families.values())}"
                )
            app_names.update(names)
            app_families.update(families)
        summaries[key] = summary
        applied_programs[key] = app_programs
        kinsn_names[key] = app_names
        kinsn_families[key] = app_families
    return summaries, applied_programs, kinsn_names, kinsn_families


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
    pair_prefix = pair.name[:14]
    return any(pair.name.startswith(name[:14]) or name.startswith(pair_prefix) for name in applied_names)


def bpf_rows(applied_names: dict[str, Counter[str]]) -> list[BpfRow]:
    rows: list[BpfRow] = []
    for key, info in CORPUS.items():
        run_dir = resolve(info["stats_on"])
        app = app_json(run_dir, info["stem"])
        qualified = paired_bpf_rows(app)
        direct = [pair for pair in qualified if is_direct_self_applied(pair, applied_names[key])]
        rows.append(BpfRow(key=key, app=info["app"], qualified=qualified, direct_applied=direct))
    return rows


def plot_corpus(
    workloads: list[WorkloadRow],
    bpf: list[BpfRow],
    families: dict[str, Counter[str]],
) -> pathlib.Path:
    FIG_DIR.mkdir(parents=True, exist_ok=True)
    labels = [row.key for row in workloads]
    x = list(range(len(labels)))
    fig, axes = plt.subplots(1, 3, figsize=(16.6, 5.2), dpi=180)

    ax = axes[0]
    workload_values = [row.post_over_baseline for row in workloads]
    ax.bar(x, workload_values, color="#4e79a7", width=0.58)
    ax.axhline(1.0, color="0.25", linestyle="--", linewidth=1.0)
    ax.set_title("Workload throughput")
    ax.set_ylabel("post_rejit / baseline")
    ax.set_xticks(x)
    ax.set_xticklabels(labels, rotation=28, ha="right")
    ax.set_ylim(min(0.85, min(workload_values) * 0.96), max(1.15, max(workload_values) * 1.06))
    ax.grid(axis="y", color="0.9")
    for index, value in enumerate(workload_values):
        ax.text(index, value + 0.012, f"{value:.2f}x", ha="center", va="bottom", fontsize=8)

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
    visible = [value for value in bpf_values + direct_y if not math.isnan(value)]
    ax.set_ylim(min(0.75, min(visible) * 0.94), max(1.25, max(visible) * 1.06))
    ax.grid(axis="y", color="0.9")
    ax.legend(frameon=False, loc="upper left", fontsize=8)
    for index, key in enumerate(labels):
        row = bpf_by_key[key]
        ax.text(index, bpf_values[index] + 0.015, f"n={len(row.qualified)}", ha="center", va="bottom", fontsize=8)

    ax = axes[2]
    family_colors = {
        "lea": "#76b7b2",
        "cond_select": "#e15759",
        "rotate": "#4e79a7",
        "extract": "#f28e2b",
        "endian_fusion": "#59a14f",
        "bulk_memory": "#edc948",
        "prefetch": "#b07aa1",
        "other": "#9c755f",
    }
    active_families = [
        family
        for family in KINSN_FAMILIES
        if sum(families[key].get(family, 0) for key in labels) > 0
    ]
    sites = [sum(families[key].values()) for key in labels]
    bottoms = [0] * len(labels)
    for family in active_families:
        values = [families[key].get(family, 0) for key in labels]
        ax.bar(x, values, bottom=bottoms, color=family_colors[family], width=0.58, label=family)
        bottoms = [bottom + value for bottom, value in zip(bottoms, values)]
    ax.set_title("Applied kinsn families")
    ax.set_ylabel("sites applied")
    ax.set_xticks(x)
    ax.set_xticklabels(labels, rotation=28, ha="right")
    ax.set_ylim(0, max(1.0, max(sites) * 1.28))
    ax.grid(axis="y", color="0.9")
    if active_families:
        ax.legend(frameon=False, loc="upper left", ncol=2, fontsize=8)
    max_sites = max(sites) if sites else 0
    for index, site_count in enumerate(sites):
        ax.text(
            index,
            site_count + max_sites * 0.025 if max_sites else 0.05,
            str(site_count),
            ha="center",
            va="bottom",
            fontsize=8,
        )

    fig.suptitle("Kinsn ReJIT on x86 KVM corpus apps", fontsize=16)
    fig.tight_layout(rect=(0, 0.03, 1, 0.92))
    fig.savefig(FIG_OUT, bbox_inches="tight")
    plt.close(fig)
    return FIG_OUT


def total_counter(rows: dict[str, Counter[str]]) -> Counter[str]:
    total: Counter[str] = Counter()
    for counter in rows.values():
        total.update(counter)
    return total


def write_summary(
    workloads: list[WorkloadRow],
    bpf: list[BpfRow],
    apply: dict[str, ApplySummary],
    applied_programs: dict[str, Counter[str]],
    kinsn_names: dict[str, Counter[str]],
    kinsn_families: dict[str, Counter[str]],
    fig: pathlib.Path,
) -> None:
    workload_ratios = [row.post_over_baseline for row in workloads]
    all_bpf_ratios = [pair.ratio for row in bpf for pair in row.qualified]
    direct_bpf_ratios = [pair.ratio for row in bpf for pair in row.direct_applied]
    total_names = total_counter(kinsn_names)
    total_families = total_counter(kinsn_families)

    lines: list[str] = []
    lines.append("# Kinsn Corpus Evaluation Summary, 2026-06-04")
    lines.append("")
    lines.append("Generated by `docs/tmp/kinsn_eval_20260604.py` from raw artifacts.")
    lines.append("")
    lines.append(f"- Figure: `{fig.relative_to(ROOT)}`")
    lines.append(f"- Workload post/baseline geomean: `{geomean(workload_ratios):.3f}x`")
    lines.append(f"- BPF all-qualified per-program geomean: `{geomean(all_bpf_ratios):.3f}x`")
    lines.append(f"- BPF direct-self-applied per-program geomean: `{fmt_ratio(geomean(direct_bpf_ratios))}`")
    lines.append("")
    lines.append("## Artifacts")
    lines.append("")
    lines.append("| App | stats-on artifact | stats-off artifact |")
    lines.append("| --- | --- | --- |")
    for key, info in CORPUS.items():
        lines.append(
            f"| `{key}` | `{resolve(info['stats_on']).relative_to(ROOT)}` | "
            f"`{resolve(info['stats_off']).relative_to(ROOT)}` |"
        )

    lines.append("")
    lines.append("## Workload Throughput")
    lines.append("")
    lines.append("| App | baseline throughput | post-ReJIT throughput | post/baseline | sample ratios | reported errors |")
    lines.append("| --- | ---: | ---: | ---: | --- | ---: |")
    for row in workloads:
        samples = ", ".join(f"{value:.3f}x" for value in row.sample_ratios)
        lines.append(
            f"| `{row.key}` | {fmt_number(row.baseline)} | {fmt_number(row.post_rejit)} | "
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
    lines.append(
        f"| `total` | {len(all_bpf_ratios)} | {fmt_ratio(geomean(all_bpf_ratios))} | "
        f"{'/'.join(str(v) for v in wins_losses(all_bpf_ratios))} | {len(direct_bpf_ratios)} | "
        f"{fmt_ratio(geomean(direct_bpf_ratios))} | {'/'.join(str(v) for v in wins_losses(direct_bpf_ratios))} |"
    )

    lines.append("")
    lines.append("## Loadtime Apply")
    lines.append("")
    lines.append("| App | reports | applied programs | sites applied | sites matched | skipped | errors | diagnostics |")
    lines.append("| --- | ---: | ---: | ---: | ---: | ---: | ---: | --- |")
    total_apply = ApplySummary(0, 0, 0, 0, 0, 0, Counter())
    for key, summary in apply.items():
        total_apply.reports += summary.reports
        total_apply.applied_programs += summary.applied_programs
        total_apply.sites += summary.sites
        total_apply.matched += summary.matched
        total_apply.skipped += summary.skipped
        total_apply.errors += summary.errors
        total_apply.diagnostics.update(summary.diagnostics)
        diagnostics = ", ".join(f"`{name}`={count}" for name, count in sorted(summary.diagnostics.items()))
        lines.append(
            f"| `{key}` | {summary.reports} | {summary.applied_programs} | {summary.sites} | "
            f"{summary.matched} | {summary.skipped} | {summary.errors} | {diagnostics} |"
        )
    total_diagnostics = ", ".join(f"`{name}`={count}" for name, count in sorted(total_apply.diagnostics.items()))
    lines.append(
        f"| `total` | {total_apply.reports} | {total_apply.applied_programs} | {total_apply.sites} | "
        f"{total_apply.matched} | {total_apply.skipped} | {total_apply.errors} | {total_diagnostics} |"
    )

    lines.append("")
    lines.append("## Applied Kinsn Families")
    lines.append("")
    lines.append("| App | lea | cond_select | rotate | extract | endian_fusion | bulk_memory | prefetch | other | total |")
    lines.append("| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |")
    for key in CORPUS:
        counts = kinsn_families[key]
        lines.append(
            f"| `{key}` | "
            f"{counts.get('lea', 0)} | {counts.get('cond_select', 0)} | {counts.get('rotate', 0)} | "
            f"{counts.get('extract', 0)} | {counts.get('endian_fusion', 0)} | "
            f"{counts.get('bulk_memory', 0)} | {counts.get('prefetch', 0)} | "
            f"{counts.get('other', 0)} | {sum(counts.values())} |"
        )
    lines.append(
        f"| `total` | "
        f"{total_families.get('lea', 0)} | {total_families.get('cond_select', 0)} | "
        f"{total_families.get('rotate', 0)} | {total_families.get('extract', 0)} | "
        f"{total_families.get('endian_fusion', 0)} | {total_families.get('bulk_memory', 0)} | "
        f"{total_families.get('prefetch', 0)} | {total_families.get('other', 0)} | "
        f"{sum(total_families.values())} |"
    )

    lines.append("")
    lines.append("## Applied Kinsn Names")
    lines.append("")
    lines.append("| App | Applied kinsn names by count |")
    lines.append("| --- | --- |")
    for key in CORPUS:
        rendered = ", ".join(f"`{name}`={count}" for name, count in kinsn_names[key].most_common())
        lines.append(f"| `{key}` | {rendered or 'none'} |")
    total_rendered = ", ".join(f"`{name}`={count}" for name, count in total_names.most_common())
    lines.append(f"| `total` | {total_rendered or 'none'} |")

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
    lines.append("## Top Applied Programs")
    lines.append("")
    lines.append("| App | Applied programs by site count |")
    lines.append("| --- | --- |")
    for key in CORPUS:
        rendered = ", ".join(f"`{name}`={count}" for name, count in applied_programs[key].most_common(12))
        lines.append(f"| `{key}` | {rendered or 'none'} |")

    OUT_MD.write_text("\n".join(lines) + "\n")


def main() -> None:
    for key, info in CORPUS.items():
        for mode in ["stats_on", "stats_off"]:
            meta = metadata(resolve(info[mode]))
            if meta.get("status") != "completed":
                raise RuntimeError(f"{key} {mode} metadata is not completed: {meta}")
            if meta.get("samples") != 3:
                raise RuntimeError(f"{key} {mode} expected samples=3: {meta}")
            if int(meta.get("workload_seconds") or 0) != 180:
                raise RuntimeError(f"{key} {mode} expected workload_seconds=180: {meta}")
    workloads = workload_rows()
    apply, applied_programs, kinsn_names, kinsn_families = loadtime_rows()
    bpf = bpf_rows(applied_programs)
    fig = plot_corpus(workloads, bpf, kinsn_families)
    write_summary(workloads, bpf, apply, applied_programs, kinsn_names, kinsn_families, fig)
    print(f"wrote {OUT_MD.relative_to(ROOT)}")
    print(f"wrote {fig.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
