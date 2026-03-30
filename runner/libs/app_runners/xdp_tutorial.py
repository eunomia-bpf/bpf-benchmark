from __future__ import annotations

from pathlib import Path

from .. import ROOT_DIR
from ..workload import run_network_load
from .process_support import NativeProcessRunner, WorkloadResult


DEFAULT_BINARY_ROOT = ROOT_DIR / "corpus" / "build" / "xdp-tutorial" / "bin"
_BINARY_BY_OBJECT = {
    "tracing01-xdp-simple/trace_prog_kern.bpf.o": DEFAULT_BINARY_ROOT / "tracing01-xdp-simple" / "trace_load_and_stats",
    "tracing02-xdp-monitor/trace_prog_kern.bpf.o": DEFAULT_BINARY_ROOT / "tracing02-xdp-monitor" / "trace_load_and_stats",
}


class XdpTutorialRunner(NativeProcessRunner):
    def _default_binary_candidates(self) -> tuple[Path, ...]:
        if self.object_path is None:
            return ()
        key = self.object_path.relative_to(ROOT_DIR / "corpus" / "build" / "xdp-tutorial").as_posix()
        candidate = _BINARY_BY_OBJECT.get(key)
        return () if candidate is None else (candidate,)

    def _run_workload(self, seconds: float) -> WorkloadResult:
        return run_network_load(max(1, int(round(seconds))))


__all__ = ["XdpTutorialRunner"]
