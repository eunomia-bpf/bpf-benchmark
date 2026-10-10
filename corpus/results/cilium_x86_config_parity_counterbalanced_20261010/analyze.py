#!/usr/bin/env python3
"""Analyze independent-guest counterbalanced Cilium JIT/native measurements."""

from __future__ import annotations

import csv
import json
import re
import statistics
from collections import Counter
from pathlib import Path


OUT = Path(__file__).resolve().parent


def describe(values: list[float]) -> dict[str, float | int]:
    if not values:
        return {"n": 0}
    quartiles = statistics.quantiles(values, n=4, method="inclusive") if len(values) > 1 else [values[0]] * 3
    return {
        "n": len(values),
        "median": statistics.median(values),
        "min": min(values),
        "q1": quartiles[0],
        "q3": quartiles[2],
        "max": max(values),
    }


def component_counters(component: dict[str, object]) -> tuple[int, int, int]:
    stdout = str(component["stdout"])
    sent_match = re.search(r"pkts-sofar:\s*(\d+)", stdout)
    errors_match = re.search(r"pkts-sofar:.*?errors:\s*(\d+)", stdout)
    pps_match = re.search(r"\n\s*(\d+)pps", stdout)
    if not sent_match or not errors_match or not pps_match:
        raise RuntimeError(f"unrecognized pktgen output: {stdout!r}")
    return int(sent_match.group(1)), int(errors_match.group(1)), int(pps_match.group(1))


def phase_row(run: dict[str, str], phase: str, arm: str) -> tuple[dict[str, object], list[dict[str, object]]]:
    run_dir = Path(run["run_dir"])
    app = json.loads((run_dir / "details/apps/cilium__agent.json").read_text())
    if app["status"] != "ok":
        raise RuntimeError(f"{run_dir}: {app['status']}: {app.get('error', '')}")
    measurement = app[phase]
    if len(measurement["workloads"]) != 1:
        raise RuntimeError(f"{run_dir}: expected one workload in {phase}")
    workload = measurement["workloads"][0]
    sent = errors = pps = 0
    for component in workload["components"]:
        component_sent, component_errors, component_pps = component_counters(component)
        sent += component_sent
        errors += component_errors
        pps += component_pps
    outcomes = workload["config"]["outcomes"]["delta"]
    receivers = outcomes["receivers"]
    verdicts = outcomes["verdicts"]
    receiver_packets = sum(int(item["rx_packets"]) for item in receivers.values())
    receiver_errors = sum(int(item["rx_errors"]) for item in receivers.values())
    receiver_drops = sum(int(item["rx_dropped"]) for item in receivers.values())
    reason_133 = sum(
        int(item["count"])
        for key, item in verdicts.items()
        if key.startswith("reason=133,")
    )
    other_drops = sum(
        int(item["count"])
        for key, item in verdicts.items()
        if not key.startswith("reason=0,") and not key.startswith("reason=133,")
    )
    programs = list(measurement["bpf"].values())
    run_count = sum(int(program["run_cnt_delta"]) for program in programs)
    run_time_ns = sum(int(program["run_time_ns_delta"]) for program in programs)
    config = workload["config"]
    row: dict[str, object] = {
        **run,
        "phase": phase,
        "arm": arm,
        "pps": pps,
        "sent": sent,
        "pktgen_errors": errors,
        "receiver_packets": receiver_packets,
        "receiver_minus_sent": receiver_packets - sent,
        "receiver_errors": receiver_errors,
        "receiver_drops": receiver_drops,
        "reason_133": reason_133,
        "other_verdicts": other_drops,
        "verdicts": json.dumps(
            {key: int(item["count"]) for key, item in verdicts.items()},
            sort_keys=True,
            separators=(",", ":"),
        ),
        "bpf_run_count": run_count,
        "bpf_run_time_ns": run_time_ns,
        "pooled_ns_per_run": (run_time_ns / run_count) if run_count else "",
        "pktgen_cpus": json.dumps(config.get("pktgen_cpus", []), separators=(",", ":")),
        "network_softirq_delta_by_cpu": json.dumps(
            config.get("network_softirq_delta_by_cpu", {}), sort_keys=True, separators=(",", ":")
        ),
    }
    program_rows = [
        {
            "cell": run["cell"],
            "stats": run["stats"],
            "round": run["round"],
            "order_group": run["order_group"],
            "role": run["role"],
            "phase": phase,
            "arm": arm,
            **program,
            "ns_per_run": (
                int(program["run_time_ns_delta"]) / int(program["run_cnt_delta"])
                if int(program["run_cnt_delta"])
                else ""
            ),
        }
        for program in programs
    ]
    return row, program_rows


with (OUT / "runs-fixed.tsv").open(newline="") as handle:
    all_runs = list(csv.DictReader(handle, delimiter="\t"))


def accepted(run: dict[str, str]) -> bool:
    if run["rc"] != "0" or not run["run_dir"]:
        return False
    run_dir = Path(run["run_dir"])
    try:
        metadata = json.loads((run_dir / "metadata.json").read_text())
        app = json.loads((run_dir / "details/apps/cilium__agent.json").read_text())
    except (OSError, json.JSONDecodeError):
        return False
    return metadata.get("status") == "completed" and app.get("status") == "ok"


