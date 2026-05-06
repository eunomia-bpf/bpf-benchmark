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
    MacroAppDefinition(
        name="bcc/set",
        runner="bcc_set",
        workload="stress_ng_os_io_network",
        duration_s=5.0,
    ),
    MacroAppDefinition(name="otelcol-ebpf-profiler/profiling", runner="otelcol-ebpf-profiler", workload="stress_ng_cpu", duration_s=5.0),
    MacroAppDefinition(name="cilium/agent", runner="cilium", workload="network_lossy_multi", duration_s=5.0),
    MacroAppDefinition(name="tetragon/observer", runner="tetragon", workload="stress_ng_os_io_network", duration_s=5.0),
    MacroAppDefinition(name="katran", runner="katran", workload="xdp_traffic"),
    MacroAppDefinition(name="tracee/monitor", runner="tracee", workload="stress_ng_os_io_network", duration_s=5.0),
    MacroAppDefinition(
        name="bpftrace/set",
        runner="bpftrace_set",
        workload="stress_ng_os_io_network",
        duration_s=5.0,
    ),
)

MACRO_APP_DEFINITION_BY_NAME = {spec.name: spec for spec in MACRO_APP_DEFINITIONS}
