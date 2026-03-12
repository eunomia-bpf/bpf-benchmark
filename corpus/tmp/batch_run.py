#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import platform
import subprocess
import sys
import time
from collections import Counter, defaultdict
from datetime import datetime, timezone
from pathlib import Path
from typing import Any
try:
    from results_layout import authoritative_output_path, maybe_refresh_latest_alias, smoke_output_path
except ImportError:
    from corpus.results_layout import authoritative_output_path, maybe_refresh_latest_alias, smoke_output_path


def find_repo_root() -> Path:
    for candidate in Path(__file__).resolve().parents:
        if (candidate / "micro").is_dir() and (candidate / "corpus").is_dir():
            return candidate
    raise RuntimeError("unable to locate repository root from script path")


REPO_ROOT = find_repo_root()
CORPUS_ROOT = REPO_ROOT / "corpus"
DEFAULT_MANIFEST = CORPUS_ROOT / "bcf" / "manifest.json"
DEFAULT_OUTPUT = authoritative_output_path(CORPUS_ROOT / "results", "bcf_batch")
DEFAULT_RUNNER = REPO_ROOT / "micro" / "build" / "runner" / "micro_exec"
DEFAULT_INPUT_SIZE = 256
DEFAULT_REPEAT = 1
DEFAULT_TIMEOUT_SECONDS = 30
COMPATIBLE_PROG_TYPES = {"xdp", "classifier"}


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Batch-run BCF BPF objects through the micro_exec runtimes.")
    parser.add_argument("--manifest", default=str(DEFAULT_MANIFEST), help="Path to corpus/bcf/manifest.json.")
    parser.add_argument("--output", default=str(DEFAULT_OUTPUT), help="Path to output JSON results.")
    parser.add_argument("--runner", default=str(DEFAULT_RUNNER), help="Path to micro/build/runner/micro_exec.")
    parser.add_argument("--max-programs", type=int, help="Limit the number of compatible programs processed.")
    parser.add_argument(
        "--runtime",
        action="append",
        dest="runtimes",
        choices=["llvmbpf", "kernel"],
        help="Restrict the run to a subset of runtimes. Defaults to both.",
    )
    return parser.parse_args()


def run(command: list[str], cwd: Path | None = None) -> None:
    completed = subprocess.run(command, cwd=cwd, text=True)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def ensure_runner_binary(path: Path) -> None:
    if path.exists():
        return
    print("[build] micro_exec not found, building it with `make -C micro micro_exec`")
    run(["make", "-C", "micro", "micro_exec"], cwd=REPO_ROOT)


def parse_helper_output(stdout: str) -> dict[str, Any]:
    payload = stdout.strip().splitlines()
    if not payload:
        raise ValueError("micro_exec produced no stdout")
    return json.loads(payload[-1])


def trim_text(value: str, limit: int = 4000) -> str:
    value = value.strip()
    if len(value) <= limit:
        return value
    return value[: limit - 3] + "..."


def summarize_error(value: str | None) -> str:
    if not value:
        return "unknown error"
    first_line = value.splitlines()[0].strip()
    if len(value.splitlines()) > 1:
        return first_line + " ..."
    return first_line


def runtimes_from_args(args: argparse.Namespace) -> list[str]:
    return args.runtimes or ["llvmbpf", "kernel"]


def build_command(runtime: str, runner: Path, program_path: Path) -> list[str]:
    subcommand = "run-llvmbpf" if runtime == "llvmbpf" else "run-kernel"
    command = [
        str(runner),
        subcommand,
        "--program",
        str(program_path),
        "--io-mode",
        "packet",
        "--repeat",
        str(DEFAULT_REPEAT),
        "--input-size",
        str(DEFAULT_INPUT_SIZE),
    ]
    if runtime == "kernel":
        return ["sudo", "-n", *command]
    return command


def invoke_runtime(command: list[str]) -> dict[str, Any]:
    started_ns = time.perf_counter_ns()
    try:
        completed = subprocess.run(
            command,
            capture_output=True,
            text=True,
            timeout=DEFAULT_TIMEOUT_SECONDS,
        )
    except subprocess.TimeoutExpired as error:
        wall_ns = time.perf_counter_ns() - started_ns
        return {
            "status": "timeout",
            "returncode": None,
            "wall_time_ns": wall_ns,
            "sample": None,
            "stdout": trim_text(error.stdout or ""),
            "stderr": trim_text(error.stderr or ""),
            "error": f"timed out after {DEFAULT_TIMEOUT_SECONDS} seconds",
        }
    except OSError as error:
        wall_ns = time.perf_counter_ns() - started_ns
        return {
            "status": "error",
            "returncode": None,
            "wall_time_ns": wall_ns,
            "sample": None,
            "stdout": "",
            "stderr": "",
            "error": str(error),
        }

    wall_ns = time.perf_counter_ns() - started_ns
    stdout = trim_text(completed.stdout)
    stderr = trim_text(completed.stderr)
    if completed.returncode != 0:
        return {
            "status": "error",
            "returncode": completed.returncode,
            "wall_time_ns": wall_ns,
            "sample": None,
            "stdout": stdout,
            "stderr": stderr,
            "error": stderr or stdout or f"command failed with return code {completed.returncode}",
        }

    try:
        sample = parse_helper_output(completed.stdout)
    except Exception as error:  # noqa: BLE001
        return {
            "status": "error",
            "returncode": completed.returncode,
            "wall_time_ns": wall_ns,
            "sample": None,
            "stdout": stdout,
            "stderr": stderr,
            "error": f"failed to parse micro_exec output: {error}",
        }

    return {
        "status": "ok",
        "returncode": completed.returncode,
        "wall_time_ns": wall_ns,
        "sample": sample,
        "stdout": stdout,
        "stderr": stderr,
        "error": None,
    }


