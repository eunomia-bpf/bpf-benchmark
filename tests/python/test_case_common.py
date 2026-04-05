from __future__ import annotations

import json
import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import case_common, rejit
from runner.libs.app_runners.base import AppRunner
from runner.libs.workload import WorkloadResult


def test_run_case_lifecycle_reuses_single_daemon_session(monkeypatch, tmp_path: Path) -> None:
    case_common.reset_pending_result_metadata()
    class FakeProc:
        def poll(self) -> None:
            return None

    daemon_proc = FakeProc()
    daemon_socket = Path("/tmp/rejit.sock")
    daemon_stdout = tmp_path / "daemon.stdout.log"
    daemon_stderr = tmp_path / "daemon.stderr.log"
    daemon_stdout.write_text("serve: listening on /tmp/rejit.sock\n", encoding="utf-8")
    daemon_stderr.write_text(
        "kinsn discovery:\n"
        "  bpf_rotate64: function 'bpf_rotate64' found in 'bpf_rotate'\n"
        "platform: arch=X86_64 bmi1=true\n",
        encoding="utf-8",
    )
    calls: list[tuple[str, object]] = []
    phases: list[str] = []
    class FakeDaemonSession:
        def __init__(self, daemon_binary: Path) -> None:
            self.daemon_binary = daemon_binary
            self.proc = daemon_proc
            self.socket_path = daemon_socket
            self.socket_dir = "/tmp/rejit-dir"
            self.stdout_path = daemon_stdout
            self.stderr_path = daemon_stderr
            self.load_kinsn = True
            self.kinsn_metadata = {
                "expected_modules": ["bpf_endian", "bpf_rotate"],
                "module_snapshot_before_daemon": {
                    "resident_expected_modules": [],
                },
                "module_load": {
                    "loaded_modules": ["bpf_endian", "bpf_rotate"],
                    "failed_modules": [],
                },
                "status": "ready",
            }
            calls.append(("start", daemon_binary))

        @classmethod
        def start(cls, daemon_binary: Path) -> "FakeDaemonSession":
            return cls(daemon_binary)

        def __enter__(self) -> "FakeDaemonSession":
            return self

        def __exit__(self, exc_type: object, exc: object, tb: object) -> None:
            del exc_type, exc, tb
            self.close()

        def scan_programs(self, prog_ids, *, enabled_passes=None, timeout_seconds=60):
            calls.append(
                (
                    "scan",
                    {
                        "prog_ids": list(prog_ids),
                        "enabled_passes": list(enabled_passes or []),
                        "daemon_binary": self.daemon_binary,
                        "daemon_socket_path": self.socket_path,
                        "daemon_proc": self.proc,
                        "daemon_stdout_path": self.stdout_path,
                        "daemon_stderr_path": self.stderr_path,
                        "timeout_seconds": timeout_seconds,
                    },
                )
            )
            return {
                101: {
                    "prog_id": 101,
                    "sites": {},
                    "counts": {},
                    "error": "",
                }
            }

        def apply_rejit(self, prog_ids, *, enabled_passes=None):
            calls.append(
                (
                    "apply",
                    {
                        "prog_ids": list(prog_ids),
                        "enabled_passes": list(enabled_passes or []),
                        "daemon_socket_path": self.socket_path,
                        "daemon_proc": self.proc,
                        "daemon_stdout_path": self.stdout_path,
                        "daemon_stderr_path": self.stderr_path,
                    },
                )
            )
            return {
                "applied": True,
                "output": "",
                "exit_code": 0,
                "per_program": {
                    101: {
                        "prog_id": 101,
                        "applied": True,
                        "error": "",
                    }
                },
                "counts": {
                    "total_sites": 0,
                    "applied_sites": 0,
                },
                "error": "",
            }

        def close(self) -> None:
            calls.append(("stop", (self.proc, self.socket_path, self.socket_dir)))

    monkeypatch.setattr(case_common, "DaemonSession", FakeDaemonSession)
    def setup():
        phases.append("setup")
        return {"runtime": "demo"}

    def start(_setup_state):
        phases.append("start")
        return case_common.CaseLifecycleState(
            runtime=object(),
            apply_prog_ids=[101],
            scan_kwargs={"timeout_seconds": 33},
        )

    def workload(_setup_state, _lifecycle_state, phase):
        phases.append(f"workload:{phase}")
        return {"phase": phase}

    def stop(_setup_state, _lifecycle_state):
        phases.append("stop")

    def cleanup(_setup_state):
        phases.append("cleanup")

    daemon_session = FakeDaemonSession.start(Path("/tmp/fake-daemon"))
    prepared_daemon_session = case_common.prepare_daemon_session(
        daemon_session,
        daemon_binary=Path("/tmp/fake-daemon"),
    )
    try:
        result = case_common.run_case_lifecycle(
            daemon_session=prepared_daemon_session,
            setup=setup,
            start=start,
            workload=workload,
            stop=stop,
            cleanup=cleanup,
            enabled_passes=["map_inline"],
        )
    finally:
        daemon_session.close()

    assert result.baseline == {"phase": "baseline"}
    assert result.post_rejit == {"phase": "post_rejit"}
    assert [entry[0] for entry in calls] == ["start", "scan", "apply", "stop"]
    assert calls[1][1]["daemon_socket_path"] == daemon_socket
    assert calls[2][1]["daemon_socket_path"] == daemon_socket
    assert calls[1][1]["daemon_proc"] is daemon_proc
    assert calls[2][1]["daemon_proc"] is daemon_proc
    assert calls[1][1]["timeout_seconds"] == 33
    assert calls[1][1]["enabled_passes"] == ["map_inline"]
    assert calls[2][1]["enabled_passes"] == ["map_inline"]
    kinsn_metadata = result.metadata["kinsn_modules"]
    assert kinsn_metadata["module_snapshot_before_daemon"]["resident_expected_modules"] == []
    assert kinsn_metadata["module_load"]["loaded_modules"] == ["bpf_endian", "bpf_rotate"]
    assert kinsn_metadata["module_load"]["failed_modules"] == []
    assert "kinsn discovery:" in kinsn_metadata["daemon_kinsn_discovery"]["discovery_log"]
    assert phases == [
        "setup",
        "start",
        "workload:baseline",
        "workload:post_rejit",
        "stop",
        "cleanup",
    ]


