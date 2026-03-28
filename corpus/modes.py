#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import os
import selectors
import shlex
import statistics
import subprocess
import sys
import tempfile
import time
import traceback
from collections import Counter, defaultdict
from dataclasses import asdict, dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Callable, Mapping

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

from runner.libs import authoritative_output_path, docs_tmp_dir, latest_output_path, smoke_output_path
from runner.libs.batch_runner import run_batch_runner
from runner.libs.object_discovery import supplement_with_existing_corpus_build_objects
from runner.libs.machines import resolve_machine
from runner.libs.vm import DEFAULT_VM_TARGET

from runner.libs.run_artifacts import (
    ArtifactSession,
    derive_run_type,
    repo_relative_path,
)

from runner.libs.corpus import (
    add_filter_argument,
    add_max_programs_argument,
    add_output_json_argument,
    add_output_md_argument,
    add_repeat_argument,
    add_runner_argument,
    add_daemon_argument,
    add_timeout_argument,
    format_ns,
    format_ratio,
    geomean,
    markdown_table,
    require_minimum,
    summarize_text,
    extract_error,
)


import yaml

ROOT_DIR = Path(__file__).resolve().parent.parent
DRIVER_RELATIVE = Path(__file__).with_name("driver.py").resolve().relative_to(ROOT_DIR)
DEFAULT_MACRO_CORPUS_YAML = ROOT_DIR / "corpus" / "config" / "macro_corpus.yaml"
DEFAULT_BENCHMARK_CONFIG_YAML = ROOT_DIR / "corpus" / "config" / "benchmark_config.yaml"
DEFAULT_REJIT_ENABLED_PASSES = ["map_inline", "const_prop", "dce"]
FALLBACK_OUTPUT_JSON = authoritative_output_path(ROOT_DIR / "corpus" / "results", "corpus_vm_batch")
FALLBACK_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "corpus-batch-rejit-results.md"
DEFAULT_RUNNER = ROOT_DIR / "runner" / "build" / "micro_exec"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_KERNEL_TREE = ROOT_DIR / "vendor" / "linux-framework"
DEFAULT_KERNEL_IMAGE = DEFAULT_KERNEL_TREE / "arch" / "x86" / "boot" / "bzImage"
DEFAULT_BTF_PATH = DEFAULT_KERNEL_TREE / "vmlinux"
DEFAULT_CORPUS_BUILD_REPORT = latest_output_path(ROOT_DIR / "corpus" / "results", "expanded_corpus_build")
DEFAULT_VNG_MACHINE = resolve_machine(target=DEFAULT_VM_TARGET, action="vm-corpus")
DEFAULT_VNG = str(Path(DEFAULT_VNG_MACHINE.executable))
FALLBACK_REPEAT = 200
DEFAULT_TIMEOUT_SECONDS = 240
GUEST_BATCH_TARGETS_PER_CHUNK = 1


@dataclass(frozen=True)
class ResolvedProgram:
    source: str
    object_path: str
    object_abs_path: str
    repo: str
    source_name: str
    family: str
    category: str
    level: str
    description: str | None
    hypothesis: str | None
    tags: tuple[str, ...]
    object_relpath: str
    canonical_object_name: str
    object_basename: str
    short_name: str
    program_name: str
    canonical_name: str
    fixture_path: str | None
    test_method: str
    prog_type_name: str
    section_name: str
    io_mode: str
    raw_packet: bool
    input_size: int
    memory_path: str | None
    trigger: str | None
    trigger_timeout_seconds: int | None
    compile_loader: str | None
    attach_group: str | None
    rejit_enabled: bool


@dataclass(frozen=True)
class ResolvedObject:
    source: str
    object_path: str
    object_abs_path: str
    repo: str
    source_name: str
    family: str
    category: str
    level: str
    description: str | None
    hypothesis: str | None
    tags: tuple[str, ...]
    object_relpath: str
    canonical_name: str
    object_basename: str
    short_name: str
    fixture_path: str | None
    compile_loader: str | None
    shared_state_policy: str
    allow_object_only_result: bool
    test_method: str
    programs: tuple[ResolvedProgram, ...]


def _mapping_dict(value: Any, *, field_name: str) -> dict[str, Any]:
    if value is None:
        return {}
    if not isinstance(value, dict):
        raise SystemExit(f"invalid benchmark config field: {field_name} must be a mapping")
    return dict(value)


def _deep_merge(base: Mapping[str, Any], override: Mapping[str, Any]) -> dict[str, Any]:
    merged = dict(base)
    for key, value in override.items():
        if isinstance(value, dict) and isinstance(merged.get(key), dict):
            merged[key] = _deep_merge(
                _mapping_dict(merged[key], field_name=str(key)),
                value,
            )
        else:
            merged[key] = value
    return merged


def _fallback_benchmark_config() -> dict[str, Any]:
    return {
        "defaults": {
            "iterations": 3,
            "warmups": 1,
            "repeat": FALLBACK_REPEAT,
            "output_json": str(FALLBACK_OUTPUT_JSON),
            "output_md": str(FALLBACK_OUTPUT_MD),
        },
        "passes": {},
        "profiles": {},
    }


def load_benchmark_config(profile: str | None = None) -> dict[str, Any]:
    config_path = DEFAULT_BENCHMARK_CONFIG_YAML
    root_config = _fallback_benchmark_config()
    config_loaded = False

    if config_path.exists():
        loaded = yaml.safe_load(config_path.read_text())
        if loaded is None:
            loaded = {}
        if not isinstance(loaded, dict):
            raise SystemExit(f"benchmark config must be a YAML mapping: {config_path}")
        root_config = _deep_merge(root_config, loaded)
        config_loaded = True
    elif profile:
        raise SystemExit(f"benchmark profile requested but config file not found: {config_path}")

    defaults = _mapping_dict(root_config.get("defaults"), field_name="defaults")
    passes = _mapping_dict(root_config.get("passes"), field_name="passes")
    profiles = _mapping_dict(root_config.get("profiles"), field_name="profiles")

    profile_overrides: dict[str, Any] = {}
    if profile:
        available = ", ".join(sorted(profiles))
        raw_profile = profiles.get(profile)
        if raw_profile is None:
            message = f"unknown benchmark profile: {profile}"
            if available:
                message += f" (available: {available})"
            raise SystemExit(message)
        profile_overrides = _mapping_dict(raw_profile, field_name=f"profiles.{profile}")

    effective = _deep_merge({**defaults, "passes": passes}, profile_overrides)
    effective["passes"] = _mapping_dict(effective.get("passes"), field_name="passes")
    effective["profile"] = profile
    effective["config_path"] = config_path if config_loaded else None
    effective["config_loaded"] = config_loaded
    effective["available_profiles"] = sorted(profiles)
    return effective


def benchmark_enabled_passes(benchmark_config: Mapping[str, Any] | None) -> list[str]:
    passes_config = _mapping_dict(
        (benchmark_config or {}).get("passes"),
        field_name="passes",
    )

    def normalize(values: Any) -> list[str]:
        if not isinstance(values, list):
            return []
        return [str(value).strip() for value in values if str(value).strip()]

    active_list = normalize(passes_config.get("active_list"))
    if active_list:
        return active_list

    active_name = str(passes_config.get("active") or "").strip()
    if active_name:
        named_list = normalize(passes_config.get(active_name))
        if named_list:
            return named_list

    performance_list = normalize(passes_config.get("performance"))
    if performance_list:
        return performance_list

    return list(DEFAULT_REJIT_ENABLED_PASSES)


def benchmark_warmup_repeat(benchmark_config: Mapping[str, Any] | None) -> int:
    value = (benchmark_config or {}).get("warmups")
    try:
        return max(0, int(value))
    except (TypeError, ValueError):
        return 0


def parse_packet_args(argv: list[str] | None = None) -> argparse.Namespace:
    argv = list(sys.argv[1:] if argv is None else argv)
    pre_parser = argparse.ArgumentParser(add_help=False)
    pre_parser.add_argument("--profile")
    pre_args, _ = pre_parser.parse_known_args(argv)
    benchmark_config = load_benchmark_config(pre_args.profile)
    profile_names = benchmark_config.get("available_profiles") or []
    profile_help = "Benchmark profile from benchmark_config.yaml."
    if profile_names:
        profile_help += f" Available: {', '.join(profile_names)}."

    parser = argparse.ArgumentParser(
        description=(
            "Run the macro_corpus.yaml-driven corpus REJIT batch on "
            "the framework kernel guest."
        )
    )
    parser.add_argument(
        "--macro-corpus-yaml",
        default=str(DEFAULT_MACRO_CORPUS_YAML),
        help="Macro corpus YAML manifest used to select the corpus targets.",
    )
    parser.add_argument("--profile", default=benchmark_config.get("profile"), help=profile_help)
    add_output_json_argument(parser, benchmark_config["output_json"])
    add_output_md_argument(parser, benchmark_config["output_md"])
    add_runner_argument(parser, DEFAULT_RUNNER, help_text="Path to micro_exec.")
    add_daemon_argument(parser, DEFAULT_DAEMON, help_text="Path to bpfrejit-daemon.")
    parser.add_argument(
        "--kernel-tree",
        default=str(DEFAULT_KERNEL_TREE),
        help="Framework kernel tree recorded in result metadata.",
    )
    parser.add_argument(
        "--kernel-image",
        default=str(DEFAULT_KERNEL_IMAGE),
        help="Kernel image passed to vng --run.",
    )
    parser.add_argument(
        "--btf-custom-path",
        default=str(DEFAULT_BTF_PATH),
        help="BTF path passed to guest micro_exec invocations.",
    )
    parser.add_argument(
        "--corpus-build-report",
        default=str(DEFAULT_CORPUS_BUILD_REPORT),
        help="Strict corpus object availability report emitted by build_corpus_objects.py.",
    )
    parser.add_argument(
        "--vng",
        default=DEFAULT_VNG,
        help="vng executable to use for strict guest runs.",
    )
    add_repeat_argument(
        parser,
        int(benchmark_config["repeat"]),
        help_text="Repeat count passed to each micro_exec invocation.",
    )
    add_timeout_argument(parser, DEFAULT_TIMEOUT_SECONDS, help_text="Per-target timeout in seconds.")
    add_filter_argument(
        parser,
        help_text="Only include targets whose canonical name, object path, program name, or source contains this substring. Repeatable.",
    )
    add_max_programs_argument(parser, help_text="Optional cap for smoke testing.")
    parser.add_argument(
        "--skip-families",
        action="append",
        help="Comma-separated REJIT families to exclude from daemon apply. Supported: cmov, wide, rotate, lea, extract, endian, branch-flip.",
    )
    parser.add_argument(
        "--blind-apply",
        action="store_true",
        help="Ignore per-program policies and force blind all-apply auto-scan REJIT for debugging.",
    )
    parser.add_argument(
        "--guest-info",
        action="store_true",
        help=argparse.SUPPRESS,
    )
    parser.add_argument(
        "--guest-target-json",
        help=argparse.SUPPRESS,
    )
    parser.add_argument(
        "--guest-result-json",
        help=argparse.SUPPRESS,
    )
    args = parser.parse_args(argv)
    args.benchmark_config = load_benchmark_config(args.profile)
    args.default_output_json = str(args.benchmark_config["output_json"])
    args.default_output_md = str(args.benchmark_config["output_md"])
    return args


def build_corpus_artifact_metadata(
    *,
    generated_at: str,
    run_type: str,
    mode_name: str,
    output_json: Path,
    output_md: Path,
    summary: dict[str, Any],
    progress: dict[str, Any],
    extra_fields: dict[str, Any],
) -> dict[str, Any]:
    metadata = {
        "generated_at": generated_at,
        "suite": "corpus",
        "mode": mode_name,
        "run_type": run_type,
        "output_hint_json": repo_relative_path(output_json),
        "output_hint_md": repo_relative_path(output_md),
        "summary": summary,
        "progress": progress,
    }
    metadata.update(extra_fields)
    return metadata


def canonical_family_name(value: str) -> str:
    normalized = value.strip().lower().replace("_", "-")
    mapping = {
        "cmov": "cmov",
        "cond-select": "cmov",
        "wide": "wide",
        "wide-mem": "wide",
        "wide-load": "wide",
        "rotate": "rotate",
        "lea": "lea",
        "addr-calc": "lea",
        "addrcalc": "lea",
        "extract": "extract",
        "bitfield": "extract",
        "bitfield-extract": "extract",
        "bit-extract": "extract",
        "endian": "endian",
        "endian-fusion": "endian",
        "branch-flip": "branch-flip",
        "branchflip": "branch-flip",
        "bflip": "branch-flip",
    }
    if normalized not in mapping:
        raise SystemExit(
            f"unsupported family in --skip-families: {value} "
            "(expected cmov, wide, rotate, lea, extract, endian, or branch-flip)"
        )
    return mapping[normalized]


def normalize_skip_families(values: list[str] | None) -> list[str]:
    normalized: list[str] = []
    seen: set[str] = set()
    for raw in values or []:
        for item in raw.split(","):
            if not item.strip():
                continue
            family = canonical_family_name(item)
            if family not in seen:
                seen.add(family)
                normalized.append(family)
    return normalized


def normalize_passes(value: Any) -> list[str]:
    if not isinstance(value, list):
        return []
    return [str(item) for item in value if str(item)]


def manifest_program_names(entry: Mapping[str, Any]) -> list[str]:
    program_name = str(entry.get("program_name") or "").strip()
    if program_name:
        return [program_name]
    return normalize_passes(entry.get("program_names"))


def split_corpus_source(source: str, family: str | None = None) -> tuple[str, str]:
    raw_source = str(source or "")
    source_path = Path(raw_source)
    parts = source_path.parts
    for index in range(len(parts) - 2):
        if parts[index : index + 2] != ("corpus", "build"):
            continue
        repo_index = index + 2
        repo_name = str(parts[repo_index]).strip()
        object_rel = Path(*parts[repo_index + 1 :])
        object_name = str(object_rel).strip() if str(object_rel) != "." else source_path.name
        return repo_name, object_name
    return str(family or "").strip(), str(source_path.name or raw_source).strip()


