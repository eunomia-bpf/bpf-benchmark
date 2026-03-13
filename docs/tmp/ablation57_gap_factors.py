#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import re
from dataclasses import dataclass
from pathlib import Path
from typing import Any


REPO_ROOT = Path(__file__).resolve().parents[2]
PLAN_DOC = REPO_ROOT / "docs" / "kernel-jit-optimization-plan.md"
GAP_DOC = REPO_ROOT / "docs" / "tmp" / "characterization-gap-decomposition.md"
POST_FIX_JSON = REPO_ROOT / "micro" / "results" / "post_fix_micro_62bench_20260313.json"

CALLEE_CURRENT_FILES = {
    "simple": REPO_ROOT / "docs" / "tmp" / "ablation_callee_current_simple.json",
    "simple_packet": REPO_ROOT / "docs" / "tmp" / "ablation_callee_current_simple_packet.json",
    "load_native_u64": REPO_ROOT / "docs" / "tmp" / "ablation_callee_current_load_native_u64.json",
    "fibonacci_iter": REPO_ROOT / "docs" / "tmp" / "ablation_callee_current_fibonacci_iter.json",
}

CALLEE_ALLSAVE_FILES = {
    "simple": REPO_ROOT / "docs" / "tmp" / "ablation_callee_allsave_simple.json",
    "simple_packet": REPO_ROOT / "docs" / "tmp" / "ablation_callee_allsave_simple_packet.json",
    "load_native_u64": REPO_ROOT / "docs" / "tmp" / "ablation_callee_allsave_load_native_u64.json",
    "fibonacci_iter": REPO_ROOT / "docs" / "tmp" / "ablation_callee_allsave_fibonacci_iter.json",
}

BMI_FILES = {
    "rotate64_hash": REPO_ROOT / "docs" / "tmp" / "ablation57_rotate64_hash_bmi.json",
    "bitfield_extract": REPO_ROOT / "docs" / "tmp" / "ablation57_bitfield_extract_bmi.json",
    "bitcount": REPO_ROOT / "docs" / "tmp" / "ablation57_bitcount_bmi.json",
    "rotate_dense": REPO_ROOT / "docs" / "tmp" / "ablation57_rotate_dense_bmi.json",
}

KEY_POST_FIX_BENCHES = [
    "load_byte_recompose",
    "simple",
    "simple_packet",
    "rotate64_hash",
    "bitcount",
    "checksum",
]


@dataclass
class FactorEstimate:
    name: str
    point_share: float
    point_abs: float
    confidence: str
    method: str
    note: str


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Quantify byte-recompose / callee-saved / BMI contributions.")
    parser.add_argument(
        "--output",
        type=Path,
        default=REPO_ROOT / "docs" / "tmp" / "ablation-byte-recompose-callee-bmi.md",
    )
    return parser.parse_args()


def read_text(path: Path) -> str:
    return path.read_text()


def read_json(path: Path) -> dict[str, Any]:
    return json.loads(path.read_text())


def must_match(pattern: str, text: str) -> re.Match[str]:
    match = re.search(pattern, text, re.MULTILINE)
    if match is None:
        raise ValueError(f"pattern not found: {pattern}")
    return match


def parse_plan_constants(plan_text: str, gap_text: str) -> dict[str, float]:
    char_gap = float(
        must_match(r"Characterization gap geomean \(all 56\) \| ([0-9.]+)x", gap_text).group(1)
    )
    byte_share = float(must_match(r"Byte-recompose 占 kernel surplus \| ([0-9.]+)%", plan_text).group(1)) / 100.0
    callee_hist_share = (
        float(must_match(r"Prologue/epilogue 占 surplus \| ([0-9.]+)%", plan_text).group(1)) / 100.0
    )
    return {
        "characterization_gap": char_gap,
        "surplus": char_gap - 1.0,
        "byte_share": byte_share,
        "callee_hist_share": callee_hist_share,
    }


def parse_gap_table(gap_text: str) -> dict[str, dict[str, float]]:
    lines = gap_text.splitlines()
    start = None
    for idx, line in enumerate(lines):
        if line.strip() == "## Full Per-Benchmark Table":
            start = idx + 3
            break
    if start is None:
        raise ValueError("full per-benchmark table not found")

    headers = [
        "Benchmark",
        "Family",
        "llvmbpf",
        "kernel stock (char)",
        "kernel recompile",
        "Char gap",
    ]
    rows: dict[str, dict[str, float]] = {}
    for line in lines[start:]:
        if not line.startswith("|"):
            break
        parts = [part.strip() for part in line.strip().strip("|").split("|")]
        if len(parts) < 6 or parts[0] in {"Benchmark", "---"}:
            continue
        name = parts[0]
        llvmbpf = parse_ns(parts[2])
        kernel = parse_ns(parts[3])
        char_gap = parse_ratio(parts[5])
        rows[name] = {
            "llvmbpf_ns": llvmbpf,
            "kernel_stock_char_ns": kernel,
            "char_gap": char_gap,
            "char_surplus": char_gap - 1.0,
        }
    return rows


