#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import statistics
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Iterable


REPO_ROOT = Path(__file__).resolve().parents[2]
DEFAULT_CHARACTERIZATION_JSON = (
    REPO_ROOT / "micro" / "results" / "pure_jit_authoritative_strict_20260312.json"
)
DEFAULT_RECOMPILE_JSON = REPO_ROOT / "micro" / "results" / "kernel_recompile_strict_20260312.json"
DEFAULT_OUTPUT_MD = REPO_ROOT / "docs" / "tmp" / "characterization-gap-decomposition.md"

GAP_BUCKETS = (
    (">2x", lambda value: value > 2.0),
    ("1.5-2x", lambda value: 1.5 <= value <= 2.0),
    ("1.2-1.5x", lambda value: 1.2 <= value < 1.5),
    ("1.0-1.2x", lambda value: 1.0 <= value < 1.2),
    ("<1.0x", lambda value: value < 1.0),
)

LLVM_PASS_FAMILIES = {
    "branch-density",
    "branch-fanout",
    "code-clone",
    "dep-chain",
    "large-mixed",
    "nested-loop",
    "parser",
    "popcount",
    "reduction",
    "search",
    "strength-reduce",
    "switch-dispatch",
}

PROLOGUE_RUNTIME_NAMES = {
    "simple",
    "simple_packet",
    "memory_pair_sum",
    "load_native_u64",
    "mega_basic_block_2048",
    "struct_field_cluster",
}

SPECIAL_MISSING_NAMES = [
    "binary_search",
    "switch_dispatch",
    "branch_dense",
    "bpf_call_chain",
    "bounds_ladder",
    "mixed_alu_mem",
]


@dataclass
class ArtifactData:
    path: Path
    source: str
    payload: dict[str, Any]


@dataclass
class CombinedRow:
    name: str
    family: str
    llvmbpf_ns: float
    kernel_stock_char_ns: float
    kernel_stock_recompile_ns: float | None
    kernel_recompile_ns: float | None
    status: str
    applied: bool
    total_sites: int
    failure_reasons: list[str]
    characterization_gap: float
    bpfrejit_recovery: float | None
    remaining_gap_raw: float | None
    remaining_gap_implied: float | None
    recovery_fraction: float | None
    kernel_stock_alignment: float | None

    @property
    def valid_recompile(self) -> bool:
        return (
            self.status == "ok"
            and self.kernel_stock_recompile_ns is not None
            and self.kernel_stock_recompile_ns > 0.0
            and self.kernel_recompile_ns is not None
            and self.kernel_recompile_ns > 0.0
        )

    @property
    def char_kernel_ge_100(self) -> bool:
        return self.kernel_stock_char_ns >= 100.0

    @property
    def both_char_runtimes_ge_100(self) -> bool:
        return self.kernel_stock_char_ns >= 100.0 and self.llvmbpf_ns >= 100.0

    @property
    def noteworthy_gap(self) -> bool:
        return self.characterization_gap >= 1.2


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Decompose the strict characterization gap with strict recompile data.")
    parser.add_argument("--characterization-json", type=Path, default=DEFAULT_CHARACTERIZATION_JSON)
    parser.add_argument("--recompile-json", type=Path, default=DEFAULT_RECOMPILE_JSON)
    parser.add_argument("--output", type=Path, default=DEFAULT_OUTPUT_MD)
    return parser.parse_args(argv)


def read_json_with_git_fallback(path: Path) -> ArtifactData:
    if path.exists():
        return ArtifactData(path=path, source="worktree", payload=json.loads(path.read_text()))

    relpath = path.relative_to(REPO_ROOT)
    completed = subprocess.run(
        ["git", "show", f"HEAD:{relpath.as_posix()}"],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
        check=False,
    )
    if completed.returncode == 0 and completed.stdout.strip():
        return ArtifactData(path=path, source="git:HEAD", payload=json.loads(completed.stdout))

    raise FileNotFoundError(f"unable to read {path} from worktree or git HEAD")


def geomean(values: Iterable[float]) -> float | None:
    positive = [value for value in values if value is not None and value > 0.0]
    if not positive:
        return None
    return math.exp(statistics.mean(math.log(value) for value in positive))


def arithmetic_mean(values: Iterable[float]) -> float | None:
    present = [value for value in values if value is not None]
    if not present:
        return None
    return statistics.mean(present)


