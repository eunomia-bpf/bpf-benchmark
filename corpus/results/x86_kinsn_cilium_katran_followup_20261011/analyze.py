#!/usr/bin/env python3
"""Analyze the follow-up kinsn Cilium and Katran timing (fresh guest per cell).

Reads runs-cilium.tsv and runs-katran.tsv written by run-series.sh, rejects any
cell whose phases did not do the same work, and writes samples.csv, guests.csv,
live-program-images.csv and analysis.json next to this script.
"""

from __future__ import annotations

import csv
import json
import re
import statistics
from collections import Counter
from pathlib import Path


OUT = Path(__file__).resolve().parent
ARMS = {
    "jit-kinsn": ("jit", "kinsn"),
    "jit-native": ("jit", "native"),
    "native-jit": ("native", "jit"),
    "jit-jit": ("jit-first", "jit-second"),
}
APP_JSON = {"cilium": "cilium__agent.json", "katran": "katran.json"}
EVIDENCE = {"cilium": "cilium_agent", "katran": "katran"}


def describe(values: list[float]) -> dict[str, float | int]:
    if not values:
        return {"n": 0}
    quartiles = (
        statistics.quantiles(values, n=4, method="inclusive")
        if len(values) > 1
        else [values[0]] * 3
    )
    return {
        "n": len(values),
        "median": statistics.median(values),
        "min": min(values),
        "q1": quartiles[0],
        "q3": quartiles[2],
        "max": max(values),
    }


def pktgen_counters(workload: dict[str, object]) -> tuple[int, int, int]:
    sent = errors = pps = 0
    for component in workload["components"]:
        stdout = str(component["stdout"])
        sent_match = re.search(r"pkts-sofar:\s*(\d+)", stdout)
        errors_match = re.search(r"pkts-sofar:.*?errors:\s*(\d+)", stdout)
        pps_match = re.search(r"\n\s*(\d+)pps", stdout)
        if not sent_match or not errors_match or not pps_match:
            raise RuntimeError(f"unrecognized pktgen output: {stdout!r}")
        sent += int(sent_match.group(1))
        errors += int(errors_match.group(1))
        pps += int(pps_match.group(1))
    return sent, errors, pps


def cilium_outcomes(outcomes: dict[str, object], sent: int) -> dict[str, object]:
    receivers = outcomes["receivers"]
    verdicts = outcomes["verdicts"]
    receiver_packets = sum(int(item["rx_packets"]) for item in receivers.values())
    row = {
        "receiver_packets": receiver_packets,
        "receiver_minus_sent": receiver_packets - sent,
        "receiver_errors": sum(int(item["rx_errors"]) for item in receivers.values()),
        "receiver_drops": sum(int(item["rx_dropped"]) for item in receivers.values()),
        "drops": sum(
            int(item["count"]) for key, item in verdicts.items() if key.startswith("reason=133,")
        ),
        "other_verdicts": sum(
            int(item["count"])
            for key, item in verdicts.items()
            if not key.startswith("reason=0,") and not key.startswith("reason=133,")
        ),
        "verdicts": json.dumps(
            {key: int(item["count"]) for key, item in verdicts.items()},
            sort_keys=True,
            separators=(",", ":"),
        ),
    }
    return row


def katran_outcomes(outcomes: dict[str, object], sent: int) -> dict[str, object]:
    counters = outcomes["counters"]
    receiver = outcomes["receiver"]
    interfaces = outcomes["interfaces"]

    def packets(name: str) -> int:
        return int(counters[name]["packets_or_v1"])

    receiver_packets = int(receiver["rx_packets"])
    return {
        "receiver_packets": receiver_packets,
        "receiver_minus_sent": receiver_packets - sent,
        "receiver_errors": int(receiver["rx_errors"]),
        "receiver_drops": int(receiver["rx_dropped"])
        + sum(int(item["rx_dropped"]) + int(item["tx_dropped"]) for item in interfaces.values()),
        "drops": packets("drop") + packets("consistent_hash_drop") + packets("encap_fail"),
        "other_verdicts": packets("pass"),
        "katran_total": packets("total"),
        "katran_tx": packets("tx"),
        "katran_vip_0": packets("vip_0"),
        "katran_lru": packets("lru"),
        "katran_lru_miss": packets("lru_miss"),
        "katran_fallback_lru": packets("fallback_lru"),
        "katran_real_packets": sum(
            int(item["packets_or_v1"]) for item in outcomes["real_counters"].values()
        ),
        "verdicts": json.dumps(
            {name: packets(name) for name in sorted(counters)},
            sort_keys=True,
            separators=(",", ":"),
        ),
    }


