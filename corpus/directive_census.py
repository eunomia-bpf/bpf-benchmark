#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import re
import statistics
import subprocess
import tempfile
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor
from dataclasses import asdict, dataclass
from pathlib import Path
try:
    from common import build_scanner_command
except ImportError:
    from corpus.common import build_scanner_command

try:
    from elftools.elf.elffile import ELFFile
except ImportError as exc:  # pragma: no cover - runtime dependency failure
    raise SystemExit("pyelftools is required: pip install pyelftools") from exc


SHF_EXECINSTR = 0x4
INSN_SIZE = 8
FAMILY_FIELDS = (
    ("COND_SELECT", "cmov"),
    ("WIDE_MEM", "wide"),
    ("ROTATE", "rotate"),
    ("ADDR_CALC", "lea"),
    ("BITFIELD_EXTRACT", "extract"),
    ("ZERO_EXT_ELIDE", "zeroext"),
    ("ENDIAN_FUSION", "endian"),
    ("BRANCH_FLIP", "bflip"),
)
NEW_FAMILY_LABELS = {"ZERO_EXT_ELIDE", "ENDIAN_FUSION", "BRANCH_FLIP"}
SCANNER_PATTERNS = {
    "cmov": re.compile(r"^\s*cmov:\s*(\d+)\s*$"),
    "wide": re.compile(r"^\s*wide:\s*(\d+)\s*$"),
    "rotate": re.compile(r"^\s*rotate:\s*(\d+)\s*$"),
    "lea": re.compile(r"^\s*lea:\s*(\d+)\s*$"),
    "extract": re.compile(r"^\s*extract:\s*(\d+)\s*$"),
    "zeroext": re.compile(r"^\s*zeroext:\s*(\d+)\s*$"),
    "endian": re.compile(r"^\s*endian:\s*(\d+)\s*$"),
    "bflip": re.compile(r"^\s*bflip:\s*(\d+)\s*$"),
}

@dataclass(frozen=True)
class SectionResult:
    name: str
    insn_count: int
    cmov: int
    wide: int
    rotate: int
    lea: int
    extract: int
    zeroext: int
    endian: int
    bflip: int

    @property
    def total(self) -> int:
        return (
            self.cmov
            + self.wide
            + self.rotate
            + self.lea
            + self.extract
            + self.zeroext
            + self.endian
            + self.bflip
        )


@dataclass(frozen=True)
class ProgramResult:
    source: str
    relpath: str
    display_name: str
    insn_count: int
    exec_section_count: int
    cmov: int
    wide: int
    rotate: int
    lea: int
    extract: int
    zeroext: int
    endian: int
    bflip: int
    sections: tuple[SectionResult, ...]

    @property
    def total(self) -> int:
        return (
            self.cmov
            + self.wide
            + self.rotate
            + self.lea
            + self.extract
            + self.zeroext
            + self.endian
            + self.bflip
        )


@dataclass(frozen=True)
class ScanInputs:
    micro_paths: tuple[Path, ...]
    corpus_paths: tuple[Path, ...]
    skipped_non_bpf: tuple[str, ...]
    raw_micro_count: int
    raw_corpus_count: int
    corpus_source: str


def parse_args() -> argparse.Namespace:
    script_dir = Path(__file__).resolve().parent
    repo_root = script_dir.parent
    parser = argparse.ArgumentParser(
        description="Scanner-backed v5 directive census over micro + corpus .bpf.o files."
    )
    parser.add_argument(
        "--repo-root",
        default=str(repo_root),
        help="Repository root. Defaults to the parent of this script.",
    )
    parser.add_argument(
        "--scanner",
        default=str(repo_root / "scanner" / "build" / "bpf-jit-scanner"),
        help="Path to the built scanner CLI.",
    )
    parser.add_argument(
        "--output",
        help="Deprecated alias for --output-md.",
    )
    parser.add_argument(
        "--output-md",
        help="Markdown report path.",
    )
    parser.add_argument(
        "--output-json",
        help="Optional JSON report path.",
    )
    parser.add_argument(
        "--corpus-build-report",
        help=(
            "Optional expanded corpus build JSON report. When omitted, the script "
            "scans `corpus/build/**/*.bpf.o` directly."
        ),
    )
    parser.add_argument(
        "--top-n",
        type=int,
        default=15,
        help="Number of objects to include in the top-coverage tables.",
    )
    parser.add_argument(
        "--workers",
        type=int,
        default=min(8, os.cpu_count() or 1),
        help="Parallel object scans to run at once.",
    )
    return parser.parse_args()