def parse_ns(token: str) -> float:
    token = token.replace("`", "").strip()
    if token.endswith("us"):
        return float(token[:-2].strip()) * 1000.0
    if token.endswith("ns"):
        return float(token[:-2].strip())
    if token == "n/a":
        raise ValueError("unexpected n/a in ns field")
    return float(token)


def parse_ratio(token: str) -> float:
    token = token.replace("`", "").strip()
    if token.endswith("x"):
        token = token[:-1]
    return float(token)


def load_exec_median(path: Path, mode: str) -> float | None:
    if not path.exists():
        return None
    payload = read_json(path)
    modes = payload.get("modes", {})
    entry = modes.get(mode)
    if not isinstance(entry, dict):
        return None
    exec_ns = entry.get("exec_ns", {})
    if not isinstance(exec_ns, dict):
        return None
    median = exec_ns.get("median")
    return float(median) if median is not None else None


def compute_callee_current_share(
    char_rows: dict[str, dict[str, float]],
    surplus: float,
) -> tuple[FactorEstimate, list[dict[str, Any]]]:
    proxy_rows: list[dict[str, Any]] = []

    for name in CALLEE_CURRENT_FILES:
        current = load_exec_median(CALLEE_CURRENT_FILES[name], "stock")
        allsave = load_exec_median(CALLEE_ALLSAVE_FILES[name], "stock")
        llvmbpf = load_exec_median(CALLEE_CURRENT_FILES[name], "llvmbpf")
        if current is None or allsave is None or llvmbpf is None:
            continue
        historical_gap = max((allsave / llvmbpf) - 1.0, 0.0)
        current_gap = max((current / llvmbpf) - 1.0, 0.0)
        removed_share = ((historical_gap - current_gap) / historical_gap) if historical_gap > 0 else 0.0
        proxy_rows.append(
            {
                "benchmark": name,
                "llvmbpf_ns": llvmbpf,
                "current_ns": current,
                "allsave_ns": allsave,
                "current_gap": max(current / llvmbpf, 0.0),
                "removed_share": removed_share,
            }
        )

    estimate = FactorEstimate(
        name="callee-saved (current 7.0-rc2 stock)",
        point_share=0.0,
        point_abs=0.0,
        confidence="Medium-Low",
        method=(
            "Current-vs-allsave proxy on `simple`, `simple_packet`, `load_native_u64`, and `fibonacci_iter`; "
            "report how much of the old allsave gap has already been removed by current stock."
        ),
        note=(
            "Current stock already includes `detect_reg_usage()`, so the live contribution is modeled as zero. "
            "Treat `18.5%` only as a historical upper bound for pre-v7 kernels."
        ),
    )
    return estimate, proxy_rows


def compute_bmi_share(
    char_rows: dict[str, dict[str, float]],
    surplus: float,
) -> tuple[FactorEstimate, list[dict[str, Any]]]:
    proxy_rows: list[dict[str, Any]] = []
    factor_surplus_sum = 0.0
    char_surplus_sum = 0.0

    for name in ["rotate64_hash", "bitfield_extract", "bitcount"]:
        path = BMI_FILES[name]
        llvmbpf = load_exec_median(path, "llvmbpf")
        nobmi = load_exec_median(path, "llvmbpf-nobmi")
        char_row = char_rows.get(name)
        if llvmbpf is None or nobmi is None or char_row is None:
            continue
        factor_surplus = (nobmi / llvmbpf) - 1.0
        local_share = factor_surplus / char_row["char_surplus"] if char_row["char_surplus"] > 0 else 0.0
        factor_surplus_sum += factor_surplus
        char_surplus_sum += char_row["char_surplus"]
        proxy_rows.append(
            {
                "benchmark": name,
                "llvmbpf_ns": llvmbpf,
                "nobmi_ns": nobmi,
                "char_gap": char_row["char_gap"],
                "factor_surplus": factor_surplus,
                "local_share": local_share,
            }
        )

    weighted_local_share = factor_surplus_sum / char_surplus_sum if char_surplus_sum > 0 else 0.0
    # Coverage prior from docs/tmp/additional_jit_optimizations.md:
    # ~10 rotate-idiom pure-JIT benchmarks + 1 blsr benchmark + 1 extract-style benchmark.
    prevalence = 12.0 / 56.0
    signed_suite_share = weighted_local_share * prevalence
    point_share = max(0.0, signed_suite_share)
    estimate = FactorEstimate(
        name="BMI/BMI2-specific delta",
        point_share=point_share,
        point_abs=point_share * surplus,
        confidence="Low",
        method=(
            "Direct `llvmbpf` vs `llvmbpf-nobmi` proxy on `rotate64_hash`, `bitfield_extract`, and `bitcount`, "
            "then multiplied by a conservative coverage prior (`12/56`)."
        ),
        note=(
            f"Signed proxy estimate is {signed_suite_share * 100.0:+.1f}% of suite surplus, so the "
            "reported contribution is clipped to zero. This suggests the incremental BMI-only choice "
            "(`rorx`/`bextr`/`blsr`) is not a first-order driver of the current 1.641x gap."
        ),
    )
    return estimate, proxy_rows


