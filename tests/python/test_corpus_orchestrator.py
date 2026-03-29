from __future__ import annotations

import sys
from pathlib import Path
from types import SimpleNamespace

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


def test_run_suite_routes_app_native_and_test_run(monkeypatch, tmp_path: Path) -> None:
    manifest_path = tmp_path / "macro.yaml"
    manifest_path.write_text(
        yaml.safe_dump({"schema_version": 2, "defaults": {"repeat": 7}, "objects": []}, sort_keys=False),
        encoding="utf-8",
    )
    daemon_binary = tmp_path / "daemon"
    runner_binary = tmp_path / "micro_exec"
    daemon_binary.write_text("", encoding="utf-8")
    runner_binary.write_text("", encoding="utf-8")
    daemon_binary.chmod(0o755)
    runner_binary.chmod(0o755)

    objects = [
        SimpleNamespace(
            object_path="corpus/build/bcc/execsnoop.bpf.o",
            object_abs_path=str(tmp_path / "execsnoop.bpf.o"),
            repo="bcc",
            measurement="app_native",
            programs=(SimpleNamespace(program_name="tracepoint__syscalls__sys_enter_execve"),),
        ),
        SimpleNamespace(
            object_path="corpus/build/xdp-tutorial/xdp_pass_kern.bpf.o",
            object_abs_path=str(tmp_path / "xdp_pass_kern.bpf.o"),
            repo="xdp-tutorial",
            measurement="test_run",
            programs=(SimpleNamespace(program_name="xdp_prog_simple", prog_type_name="xdp", section_name="xdp"),),
        ),
    ]

    monkeypatch.setattr(orchestrator, "_manifest_build_report", lambda _path: {"path": _path, "summary": {}, "available_objects": set(), "supplemented_existing": 0})
    monkeypatch.setattr(orchestrator, "load_targets_from_yaml", lambda *_args, **_kwargs: (objects, {"selected_objects": 2}))
    monkeypatch.setattr(
        orchestrator,
        "_start_daemon_server",
        lambda _daemon: (object(), Path("/tmp/rejit.sock"), "/tmp/rejit-dir", Path("/tmp/stdout"), Path("/tmp/stderr")),
    )
    monkeypatch.setattr(orchestrator, "_stop_daemon_server", lambda *_args: None)
    monkeypatch.setattr(
        orchestrator,
        "_run_app_native_entry",
        lambda obj, **_kwargs: {"object": obj.object_path, "measurement": obj.measurement, "status": "ok"},
    )
    monkeypatch.setattr(
        orchestrator,
        "_run_test_run_entry",
        lambda obj, **_kwargs: {"object": obj.object_path, "measurement": obj.measurement, "status": "fallback"},
    )

    args = orchestrator.parse_args(
        [
            "--suite",
            str(manifest_path),
            "--daemon",
            str(daemon_binary),
            "--runner",
            str(runner_binary),
        ]
    )
    payload = orchestrator.run_suite(args)

    assert payload["repeat"] == 7
    assert payload["summary"]["selected_objects"] == 2
    assert payload["summary"]["statuses"] == {"fallback": 1, "ok": 1}
    assert payload["summary"]["measurements"] == {"app_native": 1, "test_run": 1}
