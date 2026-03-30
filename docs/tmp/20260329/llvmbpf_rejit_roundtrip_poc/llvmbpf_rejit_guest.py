#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
import time
from pathlib import Path
from typing import Any


SCRIPT_PATH = Path(__file__).resolve()
WORKDIR = SCRIPT_PATH.parent


def find_repo_root() -> Path:
    for parent in [SCRIPT_PATH.parent, *SCRIPT_PATH.parents]:
        if (parent / "Makefile").exists() and (parent / "AGENTS.md").exists():
            return parent
    raise RuntimeError(f"unable to locate repo root from {SCRIPT_PATH}")


REPO_ROOT = find_repo_root()
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from runner.libs.app_runners.bcc import BCCRunner  # noqa: E402
from runner.libs.app_runners.tracee import TraceeRunner  # noqa: E402
from runner.libs.agent import find_bpf_programs  # noqa: E402


HELPER_BINARY = WORKDIR / "guest_helper" / "target" / "release" / "llvmbpf-rejit-guest"
TRACEE_PROGRAM_STABILIZE_TIMEOUT_S = 20.0
TRACEE_PROGRAM_STABLE_WINDOW_S = 3.0
TRACEE_PROGRAM_POLL_INTERVAL_S = 0.5


def safe_slug(text: str) -> str:
    return re.sub(r"[^A-Za-z0-9._-]+", "_", text).strip("_") or "program"


def write_json(path: Path, payload: Any) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")


def run_helper(argv: list[str]) -> dict[str, Any]:
    completed = subprocess.run(
        argv,
        cwd=REPO_ROOT,
        text=True,
        capture_output=True,
        check=False,
    )
    if completed.returncode != 0:
        raise RuntimeError(
            f"helper failed rc={completed.returncode}: {' '.join(argv)}\n"
            f"stdout:\n{completed.stdout}\n"
            f"stderr:\n{completed.stderr}"
        )
    return json.loads(completed.stdout)


def wait_for_tracee_programs(runner: TraceeRunner) -> list[dict[str, Any]]:
    if runner.pid is None:
        raise RuntimeError("TraceeRunner has no pid after start()")

    deadline = time.monotonic() + TRACEE_PROGRAM_STABILIZE_TIMEOUT_S
    stable_deadline: float | None = None
    best_programs = [dict(program) for program in runner.programs]
    best_count = len(best_programs)

    while time.monotonic() < deadline:
        current = [dict(program) for program in find_bpf_programs(runner.pid)]
        current_count = len(current)
        if current_count > best_count:
            best_programs = current
            best_count = current_count
            stable_deadline = time.monotonic() + TRACEE_PROGRAM_STABLE_WINDOW_S
        elif current_count == best_count and current_count > 0:
            if stable_deadline is None:
                stable_deadline = time.monotonic() + TRACEE_PROGRAM_STABLE_WINDOW_S
            if time.monotonic() >= stable_deadline:
                break
        else:
            stable_deadline = None
        time.sleep(TRACEE_PROGRAM_POLL_INTERVAL_S)

    if not best_programs:
        raise RuntimeError("Tracee attached no BPF programs after stabilization wait")
    runner.programs = best_programs
    return best_programs


def open_runner(scenario: str, bcc_tool: str | None) -> tuple[Any, list[dict[str, Any]]]:
    if scenario == "execsnoop":
        runner = BCCRunner(tool_name="execsnoop")
    elif scenario == "bcc":
        if not bcc_tool:
            raise RuntimeError("--bcc-tool is required for scenario=bcc")
        runner = BCCRunner(tool_name=bcc_tool)
    elif scenario == "tracee":
        runner = TraceeRunner()
    else:
        raise RuntimeError(f"unsupported scenario: {scenario}")

    runner.start()
    if scenario == "tracee":
        programs = wait_for_tracee_programs(runner)
    else:
        programs = [dict(program) for program in runner.programs]
    if not programs:
        raise RuntimeError(f"{scenario} attached no programs")
    return runner, programs


def build_manifest(
    session_dir: Path,
    scenario: str,
    programs: list[dict[str, Any]],
) -> dict[str, Any]:
    manifest_programs: list[dict[str, Any]] = []
    for program in programs:
        prog_id = int(program["id"])
        prog_name = str(program.get("name") or f"prog_{prog_id}")
        program_dir = session_dir / "programs" / f"{prog_id}_{safe_slug(prog_name)}"
        program_dir.mkdir(parents=True, exist_ok=True)
        dump_payload = run_helper(
            [
                str(HELPER_BINARY),
                "dump",
                "--prog-id",
                str(prog_id),
                "--output-dir",
                str(program_dir),
            ]
        )
        write_json(program_dir / "dump.json", dump_payload)
        manifest_programs.append(
            {
                "program_id": prog_id,
                "program_name": prog_name,
                "program_dir": str(program_dir),
                "original_bin_path": dump_payload["original_bin_path"],
                "dump": dump_payload,
                "owner_pids": program.get("owner_pids") or [],
                "type": program.get("type"),
            }
        )

    manifest = {
        "scenario": scenario,
        "session_dir": str(session_dir),
        "programs": manifest_programs,
    }
    write_json(session_dir / "manifest.json", manifest)
    return manifest


def wait_for_host_prepare(session_dir: Path, timeout_s: int) -> dict[str, Any]:
    summary_path = session_dir / "host_prepare_summary.json"
    deadline = time.monotonic() + timeout_s
    while time.monotonic() < deadline:
        if summary_path.exists():
            return json.loads(summary_path.read_text(encoding="utf-8"))
        time.sleep(1)
    raise RuntimeError(f"timed out waiting for host_prepare_summary.json in {session_dir}")


def run_session(session_dir: Path, scenario: str, bcc_tool: str | None, wait_timeout_s: int) -> None:
    session_dir.mkdir(parents=True, exist_ok=True)
    runner = None
    try:
        runner, programs = open_runner(scenario, bcc_tool)
        manifest = build_manifest(session_dir, scenario, programs)
        host_summary = wait_for_host_prepare(session_dir, wait_timeout_s)
        manifest_by_id = {
            int(program["program_id"]): program for program in manifest["programs"]
        }

        results = {
            "scenario": scenario,
            "session_dir": str(session_dir),
            "programs": [],
        }
        for program in host_summary["programs"]:
            result_entry = dict(program)
            if program["status"] != "ok":
                results["programs"].append(result_entry)
                continue

            helper_payload = run_helper(
                [
                    str(HELPER_BINARY),
                    "rejit",
                    "--prog-id",
                    str(program["program_id"]),
                    "--roundtrip-bin",
                    str(program["roundtrip_bin_path"]),
                ]
            )
            manifest_program = manifest_by_id[int(program["program_id"])]
            write_json(
                Path(manifest_program["program_dir"]) / "rejit.json",
                helper_payload,
            )
            result_entry["rejit"] = helper_payload
            results["programs"].append(result_entry)

        write_json(session_dir / "results.json", results)
        print(json.dumps(results, indent=2))
    finally:
        if runner is not None:
            runner.stop()


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="VM-side live-program GET_ORIGINAL + REJIT session driver")
    parser.add_argument("--session-dir", type=Path, required=True)
    parser.add_argument("--scenario", choices=("execsnoop", "bcc", "tracee"), required=True)
    parser.add_argument("--bcc-tool", default=None)
    parser.add_argument("--wait-timeout-s", type=int, default=1800)
    return parser


def main() -> int:
    args = build_parser().parse_args()
    run_session(args.session_dir.resolve(), args.scenario, args.bcc_tool, args.wait_timeout_s)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
