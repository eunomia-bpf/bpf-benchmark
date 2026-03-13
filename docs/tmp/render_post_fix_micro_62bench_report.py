#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import statistics
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Any


REPO_ROOT = Path(__file__).resolve().parents[2]
DEFAULT_INPUT = REPO_ROOT / "micro" / "results" / "post_fix_micro_62bench_20260313.json"
DEFAULT_OUTPUT = REPO_ROOT / "docs" / "tmp" / "post-fix-micro-62bench-rerun.md"

NEW_BENCHMARKS = [
    "cond_select_dense",
    "rotate_dense",
    "addr_calc_stride",
    "extract_dense",
    "endian_swap_dense",
    "branch_flip_dense",
]

PREV_143 = {
    "benchmarks_total": 56,
    "valid_pairs": 56,
    "applied_pairs": 11,
    "geomean_stock_over_recompile": 1.007,
    "applied_only_geomean_stock_over_recompile": 0.986,
    "wins": 29,
    "losses": 26,
    "ties": 1,
}


@dataclass
class Row:
    name: str
    family: str
    stock_median_ns: float | None
    recompile_median_ns: float | None
    ratio: float | None
    applied: bool
    total_sites: int
    site_mix: dict[str, int]
    stock_status: str
    recompile_status: str
    policy_file: str | None
    policy_note: str | None


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Render the post-fix 62-benchmark micro rerun report.")
    parser.add_argument("--input", default=str(DEFAULT_INPUT))
    parser.add_argument("--output", default=str(DEFAULT_OUTPUT))
    return parser.parse_args()


def geometric_mean(values: list[float]) -> float | None:
    positive = [value for value in values if value > 0.0]
    if not positive:
        return None
    return math.exp(statistics.mean(math.log(value) for value in positive))


def format_ratio(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.3f}x"


def format_delta_ratio(current: float | None, baseline: float | None) -> str:
    if current is None or baseline is None or baseline == 0:
        return "n/a"
    return f"{((current / baseline) - 1.0) * 100.0:+.1f}%"


def format_delta_int(current: int | None, baseline: int | None) -> str:
    if current is None or baseline is None:
        return "n/a"
    return f"{current - baseline:+d}"


def format_ns(value: float | int | None) -> str:
    if value is None:
        return "n/a"
    value_f = float(value)
    if value_f >= 1_000_000:
        return f"{value_f / 1_000_000:.3f} ms"
    if value_f >= 1_000:
        return f"{value_f / 1_000:.3f} us"
    if abs(value_f - round(value_f)) < 1e-9:
        return f"{int(round(value_f))} ns"
    return f"{value_f:.1f} ns"


def format_site_mix(site_mix: dict[str, int]) -> str:
    parts = [f"{name}={count}" for name, count in site_mix.items() if count > 0]
    return ", ".join(parts) if parts else "none"


def ratio_status(value: float | None) -> str:
    if value is None:
        return "n/a"
    if value > 1.0:
        return "win"
    if value < 1.0:
        return "loss"
    return "tie"


def policy_site_count(policy_file: str | None) -> int | None:
    if not policy_file:
        return None
    path = Path(policy_file)
    if not path.exists():
        return None
    text = path.read_text()
    if "sites: []" in text:
        return 0
    return sum(1 for line in text.splitlines() if line.lstrip().startswith("- insn:"))


def extract_policy_note(recompile_run: dict[str, Any], policy_file: str | None) -> str | None:
    summary_line: str | None = None
    lookup_miss = False
    for sample in recompile_run.get("samples", []):
        stderr_tail = str(sample.get("stderr_tail", ""))
        if not stderr_tail:
            continue
        for line in stderr_tail.splitlines():
            if "recompile-policy:" not in line:
                continue
            message = line.split("recompile-policy:", 1)[1].strip()
            if "was not found in the live program" in message:
                lookup_miss = True
            if " kept " in f" {message} " or " selected " in f" {message} ":
                summary_line = message
        if summary_line is not None:
            break

    site_count = policy_site_count(policy_file)
    prefix = ""
    if site_count == 0:
        prefix = "policy file currently empty; "
    elif lookup_miss:
        prefix = "aggregate policy insns missed live program; "

    if summary_line is not None:
        return prefix + summary_line
    if prefix:
        return prefix.rstrip("; ")
    return None


