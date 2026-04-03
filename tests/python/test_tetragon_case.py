from __future__ import annotations

import io
import subprocess
import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from e2e.cases.tetragon import case
from runner.libs.app_runners import tetragon_support
from runner.libs.workload import WorkloadResult


def test_select_tetragon_programs_raises_on_missing_requested_name() -> None:
    live_programs = [
        {"id": 17, "name": "execve_rate"},
        {"id": 21, "name": "event_execve"},
    ]

    with pytest.raises(RuntimeError, match="configured apply_programs not found"):
        case.select_tetragon_programs(
            live_programs,
            {"apply_programs": ["missing_program"]},
            config_key="apply_programs",
            allow_all_when_unset=False,
        )


def test_workload_specs_from_config_parses_exec_storm() -> None:
    workloads = case.workload_specs_from_config(
        {
            "workloads": [
                {
                    "name": "stress_exec",
                    "kind": "exec_storm",
                    "metric": "bogo-ops/s",
                    "description": "stress-ng execve workload",
                    "value": 3,
                }
            ]
        }
    )

    assert len(workloads) == 1
    assert workloads[0].name == "stress_exec"
    assert workloads[0].kind == "exec_storm"
    assert workloads[0].value == 3


def test_run_workload_with_options_routes_exec_storm_into_cgroup_helper(monkeypatch) -> None:
    expected = WorkloadResult(
        ops_total=12.0,
        ops_per_sec=3.0,
        duration_s=4.0,
        stdout="stdout",
        stderr="stderr",
    )

    monkeypatch.setattr(case, "run_exec_storm_in_cgroup", lambda duration_s, rate: expected)

    result = case.run_workload_with_options(
        case.WorkloadSpec(
            name="stress_exec",
            kind="exec_storm",
            metric="bogo-ops/s",
            description="stress-ng execve workload",
            value=3,
        ),
        5,
        exec_workload_cgroup=True,
    )

    assert result == expected


def test_build_markdown_keeps_preflight_for_error_payload() -> None:
    payload = {
        "generated_at": "2026-03-27T23:34:34.000000+00:00",
        "status": "error",
        "mode": "error",
        "error_message": "preflight observed zero apply-program executions; invalid optimization benchmark",
        "smoke": False,
        "duration_s": 30,
        "tetragon_binary": "/tmp/tetragon",
        "setup": {"returncode": 0, "tetragon_binary": "/tmp/tetragon"},
        "limitations": ["Configured Tetragon workload did not execute the configured apply programs during preflight."],
        "preflight": {
            "workloads": [
                {
                    "name": "stress_exec",
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


def test_build_program_summary_uses_applied_sites_instead_of_scan_candidates() -> None:
    baseline = {
        "workloads": [
            {
                "bpf": {
                    "programs": {
                        "17": {
                            "id": 17,
                            "name": "execve_rate",
                            "type": "kprobe",
                            "run_cnt_delta": 10,
                            "run_time_ns_delta": 1000,
                        }
                    }
                }
            }
        ]
    }
    post = {
        "workloads": [
            {
                "bpf": {
                    "programs": {
                        "17": {
                            "id": 17,
                            "name": "execve_rate",
                            "type": "kprobe",
                            "run_cnt_delta": 12,
                            "run_time_ns_delta": 900,
                        }
                    }
                }
            }
        ]
    }
    rejit_result = {
        "per_program": {
            17: {
                "counts": {"applied_sites": 2},
                "debug_result": {
                    "passes": [
                        {"pass_name": "map_inline", "sites_applied": 1},
                        {"pass_name": "const_prop", "sites_applied": 1},
                    ]
                },
            }
        }
    }

    summary = case.build_program_summary(rejit_result, baseline, post)

    assert summary == [
        {
            "id": 17,
            "name": "execve_rate",
            "type": "kprobe",
            "sites": 2,
            "stock_avg_ns": 100.0,
            "rejit_avg_ns": 75.0,
            "speedup": pytest.approx(100.0 / 75.0),
            "stock_events": 10,
            "rejit_events": 12,
        }
    ]


class _FakeProcess:
    def __init__(self) -> None:
        self.pid = 4242
        self.returncode = None
        self.stdout = io.StringIO("")
        self.stderr = io.StringIO("")

    def poll(self) -> int | None:
        return self.returncode


def test_tetragon_session_preserves_startup_failure_when_cleanup_times_out(monkeypatch) -> None:
    session = tetragon_support.TetragonAgentSession(["/usr/local/bin/tetragon"], 20)
    session.collector.snapshot = lambda: {"stderr_tail": ["startup log"], "stdout_tail": []}  # type: ignore[method-assign]

    monkeypatch.setattr(tetragon_support, "current_prog_ids", lambda: [])
    monkeypatch.setattr(tetragon_support, "start_agent", lambda *_args, **_kwargs: _FakeProcess())
    monkeypatch.setattr(tetragon_support, "wait_healthy", lambda *_args, **_kwargs: False)
    monkeypatch.setattr(
        tetragon_support,
        "stop_agent",
        lambda *_args, **_kwargs: (_ for _ in ()).throw(
            subprocess.TimeoutExpired(["/usr/local/bin/tetragon"], 3)
        ),
    )

    with pytest.raises(RuntimeError) as excinfo:
        session.__enter__()

    message = str(excinfo.value)
    assert "Tetragon failed to become healthy within 20s: startup log" in message
    assert "Cleanup error while stopping Tetragon: failed to stop Tetragon process cleanly" in message
    assert "timed out after 3 seconds" in message


def test_tetragon_session_preserves_empty_program_failure_when_cleanup_times_out(monkeypatch) -> None:
    monkeypatch.setattr(tetragon_support, "current_prog_ids", lambda: [])
    monkeypatch.setattr(tetragon_support, "start_agent", lambda *_args, **_kwargs: _FakeProcess())
    monkeypatch.setattr(tetragon_support, "wait_healthy", lambda *_args, **_kwargs: True)
    monkeypatch.setattr(tetragon_support, "current_programs", lambda: [])
    monkeypatch.setattr(
        tetragon_support,
        "stop_agent",
        lambda *_args, **_kwargs: (_ for _ in ()).throw(
            subprocess.TimeoutExpired(["/usr/local/bin/tetragon"], 3)
        ),
    )

    session = tetragon_support.TetragonAgentSession(["/usr/local/bin/tetragon"], 20)

    with pytest.raises(RuntimeError) as excinfo:
        session.__enter__()

    message = str(excinfo.value)
    assert "Tetragon became healthy but no new BPF programs were found" in message
    assert "Cleanup error while stopping Tetragon: failed to stop Tetragon process cleanly" in message
    assert "timed out after 3 seconds" in message
