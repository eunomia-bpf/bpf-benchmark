#!/usr/bin/env python3
"""Post-hoc arm64 kinsn microbenchmark analysis for the 2026-06-06 artifacts."""

from __future__ import annotations

import json
import math
import statistics
from collections import Counter
from pathlib import Path

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter


ROOT = Path(__file__).resolve().parents[2]
FIG = ROOT / "docs" / "figures"
SUMMARY = ROOT / "docs" / "tmp" / "arm64_kinsn_micro_20260606_summary.md"
PURE = ROOT / "micro/results/aws_arm64_micro_20260606_001225_821028/details/result.json"
HELPERS = ROOT / "micro/results/aws_arm64_micro_20260606_160621_594885/details/result.json"

SHORT_NAMES = {
    "simple": "simple",
    "simple_packet": "simple_pkt",
    "bitmap_popcount_scan": "bitmap",
    "sorted_rule_binary_search": "bin_search",
    "bcc_runqlat_log2_histogram_bucket": "runqlat",
    "trace_event_type_switch_dispatch": "trace_sw",
    "packet_checksum_fold": "cksum",
    "payload_prefix_memcmp_scan": "memcmp",
    "packet_vlan_tcpopt_parser": "vlan",
    "bpf_local_call_fanout_dispatch": "call_fanout",
    "flow_5tuple_rss_hash": "5tuple",
    "katran_lb_consistent_hash_select": "katran",
    "cilium_policy_guard_tree_filter": "policy",
    "siphash_rotate64_mixer": "siphash",
    "packet_record_bounds_window": "bounds",
    "flow_record_field_scan": "field",
    "packed_header_bitfield_decode": "bitfield",
    "bpftrace_string_search_prefix_scan": "str_search",
    "tracee_syscall_name_table_lookup": "syscall",
    "tracee_http_method_prefix_detect": "http",
    "cilium_socket_lb_service_select": "sock_lb",
    "bcc_tcpconnect_ipv4_tuple_filter": "tcpconn",
    "tetragon_process_event_arg_filter": "tetragon",
    "otel_stack_frame_unwind_scan": "otel",
    "cilium_ct_nat_tuple_rewrite": "ct_nat",
    "packet_toeplitz_rss_hash": "toeplitz",
    "bpftrace_comm_key_fnv_hash": "fnv",
    "tc_packet_checksum_fold": "tc_cksum",
    "cgroup_skb_hash_chain": "cgroup",
}


def geomean(values: list[float]) -> float:
    return math.exp(sum(math.log(value) for value in values) / len(values))


def sample_kinsn_counts(sample: dict) -> tuple[int, int, Counter[str]]:
    matched = 0
    applied = 0
    names: Counter[str] = Counter()
    for program in (sample.get("rejit_result") or {}).get("per_program", {}).values():
        for pass_result in program.get("passes", []):
            summary = pass_result.get("bpfopt_summary") or {}
            if summary.get("pass") != "kinsn":
                continue
            matched += int(summary.get("sites_matched") or 0)
            applied += int(summary.get("sites_applied") or 0)
            names.update(summary.get("kinsn_calls_by_name") or {})
    return matched, applied, names


def code_size(sample: dict) -> int:
    return int((sample.get("code_size") or {}).get("native_code_bytes") or sample.get("jited_prog_len") or 0)


def correctness_mismatches(data: dict) -> int:
    mismatches = 0
    for bench in data["benchmarks"]:
        expected_result = bench.get("expected_result")
        expected_retval = bench.get("expected_retval")
        for run in bench["runs"]:
            for sample in run["samples"]:
                if expected_result is not None and sample.get("result") != expected_result:
                    mismatches += 1
                if expected_retval is not None and sample.get("retval") != expected_retval:
                    mismatches += 1
    return mismatches