def is_code_section(section) -> bool:
    return bool(section.header["sh_flags"] & SHF_EXECINSTR) and section.data_size > 0


def is_scannable_code_section(section) -> bool:
    name = section.name or ""
    return is_code_section(section) and not name.startswith(".")


def is_bpf_machine(elf: ELFFile) -> bool:
    machine = elf["e_machine"]
    return machine == "EM_BPF" or machine == 247


def filter_bpf_paths(paths: list[Path], repo_root: Path) -> tuple[list[Path], list[str]]:
    kept: list[Path] = []
    skipped: list[str] = []
    for path in paths:
        with path.open("rb") as handle:
            elf = ELFFile(handle)
            if is_bpf_machine(elf):
                kept.append(path)
            else:
                skipped.append(path.relative_to(repo_root).as_posix())
    return kept, skipped


def load_corpus_paths_from_build_report(report_path: Path) -> tuple[list[Path], str]:
    payload = json.loads(report_path.read_text())
    summary = payload.get("summary") or {}
    object_paths = summary.get("compiled_objects") or []
    if not object_paths:
        object_paths = [
            record["object_path"]
            for record in payload.get("records", [])
            if record.get("status") == "ok" and record.get("object_path")
        ]

    seen: set[Path] = set()
    resolved: list[Path] = []
    for raw_path in object_paths:
        path = Path(raw_path).resolve()
        if path in seen or not path.exists():
            continue
        seen.add(path)
        resolved.append(path)
    return sorted(resolved), f"expanded build report `{report_path}`"


def collect_inputs(repo_root: Path, corpus_build_report: Path | None = None) -> ScanInputs:
    raw_micro_paths = sorted((repo_root / "micro" / "programs").glob("*.bpf.o"))
    if corpus_build_report is not None and corpus_build_report.exists():
        raw_corpus_paths, corpus_source = load_corpus_paths_from_build_report(
            corpus_build_report.resolve()
        )
    else:
        corpus_build_root = repo_root / "corpus" / "build"
        if corpus_build_root.exists():
            raw_corpus_paths = sorted(corpus_build_root.rglob("*.bpf.o"))
            corpus_source = "filesystem scan under `corpus/build`"
        else:
            raw_corpus_paths = sorted((repo_root / "corpus").rglob("*.bpf.o"))
            corpus_source = "filesystem scan under `corpus/`"

    micro_paths, skipped_micro = filter_bpf_paths(raw_micro_paths, repo_root)
    corpus_paths, skipped_corpus = filter_bpf_paths(raw_corpus_paths, repo_root)
    return ScanInputs(
        micro_paths=tuple(micro_paths),
        corpus_paths=tuple(corpus_paths),
        skipped_non_bpf=tuple(sorted(skipped_micro + skipped_corpus)),
        raw_micro_count=len(raw_micro_paths),
        raw_corpus_count=len(raw_corpus_paths),
        corpus_source=corpus_source,
    )


def parse_scanner_output(stdout: str) -> dict[str, int]:
    counts = {field: 0 for _, field in FAMILY_FIELDS}
    accepted = False
    for line in stdout.splitlines():
        stripped = line.strip()
        if re.match(r"^Accepted\s+\d+\s+v5 site\(s\)\s*$", stripped):
            accepted = True
        for _, field in FAMILY_FIELDS:
            match = SCANNER_PATTERNS[field].match(stripped)
            if match:
                counts[field] = int(match.group(1))
    if not accepted:
        raise RuntimeError(f"scanner output missing acceptance summary:\n{stdout}")
    return counts


