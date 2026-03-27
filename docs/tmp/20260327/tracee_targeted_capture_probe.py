#!/usr/bin/env python3
from __future__ import annotations

import json
import sys
from pathlib import Path

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from e2e.case_common import build_map_capture_specs, capture_map_state
from e2e.cases.tracee.case import (
    CACHED_TRACEE_BINARY,
    TraceeAgentSession,
    build_tracee_commands,
    load_config,
    resolve_tracee_binary,
    run_setup_script,
    select_tracee_programs,
)
from runner.libs import ROOT_DIR, write_json
from runner.libs.rejit import apply_daemon_rejit, benchmark_rejit_enabled_passes


OUT_PATH = ROOT_DIR / "docs" / "tmp" / "20260327" / "tracee_targeted_capture_probe_20260327.json"


def main() -> int:
    result: dict[str, object] = {"status": "starting"}
    write_json(OUT_PATH, result)

    try:
        config = load_config(ROOT_DIR / "e2e" / "cases" / "tracee" / "config.yaml")
        setup = {
            "returncode": 0,
            "tracee_binary": str(CACHED_TRACEE_BINARY) if CACHED_TRACEE_BINARY.exists() else None,
            "stdout_tail": "",
            "stderr_tail": "",
        }
        binary = resolve_tracee_binary(None, setup)
        if binary is None:
            setup = run_setup_script(ROOT_DIR / "e2e" / "cases" / "tracee" / "setup.sh")
            binary = resolve_tracee_binary(None, setup)
        if binary is None:
            raise RuntimeError("tracee binary unavailable")

        commands = build_tracee_commands(binary, list(config.get("events") or []), [])
        with TraceeAgentSession(commands, load_timeout=20) as session:
            selected = select_tracee_programs(session.programs, config)
            capture_plan = build_map_capture_specs(
                selected,
                repo_name="tracee",
                object_paths=sorted((ROOT_DIR / "corpus" / "build" / "tracee").glob("*.bpf.o")),
                runner_binary=ROOT_DIR / "runner" / "build" / "micro_exec",
            )
            specs = list(capture_plan.get("program_specs") or [])
            matching_specs = [spec for spec in specs if str(spec.get("program") or "") == "sys_enter_submit"]
            matching_ids = {int(spec.get("prog_id", 0) or 0) for spec in matching_specs}
            matching_programs = [
                prog for prog in session.programs if int(prog.get("id", 0) or 0) in matching_ids
            ]
            result = {
                "status": "launched",
                "tracee_binary": binary,
                "program_count": len(session.programs),
                "selected_program_count": len(selected),
                "capture_plan_summary": {
                    "discovery_errors": capture_plan.get("discovery_errors"),
                    "unmatched_programs": capture_plan.get("unmatched_programs"),
                    "ambiguous_programs": capture_plan.get("ambiguous_programs"),
                },
                "matching_specs": matching_specs,
                "matching_program_names": [prog.get("name") for prog in matching_programs],
            }
            write_json(OUT_PATH, result)

            if not matching_specs:
                nearby = [
                    spec
                    for spec in specs
                    if "submit" in str(spec.get("program") or "") or "sys_enter" in str(spec.get("program") or "")
                ]
                result["status"] = "no_match"
                result["nearby_specs"] = nearby[:20]
                write_json(OUT_PATH, result)
                print(json.dumps(result, indent=2, sort_keys=True))
                return 0

            target_spec = matching_specs[0]
            target_prog_id = int(target_spec["prog_id"])
            capture = capture_map_state(
                captured_from="debug/tracee-targeted-pre-rejit",
                program_specs=[target_spec],
                optimize_results={},
            )
            rejit = apply_daemon_rejit(
                ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon",
                [target_prog_id],
                enabled_passes=benchmark_rejit_enabled_passes(),
            )
            result.update(
                {
                    "status": "completed",
                    "target_prog_id": target_prog_id,
                    "rejit": rejit,
                    "capture": capture,
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
