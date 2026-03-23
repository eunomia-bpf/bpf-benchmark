#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import platform
import random
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
    from results_layout import authoritative_output_path
except ImportError:
    from corpus.results_layout import authoritative_output_path

try:
    from runner.libs.catalog import load_catalog
    from runner.libs.corpus import (
        add_repeat_argument,
        ensure_parent,
        materialize_dummy_context,
        materialize_dummy_packet,
        materialize_katran_packet,
    )
    from runner.libs.inventory import discover_object_programs
    from runner.libs.results import (
        float_summary,
        ns_summary,
        parse_runner_sample,
        summarize_optional_ns,
        summarize_phase_timings,
    )
    from runner.libs.run_artifacts import (
        create_run_artifact_dir,
        derive_run_type,
        extract_daemon_debug_details,
        repo_relative_path,
        result_root_for_output,
        summarize_benchmark_results,
        update_run_artifact,
    )
except ImportError:
    from runner.libs.catalog import load_catalog
    from runner.libs.corpus import (
        add_repeat_argument,
        ensure_parent,
        materialize_dummy_context,
        materialize_dummy_packet,
        materialize_katran_packet,
    )
    from runner.libs.inventory import discover_object_programs
    from runner.libs.results import (
        float_summary,
        ns_summary,
        parse_runner_sample,
        summarize_optional_ns,
        summarize_phase_timings,
    )
    from runner.libs.run_artifacts import (
        create_run_artifact_dir,
        derive_run_type,
        extract_daemon_debug_details,
        repo_relative_path,
        result_root_for_output,
        summarize_benchmark_results,
        update_run_artifact,
    )

