#!/usr/bin/env python3
from __future__ import annotations

import collections
import json
import pathlib
import re
import sys


def fail(message: str) -> None:
    raise SystemExit(f"Cilium functional preflight failed: {message}")


def packet_counts(workload: dict[str, object]) -> tuple[list[int], list[int]]:
    sent: list[int] = []
    errors: list[int] = []
    for component in workload.get("components", []):
        text = str(component.get("stdout") or "")
        result = re.search(r"Result: OK: .*?,\s*(\d+)\s+\(", text)
        error = re.search(r"errors:\s*(\d+)\s*$", text)
        if result is None or error is None:
            fail("could not parse pktgen outcome")
        sent.append(int(result.group(1)))
        errors.append(int(error.group(1)))
    return sent, errors


def outcome(phase: dict[str, object]) -> dict[str, object]:
    workloads = phase.get("workloads", [])
    if len(workloads) != 1:
        fail(f"expected one workload, got {len(workloads)}")
    config = workloads[0].get("config", {})
    payload = config.get("outcomes", {}).get("delta")
    if not isinstance(payload, dict):
        fail("missing outcome delta")
    return payload


def inventory(run_dir: pathlib.Path, phase: str) -> collections.Counter[tuple[str, str]]:
    path = run_dir / "details" / "bpf-evidence" / "cilium_agent" / phase / "program-inventory.json"
    records = json.loads(path.read_text())
    return collections.Counter((str(record.get("name")), str(record.get("type"))) for record in records)


def attachments(run_dir: pathlib.Path, phase: str) -> collections.Counter[tuple[str, str]]:
    root = run_dir / "details" / "bpf-evidence" / "cilium_agent" / phase
    programs = json.loads((root / "program-inventory.json").read_text())
    names = {int(record["id"]): str(record.get("name")) for record in programs}
    links = json.loads((root / "bpftool-link.json").read_text() or "[]")
    signature: collections.Counter[tuple[str, str]] = collections.Counter()
    for link in links:
        program_id = int(link.get("prog_id", 0) or 0)
        if program_id not in names:
            continue
        signature[(str(link.get("type")), str(link.get("attach_type")))] += 1
    net = json.loads((root / "bpftool-net.json").read_text() or "{}")
    for kind, records in net.items():
        if not isinstance(records, list):
            continue
        for record in records:
            program_id = int(record.get("id", record.get("prog_id", 0)) or 0)
            if program_id in names:
                signature[(str(kind), str(record.get("mode", record.get("attach_type", ""))))] += 1
    return signature


def main() -> None:
    results = pathlib.Path(sys.argv[1])
    candidates = sorted(results.glob("aws_x86_corpus_*"), key=lambda path: path.stat().st_mtime)
    if not candidates:
        fail("no AWS corpus result found")
    run_dir = candidates[-1]
    app = json.loads((run_dir / "details" / "apps" / "cilium__agent.json").read_text())
    if app.get("status") != "ok":
        fail(str(app.get("error") or "application status is not ok"))

    baseline = app["baseline"]
    native = app["post_rejit"]
    baseline_sent, baseline_errors = packet_counts(baseline["workloads"][0])
    native_sent, native_errors = packet_counts(native["workloads"][0])
    if any(baseline_errors + native_errors):
        fail(f"pktgen errors: baseline={baseline_errors}, native={native_errors}")

    baseline_outcome = outcome(baseline)
    native_outcome = outcome(native)
    for label, snapshot, sent in (
        ("baseline", baseline_outcome, baseline_sent),
        ("native", native_outcome, native_sent),
    ):
        verdicts = snapshot.get("verdicts", {})
        bad = {
            key: value
            for key, value in verdicts.items()
            if not key.startswith("reason=0,") and int(value.get("count", 0)) != 0
        }
        if bad:
            fail(f"{label} has drop verdicts: {bad}")
        directions = {
            key.split("direction=", 1)[1]
            for key, value in verdicts.items()
            if key.startswith("reason=0,") and int(value.get("count", 0)) > 0
        }
        if directions != {"1", "2"}:
            fail(f"{label} forwarded direction set is {sorted(directions)}")
        receivers = snapshot.get("receivers", {})
        rx = sorted(int(value.get("rx_packets", 0)) for value in receivers.values())
        expected = sorted(sent)
        if len(rx) != 2 or any(abs(actual - wanted) > max(32, wanted // 10000) for actual, wanted in zip(rx, expected)):
            fail(f"{label} receiver counts {rx} do not match pktgen sent {expected}")

    baseline_inventory = inventory(run_dir, "baseline")
    native_inventory = inventory(run_dir, "post_rejit")
    if baseline_inventory != native_inventory:
        fail(f"program inventories differ: baseline={baseline_inventory}, native={native_inventory}")
    baseline_attachments = attachments(run_dir, "baseline")
    native_attachments = attachments(run_dir, "post_rejit")
    if baseline_attachments != native_attachments:
        fail(f"attachment graphs differ: baseline={baseline_attachments}, native={native_attachments}")

    print(json.dumps({
        "status": "pass",
        "run_dir": str(run_dir),
        "program_count": sum(baseline_inventory.values()),
        "inventory": {f"{name}/{kind}": count for (name, kind), count in sorted(baseline_inventory.items())},
        "attachments": {f"{kind}/{attach}": count for (kind, attach), count in sorted(baseline_attachments.items())},
        "baseline_sent": baseline_sent,
        "native_sent": native_sent,
        "baseline_verdicts": baseline_outcome.get("verdicts", {}),
        "native_verdicts": native_outcome.get("verdicts", {}),
        "baseline_receivers": baseline_outcome.get("receivers", {}),
        "native_receivers": native_outcome.get("receivers", {}),
    }, indent=2, sort_keys=True))


if __name__ == "__main__":
    main()
