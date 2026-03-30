"""Shared corpus/E2E app runners."""

from __future__ import annotations

from .bpftrace import BpftraceRunner
from .bcc import BCCRunner
from .coroot_node_agent import CorootNodeAgentRunner
from .datadog_agent import DatadogAgentRunner
from .katran import KatranRunner
from .kubearmor import KubeArmorRunner
from .libbpf_bootstrap import LibbpfBootstrapRunner
from .real_world_code_size import RealWorldCodeSizeRunner
from .scx import ScxRunner
from .systemd import SystemdRunner
from .tetragon import TetragonRunner
from .tracee import TraceeRunner
from .tubular import TubularRunner
from .xdp_tools import XdpToolsRunner
from .xdp_tutorial import XdpTutorialRunner


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
    if normalized == "kubearmor":
        return KubeArmorRunner(**kwargs)
    if normalized == "coroot-node-agent":
        return CorootNodeAgentRunner(**kwargs)
    if normalized == "datadog-agent":
        return DatadogAgentRunner(**kwargs)
    if normalized == "libbpf-bootstrap":
        return LibbpfBootstrapRunner(**kwargs)
    if normalized == "real_world_code_size":
        return RealWorldCodeSizeRunner(**kwargs)
    if normalized == "systemd":
        return SystemdRunner(**kwargs)
    if normalized == "tubular":
        return TubularRunner(**kwargs)
    if normalized == "xdp-tools":
        return XdpToolsRunner(**kwargs)
    if normalized == "xdp-tutorial":
        return XdpTutorialRunner(**kwargs)
    raise NotImplementedError(f"no shared app runner is implemented for repo {repo!r}")


__all__ = [
    "BpftraceRunner",
    "BCCRunner",
    "CorootNodeAgentRunner",
    "DatadogAgentRunner",
    "KatranRunner",
    "KubeArmorRunner",
    "LibbpfBootstrapRunner",
    "RealWorldCodeSizeRunner",
    "ScxRunner",
    "SystemdRunner",
    "TetragonRunner",
    "TraceeRunner",
    "TubularRunner",
    "XdpToolsRunner",
    "XdpTutorialRunner",
    "get_app_runner",
]
