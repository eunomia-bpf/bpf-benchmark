#!/usr/bin/env python3
"""
Analyze per-form ablation results from targeted JSON files.
Computes per-family geomeans and writes the ablation report.
"""
import json
import math
import os
import sys
from pathlib import Path

REPO = Path("/home/yunwei37/workspace/bpf-benchmark")
RESULTS_DIR = REPO / "micro/results/per_form_ablation_20260313"
OUTPUT_MD = REPO / "docs/tmp/micro-per-form-ablation.md"

FAMILIES = {
    "rotate": "Rotate (ROL/ROR)",
    "wide": "Wide Load (MOV32 → MOV64)",
    "lea": "Address Calc (ADD/SUB → LEA)",
    "cmov": "Conditional Select (Jcc → CMOV)",
    "extract": "Bitfield Extract (AND/SHR → BEXTR)",
    "endian": "Endian Fusion (LDX+BSWAP → MOVBE)",
    "branch_flip": "Branch Flip (Jcc inversion)",
}

# Which benchmarks are applicable for each family
FAMILY_BENCHES = {
    "rotate": ["rotate_dense", "cmov_dense", "memcmp_prefix_64"],
    "wide": ["binary_search", "log2_fold", "bounds_ladder", "bpf_call_chain",
             "branch_dense", "mixed_alu_mem", "multi_acc_4", "multi_acc_8", "switch_dispatch"],
    "lea": ["addr_calc_stride", "multi_acc_4", "multi_acc_8"],
    "cmov": ["binary_search", "bounds_ladder", "bpf_call_chain", "branch_dense",
             "cmov_select", "cond_select_dense", "switch_dispatch"],
    "extract": ["mixed_alu_mem", "extract_dense"],
    "endian": ["endian_swap_dense"],
    "branch_flip": ["branch_dense", "branch_flip_dense", "large_mixed_500"],
}

# Site counts per bench per family (from policy files)
SITES_INFO = {
    "rotate": {"rotate_dense": 256, "cmov_dense": 26, "memcmp_prefix_64": 3},
    "wide": {"binary_search": 2, "log2_fold": 3, "bounds_ladder": 2, "bpf_call_chain": 2,
             "branch_dense": 2, "mixed_alu_mem": 1, "multi_acc_4": 2, "multi_acc_8": 2, "switch_dispatch": 2},
    "lea": {"addr_calc_stride": 8, "multi_acc_4": 1, "multi_acc_8": 2},
    "cmov": {"binary_search": 1, "bounds_ladder": 2, "bpf_call_chain": 1, "branch_dense": 1,
             "cmov_select": 1, "cond_select_dense": 104, "switch_dispatch": 1},
    "extract": {"mixed_alu_mem": 2, "extract_dense": 512},
    "endian": {"endian_swap_dense": 256},
    "branch_flip": {"branch_dense": 4, "branch_flip_dense": 255, "large_mixed_500": 3},
}

def geomean(values):
    if not values:
        return None
    vals = [v for v in values if v and v > 0]
    if not vals:
        return None
    return math.exp(sum(math.log(v) for v in vals) / len(vals))

def load_results(json_file):
    """Load a results JSON and return {bench_name: (kernel_median, recompile_median)} mapping."""
    if not json_file.exists():
        return None
    with open(json_file) as f:
        data = json.load(f)
    result = {}
    for b in data.get("benchmarks", []):
        name = b["name"]
        k_med = None
        kr_med = None
        for r in b.get("runs", []):
            if r["runtime"] == "kernel":
                k_med = r["exec_ns"]["median"]
            elif r["runtime"] == "kernel-recompile":
                kr_med = r["exec_ns"]["median"]
        if k_med and kr_med:
            result[name] = (k_med, kr_med)
    return result

