from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from e2e.cases.scx import case


def test_build_markdown_reports_applied_site_summary() -> None:
    payload = {
        "generated_at": "2026-04-02T00:00:00+00:00",
        "status": "ok",
        "mode": "scx_rusty_loader",
        "duration_s": 10,
        "smoke": False,
        "host": {"kernel": "demo"},
        "scheduler_binary": "/tmp/scx_rusty",
        "preflight": {
            "state_before": "enabled",
            "available_workloads": ["hackbench"],
            "runtime_counters_available": True,
        },
        "scheduler_programs": [{"id": 101}],
        "scheduler_ops": ["rusty"],
        "baseline": {"workloads": []},
        "post_rejit": None,
        "comparison": {"comparable": False, "reason": "n/a"},
        "limitations": [],
        "site_summary": {
            "site_totals": {
                "total_sites": 3,
                "map_inline_sites": 1,
                "const_prop_sites": 1,
                "dce_sites": 1,
            }
        },
    }

    markdown = case.build_markdown(payload)

    assert "applied sites total=`3`" in markdown
    assert "map_inline=1, const_prop=1, dce=1" in markdown
