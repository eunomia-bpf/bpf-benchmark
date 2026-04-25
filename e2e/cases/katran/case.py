from __future__ import annotations

import argparse
import json
import sys
from datetime import datetime, timezone
from pathlib import Path
from typing import Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs.app_runners.katran import (  # noqa: E402
    DEFAULT_CONCURRENCY,
    DEFAULT_INTERFACE,
    KatranRunner,
)
from runner.libs.bpf_stats import compute_delta, enable_bpf_stats, sample_bpf_stats  # noqa: E402
from runner.libs.case_common import (  # noqa: E402
    CaseLifecycleState,
    host_metadata,
    run_app_runner_lifecycle,
)


DEFAULT_DURATION_S = 5


def measure_workload(
    runner: KatranRunner,
    duration_s: int,
    prog_ids: list[int],
) -> dict[str, object]:
    before_bpf = sample_bpf_stats(prog_ids)
    workload_result = runner.run_workload(duration_s)
    after_bpf = sample_bpf_stats(prog_ids)
    return {
        "throughput": workload_result.ops_per_sec,
        "metric": "ops/s",
        "duration_s": duration_s,
        "bpf": compute_delta(before_bpf, after_bpf),
    }


def build_markdown(payload: Mapping[str, object]) -> str:
    return "\n".join(
        [
            "# Katran End-to-End Benchmark",
            "",
            "```json",
            json.dumps(payload, indent=2, sort_keys=True, default=str),
            "```",
        ]
    )


def phase_payload(phase_name: str, phase_result: Mapping[str, object] | None) -> dict[str, object] | None:
    if phase_result is None:
        return None
    measurement = phase_result.get("measurement")
    return {
        "phase": phase_name,
        "status": str(phase_result.get("status") or "error"),
        "reason": str(phase_result.get("reason") or ""),
        "measurement": dict(measurement) if isinstance(measurement, Mapping) else None,
    }
def _programs(value: object) -> list[dict[str, object]]:
    if not isinstance(value, Sequence) or isinstance(value, (str, bytes, bytearray)):
        return []
    return [dict(program) for program in value if isinstance(program, Mapping)]
def lifecycle_programs(lifecycle_result: object, *, runner: KatranRunner | None = None) -> list[dict[str, object]]:
    artifacts = getattr(lifecycle_result, "artifacts", {})
    if isinstance(artifacts, Mapping):
        programs = _programs(artifacts.get("programs"))
        if programs:
            return programs
        live_program = artifacts.get("live_program")
        if isinstance(live_program, Mapping):
            programs = _programs(live_program.get("programs"))
            if programs:
                return programs
    if runner is not None:
        programs = _programs(getattr(runner, "programs", None))
        if programs:
            return programs
        if isinstance(getattr(runner, "artifacts", None), Mapping):
            live_program = runner.artifacts.get("live_program")
            if isinstance(live_program, Mapping):
                programs = _programs(live_program.get("programs"))
                if programs:
                    return programs
    return []


def run_katran_case(args: argparse.Namespace) -> dict[str, object]:
    prepared_daemon_session = getattr(args, "_prepared_daemon_session", None)
    if prepared_daemon_session is None:
        raise RuntimeError("prepared daemon session is required")

    duration_override = int(args.duration or 0)
    duration_s = int(duration_override or DEFAULT_DURATION_S)
    workload_spec = {"kind": "network"}
    runner = KatranRunner(
        iface=DEFAULT_INTERFACE,
        router_peer_iface=None,
        concurrency=DEFAULT_CONCURRENCY,
        workload_spec=workload_spec,
    )

    def workload(lifecycle: object, _phase_name: str) -> dict[str, object]:
        prog_ids = list(getattr(lifecycle, "prog_ids", []) or [])
        return {
            "status": "ok",
            "measurement": measure_workload(runner, duration_s, prog_ids),
        }
    def build_state(active_runner: KatranRunner, started_prog_ids: list[int]) -> CaseLifecycleState:
        prog_ids = [int(value) for value in started_prog_ids if int(value) > 0]
        if not prog_ids:
            raise RuntimeError("Katran runner did not expose any live prog_ids")
        programs = _programs(active_runner.programs)
        if not programs:
            raise RuntimeError("Katran runner did not expose any live programs")
        artifacts: dict[str, object] = {
            "programs": programs,
            "rejit_policy_context": {"repo": "katran", "level": "e2e"},
        }
        if isinstance(active_runner.artifacts, Mapping):
            live_program = active_runner.artifacts.get("live_program")
            if isinstance(live_program, Mapping):
                artifacts["live_program"] = dict(live_program)
        return CaseLifecycleState(runtime=active_runner, prog_ids=prog_ids, artifacts=artifacts)

    with enable_bpf_stats():
        lifecycle_result = run_app_runner_lifecycle(
            daemon_session=prepared_daemon_session,
            runner=runner,
            measure=workload,
            build_state=build_state,
        )

    baseline = phase_payload("baseline", lifecycle_result.baseline)
    if baseline is None:
        baseline = {
            "phase": "baseline",
            "status": "error",
            "reason": "baseline measurement is missing",
            "measurement": None,
        }
    post_rejit = phase_payload("post_rejit", lifecycle_result.post_rejit)
    if lifecycle_result.rejit_result is not None and post_rejit is None:
        post_rejit = {
            "phase": "post_rejit",
            "status": "error",
            "reason": "post-ReJIT measurement is missing",
            "measurement": None,
        }
    if post_rejit is not None and isinstance(lifecycle_result.rejit_result, Mapping):
        apply_error = str(lifecycle_result.rejit_result.get("error") or "").strip()
        if apply_error:
            post_rejit["status"] = "error"
            post_rejit["reason"] = apply_error
    programs = lifecycle_programs(lifecycle_result, runner=runner)

    errors: list[str] = []
    if str(baseline.get("status") or "") != "ok":
        errors.append(str(baseline.get("reason") or "baseline failed"))
    if isinstance(post_rejit, Mapping) and str(post_rejit.get("status") or "") != "ok":
        errors.append(str(post_rejit.get("reason") or "post_rejit failed"))

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "error" if errors else "ok",
        "daemon": str(Path(args.daemon).resolve()),
        "duration_s": duration_s,
        "workload_spec": dict(workload_spec),
        "host": host_metadata(),
        "programs": programs,
        "baseline": baseline,
        "post_rejit": post_rejit,
        "rejit_result": lifecycle_result.rejit_result,
        "process": dict(runner.process_output),
    }
    if errors:
        payload["error_message"] = "; ".join(errors)
    return payload
