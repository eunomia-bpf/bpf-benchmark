"""Shared corpus/E2E app runners."""

from __future__ import annotations

import importlib

from .base import AppRunner

def _adapt_bcc(workload: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    tool_name = str(kwargs.pop("tool", "") or "").strip()
    if not tool_name:
        raise TypeError("bcc runner requires args.tool")
    mapped = dict(kwargs)
    mapped["tool_name"] = tool_name
    if workload:
        mapped.setdefault("workload_spec", {"kind": str(workload).strip()})
    return mapped


def _adapt_bpftrace(workload: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    script_name = str(kwargs.pop("script", "") or "").strip()
    if not script_name:
        raise TypeError("bpftrace runner requires args.script")
    mapped = dict(kwargs)
    mapped["script_name"] = script_name
    if workload:
        mapped.setdefault("workload_spec", {"kind": str(workload).strip()})
    return mapped


def _adapt_scx(workload: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    scheduler = str(kwargs.pop("scheduler", "") or "").strip()
    if not scheduler:
        raise TypeError("scx runner requires args.scheduler")
    mapped = dict(kwargs)
    mapped["scheduler"] = scheduler
    if workload:
        kind = str(workload).strip()
        mapped.setdefault("workload_spec", {"name": kind, "kind": kind, "metric": "runs/s"})
    return mapped


def _adapt_tracee(workload: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    mapped = dict(kwargs)
    if workload:
        kind = str(workload).strip()
        mapped.setdefault("workload_spec", {"kind": kind, "name": kind})
    return mapped


def _adapt_tetragon(workload: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    mapped = dict(kwargs)
    if "setup_result" not in mapped:
        from .tetragon import inspect_tetragon_setup

        mapped["setup_result"] = inspect_tetragon_setup()
    if workload:
        kind = str(workload).strip()
        mapped.setdefault("workload_spec", {"kind": kind, "value": 2})
    return mapped


def _adapt_katran(workload: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    mapped = dict(kwargs)
    if workload:
        mapped.setdefault("workload_spec", {"kind": str(workload).strip()})
    return mapped


_RUNNERS = {
    "bcc": ("runner.libs.app_runners.bcc", "BCCRunner", _adapt_bcc),
    "bpftrace": ("runner.libs.app_runners.bpftrace", "BpftraceRunner", _adapt_bpftrace),
    "katran": ("runner.libs.app_runners.katran", "KatranRunner", _adapt_katran),
    "scx": ("runner.libs.app_runners.scx", "ScxRunner", _adapt_scx),
    "tetragon": ("runner.libs.app_runners.tetragon", "TetragonRunner", _adapt_tetragon),
    "tracee": ("runner.libs.app_runners.tracee", "TraceeRunner", _adapt_tracee),
}


def get_app_runner(
    runner: str,
    *,
    workload: str | None = None,
    **kwargs: object,
) -> AppRunner:
    normalized = str(runner or "").strip().lower()
    spec = _RUNNERS.get(normalized)
    if spec is None:
        raise NotImplementedError(f"no shared app runner is implemented for runner {runner!r}")
    module_name, class_name, adapter = spec
    constructor_kwargs = adapter(workload, dict(kwargs))
    module = importlib.import_module(module_name)
    runner_class = getattr(module, class_name)
    return runner_class(**constructor_kwargs)