from runner.libs.attach import (
    attach_cgroup_skb,
    attach_cgroup_sysctl,
    attach_fentry,
    attach_fexit,
    attach_kprobe,
    attach_lsm,
    attach_perf_event,
    attach_raw_tracepoint,
    attach_socket_filter,
    attach_tracepoint,
    bpf_obj_get,
    detach_cgroup_skb,
    detach_cgroup_sysctl,
    managed_attachments,
    parse_section_attach_info,
)
from runner.libs.metrics import (
    enable_bpf_stats,
    sample_bpf_stats,
    compute_delta,
)
ROOT_DIR = Path(__file__).resolve().parent.parent
DEFAULT_SUITE = ROOT_DIR / "corpus" / "config" / "macro_corpus.yaml"
DEFAULT_PACKET = ROOT_DIR / "corpus" / "inputs" / "macro_dummy_packet_64.bin"
DEFAULT_KATRAN_PACKET = ROOT_DIR / "corpus" / "inputs" / "katran_vip_packet_64.bin"
DEFAULT_CONTEXT = ROOT_DIR / "corpus" / "inputs" / "macro_dummy_context_64.bin"
DEFAULT_BTF_CANDIDATES = (
    Path("/sys/kernel/btf/vmlinux"),
    ROOT_DIR / "vendor" / "linux-framework" / "vmlinux",
    ROOT_DIR / "vendor" / "linux" / "vmlinux",
)
DEFAULT_OUTPUT = authoritative_output_path(ROOT_DIR / "corpus" / "results", "macro_corpus")
DEFAULT_RUNNER = ROOT_DIR / "runner" / "build" / "micro_exec"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_BPFTOOL = "bpftool"
ZERO_DIRECTIVE_SCAN = {
    "cmov_sites": 0,
    "wide_sites": 0,
    "rotate_sites": 0,
    "lea_sites": 0,
    "bitfield_sites": 0,
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
    daemon_binary: Path
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
    parser.add_argument("--skip-build", action="store_true", help="Do not build micro_exec when missing.")
    parser.add_argument("--list", action="store_true", help="List configured benchmarks and runtimes.")
    parser.add_argument(
        "--daemon-socket",
        default=None,
        help=(
            "Path to a Unix socket for a running bpfrejit-daemon serve instance. "
            "When set, micro_exec connects to the daemon over the socket instead of "
            "forking a new process for each optimization."
        ),
    )
    return parser.parse_args(argv)


def maybe_reexec_as_root(args: argparse.Namespace) -> None:
    """No-op: VM guests are already root, host does not run BPF operations."""
    return


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


def kernel_btf_unsupported(error_text: str) -> bool:
    haystack = error_text.lower()
    if "kernel_btf" not in haystack:
        return False
    needles = (
        "expected no more arguments",
        "unknown option",
        "unrecognized option",
        "invalid argument",
    )
    return any(needle in haystack for needle in needles)


def run_bpftool_loadall(
    suite: SuiteSpec,
    spec: ProgramSpec,
    pin_dir: Path,
    *,
    suffix_args: tuple[str, ...] = (),
    timeout_seconds: int = 180,
) -> tuple[list[str], list[dict[str, Any]]]:
    btf_path = detect_btf_path(spec.btf_path)
    base_command = [suite.bpftool_binary, "prog", "loadall", str(spec.source), str(pin_dir)]
    commands: list[tuple[list[str], bool]] = []
    if btf_path is not None:
        commands.append(([*base_command, "kernel_btf", str(btf_path), *suffix_args], True))
    commands.append(([*base_command, *suffix_args], False))

    attempts: list[dict[str, Any]] = []
    for index, (command, used_kernel_btf) in enumerate(commands):
        try:
            run_text_command(command, timeout_seconds=timeout_seconds)
            attempts.append(
                {
                    "command": command,
                    "used_kernel_btf": used_kernel_btf,
                    "fallback_retry": index > 0,
                    "ok": True,
                    "error": "",
                }
            )
            return command, attempts
        except RuntimeError as exc:
            error_text = str(exc)
            attempts.append(
                {
                    "command": command,
                    "used_kernel_btf": used_kernel_btf,
                    "fallback_retry": index > 0,
                    "ok": False,
                    "error": error_text,
                }
            )
            should_retry = (
                used_kernel_btf
                and index + 1 < len(commands)
                and kernel_btf_unsupported(error_text)
            )
            if not should_retry:
                raise
    raise RuntimeError("bpftool prog loadall failed without an actionable error")


def maybe_build_runner(suite: SuiteSpec, skip_build: bool) -> None:
    if suite.runner_binary.exists():
        return
    if skip_build:
        raise SystemExit(f"runner binary missing: {suite.runner_binary}")
    completed = subprocess.run(["make", "-C", "runner", "micro_exec"], cwd=ROOT_DIR, text=True)
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
    daemon_binary = Path(manifest.build.daemon_binary or DEFAULT_DAEMON)
    if not daemon_binary.is_absolute():
        daemon_binary = (ROOT_DIR / daemon_binary).resolve()

    return SuiteSpec(
        suite_name=manifest.suite_name,
        manifest_path=manifest.manifest_path,
        output_path=output_path,
        defaults_iterations=int(manifest.defaults.iterations or 5),
        defaults_warmups=int(manifest.defaults.warmups or 1),
        defaults_repeat=int(manifest.defaults.repeat or 50),
        runner_binary=runner_binary,
        bpftool_binary=str(manifest.build.bpftool_binary or DEFAULT_BPFTOOL),
        daemon_binary=daemon_binary,
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


def build_run_metadata(
    results: dict[str, Any],
    *,
    output_hint: Path,
    run_type: str,
    daemon_debug_entries: int,
) -> dict[str, Any]:
    metadata = summarize_benchmark_results(results)
    metadata["run_type"] = run_type
    metadata["output_hint"] = repo_relative_path(output_hint)
    metadata["paper_summary"]["daemon_debug_entries"] = daemon_debug_entries
    return metadata


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

    if io_mode == "packet" and spec.family == "katran":
        input_path = materialize_katran_packet(input_path or DEFAULT_KATRAN_PACKET)
        input_size = max(input_size, int(input_path.stat().st_size))
    elif input_path is None:
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
    rejit: bool = False,
    daemon_socket: str | None = None,
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
    if rejit:
        command.append("--rejit")
    if daemon_socket is not None:
        command.extend(["--daemon-socket", str(daemon_socket)])
    return command


def run_micro_exec_sample(
    suite: SuiteSpec,
    spec: ProgramSpec,
    program_name: str,
    *,
    repeat: int,
    compile_only: bool,
    rejit: bool = False,
    daemon_socket: str | None = None,
) -> dict[str, Any]:
    command = build_runner_command(
        suite,
        spec,
        program_name,
        repeat=repeat,
        compile_only=compile_only,
        rejit=rejit,
        daemon_socket=daemon_socket,
    )
    started_ns = time.perf_counter_ns()
    completed = run_text_command(command)
    sample = dict(parse_runner_sample(completed.stdout))
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


def run_attach_trigger_sample(
    suite: SuiteSpec,
    spec: ProgramSpec,
    *,
    repeat: int,
    iteration_idx: int,
) -> dict[str, Any]:
    if not spec.trigger:
        raise RuntimeError(f"{spec.name}: attach_trigger requires a trigger command")

    pin_dir = unique_pin_dir(spec.name, "kernel", iteration_idx)

    started_ns = time.perf_counter_ns()
    load_attempts: list[dict[str, Any]] = []
    try:
        load_command, load_attempts = run_bpftool_loadall(
            suite,
            spec,
            pin_dir,
            suffix_args=("autoattach",),
        )
        load_ns = time.perf_counter_ns() - started_ns
        attached = attached_programs_for_pin_dir(suite.bpftool_binary, pin_dir)
        if spec.program_names:
            attached = [entry for entry in attached if entry["program_name"] in spec.program_names]
        if not attached:
            raise RuntimeError(f"{spec.name}: no attached programs found under {pin_dir}")

        infos = [program_info_by_id(suite.bpftool_binary, int(entry["prog_id"])) for entry in attached]
        code_size = aggregate_program_infos(infos)
        trigger = run_trigger_command(spec.trigger, repeat, spec.trigger_timeout_seconds)
        sample = {
            "compile_ns": load_ns,
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
                "performed": False,
                **ZERO_DIRECTIVE_SCAN,
            },
            "attached_programs": attached,
            "trigger": {
                "command": spec.trigger,
                "returncodes": trigger["returncodes"],
                "stdout_tail": trigger["stdout_tail"],
                "stderr_tail": trigger["stderr_tail"],
            },
            "effective_repeat": max(1, repeat),
            "bpftool_command": load_command,
            "bpftool_attempts": load_attempts,
        }
        return sample
    finally:
        subprocess.run(["rm", "-rf", str(pin_dir)], cwd=ROOT_DIR, capture_output=True, text=True, check=False)


def run_compile_only_loadall_sample(
    suite: SuiteSpec,
    spec: ProgramSpec,
    *,
    iteration_idx: int,
) -> dict[str, Any]:
    pin_dir = unique_pin_dir(spec.name, "kernel", iteration_idx)

    started_ns = time.perf_counter_ns()
    load_attempts: list[dict[str, Any]] = []
    try:
        load_command, load_attempts = run_bpftool_loadall(suite, spec, pin_dir)
        load_ns = time.perf_counter_ns() - started_ns
        pinned = pinned_programs_for_pin_dir(suite.bpftool_binary, pin_dir)
        if spec.program_names:
            pinned = [entry for entry in pinned if entry["program_name"] in spec.program_names]
        if not pinned:
            raise RuntimeError(f"{spec.name}: no pinned programs found under {pin_dir}")

        infos = [program_info_by_id(suite.bpftool_binary, int(entry["prog_id"])) for entry in pinned]
        code_size = aggregate_program_infos(infos)
        sample = {
            "compile_ns": load_ns,
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
                "performed": False,
                **ZERO_DIRECTIVE_SCAN,
            },
            "pinned_programs": pinned,
            "effective_repeat": 1,
            "bpftool_command": load_command,
            "bpftool_attempts": load_attempts,
        }
        return sample
    finally:
        subprocess.run(["rm", "-rf", str(pin_dir)], cwd=ROOT_DIR, capture_output=True, text=True, check=False)