def main():
    # Load all-families reference (ablation_all_targeted.json)
    all_ref = load_results(RESULTS_DIR / "ablation_all_targeted.json")
    if all_ref is None:
        print("ERROR: ablation_all_targeted.json not found")
        sys.exit(1)

    # Load per-family results
    family_data = {}
    missing = []
    for slug in FAMILIES:
        fname = RESULTS_DIR / f"ablation_{slug}_targeted.json"
        data = load_results(fname)
        if data is None:
            missing.append(slug)
            print(f"WARNING: {fname} not found")
        else:
            family_data[slug] = data

    if missing:
        print(f"Missing families: {missing}")
        print("Analysis will be partial.")

    # Compute per-family metrics
    family_metrics = {}
    for slug, benches in FAMILY_BENCHES.items():
        if slug not in family_data:
            continue
        data = family_data[slug]
        ratios = []
        bench_details = []
        for bench in benches:
            if bench in data:
                k, kr = data[bench]
                ratio = kr / k
                ratios.append(ratio)
                sites = SITES_INFO.get(slug, {}).get(bench, "?")
                bench_details.append((bench, k, kr, ratio, sites))
        gm = geomean(ratios)
        family_metrics[slug] = {
            "geomean": gm,
            "ratios": ratios,
            "bench_details": bench_details,
            "n": len(ratios),
        }

    # All-families reference metrics for the applicable benches
    all_applicable_benches = set()
    for benches in FAMILY_BENCHES.values():
        all_applicable_benches.update(benches)
    all_ratios = []
    for bench in all_applicable_benches:
        if bench in all_ref:
            k, kr = all_ref[bench]
            all_ratios.append(kr / k)
    all_gm = geomean(all_ratios)

    # Write report
    lines = []
    lines.append("# Per-Form Ablation Analysis: BpfReJIT Micro Benchmarks")
    lines.append("")
    lines.append(f"**Date**: 2026-03-13")
    lines.append(f"**Suite**: 62-benchmark micro suite, targeted 19 benchmarks with policy sites")
    lines.append(f"**Protocol**: iterations=5, warmups=3, repeat=1000, single VM session")
    lines.append(f"**Method**: For each canonical form family, only that family's sites are active; all other sites cleared")
    lines.append(f"**Metric**: kernel-recompile / kernel (lower = faster with recompile; <1.0 = win)")
    lines.append("")
    lines.append("## Summary Table")
    lines.append("")
    lines.append("| Family | Sites | Applicable Benchmarks | Geomean Ratio | Win/Loss |")
    lines.append("|--------|-------|----------------------|---------------|----------|")

    sorted_families = sorted(
        [(slug, m) for slug, m in family_metrics.items()],
        key=lambda x: x[1]["geomean"] if x[1]["geomean"] else 999
    )

    for slug, m in sorted_families:
        name = FAMILIES[slug]
        gm = m["geomean"]
        n = m["n"]
        total_sites = sum(SITES_INFO.get(slug, {}).values())
        win_loss = "WIN" if gm and gm < 1.0 else "LOSS"
        gm_str = f"{gm:.3f}x" if gm else "N/A"
        lines.append(f"| {name} | {total_sites} | {n} | {gm_str} | {win_loss} |")

    # All-families combined
    lines.append(f"| **ALL (combined reference)** | — | {len(all_ratios)} | {all_gm:.3f}x | {'WIN' if all_gm < 1.0 else 'LOSS'} |")
    lines.append("")
    lines.append("## Per-Family Detail")
    lines.append("")

    for slug, m in sorted_families:
        name = FAMILIES[slug]
        gm = m["geomean"]
        lines.append(f"### {name}")
        lines.append("")
        lines.append(f"**Geomean**: {gm:.3f}x | **Benchmarks**: {m['n']}")
        lines.append("")
        lines.append("| Benchmark | Sites | kernel (ns) | recompile (ns) | ratio |")
        lines.append("|-----------|-------|-------------|----------------|-------|")
        for bench, k, kr, ratio, sites in sorted(m["bench_details"], key=lambda x: x[3]):
            status = "<" if ratio < 1.0 else ">"
            lines.append(f"| {bench} | {sites} | {k:.0f} | {kr:.0f} | {ratio:.3f}x {status if ratio != 1.0 else '='} |")
        lines.append("")

    lines.append("## All-Families Combined Reference")
    lines.append("")
    lines.append(f"Geomean across {len(all_ratios)} applicable benchmarks with all families active: **{all_gm:.3f}x**")
    lines.append("")
    lines.append("| Benchmark | kernel (ns) | recompile (ns) | ratio |")
    lines.append("|-----------|-------------|----------------|-------|")
    for bench in sorted(all_applicable_benches):
        if bench in all_ref:
            k, kr = all_ref[bench]
            ratio = kr / k
            lines.append(f"| {bench} | {k:.0f} | {kr:.0f} | {ratio:.3f}x |")
    lines.append("")

    lines.append("## Interpretation & Optimal Combination")
    lines.append("")
    lines.append("### Ranking by per-family contribution (lower ratio = more beneficial):")
    lines.append("")
    rank = 1
    for slug, m in sorted_families:
        name = FAMILIES[slug]
        gm = m["geomean"]
        if gm:
            contribution = 1.0 - gm
            lines.append(f"{rank}. **{name}**: {gm:.3f}x ({contribution:+.1%} contribution)")
        rank += 1
    lines.append("")
    lines.append("### Policy recommendations:")
    lines.append("")
    wins = [(slug, m) for slug, m in sorted_families if m["geomean"] and m["geomean"] < 1.0]
    losses = [(slug, m) for slug, m in sorted_families if m["geomean"] and m["geomean"] >= 1.0]
    lines.append("**Beneficial forms (keep active):**")
    for slug, m in wins:
        lines.append(f"- {FAMILIES[slug]}: {m['geomean']:.3f}x geomean")
    lines.append("")
    lines.append("**Detrimental forms (skip or be policy-selective):**")
    for slug, m in losses:
        lines.append(f"- {FAMILIES[slug]}: {m['geomean']:.3f}x geomean")
    lines.append("")
    lines.append("### Notes on context-sensitivity:")
    lines.append("")
    lines.append("- **CMOV/cond_select_dense**: Policy-sensitive. Predictable branches → CMOV regression. Unpredictable branches → win.")
    lines.append("- **EXTRACT/extract_dense**: Dense-site I-cache flush dominates for 512 sites. Sparse sites (mixed_alu_mem) may win.")
    lines.append("- **ENDIAN/endian_swap_dense**: Same-size rewrite (5B→5B) means I-cache flush with no code-size benefit.")
    lines.append("- **ROTATE**: Consistently beneficial for dense sites (256 sites → 1.167x authoritative).")
    lines.append("- **LEA/addr_calc_stride**: Consistently beneficial for sparse sites (8 sites → 1.401x authoritative).")
    lines.append("")
    lines.append("---")
    lines.append(f"*Generated by docs/tmp/analyze_per_form_ablation.py*")

    OUTPUT_MD.parent.mkdir(parents=True, exist_ok=True)
    with open(OUTPUT_MD, "w") as f:
        f.write("\n".join(lines) + "\n")

    print(f"Report written to {OUTPUT_MD}")
    print(f"\nSummary:")
    print(f"  All-families reference: {all_gm:.3f}x ({len(all_ratios)} benches)")
    for slug, m in sorted_families:
        gm = m["geomean"]
        print(f"  {slug}: {gm:.3f}x ({m['n']} benches)" if gm else f"  {slug}: N/A")
    print(f"\nMissing families: {missing}")

if __name__ == "__main__":
    main()
