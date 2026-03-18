#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import os
import platform
import random
import statistics
import subprocess
import sys
import time
from collections import Counter
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any
SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

try:
    from results_layout import maybe_refresh_latest_alias, refresh_latest_alias
except ImportError:
    from corpus.results_layout import maybe_refresh_latest_alias, refresh_latest_alias

try:
    from orchestrator.catalog import load_catalog
    from orchestrator.inventory import discover_object_programs
except ImportError:
    from micro.orchestrator.catalog import load_catalog
    from micro.orchestrator.inventory import discover_object_programs
try:
    from common import (
        add_repeat_argument,
        ensure_parent,
        materialize_dummy_context,
        materialize_dummy_packet,
    )
except ImportError:
    from corpus.common import (
        add_repeat_argument,
        ensure_parent,
        materialize_dummy_context,
        materialize_dummy_packet,
    )


ROOT_DIR = Path(__file__).resolve().parent.parent
DEFAULT_SUITE = ROOT_DIR / "corpus" / "config" / "macro_corpus.yaml"
DEFAULT_PACKET = ROOT_DIR / "corpus" / "inputs" / "macro_dummy_packet_64.bin"
DEFAULT_CONTEXT = ROOT_DIR / "corpus" / "inputs" / "macro_dummy_context_64.bin"
DEFAULT_BTF_CANDIDATES = (
    Path("/sys/kernel/btf/vmlinux"),
    ROOT_DIR / "vendor" / "linux-framework" / "vmlinux",
    ROOT_DIR / "vendor" / "linux" / "vmlinux",
)
DEFAULT_OUTPUT = ROOT_DIR / "corpus" / "results" / "macro_corpus.latest.json"
DEFAULT_RUNNER = ROOT_DIR / "micro" / "build" / "runner" / "micro_exec"
DEFAULT_SCANNER = ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"
DEFAULT_BPFTOOL = "bpftool"
ZERO_DIRECTIVE_SCAN = {
    "cmov_sites": 0,
    "wide_sites": 0,
    "rotate_sites": 0,
    "lea_sites": 0,
    "bitfield_sites": 0,
    "zero_ext_sites": 0,
    "endian_sites": 0,
    "branch_flip_sites": 0,
    "total_sites": 0,
}


@dataclass(frozen=True)
class RuntimeSpec:
    name: str
    label: str
    mode: str


@dataclass(frozen=True)
class ProgramSpec:
    name: str
    description: str
    source: Path
    prog_type: str
    test_method: str
    tags: tuple[str, ...]
    sections: tuple[str, ...]
    program_names: tuple[str, ...]
    io_mode: str | None
    test_input: Path | None
    input_size: int | None
    trigger: str | None
    trigger_timeout_seconds: int
    compile_loader: str
    category: str | None = None
    family: str | None = None
    level: str | None = None
    hypothesis: str | None = None
    btf_path: Path | None = None
    recompile_supported: bool = True


@dataclass(frozen=True)
class SuiteSpec:
    suite_name: str
    manifest_path: Path
    output_path: Path
    defaults_iterations: int
    defaults_warmups: int
    defaults_repeat: int
    runner_binary: Path
    bpftool_binary: str
    scanner_binary: Path
    runtimes: tuple[RuntimeSpec, ...]
    programs: tuple[ProgramSpec, ...]


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the declarative macro eBPF corpus.")
    parser.add_argument("--suite", default=str(DEFAULT_SUITE), help="Path to macro corpus YAML.")
    parser.add_argument("--bench", action="append", dest="benches", help="Benchmark name filter.")
    parser.add_argument("--runtime", action="append", dest="runtimes", help="Runtime name filter.")
    parser.add_argument("--iterations", type=int, help="Measured samples per benchmark/runtime pair.")
    parser.add_argument("--warmups", type=int, help="Warmup samples per benchmark/runtime pair.")
    add_repeat_argument(parser, help_text="Inner repeat count for test_run or trigger commands.")
    parser.add_argument("--output", help="Override JSON output path.")
    parser.add_argument("--seed", type=int, default=0, help="Seed used for runtime order shuffling.")
    parser.add_argument("--skip-recompile", action="store_true", help="Only run baseline kernel mode.")
    parser.add_argument("--skip-build", action="store_true", help="Do not build micro_exec when missing.")
    parser.add_argument("--list", action="store_true", help="List configured benchmarks and runtimes.")
    parser.add_argument("--no-sudo-reexec", action="store_true", help="Do not automatically re-exec under sudo.")
    return parser.parse_args(argv)


def maybe_reexec_as_root(args: argparse.Namespace) -> None:
    if args.no_sudo_reexec or os.geteuid() == 0:
        return
    probe = subprocess.run(["sudo", "-n", "true"], capture_output=True, text=True)
    if probe.returncode != 0:
        raise SystemExit("macro corpus runner requires root or passwordless sudo")
    os.execvp("sudo", ["sudo", "-n", sys.executable, *sys.argv])