def _attach_pinned_program(
    pin_path: str,
    section_name: str,
    prog_fd: int,
) -> int | None:
    """Attach a single pinned program based on its section name.

    Returns the attachment fd (perf_event fd, link fd, or cgroup fd), or
    None if the program type is not supported for manual attachment
    (e.g. uprobes, struct_ops).
    """
    info = parse_section_attach_info(section_name)
    method = info["attach_method"]

    if method == "tracepoint":
        category = info["category"]
        event = info["event"]
        if not category or not event:
            return None
        return attach_tracepoint(prog_fd, category, event)

    if method == "kprobe":
        func_name = info["event"]
        if not func_name:
            return None
        return attach_kprobe(prog_fd, func_name, is_return=False)

    if method == "kretprobe":
        func_name = info["event"]
        if not func_name:
            return None
        return attach_kprobe(prog_fd, func_name, is_return=True)

    if method == "raw_tracepoint":
        tp_name = info["event"]
        if not tp_name:
            return None
        return attach_raw_tracepoint(prog_fd, tp_name)

    if method == "tp_btf":
        # tp_btf programs have BTF-encoded attach info; use link_create
        # with BPF_TRACE_RAW_TP (the kernel resolves the target via BTF)
        from runner.libs.attach import _bpf_link_create, BPF_TRACE_RAW_TP
        return _bpf_link_create(prog_fd, 0, BPF_TRACE_RAW_TP)

    if method == "fentry":
        return attach_fentry(prog_fd)

    if method == "fexit":
        return attach_fexit(prog_fd)

    if method == "lsm":
        return attach_lsm(prog_fd)

    if method == "perf_event":
        return attach_perf_event(prog_fd)

    if method == "cgroup_sysctl":
        return attach_cgroup_sysctl(prog_fd)

    if method == "cgroup_skb":
        egress = info.get("category", "") == "egress"
        return attach_cgroup_skb(prog_fd, egress=egress)

    if method == "socket_filter":
        return attach_socket_filter(prog_fd)

    # uprobes, struct_ops, iter, syscall, and unknown types: skip
    return None


