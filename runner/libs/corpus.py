from __future__ import annotations

import argparse
from dataclasses import asdict, dataclass
import json
import math
import os
import shutil
import subprocess
import sys
import tempfile
import time
from pathlib import Path
from typing import Any, Mapping, Sequence

import yaml

from . import ROOT_DIR, ensure_parent, resolve_bpftool_binary, run_command, run_json_command, tail_text, which
from .agent import find_bpf_programs, stop_agent, wait_healthy
from .batch_runner import run_batch_runner
from .metrics import enable_bpf_stats, sample_bpf_stats
from .object_discovery import supplement_with_existing_corpus_build_objects
from .rejit import (
    _start_daemon_server,
    _stop_daemon_server,
    apply_daemon_rejit,
    benchmark_config_enabled_passes,
    benchmark_policy_required_site_passes,
    resolve_program_enabled_passes,
)
from .results import parse_runner_sample


def relpath(path: Path | str, root_dir: Path) -> str:
    candidate = Path(path)
    try:
        return candidate.relative_to(root_dir).as_posix()
    except ValueError:
        return str(candidate)


_DEFAULT_CORPUS_BATCH_SIZE = 100
_DEFAULT_APP_NATIVE_LOAD_TIMEOUT_SECONDS = 60
_BATCH_RESOURCE_ERROR_SUBSTRINGS = (
    "cannot allocate memory",
    "enomem",
    "too many open files",
    "emfile",
    "enfile",
)


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
    loader: str = "generic"
    loader_binary: str | None = None
    loader_args: tuple[str, ...] = ()
    loader_setup_script: str | None = None
    loader_timeout_seconds: int | None = None


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
    loader: str = "generic"
    loader_binary: str | None = None
    loader_args: tuple[str, ...] = ()
    loader_setup_script: str | None = None
    loader_timeout_seconds: int | None = None


def normalize_passes(value: Any) -> list[str]:
    if not isinstance(value, list):
        return []
    return [str(item) for item in value if str(item)]


def program_policy_context(program: ResolvedProgram) -> dict[str, Any]:
    return {
        "repo": program.repo,
        "object": program.object_basename,
        "object_relpath": program.object_relpath,
        "object_path": program.object_path,
        "program": program.program_name,
        "section": program.section_name,
        "prog_type": program.prog_type_name,
        "test_method": program.test_method,
        "attach_group": program.attach_group,
        "family": program.family,
        "category": program.category,
        "level": program.level,
    }


def _site_counts_from_static_verify_record(record: Mapping[str, Any]) -> dict[str, int]:
    raw_details = record.get("daemon_pass_details")
    if not isinstance(raw_details, list):
        return {}
    counts: dict[str, int] = {}
    for item in raw_details:
        if not isinstance(item, Mapping):
            continue
        pass_name = str(item.get("pass_name") or "").strip()
        if not pass_name:
            continue
        try:
            count = int(item.get("sites_found") or item.get("sites_applied") or 0)
        except (TypeError, ValueError):
            continue
        counts[pass_name] = counts.get(pass_name, 0) + max(0, count)
    return counts


def _build_program_site_scan_jobs(
    *,
    objects: list[ResolvedObject],
    daemon_socket: str,
    enabled_passes: list[str],
) -> tuple[list[dict[str, Any]], dict[str, ResolvedObject]]:
    jobs: list[dict[str, Any]] = []
    objects_by_job_id: dict[str, ResolvedObject] = {}
    for index, obj in enumerate(objects, start=1):
        job_id = f"site-scan-{index:04d}"
        jobs.append(
            {
                "id": job_id,
                "type": "static_verify_object",
                "execution": "serial",
                "object": str(ROOT_DIR / obj.object_path),
                "object_index": index,
                "daemon_socket": daemon_socket,
                "enabled_passes": list(enabled_passes),
            }
        )
        objects_by_job_id[job_id] = obj
    return jobs, objects_by_job_id


def scan_program_site_counts(
    *,
    objects: list[ResolvedObject],
    runner: Path,
    daemon_socket: str,
    enabled_passes: list[str],
    timeout_seconds: int,
) -> dict[str, dict[str, int]]:
    if not objects or not enabled_passes:
        return {}

    jobs, objects_by_job_id = _build_program_site_scan_jobs(
        objects=objects,
        daemon_socket=daemon_socket,
        enabled_passes=enabled_passes,
    )
    batch_result = run_batch_runner(
        runner,
        spec_payload={
            "schema_version": 1,
            "scheduler": {
                "max_parallel_jobs": 1,
            },
            "jobs": jobs,
        },
        timeout_seconds=packet_batch_timeout_seconds(max(1, len(objects)), timeout_seconds),
        cwd=ROOT_DIR,
    )
    result_payload = batch_result.get("result")
    if not isinstance(result_payload, Mapping):
        return {}

    raw_jobs = result_payload.get("jobs")
    if not isinstance(raw_jobs, list):
        return {}

    counts_by_program: dict[str, dict[str, int]] = {}
    for raw_job in raw_jobs:
        if not isinstance(raw_job, Mapping):
            continue
        job_id = str(raw_job.get("id") or "").strip()
        obj = objects_by_job_id.get(job_id)
        if obj is None:
            continue
        payload = raw_job.get("payload")
        records = payload.get("records") if isinstance(payload, Mapping) else None
        if not isinstance(records, list):
            continue
        programs_by_name = {program.program_name: program for program in obj.programs}
        for raw_record in records:
            if not isinstance(raw_record, Mapping):
                continue
            program_name = str(raw_record.get("prog_name") or "").strip()
            program = programs_by_name.get(program_name)
            if program is None:
                continue
            counts_by_program[program.canonical_name] = _site_counts_from_static_verify_record(raw_record)
    return counts_by_program


def resolve_program_enabled_passes_map(
    *,
    objects: list[ResolvedObject],
    benchmark_config: Mapping[str, Any] | None,
    runner: Path,
    daemon_socket: str,
    timeout_seconds: int,
    enabled_passes: list[str] | None = None,
) -> dict[str, list[str]]:
    if enabled_passes is not None:
        return {
            program.canonical_name: list(enabled_passes)
            for obj in objects
            for program in obj.programs
        }

    fallback_passes = benchmark_config_enabled_passes(benchmark_config)
    site_passes = benchmark_policy_required_site_passes(benchmark_config)
    site_counts_by_program = scan_program_site_counts(
        objects=objects,
        runner=runner,
        daemon_socket=daemon_socket,
        enabled_passes=site_passes,
        timeout_seconds=timeout_seconds,
    ) if site_passes else {}

    return {
        program.canonical_name: resolve_program_enabled_passes(
            benchmark_config,
            context=program_policy_context(program),
            site_counts=site_counts_by_program.get(program.canonical_name),
            fallback_passes=fallback_passes,
        )
        for obj in objects
        for program in obj.programs
    }


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


def _sequence(value: Any, *, field_name: str) -> list[Any]:
    if value is None:
        return []
    if not isinstance(value, list):
        raise SystemExit(f"invalid manifest field: {field_name} must be a sequence")
    return list(value)


def _loader_kind(value: Any) -> str:
    text = _string_or_none(value) or "generic"
    normalized = text.strip().lower()
    if normalized not in {"generic", "app-native"}:
        raise SystemExit(f"invalid loader kind: {value!r}")
    return normalized


def _resolve_repo_loader_configs(manifest: Mapping[str, Any]) -> dict[str, dict[str, Any]]:
    raw_repos = manifest.get("repos")
    if raw_repos is None:
        return {}
    if not isinstance(raw_repos, Mapping):
        raise SystemExit("macro corpus YAML field 'repos' must be a mapping")

    configs: dict[str, dict[str, Any]] = {}
    for raw_repo_name, raw_config in raw_repos.items():
        repo_name = str(raw_repo_name).strip()
        if not repo_name:
            raise SystemExit("macro corpus YAML field 'repos' contains an empty repo name")
        if not isinstance(raw_config, Mapping):
            raise SystemExit(f"macro corpus YAML repos[{repo_name!r}] must be a mapping")
        loader_args = _sequence(raw_config.get("loader_args"), field_name=f"repos[{repo_name!r}].loader_args")
        configs[repo_name.lower()] = {
            "loader": _loader_kind(raw_config.get("loader")),
            "loader_binary": _string_or_none(raw_config.get("loader_binary")),
            "loader_args": tuple(str(item) for item in loader_args if str(item).strip()),
            "loader_setup_script": _string_or_none(raw_config.get("loader_setup_script")),
            "loader_timeout_seconds": _int_or_default(
                raw_config.get("loader_timeout_seconds"),
                _DEFAULT_APP_NATIVE_LOAD_TIMEOUT_SECONDS,
            ),
        }
    return configs


def _repo_loader_config_for(
    repo: str,
    repo_loader_configs: Mapping[str, Mapping[str, Any]] | None,
) -> Mapping[str, Any]:
    if repo_loader_configs is None:
        return {}
    return repo_loader_configs.get(repo.lower(), {})


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
    base = dict(payload)
    base["programs"] = tuple(programs)
    base.setdefault("fixture_path", None)
    return ResolvedObject(**base)


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
        loader=obj.loader,
        loader_binary=obj.loader_binary,
        loader_args=obj.loader_args,
        loader_setup_script=obj.loader_setup_script,
        loader_timeout_seconds=obj.loader_timeout_seconds,
    )


