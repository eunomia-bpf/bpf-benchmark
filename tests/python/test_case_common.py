from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from e2e import case_common
from runner.libs import rejit


def test_run_case_lifecycle_reuses_single_daemon_session(monkeypatch) -> None:
    daemon_proc = object()
    daemon_socket = Path("/tmp/rejit.sock")
    daemon_stdout = Path("/tmp/rejit.stdout.log")
    daemon_stderr = Path("/tmp/rejit.stderr.log")
    calls: list[tuple[str, object]] = []
    phases: list[str] = []

    def fake_start_daemon_server(daemon_binary):
        calls.append(("start", daemon_binary))
        return daemon_proc, daemon_socket, "/tmp/rejit-dir", daemon_stdout, daemon_stderr

    def fake_stop_daemon_server(proc, socket_path, socket_dir):
        calls.append(("stop", (proc, socket_path, socket_dir)))

    def fake_scan_programs(prog_ids, daemon_binary, **kwargs):
        calls.append(
            (
                "scan",
                {
                    "prog_ids": list(prog_ids),
                    "daemon_binary": daemon_binary,
                    "daemon_socket_path": kwargs["daemon_socket_path"],
                    "daemon_proc": kwargs["daemon_proc"],
                    "daemon_stdout_path": kwargs["daemon_stdout_path"],
                    "daemon_stderr_path": kwargs["daemon_stderr_path"],
                    "timeout_seconds": kwargs["timeout_seconds"],
                },
            )
        )
        return {
            101: {
                "enumerate_record": None,
                "sites": {},
                "counts": {},
                "error": "",
            }
        }

    def fake_apply_daemon_rejit(daemon_binary, prog_ids, *, enabled_passes=None, **kwargs):
        calls.append(
            (
                "apply",
                {
                    "prog_ids": list(prog_ids),
                    "daemon_binary": daemon_binary,
                    "enabled_passes": list(enabled_passes or []),
                    "daemon_socket_path": kwargs["daemon_socket_path"],
                    "daemon_proc": kwargs["daemon_proc"],
                    "daemon_stdout_path": kwargs["daemon_stdout_path"],
                    "daemon_stderr_path": kwargs["daemon_stderr_path"],
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

    monkeypatch.setattr(rejit, "_start_daemon_server", fake_start_daemon_server)
    monkeypatch.setattr(rejit, "_stop_daemon_server", fake_stop_daemon_server)
    monkeypatch.setattr(rejit, "scan_programs", fake_scan_programs)
    monkeypatch.setattr(rejit, "apply_daemon_rejit", fake_apply_daemon_rejit)

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

    result = case_common.run_case_lifecycle(
        daemon_binary=Path("/tmp/fake-daemon"),
        setup=setup,
        start=start,
        workload=workload,
        stop=stop,
        cleanup=cleanup,
        enabled_passes=["map_inline"],
    )

    assert result.baseline == {"phase": "baseline"}
    assert result.post_rejit == {"phase": "post_rejit"}
    assert [entry[0] for entry in calls] == ["start", "scan", "apply", "stop"]
    assert calls[1][1]["daemon_socket_path"] == daemon_socket
    assert calls[2][1]["daemon_socket_path"] == daemon_socket
    assert calls[1][1]["daemon_proc"] is daemon_proc
    assert calls[2][1]["daemon_proc"] is daemon_proc
    assert calls[1][1]["timeout_seconds"] == 33
    assert calls[2][1]["enabled_passes"] == ["map_inline"]
    assert phases == [
        "setup",
        "start",
        "workload:baseline",
        "workload:post_rejit",
        "stop",
        "cleanup",
    ]