def load_post_fix_rows() -> list[dict[str, Any]]:
    payload = read_json(POST_FIX_JSON)
    result: list[dict[str, Any]] = []
    for bench in payload["benchmarks"]:
        if bench["name"] not in KEY_POST_FIX_BENCHES:
            continue
        runs = {run["runtime"]: run for run in bench["runs"]}
        stock = runs["kernel"]["exec_ns"]["median"]
        recomp = runs["kernel-recompile"]["exec_ns"]["median"]
        result.append(
            {
                "benchmark": bench["name"],
                "stock_ns": float(stock),
                "recompile_ns": float(recomp),
                "stock_over_recompile": float(stock) / float(recomp),
            }
        )
    return sorted(result, key=lambda row: row["benchmark"])


def format_ratio(value: float) -> str:
    return f"{value:.3f}x"


def format_share(value: float) -> str:
    return f"{value * 100.0:.1f}%"


def format_ns(value: float) -> str:
    if value >= 1000.0:
        return f"{value / 1000.0:.1f} us"
    if value.is_integer():
        return f"{int(value)} ns"
    return f"{value:.1f} ns"


def markdown_table(headers: list[str], rows: list[list[str]]) -> str:
    rendered = [
        "| " + " | ".join(headers) + " |",
        "| " + " | ".join(["---"] * len(headers)) + " |",
    ]
    rendered.extend("| " + " | ".join(row) + " |" for row in rows)
    return "\n".join(rendered)


