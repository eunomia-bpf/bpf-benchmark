#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import platform
import shutil
import subprocess
import sys
import time
from collections import Counter
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

try:
    from results_layout import authoritative_output_path, maybe_refresh_latest_alias, smoke_output_path
except ImportError:
    from corpus.results_layout import authoritative_output_path, maybe_refresh_latest_alias, smoke_output_path


ROOT = Path(__file__).resolve().parent
REPO_ROOT = ROOT.parent
DEFAULT_INVENTORY = ROOT / "inventory.json"
DEFAULT_OUTPUT = authoritative_output_path(ROOT / "results", "real_world_code_size")
DEFAULT_REPORT = ROOT / "results" / "real_world_code_size.md"
DEFAULT_RUNNER = REPO_ROOT / "micro" / "build" / "runner" / "micro_exec"
DEFAULT_BUILD_ROOT = ROOT / "build" / "real_world_code_size"
DEFAULT_TIMEOUT_SECONDS = 60
SUPPORTED_REPOS = (
    "libbpf-bootstrap",
    "bcf-cilium",
    "bcf-inspektor-gadget",
    "bcf-collected",
    "bcf-bcc",
    "bcf-bpf-examples",
    "bcf-calico",
)
DEFAULT_REPOS = (
    "libbpf-bootstrap",
    "bcf-cilium",
    "bcf-inspektor-gadget",
    "bcf-collected",
)
BCF_PROFILE_DIRS = {
    "bcf-cilium": ROOT / "bcf" / "cilium",
    "bcf-inspektor-gadget": ROOT / "bcf" / "inspektor-gadget",
    "bcf-collected": ROOT / "bcf" / "collected",
    "bcf-bcc": ROOT / "bcf" / "bcc",
    "bcf-bpf-examples": ROOT / "bcf" / "bpf-examples",
    "bcf-calico": ROOT / "bcf" / "calico",
}
SUPPORTED_RUNTIMES = ("kernel", "kernel-recompile")
PAIR_RUNTIME_SET = frozenset(SUPPORTED_RUNTIMES)
PAIR_RATIO_KEY = "kernel_recompile_over_kernel_native_code_ratio"


@dataclass(frozen=True)
class RepoBuildProfile:
    name: str
    display_name: str
    repo_dir: Path
    source_root: Path


@dataclass(frozen=True)
class ObjectScanProfile:
    name: str
    display_name: str
    object_root: Path


@dataclass(frozen=True)
class ArtifactWorkItem:
    repo_name: str
    display_name: str
    relative_path: str
    artifact_kind: str
    source_path: Path | None = None
    object_path: Path | None = None
    build_profile: RepoBuildProfile | None = None


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Compile real-world .bpf.c sources and compare per-program native code size."
    )
    parser.add_argument("--inventory", default=str(DEFAULT_INVENTORY), help="Path to corpus/inventory.json.")
    parser.add_argument("--output", default=str(DEFAULT_OUTPUT), help="Path to output JSON payload.")
    parser.add_argument("--report", default=str(DEFAULT_REPORT), help="Path to Markdown report.")
    parser.add_argument("--runner", default=str(DEFAULT_RUNNER), help="Path to micro/build/runner/micro_exec.")
    parser.add_argument("--build-root", default=str(DEFAULT_BUILD_ROOT), help="Directory for compiled BPF objects.")
    parser.add_argument("--clang", default="clang", help="clang binary to use for BPF compilation.")
    parser.add_argument("--bpftool", default="bpftool", help="bpftool binary to use for vmlinux.h/object generation.")
    parser.add_argument(
        "--repo",
        action="append",
        dest="repos",
        choices=list(SUPPORTED_REPOS),
        help="Restrict the run to a subset of supported corpora/artifact groups. Defaults to the curated set.",
    )
    parser.add_argument(
        "--runtime",
        action="append",
        dest="runtimes",
        choices=list(SUPPORTED_RUNTIMES),
        help="Restrict the inspect phase to a subset of kernel runtimes. Defaults to stock kernel and kernel-recompile.",
    )
    parser.add_argument("--max-sources", type=int, help="Limit the number of input artifacts processed per run.")
    parser.add_argument(
        "--timeout-seconds",
        type=int,
        default=DEFAULT_TIMEOUT_SECONDS,
        help="Per-command timeout in seconds.",
    )
    return parser.parse_args()


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