def test_run_case_lifecycle_can_measure_post_phase_after_partial_apply(monkeypatch, tmp_path: Path) -> None:
    case_common.reset_pending_result_metadata()
    class FakeProc:
        def poll(self) -> None:
            return None

    daemon_stdout = tmp_path / "daemon.stdout.log"
    daemon_stderr = tmp_path / "daemon.stderr.log"
    daemon_stdout.write_text("serve: listening on /tmp/rejit.sock\n", encoding="utf-8")
    daemon_stderr.write_text("kinsn discovery:\n  module loaded\n", encoding="utf-8")
    class FakeDaemonSession:
        def __init__(self) -> None:
            self.proc = FakeProc()
            self.socket_path = Path("/tmp/rejit.sock")
            self.socket_dir = "/tmp/rejit-dir"
            self.stdout_path = daemon_stdout
            self.stderr_path = daemon_stderr
            self.load_kinsn = True
            self.kinsn_metadata = {
                "expected_modules": ["bpf_endian", "bpf_rotate"],
                "module_snapshot_before_daemon": {
                    "resident_expected_modules": [],
                },
                "module_load": {
                    "loaded_modules": ["bpf_endian", "bpf_rotate"],
                    "failed_modules": [],
                },
                "status": "ready",
            }

        @classmethod
        def start(cls, _daemon_binary: Path) -> "FakeDaemonSession":
            return cls()

        def __enter__(self) -> "FakeDaemonSession":
            return self

        def __exit__(self, exc_type: object, exc: object, tb: object) -> None:
            del exc_type, exc, tb
            self.close()

        def scan_programs(self, _prog_ids, *, enabled_passes=None, timeout_seconds=60):
            del enabled_passes
            del timeout_seconds
            return {101: {"prog_id": 101, "sites": {}, "counts": {}, "error": ""}}

        def apply_rejit(self, _prog_ids, *, enabled_passes=None):
            del enabled_passes
            return {
                "applied": False,
                "output": "",
                "exit_code": 1,
                "per_program": {
                    101: {
                        "prog_id": 101,
                        "applied": False,
                        "error": "prog 101: id changed after struct_ops refresh",
                    }
                },
                "counts": {
                    "total_sites": 7,
                    "applied_sites": 7,
                },
                "error": "prog 101: id changed after struct_ops refresh",
            }

        def close(self) -> None:
            return None

    monkeypatch.setattr(case_common, "DaemonSession", FakeDaemonSession)
    phases: list[str] = []

    daemon_session = FakeDaemonSession.start(Path("/tmp/fake-daemon"))
    prepared_daemon_session = case_common.prepare_daemon_session(
        daemon_session,
        daemon_binary=Path("/tmp/fake-daemon"),
    )
    try:
        result = case_common.run_case_lifecycle(
            daemon_session=prepared_daemon_session,
            setup=lambda: {"runtime": "demo"},
            start=lambda _setup_state: case_common.CaseLifecycleState(
                runtime=object(),
                apply_prog_ids=[101],
            ),
            workload=lambda _setup_state, _lifecycle_state, phase: phases.append(f"workload:{phase}") or {"phase": phase},
            stop=lambda _setup_state, _lifecycle_state: phases.append("stop"),
            cleanup=lambda _setup_state: phases.append("cleanup"),
            should_run_post_rejit=lambda rejit_result: int(
                (((rejit_result.get("counts") or {}).get("applied_sites", 0)) or 0)
            ) > 0,
        )
    finally:
        daemon_session.close()

    assert result.post_rejit == {"phase": "post_rejit"}
    assert phases == [
        "workload:baseline",
        "workload:post_rejit",
        "stop",
        "cleanup",
    ]
    assert result.metadata["kinsn_modules"]["module_load"]["loaded_modules"] == ["bpf_endian", "bpf_rotate"]