def median(values: Iterable[float]) -> float | None:
    present = [value for value in values if value is not None]
    if not present:
        return None
    return statistics.median(present)


def fmt_ratio(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.3f}x"


def fmt_percent(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value * 100:.1f}%"


def fmt_fraction(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.3f}"


def fmt_ns(value: float | None) -> str:
    if value is None:
        return "n/a"
    if value >= 1000.0:
        return f"{value / 1000.0:.3f} us"
    if float(value).is_integer():
        return f"{int(value)} ns"
    return f"{value:.1f} ns"


def markdown_table(headers: list[str], rows: list[list[str]]) -> str:
    separator = ["---"] * len(headers)
    rendered = ["| " + " | ".join(headers) + " |", "| " + " | ".join(separator) + " |"]
    rendered.extend("| " + " | ".join(row) + " |" for row in rows)
    return "\n".join(rendered)


def load_characterization_rows(payload: dict[str, Any]) -> dict[str, dict[str, Any]]:
    rows: dict[str, dict[str, Any]] = {}
    for benchmark in payload["benchmarks"]:
        runs = {run["runtime"]: run for run in benchmark["runs"]}
        llvmbpf = runs["llvmbpf"]["exec_ns"]["median"]
        kernel = runs["kernel"]["exec_ns"]["median"]
        rows[benchmark["name"]] = {
            "family": benchmark["family"],
            "llvmbpf_ns": float(llvmbpf),
            "kernel_stock_char_ns": float(kernel),
        }
    return rows


def load_recompile_rows(payload: dict[str, Any]) -> dict[str, dict[str, Any]]:
    rows: dict[str, dict[str, Any]] = {}
    for benchmark in payload["benchmarks"]:
        runs = {run["runtime"]: run for run in benchmark["runs"]}
        stock = runs["kernel"]
        recompile = runs["kernel-recompile"]
        rows[benchmark["name"]] = {
            "family": benchmark["family"],
            "kernel_stock_recompile_ns": (
                float(stock["exec_ns"]["median"]) if stock["exec_ns"].get("median") is not None else None
            ),
            "kernel_recompile_ns": (
                float(recompile["exec_ns"]["median"])
                if recompile["exec_ns"].get("median") is not None
                else None
            ),
            "status": str(recompile.get("status", "unknown")),
            "applied": bool(recompile.get("recompile_observation", {}).get("applied", False)),
            "total_sites": int(recompile.get("recompile_observation", {}).get("total_sites", 0) or 0),
            "failure_reasons": normalize_failure_reasons(recompile.get("failures", [])),
        }
    return rows


def normalize_failure_reasons(failures: list[dict[str, Any]]) -> list[str]:
    reasons: list[str] = []
    for failure in failures:
        reason = str(failure.get("reason") or "").strip()
        if reason:
            reasons.append(reason)
    return sorted(set(reasons))


def combine_rows(
    characterization_rows: dict[str, dict[str, Any]],
    recompile_rows: dict[str, dict[str, Any]],
) -> list[CombinedRow]:
    combined: list[CombinedRow] = []
    for name in sorted(characterization_rows):
        char = characterization_rows[name]
        recomp = recompile_rows.get(name)
        if recomp is None:
            raise KeyError(f"benchmark {name} missing from recompile dataset")

        characterization_gap = char["kernel_stock_char_ns"] / char["llvmbpf_ns"]
        recovery = None
        remaining_raw = None
        remaining_implied = None
        recovery_fraction = None
        stock_alignment = None

        if recomp["kernel_stock_recompile_ns"] is not None:
            stock_alignment = recomp["kernel_stock_recompile_ns"] / char["kernel_stock_char_ns"]

        if (
            recomp["status"] == "ok"
            and recomp["kernel_stock_recompile_ns"] is not None
            and recomp["kernel_recompile_ns"] is not None
            and recomp["kernel_stock_recompile_ns"] > 0.0
            and recomp["kernel_recompile_ns"] > 0.0
        ):
            recovery = recomp["kernel_stock_recompile_ns"] / recomp["kernel_recompile_ns"]
            remaining_raw = recomp["kernel_recompile_ns"] / char["llvmbpf_ns"]
            remaining_implied = characterization_gap / recovery
            denominator = characterization_gap - 1.0
            if abs(denominator) > 1e-12:
                recovery_fraction = (recovery - 1.0) / denominator

        combined.append(
            CombinedRow(
                name=name,
                family=char["family"],
                llvmbpf_ns=char["llvmbpf_ns"],
                kernel_stock_char_ns=char["kernel_stock_char_ns"],
                kernel_stock_recompile_ns=recomp["kernel_stock_recompile_ns"],
                kernel_recompile_ns=recomp["kernel_recompile_ns"],
                status=recomp["status"],
                applied=recomp["applied"],
                total_sites=recomp["total_sites"],
                failure_reasons=recomp["failure_reasons"],
                characterization_gap=characterization_gap,
                bpfrejit_recovery=recovery,
                remaining_gap_raw=remaining_raw,
                remaining_gap_implied=remaining_implied,
                recovery_fraction=recovery_fraction,
                kernel_stock_alignment=stock_alignment,
            )
        )
    return combined


