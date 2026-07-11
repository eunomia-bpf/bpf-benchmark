#!/usr/bin/env python3
"""Post-hoc arm64 kop microbenchmark analysis for 2026-06-05 artifacts."""

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
SUMMARY = ROOT / "docs" / "tmp" / "arm64_kop_micro_20260605_summary.md"

PURE = ROOT / "micro/results/aws_arm64_micro_20260605_195615_598255/details/result.json"
STAGE2 = ROOT / "micro/results/aws_arm64_micro_20260605_201826_257732/details/result.json"

ARTIFACTS = [
    ("pure bytecode 29", PURE),
    ("with helpers/maps 13", STAGE2),
]

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
    "helper_only_uid_gid": "uid_gid",
    "helper_chain_simple": "helpers",
    "map_array_lookup": "array",
    "map_array_index_packet": "array_pkt",
    "map_hash_lookup": "hash",
    "map_hash_str_key": "hash_str",
    "map_percpu_array": "percpu_arr",
    "map_lru_hash_counter": "lru_hash",
    "map_percpu_hash_counter": "percpu_hash",
    "combined_helper_map": "helper_map",
    "multi_map_policy": "multi_map",
    "packet_5tuple_classify": "5tuple_map",
    "stats_mixed_helpers": "mixed",
}


def load(path: Path) -> dict:
    return json.loads(path.read_text())


def geomean(values: list[float]) -> float:
    return math.exp(sum(math.log(value) for value in values) / len(values))


def short_name(name: str) -> str:
    return SHORT_NAMES.get(name, name[:12])


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


def sample_kop_counts(sample: dict) -> tuple[int, int, Counter[str], Counter[str]]:
    matched = 0
    applied = 0
    families: Counter[str] = Counter()
    names: Counter[str] = Counter()
    for program in (sample.get("rejit_result") or {}).get("per_program", {}).values():
        for pass_result in program.get("passes", []):
            summary = pass_result.get("bpfopt_summary") or {}
            if summary.get("pass") != "kop":
                continue
            matched += int(summary.get("sites_matched") or 0)
            applied += int(summary.get("sites_applied") or 0)
            families.update(summary.get("kop_calls_by_family") or {})
            names.update(summary.get("kop_calls_by_name") or {})
    return matched, applied, families, names


def median_int(values: list[int]) -> int:
    return int(statistics.median(values)) if values else 0


def suite_rows(data: dict) -> list[dict]:
    rows = []
    for bench in data["benchmarks"]:
        runtimes = {run["runtime"]: run for run in bench["runs"]}
        if "kernel" not in runtimes or "kernel_rejit" not in runtimes:
            continue
        kernel_samples = runtimes["kernel"]["samples"]
        rejit_samples = runtimes["kernel_rejit"]["samples"]
        kernel_ns = statistics.median(sample["exec_ns"] for sample in kernel_samples)
        rejit_ns = statistics.median(sample["exec_ns"] for sample in rejit_samples)
        kernel_code = statistics.median(
            sample.get("code_size", {}).get("native_code_bytes", sample.get("jited_prog_len", 0))
            for sample in kernel_samples
        )
        rejit_code = statistics.median(
            sample.get("code_size", {}).get("native_code_bytes", sample.get("jited_prog_len", 0))
            for sample in rejit_samples
        )
        matched_values = []
        applied_values = []
        family_counts: Counter[str] = Counter()
        name_counts: Counter[str] = Counter()
        for sample in rejit_samples:
            matched, applied, families, names = sample_kop_counts(sample)
            matched_values.append(matched)
            applied_values.append(applied)
            family_counts.update(families)
            name_counts.update(names)
        rows.append(
            {
                "name": bench["name"],
                "kernel_ns": kernel_ns,
                "rejit_ns": rejit_ns,
                "speedup": kernel_ns / rejit_ns,
                "kernel_code": kernel_code,
                "rejit_code": rejit_code,
                "code_ratio": rejit_code / kernel_code if kernel_code else 1.0,
                "matched": median_int(matched_values),
                "applied": median_int(applied_values),
                "families": family_counts,
                "names": name_counts,
            }
        )
    return rows


def suite_summary(label: str, path: Path) -> dict:
    data = load(path)
    rows = suite_rows(data)
    speedups = [row["speedup"] for row in rows]
    code_ratios = [row["code_ratio"] for row in rows if row["kernel_code"]]
    return {
        "label": label,
        "path": path,
        "data": data,
        "rows": rows,
        "mismatches": correctness_mismatches(data),
        "geomean": geomean(speedups),
        "code_geomean": geomean(code_ratios),
        "wins": sum(value > 1.02 for value in speedups),
        "losses": sum(value < 0.98 for value in speedups),
        "ties": sum(0.98 <= value <= 1.02 for value in speedups),
        "total_applied": sum(row["applied"] for row in rows),
        "total_matched": sum(row["matched"] for row in rows),
        "families": sum((row["families"] for row in rows), Counter()),
        "names": sum((row["names"] for row in rows), Counter()),
    }