def parse_json_output(stdout: str) -> Any:
    payload = stdout.strip().splitlines()
    if not payload:
        raise ValueError("command produced no stdout")
    return json.loads(payload[-1])


def invoke_command(command: list[str], timeout_seconds: int, cwd: Path | None = None) -> dict[str, Any]:
    started_ns = time.perf_counter_ns()
    try:
        completed = subprocess.run(
            command,
            cwd=cwd,
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
        )
    except subprocess.TimeoutExpired as error:
        wall_ns = time.perf_counter_ns() - started_ns
        return {
            "status": "timeout",
            "returncode": None,
            "wall_time_ns": wall_ns,
            "stdout": trim_text(error.stdout or ""),
            "stderr": trim_text(error.stderr or ""),
            "error": f"timed out after {timeout_seconds} seconds",
        }
    except OSError as error:
        wall_ns = time.perf_counter_ns() - started_ns
        return {
            "status": "error",
            "returncode": None,
            "wall_time_ns": wall_ns,
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
            "stdout": stdout,
            "stderr": stderr,
            "error": stderr or stdout or f"command failed with return code {completed.returncode}",
        }

    return {
        "status": "ok",
        "returncode": completed.returncode,
        "wall_time_ns": wall_ns,
        "stdout": stdout,
        "stderr": stderr,
        "error": None,
    }


def ensure_runner_binary(path: Path) -> None:
    if path.exists():
        return
    completed = subprocess.run(["make", "-C", "micro", "micro_exec"], cwd=REPO_ROOT, text=True)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def supported_repos_from_inventory(inventory: dict[str, Any], requested: list[str] | None) -> list[RepoBuildProfile]:
    requested_set = set(requested or DEFAULT_REPOS)
    profiles: list[RepoBuildProfile] = []
    for repo in inventory["repos"]:
        repo_name = str(repo["name"])
        if repo_name not in requested_set:
            continue
        if repo_name not in SUPPORTED_REPOS:
            continue
        repo_dir = Path(repo["repo_dir"]).resolve()
        if repo_name == "libbpf-bootstrap":
            profiles.append(
                RepoBuildProfile(
                    name=repo_name,
                    display_name=repo_name,
                    repo_dir=repo_dir,
                    source_root=repo_dir / "examples" / "c",
                )
            )
    return profiles


def supported_object_profiles(requested: list[str] | None) -> list[ObjectScanProfile]:
    requested_set = set(requested or DEFAULT_REPOS)
    profiles: list[ObjectScanProfile] = []
    for repo_name, object_root in BCF_PROFILE_DIRS.items():
        if repo_name not in requested_set:
            continue
        if not object_root.is_dir():
            continue
        profiles.append(
            ObjectScanProfile(
                name=repo_name,
                display_name=f"bcf/{object_root.name}",
                object_root=object_root.resolve(),
            )
        )
    return profiles


def load_inventory(path: Path) -> dict[str, Any]:
    if not path.exists():
        raise SystemExit(f"inventory not found: {path}")
    inventory = json.loads(path.read_text())
    if "repos" not in inventory:
        raise SystemExit(f"unexpected inventory schema: {path}")
    return inventory


def target_arch_macro() -> str:
    machine = platform.machine().lower()
    mapping = {
        "x86_64": "x86",
        "amd64": "x86",
        "aarch64": "arm64",
        "arm64": "arm64",
        "armv7l": "arm",
        "armv8l": "arm",
        "ppc64le": "powerpc",
        "riscv64": "riscv",
        "loongarch64": "loongarch",
    }
    if machine in mapping:
        return mapping[machine]
    if machine.startswith("arm"):
        return "arm"
    if machine.startswith("mips"):
        return "mips"
    return machine


