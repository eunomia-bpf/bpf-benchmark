#!/usr/bin/env python3
"""Post-hoc all-force kinsn corpus evaluation for 2026-06-03.

This script intentionally lives under docs/tmp: it analyzes raw benchmark
artifacts after collection and does not participate in the benchmark framework.
"""

from __future__ import annotations

import importlib.util
import json
import math
import os
import pathlib
import statistics
import struct
import sys
from collections import Counter, defaultdict
from typing import Any

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt


ROOT = pathlib.Path(__file__).resolve().parents[2]


def artifact_path(env_name: str, default: str) -> pathlib.Path:
    value = os.environ.get(env_name, default)
    path = pathlib.Path(value)
    return path if path.is_absolute() else ROOT / path


RUN_DIR = artifact_path(
    "KINSN_EVAL_RUN_DIR", "corpus/results/x86_kvm_corpus_20260603_175429_964295"
)
SMOKE_DIR = artifact_path(
    "KINSN_EVAL_SMOKE_DIR", "corpus/results/x86_kvm_corpus_20260603_185015_116803"
)
OUT_MD = ROOT / "docs" / "tmp" / "kinsn_all_force_eval_20260603_summary.md"
FIG_OUT = ROOT / "docs" / "figures" / "eval-kinsn-all-force-corpus-20260603.png"
PASS_NAME = os.environ.get("KINSN_EVAL_PASS_NAME", "")
BPF_CALL = 0x85
BPF_PSEUDO_KINSN_CALL = 4
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


def load_base() -> Any:
    path = ROOT / "docs" / "tmp" / "kinsn_eval_20260531.py"
    spec = importlib.util.spec_from_file_location("kinsn_eval_20260531_base", path)
    if spec is None or spec.loader is None:
        raise RuntimeError(f"failed to load {path}")
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    module.RUN_DIR = RUN_DIR
    return module


base = load_base()
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


def kinsn_family(name: str) -> str:
    if name.startswith("bpf_x86_lea"):
        return "lea"
    if name.startswith("bpf_x86_cmp_cmov") or name.startswith("bpf_x86_cmov"):
        return "cond_select"
    if "_rol" in name or "_ror" in name:
        return "rotate"
    if "bextr" in name or name.startswith("bpf_x86_sh"):
        return "extract"
    if "bswap" in name or "movbe" in name:
        return "endian_fusion"
    if "memcpy" in name or "memset" in name or "rep_" in name:
        return "bulk_memory"
    if "prefetch" in name:
        return "prefetch"
    return "other"


def load_kinsn_targets(workdir: pathlib.Path) -> dict[tuple[int, int], str]:
    target = json.loads((workdir / "target.json").read_text())
    pair_to_name: dict[tuple[int, int], str] = {}
    for name, entry in target.get("kinsns", {}).items():
        pair = (int(entry["call_offset"]), int(entry["btf_func_id"]))
        previous = pair_to_name.get(pair)
        if previous is not None:
            raise RuntimeError(f"{workdir}: duplicate kinsn target {pair}: {previous}, {name}")
        pair_to_name[pair] = name
    return pair_to_name


def decode_applied_kinsns(workdir: pathlib.Path) -> Counter[str]:
    data = (workdir / "input.bin").read_bytes()
    if len(data) % 8:
        raise RuntimeError(f"{workdir}: input.bin size is not a BPF instruction multiple")
    pair_to_name = load_kinsn_targets(workdir)
    names: Counter[str] = Counter()
    for pc in range(0, len(data), 8):
        code, regs, off, imm = struct.unpack_from("<BBhi", data, pc)
        src_reg = regs >> 4
        if code != BPF_CALL or src_reg != BPF_PSEUDO_KINSN_CALL:
            continue
        pair = (int(off), int(imm))
        name = pair_to_name.get(pair)
        if name is None:
            raise RuntimeError(f"{workdir}: kinsn call {pair} has no target.json entry")
        names[name] += 1
    return names


