#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import os
import subprocess
import sys
import tempfile
from collections import Counter, defaultdict
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path
from typing import Any

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

from policy_utils import POLICY_DIR, ROOT_DIR, object_relative_path, object_roots, policy_path_for_object

try:
    from elftools.elf.elffile import ELFFile
except ImportError as exc:  # pragma: no cover - runtime dependency failure
    raise SystemExit("pyelftools is required: pip install pyelftools") from exc


DEFAULT_SCANNER = ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"
DEFAULT_RESULTS_MD = ROOT_DIR / "docs" / "tmp" / "corpus-full-recompile-v6.md"
DEFAULT_RESULTS_JSON = ROOT_DIR / "corpus" / "results" / "corpus_v5_vm_batch_full.json"
DEFAULT_TIMEOUT_SECONDS = 180
DEFAULT_WORKERS = max(1, min(8, os.cpu_count() or 1))
SHF_EXECINSTR = 0x4
POLICY_FAMILY_KEYS = ("cmov", "wide_mem", "rotate", "extract", "lea", "zeroext", "endian", "bflip")
SCANNER_SUMMARY_FIELDS = (
    ("cmov", "cmov_sites"),
    ("wide_mem", "wide_sites"),
    ("rotate", "rotate_sites"),
    ("extract", "extract_sites"),
    ("lea", "lea_sites"),
    ("zeroext", "zero_ext_sites"),
    ("endian", "endian_sites"),
    ("bflip", "branch_flip_sites"),
)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Generate default per-object corpus policy YAMLs from scanner --json "
            "site census, with CMOV disabled for known v6 corpus regressors."
        )
    )
    parser.add_argument(
        "--scanner",
        default=str(DEFAULT_SCANNER),
        help="Path to bpf-jit-scanner.",
    )
    parser.add_argument(
        "--policy-dir",
        default=str(POLICY_DIR),
        help="Output directory for generated policy files.",
    )
    parser.add_argument(
        "--results-md",
        default=str(DEFAULT_RESULTS_MD),
        help="Authoritative v6 markdown report used to discover the matching JSON artifact.",
    )
    parser.add_argument(
        "--results-json",
        default=str(DEFAULT_RESULTS_JSON),
        help="Fallback v6 VM batch JSON when the markdown report does not name one.",
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
        help="Concurrent workers used for per-object scanner subprocesses.",
    )
    parser.add_argument(
        "--timeout",
        type=int,
        default=DEFAULT_TIMEOUT_SECONDS,
        help="Per-subprocess timeout in seconds.",
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Scan and print the planned policy outputs without writing files.",
    )
    return parser.parse_args(argv)


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


def scan_xlated_section(scanner: Path, xlated_path: Path, *, timeout_seconds: int) -> dict[str, Any]:
    payload = run_json_command(
        [
            str(scanner),
            "scan",
            "--xlated",
            str(xlated_path),
            "--all",
            "--json",
            "--v5",
        ],
        timeout_seconds=timeout_seconds,
        label=f"scanner:{xlated_path}",
    )
    if not isinstance(payload, dict):
        raise RuntimeError(f"scanner output for {xlated_path} was not a JSON object")
    return payload


def load_results_json_path(results_md: Path, fallback_json: Path) -> Path:
    if results_md.exists():
        for line in results_md.read_text().splitlines():
            prefix = "- VM batch JSON: `"
            if line.startswith(prefix) and line.endswith("`"):
                candidate = Path(line[len(prefix):-1])
                return candidate if candidate.is_absolute() else (ROOT_DIR / candidate).resolve()
    return fallback_json.resolve()


def load_cmov_regressors(results_json: Path) -> dict[Path, dict[str, Any]]:
    payload = json.loads(results_json.read_text())
    records = payload.get("programs") or payload.get("records") or []
    object_ratios: dict[Path, list[float]] = defaultdict(list)
    object_regressions: Counter[Path] = Counter()
    object_wins: Counter[Path] = Counter()
    for record in records:
        if not isinstance(record, dict):
            continue
        if not record.get("v5_run_applied"):
            continue
        applied = set(record.get("applied_families_run") or [])
        if "cmov" not in applied:
            continue
        ratio = record.get("speedup_ratio")
        if not isinstance(ratio, (int, float)) or ratio <= 0:
            continue
        object_path = (ROOT_DIR / str(record.get("object_path", ""))).resolve()
        object_ratios[object_path].append(float(ratio))
        if ratio < 1.0:
            object_regressions[object_path] += 1
        elif ratio > 1.0:
            object_wins[object_path] += 1

    regressors: dict[Path, dict[str, Any]] = {}
    for object_path, ratios in object_ratios.items():
        geomean = math.exp(sum(math.log(value) for value in ratios) / len(ratios))
        if geomean < 1.0:
            regressors[object_path] = {
                "geomean": geomean,
                "samples": len(ratios),
                "regressions": object_regressions[object_path],
                "wins": object_wins[object_path],
            }
    return regressors


def is_scannable_code_section(section: Any) -> bool:
    name = section.name or ""
    flags = int(section.header["sh_flags"])
    return bool(flags & SHF_EXECINSTR) and section.data_size > 0 and not name.startswith(".")


