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


def test_run_suite_splits_program_measurements_and_routes_loader_instances(monkeypatch, tmp_path: Path) -> None:
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
            object_path="corpus/build/tracee/tracee.bpf.o",
            object_abs_path=str(tmp_path / "tracee.bpf.o"),
            repo="tracee",
            measurement="app_native",
            programs=(
                SimpleNamespace(
                    program_name="sys_enter_submit",
                    measurement="app_native",
                ),
                SimpleNamespace(
                    program_name="cgroup_skb_egress",
                    measurement="test_run",
                ),
            ),
        ),
        SimpleNamespace(
            object_path="corpus/build/bcc/execsnoop.bpf.o",
            object_abs_path=str(tmp_path / "execsnoop.bpf.o"),
            repo="bcc",
            measurement="app_native",
            programs=(
                SimpleNamespace(
                    program_name="tracepoint__syscalls__sys_enter_execve",
                    measurement="app_native",
                ),
            ),
        ),
        SimpleNamespace(
            object_path="corpus/build/bcc/opensnoop.bpf.o",
            object_abs_path=str(tmp_path / "opensnoop.bpf.o"),
            repo="bcc",
            measurement="app_native",
            programs=(
                SimpleNamespace(
                    program_name="tracepoint__syscalls__sys_enter_openat",
                    measurement="app_native",
                ),
            ),
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

    batch_calls: list[tuple[str, tuple[str, ...], tuple[tuple[str, ...], ...]]] = []

    def fake_run_app_native_loader_instance(indexed_group, *, loader_label, **_kwargs):
        batch_calls.append(
            (
                loader_label,
                tuple(obj.object_path for _, obj in indexed_group),
                tuple(tuple(program.program_name for program in obj.programs) for _, obj in indexed_group),
            )
        )
        return (
            [
                (
                    index,
                    {
                        "object": obj.object_path,
                        "measurement": obj.measurement,
                        "status": "ok",
                        "repo": obj.repo,
                        "loader_instance": loader_label,
                    },
                )
                for index, obj in indexed_group
            ],
            {
                "repo": indexed_group[0][1].repo,
                "loader_instance": loader_label,
                "measurement": "app_native",
                "status": "ok",
                "objects": [obj.object_path for _, obj in indexed_group],
            },
        )

    monkeypatch.setattr(orchestrator, "_run_app_native_loader_instance", fake_run_app_native_loader_instance)

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
    assert payload["summary"]["selected_manifest_objects"] == 3
    assert payload["summary"]["selected_execution_units"] == 4
    assert payload["summary"]["selected_programs"] == 4
    assert payload["summary"]["statuses"] == {"error": 1, "ok": 3}
    assert payload["summary"]["measurements"] == {"app_native": 3, "test_run": 1}
    assert payload["status"] == "error"
    assert batch_calls == [
        (
            "tracee",
            (
                "corpus/build/tracee/tracee.bpf.o",
            ),
            (("sys_enter_submit",),),
        ),
        (
            "bcc:execsnoop",
            (
                "corpus/build/bcc/execsnoop.bpf.o",
            ),
            (("tracepoint__syscalls__sys_enter_execve",),),
        ),
        (
            "bcc:opensnoop",
            (
                "corpus/build/bcc/opensnoop.bpf.o",
            ),
            (("tracepoint__syscalls__sys_enter_openat",),),
        )
    ]
    assert payload["app_native_batches"] == [
        {
            "repo": "tracee",
            "loader_instance": "tracee",
            "measurement": "app_native",
            "status": "ok",
            "objects": [
                "corpus/build/tracee/tracee.bpf.o",
            ],
        },
        {
            "repo": "bcc",
            "loader_instance": "bcc:execsnoop",
            "measurement": "app_native",
            "status": "ok",
            "objects": [
                "corpus/build/bcc/execsnoop.bpf.o",
            ],
        },
        {
            "repo": "bcc",
            "loader_instance": "bcc:opensnoop",
            "measurement": "app_native",
            "status": "ok",
            "objects": [
                "corpus/build/bcc/opensnoop.bpf.o",
            ],
        }
    ]
    assert any(
        result["measurement"] == "test_run" and "unsupported corpus measurement" in result["error"]
        for result in payload["results"]
    )


def test_parse_args_rejects_invalid_repeat_and_workload_seconds() -> None:
    with pytest.raises(SystemExit, match="--repeat must be >= 0"):
        orchestrator.parse_args(["--repeat", "-1"])

    with pytest.raises(SystemExit, match="--workload-seconds must be > 0"):
        orchestrator.parse_args(["--workload-seconds", "0"])