def _string_or_none(value: Any) -> str | None:
    text = str(value or "").strip()
    return text or None


def _int_or_default(value: Any, default: int) -> int:
    if value in (None, ""):
        return default
    return int(value)


def _int_or_none(value: Any) -> int | None:
    if value in (None, ""):
        return None
    return int(value)


def _bool_or_default(value: Any, default: bool) -> bool:
    if value in (None, ""):
        return default
    if isinstance(value, bool):
        return value
    text = str(value).strip().lower()
    if text in {"1", "true", "yes", "on"}:
        return True
    if text in {"0", "false", "no", "off"}:
        return False
    raise SystemExit(f"invalid boolean value: {value!r}")


def _string_tuple(value: Any) -> tuple[str, ...]:
    if not isinstance(value, list):
        return ()
    return tuple(str(item).strip() for item in value if str(item).strip())


def _mapping(value: Any, *, field_name: str) -> dict[str, Any]:
    if value is None:
        return {}
    if not isinstance(value, dict):
        raise SystemExit(f"invalid manifest field: {field_name} must be a mapping")
    return dict(value)


def _sequence(value: Any, *, field_name: str) -> list[Any]:
    if value is None:
        return []
    if not isinstance(value, list):
        raise SystemExit(f"invalid manifest field: {field_name} must be a sequence")
    return list(value)


def object_matches_filter(obj: ResolvedObject, lowered_filters: list[str]) -> bool:
    if not lowered_filters:
        return True
    haystacks = [
        obj.canonical_name.lower(),
        obj.object_path.lower(),
        obj.object_relpath.lower(),
        obj.repo.lower(),
        obj.source_name.lower(),
        obj.object_basename.lower(),
    ]
    return any(any(needle in haystack for haystack in haystacks) for needle in lowered_filters)


def program_matches_filter(program: ResolvedProgram, lowered_filters: list[str]) -> bool:
    if not lowered_filters:
        return True
    haystacks = [
        program.canonical_name.lower(),
        program.short_name.lower(),
        program.canonical_object_name.lower(),
        program.object_path.lower(),
        program.object_relpath.lower(),
        program.program_name.lower(),
        program.source_name.lower(),
        program.repo.lower(),
        program.section_name.lower(),
        program.prog_type_name.lower(),
    ]
    return any(any(needle in haystack for haystack in haystacks) for needle in lowered_filters)


def build_target_name(
    *,
    source: str,
    family: str | None = None,
    program_names: list[str] | None = None,
) -> str:
    repo_name, object_name = split_corpus_source(source, family)
    prefix = ":".join(part for part in (repo_name, object_name) if part)
    names = [name for name in (program_names or []) if name]
    if not names:
        return prefix
    program_token = "+".join(names)
    return f"{prefix}:{program_token}" if prefix else program_token


def resolve_target_name(entry: Mapping[str, Any]) -> str:
    raw_name = str(entry.get("name") or "").strip()
    if raw_name:
        return raw_name
    return build_target_name(
        source=str(entry.get("source", "")),
        family=str(entry.get("family", "")),
        program_names=manifest_program_names(entry),
    )


def record_target_name(record: Mapping[str, Any]) -> str:
    raw_name = str(record.get("name") or "").strip()
    if raw_name:
        return raw_name
    program_names = record.get("program_names")
    if not isinstance(program_names, list):
        program_names = []
    return build_target_name(
        source=str(record.get("object_path", "")),
        family=str(record.get("source_name", "")),
        program_names=[str(item) for item in program_names if str(item)]
        or ([str(record.get("program_name")).strip()] if str(record.get("program_name") or "").strip() else []),
    )


def merge_passes(*pass_lists: list[str]) -> list[str]:
    merged: list[str] = []
    seen: set[str] = set()
    for values in pass_lists:
        for name in values:
            if name in seen:
                continue
            seen.add(name)
            merged.append(name)
    return merged


def batch_text_invocation_summary(result: dict[str, Any] | None) -> dict[str, Any] | None:
    if result is None:
        return None
    summary = {
        "ok": result["ok"],
        "returncode": result["returncode"],
        "timed_out": result["timed_out"],
        "duration_seconds": result["duration_seconds"],
        "error": result["error"],
        "stderr_tail": summarize_text(result["stderr"]),
        "stdout_tail": summarize_text(result.get("diagnostic_stdout", result["stdout"])),
    }
    command = result.get("command")
    if isinstance(command, str):
        summary["command"] = command
    elif isinstance(command, list):
        summary["command"] = [str(part) for part in command]
    debug_artifacts = result.get("debug_artifacts")
    if isinstance(debug_artifacts, dict) and debug_artifacts:
        summary["debug_artifacts"] = {
            str(key): str(value)
            for key, value in debug_artifacts.items()
            if str(value)
        }
    return summary


def start_daemon_server(daemon: Path, daemon_socket: str) -> subprocess.Popen[str]:
    socket_path = Path(daemon_socket)
    socket_path.unlink(missing_ok=True)
    daemon_proc: subprocess.Popen[str] = subprocess.Popen(
        [str(daemon), "serve", "--socket", daemon_socket],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
        text=True,
    )
    time.sleep(0.5)
    return daemon_proc


def stop_daemon_server(daemon_proc: subprocess.Popen[str] | None, daemon_socket: str | None) -> None:
    if daemon_proc is not None:
        daemon_proc.terminate()
        try:
            daemon_proc.wait(timeout=5)
        except subprocess.TimeoutExpired:
            daemon_proc.kill()
            daemon_proc.wait()
    if daemon_socket:
        Path(daemon_socket).unlink(missing_ok=True)


def emit_guest_event(kind: str, **payload: Any) -> None:
    print(json.dumps({"kind": kind, **payload}, sort_keys=True), flush=True)


def parse_guest_event(line: str) -> dict[str, Any] | None:
    text = line.strip()
    if not text or not text.startswith("{"):
        return None
    try:
        payload = json.loads(text)
    except json.JSONDecodeError:
        return None
    if not isinstance(payload, dict) or not isinstance(payload.get("kind"), str):
        return None
    return payload


def packet_batch_timeout_seconds(target_count: int, per_target_timeout: int) -> int:
    return max(1, target_count) * max(1, per_target_timeout) * 4 + 120


def size_ratio(
    baseline_record: dict[str, Any] | None,
    rejit_record: dict[str, Any] | None,
) -> float | None:
    if not baseline_record or not rejit_record:
        return None
    if not baseline_record.get("ok") or not rejit_record.get("ok"):
        return None
    baseline_len = ((baseline_record.get("sample") or {}).get("jited_prog_len"))
    rejit_len = ((rejit_record.get("sample") or {}).get("jited_prog_len"))
    if not baseline_len or not rejit_len:
        return None
    return float(baseline_len) / float(rejit_len)


def size_delta_pct(
    baseline_record: dict[str, Any] | None,
    rejit_record: dict[str, Any] | None,
) -> float | None:
    ratio = size_ratio(baseline_record, rejit_record)
    if ratio is None:
        return None
    baseline_len = ((baseline_record.get("sample") or {}).get("jited_prog_len"))
    rejit_len = ((rejit_record.get("sample") or {}).get("jited_prog_len"))
    if baseline_len in (None, 0) or rejit_len is None:
        return None
    return (float(rejit_len) - float(baseline_len)) * 100.0 / float(baseline_len)


def speedup_ratio(
    baseline_record: dict[str, Any] | None,
    rejit_record: dict[str, Any] | None,
) -> float | None:
    if not baseline_record or not rejit_record:
        return None
    if not baseline_record.get("ok") or not rejit_record.get("ok"):
        return None
    baseline_ns = ((baseline_record.get("sample") or {}).get("exec_ns"))
    rejit_ns = ((rejit_record.get("sample") or {}).get("exec_ns"))
    if not baseline_ns or not rejit_ns:
        return None
    return float(baseline_ns) / float(rejit_ns)


def summarize_failure_reason(record: dict[str, Any] | None) -> str:
    if not record:
        return "n/a"
    error = record.get("error")
    if error:
        return str(error)
    sample = record.get("sample") or {}
    rejit = sample.get("rejit") or {}
    if rejit.get("error"):
        return str(rejit["error"])
    return "unknown"


def program_label(record: dict[str, Any]) -> str:
    return record_target_name(record)


def rejit_metadata(record: dict[str, Any] | None) -> dict[str, Any]:
    if not record or not record.get("ok"):
        return {}
    return (record.get("sample") or {}).get("rejit") or {}


def rejit_passes(record: dict[str, Any] | None) -> list[str]:
    return normalize_passes(rejit_metadata(record).get("passes_applied"))


def build_empty_record(target: dict[str, Any], execution_mode: str) -> dict[str, Any]:
    return {
        **target,
        "execution_mode": execution_mode,
        "policy_path": target.get("policy_path"),
        "policy_mode": str(target.get("policy_mode", "stock")),
        "daemon_cli": None,
        "baseline_compile": None,
        "rejit_compile": None,
        "baseline_run": None,
        "rejit_run": None,
        "rejit_compile_applied": False,
        "rejit_run_applied": False,
        "compile_passes_applied": [],
        "run_passes_applied": [],
        "applied_passes": [],
        "size_ratio": None,
        "size_delta_pct": None,
        "speedup_ratio": None,
        "record_error": None,
        "guest_invocation": None,
    }


def corpus_batch_parallel_jobs() -> int:
    return max(1, int(math.floor((os.cpu_count() or 1) * 0.8)))


def build_test_run_batch_job(
    *,
    job_id: str,
    execution: str,
    runtime: str,
    object_path: Path,
    program_name: str | None,
    attach_program_name: str | None,
    io_mode: str,
    raw_packet: bool,
    memory_path: Path | None,
    input_size: int,
    repeat: int,
    warmup_repeat: int | None = None,
    btf_custom_path: Path | None,
    compile_only: bool,
    daemon_socket: str | None = None,
    enabled_passes: list[str] | None = None,
    prepared_key: str | None = None,
    prepared_ref: str | None = None,
    prepared_group: str | None = None,
    release_prepared: bool = True,
    fixture_path: Path | None = None,
    trigger_command: str | None = None,
    trigger_timeout_seconds: int | None = None,
) -> dict[str, Any]:
    job: dict[str, Any] = {
        "id": job_id,
        "type": "test_run",
        "execution": execution,
        "runtime": runtime,
        "program": str(object_path),
        "io_mode": io_mode,
        "repeat": max(1, repeat),
        "compile_only": compile_only,
    }
    if warmup_repeat is not None:
        job["warmup_repeat"] = max(0, int(warmup_repeat))
    if program_name is not None:
        job["program_name"] = program_name
    if attach_program_name is not None:
        job["attach_program_name"] = attach_program_name
    if raw_packet:
        job["raw_packet"] = True
    if memory_path is not None:
        job["memory"] = str(memory_path)
    if fixture_path is not None:
        job["fixture_path"] = str(fixture_path)
    if trigger_command is not None:
        job["trigger_command"] = trigger_command
    if trigger_timeout_seconds is not None:
        job["trigger_timeout_seconds"] = int(trigger_timeout_seconds)
    if input_size > 0:
        job["input_size"] = int(input_size)
    if btf_custom_path is not None:
        job["btf_custom_path"] = str(btf_custom_path)
    if daemon_socket is not None:
        job["daemon_socket"] = daemon_socket
    if enabled_passes:
        job["enabled_passes"] = list(enabled_passes)
    if prepared_key is not None:
        job["prepared_key"] = prepared_key
    if prepared_ref is not None:
        job["prepared_ref"] = prepared_ref
    if prepared_group is not None:
        job["prepared_group"] = prepared_group
    if not release_prepared:
        job["release_prepared"] = False
    return job


def batch_job_invocation_summary(job_result: Mapping[str, Any] | None) -> dict[str, Any] | None:
    if not isinstance(job_result, Mapping):
        return None
    samples = job_result.get("samples")
    last_sample = None
    if isinstance(samples, list) and samples:
        candidate = samples[-1]
        if isinstance(candidate, dict):
            last_sample = dict(candidate)
    ok = bool(job_result.get("ok"))
    error = str(job_result.get("error") or "") or None
    return {
        "ok": ok,
        "returncode": 0 if ok else 2,
        "timed_out": False,
        "duration_seconds": float(job_result.get("wall_time_ns", 0) or 0) / 1_000_000_000.0,
        "error": error,
        "stderr_tail": summarize_text(error or ""),
        "stdout_tail": "",
        "sample": last_sample,
    }


def batch_job_result_map(batch_payload: Mapping[str, Any] | None) -> dict[str, dict[str, Any]]:
    if not isinstance(batch_payload, Mapping):
        return {}
    jobs = batch_payload.get("jobs")
    if not isinstance(jobs, list):
        return {}
    mapped: dict[str, dict[str, Any]] = {}
    for item in jobs:
        if not isinstance(item, dict):
            continue
        job_id = item.get("id")
        if isinstance(job_id, str) and job_id:
            mapped[job_id] = dict(item)
    return mapped


