from __future__ import annotations

import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import bpf_stats


def test_sample_bpf_stats_fails_when_prog_fd_lookup_fails(monkeypatch) -> None:
    monkeypatch.setattr(bpf_stats, "resolve_bpftool_binary", lambda: "bpftool")
    monkeypatch.setattr(bpf_stats, "run_json_command", lambda *_args, **_kwargs: [])
    monkeypatch.setattr(bpf_stats, "_prog_fd_by_id", lambda _prog_id: None)

    with pytest.raises(RuntimeError, match="failed to sample BPF stats: prog_id=7: failed to resolve program FD"):
        bpf_stats.sample_bpf_stats([7])


def test_sample_bpf_stats_fails_when_prog_info_lookup_fails(monkeypatch) -> None:
    monkeypatch.setattr(bpf_stats, "resolve_bpftool_binary", lambda: "bpftool")
    monkeypatch.setattr(
        bpf_stats,
        "run_json_command",
        lambda *_args, **_kwargs: [{"id": 7, "name": "demo", "type": "xdp", "run_cnt": 1, "run_time_ns": 10}],
    )
    monkeypatch.setattr(bpf_stats, "_prog_fd_by_id", lambda _prog_id: 91)
    monkeypatch.setattr(bpf_stats, "_prog_info_from_fd", lambda _fd: None)
    monkeypatch.setattr(bpf_stats.os, "close", lambda _fd: None)

    with pytest.raises(RuntimeError, match="failed to read program info by FD"):
        bpf_stats.sample_bpf_stats([7])


def test_sample_bpf_stats_still_fails_without_bpftool_or_fd_info(monkeypatch) -> None:
    monkeypatch.setattr(bpf_stats, "resolve_bpftool_binary", lambda: "bpftool")
    monkeypatch.setattr(bpf_stats, "run_json_command", lambda *_args, **_kwargs: [])
    monkeypatch.setattr(bpf_stats, "_prog_fd_by_id", lambda _prog_id: 91)
    monkeypatch.setattr(bpf_stats, "_prog_info_from_fd", lambda _fd: None)
    monkeypatch.setattr(bpf_stats.os, "close", lambda _fd: None)

    with pytest.raises(RuntimeError, match="failed to read program info by FD"):
        bpf_stats.sample_bpf_stats([7])


def test_libbpf_missing_required_symbol_fails_loudly(monkeypatch) -> None:
    def enable_stats(_mode: int) -> int:
        return 0

    class FakeLib:
        def __init__(self) -> None:
            self.bpf_enable_stats = enable_stats

    bpf_stats._libbpf.cache_clear()
    monkeypatch.setattr(bpf_stats.ctypes, "CDLL", lambda *_args, **_kwargs: FakeLib())

    with pytest.raises(RuntimeError, match="bpf_prog_get_fd_by_id"):
        bpf_stats._libbpf()

    bpf_stats._libbpf.cache_clear()


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
