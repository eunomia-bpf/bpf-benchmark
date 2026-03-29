from __future__ import annotations

"""Corpus manifest parsing and shared result helpers."""

from collections import Counter
from dataclasses import asdict, dataclass, replace
import json
import math
from pathlib import Path
from typing import Any, Mapping

import yaml

from . import ROOT_DIR, ensure_parent
from .object_discovery import supplement_with_existing_corpus_build_objects


_ALLOWED_MEASUREMENTS = {"app_native", "test_run"}
_ALLOWED_LOADERS = {"generic", "app-native"}
_DEFAULT_APP_NATIVE_LOAD_TIMEOUT_SECONDS = 60


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
    measurement: str
    prog_type_name: str
    section_name: str
    fixture_path: str | None
    rejit_enabled: bool
    compile_loader: str | None
    loader: str = "generic"
    loader_binary: str | None = None
    loader_args: tuple[str, ...] = ()
    loader_setup_script: str | None = None
    loader_timeout_seconds: int | None = None
    io_mode: str = "context"
    raw_packet: bool = False
    input_size: int = 0
    memory_path: str | None = None


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
    measurement: str
    programs: tuple[ResolvedProgram, ...]
    fixture_path: str | None = None
    compile_loader: str | None = None
    loader: str = "generic"
    loader_binary: str | None = None
    loader_args: tuple[str, ...] = ()
    loader_setup_script: str | None = None
    loader_timeout_seconds: int | None = None


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


def _normalize_measurement(value: Any, *, field_name: str) -> str:
    measurement = _string_or_none(value)
    if measurement is None:
        raise SystemExit(f"invalid manifest field: {field_name} is required")
    if measurement not in _ALLOWED_MEASUREMENTS:
        allowed = ", ".join(sorted(_ALLOWED_MEASUREMENTS))
        raise SystemExit(
            f"invalid manifest field: {field_name} must be one of {allowed}; got {measurement!r}"
        )
    return measurement


def _loader_kind(value: Any) -> str:
    text = _string_or_none(value) or "generic"
    normalized = text.strip().lower()
    if normalized not in _ALLOWED_LOADERS:
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
        raise SystemExit("resolved object payload missing programs list")
    programs = []
    for item in programs_payload:
        if not isinstance(item, Mapping):
            continue
        programs.append(ResolvedProgram(**dict(item)))
    return ResolvedObject(**{**dict(payload), "programs": tuple(programs)})


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
    return replace(obj, programs=programs)


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
    raw_programs = _sequence(entry.get("programs"), field_name=f"objects[{index}].programs")
    if not raw_programs:
        raise SystemExit(f"manifest object #{index} has no programs; object-only entries were removed")

    object_measurement = _normalize_measurement(
        entry.get("measurement"),
        field_name=f"objects[{index}].measurement",
    )
    object_prog_type = _string_or_none(entry.get("prog_type")) or ""
    object_section = _string_or_none(entry.get("section")) or ""
    object_rejit_enabled = bool(entry.get("rejit_enabled", True))
    object_io_mode = _string_or_none(entry.get("io_mode")) or "context"
    object_raw_packet = _bool_or_default(entry.get("raw_packet"), False)
    object_input_size = _int_or_default(entry.get("input_size"), 0)
    object_memory_path = _string_or_none(entry.get("test_input"))

    def default_program_fixture_path(program_name: str) -> str | None:
        relative = Path("corpus") / "fixtures" / repo / object_basename / f"{program_name}.json"
        absolute = ROOT_DIR / relative
        return relative.as_posix() if absolute.exists() else None

    programs: list[ResolvedProgram] = []
    for program_index, raw_program in enumerate(raw_programs, start=1):
        if not isinstance(raw_program, Mapping):
            raise SystemExit(f"manifest objects[{index}].programs[{program_index}] must be a mapping")
        program_name = _string_or_none(raw_program.get("name"))
        if program_name is None:
            raise SystemExit(f"manifest objects[{index}].programs[{program_index}] missing name")
        program_measurement = _normalize_measurement(
            raw_program.get("measurement", object_measurement),
            field_name=f"objects[{index}].programs[{program_index}].measurement",
        )
        prog_type_name = _string_or_none(raw_program.get("prog_type")) or object_prog_type
        section_name = _string_or_none(raw_program.get("section")) or object_section or ""
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
                measurement=program_measurement,
                prog_type_name=prog_type_name,
                section_name=section_name,
                fixture_path=program_fixture_path,
                rejit_enabled=bool(raw_program.get("rejit_enabled", object_rejit_enabled)),
                compile_loader=compile_loader,
                loader=loader,
                loader_binary=loader_binary,
                loader_args=loader_args,
                loader_setup_script=loader_setup_script,
                loader_timeout_seconds=loader_timeout_seconds,
                io_mode=_string_or_none(raw_program.get("io_mode")) or object_io_mode,
                raw_packet=_bool_or_default(raw_program.get("raw_packet"), object_raw_packet),
                input_size=_int_or_default(raw_program.get("input_size"), object_input_size),
                memory_path=_string_or_none(raw_program.get("test_input")) or object_memory_path,
            )
        )

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
        measurement=object_measurement,
        programs=tuple(programs),
        fixture_path=fixture_path,
        compile_loader=compile_loader,
        loader=loader,
        loader_binary=loader_binary,
        loader_args=loader_args,
        loader_setup_script=loader_setup_script,
        loader_timeout_seconds=loader_timeout_seconds,
    )


