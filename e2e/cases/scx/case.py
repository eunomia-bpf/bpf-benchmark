from __future__ import annotations

import argparse
import json
import sys
import time
from datetime import datetime, timezone
from pathlib import Path
from typing import Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs import tail_text, which  # noqa: E402
from runner.libs.agent import bpftool_prog_show_records  # noqa: E402
from runner.libs.app_runners.scx import ScxRunner, read_scx_ops, read_scx_state  # noqa: E402
from runner.libs.app_runners.setup_support import repo_artifact_root  # noqa: E402
from runner.libs.bpf_stats import compute_delta, sample_bpf_stats_from_records  # noqa: E402
from runner.libs.case_common import CaseLifecycleState, host_metadata, run_case_lifecycle  # noqa: E402

DEFAULT_LOAD_TIMEOUT = 20
DEFAULT_DURATION_S = 10
DEFAULT_STATS_RETRY_ATTEMPTS = 10
DEFAULT_STATS_RETRY_SLEEP_S = 0.2

def default_scx_binary() -> Path:
    return repo_artifact_root() / "scx" / "bin" / "scx_rusty"

def ensure_artifacts(daemon_binary: Path, scheduler_binary: Path) -> None:
    if not daemon_binary.exists():
        raise RuntimeError(f"bpfrejit-daemon not found: {daemon_binary}")
    if not scheduler_binary.exists():
        raise RuntimeError(f"scx_rusty binary not found: {scheduler_binary}")

def workload_specs() -> list[dict[str, str]]:
    required = (
        ("hackbench", {"name": "hackbench", "kind": "hackbench", "metric": "runs/s"}),
        ("stress-ng", {"name": "stress-ng-cpu", "kind": "stress_ng_cpu", "metric": "bogo-ops/s"}),
        ("sysbench", {"name": "sysbench-cpu", "kind": "sysbench_cpu", "metric": "events/s"}),
    )
    missing = [binary for binary, _spec in required if not which(binary)]
    if missing:
        raise RuntimeError("scx benchmark requires fixed workload generators in PATH: " + ", ".join(missing))
    return [dict(spec) for _binary, spec in required]

def _programs(programs: object) -> list[dict[str, object]]:
    if not isinstance(programs, Sequence) or isinstance(programs, (str, bytes, bytearray)):
        return []
    return [
        dict(program)
        for program in programs
        if isinstance(program, Mapping)
        and int(program.get("id", 0) or 0) > 0
        and str(program.get("name") or "").strip()
    ]

def _resolve_live_prog_ids(
    runner: ScxRunner,
    logical_prog_ids: Sequence[int],
    *,
    previous_programs: Sequence[Mapping[str, object]],
    current_programs: Sequence[Mapping[str, object]] | None = None,
    allow_fallback: bool = True,
) -> tuple[dict[int, int], list[dict[str, object]]]:
    logical_ids = [int(prog_id) for prog_id in logical_prog_ids if int(prog_id) > 0]
    if not logical_ids:
        return {}, []
    previous_program_list = _programs(previous_programs)
    logical_name_by_id = {
        int(program["id"]): str(program["name"]).strip()
        for program in previous_program_list
        if int(program.get("id", 0) or 0) in logical_ids and str(program.get("name") or "").strip()
    }
    raw_live_programs = (
        [dict(program) for program in current_programs]
        if current_programs is not None
        else [dict(program) for program in runner.refresh_live_programs()]
    )
    raw_live_programs.sort(key=lambda program: int(program.get("id", 0) or 0))
    live_programs = _programs(raw_live_programs)
    live_programs.sort(key=lambda program: int(program.get("id", 0) or 0))
    if not live_programs and allow_fallback:
        live_programs = [dict(program) for program in previous_program_list]
    live_id_by_name = {str(program["name"]).strip(): int(program["id"]) for program in live_programs}
    live_ids = {
        int(program.get("id", 0) or 0)
        for program in raw_live_programs
        if int(program.get("id", 0) or 0) > 0
    }
    logical_to_live: dict[int, int] = {}
    for logical_id in logical_ids:
        live_id = int(live_id_by_name.get(logical_name_by_id.get(logical_id, ""), 0) or 0)
        if live_id > 0:
            logical_to_live[logical_id] = live_id
        elif logical_id in live_ids:
            logical_to_live[logical_id] = logical_id
    matched_live_ids = {int(live_id) for live_id in logical_to_live.values() if int(live_id) > 0}
    matched_live_programs = [
        dict(program)
        for program in raw_live_programs
        if int(program.get("id", 0) or 0) in matched_live_ids
    ]
    return logical_to_live, matched_live_programs


