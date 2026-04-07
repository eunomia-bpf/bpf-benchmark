from __future__ import annotations

from contextlib import nullcontext
import sys
from pathlib import Path
from types import SimpleNamespace

import pytest
import yaml

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from corpus import driver
from runner.libs.app_runners.base import AppRunner
from runner.libs.app_suite_schema import AppSpec, AppWorkload
from runner.libs.case_common import CaseLifecycleState


def test_program_phase_stats_computes_deltas() -> None:
    stats = driver._program_phase_stats(
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

    assert driver._infer_prog_type_name(program) == "xdp"


def test_build_app_error_result_preserves_baseline_and_apply_details() -> None:
    app = AppSpec(
        name="scx/rusty",
        runner="scx",
        workload=AppWorkload(corpus="hackbench", e2e="hackbench"),
        args={"scheduler": "rusty"},
    )
    state = CaseLifecycleState(
        runtime=SimpleNamespace(),
        target_prog_ids=[7],
        apply_prog_ids=[7],
        artifacts={
            "programs": [{"id": 7, "name": "rusty_enqueue", "type": "struct_ops"}],
            "command_used": ["scx_rusty", "--stats", "1"],
        },
    )
    baseline_measurement = {
        "workload": {"duration_s": 1.0, "ops_per_sec": 2.0},
        "workloads": [{"duration_s": 1.0, "ops_per_sec": 2.0}],
        "initial_stats": {
            7: {"id": 7, "name": "rusty_enqueue", "type": "struct_ops", "run_cnt": 10, "run_time_ns": 1000}
        },
        "final_stats": {
            7: {"id": 7, "name": "rusty_enqueue", "type": "struct_ops", "run_cnt": 14, "run_time_ns": 1800}
        },
    }
    apply_result = {
        "applied": True,
        "per_program": {
            7: {
                "applied": True,
                "error": "",
                "counts": {"total_sites": 2, "applied_sites": 2},
                "exit_code": 0,
                "output": "ok",
            }
        },
    }

    result = driver._build_app_error_result(
        app,
        workload_seconds=1.0,
        error="post-rejit measurement failed",
        measurement_mode="program",
        state=state,
        baseline_measurement=baseline_measurement,
        apply_result=apply_result,
    )

    assert result["prog_ids"] == [7]
    assert result["baseline"]["programs"]["7"]["run_cnt"] == 4
    assert result["baseline"]["programs"]["7"]["exec_ns"] == pytest.approx(200.0)
    assert result["rejit_apply"] == apply_result
    assert result["had_post_rejit_measurement"] is False
    assert result["program_measurements"]["7"]["applied"] is True
    assert result["program_measurements"]["7"]["comparison_exclusion_reason"] == "missing_post_rejit_measurement"


def test_finalize_app_result_treats_identity_rejit_as_non_comparable_but_not_error() -> None:
    app = AppSpec(
        name="scx/rusty",
        runner="scx",
        workload=AppWorkload(corpus="hackbench", e2e="hackbench"),
        args={"scheduler": "rusty"},
    )
    state = CaseLifecycleState(
        runtime=SimpleNamespace(),
        target_prog_ids=[7],
        apply_prog_ids=[7],
        artifacts={
            "programs": [{"id": 7, "name": "rusty_select_cpu", "type": "struct_ops"}],
            "command_used": ["scx_rusty", "--stats", "1"],
        },
    )
    baseline_measurement = {
        "workload": {"duration_s": 1.0, "ops_per_sec": 2.0},
        "workloads": [{"duration_s": 1.0, "ops_per_sec": 2.0}],
        "initial_stats": {
            7: {"id": 7, "name": "rusty_select_cpu", "type": "struct_ops", "run_cnt": 10, "run_time_ns": 1000}
        },
        "final_stats": {
            7: {"id": 7, "name": "rusty_select_cpu", "type": "struct_ops", "run_cnt": 14, "run_time_ns": 1800}
        },
    }
    rejit_measurement = {
        "workload": {"duration_s": 1.0, "ops_per_sec": 2.0},
        "workloads": [{"duration_s": 1.0, "ops_per_sec": 2.0}],
        "initial_stats": {
            7: {"id": 7, "name": "rusty_select_cpu", "type": "struct_ops", "run_cnt": 14, "run_time_ns": 1800}
        },
        "final_stats": {
            7: {"id": 7, "name": "rusty_select_cpu", "type": "struct_ops", "run_cnt": 19, "run_time_ns": 2800}
        },
    }
    apply_result = {
        "applied": True,
        "counts": {"applied_sites": 0, "total_sites": 0},
        "per_program": {
            7: {
                "applied": True,
                "counts": {"applied_sites": 0, "total_sites": 0},
                "summary": {"applied": True, "program_changed": False, "total_sites_applied": 0},
                "error": "",
            }
        },
        "error": "",
    }

    result = driver._finalize_app_result(
        app,
        runner=SimpleNamespace(process_output={"stderr_tail": [], "stdout_tail": []}),
        state=state,
        workload_seconds=1.0,
        measurement_mode="program",
        baseline_measurement=baseline_measurement,
        apply_result=apply_result,
        rejit_measurement=rejit_measurement,
    )

    assert result["status"] == "ok"
    assert result["program_measurements"]["7"]["applied"] is True
    assert result["program_measurements"]["7"]["changed"] is False
    assert result["program_measurements"]["7"]["comparable"] is False
    assert result["program_measurements"]["7"]["comparison_exclusion_reason"] == "no_programs_changed_in_loader"


def test_run_suite_measures_post_rejit_when_apply_record_changed(monkeypatch, tmp_path: Path) -> None:
    manifest_path = tmp_path / "macro_apps.yaml"
    manifest_path.write_text(
        yaml.safe_dump(
            {
                "schema_version": 1,
                "suite_name": "macro_apps",
                "defaults": {
                    "samples": 1,
                    "duration_s": 1,
                },
                "apps": [
                    {
                        "name": "alpha",
                        "runner": "bcc",
                        "workload": {
                            "corpus": "exec_loop",
                            "e2e": "exec_loop",
                        },
                    }
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

    class FakeDaemonSession:
        def __init__(self) -> None:
            self.proc = FakeProc()
            self.socket_path = Path("/tmp/rejit.sock")
            self.socket_dir = "/tmp/rejit-dir"
            self.stdout_path = tmp_path / "daemon.stdout.log"
            self.stderr_path = tmp_path / "daemon.stderr.log"
            self.load_kinsn = False
            self.kinsn_metadata = {}

        @classmethod
        def start(cls, daemon_binary: Path, *, load_kinsn: bool = False) -> "FakeDaemonSession":
            del daemon_binary
            session = cls()
            session.load_kinsn = bool(load_kinsn)
            return session

        def __enter__(self) -> "FakeDaemonSession":
            return self

        def __exit__(self, exc_type: object, exc: object, tb: object) -> None:
            del exc_type, exc, tb

        def scan_programs(self, prog_ids, *, enabled_passes=None, timeout_seconds=60):
            del enabled_passes, timeout_seconds
            return {
                int(prog_id): {
                    "prog_id": int(prog_id),
                    "sites": {},
                    "counts": {},
                    "error": "",
                }
                for prog_id in prog_ids
            }

        def apply_rejit(self, prog_ids, *, enabled_passes=None):
            del prog_ids, enabled_passes
            return {
                "applied": False,
                "error": "",
                "counts": {"applied_sites": 0, "total_sites": 1},
                "per_program": {
                    101: {
                        "applied": False,
                        "error": "",
                        "counts": {"total_sites": 1, "applied_sites": 0},
                        "debug_result": {
                            "changed": True,
                            "summary": {
                                "program_changed": True,
                                "total_sites_applied": 1,
                            },
                        },
                        "exit_code": 0,
                        "output": "changed",
                    }
                },
            }

    class FakeRunner(AppRunner):
        def __init__(self, *, app_name: str, workload: str, **kwargs) -> None:
            super().__init__()
            self.app_name = app_name
            self.workload = workload
            self.kwargs = kwargs
            self.process_output = {"returncode": 0, "stdout_tail": "", "stderr_tail": ""}
            self.command_used = ["demo-runner", app_name]
            self.programs = [{"id": 101, "name": "alpha_prog", "type": "xdp"}]
            self._last_workload_details: dict[str, object] = {}

        def start(self) -> list[int]:
            return [101]

        def run_workload(self, seconds: float) -> object:
            return SimpleNamespace(
                to_dict=lambda: {
                    "app": self.app_name,
                    "duration_s": float(seconds),
                    "ops_per_sec": 10.0,
                }
            )

        def run_workload_spec(self, workload_spec, seconds: float) -> object:
            del workload_spec
            return self.run_workload(seconds)

        def stop(self) -> None:
            return None

        def select_corpus_program_ids(self, initial_stats, final_stats) -> list[int] | None:
            del initial_stats, final_stats
            return None

        def corpus_measurement_mode(self) -> str:
            return "program"

        @property
        def pid(self) -> int | None:
            return None

        @property
        def program_fds(self) -> dict[int, int]:
            return {}

        @property
        def last_workload_details(self) -> dict[str, object]:
            return dict(self._last_workload_details)

    snapshot_sequences = {
        101: [
            {
                "id": 101,
                "name": "alpha_prog",
                "type": "xdp",
                "run_cnt": 0,
                "run_time_ns": 0,
                "bytes_jited": 64,
                "bytes_xlated": 32,
            },
            {
                "id": 101,
                "name": "alpha_prog",
                "type": "xdp",
                "run_cnt": 5,
                "run_time_ns": 500,
                "bytes_jited": 64,
                "bytes_xlated": 32,
            },
            {
                "id": 101,
                "name": "alpha_prog",
                "type": "xdp",
                "run_cnt": 5,
                "run_time_ns": 500,
                "bytes_jited": 64,
                "bytes_xlated": 32,
            },
            {
                "id": 101,
                "name": "alpha_prog",
                "type": "xdp",
                "run_cnt": 12,
                "run_time_ns": 1400,
                "bytes_jited": 64,
                "bytes_xlated": 32,
            },
        ],
    }
    snapshot_counts = {101: 0}

    def fake_sample_bpf_stats(prog_ids: list[int], prog_fds=None) -> dict[int, dict[str, object]]:
        del prog_fds
        prog_id = int(prog_ids[0])
        sequence = snapshot_sequences[prog_id]
        index = snapshot_counts[prog_id]
        if index >= len(sequence):
            index = len(sequence) - 1
        snapshot_counts[prog_id] += 1
        return {prog_id: dict(sequence[index])}

    def fake_get_app_runner(_runner_name: str, **kwargs) -> FakeRunner:
        app_name = str(kwargs.pop("app_name"))
        workload = str(kwargs.pop("workload"))
        return FakeRunner(app_name=app_name, workload=workload, **kwargs)

    monkeypatch.setattr(driver, "DaemonSession", FakeDaemonSession)
    monkeypatch.setattr(driver, "get_app_runner", fake_get_app_runner)
    monkeypatch.setattr(driver, "enable_bpf_stats", lambda: nullcontext())
    monkeypatch.setattr(driver, "sample_bpf_stats", fake_sample_bpf_stats)
    monkeypatch.setattr(driver, "wait_for_suite_quiescence", lambda: None)
    monkeypatch.setattr(driver, "_resolve_scan_pass_selection", lambda _selection: (["map_inline"], {"profile": "test"}, "test"))
    monkeypatch.setattr(
        driver,
        "_resolve_apply_passes_by_program",
        lambda **kwargs: {int(prog_id): ["map_inline"] for prog_id in kwargs["requested_prog_ids"]},
    )

    args = driver.parse_args(
        [
            "--suite",
            str(manifest_path),
            "--daemon",
            str(daemon_binary),
            "--no-kinsn",
        ]
    )
    payload = driver.run_suite(args)

    assert payload["status"] == "ok"
    result = payload["results"][0]
    assert result["had_post_rejit_measurement"] is True
    assert result["program_measurements"]["101"]["applied"] is False
    assert result["program_measurements"]["101"]["changed"] is True
    assert result["program_measurements"]["101"]["comparable"] is True
    assert result["program_measurements"]["101"]["speedup"] == pytest.approx(7.0 / 9.0)
    assert result["rejit"]["programs"]["101"]["run_cnt"] == 7


def test_run_suite_uses_app_manifest_and_single_daemon_session(monkeypatch, tmp_path: Path) -> None:
    manifest_path = tmp_path / "macro_apps.yaml"
    manifest_path.write_text(
        yaml.safe_dump(
            {
                "schema_version": 1,
                "suite_name": "macro_apps",
                "defaults": {
                    "samples": 7,
                    "duration_s": 4,
                },
                "apps": [
                    {
                        "name": "alpha",
                        "runner": "bcc",
                        "workload": {
                            "corpus": "exec_loop",
                            "e2e": "exec_loop",
                        },
                        "args": {"tool": "execsnoop"},
                    },
                    {
                        "name": "beta",
                        "runner": "tracee",
                        "workload": {
                            "corpus": "file_open",
                            "e2e": "file_open",
                        },
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
            self.socket_dir = "/tmp/rejit-dir"
            self.stdout_path = tmp_path / "daemon.stdout.log"
            self.stderr_path = tmp_path / "daemon.stderr.log"
            self.load_kinsn = False
            self.stdout_path.write_text("serve: listening on /tmp/rejit.sock\n", encoding="utf-8")
            self.stderr_path.write_text("kinsn discovery:\n  module loaded\n", encoding="utf-8")
            self.kinsn_metadata = {
                "expected_modules": ["bpf_rotate"],
                "module_load": {"loaded_modules": ["bpf_rotate"], "failed_modules": []},
                "daemon_kinsn_discovery": {"status": "ok", "discovery_log": "kinsn discovery:\n"},
                "status": "ready",
            }

        @classmethod
        def start(cls, daemon_binary: Path, *, load_kinsn: bool = False) -> "FakeDaemonSession":
            daemon_events.append(("start", daemon_binary, load_kinsn))
            session = cls()
            session.load_kinsn = bool(load_kinsn)
            return session

        def __enter__(self) -> "FakeDaemonSession":
            return self

        def __exit__(self, exc_type: object, exc: object, tb: object) -> None:
            del exc_type, exc, tb
            daemon_events.append("stop")

        def scan_programs(self, prog_ids, *, enabled_passes=None, timeout_seconds=60):
            daemon_events.append(("scan", list(prog_ids), list(enabled_passes or []), timeout_seconds))
            return {
                int(prog_id): {
                    "prog_id": int(prog_id),
                    "sites": {},
                    "counts": {},
                    "error": "",
                }
                for prog_id in prog_ids
            }

        def apply_rejit(self, prog_ids, *, enabled_passes=None):
            daemon_events.append(("apply", list(prog_ids), list(enabled_passes or [])))
            return {
                "applied": True,
                "error": "demo apply failure",
                "counts": {"applied_sites": 3},
                "per_program": {
                    101: {
                        "applied": True,
                        "error": "",
                        "counts": {"total_sites": 3, "applied_sites": 3},
                        "exit_code": 0,
                        "output": "alpha ok",
                    },
                    202: {
                        "applied": False,
                        "error": "demo apply failure",
                        "counts": {"total_sites": 0, "applied_sites": 0},
                        "exit_code": 1,
                        "output": "beta failed",
                    },
                },
            }

    runner_events: list[object] = []

    class FakeRunner(AppRunner):
        def __init__(self, *, app_name: str, workload: str, **kwargs) -> None:
            super().__init__()
            self.app_name = app_name
            self.workload = workload
            self.kwargs = kwargs
            self._last_workload_details: dict[str, object] = {}
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

        def run_workload_spec(self, workload_spec, seconds: float) -> object:
            del workload_spec
            return self.run_workload(seconds)

        def stop(self) -> None:
            runner_events.append(("stop", self.app_name))

        def select_corpus_program_ids(self, initial_stats, final_stats) -> list[int] | None:
            del initial_stats, final_stats
            return None

        def corpus_measurement_mode(self) -> str:
            return "program"

        @property
        def pid(self) -> int | None:
            return None

        @property
        def program_fds(self) -> dict[int, int]:
            return {}

        @property
        def last_workload_details(self) -> dict[str, object]:
            return dict(self._last_workload_details)

    snapshot_sequences = {
        101: [
            {
                "id": 101,
                "name": "alpha_prog",
                "type": "xdp",
                "run_cnt": 0,
                "run_time_ns": 0,
                "bytes_jited": 64,
                "bytes_xlated": 32,
            },
            {
                "id": 101,
                "name": "alpha_prog",
                "type": "xdp",
                "run_cnt": 5,
                "run_time_ns": 500,
                "bytes_jited": 64,
                "bytes_xlated": 32,
            },
            {
                "id": 101,
                "name": "alpha_prog",
                "type": "xdp",
                "run_cnt": 5,
                "run_time_ns": 500,
                "bytes_jited": 64,
                "bytes_xlated": 32,
            },
            {
                "id": 101,
                "name": "alpha_prog",
                "type": "xdp",
                "run_cnt": 12,
                "run_time_ns": 1400,
                "bytes_jited": 64,
                "bytes_xlated": 32,
            },
        ],
        202: [
            {
                "id": 202,
                "name": "beta_prog",
                "type": "tracepoint",
                "run_cnt": 0,
                "run_time_ns": 0,
                "bytes_jited": 96,
                "bytes_xlated": 48,
            },
            {
                "id": 202,
                "name": "beta_prog",
                "type": "tracepoint",
                "run_cnt": 4,
                "run_time_ns": 800,
                "bytes_jited": 96,
                "bytes_xlated": 48,
            },
        ],
    }
    snapshot_counts = {101: 0, 202: 0}

    def fake_sample_bpf_stats(prog_ids: list[int], prog_fds=None) -> dict[int, dict[str, object]]:
        del prog_fds
        prog_id = int(prog_ids[0])
        sequence = snapshot_sequences[prog_id]
        index = snapshot_counts[prog_id]
        if index >= len(sequence):
            index = len(sequence) - 1
        snapshot_counts[prog_id] += 1
        return {prog_id: dict(sequence[index])}

    def fake_get_app_runner(_runner_name: str, **kwargs) -> FakeRunner:
        app_name = str(kwargs.pop("app_name"))
        workload = str(kwargs.pop("workload"))
        return FakeRunner(app_name=app_name, workload=workload, **kwargs)

    monkeypatch.setattr(driver, "DaemonSession", FakeDaemonSession)
    monkeypatch.setattr(driver, "get_app_runner", fake_get_app_runner)
    monkeypatch.setattr(driver, "enable_bpf_stats", lambda: nullcontext())
    monkeypatch.setattr(driver, "sample_bpf_stats", fake_sample_bpf_stats)
    monkeypatch.setattr(driver, "wait_for_suite_quiescence", lambda: None)
    monkeypatch.setenv("BPFREJIT_BENCH_PASSES", "map_inline")

    args = driver.parse_args(
        [
            "--suite",
            str(manifest_path),
            "--daemon",
            str(daemon_binary),
        ]
    )
    payload = driver.run_suite(args)

    assert payload["samples"] == 7
    assert payload["workload_seconds"] == 4.0
    assert payload["suite_name"] == "macro_apps"
    assert payload["suite_summary"]["selected_apps"] == 2
    assert payload["summary"]["selected_apps"] == 2
    assert payload["summary"]["discovered_programs"] == 2
    assert payload["summary"]["statuses"] == {"error": 1, "ok": 1}
    assert payload["summary"]["sample_count"] == 1
    assert payload["summary"]["applied_only_geomean"] == pytest.approx(7.0 / 9.0)
    assert payload["summary"]["all_comparable_geomean"] == pytest.approx(7.0 / 9.0)
    assert payload["summary"]["comparison_exclusion_reasons"] == [
        {
            "app": "beta",
            "apply_error": "demo apply failure",
            "applied": False,
            "changed": False,
            "label": "beta:beta_prog#202",
            "program": "beta_prog",
            "program_id": 202,
            "reason": "apply_error: demo apply failure",
            "unit": "program",
        }
    ]
    assert payload["status"] == "error"
    assert payload["kinsn_modules"]["module_load"]["loaded_modules"] == ["bpf_rotate"]
    assert payload["metadata"]["kinsn_modules"]["count"] == 2
    assert [result["app"] for result in payload["results"]] == ["alpha", "beta"]
    assert payload["results"][0]["status"] == "ok"
    assert payload["results"][0]["baseline"]["programs"]["101"]["run_cnt"] == 5
    assert payload["results"][0]["rejit"]["programs"]["101"]["run_cnt"] == 7
    assert payload["results"][0]["program_measurements"]["101"]["applied"] is True
    assert payload["results"][0]["program_measurements"]["101"]["comparable"] is True
    assert payload["results"][0]["program_measurements"]["101"]["speedup"] == pytest.approx(7.0 / 9.0)
    assert payload["results"][0]["baseline_workload"]["duration_s"] == 4.0
    assert len(payload["results"][0]["baseline_workloads"]) == 7
    assert len(payload["results"][0]["rejit_workloads"]) == 7
    assert payload["results"][1]["status"] == "error"
    assert payload["results"][1]["error"] == "demo apply failure"
    assert payload["results"][1]["program_measurements"]["202"]["comparison_exclusion_reason"] == "apply_error: demo apply failure"
    assert len(payload["results"][1]["baseline_workloads"]) == 7
    assert payload["results"][1]["rejit_workloads"] == []
    assert daemon_events == [
        ("start", daemon_binary.resolve(), True),
        ("scan", [101, 202], ["map_inline"], 60),
        ("apply", [101, 202], ["map_inline"]),
        "stop",
    ]
    assert runner_events[0] == ("start", "alpha", "exec_loop", {"tool": "execsnoop"})
    assert runner_events.count(("workload", "alpha", 4.0)) == 14
    assert ("stop", "alpha") in runner_events
    assert ("start", "beta", "file_open", {}) in runner_events
    assert runner_events.count(("workload", "beta", 4.0)) == 7
    assert ("stop", "beta") in runner_events


def test_run_suite_marks_remaining_apps_after_daemon_exit(monkeypatch, tmp_path: Path) -> None:
    manifest_path = tmp_path / "macro_apps.yaml"
    manifest_path.write_text(
        yaml.safe_dump(
            {
                "schema_version": 1,
                "apps": [
                    {"name": "alpha", "runner": "bcc", "workload": {"corpus": "exec_loop", "e2e": "exec_loop"}},
                    {"name": "beta", "runner": "tracee", "workload": {"corpus": "file_open", "e2e": "file_open"}},
                    {"name": "gamma", "runner": "bpftrace", "workload": {"corpus": "exec_loop", "e2e": "exec_loop"}},
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
            self.socket_dir = "/tmp/rejit-dir"
            self.stdout_path = tmp_path / "daemon.stdout.log"
            self.stderr_path = tmp_path / "daemon.stderr.log"
            self.stdout_path.write_text("serve: listening on /tmp/rejit.sock\n", encoding="utf-8")
            self.stderr_path.write_text("kinsn discovery:\n  module loaded\n", encoding="utf-8")
            self.kinsn_metadata = {
                "expected_modules": ["bpf_rotate"],
                "module_load": {"loaded_modules": ["bpf_rotate"], "failed_modules": []},
                "status": "ready",
            }

        @classmethod
        def start(cls, _daemon_binary: Path, *, load_kinsn: bool = False) -> "FakeDaemonSession":
            assert load_kinsn is True
            return cls()

        def __enter__(self) -> "FakeDaemonSession":
            return self

        def __exit__(self, exc_type: object, exc: object, tb: object) -> None:
            del exc_type, exc, tb

    run_calls: list[str] = []

    class FakeRunner(AppRunner):
        def __init__(self, *, app_name: str, workload: str, **kwargs) -> None:
            del kwargs
            super().__init__()
            self.app_name = app_name
            self.workload = workload
            self.command_used = ["fake-runner", app_name]
            self.process_output = {"returncode": 0, "stdout_tail": "", "stderr_tail": ""}
            self.programs = [{"id": 100 + len(run_calls), "name": f"{app_name}_prog", "type": "xdp"}]

        def start(self) -> list[int]:
            run_calls.append(self.app_name)
            return [int(self.programs[0]["id"])]

        def run_workload(self, seconds: float) -> object:
            del seconds
            raise AssertionError("fatal daemon exit should abort before workload measurement")

        def run_workload_spec(self, workload_spec, seconds: float) -> object:
            del workload_spec, seconds
            raise AssertionError("fatal daemon exit should abort before workload measurement")

        def stop(self) -> None:
            return None

        def select_corpus_program_ids(self, initial_stats, final_stats) -> list[int] | None:
            del initial_stats, final_stats
            return None

        def corpus_measurement_mode(self) -> str:
            return "program"

        @property
        def pid(self) -> int | None:
            return None

        @property
        def program_fds(self) -> dict[int, int]:
            return {}

        @property
        def last_workload_details(self) -> dict[str, object]:
            return {}

    def fake_get_app_runner(_runner_name: str, **kwargs) -> FakeRunner:
        app_name = str(kwargs.pop("app_name"))
        workload = str(kwargs.pop("workload"))
        return FakeRunner(app_name=app_name, workload=workload, **kwargs)

    monkeypatch.setattr(driver, "DaemonSession", FakeDaemonSession)
    monkeypatch.setattr(driver, "get_app_runner", fake_get_app_runner)
    monkeypatch.setattr(driver, "enable_bpf_stats", lambda: nullcontext())

    payload = driver.run_suite(
        driver.parse_args(
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
    assert [result["status"] for result in payload["results"]] == ["error", "error", "error"]
    assert payload["results"][0]["error"] == "daemon session exited early (rc=17)"
    assert payload["results"][1]["error"] == "daemon session exited early (rc=17)"
    assert payload["results"][2]["error"] == "daemon session exited early (rc=17)"


def test_parse_args_rejects_invalid_samples_and_workload_seconds() -> None:
    with pytest.raises(SystemExit, match="--samples must be >= 0"):
        driver.parse_args(["--samples", "-1"])

    with pytest.raises(SystemExit, match="--workload-seconds must be >= 0"):
        driver.parse_args(["--workload-seconds", "-1"])
