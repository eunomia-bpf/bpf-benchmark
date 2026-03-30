from __future__ import annotations

import io
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs.app_runners import scx_support


class _FakeProcess:
    def __init__(self) -> None:
        self.stdout = io.StringIO("")
        self.stderr = io.StringIO("")
        self.pid = 4321

    def poll(self) -> None:
        return None


def test_scx_scheduler_session_uses_fail_fast_shell_wrapper(monkeypatch) -> None:
    launched: dict[str, object] = {}

    def fake_start_agent(binary: str, args, env=None):
        launched["binary"] = binary
        launched["args"] = list(args)
        launched["env"] = dict(env or {})
        return _FakeProcess()

    monkeypatch.setattr(scx_support, "start_agent", fake_start_agent)
    monkeypatch.setattr(scx_support, "wait_healthy", lambda proc, timeout, health_check: True)
    monkeypatch.setattr(
        scx_support.ScxSchedulerSession,
        "_discover_programs",
        lambda self: [{"id": 101, "type": "struct_ops"}],
    )
    monkeypatch.setattr(scx_support, "stop_agent", lambda proc, timeout=8: 0)

    session = scx_support.ScxSchedulerSession(Path("/tmp/scx_rusty"), ["--slice", "2"], 15)
    with session as active:
        assert active.programs == [{"id": 101, "type": "struct_ops"}]

    assert launched["binary"] == "bash"
    assert launched["args"][0] == "-lc"
    command_text = str(launched["args"][1])
    assert command_text.startswith("set -euo pipefail; ulimit -l unlimited; exec ")
    assert " /tmp/scx_rusty --stats 1 --slice 2" in command_text
