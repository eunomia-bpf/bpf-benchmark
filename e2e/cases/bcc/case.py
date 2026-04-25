from __future__ import annotations

import argparse
import json
import sys
from datetime import datetime, timezone
from pathlib import Path
from typing import Mapping

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs.app_runners.bcc import BCCRunner, find_tool_binary, inspect_bcc_setup, resolve_tools_dir  # noqa: E402
from runner.libs.benchmark_catalog import (  # noqa: E402
    BCC_E2E_ATTACH_TIMEOUT_S,
    BCC_E2E_DURATION_S,
    BCC_TOOL_SPECS,
    BCCToolSpec,
)
from runner.libs.bpf_stats import compute_delta, enable_bpf_stats, sample_bpf_stats  # noqa: E402
from runner.libs.case_common import CaseLifecycleState, host_metadata, run_app_runner_lifecycle  # noqa: E402

def ensure_artifacts(daemon_binary: Path) -> None:
    if not daemon_binary.exists():
        raise RuntimeError(f"bpfrejit-daemon not found: {daemon_binary}")


def measure_workload(runner: BCCRunner, duration_s: int, prog_ids: list[int]) -> dict[str, object]:
    before_bpf = sample_bpf_stats(prog_ids)
    workload_result = runner.run_workload(float(duration_s))
    after_bpf = sample_bpf_stats(prog_ids)
    return {"throughput": workload_result.ops_per_sec, "metric": "ops/s", "duration_s": duration_s, "bpf": compute_delta(before_bpf, after_bpf)}
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
def lifecycle_programs(lifecycle_result: object) -> list[dict[str, object]]:
    artifacts = getattr(lifecycle_result, "artifacts", {})
    raw_programs = artifacts.get("programs") if isinstance(artifacts, Mapping) else None
    return [dict(program) for program in (raw_programs or []) if isinstance(program, Mapping)]
def merge_programs(existing: list[dict[str, object]], incoming: object) -> None:
    seen_ids = {
        int(program.get("id", 0) or 0)
        for program in existing
        if int(program.get("id", 0) or 0) > 0
    }
    for program in incoming or []:
        if not isinstance(program, Mapping):
            continue
        prog_id = int(program.get("id", 0) or 0)
        if prog_id <= 0 or prog_id in seen_ids:
            continue
        existing.append(dict(program))
        seen_ids.add(prog_id)
def run_phase(
    spec: BCCToolSpec,
    tool_binary: Path,
    *,
    duration_s: int,
    attach_timeout_s: int,
    prepared_daemon_session: object,
) -> dict[str, object]:
    runner = BCCRunner(
        tool_binary=tool_binary,
        tool_args=spec.tool_args,
        workload_spec=spec.workload_spec,
        attach_timeout_s=attach_timeout_s,
    )
    def workload(lifecycle: CaseLifecycleState, _phase_name: str) -> dict[str, object]:
        prog_ids = [int(value) for value in lifecycle.prog_ids if int(value) > 0]
        if not prog_ids:
            return {"status": "error", "reason": "no BPF programs are attached", "measurement": None}
        return {"status": "ok", "reason": "", "measurement": measure_workload(runner, duration_s, prog_ids)}
    def build_state(active_runner: BCCRunner, started_prog_ids: list[int]) -> CaseLifecycleState:
        prog_ids = [int(value) for value in started_prog_ids if int(value) > 0]
        if not prog_ids:
            raise RuntimeError(f"BCC tool {spec.name} did not expose any live prog_ids")
        programs = [dict(program) for program in active_runner.programs]
        if not programs:
            raise RuntimeError(f"BCC tool {spec.name} did not expose any live programs")
        return CaseLifecycleState(
            runtime=active_runner,
            prog_ids=prog_ids,
            artifacts={
                "programs": programs,
                "rejit_policy_context": {"repo": "bcc", "category": "bcc", "level": "e2e"},
            },
        )
    try:
        lifecycle_result = run_app_runner_lifecycle(
            daemon_session=prepared_daemon_session,
            runner=runner,
            measure=workload,
            build_state=build_state,
        )
    except Exception as exc:
        return {
            "baseline": {"phase": "baseline", "status": "error", "reason": str(exc), "measurement": None},
            "post_rejit": None,
            "rejit_result": None,
            "programs": [],
            "process": dict(runner.process_output),
        }
    programs = lifecycle_programs(lifecycle_result)
    baseline = phase_payload("baseline", lifecycle_result.baseline)
    if baseline is None:
        baseline = {"phase": "baseline", "status": "error", "reason": "baseline measurement is missing", "measurement": None}
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
    return {
        "baseline": baseline,
        "post_rejit": post_rejit,
        "rejit_result": lifecycle_result.rejit_result,
        "programs": programs,
        "process": dict(runner.process_output),
    }