def clang_sys_include_flags(clang: str) -> list[str]:
    completed = subprocess.run(
        [clang, "-v", "-E", "-"],
        input="",
        capture_output=True,
        text=True,
        check=False,
    )
    if completed.returncode != 0:
        raise SystemExit(f"unable to query clang system include paths via `{clang} -v -E -`")

    flags: list[str] = []
    collecting = False
    for line in completed.stderr.splitlines():
        if "<...> search starts here:" in line:
            collecting = True
            continue
        if "End of search list." in line:
            break
        if not collecting:
            continue
        include_path = line.strip()
        if include_path:
            flags.extend(["-idirafter", include_path])
    return flags


def ensure_vmlinux_header(bpftool: str, output_path: Path) -> None:
    if output_path.exists():
        return
    output_path.parent.mkdir(parents=True, exist_ok=True)
    with output_path.open("w") as handle:
        completed = subprocess.run(
            [bpftool, "btf", "dump", "file", "/sys/kernel/btf/vmlinux", "format", "c"],
            stdout=handle,
            stderr=subprocess.PIPE,
            text=True,
            check=False,
        )
    if completed.returncode != 0:
        output_path.unlink(missing_ok=True)
        raise SystemExit(
            "unable to generate vmlinux.h with bpftool: "
            + trim_text(completed.stderr or f"command failed with return code {completed.returncode}")
        )


def build_command_for_runtime(
    runtime: str,
    runner: Path,
    object_path: Path,
    program_name: str,
) -> list[str]:
    command = [
        str(runner),
        "run-kernel",
        "--program",
        str(object_path),
        "--program-name",
        program_name,
        "--compile-only",
        "--io-mode",
        "packet",
    ]
    if runtime == "kernel-recompile":
        command.extend(["--recompile-v5", "--recompile-all"])
    return ["sudo", "-n", *command]


def compile_source(
    profile: RepoBuildProfile,
    source_path: Path,
    build_root: Path,
    clang: str,
    bpftool: str | None,
    sys_include_flags: list[str],
    timeout_seconds: int,
) -> dict[str, Any]:
    repo_build_root = build_root / profile.name
    repo_build_root.mkdir(parents=True, exist_ok=True)
    vmlinux_header = repo_build_root / "vmlinux.h"
    source_stem = source_path.name.removesuffix(".c")
    temp_object_path = repo_build_root / f"{source_stem}.tmp.o"
    object_path = repo_build_root / f"{source_stem}.o"

    clang_command = [
        clang,
        "-g",
        "-O2",
        "-target",
        "bpf",
        f"-D__TARGET_ARCH_{target_arch_macro()}",
        "-I",
        str(repo_build_root),
        "-I",
        str(REPO_ROOT / "vendor" / "libbpf" / "src"),
        "-I",
        str(REPO_ROOT / "vendor" / "libbpf" / "include" / "uapi"),
        "-I",
        str(profile.source_root),
        *sys_include_flags,
        "-c",
        str(source_path),
        "-o",
        str(temp_object_path),
    ]
    compile_outcome = invoke_command(clang_command, timeout_seconds)
    if compile_outcome["status"] != "ok":
        return {
            "status": "error",
            "stage": "clang",
            "object_path": str(object_path),
            "temp_object_path": str(temp_object_path),
            "vmlinux_header": str(vmlinux_header),
            "compile_command": clang_command,
            "object_finalize_command": None,
            **compile_outcome,
        }

    finalize_command: list[str] | None = None
    finalize_outcome: dict[str, Any]
    if bpftool is not None:
        finalize_command = [bpftool, "gen", "object", str(object_path), str(temp_object_path)]
        finalize_outcome = invoke_command(finalize_command, timeout_seconds)
        if finalize_outcome["status"] != "ok":
            return {
                "status": "error",
                "stage": "bpftool_gen_object",
                "object_path": str(object_path),
                "temp_object_path": str(temp_object_path),
                "vmlinux_header": str(vmlinux_header),
                "compile_command": clang_command,
                "object_finalize_command": finalize_command,
                "compile_stdout": compile_outcome["stdout"],
                "compile_stderr": compile_outcome["stderr"],
                **finalize_outcome,
            }
    else:
        shutil.copyfile(temp_object_path, object_path)
        finalize_outcome = {
            "status": "ok",
            "returncode": 0,
            "wall_time_ns": 0,
            "stdout": "",
            "stderr": "",
            "error": None,
        }

    return {
        "status": "ok",
        "stage": "complete",
        "object_path": str(object_path),
        "temp_object_path": str(temp_object_path),
        "vmlinux_header": str(vmlinux_header),
        "compile_command": clang_command,
        "object_finalize_command": finalize_command,
        "compile_stdout": compile_outcome["stdout"],
        "compile_stderr": compile_outcome["stderr"],
        "compile_wall_time_ns": compile_outcome["wall_time_ns"],
        "finalize_stdout": finalize_outcome["stdout"],
        "finalize_stderr": finalize_outcome["stderr"],
        "finalize_wall_time_ns": finalize_outcome["wall_time_ns"],
    }


