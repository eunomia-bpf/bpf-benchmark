#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import subprocess
import sys
import tempfile
from collections import Counter
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path
from typing import Any

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

from policy_utils import (
    POLICY_DIR,
    ROOT_DIR,
    canonical_policy_family_name,
    object_relative_path,
    object_roots,
    policy_path_for_program,
    render_policy_v3_text,
)

try:
    from orchestrator.inventory import discover_object_programs
except ImportError:
    from micro.orchestrator.inventory import discover_object_programs

try:
    from elftools.elf.elffile import ELFFile
except ImportError as exc:  # pragma: no cover - runtime dependency failure
    raise SystemExit("pyelftools is required: pip install pyelftools") from exc


DEFAULT_SCANNER = ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"
DEFAULT_RUNNER = ROOT_DIR / "micro" / "build" / "runner" / "micro_exec"
DEFAULT_TIMEOUT_SECONDS = 180
DEFAULT_WORKERS = max(1, min(8, os.cpu_count() or 1))
SHF_EXECINSTR = 0x4
POLICY_FAMILY_KEYS = (
    "cmov",
    "wide",
    "rotate",
    "extract",
    "lea",
    "zero-ext",
    "endian",
    "branch-flip",
)
SCANNER_SUMMARY_FIELDS = (
    ("cmov", "cmov_sites"),
    ("wide", "wide_sites"),
    ("rotate", "rotate_sites"),
    ("extract", "extract_sites"),
    ("lea", "lea_sites"),
    ("zero-ext", "zero_ext_sites"),
    ("endian", "endian_sites"),
    ("branch-flip", "branch_flip_sites"),
)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Generate per-program version 3 corpus policy YAMLs from scanner "
            "site manifests, keeping every discovered site except CMOV."
        )
    )
    parser.add_argument(
        "--scanner",
        default=str(DEFAULT_SCANNER),
        help="Path to bpf-jit-scanner.",
    )
    parser.add_argument(
        "--runner",
        default=str(DEFAULT_RUNNER),
        help="Path to micro_exec, used to enumerate program names in each object.",
    )
    parser.add_argument(
        "--policy-dir",
        default=str(POLICY_DIR),
        help="Output directory for generated policy files.",
    )
    parser.add_argument(
        "--object-root",
        action="append",
        dest="object_roots",
        help="Object root to scan for *.bpf.o files. Repeatable; defaults to existing corpus/build, corpus/expanded_corpus, corpus/objects.",
    )
    parser.add_argument(
        "--filter",
        action="append",
        dest="filters",
        help="Only scan objects whose relative path contains this substring. Repeatable.",
    )
    parser.add_argument(
        "--max-objects",
        type=int,
        help="Optional cap for smoke testing.",
    )
    parser.add_argument(
        "--workers",
        type=int,
        default=DEFAULT_WORKERS,
        help="Concurrent workers used for per-object inventory + scanner subprocesses.",
    )
    parser.add_argument(
        "--timeout",
        type=int,
        default=DEFAULT_TIMEOUT_SECONDS,
        help="Per-subprocess timeout in seconds.",
    )
    parser.add_argument(
        "--skip-families",
        default="cmov",
        help=(
            "Comma-separated policy families to exclude from the explicit allowlist. "
            "Defaults to cmov."
        ),
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Plan the version 3 policy outputs without writing files.",
    )
    return parser.parse_args(argv)


def parse_skip_families_arg(raw_value: str) -> tuple[str, ...]:
    families: list[str] = []
    seen: set[str] = set()
    for chunk in (raw_value or "").split(","):
        token = chunk.strip()
        if not token:
            continue
        family = canonical_policy_family_name(token)
        if family in seen:
            continue
        seen.add(family)
        families.append(family)
    return tuple(families)


def parse_last_json_line(stdout: str, *, label: str) -> Any:
    lines = [line.strip() for line in stdout.splitlines() if line.strip()]
    if not lines:
        raise RuntimeError(f"{label} produced no JSON output")
    return json.loads(lines[-1])


def run_json_command(command: list[str], *, timeout_seconds: int, label: str) -> Any:
    completed = subprocess.run(
        command,
        cwd=ROOT_DIR,
        capture_output=True,
        text=True,
        timeout=timeout_seconds,
        check=False,
    )
    if completed.returncode != 0:
        detail = completed.stderr.strip() or completed.stdout.strip() or f"exit={completed.returncode}"
        raise RuntimeError(f"{label} failed: {' '.join(command)}\n{detail}")
    return parse_last_json_line(completed.stdout, label=label)