def find_program_in_object(obj: ResolvedObject, program_name: str) -> ResolvedProgram | None:
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
        selected_programs = (
            obj.programs
            if object_selected
            else tuple(program for program in obj.programs if program_matches_filter(program, lowered_filters))
        )
        if not selected_programs:
            continue
        if remaining_programs is not None:
            if remaining_programs <= 0:
                break
            selected_programs = selected_programs[:remaining_programs]
            remaining_programs -= len(selected_programs)
            if not selected_programs:
                break
        selected_objects.append(clone_resolved_object(obj, selected_programs))

    available_objects = corpus_build_report["available_objects"]
    missing_from_build_report: list[str] = []
    for obj in selected_objects:
        if obj.object_abs_path in available_objects:
            continue
        location_detail = "present on disk but absent from report"
        if not Path(obj.object_abs_path).exists():
            location_detail = "absent from report and missing on disk"
        missing_from_build_report.append(f"{obj.object_path} ({location_detail})")

    if missing_from_build_report:
        raise SystemExit(
            "selected corpus objects are missing from the build report: "
            + ", ".join(missing_from_build_report[:12])
            + (" ..." if len(missing_from_build_report) > 12 else "")
        )

    build_summary_payload = corpus_build_report.get("summary") or {}
    report_available_total = int(
        build_summary_payload.get("available_total", len(available_objects)) or len(available_objects)
    )
    supplemented_existing = int(corpus_build_report.get("supplemented_existing", 0) or 0)
    measurement_counts = Counter(
        program.measurement for obj in selected_objects for program in obj.programs
    )
    summary = {
        "manifest": str(yaml_path),
        "schema_version": 2,
        "total_objects": len(resolved_objects),
        "selected_objects": len(selected_objects),
        "total_programs": sum(len(obj.programs) for obj in resolved_objects),
        "selected_programs": sum(len(obj.programs) for obj in selected_objects),
        "selected_programs_by_measurement": dict(sorted(measurement_counts.items())),
        "build_report_path": str(corpus_build_report["path"]),
        "available_objects": max(report_available_total, len(available_objects)),
        "built_from_source": int(build_summary_payload.get("built_ok", 0) or 0),
        "staged_existing": int(build_summary_payload.get("staged_existing", 0) or 0) + supplemented_existing,
        "supplemented_existing": supplemented_existing,
    }
    return selected_objects, summary

def require_minimum(value: int, minimum: int, flag: str) -> None:
    if value < minimum:
        raise SystemExit(f"{flag} must be >= {minimum}")


def _ipv4_checksum(header: bytes | bytearray) -> int:
    s = 0
    for index in range(0, len(header), 2):
        s += (header[index] << 8) + header[index + 1]
    while s >> 16:
        s = (s & 0xFFFF) + (s >> 16)
    return ~s & 0xFFFF


def _checksum16(data: bytes | bytearray) -> int:
    blob = bytes(data)
    if len(blob) % 2:
        blob += b"\x00"
    total = 0
    for index in range(0, len(blob), 2):
        total += (blob[index] << 8) + blob[index + 1]
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


