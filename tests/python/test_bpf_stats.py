from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import bpf_stats


def test_read_program_stats_raises_when_requested_program_is_unresolved(monkeypatch) -> None:
    monkeypatch.setattr(bpf_stats, "_prog_fd_by_id", lambda _prog_id: None)

    try:
        bpf_stats.read_program_stats([11])
    except RuntimeError as exc:
        assert "11" in str(exc)
        assert "failed to read BPF stats" in str(exc)
    else:
        raise AssertionError("read_program_stats() unexpectedly succeeded")


def test_read_program_stats_closes_program_fd_after_info_read(monkeypatch) -> None:
    closed: list[int] = []
    info = bpf_stats.BpfProgInfo()
    info.id = 11
    info.name = b"demo"
    info.run_cnt = 5
    info.run_time_ns = 500
    info.jited_prog_len = 64
    info.xlated_prog_len = 32

    monkeypatch.setattr(bpf_stats, "_prog_fd_by_id", lambda _prog_id: 7)
    monkeypatch.setattr(bpf_stats, "_prog_info_from_fd", lambda _fd: info)
    monkeypatch.setattr(bpf_stats.os, "close", lambda fd: closed.append(fd))

    stats = bpf_stats.read_program_stats([11])

    assert stats[11]["name"] == "demo"
    assert stats[11]["exec_ns"] == 100.0
    assert closed == [7]
