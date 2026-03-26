#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import re
import struct
import subprocess
from collections import Counter, defaultdict
from concurrent.futures import ThreadPoolExecutor
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Any

from elftools.elf.elffile import ELFFile


REPO_ROOT = Path(__file__).resolve().parents[3]
CORPUS_BUILD_ROOT = REPO_ROOT / "corpus" / "build"
RUNNER_BINARY = REPO_ROOT / "runner" / "build" / "micro_exec"
UAPI_BPF_H = REPO_ROOT / "vendor" / "linux-framework" / "tools" / "include" / "uapi" / "linux" / "bpf.h"
DEFAULT_OUTPUT_PREFIX = REPO_ROOT / "docs" / "tmp" / "20260326" / "corpus_call_statistics_20260326"

SHF_EXECINSTR = 0x4
BPF_CALL_OPCODE = 0x85
BPF_HELPER_CALL_SRC = 0
BPF_PSEUDO_CALL_SRC = 1
BPF_KFUNC_CALL_SRC = 2
TAIL_CALL_HELPER = "tail_call"
HELPER_NAME_RE = re.compile(r"FN\(([^,]+),\s*([0-9]+),")

# Security-oriented default set. This covers the helpers called out in the repo's
# security/firewall notes plus the legacy probe_read variants that still show up
# in older corpus objects.
DEFAULT_DANGEROUS_HELPERS = (
    "override_return",
    "send_signal",
    "send_signal_thread",
    "probe_write_user",
    "probe_read",
    "probe_read_str",
    "probe_read_user",
    "probe_read_user_str",
    "probe_read_kernel",
    "probe_read_kernel_str",
    "copy_from_user",
    "copy_from_user_task",
    "d_path",
)


@dataclass(frozen=True, slots=True)
class ObjectScanResult:
    project: str
    object_path: str
    object_name: str
    exec_section_count: int
    exec_insn_count: int
    bpf2bpf_calls: int
    tail_call_helpers: int
    dangerous_helper_calls: dict[str, int]
    programs: list[dict[str, Any]]
    list_programs_error: str | None

    @property
    def program_count(self) -> int:
        return len(self.programs)

    @property
    def dangerous_helper_total(self) -> int:
        return sum(self.dangerous_helper_calls.values())


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Scan corpus/build/**/*.bpf.o, enumerate programs via micro_exec "
            "list-programs, parse ELF BPF instructions, and emit call statistics."
        )
    )
    parser.add_argument(
        "--repo-root",
        default=str(REPO_ROOT),
        help="Repository root. Defaults to this script's repo.",
    )
    parser.add_argument(
        "--corpus-build-root",
        default=str(CORPUS_BUILD_ROOT),
        help="Root directory containing built corpus .bpf.o files.",
    )
    parser.add_argument(
        "--runner-binary",
        default=str(RUNNER_BINARY),
        help="Path to runner/build/micro_exec.",
    )
    parser.add_argument(
        "--uapi-bpf-h",
        default=str(UAPI_BPF_H),
        help="Repo-local uapi/linux/bpf.h used to resolve helper ids.",
    )
    parser.add_argument(
        "--output-json",
        default=str(DEFAULT_OUTPUT_PREFIX) + ".json",
        help="Output JSON path.",
    )
    parser.add_argument(
        "--output-md",
        default=str(DEFAULT_OUTPUT_PREFIX) + ".md",
        help="Output Markdown path.",
    )
    parser.add_argument(
        "--workers",
        type=int,
        default=min(8, os.cpu_count() or 1),
        help="Parallel object scans.",
    )
    return parser.parse_args()


def load_helper_ids(uapi_bpf_h: Path) -> dict[str, int]:
    helper_ids: dict[str, int] = {}
    for line in uapi_bpf_h.read_text().splitlines():
        match = HELPER_NAME_RE.search(line)
        if not match:
            continue
        helper_ids[match.group(1)] = int(match.group(2))
    return helper_ids


def resolve_dangerous_helpers(helper_ids: dict[str, int], uapi_bpf_h: Path) -> list[tuple[str, int]]:
    resolved: list[tuple[str, int]] = []
    missing: list[str] = []
    for name in DEFAULT_DANGEROUS_HELPERS:
        helper_id = helper_ids.get(name)
        if helper_id is None:
            missing.append(name)
            continue
        resolved.append((name, helper_id))
    if missing:
        missing_text = ", ".join(sorted(missing))
        raise RuntimeError(f"missing helper ids in {uapi_bpf_h}: {missing_text}")
    return resolved