def resolve_manifest_object(
    entry: Mapping[str, Any],
    *,
    index: int,
    repo_loader_configs: Mapping[str, Mapping[str, Any]] | None = None,
) -> ResolvedObject:
    source = _string_or_none(entry.get("source"))
    if source is None:
        raise SystemExit(f"manifest object #{index} missing source")
    object_candidate = Path(source)
    object_path = object_candidate if object_candidate.is_absolute() else (ROOT_DIR / object_candidate)
    repo_from_source, object_relpath = split_corpus_source(source, _string_or_none(entry.get("family")) or "")
    repo = _string_or_none(entry.get("repo")) or repo_from_source or (
        _string_or_none(entry.get("family")) or object_candidate.name
    )
    repo_loader_config = _repo_loader_config_for(repo, repo_loader_configs)
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
    loader = _loader_kind(entry.get("loader") if "loader" in entry else repo_loader_config.get("loader"))
    loader_binary = _string_or_none(entry.get("loader_binary")) or _string_or_none(repo_loader_config.get("loader_binary"))
    loader_args = tuple(
        str(item).strip()
        for item in (
            _sequence(entry.get("loader_args"), field_name=f"objects[{index}].loader_args")
            if entry.get("loader_args") is not None
            else list(repo_loader_config.get("loader_args") or [])
        )
        if str(item).strip()
    )
    loader_setup_script = (
        _string_or_none(entry.get("loader_setup_script"))
        or _string_or_none(repo_loader_config.get("loader_setup_script"))
    )
    loader_timeout_seconds = _int_or_default(
        entry.get("loader_timeout_seconds")
        if entry.get("loader_timeout_seconds") is not None
        else repo_loader_config.get("loader_timeout_seconds"),
        _DEFAULT_APP_NATIVE_LOAD_TIMEOUT_SECONDS,
    )
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
                loader=loader,
                loader_binary=loader_binary,
                loader_args=loader_args,
                loader_setup_script=loader_setup_script,
                loader_timeout_seconds=loader_timeout_seconds,
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
        loader=loader,
        loader_binary=loader_binary,
        loader_args=loader_args,
        loader_setup_script=loader_setup_script,
        loader_timeout_seconds=loader_timeout_seconds,
    )


def find_program_in_object(
    obj: ResolvedObject,
    program_name: str,
) -> ResolvedProgram | None:
    for program in obj.programs:
        if program.program_name == program_name:
            return program
    return None


def attach_trigger_unsupported_reason(
    obj: ResolvedObject,
    program: ResolvedProgram,
) -> str | None:
    candidate = program
    if program.attach_group:
        grouped = find_program_in_object(obj, program.attach_group)
        if grouped is not None:
            candidate = grouped

    section_name = str(candidate.section_name or "").strip()
    if not section_name:
        return "attach_trigger requires a non-empty auto-attach section; got empty section"

    parts = section_name.split("/")
    root = parts[0]
    root_prefixes = ("kprobe", "kretprobe", "fentry", "fexit", "fmod_ret", "lsm")

    if len(parts) == 3 and root in {"tracepoint", "tp"} and all(parts[1:]):
        return None
    if len(parts) >= 2 and root in {"raw_tracepoint", "raw_tp", "tp_btf"} and all(parts[1:]):
        return None
    if root in {"ksyscall", "kretsyscall"} and len(parts) == 2 and all(parts[1:]):
        return None
    if root.startswith(root_prefixes):
        if len(parts) == 1:
            if "." in root:
                return None
        elif all(parts[1:]):
            return None

    return (
        "attach_trigger does not currently recognize the section as an auto-triggerable "
        "kernel event hook; "
        f"got {section_name}"
    )


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