def test_run_app_runner_lifecycle_wraps_app_runner_defaults(tmp_path: Path) -> None:
    case_common.reset_pending_result_metadata()

    class FakeProc:
        def poll(self) -> None:
            return None

    daemon_stdout = tmp_path / "daemon.stdout.log"
    daemon_stderr = tmp_path / "daemon.stderr.log"
    daemon_stdout.write_text("serve: listening on /tmp/rejit.sock\n", encoding="utf-8")
    daemon_stderr.write_text("kinsn discovery:\n  module loaded\n", encoding="utf-8")

    class FakeDaemonSession:
        def __init__(self) -> None:
            self.proc = FakeProc()
            self.socket_path = Path("/tmp/rejit.sock")
            self.socket_dir = "/tmp/rejit-dir"
            self.stdout_path = daemon_stdout
            self.stderr_path = daemon_stderr
            self.load_kinsn = True
            self.kinsn_metadata = {
                "expected_modules": ["bpf_rotate"],
                "module_load": {
                    "loaded_modules": ["bpf_rotate"],
                    "failed_modules": [],
                },
                "status": "ready",
            }

        def scan_programs(self, prog_ids, *, enabled_passes=None, timeout_seconds=60):
            del enabled_passes
            del timeout_seconds
            return {int(prog_ids[0]): {"sites": {}, "counts": {}, "error": ""}}

        def apply_rejit(self, _prog_ids, *, enabled_passes=None):
            del enabled_passes
            return {
                "applied": True,
                "error": "",
                "counts": {"applied_sites": 1},
                "per_program": {101: {"applied": True}},
            }

    class FakeRunner(AppRunner):
        def __init__(self) -> None:
            super().__init__()
            self.artifacts = {"source": "runner"}
            self.command_used = ["demo-runner", "alpha"]
            self._last_workload_details: dict[str, object] = {}

        def start(self) -> list[int]:
            self.programs = [{"id": 101, "name": "alpha_prog", "type": "xdp"}]
            return [101]

        def run_workload(self, seconds: float) -> WorkloadResult:
            return WorkloadResult(
                ops_total=seconds,
                ops_per_sec=seconds,
                duration_s=seconds,
                stdout="",
                stderr="",
            )

        def run_workload_spec(self, workload_spec, seconds: float) -> WorkloadResult:
            del workload_spec
            return self.run_workload(seconds)

        def stop(self) -> None:
            self.process_output = {"returncode": 0}

        def select_corpus_program_ids(self, initial_stats, final_stats) -> list[int] | None:
            del initial_stats, final_stats
            return None

        def corpus_measurement_mode(self) -> str:
            return "app"

        @property
        def pid(self) -> int | None:
            return None

        @property
        def program_fds(self) -> dict[int, int]:
            return {}

        @property
        def last_workload_details(self) -> dict[str, object]:
            return dict(self._last_workload_details)

    prepared_daemon_session = case_common.prepare_daemon_session(
        FakeDaemonSession(),
        daemon_binary=Path("/tmp/fake-daemon"),
    )
    runner = FakeRunner()
    result = case_common.run_app_runner_lifecycle(
        daemon_session=prepared_daemon_session,
        runner=runner,
        measure=lambda lifecycle, phase: {
            "phase": phase,
            "prog_ids": list(lifecycle.target_prog_ids),
        },
    )

    assert result.baseline == {"phase": "baseline", "prog_ids": [101]}
    assert result.post_rejit == {"phase": "post_rejit", "prog_ids": [101]}
    assert result.artifacts["runner_artifacts"] == {"source": "runner"}
    assert result.artifacts["command_used"] == ["demo-runner", "alpha"]
    assert result.artifacts["programs"] == [{"id": 101, "name": "alpha_prog", "type": "xdp"}]


