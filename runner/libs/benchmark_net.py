from __future__ import annotations

BENCHMARK_IFACE = "bpfbench0"
BENCHMARK_PEER_IFACE = "bpfbench1"
BENCHMARK_NETNS = "bpfbenchns"
BENCHMARK_IFACE_CIDR = "198.18.0.1/30"
BENCHMARK_PEER_IFACE_CIDR = "198.18.0.2/30"


def _cidr_host(cidr: str) -> str:
    return str(cidr).split("/", 1)[0]


BENCHMARK_IFACE_IP = _cidr_host(BENCHMARK_IFACE_CIDR)
BENCHMARK_PEER_IFACE_IP = _cidr_host(BENCHMARK_PEER_IFACE_CIDR)


def is_benchmark_interface(interface: str | None) -> bool:
    normalized = str(interface or "").strip()
    return normalized in {BENCHMARK_IFACE, BENCHMARK_PEER_IFACE}


__all__ = [
    "BENCHMARK_IFACE",
    "BENCHMARK_IFACE_CIDR",
    "BENCHMARK_IFACE_IP",
    "BENCHMARK_NETNS",
    "BENCHMARK_PEER_IFACE",
    "BENCHMARK_PEER_IFACE_CIDR",
    "BENCHMARK_PEER_IFACE_IP",
    "is_benchmark_interface",
]
