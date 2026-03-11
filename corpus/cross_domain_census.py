#!/usr/bin/env python3
"""Cross-domain directive site census.

Scans all corpus .bpf.o files grouped by domain (Networking, Tracing,
Security/Resource, Testing, Examples) and produces a summary table
suitable for direct paper citation.
"""
from __future__ import annotations

import sys
from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

from directive_census import (
    Insn,
    SectionResult,
    ProgramResult,
    parse_raw_insns,
    is_code_section,
    is_bpf_machine,
    scan_cmov,
    scan_wide_mem,
    scan_rotate,
    scan_addr_calc,
    analyze_object,
    filter_bpf_paths,
)

try:
    from elftools.elf.elffile import ELFFile
except ImportError as exc:
    raise SystemExit("pyelftools is required: pip install pyelftools") from exc


# Domain classification: maps corpus directory names to domains
DOMAIN_MAP: dict[str, str] = {
    # Networking
    "calico": "Networking",
    "katran": "Networking",
    "suricata": "Networking",
    "loxilb": "Networking",
    "xdp-tools": "Networking",
    "xdp-examples": "Networking",
    "xdp-tutorial": "Networking",
    "cilium": "Networking",
    "netbird": "Networking",
    "tubular": "Networking",
    # Tracing
    "bcc": "Tracing",
    "tetragon": "Tracing",
    # Security/Resource
    "systemd": "Security/Resource",
    # Testing
    "linux-selftests": "Testing",
    # Examples
    "libbpf-bootstrap": "Examples",
    # Other
    "manual-test": "Other",
    "real_world_code_size": "Other",
}

DOMAIN_ORDER = ["Networking", "Tracing", "Security/Resource", "Testing", "Examples", "Other"]


@dataclass
class DomainStats:
    domain: str
    sources: list[str]  # corpus directory names
    objects: int = 0
    programs: int = 0  # number of executable sections
    insn_count: int = 0
    cmov: int = 0
    wide: int = 0
    rotate: int = 0
    lea: int = 0
    objects_with_sites: int = 0
    results: list[ProgramResult] | None = None

    @property
    def total_sites(self) -> int:
        return self.cmov + self.wide + self.rotate + self.lea


def classify_domain(corpus_dir_name: str) -> str:
    return DOMAIN_MAP.get(corpus_dir_name, "Other")


def find_corpus_objects(corpus_build_dir: Path) -> dict[str, list[Path]]:
    """Find all .bpf.o files grouped by corpus directory name."""
    grouped: dict[str, list[Path]] = defaultdict(list)
    if not corpus_build_dir.exists():
        return grouped
    for subdir in sorted(corpus_build_dir.iterdir()):
        if not subdir.is_dir():
            continue
        objects = sorted(subdir.rglob("*.bpf.o"))
        if objects:
            grouped[subdir.name] = objects
    return grouped


