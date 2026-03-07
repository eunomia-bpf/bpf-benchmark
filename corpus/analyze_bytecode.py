#!/usr/bin/env python3
from __future__ import annotations

import json
import statistics
import struct
import sys
from collections import Counter, defaultdict
from pathlib import Path
from typing import Any

from elftools.elf.elffile import ELFFile
from elftools.elf.sections import SymbolTableSection


MANIFEST_PATH = Path("corpus/bcf/manifest.json")
DATASET_ROOT = Path("corpus/bcf")
RESULTS_DIR = Path("corpus/results")

SHF_EXECINSTR = 0x4
INSN_SIZE = 8

BPF_LD = 0x00
BPF_LDX = 0x01
BPF_ST = 0x02
BPF_STX = 0x03
BPF_ALU = 0x04
BPF_JMP = 0x05
BPF_JMP32 = 0x06
BPF_ALU64 = 0x07

HELPER_NAMES = {
    1: "map_lookup_elem",
    2: "map_update_elem",
    3: "map_delete_elem",
    4: "probe_read",
    5: "ktime_get_ns",
    6: "trace_printk",
    7: "get_prandom_u32",
    12: "tail_call",
    14: "get_current_pid_tgid",
    15: "get_current_uid_gid",
    16: "get_current_comm",
    25: "perf_event_output",
    26: "skb_load_bytes",
    28: "get_smp_processor_id",
    35: "get_current_cgroup_id",
    45: "probe_read_kernel",
    46: "probe_read_user",
    113: "probe_read_kernel_str",
    115: "get_current_task_btf",
    164: "ktime_get_boot_ns",
}

SKIP_SECTION_EXACT = {
    ".BTF",
    ".BTF.ext",
    ".maps",
    ".rel",
    ".rodata",
    ".data",
    ".bss",
    "license",
    ".license",
}
SKIP_SECTION_PREFIXES = (
    ".debug",
    ".rel",
    ".rela",
    ".rodata",
    ".data",
    ".bss",
    ".maps",
)


def helper_name(helper_id: int) -> str:
    return HELPER_NAMES.get(helper_id, f"helper_{helper_id}")


def is_skipped_section(section_name: str) -> bool:
    return section_name in SKIP_SECTION_EXACT or section_name.startswith(SKIP_SECTION_PREFIXES)


def counter_to_json(counter: Counter[int]) -> dict[str, int]:
    return {str(key): counter[key] for key in sorted(counter)}


def collect_func_symbol_counts(elf: ELFFile) -> dict[int, int]:
    counts: dict[int, int] = defaultdict(int)
    for section in elf.iter_sections():
        if not isinstance(section, SymbolTableSection):
            continue
        for symbol in section.iter_symbols():
            section_index = symbol["st_shndx"]
            if symbol["st_info"]["type"] != "STT_FUNC" or not isinstance(section_index, int):
                continue
            counts[section_index] += 1
    return counts


def parse_section_bytecode(data: bytes) -> tuple[dict[str, Any], Counter[int]]:
    raw_insn_count = len(data) // INSN_SIZE
    trailing_bytes = len(data) % INSN_SIZE
    helper_histogram: Counter[int] = Counter()
    metrics = {
        "insn_count": raw_insn_count,
        "alu_count": 0,
        "alu64_count": 0,
        "mem_load_count": 0,
        "mem_store_count": 0,
        "branch_count": 0,
        "call_count": 0,
        "bpf2bpf_call_count": 0,
        "trailing_bytes": trailing_bytes,
    }

    idx = 0
    while idx < raw_insn_count:
        offset = idx * INSN_SIZE
        code, regs, _off, imm = struct.unpack_from("<BBhi", data, offset)
        dst_reg = regs & 0x0F
        src_reg = (regs >> 4) & 0x0F
        op_class = code & 0x07
        del dst_reg  # Parsed for completeness, but not currently emitted.

        if op_class == BPF_ALU:
            metrics["alu_count"] += 1
        elif op_class == BPF_ALU64:
            metrics["alu64_count"] += 1
        elif op_class in (BPF_LD, BPF_LDX):
            metrics["mem_load_count"] += 1
        elif op_class in (BPF_ST, BPF_STX):
            metrics["mem_store_count"] += 1

        if code == 0x85:
            if src_reg == 0:
                metrics["call_count"] += 1
                helper_histogram[imm] += 1
            elif src_reg == 1:
                metrics["bpf2bpf_call_count"] += 1
        elif op_class in (BPF_JMP, BPF_JMP32):
            is_call = (code & 0xF0) == 0x80
            is_exit = (code & 0xF0) == 0x90
            if not is_call and not is_exit:
                metrics["branch_count"] += 1

        if code == 0x18 and idx + 1 < raw_insn_count:
            idx += 2
        else:
            idx += 1

    return metrics, helper_histogram


