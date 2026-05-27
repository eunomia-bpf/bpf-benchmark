#!/usr/bin/env python3
"""Generate the micro characterization figures used by docs/micro-bench-status.md.

This is an analysis-side script. It reads raw micro result.json artifacts and
writes PNG figures under docs/figures.
"""

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

X86_PURE_BYTECODE = ROOT / "micro/results/x86_kvm_micro_20260526_210952_650695/details/result.json"
X86_WITH_HELPERS = ROOT / "micro/results/x86_kvm_micro_20260526_210434_440390/details/result.json"
ARM_PURE_BYTECODE = ROOT / "micro/results/aws_arm64_micro_20260523_091516_610343/details/result.json"
ARM_WITH_HELPERS = ROOT / "micro/results/aws_arm64_micro_20260523_092823_183684/details/result.json"

RUNTIME_LABELS = {
    "native_kernel": "Kernel native",
    "llvmbpf": "Userspace eBPF",
    "native": "Userspace native",
}
RUNTIME_COLORS = {
    "native_kernel": "#4C78A8",
    "llvmbpf": "#B279A2",
    "native": "#54A24B",
}
RUNTIME_ORDER = ["native_kernel", "llvmbpf", "native"]

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
    "helper_chain_simple": "helper",
    "map_array_lookup": "array",
    "map_array_index_packet": "array_idx",
    "map_hash_lookup": "hash",
    "map_hash_str_key": "hash_str",
    "map_percpu_array": "pcpu_arr",
    "map_lru_hash_counter": "lru",
    "map_percpu_hash_counter": "pcpu_hash",
    "combined_helper_map": "combined",
    "multi_map_policy": "multi_map",
    "packet_5tuple_classify": "classify",
    "stats_mixed_helpers": "mixed",
}


def load_result(path: Path) -> dict:
    return json.loads(path.read_text())


def geomean(values: list[float]) -> float:
    return math.exp(sum(math.log(value) for value in values) / len(values))


def benchmark_medians(data: dict, field: str = "exec_ns") -> list[tuple[str, dict[str, float]]]:
    rows = []
    for bench in data["benchmarks"]:
        medians = {}
        for run in bench["runs"]:
            values = []
            for sample in run["samples"]:
                if field == "exec_ns" and "exec_ns" in sample:
                    values.append(sample["exec_ns"])
                elif field == "code_size":
                    code_size = sample.get("code_size") or {}
                    if "native_code_bytes" in code_size:
                        values.append(code_size["native_code_bytes"])
            if values:
                medians[run["runtime"]] = statistics.median(values)
        rows.append((bench["name"], medians))
    return rows


def speedup(data: dict, runtime: str) -> float:
    ratios = []
    for _, medians in benchmark_medians(data):
        kernel = medians.get("kernel")
        runtime_value = medians.get(runtime)
        if kernel and runtime_value:
            ratios.append(runtime_value / kernel)
    return 1.0 / geomean(ratios)


def code_size_ratio(data: dict, runtime: str = "native_kernel") -> float:
    ratios = []
    for _, medians in benchmark_medians(data, field="code_size"):
        kernel = medians.get("kernel")
        runtime_value = medians.get(runtime)
        if kernel and runtime_value:
            ratios.append(runtime_value / kernel)
    return geomean(ratios)


def per_case_speedups(data: dict, include_userspace: bool) -> list[tuple[str, dict[str, float]]]:
    rows = []
    for name, medians in benchmark_medians(data):
        kernel = medians.get("kernel")
        if not kernel:
            continue
        values = {}
        if medians.get("native_kernel"):
            values["Kernel native"] = kernel / medians["native_kernel"]
        if include_userspace and medians.get("llvmbpf"):
            values["Userspace eBPF"] = kernel / medians["llvmbpf"]
        if include_userspace and medians.get("native"):
            values["Userspace native"] = kernel / medians["native"]
        rows.append((name, values))
    return rows


def short_name(name: str) -> str:
    return SHORT_NAMES.get(name, name[:12])