def collect_object_paths(corpus_build_root: Path) -> list[Path]:
    return sorted(path.resolve() for path in corpus_build_root.rglob("*.bpf.o"))


def derive_project(corpus_build_root: Path, object_path: Path) -> str:
    relpath = object_path.relative_to(corpus_build_root)
    if not relpath.parts:
        return object_path.parent.name
    return relpath.parts[0]


def list_programs(runner_binary: Path, object_path: Path) -> list[dict[str, Any]]:
    command = [str(runner_binary), "list-programs", "--program", str(object_path)]
    completed = subprocess.run(
        command,
        capture_output=True,
        text=True,
        timeout=180,
    )
    if completed.returncode != 0:
        detail = completed.stderr.strip() or completed.stdout.strip()
        raise RuntimeError(f"command failed ({completed.returncode}): {' '.join(command)}\n{detail}")
    stdout = completed.stdout.strip()
    if not stdout:
        raise RuntimeError(f"empty stdout from {' '.join(command)}")
    payload = json.loads(stdout.splitlines()[-1])
    if not isinstance(payload, list):
        raise RuntimeError(f"unexpected list-programs payload type: {type(payload).__name__}")
    programs: list[dict[str, Any]] = []
    for record in payload:
        if not isinstance(record, dict):
            continue
        programs.append(
            {
                "name": str(record.get("name", "")),
                "section_name": str(record.get("section_name", "")),
                "insn_count": int(record.get("insn_count", 0) or 0),
                "prog_type": int(record.get("prog_type", 0) or 0),
                "expected_attach_type": int(record.get("expected_attach_type", 0) or 0),
                "prog_type_name": str(record.get("prog_type_name", "")),
                "attach_type_name": str(record.get("attach_type_name", "")),
            }
        )
    return programs


def scan_elf_calls(
    object_path: Path,
    dangerous_helpers: list[tuple[str, int]],
    tail_call_helper_id: int,
) -> dict[str, Any]:
    dangerous_helper_ids = dict((helper_id, name) for name, helper_id in dangerous_helpers)
    helper_counts: Counter[str] = Counter()
    exec_section_count = 0
    exec_insn_count = 0
    bpf2bpf_calls = 0
    tail_call_helpers = 0

    with object_path.open("rb") as handle:
        elf = ELFFile(handle)
        if elf["e_machine"] not in ("EM_BPF", 247):
            raise RuntimeError(f"not an EM_BPF object: {object_path}")
        endian = "<" if elf.little_endian else ">"
        insn_struct = struct.Struct(f"{endian}BBhi")

        for section in elf.iter_sections():
            if not (section.header["sh_flags"] & SHF_EXECINSTR):
                continue
            if section.data_size <= 0:
                continue
            if section.data_size % insn_struct.size != 0:
                raise RuntimeError(
                    f"section {section.name!r} size {section.data_size} is not a multiple of {insn_struct.size}"
                )

            exec_section_count += 1
            exec_insn_count += section.data_size // insn_struct.size
            data = section.data()
            for offset in range(0, len(data), insn_struct.size):
                code, regs, _off16, imm = insn_struct.unpack_from(data, offset)
                if code != BPF_CALL_OPCODE:
                    continue
                src_reg = regs >> 4
                if src_reg == BPF_PSEUDO_CALL_SRC:
                    bpf2bpf_calls += 1
                    continue
                if src_reg != BPF_HELPER_CALL_SRC:
                    continue
                if imm == tail_call_helper_id:
                    tail_call_helpers += 1
                helper_name = dangerous_helper_ids.get(imm)
                if helper_name is not None:
                    helper_counts[helper_name] += 1

    return {
        "exec_section_count": exec_section_count,
        "exec_insn_count": exec_insn_count,
        "bpf2bpf_calls": bpf2bpf_calls,
        "tail_call_helpers": tail_call_helpers,
        "dangerous_helper_calls": dict(
            (name, helper_counts.get(name, 0)) for name, _helper_id in dangerous_helpers
        ),
    }