def build_target_batch_plan(
    *,
    targets: list[dict[str, Any]],
    repeat: int,
    warmup_repeat: int,
    btf_custom_path: Path | None,
    enable_recompile: bool,
    enable_exec: bool,
    daemon_socket: str | None,
    enabled_passes: list[str] | None = None,
) -> tuple[dict[str, Any], list[dict[str, str]]]:
    jobs: list[dict[str, Any]] = []
    job_refs: list[dict[str, str]] = []
    target_entries: list[dict[str, Any]] = []
    parallel_jobs = corpus_batch_parallel_jobs()

    for index, target in enumerate(targets, start=1):
        object_path = ROOT_DIR / target["object_path"]
        memory_path = Path(target["memory_path"]) if target.get("memory_path") else None
        prefix = f"target-{index:04d}"
        refs: dict[str, str] = {}
        job_refs.append(refs)
        target_entries.append(
            {
                "target": target,
                "object_path": object_path,
                "memory_path": memory_path,
                "prefix": prefix,
                "refs": refs,
                "baseline_prepared_key": f"{prefix}:baseline-prepared",
                "rejit_prepared_key": f"{prefix}:rejit-prepared",
            }
        )

    for chunk_start in range(0, len(target_entries), parallel_jobs):
        chunk = target_entries[chunk_start : chunk_start + parallel_jobs]
        baseline_group = f"chunk-{chunk_start // parallel_jobs:04d}:baseline"
        rejit_group = f"chunk-{chunk_start // parallel_jobs:04d}:rejit"

        for entry in chunk:
            target = entry["target"]
            refs = entry["refs"]
            refs["baseline_compile"] = f"{entry['prefix']}:baseline-compile"
            jobs.append(
                build_test_run_batch_job(
                    job_id=refs["baseline_compile"],
                    execution="parallel",
                    runtime="kernel",
                    object_path=entry["object_path"],
                    program_name=target["program_name"],
                    attach_program_name=target.get("attach_group"),
                    io_mode=target["io_mode"],
                    raw_packet=bool(target.get("raw_packet", False)),
                    memory_path=entry["memory_path"],
                    input_size=int(target["input_size"]),
                    repeat=repeat,
                    warmup_repeat=warmup_repeat,
                    btf_custom_path=btf_custom_path,
                    compile_only=True,
                    prepared_key=(
                        entry["baseline_prepared_key"]
                        if enable_exec and target.get("can_test_run")
                        else None
                    ),
                    prepared_group=(
                        baseline_group
                        if enable_exec and target.get("can_test_run")
                        else None
                    ),
                )
            )

        if enable_exec:
            for entry in chunk:
                target = entry["target"]
                refs = entry["refs"]
                refs["baseline_run"] = f"{entry['prefix']}:baseline-run"
                if target.get("can_test_run"):
                    jobs.append(
                        build_test_run_batch_job(
                            job_id=refs["baseline_run"],
                            execution="serial",
                            runtime="kernel",
                            object_path=entry["object_path"],
                            program_name=target["program_name"],
                            attach_program_name=target.get("attach_group"),
                            io_mode=target["io_mode"],
                            raw_packet=bool(target.get("raw_packet", False)),
                            memory_path=entry["memory_path"],
                            input_size=int(target["input_size"]),
                            repeat=repeat,
                            warmup_repeat=warmup_repeat,
                            btf_custom_path=btf_custom_path,
                            compile_only=False,
                            prepared_ref=entry["baseline_prepared_key"],
                            prepared_group=baseline_group,
                        )
                    )
                else:
                    jobs.append(
                        build_test_run_batch_job(
                            job_id=refs["baseline_run"],
                            execution="serial",
                            runtime="kernel-attach",
                            object_path=entry["object_path"],
                            program_name=target["program_name"],
                            attach_program_name=target.get("attach_group"),
                            io_mode="map",
                            raw_packet=False,
                            memory_path=None,
                            input_size=0,
                            repeat=repeat,
                            warmup_repeat=warmup_repeat,
                            btf_custom_path=btf_custom_path,
                            compile_only=False,
                        )
                    )

        if enable_recompile and enable_exec:
            for entry in chunk:
                target = entry["target"]
                refs = entry["refs"]
                if not target.get("can_test_run"):
                    continue
                refs["pgo_warmup"] = f"{entry['prefix']}:pgo-warmup"
                jobs.append(
                    build_test_run_batch_job(
                        job_id=refs["pgo_warmup"],
                        execution="serial",
                        runtime="kernel",
                        object_path=entry["object_path"],
                        program_name=target["program_name"],
                        attach_program_name=target.get("attach_group"),
                        io_mode=target["io_mode"],
                        raw_packet=bool(target.get("raw_packet", False)),
                        memory_path=entry["memory_path"],
                        input_size=int(target["input_size"]),
                        repeat=10,
                        warmup_repeat=warmup_repeat,
                        btf_custom_path=btf_custom_path,
                        compile_only=False,
                    )
                )

        if enable_recompile:
            for entry in chunk:
                target = entry["target"]
                refs = entry["refs"]
                refs["rejit_compile"] = f"{entry['prefix']}:rejit-compile"
                jobs.append(
                    build_test_run_batch_job(
                        job_id=refs["rejit_compile"],
                        execution="parallel",
                        runtime="kernel-rejit",
                        object_path=entry["object_path"],
                        program_name=target["program_name"],
                        attach_program_name=target.get("attach_group"),
                        io_mode=target["io_mode"],
                        raw_packet=bool(target.get("raw_packet", False)),
                        memory_path=entry["memory_path"],
                        input_size=int(target["input_size"]),
                        repeat=repeat,
                        warmup_repeat=warmup_repeat,
                        btf_custom_path=btf_custom_path,
                        compile_only=True,
                        daemon_socket=daemon_socket,
                        enabled_passes=enabled_passes,
                        prepared_key=(
                            entry["rejit_prepared_key"]
                            if enable_exec and target.get("can_test_run")
                            else None
                        ),
                        prepared_group=(
                            rejit_group
                            if enable_exec and target.get("can_test_run")
                            else None
                        ),
                    )
                )

        if enable_recompile and enable_exec:
            for entry in chunk:
                target = entry["target"]
                refs = entry["refs"]
                refs["rejit_run"] = f"{entry['prefix']}:rejit-run"
                if target.get("can_test_run"):
                    jobs.append(
                        build_test_run_batch_job(
                            job_id=refs["rejit_run"],
                            execution="serial",
                            runtime="kernel-rejit",
                            object_path=entry["object_path"],
                            program_name=target["program_name"],
                            attach_program_name=target.get("attach_group"),
                            io_mode=target["io_mode"],
                            raw_packet=bool(target.get("raw_packet", False)),
                            memory_path=entry["memory_path"],
                            input_size=int(target["input_size"]),
                            repeat=repeat,
                            warmup_repeat=warmup_repeat,
                            btf_custom_path=btf_custom_path,
                            compile_only=False,
                            daemon_socket=daemon_socket,
                            enabled_passes=enabled_passes,
                            prepared_ref=entry["rejit_prepared_key"],
                            prepared_group=rejit_group,
                        )
                    )
                else:
                    jobs.append(
                        build_test_run_batch_job(
                            job_id=refs["rejit_run"],
                            execution="serial",
                            runtime="kernel-attach-rejit",
                            object_path=entry["object_path"],
                            program_name=target["program_name"],
                            attach_program_name=target.get("attach_group"),
                            io_mode="map",
                            raw_packet=False,
                            memory_path=None,
                            input_size=0,
                            repeat=repeat,
                            warmup_repeat=warmup_repeat,
                            btf_custom_path=btf_custom_path,
                            compile_only=False,
                            daemon_socket=daemon_socket,
                            enabled_passes=enabled_passes,
                        )
                    )

    return {
        "schema_version": 1,
        "scheduler": {
            "max_parallel_jobs": parallel_jobs,
        },
        "jobs": jobs,
    }, job_refs


def build_record_from_batch_results(
    *,
    target: dict[str, Any],
    execution_mode: str,
    enable_recompile: bool,
    enable_exec: bool,
    skip_families: list[str],
    blind_apply: bool,
    job_refs: Mapping[str, str],
    results_by_id: Mapping[str, dict[str, Any]],
) -> dict[str, Any]:
    record = build_empty_record(target, execution_mode)
    policy_mode = "blind-apply-rejit" if blind_apply else "daemon-auto"

    baseline_compile_raw = batch_job_invocation_summary(results_by_id.get(job_refs.get("baseline_compile", "")))
    baseline_run_raw = batch_job_invocation_summary(results_by_id.get(job_refs.get("baseline_run", "")))
    rejit_compile_raw = batch_job_invocation_summary(results_by_id.get(job_refs.get("rejit_compile", "")))
    rejit_run_raw = batch_job_invocation_summary(results_by_id.get(job_refs.get("rejit_run", "")))

    record["daemon_cli"] = None
    record["policy_path"] = None
    record["policy_mode"] = policy_mode
    record["baseline_compile"] = baseline_compile_raw
    record["rejit_compile"] = rejit_compile_raw
    record["rejit_run"] = rejit_run_raw
    record["baseline_run"] = baseline_run_raw

    if (
        enable_exec
        and enable_recompile
        and target.get("can_test_run")
        and rejit_run_raw
        and rejit_run_raw.get("ok")
        and record["baseline_run"] is None
    ):
        record["record_error"] = "stock phase missing from batch runner output"
    record["rejit_compile_applied"] = bool((((record["rejit_compile"] or {}).get("sample") or {}).get("rejit") or {}).get("applied"))
    record["rejit_run_applied"] = bool((((record["rejit_run"] or {}).get("sample") or {}).get("rejit") or {}).get("applied"))
    record["compile_passes_applied"] = rejit_passes(record["rejit_compile"])
    record["run_passes_applied"] = rejit_passes(record["rejit_run"])
    record["applied_passes"] = merge_passes(
        record["compile_passes_applied"],
        record["run_passes_applied"],
    )
    record["size_ratio"] = size_ratio(record["baseline_compile"], record["rejit_compile"])
    record["size_delta_pct"] = size_delta_pct(record["baseline_compile"], record["rejit_compile"])
    record["speedup_ratio"] = speedup_ratio(record["baseline_run"], record["rejit_run"])
    return record


def run_targets_locally_batch(
    *,
    targets: list[dict[str, Any]],
    runner: Path,
    daemon: Path,
    repeat: int,
    warmup_repeat: int,
    timeout_seconds: int,
    execution_mode: str,
    btf_custom_path: Path | None,
    enable_recompile: bool,
    enable_exec: bool,
    skip_families: list[str],
    blind_apply: bool,
    daemon_socket: str | None = None,
    enabled_passes: list[str] | None = None,
) -> tuple[list[dict[str, Any]], dict[str, Any]]:
    active_daemon_socket = daemon_socket
    daemon_proc = None
    if enable_recompile and active_daemon_socket is None:
        active_daemon_socket = f"/tmp/bpfrejit-{os.getpid()}.sock"
        daemon_proc = start_daemon_server(daemon, active_daemon_socket)

    try:
        spec_payload, job_refs = build_target_batch_plan(
            targets=targets,
            repeat=repeat,
            warmup_repeat=warmup_repeat,
            btf_custom_path=btf_custom_path,
            enable_recompile=enable_recompile,
            enable_exec=enable_exec,
            daemon_socket=active_daemon_socket,
            enabled_passes=enabled_passes,
        )
        batch_result = run_batch_runner(
            runner,
            spec_payload=spec_payload,
            timeout_seconds=packet_batch_timeout_seconds(len(targets), timeout_seconds),
            cwd=ROOT_DIR,
        )
    finally:
        stop_daemon_server(daemon_proc, active_daemon_socket if daemon_proc is not None else None)

    results_by_id = batch_job_result_map(batch_result.get("result"))
    records = [
        build_record_from_batch_results(
            target=target,
            execution_mode=execution_mode,
            enable_recompile=enable_recompile,
            enable_exec=enable_exec,
            skip_families=skip_families,
            blind_apply=blind_apply,
            job_refs=refs,
            results_by_id=results_by_id,
        )
        for target, refs in zip(targets, job_refs, strict=True)
    ]
    return records, batch_result


def guest_info_payload() -> dict[str, Any]:
    return {
        "kind": "guest_info",
        "kernel_release": subprocess.run(
            ["uname", "-r"],
            cwd=ROOT_DIR,
            capture_output=True,
            text=True,
            check=False,
        ).stdout.strip(),
        "cwd": str(Path.cwd()),
        "runner_exists": DEFAULT_RUNNER.exists(),
        "btf_exists": DEFAULT_BTF_PATH.exists(),
        "uid": os.geteuid(),
    }


def run_guest_info_mode() -> int:
    print(json.dumps(guest_info_payload(), sort_keys=True))
    return 0


def load_guest_batch_targets(target_path: Path) -> list[ResolvedObject]:
    payload = json.loads(target_path.read_text())
    if not isinstance(payload, dict):
        raise SystemExit("--guest-target-json payload must be a JSON object")
    objects = payload.get("objects")
    if not isinstance(objects, list):
        raise SystemExit("--guest-target-json payload missing objects list")
    normalized_objects: list[ResolvedObject] = []
    for index, obj in enumerate(objects, start=1):
        if not isinstance(obj, dict):
            raise SystemExit(f"--guest-target-json object #{index} must be a JSON object")
        normalized_objects.append(deserialize_resolved_object(obj))
    return normalized_objects


def write_guest_batch_records(result_path: Path, records: list[dict[str, Any]]) -> None:
    payload = {"records": records}
    with tempfile.NamedTemporaryFile(
        mode="w",
        dir=result_path.parent,
        prefix=f"{result_path.name}.",
        suffix=".tmp",
        delete=False,
    ) as handle:
        json.dump(payload, handle)
        handle.write("\n")
        temp_path = Path(handle.name)
    temp_path.replace(result_path)


def _strip_daemon_response(value: Any) -> Any:
    if isinstance(value, dict):
        sanitized: dict[str, Any] = {}
        for key, item in value.items():
            if key == "daemon_response":
                continue
            sanitized[key] = _strip_daemon_response(item)
        return sanitized
    if isinstance(value, list):
        return [_strip_daemon_response(item) for item in value]
    return value


def sanitize_guest_batch_record(record: dict[str, Any]) -> dict[str, Any]:
    return _strip_daemon_response(record)


