from __future__ import annotations

import json
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import rejit


def test_apply_one_treats_missing_inlined_map_entries_as_empty(monkeypatch) -> None:
    payload = {
        "summary": {"applied": True, "total_sites_applied": 0},
        "program": {"prog_name": "balancer_ingress"},
        "inlined_map_entries": None,
    }

    def fake_run(*args, **kwargs):
        del args, kwargs
        return subprocess.CompletedProcess(
            args=["daemon", "apply", "123"],
            returncode=0,
            stdout=json.dumps(payload),
            stderr="",
        )

    monkeypatch.setattr(rejit.subprocess, "run", fake_run)

    result = rejit._apply_one(Path("/tmp/fake-daemon"), 123)

    assert result["applied"] is True
    assert result["inlined_map_entries"] == []
    assert result["kernel_prog_name"] == "balancer_ingress"


def test_socket_error_result_preserves_supplied_exit_code() -> None:
    result = rejit._socket_error_result(
        123,
        "socket optimize timed out after 120s for prog 123",
        exit_code=124,
    )

    assert result["applied"] is False
    assert result["exit_code"] == 124
    assert "timed out" in str(result["error"])


def test_benchmark_rejit_enabled_passes_respects_explicit_empty_env(monkeypatch) -> None:
    monkeypatch.setenv("BPFREJIT_BENCH_PASSES", "")

    assert rejit.benchmark_rejit_enabled_passes() == []


def test_benchmark_rejit_enabled_passes_uses_default_when_env_missing(monkeypatch) -> None:
    monkeypatch.delenv("BPFREJIT_BENCH_PASSES", raising=False)

    assert rejit.benchmark_rejit_enabled_passes() == ["map_inline", "const_prop", "dce"]


def test_apply_daemon_rejit_empty_pass_list_uses_socket(monkeypatch) -> None:
    calls: list[tuple[str, object]] = []

    def fake_start_daemon_server(_daemon_binary):
        calls.append(("start", None))
        return object(), Path("/tmp/daemon.sock"), "/tmp/daemon-dir", None, None

    def fake_apply_one_via_socket(socket_path, prog_id, enabled_passes, **kwargs):
        del kwargs
        calls.append(("socket", (socket_path, prog_id, list(enabled_passes))))
        return {
            "applied": True,
            "output": "",
            "exit_code": 0,
            "counts": {"total_sites": 0, "applied_sites": 0},
            "error": "",
        }

    def fake_apply_one(_daemon_binary, _prog_id):
        raise AssertionError("CLI apply path should not be used for explicit empty pass lists")

    def fake_stop_daemon_server(_proc, _socket_path, _socket_dir):
        calls.append(("stop", None))

    monkeypatch.setattr(rejit, "_start_daemon_server", fake_start_daemon_server)
    monkeypatch.setattr(rejit, "_apply_one_via_socket", fake_apply_one_via_socket)
    monkeypatch.setattr(rejit, "_apply_one", fake_apply_one)
    monkeypatch.setattr(rejit, "_stop_daemon_server", fake_stop_daemon_server)

    result = rejit.apply_daemon_rejit(Path("/tmp/fake-daemon"), [123], enabled_passes=[])

    assert result["applied"] is True
    assert ("start", None) in calls
    assert ("socket", (Path("/tmp/daemon.sock"), 123, [])) in calls
    assert ("stop", None) in calls


def test_apply_one_via_socket_sends_explicit_empty_pass_list(monkeypatch) -> None:
    sent_payload: dict[str, object] = {}

    class FakeSocket:
        def settimeout(self, _timeout):
            return None

        def connect(self, _path):
            return None

        def sendall(self, payload: bytes) -> None:
            sent_payload.update(json.loads(payload.decode().strip()))

        def recv(self, _size: int) -> bytes:
            return b'{"status":"ok","summary":{"applied":true,"total_sites_applied":0},"program":{"prog_name":"x"}}\n'

        def __enter__(self):
            return self

        def __exit__(self, exc_type, exc, tb):
            del exc_type, exc, tb
            return False

    monkeypatch.setattr(rejit.socket, "socket", lambda *args, **kwargs: FakeSocket())

    result = rejit._apply_one_via_socket(Path("/tmp/daemon.sock"), 321, [])

    assert result["applied"] is True
    assert sent_payload == {"cmd": "optimize", "prog_id": 321, "enabled_passes": []}
