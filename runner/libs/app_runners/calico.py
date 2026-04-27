from __future__ import annotations

import os
import time
from pathlib import Path
from typing import Mapping

from .. import ROOT_DIR, resolve_bpftool_binary, run_command, run_json_command, tail_text, which
from .process_support import describe_process_exit, programs_after, wait_until_program_set_stable
from ..workload import WorkloadResult, run_named_workload
from .etcd_support import (
    EtcdBackedNativeRunner,
    anchored_iface_regex,
    detect_primary_interface,
    ensure_benchmark_interface,
    is_synthetic_benchmark_interface,
    runner_hostname,
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
        elif is_synthetic_benchmark_interface(self.device):
            self.device = ensure_benchmark_interface()

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

    def start(self) -> list[int]:
        super().start()
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


__all__ = ["CalicoRunner"]
