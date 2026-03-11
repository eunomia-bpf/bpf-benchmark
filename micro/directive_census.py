#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import statistics
import struct
import sys
from collections import Counter
from dataclasses import dataclass
from pathlib import Path

try:
    from elftools.elf.elffile import ELFFile
except ImportError as exc:  # pragma: no cover - dependency failure is runtime-only
    raise SystemExit("pyelftools is required: pip install pyelftools") from exc


SHF_EXECINSTR = 0x4
INSN_SIZE = 8

BPF_JIT_RK_COND_SELECT = 1
BPF_JIT_RK_WIDE_MEM = 2
BPF_JIT_RK_ROTATE = 3
BPF_JIT_RK_ADDR_CALC = 4

BPF_ALU = 0x04
BPF_JMP = 0x05
BPF_JMP32 = 0x06
BPF_ALU64 = 0x07

REQUIRED_WORKLOADS = {
    "Mechanism isolation": (
        "load_byte_recompose",
        "binary_search",
        "switch_dispatch",
        "branch_layout",
    ),
    "Policy sensitivity": (
        "packet_rss_hash",
        "local_call_fanout",
        "branch_fanout_32",
        "mega_basic_block_2048",
    ),
}


@dataclass(frozen=True)
class Insn:
    code: int
    regs: int
    off: int
    imm: int

    @property
    def dst_reg(self) -> int:
        return self.regs & 0x0F

    @property
    def src_reg(self) -> int:
        return (self.regs >> 4) & 0x0F


@dataclass(frozen=True)
class SectionResult:
    name: str
    insn_count: int
    rotate: int
    wide: int
    lea: int
    cmov: int

    @property
    def total(self) -> int:
        return self.rotate + self.wide + self.lea + self.cmov