def load_targets_from_yaml(
    yaml_path: Path,
    corpus_build_report: dict[str, Any],
    filters: list[str] | None = None,
    max_programs: int | None = None,
) -> tuple[list[ResolvedObject], dict[str, Any]]:
    manifest = yaml.safe_load(yaml_path.read_text(encoding="utf-8"))
    if not isinstance(manifest, dict):
        raise SystemExit(f"macro corpus YAML root must be a mapping: {yaml_path}")
    if int(manifest.get("schema_version", 0) or 0) != 2 or "objects" not in manifest:
        raise SystemExit(f"macro corpus YAML must use schema_version: 2 objects format: {yaml_path}")

    repo_loader_configs = _resolve_repo_loader_configs(manifest)
    raw_objects = _sequence(manifest.get("objects"), field_name="objects")
    resolved_objects = [
        resolve_manifest_object(entry, index=index, repo_loader_configs=repo_loader_configs)
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
            selected_programs = tuple(
                program for program in obj.programs if program_matches_filter(program, lowered_filters)
            )
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
    report_available_total = int(
        build_summary_payload.get("available_total", len(available_objects)) or len(available_objects)
    )
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



def add_output_json_argument(
    parser: argparse.ArgumentParser,
    default: Path | str,
    *,
    help_text: str = "Path for structured JSON output.",
) -> None:
    parser.add_argument("--output-json", default=str(default), help=help_text)


def add_output_md_argument(
    parser: argparse.ArgumentParser,
    default: Path | str,
    *,
    help_text: str = "Path for markdown output.",
) -> None:
    parser.add_argument("--output-md", default=str(default), help=help_text)


def add_runner_argument(
    parser: argparse.ArgumentParser,
    default: Path | str | None = None,
    *,
    help_text: str,
) -> None:
    kwargs: dict[str, Any] = {"help": help_text}
    if default is not None:
        kwargs["default"] = str(default)
    parser.add_argument("--runner", **kwargs)


def add_daemon_argument(
    parser: argparse.ArgumentParser,
    default: Path | str,
    *,
    help_text: str,
) -> None:
    parser.add_argument("--daemon", default=str(default), help=help_text)


def add_repeat_argument(
    parser: argparse.ArgumentParser,
    default: int | None = None,
    *,
    help_text: str,
) -> None:
    kwargs: dict[str, Any] = {"type": int, "help": help_text}
    if default is not None:
        kwargs["default"] = default
    parser.add_argument("--repeat", **kwargs)


def add_timeout_argument(
    parser: argparse.ArgumentParser,
    default: int,
    *,
    help_text: str,
) -> None:
    parser.add_argument("--timeout", type=int, default=default, help=help_text)


def add_filter_argument(
    parser: argparse.ArgumentParser,
    *,
    help_text: str,
) -> None:
    parser.add_argument("--filter", action="append", dest="filters", help=help_text)


def add_max_programs_argument(
    parser: argparse.ArgumentParser,
    *,
    help_text: str,
) -> None:
    parser.add_argument("--max-programs", type=int, help=help_text)


def require_minimum(value: int, minimum: int, flag: str) -> None:
    if value < minimum:
        raise SystemExit(f"{flag} must be >= {minimum}")


def _ipv4_checksum(header: bytes | bytearray) -> int:
    """Compute RFC 791 one's complement checksum over a 20-byte IPv4 header."""
    s = 0
    for i in range(0, len(header), 2):
        s += (header[i] << 8) + header[i + 1]
    while s >> 16:
        s = (s & 0xFFFF) + (s >> 16)
    return ~s & 0xFFFF


def _checksum16(data: bytes | bytearray) -> int:
    blob = bytes(data)
    if len(blob) % 2:
        blob += b"\x00"
    total = 0
    for i in range(0, len(blob), 2):
        total += (blob[i] << 8) + blob[i + 1]
    while total >> 16:
        total = (total & 0xFFFF) + (total >> 16)
    return ~total & 0xFFFF


def _tcp_ipv4_checksum(src_ip: bytes, dst_ip: bytes, segment: bytes | bytearray) -> int:
    pseudo_header = bytearray(12)
    pseudo_header[0:4] = src_ip
    pseudo_header[4:8] = dst_ip
    pseudo_header[9] = 6
    pseudo_header[10:12] = len(segment).to_bytes(2, "big")
    return _checksum16(pseudo_header + bytes(segment))


# Expected content of the canonical corpus dummy packet (version tag at bytes 0-5 of MAC dst).
# Bumping this sentinel forces regeneration when the packet layout is updated.
_CORPUS_PACKET_MAGIC = bytes.fromhex("ffffffffffff")  # broadcast dst MAC as version sentinel
_KATRAN_PACKET_MAGIC = bytes.fromhex("02000000000a")  # Katran LB MAC as version sentinel

# Keep these values in sync with e2e/cases/katran/case.py.
_KATRAN_CLIENT_IP = bytes([10, 0, 0, 2])
_KATRAN_VIP_IP = bytes([10, 100, 1, 1])
_KATRAN_CLIENT_MAC = bytes.fromhex("02000000001c")
_KATRAN_LB_MAC = bytes.fromhex("02000000000a")
_KATRAN_SRC_PORT = 31337
_KATRAN_DST_PORT = 8080
_KATRAN_TCP_ACK = 0x10
_KATRAN_PAYLOAD = b"KATRANVIP!"


def _build_ipv4_tcp_packet(
    *,
    dst_mac: bytes,
    src_mac: bytes,
    src_ip: bytes,
    dst_ip: bytes,
    src_port: int,
    dst_port: int,
    payload: bytes,
    tcp_flags: int,
) -> bytearray:
    ip_total_length = 20 + 20 + len(payload)
    packet = bytearray(max(64, 14 + ip_total_length))

    packet[0:6] = dst_mac
    packet[6:12] = src_mac
    packet[12:14] = bytes.fromhex("0800")

    packet[14] = 0x45
    packet[15] = 0x00
    packet[16:18] = ip_total_length.to_bytes(2, "big")
    packet[18:20] = (0).to_bytes(2, "big")
    packet[20:22] = (0x4000).to_bytes(2, "big")
    packet[22] = 64
    packet[23] = 6
    packet[24:26] = (0).to_bytes(2, "big")
    packet[26:30] = src_ip
    packet[30:34] = dst_ip
    packet[24:26] = _ipv4_checksum(packet[14:34]).to_bytes(2, "big")

    packet[34:36] = int(src_port).to_bytes(2, "big")
    packet[36:38] = int(dst_port).to_bytes(2, "big")
    packet[38:42] = (1).to_bytes(4, "big")
    packet[42:46] = (0).to_bytes(4, "big")
    packet[46] = 0x50
    packet[47] = int(tcp_flags & 0xFF)
    packet[48:50] = (8192).to_bytes(2, "big")
    packet[50:52] = (0).to_bytes(2, "big")
    packet[52:54] = (0).to_bytes(2, "big")
    packet[54 : 54 + len(payload)] = payload
    packet[50:52] = _tcp_ipv4_checksum(src_ip, dst_ip, packet[34 : 54 + len(payload)]).to_bytes(2, "big")
    return packet


def _build_corpus_packet() -> bytearray:
    """
    Build a 64-byte canonical Ethernet/IPv4/TCP packet for corpus measurements.

    Layout:
      Ethernet (14B): dst=ff:ff:ff:ff:ff:ff, src=00:11:22:33:44:55, EtherType=0x0800
      IPv4 (20B):     version=4, IHL=5, tot_len=50, proto=TCP(6),
                      src=10.0.0.1, dst=10.0.0.2, correct checksum
      TCP (20B):      src_port=12345, dst_port=80, seq=1, flags=SYN, data_offset=5
      Payload (10B):  0x41 ('A') * 10
    """
    packet = bytearray(64)

    # Ethernet header
    packet[0:6] = bytes.fromhex("ffffffffffff")   # dst MAC (broadcast)
    packet[6:12] = bytes.fromhex("001122334455")  # src MAC
    packet[12:14] = bytes.fromhex("0800")          # EtherType = IPv4

    # IPv4 header (checksum field zeroed first, then filled)
    packet[14] = 0x45        # version=4, IHL=5
    packet[15] = 0x00        # DSCP/ECN
    packet[16:18] = (50).to_bytes(2, "big")       # total length (20 IP + 20 TCP + 10 data)
    packet[18:20] = (0).to_bytes(2, "big")         # identification
    packet[20:22] = (0x4000).to_bytes(2, "big")    # flags=DF, frag_offset=0
    packet[22] = 64           # TTL
    packet[23] = 6            # protocol = TCP
    packet[24:26] = (0).to_bytes(2, "big")         # checksum placeholder
    packet[26:30] = bytes([10, 0, 0, 1])           # src IP = 10.0.0.1
    packet[30:34] = bytes([10, 0, 0, 2])           # dst IP = 10.0.0.2

    # Compute and fill IPv4 checksum over the 20-byte IP header
    chk = _ipv4_checksum(packet[14:34])
    packet[24:26] = chk.to_bytes(2, "big")

    # TCP header
    packet[34:36] = (12345).to_bytes(2, "big")     # src_port
    packet[36:38] = (80).to_bytes(2, "big")         # dst_port
    packet[38:42] = (1).to_bytes(4, "big")          # seq = 1
    packet[42:46] = (0).to_bytes(4, "big")          # ack = 0
    packet[46] = 0x50        # data_offset=5 (no options)
    packet[47] = 0x02        # flags = SYN
    packet[48:50] = (8192).to_bytes(2, "big")       # window
    packet[50:52] = (0).to_bytes(2, "big")          # TCP checksum (0; not verified by XDP)
    packet[52:54] = (0).to_bytes(2, "big")          # urgent pointer

    # Payload
    packet[54:64] = bytes([0x41] * 10)              # 'A' * 10

    return packet


def _build_katran_packet() -> bytearray:
    return _build_ipv4_tcp_packet(
        dst_mac=_KATRAN_LB_MAC,
        src_mac=_KATRAN_CLIENT_MAC,
        src_ip=_KATRAN_CLIENT_IP,
        dst_ip=_KATRAN_VIP_IP,
        src_port=_KATRAN_SRC_PORT,
        dst_port=_KATRAN_DST_PORT,
        payload=_KATRAN_PAYLOAD,
        tcp_flags=_KATRAN_TCP_ACK,
    )


def materialize_dummy_packet(path: Path) -> Path:
    ensure_parent(path)
    # Regenerate if the file is absent, wrong size, or does not start with the
    # current magic bytes (which change when the packet layout is updated).
    if path.exists() and path.stat().st_size == 64:
        existing = path.read_bytes()
        if existing[0:6] == _CORPUS_PACKET_MAGIC:
            return path

    packet = _build_corpus_packet()
    path.write_bytes(packet)
    return path


def materialize_katran_packet(path: Path) -> Path:
    ensure_parent(path)
    if path.exists() and path.stat().st_size == 64:
        existing = path.read_bytes()
        if existing[0:6] == _KATRAN_PACKET_MAGIC:
            return path

    packet = _build_katran_packet()
    path.write_bytes(packet)
    return path


def materialize_dummy_context(path: Path, size: int = 64) -> Path:
    ensure_parent(path)
    if path.exists() and path.stat().st_size == size:
        return path
    path.write_bytes(bytes(size))
    return path


def summarize_text(text: str | bytes, max_lines: int = 20, max_chars: int = 4000) -> str:
    if isinstance(text, bytes):
        text = text.decode("utf-8", errors="replace")
    lines = [line.rstrip() for line in text.splitlines() if line.strip()]
    if len(lines) > max_lines:
        lines = lines[-max_lines:]
    summary = "\n".join(lines)
    if len(summary) > max_chars:
        summary = summary[-max_chars:]
    return summary



def extract_error(stderr: str, stdout: str, returncode: int | None) -> str:
    for text in (stderr, stdout):
        lines = [line.strip() for line in text.splitlines() if line.strip()]
        if lines:
            return f"{lines[-1]} (exit={returncode})"
    return f"command failed (exit={returncode})"


def run_command(
    command: list[str],
    timeout_seconds: int,
    *,
    cwd: Path,
    expect_json: bool = True,
) -> dict[str, Any]:
    start = time.monotonic()
    try:
        completed = subprocess.run(
            command,
            cwd=cwd,
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
        )
    except subprocess.TimeoutExpired as exc:
        # exc.stdout/stderr may be bytes even with text=True
        raw_stdout = exc.stdout or ""
        raw_stderr = exc.stderr or ""
        if isinstance(raw_stdout, bytes):
            raw_stdout = raw_stdout.decode("utf-8", errors="replace")
        if isinstance(raw_stderr, bytes):
            raw_stderr = raw_stderr.decode("utf-8", errors="replace")
        return {
            "ok": False,
            "command": command,
            "returncode": None,
            "timed_out": True,
            "duration_seconds": time.monotonic() - start,
            "stdout": raw_stdout,
            "stderr": raw_stderr,
            "sample": None,
            "error": f"timeout after {timeout_seconds}s",
        }

    stdout = completed.stdout or ""
    stderr = completed.stderr or ""
    sample = None
    parse_error = None
    if completed.returncode == 0 and expect_json:
        try:
            sample = parse_runner_sample(stdout)
        except Exception as exc:  # pragma: no cover
            parse_error = str(exc)

    ok = completed.returncode == 0 and (sample is not None if expect_json else True)
    error = parse_error if parse_error is not None else None
    if not ok and error is None:
        error = extract_error(stderr, stdout, completed.returncode)

    return {
        "ok": ok,
        "command": command,
        "returncode": completed.returncode,
        "timed_out": False,
        "duration_seconds": time.monotonic() - start,
        "stdout": stdout,
        "stderr": stderr,
        "sample": sample,
        "error": error,
    }


def run_text_command(command: list[str], timeout_seconds: int, *, cwd: Path) -> dict[str, Any]:
    result = run_command(command, timeout_seconds, cwd=cwd, expect_json=False)
    result.setdefault("sample", None)
    return result


def write_json_output(path: Path, payload: Any) -> None:
    ensure_parent(path)
    path.write_text(json.dumps(payload, indent=2) + "\n")


def write_text_output(path: Path, text: str) -> None:
    ensure_parent(path)
    path.write_text(text)


def parse_runner_json(stdout: str) -> dict[str, Any]:
    return dict(parse_runner_sample(stdout))


def invocation_summary(result: Mapping[str, Any] | None) -> dict[str, Any] | None:
    if result is None:
        return None
    return {
        "ok": bool(result.get("ok")),
        "returncode": result.get("returncode"),
        "timed_out": bool(result.get("timed_out")),
        "duration_seconds": result.get("duration_seconds"),
        "error": result.get("error"),
        "stderr_tail": summarize_text(str(result.get("stderr", ""))),
        "sample": result.get("sample"),
    }


def normalize_section_root(section_name: str) -> str:
    if not section_name:
        return "unknown"
    root = section_name.split("/", 1)[0]
    if root.startswith("kprobe"):
        return "kprobe"
    if root.startswith("kretprobe"):
        return "kretprobe"
    if root.startswith("raw_tp"):
        return "raw_tp"
    return root


def infer_program_kind(section_name: str) -> str:
    root = normalize_section_root(section_name)
    if root in {"xdp", "socket", "classifier", "tc", "flow_dissector", "sk_skb", "sk_msg"}:
        return root
    if root in {"kprobe", "kretprobe", "tracepoint", "raw_tracepoint", "raw_tp"}:
        return "tracing"
    if root in {"fentry", "fexit", "fmod_ret", "lsm"}:
        return "tracing"
    if root in {"uprobe", "uretprobe", "usdt"}:
        return "tracing"
    if root in {"perf_event", "iter", "syscall", "struct_ops"}:
        return root
    return root


def execution_plan(section_name: str, packet_path: Path, context_path: Path) -> dict[str, Any]:
    root = normalize_section_root(section_name)
    if root in {"xdp", "socket", "classifier", "tc", "flow_dissector", "sk_skb", "sk_msg"}:
        return {
            "io_mode": "packet",
            "memory_path": packet_path,
            "input_size": 64,
        }
    if root in {"raw_tracepoint", "raw_tp"}:
        return {
            "io_mode": "context",
            "memory_path": context_path,
            "input_size": 64,
        }
    return {
        "io_mode": "context",
        "memory_path": None,
        "input_size": 0,
    }


def text_invocation_summary(result: Mapping[str, Any] | None) -> dict[str, Any] | None:
    if result is None:
        return None
    payload = invocation_summary(result)
    if payload is None:
        return None
    payload["stdout_tail"] = summarize_text(str(result.get("stdout", "")))
    return payload


def program_label(record: Mapping[str, Any]) -> str:
    return f"{record['object_path']}:{record['program_name']}"


def markdown_table(headers: list[str], rows: list[list[Any]]) -> list[str]:
    lines = [
        "| " + " | ".join(headers) + " |",
        "| " + " | ".join("---" for _ in headers) + " |",
    ]
    for row in rows:
        lines.append("| " + " | ".join(str(cell) for cell in row) + " |")
    return lines


def format_ns(value: Any) -> str:
    if value is None:
        return "n/a"
    return str(int(value))


def geomean(values: list[float | int | None]) -> float | None:
    filtered = [float(value) for value in values if value is not None and float(value) > 0.0]
    if not filtered:
        return None
    return math.exp(sum(math.log(value) for value in filtered) / len(filtered))


def format_ratio(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.3f}x"


def format_pct(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:+.1f}%"


def summarize_failure_reason(record: Mapping[str, Any] | None) -> str:
    if not record:
        return "n/a"
    error = record.get("error")
    if error:
        return str(error)
    sample = record.get("sample") or {}
    rejit = sample.get("rejit") if isinstance(sample, Mapping) else {}
    if isinstance(rejit, Mapping) and rejit.get("error"):
        return str(rejit["error"])
    return "unknown"


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


def sample_field(
    record: Mapping[str, Any] | None,
    field_name: str,
) -> Any:
    if not isinstance(record, Mapping):
        return None
    sample = record.get("sample")
    if not isinstance(sample, Mapping):
        return None
    return sample.get(field_name)


def comparison_exclusion_reason(
    *,
    obj: ResolvedObject,
    program: ResolvedProgram,
    baseline_record: dict[str, Any] | None,
    rejit_record: dict[str, Any] | None,
) -> str | None:
    if program.test_method == "compile_only":
        return None
    if not baseline_record or not rejit_record:
        return None
    if not baseline_record.get("ok") or not rejit_record.get("ok"):
        return None
    if speedup_ratio(baseline_record, rejit_record) is not None:
        return None

    baseline_exec_ns = sample_field(baseline_record, "exec_ns")
    rejit_exec_ns = sample_field(rejit_record, "exec_ns")
    baseline_run_cnt = sample_field(baseline_record, "result")
    rejit_run_cnt = sample_field(rejit_record, "result")

    if program.test_method == "attach_trigger":
        unsupported_reason = attach_trigger_unsupported_reason(obj, program)
        if unsupported_reason is not None:
            return f"attach_trigger measurement unsupported: {unsupported_reason}"
        if baseline_run_cnt == 0 and rejit_run_cnt == 0:
            return "attach_trigger did not fire the target program in baseline or REJIT (run_cnt_delta=0)"
        if baseline_run_cnt == 0:
            return "attach_trigger did not fire the target program in baseline (run_cnt_delta=0)"
        if rejit_run_cnt == 0:
            return "attach_trigger did not fire the target program in REJIT (run_cnt_delta=0)"
        if baseline_exec_ns == 0 and rejit_exec_ns == 0:
            return "attach_trigger produced exec_ns=0 in baseline and REJIT"
        if baseline_exec_ns == 0:
            return "attach_trigger produced exec_ns=0 in baseline"
        if rejit_exec_ns == 0:
            return "attach_trigger produced exec_ns=0 in REJIT"

    if baseline_exec_ns == 0 and rejit_exec_ns == 0:
        return f"{program.test_method} reported exec_ns=0 in baseline and REJIT"
    if baseline_exec_ns == 0:
        return f"{program.test_method} reported exec_ns=0 in baseline"
    if rejit_exec_ns == 0:
        return f"{program.test_method} reported exec_ns=0 in REJIT"
    return f"{program.test_method} runtime comparison is unavailable"


def rejit_metadata(record: dict[str, Any] | None) -> dict[str, Any]:
    if not record or not record.get("ok"):
        return {}
    return (record.get("sample") or {}).get("rejit") or {}


def rejit_passes(record: dict[str, Any] | None) -> list[str]:
    return normalize_passes(rejit_metadata(record).get("passes_applied"))


def merge_unique_names(names: list[str]) -> list[str]:
    merged: list[str] = []
    seen: set[str] = set()
    for name in names:
        if not name or name in seen:
            continue
        seen.add(name)
        merged.append(name)
    return merged


def program_load_names(program: ResolvedProgram) -> list[str]:
    names = [program.program_name]
    if program.attach_group:
        names.append(program.attach_group)
    return merge_unique_names(names)


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
    load_program_names: list[str] | None = None,
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
    if load_program_names is not None:
        job["load_program_names"] = list(load_program_names)
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
    if enabled_passes is not None:
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


def runtime_for_program(program: ResolvedProgram, *, rejit: bool) -> str:
    if program.test_method == "attach_trigger":
        return "kernel-attach-rejit" if rejit else "kernel-attach"
    return "kernel-rejit" if rejit else "kernel"


def build_prepared_groups(obj: ResolvedObject) -> list[dict[str, Any]]:
    groups_by_key: dict[str, dict[str, Any]] = {}
    ordered_groups: list[dict[str, Any]] = []
    for program in obj.programs:
        if program.test_method == "attach_trigger":
            group_key = f"attach:{program.attach_group or program.program_name}"
        else:
            group_key = f"program:{program.program_name}"
        group = groups_by_key.get(group_key)
        if group is None:
            group = {
                "group_key": group_key,
                "programs": [],
                "load_program_names": [],
            }
            groups_by_key[group_key] = group
            ordered_groups.append(group)
        group["programs"].append(program)
        group["load_program_names"] = merge_unique_names(
            list(group["load_program_names"]) + program_load_names(program)
        )
    return ordered_groups


def _current_live_prog_ids() -> list[int]:
    payload = run_json_command([resolve_bpftool_binary(), "-j", "-p", "prog", "show"], timeout=30)
    if not isinstance(payload, list):
        return []
    return [
        int(record["id"])
        for record in payload
        if isinstance(record, Mapping) and int(record.get("id", 0) or 0) > 0
    ]


def _program_names_match(live_name: str, object_program_name: str) -> bool:
    if not live_name or not object_program_name:
        return False
    return (
        live_name == object_program_name
        or object_program_name.startswith(live_name)
        or live_name.startswith(object_program_name)
    )


def _match_live_program(
    program: ResolvedProgram,
    live_programs: Sequence[Mapping[str, Any]],
) -> Mapping[str, Any] | None:
    exact_matches = [
        candidate
        for candidate in live_programs
        if str(candidate.get("name") or "") == program.program_name
    ]
    if len(exact_matches) == 1:
        return exact_matches[0]
    if len(exact_matches) > 1:
        raise RuntimeError(
            f"multiple live programs matched {program.program_name}: "
            + ", ".join(str(item.get("id") or "?") for item in exact_matches)
        )

    fuzzy_matches = [
        candidate
        for candidate in live_programs
        if _program_names_match(str(candidate.get("name") or ""), program.program_name)
    ]
    if len(fuzzy_matches) == 1:
        return fuzzy_matches[0]
    if len(fuzzy_matches) > 1:
        raise RuntimeError(
            f"multiple fuzzy live programs matched {program.program_name}: "
            + ", ".join(str(item.get("name") or "?") for item in fuzzy_matches)
        )
    return None


def _resolve_executable_candidate(candidate: str | None) -> str | None:
    text = str(candidate or "").strip()
    if not text:
        return None
    resolved = which(text)
    if resolved is not None:
        return resolved
    path = Path(text).expanduser()
    if not path.is_absolute():
        path = ROOT_DIR / path
    if path.is_file() and os.access(path, os.X_OK):
        return str(path.resolve())
    return None


def _make_invocation_error(error: str, *, duration_seconds: float = 0.0) -> dict[str, Any]:
    return {
        "ok": False,
        "returncode": 2,
        "timed_out": False,
        "duration_seconds": float(duration_seconds),
        "error": error,
        "stderr_tail": summarize_text(error),
        "stdout_tail": "",
    }


def _make_invocation_summary(
    sample: Mapping[str, Any],
    *,
    ok: bool = True,
    error: str | None = None,
    duration_seconds: float = 0.0,
) -> dict[str, Any]:
    invocation = {
        "ok": ok,
        "returncode": 0 if ok else 2,
        "timed_out": False,
        "duration_seconds": float(duration_seconds),
        "error": error,
        "stderr_tail": summarize_text(error or ""),
        "stdout_tail": "",
        "sample": dict(sample),
    }
    if not ok and error:
        invocation["stderr_tail"] = summarize_text(error)
    return invocation


def _sample_rejit_metadata(
    *,
    requested: bool,
    result: Mapping[str, Any] | None = None,
) -> dict[str, Any]:
    if not requested:
        return {
            "requested": False,
            "mode": "none",
            "syscall_attempted": False,
            "applied": False,
            "error": "",
            "total_sites_applied": 0,
            "passes_applied": [],
            "verifier_retries": 0,
            "final_disabled_passes": [],
        }

    summary = result.get("summary") if isinstance(result, Mapping) else {}
    if not isinstance(summary, Mapping):
        summary = {}
    debug_result = result.get("debug_result") if isinstance(result, Mapping) else {}
    if not isinstance(debug_result, Mapping):
        debug_result = {}
    return {
        "requested": True,
        "mode": "daemon",
        "syscall_attempted": True,
        "applied": bool(result.get("applied", False)) if isinstance(result, Mapping) else False,
        "error": str(result.get("error") or "") if isinstance(result, Mapping) else "",
        "total_sites_applied": int((summary or {}).get("total_sites_applied", 0) or 0),
        "passes_applied": list(debug_result.get("passes_applied") or []),
        "verifier_retries": int((summary or {}).get("verifier_retries", 0) or 0),
        "final_disabled_passes": list((summary or {}).get("final_disabled_passes") or []),
    }


def _compile_sample_from_bpf_stats(
    stats: Mapping[str, Any],
    *,
    rejit: Mapping[str, Any] | None = None,
) -> dict[str, Any]:
    return {
        "compile_ns": 0,
        "exec_ns": 0,
        "timing_source": "live_bpf_stats",
        "timing_source_wall": "unavailable",
        "result": 0,
        "retval": 0,
        "jited_prog_len": int(stats.get("bytes_jited", 0) or 0),
        "xlated_prog_len": int(stats.get("bytes_xlated", 0) or 0),
        "rejit": dict(rejit or _sample_rejit_metadata(requested=False)),
    }


def _read_process_log_tail(path: Path) -> str:
    try:
        return tail_text(path.read_text(encoding="utf-8", errors="replace"), max_lines=40, max_chars=8000)
    except OSError:
        return ""


def _resolve_tracee_loader_binary(obj: ResolvedObject) -> str:
    resolved = _resolve_executable_candidate(obj.loader_binary)
    if resolved is not None:
        return resolved

    setup_script = _resolve_executable_candidate(obj.loader_setup_script)
    if setup_script is None:
        candidate = Path(obj.loader_setup_script or "e2e/cases/tracee/setup.sh")
        if not candidate.is_absolute():
            candidate = ROOT_DIR / candidate
        setup_script = str(candidate.resolve()) if candidate.exists() else None
    if setup_script is None:
        raise RuntimeError(
            "tracee loader binary is unavailable and no setup script was configured"
        )

    completed = run_command(["bash", setup_script], cwd=ROOT_DIR, check=False, timeout=1800)
    scripted_binary = ""
    for line in (completed.stdout or "").splitlines():
        if line.startswith("TRACEE_BINARY="):
            scripted_binary = line.split("=", 1)[1].strip()
            break

    resolved = _resolve_executable_candidate(scripted_binary)
    if resolved is not None:
        return resolved

    details = tail_text("\n".join(filter(None, [completed.stderr, completed.stdout])), max_lines=40, max_chars=8000)
    raise RuntimeError(
        "tracee setup did not yield an executable loader binary"
        + (f": {details}" if details else "")
    )


def _ensure_empty_tracee_signatures_dir() -> Path:
    signatures_dir = ROOT_DIR / "e2e" / "cases" / "tracee" / "bin" / "signatures"
    signatures_dir.mkdir(parents=True, exist_ok=True)
    return signatures_dir


def _args_have_flag(args: Sequence[str], flag: str) -> bool:
    return any(arg == flag or arg.startswith(f"{flag}=") for arg in args)


def _build_tracee_loader_command(obj: ResolvedObject) -> list[str]:
    binary = _resolve_tracee_loader_binary(obj)
    args = ["--install-path" if arg == "--install-dir" else arg for arg in obj.loader_args]
    if not _args_have_flag(args, "--install-path"):
        args.extend(["--install-path", "/tmp/tracee"])
    if not _args_have_flag(args, "--output"):
        args.extend(["--output", "none"])
    if not _args_have_flag(args, "--signatures-dir"):
        args.extend(["--signatures-dir", str(_ensure_empty_tracee_signatures_dir())])
    return [binary, *args]


def _start_tracee_app_native_session(obj: ResolvedObject) -> dict[str, Any]:
    command = _build_tracee_loader_command(obj)
    process_dir = Path(tempfile.mkdtemp(prefix="tracee-app-native-"))
    stdout_path = process_dir / "stdout.log"
    stderr_path = process_dir / "stderr.log"
    stdout_handle = stdout_path.open("w", encoding="utf-8")
    stderr_handle = stderr_path.open("w", encoding="utf-8")
    preexisting_ids = set(_current_live_prog_ids())
    proc = None
    try:
        proc = subprocess.Popen(
            command,
            cwd=ROOT_DIR,
            env={
                **os.environ,
                "HOME": os.environ.get("HOME", str(ROOT_DIR)),
            },
            stdout=stdout_handle,
            stderr=stderr_handle,
            text=True,
        )
    finally:
        stdout_handle.close()
        stderr_handle.close()

    load_timeout = int(obj.loader_timeout_seconds or _DEFAULT_APP_NATIVE_LOAD_TIMEOUT_SECONDS)

    def _health_check() -> bool:
        return bool(
            [
                item
                for item in find_bpf_programs(proc.pid or 0)
                if int(item.get("id", -1)) not in preexisting_ids
            ]
        )

    healthy = wait_healthy(proc, load_timeout, _health_check)
    if not healthy:
        stderr_tail = _read_process_log_tail(stderr_path)
        stdout_tail = _read_process_log_tail(stdout_path)
        if proc.poll() is None:
            stop_agent(proc, timeout=8)
        details = tail_text("\n".join(filter(None, [stderr_tail, stdout_tail])), max_lines=40, max_chars=8000)
        rendered = " ".join(command)
        raise RuntimeError(
            f"tracee app-native loader failed to become healthy: {rendered}"
            + (f": {details}" if details else "")
        )

    live_programs = [
        dict(item)
        for item in find_bpf_programs(proc.pid or 0)
        if int(item.get("id", -1)) not in preexisting_ids
    ]
    if not live_programs:
        stop_agent(proc, timeout=8)
        raise RuntimeError("tracee app-native loader started but did not own any new BPF programs")

    return {
        "process": proc,
        "command": command,
        "process_dir": process_dir,
        "stdout_path": stdout_path,
        "stderr_path": stderr_path,
        "live_programs": live_programs,
    }


def _stop_app_native_session(session: Mapping[str, Any]) -> None:
    process = session.get("process")
    if isinstance(process, subprocess.Popen):
        stop_agent(process, timeout=8)
    process_dir = session.get("process_dir")
    if isinstance(process_dir, Path):
        shutil.rmtree(process_dir, ignore_errors=True)


def _run_trigger_command(
    command: str,
    *,
    timeout_seconds: int | None,
) -> float:
    started = time.monotonic()
    run_command(
        ["bash", "-lc", command],
        cwd=ROOT_DIR,
        timeout=timeout_seconds or 30,
    )
    return max(0.0, time.monotonic() - started)


def _run_app_native_attach_trigger(
    program: ResolvedProgram,
    *,
    prog_id: int,
    warmup_repeat: int,
) -> tuple[dict[str, Any], float]:
    trigger_command = str(program.trigger or "").strip()
    if not trigger_command:
        raise RuntimeError(
            f"app-native attach_trigger requires an explicit trigger command for {program.canonical_name}"
        )

    if warmup_repeat > 0:
        _run_trigger_command(
            trigger_command,
            timeout_seconds=program.trigger_timeout_seconds,
        )

    before = sample_bpf_stats([prog_id]).get(prog_id) or {}
    duration_seconds = _run_trigger_command(
        trigger_command,
        timeout_seconds=program.trigger_timeout_seconds,
    )
    after = sample_bpf_stats([prog_id]).get(prog_id) or {}
    run_cnt_delta = max(
        0,
        int(after.get("run_cnt", 0) or 0) - int(before.get("run_cnt", 0) or 0),
    )
    run_time_ns_delta = max(
        0,
        int(after.get("run_time_ns", 0) or 0) - int(before.get("run_time_ns", 0) or 0),
    )
    sample = {
        "compile_ns": 0,
        "exec_ns": (run_time_ns_delta // run_cnt_delta) if run_cnt_delta > 0 else 0,
        "timing_source": "bpf_stats",
        "timing_source_wall": "unavailable",
        "result": run_cnt_delta,
        "retval": 0,
        "jited_prog_len": int(after.get("bytes_jited", 0) or before.get("bytes_jited", 0) or 0),
        "xlated_prog_len": int(after.get("bytes_xlated", 0) or before.get("bytes_xlated", 0) or 0),
        "rejit": _sample_rejit_metadata(requested=False),
    }
    return sample, duration_seconds


def _build_app_native_program_record(
    *,
    obj: ResolvedObject,
    program: ResolvedProgram,
    live_program: Mapping[str, Any] | None,
    daemon_binary: Path,
    daemon_socket: str,
    enabled_passes: list[str],
    warmup_repeat: int,
    execution_mode: str,
) -> dict[str, Any]:
    record = build_empty_program_record(program, execution_mode)
    record["guest_invocation"] = {
        "loader": program.loader,
        "loader_binary": program.loader_binary,
    }
    if live_program is None:
        error = f"app-native loader did not load manifest program {program.program_name}"
        record["baseline_compile"] = _make_invocation_error(error)
        record["rejit_compile"] = _make_invocation_error(error)
        if program.test_method != "compile_only":
            record["baseline_run"] = _make_invocation_error(error)
            record["rejit_run"] = _make_invocation_error(error)
        record["record_error"] = error
        return record

    prog_id = int(live_program.get("id", 0) or 0)
    if prog_id <= 0:
        error = f"live program {program.program_name} is missing a valid prog_id"
        record["baseline_compile"] = _make_invocation_error(error)
        record["rejit_compile"] = _make_invocation_error(error)
        if program.test_method != "compile_only":
            record["baseline_run"] = _make_invocation_error(error)
            record["rejit_run"] = _make_invocation_error(error)
        record["record_error"] = error
        return record

    baseline_stats = sample_bpf_stats([prog_id]).get(prog_id)
    if not isinstance(baseline_stats, Mapping):
        error = f"failed to sample live BPF stats for prog_id {prog_id}"
        record["baseline_compile"] = _make_invocation_error(error)
        record["rejit_compile"] = _make_invocation_error(error)
        if program.test_method != "compile_only":
            record["baseline_run"] = _make_invocation_error(error)
            record["rejit_run"] = _make_invocation_error(error)
        record["record_error"] = error
        return record

    record["baseline_compile"] = _make_invocation_summary(
        _compile_sample_from_bpf_stats(baseline_stats),
    )

    if program.test_method != "compile_only":
        try:
            baseline_sample, baseline_duration = _run_app_native_attach_trigger(
                program,
                prog_id=prog_id,
                warmup_repeat=warmup_repeat,
            )
            record["baseline_run"] = _make_invocation_summary(
                baseline_sample,
                duration_seconds=baseline_duration,
            )
        except Exception as exc:
            record["baseline_run"] = _make_invocation_error(str(exc))

    rejit_error: str | None = None
    try:
        rejit_result = apply_daemon_rejit(
            daemon_binary,
            [prog_id],
            enabled_passes=enabled_passes,
            daemon_socket_path=Path(daemon_socket),
        )
        per_program = (
            rejit_result.get("per_program", {}).get(prog_id, {})
            if isinstance(rejit_result.get("per_program"), Mapping)
            else {}
        )
        compile_ok = int(per_program.get("exit_code", 0) or 0) == 0
        rejit_stats = sample_bpf_stats([prog_id]).get(prog_id) or baseline_stats
        rejit_sample = _compile_sample_from_bpf_stats(
            rejit_stats,
            rejit=_sample_rejit_metadata(requested=True, result=per_program),
        )
        if compile_ok:
            record["rejit_compile"] = _make_invocation_summary(rejit_sample)
        else:
            rejit_error = str(per_program.get("error") or rejit_result.get("error") or "daemon optimize failed")
            record["rejit_compile"] = _make_invocation_summary(
                rejit_sample,
                ok=False,
                error=rejit_error,
            )
        if program.test_method != "compile_only":
            if compile_ok:
                try:
                    rejit_run_sample, rejit_duration = _run_app_native_attach_trigger(
                        program,
                        prog_id=prog_id,
                        warmup_repeat=warmup_repeat,
                    )
                    rejit_run_sample["rejit"] = _sample_rejit_metadata(requested=True, result=per_program)
                    record["rejit_run"] = _make_invocation_summary(
                        rejit_run_sample,
                        duration_seconds=rejit_duration,
                    )
                except Exception as exc:
                    record["rejit_run"] = _make_invocation_error(str(exc))
            else:
                record["rejit_run"] = _make_invocation_error(rejit_error or "daemon optimize failed")
    except Exception as exc:
        error = str(exc)
        record["rejit_compile"] = _make_invocation_error(error)
        if program.test_method != "compile_only":
            record["rejit_run"] = _make_invocation_error(error)

    record["compile_passes_applied"] = rejit_passes(record["rejit_compile"])
    record["run_passes_applied"] = rejit_passes(record["rejit_run"])
    record["applied_passes"] = merge_passes(record["compile_passes_applied"], record["run_passes_applied"])
    record["size_ratio"] = size_ratio(record["baseline_compile"], record["rejit_compile"])
    record["size_delta_pct"] = size_delta_pct(record["baseline_compile"], record["rejit_compile"])
    record["speedup_ratio"] = speedup_ratio(record["baseline_run"], record["rejit_run"])
    record["comparison_exclusion_reason"] = comparison_exclusion_reason(
        obj=obj,
        program=program,
        baseline_record=record["baseline_run"],
        rejit_record=record["rejit_run"],
    )
    if (
        record.get("baseline_compile")
        and not record["baseline_compile"].get("ok")
        and record.get("record_error") is None
    ):
        record["record_error"] = summarize_failure_reason(record["baseline_compile"])
    return record


def _build_app_native_object_record(
    *,
    obj: ResolvedObject,
    program_records: Sequence[Mapping[str, Any]],
    execution_mode: str,
) -> dict[str, Any]:
    record = build_empty_object_record(obj, execution_mode)
    baseline_summaries = [
        program_record.get("baseline_compile")
        for program_record in program_records
        if isinstance(program_record.get("baseline_compile"), Mapping)
    ]
    rejit_summaries = [
        program_record.get("rejit_compile")
        for program_record in program_records
        if isinstance(program_record.get("rejit_compile"), Mapping)
    ]
    record["stock_compile"] = representative_object_compile_summary(baseline_summaries)
    record["rejit_compile"] = representative_object_compile_summary(rejit_summaries)

    baseline_error = object_compile_error_summary("baseline", baseline_summaries)
    rejit_error = object_compile_error_summary("REJIT", rejit_summaries)
    baseline_ok = any(summary.get("ok") for summary in baseline_summaries)
    rejit_ok = any(summary.get("ok") for summary in rejit_summaries)

    if baseline_error and not baseline_ok:
        record["status"] = "error"
        record["error"] = baseline_error
    elif rejit_error and not rejit_ok:
        record["status"] = "error"
        record["error"] = rejit_error
    elif baseline_error or rejit_error:
        record["status"] = "partial"
        record["error"] = "; ".join(error for error in (baseline_error, rejit_error) if error)
    return record


def _run_tracee_app_native_object(
    *,
    obj: ResolvedObject,
    daemon_binary: Path,
    daemon_socket: str,
    execution_mode: str,
    warmup_repeat: int,
    enabled_passes_map: Mapping[str, list[str]],
) -> tuple[dict[str, Any], list[dict[str, Any]], dict[str, Any]]:
    started = time.monotonic()
    session: dict[str, Any] | None = None
    try:
        session = _start_tracee_app_native_session(obj)
        live_programs = list(session.get("live_programs") or [])
        live_programs_by_name = {
            str(program.get("name") or ""): dict(program)
            for program in live_programs
            if str(program.get("name") or "")
        }
        program_records: list[dict[str, Any]] = []
        with enable_bpf_stats():
            for program in obj.programs:
                live_program = live_programs_by_name.get(program.program_name)
                if live_program is None:
                    live_program = _match_live_program(program, live_programs)
                program_records.append(
                    _build_app_native_program_record(
                        obj=obj,
                        program=program,
                        live_program=live_program,
                        daemon_binary=daemon_binary,
                        daemon_socket=daemon_socket,
                        enabled_passes=list(enabled_passes_map.get(program.canonical_name, [])),
                        warmup_repeat=warmup_repeat,
                        execution_mode=execution_mode,
                    )
                )
        object_record = _build_app_native_object_record(
            obj=obj,
            program_records=program_records,
            execution_mode=execution_mode,
        )
        job_errors = any(
            isinstance(invocation, Mapping) and not invocation.get("ok", False)
            for program_record in program_records
            for invocation in (
                program_record.get("baseline_compile"),
                program_record.get("baseline_run"),
                program_record.get("rejit_compile"),
                program_record.get("rejit_run"),
            )
            if invocation is not None
        )
        result = {
            "ok": True,
            "completed_with_job_errors": job_errors,
            "returncode": 2 if job_errors else 0,
            "timed_out": False,
            "duration_seconds": max(0.0, time.monotonic() - started),
            "stdout": "",
            "stderr": "",
            "error": None,
            "result": {
                "jobs": [],
                "app_native": {
                    "repo": obj.repo,
                    "loader": obj.loader,
                    "command": list(session.get("command") or []),
                    "loaded_program_count": len(live_programs),
                },
            },
            "progress": None,
        }
        return object_record, program_records, result
    finally:
        if session is not None:
            _stop_app_native_session(session)


def build_object_batch_plan_v2(
    *,
    objects: list[ResolvedObject],
    repeat: int,
    warmup_repeat: int,
    btf_custom_path: Path | None,
    daemon_socket: str,
    enabled_passes: list[str] | None = None,
    program_enabled_passes: Mapping[str, list[str]] | None = None,
    batch_label: str | None = None,
) -> tuple[dict[str, Any], list[dict[str, Any]]]:
    baseline_prepare_jobs: list[dict[str, Any]] = []
    baseline_measure_jobs: list[dict[str, Any]] = []
    rejit_prepare_jobs: list[dict[str, Any]] = []
    rejit_measure_jobs: list[dict[str, Any]] = []
    object_refs: list[dict[str, Any]] = []
    batch_prefix = f"{batch_label}:" if batch_label else ""
    baseline_batch_group = f"{batch_prefix}baseline"
    rejit_batch_group = f"{batch_prefix}rejit"

    for index, obj in enumerate(objects, start=1):
        object_job_prefix = f"{batch_prefix}object-{index:04d}"
        object_path = ROOT_DIR / obj.object_path
        fixture_path = Path(obj.fixture_path) if obj.fixture_path else None
        refs: dict[str, Any] = {
            "object": obj,
            "baseline_group_compiles": [],
            "rejit_group_compiles": [],
            "programs": {},
        }
        object_refs.append(refs)

        def enabled_passes_for_program(program: ResolvedProgram) -> list[str] | None:
            if program_enabled_passes is not None and program.canonical_name in program_enabled_passes:
                return list(program_enabled_passes[program.canonical_name])
            if enabled_passes is not None:
                return list(enabled_passes)
            return None

        for program_index, program in enumerate(obj.programs, start=1):
            refs["programs"][program.canonical_name] = {
                "baseline_compile": f"{object_job_prefix}:program-{program_index:04d}:baseline-compile",
                "baseline_run": f"{object_job_prefix}:program-{program_index:04d}:baseline-run",
                "rejit_compile": f"{object_job_prefix}:program-{program_index:04d}:rejit-compile",
                "rejit_run": f"{object_job_prefix}:program-{program_index:04d}:rejit-run",
            }
        prepared_groups = build_prepared_groups(obj)

        for group_index, group in enumerate(prepared_groups, start=1):
            baseline_group = f"{object_job_prefix}:baseline-group-{group_index:04d}"
            baseline_prepared_key = f"{baseline_group}:prepared"
            baseline_prepare_job_id = f"{baseline_group}:prepare"
            load_program_names = list(group["load_program_names"])

            refs["baseline_group_compiles"].append(baseline_prepare_job_id)

            baseline_prepare_jobs.append(
                build_test_run_batch_job(
                    job_id=baseline_prepare_job_id,
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
                    load_program_names=load_program_names,
                    prepared_key=baseline_prepared_key,
                    prepared_group=baseline_batch_group,
                    fixture_path=fixture_path,
                )
            )

            for program in group["programs"]:
                program_refs = refs["programs"][program.canonical_name]
                memory_path = Path(program.memory_path) if program.memory_path else None
                program_fixture_path = Path(program.fixture_path) if program.fixture_path else fixture_path
                baseline_measure_jobs.append(
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
                        prepared_group=baseline_batch_group,
                        release_prepared=False,
                        fixture_path=program_fixture_path,
                        trigger_command=program.trigger,
                        trigger_timeout_seconds=program.trigger_timeout_seconds,
                    )
                )
                if program.test_method != "compile_only":
                    baseline_measure_jobs.append(
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
                            prepared_group=baseline_batch_group,
                            release_prepared=False,
                            fixture_path=program_fixture_path,
                            trigger_command=program.trigger,
                            trigger_timeout_seconds=program.trigger_timeout_seconds,
                        )
                    )

            for program in group["programs"]:
                program_refs = refs["programs"][program.canonical_name]
                memory_path = Path(program.memory_path) if program.memory_path else None
                program_fixture_path = Path(program.fixture_path) if program.fixture_path else fixture_path
                rejit_group = f"{program_refs['rejit_compile']}:group"
                rejit_prepared_key = f"{program_refs['rejit_compile']}:prepared"
                program_passes = enabled_passes_for_program(program)

                refs["rejit_group_compiles"].append(program_refs["rejit_compile"])

                rejit_prepare_jobs.append(
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
                        enabled_passes=program_passes,
                        load_program_names=program_load_names(program),
                        prepared_key=rejit_prepared_key,
                        prepared_group=rejit_batch_group,
                        fixture_path=program_fixture_path,
                        trigger_command=program.trigger,
                        trigger_timeout_seconds=program.trigger_timeout_seconds,
                    )
                )
                if program.test_method != "compile_only" and program.rejit_enabled:
                    rejit_measure_jobs.append(
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
                            enabled_passes=program_passes,
                            prepared_ref=rejit_prepared_key,
                            prepared_group=rejit_batch_group,
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
        "jobs": (
            baseline_prepare_jobs
            + baseline_measure_jobs
            + rejit_prepare_jobs
            + rejit_measure_jobs
        ),
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
        "loader": program.loader,
        "loader_binary": program.loader_binary,
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
        "comparison_exclusion_reason": None,
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
        "loader": obj.loader,
        "loader_binary": obj.loader_binary,
        "shared_state_policy": obj.shared_state_policy,
        "program_count": len(obj.programs),
        "measured_program_count": sum(1 for program in obj.programs if program.test_method != "compile_only"),
        "execution_mode": execution_mode,
        "stock_compile": None,
        "rejit_compile": None,
        "status": "error" if error else "ok",
        "error": error,
    }