def build_rows(results: dict[str, Any]) -> list[Row]:
    rows: list[Row] = []
    for benchmark in results["benchmarks"]:
        runs = {run["runtime"]: run for run in benchmark["runs"]}
        stock = runs.get("kernel", {})
        recompile = runs.get("kernel-recompile", {})
        stock_median = None
        recompile_median = None
        if stock.get("measurement_complete"):
            stock_median = stock.get("exec_ns", {}).get("median")
        if recompile.get("measurement_complete"):
            recompile_median = recompile.get("exec_ns", {}).get("median")

        ratio = None
        if stock_median not in (None, 0) and recompile_median not in (None, 0):
            ratio = float(stock_median) / float(recompile_median)

        obs = recompile.get("recompile_observation", {}) if isinstance(recompile, dict) else {}
        site_mix = {
            "cmov": int(obs.get("cmov_sites", 0) or 0),
            "wide": int(obs.get("wide_sites", 0) or 0),
            "rotate": int(obs.get("rotate_sites", 0) or 0),
            "lea": int(obs.get("lea_sites", 0) or 0),
            "extract": int(obs.get("bitfield_sites", 0) or 0),
            "zero_ext": int(obs.get("zero_ext_sites", 0) or 0),
            "endian": int(obs.get("endian_sites", 0) or 0),
            "branch_flip": int(obs.get("branch_flip_sites", 0) or 0),
        }
        rows.append(
            Row(
                name=str(benchmark["name"]),
                family=str(benchmark["family"]),
                stock_median_ns=stock_median,
                recompile_median_ns=recompile_median,
                ratio=ratio,
                applied=bool(obs.get("applied")),
                total_sites=int(obs.get("total_sites", 0) or 0),
                site_mix=site_mix,
                stock_status=str(stock.get("status", "missing")),
                recompile_status=str(recompile.get("status", "missing")),
                policy_file=str(benchmark.get("policy_file")) if benchmark.get("policy_file") else None,
                policy_note=extract_policy_note(recompile, str(benchmark.get("policy_file")) if benchmark.get("policy_file") else None),
            )
        )
    return rows


def summarize_rows(rows: list[Row]) -> dict[str, Any]:
    valid = [row for row in rows if row.ratio is not None]
    applied = [row for row in valid if row.applied]
    return {
        "benchmarks_total": len(rows),
        "valid_pairs": len(valid),
        "invalid_pairs": len(rows) - len(valid),
        "applied_pairs": len(applied),
        "geomean_stock_over_recompile": geometric_mean([row.ratio for row in valid if row.ratio is not None]),
        "applied_only_geomean_stock_over_recompile": geometric_mean(
            [row.ratio for row in applied if row.ratio is not None]
        ),
        "wins": sum(1 for row in valid if row.ratio is not None and row.ratio > 1.0),
        "losses": sum(1 for row in valid if row.ratio is not None and row.ratio < 1.0),
        "ties": sum(1 for row in valid if row.ratio == 1.0),
    }


def top_rows(rows: list[Row], *, reverse: bool, limit: int = 5) -> list[Row]:
    valid = [row for row in rows if row.ratio is not None]
    return sorted(valid, key=lambda row: (row.ratio, row.name), reverse=reverse)[:limit]


