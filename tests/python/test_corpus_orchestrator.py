from __future__ import annotations

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


def test_run_suite_routes_app_native_and_test_run(monkeypatch, tmp_path: Path) -> None:
    manifest_path = tmp_path / "macro.yaml"
    manifest_path.write_text(
        yaml.safe_dump({"schema_version": 2, "defaults": {"repeat": 7}, "objects": []}, sort_keys=False),
        encoding="utf-8",
    )
    daemon_binary = tmp_path / "daemon"
    daemon_binary.write_text("", encoding="utf-8")
    daemon_binary.chmod(0o755)

    objects = [
        SimpleNamespace(
            object_path="corpus/build/bcc/execsnoop.bpf.o",
            object_abs_path=str(tmp_path / "execsnoop.bpf.o"),
            repo="bcc",
            measurement="app_native",
            programs=(SimpleNamespace(program_name="tracepoint__syscalls__sys_enter_execve"),),
        ),
        SimpleNamespace(
            object_path="corpus/build/bcc/opensnoop.bpf.o",
            object_abs_path=str(tmp_path / "opensnoop.bpf.o"),
            repo="bcc",
            measurement="app_native",
            programs=(SimpleNamespace(program_name="tracepoint__syscalls__sys_enter_openat"),),
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
    monkeypatch.setattr(orchestrator, "load_targets_from_yaml", lambda *_args, **_kwargs: (objects, {"selected_objects": 3}))

    class FakeProc:
        def poll(self) -> None:
            return None

    class FakeDaemonSession:
        def __init__(self) -> None:
            self.proc = FakeProc()
            self.socket_path = Path("/tmp/rejit.sock")

        @classmethod
        def start(cls, _daemon: Path) -> "FakeDaemonSession":
            return cls()

        def __enter__(self) -> "FakeDaemonSession":
            return self

        def __exit__(self, exc_type: object, exc: object, tb: object) -> None:
            del exc_type, exc, tb

        def close(self) -> None:
            return None

    monkeypatch.setattr(orchestrator, "DaemonSession", FakeDaemonSession)

    batch_calls: list[tuple[str, tuple[str, ...]]] = []

    def fake_run_app_native_repo_group(indexed_group, **_kwargs):
        batch_calls.append((indexed_group[0][1].repo, tuple(obj.object_path for _, obj in indexed_group)))
        return (
            [
                (
                    index,
                    {"object": obj.object_path, "measurement": obj.measurement, "status": "ok", "repo": obj.repo},
                )
                for index, obj in indexed_group
            ],
            {
                "repo": indexed_group[0][1].repo,
                "measurement": "app_native",
                "status": "ok",
                "objects": [obj.object_path for _, obj in indexed_group],
            },
        )

    monkeypatch.setattr(orchestrator, "_run_app_native_repo_group", fake_run_app_native_repo_group)
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
        ]
    )
    payload = orchestrator.run_suite(args)

    assert payload["repeat"] == 7
    assert payload["summary"]["selected_objects"] == 3
    assert payload["summary"]["statuses"] == {"fallback": 1, "ok": 2}
    assert payload["summary"]["measurements"] == {"app_native": 2, "test_run": 1}
    assert batch_calls == [
        (
            "bcc",
            (
                "corpus/build/bcc/execsnoop.bpf.o",
                "corpus/build/bcc/opensnoop.bpf.o",
            ),
        )
    ]
    assert payload["app_native_batches"] == [
        {
            "repo": "bcc",
            "measurement": "app_native",
            "status": "ok",
            "objects": [
                "corpus/build/bcc/execsnoop.bpf.o",
                "corpus/build/bcc/opensnoop.bpf.o",
            ],
        }
    ]


def test_parse_args_rejects_invalid_repeat_and_workload_seconds() -> None:
    with pytest.raises(SystemExit, match="--repeat must be >= 0"):
        orchestrator.parse_args(["--repeat", "-1"])

    with pytest.raises(SystemExit, match="--workload-seconds must be > 0"):
        orchestrator.parse_args(["--workload-seconds", "0"])