def draw(summaries: list[dict]) -> None:
    FIG.mkdir(parents=True, exist_ok=True)
    fig, axes = plt.subplots(2, 1, figsize=(15.5, 8.2), sharey=False)
    for ax, summary in zip(axes, summaries):
        rows = summary["rows"]
        labels = [short_name(row["name"]) for row in rows]
        values = [row["speedup"] for row in rows]
        colors = ["#4C78A8" if row["applied"] else "#9AA0A6" for row in rows]
        ax.bar(range(len(rows)), values, width=0.72, color=colors, edgecolor="#333333", linewidth=0.45)
        ax.axhline(1.0, color="#333333", linestyle="--", linewidth=1.1)
        ax.axhline(summary["geomean"], color="#E45756", linewidth=1.25)
        ax.text(
            len(rows) - 0.2,
            summary["geomean"] + 0.008,
            f"geomean {summary['geomean']:.3f}x",
            ha="right",
            va="bottom",
            color="#B22222",
            fontsize=11,
        )
        for idx, row in enumerate(rows):
            if row["speedup"] > 1.05 or row["speedup"] < 0.94 or row["applied"]:
                ax.text(idx, row["speedup"] + 0.012, f"{row['speedup']:.2f}x", ha="center", fontsize=8)
        ax.set_xticks(range(len(rows)))
        ax.set_xticklabels(labels, rotation=50, ha="right", fontsize=10)
        ax.set_ylabel("kernel / kernel_rejit", fontsize=12)
        ax.set_title(
            f"arm64 AWS kop ReJIT: {summary['label']} "
            f"(applied sites: {summary['total_applied']})",
            fontsize=15,
            pad=8,
        )
        ymin = min(0.88, min(values) * 0.96)
        ymax = max(1.12, max(values) * 1.10)
        ax.set_ylim(ymin, ymax)
        ax.yaxis.set_major_formatter(FuncFormatter(lambda value, _: f"{value:.2f}x"))
        ax.grid(axis="y", color="#eeeeee", linewidth=0.8)
    fig.suptitle("Matched arm64 kop microbenchmark follow-up (AWS t4g.small, SAMPLES=3)", fontsize=18)
    fig.tight_layout(rect=[0, 0, 1, 0.96])
    fig.savefig(FIG / "kop-micro-arm64-rejit-20260605.png", dpi=180, bbox_inches="tight")
    plt.close(fig)


def format_counter(counter: Counter[str]) -> str:
    if not counter:
        return "-"
    return ", ".join(f"{name}={count}" for name, count in counter.most_common())


def write_summary(summaries: list[dict]) -> None:
    lines = [
        "# arm64 kop micro 2026-06-05",
        "",
        "| Suite | Result source | Benchmarks | Mismatches | Speedup geomean | Wins / losses / ties | Matched sites | Applied sites | Code-size ratio |",
        "|---|---|---:|---:|---:|---:|---:|---:|---:|",
    ]
    for summary in summaries:
        rel = summary["path"].relative_to(ROOT)
        lines.append(
            f"| {summary['label']} | `{rel}` | {len(summary['rows'])} | {summary['mismatches']} | "
            f"{summary['geomean']:.3f}x | {summary['wins']} / {summary['losses']} / {summary['ties']} | "
            f"{summary['total_matched']} | {summary['total_applied']} | {summary['code_geomean']:.3f}x |"
        )
    lines.extend(["", "## KOperation coverage", ""])
    for summary in summaries:
        lines.extend(
            [
                f"- {summary['label']}: families {format_counter(summary['families'])}; names {format_counter(summary['names'])}",
            ]
        )
    lines.extend(["", "## Top per-case speedups", ""])
    for summary in summaries:
        lines.append(f"### {summary['label']}")
        lines.append("")
        lines.append("| Case | Kernel ns | Kernel ReJIT ns | Speedup | Applied sites |")
        lines.append("|---|---:|---:|---:|---:|")
        for row in sorted(summary["rows"], key=lambda item: item["speedup"], reverse=True)[:8]:
            lines.append(
                f"| `{row['name']}` | {row['kernel_ns']:.0f} | {row['rejit_ns']:.0f} | "
                f"{row['speedup']:.3f}x | {row['applied']} |"
            )
        lines.append("")
    lines.extend(["## Worst per-case speedups", ""])
    for summary in summaries:
        lines.append(f"### {summary['label']}")
        lines.append("")
        lines.append("| Case | Kernel ns | Kernel ReJIT ns | Speedup | Applied sites |")
        lines.append("|---|---:|---:|---:|---:|")
        for row in sorted(summary["rows"], key=lambda item: item["speedup"])[:8]:
            lines.append(
                f"| `{row['name']}` | {row['kernel_ns']:.0f} | {row['rejit_ns']:.0f} | "
                f"{row['speedup']:.3f}x | {row['applied']} |"
            )
        lines.append("")
    SUMMARY.write_text("\n".join(lines) + "\n")


def main() -> None:
    for _, path in ARTIFACTS:
        if not path.exists():
            raise SystemExit(f"missing artifact: {path}")
    summaries = [suite_summary(label, path) for label, path in ARTIFACTS]
    draw(summaries)
    write_summary(summaries)
    for summary in summaries:
        print(
            f"{summary['label']}: geomean={summary['geomean']:.3f}x "
            f"applied={summary['total_applied']} mismatches={summary['mismatches']}"
        )
    print(f"wrote {FIG / 'kop-micro-arm64-rejit-20260605.png'}")
    print(f"wrote {SUMMARY}")


if __name__ == "__main__":
    main()
