#!/usr/bin/env python3
"""Generate the 2026-06-06 micro characterization figures.

This is an analysis-side script. It reads raw micro result.json artifacts and
writes PNG figures under docs/figures plus a small markdown summary under
docs/tmp.
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
SUMMARY = ROOT / "docs" / "tmp" / "micro_characterization_20260606_summary.md"

X86_PURE_BYTECODE = ROOT / "micro/results/x86_kvm_micro_20260526_210952_650695/details/result.json"
X86_WITH_HELPERS = ROOT / "micro/results/x86_kvm_micro_20260526_210434_440390/details/result.json"
ARM_PURE_BYTECODE = ROOT / "micro/results/aws_arm64_micro_20260606_063319_954947/details/result.json"
ARM_WITH_HELPERS = ROOT / "micro/results/aws_arm64_micro_20260606_084130_711782/details/result.json"

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

ARTIFACTS = [
    ("x86 KVM", "pure bytecode 29", X86_PURE_BYTECODE, ["native_kernel", "llvmbpf", "native"]),
    ("x86 KVM", "with helpers/maps 13", X86_WITH_HELPERS, ["native_kernel"]),
    ("arm64 AWS", "pure bytecode 29", ARM_PURE_BYTECODE, ["native_kernel", "llvmbpf", "native"]),
    ("arm64 AWS", "with helpers/maps 13", ARM_WITH_HELPERS, ["native_kernel"]),
]


def load_result(path: Path) -> dict:
    return json.loads(path.read_text())


def geomean(values: list[float]) -> float:
    return math.exp(sum(math.log(value) for value in values) / len(values))


def percentile(values: list[float], pct: float) -> float:
    ordered = sorted(values)
    return ordered[int(pct * (len(ordered) - 1))]


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


def ratio_geomean(data: dict, runtime: str) -> float:
    ratios = []
    for _, medians in benchmark_medians(data):
        kernel = medians.get("kernel")
        runtime_value = medians.get(runtime)
        if kernel and runtime_value:
            ratios.append(runtime_value / kernel)
    return geomean(ratios)


def code_size_ratio(data: dict, runtime: str) -> float:
    ratios = []
    for _, medians in benchmark_medians(data, field="code_size"):
        kernel = medians.get("kernel")
        runtime_value = medians.get(runtime)
        if kernel and runtime_value:
            ratios.append(runtime_value / kernel)
    return geomean(ratios)


def wins_losses_ties(data: dict, runtime: str) -> tuple[int, int, int]:
    wins = losses = ties = 0
    for _, medians in benchmark_medians(data):
        kernel = medians.get("kernel")
        runtime_value = medians.get(runtime)
        if not kernel or not runtime_value:
            continue
        ratio = runtime_value / kernel
        if ratio < 0.98:
            wins += 1
        elif ratio > 1.02:
            losses += 1
        else:
            ties += 1
    return wins, losses, ties


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


def runtime_cv_summary(data: dict, runtimes: list[str]) -> tuple[int, float, float, float, int]:
    included = {"kernel", *runtimes}
    cvs = []
    within2 = 0
    for bench in data["benchmarks"]:
        for run in bench["runs"]:
            if run["runtime"] not in included:
                continue
            values = [sample["exec_ns"] for sample in run["samples"] if "exec_ns" in sample]
            if len(values) < 2:
                continue
            mean = statistics.mean(values)
            if not mean:
                continue
            cv = statistics.stdev(values) / mean
            cvs.append(cv)
            median = statistics.median(values)
            if all(abs(value - median) <= 0.02 * median for value in values):
                within2 += 1
    return len(cvs), statistics.median(cvs), percentile(cvs, 0.95), max(cvs), within2


def draw_grouped_bars(filename: str, ylabel: str, title: str, values_fn, ylimit: float, lower_is_better: bool) -> None:
    rows = []
    group_labels = []
    for platform, suite, path, runtimes in ARTIFACTS:
        data = load_result(path)
        group_labels.append(f"{platform}\n{suite.replace(' 29', '').replace(' 13', '')}")
        rows.append([(runtime, values_fn(data, runtime)) for runtime in RUNTIME_ORDER if runtime in runtimes])

    fig, ax = plt.subplots(figsize=(8.7, 4.8))
    group_width = 0.56
    bar_width = 0.20
    for idx, row in enumerate(rows):
        if len(row) == 1:
            offsets = [0.0]
        else:
            offsets = [(-group_width / 2.0) + (i + 0.5) * (group_width / len(row)) for i in range(len(row))]
        for offset, (runtime, value) in zip(offsets, row):
            ax.bar(
                idx + offset,
                value,
                width=min(bar_width, group_width / max(len(row), 1) * 0.78),
                color=RUNTIME_COLORS[runtime],
                edgecolor="#333333",
                linewidth=0.55,
            )
            ax.text(idx + offset, value + ylimit * 0.018, f"{value:.2f}x", ha="center", va="bottom", fontsize=9)

    handles = [plt.Rectangle((0, 0), 1, 1, color=RUNTIME_COLORS[runtime], ec="#333333") for runtime in RUNTIME_ORDER]
    labels = [RUNTIME_LABELS[runtime] for runtime in RUNTIME_ORDER]
    ax.axhline(1.0, color="#333333", linestyle="--", linewidth=1.2)
    ax.set_xticks(range(len(group_labels)))
    ax.set_xticklabels(group_labels, fontsize=10)
    ax.set_ylabel(ylabel, fontsize=12)
    ax.set_title(title, fontsize=15, pad=10)
    ax.set_ylim(0, ylimit)
    ax.yaxis.set_major_formatter(FuncFormatter(lambda value, _: f"{value:.1f}x"))
    ax.tick_params(axis="y", labelsize=10)
    ax.grid(axis="y", color="#eeeeee", linewidth=0.8)
    ax.legend(handles, labels, frameon=False, ncol=3, loc="upper center", bbox_to_anchor=(0.5, 1.04), fontsize=10)
    note = "Lower is smaller" if lower_is_better else "Higher is better"
    ax.text(
        0.5,
        -0.19,
        f"Kernel eBPF JIT is the normalized 1.0 baseline (dashed line). {note}; pure-bytecode suites are four-way.",
        transform=ax.transAxes,
        ha="center",
        fontsize=9,
        color="#555555",
    )
    fig.tight_layout(rect=[0, 0.05, 1, 1])
    fig.savefig(FIG / filename, dpi=180, bbox_inches="tight")
    plt.close(fig)


def plot_per_case_panel(
    ax,
    rows: list[tuple[str, dict[str, float]]],
    title: str,
    series: list[tuple[str, str]],
    *,
    upper: float,
) -> None:
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
    ax.set_ylim(0.28 if len(series) > 1 else 0.65, upper)
    ticks = [0.33, 0.5, 0.75, 1.0, 1.5, 2.0, 3.0, 5.0]
    if upper > 6.0:
        ticks.append(7.0)
    elif len(series) == 1:
        ticks = [tick for tick in ticks if tick >= 0.75 and tick <= max(upper, 2.0)]
    ax.set_yticks(ticks)
    ax.yaxis.set_major_formatter(FuncFormatter(lambda value, _: f"{value:g}x"))
    ax.tick_params(axis="y", labelsize=15)
    ax.grid(axis="y", color="#eeeeee", linewidth=0.9)
    ax.set_title(title, fontsize=20, pad=12)
    ax.set_ylabel("Speedup over kernel eBPF JIT", fontsize=16)


def draw_per_case_figure(
    *,
    path: Path,
    include_userspace: bool,
    title: str,
    filename: str,
    figsize: tuple[float, float],
    upper: float,
) -> None:
    rows = per_case_speedups(load_result(path), include_userspace=include_userspace)
    series = [("Kernel native", RUNTIME_COLORS["native_kernel"])]
    if include_userspace:
        series.extend(
            [
                ("Userspace eBPF", RUNTIME_COLORS["llvmbpf"]),
                ("Userspace native", RUNTIME_COLORS["native"]),
            ]
        )
    fig, ax = plt.subplots(figsize=figsize)
    plot_per_case_panel(
        ax,
        rows,
        title,
        series,
        upper=upper,
    )
    handles, labels = ax.get_legend_handles_labels()
    fig.legend(handles, labels, loc="upper center", ncol=len(labels), frameon=False, bbox_to_anchor=(0.5, 1.02), fontsize=16)
    fig.text(
        0.5,
        0.015,
        "Kernel eBPF is the normalized 1.0 baseline (dashed line). Higher is better; y-axis is log-scaled.",
        ha="center",
        fontsize=14,
        color="#555555",
    )
    fig.tight_layout(rect=[0, 0.08, 1, 0.92])
    fig.savefig(FIG / filename, dpi=180, bbox_inches="tight")
    plt.close(fig)


def draw_per_case_figures() -> None:
    draw_per_case_figure(
        path=X86_PURE_BYTECODE,
        include_userspace=True,
        title="x86 KVM pure bytecode cases",
        filename="micro-characterization-x86-pure-bytecode-percase-20260606.png",
        figsize=(24.0, 5.9),
        upper=7.2,
    )
    draw_per_case_figure(
        path=X86_WITH_HELPERS,
        include_userspace=False,
        title="x86 KVM with helpers/maps cases",
        filename="micro-characterization-x86-helpers-maps-percase-20260606.png",
        figsize=(14.2, 5.3),
        upper=3.6,
    )
    draw_per_case_figure(
        path=ARM_PURE_BYTECODE,
        include_userspace=True,
        title="arm64 AWS pure bytecode cases",
        filename="micro-characterization-arm64-pure-bytecode-percase-20260606.png",
        figsize=(24.0, 5.9),
        upper=7.2,
    )
    draw_per_case_figure(
        path=ARM_WITH_HELPERS,
        include_userspace=False,
        title="arm64 AWS with helpers/maps cases",
        filename="micro-characterization-arm64-helpers-maps-percase-20260606.png",
        figsize=(14.2, 5.3),
        upper=3.6,
    )


def write_summary() -> None:
    lines = [
        "# Micro characterization 2026-06-06 summary",
        "",
        "Post-hoc analysis from raw result.json files. Ratios use per-benchmark median exec_ns.",
        "",
        "| Platform | Suite | Runtime | Runtime/kernel geomean | Speedup | Wins / losses / ties | Code-size ratio |",
        "|---|---|---|---:|---:|---:|---:|",
    ]
    for platform, suite, path, runtimes in ARTIFACTS:
        data = load_result(path)
        for runtime in RUNTIME_ORDER:
            if runtime not in runtimes:
                continue
            ratio = ratio_geomean(data, runtime)
            wins, losses, ties = wins_losses_ties(data, runtime)
            lines.append(
                f"| {platform} | {suite} | {RUNTIME_LABELS[runtime]} | {ratio:.3f} | {1.0 / ratio:.3f}x | "
                f"{wins} / {losses} / {ties} | {code_size_ratio(data, runtime):.3f} |"
            )

    lines += [
        "",
        "## Variability",
        "",
        "| Platform | Suite | Benchmark/runtime pairs | Median CV | p95 CV | Max CV | Pairs within 2% of median |",
        "|---|---|---:|---:|---:|---:|---:|",
    ]
    for platform, suite, path, runtimes in ARTIFACTS:
        data = load_result(path)
        count, median_cv, p95_cv, max_cv, within2 = runtime_cv_summary(data, runtimes)
        lines.append(
            f"| {platform} | {suite} | {count} | {median_cv * 100:.2f}% | {p95_cv * 100:.2f}% | "
            f"{max_cv * 100:.2f}% | {within2} / {count} |"
        )
    SUMMARY.write_text("\n".join(lines) + "\n")


def main() -> None:
    FIG.mkdir(parents=True, exist_ok=True)
    draw_grouped_bars(
        "micro-characterization-runtime-aggregate-20260606.png",
        "Speedup over kernel eBPF JIT",
        "Microbenchmark aggregate speedup over kernel eBPF JIT",
        lambda data, runtime: 1.0 / ratio_geomean(data, runtime),
        2.65,
        lower_is_better=False,
    )
    draw_per_case_figures()
    draw_grouped_bars(
        "micro-characterization-code-size-20260606.png",
        "Machine-code size / kernel eBPF JIT size",
        "Microbenchmark machine-code size ratio",
        code_size_ratio,
        1.15,
        lower_is_better=True,
    )
    write_summary()


if __name__ == "__main__":
    main()
