from __future__ import annotations

import argparse
import json
import sys
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs.app_runners.tetragon import (  # noqa: E402
    TetragonRunner,
    inspect_tetragon_setup,
    resolve_tetragon_binary,
)
from runner.libs.benchmark_catalog import TETRAGON_E2E_DURATION_S, TETRAGON_E2E_WORKLOADS  # noqa: E402
from runner.libs.bpf_stats import compute_delta, enable_bpf_stats, sample_bpf_stats  # noqa: E402
from runner.libs.case_common import CaseLifecycleState, ensure_daemon_binary, host_metadata, run_case_lifecycle  # noqa: E402


DEFAULT_DURATION_S = TETRAGON_E2E_DURATION_S
DEFAULT_LOAD_TIMEOUT_S = 45


@dataclass(frozen=True)
class WorkloadSpec:
    name: str
    kind: str
    metric: str
    value: int = 0


DEFAULT_WORKLOADS = tuple(
    WorkloadSpec(
        name=str(spec["name"]),
        kind=str(spec["kind"]),
        metric=str(spec["metric"]),
        value=int(spec.get("value", 0) or 0),
    )
    for spec in TETRAGON_E2E_WORKLOADS
)
def case_config() -> dict[str, object]:
    return {
        "measurement_duration_s": DEFAULT_DURATION_S,
        "workloads": [
            {
                "name": spec.name,
                "kind": spec.kind,
                "metric": spec.metric,
                "value": spec.value,
            }
            for spec in DEFAULT_WORKLOADS
        ],
    }


def measure_workload(
    runner: TetragonRunner,
    workload_spec: WorkloadSpec,
    duration_s: int,
    prog_ids: Sequence[int],
) -> dict[str, object]:
    active_prog_ids = [int(prog_id) for prog_id in prog_ids if int(prog_id) > 0]
    if not active_prog_ids:
        raise RuntimeError("tetragon workload measurement requires at least one live program id")
    before_bpf = sample_bpf_stats(active_prog_ids)
    workload_result = runner.run_workload_spec(
        {
            "kind": workload_spec.kind,
            "value": workload_spec.value,
        },
        duration_s,
    )
    after_bpf = sample_bpf_stats(active_prog_ids)
    return {
        "name": workload_spec.name,
        "kind": workload_spec.kind,
        "metric": workload_spec.metric,
        "throughput": workload_result.ops_per_sec,
        "bpf": compute_delta(before_bpf, after_bpf),
    }


def run_phase(
    runner: TetragonRunner,
    workloads: Sequence[WorkloadSpec],
    duration_s: int,
    prog_ids: Sequence[int],
    *,
    phase_name: str,
) -> dict[str, object]:
    return {
        "phase": phase_name,
        "records": [
            measure_workload(runner, spec, duration_s, prog_ids)
            for spec in workloads
        ],
    }


def build_markdown(payload: Mapping[str, object]) -> str:
    return "\n".join(
        [
            "# Tetragon Real End-to-End Benchmark",
            "",
            "```json",
            json.dumps(payload, indent=2, sort_keys=True, default=str),
            "```",
        ]
    )


def error_payload(
    *,
    config: Mapping[str, object],
    tetragon_binary: str | None,
    duration_s: int,
    setup_result: Mapping[str, object],
    error_message: str,
    limitations: Sequence[str],
) -> dict[str, object]:
    return {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "error",
        "mode": "tetragon_daemon",
        "duration_s": duration_s,
        "tetragon_binary": tetragon_binary,
        "setup": dict(setup_result),
        "host": host_metadata(),
        "config": dict(config),
        "programs": [],
        "baseline": None,
        "post_rejit": None,
        "rejit_result": None,
        "limitations": list(limitations),
        "error_message": error_message,
    }