def draw_aggregate() -> None:
    artifacts = [
        ("x86 KVM", "Pure bytecode", X86_PURE_BYTECODE, ["native_kernel", "llvmbpf", "native"]),
        ("x86 KVM", "With helpers/maps", X86_WITH_HELPERS, ["native_kernel"]),
        ("arm64 AWS", "Pure bytecode", ARM_PURE_BYTECODE, ["native_kernel"]),
        ("arm64 AWS", "With helpers/maps", ARM_WITH_HELPERS, ["native_kernel"]),
    ]
    group_labels = [f"{platform}\n{suite}" for platform, suite, _, _ in artifacts]
    rows = []
    for _, _, path, runtimes in artifacts:
        data = load_result(path)
        rows.append([(runtime, speedup(data, runtime)) for runtime in RUNTIME_ORDER if runtime in runtimes])

    fig, ax = plt.subplots(figsize=(8.2, 4.6))
    group_width = 0.50
    bar_width = 0.20
    for idx, row in enumerate(rows):
        if len(row) == 1:
            offsets = [0.0]
        else:
            offsets = [
                (-group_width / 2.0) + (i + 0.5) * (group_width / len(row))
                for i in range(len(row))
            ]
        for offset, (runtime, value) in zip(offsets, row):
            ax.bar(
                idx + offset,
                value,
                width=min(bar_width, group_width / max(len(row), 1) * 0.78),
                color=RUNTIME_COLORS[runtime],
                edgecolor="#333333",
                linewidth=0.55,
            )
            ax.text(idx + offset, value + 0.045, f"{value:.2f}x", ha="center", va="bottom", fontsize=9)

    handles = [
        plt.Rectangle((0, 0), 1, 1, color=RUNTIME_COLORS[runtime], ec="#333333")
        for runtime in RUNTIME_ORDER
    ]
    labels = [RUNTIME_LABELS[runtime] for runtime in RUNTIME_ORDER]
    ax.axhline(1.0, color="#333333", linestyle="--", linewidth=1.2)
    ax.set_xticks(range(len(group_labels)))
    ax.set_xticklabels(group_labels, fontsize=10)
    ax.set_ylabel("Speedup over kernel eBPF JIT", fontsize=12)
    ax.set_title("Microbenchmark aggregate speedup over kernel eBPF JIT", fontsize=15, pad=10)
    max_value = max(value for row in rows for _, value in row)
    ax.set_ylim(0, max_value * 1.28)
    ax.yaxis.set_major_formatter(FuncFormatter(lambda value, _: f"{value:.1f}x"))
    ax.tick_params(axis="y", labelsize=10)
    ax.grid(axis="y", color="#eeeeee", linewidth=0.8)
    ax.legend(handles, labels, frameon=False, ncol=3, loc="upper center", bbox_to_anchor=(0.5, 1.04), fontsize=10)
    ax.text(
        0.5,
        -0.18,
        "Kernel eBPF is the normalized 1.0 baseline (dashed line). With helpers/maps and arm64 report kernel native only.",
        transform=ax.transAxes,
        ha="center",
        fontsize=9,
        color="#555555",
    )
    fig.tight_layout(rect=[0, 0.05, 1, 1])
    fig.savefig(FIG / "micro-characterization-runtime-aggregate-20260527.png", dpi=180, bbox_inches="tight")
    plt.close(fig)