def is_bpf_machine(path: Path) -> bool:
    with path.open("rb") as handle:
        elf = ELFFile(handle)
        machine = elf["e_machine"]
        return machine == "EM_BPF" or int(machine) == 247


def filter_bpf_paths(paths: list[Path]) -> list[Path]:
    kept: list[Path] = []
    for path in paths:
        try:
            if is_bpf_machine(path):
                kept.append(path)
        except Exception:
            continue
    return kept


def discover_object_paths(
    root_paths: tuple[Path, ...],
    *,
    filters: list[str] | None,
    max_objects: int | None,
) -> list[Path]:
    lowered_filters = [token.lower() for token in (filters or []) if token]
    discovered: list[Path] = []
    seen: set[Path] = set()
    for root in root_paths:
        for path in filter_bpf_paths(sorted(root.rglob("*.bpf.o"))):
            resolved = path.resolve()
            if resolved in seen:
                continue
            relative = object_relative_path(resolved).as_posix().lower()
            if lowered_filters and not any(token in relative for token in lowered_filters):
                continue
            seen.add(resolved)
            discovered.append(resolved)
            if max_objects is not None and len(discovered) >= max_objects:
                return discovered
    return discovered


def scan_program_manifest(
    scanner: Path,
    object_path: Path,
    program_name: str,
    section_name: str,
    *,
    timeout_seconds: int,
) -> dict[str, Any]:
    label = f"scanner:{object_relative_path(object_path).as_posix()}:{program_name}"
    try:
        payload = run_json_command(
            [
                str(scanner),
                "scan",
                str(object_path),
                "--program-name",
                program_name,
                "--all",
                "--json",
            ],
            timeout_seconds=timeout_seconds,
            label=label,
        )
    except RuntimeError:
        payload = scan_program_manifest_from_section(
            scanner,
            object_path,
            program_name,
            section_name,
            timeout_seconds=timeout_seconds,
            label=label,
        )
    if not isinstance(payload, dict):
        raise RuntimeError(
            f"scanner output for {object_relative_path(object_path).as_posix()}:{program_name} "
            "was not a JSON object"
        )
    return payload


def load_executable_section_bytes(object_path: Path, section_name: str) -> bytes:
    with object_path.open("rb") as handle:
        elf = ELFFile(handle)
        for section in elf.iter_sections():
            name = section.name or ""
            flags = int(section.header["sh_flags"])
            if name != section_name:
                continue
            if not (flags & SHF_EXECINSTR) or section.data_size <= 0:
                raise RuntimeError(
                    f"section {section_name} in {object_relative_path(object_path).as_posix()} is not executable"
                )
            return bytes(section.data())
    raise RuntimeError(
        f"unable to locate executable section {section_name} in {object_relative_path(object_path).as_posix()}"
    )


def scan_program_manifest_from_section(
    scanner: Path,
    object_path: Path,
    program_name: str,
    section_name: str,
    *,
    timeout_seconds: int,
    label: str,
) -> dict[str, Any]:
    section_bytes = load_executable_section_bytes(object_path, section_name)
    with tempfile.NamedTemporaryFile(
        prefix="corpus-policy-program-",
        suffix=".xlated",
        dir=ROOT_DIR,
        delete=False,
    ) as handle:
        handle.write(section_bytes)
        tmp_path = Path(handle.name)
    try:
        return run_json_command(
            [
                str(scanner),
                "scan",
                "--xlated",
                str(tmp_path),
                "--program-name",
                program_name,
                "--all",
                "--json",
            ],
            timeout_seconds=timeout_seconds,
            label=f"{label}:section-fallback",
        )
    finally:
        tmp_path.unlink(missing_ok=True)

