from __future__ import annotations

import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import metrics


def test_sample_bpf_stats_fails_when_prog_fd_lookup_fails(monkeypatch) -> None:
    monkeypatch.setattr(metrics, "resolve_bpftool_binary", lambda: "bpftool")
    monkeypatch.setattr(metrics, "run_json_command", lambda *_args, **_kwargs: [])
    monkeypatch.setattr(metrics, "_prog_fd_by_id", lambda _prog_id: None)

    with pytest.raises(RuntimeError, match="failed to sample BPF stats: prog_id=7: failed to resolve program FD"):
        metrics.sample_bpf_stats([7])


def test_sample_bpf_stats_fails_when_prog_info_lookup_fails(monkeypatch) -> None:
    monkeypatch.setattr(metrics, "resolve_bpftool_binary", lambda: "bpftool")
    monkeypatch.setattr(
        metrics,
        "run_json_command",
        lambda *_args, **_kwargs: [{"id": 7, "name": "demo", "type": "xdp", "run_cnt": 1, "run_time_ns": 10}],
    )
    monkeypatch.setattr(metrics, "_prog_fd_by_id", lambda _prog_id: 91)
    monkeypatch.setattr(metrics, "_prog_info_from_fd", lambda _fd: None)
    monkeypatch.setattr(metrics.os, "close", lambda _fd: None)

    with pytest.raises(RuntimeError, match="failed to read program info by FD"):
        metrics.sample_bpf_stats([7])