successful = [run for run in all_runs if accepted(run)]
latest_by_cell = {run["cell"]: run for run in successful}
runs = [latest_by_cell[cell] for cell in sorted(latest_by_cell)]
expected_cells = {
    f"fixed-stats-{stats}-round-{round_number}-{order_group}-{role}"
    for stats in (0, 1)
    for round_number in (1, 2, 3)
    for order_group, role in (
        ("jit-native", "jit-jit"),
        ("jit-native", "jit-native"),
        ("native-jit", "native-jit"),
        ("native-jit", "jit-jit"),
    )
}
if set(latest_by_cell) != expected_cells:
    raise RuntimeError(
        "fixed timing cohort mismatch: "
        f"missing={sorted(expected_cells - set(latest_by_cell))}, "
        f"extra={sorted(set(latest_by_cell) - expected_cells)}"
    )

sample_rows: list[dict[str, object]] = []
program_rows: list[dict[str, object]] = []
live_image_rows: list[dict[str, object]] = []
guest_rows: list[dict[str, object]] = []
inventory_parity_records: list[dict[str, object]] = []
macro_parity_file_count = 0
for run in runs:
    if run["role"] == "jit-native":
        arms = {"baseline": "jit", "post_rejit": "native"}
    elif run["role"] == "native-jit":
        arms = {"baseline": "native", "post_rejit": "jit"}
    else:
        arms = {"baseline": "jit-first", "post_rejit": "jit-second"}
    run_dir = Path(run["run_dir"])
    if run["role"] in {"jit-native", "native-jit"}:
        inventory_path = (
            run_dir / "details/bpf-evidence/cilium_agent/inventory-parity.json"
        )
        inventory = json.loads(inventory_path.read_text())
        if inventory != {
            "baseline_live_program_count": 51,
            "mismatches": {},
            "post_rejit_live_program_count": 51,
            "status": "pass",
        }:
            raise RuntimeError(f"{inventory_path}: unexpected inventory parity: {inventory}")
        inventory_parity_records.append({"cell": run["cell"], **inventory})
        parity_files = sorted(
            (run_dir / "details/cilium-native-config/parity").glob("**/parity.json")
        )
        if not parity_files:
            raise RuntimeError(f"{run_dir}: no native macro-parity records")
        for parity_path in parity_files:
            parity = json.loads(parity_path.read_text())
            if parity.get("status") != "pass":
                raise RuntimeError(f"{parity_path}: macro parity failed")
        macro_parity_file_count += len(parity_files)
    phases: dict[str, dict[str, object]] = {}
    for phase in ("baseline", "post_rejit"):
        row, per_program = phase_row(run, phase, arms[phase])
        sample_rows.append(row)
        program_rows.extend(per_program)
        phases[phase] = row
        if run["role"] in {"jit-native", "native-jit"}:
            graph_path = (
                run_dir
                / "details/bpf-evidence/cilium_agent"
                / phase
                / "live-program-graph.json"
            )
            graph = json.loads(graph_path.read_text())
            if len(graph["live_programs"]) != 51:
                raise RuntimeError(f"{graph_path}: expected 51 live programs")
            for program in graph["live_programs"]:
                live_image_rows.append(
                    {
                        "cell": run["cell"],
                        "stats": run["stats"],
                        "round": run["round"],
                        "order_group": run["order_group"],
                        "role": run["role"],
                        "phase": phase,
                        "arm": arms[phase],
                        "id": program["id"],
                        "type": program["type"],
                        "name": program["name"],
                        "kernel_name": program.get("kernel_name", program["name"]),
                        "bytes_jited": program["bytes_jited"],
                        "bytes_xlated": program["bytes_xlated"],
                    }
                )
    baseline = phases["baseline"]
    post = phases["post_rejit"]
    if run["role"] == "jit-native":
        jit, native = baseline, post
    elif run["role"] == "native-jit":
        native, jit = baseline, post
    else:
        jit = native = None
    guest: dict[str, object] = {
        **run,
        "first_pps": baseline["pps"],
        "second_pps": post["pps"],
        "restart_drift_second_over_first": int(post["pps"]) / int(baseline["pps"]),
    }
    if jit is not None and native is not None:
        guest["jit_pps"] = jit["pps"]
        guest["native_pps"] = native["pps"]
        guest["native_over_jit_throughput"] = int(native["pps"]) / int(jit["pps"])
        if run["stats"] == "1":
            guest["jit_ns_per_run"] = jit["pooled_ns_per_run"]
            guest["native_ns_per_run"] = native["pooled_ns_per_run"]
            guest["jit_over_native_bpf_cost"] = float(jit["pooled_ns_per_run"]) / float(native["pooled_ns_per_run"])
        cell_images = [row for row in live_image_rows if row["cell"] == run["cell"]]
        jit_image_bytes = sum(int(row["bytes_jited"]) for row in cell_images if row["arm"] == "jit")
        native_image_bytes = sum(int(row["bytes_jited"]) for row in cell_images if row["arm"] == "native")
        guest["jit_live_image_bytes"] = jit_image_bytes
        guest["native_live_image_bytes"] = native_image_bytes
        guest["native_over_jit_live_image_bytes"] = native_image_bytes / jit_image_bytes
    guest_rows.append(guest)