def append_json(lines: list[str], title: str, payload: object) -> None:
    lines.extend([f"### {title}", "", "```json", json.dumps(payload, indent=2, sort_keys=True, default=str), "```", ""])
def build_markdown(payload: Mapping[str, object]) -> str:
    lines = [
        "# BCC libbpf-tools Real End-to-End Benchmark",
        "",
        f"- Generated: `{payload.get('generated_at')}`",
        f"- Duration per phase: `{payload.get('duration_s')}s`",
        f"- Daemon: `{payload.get('daemon')}`",
        f"- Tools dir: `{payload.get('tools_dir')}`",
        f"- Setup rc: `{(payload.get('setup') or {}).get('returncode')}`",
    ]
    if payload.get("error_message"):
        lines.append(f"- Error: `{payload.get('error_message')}`")
    lines.append("")
    for record in payload.get("records", []):
        if not isinstance(record, Mapping):
            continue
        lines.extend([f"## {record.get('name')}", ""])
        append_json(lines, "Baseline", record.get("baseline"))
        append_json(lines, "Post-ReJIT", record.get("post_rejit"))
        append_json(lines, "ReJIT Result", record.get("rejit_result"))
        append_json(lines, "Process Output", record.get("process"))
    return "\n".join(lines)
def run_bcc_case(args: argparse.Namespace) -> dict[str, object]:
    prepared_daemon_session = getattr(args, "_prepared_daemon_session", None)
    if prepared_daemon_session is None:
        raise RuntimeError("prepared daemon session is required")
    daemon_binary = Path(args.daemon).resolve()
    ensure_artifacts(daemon_binary)
    setup_result = inspect_bcc_setup()
    duration_override = int(getattr(args, "duration", 0) or 0)
    duration_s = int(duration_override or BCC_E2E_DURATION_S)
    tools_dir = resolve_tools_dir("", setup_result=setup_result)
    if not BCC_TOOL_SPECS:
        return {"generated_at": datetime.now(timezone.utc).isoformat(), "status": "error", "error_message": "no tools selected", "duration_s": duration_s, "daemon": str(daemon_binary), "tools_dir": str(tools_dir), "setup": dict(setup_result), "records": []}
    missing = [spec.name for spec in BCC_TOOL_SPECS if find_tool_binary(tools_dir, spec.name) is None]
    if missing:
        return {"generated_at": datetime.now(timezone.utc).isoformat(), "status": "error", "error_message": f"missing BCC tool binaries in {tools_dir}: {', '.join(missing)}", "duration_s": duration_s, "daemon": str(daemon_binary), "tools_dir": str(tools_dir), "setup": dict(setup_result), "records": []}
    records: list[dict[str, object]] = []
    programs: list[dict[str, object]] = []
    errors: list[str] = []
    with enable_bpf_stats():
        for spec in BCC_TOOL_SPECS:
            tool_binary = find_tool_binary(tools_dir, spec.name)
            phase_data = run_phase(
                spec,
                tool_binary,
                duration_s=duration_s,
                attach_timeout_s=BCC_E2E_ATTACH_TIMEOUT_S,
                prepared_daemon_session=prepared_daemon_session,
            )
            merge_programs(programs, phase_data.pop("programs", []))
            record = {"name": spec.name, **phase_data}
            records.append(record)
            baseline = phase_data["baseline"]
            if isinstance(baseline, Mapping) and str(baseline.get("status") or "") != "ok":
                errors.append(f"{spec.name} baseline failed: {baseline.get('reason') or 'unknown failure'}")
            post_rejit = phase_data["post_rejit"]
            if isinstance(post_rejit, Mapping) and str(post_rejit.get("status") or "") != "ok":
                errors.append(f"{spec.name} post_rejit failed: {post_rejit.get('reason') or 'unknown failure'}")

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "error" if errors else "ok",
        "duration_s": duration_s,
        "daemon": str(daemon_binary),
        "tools_dir": str(tools_dir),
        "setup": dict(setup_result),
        "host": host_metadata(),
        "programs": programs,
        "records": records,
    }
    if errors:
        payload["error_message"] = "; ".join(errors)
    return payload