def scan_object(
    repo_root: Path,
    corpus_build_root: Path,
    runner_binary: Path,
    dangerous_helpers: list[tuple[str, int]],
    tail_call_helper_id: int,
    object_path: Path,
) -> ObjectScanResult:
    relpath = object_path.relative_to(repo_root).as_posix()
    programs: list[dict[str, Any]] = []
    list_programs_error: str | None = None
    try:
        programs = list_programs(runner_binary, object_path)
    except Exception as exc:
        list_programs_error = str(exc)

    elf_stats = scan_elf_calls(object_path, dangerous_helpers, tail_call_helper_id)
    return ObjectScanResult(
        project=derive_project(corpus_build_root, object_path),
        object_path=relpath,
        object_name=object_path.name,
        exec_section_count=int(elf_stats["exec_section_count"]),
        exec_insn_count=int(elf_stats["exec_insn_count"]),
        bpf2bpf_calls=int(elf_stats["bpf2bpf_calls"]),
        tail_call_helpers=int(elf_stats["tail_call_helpers"]),
        dangerous_helper_calls=dict(elf_stats["dangerous_helper_calls"]),
        programs=programs,
        list_programs_error=list_programs_error,
    )


def render_markdown_table(headers: list[str], rows: list[list[Any]]) -> str:
    lines = [
        "| " + " | ".join(headers) + " |",
        "| " + " | ".join(["---"] * len(headers)) + " |",
    ]
    for row in rows:
        rendered = [str(cell) for cell in row]
        lines.append("| " + " | ".join(rendered) + " |")
    return "\n".join(lines)


def build_project_rows(
    projects: list[dict[str, Any]],
) -> list[list[Any]]:
    rows: list[list[Any]] = []
    for project in projects:
        rows.append(
            [
                project["project"],
                project["object_count"],
                project["program_count"],
                project["exec_section_count"],
                project["exec_insn_count"],
                project["bpf2bpf_calls"],
                project["tail_call_helpers"],
                project["dangerous_helper_total"],
                project["list_programs_failures"],
            ]
        )
    return rows


def build_helper_rows(
    projects: list[dict[str, Any]],
    dangerous_helpers: list[tuple[str, int]],
) -> list[list[Any]]:
    rows: list[list[Any]] = []
    for project in projects:
        row: list[Any] = [project["project"]]
        for helper_name, _helper_id in dangerous_helpers:
            row.append(project["dangerous_helper_calls"][helper_name])
        rows.append(row)
    return rows


def build_top_object_rows(objects: list[ObjectScanResult], field: str, limit: int = 15) -> list[list[Any]]:
    sorted_objects = sorted(
        objects,
        key=lambda record: (
            getattr(record, field)
            if field != "dangerous_helper_total"
            else record.dangerous_helper_total,
            record.exec_insn_count,
            record.object_path,
        ),
        reverse=True,
    )
    rows: list[list[Any]] = []
    for record in sorted_objects[:limit]:
        metric = getattr(record, field) if field != "dangerous_helper_total" else record.dangerous_helper_total
        rows.append(
            [
                record.project,
                record.object_path,
                metric,
                record.program_count,
                record.exec_insn_count,
            ]
        )
    return rows


def normalize_failure_reason(error: str) -> str:
    reason = error.splitlines()[-1]
    if reason.startswith("no program found in object:"):
        return "no program found in object"
    return reason


def summarize_failure_reasons(objects: list[ObjectScanResult]) -> list[dict[str, Any]]:
    counts: Counter[str] = Counter()
    for record in objects:
        if not record.list_programs_error:
            continue
        counts[normalize_failure_reason(record.list_programs_error)] += 1
    return [
        {"reason": reason, "count": count}
        for reason, count in counts.most_common()
    ]