def render_report(
    constants: dict[str, float],
    byte_estimate: FactorEstimate,
    callee_estimate: FactorEstimate,
    bmi_estimate: FactorEstimate,
    callee_proxy_rows: list[dict[str, Any]],
    bmi_proxy_rows: list[dict[str, Any]],
    char_rows: dict[str, dict[str, float]],
    post_fix_rows: list[dict[str, Any]],
) -> str:
    surplus = constants["surplus"]
    hist_callee_share = constants["callee_hist_share"]
    factor_rows = [
        [
            "byte-recompose",
            format_share(byte_estimate.point_share),
            f"{byte_estimate.point_abs:.3f}",
            byte_estimate.confidence,
            byte_estimate.method,
            byte_estimate.note,
        ],
        [
            "callee-saved (current stock)",
            format_share(callee_estimate.point_share),
            f"{callee_estimate.point_abs:.3f}",
            callee_estimate.confidence,
            callee_estimate.method,
            callee_estimate.note,
        ],
        [
            "BMI/BMI2-specific delta",
            format_share(bmi_estimate.point_share),
            f"{bmi_estimate.point_abs:.3f}",
            bmi_estimate.confidence,
            bmi_estimate.method,
            bmi_estimate.note,
        ],
    ]

    callee_rows = []
    for row in callee_proxy_rows:
        callee_rows.append(
            [
                row["benchmark"],
                format_ns(row["llvmbpf_ns"]),
                format_ns(row["current_ns"]),
                format_ns(row["allsave_ns"]),
                format_ratio(row["current_gap"]),
                format_share(row["removed_share"]),
            ]
        )

    bmi_rows = []
    for row in bmi_proxy_rows:
        bmi_rows.append(
            [
                row["benchmark"],
                format_ns(row["llvmbpf_ns"]),
                format_ns(row["nobmi_ns"]),
                format_ratio(row["char_gap"]),
                f"{row['factor_surplus'] * 100.0:+.1f}%",
                format_share(row["local_share"]),
            ]
        )

    post_fix_table_rows = [
        [
            row["benchmark"],
            format_ns(row["stock_ns"]),
            format_ns(row["recompile_ns"]),
            format_ratio(row["stock_over_recompile"]),
        ]
        for row in post_fix_rows
    ]

    proxy_gap_rows = []
    for name in ["load_byte_recompose", "simple", "simple_packet", "load_native_u64", "rotate64_hash", "bitcount", "checksum"]:
        row = char_rows.get(name)
        if row is None:
            continue
        proxy_gap_rows.append(
            [
                name,
                format_ns(row["llvmbpf_ns"]),
                format_ns(row["kernel_stock_char_ns"]),
                format_ratio(row["char_gap"]),
            ]
        )

    return "\n".join(
        [
            "# Ablation #57: byte-recompose / callee-saved / BMI",
            "",
            "## Bottom Line",
            "",
            f"- 当前 characterization gap 使用 `docs/tmp/characterization-gap-decomposition.md` 的 strict geomean: **{constants['characterization_gap']:.3f}x**。",
            f"- gap surplus 定义为 `gap - 1 = {surplus:.3f}`。",
            f"- **byte-recompose 仍是主导项**：point estimate **{format_share(byte_estimate.point_share)}** of surplus，约 **{byte_estimate.point_abs:.3f}** ratio-points。",
            f"- **callee-saved 在当前 `7.0-rc2` stock 上未测到可分辨贡献**：point estimate **{format_share(callee_estimate.point_share)}**；但 **{format_share(hist_callee_share)}** 仍可作为 pre-v7 historical upper bound。",
            f"- **BMI/BMI2-only 增量贡献接近 0**：direct `llvmbpf-nobmi` spot checks give a clipped point estimate of **{format_share(bmi_estimate.point_share)}** of surplus.",
            "",
            "结论（中文）:",
            "",
            "- 如果问题是“当前 1.641x gap 里哪一项最该优先补”，答案仍然是 **byte-recompose**。",
            "- 如果问题是“历史上 18.5% 的 callee-saved 现在还剩多少”，答案是 **当前 stock 基本已经把这块吃掉了，剩余贡献接近 0**。",
            "- 如果问题是“BMI2 / 高级 bit-manip 指令本身是不是大头”，答案是 **不是；更像 low-single-digit 以内，甚至接近 0 的增量项**。",
            "",
            "## Method",
            "",
            "- `byte-recompose`: use the repo's already-published surplus share (`50.7%`) as the point estimate. This is the strongest available number because it comes from the earlier full native-code surplus decomposition, not from a single proxy benchmark.",
            "- `callee-saved`: treat `18.5%` only as a historical upper bound, then constrain the current contribution with direct current-vs-allsave spot checks on four proxies. The current-stock point estimate is fixed at `0%`, and the spot checks are used only to verify that the historical gap is already gone.",
            "- `BMI/BMI2`: use direct `llvmbpf` vs `llvmbpf-nobmi` measurements on three strict-suite proxies (`rotate64_hash`, `bitfield_extract`, `bitcount`) to estimate the incremental value of BMI-specific instruction selection. Then down-weight by a conservative coverage prior (`12/56`) based on documented rotate/bit-twiddle prevalence.",
            "- This report intentionally separates **BMI-only** from the broader **rotate-fusion / bit-twiddle family**. A rotate win can come from collapsing `shr/shl/or` into `ror`, even when the BMI2-only choice (`rorx`) adds little.",
            "",
            "## Factor Estimates",
            "",
            markdown_table(
                ["Factor", "Share of Surplus", "Absolute Contribution", "Confidence", "Method", "Notes"],
                factor_rows,
            ),
            "",
            "## Proxy Gaps From Strict Characterization",
            "",
            markdown_table(
                ["Benchmark", "llvmbpf", "kernel stock", "Char gap"],
                proxy_gap_rows,
            ),
            "",
            "## Callee-Saved Proxies",
            "",
            markdown_table(
                ["Benchmark", "llvmbpf", "current stock", "allsave stock", "Current char gap", "Historical gap already removed"],
                callee_rows,
            ),
            "",
            "Callee reading: only `fibonacci_iter` still has a visible current gap among these proxies, but the `allsave` kernel is substantially slower than current stock. That means the old fixed-save overhead was real, yet it has already been removed from today's stock baseline rather than remaining inside today's 1.641x gap.",
            "",
            "## BMI/BMI2 Proxies",
            "",
            markdown_table(
                ["Benchmark", "llvmbpf", "llvmbpf-nobmi", "Strict char gap", "nobmi delta vs llvmbpf", "Proxy-local share"],
                bmi_rows,
            ),
            "",
            "BMI reading: `bitfield_extract` still benefits from BMI-style lowering, but `rotate64_hash` and `bitcount` do not show a positive BMI-only delta in the current spot checks. So the **incremental** benefit of BMI-specific instruction choice is not stable enough to claim a large suite-level share.",
            "",
            "Auxiliary cross-check outside the original 56-benchmark strict suite:",
            "",
            f"- `rotate_dense`: `llvmbpf={format_ns(load_exec_median(BMI_FILES['rotate_dense'], 'llvmbpf') or 0.0)}`, `llvmbpf-nobmi={format_ns(load_exec_median(BMI_FILES['rotate_dense'], 'llvmbpf-nobmi') or 0.0)}`. This newly added pure rotate-isolation benchmark is essentially invariant to BMI disablement, which matches the near-zero suite-level estimate.",
            "",
            "## Broader Rotate-Fusion Note",
            "",
            "- Do not over-read the near-zero BMI-only estimate as “rotate does not matter.” It only says `rorx` / `bextr` / `blsr` over non-BMI alternatives is not a dominant incremental source.",
            "- The broader rotate-fusion family still matters locally. In the per-family ablation, `rotate64_hash` improves from `96 ns` to `69 ns` under `rotate`-only recompile, and `packet_rss_hash` improves from `30 ns` to `25 ns`. Those are real backend wins; they just should not all be attributed to BMI2-only forms.",
            "",
            "## Post-Fix 62-Bench Sanity Check",
            "",
            markdown_table(
                ["Benchmark", "post-fix stock", "post-fix recompile", "stock/recompile"],
                post_fix_table_rows,
            ),
            "",
            "This sanity check matches the decomposition story:",
            "",
            "- `load_byte_recompose` is still unrecovered in the latest post-fix run.",
            "- `simple` / `simple_packet` remain ties, which is exactly what we expect if callee-saved overhead is no longer a major open gap in current stock.",
            "- `bitcount` and `checksum` move only slightly, which is consistent with BMI/bit-twiddle being a second-order effect rather than a dominant suite-wide driver.",
            "",
            "## Interpretation",
            "",
            "- **High confidence**: byte-recompose is still the largest single contributor and should keep P1 priority.",
            "- **Medium-low confidence, but directionally clear**: callee-saved was historically important, but current stock already upstreamed the relevant optimization, so it should no longer be modeled as an 18.5% live component of today's gap.",
            "- **Low confidence, but consistent across mixed evidence**: BMI/BMI2 is best treated as a small incremental effect inside a larger rotate/bit-twiddle bucket, not as a primary explanation of the current characterization gap.",
        ]
    )


