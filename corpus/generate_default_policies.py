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
from typing import Any, Mapping

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

from runner.libs.policy import (
    POLICY_DIR,
    ROOT_DIR,
    canonical_policy_family_name,
    live_policy_dir,
    live_policy_path_for_program,
    object_relative_path,
    object_roots,
    policy_sites_from_manifest,
    policy_path_for_program,
    render_manifest_policy_v3_text,
)
from runner.libs.profiler import resolve_target_programs
from runner.libs.recompile import enumerate_program_record

try:
    from runner.libs.inventory import discover_object_programs
except ImportError:
    from runner.libs.inventory import discover_object_programs

try:
    from elftools.elf.elffile import ELFFile
except ImportError as exc:  # pragma: no cover - runtime dependency failure
    raise SystemExit("pyelftools is required: pip install pyelftools") from exc


DEFAULT_DAEMON = ROOT_DIR / "daemon" / "build" / "bpfrejit-daemon"
DEFAULT_RUNNER = ROOT_DIR / "runner" / "build" / "micro_exec"
DEFAULT_TIMEOUT_SECONDS = 180
DEFAULT_WORKERS = max(1, min(8, os.cpu_count() or 1))
SHF_EXECINSTR = 0x4
POLICY_FAMILY_KEYS = (
    "cmov",
    "wide",
    "rotate",
    "extract",
    "lea",
    "endian",
    "branch-flip",
)
SCANNER_SUMMARY_FIELDS = (
    ("cmov", "cmov_sites"),
    ("wide", "wide_sites"),
    ("rotate", "rotate_sites"),
    ("extract", "extract_sites"),
    ("lea", "lea_sites"),
    ("endian", "endian_sites"),
    ("branch-flip", "branch_flip_sites"),
)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Generate per-program version 3 corpus policy YAMLs from daemon "
            "site manifests, keeping every discovered site except CMOV."
        )
    )
    parser.add_argument(
        "--daemon",
        default=str(DEFAULT_DAEMON),
        help="Path to bpfrejit-daemon.",
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
        "--live",
        action="store_true",
        help="Enumerate live programs via bpftool + daemon enumerate instead of offline corpus objects.",
    )
    parser.add_argument(
        "--prog-id",
        action="append",
        dest="prog_ids",
        type=int,
        help="Only include these live BPF program ids in --live mode. Repeatable.",
    )
    parser.add_argument(
        "--name-contains",
        action="append",
        dest="name_contains",
        help="Only include live programs whose name contains this substring in --live mode. Repeatable.",
    )
    parser.add_argument(
        "--type",
        action="append",
        dest="type_equals",
        help="Only include live programs whose bpftool type matches this token in --live mode. Repeatable.",
    )
    parser.add_argument(
        "--max-programs",
        type=int,
        help="Optional cap for --live mode smoke testing.",
    )
    parser.add_argument(
        "--workers",
        type=int,
        default=DEFAULT_WORKERS,
        help="Concurrent workers used for per-object inventory + daemon subprocesses.",
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
    daemon: Path,
    object_path: Path,
    program_name: str,
    section_name: str,
    *,
    timeout_seconds: int,
) -> dict[str, Any]:
    label = f"daemon:{object_relative_path(object_path).as_posix()}:{program_name}"
    try:
        payload = run_json_command(
            [
                str(daemon),
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
            daemon,
            object_path,
            program_name,
            section_name,
            timeout_seconds=timeout_seconds,
            label=label,
        )
    if not isinstance(payload, dict):
        raise RuntimeError(
            f"daemon output for {object_relative_path(object_path).as_posix()}:{program_name} "
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
    daemon: Path,
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
                str(daemon),
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
    daemon: Path,
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
                daemon,
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
    _sites, site_counts, skipped_site_counts = policy_sites_from_manifest(
        manifest,
        skip_families=skip_families,
    )
    skipped_families_list = [family for family in POLICY_FAMILY_KEYS if family in skip_families]

    comments = [
        "Auto-generated by corpus/generate_default_policies.py.",
        f"Object: {object_relative_path(object_path).as_posix()}",
        f"Program: {program_name}",
        f"Section: {section_name}",
        f"Total daemon sites: {int((manifest.get('summary') or {}).get('total_sites', 0) or 0)}",
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

    rendered, _summary = render_manifest_policy_v3_text(
        program_name=program_name,
        manifest=manifest,
        comments=comments,
        skip_families=skip_families,
    )
    return rendered


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


def is_under(path: Path, root: Path) -> bool:
    try:
        path.resolve().relative_to(root.resolve())
        return True
    except ValueError:
        return False


def live_program_manifest_summary(
    daemon: Path,
    program: Mapping[str, Any],
    *,
    timeout_seconds: int,
) -> dict[str, Any]:
    prog_id = int(program.get("id", 0) or 0)
    program_name = str(program.get("name", "")).strip() or f"id-{prog_id}"
    program_type = str(program.get("type", "")).strip()
    manifest = enumerate_program_record(daemon, prog_id, timeout_seconds=timeout_seconds)
    enum_name = str(manifest.get("name") or "").strip()
    if enum_name:
        program_name = enum_name
    sites, family_counts, skipped_counts = policy_sites_from_manifest(manifest, skip_families=frozenset())
    live_total_sites = int(manifest.get("total_sites", 0) or 0)
    if live_total_sites <= 0:
        live_total_sites = len(sites)
    return {
        "prog_id": prog_id,
        "program_name": program_name,
        "program_type": program_type or str(manifest.get("type") or "").strip(),
        "site_total": live_total_sites,
        "family_totals": family_counts,
        "skipped_family_totals": skipped_counts,
        "manifest": manifest,
    }


def discover_live_program_summaries(
    daemon: Path,
    *,
    prog_ids: list[int] | None,
    name_contains: list[str] | None,
    type_equals: list[str] | None,
    max_programs: int | None,
    timeout_seconds: int,
) -> tuple[list[dict[str, Any]], list[str]]:
    selected = resolve_target_programs(
        prog_ids=prog_ids,
        name_contains=name_contains,
        type_equals=type_equals,
    )
    if max_programs is not None:
        selected = selected[: max(0, int(max_programs))]
    summaries: list[dict[str, Any]] = []
    warnings: list[str] = []
    for program in selected:
        prog_id = int(program.get("id", 0) or 0)
        if prog_id <= 0:
            continue
        try:
            summaries.append(
                live_program_manifest_summary(
                    daemon,
                    program,
                    timeout_seconds=timeout_seconds,
                )
            )
        except Exception as exc:
            warnings.append(f"live enumerate failed for prog_id={prog_id}: {exc}")
    summaries.sort(key=lambda item: (str(item["program_name"]), int(item["prog_id"])))
    return summaries, warnings


def render_live_program_policy_text(
    *,
    prog_id: int,
    program_name: str,
    program_type: str,
    manifest: Mapping[str, Any],
    skip_families: frozenset[str],
) -> str:
    _sites, site_counts, skipped_site_counts = policy_sites_from_manifest(
        manifest,
        skip_families=skip_families,
    )
    skipped_families_list = [family for family in POLICY_FAMILY_KEYS if family in skip_families]
    comments = [
        "Auto-generated by corpus/generate_default_policies.py --live.",
        f"Live program id: {prog_id}",
        f"Program: {program_name}",
        f"Type: {program_type or 'unknown'}",
        f"Total live daemon sites: {int(manifest.get('total_sites', 0) or 0)}",
        "Family site totals: "
        + ", ".join(f"{family}={site_counts.get(family, 0)}" for family in POLICY_FAMILY_KEYS),
        "Selection model: explicit site allowlist; keep every discovered live site except skipped families: "
        + ", ".join(skipped_families_list),
    ]
    for family in skipped_families_list:
        skipped_count = skipped_site_counts.get(family, 0)
        if skipped_count <= 0:
            continue
        comments.append(f"Excluded {family} sites from allowlist: {skipped_count}")
    rendered, _summary = render_manifest_policy_v3_text(
        program_name=program_name,
        manifest=manifest,
        comments=comments,
        skip_families=skip_families,
    )
    return rendered


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)

    daemon = Path(args.daemon).resolve()
    policy_dir = Path(args.policy_dir).resolve()
    skip_families = frozenset(parse_skip_families_arg(args.skip_families))
    if not daemon.exists():
        raise SystemExit(f"daemon not found: {daemon}")

    planned_outputs: list[tuple[Path, str]] = []
    warning_count = 0
    stale_root = policy_dir
    summary_text = ""

    if args.live:
        summaries, warnings = discover_live_program_summaries(
            daemon,
            prog_ids=args.prog_ids,
            name_contains=args.name_contains,
            type_equals=args.type_equals,
            max_programs=args.max_programs,
            timeout_seconds=args.timeout,
        )
        if not summaries and not warnings:
            raise SystemExit("no live BPF programs matched the requested filters")
        for warning in warnings:
            print(f"warning: {warning}", file=sys.stderr)
            warning_count += 1

        policy_positive_programs = 0
        skipped_family_programs = Counter()
        for summary in summaries:
            if int(summary.get("site_total", 0) or 0) <= 0:
                continue
            manifest = summary["manifest"]
            family_counts = summary["family_totals"]
            for family in skip_families:
                if int(family_counts.get(family, 0) or 0) > 0:
                    skipped_family_programs[family] += 1
            policy_path = live_policy_path_for_program(
                str(summary["program_name"]),
                prog_id=int(summary["prog_id"]),
                policy_dir=policy_dir,
            )
            text = render_live_program_policy_text(
                prog_id=int(summary["prog_id"]),
                program_name=str(summary["program_name"]),
                program_type=str(summary.get("program_type", "")),
                manifest=manifest,
                skip_families=skip_families,
            )
            planned_outputs.append((policy_path, text))
            policy_positive_programs += 1
        stale_root = live_policy_dir(policy_dir)
        summary_text = (
            "summary: "
            f"mode=live "
            f"enumerated_programs={len(summaries)} "
            f"site_positive_programs={policy_positive_programs} "
            f"policies={'planned' if args.dry_run else 'written'}={len(planned_outputs)} "
            f"skip_families={','.join(skip_families) or 'none'} "
            f"skip_programs="
            f"{','.join(f'{family}:{skipped_family_programs.get(family, 0)}' for family in POLICY_FAMILY_KEYS if family in skip_families) or 'none'} "
            f"stale_removed={{stale_removed}} "
            f"warnings={warning_count}"
        )
    else:
        runner = Path(args.runner).resolve()
        selected_roots = (
            tuple(Path(item).resolve() for item in args.object_roots)
            if args.object_roots
            else object_roots()
        )
        if not selected_roots:
            raise SystemExit(
                "no corpus object roots found; expected corpus/build, corpus/expanded_corpus, or corpus/objects"
            )
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
                    daemon,
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
        for summary in summaries:
            for warning in summary.get("warnings") or []:
                print(f"warning: {warning}", file=sys.stderr)
                warning_count += 1

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
        summary_text = (
            "summary: "
            f"mode=offline "
            f"scanned_objects={len(summaries)} "
            f"site_positive_objects={policy_positive_objects} "
            f"site_positive_programs={policy_positive_programs} "
            f"policies={'planned' if args.dry_run else 'written'}={len(planned_outputs)} "
            f"skip_families={','.join(skip_families) or 'none'} "
            f"skip_objects="
            f"{','.join(f'{family}:{skipped_family_objects.get(family, 0)}' for family in POLICY_FAMILY_KEYS if family in skip_families) or 'none'} "
            f"skip_programs="
            f"{','.join(f'{family}:{skipped_family_programs.get(family, 0)}' for family in POLICY_FAMILY_KEYS if family in skip_families) or 'none'} "
            f"stale_removed={{stale_removed}} "
            f"warnings={warning_count}"
        )

    planned_outputs.sort(key=lambda item: display_path(item[0]))

    stale_paths: list[Path] = []
    if not args.dry_run and stale_root.exists():
        planned_set = {path.resolve() for path, _ in planned_outputs}
        stale_paths = []
        for path in sorted(stale_root.rglob("*.policy.yaml")):
            if path.resolve() in planned_set:
                continue
            if not args.live and is_under(path, live_policy_dir(policy_dir)):
                continue
            stale_paths.append(path)
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
        prune_empty_policy_dirs(stale_root)

    print(summary_text.format(stale_removed=(0 if args.dry_run else len(stale_paths))))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