def object_compile_summaries(
    job_ids: list[str],
    results_by_id: Mapping[str, dict[str, Any]],
) -> list[dict[str, Any]]:
    summaries: list[dict[str, Any]] = []
    for job_id in job_ids:
        summary = batch_job_invocation_summary(results_by_id.get(job_id))
        if summary is not None:
            summaries.append(summary)
    return summaries


def representative_object_compile_summary(
    summaries: list[dict[str, Any]],
) -> dict[str, Any] | None:
    for summary in summaries:
        if summary.get("ok"):
            return summary
    if summaries:
        return summaries[0]
    return None


def object_compile_error_summary(
    label: str,
    summaries: list[dict[str, Any]],
) -> str | None:
    if not summaries:
        return None
    failures = [summary for summary in summaries if not summary.get("ok")]
    if not failures:
        return None
    first_reason = summarize_failure_reason(failures[0])
    if len(failures) == len(summaries):
        return f"all {len(summaries)} {label} prepared groups failed; first: {first_reason}"
    return f"{len(failures)}/{len(summaries)} {label} prepared groups failed; first: {first_reason}"


def build_program_record_v2(
    *,
    obj: ResolvedObject,
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
    record["comparison_exclusion_reason"] = comparison_exclusion_reason(
        obj=obj,
        program=program,
        baseline_record=record["baseline_run"],
        rejit_record=record["rejit_run"],
    )
    return record


def build_object_record_v2(
    *,
    obj: ResolvedObject,
    execution_mode: str,
    refs: Mapping[str, Any],
    results_by_id: Mapping[str, dict[str, Any]],
) -> dict[str, Any]:
    record = build_empty_object_record(obj, execution_mode)
    baseline_summaries = object_compile_summaries(list(refs.get("baseline_group_compiles") or []), results_by_id)
    rejit_summaries = object_compile_summaries(list(refs.get("rejit_group_compiles") or []), results_by_id)
    record["stock_compile"] = representative_object_compile_summary(baseline_summaries)
    record["rejit_compile"] = representative_object_compile_summary(rejit_summaries)

    baseline_error = object_compile_error_summary("baseline", baseline_summaries)
    rejit_error = object_compile_error_summary("REJIT", rejit_summaries)
    baseline_ok = any(summary.get("ok") for summary in baseline_summaries)
    rejit_ok = any(summary.get("ok") for summary in rejit_summaries)

    if baseline_error and not baseline_ok:
        record["status"] = "error"
        record["error"] = baseline_error
    elif rejit_error and not rejit_ok:
        record["status"] = "error"
        record["error"] = rejit_error
    elif baseline_error or rejit_error:
        record["status"] = "partial"
        record["error"] = "; ".join(
            error for error in (baseline_error, rejit_error) if error
        )
    return record


def _build_records_from_batch_result(
    *,
    object_refs: Sequence[Mapping[str, Any]],
    batch_result: Mapping[str, Any],
    execution_mode: str,
) -> tuple[list[dict[str, Any]], list[dict[str, Any]]]:
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
                    obj=obj,
                    program=program,
                    execution_mode=execution_mode,
                    job_refs=refs["programs"][program.canonical_name],
                    results_by_id=results_by_id,
                )
            )
    return object_records, program_records


