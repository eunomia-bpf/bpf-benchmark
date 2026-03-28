#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import subprocess
import sys
import tempfile
from collections import Counter, defaultdict
from pathlib import Path
from typing import Any

import yaml


SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent.parent
DEFAULT_MANIFEST = REPO_ROOT / "corpus" / "config" / "macro_corpus.yaml"
DEFAULT_RUNNER = REPO_ROOT / "runner" / "build" / "micro_exec"

PROGRAM_FIELDS = [
    "description",
    "category",
    "family",
    "level",
    "hypothesis",
    "tags",
    "test_method",
    "prog_type",
    "section",
    "io_mode",
    "test_input",
    "input_size",
    "trigger",
    "trigger_timeout_seconds",
]

OBJECT_ONLY_FIELDS = [
    "compile_loader",
]

OBJECT_LIFT_FIELDS = [
    "description",
    "category",
    "family",
    "level",
    "hypothesis",
    "tags",
    "prog_type",
    "section",
    "io_mode",
    "test_input",
    "input_size",
    "trigger",
    "trigger_timeout_seconds",
    "compile_loader",
]


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Migrate corpus/config/macro_corpus.yaml from flat v1 entries to object-centric v2."
    )
    parser.add_argument(
        "--input",
        default=str(DEFAULT_MANIFEST),
        help="Path to the v1 macro corpus YAML.",
    )
    parser.add_argument(
        "--output",
        default=str(DEFAULT_MANIFEST),
        help="Path to write the v2 macro corpus YAML.",
    )
    parser.add_argument(
        "--runner",
        default=str(DEFAULT_RUNNER),
        help="Path to runner/build/micro_exec used for list-programs.",
    )
    return parser.parse_args()


def split_corpus_source(source: str) -> tuple[str, str]:
    source_path = Path(source)
    parts = source_path.parts
    for index in range(len(parts) - 2):
        if parts[index : index + 2] != ("corpus", "build"):
            continue
        repo_index = index + 2
        repo = str(parts[repo_index]).strip()
        object_relpath = str(Path(*parts[repo_index + 1 :])).strip()
        if object_relpath:
            return repo, object_relpath
        return repo, source_path.name
    return "", source_path.name


def normalize_scalar(value: Any) -> Any:
    if value is None:
        return None
    if isinstance(value, str):
        stripped = value.strip()
        return stripped or None
    if isinstance(value, list):
        items = [str(item).strip() for item in value if str(item).strip()]
        return items or None
    return value


def normalized_value(value: Any) -> Any:
    value = normalize_scalar(value)
    if isinstance(value, list):
        return tuple(value)
    return value


def is_meaningful(value: Any) -> bool:
    normalized = normalize_scalar(value)
    return normalized is not None


def manifest_program_names(entry: dict[str, Any]) -> list[str]:
    program_name = str(entry.get("program_name") or "").strip()
    if program_name:
        return [program_name]
    return [str(item).strip() for item in (entry.get("program_names") or []) if str(item).strip()]


def manifest_section_map(entry: dict[str, Any], names: list[str]) -> dict[str, str]:
    sections = [str(item).strip() for item in (entry.get("sections") or []) if str(item).strip()]
    if not names or not sections:
        return {}
    if len(sections) == len(names):
        return dict(zip(names, sections, strict=True))
    if len(sections) == 1 and len(names) == 1:
        return {names[0]: sections[0]}
    return {}


def entry_specificity(entry: dict[str, Any]) -> tuple[int, int, int]:
    names = manifest_program_names(entry)
    scalar_program = 0 if str(entry.get("program_name") or "").strip() else 1
    populated = 0
    for field in PROGRAM_FIELDS + OBJECT_ONLY_FIELDS:
        if field == "section":
            value = entry.get("sections")
        else:
            value = entry.get(field)
        if is_meaningful(value):
            populated += 1
    return (len(names) or 1, scalar_program, -populated)


def build_program_fragment(entry: dict[str, Any], program_name: str, section_hint: str | None) -> dict[str, Any]:
    fragment: dict[str, Any] = {}
    for field in PROGRAM_FIELDS:
        if field == "section":
            value = section_hint
        else:
            value = entry.get(field)
        normalized = normalize_scalar(value)
        if normalized is not None:
            fragment[field] = normalized
    for field in OBJECT_ONLY_FIELDS:
        normalized = normalize_scalar(entry.get(field))
        if normalized is not None:
            fragment[field] = normalized
    return fragment