def object_scan_summary(
    scanner: Path,
    object_path: Path,
    *,
    timeout_seconds: int,
) -> dict[str, Any]:
    manifests: list[dict[str, Any]] = []
    family_totals = Counter()
    scannable_sections = 0
    site_positive_sections = 0
    total_sites = 0

    with object_path.open("rb") as handle:
        elf = ELFFile(handle)
        for section in elf.iter_sections():
            if not is_scannable_code_section(section):
                continue
            scannable_sections += 1
            with tempfile.NamedTemporaryFile(
                prefix="corpus-policy-section-",
                suffix=".xlated",
                dir=ROOT_DIR,
                delete=False,
            ) as tmp:
                tmp.write(section.data())
                tmp_path = Path(tmp.name)
            try:
                manifest = scan_xlated_section(scanner, tmp_path, timeout_seconds=timeout_seconds)
            finally:
                tmp_path.unlink(missing_ok=True)
            manifests.append(manifest)
            summary = manifest.get("summary") or {}
            section_total_sites = int(summary.get("total_sites", 0) or 0)
            if section_total_sites > 0:
                site_positive_sections += 1
                total_sites += section_total_sites
            for family_key, field in SCANNER_SUMMARY_FIELDS:
                family_totals[family_key] += int(summary.get(field, 0) or 0)

    return {
        "object_path": object_path,
        "relative_path": object_relative_path(object_path),
        "program_count": scannable_sections,
        "site_positive_programs": site_positive_sections,
        "total_sites": total_sites,
        "family_totals": dict(family_totals),
        "manifests": manifests,
    }


def render_policy_text(
    summary: dict[str, Any],
    *,
    cmov_skip: bool,
    cmov_evidence: dict[str, Any] | None,
    results_json: Path,
) -> str:
    lines = [
        "# Auto-generated by corpus/generate_default_policies.py.",
        f"# Object: {summary['relative_path'].as_posix()}",
        f"# Site-positive executable sections: {summary['site_positive_programs']} / {summary['program_count']}",
        f"# Total scanner sites: {summary['total_sites']}",
    ]
    if cmov_evidence is not None:
        lines.append(
            "# CMOV evidence: "
            f"{results_json.relative_to(ROOT_DIR).as_posix()} object geomean={cmov_evidence['geomean']:.3f}x "
            f"across {cmov_evidence['samples']} measured CMOV-applied program(s) "
            f"(regressions={cmov_evidence['regressions']}, wins={cmov_evidence['wins']})"
        )
    lines.append("families:")
    for key in POLICY_FAMILY_KEYS:
        value = "skip" if key == "cmov" and cmov_skip else "apply"
        lines.append(f"  {key}: {value}")
    lines.append("")
    return "\n".join(lines)


def write_policy_file(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)

    scanner = Path(args.scanner).resolve()
    policy_dir = Path(args.policy_dir).resolve()
    results_md = Path(args.results_md).resolve()
    fallback_results_json = Path(args.results_json).resolve()
    selected_roots = (
        tuple(Path(item).resolve() for item in args.object_roots)
        if args.object_roots
        else object_roots()
    )

    if not selected_roots:
        raise SystemExit("no corpus object roots found; expected corpus/build, corpus/expanded_corpus, or corpus/objects")

    if not scanner.exists():
        if args.dry_run:
            print(f"dry-run: scanner not found, no files written: {scanner}")
            return 0
        raise SystemExit(f"scanner not found: {scanner}")

    results_json = load_results_json_path(results_md, fallback_results_json)
    if not results_json.exists():
        raise SystemExit(f"results JSON not found: {results_json}")
    cmov_regressors = load_cmov_regressors(results_json)

    object_paths = discover_object_paths(
        selected_roots,
        filters=args.filters,
        max_objects=args.max_objects,
    )
    if not object_paths:
        raise SystemExit("no corpus objects matched the selected roots/filters")

    summaries: list[dict[str, Any]] = []
    failures: list[str] = []
    with ThreadPoolExecutor(max_workers=max(1, args.workers)) as executor:
        future_to_path = {
            executor.submit(
                object_scan_summary,
                scanner,
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
                failures.append(f"{object_path}: {exc}")

    summaries.sort(key=lambda item: item["relative_path"].as_posix())
    if failures:
        detail = "\n".join(failures[:20])
        raise SystemExit(f"failed to scan {len(failures)} object(s):\n{detail}")

    written = 0
    cmov_skipped = 0
    site_positive = [summary for summary in summaries if summary["total_sites"] > 0]
    for summary in site_positive:
        object_path = Path(summary["object_path"]).resolve()
        policy_path = policy_path_for_object(object_path, policy_dir)
        cmov_evidence = cmov_regressors.get(object_path)
        cmov_skip = cmov_evidence is not None
        if cmov_skip:
            cmov_skipped += 1
        text = render_policy_text(
            summary,
            cmov_skip=cmov_skip,
            cmov_evidence=cmov_evidence,
            results_json=results_json,
        )
        if args.dry_run:
            action = "would write"
        else:
            write_policy_file(policy_path, text)
            action = "wrote"
        written += 1
        print(f"{action} {policy_path.relative_to(ROOT_DIR).as_posix()}")

    print(
        "summary: "
        f"scanned_objects={len(summaries)} "
        f"site_positive_objects={len(site_positive)} "
        f"policies={'planned' if args.dry_run else 'written'}={written} "
        f"cmov_skips={cmov_skipped} "
        f"results_json={results_json.relative_to(ROOT_DIR).as_posix()}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