def run_loadall_attach_trigger_sample(
    suite: SuiteSpec,
    spec: ProgramSpec,
    *,
    repeat: int,
    iteration_idx: int,
) -> dict[str, Any]:
    """Load all programs via bpftool loadall, selectively attach chosen
    programs, enable bpf_stats, run trigger, and measure execution time
    via run_time_ns delta.

    This is the general-purpose attach+trigger path for objects that cannot
    use bpftool autoattach (e.g. objects mixing tracepoints with uprobes).
    """
    if not spec.trigger:
        raise RuntimeError(f"{spec.name}: attach_trigger requires a trigger command")

    pin_dir = unique_pin_dir(spec.name, "kernel", iteration_idx)

    started_ns = time.perf_counter_ns()
    load_attempts: list[dict[str, Any]] = []
    attachment_fds: list[int] = []
    prog_fds: list[int] = []
    cgroup_detach_info: list[tuple[int, int, str]] = []  # (cgroup_fd, prog_fd, type) tuples

    try:
        load_command, load_attempts = run_bpftool_loadall(suite, spec, pin_dir)
        load_ns = time.perf_counter_ns() - started_ns

        # Discover pinned programs
        pinned = pinned_programs_for_pin_dir(suite.bpftool_binary, pin_dir)
        if spec.program_names:
            pinned = [entry for entry in pinned if entry["program_name"] in spec.program_names]
        if not pinned:
            raise RuntimeError(f"{spec.name}: no pinned programs found under {pin_dir}")

        # Get program info for code_size
        infos = [program_info_by_id(suite.bpftool_binary, int(entry["prog_id"])) for entry in pinned]
        code_size = aggregate_program_infos(infos)

        # Get the section names for each pinned program from the object inventory
        inventory = discover_program_inventory(suite.runner_binary, spec.source)
        section_by_name = {str(p["name"]): str(p.get("section_name", "")) for p in inventory}

        # Collect prog_ids for bpf_stats
        prog_ids = [int(entry["prog_id"]) for entry in pinned]

        # Open pinned program fds and attach
        attached_programs: list[dict[str, Any]] = []
        for entry in pinned:
            prog_name = str(entry["program_name"])
            pin_path = str(entry["pin_path"])
            section_name = section_by_name.get(prog_name, "")

            try:
                prog_fd = bpf_obj_get(pin_path)
                prog_fds.append(prog_fd)
            except RuntimeError as exc:
                print(f"  [warn] failed to open pinned program {prog_name}: {exc}")
                continue

            try:
                attach_info = parse_section_attach_info(section_name)
                attach_fd = _attach_pinned_program(pin_path, section_name, prog_fd)
                if attach_fd is not None:
                    attached_programs.append({
                        "program_name": prog_name,
                        "prog_id": int(entry["prog_id"]),
                        "section_name": section_name,
                        "attach_method": attach_info["attach_method"],
                    })
                    # Track cgroup attachments separately (need explicit detach + close)
                    if attach_info["attach_method"] == "cgroup_sysctl":
                        cgroup_detach_info.append((attach_fd, prog_fd, "sysctl"))
                    elif attach_info["attach_method"] == "cgroup_skb":
                        egress = attach_info.get("category", "") == "egress"
                        cgroup_detach_info.append((attach_fd, prog_fd, "skb_egress" if egress else "skb_ingress"))
                    else:
                        # perf_event / link / socket fds: auto-detach on close
                        attachment_fds.append(attach_fd)
                else:
                    print(f"  [info] skipping unsupported attach for {prog_name} ({section_name})")
            except RuntimeError as exc:
                print(f"  [warn] failed to attach {prog_name} ({section_name}): {exc}")

        if not attached_programs:
            raise RuntimeError(f"{spec.name}: no programs could be attached")

        # Enable bpf_stats and measure
        with enable_bpf_stats():
            stats_before = sample_bpf_stats(prog_ids)
            trigger = run_trigger_command(spec.trigger, repeat, spec.trigger_timeout_seconds)
            stats_after = sample_bpf_stats(prog_ids)

        delta = compute_delta(stats_before, stats_after)
        summary = delta["summary"]
        total_run_time_ns = int(summary.get("total_run_time_ns", 0) or 0)
        total_events = int(summary.get("total_events", 0) or 0)
        avg_ns = int(summary.get("avg_ns_per_run") or 0) if summary.get("avg_ns_per_run") is not None else 0

        # Use bpf_stats run_time_ns as the authoritative exec timing
        # Fall back to wall-clock trigger time if no events were recorded
        if total_events > 0:
            exec_ns = avg_ns
            timing_source = "bpf_stats"
        else:
            exec_ns = trigger["exec_ns"]
            timing_source = "wall_clock"

        sample = {
            "compile_ns": load_ns,
            "exec_ns": exec_ns,
            "wall_exec_ns": trigger["wall_exec_ns"],
            "timing_source": timing_source,
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
                "performed": False,
                **ZERO_DIRECTIVE_SCAN,
            },
            "bpf_stats": {
                "total_run_time_ns": total_run_time_ns,
                "total_events": total_events,
                "avg_ns_per_run": avg_ns,
                "program_deltas": {
                    str(k): v for k, v in (delta.get("programs") or {}).items()
                },
            },
            "attached_programs": attached_programs,
            "trigger": {
                "command": spec.trigger,
                "returncodes": trigger["returncodes"],
                "stdout_tail": trigger["stdout_tail"],
                "stderr_tail": trigger["stderr_tail"],
            },
            "effective_repeat": max(1, repeat),
            "bpftool_command": load_command,
            "bpftool_attempts": load_attempts,
        }
        return sample
    finally:
        # Detach cgroup programs explicitly and close their fds
        for detach_entry in cgroup_detach_info:
            cgroup_fd, prog_fd, detach_type = detach_entry
            try:
                if detach_type == "sysctl":
                    detach_cgroup_sysctl(cgroup_fd, prog_fd)
                elif detach_type.startswith("skb"):
                    egress = "egress" in detach_type
                    detach_cgroup_skb(cgroup_fd, prog_fd, egress=egress)
            except Exception:
                pass
            try:
                os.close(cgroup_fd)
            except OSError:
                pass

        # Close all perf_event attachment fds (auto-detach on close)
        for fd in attachment_fds:
            try:
                os.close(fd)
            except OSError:
                pass

        # Close prog fds
        for fd in prog_fds:
            try:
                os.close(fd)
            except OSError:
                pass

        # Remove pin directory
        subprocess.run(["rm", "-rf", str(pin_dir)], cwd=ROOT_DIR, capture_output=True, text=True, check=False)


