from __future__ import annotations

from pathlib import Path
from typing import Any

from .. import ROOT_DIR, resolve_bpftool_binary, tail_text
from ..workload import WorkloadResult
from .katran_support import (
    KatranDirectSession,
    KatranDsrTopology,
    NamespaceHttpServer,
    CLIENT_NS,
    REAL_NS,
    TOPOLOGY_SETTLE_S,
    VIP_IP,
    VIP_PORT,
    configure_katran_maps,
    run_katran_prog_test_run,
    run_parallel_http_load,
    run_wrk,
)


DEFAULT_KATRAN_OBJECT = ROOT_DIR / "corpus" / "build" / "katran" / "balancer.bpf.o"
DEFAULT_PROGRAM_NAME = "balancer_ingress"
DEFAULT_INTERFACE = "katran0"
DEFAULT_CONCURRENCY = 16


class KatranRunner:
    def __init__(
        self,
        *,
        object_path: Path | str | None = None,
        program_name: str = DEFAULT_PROGRAM_NAME,
        iface: str = DEFAULT_INTERFACE,
        router_peer_iface: str | None = None,
        bpftool: str = "",
        concurrency: int = DEFAULT_CONCURRENCY,
        use_wrk_driver: bool = False,
        wrk_connections: int = 32,
        wrk_threads: int = 1,
    ) -> None:
        self.object_path = Path(object_path).resolve() if object_path is not None else DEFAULT_KATRAN_OBJECT.resolve()
        self.program_name = str(program_name)
        self.iface = str(iface)
        self.router_peer_iface = None if router_peer_iface is None else str(router_peer_iface)
        self.bpftool = str(bpftool or resolve_bpftool_binary())
        self.concurrency = max(1, int(concurrency))
        self.use_wrk_driver = bool(use_wrk_driver)
        self.wrk_connections = max(1, int(wrk_connections))
        self.wrk_threads = max(1, int(wrk_threads))
        self.topology: Any | None = None
        self.http_server: Any | None = None
        self.session: Any | None = None
        self.programs: list[dict[str, object]] = []
        self.artifacts: dict[str, object] = {}
        self.last_request_summary: dict[str, object] = {}

    @property
    def prog_id(self) -> int | None:
        return None if self.session is None else int(self.session.prog_id)

    def start(self) -> list[int]:
        if self.session is not None:
            raise RuntimeError("KatranRunner is already running")
        if not self.object_path.exists():
            raise RuntimeError(f"Katran object not found: {self.object_path}")

        topology = KatranDsrTopology(self.iface, router_peer_iface=self.router_peer_iface)
        http_server = NamespaceHttpServer(REAL_NS, VIP_IP, VIP_PORT)
        session = KatranDirectSession(
            object_path=self.object_path,
            program_name=self.program_name,
            iface=self.iface,
            attach=True,
            bpftool=self.bpftool,
        )
        try:
            topology.__enter__()
            http_server.__enter__()
            session.__enter__()
            if session.attach_error:
                raise RuntimeError(f"failed to attach Katran XDP program: {session.attach_error}")
            self.artifacts = {
                "topology": topology.metadata(),
                "http_server": http_server.metadata(),
                "live_program": session.metadata(),
                "map_configuration": configure_katran_maps(session),
                "test_run_validation": run_katran_prog_test_run(session),
            }
            import time  # noqa: PLC0415

            time.sleep(TOPOLOGY_SETTLE_S)
        except Exception:
            session.close()
            http_server.close()
            topology.close()
            raise
        self.topology = topology
        self.http_server = http_server
        self.session = session
        self.programs = [dict(session.program)]
        return [int(session.prog_id)]

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError("KatranRunner is not running")
        if self.use_wrk_driver:
            summary = run_wrk(
                namespace=CLIENT_NS,
                duration_s=max(1.0, float(seconds)),
                connections=self.wrk_connections,
                threads=self.wrk_threads,
            )
        else:
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

    def stop(self) -> None:
        errors: list[str] = []
        if self.session is not None:
            try:
                self.session.close()
            except Exception as exc:
                errors.append(str(exc))
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
        if errors:
            raise RuntimeError("; ".join(errors))


__all__ = [
    "KatranDirectSession",
    "KatranDsrTopology",
    "KatranRunner",
    "NamespaceHttpServer",
    "configure_katran_maps",
    "run_katran_prog_test_run",
    "run_parallel_http_load",
]
