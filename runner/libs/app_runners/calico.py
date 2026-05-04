from __future__ import annotations

import os
import re
import shutil
import socket
import tempfile
from pathlib import Path
from typing import Mapping

from .. import ROOT_DIR, run_command, which
from ..benchmark_net import (
    BENCHMARK_IFACE,
    BENCHMARK_IFACE_CIDR,
    BENCHMARK_NETNS,
    BENCHMARK_PEER_IFACE,
    BENCHMARK_PEER_IFACE_CIDR,
    is_benchmark_interface,
)
from ..workload import WorkloadResult, run_named_workload
from .etcd_support import LocalEtcdSession
from .process_support import NativeProcessRunner
from .setup_support import optional_repo_artifact_path, pick_host_executable



_BENCHMARK_IFACE_IP = BENCHMARK_IFACE_CIDR.split("/", 1)[0]
_BENCHMARK_HEP_NAME = "bpfbench-hep"
_BENCHMARK_GNP_NAME = "bpfbench-allow-all"


def _runner_hostname() -> str:
    return socket.gethostname().strip() or "localhost"


def _resolve_calicoctl() -> Path:
    candidate = pick_host_executable(
        optional_repo_artifact_path("calico", "bin", "calicoctl"),
        ROOT_DIR / "corpus" / "build" / "calico" / "bin" / "calicoctl",
        ROOT_DIR / "runner" / "repos" / "calico" / "bin" / "calicoctl",
        Path("/usr/bin/calicoctl"),
        Path("/usr/local/bin/calicoctl"),
    )
    if candidate is None:
        raise RuntimeError(
            "calicoctl binary not found; expected at corpus/build/calico/bin/calicoctl, "
            f"{ROOT_DIR}/runner/repos/calico/bin/calicoctl, /usr/bin/calicoctl, "
            "or BPFREJIT_REPO_ARTIFACT_ROOT/calico/bin/calicoctl"
        )
    return candidate


def _anchored_iface_regex(interface: str) -> str:
    normalized = str(interface or "").strip()
    if not normalized:
        raise RuntimeError("interface name is required for anchored_iface_regex")
    return rf"^{re.escape(normalized)}$"


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


def _prepare_calico_device(device: str | None) -> str:
    normalized = str(device or "").strip()
    if not normalized or is_benchmark_interface(normalized):
        return _ensure_benchmark_interface()
    return normalized


