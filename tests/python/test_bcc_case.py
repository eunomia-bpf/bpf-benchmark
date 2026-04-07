from __future__ import annotations

import sys
from contextlib import nullcontext
from pathlib import Path
from types import SimpleNamespace

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from e2e.cases.bcc import case


def test_load_config_reads_tool_arguments(tmp_path: Path) -> None:
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
    assert config.tools[0].tool_args == ("-T",)

def test_run_phase_uses_shared_bcc_runner(monkeypatch, tmp_path: Path) -> None:
    calls: list[object] = []
    captured: dict[str, object] = {}

    class FakeRunner:
        def __init__(self, **kwargs):
            calls.append(("init", kwargs))
            self.session = SimpleNamespace(process=SimpleNamespace(pid=321))
            self.programs = [{"id": 101, "name": "tracepoint__syscalls__sys_enter_execve"}]
            self.process_output = {"returncode": 0, "stdout_tail": "", "stderr_tail": ""}
            self.artifacts = {}
            self.command_used = ["bcc-tool", "execsnoop"]

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

    def fake_run_app_runner_phase_records(**kwargs):
        captured["enabled_passes"] = kwargs["enabled_passes"]
        runner = kwargs["runner"]
        prog_ids = list(runner.start())
        lifecycle = kwargs["build_state"](runner, prog_ids)
        captured["artifacts"] = dict(lifecycle.artifacts)
        baseline = kwargs["measure"](lifecycle, "baseline")
        runner.stop()
        return baseline, None

    monkeypatch.setattr(case, "BCCRunner", FakeRunner)
    monkeypatch.setattr(case, "run_app_runner_phase_records", fake_run_app_runner_phase_records)
    monkeypatch.setattr(
        case,
        "measure_app_runner_workload",
        lambda _runner, duration_s, prog_ids, **_kwargs: {
            "bpf": {"summary": {"avg_ns_per_run": 12.0}},
            "workload": {"ops_per_sec": 2.0, "duration_s": duration_s},
            "agent_cpu": {"total_pct": 5.0},
            "prog_ids": list(prog_ids),
        },
    )

    spec = case.ToolSpec(
        name="execsnoop",
        description="exec tracing",
        expected_programs=2,
        workload_kind="exec_loop",
        spawn_timeout_s=15,
        tool_args=("-T",),
    )

    baseline, rejit = case.run_phase(
        spec,
        tool_binary=tmp_path / "execsnoop",
        duration_s=5,
        attach_timeout=20,
        enabled_passes=None,
        policy_context={"repo": "bcc", "category": "bcc", "level": "e2e"},
        prepared_daemon_session=object(),
    )

    assert baseline["status"] == "ok"
    assert baseline["measurement"]["prog_ids"] == [101]
    assert rejit is None
    assert captured["enabled_passes"] is None
    assert captured["artifacts"]["rejit_policy_context"] == {
        "repo": "bcc",
        "category": "bcc",
        "level": "e2e",
    }
    assert calls[0][0] == "init"
    assert "start" in calls
    assert "stop" in calls


def test_run_bcc_case_reports_effective_passes(monkeypatch, tmp_path: Path) -> None:
    daemon_binary = tmp_path / "daemon"
    daemon_binary.write_text("", encoding="utf-8")
    daemon_binary.chmod(0o755)
    tool_binary = tmp_path / "execsnoop"
    tool_binary.write_text("", encoding="utf-8")
    tool_binary.chmod(0o755)

    config_path = tmp_path / "bcc-config.yaml"
    config_path.write_text(
        """
tools:
  - name: execsnoop
    description: exec tracing
    expected_programs: 2
    workload_kind: exec_loop
    spawn_timeout_s: 15
measurement_duration_s: 30
smoke_duration_s: 10
attach_timeout_s: 20
""".strip()
        + "\n",
        encoding="utf-8",
    )

    monkeypatch.setattr(case, "benchmark_rejit_enabled_passes", lambda: ["map_inline", "const_prop", "dce"])
    monkeypatch.setattr(case, "run_setup_script", lambda _path: {"returncode": 0, "stdout_tail": "", "stderr_tail": ""})
    monkeypatch.setattr(case, "resolve_tools_dir", lambda *_args, **_kwargs: tmp_path)
    monkeypatch.setattr(case, "find_tool_binary", lambda *_args, **_kwargs: tool_binary)
    monkeypatch.setattr(case, "host_metadata", lambda: {"kernel": "demo"})
    monkeypatch.setattr(case, "enable_bpf_stats", lambda: nullcontext())
    monkeypatch.setattr(
        case,
        "run_phase",
        lambda *args, **kwargs: (
            {
                "status": "ok",
                "site_totals": {
                    **case.zero_site_totals(case.BCC_SITE_TOTAL_FIELDS),
                    "total_sites": 19,
                    "map_inline_sites": 19,
                },
                "measurement": {},
            },
            {
                "status": "ok",
                "site_totals": case.zero_site_totals(case.BCC_SITE_TOTAL_FIELDS),
                "measurement": {},
                "rejit_result": {
                    "counts": {"applied_sites": 3},
                    "per_program": {
                        "101": {
                            "counts": {"applied_sites": 3},
                            "debug_result": {
                                "passes": [
                                    {"pass_name": "map_inline", "sites_applied": 2},
                                    {"pass_name": "const_prop", "sites_applied": 1},
                                ]
                            },
                        }
                    },
                    "effective_enabled_passes_by_program": {
                        "101": ["map_inline"],
                    }
                },
            },
        ),
    )

    args = SimpleNamespace(
        daemon=str(daemon_binary),
        smoke=False,
        smoke_duration=0,
        duration=0,
        setup_script=str(tmp_path / "setup.sh"),
        config=str(config_path),
        tools=None,
        tools_dir=str(tmp_path),
        _prepared_daemon_session=object(),
    )

    payload = case.run_bcc_case(args)

    assert payload["selected_rejit_passes"] == ["map_inline"]
    assert payload["requested_rejit_passes"] == ["map_inline", "const_prop", "dce"]
    assert payload["summary"]["site_totals"]["total_sites"] == 3
    assert payload["summary"]["site_totals"]["map_inline_sites"] == 2
    assert payload["summary"]["site_totals"]["const_prop_sites"] == 1