def test_run_case_lifecycle_resolves_policy_per_program(monkeypatch, tmp_path: Path) -> None:
    case_common.reset_pending_result_metadata()
    monkeypatch.delenv("BPFREJIT_BENCH_PASSES", raising=False)

    class FakeProc:
        def poll(self) -> None:
            return None

    daemon_stdout = tmp_path / "daemon.stdout.log"
    daemon_stderr = tmp_path / "daemon.stderr.log"
    daemon_stdout.write_text("serve: listening on /tmp/rejit.sock\n", encoding="utf-8")
    daemon_stderr.write_text("kinsn discovery:\n  module loaded\n", encoding="utf-8")
    calls: list[tuple[str, object]] = []

    class FakeDaemonSession:
        def __init__(self) -> None:
            self.proc = FakeProc()
            self.socket_path = Path("/tmp/rejit.sock")
            self.socket_dir = "/tmp/rejit-dir"
            self.stdout_path = daemon_stdout
            self.stderr_path = daemon_stderr
            self.kinsn_metadata = {
                "expected_modules": ["bpf_rotate"],
                "module_load": {"loaded_modules": ["bpf_rotate"], "failed_modules": []},
                "status": "ready",
            }

        def scan_programs(self, prog_ids, *, enabled_passes=None, timeout_seconds=60):
            calls.append(("scan", (list(prog_ids), list(enabled_passes or []), timeout_seconds)))
            return {
                101: {
                    "prog_id": 101,
                    "sites": {"map_inline_sites": 2},
                    "counts": {"map_inline_sites": 2},
                    "error": "",
                },
                202: {
                    "prog_id": 202,
                    "sites": {"map_inline_sites": 0},
                    "counts": {"map_inline_sites": 0},
                    "error": "",
                },
            }

        def apply_rejit(self, prog_ids, *, enabled_passes=None):
            calls.append(("apply", (list(prog_ids), list(enabled_passes or []))))
            per_program = {
                int(prog_id): {
                    "applied": True,
                    "output": "",
                    "exit_code": 0,
                    "counts": {"total_sites": 1, "applied_sites": 1},
                    "error": "",
                }
                for prog_id in prog_ids
            }
            return {
                "applied": True,
                "output": "",
                "exit_code": 0,
                "per_program": per_program,
                "counts": {
                    "total_sites": len(per_program),
                    "applied_sites": len(per_program),
                },
                "error": "",
            }

    monkeypatch.setattr(
        rejit,
        "load_benchmark_config",
        lambda profile=None: {
            "profile": profile,
            "policy": {
                "default": {"passes": ["const_prop"]},
                "rules": [
                    {
                        "match": {"program": "alpha_prog", "has_sites": ["map_inline"]},
                        "enable": ["map_inline"],
                    },
                    {
                        "match": {"program": "beta_prog"},
                        "passes": ["dce"],
                    },
                ],
            },
            "passes": {},
        },
    )

    prepared_daemon_session = case_common.prepare_daemon_session(
        FakeDaemonSession(),
        daemon_binary=Path("/tmp/fake-daemon"),
    )
    result = case_common.run_case_lifecycle(
        daemon_session=prepared_daemon_session,
        setup=lambda: None,
        start=lambda _setup_state: case_common.CaseLifecycleState(
            runtime=object(),
            apply_prog_ids=[101, 202],
            artifacts={
                "programs": [
                    {"id": 101, "name": "alpha_prog", "type": "xdp"},
                    {"id": 202, "name": "beta_prog", "type": "kprobe"},
                ],
            },
        ),
        workload=lambda _setup_state, _lifecycle_state, phase: {"phase": phase},
        stop=lambda _setup_state, _lifecycle_state: None,
        cleanup=lambda _setup_state: None,
    )

    assert result.post_rejit == {"phase": "post_rejit"}
    assert calls == [
        ("scan", ([101, 202], ["const_prop", "map_inline", "dce"], 60)),
        ("apply", ([101], ["const_prop", "map_inline"])),
        ("apply", ([202], ["dce"])),
    ]
    assert result.rejit_result is not None
    assert result.rejit_result["selection_source"] == "benchmark_config"
    assert result.rejit_result["scan_enabled_passes"] == ["const_prop", "map_inline", "dce"]
    assert result.rejit_result["effective_enabled_passes_by_program"] == {
        "101": ["const_prop", "map_inline"],
        "202": ["dce"],
    }


