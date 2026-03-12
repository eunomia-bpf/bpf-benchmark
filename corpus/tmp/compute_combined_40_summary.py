#!/usr/bin/env python3
from __future__ import annotations

import math
import sys
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path

import numpy as np


def find_repo_root() -> Path:
    for candidate in Path(__file__).resolve().parents:
        if (candidate / "micro").is_dir() and (candidate / "corpus").is_dir():
            return candidate
    raise RuntimeError("unable to locate repository root from script path")


SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = find_repo_root()
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

from micro.archive.scripts.analyze_statistics import (
    BOOTSTRAP_ITERATIONS,
    DEFAULT_SEED,
    apply_benjamini_hochberg_correction,
    build_runtime_rows,
    build_suite_summary,
    geometric_mean,
    load_results,
)


MICRO_RESULTS_DIR = REPO_ROOT / "micro" / "results"
CORPUS_RESULTS_DIR = REPO_ROOT / "corpus" / "results"

PURE_JIT_LATEST_PATH = MICRO_RESULTS_DIR / "pure_jit.latest.json"
PURE_JIT_AUTHORITATIVE_PATH = next(
    iter(sorted(MICRO_RESULTS_DIR.glob("pure_jit_authoritative_*.json"))),
    MICRO_RESULTS_DIR / "pure_jit.latest.json",
)
NEW_PURE_JIT_PATH = MICRO_RESULTS_DIR / "new_benchmarks_authoritative.json"
RUNTIME_AUTHORITATIVE_PATH = MICRO_RESULTS_DIR / "runtime_authoritative.json"
NEW_RUNTIME_PATH = MICRO_RESULTS_DIR / "new_runtime_authoritative.json"
OUTPUT_PATH = CORPUS_RESULTS_DIR / "combined_40_summary.md"

EXPECTED_ORIGINAL_PURE_JIT_COUNT = 31
EXPECTED_NEW_PURE_JIT_COUNT = 9
EXPECTED_NEW_RUNTIME_COUNT = 1


@dataclass(frozen=True)
class ResultSource:
    path: Path
    results: dict[str, object]
    benchmark_count: int

    @property
    def generated_at(self) -> str:
        return str(self.results.get("generated_at", "unknown"))


def load_source(path: Path) -> ResultSource:
    results = load_results(path)
    benchmarks = results.get("benchmarks", [])
    if not isinstance(benchmarks, list):
        raise ValueError(f"{path} does not contain a benchmark list")
    return ResultSource(path=path, results=results, benchmark_count=len(benchmarks))


def choose_original_pure_jit_source() -> tuple[ResultSource, ResultSource | None, str]:
    latest_source = load_source(PURE_JIT_LATEST_PATH) if PURE_JIT_LATEST_PATH.exists() else None

    if PURE_JIT_AUTHORITATIVE_PATH.exists():
        authoritative_source = load_source(PURE_JIT_AUTHORITATIVE_PATH)
        note = (
            f"Selected `{PURE_JIT_AUTHORITATIVE_PATH.relative_to(REPO_ROOT)}` as the original pure-JIT source "
            f"because it exists and contains {authoritative_source.benchmark_count} benchmarks."
        )
        return authoritative_source, latest_source, note

    if latest_source is not None and latest_source.benchmark_count == EXPECTED_ORIGINAL_PURE_JIT_COUNT:
        note = (
            f"Fell back to `{PURE_JIT_LATEST_PATH.relative_to(REPO_ROOT)}` because "
            f"`{PURE_JIT_AUTHORITATIVE_PATH.relative_to(REPO_ROOT)}` is missing."
        )
        return latest_source, latest_source, note

    raise FileNotFoundError(
        "Unable to resolve the original pure-JIT benchmark source: "
        f"`{PURE_JIT_AUTHORITATIVE_PATH}` is missing and `{PURE_JIT_LATEST_PATH}` does not contain "
        f"{EXPECTED_ORIGINAL_PURE_JIT_COUNT} benchmarks."
    )


def combine_results(suite_name: str, sources: list[ResultSource]) -> dict[str, object]:
    combined_benchmarks: list[dict[str, object]] = []
    seen_names: set[str] = set()

    for source in sources:
        for benchmark in source.results.get("benchmarks", []):
            benchmark_name = str(benchmark.get("name", "<unknown>"))
            if benchmark_name in seen_names:
                raise ValueError(f"Duplicate benchmark name across combined sources: {benchmark_name}")
            seen_names.add(benchmark_name)
            combined_benchmarks.append(benchmark)

    return {
        "suite": suite_name,
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "benchmarks": combined_benchmarks,
        "combined_from": [str(source.path.relative_to(REPO_ROOT)) for source in sources],
    }


