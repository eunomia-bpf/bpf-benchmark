from __future__ import annotations

import http.client
import json
import os
import shutil
import signal
import socket
import time
import urllib.parse
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Mapping, Sequence

from .. import ROOT_DIR, run_command, tail_text
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
from .native_loader_env import native_loader_manifest_env
from .process_support import NativeProcessRunner
from .setup_support import optional_repo_artifact_path


_CILIUM_API_BASE = "/v1"
_CILIUM_ENDPOINT_PEER_IFACE = "eth0"


@dataclass(frozen=True)
class _CiliumEndpointSpec:
    namespace: str
    host_if: str
    container_id: str
    label: str


_CILIUM_ENDPOINT_SPECS: tuple[_CiliumEndpointSpec, ...] = (
    _CiliumEndpointSpec("bpfbench-cepa", "lxcbench0", "bpfbench-cepa", "a"),
    _CiliumEndpointSpec("bpfbench-cepb", "lxcbench1", "bpfbench-cepb", "b"),
)


class _UnixHTTPConnection(http.client.HTTPConnection):
    def __init__(self, socket_path: Path) -> None:
        super().__init__("localhost")
        self.socket_path = Path(socket_path)

    def connect(self) -> None:
        sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        try:
            sock.connect(str(self.socket_path))
        except Exception:
            sock.close()
            raise
        self.sock = sock


def _api_json(
    socket_path: Path,
    method: str,
    path: str,
    *,
    body: Mapping[str, object] | None = None,
    expected_status: Sequence[int] = (200,),
) -> Any:
    payload = None if body is None else json.dumps(body, sort_keys=True).encode()
    headers = {"Accept": "application/json", "Host": "localhost"}
    if payload is not None:
        headers["Content-Type"] = "application/json"
        headers["Content-Length"] = str(len(payload))
    connection = _UnixHTTPConnection(socket_path)
    try:
        connection.request(method, path, body=payload, headers=headers)
        response = connection.getresponse()
        raw = response.read()
    finally:
        connection.close()
    text = raw.decode("utf-8", errors="replace")
    if response.status not in {int(status) for status in expected_status}:
        raise RuntimeError(
            f"Cilium API {method} {path} returned HTTP {response.status}: "
            f"{tail_text(text, max_lines=20, max_chars=4000)}"
        )
    if not text.strip():
        return {}
    try:
        return json.loads(text)
    except json.JSONDecodeError as exc:
        raise RuntimeError(f"Cilium API {method} {path} returned invalid JSON: {tail_text(text)}") from exc


def _endpoint_api_path(endpoint_id: int | str) -> str:
    return _CILIUM_API_BASE + "/endpoint/" + urllib.parse.quote(str(endpoint_id), safe="")


def _link_exists(name: str) -> bool:
    try:
        run_command(["ip", "-o", "link", "show", "dev", name])
    except Exception:
        return False
    return True


def _delete_link_if_exists(name: str) -> None:
    if not _link_exists(name):
        return
    try:
        run_command(["ip", "link", "delete", "dev", name])
    except Exception:
        pass


def _netns_exists(name: str) -> bool:
    try:
        completed = run_command(["ip", "netns", "list"])
    except Exception:
        return False
    return any(line.split(maxsplit=1)[0].strip() == name for line in completed.stdout.splitlines())


def _link_exists_in_netns(namespace: str, name: str) -> bool:
    if not _netns_exists(namespace):
        return False
    try:
        run_command(["ip", "-n", namespace, "-o", "link", "show", "dev", name])
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
        )
        peer_exists_in_netns = False
    if iface_exists and not peer_exists_in_netns:
        _delete_link_if_exists(BENCHMARK_IFACE)
        iface_exists = False
        peer_exists_in_root = False
        peer_exists_in_netns = False
    if not _netns_exists(BENCHMARK_NETNS):
        run_command(["ip", "netns", "add", BENCHMARK_NETNS])
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
        )
        peer_exists_in_root = True
    if peer_exists_in_root:
        run_command(["ip", "link", "set", "dev", BENCHMARK_PEER_IFACE, "netns", BENCHMARK_NETNS])
    if not _link_exists_in_netns(BENCHMARK_NETNS, BENCHMARK_PEER_IFACE):
        raise RuntimeError(
            f"benchmark peer interface {BENCHMARK_PEER_IFACE} is unavailable in namespace {BENCHMARK_NETNS}"
        )
    run_command(["ip", "addr", "replace", BENCHMARK_IFACE_CIDR, "dev", BENCHMARK_IFACE])
    run_command(["ip", "link", "set", "dev", BENCHMARK_IFACE, "up"])
    run_command(
        ["ip", "-n", BENCHMARK_NETNS, "addr", "replace", BENCHMARK_PEER_IFACE_CIDR, "dev", BENCHMARK_PEER_IFACE],
    )
    run_command(["ip", "-n", BENCHMARK_NETNS, "link", "set", "dev", "lo", "up"])
    run_command(["ip", "-n", BENCHMARK_NETNS, "link", "set", "dev", BENCHMARK_PEER_IFACE, "up"])
    return BENCHMARK_IFACE