def _current_program_snapshot() -> list[dict[str, object]]:
    records = [dict(record) for record in bpftool_prog_show_records()]
    records.sort(key=lambda record: int(record.get("id", 0) or 0))
    return records


def _program_preview(programs: Sequence[Mapping[str, object]], *, limit: int = 24) -> str:
    preview = []
    for program in programs[:limit]:
        preview.append(
            f"{int(program.get('id', 0) or 0)}:{str(program.get('type') or '').strip()}:{str(program.get('name') or '').strip() or '<unnamed>'}"
        )
    if len(programs) > limit:
        preview.append(f"...(+{len(programs) - limit} more)")
    return ", ".join(preview) if preview else "<none>"


def _scx_runtime_debug_context(
    runner: ScxRunner,
    current_programs: Sequence[Mapping[str, object]],
) -> str:
    parts: list[str] = []
    try:
        parts.append(f"state={read_scx_state()!r}")
    except Exception as exc:
        parts.append(f"state_error={exc}")
    try:
        parts.append(f"ops={read_scx_ops()!r}")
    except Exception as exc:
        parts.append(f"ops_error={exc}")
    rusty_programs = [
        dict(program)
        for program in current_programs
        if "rusty" in str(program.get("name") or "")
        or str(program.get("type") or "").strip() == "struct_ops"
    ]
    snapshot_preview = rusty_programs if rusty_programs else list(current_programs)
    parts.append(f"bpftool_preview={_program_preview(snapshot_preview)}")
    snapshot = runner.collector_snapshot()
    combined = "\n".join(list(snapshot.get("stderr_tail") or []) + list(snapshot.get("stdout_tail") or []))
    if combined.strip():
        parts.append("runner_output=" + tail_text(combined, max_lines=40, max_chars=4000).replace("\n", " | "))
    return "; ".join(part for part in parts if part)

def _sample_scx_bpf_stats(
    runner: ScxRunner,
    logical_prog_ids: Sequence[int],
    *,
    previous_programs: Sequence[Mapping[str, object]],
) -> tuple[dict[int, dict[str, object]], list[dict[str, object]]]:
    last_error: RuntimeError | None = None
    last_snapshot: list[dict[str, object]] = []
    for attempt in range(DEFAULT_STATS_RETRY_ATTEMPTS):
        current_programs = _current_program_snapshot()
        last_snapshot = [dict(program) for program in current_programs]
        logical_to_live, live_programs = _resolve_live_prog_ids(
            runner,
            logical_prog_ids,
            previous_programs=previous_programs,
            current_programs=current_programs,
            allow_fallback=False,
        )
        sampled_prog_ids = sorted({int(live_id) for live_id in logical_to_live.values() if int(live_id) > 0})
        if not sampled_prog_ids:
            last_error = RuntimeError(
                "scx runner did not expose any live scheduler programs for BPF stats sampling"
            )
        else:
            raw_stats = sample_bpf_stats_from_records(current_programs, sampled_prog_ids)
            live_to_logical = {int(live_id): int(logical_id) for logical_id, live_id in logical_to_live.items()}
            remapped = {
                live_to_logical[int(sampled_prog_id)]: {**dict(record), "id": live_to_logical[int(sampled_prog_id)]}
                for sampled_prog_id, record in raw_stats.items()
                if int(sampled_prog_id) in live_to_logical
            }
            if remapped:
                return remapped, live_programs
            last_error = RuntimeError("scx BPF stats sampling returned no logical program records")
        if attempt + 1 < DEFAULT_STATS_RETRY_ATTEMPTS:
            time.sleep(DEFAULT_STATS_RETRY_SLEEP_S)
    debug_context = _scx_runtime_debug_context(runner, last_snapshot)
    if last_error is not None and debug_context:
        raise RuntimeError(f"{last_error}; {debug_context}")
    raise last_error or RuntimeError("scx BPF stats sampling failed without a recorded error")