def use_prebuilt_object(object_path: Path) -> dict[str, Any]:
    return {
        "status": "ok",
        "stage": "prebuilt_object",
        "object_path": str(object_path),
        "temp_object_path": None,
        "vmlinux_header": None,
        "compile_command": None,
        "object_finalize_command": None,
        "compile_stdout": "",
        "compile_stderr": "",
        "compile_wall_time_ns": 0,
        "finalize_stdout": "",
        "finalize_stderr": "",
        "finalize_wall_time_ns": 0,
    }


def list_object_programs(runner: Path, object_path: Path, timeout_seconds: int) -> dict[str, Any]:
    command = [
        str(runner),
        "list-programs",
        "--program",
        str(object_path),
    ]
    outcome = invoke_command(command, timeout_seconds)
    if outcome["status"] != "ok":
        return {"command": command, "programs": [], **outcome}
    try:
        programs = parse_json_output(outcome["stdout"])
    except Exception as error:  # noqa: BLE001
        return {
            "command": command,
            "programs": [],
            "status": "error",
            "returncode": 0,
            "wall_time_ns": outcome["wall_time_ns"],
            "stdout": outcome["stdout"],
            "stderr": outcome["stderr"],
            "error": f"failed to parse list-programs output: {error}",
        }
    return {"command": command, "programs": programs, **outcome}


def inspect_program(
    runtime: str,
    runner: Path,
    object_path: Path,
    program_name: str,
    timeout_seconds: int,
) -> dict[str, Any]:
    command = build_command_for_runtime(runtime, runner, object_path, program_name)
    outcome = invoke_command(command, timeout_seconds)
    if outcome["status"] != "ok":
        return {"runtime": runtime, "command": command, "sample": None, **outcome}
    try:
        sample = parse_json_output(outcome["stdout"])
    except Exception as error:  # noqa: BLE001
        return {
            "runtime": runtime,
            "command": command,
            "sample": None,
            "status": "error",
            "returncode": 0,
            "wall_time_ns": outcome["wall_time_ns"],
            "stdout": outcome["stdout"],
            "stderr": outcome["stderr"],
            "error": f"failed to parse runtime output: {error}",
        }
    return {"runtime": runtime, "command": command, "sample": sample, **outcome}


def geomean(values: list[float]) -> float | None:
    positive_values = [value for value in values if value > 0.0]
    if not positive_values:
        return None
    return math.exp(sum(math.log(value) for value in positive_values) / len(positive_values))


def load_repo_sources(
    inventory: dict[str, Any],
    profiles: list[RepoBuildProfile],
    max_sources: int | None,
) -> list[ArtifactWorkItem]:
    files_by_repo = {str(repo["name"]): list(repo["files"]) for repo in inventory["repos"]}
    selected: list[ArtifactWorkItem] = []
    for profile in profiles:
        relative_files = files_by_repo.get(profile.name, [])
        for relative_path in relative_files:
            if not relative_path.endswith(".bpf.c"):
                continue
            source_path = profile.repo_dir / relative_path
            selected.append(
                ArtifactWorkItem(
                    repo_name=profile.name,
                    display_name=profile.display_name,
                    relative_path=relative_path,
                    artifact_kind="source",
                    source_path=source_path.resolve(),
                    build_profile=profile,
                )
            )
    selected.sort(key=lambda item: (item.repo_name, item.relative_path))
    if max_sources is not None:
        return selected[:max_sources]
    return selected