def phase_row(series: str, run: dict[str, str], phase: str, arm: str) -> tuple[dict[str, object], list[dict[str, object]]]:
    run_dir = Path(run["run_dir"])
    app = json.loads((run_dir / "details/apps" / APP_JSON[series]).read_text())
    if app["status"] != "ok":
        raise RuntimeError(f"{run_dir}: {app['status']}: {app.get('error', '')}")
    measurement = app[phase]
    if len(measurement["workloads"]) != 1:
        raise RuntimeError(f"{run_dir}: expected one workload in {phase}")
    workload = measurement["workloads"][0]
    sent, errors, pps = pktgen_counters(workload)
    outcomes = workload["config"]["outcomes"]["delta"]
    work = cilium_outcomes(outcomes, sent) if series == "cilium" else katran_outcomes(outcomes, sent)
    programs = list(measurement["bpf"].values())
    run_count = sum(int(program["run_cnt_delta"]) for program in programs)
    run_time_ns = sum(int(program["run_time_ns_delta"]) for program in programs)
    row: dict[str, object] = {
        "series": series,
        **run,
        "phase": phase,
        "arm": arm,
        "pps": pps,
        "sent": sent,
        "pktgen_errors": errors,
        **work,
        "bpf_run_count": run_count,
        "bpf_run_time_ns": run_time_ns,
        "pooled_ns_per_run": (run_time_ns / run_count) if run_count else "",
    }
    images: list[dict[str, object]] = []
    graph_path = run_dir / "details/bpf-evidence" / EVIDENCE[series] / phase / "live-program-graph.json"
    if graph_path.exists():
        graph = json.loads(graph_path.read_text())
        for program in graph["live_programs"]:
            images.append(
                {
                    "series": series,
                    "cell": run["cell"],
                    "stats": run["stats"],
                    "role": run["role"],
                    "phase": phase,
                    "arm": arm,
                    "id": program["id"],
                    "type": program["type"],
                    "name": program["name"],
                    "bytes_jited": program["bytes_jited"],
                    "bytes_xlated": program["bytes_xlated"],
                }
            )
    return row, images


def kinsn_sites(run_dir: Path, series: str) -> dict[str, object]:
    path = run_dir / "details/loadtime-reports" / APP_JSON[series].replace(".json", ".jsonl")
    if not path.exists():
        return {}
    families: Counter[str] = Counter()
    programs = 0
    for line in path.read_text().splitlines():
        if not line.strip():
            continue
        report = json.loads(line).get("report") or {}
        calls = report.get("kinsn_calls_by_family") or {}
        programs += sum(calls.values()) > 0
        families.update({key: int(value) for key, value in calls.items()})
    return {"kinsn_sites": sum(families.values()), "kinsn_programs": programs,
            "kinsn_sites_by_family": dict(sorted(families.items()))}


def accepted(series: str, run: dict[str, str]) -> bool:
    if run["rc"] != "0" or not run["run_dir"]:
        return False
    run_dir = Path(run["run_dir"])
    try:
        metadata = json.loads((run_dir / "metadata.json").read_text())
        app = json.loads((run_dir / "details/apps" / APP_JSON[series]).read_text())
    except (OSError, json.JSONDecodeError):
        return False
    return metadata.get("status") == "completed" and app.get("status") == "ok"


