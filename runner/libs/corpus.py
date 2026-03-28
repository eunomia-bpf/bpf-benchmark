from __future__ import annotations

import argparse
from dataclasses import asdict, dataclass
import json
import math
import subprocess
import sys
import tempfile
import time
from pathlib import Path
from typing import Any, Mapping

import yaml

from . import ROOT_DIR, ensure_parent
from .batch_runner import run_batch_runner
from .object_discovery import supplement_with_existing_corpus_build_objects
from .rejit import _start_daemon_server, _stop_daemon_server
from .results import parse_runner_sample


def relpath(path: Path | str, root_dir: Path) -> str:
    candidate = Path(path)
    try:
        return candidate.relative_to(root_dir).as_posix()
    except ValueError:
        return str(candidate)


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


def normalize_passes(value: Any) -> list[str]:
    if not isinstance(value, list):
        return []
    return [str(item) for item in value if str(item)]


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
    )


def resolve_manifest_object(entry: Mapping[str, Any], *, index: int) -> ResolvedObject:
    source = _string_or_none(entry.get("source"))
    if source is None:
        raise SystemExit(f"manifest object #{index} missing source")
    object_candidate = Path(source)
    object_path = object_candidate if object_candidate.is_absolute() else (ROOT_DIR / object_candidate)
    repo_from_source, object_relpath = split_corpus_source(source, _string_or_none(entry.get("family")) or "")
    repo = _string_or_none(entry.get("repo")) or repo_from_source or (
        _string_or_none(entry.get("family")) or object_candidate.name
    )
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


def find_program_in_object(
    obj: ResolvedObject,
    program_name: str,
) -> ResolvedProgram | None:
    for program in obj.programs:
        if program.program_name == program_name:
            return program
    return None


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


def rejit_metadata(record: dict[str, Any] | None) -> dict[str, Any]:
    if not record or not record.get("ok"):
        return {}
    return (record.get("sample") or {}).get("rejit") or {}


def rejit_passes(record: dict[str, Any] | None) -> list[str]:
    return normalize_passes(rejit_metadata(record).get("passes_applied"))


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
    daemon_server: tuple[subprocess.Popen[str], Path, str, Path, Path] | None = None
    if objects and active_daemon_socket is None:
        daemon_server = _start_daemon_server(daemon)
        active_daemon_socket = str(daemon_server[1])

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
        if daemon_server is not None:
            _stop_daemon_server(daemon_server[0], daemon_server[1], daemon_server[2])

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


__all__ = [
    "add_filter_argument",
    "add_max_programs_argument",
    "add_output_json_argument",
    "add_output_md_argument",
    "add_repeat_argument",
    "add_runner_argument",
    "add_daemon_argument",
    "add_timeout_argument",
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