_CORPUS_PACKET_MAGIC = bytes.fromhex("ffffffffffff")
_KATRAN_PACKET_MAGIC = bytes.fromhex("02000000000a")
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
    packet = bytearray(64)
    packet[0:6] = bytes.fromhex("ffffffffffff")
    packet[6:12] = bytes.fromhex("001122334455")
    packet[12:14] = bytes.fromhex("0800")
    packet[14] = 0x45
    packet[15] = 0x00
    packet[16:18] = (50).to_bytes(2, "big")
    packet[18:20] = (0).to_bytes(2, "big")
    packet[20:22] = (0x4000).to_bytes(2, "big")
    packet[22] = 64
    packet[23] = 6
    packet[24:26] = (0).to_bytes(2, "big")
    packet[26:30] = bytes([10, 0, 0, 1])
    packet[30:34] = bytes([10, 0, 0, 2])
    packet[24:26] = _ipv4_checksum(packet[14:34]).to_bytes(2, "big")
    packet[34:36] = (12345).to_bytes(2, "big")
    packet[36:38] = (80).to_bytes(2, "big")
    packet[38:42] = (1).to_bytes(4, "big")
    packet[42:46] = (0).to_bytes(4, "big")
    packet[46] = 0x50
    packet[47] = 0x02
    packet[48:50] = (8192).to_bytes(2, "big")
    packet[50:52] = (0).to_bytes(2, "big")
    packet[52:54] = (0).to_bytes(2, "big")
    packet[54:64] = bytes([0x41] * 10)
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
    if path.exists() and path.stat().st_size == 64 and path.read_bytes()[0:6] == _CORPUS_PACKET_MAGIC:
        return path
    path.write_bytes(_build_corpus_packet())
    return path


def materialize_katran_packet(path: Path) -> Path:
    ensure_parent(path)
    if path.exists() and path.stat().st_size == 64 and path.read_bytes()[0:6] == _KATRAN_PACKET_MAGIC:
        return path
    path.write_bytes(_build_katran_packet())
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


def sample_field(record: Mapping[str, Any] | None, field_name: str) -> Any:
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
    del obj
    if not baseline_record or not rejit_record:
        return None
    if not baseline_record.get("ok") or not rejit_record.get("ok"):
        return None
    if speedup_ratio(baseline_record, rejit_record) is not None:
        return None
    baseline_exec_ns = sample_field(baseline_record, "exec_ns")
    rejit_exec_ns = sample_field(rejit_record, "exec_ns")
    if baseline_exec_ns == 0 and rejit_exec_ns == 0:
        return f"{program.measurement} reported exec_ns=0 in baseline and REJIT"
    if baseline_exec_ns == 0:
        return f"{program.measurement} reported exec_ns=0 in baseline"
    if rejit_exec_ns == 0:
        return f"{program.measurement} reported exec_ns=0 in REJIT"
    return f"{program.measurement} runtime comparison is unavailable"


def rejit_metadata(record: dict[str, Any] | None) -> dict[str, Any]:
    if not record or not record.get("ok"):
        return {}
    return (record.get("sample") or {}).get("rejit") or {}


def rejit_passes(record: dict[str, Any] | None) -> list[str]:
    return normalize_passes(rejit_metadata(record).get("passes_applied"))


__all__ = [
    "ResolvedObject",
    "ResolvedProgram",
    "add_daemon_argument",
    "add_filter_argument",
    "add_max_programs_argument",
    "add_output_json_argument",
    "add_output_md_argument",
    "add_repeat_argument",
    "add_runner_argument",
    "add_timeout_argument",
    "clone_resolved_object",
    "comparison_exclusion_reason",
    "deserialize_resolved_object",
    "find_program_in_object",
    "format_ns",
    "format_pct",
    "format_ratio",
    "geomean",
    "load_corpus_build_report",
    "load_targets_from_yaml",
    "markdown_table",
    "materialize_dummy_context",
    "materialize_dummy_packet",
    "materialize_katran_packet",
    "normalize_passes",
    "program_label",
    "program_matches_filter",
    "relpath",
    "rejit_metadata",
    "rejit_passes",
    "require_minimum",
    "packet_batch_timeout_seconds",
    "resolve_manifest_object",
    "sanitize_guest_batch_record",
    "sample_field",
    "serialize_resolved_object",
    "size_delta_pct",
    "size_ratio",
    "speedup_ratio",
    "split_corpus_source",
    "summarize_failure_reason",
    "summarize_text",
]