def execute_sample(
    suite: SuiteSpec,
    spec: ProgramSpec,
    runtime: RuntimeSpec,
    *,
    repeat: int,
    iteration_idx: int,
    daemon_socket: str | None = None,
) -> dict[str, Any]:
    inventory = discover_program_inventory(suite.runner_binary, spec.source)
    selected = choose_programs(spec, inventory)
    if spec.test_method == "attach_trigger":
        if spec.compile_loader == "bpftool_loadall":
            return run_loadall_attach_trigger_sample(
                suite,
                spec,
                repeat=repeat,
                iteration_idx=iteration_idx,
            )
        return run_attach_trigger_sample(
            suite,
            spec,
            repeat=repeat,
            iteration_idx=iteration_idx,
        )

    compile_only = spec.test_method == "compile_only"
    if compile_only and spec.compile_loader == "bpftool_loadall":
        return run_compile_only_loadall_sample(
            suite,
            spec,
            iteration_idx=iteration_idx,
        )

    is_rejit_runtime = runtime.mode in {"kernel-rejit", "kernel_rejit"}
    if len(selected) != 1:
        raise RuntimeError(f"{spec.name}: expected exactly one selected program, found {len(selected)}")
    program_name = str(selected[0]["name"])
    return run_micro_exec_sample(
        suite,
        spec,
        program_name,
        repeat=repeat,
        compile_only=compile_only,
        rejit=is_rejit_runtime,
        daemon_socket=daemon_socket if is_rejit_runtime else None,
    )


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


