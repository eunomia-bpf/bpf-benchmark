from __future__ import annotations

from pathlib import Path

from .. import ROOT_DIR
from .process_support import NativeProcessRunner


DEFAULT_BINARY_ROOT = ROOT_DIR / "corpus" / "build" / "xdp-tools" / "bin"
_LOOPBACK = "lo"
_XDP_BENCH = DEFAULT_BINARY_ROOT / "xdp-bench" / "xdp-bench"
_XDP_FORWARD = DEFAULT_BINARY_ROOT / "xdp-forward" / "xdp-forward"
_XDP_MONITOR = DEFAULT_BINARY_ROOT / "xdp-monitor" / "xdp-monitor"
_XDP_TRAFFICGEN = DEFAULT_BINARY_ROOT / "xdp-trafficgen" / "xdp-trafficgen"
_BINARY_BY_TOOL = {
    "xdp_basic": _XDP_BENCH,
    "xdp_load_bytes": _XDP_BENCH,
    "xdp_redirect_basic": _XDP_BENCH,
    "xdp_redirect_cpumap": _XDP_BENCH,
    "xdp_redirect_devmap": _XDP_BENCH,
    "xdp_redirect_devmap_multi": _XDP_BENCH,
    "xdpsock": _XDP_BENCH,
    "xdp_forward": _XDP_FORWARD,
    "xdp_flowtable": _XDP_FORWARD,
    "xdp_flowtable_sample": _XDP_FORWARD,
    "xdp_monitor": _XDP_MONITOR,
    "xdp_sample": _XDP_MONITOR,
    "xdp_trafficgen": _XDP_TRAFFICGEN,
}


class XdpToolsRunner(NativeProcessRunner):
    def __init__(self, *, tool: str, **kwargs: object) -> None:
        self.tool = str(tool).strip()
        if not self.tool:
            raise RuntimeError("XdpToolsRunner requires a tool name")
        super().__init__(**kwargs)

    def _default_binary_candidates(self) -> tuple[Path, ...]:
        candidate = _BINARY_BY_TOOL.get(self.tool)
        return () if candidate is None else (candidate,)

    def _command(self, binary: Path) -> list[str]:
        if self.tool == "xdp_basic":
            return [str(binary), "pass", "--dev", _LOOPBACK, *self.loader_args]
        if self.tool == "xdp_load_bytes":
            return [str(binary), "pass", "--dev", _LOOPBACK, "--load-mode", "load-bytes", *self.loader_args]
        if self.tool == "xdp_redirect_basic":
            return [str(binary), "redirect", "--dev_in", _LOOPBACK, "--dev_out", _LOOPBACK, *self.loader_args]
        if self.tool == "xdp_redirect_cpumap":
            return [str(binary), "redirect-cpu", "--dev", _LOOPBACK, *self.loader_args]
        if self.tool == "xdp_redirect_devmap":
            return [str(binary), "redirect-map", "--dev_in", _LOOPBACK, "--dev_out", _LOOPBACK, *self.loader_args]
        if self.tool == "xdp_redirect_devmap_multi":
            return [str(binary), "redirect-multi", "--devs", _LOOPBACK, *self.loader_args]
        if self.tool == "xdpsock":
            return [str(binary), "xsk-drop", "--dev", _LOOPBACK, *self.loader_args]
        if self.tool == "xdp_forward":
            return [str(binary), "load", _LOOPBACK, *self.loader_args]
        if self.tool in {"xdp_flowtable", "xdp_flowtable_sample"}:
            return [str(binary), "load", "--fwd-mode", "flowtable", _LOOPBACK, *self.loader_args]
        if self.tool == "xdp_trafficgen":
            return [str(binary), "udp", "--interface", _LOOPBACK, *self.loader_args]
        return [str(binary), *self.loader_args]


__all__ = ["XdpToolsRunner"]