def run_guest_batch_mode(args: argparse.Namespace) -> int:
    target_path = Path(args.guest_target_json).resolve()
    objects = load_guest_batch_targets(target_path)
    runner = Path(args.runner).resolve()
    daemon = Path(args.daemon).resolve()
    btf_custom_path = Path(args.btf_custom_path).resolve() if args.btf_custom_path else None
    guest_result_path = Path(args.guest_result_json).resolve() if args.guest_result_json else None
    enabled_passes = benchmark_enabled_passes(args.benchmark_config)
    warmup_repeat = benchmark_warmup_repeat(args.benchmark_config)
    if btf_custom_path is None:
        raise SystemExit("--btf-custom-path is required in guest batch mode")

    emit_guest_event("guest_info", payload=guest_info_payload())
    records: list[dict[str, Any]] = []
    if guest_result_path is not None:
        write_guest_batch_records(guest_result_path, records)

    active_daemon_socket: str | None = None
    daemon_proc: subprocess.Popen[str] | None = None
    if objects:
        active_daemon_socket = f"/tmp/bpfrejit-guest-{os.getpid()}.sock"
        daemon_proc = start_daemon_server(daemon, active_daemon_socket)

    try:
        for chunk_start in range(0, len(objects), GUEST_BATCH_TARGETS_PER_CHUNK):
            object_chunk = objects[chunk_start : chunk_start + GUEST_BATCH_TARGETS_PER_CHUNK]
            try:
                object_records, program_records, _batch_result = run_objects_locally_batch(
                    objects=object_chunk,
                    runner=runner,
                    daemon=daemon,
                    repeat=args.repeat,
                    warmup_repeat=warmup_repeat,
                    timeout_seconds=args.timeout,
                    execution_mode="vm",
                    btf_custom_path=btf_custom_path,
                    daemon_socket=active_daemon_socket,
                    enabled_passes=enabled_passes,
                )
                built_records = []
                for obj in object_chunk:
                    object_record = next(
                        item for item in object_records if item["canonical_object_name"] == obj.canonical_name
                    )
                    object_program_records = [
                        item for item in program_records if item["canonical_object_name"] == obj.canonical_name
                    ]
                    built_records.append(
                        {
                            "object_record": object_record,
                            "program_records": object_program_records,
                        }
                    )
            except Exception as exc:
                print(traceback.format_exc(), file=sys.stderr, flush=True)
                built_records = []
                for obj in object_chunk:
                    built_records.append(
                        {
                            "object_record": build_empty_object_record(
                                obj,
                                "vm",
                                error=f"guest batch exception: {exc}",
                            ),
                            "program_records": [],
                        }
                    )

            for index, record in enumerate(built_records, start=chunk_start + 1):
                records.append(sanitize_guest_batch_record(record))
                if guest_result_path is not None:
                    write_guest_batch_records(guest_result_path, records)
                    emit_guest_event("program_progress", index=index, total=len(objects))
                else:
                    emit_guest_event("program_record", index=index, total=len(objects), record=record)
    finally:
        stop_daemon_server(daemon_proc, active_daemon_socket if daemon_proc is not None else None)
    return 0


def build_vm_shell_command(
    *,
    kernel_image: Path,
    guest_exec: str,
    timeout_seconds: int,
    vng_binary: str,
) -> list[str]:
    command = [
        sys.executable,
        str(ROOT_DIR / "runner" / "scripts" / "run_vm_shell.py"),
        "--action",
        "vm-corpus",
        "--kernel-image",
        str(kernel_image),
        "--timeout",
        str(timeout_seconds),
        "--command",
        guest_exec,
    ]
    if vng_binary != DEFAULT_VNG:
        command.extend(["--vm-executable", vng_binary])
    return command


def build_guest_exec(argv: list[str]) -> str:
    # Load kinsn kernel modules before running the guest command so the daemon
    # can apply platform-specific rewrites (rotate, cond_select, extract).
    load_script = ROOT_DIR / "module" / "load_all.sh"
    kinsn_load = f"{shlex.quote(str(load_script))} 2>/dev/null || true; "
    main_cmd = " ".join(shlex.quote(part) for part in argv)
    return kinsn_load + main_cmd


def load_corpus_build_report(path: Path) -> dict[str, Any]:
    payload = json.loads(path.read_text())
    summary = payload.get("summary") or {}
    raw_paths = summary.get("available_objects")
    if not isinstance(raw_paths, list) or not raw_paths:
        raise SystemExit(f"invalid corpus build report schema (missing summary.available_objects): {path}")
    raw_build_root = payload.get("build_root")
    if isinstance(raw_build_root, str) and raw_build_root.strip():
        build_root = Path(raw_build_root).resolve()
    else:
        build_root = (path.parent.parent / "build").resolve()
    resolved_paths, supplemented_existing = supplement_with_existing_corpus_build_objects(
        raw_paths,
        build_root=build_root,
    )
    available_objects = {str(object_path) for object_path in resolved_paths}
    if not available_objects:
        raise SystemExit(f"corpus build report has no existing available_objects: {path}")
    return {
        "path": path,
        "payload": payload,
        "summary": summary,
        "available_objects": available_objects,
        "build_root": build_root,
        "supplemented_existing": supplemented_existing,
    }


def serialize_resolved_object(obj: ResolvedObject) -> dict[str, Any]:
    return asdict(obj)


def deserialize_resolved_object(payload: Mapping[str, Any]) -> ResolvedObject:
    programs_payload = payload.get("programs")
    if not isinstance(programs_payload, list):
        raise SystemExit("guest object payload missing programs list")
    programs = []
    for item in programs_payload:
        if not isinstance(item, Mapping):
            continue
        program_payload = dict(item)
        program_payload.setdefault("fixture_path", None)
        programs.append(ResolvedProgram(**program_payload))
    programs = tuple(programs)
    base = dict(payload)
    base["programs"] = programs
    base.setdefault("fixture_path", None)
    return ResolvedObject(**base)


def clone_resolved_object(obj: ResolvedObject, programs: tuple[ResolvedProgram, ...]) -> ResolvedObject:
    return ResolvedObject(
        source=obj.source,
        object_path=obj.object_path,
        object_abs_path=obj.object_abs_path,
        repo=obj.repo,
        source_name=obj.source_name,
        family=obj.family,
        category=obj.category,
        level=obj.level,
        description=obj.description,
        hypothesis=obj.hypothesis,
        tags=obj.tags,
        object_relpath=obj.object_relpath,
        canonical_name=obj.canonical_name,
        object_basename=obj.object_basename,
        short_name=obj.short_name,
        fixture_path=obj.fixture_path,
        compile_loader=obj.compile_loader,
        shared_state_policy=obj.shared_state_policy,
        allow_object_only_result=obj.allow_object_only_result,
        test_method=obj.test_method,
        programs=programs,
    )


def resolve_manifest_object(entry: Mapping[str, Any], *, index: int) -> ResolvedObject:
    source = _string_or_none(entry.get("source"))
    if source is None:
        raise SystemExit(f"manifest object #{index} missing source")
    object_candidate = Path(source)
    object_path = object_candidate if object_candidate.is_absolute() else (ROOT_DIR / object_candidate)
    repo_from_source, object_relpath = split_corpus_source(source, _string_or_none(entry.get("family")) or "")
    repo = _string_or_none(entry.get("repo")) or repo_from_source or (_string_or_none(entry.get("family")) or object_candidate.name)
    family = _string_or_none(entry.get("family")) or repo
    category = _string_or_none(entry.get("category")) or ""
    level = _string_or_none(entry.get("level")) or ""
    description = _string_or_none(entry.get("description"))
    hypothesis = _string_or_none(entry.get("hypothesis"))
    tags = _string_tuple(entry.get("tags"))
    object_basename = Path(source).name
    canonical_object_name = f"{repo}:{object_relpath}" if repo else object_relpath
    short_name = f"{repo}:{object_basename}" if repo else object_basename
    fixture_path = _string_or_none(entry.get("fixture_path"))
    compile_loader = _string_or_none(entry.get("compile_loader"))
    shared_state_policy = _string_or_none(entry.get("shared_state_policy")) or "reset_maps"
    allow_object_only_result = bool(entry.get("allow_object_only_result", False))
    object_test_method = _string_or_none(entry.get("test_method")) or "compile_only"
    object_prog_type = _string_or_none(entry.get("prog_type")) or ""
    object_section = _string_or_none(entry.get("section")) or ""
    object_io_mode = _string_or_none(entry.get("io_mode")) or "context"
    object_raw_packet = _bool_or_default(entry.get("raw_packet"), False)
    object_test_input = _string_or_none(entry.get("test_input"))
    object_input_size = _int_or_default(entry.get("input_size"), 0)
    object_trigger = _string_or_none(entry.get("trigger"))
    object_trigger_timeout = _int_or_none(entry.get("trigger_timeout_seconds"))
    object_attach_group = _string_or_none(entry.get("attach_group"))
    object_rejit_enabled = bool(entry.get("rejit_enabled", True))

    def default_program_fixture_path(program_name: str) -> str | None:
        relative = Path("corpus") / "fixtures" / repo / object_basename / f"{program_name}.json"
        absolute = ROOT_DIR / relative
        return relative.as_posix() if absolute.exists() else None

    raw_programs = _sequence(entry.get("programs"), field_name=f"objects[{index}].programs")
    programs: list[ResolvedProgram] = []
    for program_index, raw_program in enumerate(raw_programs, start=1):
        if not isinstance(raw_program, Mapping):
            raise SystemExit(f"manifest objects[{index}].programs[{program_index}] must be a mapping")
        program_name = _string_or_none(raw_program.get("name"))
        if program_name is None:
            raise SystemExit(f"manifest objects[{index}].programs[{program_index}] missing name")
        test_method = _string_or_none(raw_program.get("test_method")) or object_test_method
        prog_type_name = _string_or_none(raw_program.get("prog_type")) or object_prog_type
        section_name = _string_or_none(raw_program.get("section")) or object_section or ""
        io_mode = _string_or_none(raw_program.get("io_mode")) or object_io_mode
        raw_packet = _bool_or_default(raw_program.get("raw_packet"), object_raw_packet)
        memory_path = _string_or_none(raw_program.get("test_input")) or object_test_input
        input_size = _int_or_default(raw_program.get("input_size"), object_input_size)
        trigger = _string_or_none(raw_program.get("trigger")) or object_trigger
        trigger_timeout_seconds = _int_or_none(raw_program.get("trigger_timeout_seconds"))
        if trigger_timeout_seconds is None:
            trigger_timeout_seconds = object_trigger_timeout
        attach_group = _string_or_none(raw_program.get("attach_group")) or object_attach_group
        if test_method == "attach_trigger" and attach_group is None:
            attach_group = program_name
        rejit_enabled = bool(raw_program.get("rejit_enabled", object_rejit_enabled))
        program_fixture_path = (
            _string_or_none(raw_program.get("fixture_path"))
            or fixture_path
            or default_program_fixture_path(program_name)
        )
        program_family = _string_or_none(raw_program.get("family")) or family
        program_category = _string_or_none(raw_program.get("category")) or category
        program_level = _string_or_none(raw_program.get("level")) or level
        program_description = _string_or_none(raw_program.get("description")) or description
        program_hypothesis = _string_or_none(raw_program.get("hypothesis")) or hypothesis
        program_tags = _string_tuple(raw_program.get("tags")) or tags
        canonical_name = f"{canonical_object_name}:{program_name}"
        short_program_name = f"{short_name}:{program_name}"
        programs.append(
            ResolvedProgram(
                source=source,
                object_path=source,
                object_abs_path=str(object_path.resolve()),
                repo=repo,
                source_name=program_family or repo,
                family=program_family or "",
                category=program_category or "",
                level=program_level or "",
                description=program_description,
                hypothesis=program_hypothesis,
                tags=program_tags,
                object_relpath=object_relpath,
                canonical_object_name=canonical_object_name,
                object_basename=object_basename,
                short_name=short_program_name,
                program_name=program_name,
                canonical_name=canonical_name,
                fixture_path=program_fixture_path,
                test_method=test_method,
                prog_type_name=prog_type_name,
                section_name=section_name,
                io_mode=io_mode,
                raw_packet=raw_packet,
                input_size=input_size,
                memory_path=memory_path,
                trigger=trigger,
                trigger_timeout_seconds=trigger_timeout_seconds,
                compile_loader=compile_loader,
                attach_group=attach_group,
                rejit_enabled=rejit_enabled,
            )
        )

    if not programs and not allow_object_only_result:
        raise SystemExit(f"manifest object #{index} has no programs and does not allow object-only results")

    return ResolvedObject(
        source=source,
        object_path=source,
        object_abs_path=str(object_path.resolve()),
        repo=repo,
        source_name=family or repo,
        family=family or "",
        category=category or "",
        level=level or "",
        description=description,
        hypothesis=hypothesis,
        tags=tags,
        object_relpath=object_relpath,
        canonical_name=canonical_object_name,
        object_basename=object_basename,
        short_name=short_name,
        fixture_path=fixture_path,
        compile_loader=compile_loader,
        shared_state_policy=shared_state_policy,
        allow_object_only_result=allow_object_only_result,
        test_method=object_test_method,
        programs=tuple(programs),
    )


def runtime_for_program(program: ResolvedProgram, *, rejit: bool) -> str:
    if program.test_method == "attach_trigger":
        return "kernel-attach-rejit" if rejit else "kernel-attach"
    return "kernel-rejit" if rejit else "kernel"


def find_program_in_object(
    obj: ResolvedObject,
    program_name: str,
) -> ResolvedProgram | None:
    for program in obj.programs:
        if program.program_name == program_name:
            return program
    return None