def merge_program_fragments(source: str, program_name: str, fragments: list[tuple[tuple[int, int, int], dict[str, Any]]]) -> dict[str, Any]:
    merged: dict[str, Any] = {}
    chosen_by_field: dict[str, tuple[int, int, int]] = {}
    conflicts: list[str] = []
    for specificity, fragment in sorted(fragments, key=lambda item: item[0]):
        for field, value in fragment.items():
            if not is_meaningful(value):
                continue
            if field not in merged:
                merged[field] = value
                chosen_by_field[field] = specificity
                continue
            if normalized_value(merged[field]) == normalized_value(value):
                continue
            previous_specificity = chosen_by_field[field]
            if specificity == previous_specificity:
                conflicts.append(
                    f"{source}:{program_name}:{field} conflict between equally specific fragments "
                    f"({merged[field]!r} vs {value!r})"
                )
    if conflicts:
        raise SystemExit("\n".join(conflicts))
    return merged


def list_programs(runner: Path, source: str) -> tuple[list[dict[str, Any]], str | None]:
    command = [str(runner), "list-programs", "--program", source]
    completed = subprocess.run(
        command,
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
        check=False,
    )
    if completed.returncode != 0:
        error = completed.stderr.strip() or completed.stdout.strip() or f"exit {completed.returncode}"
        return [], error
    try:
        payload = json.loads(completed.stdout)
    except json.JSONDecodeError as exc:
        return [], f"invalid JSON: {exc}"
    if not isinstance(payload, list):
        return [], "list-programs output was not a JSON array"
    programs: list[dict[str, Any]] = []
    for item in payload:
        if not isinstance(item, dict):
            return [], "list-programs entry was not a JSON object"
        name = str(item.get("name") or "").strip()
        if not name:
            continue
        section = str(item.get("section_name") or "").strip() or None
        prog_type = str(item.get("prog_type_name") or "").strip() or None
        programs.append(
            {
                "name": name,
                "section": section,
                "prog_type": prog_type,
            }
        )
    return programs, None


def common_nonempty_value(records: list[dict[str, Any]], field: str) -> Any:
    if not records:
        return None
    values = [record.get(field) for record in records]
    if not all(is_meaningful(value) for value in values):
        return None
    baseline = normalized_value(values[0])
    for value in values[1:]:
        if normalized_value(value) != baseline:
            return None
    return values[0]


def choose_default_test_method(programs: list[dict[str, Any]]) -> str:
    methods = [str(program.get("test_method") or "").strip() for program in programs if str(program.get("test_method") or "").strip()]
    if not methods:
        return "compile_only"
    counts = Counter(methods)
    return sorted(counts.items(), key=lambda item: (-item[1], item[0]))[0][0]


def render_program_entry(program: dict[str, Any], object_defaults: dict[str, Any]) -> dict[str, Any]:
    entry: dict[str, Any] = {"name": program["name"]}
    for field in PROGRAM_FIELDS:
        if field == "test_method":
            object_value = object_defaults.get("test_method")
            value = program.get(field)
            if is_meaningful(value) and normalized_value(value) != normalized_value(object_value):
                entry[field] = value
            continue
        value = program.get(field)
        if not is_meaningful(value):
            continue
        object_value = object_defaults.get(field)
        if is_meaningful(object_value) and normalized_value(value) == normalized_value(object_value):
            continue
        entry[field] = value
    return entry


