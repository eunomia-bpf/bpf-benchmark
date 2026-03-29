from __future__ import annotations

import time
from dataclasses import dataclass
from pathlib import Path
from typing import Any

from .. import ROOT_DIR, tail_text
from ..agent import find_bpf_programs
from ..workload import (
    WorkloadResult,
    run_dd_read_load,
    run_exec_storm,
    run_scheduler_load,
    run_tcp_connect_load,
)


DEFAULT_SCRIPT_DIR = ROOT_DIR / "e2e" / "cases" / "bpftrace" / "scripts"


@dataclass(frozen=True, slots=True)
class ScriptSpec:
    name: str
    script_path: Path
    description: str
    expected_programs: int
    workload_kind: str


SCRIPTS: tuple[ScriptSpec, ...] = (
    ScriptSpec(
        name="tcplife",
        script_path=DEFAULT_SCRIPT_DIR / "tcplife.bt",
        description="kprobe tcp_set_state: TCP session lifespan with IPv4/IPv6 struct field access, bswap, ntop, 3 maps",
        expected_programs=1,
        workload_kind="tcp_connect",
    ),
    ScriptSpec(
        name="biosnoop",
        script_path=DEFAULT_SCRIPT_DIR / "biosnoop.bt",
        description="tracepoint block_io_start/done: per-I/O latency with tuple-keyed maps and bitwise ops (dev >> 20)",
        expected_programs=2,
        workload_kind="dd_read",
    ),
    ScriptSpec(
        name="runqlat",
        script_path=DEFAULT_SCRIPT_DIR / "runqlat.bt",
        description="tracepoint sched_wakeup/wakeup_new/switch: run queue latency histogram, 3 probes",
        expected_programs=3,
        workload_kind="scheduler",
    ),
    ScriptSpec(
        name="tcpretrans",
        script_path=DEFAULT_SCRIPT_DIR / "tcpretrans.bt",
        description="kprobe tcp_retransmit_skb: TCP retransmit tracing with 12-entry state string map, ntop/bswap",
        expected_programs=1,
        workload_kind="tcp_connect",
    ),
    ScriptSpec(
        name="capable",
        script_path=DEFAULT_SCRIPT_DIR / "capable.bt",
        description="kprobe cap_capable: security capability checks with 41-entry string map lookup",
        expected_programs=1,
        workload_kind="exec_storm",
    ),
    ScriptSpec(
        name="vfsstat",
        script_path=DEFAULT_SCRIPT_DIR / "vfsstat.bt",
        description="kprobe vfs_read*/write*/fsync/open/create: per-function counters with interval printing",
        expected_programs=6,
        workload_kind="dd_read",
    ),
)


def wait_for_attached_programs(
    process: Any,
    *,
    expected_count: int,
    timeout_s: int,
) -> list[dict[str, object]]:
    deadline = time.monotonic() + timeout_s
    last_nonempty: list[dict[str, object]] = []
    stable_ids: tuple[int, ...] | None = None
    stable_rounds = 0
    while time.monotonic() < deadline:
        matches = find_bpf_programs(int(process.pid or 0))
        if matches:
            last_nonempty = matches
            ids = tuple(int(item.get("id", 0)) for item in matches)
            if ids == stable_ids:
                stable_rounds += 1
            else:
                stable_ids = ids
                stable_rounds = 1
            if len(matches) >= expected_count and stable_rounds >= 2:
                return matches
        elif process.poll() is not None and not last_nonempty:
            break
        time.sleep(0.5)
    return last_nonempty


def run_named_workload(kind: str, duration_s: int) -> WorkloadResult:
    if kind == "tcp_connect":
        return run_tcp_connect_load(duration_s)
    if kind == "dd_read":
        return run_dd_read_load(duration_s)
    if kind == "scheduler":
        return run_scheduler_load(duration_s)
    if kind == "exec_storm":
        return run_exec_storm(duration_s, rate=2)
    raise RuntimeError(f"unsupported workload kind: {kind}")


def finalize_process_output(process: Any) -> dict[str, object]:
    stdout = ""
    stderr = ""
    try:
        stdout, stderr = process.communicate(timeout=1)
    except Exception:
        if process.stdout is not None:
            try:
                stdout = process.stdout.read()
            except Exception:
                stdout = ""
        if process.stderr is not None:
            try:
                stderr = process.stderr.read()
            except Exception:
                stderr = ""
    return {
        "returncode": process.returncode,
        "stdout_tail": tail_text(stdout, max_lines=40, max_chars=8000),
        "stderr_tail": tail_text(stderr, max_lines=40, max_chars=8000),
    }
