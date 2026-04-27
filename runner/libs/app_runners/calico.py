from __future__ import annotations

import os
from pathlib import Path
from typing import Mapping

from .. import ROOT_DIR, run_command, which
from ..workload import WorkloadResult, run_named_workload
from .etcd_support import (
    EtcdBackedNativeRunner,
    anchored_iface_regex,
    detect_primary_interface,
    is_synthetic_benchmark_interface,
    runner_hostname,
)
from .setup_support import optional_repo_artifact_path


class CalicoRunner(EtcdBackedNativeRunner):
    _NETFILTER_MODULES = (
        "ip_tables",
        "iptable_filter",
        "iptable_nat",
        "ip6_tables",
        "xt_set",
        "ip_set",
        "nf_conntrack",
        "nf_conntrack_netlink",
    )

    def __init__(
        self,
        *,
        device: str | None = None,
        node_name: str | None = None,
        **kwargs: object,
    ) -> None:
        kwargs.setdefault("load_timeout_s", 90)
        super().__init__(**kwargs)
        self.device = str(device or "").strip() or None
        self.node_name = str(node_name or "").strip() or runner_hostname()

    def _default_binary_candidates(self) -> tuple[Path, ...]:
        return tuple(
            candidate
            for candidate in (
                optional_repo_artifact_path("calico", "bin", "calico-node"),
                ROOT_DIR / "corpus" / "build" / "calico" / "bin" / "calico-node",
                ROOT_DIR / "runner" / "repos" / "calico" / "bin" / "calico-node",
                Path("/usr/bin/calico-node"),
                Path("/usr/local/bin/calico-node"),
            )
            if candidate is not None
        )

    def _after_runtime_prepared(self) -> None:
        if self.device is None:
            self.device = detect_primary_interface(prefer_benchmark=True)

    def _run_workload(self, seconds: float) -> WorkloadResult:
        if not self.workload_kind:
            raise RuntimeError("CalicoRunner requires an explicit workload_kind")
        return run_named_workload(self.workload_kind, seconds, network_device=self.device)

    def run_workload_spec(self, workload_spec: Mapping[str, object], seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError(f"{type(self).__name__} is not running")
        requested_kind = str(workload_spec.get("kind") or workload_spec.get("name") or "").strip()
        if not requested_kind:
            raise RuntimeError(f"{type(self).__name__} workload spec is missing a workload kind")
        return run_named_workload(requested_kind, seconds, network_device=self.device)

    def _after_etcd_started(self) -> None:
        self._prime_netfilter_state()
        binary = self._resolve_binary()
        run_command(
            [str(binary), "-startup"],
            env=self._merged_env(self._startup_env()),
            timeout=60,
        )

    def _command(self, binary: Path) -> list[str]:
        return [str(binary), "-felix", *self.loader_args]

    def _command_env(self) -> dict[str, str]:
        env = self._startup_env()
        if not self.device:
            raise RuntimeError("CalicoRunner could not determine a network device")
        iface_regex = anchored_iface_regex(self.device)
        env.update(
            {
                "FELIX_DATASTORETYPE": "etcdv3",
                "FELIX_ETCDADDR": self._etcd_authority(),
                "FELIX_ETCDENDPOINTS": self._etcd_client_url(),
                "FELIX_ETCDSCHEME": "http",
                "FELIX_FELIXHOSTNAME": self.node_name,
                "FELIX_HEALTHENABLED": "true",
                "FELIX_IPV6SUPPORT": "false",
                "FELIX_IPFORWARDING": "Enabled",
                "FELIX_BPFENABLED": "true",
                "FELIX_BPFKUBEPROXYIPTABLESCLEANUPENABLED": "false",
                "FELIX_BPFCONNECTTIMELOADBALANCING": "Disabled",
                "FELIX_IPTABLESBACKEND": "NFT",
                "FELIX_NFTABLESMODE": "Enabled",
                "FELIX_BPFDATAIFACEPATTERN": iface_regex,
                "FELIX_BPFL3IFACEPATTERN": iface_regex,
                "FELIX_LOGFILEPATH": "none",
                "FELIX_LOGSEVERITYSCREEN": "Info",
                "FELIX_LOGSEVERITYSYS": "none",
            }
        )
        if is_synthetic_benchmark_interface(self.device):
            # The fallback benchmark veth only supports generic XDP attach mode.
            env["FELIX_GenericXDPEnabled"] = "true"
        return env

    def _startup_env(self) -> dict[str, str]:
        if not self.device:
            raise RuntimeError("CalicoRunner could not determine a network device")
        return {
            "DATASTORE_TYPE": "etcdv3",
            "ETCD_ENDPOINTS": self._etcd_client_url(),
            "ETCD_AUTHORITY": self._etcd_authority(),
            "ETCD_SCHEME": "http",
            "NODENAME": self.node_name,
            "CALICO_NODENAME": self.node_name,
            "CALICO_IP": "autodetect",
            "IP": "autodetect",
            "IP_AUTODETECTION_METHOD": f"interface={self.device}",
            "NO_DEFAULT_POOLS": "true",
            "CALICO_NETWORKING_BACKEND": "none",
        }

    def _etcd_client_url(self) -> str:
        if self.etcd_session is None or not self.etcd_session.client_url:
            raise RuntimeError("CalicoRunner requires a running etcd session before start")
        return self.etcd_session.client_url

    def _etcd_authority(self) -> str:
        return self._etcd_client_url().removeprefix("http://").removeprefix("https://")

    def _merged_env(self, env: dict[str, str]) -> dict[str, str]:
        merged = dict(os.environ)
        merged.update(env)
        return merged

    def _prime_netfilter_state(self) -> None:
        modprobe_binary = which("modprobe")
        if modprobe_binary is not None:
            run_command(
                [modprobe_binary, "-a", *self._NETFILTER_MODULES],
                check=False,
                timeout=20,
            )
        for command in (
            ("iptables-legacy", "-w", "-t", "filter", "-S"),
            ("ip6tables-legacy", "-w", "-t", "filter", "-S"),
        ):
            binary = which(command[0])
            if binary is None:
                continue
            run_command([binary, *command[1:]], check=False, timeout=20)


__all__ = ["CalicoRunner"]