def analyze_object(manifest_entry: dict[str, Any]) -> dict[str, Any]:
    object_path = DATASET_ROOT / manifest_entry["relative_path"]
    with object_path.open("rb") as handle:
        elf = ELFFile(handle)
        func_symbol_counts = collect_func_symbol_counts(elf)

        section_features: list[dict[str, Any]] = []
        aggregate_metrics = {
            "insn_count": 0,
            "alu_count": 0,
            "alu64_count": 0,
            "mem_load_count": 0,
            "mem_store_count": 0,
            "branch_count": 0,
            "call_count": 0,
            "bpf2bpf_call_count": 0,
        }
        helper_histogram: Counter[int] = Counter()

        for section_index, section in enumerate(elf.iter_sections()):
            section_name = section.name or ""
            if is_skipped_section(section_name):
                continue
            if not (section.header["sh_flags"] & SHF_EXECINSTR):
                continue

            data = section.data()
            metrics, section_helper_histogram = parse_section_bytecode(data)
            func_symbol_count = func_symbol_counts.get(section_index, 0)
            section_record = {
                "section_index": section_index,
                "section_name": section_name,
                "section_size": len(data),
                "func_symbol_count": func_symbol_count,
                "has_subprograms": func_symbol_count > 1,
                **metrics,
                "helper_histogram": counter_to_json(section_helper_histogram),
            }
            section_features.append(section_record)

            for metric_name in aggregate_metrics:
                aggregate_metrics[metric_name] += metrics[metric_name]
            helper_histogram.update(section_helper_histogram)

    record = dict(manifest_entry)
    record.update(
        {
            "object_path": str(object_path),
            "exec_section_count": len(section_features),
            "has_subprograms": any(section["has_subprograms"] for section in section_features),
            **aggregate_metrics,
            "helper_histogram": counter_to_json(helper_histogram),
            "sections": section_features,
        }
    )
    return record


def format_percent(numerator: int, denominator: int) -> str:
    if denominator == 0:
        return "0.00%"
    return f"{(numerator / denominator) * 100:.2f}%"


def format_distribution(values: list[int]) -> str:
    if not values:
        return "min=0 median=0 mean=0.00 max=0"
    return (
        f"min={min(values)} "
        f"median={statistics.median(values):.2f} "
        f"mean={statistics.mean(values):.2f} "
        f"max={max(values)}"
    )


def write_outputs(records: list[dict[str, Any]], helper_counter: Counter[int]) -> None:
    RESULTS_DIR.mkdir(parents=True, exist_ok=True)

    bytecode_features_path = RESULTS_DIR / "bytecode_features.json"
    bytecode_features_path.write_text(json.dumps(records, indent=2, sort_keys=True) + "\n")

    total_helper_calls = sum(helper_counter.values())
    cumulative = 0
    helper_rows = []
    for helper_id, count in helper_counter.most_common():
        cumulative += count
        helper_rows.append(
            {
                "helper_id": helper_id,
                "helper_name": helper_name(helper_id),
                "count": count,
                "percentage": (count / total_helper_calls * 100) if total_helper_calls else 0.0,
                "cumulative_percentage": (cumulative / total_helper_calls * 100) if total_helper_calls else 0.0,
            }
        )

    helper_pareto_path = RESULTS_DIR / "helper_pareto.json"
    helper_pareto_path.write_text(
        json.dumps(
            {
                "total_helper_calls": total_helper_calls,
                "helpers": helper_rows,
            },
            indent=2,
            sort_keys=True,
        )
        + "\n"
    )


def print_summary(records: list[dict[str, Any]], skipped: list[dict[str, str]], helper_counter: Counter[int]) -> None:
    total_programs = len(records)
    total_exec_sections = sum(record["exec_section_count"] for record in records)
    insn_counts = [record["insn_count"] for record in records]
    total_helper_calls = sum(helper_counter.values())

    print(f"Total programs analyzed: {total_programs}")
    print(f"Total executable sections: {total_exec_sections}")
    print(f"Instruction count distribution: {format_distribution(insn_counts)}")
    print("Top-15 helpers by call frequency with cumulative %:")

    cumulative = 0
    for helper_id, count in helper_counter.most_common(15):
        cumulative += count
        share = (count / total_helper_calls * 100) if total_helper_calls else 0.0
        cumulative_share = (cumulative / total_helper_calls * 100) if total_helper_calls else 0.0
        print(
            f"  {helper_id:>3} {helper_name(helper_id):<24} "
            f"{count:>8} calls  {share:6.2f}%  cumulative {cumulative_share:6.2f}%"
        )

    programs_with_bpf2bpf = sum(1 for record in records if record["bpf2bpf_call_count"] > 0)
    programs_with_many_helpers = sum(1 for record in records if record["call_count"] > 100)
    print(f"% of programs with BPF-to-BPF calls: {format_percent(programs_with_bpf2bpf, total_programs)}")
    print(f"% of programs with >100 helper calls: {format_percent(programs_with_many_helpers, total_programs)}")
    print(f"Skipped malformed ELFs: {len(skipped)}")

    if skipped:
        preview = ", ".join(item["relative_path"] for item in skipped[:5])
        suffix = "" if len(skipped) <= 5 else ", ..."
        print(f"Skipped samples: {preview}{suffix}")


def main() -> int:
    try:
        manifest = json.loads(MANIFEST_PATH.read_text())
    except Exception as exc:
        print(f"Failed to read manifest {MANIFEST_PATH}: {exc}", file=sys.stderr)
        return 1

    program_entries = manifest.get("programs")
    if not isinstance(program_entries, list):
        print(f"Manifest {MANIFEST_PATH} does not contain a valid 'programs' list.", file=sys.stderr)
        return 1

    records: list[dict[str, Any]] = []
    skipped: list[dict[str, str]] = []
    helper_counter: Counter[int] = Counter()

    for manifest_entry in program_entries:
        relative_path = manifest_entry.get("relative_path", "<unknown>")
        try:
            record = analyze_object(manifest_entry)
        except Exception as exc:
            skipped.append({"relative_path": str(relative_path), "error": str(exc)})
            continue

        records.append(record)
        helper_counter.update({int(key): value for key, value in record["helper_histogram"].items()})

    write_outputs(records, helper_counter)
    print_summary(records, skipped, helper_counter)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