def generic_attach_section_unsupported_reason(
    prog_type_name: str,
    section_name: str,
) -> str | None:
    prog_type = prog_type_name.strip()
    section = section_name.strip()
    if prog_type == "tracepoint":
        parts = section.split("/") if section else []
        if len(parts) != 3 or parts[0] != "tracepoint" or not parts[1] or not parts[2]:
            return (
                "libbpf generic tracepoint attach requires section "
                f"'tracepoint/<category>/<name>', got '{section or '<empty>'}'"
            )
    return None


def attach_trigger_unsupported_reason(
    obj: ResolvedObject,
    program: ResolvedProgram,
) -> str | None:
    if program.test_method != "attach_trigger":
        return None
    attach_name = program.attach_group or program.program_name
    attach_program = find_program_in_object(obj, attach_name)
    if attach_program is None:
        return f"attach program '{attach_name}' not found in object"
    return generic_attach_section_unsupported_reason(
        attach_program.prog_type_name,
        attach_program.section_name,
    )


def build_object_batch_plan_v2(
    *,
    objects: list[ResolvedObject],
    repeat: int,
    warmup_repeat: int,
    btf_custom_path: Path | None,
    daemon_socket: str,
    enabled_passes: list[str] | None = None,
) -> tuple[dict[str, Any], list[dict[str, Any]]]:
    jobs: list[dict[str, Any]] = []
    object_refs: list[dict[str, Any]] = []

    for index, obj in enumerate(objects, start=1):
        object_path = ROOT_DIR / obj.object_path
        fixture_path = Path(obj.fixture_path) if obj.fixture_path else None
        baseline_group = f"object-{index:04d}:baseline"
        rejit_group = f"object-{index:04d}:rejit"
        baseline_prepared_key = f"{baseline_group}:prepared"
        rejit_prepared_key = f"{rejit_group}:prepared"
        refs: dict[str, Any] = {
            "object": obj,
            "baseline_object_compile": f"object-{index:04d}:baseline-object-compile",
            "rejit_object_compile": f"object-{index:04d}:rejit-object-compile",
            "programs": {},
        }
        object_refs.append(refs)

        jobs.append(
            build_test_run_batch_job(
                job_id=refs["baseline_object_compile"],
                execution="serial",
                runtime="kernel",
                object_path=object_path,
                program_name=None,
                attach_program_name=None,
                io_mode="context",
                raw_packet=False,
                memory_path=None,
                input_size=0,
                repeat=repeat,
                warmup_repeat=warmup_repeat,
                btf_custom_path=btf_custom_path,
                compile_only=True,
                prepared_key=baseline_prepared_key,
                prepared_group=baseline_group,
                fixture_path=fixture_path,
            )
        )

        for program_index, program in enumerate(obj.programs, start=1):
            program_refs = {
                "baseline_compile": f"object-{index:04d}:program-{program_index:04d}:baseline-compile",
                "baseline_run": f"object-{index:04d}:program-{program_index:04d}:baseline-run",
                "rejit_compile": f"object-{index:04d}:program-{program_index:04d}:rejit-compile",
                "rejit_run": f"object-{index:04d}:program-{program_index:04d}:rejit-run",
            }
            refs["programs"][program.canonical_name] = program_refs
            memory_path = Path(program.memory_path) if program.memory_path else None
            program_fixture_path = Path(program.fixture_path) if program.fixture_path else fixture_path
            jobs.append(
                build_test_run_batch_job(
                    job_id=program_refs["baseline_compile"],
                    execution="serial",
                    runtime=runtime_for_program(program, rejit=False),
                    object_path=object_path,
                    program_name=program.program_name,
                    attach_program_name=program.attach_group,
                    io_mode=program.io_mode,
                    raw_packet=program.raw_packet,
                    memory_path=memory_path,
                    input_size=program.input_size,
                    repeat=repeat,
                    warmup_repeat=warmup_repeat,
                    btf_custom_path=btf_custom_path,
                    compile_only=True,
                    prepared_ref=baseline_prepared_key,
                    prepared_group=baseline_group,
                    release_prepared=False,
                    fixture_path=program_fixture_path,
                    trigger_command=program.trigger,
                    trigger_timeout_seconds=program.trigger_timeout_seconds,
                )
            )
            if program.test_method != "compile_only":
                jobs.append(
                    build_test_run_batch_job(
                        job_id=program_refs["baseline_run"],
                        execution="serial",
                        runtime=runtime_for_program(program, rejit=False),
                        object_path=object_path,
                        program_name=program.program_name,
                        attach_program_name=program.attach_group,
                        io_mode=program.io_mode,
                        raw_packet=program.raw_packet,
                        memory_path=memory_path,
                        input_size=program.input_size,
                        repeat=repeat,
                        warmup_repeat=warmup_repeat,
                        btf_custom_path=btf_custom_path,
                        compile_only=False,
                        prepared_ref=baseline_prepared_key,
                        prepared_group=baseline_group,
                        release_prepared=False,
                        fixture_path=program_fixture_path,
                        trigger_command=program.trigger,
                        trigger_timeout_seconds=program.trigger_timeout_seconds,
                    )
                )

        jobs.append(
            build_test_run_batch_job(
                job_id=refs["rejit_object_compile"],
                execution="serial",
                runtime="kernel-rejit",
                object_path=object_path,
                program_name=None,
                attach_program_name=None,
                io_mode="context",
                raw_packet=False,
                memory_path=None,
                input_size=0,
                repeat=repeat,
                warmup_repeat=warmup_repeat,
                btf_custom_path=btf_custom_path,
                compile_only=True,
                daemon_socket=daemon_socket,
                enabled_passes=enabled_passes,
                prepared_key=rejit_prepared_key,
                prepared_group=rejit_group,
                fixture_path=fixture_path,
            )
        )

        for program_index, program in enumerate(obj.programs, start=1):
            program_refs = refs["programs"][program.canonical_name]
            memory_path = Path(program.memory_path) if program.memory_path else None
            program_fixture_path = Path(program.fixture_path) if program.fixture_path else fixture_path
            jobs.append(
                build_test_run_batch_job(
                    job_id=program_refs["rejit_compile"],
                    execution="serial",
                    runtime=runtime_for_program(program, rejit=True),
                    object_path=object_path,
                    program_name=program.program_name,
                    attach_program_name=program.attach_group,
                    io_mode=program.io_mode,
                    raw_packet=program.raw_packet,
                    memory_path=memory_path,
                    input_size=program.input_size,
                    repeat=repeat,
                    warmup_repeat=warmup_repeat,
                    btf_custom_path=btf_custom_path,
                    compile_only=True,
                    daemon_socket=daemon_socket,
                    enabled_passes=enabled_passes,
                    prepared_ref=rejit_prepared_key,
                    prepared_group=rejit_group,
                    release_prepared=False,
                    fixture_path=program_fixture_path,
                    trigger_command=program.trigger,
                    trigger_timeout_seconds=program.trigger_timeout_seconds,
                )
            )
            if program.test_method != "compile_only" and program.rejit_enabled:
                jobs.append(
                    build_test_run_batch_job(
                        job_id=program_refs["rejit_run"],
                        execution="serial",
                        runtime=runtime_for_program(program, rejit=True),
                        object_path=object_path,
                        program_name=program.program_name,
                        attach_program_name=program.attach_group,
                        io_mode=program.io_mode,
                        raw_packet=program.raw_packet,
                        memory_path=memory_path,
                        input_size=program.input_size,
                        repeat=repeat,
                        warmup_repeat=warmup_repeat,
                        btf_custom_path=btf_custom_path,
                        compile_only=False,
                        daemon_socket=daemon_socket,
                        enabled_passes=enabled_passes,
                        prepared_ref=rejit_prepared_key,
                        prepared_group=rejit_group,
                        release_prepared=False,
                        fixture_path=program_fixture_path,
                        trigger_command=program.trigger,
                        trigger_timeout_seconds=program.trigger_timeout_seconds,
                    )
                )

    return {
        "schema_version": 1,
        "scheduler": {
            "max_parallel_jobs": 1,
        },
        "jobs": jobs,
    }, object_refs


def build_empty_program_record(program: ResolvedProgram, execution_mode: str) -> dict[str, Any]:
    return {
        "canonical_name": program.canonical_name,
        "short_name": program.short_name,
        "canonical_object_name": program.canonical_object_name,
        "repo": program.repo,
        "source_name": program.source_name,
        "family": program.family,
        "category": program.category,
        "level": program.level,
        "description": program.description,
        "hypothesis": program.hypothesis,
        "tags": list(program.tags),
        "object_path": program.object_path,
        "object_relpath": program.object_relpath,
        "object_basename": program.object_basename,
        "program_name": program.program_name,
        "section_name": program.section_name,
        "prog_type_name": program.prog_type_name,
        "test_method": program.test_method,
        "compile_loader": program.compile_loader,
        "attach_group": program.attach_group,
        "io_mode": program.io_mode,
        "raw_packet": program.raw_packet,
        "input_size": program.input_size,
        "memory_path": program.memory_path,
        "execution_mode": execution_mode,
        "baseline_compile": None,
        "baseline_run": None,
        "rejit_compile": None,
        "rejit_run": None,
        "compile_passes_applied": [],
        "run_passes_applied": [],
        "applied_passes": [],
        "size_ratio": None,
        "size_delta_pct": None,
        "speedup_ratio": None,
        "record_error": None,
        "guest_invocation": None,
    }


def build_empty_object_record(obj: ResolvedObject, execution_mode: str, *, error: str | None = None) -> dict[str, Any]:
    return {
        "canonical_object_name": obj.canonical_name,
        "repo": obj.repo,
        "source_name": obj.source_name,
        "object_path": obj.object_path,
        "object_relpath": obj.object_relpath,
        "object_basename": obj.object_basename,
        "source": obj.source,
        "compile_loader": obj.compile_loader,
        "shared_state_policy": obj.shared_state_policy,
        "program_count": len(obj.programs),
        "measured_program_count": sum(1 for program in obj.programs if program.test_method != "compile_only"),
        "execution_mode": execution_mode,
        "stock_compile": None,
        "rejit_compile": None,
        "status": "error" if error else "ok",
        "error": error,
    }


def build_program_record_v2(
    *,
    program: ResolvedProgram,
    execution_mode: str,
    job_refs: Mapping[str, str],
    results_by_id: Mapping[str, dict[str, Any]],
) -> dict[str, Any]:
    record = build_empty_program_record(program, execution_mode)
    record["baseline_compile"] = batch_job_invocation_summary(results_by_id.get(job_refs["baseline_compile"]))
    record["rejit_compile"] = batch_job_invocation_summary(results_by_id.get(job_refs["rejit_compile"]))
    if program.test_method != "compile_only":
        record["baseline_run"] = batch_job_invocation_summary(results_by_id.get(job_refs["baseline_run"]))
        record["rejit_run"] = batch_job_invocation_summary(results_by_id.get(job_refs["rejit_run"]))

    record["compile_passes_applied"] = rejit_passes(record["rejit_compile"])
    record["run_passes_applied"] = rejit_passes(record["rejit_run"])
    record["applied_passes"] = merge_passes(record["compile_passes_applied"], record["run_passes_applied"])
    record["size_ratio"] = size_ratio(record["baseline_compile"], record["rejit_compile"])
    record["size_delta_pct"] = size_delta_pct(record["baseline_compile"], record["rejit_compile"])
    record["speedup_ratio"] = speedup_ratio(record["baseline_run"], record["rejit_run"])
    return record


def build_object_record_v2(
    *,
    obj: ResolvedObject,
    execution_mode: str,
    refs: Mapping[str, Any],
    results_by_id: Mapping[str, dict[str, Any]],
) -> dict[str, Any]:
    record = build_empty_object_record(obj, execution_mode)
    record["stock_compile"] = batch_job_invocation_summary(results_by_id.get(refs["baseline_object_compile"]))
    record["rejit_compile"] = batch_job_invocation_summary(results_by_id.get(refs["rejit_object_compile"]))
    if record["stock_compile"] and not record["stock_compile"].get("ok"):
        record["status"] = "error"
        record["error"] = summarize_failure_reason(record["stock_compile"])
    elif record["rejit_compile"] and not record["rejit_compile"].get("ok"):
        record["status"] = "error"
        record["error"] = summarize_failure_reason(record["rejit_compile"])
    return record


def run_objects_locally_batch(
    *,
    objects: list[ResolvedObject],
    runner: Path,
    daemon: Path,
    repeat: int,
    warmup_repeat: int,
    timeout_seconds: int,
    execution_mode: str,
    btf_custom_path: Path | None,
    daemon_socket: str | None = None,
    enabled_passes: list[str] | None = None,
) -> tuple[list[dict[str, Any]], list[dict[str, Any]], dict[str, Any]]:
    active_daemon_socket = daemon_socket
    daemon_proc = None
    if objects and active_daemon_socket is None:
        active_daemon_socket = f"/tmp/bpfrejit-{os.getpid()}.sock"
        daemon_proc = start_daemon_server(daemon, active_daemon_socket)

    try:
        if not objects:
            batch_result = {
                "ok": True,
                "completed_with_job_errors": False,
                "returncode": 0,
                "timed_out": False,
                "duration_seconds": 0.0,
                "stdout": "",
                "stderr": "",
                "error": None,
                "result": {"jobs": []},
                "progress": None,
            }
            return [], [], batch_result

        assert active_daemon_socket is not None
        spec_payload, object_refs = build_object_batch_plan_v2(
            objects=objects,
            repeat=repeat,
            warmup_repeat=warmup_repeat,
            btf_custom_path=btf_custom_path,
            daemon_socket=active_daemon_socket,
            enabled_passes=enabled_passes,
        )
        batch_result = run_batch_runner(
            runner,
            spec_payload=spec_payload,
            timeout_seconds=packet_batch_timeout_seconds(max(1, len(objects)), timeout_seconds),
            cwd=ROOT_DIR,
        )
    finally:
        stop_daemon_server(daemon_proc, active_daemon_socket if daemon_proc is not None else None)

    results_by_id = batch_job_result_map(batch_result.get("result"))
    object_records: list[dict[str, Any]] = []
    program_records: list[dict[str, Any]] = []
    for refs in object_refs:
        obj = refs["object"]
        object_records.append(
            build_object_record_v2(
                obj=obj,
                execution_mode=execution_mode,
                refs=refs,
                results_by_id=results_by_id,
            )
        )
        for program in obj.programs:
            program_records.append(
                build_program_record_v2(
                    program=program,
                    execution_mode=execution_mode,
                    job_refs=refs["programs"][program.canonical_name],
                    results_by_id=results_by_id,
                )
            )
    return object_records, program_records, batch_result