def test_measure_app_runner_workload_collects_bpf_and_cpu(monkeypatch) -> None:
    samples = iter(
        [
            {
                101: {
                    "id": 101,
                    "name": "alpha_prog",
                    "run_cnt": 2,
                    "run_time_ns": 20,
                }
            },
            {
                101: {
                    "id": 101,
                    "name": "alpha_prog",
                    "run_cnt": 5,
                    "run_time_ns": 35,
                }
            },
        ]
    )

    class FakeRunner(AppRunner):
        def start(self) -> list[int]:
            return [101]

        def run_workload(self, seconds: float) -> WorkloadResult:
            return WorkloadResult(
                ops_total=12.0,
                ops_per_sec=6.0,
                duration_s=seconds,
                stdout="ok",
                stderr="",
            )

        def run_workload_spec(self, workload_spec, seconds: float) -> WorkloadResult:
            del workload_spec
            return self.run_workload(seconds)

        def stop(self) -> None:
            return None

        def select_corpus_program_ids(self, initial_stats, final_stats) -> list[int] | None:
            del initial_stats, final_stats
            return None

        def corpus_measurement_mode(self) -> str:
            return "app"

        @property
        def pid(self) -> int | None:
            return None

        @property
        def program_fds(self) -> dict[int, int]:
            return {}

        @property
        def last_workload_details(self) -> dict[str, object]:
            return {}

    monkeypatch.setattr(case_common, "sample_bpf_stats", lambda prog_ids, prog_fds=None: next(samples))
    monkeypatch.setattr(case_common, "sample_cpu_usage", lambda pids, duration_s: {321: {"user_pct": 1.5, "sys_pct": 2.5}})
    monkeypatch.setattr(case_common, "sample_total_cpu_usage", lambda duration_s: {"busy_pct": 70.0})
    monkeypatch.setattr(case_common, "compute_delta", lambda before, after: {"summary": {"avg_ns_per_run": 3.0}})

    measurement = case_common.measure_app_runner_workload(
        FakeRunner(),
        2,
        [101],
        agent_pid=321,
    )

    assert measurement["workload"]["ops_total"] == 12.0
    assert measurement["initial_stats"][101]["run_cnt"] == 2
    assert measurement["final_stats"][101]["run_cnt"] == 5
    assert measurement["bpf"]["summary"]["avg_ns_per_run"] == 3.0
    assert measurement["agent_cpu"]["total_pct"] == 4.0
    assert measurement["system_cpu"]["busy_pct"] == 70.0


def test_prepare_daemon_session_requires_captured_kinsn_metadata_when_load_kinsn_requested(tmp_path: Path) -> None:
    class FakeDaemonSession:
        def __init__(self) -> None:
            self.daemon_binary = Path("/tmp/fake-daemon")
            self.stdout_path = tmp_path / "daemon.stdout.log"
            self.stderr_path = tmp_path / "daemon.stderr.log"
            self.stdout_path.write_text("serve: listening on /tmp/rejit.sock\n", encoding="utf-8")
            self.stderr_path.write_text("kinsn discovery:\n  module loaded\n", encoding="utf-8")
            self.load_kinsn = True
            self.kinsn_metadata = {}

    with pytest.raises(RuntimeError, match="did not capture kinsn metadata"):
        case_common.prepare_daemon_session(FakeDaemonSession(), daemon_binary=Path("/tmp/fake-daemon"))


def test_persist_results_truncates_large_nested_strings(tmp_path) -> None:
    case_common.reset_pending_result_metadata()
    large_output = ("abcdef0123456789" * 2000) + "tail-marker"
    payload = {
        "status": "ok",
        "rejit_result": {
            "output": large_output,
        },
    }
    output_json = tmp_path / "result.json"
    output_md = tmp_path / "result.md"

    case_common.persist_results(
        payload,
        output_json,
        output_md,
        lambda persisted_payload: f"status={persisted_payload['status']}",
    )

    persisted = json.loads(output_json.read_text())
    compact_output = persisted["rejit_result"]["output"]
    assert compact_output.startswith(large_output[:64])
    assert compact_output.endswith(large_output[-64:])
    assert "...[truncated " in compact_output
    assert len(compact_output) < len(large_output)
    assert output_md.read_text() == "status=ok"