def bucket_for_gap(value: float) -> str:
    for label, predicate in GAP_BUCKETS:
        if predicate(value):
            return label
    raise AssertionError(f"unbucketed gap value: {value}")


def overall_recovery_fraction(rows: Iterable[CombinedRow]) -> float | None:
    present = [row for row in rows if row.valid_recompile]
    gap_gm = geomean(row.characterization_gap for row in present)
    recovery_gm = geomean(row.bpfrejit_recovery for row in present)
    if gap_gm is None or recovery_gm is None:
        return None
    denominator = gap_gm - 1.0
    if abs(denominator) <= 1e-12:
        return None
    return (recovery_gm - 1.0) / denominator


def top_rows(
    rows: Iterable[CombinedRow],
    *,
    predicate,
    key,
    reverse: bool,
    limit: int,
) -> list[CombinedRow]:
    filtered = [row for row in rows if predicate(row)]
    return sorted(filtered, key=key, reverse=reverse)[:limit]


def summarized_examples(rows: list[CombinedRow], limit: int = 3) -> str:
    if not rows:
        return "-"
    return ", ".join(row.name for row in rows[:limit])


def manual_source_groups(rows: list[CombinedRow]) -> dict[str, list[CombinedRow]]:
    backend_demonstrated = [
        row
        for row in rows
        if row.valid_recompile
        and row.char_kernel_ge_100
        and row.noteworthy_gap
        and row.applied
        and row.recovery_fraction is not None
        and row.recovery_fraction >= 0.25
    ]

    backend_unrecovered = [
        row
        for row in rows
        if row.noteworthy_gap
        and (
            (
                row.valid_recompile
                and row.char_kernel_ge_100
                and row.total_sites > 0
                and row.recovery_fraction is not None
                and row.recovery_fraction <= 0.05
            )
            or (
                not row.valid_recompile
                and row.total_sites > 0
            )
        )
    ]

    llvm_pass_likely = [
        row
        for row in rows
        if row.noteworthy_gap
        and row.family in LLVM_PASS_FAMILIES
        and (
            (row.valid_recompile and row.recovery_fraction is not None and row.recovery_fraction < 0.10)
            or not row.valid_recompile
        )
    ]

    overhead_likely = [
        row
        for row in rows
        if row.name in PROLOGUE_RUNTIME_NAMES
        or (
            row.noteworthy_gap
            and not row.applied
            and row.total_sites == 0
        )
    ]

    return {
        "backend_demonstrated": unique_rows(backend_demonstrated),
        "backend_unrecovered": unique_rows(backend_unrecovered),
        "llvm_pass_likely": unique_rows(llvm_pass_likely),
        "overhead_likely": unique_rows(overhead_likely),
    }


def unique_rows(rows: list[CombinedRow]) -> list[CombinedRow]:
    seen: set[str] = set()
    deduped: list[CombinedRow] = []
    for row in rows:
        if row.name in seen:
            continue
        seen.add(row.name)
        deduped.append(row)
    return sorted(deduped, key=lambda row: row.characterization_gap, reverse=True)


def group_summary(rows: list[CombinedRow]) -> dict[str, str]:
    valid = [row for row in rows if row.valid_recompile]
    return {
        "count": str(len(rows)),
        "valid": str(len(valid)),
        "char_gap": fmt_ratio(geomean(row.characterization_gap for row in rows)),
        "recovery": fmt_ratio(geomean(row.bpfrejit_recovery for row in valid)),
        "remaining": fmt_ratio(geomean(row.remaining_gap_implied for row in valid)),
        "examples": summarized_examples(rows),
    }