def _split_object_batches(
    objects: Sequence[ResolvedObject],
    batch_size: int,
) -> list[list[ResolvedObject]]:
    return [
        list(objects[index:index + batch_size])
        for index in range(0, len(objects), batch_size)
    ]


def _prepare_resource_error(
    spec_payload: Mapping[str, Any],
    batch_result: Mapping[str, Any],
) -> str | None:
    results_by_id = batch_job_result_map(batch_result.get("result"))
    jobs = spec_payload.get("jobs")
    if not isinstance(jobs, list):
        return None
    for raw_job in jobs:
        if not isinstance(raw_job, Mapping) or not raw_job.get("prepared_key"):
            continue
        job_id = str(raw_job.get("id") or "").strip()
        if not job_id:
            continue
        result = results_by_id.get(job_id)
        if not result or result.get("ok"):
            continue
        error_text = summarize_failure_reason(result)
        lowered = error_text.lower()
        if any(token in lowered for token in _BATCH_RESOURCE_ERROR_SUBSTRINGS):
            return error_text
    return None


def _empty_corpus_batch_result(*, batch_size: int) -> dict[str, Any]:
    return {
        "ok": True,
        "completed_with_job_errors": False,
        "returncode": 0,
        "timed_out": False,
        "duration_seconds": 0.0,
        "stdout": "",
        "stderr": "",
        "error": None,
        "result": {
            "jobs": [],
            "batch_summary": {
                "requested_batch_size": batch_size,
                "attempted_batch_sizes": [],
                "effective_batch_sizes": [],
                "retry_splits": [],
            },
        },
        "progress": None,
    }