def main() -> int:
    args = parse_args()
    manifest_path = Path(args.manifest).resolve()
    if args.output == str(DEFAULT_OUTPUT) and args.max_programs is not None:
        output_path = smoke_output_path(CORPUS_ROOT / "results", "bcf_batch")
    else:
        output_path = Path(args.output).resolve()
    runner_path = Path(args.runner).resolve()

    if not manifest_path.exists():
        raise SystemExit(f"manifest not found: {manifest_path}")

    ensure_runner_binary(runner_path)

    manifest = json.loads(manifest_path.read_text())
    all_programs = list(manifest["programs"])
    compatible_prog_types = set(manifest.get("compatible_prog_types", sorted(COMPATIBLE_PROG_TYPES)))
    compatible_programs = [
        program for program in all_programs
        if program.get("program_type") in compatible_prog_types and program.get("test_run_compatible")
    ]
    if args.max_programs is not None:
        compatible_programs = compatible_programs[: args.max_programs]

    runtimes = runtimes_from_args(args)
    results: list[dict[str, Any]] = []
    runtime_status: dict[str, Counter[str]] = {runtime: Counter() for runtime in runtimes}
    by_source: defaultdict[str, Counter[str]] = defaultdict(Counter)

    for index, program in enumerate(compatible_programs, start=1):
        program_path = manifest_path.parent / str(program["relative_path"])
        program_record = {
            "file_name": program["file_name"],
            "relative_path": program["relative_path"],
            "source_project": program["source_project"],
            "source_group": program["source_group"],
            "canonical_name": program["canonical_name"],
            "clang_version": program["clang_version"],
            "optimization_level": program["optimization_level"],
            "program_type": program["program_type"],
            "runs": [],
        }

        print(
            f"[{index:03}/{len(compatible_programs):03}] "
            f"{program['source_project']}/{program['file_name']} ({program['program_type']})"
        )

        for runtime in runtimes:
            command = build_command(runtime, runner_path, program_path)
            outcome = invoke_runtime(command)
            runtime_status[runtime][outcome["status"]] += 1
            by_source[str(program["source_project"])][outcome["status"]] += 1

            run_record = {
                "runtime": runtime,
                "command": command,
                **outcome,
            }
            program_record["runs"].append(run_record)
            if outcome["status"] == "ok":
                sample = outcome["sample"]
                print(
                    f"  {runtime:8} ok "
                    f"compile={sample['compile_ns']}ns "
                    f"exec={sample['exec_ns']}ns "
                    f"retval={sample['retval']}"
                )
            else:
                print(f"  {runtime:8} {outcome['status']} {summarize_error(outcome['error'])}")

        results.append(program_record)

    payload = {
        "dataset": "bcf",
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "manifest": str(manifest_path),
        "runner_binary": str(runner_path),
        "host": {
            "hostname": platform.node(),
            "platform": platform.platform(),
            "python": sys.version.split()[0],
        },
        "defaults": {
            "input_size": DEFAULT_INPUT_SIZE,
            "repeat": DEFAULT_REPEAT,
            "timeout_seconds": DEFAULT_TIMEOUT_SECONDS,
            "runtimes": runtimes,
            "compatible_prog_types": sorted(compatible_prog_types),
        },
        "corpus": {
            "total_manifest_programs": len(all_programs),
            "compatible_programs": manifest["counts"]["test_run_compatible_variants"],
            "selected_programs": len(compatible_programs),
            "skipped_incompatible_programs": len(all_programs) - manifest["counts"]["test_run_compatible_variants"],
        },
        "results": results,
        "summary": {
            "by_runtime": {runtime: dict(counter) for runtime, counter in runtime_status.items()},
            "by_source": {source: dict(counter) for source, counter in sorted(by_source.items())},
        },
    }

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(json.dumps(payload, indent=2))
    maybe_refresh_latest_alias(output_path)
    print(f"[done] wrote {output_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