def run_tetragon_case(args: argparse.Namespace) -> dict[str, object]:
    config = case_config()
    duration_s = int(args.duration or DEFAULT_DURATION_S)
    load_timeout_s = DEFAULT_LOAD_TIMEOUT_S
    workloads = DEFAULT_WORKLOADS
    daemon_binary = Path(args.daemon).resolve()
    ensure_daemon_binary(daemon_binary)

    setup_result = inspect_tetragon_setup()
    limitations: list[str] = []
    if setup_result["returncode"] != 0:
        limitations.append("Tetragon setup inspection failed before execution.")

    tetragon_binary = resolve_tetragon_binary(None, setup_result)
    if tetragon_binary is None:
        return error_payload(
            config=config,
            tetragon_binary=None,
            duration_s=duration_s,
            setup_result=setup_result,
            error_message="Tetragon binary is unavailable in this environment; manual .bpf.o path is forbidden.",
            limitations=limitations,
        )

    prepared_daemon_session = getattr(args, "_prepared_daemon_session", None)
    if prepared_daemon_session is None:
        return error_payload(
            config=config,
            tetragon_binary=tetragon_binary,
            duration_s=duration_s,
            setup_result=setup_result,
            error_message="prepared daemon session is required",
            limitations=limitations,
        )
    if not workloads:
        return error_payload(
            config=config,
            tetragon_binary=tetragon_binary,
            duration_s=duration_s,
            setup_result=setup_result,
            error_message="Tetragon config contains no workloads",
            limitations=limitations,
        )

    try:
        with enable_bpf_stats():

            def setup() -> dict[str, object]:
                return {}

            def start(_: object) -> CaseLifecycleState:
                runner = TetragonRunner(
                    tetragon_binary=tetragon_binary,
                    load_timeout_s=load_timeout_s,
                    setup_result=setup_result,
                )
                runner.start()
                programs = [dict(program) for program in runner.programs]
                prog_ids = [
                    int(program.get("id", 0) or 0)
                    for program in programs
                    if int(program.get("id", 0) or 0) > 0
                ]
                return CaseLifecycleState(
                    runtime=runner,
                    prog_ids=prog_ids,
                    artifacts={
                        "programs": programs,
                        "rejit_policy_context": {"repo": "tetragon", "level": "e2e"},
                    },
                )

            def workload(_: object, lifecycle: CaseLifecycleState, phase_name: str) -> dict[str, object]:
                runner = lifecycle.runtime
                if not isinstance(runner, TetragonRunner):
                    raise RuntimeError(f"tetragon lifecycle returned a non-runner runtime: {type(runner).__name__}")
                return run_phase(
                    runner,
                    workloads,
                    duration_s,
                    lifecycle.prog_ids,
                    phase_name=phase_name,
                )

            def stop(_: object, lifecycle: CaseLifecycleState) -> None:
                runner = lifecycle.runtime
                if not isinstance(runner, TetragonRunner):
                    raise RuntimeError(f"tetragon lifecycle returned a non-runner runtime: {type(runner).__name__}")
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
    except Exception as exc:
        return error_payload(
            config=config,
            tetragon_binary=tetragon_binary,
            duration_s=duration_s,
            setup_result=setup_result,
            error_message=f"Tetragon case could not run: {exc}",
            limitations=limitations,
        )

    if lifecycle_result.state is None or lifecycle_result.baseline is None:
        return error_payload(
            config=config,
            tetragon_binary=tetragon_binary,
            duration_s=duration_s,
            setup_result=setup_result,
            error_message="Tetragon lifecycle completed without a baseline phase",
            limitations=limitations,
        )

    post_rejit = lifecycle_result.post_rejit
    rejit_result = lifecycle_result.rejit_result
    if post_rejit is not None and isinstance(rejit_result, Mapping):
        rejit_error = str(rejit_result.get("error") or "").strip()
        if rejit_error:
            post_rejit["status"] = "error"
            post_rejit["reason"] = rejit_error

    errors: list[str] = []
    if isinstance(rejit_result, Mapping):
        rejit_error = str(rejit_result.get("error") or "").strip()
        if rejit_error:
            limitations.append(f"ReJIT/apply reported errors: {rejit_error}")
            errors.append(rejit_error)
    if post_rejit is None:
        missing_post_rejit = "Post-ReJIT phase is unavailable."
        limitations.append(missing_post_rejit)
        errors.append(missing_post_rejit)

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "error" if errors else "ok",
        "mode": "tetragon_daemon",
        "duration_s": duration_s,
        "tetragon_binary": tetragon_binary,
        "setup": dict(setup_result),
        "host": host_metadata(),
        "config": dict(config),
        "programs": [dict(program) for program in lifecycle_result.artifacts.get("programs") or []],
        "baseline": lifecycle_result.baseline,
        "post_rejit": post_rejit,
        "rejit_result": rejit_result,
        "limitations": limitations,
    }
    if errors:
        payload["error_message"] = "; ".join(errors)
    return payload