def measure_workload(
    runner: ScxRunner,
    workload_spec: Mapping[str, object],
    duration_s: int,
    *,
    prog_ids: Sequence[int],
) -> dict[str, object]:
    logical_prog_ids = [int(prog_id) for prog_id in prog_ids if int(prog_id) > 0]
    if not logical_prog_ids:
        raise RuntimeError("scx workload measurement requires at least one live program id")
    before_bpf, live_programs = _sample_scx_bpf_stats(runner, logical_prog_ids, previous_programs=_programs(runner.programs))
    workload_result = runner.run_workload_spec(workload_spec, duration_s)
    after_bpf, _ = _sample_scx_bpf_stats(runner, logical_prog_ids, previous_programs=live_programs)
    return {
        "name": str(workload_spec.get("name", workload_spec.get("kind", "unknown"))),
        "kind": str(workload_spec.get("kind", "")),
        "metric": str(workload_spec.get("metric", "ops/s")),
        "throughput": workload_result.ops_per_sec,
        "bpf": compute_delta(before_bpf, after_bpf),
    }

def run_phase(
    runner: ScxRunner,
    workloads: Sequence[Mapping[str, object]],
    duration_s: int,
    *,
    phase_name: str,
    prog_ids: Sequence[int],
) -> dict[str, object]:
    records: list[dict[str, object]] = []
    for workload_spec in workloads:
        workload_name = str(workload_spec.get("name", workload_spec.get("kind", "unknown")))
        try:
            records.append(measure_workload(runner, workload_spec, duration_s, prog_ids=prog_ids))
        except Exception as exc:
            raise RuntimeError(f"{phase_name}/{workload_name}: {exc}") from exc
    return {
        "phase": phase_name,
        "records": records,
    }


def build_markdown(payload: Mapping[str, object]) -> str:
    return "\n".join(
        [
            "# scx_rusty End-to-End Benchmark",
            "",
            "```json",
            json.dumps(payload, indent=2, sort_keys=True, default=str),
            "```",
        ]
    )


def _payload(
    *,
    status: str,
    duration_s: int,
    scheduler_binary: Path,
    programs: Sequence[Mapping[str, object]] | None,
    baseline: Mapping[str, object] | None,
    post_rejit: Mapping[str, object] | None,
    rejit_result: Mapping[str, object] | None,
    limitations: Sequence[str],
    error_message: str | None = None,
) -> dict[str, object]:
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": status,
        "mode": "scx_daemon",
        "duration_s": duration_s,
        "scheduler_binary": str(scheduler_binary),
        "host": host_metadata(),
        "programs": [dict(program) for program in programs or []],
        "baseline": baseline,
        "post_rejit": post_rejit,
        "rejit_result": rejit_result,
        "limitations": list(limitations),
    }
    if error_message:
        payload["error_message"] = error_message
    return payload