def analyze_section(section, scanner: Path) -> SectionResult:
    data = section.data()
    with tempfile.NamedTemporaryFile(
        prefix="bpf-jit-section-", suffix=".xlated", delete=False
    ) as handle:
        handle.write(data)
        temp_path = Path(handle.name)
    try:
        completed = subprocess.run(
            build_scanner_command(scanner, temp_path),
            capture_output=True,
            text=True,
            check=False,
        )
        if completed.returncode != 0:
            stderr = (completed.stderr or "").strip()
            stdout = (completed.stdout or "").strip()
            detail = stderr or stdout or f"exit={completed.returncode}"
            raise RuntimeError(f"scanner failed on section {section.name}: {detail}")
        counts = parse_scanner_output(completed.stdout or "")
    finally:
        temp_path.unlink(missing_ok=True)

    return SectionResult(
        name=section.name or "<unnamed>",
        insn_count=len(data) // INSN_SIZE,
        cmov=counts["cmov"],
        wide=counts["wide"],
        rotate=counts["rotate"],
        lea=counts["lea"],
        extract=counts["extract"],
        zeroext=counts["zeroext"],
        endian=counts["endian"],
        bflip=counts["bflip"],
    )


def analyze_object(path: Path, source: str, repo_root: Path, scanner: Path) -> ProgramResult:
    with path.open("rb") as handle:
        elf = ELFFile(handle)
        section_results = [
            analyze_section(section, scanner)
            for section in elf.iter_sections()
            if is_scannable_code_section(section)
        ]

    relpath = path.relative_to(repo_root).as_posix()
    return ProgramResult(
        source=source,
        relpath=relpath,
        display_name=path.name,
        insn_count=sum(section.insn_count for section in section_results),
        exec_section_count=len(section_results),
        cmov=sum(section.cmov for section in section_results),
        wide=sum(section.wide for section in section_results),
        rotate=sum(section.rotate for section in section_results),
        lea=sum(section.lea for section in section_results),
        extract=sum(section.extract for section in section_results),
        zeroext=sum(section.zeroext for section in section_results),
        endian=sum(section.endian for section in section_results),
        bflip=sum(section.bflip for section in section_results),
        sections=tuple(section_results),
    )


def analyze_many(
    paths: tuple[Path, ...], source: str, repo_root: Path, scanner: Path, workers: int
) -> list[ProgramResult]:
    if not paths:
        return []
    with ThreadPoolExecutor(max_workers=max(1, workers)) as executor:
        futures = [
            executor.submit(analyze_object, path, source, repo_root, scanner)
            for path in paths
        ]
        return [future.result() for future in futures]


def sort_results(results: list[ProgramResult]) -> list[ProgramResult]:
    return sorted(
        results,
        key=lambda item: tuple(
            [-item.total]
            + [-getattr(item, field) for _, field in FAMILY_FIELDS]
            + [item.relpath]
        ),
    )


def family_totals(results: list[ProgramResult]) -> dict[str, int]:
    return {label: sum(getattr(item, field) for item in results) for label, field in FAMILY_FIELDS}


def family_object_coverage(results: list[ProgramResult]) -> dict[str, int]:
    return {label: sum(1 for item in results if getattr(item, field) > 0) for label, field in FAMILY_FIELDS}


def objects_with_sites(results: list[ProgramResult]) -> int:
    return sum(1 for item in results if item.total > 0)


def mean_sites(results: list[ProgramResult]) -> float:
    if not results:
        return 0.0
    return statistics.mean(item.total for item in results)


def markdown_table(headers: list[str], rows: list[list[object]]) -> list[str]:
    lines = [
        "| " + " | ".join(headers) + " |",
        "| " + " | ".join("---" for _ in headers) + " |",
    ]
    for row in rows:
        lines.append("| " + " | ".join(str(cell) for cell in row) + " |")
    return lines


def dataset_summary_rows(results: list[ProgramResult]) -> list[list[object]]:
    totals = family_totals(results)
    coverage = family_object_coverage(results)
    rows = [
        ["Objects", len(results)],
        ["Objects with >=1 site", objects_with_sites(results)],
        ["Coverage", f"{(objects_with_sites(results) / len(results) * 100):.1f}%" if results else "0.0%"],
        ["Executable sections", sum(item.exec_section_count for item in results)],
        ["BPF instructions", sum(item.insn_count for item in results)],
        ["Total sites", sum(item.total for item in results)],
        ["Average sites per object", f"{mean_sites(results):.2f}"],
    ]
    for label, _ in FAMILY_FIELDS:
        rows.append([f"{label} sites / objects", f"{totals[label]} / {coverage[label]}"])
    return rows


