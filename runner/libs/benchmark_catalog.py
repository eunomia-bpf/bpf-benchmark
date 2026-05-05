from __future__ import annotations

from dataclasses import dataclass, field


DEFAULT_CORPUS_SAMPLES = 3
DEFAULT_CORPUS_WORKLOAD_DURATION_S = 3.0


@dataclass(frozen=True)
class MacroAppDefinition:
    name: str
    runner: str
    workload: str
    runner_args: dict[str, object] = field(default_factory=dict)
    duration_s: float | None = None


MACRO_APP_DEFINITIONS: tuple[MacroAppDefinition, ...] = (
    MacroAppDefinition(name="bcc/capable", runner="bcc", workload="stress_ng_os", runner_args={"tool": "capable"}),
    MacroAppDefinition(name="bcc/biosnoop", runner="bcc", workload="fio_randrw", runner_args={"tool": "biosnoop"}, duration_s=5.0),
    MacroAppDefinition(name="bcc/vfsstat", runner="bcc", workload="stress_ng_filesystem", runner_args={"tool": "vfsstat"}),
    MacroAppDefinition(name="bcc/opensnoop", runner="bcc", workload="stress_ng_filesystem", runner_args={"tool": "opensnoop"}),
    MacroAppDefinition(name="bcc/syscount", runner="bcc", workload="stress_ng_os", runner_args={"tool": "syscount", "tool_args": ("-L", "-i", "1")}),
    MacroAppDefinition(name="bcc/tcpconnect", runner="bcc", workload="tcp_connect", runner_args={"tool": "tcpconnect"}),
    MacroAppDefinition(name="bcc/tcplife", runner="bcc", workload="tcp_connect", runner_args={"tool": "tcplife"}),
    MacroAppDefinition(name="bcc/runqlat", runner="bcc", workload="stress_ng_scheduler", runner_args={"tool": "runqlat"}),
    MacroAppDefinition(name="otelcol-ebpf-profiler/profiling", runner="otelcol-ebpf-profiler", workload="stress_ng_cpu", duration_s=5.0),
    MacroAppDefinition(name="cilium/agent", runner="cilium", workload="network_lossy_multi", duration_s=5.0),
    MacroAppDefinition(name="tetragon/observer", runner="tetragon", workload="stress_ng_os_io_network", duration_s=5.0),
    MacroAppDefinition(name="katran", runner="katran", workload="xdp_traffic"),
    MacroAppDefinition(name="tracee/monitor", runner="tracee", workload="stress_ng_os_io_network", duration_s=5.0),
    MacroAppDefinition(name="bpftrace/capable", runner="bpftrace", workload="stress_ng_os", runner_args={"script": "capable"}),
    MacroAppDefinition(name="bpftrace/biosnoop", runner="bpftrace", workload="fio_randrw", runner_args={"script": "biosnoop"}, duration_s=5.0),
    MacroAppDefinition(name="bpftrace/vfsstat", runner="bpftrace", workload="stress_ng_filesystem", runner_args={"script": "vfsstat"}),
    MacroAppDefinition(name="bpftrace/runqlat", runner="bpftrace", workload="stress_ng_scheduler", runner_args={"script": "runqlat"}),
    MacroAppDefinition(name="bpftrace/tcplife", runner="bpftrace", workload="tcp_connect", runner_args={"script": "tcplife"}),
)

MACRO_APP_DEFINITION_BY_NAME = {spec.name: spec for spec in MACRO_APP_DEFINITIONS}