def ns_summary(values: list[int]) -> dict[str, float | int | None]:
    if not values:
        return {
            "count": 0,
            "mean": None,
            "median": None,
            "min": None,
            "max": None,
            "p95": None,
            "stdev": None,
        }

    sorted_values = sorted(values)
    p95_index = min(len(sorted_values) - 1, math.ceil(len(sorted_values) * 0.95) - 1)
    return {
        "count": len(values),
        "mean": statistics.mean(values),
        "median": statistics.median(values),
        "min": sorted_values[0],
        "max": sorted_values[-1],
        "p95": sorted_values[p95_index],
        "stdev": statistics.stdev(values) if len(values) > 1 else 0,
    }


def summarize_phase_timings(samples: list[dict[str, Any]]) -> dict[str, dict[str, float | int | None]]:
    buckets: dict[str, list[int]] = {}
    for sample in samples:
        for name, value in sample.get("phases_ns", {}).items():
            buckets.setdefault(str(name), []).append(int(value))
    return {name: ns_summary(values) for name, values in buckets.items()}


def summarize_optional_ns(samples: list[dict[str, Any]], field_name: str) -> dict[str, float | int | None] | None:
    values = [int(sample[field_name]) for sample in samples if sample.get(field_name) is not None]
    if not values:
        return None
    return ns_summary(values)


def summarize_code_size(samples: list[dict[str, Any]]) -> dict[str, dict[str, float | int | None]]:
    buckets: dict[str, list[float | int]] = {}
    for sample in samples:
        code_size = sample.get("code_size", {})
        if not isinstance(code_size, dict):
            continue
        for name in ("bpf_bytecode_bytes", "native_code_bytes", "inflation_ratio"):
            value = code_size.get(name)
            if value is None:
                continue
            buckets.setdefault(name, []).append(value)

    return {
        name: ns_summary([int(value) for value in values]) if name != "inflation_ratio" else float_summary(values)
        for name, values in buckets.items()
    }


def float_summary(values: list[float | int]) -> dict[str, float | int | None]:
    if not values:
        return {
            "count": 0,
            "mean": None,
            "median": None,
            "min": None,
            "max": None,
            "p95": None,
            "stdev": None,
        }
    sorted_values = sorted(float(value) for value in values)
    p95_index = min(len(sorted_values) - 1, math.ceil(len(sorted_values) * 0.95) - 1)
    return {
        "count": len(sorted_values),
        "mean": statistics.mean(sorted_values),
        "median": statistics.median(sorted_values),
        "min": sorted_values[0],
        "max": sorted_values[-1],
        "p95": sorted_values[p95_index],
        "stdev": statistics.stdev(sorted_values) if len(sorted_values) > 1 else 0,
    }


def parse_runner_json(stdout: str) -> dict[str, Any]:
    lines = [line.strip() for line in stdout.splitlines() if line.strip()]
    if not lines:
        raise RuntimeError("runner produced no output")
    return json.loads(lines[-1])


def run_text_command(
    command: list[str],
    *,
    timeout_seconds: int = 180,
    pass_fds: tuple[int, ...] = (),
) -> subprocess.CompletedProcess[str]:
    completed = subprocess.run(
        command,
        cwd=ROOT_DIR,
        capture_output=True,
        text=True,
        timeout=timeout_seconds,
        pass_fds=pass_fds,
    )
    if completed.returncode != 0:
        details = (completed.stderr or completed.stdout).strip()
        raise RuntimeError(f"command failed ({completed.returncode}): {' '.join(command)}\n{details}")
    return completed


def maybe_build_runner(suite: SuiteSpec, skip_build: bool) -> None:
    if suite.runner_binary.exists():
        return
    if skip_build:
        raise SystemExit(f"runner binary missing: {suite.runner_binary}")
    completed = subprocess.run(["make", "-C", "micro", "micro_exec"], cwd=ROOT_DIR, text=True)
    if completed.returncode != 0:
        raise SystemExit("failed to build micro_exec")


def detect_btf_path(preferred: Path | None = None) -> Path | None:
    candidates: list[Path] = []
    if preferred is not None:
        candidates.append(preferred)
    for candidate in DEFAULT_BTF_CANDIDATES:
        if candidate not in candidates:
            candidates.append(candidate)
    for candidate in candidates:
        if candidate.exists():
            return candidate
    return None