def _execute_generic_object_batches(
    *,
    objects: list[ResolvedObject],
    runner: Path,
    repeat: int,
    warmup_repeat: int,
    timeout_seconds: int,
    execution_mode: str,
    btf_custom_path: Path | None,
    daemon_socket: str,
    enabled_passes: list[str] | None = None,
    program_enabled_passes: Mapping[str, list[str]] | None = None,
    batch_size: int = _DEFAULT_CORPUS_BATCH_SIZE,
) -> tuple[list[dict[str, Any]], list[dict[str, Any]], dict[str, Any]]:
    if not objects:
        return [], [], _empty_corpus_batch_result(batch_size=batch_size)

    completed_batches: list[tuple[list[dict[str, Any]], dict[str, Any]]] = []
    attempted_batch_sizes: list[int] = []
    effective_batch_sizes: list[int] = []
    retry_splits: list[dict[str, Any]] = []
    total_duration_seconds = 0.0
    stdout_chunks: list[str] = []
    stderr_chunks: list[str] = []

    def execute_batch(batch_objects: list[ResolvedObject], batch_label: str) -> None:
        nonlocal total_duration_seconds

        attempted_batch_sizes.append(len(batch_objects))
        spec_payload, object_refs = build_object_batch_plan_v2(
            objects=batch_objects,
            repeat=repeat,
            warmup_repeat=warmup_repeat,
            btf_custom_path=btf_custom_path,
            daemon_socket=daemon_socket,
            enabled_passes=enabled_passes,
            program_enabled_passes=program_enabled_passes,
            batch_label=batch_label,
        )
        batch_result = run_batch_runner(
            runner,
            spec_payload=spec_payload,
            timeout_seconds=packet_batch_timeout_seconds(max(1, len(batch_objects)), timeout_seconds),
            cwd=ROOT_DIR,
        )
        total_duration_seconds += float(batch_result.get("duration_seconds", 0.0) or 0.0)
        stdout = str(batch_result.get("stdout") or "").strip()
        stderr = str(batch_result.get("stderr") or "").strip()
        if stdout:
            stdout_chunks.append(stdout)
        if stderr:
            stderr_chunks.append(stderr)

        resource_error = _prepare_resource_error(spec_payload, batch_result)
        if resource_error is not None and len(batch_objects) > 1:
            midpoint = max(1, len(batch_objects) // 2)
            retry_splits.append(
                {
                    "batch_label": batch_label,
                    "object_count": len(batch_objects),
                    "retry_batch_size": midpoint,
                    "error": resource_error,
                }
            )
            execute_batch(batch_objects[:midpoint], f"{batch_label}-a")
            execute_batch(batch_objects[midpoint:], f"{batch_label}-b")
            return

        effective_batch_sizes.append(len(batch_objects))
        completed_batches.append((object_refs, batch_result))

    for batch_index, batch_objects in enumerate(_split_object_batches(objects, batch_size), start=1):
        execute_batch(batch_objects, f"batch-{batch_index:04d}")

    object_records: list[dict[str, Any]] = []
    program_records: list[dict[str, Any]] = []
    combined_jobs: list[dict[str, Any]] = []
    completed_with_job_errors = False
    combined_ok = True
    combined_timed_out = False
    combined_returncode: int | None = 0
    combined_error: str | None = None

    for object_refs, batch_result in completed_batches:
        batch_object_records, batch_program_records = _build_records_from_batch_result(
            object_refs=object_refs,
            batch_result=batch_result,
            execution_mode=execution_mode,
        )
        object_records.extend(batch_object_records)
        program_records.extend(batch_program_records)

        payload = batch_result.get("result")
        if isinstance(payload, Mapping):
            raw_jobs = payload.get("jobs")
            if isinstance(raw_jobs, list):
                combined_jobs.extend(item for item in raw_jobs if isinstance(item, dict))

        combined_ok = combined_ok and bool(batch_result.get("ok"))
        completed_with_job_errors = (
            completed_with_job_errors or bool(batch_result.get("completed_with_job_errors"))
        )
        combined_timed_out = combined_timed_out or bool(batch_result.get("timed_out"))
        if combined_error is None and batch_result.get("error"):
            combined_error = str(batch_result["error"])

        result_returncode = batch_result.get("returncode")
        if isinstance(result_returncode, int) and result_returncode not in (0, 2):
            combined_returncode = result_returncode
        elif combined_returncode == 0 and result_returncode == 2:
            combined_returncode = 2

    if combined_timed_out:
        combined_returncode = None
    elif combined_returncode == 0 and completed_with_job_errors:
        combined_returncode = 2

    batch_result = {
        "ok": combined_ok,
        "completed_with_job_errors": completed_with_job_errors,
        "returncode": combined_returncode,
        "timed_out": combined_timed_out,
        "duration_seconds": total_duration_seconds,
        "stdout": "\n".join(stdout_chunks),
        "stderr": "\n".join(stderr_chunks),
        "error": combined_error,
        "result": {
            "jobs": combined_jobs,
            "batch_summary": {
                "requested_batch_size": batch_size,
                "attempted_batch_sizes": attempted_batch_sizes,
                "effective_batch_sizes": effective_batch_sizes,
                "retry_splits": retry_splits,
            },
        },
        "progress": None,
    }
    return object_records, program_records, batch_result


def _run_app_native_object(
    *,
    obj: ResolvedObject,
    daemon_binary: Path,
    daemon_socket: str,
    execution_mode: str,
    warmup_repeat: int,
    enabled_passes_map: Mapping[str, list[str]],
) -> tuple[dict[str, Any], list[dict[str, Any]], dict[str, Any]]:
    if obj.repo.lower() == "tracee":
        return _run_tracee_app_native_object(
            obj=obj,
            daemon_binary=daemon_binary,
            daemon_socket=daemon_socket,
            execution_mode=execution_mode,
            warmup_repeat=warmup_repeat,
            enabled_passes_map=enabled_passes_map,
        )
    raise RuntimeError(f"app-native loader is not implemented for repo {obj.repo}")


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
    benchmark_config: Mapping[str, Any] | None = None,
    batch_size: int = _DEFAULT_CORPUS_BATCH_SIZE,
) -> tuple[list[dict[str, Any]], list[dict[str, Any]], dict[str, Any]]:
    if batch_size < 1:
        raise ValueError(f"batch_size must be >= 1, got {batch_size}")
    if not objects:
        return [], [], _empty_corpus_batch_result(batch_size=batch_size)

    active_daemon_socket = daemon_socket
    daemon_server: tuple[subprocess.Popen[str], Path, str, Path, Path] | None = None
    if active_daemon_socket is None:
        daemon_server = _start_daemon_server(daemon)
        active_daemon_socket = str(daemon_server[1])

    generic_objects = [obj for obj in objects if obj.loader == "generic"]
    app_native_objects = [obj for obj in objects if obj.loader == "app-native"]
    fallback_enabled_passes = list(enabled_passes) if enabled_passes is not None else benchmark_config_enabled_passes(benchmark_config)
    combined_object_records: dict[str, dict[str, Any]] = {}
    combined_program_records: dict[str, dict[str, Any]] = {}
    combined_jobs: list[dict[str, Any]] = []
    completed_with_job_errors = False
    combined_ok = True
    combined_timed_out = False
    combined_returncode: int | None = 0
    combined_error: str | None = None
    total_duration_seconds = 0.0
    stdout_chunks: list[str] = []
    stderr_chunks: list[str] = []
    attempted_batch_sizes: list[int] = []
    effective_batch_sizes: list[int] = []
    retry_splits: list[dict[str, Any]] = []
    app_native_summary: list[dict[str, Any]] = []

    try:
        assert active_daemon_socket is not None
        generic_program_enabled_passes: dict[str, list[str]] = {}
        if generic_objects:
            generic_program_enabled_passes = resolve_program_enabled_passes_map(
                objects=generic_objects,
                benchmark_config=benchmark_config,
                runner=runner,
                daemon_socket=active_daemon_socket,
                timeout_seconds=timeout_seconds,
                enabled_passes=enabled_passes,
            )
        program_enabled_passes = {
            program.canonical_name: list(generic_program_enabled_passes.get(program.canonical_name, fallback_enabled_passes))
            for obj in objects
            for program in obj.programs
        }

        if generic_objects:
            generic_object_records, generic_program_records, generic_batch_result = _execute_generic_object_batches(
                objects=generic_objects,
                runner=runner,
                repeat=repeat,
                warmup_repeat=warmup_repeat,
                timeout_seconds=timeout_seconds,
                execution_mode=execution_mode,
                btf_custom_path=btf_custom_path,
                daemon_socket=active_daemon_socket,
                enabled_passes=enabled_passes,
                program_enabled_passes=generic_program_enabled_passes,
                batch_size=batch_size,
            )
            for record in generic_object_records:
                combined_object_records[str(record["canonical_object_name"])] = record
            for record in generic_program_records:
                combined_program_records[str(record["canonical_name"])] = record
            payload = generic_batch_result.get("result")
            if isinstance(payload, Mapping):
                raw_jobs = payload.get("jobs")
                if isinstance(raw_jobs, list):
                    combined_jobs.extend(item for item in raw_jobs if isinstance(item, dict))
                batch_summary = payload.get("batch_summary")
                if isinstance(batch_summary, Mapping):
                    attempted_batch_sizes.extend(
                        int(value) for value in batch_summary.get("attempted_batch_sizes", []) or []
                    )
                    effective_batch_sizes.extend(
                        int(value) for value in batch_summary.get("effective_batch_sizes", []) or []
                    )
                    retry_splits.extend(
                        dict(item) for item in batch_summary.get("retry_splits", []) or []
                        if isinstance(item, Mapping)
                    )
            total_duration_seconds += float(generic_batch_result.get("duration_seconds", 0.0) or 0.0)
            stdout = str(generic_batch_result.get("stdout") or "").strip()
            stderr = str(generic_batch_result.get("stderr") or "").strip()
            if stdout:
                stdout_chunks.append(stdout)
            if stderr:
                stderr_chunks.append(stderr)
            combined_ok = combined_ok and bool(generic_batch_result.get("ok"))
            completed_with_job_errors = (
                completed_with_job_errors or bool(generic_batch_result.get("completed_with_job_errors"))
            )
            combined_timed_out = combined_timed_out or bool(generic_batch_result.get("timed_out"))
            if combined_error is None and generic_batch_result.get("error"):
                combined_error = str(generic_batch_result["error"])
            result_returncode = generic_batch_result.get("returncode")
            if isinstance(result_returncode, int) and result_returncode not in (0, 2):
                combined_returncode = result_returncode
            elif combined_returncode == 0 and result_returncode == 2:
                combined_returncode = 2

        for obj in app_native_objects:
            try:
                object_record, program_records, app_batch_result = _run_app_native_object(
                    obj=obj,
                    daemon_binary=daemon,
                    daemon_socket=active_daemon_socket,
                    execution_mode=execution_mode,
                    warmup_repeat=warmup_repeat,
                    enabled_passes_map=program_enabled_passes,
                )
            except Exception as exc:
                error_text = str(exc)
                object_record = build_empty_object_record(obj, execution_mode, error=error_text)
                program_records = []
                for program in obj.programs:
                    program_record = build_empty_program_record(program, execution_mode)
                    program_record["guest_invocation"] = {
                        "loader": program.loader,
                        "loader_binary": program.loader_binary,
                    }
                    invocation_error = _make_invocation_error(error_text)
                    program_record["baseline_compile"] = invocation_error
                    program_record["rejit_compile"] = invocation_error
                    if program.test_method != "compile_only":
                        program_record["baseline_run"] = invocation_error
                        program_record["rejit_run"] = invocation_error
                    program_record["record_error"] = error_text
                    program_records.append(program_record)
                app_batch_result = {
                    "ok": True,
                    "completed_with_job_errors": True,
                    "returncode": 2,
                    "timed_out": False,
                    "duration_seconds": 0.0,
                    "stdout": "",
                    "stderr": error_text,
                    "error": None,
                    "result": {"jobs": []},
                    "progress": None,
                }

            combined_object_records[obj.canonical_name] = object_record
            for record in program_records:
                combined_program_records[str(record["canonical_name"])] = record
            total_duration_seconds += float(app_batch_result.get("duration_seconds", 0.0) or 0.0)
            stdout = str(app_batch_result.get("stdout") or "").strip()
            stderr = str(app_batch_result.get("stderr") or "").strip()
            if stdout:
                stdout_chunks.append(stdout)
            if stderr:
                stderr_chunks.append(stderr)
            combined_ok = combined_ok and bool(app_batch_result.get("ok"))
            completed_with_job_errors = (
                completed_with_job_errors or bool(app_batch_result.get("completed_with_job_errors"))
            )
            combined_timed_out = combined_timed_out or bool(app_batch_result.get("timed_out"))
            if combined_error is None and app_batch_result.get("error"):
                combined_error = str(app_batch_result["error"])
            result_returncode = app_batch_result.get("returncode")
            if isinstance(result_returncode, int) and result_returncode not in (0, 2):
                combined_returncode = result_returncode
            elif combined_returncode == 0 and result_returncode == 2:
                combined_returncode = 2
            app_native_summary.append(
                {
                    "repo": obj.repo,
                    "object": obj.canonical_name,
                    "status": object_record.get("status"),
                }
            )
    finally:
        if daemon_server is not None:
            _stop_daemon_server(daemon_server[0], daemon_server[1], daemon_server[2])

    ordered_object_records = [
        combined_object_records[obj.canonical_name]
        for obj in objects
        if obj.canonical_name in combined_object_records
    ]
    ordered_program_records = [
        combined_program_records[program.canonical_name]
        for obj in objects
        for program in obj.programs
        if program.canonical_name in combined_program_records
    ]

    if combined_timed_out:
        combined_returncode = None
    elif combined_returncode == 0 and completed_with_job_errors:
        combined_returncode = 2

    batch_result = {
        "ok": combined_ok,
        "completed_with_job_errors": completed_with_job_errors,
        "returncode": combined_returncode,
        "timed_out": combined_timed_out,
        "duration_seconds": total_duration_seconds,
        "stdout": "\n".join(stdout_chunks),
        "stderr": "\n".join(stderr_chunks),
        "error": combined_error,
        "result": {
            "jobs": combined_jobs,
            "batch_summary": {
                "requested_batch_size": batch_size,
                "attempted_batch_sizes": attempted_batch_sizes,
                "effective_batch_sizes": effective_batch_sizes,
                "retry_splits": retry_splits,
                "app_native_objects": app_native_summary,
            },
        },
        "progress": None,
    }
    return ordered_object_records, ordered_program_records, batch_result


