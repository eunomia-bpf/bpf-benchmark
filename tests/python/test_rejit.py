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