def applied_kinsn_summary() -> tuple[dict[str, Counter[str]], Counter[str], dict[str, Counter[str]], Counter[str]]:
    per_app_names: dict[str, Counter[str]] = {}
    per_app_families: dict[str, Counter[str]] = {}
    total_names: Counter[str] = Counter()
    total_families: Counter[str] = Counter()
    for key, _, stem in APPS:
        app_names: Counter[str] = Counter()
        path = RUN_DIR / "details" / "loadtime-reports" / f"{stem}.jsonl"
        for line in path.read_text().splitlines():
            if not line.strip():
                continue
            record = json.loads(line)
            report = record.get("report") or {}
            sites = int(report.get("sites_applied") or 0)
            if sites == 0:
                continue
            workdir = pathlib.Path(record["workdir"])
            if not workdir.is_absolute():
                workdir = RUN_DIR / workdir
            decoded = decode_applied_kinsns(workdir)
            decoded_sites = sum(decoded.values())
            if decoded_sites != sites:
                raise RuntimeError(
                    f"{workdir}: decoded {decoded_sites} kinsn calls, report has {sites} applied sites"
                )
            app_names.update(decoded)

        app_families: Counter[str] = Counter()
        for name, count in app_names.items():
            app_families[kinsn_family(name)] += count
        per_app_names[key] = app_names
        per_app_families[key] = app_families
        total_names.update(app_names)
        total_families.update(app_families)
    return per_app_names, total_names, per_app_families, total_families


def app_status_rows() -> list[tuple[str, str, str, str]]:
    rows: list[tuple[str, str, str, str]] = []
    for key, app_name, stem in APPS:
        app = json.loads((RUN_DIR / "details" / "apps" / f"{stem}.json").read_text())
        rows.append((key, app_name, str(app.get("status")), str(app.get("error") or "")))
    return rows


