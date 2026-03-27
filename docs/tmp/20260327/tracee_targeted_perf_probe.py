#!/usr/bin/env python3
from __future__ import annotations

import json
import sys
from pathlib import Path

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from e2e.case_common import build_map_capture_specs
from e2e.cases.tracee.case import (
    TraceeAgentSession,
    build_tracee_commands,
    load_config,
    resolve_tracee_binary,
    run_setup_script,
)
from runner.libs import ROOT_DIR, write_json
from runner.libs.metrics import compute_delta, enable_bpf_stats, sample_bpf_stats
from runner.libs.rejit import apply_daemon_rejit, benchmark_rejit_enabled_passes
from runner.libs.workload import run_user_exec_loop


OUT_PATH = ROOT_DIR / "docs" / "tmp" / "20260327" / "tracee_targeted_perf_probe_20260327.json"


def main() -> int:
    result: dict[str, object] = {"status": "starting"}
    write_json(OUT_PATH, result)

    try:
        config = load_config(ROOT_DIR / "e2e" / "cases" / "tracee" / "config.yaml")
        workloads = [item for item in list(config.get("workloads") or []) if item.get("name") == "exec_storm"]
        if not workloads:
            raise RuntimeError("exec_storm workload missing from tracee config")

        setup = run_setup_script(ROOT_DIR / "e2e" / "cases" / "tracee" / "setup.sh")
        binary = resolve_tracee_binary(None, setup)
        if binary is None:
            raise RuntimeError("tracee binary unavailable")

        commands = build_tracee_commands(binary, list(config.get("events") or []), [])
        with enable_bpf_stats():
            with TraceeAgentSession(commands, load_timeout=20) as session:
                result.update(
                    {
                        "status": "launched",
                        "tracee_binary": binary,
                        "live_program_count": len(session.programs),
                    }
                )
                write_json(OUT_PATH, result)
                capture_plan = build_map_capture_specs(
                    session.programs,
                    repo_name="tracee",
                    object_paths=sorted((ROOT_DIR / "corpus" / "build" / "tracee").glob("*.bpf.o")),
                    runner_binary=ROOT_DIR / "runner" / "build" / "micro_exec",
                )
                specs = list(capture_plan.get("program_specs") or [])
                matching_specs = [spec for spec in specs if str(spec.get("program") or "") == "sys_enter_submit"]
                if not matching_specs:
                    nearby = [
                        spec
                        for spec in specs
                        if "submit" in str(spec.get("program") or "") or "sys_enter" in str(spec.get("program") or "")
                    ]
                    result.update(
                        {
                            "status": "no_match",
                            "nearby_specs": nearby[:20],
                            "capture_plan_summary": {
                                "discovery_errors": capture_plan.get("discovery_errors"),
                                "unmatched_programs": capture_plan.get("unmatched_programs"),
                                "ambiguous_programs": capture_plan.get("ambiguous_programs"),
                            },
                        }
                    )
                    write_json(OUT_PATH, result)
                    print(json.dumps(result, indent=2, sort_keys=True))
                    return 0

                target_prog_id = int(matching_specs[0]["prog_id"])
                target_prog_fds = {target_prog_id: session.program_fds[target_prog_id]}
                result.update(
                    {
                        "status": "baseline_running",
                        "target_prog_id": target_prog_id,
                        "target_prog_name": "sys_enter_submit",
                    }
                )
                write_json(OUT_PATH, result)
                baseline_before = sample_bpf_stats([target_prog_id], prog_fds=target_prog_fds)
                baseline_workload = run_user_exec_loop(5)
                baseline_after = sample_bpf_stats([target_prog_id], prog_fds=target_prog_fds)
                baseline = {
                    "workload": baseline_workload.to_dict(),
                    "delta": compute_delta(baseline_before, baseline_after),
                }
                result.update(
                    {
                        "status": "baseline_completed",
                        "baseline": baseline,
                    }
                )
                write_json(OUT_PATH, result)
                rejit = apply_daemon_rejit(
                    ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon",
                    [target_prog_id],
                    enabled_passes=benchmark_rejit_enabled_passes(),
                )
                result.update(
                    {
                        "status": "post_rejit_running",
                        "rejit": rejit,
                    }
                )
                write_json(OUT_PATH, result)
                post_before = sample_bpf_stats([target_prog_id], prog_fds=target_prog_fds)
                post_workload = run_user_exec_loop(5)
                post_after = sample_bpf_stats([target_prog_id], prog_fds=target_prog_fds)
                post_rejit = {
                    "workload": post_workload.to_dict(),
                    "delta": compute_delta(post_before, post_after),
                }

                baseline_program = ((baseline.get("delta") or {}).get("programs") or {}).get(target_prog_id, {})
                post_program = ((post_rejit.get("delta") or {}).get("programs") or {}).get(target_prog_id, {})
                baseline_avg = baseline_program.get("avg_ns_per_run")
                post_avg = post_program.get("avg_ns_per_run")
                speedup_ratio = (
                    float(baseline_avg) / float(post_avg)
                    if baseline_avg not in (None, 0) and post_avg not in (None, 0)
                    else None
                )

                result.update(
                    {
                        "status": "completed",
                        "tracee_binary": binary,
                        "target_prog_id": target_prog_id,
                        "target_prog_name": "sys_enter_submit",
                        "baseline": baseline,
                        "rejit": rejit,
                        "post_rejit": post_rejit,
                        "comparison": {
                            "baseline_avg_ns_per_run": baseline_avg,
                            "post_avg_ns_per_run": post_avg,
                            "speedup_ratio": speedup_ratio,
                        },
                    }
                )
                write_json(OUT_PATH, result)
                print(json.dumps(result, indent=2, sort_keys=True))
                return 0
    except Exception as exc:
        result["status"] = "error"
        result["error"] = str(exc)
        write_json(OUT_PATH, result)
        print(json.dumps(result, indent=2, sort_keys=True))
        raise


if __name__ == "__main__":
    raise SystemExit(main())
