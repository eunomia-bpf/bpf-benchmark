#!/usr/bin/env python3
from __future__ import annotations

import json
import pathlib
import re
import sys


def fail(message: str) -> None:
    raise SystemExit(f"Katran functional preflight failed: {message}")


def phase_result(phase: dict[str, object]) -> dict[str, object]:
    workloads = phase.get("workloads", [])
    if len(workloads) != 1:
        fail(f"expected one workload, got {len(workloads)}")
    workload = workloads[0]
    components = workload.get("components", [])
    if len(components) != 1:
        fail(f"expected one pktgen worker, got {len(components)}")
    text = str(components[0].get("stdout") or "")
    result = re.search(r"Result: OK: .*?,\s*(\d+)\s+\(", text)
    error = re.search(r"errors:\s*(\d+)\s*$", text)
    if result is None or error is None:
        fail("could not parse pktgen result")
    sent, errors = int(result.group(1)), int(error.group(1))
    if errors:
        fail(f"pktgen reported {errors} errors")
    delta = workload.get("config", {}).get("outcomes", {}).get("delta")
    if not isinstance(delta, dict):
        fail("missing outcome delta")
    counters = delta.get("counters", {})
    real = delta.get("real_counters", {}).get("real_1", {})
    receiver = delta.get("receiver", {})
    observed = {
        "total": int(counters.get("total", {}).get("packets_or_v1", 0)),
        "tx": int(counters.get("tx", {}).get("packets_or_v1", 0)),
        "pass": int(counters.get("pass", {}).get("packets_or_v1", 0)),
        "drop": int(counters.get("drop", {}).get("packets_or_v1", 0)),
        "vip_0": int(counters.get("vip_0", {}).get("packets_or_v1", 0)),
        "real_1": int(real.get("packets_or_v1", 0)),
        "receiver": int(receiver.get("rx_packets", 0)),
    }
    tolerance = max(32, sent // 10000)
    for name in ("total", "tx", "vip_0", "real_1", "receiver"):
        if abs(observed[name] - sent) > tolerance:
            fail(f"{name}={observed[name]} does not match sent={sent}")
    if observed["pass"] or observed["drop"]:
        fail(f"unexpected actions: pass={observed['pass']} drop={observed['drop']}")
    return {"sent": sent, "errors": errors, **observed}


def main() -> None:
    results = pathlib.Path(sys.argv[1])
    candidates = sorted(results.glob("aws_x86_corpus_*"), key=lambda path: path.stat().st_mtime)
    if not candidates:
        fail("no AWS corpus result found")
    run_dir = candidates[-1]
    app = json.loads((run_dir / "details" / "apps" / "katran.json").read_text())
    if app.get("status") != "ok":
        fail(str(app.get("error") or "application status is not ok"))
    baseline = phase_result(app["baseline"])
    native = phase_result(app["post_rejit"])
    print(json.dumps({"status": "pass", "run_dir": str(run_dir),
                      "baseline": baseline, "native": native}, indent=2, sort_keys=True))


if __name__ == "__main__":
    main()