def load_suite(path: Path, output_override: str | None) -> SuiteSpec:
    manifest = load_catalog(path)
    runtimes = tuple(
        RuntimeSpec(
            name=runtime.name,
            label=runtime.label,
            mode=runtime.mode,
        )
        for runtime in manifest.runtimes
    )
    programs = [
        ProgramSpec(
            name=target.name,
            description=target.description,
            source=target.object_path,
            prog_type=str(target.prog_type or "unknown"),
            test_method=str(target.test_method or "compile_only"),
            tags=tuple(target.tags),
            sections=tuple(target.sections),
            program_names=tuple(target.program_names),
            io_mode=target.io_mode,
            test_input=target.input_path,
            input_size=target.input_size,
            trigger=target.trigger,
            trigger_timeout_seconds=int(target.trigger_timeout_seconds or 30),
            compile_loader=str(target.compile_loader or "micro_exec"),
            category=target.category,
            family=target.family,
            level=target.level,
            hypothesis=target.hypothesis,
            btf_path=target.metadata.get("btf_path") if isinstance(target.metadata.get("btf_path"), Path) else None,
            recompile_supported=bool(target.metadata.get("recompile_supported", True)),
        )
        for target in manifest.targets
    ]

    output_path = Path(output_override or manifest.defaults.output or DEFAULT_OUTPUT)
    if not output_path.is_absolute():
        output_path = (ROOT_DIR / output_path).resolve()

    runner_binary = Path(manifest.build.runner_binary or DEFAULT_RUNNER)
    if not runner_binary.is_absolute():
        runner_binary = (ROOT_DIR / runner_binary).resolve()
    scanner_binary = Path(manifest.build.scanner_binary or DEFAULT_SCANNER)
    if not scanner_binary.is_absolute():
        scanner_binary = (ROOT_DIR / scanner_binary).resolve()

    return SuiteSpec(
        suite_name=manifest.suite_name,
        manifest_path=manifest.manifest_path,
        output_path=output_path,
        defaults_iterations=int(manifest.defaults.iterations or 5),
        defaults_warmups=int(manifest.defaults.warmups or 1),
        defaults_repeat=int(manifest.defaults.repeat or 50),
        runner_binary=runner_binary,
        bpftool_binary=str(manifest.build.bpftool_binary or DEFAULT_BPFTOOL),
        scanner_binary=scanner_binary,
        runtimes=runtimes,
        programs=tuple(programs),
    )


def list_suite(suite: SuiteSpec) -> None:
    print("Benchmarks")
    print("----------")
    for program in suite.programs:
        tags = ",".join(program.tags)
        print(f"{program.name:26} {program.test_method:18} {program.prog_type:12} {tags}")
    print()
    print("Runtimes")
    print("--------")
    for runtime in suite.runtimes:
        print(f"{runtime.name:20} {runtime.label}")


def select_programs(programs: tuple[ProgramSpec, ...], names: list[str] | None) -> list[ProgramSpec]:
    if not names:
        return list(programs)
    selected = []
    by_name = {program.name: program for program in programs}
    for name in names:
        program = by_name.get(name)
        if program is None:
            raise SystemExit(f"unknown benchmark: {name}")
        selected.append(program)
    return selected


def select_runtimes(runtimes: tuple[RuntimeSpec, ...], names: list[str] | None) -> list[RuntimeSpec]:
    if not names:
        return list(runtimes)
    by_name = {runtime.name: runtime for runtime in runtimes}
    selected = []
    for name in names:
        runtime = by_name.get(name)
        if runtime is None:
            raise SystemExit(f"unknown runtime: {name}")
        selected.append(runtime)
    return selected


def discover_program_inventory(runner: Path, object_path: Path) -> list[dict[str, Any]]:
    return [
        {
            "name": entry.name,
            "section_name": entry.section_name,
            "insn_count": entry.insn_count,
            "prog_type": entry.prog_type,
            "expected_attach_type": entry.expected_attach_type,
            "prog_type_name": entry.prog_type_name,
            "attach_type_name": entry.attach_type_name,
        }
        for entry in discover_object_programs(runner, object_path)
    ]


def program_matches(spec: ProgramSpec, program: dict[str, Any]) -> bool:
    name = str(program.get("name", ""))
    section_name = str(program.get("section_name", ""))
    if spec.program_names and name not in spec.program_names:
        return False
    if spec.sections:
        if section_name in spec.sections:
            return True
        root = section_name.split("/", 1)[0]
        return root in spec.sections
    return not spec.program_names or name in spec.program_names


def choose_programs(spec: ProgramSpec, inventory: list[dict[str, Any]]) -> list[dict[str, Any]]:
    selected = [program for program in inventory if program_matches(spec, program)]
    if not selected and spec.program_names:
        raise RuntimeError(f"{spec.name}: none of {spec.program_names} found in {spec.source}")
    if not selected:
        return inventory
    return selected


