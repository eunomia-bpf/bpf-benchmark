from __future__ import annotations

import time
from pathlib import Path
from typing import Any, Mapping

from .. import tail_text
from ..workload import WorkloadResult
from .base import AppRunner
from .katran_support import (
    CLIENT_NS,
    DEFAULT_KATRAN_BALANCER_PROG_PATH,
    DEFAULT_KATRAN_SERVER_LOAD_TIMEOUT_S,
    DEFAULT_KATRAN_STOP_SETTLE_S,
    KatranDsrTopology,
    KatranServerSession,
    NamespaceHttpServer,
    REAL_NS,
    ROUTER_LB_MAC,
    TOPOLOGY_SETTLE_S,
    VIP_IP,
    VIP_PORT,
    configure_katran_maps,
    resolve_katran_server_binary,
    run_katran_prog_test_run,
    run_parallel_http_load,
    wait_for_katran_teardown,
)


DEFAULT_INTERFACE = "katran0"
DEFAULT_CONCURRENCY = 4
DEFAULT_TEST_RUN_BATCH_REPEAT = 128
DEFAULT_WORKLOAD_KIND = "network"
DEFAULT_LOAD_TIMEOUT_S = DEFAULT_KATRAN_SERVER_LOAD_TIMEOUT_S


class KatranRunner(AppRunner):
    def __init__(
        self,
        *,
        loader_binary: Path | str | None = None,
        iface: str = DEFAULT_INTERFACE,
        router_peer_iface: str | None = None,
        load_timeout_s: int = DEFAULT_LOAD_TIMEOUT_S,
        concurrency: int = DEFAULT_CONCURRENCY,
        workload_kind: str = DEFAULT_WORKLOAD_KIND,
        test_run_batch_repeat: int = DEFAULT_TEST_RUN_BATCH_REPEAT,
        default_router_mac: str = ROUTER_LB_MAC,
    ) -> None:
        super().__init__()
        self.loader_binary = None if loader_binary is None else Path(loader_binary).resolve()
        self.balancer_prog_path = DEFAULT_KATRAN_BALANCER_PROG_PATH.resolve()
        self.iface = str(iface)
        self.router_peer_iface = None if router_peer_iface is None else str(router_peer_iface)
        self.load_timeout_s = int(load_timeout_s)
        self.concurrency = max(1, int(concurrency))
        self.workload_kind = str(workload_kind or DEFAULT_WORKLOAD_KIND).strip().lower()
        self.test_run_batch_repeat = max(1, int(test_run_batch_repeat))
        self.default_router_mac = str(default_router_mac)
        self.topology: Any | None = None
        self.http_server: Any | None = None
        self.session: KatranServerSession | None = None
        self.artifacts: dict[str, object] = {}
        self.last_request_summary: dict[str, object] = {}

    @property
    def prog_id(self) -> int | None:
        return None if self.session is None else int(self.session.prog_id)

    @property
    def pid(self) -> int | None:
        return None if self.session is None else self.session.pid

    def select_corpus_program_ids(
        self,
        initial_stats: Mapping[int, Mapping[str, object]],
        final_stats: Mapping[int, Mapping[str, object]],
    ) -> list[int] | None:
        del initial_stats, final_stats
        return None

    def corpus_measurement_mode(self) -> str:
        return "program"

    @property
    def program_fds(self) -> Mapping[int, int]:
        return {}

    @property
    def last_workload_details(self) -> Mapping[str, object]:
        return dict(self.last_request_summary)

    def start(self) -> list[int]:
        if self.session is not None:
            raise RuntimeError("KatranRunner is already running")

        topology = KatranDsrTopology(self.iface, router_peer_iface=self.router_peer_iface)
        http_server = None if self.workload_kind == "test_run" else NamespaceHttpServer(REAL_NS, VIP_IP, VIP_PORT)
        server_binary = resolve_katran_server_binary(self.loader_binary)
        session = KatranServerSession(
            server_binary=server_binary,
            balancer_prog_path=self.balancer_prog_path,
            iface=self.iface,
            default_router_mac=self.default_router_mac,
            load_timeout_s=self.load_timeout_s,
        )
        try:
            topology.__enter__()
            if http_server is not None:
                http_server.__enter__()
            session.__enter__()
            if self.workload_kind == "network":
                session.reattach_xdpgeneric()
            self.artifacts = {
                "topology": topology.metadata(),
                "http_server": {} if http_server is None else http_server.metadata(),
                "live_program": session.metadata(),
                "map_configuration": configure_katran_maps(session),
                "test_run_validation": run_katran_prog_test_run(session, repeat=1, require_xdp_tx=False),
            }
            time.sleep(TOPOLOGY_SETTLE_S)
        except Exception:
            session.close()
            if http_server is not None:
                http_server.close()
            topology.close()
            raise
        self.topology = topology
        self.http_server = http_server
        self.session = session
        self.loader_binary = server_binary
        self.command_used = list(session.command_used)
        self.programs = [dict(session.program)]
        return [int(session.prog_id)]

    def _run_test_run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError("KatranRunner is not running")
        deadline = time.monotonic() + max(0.1, float(seconds))
        batches = 0
        total_packets = 0
        last_summary: dict[str, object] = {}
        started_at = time.monotonic()
        while time.monotonic() < deadline or batches == 0:
            last_summary = run_katran_prog_test_run(
                self.session,
                repeat=self.test_run_batch_repeat,
                require_xdp_tx=False,
            )
            total_packets += int(last_summary.get("repeat", 0) or 0)
            batches += 1
        elapsed = max(0.000001, time.monotonic() - started_at)
        self.last_request_summary = {
            "driver": "prog_test_run",
            "batches": batches,
            "packet_count": total_packets,
            "duration_s": elapsed,
            "last_result": dict(last_summary),
            "namespace": CLIENT_NS,
        }
        return WorkloadResult(
            ops_total=float(total_packets),
            ops_per_sec=float(total_packets) / elapsed,
            duration_s=elapsed,
            stdout="",
            stderr=tail_text(str(last_summary)),
        )

    def _run_network_workload(self, seconds: float) -> WorkloadResult:
        summary = run_parallel_http_load(duration_s=max(1.0, float(seconds)), concurrency=self.concurrency)
        self.last_request_summary = dict(summary)
        request_count = int(summary.get("request_count", 0) or 0)
        success_count = int(summary.get("success_count", 0) or 0)
        if request_count <= 0:
            raise RuntimeError(f"Katran workload produced zero requests: {summary.get('failure_preview')}")
        if success_count != request_count:
            raise RuntimeError(f"Katran workload observed failures: {summary.get('failure_preview')}")
        return WorkloadResult(
            ops_total=float(request_count),
            ops_per_sec=float(summary.get("ops_per_sec")) if summary.get("ops_per_sec") is not None else None,
            duration_s=float(summary.get("duration_s") or seconds),
            stdout="",
            stderr=tail_text(str(summary.get("failure_preview") or "")),
        )

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError("KatranRunner is not running")
        if self.workload_kind == "test_run":
            return self._run_test_run_workload(seconds)
        if self.workload_kind != "network":
            raise RuntimeError(f"unsupported Katran workload kind: {self.workload_kind}")
        return self._run_network_workload(seconds)

    def run_workload_spec(
        self,
        workload_spec: Mapping[str, object],
        seconds: float,
    ) -> WorkloadResult:
        requested_kind = str(workload_spec.get("kind") or workload_spec.get("name") or self.workload_kind).strip().lower()
        if requested_kind != self.workload_kind:
            raise RuntimeError(
                f"KatranRunner workload kind is fixed at start ({self.workload_kind}); requested {requested_kind}"
            )
        return self.run_workload(seconds)

    def stop(self) -> None:
        errors: list[str] = []
        prog_id = self.prog_id
        if self.session is not None:
            session = self.session
            process = None if session.session is None else session.session.process
            snapshot = session.collector_snapshot()
            try:
                session.close()
            except Exception as exc:
                errors.append(str(exc))
            self.process_output = {
                "returncode": None if process is None else process.returncode,
                "stdout_tail": "\n".join(snapshot.get("stdout_tail") or []),
                "stderr_tail": "\n".join(snapshot.get("stderr_tail") or []),
            }
            self.session = None
        if self.http_server is not None:
            try:
                self.http_server.close()
            except Exception as exc:
                errors.append(str(exc))
            self.http_server = None
        if self.topology is not None:
            try:
                self.topology.close()
            except Exception as exc:
                errors.append(str(exc))
            self.topology = None
        if not errors:
            try:
                wait_for_katran_teardown(prog_id, settle_s=DEFAULT_KATRAN_STOP_SETTLE_S)
            except Exception as exc:
                errors.append(str(exc))
        if errors:
            raise RuntimeError("; ".join(errors))


__all__ = [
    "KatranDsrTopology",
    "KatranRunner",
    "NamespaceHttpServer",
    "configure_katran_maps",
    "run_katran_prog_test_run",
    "run_parallel_http_load",
]