def dataset_summary_dict(results: list[ProgramResult]) -> dict[str, object]:
    totals = family_totals(results)
    coverage = family_object_coverage(results)
    return {
        "objects": len(results),
        "objects_with_sites": objects_with_sites(results),
        "coverage_percent": round((objects_with_sites(results) / len(results) * 100), 1) if results else 0.0,
        "executable_sections": sum(item.exec_section_count for item in results),
        "bpf_instructions": sum(item.insn_count for item in results),
        "total_sites": sum(item.total for item in results),
        "average_sites_per_object": round(mean_sites(results), 2),
        "families": {
            label: {"sites": totals[label], "objects": coverage[label]}
            for label, _ in FAMILY_FIELDS
        },
    }


def family_summary_rows(
    all_results: list[ProgramResult],
    micro_results: list[ProgramResult],
    corpus_results: list[ProgramResult],
) -> list[list[object]]:
    all_totals = family_totals(all_results)
    all_coverage = family_object_coverage(all_results)
    micro_totals = family_totals(micro_results)
    micro_coverage = family_object_coverage(micro_results)
    corpus_totals = family_totals(corpus_results)
    corpus_coverage = family_object_coverage(corpus_results)
    rows: list[list[object]] = []
    for label, _ in FAMILY_FIELDS:
        rows.append(
            [
                label,
                all_totals[label],
                all_coverage[label],
                micro_totals[label],
                micro_coverage[label],
                corpus_totals[label],
                corpus_coverage[label],
            ]
        )
    return rows


def project_name(result: ProgramResult) -> str:
    parts = Path(result.relpath).parts
    if len(parts) >= 2 and parts[0] == "micro":
        return "micro"
    if len(parts) >= 3 and parts[0] == "corpus" and parts[1] == "build":
        return parts[2]
    if parts:
        return parts[0]
    return result.source


def project_summary_rows(results: list[ProgramResult]) -> list[list[object]]:
    grouped: dict[str, list[ProgramResult]] = defaultdict(list)
    for result in results:
        grouped[project_name(result)].append(result)

    rows: list[list[object]] = []
    for project, items in grouped.items():
        totals = family_totals(items)
        rows.append(
            [
                project,
                len(items),
                objects_with_sites(items),
                sum(item.total for item in items),
                totals["COND_SELECT"],
                totals["WIDE_MEM"],
                totals["ROTATE"],
                totals["ADDR_CALC"],
                totals["BITFIELD_EXTRACT"],
                totals["ZERO_EXT_ELIDE"],
                totals["ENDIAN_FUSION"],
                totals["BRANCH_FLIP"],
            ]
        )
    return sorted(rows, key=lambda row: (-int(row[3]), str(row[0])))


def top_rows(results: list[ProgramResult], top_n: int) -> list[list[object]]:
    rows: list[list[object]] = []
    for item in sort_results(results)[:top_n]:
        rows.append(
            [
                item.relpath,
                item.insn_count,
                item.exec_section_count,
                item.cmov,
                item.wide,
                item.rotate,
                item.lea,
                item.extract,
                item.zeroext,
                item.endian,
                item.bflip,
                item.total,
            ]
        )
    return rows


def serialize_program(result: ProgramResult) -> dict[str, object]:
    payload = asdict(result)
    payload["total"] = result.total
    return payload