def plot_corpus(
    workloads: list[Any],
    bpf: list[Any],
    apply: dict[str, dict[str, Counter[str]]],
    family_counts: dict[str, Counter[str]],
) -> pathlib.Path:
    FIG_OUT.parent.mkdir(parents=True, exist_ok=True)
    labels = [row.key for row in workloads]
    x = list(range(len(labels)))
    fig, axes = plt.subplots(1, 3, figsize=(16.2, 4.9), dpi=180)

    ax = axes[0]
    workload_values = [row.post_over_baseline for row in workloads]
    ax.bar(x, workload_values, color="#4e79a7", width=0.58)
    ax.axhline(1.0, color="0.25", linestyle="--", linewidth=1.0)
    ax.set_title("Workload throughput")
    ax.set_ylabel("post_rejit / baseline")
    ax.set_xticks(x)
    ax.set_xticklabels(labels, rotation=28, ha="right")
    ax.set_ylim(min(0.9, min(workload_values) * 0.96), max(1.35, max(workload_values) * 1.04))
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
    all_bpf_values = bpf_values + direct_y
    ax.set_ylim(min(0.75, min(all_bpf_values) * 0.94), max(1.25, max(all_bpf_values) * 1.06))
    ax.grid(axis="y", color="0.9")
    ax.legend(frameon=False, loc="upper center", bbox_to_anchor=(0.5, 1.18), ncol=2)
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
        if sum(family_counts[key].get(family, 0) for key in labels) > 0
    ]
    sites = [sum(family_counts[key].values()) for key in labels]
    bottoms = [0] * len(labels)
    for family in active_families:
        values = [family_counts[key].get(family, 0) for key in labels]
        ax.bar(
            x,
            values,
            bottom=bottoms,
            color=family_colors[family],
            width=0.58,
            label=family,
        )
        bottoms = [bottom + value for bottom, value in zip(bottoms, values)]
    ax.set_title("Applied kinsn families")
    ax.set_ylabel("sites applied")
    ax.set_xticks(x)
    ax.set_xticklabels(labels, rotation=28, ha="right")
    ax.set_ylim(0, max(1.0, max(sites) * 1.28))
    ax.grid(axis="y", color="0.9")
    if active_families:
        ax.legend(frameon=False, loc="upper center", bbox_to_anchor=(0.5, 1.2), ncol=2)
    max_sites = max(sites) if sites else 0
    for index, site_count in enumerate(sites):
        label = str(site_count) if site_count else "0"
        ax.text(
            index,
            site_count + max_sites * 0.025 if max_sites else 0.05,
            label,
            ha="center",
            va="bottom",
            fontsize=8,
        )

    fig.suptitle("x86 KVM all-force kinsn corpus evaluation", fontsize=16)
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
    kinsn_names: dict[str, Counter[str]],
    total_kinsn_names: Counter[str],
    kinsn_families: dict[str, Counter[str]],
    total_kinsn_families: Counter[str],
    fig: pathlib.Path,
) -> None:
    metadata = json.loads((RUN_DIR / "metadata.json").read_text())
    smoke_metadata = json.loads((SMOKE_DIR / "metadata.json").read_text())
    all_bpf_ratios = [pair.ratio for row in bpf for pair in row.qualified]
    direct_bpf_ratios = [pair.ratio for row in bpf for pair in row.direct_applied]
    workload_ratios = [row.post_over_baseline for row in workloads]
    total = Counter()
    for key, _, _ in APPS:
        total.update(apply[key].get(PASS_NAME, Counter()))

    lines: list[str] = []
    lines.append("# All-Force Kinsn Corpus Evaluation, 2026-06-03")
    lines.append("")
    lines.append("Generated by `docs/tmp/kinsn_all_force_eval_20260603.py` from raw artifacts.")
    lines.append("")
    lines.append(f"- Artifact: `{RUN_DIR.relative_to(ROOT)}`")
    lines.append(f"- Smoke artifact: `{SMOKE_DIR.relative_to(ROOT)}`")
    lines.append(f"- Figure: `{fig.relative_to(ROOT)}`")
    lines.append(f"- Enabled pass entrypoint: `{', '.join(metadata['config']['enabled_passes'])}`")
    lines.append(
        "- Smoke enabled pass entrypoint: "
        f"`{', '.join(smoke_metadata['config']['enabled_passes'])}`"
    )
    lines.append(f"- Samples: `{metadata['samples']}`")
    lines.append(f"- Workload seconds: `{metadata['workload_seconds']:.0f}`")
    lines.append("- Policy: backend default is all-force kinsn; no YAML workload/app disable was used.")
    lines.append(f"- Loadtime apply: `{total['sites']}/{total['matched']}` sites applied, `{total['skipped']}` skipped, `{total['errors']}` errors.")
    lines.append(f"- Workload post/baseline geomean: `{geomean(workload_ratios):.3f}x`")
    lines.append(f"- BPF all-qualified per-program geomean: `{geomean(all_bpf_ratios):.3f}x`")
    lines.append(f"- BPF direct-self-applied per-program geomean: `{fmt_ratio(geomean(direct_bpf_ratios))}`")
    family_summary = ", ".join(
        f"{family}={total_kinsn_families.get(family, 0)}" for family in KINSN_FAMILIES
    )
    lines.append(f"- Applied kinsn families decoded from retained bytecode: `{family_summary}`.")
    lines.append("")
    lines.append("## App Status")
    lines.append("")
    lines.append("| App | status | error |")
    lines.append("| --- | --- | --- |")
    for _, app_name, status, error in app_status_rows():
        lines.append(f"| `{app_name}` | `{status}` | `{error}` |")
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
    lines.append("## Loadtime Apply")
    lines.append("")
    lines.append("| App | reports | applied programs | sites applied | sites matched | skipped | errors |")
    lines.append("| --- | ---: | ---: | ---: | ---: | ---: | ---: |")
    for key, _, _ in APPS:
        summary = apply[key].get(PASS_NAME, Counter())
        lines.append(
            f"| `{key}` | {summary.get('reports', 0)} | {summary.get('applied_programs', 0)} | "
            f"{summary.get('sites', 0)} | {summary.get('matched', 0)} | "
            f"{summary.get('skipped', 0)} | {summary.get('errors', 0)} |"
        )
    lines.append(
        f"| `total` | {total['reports']} | {total['applied_programs']} | "
        f"{total['sites']} | {total['matched']} | {total['skipped']} | {total['errors']} |"
    )

    lines.append("")
    lines.append("## Applied Kinsn Families")
    lines.append("")
    lines.append(
        "Decoded from each applied loadtime workdir's final `input.bin`; decoded call counts must match `sites_applied`."
    )
    lines.append("")
    lines.append("| App | lea | cond_select | rotate | extract | endian_fusion | bulk_memory | prefetch | other | total |")
    lines.append("| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |")
    for key, _, _ in APPS:
        counts = kinsn_families[key]
        row_total = sum(counts.values())
        lines.append(
            f"| `{key}` | "
            f"{counts.get('lea', 0)} | {counts.get('cond_select', 0)} | "
            f"{counts.get('rotate', 0)} | {counts.get('extract', 0)} | "
            f"{counts.get('endian_fusion', 0)} | {counts.get('bulk_memory', 0)} | "
            f"{counts.get('prefetch', 0)} | {counts.get('other', 0)} | {row_total} |"
        )
    lines.append(
        f"| `total` | "
        f"{total_kinsn_families.get('lea', 0)} | {total_kinsn_families.get('cond_select', 0)} | "
        f"{total_kinsn_families.get('rotate', 0)} | {total_kinsn_families.get('extract', 0)} | "
        f"{total_kinsn_families.get('endian_fusion', 0)} | {total_kinsn_families.get('bulk_memory', 0)} | "
        f"{total_kinsn_families.get('prefetch', 0)} | {total_kinsn_families.get('other', 0)} | "
        f"{sum(total_kinsn_families.values())} |"
    )

    lines.append("")
    lines.append("## Applied Kinsn Names")
    lines.append("")
    lines.append("| App | Applied kinsn names by count |")
    lines.append("| --- | --- |")
    for key, _, _ in APPS:
        rendered = ", ".join(f"`{name}`={count}" for name, count in kinsn_names[key].most_common())
        lines.append(f"| `{key}` | {rendered or 'none'} |")
    total_rendered = ", ".join(f"`{name}`={count}" for name, count in total_kinsn_names.most_common())
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
    OUT_MD.write_text("\n".join(lines) + "\n")