def build_summary_v2(program_records: list[dict[str, Any]], object_records: list[dict[str, Any]]) -> dict[str, Any]:
    compile_pairs = [
        record
        for record in program_records
        if record.get("baseline_compile") and record["baseline_compile"].get("ok")
        and record.get("rejit_compile") and record["rejit_compile"].get("ok")
    ]
    measured_pairs = [
        record
        for record in program_records
        if record.get("baseline_run") and record["baseline_run"].get("ok")
        and record.get("rejit_run") and record["rejit_run"].get("ok")
    ]
    applied_programs = [record for record in program_records if record.get("applied_passes")]
    compile_pass_counts = Counter()
    run_pass_counts = Counter()
    for record in program_records:
        compile_pass_counts.update(record.get("compile_passes_applied") or [])
        run_pass_counts.update(record.get("run_passes_applied") or [])

    failure_reasons = Counter()
    rejit_failures = Counter()
    for record in program_records:
        if record.get("record_error"):
            failure_reasons[str(record["record_error"])] += 1
            continue
        for key in ("baseline_compile", "rejit_compile", "baseline_run", "rejit_run"):
            raw = record.get(key)
            if raw and not raw.get("ok"):
                failure_reasons[summarize_failure_reason(raw)] += 1
        for key in ("rejit_compile", "rejit_run"):
            raw = record.get(key)
            if raw and raw.get("ok"):
                rejit = ((raw.get("sample") or {}).get("rejit") or {})
                if rejit.get("requested") and not rejit.get("applied") and rejit.get("error"):
                    rejit_failures[str(rejit["error"])] += 1

    size_ratios = [record["size_ratio"] for record in compile_pairs if record.get("size_ratio") is not None]
    exec_ratios = [record["speedup_ratio"] for record in measured_pairs if record.get("speedup_ratio") is not None]

    def aggregate_rows(grouped: Mapping[str, list[dict[str, Any]]], label_key: str) -> list[dict[str, Any]]:
        rows: list[dict[str, Any]] = []
        for label, items in grouped.items():
            grouped_compile = [item for item in items if item in compile_pairs]
            grouped_measured = [item for item in items if item in measured_pairs]
            rows.append(
                {
                    label_key: label,
                    "programs": len(items),
                    "compile_pairs": len(grouped_compile),
                    "measured_pairs": len(grouped_measured),
                    "applied_programs": sum(1 for item in items if item.get("applied_passes")),
                    "code_size_ratio_geomean": geomean([item["size_ratio"] for item in grouped_compile if item.get("size_ratio") is not None]),
                    "exec_ratio_geomean": geomean([item["speedup_ratio"] for item in grouped_measured if item.get("speedup_ratio") is not None]),
                }
            )
        rows.sort(key=lambda item: (-item["programs"], item[label_key]))
        return rows

    grouped_by_repo: dict[str, list[dict[str, Any]]] = defaultdict(list)
    grouped_by_object: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for record in program_records:
        grouped_by_repo[record["repo"]].append(record)
        grouped_by_object[record["canonical_object_name"]].append(record)

    return {
        "effective_mode": "vm",
        "objects_attempted": len(object_records),
        "targets_attempted": len(program_records),
        "compile_pairs": len(compile_pairs),
        "measured_pairs": len(measured_pairs),
        "applied_programs": len(applied_programs),
        "code_size_ratio_geomean": geomean(size_ratios),
        "code_size_delta_median_pct": statistics.median(
            [record["size_delta_pct"] for record in compile_pairs if record.get("size_delta_pct") is not None]
        ) if compile_pairs else None,
        "exec_ratio_geomean": geomean(exec_ratios),
        "exec_ratio_median": statistics.median(exec_ratios) if exec_ratios else None,
        "exec_ratio_min": min(exec_ratios) if exec_ratios else None,
        "exec_ratio_max": max(exec_ratios) if exec_ratios else None,
        "pass_counts": dict(sorted((compile_pass_counts + run_pass_counts).items())),
        "compile_pass_counts": dict(sorted(compile_pass_counts.items())),
        "run_pass_counts": dict(sorted(run_pass_counts.items())),
        "failure_reasons": dict(failure_reasons.most_common(16)),
        "rejit_failure_reasons": dict(rejit_failures.most_common(16)),
        "by_repo": aggregate_rows(grouped_by_repo, "repo"),
        "by_object": aggregate_rows(grouped_by_object, "canonical_object_name"),
    }


def build_markdown_v2(data: dict[str, Any]) -> str:
    summary = data["summary"]
    records = sorted(data["program_records"], key=lambda item: item["canonical_name"])
    object_records = sorted(data["object_records"], key=lambda item: item["canonical_object_name"])
    corpus_build_summary = data.get("corpus_build_summary") or {}
    guest_info = (data.get("guest_smoke") or {}).get("payload")
    lines: list[str] = [
        "# Corpus Batch REJIT Results",
        "",
        f"- Generated: {data['generated_at']}",
        f"- Corpus manifest: `{data['macro_corpus_yaml']}`",
        f"- Corpus build report: `{data['corpus_build_report']}`",
        f"- Runner: `{data['runner_binary']}`",
        f"- Daemon: `{data['daemon_binary']}`",
        "- Requested mode: `strict-vm`",
        f"- Effective mode: `{summary['effective_mode']}`",
        f"- Benchmark profile: `{data.get('benchmark_profile') or 'default'}`",
        f"- Benchmark config: `{data.get('benchmark_config') or 'fallback-defaults'}`",
        f"- Objects: {summary['objects_attempted']}",
        f"- Programs: {summary['targets_attempted']}",
        f"- Compile pairs: {summary['compile_pairs']}",
        f"- Measured pairs: {summary['measured_pairs']}",
        f"- REJIT applied programs: {summary['applied_programs']}",
        f"- Code-size ratio geomean (baseline/rejit): {format_ratio(summary['code_size_ratio_geomean'])}",
        f"- Exec-time ratio geomean (baseline/rejit): {format_ratio(summary['exec_ratio_geomean'])}",
    ]
    if corpus_build_summary:
        lines.append(
            f"- Build availability: {corpus_build_summary.get('available_total', 0)} objects "
            f"({corpus_build_summary.get('built_ok', 0)} built, {corpus_build_summary.get('staged_existing', 0)} staged)"
        )
    if guest_info:
        lines.append(f"- Guest kernel: `{guest_info.get('kernel_release', 'unknown')}`")
    lines.append("")

    lines.extend(["## By Repo", ""])
    lines.extend(
        markdown_table(
            ["Repo", "Programs", "Compile Pairs", "Measured Pairs", "Applied", "Code Ratio", "Exec Ratio"],
            [
                [
                    row["repo"],
                    row["programs"],
                    row["compile_pairs"],
                    row["measured_pairs"],
                    row["applied_programs"],
                    format_ratio(row["code_size_ratio_geomean"]),
                    format_ratio(row["exec_ratio_geomean"]),
                ]
                for row in summary["by_repo"]
            ],
        )
    )
    lines.append("")

    lines.extend(["## By Object", ""])
    lines.extend(
        markdown_table(
            ["Object", "Programs", "Compile", "REJIT Compile", "Status", "Error"],
            [
                [
                    row["canonical_object_name"],
                    row["program_count"],
                    format_ns(((row.get("stock_compile") or {}).get("sample") or {}).get("compile_ns")),
                    format_ns(((row.get("rejit_compile") or {}).get("sample") or {}).get("compile_ns")),
                    row["status"],
                    row.get("error") or "",
                ]
                for row in object_records
            ],
        )
    )
    lines.append("")

    lines.extend(["## Per-Program Results", ""])
    lines.extend(
        markdown_table(
            [
                "Program",
                "Repo",
                "Type",
                "Compile Passes",
                "Run Passes",
                "Baseline JIT",
                "REJIT JIT",
                "Code Ratio",
                "Baseline ns",
                "REJIT ns",
                "Exec Ratio",
                "Note",
            ],
            [
                [
                    record["canonical_name"],
                    record["repo"],
                    record["prog_type_name"],
                    ", ".join(record.get("compile_passes_applied") or []) or "-",
                    ", ".join(record.get("run_passes_applied") or []) or "-",
                    format_ns(((record.get("baseline_compile") or {}).get("sample") or {}).get("jited_prog_len")),
                    format_ns(((record.get("rejit_compile") or {}).get("sample") or {}).get("jited_prog_len")),
                    format_ratio(record.get("size_ratio")),
                    format_ns(((record.get("baseline_run") or {}).get("sample") or {}).get("exec_ns")),
                    format_ns(((record.get("rejit_run") or {}).get("sample") or {}).get("exec_ns")),
                    format_ratio(record.get("speedup_ratio")),
                    record.get("record_error")
                    or (
                        summarize_failure_reason(record.get("rejit_compile"))
                        if record.get("rejit_compile") and not record["rejit_compile"].get("ok")
                        else ""
                    ),
                ]
                for record in records
            ],
        )
    )

    if summary["failure_reasons"]:
        lines.extend(["", "## Top Failure Reasons", ""])
        lines.extend(markdown_table(["Reason", "Count"], [[reason, count] for reason, count in summary["failure_reasons"].items()]))

    return "\n".join(lines) + "\n"


def load_targets_from_yaml(
    yaml_path: Path,
    corpus_build_report: dict[str, Any],
    filters: list[str] | None = None,
    max_programs: int | None = None,
) -> tuple[list[ResolvedObject], dict[str, Any]]:
    with open(yaml_path) as f:
        manifest = yaml.safe_load(f)
    if not isinstance(manifest, dict):
        raise SystemExit(f"macro corpus YAML root must be a mapping: {yaml_path}")
    if int(manifest.get("schema_version", 0) or 0) != 2 or "objects" not in manifest:
        raise SystemExit(f"macro corpus YAML must use schema_version: 2 objects format: {yaml_path}")

    raw_objects = _sequence(manifest.get("objects"), field_name="objects")
    resolved_objects = [
        resolve_manifest_object(entry, index=index)
        for index, entry in enumerate(raw_objects, start=1)
    ]
    resolved_objects.sort(key=lambda item: item.canonical_name)

    lowered_filters = [item.lower() for item in filters or []]
    selected_objects: list[ResolvedObject] = []
    remaining_programs = max_programs
    for obj in resolved_objects:
        object_selected = object_matches_filter(obj, lowered_filters)
        if object_selected:
            selected_programs = obj.programs
        else:
            selected_programs = tuple(program for program in obj.programs if program_matches_filter(program, lowered_filters))
        if not selected_programs and (obj.programs or not object_selected):
            continue
        if remaining_programs is not None and selected_programs:
            if remaining_programs <= 0:
                break
            selected_programs = selected_programs[:remaining_programs]
            remaining_programs -= len(selected_programs)
            if not selected_programs:
                break
        selected_objects.append(clone_resolved_object(obj, selected_programs))

    available_objects = corpus_build_report["available_objects"]
    kept_selected_objects: list[ResolvedObject] = []
    kept_on_disk_only: list[str] = []
    dropped_missing_objects: list[str] = []
    for obj in selected_objects:
        if obj.object_abs_path in available_objects:
            kept_selected_objects.append(obj)
            continue
        if Path(obj.object_abs_path).exists():
            kept_selected_objects.append(obj)
            kept_on_disk_only.append(obj.object_path)
            continue
        dropped_missing_objects.append(obj.object_path)

    if kept_on_disk_only:
        print(
            "warning: selected corpus objects missing from build report but present on disk; keeping them: "
            + ", ".join(kept_on_disk_only[:12])
            + (" ..." if len(kept_on_disk_only) > 12 else ""),
            file=sys.stderr,
            flush=True,
        )
    if dropped_missing_objects:
        print(
            "warning: selected corpus objects missing from build report and disk; dropping them: "
            + ", ".join(dropped_missing_objects[:12])
            + (" ..." if len(dropped_missing_objects) > 12 else ""),
            file=sys.stderr,
            flush=True,
        )
    selected_objects = kept_selected_objects

    build_summary_payload = corpus_build_report.get("summary") or {}
    report_available_total = int(build_summary_payload.get("available_total", len(available_objects)) or len(available_objects))
    supplemented_existing = int(corpus_build_report.get("supplemented_existing", 0) or 0)
    summary = {
        "manifest": str(yaml_path),
        "schema_version": 2,
        "total_objects": len(resolved_objects),
        "selected_objects": len(selected_objects),
        "total_programs": sum(len(obj.programs) for obj in resolved_objects),
        "selected_programs": sum(len(obj.programs) for obj in selected_objects),
        "build_report_path": str(corpus_build_report["path"]),
        "available_objects": max(report_available_total, len(available_objects)),
        "built_from_source": int(build_summary_payload.get("built_ok", 0) or 0),
        "staged_existing": int(build_summary_payload.get("staged_existing", 0) or 0) + supplemented_existing,
        "supplemented_existing": supplemented_existing,
    }
    return selected_objects, summary


