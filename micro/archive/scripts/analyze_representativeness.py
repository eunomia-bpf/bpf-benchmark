#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import statistics
import sys
from pathlib import Path

ROOT_DIR = Path(__file__).resolve().parent.parent.parent
REPO_ROOT = ROOT_DIR.parent
for candidate in (REPO_ROOT, ROOT_DIR):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

from elftools.elf.elffile import ELFFile

try:
    from benchmark_catalog import load_suite
except ImportError:
    from micro.benchmark_catalog import load_suite
from corpus.analyze_bytecode import (
    SHF_EXECINSTR,
    collect_func_symbol_counts,
    is_skipped_section,
    parse_section_bytecode,
)

DEFAULT_OUTPUT = ROOT_DIR / "results" / "representativeness_report.md"
DEFAULT_CORPUS = REPO_ROOT / "corpus" / "results" / "bytecode_features.json"
DEFAULT_SUITES = (
    REPO_ROOT / "config" / "micro_pure_jit.yaml",
)

FEATURES = (
    ("insn_count", "Total insns"),
    ("branch_count", "Branch insns"),
    ("mem_ops", "Memory ops"),
    ("call_count", "Helper calls"),
    ("bpf2bpf_call_count", "BPF-to-BPF calls"),
)

BOX_FEATURES = ("insn_count", "branch_count", "mem_ops", "call_count", "bpf2bpf_call_count")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Compare micro benchmark feature coverage against the BCF corpus.")
    parser.add_argument(
        "--suite",
        action="append",
        dest="suites",
        help="Optional suite manifest path. Defaults to micro_pure_jit.",
    )
    parser.add_argument(
        "--corpus",
        default=str(DEFAULT_CORPUS),
        help="Path to corpus/results/bytecode_features.json.",
    )
    parser.add_argument(
        "--output",
        default=str(DEFAULT_OUTPUT),
        help="Markdown report output path.",
    )
    return parser.parse_args()


def percentile(sorted_values: list[int], probability: float) -> int:
    if not sorted_values:
        return 0
    if len(sorted_values) == 1:
        return sorted_values[0]
    rank = int(round((len(sorted_values) - 1) * probability))
    return sorted_values[max(0, min(rank, len(sorted_values) - 1))]


def distribution(values: list[int]) -> dict[str, int | float]:
    ordered = sorted(values)
    if not ordered:
        return {"min": 0, "median": 0, "mean": 0.0, "p90": 0, "p99": 0, "max": 0}
    return {
        "min": ordered[0],
        "median": int(statistics.median(ordered)),
        "mean": statistics.mean(ordered),
        "p90": percentile(ordered, 0.90),
        "p99": percentile(ordered, 0.99),
        "max": ordered[-1],
    }


def ratio(numerator: int, denominator: int) -> float:
    if denominator == 0:
        return 0.0
    return numerator / denominator


def format_percent(value: float) -> str:
    return f"{value * 100:.1f}%"


def load_corpus_records(path: Path) -> list[dict[str, int]]:
    raw_records = json.loads(path.read_text())
    records: list[dict[str, int]] = []
    for raw in raw_records:
        records.append(
            {
                "insn_count": int(raw["insn_count"]),
                "branch_count": int(raw["branch_count"]),
                "mem_ops": int(raw["mem_load_count"]) + int(raw["mem_store_count"]),
                "call_count": int(raw["call_count"]),
                "bpf2bpf_call_count": int(raw["bpf2bpf_call_count"]),
                "has_subprograms": 1 if raw.get("has_subprograms") else 0,
            }
        )
    return records


def analyze_object(path: Path) -> dict[str, int]:
    with path.open("rb") as handle:
        elf = ELFFile(handle)
        func_symbol_counts = collect_func_symbol_counts(elf)
        metrics = {
            "insn_count": 0,
            "branch_count": 0,
            "mem_ops": 0,
            "call_count": 0,
            "bpf2bpf_call_count": 0,
            "has_subprograms": 0,
        }
        for section_index, section in enumerate(elf.iter_sections()):
            if is_skipped_section(section.name or ""):
                continue
            if not (section.header["sh_flags"] & SHF_EXECINSTR):
                continue
            section_metrics, _ = parse_section_bytecode(section.data())
            metrics["insn_count"] += int(section_metrics["insn_count"])
            metrics["branch_count"] += int(section_metrics["branch_count"])
            metrics["mem_ops"] += int(section_metrics["mem_load_count"]) + int(section_metrics["mem_store_count"])
            metrics["call_count"] += int(section_metrics["call_count"])
            metrics["bpf2bpf_call_count"] += int(section_metrics["bpf2bpf_call_count"])
            if func_symbol_counts.get(section_index, 0) > 1:
                metrics["has_subprograms"] = 1
    return metrics


def load_suite_records(manifest_path: Path) -> tuple[str, list[dict[str, object]]]:
    suite = load_suite(manifest_path)
    records: list[dict[str, object]] = []
    for benchmark in suite.benchmarks.values():
        object_path = benchmark.program_object
        if not object_path.exists():
            raise FileNotFoundError(f"benchmark object missing: {object_path}")
        metrics = analyze_object(object_path)
        records.append(
            {
                "name": benchmark.name,
                "category": benchmark.category,
                "family": benchmark.family or "-",
                **metrics,
            }
        )
    return suite.manifest_path.stem, records


def feature_range(records: list[dict[str, object]], feature: str) -> tuple[int, int]:
    values = [int(record[feature]) for record in records]
    return min(values), max(values)


