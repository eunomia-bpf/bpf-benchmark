from __future__ import annotations

from pathlib import Path
from typing import Mapping

from .. import ROOT_DIR
from ..workload import WorkloadResult, run_named_workload
from .etcd_support import EtcdBackedNativeRunner, detect_primary_interface
from .setup_support import optional_repo_artifact_path


class CiliumRunner(EtcdBackedNativeRunner):
    def __init__(
        self,
        *,
        device: str | None = None,
        cluster_name: str = "default",
        cluster_id: int = 0,
        ipv4_range: str = "10.244.0.0/24",
        **kwargs: object,
    ) -> None:
        kwargs.setdefault("load_timeout_s", 120)
        super().__init__(**kwargs)
        self.device = str(device or "").strip() or None
        self.cluster_name = str(cluster_name or "").strip() or "default"
        self.cluster_id = int(cluster_id)
        self.ipv4_range = str(ipv4_range or "").strip() or "10.244.0.0/24"
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

    def _after_runtime_prepared(self) -> None:
        if self.runtime_dir is None:
            raise RuntimeError("CiliumRunner runtime directory is not prepared")
        self._bpf_root = self.runtime_dir / "bpffs"
        self._state_dir = self.runtime_dir / "state"
        self._bpf_root.mkdir(parents=True, exist_ok=True)
        self._state_dir.mkdir(parents=True, exist_ok=True)
        if self.device is None:
            self.device = detect_primary_interface(prefer_benchmark=True)

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


__all__ = ["CiliumRunner"]