def default_io_plan(spec: ProgramSpec) -> tuple[str, Path | None, int]:
    root = spec.prog_type
    io_mode = spec.io_mode
    input_path = spec.test_input
    input_size = spec.input_size if spec.input_size is not None else 64

    if io_mode is None:
        if root in {"xdp", "tc", "classifier", "socket", "flow_dissector", "sk_skb", "sk_msg"}:
            io_mode = "packet"
        else:
            io_mode = "context"

    if input_path is None:
        if io_mode == "packet":
            input_path = materialize_dummy_packet(DEFAULT_PACKET)
        elif io_mode == "context":
            input_path = materialize_dummy_context(DEFAULT_CONTEXT, input_size)

    if io_mode == "context" and input_path is not None and input_size <= 0:
        input_size = max(1, input_path.stat().st_size)

    return io_mode, input_path, input_size


def build_runner_command(
    suite: SuiteSpec,
    spec: ProgramSpec,
    program_name: str,
    *,
    repeat: int,
    compile_only: bool,
    recompile_v5: bool,
) -> list[str]:
    io_mode, input_path, input_size = default_io_plan(spec)
    btf_path = detect_btf_path(spec.btf_path)

    command = [
        str(suite.runner_binary),
        "run-kernel",
        "--program",
        str(spec.source),
        "--program-name",
        program_name,
        "--io-mode",
        io_mode,
        "--repeat",
        str(max(1, repeat)),
    ]
    if io_mode == "packet":
        command.append("--raw-packet")
    if input_path is not None:
        command.extend(["--memory", str(input_path)])
    if input_size > 0:
        command.extend(["--input-size", str(input_size)])
    if btf_path is not None:
        command.extend(["--btf-custom-path", str(btf_path)])
    if compile_only:
        command.append("--compile-only")
    if recompile_v5:
        command.extend(["--recompile-v5", "--recompile-all"])
    return command


def run_micro_exec_sample(
    suite: SuiteSpec,
    spec: ProgramSpec,
    program_name: str,
    *,
    repeat: int,
    compile_only: bool,
    recompile_v5: bool,
) -> dict[str, Any]:
    command = build_runner_command(
        suite,
        spec,
        program_name,
        repeat=repeat,
        compile_only=compile_only,
        recompile_v5=recompile_v5,
    )
    started_ns = time.perf_counter_ns()
    completed = run_text_command(command)
    sample = parse_runner_json(completed.stdout)
    sample.setdefault("wall_exec_ns", None)
    sample.setdefault("phases_ns", {})
    sample.setdefault("code_size", {})
    sample["command"] = command
    sample["effective_repeat"] = max(1, repeat)
    sample["runner_wall_ns"] = time.perf_counter_ns() - started_ns
    return sample


def unique_pin_dir(spec_name: str, runtime_name: str, iteration_idx: int) -> Path:
    slug = "".join(ch if ch.isalnum() else "_" for ch in spec_name)
    return Path("/sys/fs/bpf") / f"macro_corpus_{slug}_{runtime_name}_{os.getpid()}_{iteration_idx}"


def bpftool_json(bpftool_binary: str, command: list[str]) -> Any:
    completed = subprocess.run(
        [bpftool_binary, *command],
        cwd=ROOT_DIR,
        capture_output=True,
        text=True,
        timeout=180,
    )
    stdout = completed.stdout.strip()
    if not stdout:
        details = (completed.stderr or completed.stdout).strip()
        raise RuntimeError(
            f"bpftool command failed ({completed.returncode}): {bpftool_binary} {' '.join(command)}\n{details}"
        )

    try:
        payload = json.loads(stdout)
    except json.JSONDecodeError as exc:
        details = (completed.stderr or completed.stdout).strip()
        raise RuntimeError(
            f"bpftool command returned non-JSON output ({completed.returncode}): "
            f"{bpftool_binary} {' '.join(command)}\n{details}"
        ) from exc

    if completed.returncode != 0 and isinstance(payload, dict) and "error" in payload:
        raise RuntimeError(
            f"bpftool command failed ({completed.returncode}): {bpftool_binary} {' '.join(command)}\n{payload['error']}"
        )
    return payload


def attached_programs_for_pin_dir(bpftool_binary: str, pin_dir: Path) -> list[dict[str, Any]]:
    records = []
    if not pin_dir.exists():
        return records
    for path in sorted(pin_dir.iterdir()):
        try:
            link_info = bpftool_json(bpftool_binary, ["-j", "-p", "link", "show", "pinned", str(path)])
            records.append(
                {
                    "pin_path": str(path),
                    "program_name": path.name,
                    "prog_id": int(link_info["prog_id"]),
                    "link_id": int(link_info["id"]),
                    "type": str(link_info["type"]),
                    "attach_type": str(link_info.get("attach_type", "")),
                }
            )
        except RuntimeError as exc:
            if "incorrect object type: prog" not in str(exc):
                raise
            prog_info = bpftool_json(bpftool_binary, ["-j", "-p", "prog", "show", "pinned", str(path)])
            if isinstance(prog_info, list):
                if len(prog_info) != 1:
                    raise RuntimeError(f"unexpected pinned program payload for {path}")
                prog_info = prog_info[0]
            records.append(
                {
                    "pin_path": str(path),
                    "program_name": path.name,
                    "prog_id": int(prog_info["id"]),
                    "link_id": None,
                    "type": str(prog_info.get("type", "")),
                    "attach_type": str(prog_info.get("attach_type", "")),
                }
            )
    return records