def within_range(records: list[dict[str, int]], feature: str, lower: int, upper: int) -> float:
    if not records:
        return 0.0
    matched = sum(1 for record in records if lower <= record[feature] <= upper)
    return ratio(matched, len(records))


def within_box(records: list[dict[str, int]], bounds: dict[str, tuple[int, int]]) -> float:
    if not records:
        return 0.0
    matched = 0
    for record in records:
        if all(bounds[feature][0] <= record[feature] <= bounds[feature][1] for feature in BOX_FEATURES):
            matched += 1
    return ratio(matched, len(records))


def category_counts(records: list[dict[str, object]]) -> dict[str, int]:
    counts: dict[str, int] = {}
    for record in records:
        category = str(record["category"])
        counts[category] = counts.get(category, 0) + 1
    return counts


def render_report(
    suite_records: dict[str, list[dict[str, object]]],
    corpus_records: list[dict[str, int]],
    suite_paths: list[Path],
    corpus_path: Path,
) -> str:
    all_suite_records = [record for records in suite_records.values() for record in records]
    corpus_distributions = {
        feature: distribution([record[feature] for record in corpus_records])
        for feature, _ in FEATURES
    }

    lines = [
        "# Representativeness Analysis",
        "",
        f"- Suites: {', '.join(f'`{path}`' for path in suite_paths)}",
        f"- Corpus: `{corpus_path}`",
        f"- Corpus programs analyzed: {len(corpus_records)}",
        "",
        "## Suite Inventory",
        "",
        "| Scope | Benchmarks | Category mix |",
        "| --- | ---: | --- |",
    ]

    for scope, records in (*suite_records.items(), ("combined", all_suite_records)):
        mix = ", ".join(f"{category}:{count}" for category, count in sorted(category_counts(records).items()))
        lines.append(f"| {scope} | {len(records)} | {mix} |")

    lines.extend(
        [
            "",
            "## Static Feature Ranges",
            "",
            "| Scope | Feature | Corpus median | Corpus p90 | Corpus p99 | Suite max |",
            "| --- | --- | ---: | ---: | ---: | ---: |",
        ]
    )

    for scope, records in (*suite_records.items(), ("combined", all_suite_records)):
        for feature, label in FEATURES:
            corpus_stats = corpus_distributions[feature]
            suite_max = max(int(record[feature]) for record in records)
            lines.append(
                f"| {scope} | {label} | {corpus_stats['median']} | {corpus_stats['p90']} | "
                f"{corpus_stats['p99']} | {suite_max} |"
            )

    lines.extend(
        [
            "",
            "## Corpus Coverage",
            "",
            "| Scope | % corpus in insn range | % corpus in helper-call range | % corpus in bpf2bpf range | % corpus inside 5D feature box |",
            "| --- | ---: | ---: | ---: | ---: |",
        ]
    )

    for scope, records in (*suite_records.items(), ("combined", all_suite_records)):
        bounds = {feature: feature_range(records, feature) for feature, _ in FEATURES}
        lines.append(
            f"| {scope} | "
            f"{format_percent(within_range(corpus_records, 'insn_count', *bounds['insn_count']))} | "
            f"{format_percent(within_range(corpus_records, 'call_count', *bounds['call_count']))} | "
            f"{format_percent(within_range(corpus_records, 'bpf2bpf_call_count', *bounds['bpf2bpf_call_count']))} | "
            f"{format_percent(within_box(corpus_records, bounds))} |"
        )

    combined_bounds = {feature: feature_range(all_suite_records, feature) for feature, _ in FEATURES}
    corpus_subprogram_share = ratio(sum(record["has_subprograms"] for record in corpus_records), len(corpus_records))
    suite_subprogram_share = ratio(sum(int(record["has_subprograms"]) for record in all_suite_records), len(all_suite_records))
    lines.extend(
        [
            "",
            "## Remaining Gaps",
            "",
            (
                f"- Program scale: combined suite now spans `{combined_bounds['insn_count'][0]}..{combined_bounds['insn_count'][1]}` "
                f"BPF insns, while the BCF median is `{corpus_distributions['insn_count']['median']}` and p90 is "
                f"`{corpus_distributions['insn_count']['p90']}`."
            ),
            (
                f"- Call coverage: combined suite reaches `{combined_bounds['call_count'][1]}` static helper calls, "
                f"which covers {format_percent(within_range(corpus_records, 'call_count', *combined_bounds['call_count']))} "
                "of the corpus by that feature alone."
            ),
            (
                f"- Local subprogram gap: `{format_percent(corpus_subprogram_share)}` of corpus programs contain multiple "
                f"functions, while the current benchmark suite contributes `{format_percent(suite_subprogram_share)}` "
                "such programs because llvmbpf still lacks local-call loader support."
            ),
            (
                f"- Multi-dimensional realism: only {format_percent(within_box(corpus_records, combined_bounds))} "
                "of corpus programs fall inside the combined 5D feature box, so macro-corpus validation remains mandatory."
            ),
        ]
    )

    return "\n".join(lines) + "\n"


def main() -> int:
    args = parse_args()
    suite_paths = [Path(path).resolve() for path in (args.suites or [str(path) for path in DEFAULT_SUITES])]
    corpus_path = Path(args.corpus).resolve()
    output_path = Path(args.output).resolve()

    corpus_records = load_corpus_records(corpus_path)
    suite_records: dict[str, list[dict[str, object]]] = {}
    for suite_path in suite_paths:
        suite_name, records = load_suite_records(suite_path)
        suite_records[suite_name] = records

    report = render_report(suite_records, corpus_records, suite_paths, corpus_path)
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(report)
    print(report, end="")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
