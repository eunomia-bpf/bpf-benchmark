from __future__ import annotations

import json
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import case_common


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
    lsmod_outputs = [
        subprocess.CompletedProcess(["lsmod"], 0, "Module                  Size  Used by\n", ""),
        subprocess.CompletedProcess(
            ["lsmod"],
            0,
            "Module                  Size  Used by\n"
            "bpf_endian             16384  0\n"
            "bpf_rotate             16384  0\n",
            "",
        ),
    ]

    def fake_run_command(command, **_kwargs):
        if list(command) == ["lsmod"]:
            return lsmod_outputs.pop(0)
        if str(command[0]).endswith("/module/load_all.sh"):
            return subprocess.CompletedProcess(
                list(command),
                0,
                "Loaded bpf_endian\nLoaded bpf_rotate\nkinsn modules: 2/2 loaded\n",
                "",
            )
        raise AssertionError(f"unexpected command: {command}")

    class FakeDaemonSession:
        def __init__(self, daemon_binary: Path) -> None:
            self.daemon_binary = daemon_binary
            self.proc = daemon_proc
            self.socket_path = daemon_socket
            self.socket_dir = "/tmp/rejit-dir"
            self.stdout_path = daemon_stdout
            self.stderr_path = daemon_stderr
            calls.append(("start", daemon_binary))

        @classmethod
        def start(cls, daemon_binary: Path) -> "FakeDaemonSession":
            return cls(daemon_binary)

        def __enter__(self) -> "FakeDaemonSession":
            return self

        def __exit__(self, exc_type: object, exc: object, tb: object) -> None:
            del exc_type, exc, tb
            self.close()

        def scan_programs(self, prog_ids, *, timeout_seconds=60):
            calls.append(
                (
                    "scan",
                    {
                        "prog_ids": list(prog_ids),
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
                "per_program": {},
                "counts": {
                    "total_sites": 0,
                    "applied_sites": 0,
                },
                "error": "",
            }

        def close(self) -> None:
            calls.append(("stop", (self.proc, self.socket_path, self.socket_dir)))

    monkeypatch.setattr(case_common, "DaemonSession", FakeDaemonSession)
    monkeypatch.setattr(case_common, "_expected_kinsn_modules", lambda: ["bpf_endian", "bpf_rotate"])
    monkeypatch.setattr(case_common, "run_command", fake_run_command)

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
    lsmod_outputs = [
        subprocess.CompletedProcess(["lsmod"], 0, "Module                  Size  Used by\n", ""),
        subprocess.CompletedProcess(
            ["lsmod"],
            0,
            "Module                  Size  Used by\nbpf_endian             16384  0\n",
            "",
        ),
    ]

    def fake_run_command(command, **_kwargs):
        if list(command) == ["lsmod"]:
            return lsmod_outputs.pop(0)
        if str(command[0]).endswith("/module/load_all.sh"):
            return subprocess.CompletedProcess(list(command), 0, "Loaded bpf_endian\n", "")
        raise AssertionError(f"unexpected command: {command}")

    class FakeDaemonSession:
        def __init__(self) -> None:
            self.proc = FakeProc()
            self.socket_path = Path("/tmp/rejit.sock")
            self.socket_dir = "/tmp/rejit-dir"
            self.stdout_path = daemon_stdout
            self.stderr_path = daemon_stderr

        @classmethod
        def start(cls, _daemon_binary: Path) -> "FakeDaemonSession":
            return cls()

        def __enter__(self) -> "FakeDaemonSession":
            return self

        def __exit__(self, exc_type: object, exc: object, tb: object) -> None:
            del exc_type, exc, tb
            self.close()

        def scan_programs(self, _prog_ids, *, timeout_seconds=60):
            del timeout_seconds
            return {101: {"prog_id": 101, "sites": {}, "counts": {}, "error": ""}}

        def apply_rejit(self, _prog_ids, *, enabled_passes=None):
            del enabled_passes
            return {
                "applied": False,
                "output": "",
                "exit_code": 1,
                "per_program": {},
                "counts": {
                    "total_sites": 7,
                    "applied_sites": 7,
                },
                "error": "prog 101: id changed after struct_ops refresh",
            }

        def close(self) -> None:
            return None

    monkeypatch.setattr(case_common, "DaemonSession", FakeDaemonSession)
    monkeypatch.setattr(case_common, "_expected_kinsn_modules", lambda: ["bpf_endian"])
    monkeypatch.setattr(case_common, "run_command", fake_run_command)

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
    assert result.metadata["kinsn_modules"]["module_load"]["loaded_modules"] == ["bpf_endian"]


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
