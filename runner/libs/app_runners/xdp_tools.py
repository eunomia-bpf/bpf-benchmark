from __future__ import annotations

from pathlib import Path

from .. import ROOT_DIR
from .process_support import NativeProcessRunner, run_sleep_workload


DEFAULT_BINARY_ROOT = ROOT_DIR / "corpus" / "build" / "xdp-tools" / "bin"
_LOOPBACK = "lo"


class XdpToolsRunner(NativeProcessRunner):
    def _default_binary_candidates(self) -> tuple[Path, ...]:
        if self.object_path is None:
            return ()
        stem = self.object_path.name.removesuffix(".bpf.o")
        if stem in {"xdp_basic", "xdp_redirect_basic", "xdp_redirect_cpumap", "xdp_redirect_devmap", "xdp_redirect_devmap_multi"}:
            return (DEFAULT_BINARY_ROOT / "xdp-bench" / "xdp-bench",)
        if stem in {"xdp_monitor", "xdp_sample"}:
            return (DEFAULT_BINARY_ROOT / "xdp-monitor" / "xdp-monitor",)
        if stem == "xdp_trafficgen":
            return (DEFAULT_BINARY_ROOT / "xdp-trafficgen" / "xdp-trafficgen",)
        return ()

    def _command(self, binary: Path) -> list[str]:
        stem = "" if self.object_path is None else self.object_path.name.removesuffix(".bpf.o")
        if stem == "xdp_basic":
            return [str(binary), "pass", "--dev", _LOOPBACK, *self.loader_args]
        if stem == "xdp_redirect_basic":
            return [str(binary), "redirect", "--dev_in", _LOOPBACK, "--dev_out", _LOOPBACK, *self.loader_args]
        if stem == "xdp_redirect_cpumap":
            return [str(binary), "redirect-cpu", "--dev", _LOOPBACK, *self.loader_args]
        if stem == "xdp_redirect_devmap":
            return [str(binary), "redirect-map", "--dev_in", _LOOPBACK, "--dev_out", _LOOPBACK, *self.loader_args]
        if stem == "xdp_redirect_devmap_multi":
            return [str(binary), "redirect-multi", "--devs", _LOOPBACK, *self.loader_args]
        if stem == "xdp_trafficgen":
            return [str(binary), "udp", "--interface", _LOOPBACK, *self.loader_args]
        return [str(binary), *self.loader_args]

    def _run_workload(self, seconds: float):
        return run_sleep_workload(seconds)


__all__ = ["XdpToolsRunner"]