def build_exec_summary(results: dict[str, object]) -> tuple[list[dict[str, object]], dict[str, object]]:
    rng = np.random.default_rng(DEFAULT_SEED)
    _, comparison_rows = build_runtime_rows(results, BOOTSTRAP_ITERATIONS, rng, "exec_ns")
    apply_benjamini_hochberg_correction(comparison_rows)
    suite_summary = build_suite_summary(comparison_rows, BOOTSTRAP_ITERATIONS, rng, "exec_ns")
    return comparison_rows, suite_summary


def classify_ratio(ratio: float, tolerance: float = 1e-12) -> str:
    if not math.isfinite(ratio):
        return "n/a"
    if math.isclose(ratio, 1.0, rel_tol=0.0, abs_tol=tolerance):
        return "tie"
    return "llvmbpf" if ratio < 1.0 else "kernel"


def count_wins(rows: list[dict[str, object]], key: str) -> dict[str, int]:
    counts = {"llvmbpf": 0, "kernel": 0, "tie": 0}
    for row in rows:
        ratio = float(row[key])
        counts[classify_ratio(ratio)] += 1
    return counts


def format_ratio(value: float | None) -> str:
    if value is None or not math.isfinite(value):
        return "n/a"
    return f"{value:.3f}x"


def format_count(value: int, total: int) -> str:
    return f"{value} / {total}"


def format_path(path: Path) -> str:
    return str(path.relative_to(REPO_ROOT))


def build_pure_jit_detail_rows(rows: list[dict[str, object]]) -> list[str]:
    lines = [
        "## Pure-JIT Benchmark Detail",
        "",
        "| Benchmark | Exec ratio (L/K) | Code-size ratio (L/K) | Exec winner | Smaller code | BH-adjusted paired Wilcoxon p | Significant | Notes |",
        "| --- | ---: | ---: | --- | --- | ---: | --- | --- |",
    ]

    for row in rows:
        exec_winner = classify_ratio(float(row["exec_ratio"]))
        code_winner = classify_ratio(float(row["code_size_ratio"]))
        smaller_code = "llvmbpf" if code_winner == "llvmbpf" else ("kernel" if code_winner == "kernel" else "tie")
        adjusted_pvalue = row.get("paired_wilcoxon_pvalue_bh", math.nan)
        notes: list[str] = []
        if row.get("notes"):
            notes.append(str(row["notes"]))
        elif row.get("kernel_exec_below_resolution"):
            notes.append("kernel exec < 100ns")
        lines.append(
            "| "
            f"{row['benchmark']} | "
            f"{format_ratio(float(row['exec_ratio']))} | "
            f"{format_ratio(float(row['code_size_ratio']))} | "
            f"{exec_winner} | "
            f"{smaller_code} | "
            f"{adjusted_pvalue:.4g} | "
            f"{'Yes' if row.get('significant') else 'No'} | "
            f"{'; '.join(dict.fromkeys(notes))} |"
        )

    lines.append("")
    return lines


def build_runtime_detail_rows(rows: list[dict[str, object]]) -> list[str]:
    lines = [
        "## Runtime Benchmark Detail",
        "",
        "| Benchmark | Exec ratio (L/K) | Exec winner | BH-adjusted paired Wilcoxon p | Significant | Notes |",
        "| --- | ---: | --- | ---: | --- | --- |",
    ]

    for row in rows:
        adjusted_pvalue = row.get("paired_wilcoxon_pvalue_bh", math.nan)
        notes = str(row.get("notes") or ("kernel exec < 100ns" if row.get("kernel_exec_below_resolution") else ""))
        lines.append(
            "| "
            f"{row['benchmark']} | "
            f"{format_ratio(float(row['exec_ratio']))} | "
            f"{classify_ratio(float(row['exec_ratio']))} | "
            f"{adjusted_pvalue:.4g} | "
            f"{'Yes' if row.get('significant') else 'No'} | "
            f"{notes} |"
        )

    lines.append("")
    return lines