def build_markdown(
    *,
    characterization_artifact: ArtifactData,
    recompile_artifact: ArtifactData,
    rows: list[CombinedRow],
) -> str:
    valid_rows = [row for row in rows if row.valid_recompile]
    invalid_rows = [row for row in rows if not row.valid_recompile]
    char_ge_100_valid = [row for row in valid_rows if row.char_kernel_ge_100]
    both_ge_100_valid = [row for row in valid_rows if row.both_char_runtimes_ge_100]

    overall_rows = [
        [
            "Characterization gap geomean (all 56)",
            fmt_ratio(geomean(row.characterization_gap for row in rows)),
            "kernel_stock(char) / llvmbpf",
        ],
        [
            "Characterization gap geomean (valid recompile subset)",
            fmt_ratio(geomean(row.characterization_gap for row in valid_rows)),
            "same 50-benchmark subset used for recovery",
        ],
        [
            "BpfReJIT recovery geomean (valid 50)",
            fmt_ratio(geomean(row.bpfrejit_recovery for row in valid_rows)),
            "kernel_stock(recompile) / kernel_recompile",
        ],
        [
            "Remaining gap geomean, raw (valid 50)",
            fmt_ratio(geomean(row.remaining_gap_raw for row in valid_rows)),
            "kernel_recompile / llvmbpf across two separate strict runs",
        ],
        [
            "Remaining gap geomean, implied (valid 50)",
            fmt_ratio(geomean(row.remaining_gap_implied for row in valid_rows)),
            "characterization_gap / recovery; clean decomposition metric",
        ],
        [
            "Recovery fraction (overall, valid 50)",
            fmt_percent(overall_recovery_fraction(valid_rows)),
            "(recovery_geomean - 1) / (gap_geomean - 1)",
        ],
        [
            "Stock alignment geomean (all 56)",
            fmt_ratio(geomean(row.kernel_stock_alignment for row in rows)),
            "kernel_stock(recompile) / kernel_stock(characterization)",
        ],
        [
            "Stock alignment geomean (characterization stock >=100ns)",
            fmt_ratio(geomean(row.kernel_stock_alignment for row in rows if row.char_kernel_ge_100)),
            "sub-100ns cases removed",
        ],
        [
            "Raw remaining gap geomean (characterization stock >=100ns)",
            fmt_ratio(geomean(row.remaining_gap_raw for row in char_ge_100_valid)),
            "raw vs implied largely agree once sub-100ns cases are removed",
        ],
        [
            "Raw remaining gap geomean (both characterization runtimes >=100ns)",
            fmt_ratio(geomean(row.remaining_gap_raw for row in both_ge_100_valid)),
            "33-benchmark cleaner timing subset",
        ],
    ]

    bucket_rows: list[list[str]] = []
    for bucket_label, _ in GAP_BUCKETS:
        bucket_all = [row for row in rows if bucket_for_gap(row.characterization_gap) == bucket_label]
        bucket_valid = [row for row in bucket_all if row.valid_recompile]
        bucket_rows.append(
            [
                bucket_label,
                str(len(bucket_all)),
                str(len(bucket_valid)),
                fmt_ratio(geomean(row.characterization_gap for row in bucket_all)),
                fmt_ratio(geomean(row.bpfrejit_recovery for row in bucket_valid)),
                fmt_ratio(geomean(row.remaining_gap_raw for row in bucket_valid)),
                fmt_ratio(geomean(row.remaining_gap_implied for row in bucket_valid)),
                fmt_percent(overall_recovery_fraction(bucket_valid)),
                summarized_examples(sorted(bucket_all, key=lambda row: row.characterization_gap, reverse=True)),
            ]
        )

    high_recovery_rows = top_rows(
        rows,
        predicate=lambda row: (
            row.valid_recompile
            and row.char_kernel_ge_100
            and row.noteworthy_gap
            and row.applied
            and row.recovery_fraction is not None
        ),
        key=lambda row: row.recovery_fraction,
        reverse=True,
        limit=10,
    )
    no_recovery_rows = top_rows(
        rows,
        predicate=lambda row: (
            row.valid_recompile
            and row.char_kernel_ge_100
            and row.noteworthy_gap
            and row.recovery_fraction is not None
        ),
        key=lambda row: row.recovery_fraction,
        reverse=False,
        limit=15,
    )

    invalid_focus_rows = [
        row for row in rows if row.name in SPECIAL_MISSING_NAMES
    ]

    source_groups = manual_source_groups(rows)
    source_rows = []
    source_notes = {
        "backend_demonstrated": "already showing real backend-lowering recovery",
        "backend_unrecovered": "backend-like headroom exists, but blind all-apply is not recovering it yet",
        "llvm_pass_likely": "likely dominated by LLVM InstCombine/SimplifyCFG style IR cleanup",
        "overhead_likely": "likely fixed overhead, function-boundary cost, or non-site runtime effects",
    }
    for key in ["backend_demonstrated", "backend_unrecovered", "llvm_pass_likely", "overhead_likely"]:
        summary = group_summary(source_groups[key])
        source_rows.append(
            [
                key,
                summary["count"],
                summary["valid"],
                summary["char_gap"],
                summary["recovery"],
                summary["remaining"],
                summary["examples"],
                source_notes[key],
            ]
        )

    comparison_rows = []
    for row in sorted(rows, key=lambda item: item.characterization_gap, reverse=True):
        note = row.status
        if row.failure_reasons:
            note += " (" + ",".join(row.failure_reasons) + ")"
        if row.valid_recompile and not row.applied and row.total_sites == 0:
            note = "ok / no-sites"
        comparison_rows.append(
            [
                row.name,
                row.family,
                fmt_ns(row.llvmbpf_ns),
                fmt_ns(row.kernel_stock_char_ns),
                fmt_ns(row.kernel_recompile_ns),
                fmt_ratio(row.characterization_gap),
                fmt_ratio(row.bpfrejit_recovery),
                fmt_ratio(row.remaining_gap_raw),
                fmt_ratio(row.remaining_gap_implied),
                fmt_fraction(row.recovery_fraction),
                str(row.total_sites),
                note,
            ]
        )

    def render_ranked_table(ranked_rows: list[CombinedRow]) -> str:
        table_rows = [
            [
                row.name,
                row.family,
                fmt_ratio(row.characterization_gap),
                fmt_ratio(row.bpfrejit_recovery),
                fmt_ratio(row.remaining_gap_implied),
                fmt_fraction(row.recovery_fraction),
                str(row.total_sites),
                "yes" if row.applied else "no",
                row.status,
            ]
            for row in ranked_rows
        ]
        return markdown_table(
            [
                "Benchmark",
                "Family",
                "Char gap",
                "Recovery",
                "Remaining implied",
                "Recovery fraction",
                "Sites",
                "Applied",
                "Status",
            ],
            table_rows,
        )

    invalid_table_rows = [
        [
            row.name,
            row.family,
            fmt_ratio(row.characterization_gap),
            str(row.total_sites),
            "yes" if row.applied else "no",
            row.status,
            ",".join(row.failure_reasons) if row.failure_reasons else "-",
            fmt_ns(row.kernel_recompile_ns),
        ]
        for row in sorted(invalid_focus_rows, key=lambda item: item.characterization_gap, reverse=True)
    ]

    lines = [
        "# Characterization Gap Decomposition",
        "",
        "## Inputs",
        "",
        f"- Characterization strict JSON: `{characterization_artifact.path}` ({characterization_artifact.source})",
        f"- Recompile strict JSON: `{recompile_artifact.path}` ({recompile_artifact.source})",
        "- Context docs: `docs/kernel-jit-optimization-plan.md`, `docs/tmp/kernel-recompile-micro-strict.md`, `docs/tmp/sub-ktime-and-strict-analysis.md`, `micro/results/pass_ablation_authoritative.md`, `micro/results/causal_isolation_analysis.md`, `docs/tmp/directive-gap-analysis.md`, `docs/tmp/optimization-beyond-isel.md`",
        "",
        "## Method Notes",
        "",
        "- `characterization gap` is `kernel_stock(characterization) / llvmbpf`; `>1.0x` means llvmbpf is faster.",
        "- `BpfReJIT recovery` is `kernel_stock(recompile) / kernel_recompile`; `>1.0x` means recompile is faster than stock in the recompile suite.",
        "- `remaining gap (raw)` is the requested `kernel_recompile / llvmbpf`, but it combines two separate strict runs: characterization is `30x1000`, recompile is `2/10/500`.",
        "- Because the two strict suites have different stock medians on sub-100ns kernels, `remaining gap (raw)` is not algebraically equal to `characterization gap / recovery` on the full 50-benchmark overlap.",
        "- `remaining gap (implied)` is therefore also reported as `characterization gap / recovery`. This is the cleaner decomposition metric for answering how much of the characterization gap the recompile result actually closes.",
        "- `recovery fraction` can be negative or exceed `1.0` on individual benchmarks. Negative means recompile widened the gap; values above `1.0` mean the local recovery exceeded the original characterization gap, usually on near-parity rows with a small denominator.",
        "- The stock-alignment rows below show the mismatch source: on all 56 benchmarks, `kernel_stock(recompile) / kernel_stock(characterization)` geomean is low, but it returns to ~1.0x after excluding sub-100ns characterization kernels.",
        "",
        "## Overall Summary",
        "",
        markdown_table(["Metric", "Value", "Notes"], overall_rows),
        "",
        "Interpretation: on the clean overlap, BpfReJIT closes only a small slice of the strict characterization gap. Using the aligned geomean formula, the recovered share is about one-twenty-fifth of the gap, leaving an implied remaining gap around `1.60x` on the valid 50-benchmark subset.",
        "",
        "## Gap Buckets",
        "",
        markdown_table(
            [
                "Bucket",
                "All",
                "Valid",
                "Char gap gm",
                "Recovery gm",
                "Remaining raw gm",
                "Remaining implied gm",
                "Overall recovery fraction",
                "Examples",
            ],
            bucket_rows,
        ),
        "",
        "Bucket takeaway: recovery is concentrated in a handful of large-gap benchmarks, but even the `>2x` bucket still retains a large implied remaining gap. The `1.0-1.2x` bucket is noisy enough that blind all-apply often regresses rather than closes the gap.",
        "",
        "## Benchmarks With Strong Recovery",
        "",
        "Filtered to valid recompile rows with characterization stock `>=100ns`, characterization gap `>=1.2x`, and at least one applied site.",
        "",
        render_ranked_table(high_recovery_rows),
        "",
        "These are the clear positive cases. The best closures are `bounds_check_heavy`, `rotate64_hash`, and `packet_redundant_bounds`; after them the recovery drops quickly into partial-gap territory rather than majority closure.",
        "",
        "## Benchmarks With No Recovery Or Regression",
        "",
        "Same filter as above, but sorted by worst recovery fraction first.",
        "",
        render_ranked_table(no_recovery_rows),
        "",
        "These rows matter more than the wins for the decomposition question. `load_byte_recompose`, `stride_load_*`, `branch_layout`, and `cmov_select` are especially important because prior characterization evidence says they are backend-heavy, yet the current blind all-apply path barely helps or actively hurts them.",
        "",
        "## Missing / Invalid Recompile Data",
        "",
        markdown_table(
            [
                "Benchmark",
                "Family",
                "Char gap",
                "Sites",
                "Applied",
                "Status",
                "Failure reason",
                "Observed recompile median",
            ],
            invalid_table_rows,
        ),
        "",
        "Important missing-data note: `binary_search`, `switch_dispatch`, `branch_dense`, and `bpf_call_chain` were site-positive but failed with `result-mismatch`; `bounds_ladder` and `mixed_alu_mem` failed with VM crashes. These six rows sit directly on the decomposition critical path, because several of them are among the larger characterization gaps.",
        "",
        "## Gap Source Discussion",
        "",
        markdown_table(
            [
                "Heuristic bucket",
                "Rows",
                "Valid",
                "Char gap gm",
                "Recovery gm",
                "Remaining implied gm",
                "Examples",
                "Reading",
            ],
            source_rows,
        ),
        "",
        "### 1. Backend lowering that BpfReJIT already demonstrably recovers",
        "",
        "- Best evidence: `rotate64_hash`, `packet_redundant_bounds`, `bounds_check_heavy`, `load_word32`, `fixed_loop_small`, `imm64_storm`.",
        "- These are the benchmarks where the current directive families actually move runtime in the right direction. The positive set is dominated by local lowering wins: rotate fusion, bounds/check simplification, and some load-width or extract-style cases.",
        "- Even here, recovery is usually partial. Only `bounds_check_heavy` clears the 50% recovery-fraction line, and that happens on a modest `1.246x` gap rather than on the largest llvmbpf wins.",
        "",
        "### 2. Backend lowering that should be recoverable, but is not recovered by the current blind path",
        "",
        "- Strong examples: `load_byte_recompose`, `stride_load_4`, `stride_load_16`, `branch_layout`, `cmov_select`, plus invalid site-positive rows `binary_search`, `switch_dispatch`, `bounds_ladder`, and `bpf_call_chain`.",
        "- This bucket matters most for #125. Prior characterization attributes the largest native-code headroom to byte-recompose (`50.7%` of surplus, `2.24x` isolated penalty in `load_byte_recompose`) and to branch/control-flow (`19.9%` of surplus). But the current recompile run does not convert that headroom into whole-benchmark closure.",
        "- The current data therefore support a sharper conclusion than \"backend lowering does not matter\": backend lowering clearly matters, but the present BpfReJIT implementation is recovering only a small, selective subset of the backend gap.",
        "",
        "### 3. Remaining gap likely dominated by LLVM passes / CFG cleanup",
        "",
        "- Likely cases: `large_mixed_500`, `large_mixed_1000`, `packet_parse`, `nested_loop_3`, `smallmul_strength_reduce`, `branch_dense`, and parts of the `code-clone` / `dep-chain` families.",
        "- Reasoning: these rows retain sizable characterization gaps while seeing little or negative recovery from backend-only recompile. That pattern matches the prior pass-ablation result that only `InstCombinePass` and `SimplifyCFGPass` materially move BPF output.",
        "- This is an inference, not a direct proof per benchmark. The evidence is: backend-only recompile does not close the gap; the repo's pass-ablation says the remaining LLVM leverage is concentrated in IR-level combination and CFG cleanup; and these families are exactly the ones where that style of simplification is plausible.",
        "",
        "### 4. Prologue / epilogue overhead and other runtime effects",
        "",
        "- Likely rows: `simple`, `simple_packet`, `memory_pair_sum`, `load_native_u64`, `mega_basic_block_2048`, and `struct_field_cluster`.",
        "- These rows have either no applied sites or zero detected sites, yet some still show noticeable characterization gaps. That points away from current directive-covered lowering and toward fixed overhead, function-boundary cost, or other non-site effects.",
        "- Caution: the current stock kernel is already on a `7.0-rc2` lineage where per-function callee-saved trimming exists upstream, so the earlier `18.5%` prologue/epilogue surplus share should be treated as historical upper-bound context, not as the exact remaining share in this strict 56-benchmark run.",
        "",
        "## Full Per-Benchmark Table",
        "",
        markdown_table(
            [
                "Benchmark",
                "Family",
                "llvmbpf",
                "kernel stock (char)",
                "kernel recompile",
                "Char gap",
                "Recovery",
                "Remaining raw",
                "Remaining implied",
                "Recovery fraction",
                "Sites",
                "Note",
            ],
            comparison_rows,
        ),
        "",
        "## Bottom Line",
        "",
        "- Strict characterization says llvmbpf is about `1.64x` faster than stock kernel geomean on the 56-benchmark suite.",
        "- Strict recompile says blind all-apply BpfReJIT recovers only about `1.028x` geomean on the valid 50-benchmark overlap, which translates to roughly `4.3%` of the strict characterization gap.",
        "- The dominant unresolved story is not \"BpfReJIT proved backend lowering irrelevant\". It is \"backend-only headroom is real, but the current directive set and blind policy recover only a small fraction of it, while LLVM pass cleanup and uncovered function-boundary/runtime effects still account for most of the remaining gap.\"",
    ]

    return "\n".join(lines) + "\n"


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    characterization_artifact = read_json_with_git_fallback(args.characterization_json.resolve())
    recompile_artifact = read_json_with_git_fallback(args.recompile_json.resolve())

    characterization_rows = load_characterization_rows(characterization_artifact.payload)
    recompile_rows = load_recompile_rows(recompile_artifact.payload)
    rows = combine_rows(characterization_rows, recompile_rows)

    output = args.output.resolve()
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(
        build_markdown(
            characterization_artifact=characterization_artifact,
            recompile_artifact=recompile_artifact,
            rows=rows,
        )
    )
    print(output)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
