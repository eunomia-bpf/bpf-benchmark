from __future__ import annotations

import os
import re
import shutil
import socket
import time
from pathlib import Path
from typing import Mapping

from .. import ROOT_DIR, resolve_bpftool_binary, run_command, run_json_command, tail_text, which
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
from .process_support import (
    NativeProcessRunner,
    describe_process_exit,
    programs_after,
    wait_until_program_set_stable,
)
from .setup_support import optional_repo_artifact_path


def _attached_program_ids_from_payload(payload: object) -> set[int]:
    attached: set[int] = set()
    pending: list[object] = [payload]
    while pending:
        current = pending.pop()
        if isinstance(current, dict):
            prog_id = int(current.get("id", 0) or 0)
            if prog_id > 0:
                attached.add(prog_id)
            pending.extend(current.values())
            continue
        if isinstance(current, list):
            pending.extend(current)
    return attached


def _attached_sched_cls_program_ids(iface: str) -> set[int]:
    payload = run_json_command(
        [resolve_bpftool_binary(), "-j", "net", "show", "dev", str(iface)],
        timeout=30,
    )
    if not isinstance(payload, list):
        raise RuntimeError(f"bpftool net show returned unexpected payload for {iface}")
    attached: set[int] = set()
    for record in payload:
        if not isinstance(record, dict):
            continue
        for key in ("tc", "tcx"):
            if key in record:
                attached.update(_attached_program_ids_from_payload(record[key]))
    if not attached:
        return set()

    current_types = {
        int(record.get("id", 0) or 0): str(record.get("type") or "")
        for record in programs_after(())
        if int(record.get("id", 0) or 0) > 0
    }
    return {
        prog_id
        for prog_id in attached
        if current_types.get(prog_id) == "sched_cls"
    }


def _runner_hostname() -> str:
    return socket.gethostname().strip() or "localhost"


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
        return run_named_workload(self.workload_kind, seconds, network_device=self.device)

    def run_workload_spec(self, workload_spec: Mapping[str, object], seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError(f"{type(self).__name__} is not running")
        requested_kind = str(workload_spec.get("kind") or workload_spec.get("name") or "").strip()
        if not requested_kind:
            raise RuntimeError(f"{type(self).__name__} workload spec is missing a workload kind")
        return run_named_workload(requested_kind, seconds, network_device=self.device)

    def _run_startup(self) -> None:
        self._prime_netfilter_state()
        binary = self._resolve_binary()
        run_command(
            [str(binary), "-startup"],
            env=self._merged_env(self._startup_env()),
            timeout=60,
        )

    def _wait_for_device_sched_cls_programs(self) -> set[int]:
        if self.session is None or self.session.process is None:
            raise RuntimeError("CalicoRunner is not running")
        if not self.device:
            raise RuntimeError("CalicoRunner could not determine a network device")

        deadline = time.monotonic() + max(1.0, float(self.load_timeout_s))
        last_error = ""
        while time.monotonic() < deadline:
            snapshot = self.session.collector_snapshot()
            if exit_reason := describe_process_exit("calico felix", self.session.process, snapshot):
                raise RuntimeError(exit_reason)

            try:
                current_program_ids = {
                    int(program.get("id", 0) or 0)
                    for program in programs_after(self.session.before_ids)
                    if int(program.get("id", 0) or 0) > 0
                }
                attached_ids = _attached_sched_cls_program_ids(self.device)
                fresh_attached_ids = {
                    prog_id
                    for prog_id in attached_ids
                    if prog_id in current_program_ids
                }
                if fresh_attached_ids:
                    return fresh_attached_ids
                last_error = ""
            except Exception as exc:
                last_error = str(exc)
            time.sleep(0.5)

        details = tail_text(
            "\n".join(
                list(self.session.collector_snapshot().get("stderr_tail") or [])
                + list(self.session.collector_snapshot().get("stdout_tail") or [])
            ),
            max_lines=40,
            max_chars=8000,
        )
        message = (
            f"Felix did not attach any sched_cls programs to {self.device} within {self.load_timeout_s}s"
        )
        if last_error:
            message += f": {last_error}"
        if details:
            message += f"\n{details}"
        raise RuntimeError(message)

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
            super().start()
        except Exception:
            self.stop()
            raise
        try:
            attached_ids = self._wait_for_device_sched_cls_programs()
            if self.session is None:
                raise RuntimeError("CalicoRunner lost its session after startup")
            refreshed_programs = wait_until_program_set_stable(
                before_ids=self.session.before_ids,
                timeout_s=self.load_timeout_s,
                process=self.session.process,
                collector_snapshot=self.session.collector_snapshot,
                process_name="calico felix",
            )
        except Exception as exc:
            self._fail_start(f"Calico felix did not finish attaching to {self.device}: {exc}")

        self.session.programs = [dict(program) for program in refreshed_programs]
        self.programs = [dict(program) for program in refreshed_programs]
        self.artifacts["benchmark_device"] = str(self.device or "")
        self.artifacts["benchmark_sched_cls_program_ids"] = sorted(int(prog_id) for prog_id in attached_ids)
        return [int(program["id"]) for program in self.programs if int(program.get("id", 0) or 0) > 0]

    def stop(self) -> None:
        super().stop()
        if self.etcd_session is not None:
            self.etcd_session.close()
            self.etcd_session = None
        if self.runtime_dir is not None:
            shutil.rmtree(self.runtime_dir, ignore_errors=True)
            self.runtime_dir = None


__all__ = ["CalicoRunner"]
