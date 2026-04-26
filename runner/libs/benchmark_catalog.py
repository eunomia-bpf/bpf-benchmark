from __future__ import annotations

from dataclasses import dataclass, field
from typing import Mapping


DEFAULT_CORPUS_SAMPLES = 30
DEFAULT_CORPUS_WORKLOAD_DURATION_S = 1.0

TRACEE_E2E_DURATION_S = 6
TRACEE_E2E_SAMPLE_COUNT = 2
TRACEE_E2E_WARMUP_DURATION_S = 2
TRACEE_E2E_WORKLOADS: tuple[dict[str, object], ...] = (
    {
        "name": "tracee_default",
        "kind": "tracee_default",
        "command": "mixed exec/open/connect workload over {duration}s",
        "metric": "ops/s",
    },
)

TETRAGON_E2E_DURATION_S = 8
TETRAGON_E2E_WORKLOADS: tuple[dict[str, object], ...] = (
    {
        "name": "exec_storm",
        "kind": "exec_storm",
        "metric": "bogo-ops/s",
        "value": 2,
    },
)

BCC_E2E_DURATION_S = 10
BCC_E2E_ATTACH_TIMEOUT_S = 20


@dataclass(frozen=True)
class BCCToolSpec:
    name: str
    workload_spec: Mapping[str, object]
    tool_args: tuple[str, ...] = ()


BCC_TOOL_SPECS: tuple[BCCToolSpec, ...] = (
    BCCToolSpec(name="tcplife", workload_spec={"kind": "tcp_connect"}),
    BCCToolSpec(name="biosnoop", workload_spec={"kind": "block_io"}),
    BCCToolSpec(name="runqlat", workload_spec={"kind": "scheduler"}),
    BCCToolSpec(name="syscount", workload_spec={"kind": "file_open"}, tool_args=("-L", "-i", "1")),
    BCCToolSpec(name="execsnoop", workload_spec={"kind": "exec_loop"}, tool_args=("-T", "-U", "-u", "65534")),
    BCCToolSpec(name="opensnoop", workload_spec={"kind": "file_open"}),
    BCCToolSpec(name="capable", workload_spec={"kind": "exec_storm"}),
    BCCToolSpec(name="vfsstat", workload_spec={"kind": "vfs_create_write_fsync"}),
    BCCToolSpec(name="tcpconnect", workload_spec={"kind": "tcp_connect"}),
    BCCToolSpec(name="bindsnoop", workload_spec={"kind": "bind_storm"}),
)

BCC_TOOL_SPEC_BY_NAME = {spec.name: spec for spec in BCC_TOOL_SPECS}


@dataclass(frozen=True)
class MacroAppDefinition:
    name: str
    runner: str
    workload: str
    runner_args: dict[str, object] = field(default_factory=dict)
    duration_s: float | None = None


MACRO_APP_DEFINITIONS: tuple[MacroAppDefinition, ...] = (
    MacroAppDefinition(name="bcc/capable", runner="bcc", workload="exec_storm", runner_args={"tool": "capable"}),
    MacroAppDefinition(name="bcc/execsnoop", runner="bcc", workload="exec_storm", runner_args={"tool": "execsnoop"}),
    MacroAppDefinition(name="bcc/bindsnoop", runner="bcc", workload="bind_storm", runner_args={"tool": "bindsnoop"}),
    MacroAppDefinition(name="bcc/biosnoop", runner="bcc", workload="block_io", runner_args={"tool": "biosnoop"}, duration_s=5.0),
    MacroAppDefinition(name="bcc/vfsstat", runner="bcc", workload="vfs_create_fsync_exact", runner_args={"tool": "vfsstat"}),
    MacroAppDefinition(name="bcc/opensnoop", runner="bcc", workload="open_family_storm", runner_args={"tool": "opensnoop"}),
    MacroAppDefinition(name="bcc/syscount", runner="bcc", workload="file_open_storm", runner_args={"tool": "syscount"}),
    MacroAppDefinition(name="bcc/tcpconnect", runner="bcc", workload="network", runner_args={"tool": "tcpconnect"}),
    MacroAppDefinition(name="bcc/tcplife", runner="bcc", workload="network", runner_args={"tool": "tcplife"}),
    MacroAppDefinition(name="bcc/runqlat", runner="bcc", workload="hackbench", runner_args={"tool": "runqlat"}),
    MacroAppDefinition(name="calico/felix", runner="calico", workload="network"),
    MacroAppDefinition(name="otelcol-ebpf-profiler/profiling", runner="otelcol-ebpf-profiler", workload="exec_storm"),
    MacroAppDefinition(name="cilium/agent", runner="cilium", workload="network"),
    MacroAppDefinition(name="tetragon/observer", runner="tetragon", workload="tetragon_exec_connect_mix"),
    MacroAppDefinition(name="katran", runner="katran", workload="test_run"),
    MacroAppDefinition(name="tracee/monitor", runner="tracee", workload="tracee_system_edge_mix", duration_s=5.0),
    MacroAppDefinition(name="bpftrace/capable", runner="bpftrace", workload="exec_storm", runner_args={"script": "capable"}),
    MacroAppDefinition(name="bpftrace/biosnoop", runner="bpftrace", workload="block_io", runner_args={"script": "biosnoop"}, duration_s=5.0),
    MacroAppDefinition(name="bpftrace/vfsstat", runner="bpftrace", workload="vfs_create_write_fsync", runner_args={"script": "vfsstat"}),
    MacroAppDefinition(name="bpftrace/runqlat", runner="bpftrace", workload="hackbench", runner_args={"script": "runqlat"}),
    MacroAppDefinition(name="bpftrace/tcplife", runner="bpftrace", workload="network", runner_args={"script": "tcplife"}),
    MacroAppDefinition(name="bpftrace/tcpretrans", runner="bpftrace", workload="tcp_retransmit", runner_args={"script": "tcpretrans"}, duration_s=5.0),
)

MACRO_APP_DEFINITION_BY_NAME = {spec.name: spec for spec in MACRO_APP_DEFINITIONS}