for row in sample_rows:
    for field in ("pktgen_errors", "receiver_errors", "receiver_drops", "reason_133"):
        if int(row[field]) != 0:
            raise RuntimeError(f"{row['cell']} {row['phase']}: nonzero {field}={row[field]}")


def treatment_values(stats: str, order: str | None, field: str) -> list[float]:
    return [
        float(row[field])
        for row in guest_rows
        if row["stats"] == stats
        and row["role"] in {"jit-native", "native-jit"}
        and (order is None or row["role"] == order)
    ]


def control_values(stats: str, group: str | None = None) -> list[float]:
    return [
        float(row["restart_drift_second_over_first"])
        for row in guest_rows
        if row["stats"] == stats
        and row["role"] == "jit-jit"
        and (group is None or row["order_group"] == group)
    ]


verdict_totals: Counter[str] = Counter()
softirq_totals: dict[str, Counter[str]] = {"NET_RX": Counter(), "NET_TX": Counter()}
for row in sample_rows:
    verdict_totals.update(json.loads(str(row["verdicts"])))
    softirqs = json.loads(str(row["network_softirq_delta_by_cpu"]))
    for kind in softirq_totals:
        softirq_totals[kind].update(
            {cpu: int(count) for cpu, count in softirqs[kind].items()}
        )


analysis: dict[str, object] = {
    "guest_count": len(guest_rows),
    "attempt_count": len(all_runs),
    "rejected_attempt_count": sum(not accepted(run) for run in all_runs),
    "host_boot_ids": sorted({run["host_boot_id"] for run in runs}),
    "config_parity": {
        "treatment_guests_passed": len(inventory_parity_records),
        "live_programs_per_arm": 51,
        "native_macro_parity_records_passed": macro_parity_file_count,
    },
    "primary_stats_off_throughput_native_over_jit": {
        "combined": describe(treatment_values("0", None, "native_over_jit_throughput")),
        "jit_native_order": describe(treatment_values("0", "jit-native", "native_over_jit_throughput")),
        "native_jit_order": describe(treatment_values("0", "native-jit", "native_over_jit_throughput")),
    },
    "secondary_stats_on_throughput_native_over_jit": {
        "combined": describe(treatment_values("1", None, "native_over_jit_throughput")),
        "jit_native_order": describe(treatment_values("1", "jit-native", "native_over_jit_throughput")),
        "native_jit_order": describe(treatment_values("1", "native-jit", "native_over_jit_throughput")),
    },
    "secondary_stats_on_bpf_cost_jit_over_native": {
        "combined": describe(treatment_values("1", None, "jit_over_native_bpf_cost")),
        "jit_native_order": describe(treatment_values("1", "jit-native", "jit_over_native_bpf_cost")),
        "native_jit_order": describe(treatment_values("1", "native-jit", "jit_over_native_bpf_cost")),
    },
    "live_image_size_native_over_jit": {
        "combined": describe(treatment_values("0", None, "native_over_jit_live_image_bytes")),
        "jit_native_order": describe(treatment_values("0", "jit-native", "native_over_jit_live_image_bytes")),
        "native_jit_order": describe(treatment_values("0", "native-jit", "native_over_jit_live_image_bytes")),
    },
    "jit_restart_controls_second_over_first": {
        stats: {
            "combined": describe(control_values(stats)),
            "jit_native_group": describe(control_values(stats, "jit-native")),
            "native_jit_group": describe(control_values(stats, "native-jit")),
        }
        for stats in ("0", "1")
    },
    "outcome_totals": {
        key: sum(int(row[key]) for row in sample_rows)
        for key in (
            "sent", "pktgen_errors", "receiver_packets", "receiver_errors",
            "receiver_drops", "reason_133", "other_verdicts",
        )
    },
    "receiver_minus_sent": describe(
        [float(row["receiver_minus_sent"]) for row in sample_rows]
    ),
    "verdict_counts_by_reason_direction": dict(sorted(verdict_totals.items())),
    "pktgen_cpus": sorted({str(row["pktgen_cpus"]) for row in sample_rows}),
    "network_softirq_totals_by_cpu": {
        kind: dict(sorted(counts.items())) for kind, counts in softirq_totals.items()
    },
}

for path, rows in (
    (OUT / "samples.csv", sample_rows),
    (OUT / "guests.csv", guest_rows),
    (OUT / "programs.csv", program_rows),
    (OUT / "live-program-images.csv", live_image_rows),
):
    fieldnames = list(dict.fromkeys(key for row in rows for key in row))
    with path.open("w", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fieldnames, lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)
(OUT / "analysis.json").write_text(json.dumps(analysis, indent=2, sort_keys=True) + "\n")