def test_persist_results_attaches_pending_kinsn_metadata(tmp_path: Path) -> None:
    case_common.reset_pending_result_metadata()
    case_common._append_pending_kinsn_metadata(
        {
            "status": "completed",
            "requested_prog_ids": [101],
            "module_load": {
                "loaded_modules": ["bpf_endian"],
                "failed_modules": [],
            },
        }
    )

    output_json = tmp_path / "result.json"
    output_md = tmp_path / "result.md"
    case_common.persist_results(
        {"status": "ok"},
        output_json,
        output_md,
        lambda payload: payload["metadata"]["kinsn_modules"]["lifecycle_runs"][0]["status"],
    )

    persisted = json.loads(output_json.read_text())
    assert persisted["metadata"]["kinsn_modules"]["count"] == 1
    assert persisted["metadata"]["kinsn_modules"]["lifecycle_runs"][0]["requested_prog_ids"] == [101]
    assert output_md.read_text() == "completed"


def test_host_metadata_records_git_error_in_payload(monkeypatch) -> None:
    def _raise_git_error() -> str:
        raise RuntimeError("fatal: detected dubious ownership")

    monkeypatch.setattr(case_common, "git_sha", _raise_git_error)

    payload = case_common.host_metadata()

    assert payload["git_sha"] is None
    assert "dubious ownership" in str(payload["git_sha_error"])


def test_run_case_lifecycle_marks_kinsn_metadata_error_when_post_rejit_fails(
    tmp_path: Path,
) -> None:
    case_common.reset_pending_result_metadata()

    class FakeProc:
        def poll(self) -> None:
            return None

    daemon_stdout = tmp_path / "daemon.stdout.log"
    daemon_stderr = tmp_path / "daemon.stderr.log"
    daemon_stdout.write_text("serve: listening on /tmp/rejit.sock\n", encoding="utf-8")
    daemon_stderr.write_text("kinsn discovery:\n  module loaded\n", encoding="utf-8")

    class FakeDaemonSession:
        def __init__(self) -> None:
            self.proc = FakeProc()
            self.socket_path = Path("/tmp/rejit.sock")
            self.socket_dir = "/tmp/rejit-dir"
            self.stdout_path = daemon_stdout
            self.stderr_path = daemon_stderr
            self.load_kinsn = True
            self.kinsn_metadata = {
                "expected_modules": ["bpf_rotate"],
                "module_load": {
                    "loaded_modules": ["bpf_rotate"],
                    "failed_modules": [],
                },
                "status": "ready",
            }

        def scan_programs(self, _prog_ids, *, enabled_passes=None, timeout_seconds=60):
            del enabled_passes
            del timeout_seconds
            return {101: {"prog_id": 101, "sites": {}, "counts": {}, "error": ""}}

        def apply_rejit(self, _prog_ids, *, enabled_passes=None):
            del enabled_passes
            return {
                "applied": True,
                "output": "",
                "exit_code": 0,
                "per_program": {101: {"applied": True}},
                "counts": {
                    "total_sites": 1,
                    "applied_sites": 1,
                },
                "error": "",
            }

    daemon_session = FakeDaemonSession()
    prepared_daemon_session = case_common.prepare_daemon_session(
        daemon_session,
        daemon_binary=Path("/tmp/fake-daemon"),
    )

    with pytest.raises(RuntimeError, match="post phase failed"):
        case_common.run_case_lifecycle(
            daemon_session=prepared_daemon_session,
            setup=lambda: {"runtime": "demo"},
            start=lambda _setup_state: case_common.CaseLifecycleState(
                runtime=object(),
                apply_prog_ids=[101],
            ),
            workload=lambda _setup_state, _lifecycle_state, phase: (
                {"phase": phase}
                if phase == "baseline"
                else (_ for _ in ()).throw(RuntimeError("post phase failed"))
            ),
            stop=lambda _setup_state, _lifecycle_state: None,
            cleanup=lambda _setup_state: None,
        )

    assert case_common._PENDING_KINSN_METADATA[-1]["status"] == "error"
    assert "post phase failed" in str(case_common._PENDING_KINSN_METADATA[-1]["error"])
