#!/usr/bin/env python3
"""Offline analysis for the October 10 Cilium JIT/native timing runs."""

from __future__ import annotations

import csv
import json
import re
import statistics
from pathlib import Path


ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).resolve().parent
RUNS = {
    "throughput_control": "x86_kvm_corpus_20261010_054232_312523",
    "throughput_kprog": "x86_kvm_corpus_20261010_055811_906903",
    "cost_kprog": "x86_kvm_corpus_20261010_061348_451617",
    "cost_control": "x86_kvm_corpus_20261010_062925_883934",
}


def describe(values: list[float | int]) -> dict[str, float | int]:
    return {
        "n": len(values),
        "median": statistics.median(values),
        "min": min(values),
        "max": max(values),
    }


def arm_for(run_kind: str, phase: str) -> str:
    if phase == "baseline":
        return "jit"
    return "native" if run_kind.endswith("kprog") else "jit_restart"


def parse_component(component: dict) -> tuple[int, int, int]:
    stdout = component["stdout"]
    sent = int(re.search(r"pkts-sofar:\s*(\d+)", stdout).group(1))
    errors = int(re.search(r"errors:\s*(\d+)", stdout).group(1))
    pps = int(re.search(r"\n\s*(\d+)pps", stdout).group(1))
    return sent, errors, pps


def app_result(run_id: str) -> dict:
    path = ROOT / "corpus/results" / run_id / "details/apps/cilium__agent.json"
    result = json.loads(path.read_text())
    if result["status"] != "ok":
        raise RuntimeError(f"{run_id}: {result['status']}: {result.get('error', '')}")
    return result


sample_rows: list[dict] = []
bpf_rows: list[dict] = []
analysis: dict = {"runs": RUNS, "throughput": {}, "bpf_cost": {}, "outcomes": {}}

for run_kind, run_id in RUNS.items():
    result = app_result(run_id)
    phase_pps: dict[str, list[int]] = {}
    analysis["outcomes"][run_kind] = {}
    for phase in ("baseline", "post_rejit"):
        pps_values: list[int] = []
        outcome_totals = {
            "sent": 0,
            "component_errors": 0,
            "receiver_packets": 0,
            "receiver_errors": 0,
            "receiver_drops": 0,
            "allow_direction_1": 0,
            "allow_direction_2": 0,
            "reason_133": 0,
            "other_verdicts": 0,
        }
        for sample, workload in enumerate(result[phase]["workloads"], 1):
            sent = errors = pps = 0
            for component in workload["components"]:
                component_sent, component_errors, component_pps = parse_component(component)
                sent += component_sent
                errors += component_errors
                pps += component_pps
            outcomes = workload["config"]["outcomes"]["delta"]
            receivers = outcomes["receivers"]
            verdicts = outcomes["verdicts"]
            receiver_packets = sum(value["rx_packets"] for value in receivers.values())
            receiver_errors = sum(value["rx_errors"] for value in receivers.values())
            receiver_drops = sum(value["rx_dropped"] for value in receivers.values())
            allow_1 = verdicts.get("reason=0,direction=1", {}).get("count", 0)
            allow_2 = verdicts.get("reason=0,direction=2", {}).get("count", 0)
            reason_133 = sum(
                value["count"] for key, value in verdicts.items() if key.startswith("reason=133,")
            )
            other_verdicts = sum(
                value["count"]
                for key, value in verdicts.items()
                if not key.startswith("reason=0,") and not key.startswith("reason=133,")
            )
            row = {
                "run_kind": run_kind,
                "run_id": run_id,
                "bpf_stats": int(run_kind.startswith("cost_")),
                "phase": phase,
                "arm": arm_for(run_kind, phase),
                "sample": sample,
                "pps": pps,
                "sent": sent,
                "component_errors": errors,
                "receiver_packets": receiver_packets,
                "receiver_minus_sent": receiver_packets - sent,
                "receiver_errors": receiver_errors,
                "receiver_drops": receiver_drops,
                "allow_direction_1": allow_1,
                "allow_direction_1_minus_sent": allow_1 - sent,
                "allow_direction_2": allow_2,
                "allow_direction_2_minus_sent": allow_2 - sent,
                "reason_133": reason_133,
                "other_verdicts": other_verdicts,
            }
            sample_rows.append(row)
            pps_values.append(pps)
            for key in outcome_totals:
                outcome_totals[key] += row[key]
        phase_pps[phase] = pps_values
        analysis["outcomes"][run_kind][phase] = outcome_totals

        programs = list(result[phase]["bpf"].values())
        total_runs = sum(program["run_cnt_delta"] for program in programs)
        total_ns = sum(program["run_time_ns_delta"] for program in programs)
        for program in programs:
            bpf_rows.append(
                {
                    "run_kind": run_kind,
                    "run_id": run_id,
                    "phase": phase,
                    "arm": arm_for(run_kind, phase),
                    **program,
                    "ns_per_run": (
                        program["run_time_ns_delta"] / program["run_cnt_delta"]
                        if program["run_cnt_delta"]
                        else ""
                    ),
                }
            )
        if run_kind.startswith("cost_"):
            active = [program for program in programs if program["run_cnt_delta"]]
            hot = [program for program in active if program["name"] == "cil_from_contai"]
            analysis["bpf_cost"].setdefault(run_kind, {})[phase] = {
                "programs": len(programs),
                "active_programs": len(active),
                "run_count": total_runs,
                "run_time_ns": total_ns,
                "pooled_ns_per_run": total_ns / total_runs,
                "hot_cil_from_container_ns_per_run": sorted(
                    program["run_time_ns_delta"] / program["run_cnt_delta"] for program in hot
                ),
            }

    ratios = [post / baseline for baseline, post in zip(phase_pps["baseline"], phase_pps["post_rejit"])]
    analysis["throughput"][run_kind] = {
        "baseline_pps": describe(phase_pps["baseline"]),
        "post_pps": describe(phase_pps["post_rejit"]),
        "paired_post_over_baseline": describe(ratios),
        "ratio_of_medians": statistics.median(phase_pps["post_rejit"])
        / statistics.median(phase_pps["baseline"]),
    }