def load_rows(path: Path) -> tuple[dict, list[dict]]:
    data = json.loads(path.read_text())
    rows = []
    for bench in data["benchmarks"]:
        runs = {run["runtime"]: run for run in bench["runs"]}
        if "kernel" not in runs or "kernel_rejit" not in runs:
            continue
        kernel_samples = runs["kernel"]["samples"]
        rejit_samples = runs["kernel_rejit"]["samples"]
        kernel_ns = statistics.median(sample["exec_ns"] for sample in kernel_samples)
        rejit_ns = statistics.median(sample["exec_ns"] for sample in rejit_samples)
        kernel_code = statistics.median(code_size(sample) for sample in kernel_samples)
        rejit_code = statistics.median(code_size(sample) for sample in rejit_samples)
        matched_samples = []
        applied_samples = []
        names: Counter[str] = Counter()
        for sample in rejit_samples:
            matched, applied, sample_names = sample_kinsn_counts(sample)
            matched_samples.append(matched)
            applied_samples.append(applied)
            names.update(sample_names)
        rows.append(
            {
                "name": bench["name"],
                "kernel_ns": kernel_ns,
                "rejit_ns": rejit_ns,
                "speedup": kernel_ns / rejit_ns,
                "kernel_code": kernel_code,
                "rejit_code": rejit_code,
                "code_ratio": rejit_code / kernel_code if kernel_code else 1.0,
                "matched_median": int(statistics.median(matched_samples)),
                "applied_median": int(statistics.median(applied_samples)),
                "matched_raw": sum(matched_samples),
                "applied_raw": sum(applied_samples),
                "names": names,
            }
        )
    return data, rows


def format_counter(counter: Counter[str]) -> str:
    return ", ".join(f"{name}={count}" for name, count in counter.most_common()) or "-"


def summarize(data: dict, rows: list[dict]) -> dict:
    speedups = [row["speedup"] for row in rows]
    code_ratios = [row["code_ratio"] for row in rows]
    kinsn_speedups = [row["speedup"] for row in rows if row["applied_median"]]
    names = sum((row["names"] for row in rows), Counter())
    return {
        "generated_at": data["generated_at"],
        "benchmarks": len(rows),
        "mismatches": correctness_mismatches(data),
        "geomean": geomean(speedups),
        "kinsn_geomean": geomean(kinsn_speedups) if kinsn_speedups else None,
        "kinsn_benchmarks": len(kinsn_speedups),
        "wins": sum(value > 1.02 for value in speedups),
        "losses": sum(value < 0.98 for value in speedups),
        "ties": sum(0.98 <= value <= 1.02 for value in speedups),
        "matched_median": sum(row["matched_median"] for row in rows),
        "applied_median": sum(row["applied_median"] for row in rows),
        "matched_raw": sum(row["matched_raw"] for row in rows),
        "applied_raw": sum(row["applied_raw"] for row in rows),
        "code_geomean": geomean(code_ratios),
        "names": names,
    }


def write_summary(pure_data: dict, pure_rows: list[dict], helper_data: dict, helper_rows: list[dict]) -> dict:
    summary = summarize(pure_data, pure_rows)
    helper_summary = summarize(helper_data, helper_rows)
    kinsn_geomean = (
        f"{summary['kinsn_geomean']:.3f}x over {summary['kinsn_benchmarks']} benchmarks"
        if summary["kinsn_geomean"] is not None
        else "N/A"
    )
    helper_kinsn_geomean = (
        f"{helper_summary['kinsn_geomean']:.3f}x over {helper_summary['kinsn_benchmarks']} benchmarks"
        if helper_summary["kinsn_geomean"] is not None
        else "N/A"
    )
    lines = [
        "# arm64 kinsn micro 2026-06-06",
        "",
        f"- Artifact: `{PURE.relative_to(ROOT)}`",
        f"- Generated at: {summary['generated_at']}",
        f"- Benchmarks: {summary['benchmarks']}",
        f"- Mismatches: {summary['mismatches']}",
        f"- Speedup geomean: {summary['geomean']:.3f}x",
        f"- Kinsn-bearing geomean: {kinsn_geomean}",
        f"- Wins / losses / ties: {summary['wins']} / {summary['losses']} / {summary['ties']}",
        f"- Matched/applied sites, median sample: {summary['matched_median']} / {summary['applied_median']}",
        f"- Matched/applied calls, all samples: {summary['matched_raw']} / {summary['applied_raw']}",
        f"- Code-size ratio geomean: {summary['code_geomean']:.3f}x",
        f"- Kinsn calls by name, all samples: {format_counter(summary['names'])}",
        "",
        "## Helpers/maps rerun",
        "",
        f"- Artifact: `{HELPERS.relative_to(ROOT)}`",
        f"- Generated at: {helper_summary['generated_at']}",
        f"- Benchmarks: {helper_summary['benchmarks']}",
        f"- Mismatches: {helper_summary['mismatches']}",
        f"- Speedup geomean: {helper_summary['geomean']:.3f}x",
        f"- Kinsn-bearing geomean: {helper_kinsn_geomean}",
        f"- Wins / losses / ties: {helper_summary['wins']} / {helper_summary['losses']} / {helper_summary['ties']}",
        f"- Matched/applied sites, median sample: {helper_summary['matched_median']} / {helper_summary['applied_median']}",
        f"- Matched/applied calls, all samples: {helper_summary['matched_raw']} / {helper_summary['applied_raw']}",
        f"- Code-size ratio geomean: {helper_summary['code_geomean']:.3f}x",
        f"- Kinsn calls by name, all samples: {format_counter(helper_summary['names'])}",
        "",
        "## Per-case results",
        "",
        "| Case | Kernel ns | Kernel ReJIT ns | Speedup | Applied median sample | Kinsn calls by name, all samples |",
        "|---|---:|---:|---:|---:|---|",
    ]
    for row in pure_rows:
        lines.append(
            f"| `{row['name']}` | {row['kernel_ns']:.0f} | {row['rejit_ns']:.0f} | "
            f"{row['speedup']:.3f}x | {row['applied_median']} | {format_counter(row['names'])} |"
        )
    SUMMARY.write_text("\n".join(lines) + "\n")
    return summary