sample_rows: list[dict[str, object]] = []
guest_rows: list[dict[str, object]] = []
image_rows: list[dict[str, object]] = []
attempts: dict[str, dict[str, int]] = {}
inventory_records: list[dict[str, object]] = []
for series in ("cilium", "katran"):
    runs_path = OUT / f"runs-{series}.tsv"
    if not runs_path.exists():
        continue
    with runs_path.open(newline="") as handle:
        all_runs = list(csv.DictReader(handle, delimiter="\t"))
    good = [run for run in all_runs if accepted(series, run)]
    latest = {run["cell"]: run for run in good}
    attempts[series] = {
        "attempts": len(all_runs),
        "accepted_cells": len(latest),
        "rejected_attempts": len(all_runs) - len(good),
    }
    for cell in sorted(latest):
        run = latest[cell]
        run_dir = Path(run["run_dir"])
        first_arm, second_arm = ARMS[run["role"]]
        phases = {}
        for phase, arm in (("baseline", first_arm), ("post_rejit", second_arm)):
            row, images = phase_row(series, run, phase, arm)
            sample_rows.append(row)
            image_rows.extend(images)
            phases[phase] = row
        parity_path = run_dir / "details/bpf-evidence" / EVIDENCE[series] / "inventory-parity.json"
        if series == "cilium":
            parity = json.loads(parity_path.read_text())
            if parity.get("status") != "pass" or parity.get("baseline_live_program_count") != 51 \
                    or parity.get("post_rejit_live_program_count") != 51:
                raise RuntimeError(f"{parity_path}: unexpected inventory parity {parity}")
            inventory_records.append({"cell": cell, "role": run["role"],
                                      "name_granularity": parity.get("name_granularity", "full")})
        first, second = phases["baseline"], phases["post_rejit"]
        guest: dict[str, object] = {
            "series": series,
            **run,
            "first_pps": first["pps"],
            "second_pps": second["pps"],
            "second_over_first": int(second["pps"]) / int(first["pps"]),
        }
        if run["role"] != "jit-jit":
            jit = first if first_arm == "jit" else second
            other = second if first_arm == "jit" else first
            guest["treatment"] = other["arm"]
            guest["treatment_over_jit_throughput"] = int(other["pps"]) / int(jit["pps"])
            if run["stats"] == "1":
                guest["jit_ns_per_run"] = jit["pooled_ns_per_run"]
                guest["treatment_ns_per_run"] = other["pooled_ns_per_run"]
                guest["jit_over_treatment_bpf_cost"] = (
                    float(jit["pooled_ns_per_run"]) / float(other["pooled_ns_per_run"])
                )
            cell_images = [row for row in image_rows if row["cell"] == cell]
            jit_bytes = sum(int(row["bytes_jited"]) for row in cell_images if row["arm"] == "jit")
            other_bytes = sum(int(row["bytes_jited"]) for row in cell_images if row["arm"] == other["arm"])
            if jit_bytes:
                guest["jit_live_image_bytes"] = jit_bytes
                guest["treatment_live_image_bytes"] = other_bytes
                guest["treatment_over_jit_live_image_bytes"] = other_bytes / jit_bytes
            if run["role"] == "jit-kinsn":
                guest.update({key: (json.dumps(value, sort_keys=True) if isinstance(value, dict) else value)
                              for key, value in kinsn_sites(run_dir, series).items()})
        guest_rows.append(guest)

# Cilium: every phase must forward every packet with no error or drop.
# Katran: its own counters must show every sent packet balanced and transmitted (XDP_TX) with no
# drop. Its transport is bimodal (about 1.4 Mpps with no pktgen errors, or 2.3-3.4 Mpps with pktgen
# queue errors and sometimes receiver loss after Katran), independent of the arm, so Katran
# throughput is reported but not used; the per-run BPF cost from statistics-on cells is the result.
KATRAN_FAST_PPS = 2_000_000
for row in sample_rows:
    if row["series"] == "cilium":
        for field in ("pktgen_errors", "receiver_errors", "receiver_drops", "drops"):
            if int(row[field]) != 0:
                raise RuntimeError(f"{row['cell']} {row['phase']}: nonzero {field}={row[field]}")
    else:
        sent = int(row["sent"])
        if int(row["drops"]) != 0:
            raise RuntimeError(f"{row['cell']} {row['phase']}: Katran drops={row['drops']}")
        for field in ("katran_tx", "katran_vip_0", "katran_real_packets"):
            if int(row[field]) != sent:
                raise RuntimeError(f"{row['cell']} {row['phase']}: {field}={row[field]} != sent {sent}")
        row["transport_mode"] = "fast" if int(row["pps"]) > KATRAN_FAST_PPS else "slow"


def values(series: str, stats: str, field: str, role: str | None = None, treatment: str | None = None) -> list[float]:
    return [
        float(row[field])
        for row in guest_rows
        if row["series"] == series and row["stats"] == stats and field in row
        and (role is None or row["role"] == role)
        and (treatment is None or row.get("treatment") == treatment)
    ]


analysis: dict[str, object] = {"attempts": attempts,
                               "host_boot_ids": sorted({str(row["host_boot_id"]) for row in guest_rows}),
                               "cilium_inventory_parity": inventory_records}
