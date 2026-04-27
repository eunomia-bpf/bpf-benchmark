from __future__ import annotations

import shutil
from pathlib import Path
from typing import Mapping

from .. import ROOT_DIR, run_command
from ..benchmark_net import (
    BENCHMARK_IFACE,
    BENCHMARK_IFACE_CIDR,
    BENCHMARK_NETNS,
    BENCHMARK_PEER_IFACE,
    BENCHMARK_PEER_IFACE_CIDR,
)
from ..workload import WorkloadResult, run_named_workload
from .etcd_support import LocalEtcdSession
from .process_support import NativeProcessRunner
from .setup_support import optional_repo_artifact_path


def _link_exists(name: str) -> bool:
    try:
        run_command(["ip", "-o", "link", "show", "dev", name], timeout=10)
    except Exception:
        return False
    return True


def _delete_link_if_exists(name: str) -> None:
    if not _link_exists(name):
        return
    try:
        run_command(["ip", "link", "delete", "dev", name], timeout=10)
    except Exception:
        pass


def _netns_exists(name: str) -> bool:
    try:
        completed = run_command(["ip", "netns", "list"], timeout=10)
    except Exception:
        return False
    return any(line.split(maxsplit=1)[0].strip() == name for line in completed.stdout.splitlines())


def _link_exists_in_netns(namespace: str, name: str) -> bool:
    if not _netns_exists(namespace):
        return False
    try:
        run_command(["ip", "-n", namespace, "-o", "link", "show", "dev", name], timeout=10)
    except Exception:
        return False
    return True


def _ensure_benchmark_interface() -> str:
    iface_exists = _link_exists(BENCHMARK_IFACE)
    peer_exists_in_root = _link_exists(BENCHMARK_PEER_IFACE)
    peer_exists_in_netns = _link_exists_in_netns(BENCHMARK_NETNS, BENCHMARK_PEER_IFACE)
    if not iface_exists and peer_exists_in_netns:
        run_command(
            ["ip", "-n", BENCHMARK_NETNS, "link", "delete", "dev", BENCHMARK_PEER_IFACE],
            check=False,
            timeout=10,
        )
        peer_exists_in_netns = False
    if iface_exists and not peer_exists_in_netns:
        _delete_link_if_exists(BENCHMARK_IFACE)
        iface_exists = False
        peer_exists_in_root = False
        peer_exists_in_netns = False
    if not _netns_exists(BENCHMARK_NETNS):
        run_command(["ip", "netns", "add", BENCHMARK_NETNS], timeout=10)
    if not iface_exists:
        run_command(
            [
                "ip",
                "link",
                "add",
                "dev",
                BENCHMARK_IFACE,
                "type",
                "veth",
                "peer",
                "name",
                BENCHMARK_PEER_IFACE,
            ],
            timeout=10,
        )
        peer_exists_in_root = True
    if peer_exists_in_root:
        run_command(["ip", "link", "set", "dev", BENCHMARK_PEER_IFACE, "netns", BENCHMARK_NETNS], timeout=10)
    if not _link_exists_in_netns(BENCHMARK_NETNS, BENCHMARK_PEER_IFACE):
        raise RuntimeError(
            f"benchmark peer interface {BENCHMARK_PEER_IFACE} is unavailable in namespace {BENCHMARK_NETNS}"
        )
    run_command(["ip", "addr", "replace", BENCHMARK_IFACE_CIDR, "dev", BENCHMARK_IFACE], timeout=10)
    run_command(["ip", "link", "set", "dev", BENCHMARK_IFACE, "up"], timeout=10)
    run_command(
        ["ip", "-n", BENCHMARK_NETNS, "addr", "replace", BENCHMARK_PEER_IFACE_CIDR, "dev", BENCHMARK_PEER_IFACE],
        timeout=10,
    )
    run_command(["ip", "-n", BENCHMARK_NETNS, "link", "set", "dev", "lo", "up"], timeout=10)
    run_command(["ip", "-n", BENCHMARK_NETNS, "link", "set", "dev", BENCHMARK_PEER_IFACE, "up"], timeout=10)
    return BENCHMARK_IFACE