def pinned_programs_for_pin_dir(bpftool_binary: str, pin_dir: Path) -> list[dict[str, Any]]:
    records = []
    if not pin_dir.exists():
        return records
    for path in sorted(pin_dir.iterdir()):
        prog_info = bpftool_json(bpftool_binary, ["-j", "-p", "prog", "show", "pinned", str(path)])
        if isinstance(prog_info, list):
            if len(prog_info) != 1:
                raise RuntimeError(f"unexpected pinned program payload for {path}")
            prog_info = prog_info[0]
        records.append(
            {
                "pin_path": str(path),
                "program_name": path.name,
                "prog_id": int(prog_info["id"]),
                "type": str(prog_info.get("type", "")),
                "attach_type": str(prog_info.get("attach_type", "")),
            }
        )
    return records


def program_info_by_id(bpftool_binary: str, prog_id: int) -> dict[str, Any]:
    payload = bpftool_json(bpftool_binary, ["-j", "-p", "prog", "show", "id", str(prog_id)])
    if isinstance(payload, list):
        if len(payload) != 1:
            raise RuntimeError(f"unexpected prog info payload for id {prog_id}")
        return payload[0]
    return payload


def aggregate_program_infos(infos: list[dict[str, Any]]) -> dict[str, Any]:
    bytes_xlated = sum(int(info.get("bytes_xlated", 0)) for info in infos)
    bytes_jited = sum(int(info.get("bytes_jited", 0)) for info in infos)
    ratio = None if bytes_xlated == 0 else bytes_jited / bytes_xlated
    return {
        "bpf_bytecode_bytes": bytes_xlated,
        "native_code_bytes": bytes_jited,
        "inflation_ratio": ratio,
        "per_program": infos,
    }


def run_trigger_command(command_text: str, repeat: int, timeout_seconds: int) -> dict[str, Any]:
    started_ns = time.perf_counter_ns()
    returncodes: list[int] = []
    stderr_chunks: list[str] = []
    stdout_chunks: list[str] = []

    for _ in range(max(1, repeat)):
        completed = subprocess.run(
            ["/bin/bash", "-lc", command_text],
            cwd=ROOT_DIR,
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
        )
        returncodes.append(int(completed.returncode))
        if completed.stdout:
            stdout_chunks.append(completed.stdout.strip())
        if completed.stderr:
            stderr_chunks.append(completed.stderr.strip())

    wall_ns = time.perf_counter_ns() - started_ns
    avg_ns = wall_ns // max(1, repeat)
    return {
        "returncode": returncodes[-1] if returncodes else 0,
        "returncodes": returncodes,
        "wall_exec_ns": wall_ns,
        "exec_ns": avg_ns,
        "stdout_tail": "\n".join(text for text in stdout_chunks if text)[-4000:],
        "stderr_tail": "\n".join(text for text in stderr_chunks if text)[-4000:],
    }


def _apply_one_v5_enumerate(
    scanner_binary: Path,
    prog_id: int,
) -> tuple[str, str, str, str]:
    """Run scanner enumerate --prog-id --recompile for one program."""
    command = [
        str(scanner_binary),
        "enumerate",
        "--prog-id",
        str(prog_id),
        "--all",
        "--recompile",
        "--json",
    ]
    command_str = " ".join(command)
    try:
        completed = subprocess.run(
            command,
            capture_output=True,
            text=True,
            timeout=60,
        )
    except Exception as exc:
        return ("", "", command_str, str(exc))
    if completed.returncode != 0:
        detail = (completed.stderr or completed.stdout or "").strip()
        return (
            completed.stdout.strip()[-4000:],
            completed.stderr.strip()[-4000:],
            command_str,
            detail or f"enumerate --prog-id {prog_id} --recompile failed (rc={completed.returncode})",
        )
    return (
        completed.stdout.strip()[-4000:],
        completed.stderr.strip()[-4000:],
        command_str,
        "",
    )