for run_kind in ("cost_kprog", "cost_control"):
    cost = analysis["bpf_cost"][run_kind]
    baseline = cost["baseline"]["pooled_ns_per_run"]
    post = cost["post_rejit"]["pooled_ns_per_run"]
    cost["baseline_over_post_cost_ratio"] = baseline / post
    hot_baseline = cost["baseline"]["hot_cil_from_container_ns_per_run"]
    hot_post = cost["post_rejit"]["hot_cil_from_container_ns_per_run"]
    cost["hot_ranked_baseline_over_post_ratios"] = [
        before / after for before, after in zip(hot_baseline, hot_post)
    ]

analysis["control_adjusted"] = {
    "throughput_ratio": analysis["throughput"]["throughput_kprog"]["ratio_of_medians"]
    / analysis["throughput"]["throughput_control"]["ratio_of_medians"],
    "bpf_cost_ratio": analysis["bpf_cost"]["cost_kprog"]["baseline_over_post_cost_ratio"]
    / analysis["bpf_cost"]["cost_control"]["baseline_over_post_cost_ratio"],
    "warning": "Separate treatment/control runs had large and inconsistent restart drift; adjusted ratios are diagnostic, not primary estimates.",
}

with (OUT / "samples.csv").open("w", newline="") as handle:
    writer = csv.DictWriter(handle, fieldnames=list(sample_rows[0]), lineterminator="\n")
    writer.writeheader()
    writer.writerows(sample_rows)

with (OUT / "bpf-programs.csv").open("w", newline="") as handle:
    writer = csv.DictWriter(handle, fieldnames=list(bpf_rows[0]), lineterminator="\n")
    writer.writeheader()
    writer.writerows(bpf_rows)

(OUT / "analysis.json").write_text(json.dumps(analysis, indent=2, sort_keys=True) + "\n")
