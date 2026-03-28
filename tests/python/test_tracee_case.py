from __future__ import annotations

import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from e2e.cases.tracee import case


def test_select_tracee_programs_raises_on_missing_requested_name() -> None:
    live_programs = [
        {"id": 17, "name": "tracepoint__raw_syscalls__sys_enter"},
        {"id": 21, "name": "tracepoint__raw_syscalls__sys_exit"},
    ]

    with pytest.raises(RuntimeError, match="configured apply_programs not found"):
        case.select_tracee_programs(
            live_programs,
            {"apply_programs": ["sys_enter_submit"]},
            config_key="apply_programs",
            allow_all_when_unset=False,
        )


def test_build_markdown_keeps_preflight_for_skipped_payload() -> None:
    payload = {
        "generated_at": "2026-03-27T19:52:35.704448+00:00",
        "status": "skipped",
        "mode": "skipped",
        "skip_reason": "preflight observed zero apply-program executions; skipping invalid optimization benchmark",
        "smoke": False,
        "duration_s": 30,
        "tracee_binary": "/tmp/tracee",
        "setup": {"returncode": 0, "tracee_binary": "/tmp/tracee"},
        "limitations": ["Configured Tracee events/workload did not execute the configured apply programs during preflight."],
        "preflight": {
            "workloads": [
                {
                    "name": "read_hotpath",
                    "events_per_sec": 57079.46,
                    "bpf": {"summary": {"avg_ns_per_run": 164.98}},
                }
            ],
            "program_activity": {
                "target_programs": {"total_run_cnt": 3295552},
                "apply_programs": {"total_run_cnt": 0},
            },
        },
    }

    markdown = case.build_markdown(payload)

    assert "## Preflight" in markdown
    assert "target_runs=3295552" in markdown
    assert "apply_runs=0" in markdown