def run_suite(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    suite = load_suite(Path(args.suite).resolve(), args.output)

    if args.list:
        list_suite(suite)
        return 0

    benchmarks = select_programs(suite.programs, args.benches)
    runtimes = select_runtimes(suite.runtimes, args.runtimes)
    if not runtimes:
        raise SystemExit("no runtimes selected")

    maybe_build_runner(suite, args.skip_build)
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

    daemon_socket = getattr(args, "daemon_socket", None)
    output_path = suite.output_path
    run_type = derive_run_type(output_path, suite.suite_name)
    artifact_dir = create_run_artifact_dir(
        results_dir=result_root_for_output(output_path),
        run_type=run_type,
        generated_at=str(results["generated_at"]),
    )
    current_benchmark_name: str | None = None
    current_benchmark_index: int | None = None
    current_benchmark_record: dict[str, Any] | None = None

    def flush_artifact(status: str, *, error_message: str | None = None) -> None:
        artifact_details, daemon_debug_entries = extract_daemon_debug_details(results)
        artifact_details["result.json"] = results
        artifact_details["progress.json"] = {
            "status": status,
            "total_benchmarks": len(benchmarks),
            "completed_benchmarks": len(results["benchmarks"]),
            "current_benchmark_index": current_benchmark_index,
            "current_benchmark": current_benchmark_name,
            "current_benchmark_record": current_benchmark_record,
        }
        if error_message:
            artifact_details["progress.json"]["error_message"] = error_message

        artifact_metadata = build_run_metadata(
            results,
            output_hint=output_path,
            run_type=run_type,
            daemon_debug_entries=daemon_debug_entries,
        )
        updated_at = datetime.now(timezone.utc).isoformat()
        artifact_metadata["status"] = status
        artifact_metadata["started_at"] = results["generated_at"]
        artifact_metadata["last_updated_at"] = updated_at
        artifact_metadata["progress"] = {
            "total_benchmarks": len(benchmarks),
            "completed_benchmarks": len(results["benchmarks"]),
            "current_benchmark_index": current_benchmark_index,
            "current_benchmark": current_benchmark_name,
        }
        if status == "completed":
            artifact_metadata["completed_at"] = updated_at
        if error_message:
            artifact_metadata["error_message"] = error_message

        update_run_artifact(
            run_dir=artifact_dir,
            run_type=run_type,
            metadata=artifact_metadata,
            detail_payloads=artifact_details,
        )

    rng = random.Random(args.seed)
    flush_artifact("running")

    try:
        for bench_idx, spec in enumerate(benchmarks):
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

            current_benchmark_name = spec.name
            current_benchmark_index = bench_idx + 1
            current_benchmark_record = benchmark_record
            flush_artifact("running")

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
                        daemon_socket=daemon_socket,
                    )

                samples = []
                for iteration_idx in range(iterations):
                    sample = execute_sample(
                        suite,
                        spec,
                        runtime,
                        repeat=repeat,
                        iteration_idx=iteration_idx,
                        daemon_socket=daemon_socket,
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
                flush_artifact("running")

            # Cross-runtime correctness check (kernel vs kernel-rejit)
            runtime_results: dict[str, int | None] = {}
            for run in benchmark_record["runs"]:
                samples = run.get("samples", [])
                if samples:
                    result_counts = Counter(sample.get("result") for sample in samples)
                    modal_result = result_counts.most_common(1)[0][0]
                    runtime_results[run["runtime"]] = modal_result
                else:
                    runtime_results[run["runtime"]] = None

            kernel_result = runtime_results.get("kernel")
            rejit_result = runtime_results.get("kernel-rejit")
            if kernel_result is not None and rejit_result is not None and kernel_result != rejit_result:
                print(
                    f"  WARNING: correctness mismatch for {spec.name}: "
                    f"kernel={kernel_result}, kernel-rejit={rejit_result}"
                )
                benchmark_record["correctness_mismatch"] = True
            else:
                benchmark_record["correctness_mismatch"] = False

            results["benchmarks"].append(benchmark_record)
            current_benchmark_record = None
            flush_artifact("running")

        current_benchmark_name = None
        current_benchmark_index = None
        flush_artifact("completed")
    except Exception as exc:
        flush_artifact("error", error_message=str(exc))
        raise

    print(f"[done] wrote {artifact_dir / 'metadata.json'}")
    return 0


MODE_NAMES = {"packet", "tracing", "perf", "code-size"}


def main(argv: list[str] | None = None) -> int:
    raw_args = list(argv if argv is not None else sys.argv[1:])

    if raw_args and raw_args[0] in MODE_NAMES:
        from corpus.modes import packet_main, run_linear_mode  # noqa: F811

        mode_name, *remaining = raw_args
        if mode_name == "packet":
            return packet_main(remaining)
        return run_linear_mode(mode_name, remaining)

    return run_suite(raw_args)


if __name__ == "__main__":
    raise SystemExit(main())