def _delete_netns_if_exists(name: str) -> None:
    if _netns_exists(name):
        run_command(["ip", "netns", "delete", name], check=False)


def _link_json(name: str, *, namespace: str | None = None) -> dict[str, object]:
    command = ["ip", "-j"]
    if namespace is not None:
        command += ["-n", namespace]
    command += ["link", "show", "dev", name]
    payload = json.loads(run_command(command).stdout)
    if not isinstance(payload, list) or not payload or not isinstance(payload[0], dict):
        raise RuntimeError(f"could not read link metadata for {name}")
    return dict(payload[0])


def _link_address(name: str, *, namespace: str | None = None) -> str:
    address = str(_link_json(name, namespace=namespace).get("address") or "").strip()
    if not address:
        raise RuntimeError(f"link {name} has no MAC address")
    return address


def _link_ifindex(name: str, *, namespace: str | None = None) -> int:
    ifindex = int(_link_json(name, namespace=namespace).get("ifindex", 0) or 0)
    if ifindex <= 0:
        raise RuntimeError(f"link {name} has no ifindex")
    return ifindex


class CiliumRunner(NativeProcessRunner):
    def __init__(
        self,
        *,
        device: str | None = None,
        cluster_name: str = "default",
        cluster_id: int = 0,
        ipv4_range: str = "10.244.0.0/24",
        **kwargs: object,
    ) -> None:
        super().__init__(**kwargs)
        self.device = str(device or "").strip() or None
        self.cluster_name = str(cluster_name or "").strip() or "default"
        self.cluster_id = int(cluster_id)
        self.ipv4_range = str(ipv4_range or "").strip() or "10.244.0.0/24"
        self.etcd_session: LocalEtcdSession | None = None
        self.runtime_dir: Path | None = None
        self._bpf_root: Path | None = None
        self._state_dir: Path | None = None
        self._managed_endpoint_ids: list[int] = []
        self._agent_paused: bool = False

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
        if not self.device:
            raise RuntimeError("CiliumRunner could not determine a network device for workload")
        self._pause_agent()
        try:
            return run_named_workload(self.workload_kind, seconds, network_device=self.device)
        finally:
            self._resume_agent()

    def run_workload_spec(self, workload_spec: Mapping[str, object], seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError(f"{type(self).__name__} is not running")
        requested_kind = str(workload_spec.get("kind") or workload_spec.get("name") or "").strip()
        if not requested_kind:
            raise RuntimeError(f"{type(self).__name__} workload spec is missing a workload kind")
        if not self.device:
            raise RuntimeError("CiliumRunner could not determine a network device for workload")
        self._pause_agent()
        try:
            return run_named_workload(requested_kind, seconds, network_device=self.device)
        finally:
            self._resume_agent()

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
            # Disable userspace continuous reload features so Cilium stops
            # rebuilding endpoint BPF every few seconds (otherwise paper-perf
            # measurements include drift-checker / dynamic-config regenerations).
            "--enable-drift-checker=false",
            "--enable-dynamic-config=false",
            "--enable-dynamic-lifecycle-manager=false",
            # Disable the 30s endpoint-bpf-prog watchdog and the 2-minute
            # periodic endpoint-regen timer. Both call orchestrator.Reinitialize
            # / RegenerateAllEndpoints, which re-loads BPF programs mid-
            # measurement and invalidates the prog IDs the corpus driver
            # captured at startup. The runtime topology is fixed during a
            # corpus run so the self-healing timers have nothing to do.
            # Source: pkg/endpoint/watchdog/ep-bpfprog-watchdog.go:25-83 and
            # pkg/endpointmanager/cell.go:222-244.
            "--endpoint-bpf-prog-watchdog-interval=0",
            "--endpoint-regen-interval=0",
            "--enable-monitor=false",
            "--enable-hubble=false",
            "--enable-l2-neigh-discovery=false",
            "--enable-policy=always",
            "--policy-audit-mode=true",
            # Crank up every BPF feature that can run without k8s/external
            # infra so cil_lxc_policy / tail_handle_ipv4_* / xdp_root /
            # bandwidth-manager / host-firewall paths all get exercised.
            "--enable-bpf-masquerade=true",
            "--enable-bpf-clock-probe=true",
            "--enable-ipv4-fragment-tracking=true",
            "--enable-pmtu-discovery=true",
            "--enable-extended-ip-protocols=true",
            "--bpf-conntrack-accounting=true",
            "--enable-xdp-prefilter=true",
            "--bpf-lb-acceleration=native",
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
            f"--socket-path={self._api_socket_path()}",
            f"--devices={self.device}",
            f"--direct-routing-device={self.device}",
            *self.loader_args,
        ]


    def _command_env(self) -> Mapping[str, str] | None:
        env = native_loader_manifest_env("cilium")
        return env or None

    def _api_socket_path(self) -> Path:
        if self._state_dir is None:
            raise RuntimeError("CiliumRunner state directory is not prepared")
        return self._state_dir / "cilium.sock"

    def _wait_for_api(self) -> Mapping[str, object]:
        socket_path = self._api_socket_path()
        while True:
            if self.session is not None and self.session.process is not None:
                returncode = self.session.process.poll()
                if returncode is not None:
                    snapshot = self.session.collector_snapshot()
                    details = tail_text(
                        "\n".join((snapshot.get("stderr_tail") or []) + (snapshot.get("stdout_tail") or [])),
                        max_lines=40,
                        max_chars=8000,
                    )
                    raise RuntimeError(f"cilium-agent exited before API became ready (rc={returncode}): {details}")
            if socket_path.exists():
                try:
                    config = _api_json(socket_path, "GET", f"{_CILIUM_API_BASE}/config", expected_status=(200,))
                    if isinstance(config, Mapping):
                        return config
                    raise RuntimeError("Cilium API /config returned a non-object payload")
                except Exception:
                    pass
            time.sleep(0.2)

    def _allocate_endpoint_ip(self, spec: _CiliumEndpointSpec) -> Mapping[str, object]:
        owner = urllib.parse.quote(spec.container_id, safe="")
        payload = _api_json(
            self._api_socket_path(),
            "POST",
            f"{_CILIUM_API_BASE}/ipam?family=ipv4&owner={owner}",
            expected_status=(201,),
        )
        if not isinstance(payload, Mapping):
            raise RuntimeError(f"Cilium IPAM returned a non-object payload for {spec.container_id}")
        address = payload.get("address")
        ipv4 = payload.get("ipv4")
        host_addressing = payload.get("host-addressing")
        if not isinstance(address, Mapping) or not isinstance(ipv4, Mapping) or not isinstance(host_addressing, Mapping):
            raise RuntimeError(f"Cilium IPAM returned incomplete endpoint addressing for {spec.container_id}: {payload!r}")
        if not str(address.get("ipv4") or "").strip():
            raise RuntimeError(f"Cilium IPAM did not allocate an IPv4 address for {spec.container_id}: {payload!r}")
        return payload

    def _prepare_endpoint_link(self, spec: _CiliumEndpointSpec, ipv4: str, gateway: str) -> None:
        _delete_link_if_exists(spec.host_if)
        _delete_netns_if_exists(spec.namespace)
        run_command(["ip", "netns", "add", spec.namespace])
        run_command(
            [
                "ip",
                "link",
                "add",
                "dev",
                spec.host_if,
                "type",
                "veth",
                "peer",
                "name",
                f"{spec.host_if}p",
            ],
        )
        run_command(["ip", "link", "set", "dev", f"{spec.host_if}p", "netns", spec.namespace])
        run_command(["ip", "link", "set", "dev", spec.host_if, "up"])
        run_command(["sysctl", "-qw", f"net.ipv4.conf.{spec.host_if}.rp_filter=0"])
        run_command(["ip", "-n", spec.namespace, "link", "set", "dev", f"{spec.host_if}p", "name", _CILIUM_ENDPOINT_PEER_IFACE])
        run_command(["ip", "netns", "exec", spec.namespace, "sysctl", "-qw", "net.ipv4.conf.all.rp_filter=0"])
        run_command(["ip", "netns", "exec", spec.namespace, "sysctl", "-qw", f"net.ipv4.conf.{_CILIUM_ENDPOINT_PEER_IFACE}.rp_filter=0"])
        run_command(["ip", "-n", spec.namespace, "link", "set", "dev", "lo", "up"])
        run_command(["ip", "-n", spec.namespace, "link", "set", "dev", _CILIUM_ENDPOINT_PEER_IFACE, "up"])
        run_command(["ip", "-n", spec.namespace, "addr", "replace", f"{ipv4}/32", "dev", _CILIUM_ENDPOINT_PEER_IFACE])
        run_command(
            ["ip", "-n", spec.namespace, "route", "replace", f"{gateway}/32", "dev", _CILIUM_ENDPOINT_PEER_IFACE, "scope", "link"],
        )
        run_command(
            ["ip", "-n", spec.namespace, "route", "replace", "default", "via", gateway, "dev", _CILIUM_ENDPOINT_PEER_IFACE],
        )

    def _create_endpoint(self, spec: _CiliumEndpointSpec) -> int:
        ipam_payload = self._allocate_endpoint_ip(spec)
        addressing = dict(ipam_payload["address"])
        ipv4_payload = dict(ipam_payload["ipv4"])
        host_addressing = dict(ipam_payload["host-addressing"])
        host_ipv4 = host_addressing.get("ipv4")
        if not isinstance(host_ipv4, Mapping):
            raise RuntimeError(f"Cilium IPAM did not return IPv4 host addressing for {spec.container_id}")
        ipv4 = str(addressing.get("ipv4") or "").strip()
        gateway = str(host_ipv4.get("ip") or "").strip()
        if not gateway:
            raise RuntimeError(f"Cilium IPAM did not return an IPv4 endpoint gateway for {spec.container_id}")
        self._prepare_endpoint_link(spec, ipv4, gateway)

        host_mac = _link_address(spec.host_if)
        peer_mac = _link_address(_CILIUM_ENDPOINT_PEER_IFACE, namespace=spec.namespace)
        host_ifindex = _link_ifindex(spec.host_if)
        endpoint_request = {
            "addressing": {
                "ipv4": ipv4,
                "ipv4-pool-name": str(addressing.get("ipv4-pool-name") or ""),
                "ipv4-expiration-uuid": str(ipv4_payload.get("expiration-uuid") or ""),
            },
            "container-id": spec.container_id,
            "container-interface-name": _CILIUM_ENDPOINT_PEER_IFACE,
            "container-name": spec.container_id,
            "container-netns-path": f"/var/run/netns/{spec.namespace}",
            "datapath-configuration": {},
            "host-mac": host_mac,
            "interface-index": host_ifindex,
            "interface-name": spec.host_if,
            "labels": [
                "container:app=bpfbench-cilium",
                f"container:instance={spec.label}",
            ],
            "mac": peer_mac,
            "state": "waiting-for-identity",
            "sync-build-endpoint": True,
        }
        response = _api_json(
            self._api_socket_path(),
            "PUT",
            _endpoint_api_path("0"),
            body=endpoint_request,
            expected_status=(201,),
        )
        if not isinstance(response, Mapping):
            raise RuntimeError(f"Cilium endpoint create returned a non-object payload for {spec.container_id}")
        endpoint_id = int(response.get("id", 0) or 0)
        if endpoint_id <= 0:
            raise RuntimeError(f"Cilium endpoint create did not return a valid ID for {spec.container_id}: {response!r}")
        networking = response.get("status", {})
        if isinstance(networking, Mapping):
            networking = networking.get("networking", {})
        if isinstance(networking, Mapping):
            realized_mac = str(networking.get("mac") or "").strip()
            if realized_mac and realized_mac.lower() != peer_mac.lower():
                run_command(
                    ["ip", "-n", spec.namespace, "link", "set", "dev", _CILIUM_ENDPOINT_PEER_IFACE, "address", realized_mac],
                )
        return endpoint_id

    def _wait_endpoint_ready(self, endpoint_id: int) -> None:
        while True:
            if self.session is not None and self.session.process is not None:
                returncode = self.session.process.poll()
                if returncode is not None:
                    snapshot = self.session.collector_snapshot()
                    details = tail_text(
                        "\n".join((snapshot.get("stderr_tail") or []) + (snapshot.get("stdout_tail") or [])),
                        max_lines=40,
                        max_chars=8000,
                    )
                    raise RuntimeError(f"cilium-agent exited before endpoint {endpoint_id} became ready (rc={returncode}): {details}")
            payload = _api_json(self._api_socket_path(), "GET", _endpoint_api_path(endpoint_id), expected_status=(200,))
            if isinstance(payload, Mapping):
                status = payload.get("status")
                if isinstance(status, Mapping):
                    state = status.get("state")
                    if str(state or "") == "ready":
                        return
            time.sleep(0.2)

    def _setup_managed_endpoints(self) -> None:
        self._wait_for_api()
        self._managed_endpoint_ids = []
        for spec in _CILIUM_ENDPOINT_SPECS:
            endpoint_id = self._create_endpoint(spec)
            self._managed_endpoint_ids.append(endpoint_id)
            self._wait_endpoint_ready(endpoint_id)
        run_command(
            ["ip", "-n", BENCHMARK_NETNS, "route", "replace", self.ipv4_range, "via", BENCHMARK_IFACE_CIDR.split("/", 1)[0]],
        )

    def refresh_programs(self) -> list[dict[str, object]]:
        return []

    def _delete_managed_endpoints(self) -> None:
        if self._state_dir is None:
            return
        socket_path = self._api_socket_path()
        if socket_path.exists():
            for endpoint_id in reversed(self._managed_endpoint_ids):
                try:
                    _api_json(socket_path, "DELETE", _endpoint_api_path(endpoint_id), expected_status=(200, 202, 204, 404))
                except Exception:
                    pass
        self._managed_endpoint_ids = []

    def _cleanup_managed_endpoint_links(self) -> None:
        for spec in _CILIUM_ENDPOINT_SPECS:
            _delete_link_if_exists(spec.host_if)
            _delete_netns_if_exists(spec.namespace)

    def _pause_agent(self) -> None:
        # Freeze cilium-agent userspace after endpoint setup so no controller
        # can call ReloadDatapath() during baseline / post_rejit measurement.
        # TC/XDP datapath programs and pinned maps stay resident in the kernel;
        # packets keep hitting them. SIGSTOP is uncatchable by Go, so this is
        # deterministic. Cleanup must SIGCONT before endpoint deletion.
        process = None if self.session is None else self.session.process
        if process is None or process.poll() is not None or self._agent_paused:
            return
        os.kill(int(process.pid), signal.SIGSTOP)
        self._agent_paused = True

    def _resume_agent(self) -> None:
        process = None if self.session is None else self.session.process
        if process is None or process.poll() is not None or not self._agent_paused:
            self._agent_paused = False
            return
        os.kill(int(process.pid), signal.SIGCONT)
        self._agent_paused = False

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
            self._cleanup_managed_endpoint_links()
            self.etcd_session = LocalEtcdSession(
                work_dir=self.runtime_dir / "etcd",
                name=type(self).__name__.replace("Runner", "").lower() or "runner",
            ).start()
            super().start()
            self._setup_managed_endpoints()
            return []
        except Exception:
            self.stop()
            raise

    def stop(self) -> None:
        self._resume_agent()
        self._delete_managed_endpoints()
        super().stop()
        self._cleanup_managed_endpoint_links()
        if self.etcd_session is not None:
            self.etcd_session.close()
            self.etcd_session = None
        if self.runtime_dir is not None:
            if self._bpf_root is not None and self._bpf_root.is_mount():
                run_command(["umount", str(self._bpf_root)], check=False)
            shutil.rmtree(self.runtime_dir, ignore_errors=True)
            self.runtime_dir = None
        self._bpf_root = None
        self._state_dir = None
        # Remove the benchmark veth so Cilium's orphaned TC BPF programs do not persist
        # into the next benchmark app's run.  TC attachments survive process death because
        # they are scoped to the network interface, not the process.
        # _ensure_benchmark_interface() recreates the veth from scratch on the next start().
        if is_benchmark_interface(self.device):
            _delete_link_if_exists(BENCHMARK_IFACE)


def run_cilium_workload_without_app(workload_name: str, seconds: float) -> WorkloadResult:
    device = _ensure_benchmark_interface()
    try:
        return run_named_workload(workload_name, seconds, network_device=device)
    finally:
        if is_benchmark_interface(device):
            _delete_link_if_exists(BENCHMARK_IFACE)
            _delete_netns_if_exists(BENCHMARK_NETNS)