def run_targets_in_guest_batch(
    *,
    targets: list[ResolvedObject],
    runner: Path,
    daemon: Path,
    kernel_image: Path,
    btf_custom_path: Path,
    profile: str | None,
    repeat: int,
    timeout_seconds: int,
    vng_binary: str,
    skip_families: list[str],
    blind_apply: bool,
    on_guest_info: Callable[[dict[str, Any]], None] | None = None,
    on_record: Callable[[int, dict[str, Any]], None] | None = None,
) -> dict[str, Any]:
    batch_tmp_dir = docs_tmp_dir("corpus-rejit-batch")
    handle = tempfile.NamedTemporaryFile(
        mode="w",
        prefix="corpus-rejit-vm-batch-",
        suffix=".json",
        dir=batch_tmp_dir,
        delete=False,
    )
    result_handle = tempfile.NamedTemporaryFile(
        mode="w",
        prefix="corpus-rejit-vm-batch-result-",
        suffix=".json",
        dir=batch_tmp_dir,
        delete=False,
    )
    try:
        guest_target_payload = {
            "objects": [serialize_resolved_object(obj) for obj in targets],
        }
        with handle:
            json.dump(guest_target_payload, handle)
            handle.write("\n")
        target_path = Path(handle.name)
        with result_handle:
            json.dump({"records": []}, result_handle)
            result_handle.write("\n")
        result_path = Path(result_handle.name)
        guest_argv = [
            "python3",
            str(DRIVER_RELATIVE),
            "--guest-target-json",
            str(target_path),
            "--guest-result-json",
            str(result_path),
            "--runner",
            str(runner),
            "--daemon",
            str(daemon),
            "--btf-custom-path",
            str(btf_custom_path),
            "--repeat",
            str(repeat),
            "--timeout",
            str(timeout_seconds),
        ]
        if profile:
            guest_argv.extend(["--profile", profile])
        if skip_families:
            guest_argv.extend(["--skip-families", ",".join(skip_families)])
        if blind_apply:
            guest_argv.append("--blind-apply")
        guest_exec = build_guest_exec(guest_argv)
        timeout_limit = packet_batch_timeout_seconds(len(targets), timeout_seconds)
        command = build_vm_shell_command(
            kernel_image=kernel_image,
            guest_exec=guest_exec,
            timeout_seconds=timeout_limit,
            vng_binary=vng_binary,
        )
        start = time.monotonic()
        process = subprocess.Popen(
            command,
            cwd=ROOT_DIR,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            bufsize=1,
        )
        selector = selectors.DefaultSelector()
        assert process.stdout is not None
        assert process.stderr is not None
        selector.register(process.stdout, selectors.EVENT_READ, data="stdout")
        selector.register(process.stderr, selectors.EVENT_READ, data="stderr")

        stdout_chunks: list[str] = []
        stderr_chunks: list[str] = []
        diagnostic_stdout_chunks: list[str] = []
        guest_info: dict[str, Any] | None = None
        emitted_records = 0
        timed_out = False
        guest_result_mtime_ns: int | None = None
        preserve_debug_artifacts = False

        def sync_guest_records() -> None:
            nonlocal emitted_records, guest_result_mtime_ns
            if not result_path.exists():
                return
            stat = result_path.stat()
            if guest_result_mtime_ns == stat.st_mtime_ns:
                return
            guest_result_mtime_ns = stat.st_mtime_ns
            try:
                payload = json.loads(result_path.read_text())
            except json.JSONDecodeError:
                return
            records_payload = payload.get("records")
            if not isinstance(records_payload, list):
                return
            while emitted_records < len(records_payload):
                record = records_payload[emitted_records]
                emitted_records += 1
                if isinstance(record, dict) and on_record is not None:
                    on_record(emitted_records, record)

        while selector.get_map():
            remaining = timeout_limit - (time.monotonic() - start)
            if remaining <= 0:
                timed_out = True
                process.kill()
                break
            ready = selector.select(timeout=min(1.0, remaining))
            sync_guest_records()
            if not ready:
                continue
            for key, _ in ready:
                stream = key.fileobj
                line = stream.readline()
                if line == "":
                    selector.unregister(stream)
                    continue
                if key.data == "stdout":
                    stdout_chunks.append(line)
                    event = parse_guest_event(line)
                    if event is None:
                        diagnostic_stdout_chunks.append(line)
                        continue
                    if event["kind"] == "guest_info":
                        payload = event.get("payload")
                        if isinstance(payload, dict):
                            guest_info = payload
                            if on_guest_info is not None:
                                on_guest_info(payload)
                        continue
                    if event["kind"] == "program_record":
                        record = event.get("record")
                        if isinstance(record, dict):
                            emitted_records += 1
                            if on_record is not None:
                                on_record(emitted_records, record)
                        continue
                    if event["kind"] == "program_progress":
                        continue
                    diagnostic_stdout_chunks.append(line)
                else:
                    stderr_chunks.append(line)
        selector.close()

        try:
            process.wait(timeout=5)
        except subprocess.TimeoutExpired:
            process.kill()
            process.wait()

        remaining_stdout = process.stdout.read() if process.stdout is not None else ""
        remaining_stderr = process.stderr.read() if process.stderr is not None else ""
        if remaining_stdout:
            for line in remaining_stdout.splitlines(keepends=True):
                stdout_chunks.append(line)
                event = parse_guest_event(line)
                if event is None:
                    diagnostic_stdout_chunks.append(line)
                    continue
                if event["kind"] == "guest_info":
                    payload = event.get("payload")
                    if isinstance(payload, dict):
                        guest_info = payload
                        if on_guest_info is not None:
                            on_guest_info(payload)
                    continue
                if event["kind"] == "program_record":
                    record = event.get("record")
                    if isinstance(record, dict):
                        emitted_records += 1
                        if on_record is not None:
                            on_record(emitted_records, record)
                    continue
                if event["kind"] == "program_progress":
                    continue
                diagnostic_stdout_chunks.append(line)
        if remaining_stderr:
            stderr_chunks.append(remaining_stderr)
        sync_guest_records()

        stdout = "".join(stdout_chunks)
        stderr = "".join(stderr_chunks)
        diagnostic_stdout = "".join(diagnostic_stdout_chunks)
        ok = process.returncode == 0 and not timed_out and guest_info is not None and emitted_records == len(targets)
        error = None
        if timed_out:
            error = f"timeout after {timeout_limit}s"
        elif process.returncode != 0:
            error = extract_error(stderr, stdout, process.returncode)
        elif guest_info is None:
            error = "guest batch missing guest_info"
        elif emitted_records != len(targets):
            error = f"guest batch emitted {emitted_records}/{len(targets)} records"

        debug_artifacts: dict[str, str] | None = None
        if error is not None:
            preserve_debug_artifacts = True
            debug_artifacts = {}
            if target_path.exists():
                debug_artifacts["target_json"] = str(target_path)
            if result_path.exists():
                debug_artifacts["result_json"] = str(result_path)
            for suffix, text in (
                ("stdout_log", stdout),
                ("stderr_log", stderr),
                ("diagnostic_stdout_log", diagnostic_stdout),
            ):
                if not text:
                    continue
                log_path = result_path.with_name(f"{result_path.name}.{suffix}.txt")
                log_path.write_text(text)
                debug_artifacts[suffix] = str(log_path)
            if not debug_artifacts:
                debug_artifacts = None

        return {
            "invocation": {
                "ok": ok,
                "command": command,
                "returncode": process.returncode,
                "timed_out": timed_out,
                "duration_seconds": time.monotonic() - start,
                "stdout": stdout,
                "stderr": stderr,
                "diagnostic_stdout": diagnostic_stdout,
                "sample": None,
                "error": error,
                "debug_artifacts": debug_artifacts,
            },
            "guest_info": guest_info,
            "records_emitted": emitted_records,
        }
    finally:
        if not locals().get("preserve_debug_artifacts", False):
            Path(handle.name).unlink(missing_ok=True)
            Path(result_handle.name).unlink(missing_ok=True)


def build_summary(records: list[dict[str, Any]]) -> dict[str, Any]:
    compile_pairs = [
        record
        for record in records
        if record.get("baseline_compile") and record["baseline_compile"].get("ok")
        and record.get("rejit_compile") and record["rejit_compile"].get("ok")
    ]
    measured_pairs = [
        record
        for record in records
        if record.get("baseline_run") and record["baseline_run"].get("ok")
        and record.get("rejit_run") and record["rejit_run"].get("ok")
    ]
    applied_programs = [record for record in records if record.get("applied_passes")]
    compile_pass_counts = Counter()
    run_pass_counts = Counter()
    for record in records:
        compile_pass_counts.update(record.get("compile_passes_applied") or [])
        run_pass_counts.update(record.get("run_passes_applied") or [])

    failure_reasons = Counter()
    rejit_failures = Counter()
    for record in records:
        if record.get("record_error"):
            failure_reasons[str(record["record_error"])] += 1
            continue
        baseline_compile = record.get("baseline_compile")
        rejit_compile = record.get("rejit_compile")
        baseline_run = record.get("baseline_run")
        rejit_run = record.get("rejit_run")
        if baseline_compile and not baseline_compile.get("ok"):
            failure_reasons[summarize_failure_reason(baseline_compile)] += 1
        if rejit_compile and not rejit_compile.get("ok"):
            failure_reasons[summarize_failure_reason(rejit_compile)] += 1
        if baseline_run and not baseline_run.get("ok"):
            failure_reasons[summarize_failure_reason(baseline_run)] += 1
        if rejit_run and not rejit_run.get("ok"):
            failure_reasons[summarize_failure_reason(rejit_run)] += 1
        if rejit_compile and rejit_compile.get("ok"):
            rejit = ((rejit_compile.get("sample") or {}).get("rejit") or {})
            if rejit.get("requested") and not rejit.get("applied") and rejit.get("error"):
                rejit_failures[str(rejit["error"])] += 1
        if rejit_run and rejit_run.get("ok"):
            rejit = ((rejit_run.get("sample") or {}).get("rejit") or {})
            if rejit.get("requested") and not rejit.get("applied") and rejit.get("error"):
                rejit_failures[str(rejit["error"])] += 1

    size_ratios = [record["size_ratio"] for record in compile_pairs if record.get("size_ratio") is not None]
    exec_ratios = [record["speedup_ratio"] for record in measured_pairs if record.get("speedup_ratio") is not None]

    by_source: list[dict[str, Any]] = []
    grouped_sources: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for record in records:
        grouped_sources[record["source_name"]].append(record)
    for source_name, items in grouped_sources.items():
        source_compile = [item for item in items if item in compile_pairs]
        source_measured = [item for item in items if item in measured_pairs]
        source_size = [item["size_ratio"] for item in source_compile if item.get("size_ratio") is not None]
        source_exec = [item["speedup_ratio"] for item in source_measured if item.get("speedup_ratio") is not None]
        source_row = {
            "source_name": source_name,
            "programs": len(items),
            "compile_pairs": len(source_compile),
            "measured_pairs": len(source_measured),
            "applied_programs": sum(1 for item in items if item.get("applied_passes")),
            "code_size_ratio_geomean": geomean(source_size),
            "exec_ratio_geomean": geomean(source_exec),
            "pass_counts": dict(sorted(Counter(pass_name for item in items for pass_name in item.get("applied_passes") or []).items())),
        }
        by_source.append(source_row)
    by_source.sort(key=lambda item: (-item["programs"], item["source_name"]))

    return {
        "effective_mode": "vm",
        "targets_attempted": len(records),
        "compile_pairs": len(compile_pairs),
        "measured_pairs": len(measured_pairs),
        "applied_programs": len(applied_programs),
        "code_size_ratio_geomean": geomean(size_ratios),
        "code_size_delta_median_pct": statistics.median([record["size_delta_pct"] for record in compile_pairs if record.get("size_delta_pct") is not None]) if compile_pairs else None,
        "exec_ratio_geomean": geomean(exec_ratios),
        "exec_ratio_median": statistics.median(exec_ratios) if exec_ratios else None,
        "exec_ratio_min": min(exec_ratios) if exec_ratios else None,
        "exec_ratio_max": max(exec_ratios) if exec_ratios else None,
        "pass_counts": dict(sorted((compile_pass_counts + run_pass_counts).items())),
        "compile_pass_counts": dict(sorted(compile_pass_counts.items())),
        "run_pass_counts": dict(sorted(run_pass_counts.items())),
        "failure_reasons": dict(failure_reasons.most_common(16)),
        "rejit_failure_reasons": dict(rejit_failures.most_common(16)),
        "by_source": by_source,
    }