for series in ("cilium", "katran"):
    result: dict[str, object] = {}
    for stats in ("0", "1"):
        block: dict[str, object] = {
            "jit_jit_second_over_first": describe(values(series, stats, "second_over_first", role="jit-jit")),
        }
        for treatment, roles in (("kinsn", ("jit-kinsn",)), ("native", ("jit-native", "native-jit"))):
            combined = values(series, stats, "treatment_over_jit_throughput", treatment=treatment)
            if not combined:
                continue
            entry: dict[str, object] = {"combined": describe(combined)}
            for role in roles:
                entry[role] = describe(values(series, stats, "treatment_over_jit_throughput", role=role))
            if stats == "1":
                entry["jit_over_treatment_bpf_cost"] = describe(
                    values(series, stats, "jit_over_treatment_bpf_cost", treatment=treatment))
                entry["jit_ns_per_run"] = describe(values(series, stats, "jit_ns_per_run", treatment=treatment))
                entry["treatment_ns_per_run"] = describe(
                    values(series, stats, "treatment_ns_per_run", treatment=treatment))
            entry["live_image_bytes_treatment_over_jit"] = describe(
                values(series, stats, "treatment_over_jit_live_image_bytes", treatment=treatment))
            block[f"{treatment}_over_jit_throughput"] = entry
        result[f"stats_{stats}"] = block
    analysis[series] = result
    sites = sorted({(row.get("kinsn_sites"), row.get("kinsn_programs")) for row in guest_rows
                    if row["series"] == series and row["role"] == "jit-kinsn"}, key=str)
    analysis[series]["kinsn_sites_and_programs_per_guest"] = [list(item) for item in sites]
    analysis[series]["outcome_totals"] = {
        key: sum(int(row[key]) for row in sample_rows if row["series"] == series)
        for key in ("sent", "pktgen_errors", "receiver_packets", "receiver_errors",
                    "receiver_drops", "drops", "other_verdicts")
    }
    analysis[series]["receiver_minus_sent"] = describe(
        [float(row["receiver_minus_sent"]) for row in sample_rows if row["series"] == series])
    if series == "katran":
        modes = Counter(
            (row["arm"], row["transport_mode"]) for row in sample_rows if row["series"] == series
        )
        analysis[series]["throughput_valid"] = False
        analysis[series]["transport_mode_by_arm"] = {
            f"{arm}/{mode}": count for (arm, mode), count in sorted(modes.items())
        }
        for mode in ("slow", "fast"):
            analysis[series][f"pps_{mode}"] = describe(
                [float(row["pps"]) for row in sample_rows
                 if row["series"] == series and row["transport_mode"] == mode])
        # Per-run cost pairs whose two phases ran in the same transport mode.
        same_mode: dict[str, list[float]] = {}
        phase_rows = {(row["cell"], row["phase"]): row for row in sample_rows if row["series"] == series}
        for guest in guest_rows:
            if guest["series"] != series or guest["stats"] != "1":
                continue
            first = phase_rows[(guest["cell"], "baseline")]
            second = phase_rows[(guest["cell"], "post_rejit")]
            if first["transport_mode"] != second["transport_mode"]:
                continue
            if guest["role"] == "jit-jit":
                same_mode.setdefault("jit_jit_first_over_second_ns", []).append(
                    float(first["pooled_ns_per_run"]) / float(second["pooled_ns_per_run"]))
            else:
                same_mode.setdefault(f"jit_over_{guest['treatment']}_bpf_cost", []).append(
                    float(guest["jit_over_treatment_bpf_cost"]))
        analysis[series]["same_transport_mode_stats_on"] = {
            key: {"values": sorted(vals), **describe(vals)} for key, vals in sorted(same_mode.items())
        }
        # Was kinsn applied to balancer_ingress? The shim logs a verifier rejection of the candidate.
        rejected = []
        for guest in guest_rows:
            if guest["series"] != series or guest["role"] != "jit-kinsn":
                continue
            log = Path(guest["run_dir"]) / "details/shim-logs/katran.post_rejit.log"
            text = log.read_text(errors="replace") if log.exists() else ""
            match = re.search(r"loadtime verifier probe rejected candidate after step kinsn errno=(\d+)", text)
            rejected.append({"cell": guest["cell"], "kinsn_rejected_errno": int(match.group(1)) if match else None})
        analysis[series]["kinsn_candidate_rejections"] = rejected
        # Does the transport mode change the per-run cost? JIT phases of statistics-on cells by mode.
        for mode in ("slow", "fast"):
            analysis[series][f"jit_ns_per_run_{mode}_mode"] = describe(
                [float(row["pooled_ns_per_run"]) for row in sample_rows
                 if row["series"] == series and row["stats"] == "1" and row["pooled_ns_per_run"] != ""
                 and str(row["arm"]).startswith("jit") and row["transport_mode"] == mode])

for path, rows in (
    (OUT / "samples.csv", sample_rows),
    (OUT / "guests.csv", guest_rows),
    (OUT / "live-program-images.csv", image_rows),
):
    fieldnames = list(dict.fromkeys(key for row in rows for key in row))
    with path.open("w", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fieldnames, lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)
(OUT / "analysis.json").write_text(json.dumps(analysis, indent=2, sort_keys=True) + "\n")
print(json.dumps({series: analysis.get(series, {}) for series in ("cilium", "katran")}, indent=1, sort_keys=True)[:6000])