def apply_recompile_v5(scanner_binary: Path, attached: list[dict[str, Any]]) -> dict[str, Any]:
    total_ns = 0
    details = []
    errors: list[str] = []
    for entry in attached:
        prog_id = int(entry["prog_id"])
        program_name = entry["program_name"]
        started_ns = time.perf_counter_ns()
        stdout_text, stderr_text, command_str, error_text = _apply_one_v5_enumerate(
            scanner_binary, prog_id
        )
        wall_ns = time.perf_counter_ns() - started_ns
        total_ns += wall_ns
        if error_text:
            errors.append(f"{program_name}: {error_text}")
        details.append(
            {
                "program_name": program_name,
                "prog_id": entry["prog_id"],
                "scanner_command": command_str,
                "stdout": stdout_text,
                "stderr": stderr_text,
                "wall_ns": wall_ns,
                "error": error_text,
            }
        )
    return {
        "applied": len(attached) > 0 and not errors,
        "wall_ns": total_ns,
        "details": details,
        "error": "; ".join(errors),
    }


def run_attach_trigger_sample(
    suite: SuiteSpec,
    spec: ProgramSpec,
    *,
    repeat: int,
    recompile_v5: bool,
    iteration_idx: int,
) -> dict[str, Any]:
    if not spec.trigger:
        raise RuntimeError(f"{spec.name}: attach_trigger requires a trigger command")

    pin_dir = unique_pin_dir(spec.name, "kernel_recompile_v5" if recompile_v5 else "kernel", iteration_idx)
    btf_path = detect_btf_path(spec.btf_path)
    load_command = [suite.bpftool_binary, "prog", "loadall", str(spec.source), str(pin_dir)]
    if btf_path is not None:
        load_command.extend(["kernel_btf", str(btf_path)])
    load_command.append("autoattach")

    started_ns = time.perf_counter_ns()
    recompile_record = {
        "requested": recompile_v5,
        "mode": "auto-scan-v5" if recompile_v5 else "none",
        "policy_generated": False,
        "policy_bytes": 0,
        "syscall_attempted": False,
        "applied": False,
        "error": "",
    }
    try:
        run_text_command(load_command)
        load_ns = time.perf_counter_ns() - started_ns
        attached = attached_programs_for_pin_dir(suite.bpftool_binary, pin_dir)
        if spec.program_names:
            attached = [entry for entry in attached if entry["program_name"] in spec.program_names]
        if not attached:
            raise RuntimeError(f"{spec.name}: no attached programs found under {pin_dir}")

        recompile_ns = 0
        apply_info = None
        if recompile_v5:
            recompile_record["policy_generated"] = True
            recompile_record["syscall_attempted"] = True
            apply_info = apply_recompile_v5(suite.scanner_binary, attached)
            recompile_ns = int(apply_info["wall_ns"])
            recompile_record["applied"] = bool(apply_info["applied"])
            recompile_record["error"] = str(apply_info.get("error", ""))

        infos = [program_info_by_id(suite.bpftool_binary, int(entry["prog_id"])) for entry in attached]
        code_size = aggregate_program_infos(infos)
        trigger = run_trigger_command(spec.trigger, repeat, spec.trigger_timeout_seconds)
        sample = {
            "compile_ns": load_ns + recompile_ns,
            "exec_ns": trigger["exec_ns"],
            "wall_exec_ns": trigger["wall_exec_ns"],
            "timing_source": "wall_clock",
            "result": trigger["returncode"],
            "retval": trigger["returncode"],
            "code_size": code_size,
            "phases_ns": {
                "object_load_ns": load_ns,
                "trigger_total_ns": trigger["wall_exec_ns"],
            },
            "perf_counters": {},
            "perf_counters_meta": {
                "requested": False,
                "collected": False,
                "include_kernel": False,
                "scope": "full_repeat_raw",
                "error": "",
            },
            "directive_scan": {
                "performed": recompile_v5,
                **ZERO_DIRECTIVE_SCAN,
            },
            "recompile": recompile_record,
            "attached_programs": attached,
            "trigger": {
                "command": spec.trigger,
                "returncodes": trigger["returncodes"],
                "stdout_tail": trigger["stdout_tail"],
                "stderr_tail": trigger["stderr_tail"],
            },
            "effective_repeat": max(1, repeat),
            "bpftool_command": load_command,
        }
        if apply_info is not None:
            sample["phases_ns"]["recompile_apply_ns"] = recompile_ns
            sample["recompile"]["details"] = apply_info["details"]
        return sample
    except Exception as exc:
        recompile_record["error"] = str(exc)
        raise
    finally:
        subprocess.run(["rm", "-rf", str(pin_dir)], cwd=ROOT_DIR, capture_output=True, text=True, check=False)