def build_markdown(data: dict[str, Any]) -> str:
    summary = data["summary"]
    records = sorted(data["programs"], key=lambda item: (record_target_name(item), item["object_path"], item["program_name"]))
    corpus_build_summary = data.get("corpus_build_summary") or {}
    guest_info = (data.get("guest_smoke") or {}).get("payload")
    lines: list[str] = [
        "# Corpus Batch REJIT Results",
        "",
        f"- Generated: {data['generated_at']}",
        f"- Corpus manifest: `{data['macro_corpus_yaml']}`",
        f"- Corpus build report: `{data['corpus_build_report']}`",
        f"- Runner: `{data['runner_binary']}`",
        f"- Daemon: `{data['daemon_binary']}`",
        "- Requested mode: `strict-vm`",
        f"- Effective mode: `{summary['effective_mode']}`",
        f"- Benchmark profile: `{data.get('benchmark_profile') or 'default'}`",
        f"- Benchmark config: `{data.get('benchmark_config') or 'fallback-defaults'}`",
        f"- Repeat: {data['repeat']}",
        f"- Skip families: `{', '.join(data.get('skip_families') or []) or 'none'}`",
        f"- Target programs: {summary['targets_attempted']}",
        f"- Compile pairs: {summary['compile_pairs']}",
        f"- Measured pairs: {summary['measured_pairs']}",
        f"- REJIT applied programs: {summary['applied_programs']}",
        f"- Code-size ratio geomean (baseline/rejit): {format_ratio(summary['code_size_ratio_geomean'])}",
        f"- Exec-time ratio geomean (baseline/rejit): {format_ratio(summary['exec_ratio_geomean'])}",
    ]
    if corpus_build_summary:
        lines.append(
            f"- Build availability: {corpus_build_summary.get('available_total', 0)} objects "
            f"({corpus_build_summary.get('built_ok', 0)} built, {corpus_build_summary.get('staged_existing', 0)} staged)"
        )
    if guest_info:
        lines.append(f"- Guest kernel: `{guest_info.get('kernel_release', 'unknown')}`")
    lines.append("")

    if summary["pass_counts"]:
        lines.extend(["## Pass Counts", ""])
        lines.extend(
            markdown_table(
                ["Pass", "Compile", "Run", "Total"],
                [
                    [
                        pass_name,
                        summary["compile_pass_counts"].get(pass_name, 0),
                        summary["run_pass_counts"].get(pass_name, 0),
                        total,
                    ]
                    for pass_name, total in summary["pass_counts"].items()
                ],
            )
        )
        lines.append("")

    lines.extend(["## By Project", ""])
    lines.extend(
        markdown_table(
            ["Project", "Programs", "Compile Pairs", "Measured Pairs", "Applied", "Code Ratio", "Exec Ratio"],
            [
                [
                    row["source_name"],
                    row["programs"],
                    row["compile_pairs"],
                    row["measured_pairs"],
                    row["applied_programs"],
                    format_ratio(row["code_size_ratio_geomean"]),
                    format_ratio(row["exec_ratio_geomean"]),
                ]
                for row in summary["by_source"]
            ],
        )
    )
    lines.append("")

    lines.extend(["## Per-Program Results", ""])
    lines.extend(
        markdown_table(
            [
                "Program",
                "Project",
                "Type",
                "Compile Passes",
                "Run Passes",
                "Baseline JIT",
                "REJIT JIT",
                "Code Ratio",
                "Baseline ns",
                "REJIT ns",
                "Exec Ratio",
                "Note",
            ],
            [
                [
                    program_label(record),
                    record["source_name"],
                    record["prog_type_name"],
                    ", ".join(record.get("compile_passes_applied") or []) or "-",
                    ", ".join(record.get("run_passes_applied") or []) or "-",
                    format_ns(((record.get("baseline_compile") or {}).get("sample") or {}).get("jited_prog_len")),
                    format_ns(((record.get("rejit_compile") or {}).get("sample") or {}).get("jited_prog_len")),
                    format_ratio(record.get("size_ratio")),
                    format_ns(((record.get("baseline_run") or {}).get("sample") or {}).get("exec_ns")),
                    format_ns(((record.get("rejit_run") or {}).get("sample") or {}).get("exec_ns")),
                    format_ratio(record.get("speedup_ratio")),
                    record.get("record_error")
                    or (
                        summarize_failure_reason(record.get("rejit_compile"))
                        if record.get("rejit_compile") and not record["rejit_compile"].get("ok")
                        else ""
                    ),
                ]
                for record in records
            ],
        )
    )

    if summary["failure_reasons"]:
        lines.extend(["", "## Top Failure Reasons", ""])
        lines.extend(
            markdown_table(
                ["Reason", "Count"],
                [[reason, count] for reason, count in summary["failure_reasons"].items()],
            )
        )

    if summary["rejit_failure_reasons"]:
        lines.extend(["", "## REJIT Failures", ""])
        lines.extend(
            markdown_table(
                ["Reason", "Count"],
                [[reason, count] for reason, count in summary["rejit_failure_reasons"].items()],
            )
        )

    lines.extend(
        [
            "",
            "## Notes",
            "",
            "- Target selection comes from `macro_corpus.yaml`; selected objects must appear in the strict build report or already exist as prebuilt `corpus/build/*.bpf.o` artifacts on disk.",
            "- In strict VM mode, the framework REJIT guest boots once, keeps `daemon serve` alive for the full batch, and runs baseline compile-only, REJIT compile-only, baseline test_run, and REJIT test_run for each target in that order.",
            "- Default steady-state semantics: the daemon is always started and tries to optimize each program; programs with no applicable sites stay on stock JIT.",
            "- `--blind-apply` switches from per-program policy mode to unconditional daemon auto-scan REJIT.",
            "- Per-program pass columns are the raw `passes_applied` lists emitted by the runner; the summary above only adds basic pass counts.",
            "- Guest batch execution writes records incrementally while keeping one guest boot and one daemon session for the full corpus run.",
            "- The Make-driven `vm-corpus` path is strict VM-only: guest batch failures fail the run instead of falling back to host execution.",
        ]
    )
    return "\n".join(lines) + "\n"


def packet_main(argv: list[str] | None = None) -> int:
    args = parse_packet_args(argv)
    require_minimum(args.repeat, 1, "--repeat")
    skip_families = normalize_skip_families(args.skip_families)
    benchmark_config_path = args.benchmark_config.get("config_path")
    if skip_families and not args.blind_apply:
        raise SystemExit("--skip-families requires --blind-apply")

    if args.guest_info:
        return run_guest_info_mode()
    if args.guest_target_json:
        return run_guest_batch_mode(args)

    macro_corpus_yaml = Path(args.macro_corpus_yaml).resolve()
    if args.output_json == args.default_output_json and args.max_programs is not None:
        output_json = smoke_output_path(ROOT_DIR / "corpus" / "results", "corpus_vm_batch")
    else:
        output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    runner = Path(args.runner).resolve()
    daemon = Path(args.daemon).resolve()
    kernel_tree = Path(args.kernel_tree).resolve()
    kernel_image = Path(args.kernel_image).resolve()
    btf_custom_path = Path(args.btf_custom_path).resolve() if args.btf_custom_path else None
    corpus_build_report_path = Path(args.corpus_build_report).resolve()

    if not macro_corpus_yaml.exists():
        raise SystemExit(f"macro corpus YAML not found: {macro_corpus_yaml}")
    if not runner.exists():
        raise SystemExit(f"runner not found: {runner}")
    if not daemon.exists():
        raise SystemExit(f"daemon not found: {daemon}")
    if not corpus_build_report_path.exists():
        raise SystemExit(f"corpus build report not found: {corpus_build_report_path}")

    run_type = derive_run_type(output_json, "corpus_vm_batch")
    started_at = datetime.now(timezone.utc).isoformat()
    corpus_build_report = load_corpus_build_report(corpus_build_report_path)

    objects, yaml_summary = load_targets_from_yaml(
        yaml_path=macro_corpus_yaml,
        corpus_build_report=corpus_build_report,
        filters=args.filters,
        max_programs=args.max_programs,
    )

    if not kernel_image.exists():
        raise SystemExit(f"kernel image missing: {kernel_image}")
    if btf_custom_path is None or not btf_custom_path.exists():
        raise SystemExit(f"btf path missing: {btf_custom_path}")

    guest_smoke: dict[str, Any] = {"invocation": None, "payload": None}
    object_records: list[dict[str, Any]] = []
    program_records: list[dict[str, Any]] = []
    total_programs = sum(len(obj.programs) for obj in objects)
    print(
        "vm-corpus selection "
        f"profile={args.profile or 'default'} "
        f"manifest_objects={yaml_summary['total_objects']} "
        f"manifest_programs={yaml_summary['total_programs']} "
        f"selected_objects={yaml_summary['selected_objects']} "
        f"selected_programs={yaml_summary['selected_programs']} "
        f"available_objects={yaml_summary['available_objects']}",
        flush=True,
    )
    result = {
        "generated_at": started_at,
        "repo_root": str(ROOT_DIR),
        "macro_corpus_yaml": str(macro_corpus_yaml),
        "corpus_build_report": str(corpus_build_report_path),
        "corpus_build_summary": corpus_build_report.get("summary") or {},
        "yaml_summary": yaml_summary,
        "benchmark_profile": args.profile,
        "benchmark_config": str(benchmark_config_path) if benchmark_config_path is not None else None,
        "runner_binary": str(runner),
        "daemon_binary": str(daemon),
        "kernel_tree": str(kernel_tree),
        "kernel_image": str(kernel_image),
        "btf_custom_path": str(btf_custom_path) if btf_custom_path is not None else None,
        "vng_binary": args.vng,
        "repeat": args.repeat,
        "timeout_seconds": args.timeout,
        "guest_smoke": guest_smoke,
        "skip_families": skip_families,
        "blind_apply": args.blind_apply,
        "summary": build_summary_v2(program_records, object_records),
        "object_records": object_records,
        "program_records": program_records,
    }
    current_target: dict[str, Any] | None = None
    current_target_index: int | None = None

    def build_artifact_metadata(
        status: str,
        session_started_at: str,
        updated_at: str,
        error_message: str | None,
    ) -> dict[str, Any]:
        result["summary"] = build_summary_v2(program_records, object_records)
        progress = {
            "status": status,
            "total_objects": len(objects),
            "completed_objects": len(object_records),
            "total_programs": total_programs,
            "completed_programs": len(program_records),
            "current_target_index": current_target_index,
            "current_target": current_target,
        }
        if error_message:
            progress["error_message"] = error_message

        metadata = build_corpus_artifact_metadata(
            generated_at=str(result["generated_at"]),
            run_type=run_type,
            mode_name="packet",
            output_json=output_json,
            output_md=output_md,
            summary=dict(result["summary"]),
            progress=progress,
            extra_fields={
                "macro_corpus_yaml": repo_relative_path(macro_corpus_yaml),
                "corpus_build_report": repo_relative_path(corpus_build_report_path),
                "corpus_build_summary": corpus_build_report.get("summary") or {},
                "yaml_summary": yaml_summary,
                "benchmark_profile": args.profile,
                "benchmark_config": repo_relative_path(benchmark_config_path) if benchmark_config_path is not None else None,
                "runner_binary": repo_relative_path(runner),
                "daemon_binary": repo_relative_path(daemon),
                "kernel_tree": repo_relative_path(kernel_tree),
                "kernel_image": repo_relative_path(kernel_image),
                "btf_custom_path": repo_relative_path(btf_custom_path) if btf_custom_path is not None else None,
                "vng_binary": args.vng,
                "repeat": args.repeat,
                "timeout_seconds": args.timeout,
                "skip_families": skip_families,
                "blind_apply": bool(args.blind_apply),
                "guest_smoke": guest_smoke,
                "started_at": session_started_at,
                "last_updated_at": updated_at,
                "status": status,
            },
        )
        if error_message:
            metadata["error_message"] = error_message
        return metadata

    session = ArtifactSession(
        output_path=output_json,
        run_type=run_type,
        generated_at=started_at,
        metadata_builder=build_artifact_metadata,
    )
    artifact_dir = session.run_dir

    def flush_artifact(status: str, *, error_message: str | None = None, include_markdown: bool = False) -> None:
        result["summary"] = build_summary_v2(program_records, object_records)
        progress = {
            "status": status,
            "total_objects": len(objects),
            "completed_objects": len(object_records),
            "total_programs": total_programs,
            "completed_programs": len(program_records),
            "current_target_index": current_target_index,
            "current_target": current_target,
        }
        if error_message:
            progress["error_message"] = error_message
        detail_texts = {"result.md": build_markdown_v2(result)} if include_markdown else None
        session.write(
            status=status,
            progress_payload=progress,
            result_payload=result,
            detail_texts=detail_texts,
            error_message=error_message,
        )

    flush_artifact("running")
    try:
        def handle_guest_info(payload: dict[str, Any]) -> None:
            guest_smoke["payload"] = payload
            flush_artifact("running")

        def handle_guest_record(index: int, record: dict[str, Any]) -> None:
            nonlocal current_target_index, current_target
            current_target_index = index
            current_target = (
                {"canonical_object_name": objects[index - 1].canonical_name}
                if index - 1 < len(objects)
                else None
            )
            object_record = record.get("object_record")
            program_bundle = record.get("program_records")
            if isinstance(object_record, dict):
                object_records.append(object_record)
            if isinstance(program_bundle, list):
                for item in program_bundle:
                    if isinstance(item, dict):
                        program_records.append(item)
            flush_artifact("running")

        batch_result = run_targets_in_guest_batch(
            targets=objects,
            runner=runner,
            daemon=daemon,
            kernel_image=kernel_image,
            btf_custom_path=btf_custom_path,
            profile=args.profile,
            repeat=args.repeat,
            timeout_seconds=args.timeout,
            vng_binary=args.vng,
            skip_families=skip_families,
            blind_apply=args.blind_apply,
            on_guest_info=handle_guest_info,
            on_record=handle_guest_record,
        )
        guest_invocation = batch_text_invocation_summary(batch_result["invocation"])
        guest_smoke["invocation"] = guest_invocation
        for record in object_records:
            record["guest_invocation"] = dict(guest_invocation) if guest_invocation is not None else None
        for record in program_records:
            record["guest_invocation"] = dict(guest_invocation) if guest_invocation is not None else None

        if not guest_smoke.get("payload"):
            smoke_error = (guest_smoke.get("invocation") or {}).get("error") or "guest smoke failed"
            raise RuntimeError(f"vm guest smoke failed: {smoke_error}")
        if not batch_result["invocation"]["ok"]:
            batch_error = batch_result["invocation"]["error"] or "guest batch failed"
            raise RuntimeError(f"vm guest batch failed: {batch_error}")

        current_target = None
        current_target_index = None
        flush_artifact("completed", include_markdown=True)
    except Exception as exc:
        flush_artifact("error", error_message=str(exc))
        raise
    summary = dict(result["summary"])
    print(f"Wrote {artifact_dir / 'metadata.json'}")
    print(
        f"mode={summary['effective_mode']} "
        f"objects={summary['objects_attempted']} "
        f"targets={summary['targets_attempted']} "
        f"compile_pairs={summary['compile_pairs']} "
        f"measured_pairs={summary['measured_pairs']} "
        f"applied={summary['applied_programs']}"
    )
    return 0