def main() -> int:
    repo_root = Path(__file__).resolve().parent.parent
    corpus_build_dir = repo_root / "corpus" / "build"
    output_path = repo_root / "docs" / "tmp" / "cross-domain-directive-census.md"

    print(f"Scanning corpus in {corpus_build_dir} ...")

    # Find all objects grouped by corpus directory
    corpus_objects = find_corpus_objects(corpus_build_dir)

    # Group by domain and scan
    domain_results: dict[str, DomainStats] = {}
    per_source_results: dict[str, list[ProgramResult]] = {}
    all_results: list[ProgramResult] = []
    skipped_objects: list[str] = []
    failed_objects: list[tuple[str, str]] = []

    for source_name, paths in sorted(corpus_objects.items()):
        domain = classify_domain(source_name)
        print(f"  [{domain}] {source_name}: {len(paths)} objects ...")

        # Filter for BPF ELF only
        bpf_paths: list[Path] = []
        for p in paths:
            try:
                with p.open("rb") as f:
                    elf = ELFFile(f)
                    if is_bpf_machine(elf):
                        bpf_paths.append(p)
                    else:
                        skipped_objects.append(
                            f"{source_name}: {p.relative_to(corpus_build_dir).as_posix()} (not EM_BPF)"
                        )
            except Exception as e:
                skipped_objects.append(
                    f"{source_name}: {p.relative_to(corpus_build_dir).as_posix()} (error: {e})"
                )

        source_results: list[ProgramResult] = []
        for p in bpf_paths:
            try:
                result = analyze_object(p, source_name, repo_root)
                source_results.append(result)
                all_results.append(result)
            except Exception as e:
                failed_objects.append(
                    (p.relative_to(repo_root).as_posix(), str(e))
                )

        per_source_results[source_name] = source_results

        if domain not in domain_results:
            domain_results[domain] = DomainStats(
                domain=domain,
                sources=[],
                results=[],
            )
        ds = domain_results[domain]
        ds.sources.append(source_name)
        ds.objects += len(source_results)
        ds.programs += sum(r.exec_section_count for r in source_results)
        ds.insn_count += sum(r.insn_count for r in source_results)
        ds.cmov += sum(r.cmov for r in source_results)
        ds.wide += sum(r.wide for r in source_results)
        ds.rotate += sum(r.rotate for r in source_results)
        ds.lea += sum(r.lea for r in source_results)
        ds.objects_with_sites += sum(1 for r in source_results if r.total > 0)
        ds.results.extend(source_results)

    # Generate report
    lines: list[str] = []
    lines.append("# Cross-Domain Directive Site Census")
    lines.append("")
    lines.append("Directive candidate sites found by scanning raw BPF bytecode from")
    lines.append("executable ELF sections in `.bpf.o` files across multiple BPF program domains.")
    lines.append("")
    lines.append("## Summary Table")
    lines.append("")
    lines.append("| Domain | Sources | Objects | Programs | Insns | CMOV | WIDE | ROTATE | LEA | Total Sites | Objects w/ Sites |")
    lines.append("| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |")

    total_objects = 0
    total_programs = 0
    total_insns = 0
    total_cmov = 0
    total_wide = 0
    total_rotate = 0
    total_lea = 0
    total_sites_all = 0
    total_with_sites = 0

    for domain in DOMAIN_ORDER:
        if domain not in domain_results:
            continue
        ds = domain_results[domain]
        lines.append(
            f"| {ds.domain} | {len(ds.sources)} | {ds.objects} | {ds.programs} | {ds.insn_count} "
            f"| {ds.cmov} | {ds.wide} | {ds.rotate} | {ds.lea} | {ds.total_sites} | {ds.objects_with_sites} |"
        )
        total_objects += ds.objects
        total_programs += ds.programs
        total_insns += ds.insn_count
        total_cmov += ds.cmov
        total_wide += ds.wide
        total_rotate += ds.rotate
        total_lea += ds.lea
        total_sites_all += ds.total_sites
        total_with_sites += ds.objects_with_sites

    lines.append(
        f"| **Total** | **{len(corpus_objects)}** | **{total_objects}** | **{total_programs}** "
        f"| **{total_insns}** | **{total_cmov}** | **{total_wide}** | **{total_rotate}** "
        f"| **{total_lea}** | **{total_sites_all}** | **{total_with_sites}** |"
    )
    lines.append("")

    # Per-source breakdown
    lines.append("## Per-Source Breakdown")
    lines.append("")
    lines.append("| Source | Domain | Objects | Programs | Insns | CMOV | WIDE | ROTATE | LEA | Total | w/ Sites |")
    lines.append("| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |")

    for source_name in sorted(per_source_results.keys()):
        results = per_source_results[source_name]
        if not results:
            lines.append(f"| {source_name} | {classify_domain(source_name)} | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |")
            continue
        domain = classify_domain(source_name)
        n_obj = len(results)
        n_prog = sum(r.exec_section_count for r in results)
        n_insn = sum(r.insn_count for r in results)
        n_cmov = sum(r.cmov for r in results)
        n_wide = sum(r.wide for r in results)
        n_rotate = sum(r.rotate for r in results)
        n_lea = sum(r.lea for r in results)
        n_total = n_cmov + n_wide + n_rotate + n_lea
        n_with = sum(1 for r in results if r.total > 0)
        lines.append(
            f"| {source_name} | {domain} | {n_obj} | {n_prog} | {n_insn} "
            f"| {n_cmov} | {n_wide} | {n_rotate} | {n_lea} | {n_total} | {n_with} |"
        )
    lines.append("")

    # Per-domain detail sections
    for domain in DOMAIN_ORDER:
        if domain not in domain_results:
            continue
        ds = domain_results[domain]
        if not ds.results:
            continue

        lines.append(f"## {domain} Domain Details")
        lines.append("")
        lines.append(f"Sources: {', '.join(ds.sources)}")
        lines.append("")

        # Show top programs with sites
        sorted_results = sorted(ds.results, key=lambda r: (-r.total, r.relpath))
        top_with_sites = [r for r in sorted_results if r.total > 0]

        if top_with_sites:
            lines.append(f"### Programs with Directive Sites ({len(top_with_sites)} of {len(ds.results)})")
            lines.append("")
            lines.append("| Program | Source | Insns | CMOV | WIDE | ROTATE | LEA | Total |")
            lines.append("| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |")
            for r in top_with_sites[:50]:  # limit to top 50
                lines.append(
                    f"| {r.display_name} | {r.source} | {r.insn_count} "
                    f"| {r.cmov} | {r.wide} | {r.rotate} | {r.lea} | {r.total} |"
                )
            if len(top_with_sites) > 50:
                lines.append(f"| ... | ... | ... | ... | ... | ... | ... | ({len(top_with_sites) - 50} more) |")
            lines.append("")
        else:
            lines.append("No programs with directive sites in this domain.")
            lines.append("")

    # Top 20 programs overall
    lines.append("## Top 20 Programs by Total Sites (All Domains)")
    lines.append("")
    sorted_all = sorted(all_results, key=lambda r: (-r.total, r.relpath))
    top_20 = [r for r in sorted_all if r.total > 0][:20]
    if top_20:
        lines.append("| Program | Source | Domain | Insns | CMOV | WIDE | ROTATE | LEA | Total |")
        lines.append("| --- | --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |")
        for r in top_20:
            domain = classify_domain(r.source)
            lines.append(
                f"| {r.display_name} | {r.source} | {domain} "
                f"| {r.insn_count} | {r.cmov} | {r.wide} | {r.rotate} | {r.lea} | {r.total} |"
            )
    lines.append("")

    # Skipped and failed
    if skipped_objects:
        lines.append("## Skipped Objects")
        lines.append("")
        for s in skipped_objects:
            lines.append(f"- {s}")
        lines.append("")

    if failed_objects:
        lines.append("## Failed Objects")
        lines.append("")
        for path, err in failed_objects:
            lines.append(f"- `{path}`: {err}")
        lines.append("")

    # Key findings
    lines.append("## Key Findings")
    lines.append("")

    # Calculate domain coverage rates
    domain_coverage: list[tuple[str, int, int]] = []
    for domain in DOMAIN_ORDER:
        if domain not in domain_results:
            continue
        ds = domain_results[domain]
        if ds.objects > 0:
            domain_coverage.append((ds.domain, ds.objects_with_sites, ds.objects))

    lines.append("### Cross-Domain Coverage")
    lines.append("")
    for domain, with_sites, total_obj in domain_coverage:
        pct = with_sites / total_obj * 100 if total_obj > 0 else 0.0
        lines.append(f"- **{domain}**: {with_sites}/{total_obj} objects ({pct:.1f}%) have at least one directive site")
    lines.append("")

    # Family distribution across domains
    lines.append("### Directive Family Distribution")
    lines.append("")
    for family_name in ["CMOV", "WIDE", "ROTATE", "LEA"]:
        domains_with_family: list[str] = []
        for domain in DOMAIN_ORDER:
            if domain not in domain_results:
                continue
            ds = domain_results[domain]
            val = getattr(ds, family_name.lower(), 0)
            if val > 0:
                domains_with_family.append(f"{ds.domain} ({val})")
        if domains_with_family:
            lines.append(f"- **{family_name}**: appears in {', '.join(domains_with_family)}")
        else:
            lines.append(f"- **{family_name}**: not found in any domain")
    lines.append("")

    # Dominant family analysis
    families = {"CMOV": total_cmov, "WIDE": total_wide, "ROTATE": total_rotate, "LEA": total_lea}
    dominant = max(families.items(), key=lambda x: x[1])
    lines.append("### Distribution Pattern")
    lines.append("")
    lines.append(f"- Dominant family by raw count: **{dominant[0]}** ({dominant[1]} sites)")
    lines.append(f"- Total directive sites across all {total_objects} objects: {total_sites_all}")
    lines.append(f"- Objects with at least one site: {total_with_sites}/{total_objects} ({total_with_sites / total_objects * 100 if total_objects > 0 else 0:.1f}%)")
    lines.append(f"- Total BPF instructions scanned: {total_insns}")
    if total_insns > 0 and total_sites_all > 0:
        lines.append(f"- Site density: {total_sites_all / total_insns * 1000:.2f} sites per 1000 instructions")
    lines.append("")

    lines.append("## Methodology")
    lines.append("")
    lines.append("- Scanned raw BPF bytecode from every executable (`SHF_EXECINSTR`) ELF section")
    lines.append("- Pattern matching uses the same heuristics as `scanner/src/scanner.cpp`")
    lines.append("- Counts are **candidate** sites (pre-verifier), not accepted rules")
    lines.append("- Only `EM_BPF` ELF objects were scanned; non-BPF `.bpf.o` files were skipped")
    lines.append("- Domain classification is based on corpus directory name")
    lines.append("")

    # Write output
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text("\n".join(lines) + "\n")
    print(f"\nWrote report to {output_path}")
    print(f"  Total objects: {total_objects}")
    print(f"  Total directive sites: {total_sites_all}")
    print(f"  Objects with sites: {total_with_sites}")
    print(f"  Skipped: {len(skipped_objects)}, Failed: {len(failed_objects)}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
