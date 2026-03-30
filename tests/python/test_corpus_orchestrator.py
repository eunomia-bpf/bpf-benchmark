from __future__ import annotations

from contextlib import nullcontext
import sys
from pathlib import Path
from types import SimpleNamespace

import pytest
import yaml

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from corpus import orchestrator


def test_program_phase_stats_computes_deltas() -> None:
    stats = orchestrator._program_phase_stats(
        {
            7: {
                "id": 7,
                "name": "demo",
                "type": "xdp",
                "run_cnt": 15,
                "run_time_ns": 1500,
                "bytes_jited": 64,
                "bytes_xlated": 32,
            }
        },
        {
            7: {
                "run_cnt": 5,
                "run_time_ns": 500,
            }
        },
    )

    assert stats[7]["run_cnt"] == 10
    assert stats[7]["run_time_ns"] == 1000
    assert stats[7]["exec_ns"] == 100.0


def test_infer_prog_type_name_uses_section_prefix_when_prog_type_is_unspec() -> None:
    program = SimpleNamespace(prog_type_name="unspec", section_name="xdp_pass")

    assert orchestrator._infer_prog_type_name(program) == "xdp"


def test_run_suite_uses_app_manifest_and_single_daemon_session(monkeypatch, tmp_path: Path) -> None:
    manifest_path = tmp_path / "macro_apps.yaml"
    manifest_path.write_text(
        yaml.safe_dump(
            {
                "schema_version": 1,
                "suite_name": "macro_apps",
                "defaults": {
                    "repeat": 7,
                    "duration_s": 4,
                },
                "apps": [
                    {
                        "name": "alpha",
                        "runner": "bcc",
                        "workload": "exec_loop",
                        "args": {"tool": "execsnoop"},
                    },
                    {
                        "name": "beta",
                        "runner": "tracee",
                        "workload": "file_open",
                    },
                ],
            },
            sort_keys=False,
        ),
        encoding="utf-8",
    )
    daemon_binary = tmp_path / "daemon"
    daemon_binary.write_text("", encoding="utf-8")
    daemon_binary.chmod(0o755)

    class FakeProc:
        def poll(self) -> None:
            return None

    daemon_events: list[object] = []

    class FakeDaemonSession:
        def __init__(self) -> None:
            self.proc = FakeProc()
            self.socket_path = Path("/tmp/rejit.sock")

        @classmethod
        def start(cls, daemon_binary: Path) -> "FakeDaemonSession":
            daemon_events.append(("start", daemon_binary))
            return cls()

        def __enter__(self) -> "FakeDaemonSession":
            return self

        def __exit__(self, exc_type: object, exc: object, tb: object) -> None:
            del exc_type, exc, tb
            daemon_events.append("stop")

        def apply_rejit(self, prog_ids, *, enabled_passes=None):
            daemon_events.append(("apply", list(prog_ids), list(enabled_passes or [])))
            prog_id = int(prog_ids[0])
            if prog_id == 101:
                return {"applied": True, "error": "", "counts": {"applied_sites": 3}}
            return {"applied": False, "error": "demo apply failure", "counts": {"applied_sites": 0}}

    runner_events: list[object] = []

    class FakeRunner:
        def __init__(self, *, app_name: str, workload: str, **kwargs) -> None:
            self.app_name = app_name
            self.workload = workload
            self.kwargs = kwargs
            self.process_output = {"returncode": 0, "stdout_tail": "", "stderr_tail": ""}
            self.command_used = ["demo-runner", app_name]
            prog_id = 101 if app_name == "alpha" else 202
            self.programs = [{"id": prog_id, "name": f"{app_name}_prog", "type": "xdp"}]

        def start(self) -> list[int]:
            runner_events.append(("start", self.app_name, self.workload, dict(self.kwargs)))
            return [int(self.programs[0]["id"])]

        def run_workload(self, seconds: float) -> object:
            runner_events.append(("workload", self.app_name, seconds))
            return SimpleNamespace(
                to_dict=lambda: {
                    "app": self.app_name,
                    "duration_s": float(seconds),
                    "ops_per_sec": 10.0,
                }
            )

        def stop(self) -> None:
            runner_events.append(("stop", self.app_name))

    snapshot_counts = {101: 0, 202: 0}

    def fake_read_program_stats(prog_ids: list[int]) -> dict[int, dict[str, object]]:
        prog_id = int(prog_ids[0])
        snapshot_counts[prog_id] += 1
        if prog_id == 101:
            if snapshot_counts[prog_id] == 1:
                return {
                    101: {
                        "id": 101,
                        "name": "alpha_prog",
                        "type": "xdp",
                        "run_cnt": 5,
                        "run_time_ns": 500,
                        "bytes_jited": 64,
                        "bytes_xlated": 32,
                    }
                }
            return {
                101: {
                    "id": 101,
                    "name": "alpha_prog",
                    "type": "xdp",
                    "run_cnt": 12,
                    "run_time_ns": 1400,
                    "bytes_jited": 64,
                    "bytes_xlated": 32,
                }
            }
        return {
            202: {
                "id": 202,
                "name": "beta_prog",
                "type": "tracepoint",
                "run_cnt": 4,
                "run_time_ns": 800,
                "bytes_jited": 96,
                "bytes_xlated": 48,
            }
        }

    def fake_get_app_runner(_runner_name: str, **kwargs) -> FakeRunner:
        app_name = str(kwargs.pop("app_name"))
        workload = str(kwargs.pop("workload"))
        return FakeRunner(app_name=app_name, workload=workload, **kwargs)

    monkeypatch.setattr(orchestrator, "DaemonSession", FakeDaemonSession)
    monkeypatch.setattr(orchestrator, "get_app_runner", fake_get_app_runner)
    monkeypatch.setattr(orchestrator, "enable_bpf_stats", lambda: nullcontext())
    monkeypatch.setattr(orchestrator, "read_program_stats", fake_read_program_stats)
    monkeypatch.setattr(orchestrator, "benchmark_rejit_enabled_passes", lambda: ["map_inline"])

    args = orchestrator.parse_args(
        [
            "--suite",
            str(manifest_path),
            "--daemon",
            str(daemon_binary),
        ]
    )
    payload = orchestrator.run_suite(args)

    assert payload["repeat"] == 7
    assert payload["workload_seconds"] == 4.0
    assert payload["suite_name"] == "macro_apps"
    assert payload["suite_summary"]["selected_apps"] == 2
    assert payload["summary"]["selected_apps"] == 2
    assert payload["summary"]["discovered_programs"] == 2
    assert payload["summary"]["statuses"] == {"error": 1, "ok": 1}
    assert payload["status"] == "error"
    assert [result["app"] for result in payload["results"]] == ["alpha", "beta"]
    assert payload["results"][0]["status"] == "ok"
    assert payload["results"][0]["baseline"]["programs"]["101"]["run_cnt"] == 5
    assert payload["results"][0]["rejit"]["programs"]["101"]["run_cnt"] == 7
    assert payload["results"][0]["baseline_workload"]["duration_s"] == 4.0
    assert payload["results"][1]["status"] == "error"
    assert payload["results"][1]["error"] == "demo apply failure"
    assert daemon_events == [
        ("start", daemon_binary.resolve()),
        ("apply", [101], ["map_inline"]),
        ("apply", [202], ["map_inline"]),
        "stop",
    ]
    assert runner_events == [
        ("start", "alpha", "exec_loop", {"tool": "execsnoop"}),
        ("workload", "alpha", 4.0),
        ("workload", "alpha", 4.0),
        ("stop", "alpha"),
        ("start", "beta", "file_open", {}),
        ("workload", "beta", 4.0),
        ("stop", "beta"),
    ]