def build_json_payload(
    repo_root: Path,
    inputs: ScanInputs,
    micro_results: list[ProgramResult],
    corpus_results: list[ProgramResult],
    top_n: int,
    scanner: Path,
) -> dict[str, object]:
    all_results = sort_results(micro_results + corpus_results)
    return {
        "metadata": {
            "repo_root": str(repo_root),
            "scanner": str(scanner),
            "raw_micro_count": inputs.raw_micro_count,
            "raw_corpus_count": inputs.raw_corpus_count,
            "corpus_source": inputs.corpus_source,
            "micro_objects": len(micro_results),
            "corpus_objects": len(corpus_results),
            "total_objects": len(all_results),
            "skipped_non_bpf_count": len(inputs.skipped_non_bpf),
            "skipped_non_bpf": list(inputs.skipped_non_bpf),
            "method": "extract executable non-dot ELF sections, then run bpf-jit-scanner scan --xlated <section> --all --v5",
        },
        "aggregate_summary": dataset_summary_dict(all_results),
        "micro_summary": dataset_summary_dict(micro_results),
        "corpus_summary": dataset_summary_dict(corpus_results),
        "family_summary": [
            {
                "family": label,
                "all_sites": family_totals(all_results)[label],
                "all_objects": family_object_coverage(all_results)[label],
                "micro_sites": family_totals(micro_results)[label],
                "micro_objects": family_object_coverage(micro_results)[label],
                "corpus_sites": family_totals(corpus_results)[label],
                "corpus_objects": family_object_coverage(corpus_results)[label],
            }
            for label, _ in FAMILY_FIELDS
        ],
        "project_summary": [
            {
                "project": row[0],
                "objects": row[1],
                "objects_with_sites": row[2],
                "total_sites": row[3],
                "families": {
                    "COND_SELECT": row[4],
                    "WIDE_MEM": row[5],
                    "ROTATE": row[6],
                    "ADDR_CALC": row[7],
                    "BITFIELD_EXTRACT": row[8],
                    "ZERO_EXT_ELIDE": row[9],
                    "ENDIAN_FUSION": row[10],
                    "BRANCH_FLIP": row[11],
                },
            }
            for row in project_summary_rows(all_results)
        ],
        "top_objects": [
            {
                "object": row[0],
                "insns": row[1],
                "sections": row[2],
                "cmov": row[3],
                "wide": row[4],
                "rotate": row[5],
                "lea": row[6],
                "extract": row[7],
                "zeroext": row[8],
                "endian": row[9],
                "bflip": row[10],
                "total": row[11],
            }
            for row in top_rows(corpus_results, top_n)
        ],
        "objects": [serialize_program(result) for result in all_results],
    }


