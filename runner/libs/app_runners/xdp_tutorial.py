from __future__ import annotations

from pathlib import Path

from .. import ROOT_DIR
from ..workload import run_network_load
from .process_support import NativeProcessRunner, WorkloadResult


DEFAULT_BINARY_ROOT = ROOT_DIR / "corpus" / "build" / "xdp-tutorial" / "bin"
_BINARY_BY_APP = {
    "advanced03-AF_XDP": DEFAULT_BINARY_ROOT / "advanced03-AF_XDP" / "af_xdp_user",
    "basic01-xdp-pass": DEFAULT_BINARY_ROOT / "basic01-xdp-pass" / "xdp_pass_user",
    "basic02-prog-by-name": DEFAULT_BINARY_ROOT / "basic02-prog-by-name" / "xdp_loader",
    "basic03-map-counter": DEFAULT_BINARY_ROOT / "basic03-map-counter" / "xdp_load_and_stats",
    "basic04-pinning-maps": DEFAULT_BINARY_ROOT / "basic04-pinning-maps" / "xdp_loader",
    "experiment01-tailgrow": DEFAULT_BINARY_ROOT / "experiment01-tailgrow" / "xdp-loader",
    "packet-solutions": DEFAULT_BINARY_ROOT / "packet-solutions" / "xdp-loader",
    "packet01-parsing": DEFAULT_BINARY_ROOT / "packet01-parsing" / "xdp-loader",
    "packet02-rewriting": DEFAULT_BINARY_ROOT / "packet02-rewriting" / "xdp-loader",
    "packet03-redirecting": DEFAULT_BINARY_ROOT / "packet03-redirecting" / "xdp-loader",
    "tracing01-xdp-simple": DEFAULT_BINARY_ROOT / "tracing01-xdp-simple" / "trace_load_and_stats",
    "tracing02-xdp-monitor": DEFAULT_BINARY_ROOT / "tracing02-xdp-monitor" / "trace_load_and_stats",
    "tracing03-xdp-debug-print": DEFAULT_BINARY_ROOT / "tracing03-xdp-debug-print" / "xdp-loader",
    "tracing04-xdp-tcpdump": DEFAULT_BINARY_ROOT / "tracing04-xdp-tcpdump" / "xdp_sample_pkts_user",
}


class XdpTutorialRunner(NativeProcessRunner):
    def __init__(self, *, app: str, **kwargs: object) -> None:
        self.app = str(app).strip()
        if not self.app:
            raise RuntimeError("XdpTutorialRunner requires an app name")
        super().__init__(**kwargs)

    def _default_binary_candidates(self) -> tuple[Path, ...]:
        candidate = _BINARY_BY_APP.get(self.app)
        return () if candidate is None else (candidate,)

    def _run_workload(self, seconds: float) -> WorkloadResult:
        return run_network_load(max(1, int(round(seconds))))


__all__ = ["XdpTutorialRunner"]