def load_prebuilt_objects(
    profiles: list[ObjectScanProfile],
    max_sources: int | None,
) -> list[ArtifactWorkItem]:
    selected: list[ArtifactWorkItem] = []
    for profile in profiles:
        object_paths = [path for path in profile.object_root.rglob("*") if path.is_file() and path.name.endswith(".o")]
        for object_path in sorted(object_paths):
            selected.append(
                ArtifactWorkItem(
                    repo_name=profile.name,
                    display_name=profile.display_name,
                    relative_path=str(object_path.relative_to(profile.object_root)),
                    artifact_kind="prebuilt_object",
                    object_path=object_path.resolve(),
                )
            )
    selected.sort(key=lambda item: (item.repo_name, item.relative_path))
    if max_sources is not None:
        return selected[:max_sources]
    return selected


def compute_summary(source_records: list[dict[str, Any]], runtimes: list[str]) -> dict[str, Any]:
    source_total = len(source_records)
    build_ok = sum(1 for record in source_records if record["build"]["status"] == "ok")
    list_ok = sum(1 for record in source_records if record["program_inventory"]["status"] == "ok")
    build_failures = Counter()
    inventory_failures = Counter()
    runtime_status: dict[str, Counter[str]] = {runtime: Counter() for runtime in runtimes}
    runtime_failures: dict[str, Counter[str]] = {runtime: Counter() for runtime in runtimes}
    program_rows: list[dict[str, Any]] = []
    selected_runtime_ok = 0
    pair_mode = set(runtimes) == PAIR_RUNTIME_SET

    for source in source_records:
        if source["build"]["status"] != "ok":
            build_failures[source["build"]["stage"]] += 1
            continue
        if source["program_inventory"]["status"] != "ok":
            inventory_failures[summarize_error(source["program_inventory"]["error"])] += 1
            continue
        for program in source["programs"]:
            program_rows.append(program)
            for runtime_run in program["runs"]:
                runtime = runtime_run["runtime"]
                runtime_status[runtime][runtime_run["status"]] += 1
                if runtime_run["status"] != "ok":
                    runtime_failures[runtime][summarize_error(runtime_run["error"])] += 1

    paired_ratios: list[float] = []
    for program in program_rows:
        runs_by_runtime = {run["runtime"]: run for run in program["runs"]}
        if not all(runtime in runs_by_runtime and runs_by_runtime[runtime]["status"] == "ok" for runtime in runtimes):
            continue
        selected_runtime_ok += 1
        if not pair_mode:
            continue
        recompile_sample = runs_by_runtime["kernel-recompile"]["sample"]
        kernel_sample = runs_by_runtime["kernel"]["sample"]
        if not recompile_sample or not kernel_sample:
            continue
        kernel_size = float(kernel_sample["code_size"]["native_code_bytes"])
        if kernel_size == 0.0:
            continue
        paired_ratios.append(float(recompile_sample["code_size"]["native_code_bytes"]) / kernel_size)

    return {
        "source_files": {
            "total": source_total,
            "build_ok": build_ok,
            "build_failed": source_total - build_ok,
            "program_inventory_ok": list_ok,
            "program_inventory_failed": build_ok - list_ok,
        },
        "programs": {
            "discovered": len(program_rows),
            "selected_runtime_ok": selected_runtime_ok,
        },
        "runtime_status": {runtime: dict(counter) for runtime, counter in runtime_status.items()},
        PAIR_RATIO_KEY: {
            "paired_programs": len(paired_ratios),
            "geomean": geomean(paired_ratios),
            "min": min(paired_ratios) if paired_ratios else None,
            "median": sorted(paired_ratios)[len(paired_ratios) // 2] if paired_ratios else None,
            "max": max(paired_ratios) if paired_ratios else None,
        },
        "build_failure_breakdown": dict(build_failures),
        "program_inventory_failure_breakdown": dict(inventory_failures),
        "runtime_failure_breakdown": {runtime: dict(counter) for runtime, counter in runtime_failures.items()},
    }


def format_ratio(value: float | None) -> str:
    if value is None:
        return "-"
    return f"{value:.3f}x"


def render_report(
    payload: dict[str, Any],
    source_records: list[dict[str, Any]],
    runtimes: list[str],
) -> str:
    summary = payload["summary"]
    ratio_summary = summary[PAIR_RATIO_KEY]
    pair_mode = set(runtimes) == PAIR_RUNTIME_SET
    selected_runtime_label = "Programs with both runtimes ok" if pair_mode else "Programs with selected runtimes ok"
    lines = [
        "# Real-World Code-Size Validation",
        "",
        f"- Generated at: `{payload['generated_at']}`",
        f"- Inventory: `{payload['inventory']}`" if payload["inventory"] else "- Inventory: `not used`",
        f"- Runner: `{payload['runner_binary']}`",
        f"- Corpora: {', '.join(f'`{repo}`' for repo in payload['filters']['repos'])}",
        f"- Runtimes: {', '.join(f'`{runtime}`' for runtime in runtimes)}",
        "",
        "## Summary",
        "",
        "| Metric | Value |",
        "| --- | ---: |",
        f"| Input artifacts considered | {summary['source_files']['total']} |",
        f"| Artifact prepare/build succeeded | {summary['source_files']['build_ok']} |",
        f"| Program inventories succeeded | {summary['source_files']['program_inventory_ok']} |",
        f"| Programs discovered | {summary['programs']['discovered']} |",
        f"| {selected_runtime_label} | {summary['programs']['selected_runtime_ok']} |",
    ]

    if pair_mode:
        lines.append(
            f"| Geomean native code-size ratio (kernel-recompile/kernel) | {format_ratio(ratio_summary['geomean'])} |"
        )

    lines.extend(
        [
            "",
            "## Runtime Status",
            "",
            "| Runtime | ok | error | timeout |",
            "| --- | ---: | ---: | ---: |",
        ]
    )
    for runtime in runtimes:
        counter = summary["runtime_status"].get(runtime, {})
        lines.append(
            f"| {runtime} | {counter.get('ok', 0)} | {counter.get('error', 0)} | {counter.get('timeout', 0)} |"
        )

    build_failures = summary["build_failure_breakdown"]
    if build_failures:
        lines.extend(
            [
                "",
                "## Build Failures",
                "",
                "| Stage | Count |",
                "| --- | ---: |",
            ]
        )
        for stage, count in sorted(build_failures.items()):
            lines.append(f"| {stage} | {count} |")

    runtime_failures = summary["runtime_failure_breakdown"]
    for runtime in runtimes:
        failures = runtime_failures.get(runtime, {})
        if not failures:
            continue
        lines.extend(
            [
                "",
                f"## {runtime} Failures",
                "",
                "| Error summary | Count |",
                "| --- | ---: |",
            ]
        )
        for error, count in sorted(failures.items(), key=lambda item: (-item[1], item[0])):
            lines.append(f"| {error} | {count} |")

    paired_rows: list[dict[str, Any]] = []
    for source in source_records:
        if source["program_inventory"]["status"] != "ok":
            continue
        for program in source["programs"]:
            runs_by_runtime = {run["runtime"]: run for run in program["runs"]}
            recompile_run = runs_by_runtime.get("kernel-recompile")
            kernel_run = runs_by_runtime.get("kernel")
            if recompile_run is None or kernel_run is None:
                continue
            if recompile_run["status"] != "ok" or kernel_run["status"] != "ok":
                continue
            recompile_size = int(recompile_run["sample"]["code_size"]["native_code_bytes"])
            kernel_size = int(kernel_run["sample"]["code_size"]["native_code_bytes"])
            if kernel_size == 0:
                continue
            paired_rows.append(
                {
                    "repo": source["repo"],
                    "source": source["relative_path"],
                    "program": program["name"],
                    "section": program["section_name"],
                    "insn_count": program["insn_count"],
                    "recompile_native": recompile_size,
                    "kernel_native": kernel_size,
                    "ratio": recompile_size / kernel_size,
                }
            )

    if pair_mode and paired_rows:
        paired_rows.sort(key=lambda row: (row["ratio"], row["repo"], row["source"], row["program"]))
        lines.extend(
            [
                "",
                "## Program-Level Results",
                "",
                "| Repo | Artifact | Program | Section | BPF insns | kernel-recompile native B | kernel native B | R/K ratio |",
                "| --- | --- | --- | --- | ---: | ---: | ---: | ---: |",
            ]
        )
        for row in paired_rows:
            lines.append(
                f"| {row['repo']} | `{row['source']}` | `{row['program']}` | `{row['section']}` | "
                f"{row['insn_count']} | {row['recompile_native']} | {row['kernel_native']} | {row['ratio']:.3f}x |"
            )

    lines.extend(
        [
            "",
            "## Notes",
            "",
            "- Each row is a single program selected from either a source-built or prebuilt real BPF object, not a handcrafted micro benchmark.",
            "- `micro_exec list-programs` enumerates every libbpf-visible program in the object, and every selected runtime is invoked with `--program-name` so multi-program objects are measured per program.",
            "- `libbpf-bootstrap` inputs are compiled from source; the integrated BCF inputs are scanned directly from prebuilt objects under `corpus/bcf/`.",
            "- The curated default set keeps the run focused on corpora that are already loadable by the current tooling: `libbpf-bootstrap`, `bcf/cilium`, `bcf/inspektor-gadget`, and `bcf/collected`.",
        ]
    )
    if pair_mode:
        lines.append(
            "- `kernel-recompile` uses the existing `micro_exec run-kernel --compile-only --recompile-v5 --recompile-all` path."
        )
    return "\n".join(lines) + "\n"


def main() -> int:
    args = parse_args()
    inventory_path = Path(args.inventory).resolve()
    if args.output == str(DEFAULT_OUTPUT) and args.max_sources is not None:
        output_path = smoke_output_path(ROOT / "results", "real_world_code_size")
    else:
        output_path = Path(args.output).resolve()
    report_path = Path(args.report).resolve()
    runner_path = Path(args.runner).resolve()
    build_root = Path(args.build_root).resolve()
    build_root.mkdir(parents=True, exist_ok=True)

    selected_repo_names = set(args.repos or DEFAULT_REPOS)
    inventory: dict[str, Any] = {"repos": []}
    source_profiles: list[RepoBuildProfile] = []
    if any(repo_name == "libbpf-bootstrap" for repo_name in selected_repo_names):
        inventory = load_inventory(inventory_path)
        source_profiles = supported_repos_from_inventory(inventory, args.repos)
    object_profiles = supported_object_profiles(args.repos)
    all_profiles: list[RepoBuildProfile | ObjectScanProfile] = [*source_profiles, *object_profiles]
    if not all_profiles:
        raise SystemExit("no supported corpora selected from inventory or local BCF objects")

    ensure_runner_binary(runner_path)
    bpftool_binary: str | None = None
    clang_binary: str | None = None
    sys_include_flags: list[str] = []
    if source_profiles:
        bpftool_binary = shutil.which(args.bpftool)
        if bpftool_binary is None:
            raise SystemExit(f"bpftool not found: {args.bpftool}")
        clang_binary = shutil.which(args.clang)
        if clang_binary is None:
            raise SystemExit(f"clang not found: {args.clang}")

        sys_include_flags = clang_sys_include_flags(clang_binary)
        for profile in source_profiles:
            ensure_vmlinux_header(bpftool_binary, build_root / profile.name / "vmlinux.h")

    runtimes = args.runtimes or list(SUPPORTED_RUNTIMES)
    selected_sources = load_repo_sources(inventory, source_profiles, max_sources=None)
    selected_objects = load_prebuilt_objects(object_profiles, max_sources=None)
    selected_artifacts = [*selected_sources, *selected_objects]
    selected_artifacts.sort(key=lambda item: (item.repo_name, item.relative_path))
    if args.max_sources is not None:
        selected_artifacts = selected_artifacts[: args.max_sources]
    if not selected_artifacts:
        raise SystemExit("no input artifacts matched the selected corpora")

    source_records: list[dict[str, Any]] = []

    for index, artifact in enumerate(selected_artifacts, start=1):
        print(f"[{index:02}/{len(selected_artifacts):02}] {artifact.display_name}/{artifact.relative_path}")
        if artifact.artifact_kind == "source":
            if artifact.build_profile is None or artifact.source_path is None or clang_binary is None:
                raise SystemExit(f"incomplete source build configuration for {artifact.relative_path}")
            build_outcome = compile_source(
                profile=artifact.build_profile,
                source_path=artifact.source_path,
                build_root=build_root,
                clang=clang_binary,
                bpftool=bpftool_binary,
                sys_include_flags=sys_include_flags,
                timeout_seconds=args.timeout_seconds,
            )
        else:
            if artifact.object_path is None:
                raise SystemExit(f"missing prebuilt object path for {artifact.relative_path}")
            build_outcome = use_prebuilt_object(artifact.object_path)
        source_record: dict[str, Any] = {
            "repo": artifact.display_name,
            "selection": artifact.repo_name,
            "artifact_kind": artifact.artifact_kind,
            "relative_path": artifact.relative_path,
            "source_path": str(artifact.source_path) if artifact.source_path is not None else None,
            "build": build_outcome,
            "program_inventory": {
                "status": "skipped",
                "command": None,
                "programs": [],
                "error": "build failed",
            },
            "programs": [],
        }

        if build_outcome["status"] != "ok":
            print(f"  build     error {summarize_error(build_outcome['error'])}")
            source_records.append(source_record)
            continue

        print(f"  build     ok {Path(build_outcome['object_path']).name}")
        inventory_outcome = list_object_programs(
            runner=runner_path,
            object_path=Path(build_outcome["object_path"]),
            timeout_seconds=args.timeout_seconds,
        )
        source_record["program_inventory"] = inventory_outcome
        if inventory_outcome["status"] != "ok":
            print(f"  programs  error {summarize_error(inventory_outcome['error'])}")
            source_records.append(source_record)
            continue

        print(f"  programs  ok {len(inventory_outcome['programs'])} entries")
        for program in inventory_outcome["programs"]:
            program_record = {
                "name": str(program["name"]),
                "section_name": str(program["section_name"]),
                "insn_count": int(program["insn_count"]),
                "prog_type": int(program.get("prog_type", 0)),
                "expected_attach_type": int(program.get("expected_attach_type", 0)),
                "prog_type_name": str(program.get("prog_type_name", "")),
                "attach_type_name": str(program.get("attach_type_name", "")),
                "runs": [],
            }
            for runtime in runtimes:
                runtime_outcome = inspect_program(
                    runtime=runtime,
                    runner=runner_path,
                    object_path=Path(build_outcome["object_path"]),
                    program_name=program_record["name"],
                    timeout_seconds=args.timeout_seconds,
                )
                program_record["runs"].append(runtime_outcome)
                if runtime_outcome["status"] == "ok":
                    sample = runtime_outcome["sample"]
                    native_bytes = sample["code_size"]["native_code_bytes"]
                    print(f"    {runtime:17} ok native={native_bytes}B")
                else:
                    print(
                        f"    {runtime:17} {runtime_outcome['status']} "
                        f"{summarize_error(runtime_outcome['error'])}"
                    )
            source_record["programs"].append(program_record)

        source_records.append(source_record)

    payload = {
        "dataset": "real_world_code_size",
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "inventory": str(inventory_path) if source_profiles else None,
        "runner_binary": str(runner_path),
        "build_root": str(build_root),
        "host": {
            "hostname": platform.node(),
            "platform": platform.platform(),
            "python": sys.version.split()[0],
        },
        "build_config": {
            "clang": clang_binary,
            "bpftool": bpftool_binary,
            "target_arch_macro": target_arch_macro(),
            "clang_sys_include_flags": sys_include_flags,
        },
        "filters": {
            "repos": [profile.display_name for profile in all_profiles],
            "repo_keys": [profile.name for profile in all_profiles],
            "runtimes": runtimes,
            "max_sources": args.max_sources,
            "timeout_seconds": args.timeout_seconds,
        },
        "sources": source_records,
        "artifacts": source_records,
    }
    payload["summary"] = compute_summary(source_records, runtimes)

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(json.dumps(payload, indent=2) + "\n")
    maybe_refresh_latest_alias(output_path)
    report_path.write_text(render_report(payload, source_records, runtimes))

    print(f"[done] wrote {output_path}")
    print(f"[done] wrote {report_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