def draw(rows: list[dict], summary: dict) -> None:
    FIG.mkdir(parents=True, exist_ok=True)
    labels = [SHORT_NAMES.get(row["name"], row["name"][:12]) for row in rows]
    values = [row["speedup"] for row in rows]
    colors = ["#2F8C6D" if row["applied_median"] else "#9AA0A6" for row in rows]

    fig, ax = plt.subplots(figsize=(15.5, 5.8))
    ax.bar(range(len(rows)), values, width=0.72, color=colors, edgecolor="#333333", linewidth=0.45)
    ax.axhline(1.0, color="#333333", linestyle="--", linewidth=1.0)
    ax.axhline(summary["geomean"], color="#C43B3B", linewidth=1.3)
    ax.text(
        len(rows) - 0.2,
        summary["geomean"] + 0.025,
        f"geomean {summary['geomean']:.3f}x",
        ha="right",
        va="bottom",
        color="#9B1C1C",
        fontsize=12,
    )
    for idx, row in enumerate(rows):
        if row["speedup"] >= 1.20 or row["speedup"] <= 0.98:
            ax.text(idx, row["speedup"] + 0.02, f"{row['speedup']:.2f}x", ha="center", fontsize=8)
    ax.set_title(
        "arm64 AWS kinsn ReJIT full micro (pure bytecode 29, SAMPLES=3)",
        fontsize=16,
        pad=10,
    )
    ax.set_ylabel("kernel / kernel_rejit speedup", fontsize=12)
    ax.set_xticks(range(len(rows)))
    ax.set_xticklabels(labels, rotation=48, ha="right", fontsize=10)
    ax.set_ylim(0.78, max(values) * 1.12)
    ax.yaxis.set_major_formatter(FuncFormatter(lambda value, _: f"{value:.2f}x"))
    ax.grid(axis="y", color="#eeeeee", linewidth=0.8)
    ax.text(
        0.01,
        0.97,
        f"median-sample applied {summary['applied_median']}; raw sample calls {summary['applied_raw']}",
        transform=ax.transAxes,
        ha="left",
        va="top",
        fontsize=11,
        color="#333333",
    )
    fig.tight_layout()
    fig.savefig(FIG / "kinsn-micro-arm64-rejit-20260606.png", dpi=180, bbox_inches="tight")
    plt.close(fig)


def main() -> None:
    if not PURE.exists():
        raise SystemExit(f"missing artifact: {PURE}")
    if not HELPERS.exists():
        raise SystemExit(f"missing artifact: {HELPERS}")
    data, rows = load_rows(PURE)
    helper_data, helper_rows = load_rows(HELPERS)
    summary = write_summary(data, rows, helper_data, helper_rows)
    draw(rows, summary)
    print(
        f"arm64 pure bytecode 29: geomean={summary['geomean']:.3f}x "
        f"applied_median={summary['applied_median']} applied_raw={summary['applied_raw']} "
        f"mismatches={summary['mismatches']}"
    )
    print(f"wrote {FIG / 'kinsn-micro-arm64-rejit-20260606.png'}")
    print(f"wrote {SUMMARY}")


if __name__ == "__main__":
    main()