def render_report(
    repo_root: Path,
    inputs: ScanInputs,
    micro_results: list[ProgramResult],
    corpus_results: list[ProgramResult],
    top_n: int,
    scanner: Path,
) -> str:
    all_results = sort_results(micro_results + corpus_results)
    corpus_totals = family_totals(corpus_results)
    corpus_coverage = family_object_coverage(corpus_results)
    dominant_family = (
        max(corpus_totals.items(), key=lambda item: (item[1], item[0])) if corpus_totals else None
    )
    widest_family = (
        max(corpus_coverage.items(), key=lambda item: (item[1], item[0])) if corpus_coverage else None
    )
    top_corpus = sort_results(corpus_results)[:3]
    project_rows = project_summary_rows(all_results)

    lines: list[str] = [
        "# Scanner-backed 8-Family Directive Census",
        "",
        f"- Repository root: `{repo_root}`",
        f"- Scanner CLI: `{scanner}`",
        f"- Raw input set on disk: {inputs.raw_micro_count} micro paths + {inputs.raw_corpus_count} corpus paths",
        f"- Corpus source: {inputs.corpus_source}",
        f"- Actual `EM_BPF` objects scanned: {len(micro_results)} micro + {len(corpus_results)} corpus = {len(all_results)} total",
        f"- Skipped non-BPF `.bpf.o` artifacts: {len(inputs.skipped_non_bpf)}",
        "- Method: extract each executable non-dot ELF section, then invoke `bpf-jit-scanner scan --xlated <section> --all --v5`.",
        "",
        "## Aggregate Summary",
        "",
    ]
    lines.extend(markdown_table(["Metric", "Value"], dataset_summary_rows(all_results)))
    lines.extend(["", "## Micro Summary", ""])
    lines.extend(markdown_table(["Metric", "Value"], dataset_summary_rows(micro_results)))
    lines.extend(["", "## Corpus Summary", ""])
    lines.extend(markdown_table(["Metric", "Value"], dataset_summary_rows(corpus_results)))
    lines.extend(["", "## Family Summary", ""])
    lines.extend(
        markdown_table(
            ["Family", "All Sites", "All Objects", "Micro Sites", "Micro Objects", "Corpus Sites", "Corpus Objects"],
            family_summary_rows(all_results, micro_results, corpus_results),
        )
    )
    lines.extend(["", "## Project Summary", ""])
    lines.extend(
        markdown_table(
            [
                "Project",
                "Objects",
                "With Sites",
                "Total",
                "CMOV",
                "WIDE",
                "ROTATE",
                "LEA",
                "EXTRACT",
                "ZEROEXT",
                "ENDIAN",
                "BFLIP",
            ],
            project_rows,
        )
    )
    lines.extend(["", f"## Top {top_n} Corpus Objects By Total Sites", ""])
    lines.extend(
        markdown_table(
            [
                "Object",
                "Insns",
                "Secs",
                "CMOV",
                "WIDE",
                "ROTATE",
                "LEA",
                "EXTRACT",
                "ZEROEXT",
                "ENDIAN",
                "BFLIP",
                "Total",
            ],
            top_rows(corpus_results, top_n),
        )
    )

    lines.extend(["", "## Analysis", ""])
    lines.append(
        f"- Corpus coverage is `{objects_with_sites(corpus_results)}/{len(corpus_results)}` objects with sites, or `{(objects_with_sites(corpus_results) / len(corpus_results) * 100):.1f}%`."
        if corpus_results
        else "- Corpus coverage is `0/0` objects with sites."
    )
    if dominant_family is not None:
        lines.append(
            f"- By raw site count, `{dominant_family[0]}` is the largest family in the corpus ({dominant_family[1]} sites)."
        )
    if widest_family is not None:
        lines.append(
            f"- By object coverage, `{widest_family[0]}` appears in the widest set of corpus objects ({widest_family[1]} objects)."
        )
    if top_corpus:
        lines.append(
            "- Highest-density corpus objects: "
            + ", ".join(f"`{item.relpath}` ({item.total})" for item in top_corpus)
            + "."
        )
    new_family_bits = [
        f"`{label}` = {corpus_totals[label]} sites across {corpus_coverage[label]} corpus objects"
        for label, _ in FAMILY_FIELDS
        if label in NEW_FAMILY_LABELS
    ]
    if new_family_bits:
        lines.append("- New-family corpus totals: " + "; ".join(new_family_bits) + ".")
    if project_rows:
        lines.append(
            "- Top projects by total sites: "
            + ", ".join(f"`{row[0]}` ({row[3]})" for row in project_rows[:5])
            + "."
        )
    lines.append(
        "- These are raw scanner-backed candidate counts over ELF program sections, not live xlated acceptance counts."
    )
    return "\n".join(lines) + "\n"


def main() -> int:
    args = parse_args()
    repo_root = Path(args.repo_root).resolve()
    scanner = Path(args.scanner).resolve()
    default_output_md = repo_root / "docs" / "tmp" / "real-program-directive-census.md"
    output_md = Path(args.output_md or args.output or default_output_md).resolve()
    output_json = Path(args.output_json).resolve() if args.output_json else None
    corpus_build_report = Path(args.corpus_build_report).resolve() if args.corpus_build_report else None
    if not scanner.exists():
        raise SystemExit(f"scanner not found: {scanner}")

    inputs = collect_inputs(repo_root, corpus_build_report)
    micro_results = analyze_many(inputs.micro_paths, "micro", repo_root, scanner, args.workers)
    corpus_results = analyze_many(inputs.corpus_paths, "corpus", repo_root, scanner, args.workers)

    report = render_report(repo_root, inputs, micro_results, corpus_results, args.top_n, scanner)
    output_md.parent.mkdir(parents=True, exist_ok=True)
    output_md.write_text(report)

    if output_json is not None:
        payload = build_json_payload(
            repo_root, inputs, micro_results, corpus_results, args.top_n, scanner
        )
        output_json.parent.mkdir(parents=True, exist_ok=True)
        output_json.write_text(json.dumps(payload, indent=2) + "\n")

    total_sites = sum(item.total for item in micro_results + corpus_results)
    outputs = [str(output_md)]
    if output_json is not None:
        outputs.append(str(output_json))
    print(
        f"Wrote {', '.join(outputs)} for {len(micro_results) + len(corpus_results)} objects "
        f"with {total_sites} total candidate sites "
        f"({len(inputs.skipped_non_bpf)} non-BPF artifacts skipped)."
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