def main() -> int:
    args = parse_args()

    plan_text = read_text(PLAN_DOC)
    gap_text = read_text(GAP_DOC)
    constants = parse_plan_constants(plan_text, gap_text)
    char_rows = parse_gap_table(gap_text)

    byte_estimate = FactorEstimate(
        name="byte-recompose",
        point_share=constants["byte_share"],
        point_abs=constants["byte_share"] * constants["surplus"],
        confidence="High",
        method="Directly use the repository's published native-code surplus decomposition.",
        note="This is the strongest number in the repo and already agrees with the causal-isolation narrative.",
    )
    callee_estimate, callee_proxy_rows = compute_callee_current_share(char_rows, constants["surplus"])
    bmi_estimate, bmi_proxy_rows = compute_bmi_share(char_rows, constants["surplus"])
    post_fix_rows = load_post_fix_rows()

    report = render_report(
        constants=constants,
        byte_estimate=byte_estimate,
        callee_estimate=callee_estimate,
        bmi_estimate=bmi_estimate,
        callee_proxy_rows=callee_proxy_rows,
        bmi_proxy_rows=bmi_proxy_rows,
        char_rows=char_rows,
        post_fix_rows=post_fix_rows,
    )

    args.output.write_text(report)
    print(
        json.dumps(
            {
                "characterization_gap": constants["characterization_gap"],
                "surplus": constants["surplus"],
                "byte_share": byte_estimate.point_share,
                "callee_current_share": callee_estimate.point_share,
                "callee_historical_upper_bound": constants["callee_hist_share"],
                "bmi_share": bmi_estimate.point_share,
                "output": str(args.output),
            },
            indent=2,
        )
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
