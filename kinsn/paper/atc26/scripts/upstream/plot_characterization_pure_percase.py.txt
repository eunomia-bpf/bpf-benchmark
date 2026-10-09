#!/usr/bin/env python3
"""Generate pure-bytecode per-case characterization figures for the paper."""

from __future__ import annotations

import json
import math
import statistics
from pathlib import Path

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter


PAPER = Path(__file__).resolve().parents[1]
REPO = PAPER.parents[1]
FIG = PAPER / "figures"

X86_PURE = REPO / "micro/results/x86_kvm_micro_20260526_210952_650695/details/result.json"
ARM64_PURE = REPO / "micro/results/aws_arm64_micro_20260606_063319_954947/details/result.json"

RUNTIME_COLORS = {
    "Kernel native": "#4C78A8",
    "Userspace eBPF": "#B279A2",
    "Userspace native": "#54A24B",
}

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


def load_rows(path: Path) -> list[tuple[str, dict[str, float]]]:
    if not path.exists():
        raise SystemExit(f"missing artifact: {path}")
    data = json.loads(path.read_text())
    rows = []
    for bench in data["benchmarks"]:
        medians = {}
        for run in bench["runs"]:
            values = [sample["exec_ns"] for sample in run["samples"] if "exec_ns" in sample]
            if values:
                medians[run["runtime"]] = statistics.median(values)
        kernel = medians.get("kernel")
        if not kernel:
            continue
        rows.append(
            (
                bench["name"],
                {
                    "Kernel native": kernel / medians["native_kernel"],
                    "Userspace eBPF": kernel / medians["llvmbpf"],
                    "Userspace native": kernel / medians["native"],
                },
            )
        )
    return rows


def geomean(values: list[float]) -> float:
    return math.exp(sum(math.log(value) for value in values) / len(values))


def draw_aggregate() -> None:
    groups = [
        ("x86 KVM\npure bytecode", load_rows(X86_PURE)),
        ("arm64 AWS\npure bytecode", load_rows(ARM64_PURE)),
    ]
    series = ["Kernel native", "Userspace eBPF", "Userspace native"]
    fig, ax = plt.subplots(figsize=(6.8, 4.4))
    width = 0.20
    for group_idx, (_, rows) in enumerate(groups):
        for series_idx, name in enumerate(series):
            offset = (series_idx - 1) * width
            speedup = geomean([entry[name] for _, entry in rows])
            ax.bar(
                group_idx + offset,
                speedup,
                width=width,
                color=RUNTIME_COLORS[name],
                edgecolor="#333333",
                linewidth=0.55,
                label=name if group_idx == 0 else None,
            )
            ax.text(group_idx + offset, speedup + 0.045, f"{speedup:.2f}x", ha="center", va="bottom", fontsize=9)

    ax.axhline(1.0, color="#333333", linestyle="--", linewidth=1.2)
    ax.set_xticks(range(len(groups)))
    ax.set_xticklabels([label for label, _ in groups], fontsize=10)
    ax.set_ylabel("Speedup over kernel eBPF JIT", fontsize=12)
    ax.set_title("Pure-bytecode aggregate speedup", fontsize=15, pad=10)
    ax.set_ylim(0, 2.45)
    ax.yaxis.set_major_formatter(FuncFormatter(lambda value, _: f"{value:.1f}x"))
    ax.tick_params(axis="y", labelsize=10)
    ax.grid(axis="y", color="#eeeeee", linewidth=0.8)
    ax.legend(frameon=False, ncol=3, loc="upper center", bbox_to_anchor=(0.5, 1.08), fontsize=10)
    fig.text(
        0.5,
        0.015,
        "Kernel eBPF is the normalized 1.0 baseline (dashed line). Higher is better.",
        ha="center",
        fontsize=9,
        color="#555555",
    )
    fig.tight_layout(rect=[0, 0.07, 1, 0.96])
    fig.savefig(FIG / "sec-3-pure-bytecode-aggregate-20260606.pdf", bbox_inches="tight")
    plt.close(fig)


def draw(path: Path, title: str, output: str) -> None:
    rows = load_rows(path)
    series = ["Kernel native", "Userspace eBPF", "Userspace native"]
    x_values = list(range(len(rows)))
    width = 0.25

    fig, ax = plt.subplots(figsize=(24.0, 5.9))
    for idx, name in enumerate(series):
        offset = (idx - 1) * width
        values = [entry[name] for _, entry in rows]
        ax.bar(
            [x + offset for x in x_values],
            values,
            width=width,
            color=RUNTIME_COLORS[name],
            edgecolor="#333333",
            linewidth=0.45,
            label=name,
        )

    ax.axhline(1.0, color="#333333", linestyle="--", linewidth=1.35)
    ax.set_xticks(x_values)
    ax.set_xticklabels([SHORT_NAMES.get(name, name[:12]) for name, _ in rows], rotation=52, ha="right", fontsize=14)
    ax.set_yscale("log")
    ax.set_ylim(0.28, 7.2)
    ax.set_yticks([0.33, 0.5, 0.75, 1.0, 1.5, 2.0, 3.0, 5.0, 7.0])
    ax.yaxis.set_major_formatter(FuncFormatter(lambda value, _: f"{value:g}x"))
    ax.tick_params(axis="y", labelsize=15)
    ax.grid(axis="y", color="#eeeeee", linewidth=0.9)
    ax.set_title(title, fontsize=20, pad=12)
    ax.set_ylabel("Speedup over kernel eBPF JIT", fontsize=16)

    handles, labels = ax.get_legend_handles_labels()
    fig.legend(handles, labels, loc="upper center", ncol=3, frameon=False, bbox_to_anchor=(0.5, 1.02), fontsize=16)
    fig.text(
        0.5,
        0.015,
        "Kernel eBPF is the normalized 1.0 baseline (dashed line). Higher is better; y-axis is log-scaled.",
        ha="center",
        fontsize=14,
        color="#555555",
    )
    fig.tight_layout(rect=[0, 0.08, 1, 0.92])
    fig.savefig(FIG / output, bbox_inches="tight")
    plt.close(fig)


def main() -> None:
    draw_aggregate()
    draw(X86_PURE, "x86 KVM pure bytecode cases", "sec-3-x86-pure-bytecode-percase-20260606.pdf")
    draw(ARM64_PURE, "arm64 AWS pure bytecode cases", "sec-3-arm64-pure-bytecode-percase-20260606.pdf")
    print(f"wrote {FIG / 'sec-3-pure-bytecode-aggregate-20260606.pdf'}")
    print(f"wrote {FIG / 'sec-3-x86-pure-bytecode-percase-20260606.pdf'}")
    print(f"wrote {FIG / 'sec-3-arm64-pure-bytecode-percase-20260606.pdf'}")


if __name__ == "__main__":
    main()