def object_scan_summary(
    scanner: Path,
    runner: Path,
    object_path: Path,
    *,
    timeout_seconds: int,
) -> dict[str, Any]:
    warnings: list[str] = []
    try:
        programs = discover_object_programs(runner, object_path, timeout_seconds=timeout_seconds)
    except Exception as exc:
        return {
            "object_path": object_path,
            "relative_path": object_relative_path(object_path),
            "program_count": 0,
            "site_positive_programs": 0,
            "total_sites": 0,
            "family_totals": {},
            "programs": [],
            "warnings": [
                "inventory failed for "
                f"{object_relative_path(object_path).as_posix()}: {exc}"
            ],
        }
    program_records: list[dict[str, Any]] = []
    family_totals = Counter()
    site_positive_programs = 0
    total_sites = 0

    for entry in programs:
        try:
            manifest = scan_program_manifest(
                scanner,
                object_path,
                entry.name,
                entry.section_name,
                timeout_seconds=timeout_seconds,
            )
        except Exception as exc:
            warnings.append(
                "program scan failed for "
                f"{object_relative_path(object_path).as_posix()}:{entry.name}: {exc}"
            )
            continue
        summary = manifest.get("summary") or {}
        site_total = int(summary.get("total_sites", 0) or 0)
        if site_total <= 0:
            continue
        site_positive_programs += 1
        total_sites += site_total
        for family_key, field in SCANNER_SUMMARY_FIELDS:
            family_totals[family_key] += int(summary.get(field, 0) or 0)
        program_records.append(
            {
                "program_name": entry.name,
                "section_name": entry.section_name,
                "site_total": site_total,
                "manifest": manifest,
            }
        )

    program_records.sort(key=lambda item: (item["section_name"], item["program_name"]))
    return {
        "object_path": object_path,
        "relative_path": object_relative_path(object_path),
        "program_count": len(programs),
        "site_positive_programs": site_positive_programs,
        "total_sites": total_sites,
        "family_totals": dict(family_totals),
        "programs": program_records,
        "warnings": warnings,
    }


def render_program_policy_text(
    *,
    object_path: Path,
    program_name: str,
    section_name: str,
    manifest: dict[str, Any],
    skip_families: frozenset[str],
) -> str:
    site_counts = Counter()
    skipped_site_counts = Counter()
    rendered_sites: list[dict[str, Any]] = []
    for entry in manifest.get("sites") or []:
        if not isinstance(entry, dict):
            continue
        family = canonical_policy_family_name(str(entry.get("family", "")))
        site_counts[family] += 1
        if family in skip_families:
            skipped_site_counts[family] += 1
            continue
        pattern_kind = str(entry.get("pattern_kind", "")).strip()
        insn = int(entry.get("insn", entry.get("start_insn", -1)))
        if insn < 0 or not pattern_kind:
            continue
        rendered_sites.append(
            {
                "insn": insn,
                "family": family,
                "pattern_kind": pattern_kind,
            }
        )
    rendered_sites.sort(
        key=lambda item: (
            int(item["insn"]),
            str(item["family"]),
            str(item["pattern_kind"]),
        )
    )
    skipped_families_list = [family for family in POLICY_FAMILY_KEYS if family in skip_families]

    comments = [
        "Auto-generated by corpus/generate_default_policies.py.",
        f"Object: {object_relative_path(object_path).as_posix()}",
        f"Program: {program_name}",
        f"Section: {section_name}",
        f"Total scanner sites: {int((manifest.get('summary') or {}).get('total_sites', 0) or 0)}",
        "Family site totals: "
        + ", ".join(f"{family}={site_counts.get(family, 0)}" for family in POLICY_FAMILY_KEYS),
        "Selection model: explicit site allowlist; keep every discovered site except skipped families: "
        + ", ".join(skipped_families_list),
    ]
    for family in skipped_families_list:
        skipped_count = skipped_site_counts.get(family, 0)
        if skipped_count <= 0:
            continue
        comments.append(
            f"Excluded {family} sites from allowlist: {skipped_count}"
        )

    return render_policy_v3_text(
        program_name=program_name,
        sites=rendered_sites,
        comments=comments,
    )


def write_policy_file(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text)


def display_path(path: Path) -> str:
    try:
        return path.relative_to(ROOT_DIR).as_posix()
    except ValueError:
        return str(path)


