#!/usr/bin/env python3
"""Generate kop microbenchmark figures from local raw result.json artifacts."""

from __future__ import annotations

import json
import math
import statistics
from pathlib import Path

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter


ROOT = Path(__file__).resolve().parents[2]
FIG = ROOT / "docs" / "figures"

BEST_RAW_KOP = ROOT / "micro/results/x86_kvm_micro_20260519_114214_364050/details/result.json"
LATEST_STOCK_KERNEL = ROOT / "micro/results/x86_kvm_micro_20260526_210351_224315/details/result.json"

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


def load(path: Path) -> dict:
    return json.loads(path.read_text())


def median_exec_ns(data: dict, runtime: str = "kernel") -> dict[str, float]:
    rows = {}
    for bench in data["benchmarks"]:
        for run in bench["runs"]:
            if run["runtime"] != runtime:
                continue
            rows[bench["name"]] = statistics.median(sample["exec_ns"] for sample in run["samples"])
            break
    return rows


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


def geomean(values: list[float]) -> float:
    return math.exp(sum(math.log(value) for value in values) / len(values))


def short_name(name: str) -> str:
    return SHORT_NAMES.get(name, name[:12])


def best_raw_rows() -> list[tuple[float, str, float, float]]:
    kop = median_exec_ns(load(BEST_RAW_KOP))
    stock = median_exec_ns(load(LATEST_STOCK_KERNEL))
    rows = []
    for name in sorted(set(kop) & set(stock)):
        rows.append((stock[name] / kop[name], name, stock[name], kop[name]))
    rows.sort(reverse=True)
    return rows


def draw_upper_bound_summary() -> None:
    rows = best_raw_rows()
    top_rows = rows[:5]
    all_geomean = geomean([speedup for speedup, _, _, _ in rows])

    labels = [short_name(name) for _, name, _, _ in top_rows] + ["all-29\ngeomean"]
    values = [speedup for speedup, _, _, _ in top_rows] + [all_geomean]

    fig, ax = plt.subplots(figsize=(9.5, 4.8))
    x_values = list(range(len(labels)))
    bars = ax.bar(
        x_values,
        values,
        width=0.58,
        color="#4C78A8",
        edgecolor="#333333",
        linewidth=0.6,
    )
    bars[-1].set_color("#F58518")
    for idx, value in enumerate(values):
        ax.text(idx, value + 0.035, f"{value:.2f}x", ha="center", va="bottom", fontsize=11)

    ax.axhline(1.0, color="#333333", linestyle="--", linewidth=1.2)
    ax.set_xticks(x_values)
    ax.set_xticklabels(labels, fontsize=12)
    ax.set_ylabel("Speedup over stock kernel eBPF", fontsize=13)
    ax.set_title("LLVM-kop upper-bound microbenchmark effect", fontsize=16, pad=10)
    ax.set_ylim(0.75, max(values) * 1.24)
    ax.yaxis.set_major_formatter(FuncFormatter(lambda value, _: f"{value:.1f}x"))
    ax.tick_params(axis="y", labelsize=11)
    ax.grid(axis="y", color="#eeeeee", linewidth=0.8)
    ax.text(
        0.5,
        -0.18,
        "Best local raw LLVM-kop candidate vs latest stock-kernel run. Median exec_ns over 3 samples; INNER_REPEAT=100000.",
        transform=ax.transAxes,
        ha="center",
        fontsize=10,
        color="#555555",
    )
    fig.tight_layout(rect=[0, 0.05, 1, 1])
    fig.savefig(FIG / "kop-micro-upper-bound-summary-20260527.png", dpi=180, bbox_inches="tight")
    plt.close(fig)


def draw_best_raw_full() -> None:
    rows = best_raw_rows()
    speedups = [value for value, _, _, _ in rows]
    labels = [short_name(name) for _, name, _, _ in rows]
    gm = geomean(speedups)

    fig, ax = plt.subplots(figsize=(17.2, 5.0))
    colors = ["#4C78A8" if value >= 1.0 else "#B279A2" for value in speedups]
    bars = ax.bar(
        range(len(rows)),
        speedups,
        width=0.72,
        color=colors,
        edgecolor="#333333",
        linewidth=0.45,
    )
    ax.axhline(1.0, color="#333333", linestyle="--", linewidth=1.2)
    ax.axhline(gm, color="#E45756", linestyle="-", linewidth=1.4)
    ax.text(len(rows) - 0.2, gm + 0.025, f"geomean {gm:.2f}x", ha="right", va="bottom", color="#B22222", fontsize=12)
    for bar, value in zip(bars, speedups):
        if value >= 1.45 or value < 0.9:
            ax.text(
                bar.get_x() + bar.get_width() / 2,
                value + 0.035,
                f"{value:.2f}x",
                ha="center",
                va="bottom",
                fontsize=9,
            )

    ax.set_xticks(range(len(rows)))
    ax.set_xticklabels(labels, rotation=52, ha="right", fontsize=11)
    ax.set_ylabel("Speedup over latest stock kernel eBPF", fontsize=13)
    ax.set_title("Best local raw LLVM-kop full-suite candidate", fontsize=17, pad=10)
    ax.set_ylim(0, max(speedups) * 1.2)
    ax.yaxis.set_major_formatter(FuncFormatter(lambda value, _: f"{value:.1f}x"))
    ax.tick_params(axis="y", labelsize=11)
    ax.grid(axis="y", color="#eeeeee", linewidth=0.8)
    ax.text(
        0.5,
        -0.24,
        "Median exec_ns over 3 samples, INNER_REPEAT=100000. Baseline is latest stock-kernel run; this raw candidate lacks an exact matched compiler-control run.",
        transform=ax.transAxes,
        ha="center",
        fontsize=10,
        color="#555555",
    )
    fig.tight_layout(rect=[0, 0.09, 1, 1])
    fig.savefig(FIG / "kop-micro-best-raw-full-20260527.png", dpi=180, bbox_inches="tight")
    plt.close(fig)


def main() -> None:
    for path in [BEST_RAW_KOP, LATEST_STOCK_KERNEL]:
        if not path.exists():
            raise SystemExit(f"missing artifact: {path}")
    if correctness_mismatches(load(BEST_RAW_KOP)):
        raise SystemExit("best raw kop artifact has correctness mismatches")
    draw_upper_bound_summary()
    draw_best_raw_full()


if __name__ == "__main__":
    main()
