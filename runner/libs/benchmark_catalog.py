from __future__ import annotations

from dataclasses import dataclass, field


DEFAULT_CORPUS_SAMPLES = 3
# Single global workload duration. Override at run time with the
# WORKLOAD_DURATION env var (passed through `make corpus
# WORKLOAD_DURATION=30`). Per-app overrides intentionally not supported --
# every app shares this duration; benchmark interpretation stays outside the
# framework and only has one duration knob to account for.
DEFAULT_CORPUS_WORKLOAD_DURATION_S = 30.0


@dataclass(frozen=True)
class MacroAppDefinition:
    name: str
    runner: str
    workload: str
    runner_args: dict[str, object] = field(default_factory=dict)


MACRO_APP_DEFINITIONS: tuple[MacroAppDefinition, ...] = (
    MacroAppDefinition(name="bcc/set", runner="bcc_set", workload="stress_ng_os_io_network"),
    # otel_mixed_workload: 5 stdlib SHA-256 interpreter loops
    # (Python/Ruby/Node/Perl/PHP) + stress-ng --cpu 1 concurrently.
    # Interpreter loops drive samples into perf_unwind_<lang> programs;
    # stress-ng exercises perf_unwind_native (and Go-labels).
    MacroAppDefinition(name="otelcol-ebpf-profiler/profiling", runner="otelcol-ebpf-profiler", workload="otel_mixed_workload"),
    MacroAppDefinition(name="cilium/agent", runner="cilium", workload="network_lossy_multi"),
    MacroAppDefinition(name="tetragon/observer", runner="tetragon", workload="stress_ng_os_io_network"),
    MacroAppDefinition(name="katran", runner="katran", workload="xdp_pktgen"),
    MacroAppDefinition(name="katran/wrk", runner="katran", workload="xdp_traffic"),
    MacroAppDefinition(name="tracee/monitor", runner="tracee", workload="stress_ng_os_io_network"),
    MacroAppDefinition(name="bpftrace/set", runner="bpftrace_set", workload="stress_ng_os_io_network"),
)

MACRO_APP_DEFINITION_BY_NAME = {spec.name: spec for spec in MACRO_APP_DEFINITIONS}
