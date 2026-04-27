from __future__ import annotations

BENCHMARK_IFACE = "bpfbench0"
BENCHMARK_PEER_IFACE = "bpfbench1"
BENCHMARK_NETNS = "bpfbenchns"
BENCHMARK_IFACE_CIDR = "198.18.0.1/30"
BENCHMARK_PEER_IFACE_CIDR = "198.18.0.2/30"
BENCHMARK_PEER_IFACE_IP = BENCHMARK_PEER_IFACE_CIDR.split("/", 1)[0]


def is_benchmark_interface(interface: str | None) -> bool:
    normalized = str(interface or "").strip()
    return normalized in {BENCHMARK_IFACE, BENCHMARK_PEER_IFACE}