def plot_per_case_panel(ax, rows: list[tuple[str, dict[str, float]]], title: str, series: list[tuple[str, str]]) -> None:
    x_values = list(range(len(rows)))
    width = 0.58 if len(series) == 1 else 0.25
    offsets = [0.0] if len(series) == 1 else [(i - (len(series) - 1) / 2.0) * width for i in range(len(series))]
    for offset, (name, color) in zip(offsets, series):
        values = [entry[name] for _, entry in rows]
        ax.bar(
            [x + offset for x in x_values],
            values,
            width=width,
            color=color,
            edgecolor="#333333",
            linewidth=0.45,
            label=name,
        )
    ax.axhline(1.0, color="#333333", linestyle="--", linewidth=1.35)
    ax.set_xticks(x_values)
    ax.set_xticklabels([short_name(name) for name, _ in rows], rotation=52, ha="right", fontsize=14)
    ax.set_yscale("log")
    ax.set_ylim(0.65 if len(series) == 1 else 0.28, 5.2)
    ticks = [0.75, 1.0, 1.25, 1.5, 2.0, 3.0, 5.0] if len(series) == 1 else [0.33, 0.5, 0.75, 1.0, 1.5, 2.0, 3.0, 5.0]
    ax.set_yticks(ticks)
    ax.yaxis.set_major_formatter(FuncFormatter(lambda value, _: f"{value:g}x"))
    ax.tick_params(axis="y", labelsize=15)
    ax.grid(axis="y", color="#eeeeee", linewidth=0.9)
    ax.set_title(title, fontsize=20, pad=12)
    ax.set_ylabel("Speedup over kernel eBPF JIT", fontsize=16)


def draw_x86_per_case() -> None:
    pure_bytecode = per_case_speedups(load_result(X86_PURE_BYTECODE), include_userspace=True)
    with_helpers = per_case_speedups(load_result(X86_WITH_HELPERS), include_userspace=False)
    fig, axes = plt.subplots(2, 1, figsize=(24.0, 10.8), gridspec_kw={"height_ratios": [1.15, 0.85]})
    plot_per_case_panel(
        axes[0],
        pure_bytecode,
        "Pure bytecode cases",
        [
            ("Kernel native", RUNTIME_COLORS["native_kernel"]),
            ("Userspace eBPF", RUNTIME_COLORS["llvmbpf"]),
            ("Userspace native", RUNTIME_COLORS["native"]),
        ],
    )
    plot_per_case_panel(
        axes[1],
        with_helpers,
        "With helpers/maps cases",
        [("Kernel native", RUNTIME_COLORS["native_kernel"])],
    )

    handles = []
    labels = []
    for ax in axes:
        ax_handles, ax_labels = ax.get_legend_handles_labels()
        for handle, label in zip(ax_handles, ax_labels):
            if label not in labels:
                handles.append(handle)
                labels.append(label)
    fig.legend(handles, labels, loc="upper center", ncol=3, frameon=False, bbox_to_anchor=(0.5, 1.005), fontsize=18)
    fig.suptitle("x86 KVM microbenchmark characterization", y=1.05, fontsize=25)
    fig.text(
        0.5,
        0.012,
        "Kernel eBPF is the normalized 1.0 baseline (dashed line). With helpers/maps only reports kernel native because helper/map-heavy programs must be evaluated against the real kernel helper/map ABI. Higher is better; y-axis is log-scaled.",
        ha="center",
        fontsize=15,
        color="#555555",
    )
    fig.tight_layout(rect=[0, 0.06, 1, 0.965])
    fig.savefig(FIG / "micro-characterization-x86-four-way-percase-vertical-20260527.png", dpi=180, bbox_inches="tight")
    plt.close(fig)


def draw_arm64_per_case() -> None:
    pure_bytecode = per_case_speedups(load_result(ARM_PURE_BYTECODE), include_userspace=False)
    with_helpers = per_case_speedups(load_result(ARM_WITH_HELPERS), include_userspace=False)
    fig, axes = plt.subplots(2, 1, figsize=(24.0, 10.8), gridspec_kw={"height_ratios": [1.15, 0.85]})
    plot_per_case_panel(
        axes[0],
        pure_bytecode,
        "Pure bytecode cases",
        [("Kernel native", RUNTIME_COLORS["native_kernel"])],
    )
    plot_per_case_panel(
        axes[1],
        with_helpers,
        "With helpers/maps cases",
        [("Kernel native", RUNTIME_COLORS["native_kernel"])],
    )
    handles, labels = axes[0].get_legend_handles_labels()
    fig.legend(handles, labels, loc="upper center", ncol=1, frameon=False, bbox_to_anchor=(0.5, 1.005), fontsize=18)
    fig.suptitle("arm64 AWS kernel-native microbenchmark characterization", y=1.05, fontsize=25)
    fig.text(
        0.5,
        0.012,
        "Kernel eBPF is the normalized 1.0 baseline (dashed line). Higher is better; y-axis is log-scaled.",
        ha="center",
        fontsize=16,
        color="#555555",
    )
    fig.tight_layout(rect=[0, 0.052, 1, 0.965])
    fig.savefig(FIG / "micro-characterization-arm64-kernel-native-percase-vertical-20260527.png", dpi=180, bbox_inches="tight")
    plt.close(fig)