def run_compile_only_loadall_sample(
    suite: SuiteSpec,
    spec: ProgramSpec,
    *,
    recompile_v5: bool,
    iteration_idx: int,
) -> dict[str, Any]:
    pin_dir = unique_pin_dir(spec.name, "kernel_recompile_v5" if recompile_v5 else "kernel", iteration_idx)
    btf_path = detect_btf_path(spec.btf_path)
    load_command = [suite.bpftool_binary, "prog", "loadall", str(spec.source), str(pin_dir)]
    if btf_path is not None:
        load_command.extend(["kernel_btf", str(btf_path)])

    recompile_record = {
        "requested": recompile_v5,
        "mode": "auto-scan-v5" if recompile_v5 else "none",
        "policy_generated": False,
        "policy_bytes": 0,
        "syscall_attempted": False,
        "applied": False,
        "error": "",
    }

    started_ns = time.perf_counter_ns()
    try:
        run_text_command(load_command)
        load_ns = time.perf_counter_ns() - started_ns
        pinned = pinned_programs_for_pin_dir(suite.bpftool_binary, pin_dir)
        if spec.program_names:
            pinned = [entry for entry in pinned if entry["program_name"] in spec.program_names]
        if not pinned:
            raise RuntimeError(f"{spec.name}: no pinned programs found under {pin_dir}")

        recompile_ns = 0
        apply_info = None
        if recompile_v5:
            recompile_record["policy_generated"] = True
            recompile_record["syscall_attempted"] = True
            apply_info = apply_recompile_v5(suite.scanner_binary, pinned)
            recompile_ns = int(apply_info["wall_ns"])
            recompile_record["applied"] = bool(apply_info["applied"])
            recompile_record["error"] = str(apply_info.get("error", ""))

        infos = [program_info_by_id(suite.bpftool_binary, int(entry["prog_id"])) for entry in pinned]
        code_size = aggregate_program_infos(infos)
        sample = {
            "compile_ns": load_ns + recompile_ns,
            "exec_ns": 0,
            "wall_exec_ns": 0,
            "timing_source": "none",
            "result": 0,
            "retval": 0,
            "code_size": code_size,
            "phases_ns": {
                "object_load_ns": load_ns,
            },
            "perf_counters": {},
            "perf_counters_meta": {
                "requested": False,
                "collected": False,
                "include_kernel": False,
                "scope": "full_repeat_raw",
                "error": "",
            },
            "directive_scan": {
                "performed": recompile_v5,
                **ZERO_DIRECTIVE_SCAN,
            },
            "recompile": recompile_record,
            "pinned_programs": pinned,
            "effective_repeat": 1,
            "bpftool_command": load_command,
        }
        if apply_info is not None:
            sample["phases_ns"]["recompile_apply_ns"] = recompile_ns
            sample["recompile"]["details"] = apply_info["details"]
        return sample
    finally:
        subprocess.run(["rm", "-rf", str(pin_dir)], cwd=ROOT_DIR, capture_output=True, text=True, check=False)


def execute_sample(
    suite: SuiteSpec,
    spec: ProgramSpec,
    runtime: RuntimeSpec,
    *,
    repeat: int,
    iteration_idx: int,
) -> dict[str, Any]:
    recompile_v5 = runtime.mode == "kernel-recompile-v5"
    if recompile_v5 and not spec.recompile_supported:
        raise RuntimeError(f"{spec.name}: runtime {runtime.name} disabled by config")

    inventory = discover_program_inventory(suite.runner_binary, spec.source)
    selected = choose_programs(spec, inventory)
    if spec.test_method == "attach_trigger":
        return run_attach_trigger_sample(
            suite,
            spec,
            repeat=repeat,
            recompile_v5=recompile_v5,
            iteration_idx=iteration_idx,
        )

    compile_only = spec.test_method == "compile_only"
    if compile_only and spec.compile_loader == "bpftool_loadall":
        return run_compile_only_loadall_sample(
            suite,
            spec,
            recompile_v5=recompile_v5,
            iteration_idx=iteration_idx,
        )

    if len(selected) != 1:
        raise RuntimeError(f"{spec.name}: expected exactly one selected program, found {len(selected)}")
    program_name = str(selected[0]["name"])
    return run_micro_exec_sample(
        suite,
        spec,
        program_name,
        repeat=repeat,
        compile_only=compile_only,
        recompile_v5=recompile_v5,
    )


def runtimes_require_recompile_support(runtimes: list[RuntimeSpec]) -> bool:
    return any(runtime.mode == "kernel-recompile-v5" for runtime in runtimes)