__all__ = [
    "add_filter_argument",
    "add_max_programs_argument",
    "add_output_json_argument",
    "add_output_md_argument",
    "add_repeat_argument",
    "add_runner_argument",
    "add_daemon_argument",
    "add_timeout_argument",
    "attach_trigger_unsupported_reason",
    "batch_job_invocation_summary",
    "batch_job_result_map",
    "build_empty_object_record",
    "build_empty_program_record",
    "build_object_batch_plan_v2",
    "build_object_record_v2",
    "build_program_record_v2",
    "build_test_run_batch_job",
    "clone_resolved_object",
    "deserialize_resolved_object",
    "ensure_parent",
    "execution_plan",
    "extract_error",
    "find_program_in_object",
    "format_pct",
    "format_ratio",
    "format_ns",
    "geomean",
    "infer_program_kind",
    "invocation_summary",
    "load_corpus_build_report",
    "load_guest_batch_targets",
    "load_targets_from_yaml",
    "markdown_table",
    "merge_passes",
    "materialize_dummy_context",
    "materialize_dummy_packet",
    "materialize_katran_packet",
    "normalize_section_root",
    "normalize_passes",
    "object_matches_filter",
    "packet_batch_timeout_seconds",
    "parse_runner_json",
    "program_label",
    "program_matches_filter",
    "require_minimum",
    "relpath",
    "ResolvedObject",
    "ResolvedProgram",
    "resolve_manifest_object",
    "rejit_metadata",
    "rejit_passes",
    "run_command",
    "run_objects_locally_batch",
    "run_text_command",
    "runtime_for_program",
    "sanitize_guest_batch_record",
    "serialize_resolved_object",
    "size_delta_pct",
    "size_ratio",
    "speedup_ratio",
    "split_corpus_source",
    "summarize_failure_reason",
    "summarize_text",
    "text_invocation_summary",
    "write_guest_batch_records",
    "write_json_output",
    "write_text_output",
]