def generate_markdown(
    payload: dict[str, Any],
    projects: list[dict[str, Any]],
    objects: list[ObjectScanResult],
    dangerous_helpers: list[tuple[str, int]],
) -> str:
    dangerous_helper_labels = ", ".join(f"`{name}`={helper_id}" for name, helper_id in dangerous_helpers)
    overall = payload["totals"]

    sections: list[str] = []
    sections.append("# Corpus Call Statistics (requested 20260326 output)")
    sections.append("")
    sections.append(f"- Generated at: `{payload['generated_at']}`")
    sections.append(f"- Corpus root: `{payload['corpus_build_root']}`")
    sections.append(f"- Runner binary: `{payload['runner_binary']}`")
    sections.append(
        "- Counting rule: object programs come from `micro_exec list-programs`; "
        "call counts scan all executable ELF sections (including `.text` subprog sections)."
    )
    sections.append(f"- Dangerous helpers counted: {dangerous_helper_labels}")
    sections.append("")
    sections.append("## Overall")
    sections.append("")
    sections.append(
        render_markdown_table(
            [
                "Objects",
                "Projects",
                "Programs",
                "Exec Sections",
                "Exec Insns",
                "bpf2bpf Calls",
                "tail_call Helpers",
                "Dangerous Helper Calls",
                "list-programs Failures",
            ],
            [
                [
                    overall["object_count"],
                    overall["project_count"],
                    overall["program_count"],
                    overall["exec_section_count"],
                    overall["exec_insn_count"],
                    overall["bpf2bpf_calls"],
                    overall["tail_call_helpers"],
                    overall["dangerous_helper_total"],
                    overall["list_programs_failures"],
                ]
            ],
        )
    )
    sections.append("")
    sections.append("## Project Summary")
    sections.append("")
    sections.append(
        render_markdown_table(
            [
                "Project",
                "Objects",
                "Programs",
                "Exec Sections",
                "Exec Insns",
                "bpf2bpf Calls",
                "tail_call Helpers",
                "Dangerous Helper Calls",
                "list-programs Failures",
            ],
            build_project_rows(projects),
        )
    )
    if overall["list_programs_failures"] > 0:
        sections.append("")
        sections.append(
            f"Program counts above only include objects where `list-programs` succeeded; "
            f"`{overall['list_programs_failures']}` objects had enumeration failures."
        )
        sections.append("")
        sections.append("## list-programs Failure Reasons")
        sections.append("")
        failure_rows = [
            [entry["count"], entry["reason"]]
            for entry in payload["list_programs_failures"]["by_reason"]
        ]
        sections.append(render_markdown_table(["Count", "Reason"], failure_rows))
    sections.append("")
    sections.append("## Dangerous Helper Breakdown By Project")
    sections.append("")
    sections.append(
        render_markdown_table(
            ["Project"] + [f"{name} ({helper_id})" for name, helper_id in dangerous_helpers],
            build_helper_rows(projects, dangerous_helpers),
        )
    )
    sections.append("")
    sections.append("## Top Objects By bpf2bpf Calls")
    sections.append("")
    sections.append(
        render_markdown_table(
            ["Project", "Object", "bpf2bpf Calls", "Programs", "Exec Insns"],
            build_top_object_rows(objects, "bpf2bpf_calls"),
        )
    )
    sections.append("")
    sections.append("## Top Objects By tail_call Helper Calls")
    sections.append("")
    sections.append(
        render_markdown_table(
            ["Project", "Object", "tail_call Helpers", "Programs", "Exec Insns"],
            build_top_object_rows(objects, "tail_call_helpers"),
        )
    )
    sections.append("")
    sections.append("## Top Objects By Dangerous Helper Calls")
    sections.append("")
    sections.append(
        render_markdown_table(
            ["Project", "Object", "Dangerous Helper Calls", "Programs", "Exec Insns"],
            build_top_object_rows(objects, "dangerous_helper_total"),
        )
    )
    return "\n".join(sections) + "\n"