def host_metadata() -> dict[str, Any]:
    return {
        "hostname": platform.node(),
        "kernel_release": platform.release(),
        "kernel_version": platform.version(),
        "machine": platform.machine(),
        "arch": platform.architecture()[0],
        "euid": os.geteuid(),
        "python": sys.version.split()[0],
    }


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    suite = load_suite(Path(args.suite).resolve(), args.output)

    if args.list:
        list_suite(suite)
        return 0

    benchmarks = select_programs(suite.programs, args.benches)
    runtimes = select_runtimes(suite.runtimes, args.runtimes)
    if args.skip_recompile:
        runtimes = [runtime for runtime in runtimes if runtime.mode != "kernel-recompile-v5"]
    if not runtimes:
        raise SystemExit("no runtimes selected")

    maybe_build_runner(suite, args.skip_build)

    needs_recompile_support = runtimes_require_recompile_support(runtimes)
    if needs_recompile_support and not suite.scanner_binary.exists():
        raise SystemExit(f"scanner binary missing: {suite.scanner_binary}")

    maybe_reexec_as_root(args)

    iterations = args.iterations if args.iterations is not None else suite.defaults_iterations
    warmups = args.warmups if args.warmups is not None else suite.defaults_warmups
    repeat = args.repeat if args.repeat is not None else suite.defaults_repeat

    results = {
        "suite_name": suite.suite_name,
        "manifest_path": str(suite.manifest_path),
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "host": host_metadata(),
        "defaults": {
            "iterations": iterations,
            "warmups": warmups,
            "repeat": repeat,
            "seed": args.seed,
        },
        "benchmarks": [],
    }

    rng = random.Random(args.seed)
    for spec in benchmarks:
        inventory = discover_program_inventory(suite.runner_binary, spec.source)
        selected_inventory = choose_programs(spec, inventory)
        benchmark_record = {
            "name": spec.name,
            "description": spec.description,
            "category": spec.category or spec.prog_type,
            "family": spec.family,
            "level": spec.level,
            "hypothesis": spec.hypothesis,
            "prog_type": spec.prog_type,
            "test_method": spec.test_method,
            "tags": list(spec.tags),
            "artifacts": {
                "program_object": str(spec.source),
                "test_input": str(spec.test_input) if spec.test_input else None,
            },
            "program_inventory": inventory,
            "selected_programs": selected_inventory,
            "runs": [],
        }

        runtime_order = list(runtimes)
        rng.shuffle(runtime_order)

        for runtime in runtime_order:
            print(f"[bench] {spec.name} [{runtime.name}]")
            for _ in range(warmups):
                execute_sample(
                    suite,
                    spec,
                    runtime,
                    repeat=repeat,
                    iteration_idx=-1,
                )

            samples = []
            for iteration_idx in range(iterations):
                sample = execute_sample(
                    suite,
                    spec,
                    runtime,
                    repeat=repeat,
                    iteration_idx=iteration_idx,
                )
                sample["iteration_index"] = iteration_idx
                samples.append(sample)

            compile_values = [int(sample["compile_ns"]) for sample in samples]
            exec_values = [int(sample["exec_ns"]) for sample in samples]
            result_values = [sample.get("result") for sample in samples]
            run_record = {
                "runtime": runtime.name,
                "label": runtime.label,
                "mode": runtime.mode,
                "repeat": repeat,
                "effective_repeat": max(1, repeat) if spec.test_method in {"bpf_prog_test_run", "attach_trigger"} else 1,
                "artifacts": {
                    "program_object": str(spec.source),
                },
                "samples": samples,
                "compile_ns": ns_summary(compile_values),
                "exec_ns": ns_summary(exec_values),
                "timing_source": str(samples[0].get("timing_source", "unknown")) if samples else "unknown",
                "phases_ns": summarize_phase_timings(samples),
                "perf_counters": {},
                "perf_counters_meta": {
                    "requested": False,
                    "collected_samples": 0,
                    "include_kernel": False,
                    "scope": "full_repeat_raw",
                    "hardware_counters_observed": False,
                    "software_counters_observed": False,
                    "errors": {},
                },
                "derived_metrics": {},
                "result_distribution": dict(Counter(str(value) for value in result_values)),
                "code_size": summarize_code_size(samples),
            }
            wall_exec_summary = summarize_optional_ns(samples, "wall_exec_ns")
            if wall_exec_summary is not None:
                run_record["wall_exec_ns"] = wall_exec_summary
            benchmark_record["runs"].append(run_record)
            print(
                f"  compile median {run_record['compile_ns']['median']} ns | "
                f"exec median {run_record['exec_ns']['median']} ns"
            )

        results["benchmarks"].append(benchmark_record)

    output_path = suite.output_path
    latest_alias_path: Path | None = None
    if output_path.name.endswith(".latest.json"):
        suite_name = output_path.name[: -len(".latest.json")]
        output_path = output_path.parent / f"{suite_name}_authoritative_{results['generated_at'][:10].replace('-', '')}.json"
        latest_alias_path = suite.output_path

    ensure_parent(output_path)
    output_path.write_text(json.dumps(results, indent=2) + "\n")
    if latest_alias_path is not None:
        refresh_latest_alias(latest_alias_path, output_path)
    else:
        maybe_refresh_latest_alias(output_path)
    print(f"[done] wrote {output_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
