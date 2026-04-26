from __future__ import annotations

import argparse

import sys
from datetime import datetime, timezone
from pathlib import Path
from typing import Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs.app_runners.tracee import (  # noqa: E402
    TraceeRunner,
    build_tracee_commands,
    inspect_tracee_setup,
    resolve_tracee_binary,
    run_tracee_workload,
)
from runner.libs.benchmark_catalog import (  # noqa: E402
    TRACEE_E2E_DURATION_S,
    TRACEE_E2E_SAMPLE_COUNT,
    TRACEE_E2E_WARMUP_DURATION_S,
    TRACEE_E2E_WORKLOADS,
)
from runner.libs.bpf_stats import compute_delta, enable_bpf_stats, sample_bpf_stats  # noqa: E402
from runner.libs.case_common import CaseLifecycleState, ensure_daemon_binary, host_metadata, run_case_lifecycle  # noqa: E402


DEFAULT_DURATION_S = TRACEE_E2E_DURATION_S
DEFAULT_SAMPLE_COUNT = TRACEE_E2E_SAMPLE_COUNT
DEFAULT_WARMUP_DURATION_S = TRACEE_E2E_WARMUP_DURATION_S
DEFAULT_LOAD_TIMEOUT_S = 120
TRACEE_MODE = "tracee_daemon_same_image_paired"
def case_config() -> dict[str, object]:
    return {
        "measurement_duration_s": DEFAULT_DURATION_S,
        "sample_count": DEFAULT_SAMPLE_COUNT,
        "warmup_duration_s": DEFAULT_WARMUP_DURATION_S,
        "workloads": [dict(workload) for workload in TRACEE_E2E_WORKLOADS],
    }


def warmup_workload(spec: Mapping[str, object], duration_s: int | float) -> None:
    if float(duration_s) <= 0.0:
        return
    run_tracee_workload(spec, max(1, int(duration_s)))


def measure_workload(
    runner: TraceeRunner | None,
    workload_spec: Mapping[str, object],
    duration_s: int,
    prog_ids: list[int],
    *,
    cycle_index: int,
) -> dict[str, object]:
    before_bpf = sample_bpf_stats(prog_ids)
    if runner is None:
        workload_result = run_tracee_workload(workload_spec, duration_s)
    else:
        workload_result = runner.run_workload_spec(workload_spec, duration_s)
    after_bpf = sample_bpf_stats(prog_ids)
    return {
        "cycle_index": cycle_index,
        "name": str(workload_spec.get("name", workload_spec.get("kind", "unknown"))),
        "kind": str(workload_spec.get("kind", "")),
        "metric": str(workload_spec.get("metric", "ops/s")),
        "app_throughput": workload_result.ops_per_sec,
        "bpf": compute_delta(before_bpf, after_bpf),
    }


def run_phase(
    workloads: Sequence[Mapping[str, object]],
    duration_s: int,
    prog_ids: list[int],
    *,
    cycle_index: int,
    phase_name: str,
    warmup_duration_s: int | float,
    runner: TraceeRunner | None = None,
) -> dict[str, object]:
    records: list[dict[str, object]] = []
    for workload_spec in workloads:
        warmup_workload(workload_spec, warmup_duration_s)
        records.append(
            measure_workload(
                runner,
                workload_spec,
                duration_s,
                prog_ids,
                cycle_index=cycle_index,
            )
        )
    return {"phase": phase_name, "records": records}

def _append_phase_markdown(lines: list[str], title: str, records: Sequence[Mapping[str, object]]) -> None:
    lines.extend([f"## {title}", ""])
    if not records:
        lines.append("- No records")
        lines.append("")
        return
    for record in records:
        lines.append(
            f"- cycle={record.get('cycle_index')} workload={record.get('name')} "
            f"throughput={record.get('app_throughput')} {record.get('metric')}"
        )
    lines.append("")