def render_summary(
    original_pure_jit_source: ResultSource,
    pure_jit_latest_source: ResultSource | None,
    new_pure_jit_source: ResultSource,
    runtime_source: ResultSource,
    new_runtime_source: ResultSource,
    source_note: str,
    pure_jit_rows: list[dict[str, object]],
    pure_jit_summary: dict[str, object],
    pure_jit_code_geomean: float,
    runtime_rows: list[dict[str, object]],
    runtime_summary: dict[str, object],
) -> str:
    pure_jit_total = len(pure_jit_rows)
    runtime_total = len(runtime_rows)

    pure_exec_wins = count_wins(pure_jit_rows, "exec_ratio")
    pure_code_wins = count_wins(pure_jit_rows, "code_size_ratio")
    runtime_exec_wins = count_wins(runtime_rows, "exec_ratio")

    pure_jit_non_significant = [row["benchmark"] for row in pure_jit_rows if not row.get("significant")]
    pure_jit_kernel_exec_wins = [row["benchmark"] for row in pure_jit_rows if classify_ratio(float(row["exec_ratio"])) == "kernel"]
    pure_jit_kernel_code_wins = [row["benchmark"] for row in pure_jit_rows if classify_ratio(float(row["code_size_ratio"])) == "kernel"]
    runtime_kernel_exec_wins = [row["benchmark"] for row in runtime_rows if classify_ratio(float(row["exec_ratio"])) == "kernel"]

    lines = [
        "# Combined 40 Summary",
        "",
        f"Generated at `{datetime.now(timezone.utc).isoformat()}`.",
        "",
        "## Inputs",
        "",
        f"- {source_note}",
        f"- Checked `{format_path(PURE_JIT_LATEST_PATH)}`: "
        + (
            f"{pure_jit_latest_source.benchmark_count} benchmarks; not used for the original 31."
            if pure_jit_latest_source is not None
            else "file missing."
        ),
        f"- Original pure-JIT authoritative input: `{format_path(original_pure_jit_source.path)}` "
        f"({original_pure_jit_source.benchmark_count} benchmarks; generated `{original_pure_jit_source.generated_at}`).",
        f"- New pure-JIT input: `{format_path(new_pure_jit_source.path)}` "
        f"({new_pure_jit_source.benchmark_count} benchmarks; generated `{new_pure_jit_source.generated_at}`).",
        f"- Original runtime input: `{format_path(runtime_source.path)}` "
        f"({runtime_source.benchmark_count} benchmarks; generated `{runtime_source.generated_at}`).",
        f"- New runtime input: `{format_path(new_runtime_source.path)}` "
        f"({new_runtime_source.benchmark_count} benchmark; generated `{new_runtime_source.generated_at}`).",
        "",
        "## Key Results",
        "",
        "| Scope | Benchmarks | Exec ratio geomean (L/K) | Code-size ratio geomean (L/K) | llvmbpf exec wins | kernel exec wins | llvmbpf smaller code | kernel smaller code | Significant |",
        "| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |",
        "| Combined pure-JIT | "
        f"{pure_jit_total} | "
        f"{format_ratio(float(pure_jit_summary['geometric_mean_ratio']))} | "
        f"{format_ratio(pure_jit_code_geomean)} | "
        f"{pure_exec_wins['llvmbpf']} | "
        f"{pure_exec_wins['kernel']} | "
        f"{pure_code_wins['llvmbpf']} | "
        f"{pure_code_wins['kernel']} | "
        f"{format_count(int(pure_jit_summary['significant_count']), pure_jit_total)} |",
        "| Combined runtime | "
        f"{runtime_total} | "
        f"{format_ratio(float(runtime_summary['geometric_mean_ratio']))} | "
        "n/a | "
        f"{runtime_exec_wins['llvmbpf']} | "
        f"{runtime_exec_wins['kernel']} | "
        "n/a | "
        "n/a | "
        f"{format_count(int(runtime_summary['significant_count']), runtime_total)} |",
        "",
        "## Requested Figures",
        "",
        f"1. Combined 40 pure-JIT exec ratio geomean (L/K): **{format_ratio(float(pure_jit_summary['geometric_mean_ratio']))}**",
        f"2. Combined 40 pure-JIT code-size ratio geomean (L/K): **{format_ratio(pure_jit_code_geomean)}**",
        (
            "3. Combined runtime exec ratio geomean (requested as `10+1`, "
            f"repo inputs available as `{runtime_source.benchmark_count}+{new_runtime_source.benchmark_count}={runtime_total}`): "
            f"**{format_ratio(float(runtime_summary['geometric_mean_ratio']))}**"
        ),
        (
            "4. Updated pure-JIT win/lose counts: "
            f"exec `llvmbpf {pure_exec_wins['llvmbpf']}` / `kernel {pure_exec_wins['kernel']}`; "
            f"code size `llvmbpf {pure_code_wins['llvmbpf']}` / `kernel {pure_code_wins['kernel']}`."
        ),
        (
            "5. Significant pure-JIT benchmarks (BH-adjusted paired Wilcoxon p < 0.05 from matched iteration data): "
            f"**{format_count(int(pure_jit_summary['significant_count']), pure_jit_total)}**."
        ),
        (
            f"- Additional context: excluding sub-resolution kernel timings (`<100ns`), "
            f"{pure_jit_summary['non_subresolution_significant_count']} / "
            f"{pure_jit_summary['non_subresolution_benchmark_count']} pure-JIT benchmarks remain significant."
        ),
        "",
        "## Win Sets",
        "",
        f"- Pure-JIT kernel execution wins ({len(pure_jit_kernel_exec_wins)}): {', '.join(pure_jit_kernel_exec_wins)}",
        f"- Pure-JIT kernel smaller-code wins ({len(pure_jit_kernel_code_wins)}): {', '.join(pure_jit_kernel_code_wins)}",
        f"- Pure-JIT non-significant after BH correction ({len(pure_jit_non_significant)}): {', '.join(pure_jit_non_significant)}",
        f"- Runtime kernel execution wins ({len(runtime_kernel_exec_wins)}): {', '.join(runtime_kernel_exec_wins)}",
        "",
    ]

    lines.extend(build_pure_jit_detail_rows(pure_jit_rows))
    lines.extend(build_runtime_detail_rows(runtime_rows))
    return "\n".join(lines)