def draw_code_size() -> None:
    artifacts = [
        ("x86 KVM", "Pure bytecode", X86_PURE_BYTECODE, ["native_kernel", "llvmbpf", "native"]),
        ("x86 KVM", "With helpers/maps", X86_WITH_HELPERS, ["native_kernel"]),
        ("arm64 AWS", "Pure bytecode", ARM_PURE_BYTECODE, ["native_kernel"]),
        ("arm64 AWS", "With helpers/maps", ARM_WITH_HELPERS, ["native_kernel"]),
    ]
    rows = []
    for _, _, path, runtimes in artifacts:
        data = load_result(path)
        rows.append([(runtime, code_size_ratio(data, runtime)) for runtime in RUNTIME_ORDER if runtime in runtimes])

    group_labels = [f"{platform}\n{suite}" for platform, suite, _, _ in artifacts]
    fig, ax = plt.subplots(figsize=(8.2, 4.6))
    group_width = 0.50
    bar_width = 0.20
    for idx, row in enumerate(rows):
        if len(row) == 1:
            offsets = [0.0]
        else:
            offsets = [
                (-group_width / 2.0) + (i + 0.5) * (group_width / len(row))
                for i in range(len(row))
            ]
        for offset, (runtime, value) in zip(offsets, row):
            ax.bar(
                idx + offset,
                value,
                width=min(bar_width, group_width / max(len(row), 1) * 0.78),
                color=RUNTIME_COLORS[runtime],
                edgecolor="#333333",
                linewidth=0.55,
            )
            ax.text(idx + offset, value + 0.025, f"{value:.2f}x", ha="center", va="bottom", fontsize=9)

    handles = [
        plt.Rectangle((0, 0), 1, 1, color=RUNTIME_COLORS[runtime], ec="#333333")
        for runtime in RUNTIME_ORDER
    ]
    labels = [RUNTIME_LABELS[runtime] for runtime in RUNTIME_ORDER]
    ax.axhline(1.0, color="#333333", linewidth=1.0, linestyle="--")
    ax.set_xticks(range(len(group_labels)))
    ax.set_xticklabels(group_labels, fontsize=10)
    ax.set_ylabel("Machine-code size / kernel eBPF JIT size", fontsize=12)
    ax.set_title("Microbenchmark machine-code size ratio", fontsize=15, pad=10)
    ax.set_ylim(0, 1.15)
    ax.yaxis.set_major_formatter(FuncFormatter(lambda value, _: f"{value:.1f}x"))
    ax.tick_params(axis="y", labelsize=10)
    ax.grid(axis="y", color="#eeeeee", linewidth=0.8)
    ax.legend(handles, labels, frameon=False, ncol=3, loc="upper center", bbox_to_anchor=(0.5, 1.04), fontsize=10)
    ax.text(
        0.5,
        -0.18,
        "Kernel eBPF JIT is the normalized 1.0 baseline (dashed line). Lower is smaller; with helpers/maps and arm64 report kernel native only.",
        transform=ax.transAxes,
        ha="center",
        fontsize=9,
        color="#555555",
    )
    fig.tight_layout(rect=[0, 0.05, 1, 1])
    fig.savefig(FIG / "micro-characterization-code-size-20260527.png", dpi=180, bbox_inches="tight")
    plt.close(fig)


def main() -> None:
    FIG.mkdir(parents=True, exist_ok=True)
    draw_aggregate()
    draw_x86_per_case()
    draw_arm64_per_case()
    draw_code_size()


if __name__ == "__main__":
    main()
