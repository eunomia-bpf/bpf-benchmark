from __future__ import annotations

import sys
from pathlib import Path
from types import SimpleNamespace

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from e2e.cases.bcc import case


def test_load_config_parses_tool_specific_rejit_pass_overrides(tmp_path: Path) -> None:
    config_path = tmp_path / "bcc-config.yaml"
    config_path.write_text(
        """
tools:
  - name: execsnoop
    description: exec tracing
    expected_programs: 2
    workload_kind: exec_loop
    spawn_timeout_s: 15
    tool_args: ["-T"]
    rejit_passes: ["map_inline"]
measurement_duration_s: 30
smoke_duration_s: 10
attach_timeout_s: 20
""".strip()
        + "\n",
        encoding="utf-8",
    )

    config = case.load_config(config_path)

    assert len(config.tools) == 1
    assert config.tools[0].name == "execsnoop"
    assert config.tools[0].rejit_passes == ("map_inline",)
    assert config.tools[0].tool_args == ("-T",)


def test_load_config_defaults_rejit_passes_to_empty_tuple(tmp_path: Path) -> None:
    config_path = tmp_path / "bcc-config.yaml"
    config_path.write_text(
        """
tools:
  - name: tcplife
    description: tcp tracing
    expected_programs: 2
    workload_kind: tcp_connect
    spawn_timeout_s: 15
measurement_duration_s: 30
smoke_duration_s: 10
attach_timeout_s: 20
""".strip()
        + "\n",
        encoding="utf-8",
    )

    config = case.load_config(config_path)

    assert len(config.tools) == 1
    assert config.tools[0].rejit_passes == ()


def test_run_phase_uses_shared_bcc_runner(monkeypatch, tmp_path: Path) -> None:
    calls: list[object] = []

    class FakeRunner:
        def __init__(self, **kwargs):
            calls.append(("init", kwargs))
            self.session = SimpleNamespace(process=SimpleNamespace(pid=321))
            self.programs = [{"id": 101, "name": "tracepoint__syscalls__sys_enter_execve"}]
            self.process_output = {"returncode": 0, "stdout_tail": "", "stderr_tail": ""}

        def start(self) -> list[int]:
            calls.append("start")
            return [101]

        def run_workload(self, seconds: float):
            calls.append(("run_workload", seconds))
            return SimpleNamespace(
                to_dict=lambda: {
                    "ops_total": 10.0,
                    "ops_per_sec": 1.0,
                    "duration_s": float(seconds),
                    "stdout": "",
                    "stderr": "",
                }
            )

        def stop(self) -> None:
            calls.append("stop")

    def fake_run_case_lifecycle(**kwargs):
        setup_state = kwargs["setup"]()
        lifecycle = kwargs["start"](setup_state)
        baseline = kwargs["workload"](setup_state, lifecycle, "baseline")
        kwargs["stop"](setup_state, lifecycle)
        kwargs["cleanup"](setup_state)
        return SimpleNamespace(
            baseline=baseline,
            scan_results={},
            rejit_result={"applied": False, "error": "synthetic"},
            post_rejit=None,
        )

    monkeypatch.setattr(case, "BCCRunner", FakeRunner)
    monkeypatch.setattr(case, "run_case_lifecycle", fake_run_case_lifecycle)
    monkeypatch.setattr(
        case,
        "measure_workload",
        lambda _runner, duration_s, prog_ids, **_kwargs: {
            "bpf": {"summary": {"avg_ns_per_run": 12.0}},
            "workload": {"ops_per_sec": 2.0, "duration_s": duration_s},
            "agent_cpu": {"total_pct": 5.0},
            "prog_ids": list(prog_ids),
        },
    )
    monkeypatch.setattr(case, "sample_bpf_stats", lambda _prog_ids: {})

    spec = case.ToolSpec(
        name="execsnoop",
        description="exec tracing",
        expected_programs=2,
        workload_kind="exec_loop",
        spawn_timeout_s=15,
        tool_args=("-T",),
        rejit_passes=(),
    )

    baseline, rejit = case.run_phase(
        spec,
        tool_binary=tmp_path / "execsnoop",
        duration_s=5,
        attach_timeout=20,
        daemon_binary=tmp_path / "daemon",
    )

    assert baseline["status"] == "ok"
    assert baseline["prog_ids"] == [101]
    assert rejit is None
    assert calls[0][0] == "init"
    assert "start" in calls
    assert "stop" in calls