def main() -> None:
    global PASS_NAME
    metadata = json.loads((RUN_DIR / "metadata.json").read_text())
    if metadata.get("status") != "completed":
        raise RuntimeError(f"unexpected run metadata: {metadata}")
    enabled_passes = metadata.get("config", {}).get("enabled_passes")
    if PASS_NAME:
        pass_name = PASS_NAME
    elif isinstance(enabled_passes, list) and len(enabled_passes) == 1:
        pass_name = str(enabled_passes[0])
    else:
        raise RuntimeError(f"cannot infer pass name from enabled passes: {enabled_passes}")
    if enabled_passes != [pass_name]:
        raise RuntimeError(f"unexpected enabled passes: {metadata.get('config')}")
    PASS_NAME = pass_name
    smoke_metadata = json.loads((SMOKE_DIR / "metadata.json").read_text())
    if smoke_metadata.get("status") != "completed":
        raise RuntimeError(f"unexpected smoke metadata: {smoke_metadata}")
    expected_samples = int(metadata.get("samples") or 0)
    workloads = workload_rows(expected_samples)
    apply, applied_names = loadtime_summary()
    kinsn_names, total_kinsn_names, kinsn_families, total_kinsn_families = applied_kinsn_summary()
    bpf = base.bpf_rows(applied_names)
    fig = plot_corpus(workloads, bpf, apply, kinsn_families)
    write_summary(
        workloads,
        bpf,
        apply,
        applied_names,
        kinsn_names,
        total_kinsn_names,
        kinsn_families,
        total_kinsn_families,
        fig,
    )
    print(f"wrote {OUT_MD.relative_to(ROOT)}")
    print(f"wrote {fig.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