def build_markdown(payload: Mapping[str, object]) -> str:
    lines = [
        "# Tracee Real End-to-End Benchmark",
        "",
        f"- Generated: {payload.get('generated_at')}",
        f"- Mode: `{payload.get('mode')}`",
        f"- Duration per workload: `{payload.get('duration_s')}s`",
        f"- Warmup per workload: `{payload.get('warmup_duration_s')}s`",
        f"- Cycles: `{payload.get('sample_count')}`",
        f"- Tracee binary: `{payload.get('tracee_binary') or 'unavailable'}`",
        f"- Programs: `{len(payload.get('programs') or [])}`",
        "",
        "## Setup",
        "",
        f"- Setup return code: `{(payload.get('setup') or {}).get('returncode')}`",
        f"- Setup tracee binary: `{(payload.get('setup') or {}).get('tracee_binary') or 'missing'}`",
        "",
    ]

    if str(payload.get("status") or "") != "ok":
        lines.extend(
            [
                "## Result",
                "",
                "- Status: `ERROR`",
                f"- Reason: `{payload.get('error_message') or 'unknown'}`",
            ]
        )
        limitations = payload.get("limitations") or []
        if limitations:
            lines.extend(["", "## Limitations", ""])
            for limitation in limitations:
                lines.append(f"- {limitation}")
        lines.append("")
        return "\n".join(lines)

    baseline = [record for record in (payload.get("baseline") or []) if isinstance(record, Mapping)]
    post_rejit = [record for record in (payload.get("post_rejit") or []) if isinstance(record, Mapping)]
    _append_phase_markdown(lines, "Baseline", baseline)
    _append_phase_markdown(lines, "Post-ReJIT", post_rejit)

    lines.extend(["## ReJIT Result", ""])
    rejit_result = payload.get("rejit_result") or {}
    if isinstance(rejit_result, Mapping) and rejit_result:
        for cycle_index in sorted(rejit_result, key=lambda value: int(value)):
            result = rejit_result[cycle_index]
            counts = result.get("program_counts") if isinstance(result, Mapping) else {}
            lines.append(
                f"- cycle={cycle_index} applied={(result or {}).get('applied')} "
                f"changed={(result or {}).get('changed')} "
                f"exit_code={(result or {}).get('exit_code')} "
                f"requested={(counts or {}).get('requested')} "
                f"applied_programs={(counts or {}).get('applied')} "
                f"error={(result or {}).get('error') or ''}"
            )
    else:
        lines.append("- No ReJIT result")

    limitations = payload.get("limitations") or []
    if limitations:
        lines.extend(["", "## Limitations", ""])
        for limitation in limitations:
            lines.append(f"- {limitation}")
    lines.append("")
    return "\n".join(lines)


def error_payload(
    *,
    config: Mapping[str, object],
    duration_s: int,
    sample_count: int,
    warmup_duration_s: float,
    tracee_binary: str | None,
    tracee_launch_command: Mapping[str, object],
    setup_result: Mapping[str, object],
    error_message: str,
    limitations: Sequence[str],
) -> dict[str, object]:
    return {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "error",
        "mode": TRACEE_MODE,
        "error_message": error_message,
        "duration_s": duration_s,
        "sample_count": sample_count,
        "warmup_duration_s": warmup_duration_s,
        "tracee_binary": tracee_binary,
        "tracee_launch_command": tracee_launch_command,
        "programs": [],
        "setup": dict(setup_result),
        "host": host_metadata(),
        "config": dict(config),
        "baseline": [],
        "post_rejit": [],
        "rejit_result": {},
        "limitations": list(limitations),
    }