class CiliumRunner(NativeProcessRunner):
    def __init__(
        self,
        *,
        device: str | None = None,
        cluster_name: str = "default",
        cluster_id: int = 0,
        ipv4_range: str = "10.244.0.0/24",
        etcd_startup_timeout_s: int = 20,
        **kwargs: object,
    ) -> None:
        kwargs.setdefault("load_timeout_s", 120)
        super().__init__(**kwargs)
        self.device = str(device or "").strip() or None
        self.cluster_name = str(cluster_name or "").strip() or "default"
        self.cluster_id = int(cluster_id)
        self.ipv4_range = str(ipv4_range or "").strip() or "10.244.0.0/24"
        self.etcd_startup_timeout_s = int(etcd_startup_timeout_s)
        self.etcd_session: LocalEtcdSession | None = None
        self.runtime_dir: Path | None = None
        self._bpf_root: Path | None = None
        self._state_dir: Path | None = None

    def _default_binary_candidates(self) -> tuple[Path, ...]:
        return tuple(
            candidate
            for candidate in (
                optional_repo_artifact_path("cilium", "bin", "cilium-agent"),
                ROOT_DIR / "corpus" / "build" / "cilium" / "bin" / "cilium-agent",
                ROOT_DIR / "runner" / "repos" / "cilium" / "bin" / "cilium-agent",
                Path("/usr/bin/cilium-agent"),
                Path("/usr/local/bin/cilium-agent"),
            )
            if candidate is not None
        )

    def _run_workload(self, seconds: float) -> WorkloadResult:
        if not self.workload_kind:
            raise RuntimeError("CiliumRunner requires an explicit workload_kind")
        return run_named_workload(self.workload_kind, seconds, network_device=self.device)

    def run_workload_spec(self, workload_spec: Mapping[str, object], seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError(f"{type(self).__name__} is not running")
        requested_kind = str(workload_spec.get("kind") or workload_spec.get("name") or "").strip()
        if not requested_kind:
            raise RuntimeError(f"{type(self).__name__} workload spec is missing a workload kind")
        return run_named_workload(requested_kind, seconds, network_device=self.device)

    def _command(self, binary: Path) -> list[str]:
        if self.etcd_session is None:
            raise RuntimeError("CiliumRunner requires a running etcd session before start")
        if not self.device:
            raise RuntimeError("CiliumRunner could not determine a network device")
        if self._bpf_root is None or self._state_dir is None:
            raise RuntimeError("CiliumRunner runtime paths are not prepared")
        etcd_address = self.etcd_session.client_url.removeprefix("http://")
        return [
            str(binary),
            "--enable-k8s=false",
            "--agent-health-require-k8s-connectivity=false",
            "--enable-ipv4=true",
            "--enable-ipv6=false",
            "--enable-l7-proxy=false",
            "--enable-health-checking=false",
            "--enable-endpoint-health-checking=false",
            "--ipam=cluster-pool",
            f"--ipv4-range={self.ipv4_range}",
            f"--ipv4-native-routing-cidr={self.ipv4_range}",
            "--kvstore=etcd",
            f"--kvstore-opt=etcd.address={etcd_address}",
            f"--cluster-name={self.cluster_name}",
            f"--cluster-id={self.cluster_id}",
            "--routing-mode=native",
            f"--bpf-root={self._bpf_root}",
            f"--state-dir={self._state_dir}",
            f"--devices={self.device}",
            f"--direct-routing-device={self.device}",
            *self.loader_args,
        ]

    def start(self) -> list[int]:
        if self.etcd_session is not None:
            raise RuntimeError(f"{type(self).__name__} is already running")
        try:
            self.runtime_dir = LocalEtcdSession.create_runtime_dir(f"{type(self).__name__.lower()}_")
            assert self.runtime_dir is not None
            self._bpf_root = self.runtime_dir / "bpffs"
            self._state_dir = self.runtime_dir / "state"
            self._bpf_root.mkdir(parents=True, exist_ok=True)
            self._state_dir.mkdir(parents=True, exist_ok=True)
            if self.device is None:
                self.device = _ensure_benchmark_interface()
            self.etcd_session = LocalEtcdSession(
                work_dir=self.runtime_dir / "etcd",
                name=type(self).__name__.replace("Runner", "").lower() or "runner",
                startup_timeout_s=self.etcd_startup_timeout_s,
            ).start()
            return super().start()
        except Exception:
            self.stop()
            raise

    def stop(self) -> None:
        super().stop()
        if self.etcd_session is not None:
            self.etcd_session.close()
            self.etcd_session = None
        if self.runtime_dir is not None:
            shutil.rmtree(self.runtime_dir, ignore_errors=True)
            self.runtime_dir = None
        self._bpf_root = None
        self._state_dir = None