@dataclass(frozen=True)
class ProgramResult:
    source: str
    relpath: str
    display_name: str
    insn_count: int
    exec_section_count: int
    rotate: int
    wide: int
    lea: int
    cmov: int
    sections: tuple[SectionResult, ...]

    @property
    def total(self) -> int:
        return self.rotate + self.wide + self.lea + self.cmov


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
        description="Scan micro + corpus .bpf.o files for directive candidate sites."
    )
    parser.add_argument(
        "--repo-root",
        default=str(repo_root),
        help="Repository root. Defaults to the parent of this script.",
    )
    parser.add_argument(
        "--output",
        default=str(repo_root / "docs" / "tmp" / "real-program-directive-census.md"),
        help="Markdown report path.",
    )
    parser.add_argument(
        "--corpus-build-report",
        help=(
            "Optional expanded corpus build JSON report. When omitted, "
            "corpus/results/expanded_corpus_build.json is used if present."
        ),
    )
    parser.add_argument(
        "--top-n",
        type=int,
        default=10,
        help="Number of programs to include in top-program tables.",
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


def is_code_section(section) -> bool:
    return bool(section.header["sh_flags"] & SHF_EXECINSTR) and section.data_size > 0


def is_bpf_machine(elf: ELFFile) -> bool:
    machine = elf["e_machine"]
    return machine == "EM_BPF" or machine == 247


def is_cond_jump_raw(insn: Insn) -> bool:
    cls = insn.code & 0x07
    if cls != BPF_JMP and cls != BPF_JMP32:
        return False
    op = insn.code & 0xF0
    return op in {0x10, 0x20, 0x30, 0x50, 0x60, 0x70, 0xA0, 0xB0, 0xC0, 0xD0}


def is_simple_mov_raw(insn: Insn) -> bool:
    cls = insn.code & 0x07
    if cls != BPF_ALU and cls != BPF_ALU64:
        return False
    if (insn.code & 0xF0) != 0xB0:
        return False
    if insn.off != 0:
        return False
    src = insn.code & 0x08
    if src == 0x08:
        return insn.imm == 0
    return insn.src_reg == 0


def scan_cmov(insns: list[Insn]) -> int:
    if len(insns) < 3:
        return 0

    count = 0
    idx = 0
    insn_cnt = len(insns)

    while idx < insn_cnt:
        if (
            idx + 3 < insn_cnt
            and is_cond_jump_raw(insns[idx])
            and insns[idx].off == 2
            and is_simple_mov_raw(insns[idx + 1])
            and is_simple_mov_raw(insns[idx + 3])
            and insns[idx + 2].code == 0x05
            and insns[idx + 2].off == 1
            and insns[idx + 1].dst_reg == insns[idx + 3].dst_reg
        ):
            count += 1
            idx += 4
            continue

        if (
            idx > 0
            and idx + 1 < insn_cnt
            and is_simple_mov_raw(insns[idx - 1])
            and is_cond_jump_raw(insns[idx])
            and insns[idx].off == 1
            and is_simple_mov_raw(insns[idx + 1])
            and insns[idx - 1].dst_reg == insns[idx + 1].dst_reg
        ):
            count += 1
            idx += 2
            continue

        idx += 1

    return count


def scan_wide_mem(insns: list[Insn]) -> int:
    if len(insns) < 4:
        return 0

    ldxb_code = 0x71
    lsh64_code = 0x67
    or64_code = 0x4F

    count = 0
    idx = 0
    insn_cnt = len(insns)

    while idx < insn_cnt:
        if insns[idx].code != ldxb_code:
            idx += 1
            continue

        base_reg = insns[idx].src_reg
        base_off = insns[idx].off
        dst_reg = insns[idx].dst_reg

        if idx + 3 < insn_cnt:
            shift_insn = insns[idx + 1]
            lo_load = insns[idx + 2]
            or_insn = insns[idx + 3]
            if (
                shift_insn.code == lsh64_code
                and shift_insn.imm == 8
                and shift_insn.dst_reg == dst_reg
                and lo_load.code == ldxb_code
                and lo_load.src_reg == base_reg
                and lo_load.off == base_off - 1
                and or_insn.code == or64_code
                and or_insn.dst_reg == dst_reg
                and or_insn.src_reg == lo_load.dst_reg
            ):
                count += 1
                idx += 4
                continue

        n_extra = 0
        while idx + 1 + n_extra * 3 + 2 < insn_cnt:
            group_start = idx + 1 + n_extra * 3
            load_insn = insns[group_start]
            shift_insn = insns[group_start + 1]
            or_insn = insns[group_start + 2]

            if load_insn.code != ldxb_code:
                break
            if load_insn.src_reg != base_reg:
                break
            if load_insn.off != base_off + (n_extra + 1):
                break
            if shift_insn.code != lsh64_code:
                break
            if shift_insn.dst_reg != load_insn.dst_reg:
                break
            if shift_insn.imm != (n_extra + 1) * 8:
                break
            if or_insn.code != or64_code:
                break
            if or_insn.dst_reg != dst_reg:
                break
            if or_insn.src_reg != load_insn.dst_reg:
                break

            n_extra += 1
            if n_extra == 7:
                break

        if n_extra == 0:
            idx += 1
            continue

        total_bytes = n_extra + 1
        if total_bytes in {2, 4, 8}:
            site_len = 1 + n_extra * 3
            count += 1
            idx += site_len
        else:
            idx += 1

    return count


def scan_rotate(insns: list[Insn]) -> int:
    if len(insns) < 4:
        return 0

    mov64_x = 0xBF
    mov32_x = 0xBC
    lsh64_k = 0x67
    lsh32_k = 0x64
    rsh64_k = 0x77
    rsh32_k = 0x74
    or64_x = 0x4F
    or32_x = 0x4C
    and64_k = 0x57
    and64_x = 0x5F

    count = 0
    idx = 0
    insn_cnt = len(insns)

    while idx < insn_cnt:
        matched = False

        if idx + 5 < insn_cnt:
            mov1 = insns[idx]
            and_i = insns[idx + 1]
            rsh = insns[idx + 2]
            mov2 = insns[idx + 3]
            lsh = insns[idx + 4]
            ior = insns[idx + 5]

            and_ok = (and_i.code == and64_k and and_i.imm != 0) or and_i.code == and64_x
            if (
                mov1.code == mov64_x
                and mov1.off == 0
                and mov1.imm == 0
                and and_ok
                and rsh.code == rsh64_k
                and mov2.code == mov64_x
                and mov2.off == 0
                and mov2.imm == 0
                and lsh.code == lsh64_k
                and ior.code == or64_x
            ):
                tmp_reg = mov1.dst_reg
                src_reg1 = mov1.src_reg
                src_reg2 = mov2.src_reg
                dst_reg = mov2.dst_reg
                rot_amount = lsh.imm
                rsh_amount = rsh.imm
                if (
                    src_reg1 == src_reg2
                    and and_i.dst_reg == tmp_reg
                    and rsh.dst_reg == tmp_reg
                    and lsh.dst_reg == dst_reg
                    and ior.dst_reg == dst_reg
                    and ior.src_reg == tmp_reg
                    and 0 < rot_amount < 32
                    and 0 < rsh_amount < 32
                    and rot_amount + rsh_amount == 32
                ):
                    count += 1
                    idx += 6
                    matched = True

        if matched:
            continue

        if idx + 4 < insn_cnt:
            mov_i = insns[idx]
            and_i = insns[idx + 1]
            insn2 = insns[idx + 2]
            insn3 = insns[idx + 3]
            ior = insns[idx + 4]

            and_ok = and_i.code == and64_k or and_i.code == and64_x
            if (
                mov_i.code == mov64_x
                and mov_i.off == 0
                and mov_i.imm == 0
                and and_ok
                and ior.code == or64_x
            ):
                tmp_reg = mov_i.dst_reg
                src_reg = mov_i.src_reg
                lsh_p = None
                rsh_p = None
                if insn2.code == rsh64_k and insn3.code == lsh64_k:
                    rsh_p = insn2
                    lsh_p = insn3
                elif insn2.code == lsh64_k and insn3.code == rsh64_k:
                    lsh_p = insn2
                    rsh_p = insn3

                if (
                    lsh_p is not None
                    and rsh_p is not None
                    and and_i.dst_reg == tmp_reg
                    and rsh_p.dst_reg == tmp_reg
                    and lsh_p.dst_reg == src_reg
                    and ior.dst_reg == src_reg
                    and ior.src_reg == tmp_reg
                ):
                    rot_amount = lsh_p.imm
                    rsh_amount = rsh_p.imm
                    if (
                        0 < rot_amount < 32
                        and 0 < rsh_amount < 32
                        and rot_amount + rsh_amount == 32
                    ):
                        count += 1
                        idx += 5
                        matched = True

        if matched:
            continue

        if idx + 4 < insn_cnt:
            mov1 = insns[idx]
            rsh = insns[idx + 1]
            mov2 = insns[idx + 2]
            lsh = insns[idx + 3]
            ior = insns[idx + 4]

            if (
                mov1.code == mov64_x
                and mov1.off == 0
                and mov1.imm == 0
                and rsh.code == rsh64_k
                and mov2.code == mov64_x
                and mov2.off == 0
                and mov2.imm == 0
                and lsh.code == lsh64_k
                and ior.code == or64_x
            ):
                tmp_reg = mov1.dst_reg
                src_reg1 = mov1.src_reg
                src_reg2 = mov2.src_reg
                dst_reg = mov2.dst_reg
                rot_amount = lsh.imm
                rsh_amount = rsh.imm
                if (
                    src_reg1 == src_reg2
                    and rsh.dst_reg == tmp_reg
                    and lsh.dst_reg == dst_reg
                    and ior.dst_reg == dst_reg
                    and ior.src_reg == tmp_reg
                    and 0 < rot_amount < 64
                    and 0 < rsh_amount < 64
                    and rot_amount + rsh_amount == 64
                ):
                    count += 1
                    idx += 5
                    matched = True

        if matched:
            continue

        if idx + 3 < insn_cnt:
            mov = insns[idx]
            rsh = insns[idx + 1]
            lsh = insns[idx + 2]
            ior = insns[idx + 3]

            if (
                mov.code == mov64_x
                and mov.off == 0
                and mov.imm == 0
                and rsh.code == rsh64_k
                and lsh.code == lsh64_k
                and ior.code == or64_x
            ):
                tmp_reg = mov.dst_reg
                src_reg = mov.src_reg
                rot_amount = lsh.imm
                rsh_amount = rsh.imm
                if (
                    rsh.dst_reg == tmp_reg
                    and lsh.dst_reg == src_reg
                    and ior.dst_reg == src_reg
                    and ior.src_reg == tmp_reg
                    and 0 < rot_amount < 64
                    and 0 < rsh_amount < 64
                    and rot_amount + rsh_amount == 64
                ):
                    count += 1
                    idx += 4
                    matched = True

        if matched:
            continue

        if idx + 3 < insn_cnt:
            mov = insns[idx]
            lsh = insns[idx + 1]
            rsh = insns[idx + 2]
            ior = insns[idx + 3]

            if mov.code == mov64_x:
                is64 = True
                width = 64
            elif mov.code == mov32_x:
                is64 = False
                width = 32
            else:
                idx += 1
                continue

            if mov.off != 0 or mov.imm != 0:
                idx += 1
                continue

            tmp_reg = mov.dst_reg
            src_reg = mov.src_reg
            expected_lsh = lsh64_k if is64 else lsh32_k
            if lsh.code != expected_lsh or lsh.dst_reg != src_reg:
                idx += 1
                continue
            rot_amount = lsh.imm
            if rot_amount <= 0 or rot_amount >= width:
                idx += 1
                continue

            expected_rsh = rsh64_k if is64 else rsh32_k
            if rsh.code != expected_rsh or rsh.dst_reg != tmp_reg:
                idx += 1
                continue
            if rsh.imm != width - rot_amount:
                idx += 1
                continue

            expected_or = or64_x if is64 else or32_x
            if (
                ior.code != expected_or
                or ior.dst_reg != src_reg
                or ior.src_reg != tmp_reg
            ):
                idx += 1
                continue

            count += 1
            idx += 4
            continue

        idx += 1

    return count


def scan_addr_calc(insns: list[Insn]) -> int:
    if len(insns) < 3:
        return 0

    mov64_x = 0xBF
    lsh64_k = 0x67
    add64_x = 0x0F

    count = 0
    idx = 0
    insn_cnt = len(insns)

    while idx + 2 < insn_cnt:
        mov = insns[idx]
        lsh = insns[idx + 1]
        add = insns[idx + 2]
        if (
            mov.code == mov64_x
            and mov.off == 0
            and mov.imm == 0
            and lsh.code == lsh64_k
            and lsh.dst_reg == mov.dst_reg
            and 1 <= lsh.imm <= 3
            and add.code == add64_x
            and add.dst_reg == mov.dst_reg
        ):
            count += 1
            idx += 3
            continue
        idx += 1

    return count


def analyze_section(section) -> SectionResult:
    insns = parse_raw_insns(section.data())
    return SectionResult(
        name=section.name or "<unnamed>",
        insn_count=len(insns),
        rotate=scan_rotate(insns),
        wide=scan_wide_mem(insns),
        lea=scan_addr_calc(insns),
        cmov=scan_cmov(insns),
    )


def analyze_object(path: Path, source: str, repo_root: Path) -> ProgramResult:
    with path.open("rb") as handle:
        elf = ELFFile(handle)
        section_results = [
            analyze_section(section)
            for section in elf.iter_sections()
            if is_code_section(section)
        ]

    relpath = path.relative_to(repo_root).as_posix()
    display_name = path.name
    insn_count = sum(section.insn_count for section in section_results)
    rotate = sum(section.rotate for section in section_results)
    wide = sum(section.wide for section in section_results)
    lea = sum(section.lea for section in section_results)
    cmov = sum(section.cmov for section in section_results)
    return ProgramResult(
        source=source,
        relpath=relpath,
        display_name=display_name,
        insn_count=insn_count,
        exec_section_count=len(section_results),
        rotate=rotate,
        wide=wide,
        lea=lea,
        cmov=cmov,
        sections=tuple(section_results),
    )


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
    report_path = corpus_build_report
    if report_path is None:
        candidate = repo_root / "corpus" / "results" / "expanded_corpus_build.json"
        if candidate.exists():
            report_path = candidate

    corpus_source = "filesystem scan under `corpus/`"
    if report_path is not None and report_path.exists():
        raw_corpus_paths, corpus_source = load_corpus_paths_from_build_report(report_path.resolve())
    else:
        raw_corpus_paths = sorted((repo_root / "corpus").rglob("*.bpf.o"))

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


def expected_micro_object_count(repo_root: Path) -> int:
    return len(tuple((repo_root / "micro" / "programs").glob("*.bpf.c")))


def sort_results(results: list[ProgramResult]) -> list[ProgramResult]:
    return sorted(results, key=lambda item: (-item.total, -item.rotate, -item.wide, -item.lea, -item.cmov, item.relpath))


def family_totals(results: list[ProgramResult]) -> dict[str, int]:
    return {
        "ROTATE": sum(item.rotate for item in results),
        "WIDE": sum(item.wide for item in results),
        "LEA": sum(item.lea for item in results),
        "CMOV": sum(item.cmov for item in results),
    }


def family_program_coverage(results: list[ProgramResult]) -> dict[str, int]:
    return {
        "ROTATE": sum(1 for item in results if item.rotate > 0),
        "WIDE": sum(1 for item in results if item.wide > 0),
        "LEA": sum(1 for item in results if item.lea > 0),
        "CMOV": sum(1 for item in results if item.cmov > 0),
    }


def mean_sites(results: list[ProgramResult]) -> float:
    if not results:
        return 0.0
    return statistics.mean(item.total for item in results)


def programs_with_sites(results: list[ProgramResult]) -> int:
    return sum(1 for item in results if item.total > 0)


def markdown_table(headers: list[str], rows: list[list[object]]) -> list[str]:
    lines = [
        "| " + " | ".join(headers) + " |",
        "| " + " | ".join("---" for _ in headers) + " |",
    ]
    for row in rows:
        lines.append("| " + " | ".join(str(cell) for cell in row) + " |")
    return lines


def summarize_dataset(name: str, results: list[ProgramResult]) -> list[str]:
    totals = family_totals(results)
    coverage = family_program_coverage(results)
    total_sites = sum(item.total for item in results)
    total_insns = sum(item.insn_count for item in results)
    total_sections = sum(item.exec_section_count for item in results)
    nonzero = programs_with_sites(results)
    rows = [
        ["Programs", len(results)],
        ["Programs with >=1 site", nonzero],
        ["Coverage", f"{(nonzero / len(results) * 100):.1f}%" if results else "0.0%"],
        ["Total executable sections", total_sections],
        ["Total BPF instructions", total_insns],
        ["Total directive sites", total_sites],
        ["Average sites per program", f"{mean_sites(results):.2f}"],
        ["ROTATE sites / programs", f"{totals['ROTATE']} / {coverage['ROTATE']}"],
        ["WIDE sites / programs", f"{totals['WIDE']} / {coverage['WIDE']}"],
        ["LEA sites / programs", f"{totals['LEA']} / {coverage['LEA']}"],
        ["CMOV sites / programs", f"{totals['CMOV']} / {coverage['CMOV']}"],
    ]
    return [f"### {name}", ""] + markdown_table(["Metric", "Value"], rows) + [""]


def render_program_table(results: list[ProgramResult]) -> list[str]:
    rows = [
        [
            item.relpath,
            item.insn_count,
            item.exec_section_count,
            item.rotate,
            item.wide,
            item.lea,
            item.cmov,
            item.total,
        ]
        for item in results
    ]
    return markdown_table(
        ["Program", "Insns", "Secs", "ROTATE", "WIDE", "LEA", "CMOV", "Total"],
        rows,
    )


def required_workload_rows(results: list[ProgramResult]) -> dict[str, list[list[object]]]:
    by_stem = {Path(item.display_name).name.removesuffix(".bpf.o"): item for item in results}
    output: dict[str, list[list[object]]] = {}
    for group_name, names in REQUIRED_WORKLOADS.items():
        rows: list[list[object]] = []
        for name in names:
            item = by_stem.get(name)
            if item is None:
                rows.append([name, "missing", "-", "-", "-", "-", "-", "-"])
                continue
            rows.append(
                [
                    name,
                    item.relpath,
                    item.insn_count,
                    item.rotate,
                    item.wide,
                    item.lea,
                    item.cmov,
                    item.total,
                ]
            )
        output[group_name] = rows
    return output


def top_rows(results: list[ProgramResult], top_n: int) -> list[list[object]]:
    rows: list[list[object]] = []
    for item in sort_results(results)[:top_n]:
        rows.append(
            [
                item.source,
                item.relpath,
                item.insn_count,
                item.rotate,
                item.wide,
                item.lea,
                item.cmov,
                item.total,
            ]
        )
    return rows


def infer_analysis(
    all_results: list[ProgramResult],
    micro_results: list[ProgramResult],
    corpus_results: list[ProgramResult],
    repo_root: Path,
) -> list[str]:
    overall_totals = family_totals(all_results)
    overall_coverage = family_program_coverage(all_results)
    micro_totals = family_totals(micro_results)
    corpus_totals = family_totals(corpus_results)
    dominant_family_total = max(overall_totals.items(), key=lambda item: (item[1], item[0]))
    dominant_family_cov = max(overall_coverage.items(), key=lambda item: (item[1], item[0]))
    top_overall = sort_results(all_results)[:3]
    top_corpus = sort_results(corpus_results)[:3]

    lines = [
        "## Analysis",
        "",
        f"- Across all {len(all_results)} available objects, `{dominant_family_total[0]}` is the most common family by raw site count ({dominant_family_total[1]} sites), while `{dominant_family_cov[0]}` touches the widest set of programs ({dominant_family_cov[1]} objects).",
        f"- The current on-disk corpus snapshot contains {len(corpus_results)} real-program objects. This is smaller than the `162 paired instances (36 unique)` target called out in `docs/kernel-jit-optimization-plan.md` §6.3, so these numbers should be treated as a snapshot of currently available workloads rather than the final paper corpus.",
    ]

    if top_overall:
        lines.append(
            f"- The densest overall objects are `{top_overall[0].relpath}` ({top_overall[0].total} sites), `{top_overall[1].relpath}` ({top_overall[1].total} sites), and `{top_overall[2].relpath}` ({top_overall[2].total} sites)."
            if len(top_overall) >= 3
            else f"- The densest overall object is `{top_overall[0].relpath}` ({top_overall[0].total} sites)."
        )
    if top_corpus:
        if len(top_corpus) >= 3:
            lines.append(
                f"- Within the real-program corpus, the highest-density objects are `{top_corpus[0].relpath}` ({top_corpus[0].total} sites), `{top_corpus[1].relpath}` ({top_corpus[1].total} sites), and `{top_corpus[2].relpath}` ({top_corpus[2].total} sites)."
            )
        else:
            lines.append(
                f"- Within the real-program corpus, the highest-density object is `{top_corpus[0].relpath}` ({top_corpus[0].total} sites)."
            )
    lines.append(
        f"- The overall site mix is heavily skewed by synthetic micro workloads: micro objects contribute {sum(item.total for item in micro_results)}/{sum(item.total for item in all_results)} total sites, and nearly all `ROTATE` opportunities come from that set ({micro_totals['ROTATE']} of {overall_totals['ROTATE']})."
    )
    lines.append(
        f"- In the current real-program corpus, `CMOV` is the only directive family with meaningful coverage ({corpus_totals['CMOV']} sites across 10 objects). `WIDE` appears only in `corpus/bcf/collected/xdp_synproxy_kern.bpf.o` ({corpus_totals['WIDE']} sites), while `ROTATE` and `LEA` have zero hits in this snapshot."
    )

    required_rows = required_workload_rows(micro_results)
    policy_rows = required_rows["Policy sensitivity"]
    hit_names = [row[0] for row in policy_rows if isinstance(row[-1], int) and row[-1] > 0]
    zero_names = [row[0] for row in policy_rows if isinstance(row[-1], int) and row[-1] == 0]
    if hit_names:
        lines.append(
            f"- The §6.3 policy-sensitivity set already contains directive-bearing workloads in this raw-ELF scan: {', '.join(f'`{name}`' for name in hit_names)}."
        )
    if zero_names:
        lines.append(
            f"- Some §6.3 policy-sensitivity workloads have zero raw-ELF hits in the current snapshot: {', '.join(f'`{name}`' for name in zero_names)}. Those benchmarks still matter for negative controls, but they should not be used to claim broad directive coverage."
        )

    corpus_nonzero = programs_with_sites(corpus_results)
    lines.append(
        f"- For paper positioning, the strongest claim this census supports is breadth of candidate coverage, not acceptance. The raw ELF scan found sites in {corpus_nonzero}/{len(corpus_results)} real-program objects; verifier-inserted instructions and exact validator checks still need an xlated-program acceptance pass to complete the §6.3 story."
    )
    lines.append(
        "- For evaluation claims, this means the micro suite already exercises all four families, but the current real-program snapshot does not yet support a strong claim that all four families are common in deployed workloads. That gap should be closed either by expanding the real corpus or by narrowing the claim to the families that actually appear."
    )
    lines.append("")
    lines.append("## Methodology Notes")
    lines.append("")
    lines.append(
        "- This census scans raw instructions from every executable ELF section in each `.bpf.o` file. It does not require loading the program into a kernel or VM."
    )
    lines.append(
        "- Pattern matching is a direct Python translation of `scanner/src/scanner.cpp` and `micro/runner/src/kernel_runner.cpp`, including the rotate variants present in the implementation."
    )
    lines.append(
        "- Counts are candidate sites, not accepted rules. They are therefore appropriate for a coverage census, but not a substitute for xlated-program acceptance-rate measurements."
    )
    return lines


def render_report(
    repo_root: Path,
    inputs: ScanInputs,
    micro_results: list[ProgramResult],
    corpus_results: list[ProgramResult],
    top_n: int,
) -> str:
    all_results = sort_results(micro_results + corpus_results)
    micro_results = sort_results(micro_results)
    corpus_results = sort_results(corpus_results)
    totals = family_totals(all_results)
    coverage = family_program_coverage(all_results)
    total_sites = sum(item.total for item in all_results)

    lines: list[str] = [
        "# Real Program Directive Census",
        "",
        f"- Repository root: `{repo_root}`",
        f"- Raw input set on disk: {inputs.raw_micro_count} micro `.bpf.o` paths + {inputs.raw_corpus_count} corpus `.bpf.o` paths",
        f"- Corpus source: {inputs.corpus_source}",
        f"- Actual `EM_BPF` objects scanned: {len(micro_results)} micro + {len(corpus_results)} corpus = {len(all_results)} total",
        f"- Skipped non-BPF `.bpf.o` artifacts: {len(inputs.skipped_non_bpf)}",
        "- Output generated by `python3 micro/directive_census.py`",
        "",
        "## Aggregate Summary",
        "",
    ]

    summary_rows = [
        ["Programs analyzed", len(all_results)],
        ["Programs with >=1 site", programs_with_sites(all_results)],
        ["Coverage", f"{(programs_with_sites(all_results) / len(all_results) * 100):.1f}%"],
        ["Total executable sections", sum(item.exec_section_count for item in all_results)],
        ["Total BPF instructions", sum(item.insn_count for item in all_results)],
        ["Total directive sites", total_sites],
        ["Average sites per program", f"{mean_sites(all_results):.2f}"],
        ["ROTATE total / programs", f"{totals['ROTATE']} / {coverage['ROTATE']}"],
        ["WIDE total / programs", f"{totals['WIDE']} / {coverage['WIDE']}"],
        ["LEA total / programs", f"{totals['LEA']} / {coverage['LEA']}"],
        ["CMOV total / programs", f"{totals['CMOV']} / {coverage['CMOV']}"],
    ]
    lines.extend(markdown_table(["Metric", "Value"], summary_rows))
    lines.append("")
    lines.extend(summarize_dataset("Micro Benchmarks", micro_results))
    lines.extend(summarize_dataset("Corpus Real Programs", corpus_results))

    lines.append("## Top Programs By Total Sites")
    lines.append("")
    lines.extend(
        markdown_table(
            ["Source", "Program", "Insns", "ROTATE", "WIDE", "LEA", "CMOV", "Total"],
            top_rows(all_results, top_n),
        )
    )
    lines.append("")

    lines.append("## Top Real Programs By Total Sites")
    lines.append("")
    lines.extend(
        markdown_table(
            ["Program", "Insns", "ROTATE", "WIDE", "LEA", "CMOV", "Total"],
            [row[1:] for row in top_rows(corpus_results, top_n)],
        )
    )
    lines.append("")

    if inputs.skipped_non_bpf:
        lines.append("## Skipped Non-BPF Artifacts")
        lines.append("")
        lines.extend(
            markdown_table(
                ["Skipped path"],
                [[path] for path in inputs.skipped_non_bpf],
            )
        )
        lines.append("")

    lines.append("## Section 6.3 Required Workloads")
    lines.append("")
    for group_name, rows in required_workload_rows(micro_results).items():
        lines.append(f"### {group_name}")
        lines.append("")
        lines.extend(
            markdown_table(
                ["Workload", "Program", "Insns", "ROTATE", "WIDE", "LEA", "CMOV", "Total"],
                rows,
            )
        )
        lines.append("")

    lines.append("## Micro Benchmark Table")
    lines.append("")
    lines.extend(render_program_table(micro_results))
    lines.append("")

    lines.append("## Corpus Real Program Table")
    lines.append("")
    lines.extend(render_program_table(corpus_results))
    lines.append("")

    lines.extend(infer_analysis(all_results, micro_results, corpus_results, repo_root))
    lines.append("")
    return "\n".join(lines)


def main() -> int:
    args = parse_args()
    repo_root = Path(args.repo_root).resolve()
    output_path = Path(args.output).resolve()
    corpus_build_report = (
        Path(args.corpus_build_report).resolve() if args.corpus_build_report else None
    )

    inputs = collect_inputs(repo_root, corpus_build_report)
    expected_micro_objects = expected_micro_object_count(repo_root)
    if inputs.raw_micro_count != expected_micro_objects:
        print(
            f"warning: expected {expected_micro_objects} micro object paths, found {inputs.raw_micro_count}",
            file=sys.stderr,
        )

    micro_results = [analyze_object(path, "micro", repo_root) for path in inputs.micro_paths]
    corpus_results = [analyze_object(path, "corpus", repo_root) for path in inputs.corpus_paths]

    report = render_report(repo_root, inputs, micro_results, corpus_results, args.top_n)
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(report + "\n")

    total_sites = sum(item.total for item in micro_results + corpus_results)
    print(
        f"Wrote {output_path} "
        f"for {len(micro_results) + len(corpus_results)} objects "
        f"with {total_sites} total candidate sites "
        f"({len(inputs.skipped_non_bpf)} non-BPF artifacts skipped)."
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