def test_run_suite_marks_remaining_apps_after_daemon_exit(monkeypatch, tmp_path: Path) -> None:
    manifest_path = tmp_path / "macro_apps.yaml"
    manifest_path.write_text(
        yaml.safe_dump(
            {
                "schema_version": 1,
                "apps": [
                    {"name": "alpha", "runner": "bcc", "workload": "exec_loop"},
                    {"name": "beta", "runner": "tracee", "workload": "file_open"},
                    {"name": "gamma", "runner": "bpftrace", "workload": "exec_loop"},
                ],
            },
            sort_keys=False,
        ),
        encoding="utf-8",
    )
    daemon_binary = tmp_path / "daemon"
    daemon_binary.write_text("", encoding="utf-8")
    daemon_binary.chmod(0o755)

    class FakeProc:
        def __init__(self) -> None:
            self.poll_calls = 0

        def poll(self) -> int | None:
            self.poll_calls += 1
            return 17 if self.poll_calls >= 1 else None

    class FakeDaemonSession:
        def __init__(self) -> None:
            self.proc = FakeProc()
            self.socket_path = Path("/tmp/rejit.sock")

        @classmethod
        def start(cls, _daemon_binary: Path) -> "FakeDaemonSession":
            return cls()

        def __enter__(self) -> "FakeDaemonSession":
            return self

        def __exit__(self, exc_type: object, exc: object, tb: object) -> None:
            del exc_type, exc, tb

    run_calls: list[str] = []

    def fake_run_app(app, *, daemon_session, workload_seconds):
        del daemon_session, workload_seconds
        run_calls.append(app.name)
        return {
            "app": app.name,
            "runner": app.runner,
            "workload": app.workload,
            "args": dict(app.args),
            "status": "ok",
        }

    monkeypatch.setattr(orchestrator, "DaemonSession", FakeDaemonSession)
    monkeypatch.setattr(orchestrator, "_run_app", fake_run_app)

    payload = orchestrator.run_suite(
        orchestrator.parse_args(
            [
                "--suite",
                str(manifest_path),
                "--daemon",
                str(daemon_binary),
            ]
        )
    )

    assert run_calls == ["alpha"]
    assert payload["status"] == "error"
    assert payload["fatal_error"] == "daemon session exited early (rc=17)"
    assert [result["status"] for result in payload["results"]] == ["ok", "error", "error"]
    assert payload["results"][1]["error"] == "daemon session exited early (rc=17)"
    assert payload["results"][2]["error"] == "daemon session exited early (rc=17)"


def test_parse_args_rejects_invalid_repeat_and_workload_seconds() -> None:
    with pytest.raises(SystemExit, match="--repeat must be >= 0"):
        orchestrator.parse_args(["--repeat", "-1"])

    with pytest.raises(SystemExit, match="--workload-seconds must be >= 0"):
        orchestrator.parse_args(["--workload-seconds", "-1"])
