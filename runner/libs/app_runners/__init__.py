"""Shared corpus/E2E app runners."""

from __future__ import annotations

from .bpftrace import BpftraceRunner
from .bcc import BCCRunner
from .katran import KatranRunner
from .scx import ScxRunner
from .tetragon import TetragonRunner
from .tracee import TraceeRunner


def get_app_runner(repo: str, **kwargs: object) -> object:
    normalized = str(repo or "").strip().lower()
    if normalized == "bcc":
        return BCCRunner(**kwargs)
    if normalized == "tracee":
        return TraceeRunner(**kwargs)
    if normalized == "katran":
        return KatranRunner(**kwargs)
    if normalized == "tetragon":
        return TetragonRunner(**kwargs)
    if normalized == "bpftrace":
        return BpftraceRunner(**kwargs)
    if normalized == "scx":
        return ScxRunner(**kwargs)
    raise NotImplementedError(f"no shared app runner is implemented for repo {repo!r}")


__all__ = [
    "BpftraceRunner",
    "BCCRunner",
    "KatranRunner",
    "ScxRunner",
    "TetragonRunner",
    "TraceeRunner",
    "get_app_runner",
]