def main() -> int:
    args = parse_args()
    repo_root = Path(args.repo_root).resolve()
    corpus_build_root = Path(args.corpus_build_root).resolve()
    runner_binary = Path(args.runner_binary).resolve()
    uapi_bpf_h = Path(args.uapi_bpf_h).resolve()
    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()

    helper_ids = load_helper_ids(uapi_bpf_h)
    dangerous_helpers = resolve_dangerous_helpers(helper_ids, uapi_bpf_h)
    tail_call_helper_id = helper_ids.get(TAIL_CALL_HELPER)
    if tail_call_helper_id is None:
        raise RuntimeError(f"failed to resolve helper id for {TAIL_CALL_HELPER}")

    object_paths = collect_object_paths(corpus_build_root)
    if not object_paths:
        raise RuntimeError(f"no .bpf.o files found under {corpus_build_root}")

    scan_args = [
        (repo_root, corpus_build_root, runner_binary, dangerous_helpers, tail_call_helper_id, object_path)
        for object_path in object_paths
    ]
    objects: list[ObjectScanResult] = []
    with ThreadPoolExecutor(max_workers=max(1, args.workers)) as executor:
        for result in executor.map(lambda item: scan_object(*item), scan_args):
            objects.append(result)
    objects.sort(key=lambda record: record.object_path)

    dangerous_helper_names = [name for name, _helper_id in dangerous_helpers]
    projects_by_name: dict[str, dict[str, Any]] = {}
    total_dangerous_calls = Counter()
    total_programs = 0
    total_exec_sections = 0
    total_exec_insns = 0
    total_bpf2bpf_calls = 0
    total_tail_call_helpers = 0
    total_list_program_failures = 0

    object_entries: list[dict[str, Any]] = []
    for record in objects:
        total_programs += record.program_count
        total_exec_sections += record.exec_section_count
        total_exec_insns += record.exec_insn_count
        total_bpf2bpf_calls += record.bpf2bpf_calls
        total_tail_call_helpers += record.tail_call_helpers
        if record.list_programs_error:
            total_list_program_failures += 1

        entry = projects_by_name.setdefault(
            record.project,
            {
                "project": record.project,
                "object_count": 0,
                "program_count": 0,
                "exec_section_count": 0,
                "exec_insn_count": 0,
                "bpf2bpf_calls": 0,
                "tail_call_helpers": 0,
                "dangerous_helper_total": 0,
                "dangerous_helper_calls": dict((name, 0) for name in dangerous_helper_names),
                "list_programs_failures": 0,
            },
        )
        entry["object_count"] += 1
        entry["program_count"] += record.program_count
        entry["exec_section_count"] += record.exec_section_count
        entry["exec_insn_count"] += record.exec_insn_count
        entry["bpf2bpf_calls"] += record.bpf2bpf_calls
        entry["tail_call_helpers"] += record.tail_call_helpers
        if record.list_programs_error:
            entry["list_programs_failures"] += 1

        for helper_name in dangerous_helper_names:
            count = record.dangerous_helper_calls.get(helper_name, 0)
            entry["dangerous_helper_calls"][helper_name] += count
            entry["dangerous_helper_total"] += count
            total_dangerous_calls[helper_name] += count

        object_entries.append(
            {
                "project": record.project,
                "object_path": record.object_path,
                "object_name": record.object_name,
                "program_count": record.program_count,
                "exec_section_count": record.exec_section_count,
                "exec_insn_count": record.exec_insn_count,
                "bpf2bpf_calls": record.bpf2bpf_calls,
                "tail_call_helpers": record.tail_call_helpers,
                "dangerous_helper_total": record.dangerous_helper_total,
                "dangerous_helper_calls": record.dangerous_helper_calls,
                "programs": record.programs,
                "list_programs_error": record.list_programs_error,
            }
        )

    projects = sorted(
        projects_by_name.values(),
        key=lambda project: (
            project["dangerous_helper_total"],
            project["bpf2bpf_calls"],
            project["tail_call_helpers"],
            project["project"],
        ),
        reverse=True,
    )
    failure_summary = summarize_failure_reasons(objects)

    payload = {
        "generated_at": datetime.now().astimezone().isoformat(timespec="seconds"),
        "repo_root": str(repo_root),
        "corpus_build_root": str(corpus_build_root),
        "runner_binary": str(runner_binary),
        "uapi_bpf_h": str(uapi_bpf_h),
        "dangerous_helpers": [
            {"name": name, "id": helper_ids[name]}
            for name in dangerous_helper_names
        ],
        "tail_call_helper": {"name": TAIL_CALL_HELPER, "id": tail_call_helper_id},
        "totals": {
            "object_count": len(objects),
            "project_count": len(projects),
            "program_count": total_programs,
            "exec_section_count": total_exec_sections,
            "exec_insn_count": total_exec_insns,
            "bpf2bpf_calls": total_bpf2bpf_calls,
            "tail_call_helpers": total_tail_call_helpers,
            "dangerous_helper_total": sum(total_dangerous_calls.values()),
            "dangerous_helper_calls": dict(
                (name, total_dangerous_calls.get(name, 0)) for name in dangerous_helper_names
            ),
            "list_programs_failures": total_list_program_failures,
        },
        "list_programs_failures": {
            "count": total_list_program_failures,
            "by_reason": failure_summary,
        },
        "projects": projects,
        "objects": object_entries,
    }

    output_json.parent.mkdir(parents=True, exist_ok=True)
    output_md.parent.mkdir(parents=True, exist_ok=True)
    output_json.write_text(json.dumps(payload, indent=2, sort_keys=False) + "\n")
    output_md.write_text(generate_markdown(payload, projects, objects, dangerous_helpers))

    print(f"wrote {output_json}")
    print(f"wrote {output_md}")
    print(
        json.dumps(
            {
                "object_count": payload["totals"]["object_count"],
                "project_count": payload["totals"]["project_count"],
                "program_count": payload["totals"]["program_count"],
                "bpf2bpf_calls": payload["totals"]["bpf2bpf_calls"],
                "tail_call_helpers": payload["totals"]["tail_call_helpers"],
                "dangerous_helper_total": payload["totals"]["dangerous_helper_total"],
                "list_programs_failures": payload["totals"]["list_programs_failures"],
            },
            indent=2,
        )
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