def render_report(results: dict[str, Any], rows: list[Row], input_path: Path) -> str:
    overall = summarize_rows(rows)
    shared_56_rows = [row for row in rows if row.name not in NEW_BENCHMARKS]
    shared_56 = summarize_rows(shared_56_rows)
    rows_by_name = {row.name: row for row in rows}
    new_rows = [rows_by_name[name] for name in NEW_BENCHMARKS if name in rows_by_name]
    new_summary = summarize_rows(new_rows)
    top_wins = top_rows(rows, reverse=True)
    top_losses = top_rows(rows, reverse=False)

    host = results.get("host", {})
    defaults = results.get("defaults", {})
    generated_at = results.get("generated_at")
    generated_date = "unknown"
    if isinstance(generated_at, str):
        try:
            generated_date = datetime.fromisoformat(generated_at.replace("Z", "+00:00")).date().isoformat()
        except ValueError:
            generated_date = generated_at

    lines = [
        "# Post-fix Micro 62-Bench Rerun",
        "",
        "## Methodology",
        "",
        f"- Date: `{generated_date}`",
        f"- Suite target: `config/micro_pure_jit.yaml` (`62` benchmarks = `56` prior + `6` new per-form isolation rows)",
        f"- JSON rows currently present: `{overall['benchmarks_total']}`",
        "- Runtime: `kernel` vs `kernel-recompile` in the framework VM",
        "- Collection mode: one benchmark per VM boot via `docs/tmp/kernel_recompile_micro_resume.py`",
        "- Guest kernel: `vendor/linux-framework/arch/x86/boot/bzImage`",
        "- Runner: `micro/build/runner/micro_exec`",
        "- Scanner: `scanner/build/bpf-jit-scanner`",
        "- `cond_select_dense` was resized from an `8192`-byte staged payload to `3328` bytes (`104` CMOV sites) before this rerun because the guest XDP `test_run` path exposes only `3512` payload bytes past the 8-byte result prefix; the original form always aborted in-kernel and could not produce a valid pair.",
        f"- Guest kernel release: `{host.get('kernel_version', 'unknown')}`",
        f"- Warmups / iterations / repeat: `{defaults.get('warmups', 'unknown')} / {defaults.get('iterations', 'unknown')} / {defaults.get('repeat', 'unknown')}`",
        f"- Output JSON: `{input_path.as_posix()}`",
        "",
        "## Headline Numbers",
        "",
        "| Metric | This rerun (62) | Shared-56 subset in this rerun | #143 post-cmov-fix (56) | Delta vs #143 |",
        "| --- | ---: | ---: | ---: | ---: |",
        "| Benchmarks total | `{current}` | `{shared}` | `{baseline}` | `{delta}` |".format(
            current=overall["benchmarks_total"],
            shared=shared_56["benchmarks_total"],
            baseline=PREV_143["benchmarks_total"],
            delta=format_delta_int(shared_56["benchmarks_total"], PREV_143["benchmarks_total"]),
        ),
        "| Valid pairs | `{current}` | `{shared}` | `{baseline}` | `{delta}` |".format(
            current=overall["valid_pairs"],
            shared=shared_56["valid_pairs"],
            baseline=PREV_143["valid_pairs"],
            delta=format_delta_int(shared_56["valid_pairs"], PREV_143["valid_pairs"]),
        ),
        "| Applied pairs | `{current}` | `{shared}` | `{baseline}` | `{delta}` |".format(
            current=overall["applied_pairs"],
            shared=shared_56["applied_pairs"],
            baseline=PREV_143["applied_pairs"],
            delta=format_delta_int(shared_56["applied_pairs"], PREV_143["applied_pairs"]),
        ),
        "| Overall geomean (stock / recompile) | `{current}` | `{shared}` | `{baseline}` | `{delta}` |".format(
            current=format_ratio(overall["geomean_stock_over_recompile"]),
            shared=format_ratio(shared_56["geomean_stock_over_recompile"]),
            baseline=format_ratio(PREV_143["geomean_stock_over_recompile"]),
            delta=format_delta_ratio(
                shared_56["geomean_stock_over_recompile"], PREV_143["geomean_stock_over_recompile"]
            ),
        ),
        "| Applied-only geomean | `{current}` | `{shared}` | `{baseline}` | `{delta}` |".format(
            current=format_ratio(overall["applied_only_geomean_stock_over_recompile"]),
            shared=format_ratio(shared_56["applied_only_geomean_stock_over_recompile"]),
            baseline=format_ratio(PREV_143["applied_only_geomean_stock_over_recompile"]),
            delta=format_delta_ratio(
                shared_56["applied_only_geomean_stock_over_recompile"],
                PREV_143["applied_only_geomean_stock_over_recompile"],
            ),
        ),
        "| Wins / losses / ties | `{current}` | `{shared}` | `{baseline}` | `-` |".format(
            current=f"{overall['wins']} / {overall['losses']} / {overall['ties']}",
            shared=f"{shared_56['wins']} / {shared_56['losses']} / {shared_56['ties']}",
            baseline=f"{PREV_143['wins']} / {PREV_143['losses']} / {PREV_143['ties']}",
        ),
        "",
        "- The direct #143 comparison should use the `Shared-56 subset` column; the `This rerun (62)` column includes the six new per-form rows and is not denominator-matched.",
        "- Overall and applied-only geomeans above are `stock / recompile`, so values above `1.000x` mean recompile is faster.",
        "",
        "## Key Findings",
        "",
        "- Denominator-matched against `#143`, the shared-56 subset regressed on overall geomean (`1.007x -> 0.985x`) but improved on applied-only geomean (`0.986x -> 1.039x`).",
        "- The six new per-form rows are net-negative in this run (`0.809x` geomean overall); only `rotate_dense` is a win, while `cond_select_dense`, `extract_dense`, and the three currently-unapplied rows all lose.",
        "",
        "## Invalid Rows",
        "",
        f"- Invalid pairs in this rerun: `{overall['invalid_pairs']}`.",
        "- `load_byte` failed on both runtimes during warmup because `sudo` in the guest reported `micro/build/runner/micro_exec: command not found`; this is a harness/path issue, not a recompile-policy failure.",
        "",
        "## New Per-Form Isolation Benchmarks",
        "",
        f"- New-benchmark rows present in this JSON: `{new_summary['benchmarks_total']} / {len(NEW_BENCHMARKS)}`.",
        f"- New-benchmark valid/apply counts: `{new_summary['valid_pairs']} / {new_summary['benchmarks_total']}` valid, `{new_summary['applied_pairs']}` applied.",
        f"- New-benchmark geomean (stock / recompile): `{format_ratio(new_summary['geomean_stock_over_recompile'])}` overall, `{format_ratio(new_summary['applied_only_geomean_stock_over_recompile'])}` applied-only.",
        "",
        "| Benchmark | Family | Applied | Sites | Site mix | Stock median | Recompile median | Stock / recompile | Status |",
        "| --- | --- | ---: | ---: | --- | ---: | ---: | ---: | --- |",
    ]

    if not new_rows:
        lines.append("| `n/a` | `n/a` | `n/a` | `n/a` | `n/a` | `n/a` | `n/a` | `n/a` | `n/a` |")
    else:
        for row in new_rows:
            lines.append(
                "| `{name}` | `{family}` | `{applied}` | `{sites}` | `{site_mix}` | `{stock}` | `{recompile}` | `{ratio}` | `{status}` |".format(
                    name=row.name,
                    family=row.family,
                    applied="yes" if row.applied else "no",
                    sites=row.total_sites,
                    site_mix=format_site_mix(row.site_mix),
                    stock=format_ns(row.stock_median_ns),
                    recompile=format_ns(row.recompile_median_ns),
                    ratio=format_ratio(row.ratio),
                    status=ratio_status(row.ratio) if row.ratio is not None else f"{row.stock_status} / {row.recompile_status}",
                )
            )
        lines.extend(
            [
                "",
                "Current policy-match notes for the new rows:",
            ]
        )
        for row in new_rows:
            note = row.policy_note or "no extra policy-match note recorded"
            lines.append(f"- `{row.name}`: {note}")

    lines.extend(
        [
            "",
            "## Top Wins And Losses",
            "",
            "| Top wins | Ratio | Applied | Sites |",
            "| --- | ---: | ---: | ---: |",
        ]
    )
    for row in top_wins:
        lines.append(
            "| `{name}` | `{ratio}` | `{applied}` | `{sites}` |".format(
                name=row.name,
                ratio=format_ratio(row.ratio),
                applied="yes" if row.applied else "no",
                sites=row.total_sites,
            )
        )

    lines.extend(
        [
            "",
            "| Top losses | Ratio | Applied | Sites |",
            "| --- | ---: | ---: | ---: |",
        ]
    )
    for row in top_losses:
        lines.append(
            "| `{name}` | `{ratio}` | `{applied}` | `{sites}` |".format(
                name=row.name,
                ratio=format_ratio(row.ratio),
                applied="yes" if row.applied else "no",
                sites=row.total_sites,
            )
        )

    return "\n".join(lines) + "\n"


def main() -> int:
    args = parse_args()
    input_path = Path(args.input).resolve()
    output_path = Path(args.output).resolve()
    results = json.loads(input_path.read_text())
    rows = build_rows(results)
    markdown = render_report(results, rows, input_path)
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(markdown)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
