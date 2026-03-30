from __future__ import annotations

import json
import subprocess
from pathlib import Path

import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import workload


def test_run_file_io_uses_buffered_fio_and_parses_json(monkeypatch, tmp_path: Path) -> None:
    captured: dict[str, object] = {}

    def fake_run_command(command, **kwargs):
        captured["command"] = list(command)
        captured["kwargs"] = dict(kwargs)
        payload = {
            "jobs": [
                {
                    "read": {"total_ios": 5, "iops": 2.0},
                    "write": {"total_ios": 7, "iops": 3.0},
                }
            ]
        }
        return subprocess.CompletedProcess(
            list(command),
            0,
            stdout=json.dumps(payload),
            stderr="",
        )

    monotonic_values = iter([100.0, 102.5])

    monkeypatch.setattr(workload, "which", lambda name: "/usr/bin/fio" if name == "fio" else None)
    monkeypatch.setattr(workload, "_disk_backed_tmp_root", lambda: tmp_path)
    monkeypatch.setattr(workload, "run_command", fake_run_command)
    monkeypatch.setattr(workload.time, "monotonic", lambda: next(monotonic_values))

    result = workload.run_file_io(2)

    command = captured["command"]
    assert isinstance(command, list)
    assert "--rw=randwrite" in command
    assert "--direct=1" not in command
    assert "--fsync=1" in command
    assert "--invalidate=1" in command
    assert result.ops_total == 12.0
    assert result.duration_s == 2.5
    assert result.ops_per_sec == 12.0 / 2.5
