"""Shared corpus app runners."""

from __future__ import annotations

import importlib

from .base import AppRunner

def _adapt_bcc(workload: str, kwargs: dict[str, object]) -> dict[str, object]:
    from .bcc import find_tool_binary, inspect_bcc_setup, resolve_tools_dir

    tool_name = str(kwargs.pop("tool", "") or "").strip()
    if not tool_name:
        raise TypeError("bcc runner requires args.tool")
    tool_args = tuple(str(arg) for arg in (kwargs.pop("tool_args", ()) or ()))
    setup_result = inspect_bcc_setup()
    tools_dir = resolve_tools_dir("", setup_result=setup_result)
    tool_binary = find_tool_binary(tools_dir, tool_name)
    if tool_binary is None:
        details = str(setup_result.get("stderr_tail") or "").strip()
        raise RuntimeError(
            details or f"bcc runner could not resolve tool binary for {tool_name!r} under {tools_dir}"
        )
    mapped = dict(kwargs)
    mapped["tool_binary"] = tool_binary
    mapped["tool_args"] = tool_args
    mapped.setdefault("workload_spec", {"kind": str(workload).strip()})
    return mapped


def _adapt_bcc_set(workload: str, kwargs: dict[str, object]) -> dict[str, object]:
    from .bcc import find_tool_binary, inspect_bcc_setup, resolve_tools_dir
    from .bcc_set import BCC_SET_TOOL_SPECS, BCC_SET_WORKLOAD

    normalized_workload = str(workload).strip()
    if normalized_workload != BCC_SET_WORKLOAD:
        raise RuntimeError(f"bcc_set runner requires workload {BCC_SET_WORKLOAD!r}; got {normalized_workload!r}")
    setup_result = inspect_bcc_setup()
    tools_dir = resolve_tools_dir("", setup_result=setup_result)
    tool_binaries: dict[str, object] = {}
    missing: list[str] = []
    for tool in BCC_SET_TOOL_SPECS:
        tool_binary = find_tool_binary(tools_dir, tool.name)
        if tool_binary is None:
            missing.append(tool.name)
            continue
        tool_binaries[tool.name] = tool_binary
    if missing:
        details = str(setup_result.get("stderr_tail") or "").strip()
        suffix = f": {details}" if details else ""
        raise RuntimeError(f"bcc_set runner missing BCC tool binaries: {', '.join(missing)}{suffix}")
    mapped = dict(kwargs)
    mapped["tool_binaries"] = tool_binaries
    mapped.setdefault("workload_spec", {"kind": normalized_workload})
    return mapped


def _adapt_bpftrace(workload: str, kwargs: dict[str, object]) -> dict[str, object]:
    script_name = str(kwargs.pop("script", "") or "").strip()
    if not script_name:
        raise TypeError("bpftrace runner requires args.script")
    mapped = dict(kwargs)
    mapped["script_name"] = script_name
    mapped.setdefault("workload_spec", {"kind": str(workload).strip()})
    return mapped


def _adapt_tracee(workload: str, kwargs: dict[str, object]) -> dict[str, object]:
    mapped = dict(kwargs)
    kind = str(workload).strip()
    mapped.setdefault("workload_spec", {"kind": kind, "name": kind})
    return mapped


def _adapt_tetragon(workload: str, kwargs: dict[str, object]) -> dict[str, object]:
    from .tetragon import inspect_tetragon_setup

    mapped = dict(kwargs)
    mapped["setup_result"] = inspect_tetragon_setup()
    kind = str(workload).strip()
    mapped.setdefault("workload_spec", {"kind": kind, "value": 2})
    return mapped


def _adapt_katran(workload: str, kwargs: dict[str, object]) -> dict[str, object]:
    mapped = dict(kwargs)
    mapped.setdefault("workload_spec", {"kind": str(workload).strip()})
    return mapped


def _adapt_native_process(workload: str, kwargs: dict[str, object]) -> dict[str, object]:
    mapped = dict(kwargs)
    mapped.setdefault("workload_kind", str(workload).strip())
    return mapped


_RUNNERS = {
    "bcc": ("runner.libs.app_runners.bcc", "BCCRunner", _adapt_bcc),
    "bcc_set": ("runner.libs.app_runners.bcc_set", "BccSetRunner", _adapt_bcc_set),
    "bpftrace": ("runner.libs.app_runners.bpftrace", "BpftraceRunner", _adapt_bpftrace),
    "cilium": ("runner.libs.app_runners.cilium", "CiliumRunner", _adapt_native_process),
    "katran": ("runner.libs.app_runners.katran", "KatranRunner", _adapt_katran),
    "otelcol-ebpf-profiler": ("runner.libs.app_runners.otel_profiler", "OtelProfilerRunner", _adapt_native_process),
    "tetragon": ("runner.libs.app_runners.tetragon", "TetragonRunner", _adapt_tetragon),
    "tracee": ("runner.libs.app_runners.tracee", "TraceeRunner", _adapt_tracee),
}


def get_app_runner(
    runner: str,
    *,
    workload: str,
    **kwargs: object,
) -> AppRunner:
    normalized = str(runner or "").strip().lower()
    normalized_workload = str(workload or "").strip()
    if not normalized_workload:
        raise TypeError("get_app_runner requires a non-empty workload")
    spec = _RUNNERS.get(normalized)
    if spec is None:
        raise NotImplementedError(f"no shared app runner is implemented for runner {runner!r}")
    module_name, class_name, adapter = spec
    constructor_kwargs = adapter(normalized_workload, dict(kwargs))
    module = importlib.import_module(module_name)
    runner_class = getattr(module, class_name)
    return runner_class(**constructor_kwargs)
