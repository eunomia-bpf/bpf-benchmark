from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from e2e.cases.bpftrace import case


def test_summarize_script_uses_applied_sites_instead_of_scan_candidates(tmp_path: Path) -> None:
    spec = case.ScriptSpec(
        name="demo",
        script_path=tmp_path / "demo.bt",
        description="demo script",
        expected_programs=1,
        workload_kind="exec_loop",
    )
    spec.script_path.write_text("BEGIN { exit(); }\n", encoding="utf-8")

    baseline = {
        "status": "ok",
        "site_totals": {
            "total_sites": 12,
            "wide_sites": 12,
        },
        "measurement": {
            "bpf": {"summary": {"avg_ns_per_run": 12.0}},
            "workload": {"ops_per_sec": 100.0},
            "agent_cpu": {"total_pct": 5.0},
        },
    }
    rejit = {
        "status": "ok",
        "measurement": {
            "bpf": {"summary": {"avg_ns_per_run": 8.0}},
            "workload": {"ops_per_sec": 110.0},
            "agent_cpu": {"total_pct": 4.0},
        },
        "rejit_result": {
            "counts": {"applied_sites": 2},
            "per_program": {
                "101": {
                    "counts": {"applied_sites": 2},
                    "debug_result": {
                        "passes": [
                            {"pass_name": "map_inline", "sites_applied": 1},
                            {"pass_name": "const_prop", "sites_applied": 1},
                        ]
                    },
                }
            },
        },
    }

    summary = case.summarize_script(spec, baseline, rejit)

    assert summary["sites"] == 2
    assert summary["site_totals"]["total_sites"] == 2
    assert summary["site_totals"]["map_inline_sites"] == 1
    assert summary["site_totals"]["const_prop_sites"] == 1