class CalicoRunner(NativeProcessRunner):
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
        etcd_startup_timeout_s: int = 20,
        **kwargs: object,
    ) -> None:
        kwargs.setdefault("load_timeout_s", 90)
        super().__init__(**kwargs)
        self.device = str(device or "").strip() or None
        self.node_name = str(node_name or "").strip() or _runner_hostname()
        self.etcd_startup_timeout_s = int(etcd_startup_timeout_s)
        self.etcd_session: LocalEtcdSession | None = None
        self.runtime_dir: Path | None = None

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

    def _run_workload(self, seconds: float) -> WorkloadResult:
        if not self.workload_kind:
            raise RuntimeError("CalicoRunner requires an explicit workload_kind")
        if not self.device:
            raise RuntimeError("CalicoRunner could not determine a network device for workload")
        return run_named_workload(self.workload_kind, seconds, network_device=self.device)

    def run_workload_spec(self, workload_spec: Mapping[str, object], seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError(f"{type(self).__name__} is not running")
        requested_kind = str(workload_spec.get("kind") or workload_spec.get("name") or "").strip()
        if not requested_kind:
            raise RuntimeError(f"{type(self).__name__} workload spec is missing a workload kind")
        if not self.device:
            raise RuntimeError("CalicoRunner could not determine a network device for workload")
        return run_named_workload(requested_kind, seconds, network_device=self.device)

    def _run_startup(self) -> None:
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
        iface_regex = _anchored_iface_regex(self.device)
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
                "FELIX_DEFAULTENDPOINTTOHOSTACTION": "ACCEPT",
                "FELIX_BPFDATAIFACEPATTERN": iface_regex,
                "FELIX_BPFL3IFACEPATTERN": iface_regex,
                "FELIX_LOGFILEPATH": "none",
                "FELIX_LOGSEVERITYSCREEN": "Info",
                "FELIX_LOGSEVERITYSYS": "none",
            }
        )
        if is_benchmark_interface(self.device):
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

    def _set_node_bgp_ipv4(self) -> None:
        """Patch the local Calico Node resource to set spec.bgp.ipv4Address.

        calico-node -startup with CALICO_NETWORKING_BACKEND=none skips writing the BGP
        IPv4 address into the Node resource (startup.go:configureAndCheckIPAddressSubnets
        returns early when backend=none).  Felix's felixnodeprocessor.go converts
        node.Spec.BGP.IPv4Address into a HostIPKey update, which is the only way Felix
        learns d.hostIP.  Without hostIP, bpf_ep_mgr.go:attachDataIfaceProgram() returns
        "unknown host IP" and the main TC datapath programs (calico_tc_main) are never
        attached to the interface, regardless of whether a HostEndpoint is registered.

        Patching the node with the interface IP after -startup completes gives Felix the
        host IP it needs to proceed with TC program attachment.
        """
        calicoctl = _resolve_calicoctl()
        iface = self.device or BENCHMARK_IFACE
        if is_benchmark_interface(iface):
            ip_cidr = BENCHMARK_IFACE_CIDR
        else:
            # For non-benchmark interfaces derive IP from the interface itself.
            import subprocess as _subprocess
            result = _subprocess.run(
                ["ip", "-4", "-o", "addr", "show", "dev", iface],
                capture_output=True,
                text=True,
            )
            match = re.search(r"inet\s+(\S+)", result.stdout)
            if not match:
                raise RuntimeError(
                    f"Cannot determine IPv4 address for interface {iface}; "
                    "set node bgp ipv4Address manually or use the benchmark interface"
                )
            ip_cidr = match.group(1)
        node_yaml = (
            "apiVersion: projectcalico.org/v3\n"
            "kind: Node\n"
            "metadata:\n"
            f"  name: {self.node_name}\n"
            "spec:\n"
            "  bgp:\n"
            f"    ipv4Address: {ip_cidr}\n"
        )
        assert self.runtime_dir is not None
        node_path = self.runtime_dir / "node.yaml"
        node_path.write_text(node_yaml)
        run_command(
            [
                str(calicoctl),
                "apply",
                "--allow-version-mismatch",
                "-f",
                str(node_path),
            ],
            env=self._merged_env(self._startup_env()),
            timeout=30,
        )

    def _apply_allow_policy(self) -> None:
        """Apply a GlobalNetworkPolicy that allows all ingress/egress for the benchmark HEP.

        Calico HostEndpoints enforce a default-deny policy: without an explicit allow rule,
        all traffic through the HEP is dropped.  wrk runs in the root namespace and sends
        packets EGRESS through bpfbench0 to the HTTP server in bpfbenchns; Felix's TC
        datapath attached to bpfbench0 would drop every packet without this allow policy.

        The policy uses a label selector matching the 'benchmark: "true"' label applied to
        the HostEndpoint.  It must be applied BEFORE _register_host_endpoint() so that Felix
        reads an allow policy alongside the HEP when it reconciles.
        """
        calicoctl = _resolve_calicoctl()
        gnp_yaml = (
            "apiVersion: projectcalico.org/v3\n"
            "kind: GlobalNetworkPolicy\n"
            "metadata:\n"
            f"  name: {_BENCHMARK_GNP_NAME}\n"
            "spec:\n"
            "  selector: benchmark == \"true\"\n"
            "  order: 0\n"
            "  ingress:\n"
            "    - action: Allow\n"
            "  egress:\n"
            "    - action: Allow\n"
            "  types:\n"
            "    - Ingress\n"
            "    - Egress\n"
        )
        assert self.runtime_dir is not None
        gnp_path = self.runtime_dir / "gnp.yaml"
        gnp_path.write_text(gnp_yaml)
        run_command(
            [
                str(calicoctl),
                "apply",
                "--allow-version-mismatch",
                "-f",
                str(gnp_path),
            ],
            env=self._merged_env(self._startup_env()),
            timeout=30,
        )

    def _register_host_endpoint(self) -> None:
        """Register a HostEndpoint in etcd so Felix attaches the main TC datapath programs.

        Felix's bpf_ep_mgr.go:attachDataIfaceProgram() only attaches programs like
        from_hep_debug.bpf.o / to_hep_debug.bpf.o when the interface has a corresponding
        HostEndpoint entry in hostIfaceToEpMap.  Without it Felix only loads 6 probe/aux
        programs and never attaches the main datapath TC programs.

        The HEP carries a 'benchmark: "true"' label so that the GlobalNetworkPolicy applied
        by _apply_allow_policy() selects it and permits all ingress/egress.
        """
        calicoctl = _resolve_calicoctl()
        iface = self.device or BENCHMARK_IFACE
        ip_addr = _BENCHMARK_IFACE_IP if is_benchmark_interface(iface) else ""
        hep_yaml = (
            "apiVersion: projectcalico.org/v3\n"
            "kind: HostEndpoint\n"
            "metadata:\n"
            f"  name: {_BENCHMARK_HEP_NAME}\n"
            "  labels:\n"
            "    benchmark: \"true\"\n"
            "spec:\n"
            f"  interfaceName: {iface}\n"
            f"  node: {self.node_name}\n"
        )
        if ip_addr:
            hep_yaml += f"  expectedIPs:\n  - {ip_addr}\n"
        assert self.runtime_dir is not None
        hep_path = self.runtime_dir / "hep.yaml"
        hep_path.write_text(hep_yaml)
        run_command(
            [
                str(calicoctl),
                "apply",
                "--allow-version-mismatch",
                "-f",
                str(hep_path),
            ],
            env=self._merged_env(self._startup_env()),
            timeout=30,
        )

    def _delete_host_endpoint(self) -> None:
        """Delete the benchmark HostEndpoint and allow policy from etcd during teardown."""
        try:
            calicoctl = _resolve_calicoctl()
        except RuntimeError:
            return
        run_command(
            [
                str(calicoctl),
                "delete",
                "--allow-version-mismatch",
                "hostendpoint",
                _BENCHMARK_HEP_NAME,
            ],
            env=self._merged_env(self._startup_env()),
            check=False,
            timeout=15,
        )
        run_command(
            [
                str(calicoctl),
                "delete",
                "--allow-version-mismatch",
                "globalnetworkpolicy",
                _BENCHMARK_GNP_NAME,
            ],
            env=self._merged_env(self._startup_env()),
            check=False,
            timeout=15,
        )

    def start(self) -> list[int]:
        if self.etcd_session is not None:
            raise RuntimeError(f"{type(self).__name__} is already running")
        try:
            self.runtime_dir = LocalEtcdSession.create_runtime_dir(f"{type(self).__name__.lower()}_")
            self.device = _prepare_calico_device(self.device)
            assert self.runtime_dir is not None
            self.etcd_session = LocalEtcdSession(
                work_dir=self.runtime_dir / "etcd",
                name=type(self).__name__.replace("Runner", "").lower() or "runner",
                startup_timeout_s=self.etcd_startup_timeout_s,
            ).start()
            self._run_startup()
            self._set_node_bgp_ipv4()
            self._apply_allow_policy()
            self._register_host_endpoint()
            prog_ids = super().start()
        except Exception:
            self.stop()
            raise
        self.artifacts["benchmark_device"] = str(self.device or "")
        return prog_ids

    def stop(self) -> None:
        super().stop()
        if self.etcd_session is not None:
            self._delete_host_endpoint()
            self.etcd_session.close()
            self.etcd_session = None
        if self.runtime_dir is not None:
            shutil.rmtree(self.runtime_dir, ignore_errors=True)
            self.runtime_dir = None
        # Remove the benchmark veth interface so Felix's orphaned TC BPF programs
        # (which persist after process death because TC attachment is not process-scoped)
        # do not interfere with subsequent app runners (e.g. cilium/agent).
        # _ensure_benchmark_interface() recreates it from scratch on the next start().
        if is_benchmark_interface(self.device):
            _delete_link_if_exists(BENCHMARK_IFACE)
