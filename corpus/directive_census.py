#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import re
import statistics
import struct
import subprocess
import tempfile
from concurrent.futures import ThreadPoolExecutor
from dataclasses import dataclass
from pathlib import Path

try:
    from elftools.elf.elffile import ELFFile
except ImportError as exc:  # pragma: no cover - runtime dependency failure
    raise SystemExit("pyelftools is required: pip install pyelftools") from exc


SHF_EXECINSTR = 0x4
INSN_SIZE = 8
FAMILY_FIELDS = (
    ("CMOV", "cmov"),
    ("WIDE_MEM", "wide"),
    ("ROTATE", "rotate"),
    ("BITFIELD_EXTRACT", "extract"),
    ("LEA", "lea"),
)


@dataclass(frozen=True)
class Insn:
    code: int
    regs: int
    off: int
    imm: int


@dataclass(frozen=True)
class SectionResult:
    name: str
    insn_count: int
    cmov: int
    wide: int
    rotate: int
    extract: int
    lea: int

    @property
    def total(self) -> int:
        return self.cmov + self.wide + self.rotate + self.extract + self.lea


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
    extract: int
    lea: int
    sections: tuple[SectionResult, ...]

    @property
    def total(self) -> int:
        return self.cmov + self.wide + self.rotate + self.extract + self.lea


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
        default=str(repo_root / "docs" / "tmp" / "real-program-directive-census.md"),
        help="Markdown report path.",
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


def parse_raw_insns(data: bytes) -> list[Insn]:
    trailing = len(data) % INSN_SIZE
    if trailing:
        raise ValueError(f"section has {trailing} trailing byte(s), not a multiple of 8")
    insns: list[Insn] = []
    for offset in range(0, len(data), INSN_SIZE):
        code, regs, off, imm = struct.unpack_from("<BBhi", data, offset)
        insns.append(Insn(code=code, regs=regs, off=off, imm=imm))
    return insns


def scan_cmov(insns: list[Insn]) -> int:  # pragma: no cover - compatibility export only
    return 0


def scan_wide_mem(insns: list[Insn]) -> int:  # pragma: no cover - compatibility export only
    return 0


def scan_rotate(insns: list[Insn]) -> int:  # pragma: no cover - compatibility export only
    return 0


def scan_addr_calc(insns: list[Insn]) -> int:  # pragma: no cover - compatibility export only
    return 0


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


def build_scanner_command(scanner: Path, xlated_path: Path) -> list[str]:
    return [str(scanner), "scan", str(xlated_path), "--all", "--v5"]


def parse_scanner_output(stdout: str) -> dict[str, int]:
    patterns = {
        "cmov": re.compile(r"^\s*cmov:\s+(\d+)\s*$"),
        "wide": re.compile(r"^\s*wide:\s+(\d+)\s*$"),
        "rotate": re.compile(r"^\s*rotate:\s+(\d+)\s*$"),
        "lea": re.compile(r"^\s*lea:\s+(\d+)\s*$"),
        "extract": re.compile(r"^\s*extract:\s*(\d+)\s*$"),
    }
    counts = {field: 0 for _, field in FAMILY_FIELDS}
    accepted = False
    for line in stdout.splitlines():
        stripped = line.strip()
        if re.match(r"^Accepted\s+\d+\s+v5 site\(s\)\s*$", stripped):
            accepted = True
        for _, field in FAMILY_FIELDS:
            match = patterns[field].match(stripped)
            if match:
                counts[field] = int(match.group(1))
    if not accepted and any(counts.values()):
        raise RuntimeError(f"scanner output missing acceptance summary:\n{stdout}")
    return counts


def analyze_section(section, scanner: Path) -> SectionResult:
    data = section.data()
    with tempfile.NamedTemporaryFile(prefix="bpf-jit-section-", suffix=".xlated", delete=False) as handle:
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
        extract=counts["extract"],
        lea=counts["lea"],
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
        extract=sum(section.extract for section in section_results),
        lea=sum(section.lea for section in section_results),
        sections=tuple(section_results),
    )


def analyze_many(paths: tuple[Path, ...], source: str, repo_root: Path, scanner: Path, workers: int) -> list[ProgramResult]:
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
        key=lambda item: (
            -item.total,
            -item.cmov,
            -item.wide,
            -item.rotate,
            -item.extract,
            -item.lea,
            item.relpath,
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
                item.extract,
                item.lea,
                item.total,
            ]
        )
    return rows


def render_report(repo_root: Path, inputs: ScanInputs, micro_results: list[ProgramResult], corpus_results: list[ProgramResult], top_n: int, scanner: Path) -> str:
    all_results = sort_results(micro_results + corpus_results)
    corpus_totals = family_totals(corpus_results)
    corpus_coverage = family_object_coverage(corpus_results)
    dominant_family = max(corpus_totals.items(), key=lambda item: (item[1], item[0])) if corpus_totals else None
    widest_family = max(corpus_coverage.items(), key=lambda item: (item[1], item[0])) if corpus_coverage else None
    top_corpus = sort_results(corpus_results)[:3]

    lines: list[str] = [
        "# Real Program Directive Census",
        "",
        f"- Repository root: `{repo_root}`",
        f"- Scanner CLI: `{scanner}`",
        f"- Raw input set on disk: {inputs.raw_micro_count} micro paths + {inputs.raw_corpus_count} corpus paths",
        f"- Corpus source: {inputs.corpus_source}",
        f"- Actual `EM_BPF` objects scanned: {len(micro_results)} micro + {len(corpus_results)} corpus = {len(all_results)} total",
        f"- Skipped non-BPF `.bpf.o` artifacts: {len(inputs.skipped_non_bpf)}",
        "- Method: extract each executable non-dot ELF section, then invoke `bpf-jit-scanner scan <section> --all --v5`.",
        "",
        "## Aggregate Summary",
        "",
    ]
    lines.extend(markdown_table(["Metric", "Value"], dataset_summary_rows(all_results)))
    lines.extend(["", "## Micro Summary", ""])
    lines.extend(markdown_table(["Metric", "Value"], dataset_summary_rows(micro_results)))
    lines.extend(["", "## Corpus Summary", ""])
    lines.extend(markdown_table(["Metric", "Value"], dataset_summary_rows(corpus_results)))
    lines.extend(["", "## Top Objects By Total Sites", ""])
    lines.extend(
        markdown_table(
            ["Object", "Insns", "Secs", "CMOV", "WIDE", "ROTATE", "EXTRACT", "LEA", "Total"],
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
            f"- Highest-density corpus objects: "
            + ", ".join(f"`{item.relpath}` ({item.total})" for item in top_corpus)
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
    output_path = Path(args.output).resolve()
    corpus_build_report = Path(args.corpus_build_report).resolve() if args.corpus_build_report else None
    if not scanner.exists():
        raise SystemExit(f"scanner not found: {scanner}")

    inputs = collect_inputs(repo_root, corpus_build_report)
    micro_results = analyze_many(inputs.micro_paths, "micro", repo_root, scanner, args.workers)
    corpus_results = analyze_many(inputs.corpus_paths, "corpus", repo_root, scanner, args.workers)

    report = render_report(repo_root, inputs, micro_results, corpus_results, args.top_n, scanner)
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(report)

    total_sites = sum(item.total for item in micro_results + corpus_results)
    print(
        f"Wrote {output_path} for {len(micro_results) + len(corpus_results)} objects "
        f"with {total_sites} total candidate sites "
        f"({len(inputs.skipped_non_bpf)} non-BPF artifacts skipped)."
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