def migrate_object_entry(
    source: str,
    entries: list[dict[str, Any]],
    runner: Path,
    failed_discovery: list[dict[str, Any]],
) -> dict[str, Any]:
    repo, _object_relpath = split_corpus_source(source)
    per_program_fragments: dict[str, list[tuple[tuple[int, int, int], dict[str, Any]]]] = defaultdict(list)
    all_compile_loaders: list[Any] = []

    for entry in entries:
        names = manifest_program_names(entry)
        sections = manifest_section_map(entry, names)
        specificity = entry_specificity(entry)
        compile_loader = normalize_scalar(entry.get("compile_loader"))
        if compile_loader is not None:
            all_compile_loaders.append(compile_loader)
        for name in names:
            fragment = build_program_fragment(entry, name, sections.get(name))
            per_program_fragments[name].append((specificity, fragment))

    discovered_programs, discovery_error = list_programs(runner, source)
    if discovery_error is not None:
        failed_discovery.append({"source": source, "error": discovery_error})
        object_entry: dict[str, Any] = {
            "source": source,
            "repo": repo,
            "test_method": "compile_only",
            "allow_object_only_result": True,
            "programs": [],
        }
        common_loader = None
        if all_compile_loaders:
            unique_loaders = {normalized_value(value) for value in all_compile_loaders}
            if len(unique_loaders) == 1:
                common_loader = all_compile_loaders[0]
        if common_loader is not None:
            object_entry["compile_loader"] = common_loader
        return object_entry

    discovered_names = [item["name"] for item in discovered_programs]
    manifest_names = set(per_program_fragments)
    missing_manifest_names = manifest_names.difference(discovered_names)
    extra_discovered_names = set(discovered_names).difference(manifest_names)
    if missing_manifest_names or extra_discovered_names:
        problems: list[str] = []
        if missing_manifest_names:
            problems.append(f"manifest-only={sorted(missing_manifest_names)}")
        if extra_discovered_names:
            problems.append(f"discovered-only={sorted(extra_discovered_names)}")
        raise SystemExit(f"{source}: list-programs inventory drift: {', '.join(problems)}")

    resolved_programs: list[dict[str, Any]] = []
    discovered_by_name = {item["name"]: item for item in discovered_programs}
    for program_name in discovered_names:
        merged = merge_program_fragments(source, program_name, per_program_fragments[program_name])
        discovery = discovered_by_name[program_name]
        if not is_meaningful(merged.get("section")) and is_meaningful(discovery.get("section")):
            merged["section"] = discovery["section"]
        if not is_meaningful(merged.get("prog_type")) and is_meaningful(discovery.get("prog_type")):
            merged["prog_type"] = discovery["prog_type"]
        merged["name"] = program_name
        resolved_programs.append(merged)

    object_entry = {
        "source": source,
        "repo": repo,
    }

    object_defaults: dict[str, Any] = {}
    object_defaults["test_method"] = choose_default_test_method(resolved_programs)
    object_entry["test_method"] = object_defaults["test_method"]

    for field in OBJECT_LIFT_FIELDS:
        value = common_nonempty_value(resolved_programs, field)
        if value is None:
            continue
        object_defaults[field] = value
        object_entry[field] = value

    object_entry["programs"] = [render_program_entry(program, object_defaults) for program in resolved_programs]
    return object_entry


def migrate_manifest(data: dict[str, Any], runner: Path) -> tuple[dict[str, Any], list[dict[str, Any]]]:
    programs = data.get("programs")
    if not isinstance(programs, list):
        raise SystemExit("expected v1 macro corpus with a top-level 'programs' list")

    grouped: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for entry in programs:
        if not isinstance(entry, dict):
            raise SystemExit("manifest programs entries must be mappings")
        source = str(entry.get("source") or "").strip()
        if not source:
            raise SystemExit("manifest entry missing source")
        grouped[source].append(dict(entry))

    migrated: dict[str, Any] = {}
    migrated["schema_version"] = 2
    for key in ("suite_name", "defaults", "build", "runtimes"):
        if key in data:
            migrated[key] = data[key]

    failed_discovery: list[dict[str, Any]] = []
    objects: list[dict[str, Any]] = []
    for source in sorted(grouped):
        objects.append(migrate_object_entry(source, grouped[source], runner, failed_discovery))
    migrated["objects"] = objects
    return migrated, failed_discovery


def atomic_write_yaml(path: Path, payload: dict[str, Any]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.NamedTemporaryFile(
        mode="w",
        dir=path.parent,
        prefix=f"{path.name}.",
        suffix=".tmp",
        delete=False,
        encoding="utf-8",
    ) as handle:
        yaml.safe_dump(payload, handle, sort_keys=False, allow_unicode=False)
        temp_path = Path(handle.name)
    temp_path.replace(path)


def main() -> int:
    args = parse_args()
    input_path = Path(args.input).resolve()
    output_path = Path(args.output).resolve()
    runner = Path(args.runner).resolve()

    if not input_path.exists():
        raise SystemExit(f"input manifest not found: {input_path}")
    if not runner.exists():
        raise SystemExit(f"runner not found: {runner}")

    data = yaml.safe_load(input_path.read_text(encoding="utf-8"))
    if not isinstance(data, dict):
        raise SystemExit(f"manifest root must be a mapping: {input_path}")
    if int(data.get("schema_version", 1) or 1) >= 2 or "objects" in data:
        atomic_write_yaml(output_path, data)
        object_count = len(data.get("objects") or [])
        program_count = sum(len(item.get("programs") or []) for item in (data.get("objects") or []))
        print(f"manifest already v2: {output_path} objects={object_count} programs={program_count}")
        return 0

    migrated, failed_discovery = migrate_manifest(data, runner)
    atomic_write_yaml(output_path, migrated)

    object_count = len(migrated.get("objects") or [])
    program_count = sum(len(item.get("programs") or []) for item in (migrated.get("objects") or []))
    print(
        f"wrote {output_path} objects={object_count} programs={program_count} "
        f"discovery_failures={len(failed_discovery)}"
    )
    for failure in failed_discovery:
        print(f"  discovery-failed {failure['source']}: {failure['error']}", file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