def prune_empty_policy_dirs(policy_dir: Path) -> None:
    if not policy_dir.exists():
        return
    for path in sorted(
        (candidate for candidate in policy_dir.rglob("*") if candidate.is_dir()),
        key=lambda candidate: len(candidate.parts),
        reverse=True,
    ):
        try:
            path.rmdir()
        except OSError:
            continue


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)

    scanner = Path(args.scanner).resolve()
    runner = Path(args.runner).resolve()
    policy_dir = Path(args.policy_dir).resolve()
    skip_families = frozenset(parse_skip_families_arg(args.skip_families))
    selected_roots = (
        tuple(Path(item).resolve() for item in args.object_roots)
        if args.object_roots
        else object_roots()
    )

    if not selected_roots:
        raise SystemExit(
            "no corpus object roots found; expected corpus/build, corpus/expanded_corpus, or corpus/objects"
        )
    if not scanner.exists():
        raise SystemExit(f"scanner not found: {scanner}")
    if not runner.exists():
        raise SystemExit(f"runner not found: {runner}")

    object_paths = discover_object_paths(
        selected_roots,
        filters=args.filters,
        max_objects=args.max_objects,
    )
    if not object_paths:
        raise SystemExit("no corpus objects matched the selected roots/filters")

    summaries: list[dict[str, Any]] = []
    with ThreadPoolExecutor(max_workers=max(1, args.workers)) as executor:
        future_to_path = {
            executor.submit(
                object_scan_summary,
                scanner,
                runner,
                object_path,
                timeout_seconds=args.timeout,
            ): object_path
            for object_path in object_paths
        }
        for future in as_completed(future_to_path):
            object_path = future_to_path[future]
            try:
                summaries.append(future.result())
            except Exception as exc:
                raise SystemExit(f"failed to scan {object_path}: {exc}") from exc

    summaries.sort(key=lambda item: item["relative_path"].as_posix())

    warning_count = 0
    for summary in summaries:
        for warning in summary.get("warnings") or []:
            print(f"warning: {warning}", file=sys.stderr)
            warning_count += 1

    planned_outputs: list[tuple[Path, str]] = []
    policy_positive_objects = 0
    policy_positive_programs = 0
    skipped_family_objects = Counter()
    skipped_family_programs = Counter()
    for summary in summaries:
        programs = summary["programs"]
        if not programs:
            continue
        policy_positive_objects += 1
        object_path = Path(summary["object_path"]).resolve()
        object_skipped_families: set[str] = set()
        for program in programs:
            manifest = program["manifest"]
            summary_payload = manifest.get("summary") or {}
            summary_counts = {
                family_key: int(summary_payload.get(field, 0) or 0)
                for family_key, field in SCANNER_SUMMARY_FIELDS
            }
            for family in skip_families:
                if summary_counts.get(family, 0) <= 0:
                    continue
                object_skipped_families.add(family)
                skipped_family_programs[family] += 1
            policy_path = policy_path_for_program(object_path, program["program_name"], policy_dir)
            text = render_program_policy_text(
                object_path=object_path,
                program_name=program["program_name"],
                section_name=program["section_name"],
                manifest=manifest,
                skip_families=skip_families,
            )
            planned_outputs.append((policy_path, text))
            policy_positive_programs += 1
        for family in object_skipped_families:
            skipped_family_objects[family] += 1

    planned_outputs.sort(key=lambda item: display_path(item[0]))

    stale_paths: list[Path] = []
    if not args.dry_run and policy_dir.exists():
        planned_set = {path.resolve() for path, _ in planned_outputs}
        stale_paths = [
            path
            for path in sorted(policy_dir.rglob("*.policy.yaml"))
            if path.resolve() not in planned_set
        ]
        for stale_path in stale_paths:
            stale_path.unlink()

    action = "would write" if args.dry_run else "wrote"
    for policy_path, text in planned_outputs:
        if not args.dry_run:
            write_policy_file(policy_path, text)
        print(f"{action} {display_path(policy_path)}")

    if not args.dry_run and stale_paths:
        for stale_path in stale_paths:
            print(f"removed stale {display_path(stale_path)}")
        prune_empty_policy_dirs(policy_dir)

    print(
        "summary: "
        f"scanned_objects={len(summaries)} "
        f"site_positive_objects={policy_positive_objects} "
        f"site_positive_programs={policy_positive_programs} "
        f"policies={'planned' if args.dry_run else 'written'}={len(planned_outputs)} "
        f"skip_families={','.join(skip_families) or 'none'} "
        f"skip_objects="
        f"{','.join(f'{family}:{skipped_family_objects.get(family, 0)}' for family in POLICY_FAMILY_KEYS if family in skip_families) or 'none'} "
        f"skip_programs="
        f"{','.join(f'{family}:{skipped_family_programs.get(family, 0)}' for family in POLICY_FAMILY_KEYS if family in skip_families) or 'none'} "
        f"stale_removed={(0 if args.dry_run else len(stale_paths))} "
        f"warnings={warning_count}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