def run_scx_case(args: argparse.Namespace) -> dict[str, object]:
    duration_s = int(args.duration or DEFAULT_DURATION_S)
    scheduler_binary = default_scx_binary().resolve()
    daemon_binary = Path(args.daemon).resolve()
    ensure_artifacts(daemon_binary, scheduler_binary)
    workloads = workload_specs()
    prepared_daemon_session = getattr(args, "_prepared_daemon_session", None)
    if prepared_daemon_session is None:
        return _payload(
            status="error",
            duration_s=duration_s,
            scheduler_binary=scheduler_binary,
            programs=[],
            baseline=None,
            post_rejit=None,
            rejit_result=None,
            limitations=[],
            error_message="prepared daemon session is required",
        )

    live_prog_ids: list[int] = []
    programs: list[dict[str, object]] = []
    try:

        def start(_: object) -> CaseLifecycleState:
            nonlocal live_prog_ids, programs
            runner = ScxRunner(
                scheduler_binary=scheduler_binary,
                load_timeout_s=DEFAULT_LOAD_TIMEOUT,
                workload_spec={"name": "hackbench", "kind": "hackbench", "metric": "runs/s"},
            )
            runner.start()
            programs = _programs(runner.programs)
            live_prog_ids = [int(program["id"]) for program in programs]
            return CaseLifecycleState(
                runtime=runner,
                prog_ids=list(live_prog_ids),
                artifacts={"programs": list(programs), "rejit_policy_context": {"repo": "scx", "level": "e2e"}},
            )

        def workload(_: object, lifecycle: CaseLifecycleState, phase_name: str) -> dict[str, object]:
            runner = lifecycle.runtime
            if not isinstance(runner, ScxRunner):
                raise RuntimeError(f"scx lifecycle returned a non-runner runtime: {type(runner).__name__}")
            return run_phase(runner, workloads, duration_s, phase_name=phase_name, prog_ids=lifecycle.prog_ids)

        def after_baseline(_: object, lifecycle: CaseLifecycleState, baseline: Mapping[str, object]) -> Mapping[str, object]:
            nonlocal live_prog_ids, programs
            del baseline
            runner = lifecycle.runtime
            if not isinstance(runner, ScxRunner):
                raise RuntimeError(f"scx lifecycle returned a non-runner runtime: {type(runner).__name__}")
            logical_to_live, programs = _resolve_live_prog_ids(
                runner,
                lifecycle.prog_ids,
                previous_programs=programs or _programs(lifecycle.artifacts.get("programs")),
            )
            live_prog_ids = [
                int(logical_to_live.get(int(logical_prog_id), 0) or 0)
                for logical_prog_id in lifecycle.prog_ids
                if int(logical_to_live.get(int(logical_prog_id), 0) or 0) > 0
            ]
            if not live_prog_ids:
                raise RuntimeError("scx baseline could not resolve live scheduler program ids for daemon apply")
            return {"programs": list(programs)}

        lifecycle_result = run_case_lifecycle(
            daemon_session=prepared_daemon_session,
            setup=lambda: {},
            start=start,
            workload=workload,
            stop=lambda _, lifecycle: lifecycle.runtime.stop(),
            cleanup=lambda _: None,
            after_baseline=after_baseline,
            resolve_rejit_prog_ids=lambda *_args: list(live_prog_ids),
        )
    except Exception as exc:
        return _payload(
            status="error",
            duration_s=duration_s,
            scheduler_binary=scheduler_binary,
            programs=programs,
            baseline=None,
            post_rejit=None,
            rejit_result=None,
            limitations=[],
            error_message=f"scx case could not run: {exc}",
        )

    if lifecycle_result.state is None or lifecycle_result.baseline is None:
        return _payload(
            status="error",
            duration_s=duration_s,
            scheduler_binary=scheduler_binary,
            programs=programs,
            baseline=None,
            post_rejit=None,
            rejit_result=None,
            limitations=[],
            error_message="scx lifecycle completed without a baseline phase",
        )

    rejit_result = lifecycle_result.rejit_result
    limitations: list[str] = []
    if isinstance(rejit_result, Mapping) and str(rejit_result.get("error") or "").strip():
        limitations.append(f"ReJIT/apply reported errors: {str(rejit_result.get('error') or '').strip()}")
    if lifecycle_result.post_rejit is None:
        limitations.append("Post-ReJIT phase is unavailable.")
    if lifecycle_result.abort is not None and str(lifecycle_result.abort.reason).strip():
        limitations.append(str(lifecycle_result.abort.reason).strip())

    return _payload(
        status="ok",
        duration_s=duration_s,
        scheduler_binary=scheduler_binary,
        programs=programs or _programs(lifecycle_result.artifacts.get("programs")),
        baseline=lifecycle_result.baseline,
        post_rejit=lifecycle_result.post_rejit,
        rejit_result=lifecycle_result.rejit_result,
        limitations=limitations,
    )
