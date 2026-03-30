"""Shared corpus/E2E app runners."""

from __future__ import annotations

import importlib
from pathlib import Path
from typing import Any, Callable

from .. import ROOT_DIR


RunnerAdapter = Callable[[str | None, str | None, dict[str, object]], dict[str, object]]


def _leaf_name(app_name: str | None) -> str:
    text = str(app_name or "").strip()
    if not text:
        return ""
    return text.rsplit("/", 1)[-1]


def _pop_string(kwargs: dict[str, object], key: str) -> str:
    value = kwargs.pop(key, "")
    return str(value).strip() if value is not None else ""


def _ensure_no_extra_args(runner: str, kwargs: dict[str, object]) -> None:
    if not kwargs:
        return
    rendered = ", ".join(sorted(kwargs))
    raise TypeError(f"unsupported args for runner {runner!r}: {rendered}")


def _adapt_passthrough(workload: str | None, app_name: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    del workload, app_name
    return kwargs


def _adapt_bcc(workload: str | None, app_name: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    tool_name = _pop_string(kwargs, "tool") or _pop_string(kwargs, "tool_name") or _leaf_name(app_name)
    if not tool_name:
        raise TypeError("bcc runner requires args.tool or an app name leaf")
    mapped = dict(kwargs)
    mapped["tool_name"] = tool_name
    if workload:
        mapped.setdefault("workload_kind", str(workload).strip())
    return mapped


def _adapt_bpftrace(workload: str | None, app_name: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    script_name = _pop_string(kwargs, "script") or _pop_string(kwargs, "script_name") or _leaf_name(app_name)
    if not script_name:
        raise TypeError("bpftrace runner requires args.script or an app name leaf")
    mapped = dict(kwargs)
    mapped["script_name"] = script_name
    if workload:
        mapped.setdefault("workload_kind", str(workload).strip())
    return mapped


def _adapt_scx(workload: str | None, app_name: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    scheduler = _pop_string(kwargs, "scheduler") or _leaf_name(app_name)
    mapped = dict(kwargs)
    if scheduler:
        mapped.setdefault("object_path", ROOT_DIR / "corpus" / "build" / "scx" / f"scx_{scheduler}_main.bpf.o")
        mapped.setdefault("scheduler_binary", ROOT_DIR / "corpus" / "build" / "scx" / "bin" / f"scx_{scheduler}")
    if workload:
        mapped.setdefault("workload_spec", {"name": str(workload), "kind": "hackbench", "metric": "runs/s"})
    return mapped


def _adapt_libbpf_bootstrap(workload: str | None, app_name: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    example = _pop_string(kwargs, "app") or _pop_string(kwargs, "example") or _leaf_name(app_name)
    if not example:
        raise TypeError("libbpf-bootstrap runner requires args.app or an app name leaf")
    mapped = dict(kwargs)
    mapped.setdefault(
        "object_path",
        ROOT_DIR / "corpus" / "build" / "libbpf-bootstrap" / "examples" / "c" / f"{example}.bpf.o",
    )
    if workload:
        mapped.setdefault("workload_kind", str(workload).strip())
    return mapped


def _adapt_systemd(workload: str | None, app_name: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    app = _pop_string(kwargs, "app") or _leaf_name(app_name)
    if not app:
        raise TypeError("systemd runner requires args.app or an app name leaf")
    mapped = dict(kwargs)
    mapped.setdefault("object_path", ROOT_DIR / "corpus" / "build" / "systemd" / f"{app}.bpf.o")
    if workload:
        mapped.setdefault("workload_kind", str(workload).strip())
    return mapped


def _adapt_xdp_tools(workload: str | None, app_name: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    tool = _pop_string(kwargs, "tool") or _leaf_name(app_name)
    if not tool:
        raise TypeError("xdp-tools runner requires args.tool or an app name leaf")
    mapped = dict(kwargs)
    mapped.setdefault("object_path", ROOT_DIR / "corpus" / "build" / "xdp-tools" / f"{tool}.bpf.o")
    if workload:
        mapped.setdefault("workload_kind", str(workload).strip())
    return mapped


_XDP_TUTORIAL_OBJECTS = {
    "advanced03-AF_XDP": "advanced03-AF_XDP/af_xdp_kern.bpf.o",
    "basic01-xdp-pass": "basic01-xdp-pass/xdp_pass_kern.bpf.o",
    "basic02-prog-by-name": "basic02-prog-by-name/xdp_prog_kern.bpf.o",
    "basic03-map-counter": "basic03-map-counter/xdp_prog_kern.bpf.o",
    "basic04-pinning-maps": "basic04-pinning-maps/xdp_prog_kern.bpf.o",
    "experiment01-tailgrow": "experiment01-tailgrow/xdp_prog_kern.bpf.o",
    "packet-solutions": "packet-solutions/xdp_prog_kern_03.bpf.o",
    "packet01-parsing": "packet01-parsing/xdp_prog_kern.bpf.o",
    "packet02-rewriting": "packet02-rewriting/xdp_prog_kern.bpf.o",
    "packet03-redirecting": "packet03-redirecting/xdp_prog_kern.bpf.o",
    "tracing01-xdp-simple": "tracing01-xdp-simple/trace_prog_kern.bpf.o",
    "tracing02-xdp-monitor": "tracing02-xdp-monitor/trace_prog_kern.bpf.o",
    "tracing03-xdp-debug-print": "tracing03-xdp-debug-print/xdp_prog_kern.bpf.o",
    "tracing04-xdp-tcpdump": "tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o",
}


def _adapt_xdp_tutorial(workload: str | None, app_name: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    app = _pop_string(kwargs, "app") or _leaf_name(app_name)
    object_relpath = _XDP_TUTORIAL_OBJECTS.get(app)
    if object_relpath is None:
        raise TypeError(f"unknown xdp-tutorial app: {app!r}")
    mapped = dict(kwargs)
    mapped.setdefault("object_path", ROOT_DIR / "corpus" / "build" / "xdp-tutorial" / object_relpath)
    if workload:
        mapped.setdefault("workload_kind", str(workload).strip())
    return mapped


def _adapt_tracee(workload: str | None, app_name: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    del app_name
    mapped = dict(kwargs)
    if workload:
        kind = "exec_storm" if workload == "tracee_default" else str(workload).strip()
        mapped.setdefault("workload_spec", {"kind": kind, "name": kind})
    return mapped


def _adapt_tetragon(workload: str | None, app_name: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    del app_name
    mapped = dict(kwargs)
    if workload:
        kind = str(workload).strip()
        mapped.setdefault("workload_spec", {"kind": kind, "value": 2})
    return mapped


def _adapt_native_process(workload: str | None, app_name: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    del app_name
    mapped = dict(kwargs)
    if workload:
        mapped.setdefault("workload_kind", str(workload).strip())
    return mapped


_RUNNERS: dict[str, tuple[str, str, RunnerAdapter]] = {
    "bcc": ("runner.libs.app_runners.bcc", "BCCRunner", _adapt_bcc),
    "bpftrace": ("runner.libs.app_runners.bpftrace", "BpftraceRunner", _adapt_bpftrace),
    "calico": ("runner.libs.app_runners.calico", "CalicoRunner", _adapt_native_process),
    "coroot-node-agent": ("runner.libs.app_runners.coroot_node_agent", "CorootNodeAgentRunner", _adapt_native_process),
    "datadog-agent": ("runner.libs.app_runners.datadog_agent", "DatadogAgentRunner", _adapt_native_process),
    "katran": ("runner.libs.app_runners.katran", "KatranRunner", _adapt_passthrough),
    "kubearmor": ("runner.libs.app_runners.kubearmor", "KubeArmorRunner", _adapt_native_process),
    "libbpf-bootstrap": ("runner.libs.app_runners.libbpf_bootstrap", "LibbpfBootstrapRunner", _adapt_libbpf_bootstrap),
    "loxilb": ("runner.libs.app_runners.loxilb", "LoxilbRunner", _adapt_native_process),
    "scx": ("runner.libs.app_runners.scx", "ScxRunner", _adapt_scx),
    "suricata": ("runner.libs.app_runners.suricata", "SuricataRunner", _adapt_native_process),
    "systemd": ("runner.libs.app_runners.systemd", "SystemdRunner", _adapt_systemd),
    "tetragon": ("runner.libs.app_runners.tetragon", "TetragonRunner", _adapt_tetragon),
    "tracee": ("runner.libs.app_runners.tracee", "TraceeRunner", _adapt_tracee),
    "tubular": ("runner.libs.app_runners.tubular", "TubularRunner", _adapt_native_process),
    "xdp-tools": ("runner.libs.app_runners.xdp_tools", "XdpToolsRunner", _adapt_xdp_tools),
    "xdp-tutorial": ("runner.libs.app_runners.xdp_tutorial", "XdpTutorialRunner", _adapt_xdp_tutorial),
}


def _load_runner_class(runner: str) -> type[object]:
    module_name, class_name, _adapter = _RUNNERS[runner]
    module = importlib.import_module(module_name)
    return getattr(module, class_name)


def get_app_runner(
    runner: str,
    *,
    workload: str | None = None,
    app_name: str | None = None,
    **kwargs: object,
) -> object:
    normalized = str(runner or "").strip().lower()
    spec = _RUNNERS.get(normalized)
    if spec is None:
        raise NotImplementedError(f"no shared app runner is implemented for runner {runner!r}")
    module_name, class_name, adapter = spec
    del module_name, class_name
    constructor_kwargs = adapter(workload, app_name, dict(kwargs))
    runner_class = _load_runner_class(normalized)
    instance = runner_class(**constructor_kwargs)
    workload_spec = constructor_kwargs.get("workload_spec")
    if workload_spec is not None and hasattr(instance, "workload_spec"):
        setattr(instance, "workload_spec", workload_spec)
    return instance


__all__ = [
    "get_app_runner",
]
