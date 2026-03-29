"""Shared corpus/E2E app runners."""

from __future__ import annotations

from .bcc import BCCRunner


def get_app_runner(repo: str, **kwargs: object) -> object:
    normalized = str(repo or "").strip().lower()
    if normalized == "bcc":
        return BCCRunner(**kwargs)
    raise NotImplementedError(f"no shared app runner is implemented for repo {repo!r}")


__all__ = [
    "BCCRunner",
    "get_app_runner",
]