def run_tracee_case(args: argparse.Namespace) -> dict[str, object]:
    config = case_config()
    duration_override = int(getattr(args, "duration", 0) or 0)
    duration_s = int(duration_override or DEFAULT_DURATION_S)
    sample_count = int(DEFAULT_SAMPLE_COUNT)
    warmup_duration_s = float(DEFAULT_WARMUP_DURATION_S)

    daemon_binary = Path(args.daemon).resolve()
    ensure_daemon_binary(daemon_binary)

    setup_result = inspect_tracee_setup()
    tracee_binary = resolve_tracee_binary(None, setup_result)
    tracee_extra_args: list[str] = []
    tracee_launch_command = build_tracee_commands(tracee_binary, tracee_extra_args) if tracee_binary else {}

    limitations: list[str] = []
    if setup_result["returncode"] != 0:
        limitations.append("Tracee setup inspection failed before execution.")
    if tracee_binary is None:
        return error_payload(
            config=config,
            duration_s=duration_s,
            sample_count=sample_count,
            warmup_duration_s=warmup_duration_s,
            tracee_binary=None,
            tracee_launch_command=tracee_launch_command,
            setup_result=setup_result,
            error_message="Tracee binary is unavailable in this environment; manual .bpf.o path is forbidden.",
            limitations=limitations,
        )

    workloads = [dict(workload) for workload in TRACEE_E2E_WORKLOADS]
    if not workloads:
        return error_payload(
            config=config,
            duration_s=duration_s,
            sample_count=sample_count,
            warmup_duration_s=warmup_duration_s,
            tracee_binary=tracee_binary,
            tracee_launch_command=tracee_launch_command,
            setup_result=setup_result,
            error_message="Tracee config contains no workloads",
            limitations=limitations,
        )

    try:
        prepared_daemon_session = getattr(args, "_prepared_daemon_session", None)
        if prepared_daemon_session is None:
            raise RuntimeError("prepared daemon session is required")

        baseline_records: list[dict[str, object]] = []
        post_rejit_records: list[dict[str, object]] = []
        rejit_result: dict[str, dict[str, object] | None] = {}
        tracee_programs: list[dict[str, object]] = []
        errors: list[str] = []

        with enable_bpf_stats():
            for cycle_index in range(sample_count):

                def setup() -> dict[str, object]:
                    return {}

                def start(_: object) -> CaseLifecycleState:
                    runner = TraceeRunner(
                        tracee_binary=tracee_binary,
                        extra_args=tracee_extra_args,
                        load_timeout_s=DEFAULT_LOAD_TIMEOUT_S,
                    )
                    runner.start()
                    prog_ids = [
                        int(program["id"])
                        for program in runner.programs
                        if int(program.get("id", 0) or 0) > 0
                    ]
                    return CaseLifecycleState(
                        runtime=runner,
                        prog_ids=prog_ids,
                        artifacts={
                            "tracee_programs": runner.programs,
                            "rejit_policy_context": {"repo": "tracee", "level": "e2e"},
                        },
                    )

                def workload(_: object, lifecycle: CaseLifecycleState, phase_name: str) -> dict[str, object]:
                    runner = lifecycle.runtime
                    assert isinstance(runner, TraceeRunner)
                    return run_phase(
                        workloads,
                        duration_s,
                        lifecycle.prog_ids,
                        cycle_index=cycle_index,
                        phase_name=phase_name,
                        warmup_duration_s=warmup_duration_s,
                        runner=runner,
                    )

                def stop(_: object, lifecycle: CaseLifecycleState) -> None:
                    runner = lifecycle.runtime
                    assert isinstance(runner, TraceeRunner)
                    runner.stop()

                def cleanup(_: object) -> None:
                    return None

                lifecycle_result = run_case_lifecycle(
                    daemon_session=prepared_daemon_session,
                    setup=setup,
                    start=start,
                    workload=workload,
                    stop=stop,
                    cleanup=cleanup,
                )

                if lifecycle_result.state is None or lifecycle_result.baseline is None:
                    raise RuntimeError(f"Tracee lifecycle cycle {cycle_index} completed without a baseline phase")
                if lifecycle_result.post_rejit is None:
                    raise RuntimeError(f"Tracee post-ReJIT phase is missing in cycle {cycle_index}")

                baseline_records.extend(
                    dict(record)
                    for record in (lifecycle_result.baseline.get("records") or [])
                    if isinstance(record, Mapping)
                )
                post_rejit_records.extend(
                    dict(record)
                    for record in (lifecycle_result.post_rejit.get("records") or [])
                    if isinstance(record, Mapping)
                )
                cycle_rejit_result = lifecycle_result.rejit_result
                rejit_result[str(cycle_index)] = cycle_rejit_result
                if isinstance(cycle_rejit_result, Mapping):
                    cycle_error = str(cycle_rejit_result.get("error") or "").strip()
                    if cycle_error:
                        limitations.append(f"Cycle {cycle_index} ReJIT/apply reported errors: {cycle_error}")
                        errors.append(f"cycle {cycle_index}: {cycle_error}")
                if not tracee_programs:
                    tracee_programs = [dict(program) for program in lifecycle_result.artifacts.get("tracee_programs") or []]
    except Exception as exc:
        return error_payload(
            config=config,
            duration_s=duration_s,
            sample_count=sample_count,
            warmup_duration_s=warmup_duration_s,
            tracee_binary=tracee_binary,
            tracee_launch_command=tracee_launch_command,
            setup_result=setup_result,
            error_message=f"Tracee case could not run: {exc}",
            limitations=limitations,
        )

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "error" if errors else "ok",
        "mode": TRACEE_MODE,
        "duration_s": duration_s,
        "sample_count": sample_count,
        "warmup_duration_s": warmup_duration_s,
        "tracee_binary": tracee_binary,
        "tracee_launch_command": tracee_launch_command,
        "programs": tracee_programs,
        "setup": setup_result,
        "host": host_metadata(),
        "config": dict(config),
        "baseline": baseline_records,
        "post_rejit": post_rejit_records,
        "rejit_result": rejit_result,
        "limitations": limitations,
    }
    if errors:
        payload["error_message"] = "; ".join(errors)
    return payload