def main() -> int:
    original_pure_jit_source, pure_jit_latest_source, source_note = choose_original_pure_jit_source()
    new_pure_jit_source = load_source(NEW_PURE_JIT_PATH)
    runtime_source = load_source(RUNTIME_AUTHORITATIVE_PATH)
    new_runtime_source = load_source(NEW_RUNTIME_PATH)

    if original_pure_jit_source.benchmark_count != EXPECTED_ORIGINAL_PURE_JIT_COUNT:
        raise ValueError(
            f"Expected {EXPECTED_ORIGINAL_PURE_JIT_COUNT} original pure-JIT benchmarks, "
            f"found {original_pure_jit_source.benchmark_count} in {original_pure_jit_source.path}"
        )
    if new_pure_jit_source.benchmark_count != EXPECTED_NEW_PURE_JIT_COUNT:
        raise ValueError(
            f"Expected {EXPECTED_NEW_PURE_JIT_COUNT} new pure-JIT benchmarks, "
            f"found {new_pure_jit_source.benchmark_count} in {new_pure_jit_source.path}"
        )
    if new_runtime_source.benchmark_count != EXPECTED_NEW_RUNTIME_COUNT:
        raise ValueError(
            f"Expected {EXPECTED_NEW_RUNTIME_COUNT} new runtime benchmark, "
            f"found {new_runtime_source.benchmark_count} in {new_runtime_source.path}"
        )

    combined_pure_jit = combine_results(
        "combined_pure_jit_authoritative",
        [original_pure_jit_source, new_pure_jit_source],
    )
    combined_runtime = combine_results(
        "combined_runtime_authoritative",
        [runtime_source, new_runtime_source],
    )

    pure_jit_rows, pure_jit_summary = build_exec_summary(combined_pure_jit)
    runtime_rows, runtime_summary = build_exec_summary(combined_runtime)

    pure_jit_code_geomean = geometric_mean(
        [float(row["code_size_ratio"]) for row in pure_jit_rows if math.isfinite(float(row["code_size_ratio"]))]
    )

    report = render_summary(
        original_pure_jit_source,
        pure_jit_latest_source,
        new_pure_jit_source,
        runtime_source,
        new_runtime_source,
        source_note,
        pure_jit_rows,
        pure_jit_summary,
        pure_jit_code_geomean,
        runtime_rows,
        runtime_summary,
    )
    OUTPUT_PATH.parent.mkdir(parents=True, exist_ok=True)
    OUTPUT_PATH.write_text(report)
    print(report)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
