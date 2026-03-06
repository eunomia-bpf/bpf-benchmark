#!/usr/bin/env python3
from __future__ import annotations

import argparse
import math
import re
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable

from benchmark_catalog import CONFIG_PATH, load_suite


ROOT_DIR = Path(__file__).resolve().parent
DEFAULT_DUMPS_DIR = ROOT_DIR / "jit-dumps"
DEFAULT_OUTPUT = DEFAULT_DUMPS_DIR / "report.md"
RUNTIMES = ("llvmbpf", "kernel")

BRANCH_RE = re.compile(r"^j[a-z0-9]*$")
STACK_SLOT_RE = re.compile(r"(?:^|[,\s])(?:-?(?:0x)?[0-9a-f]+)?\(%r(?:sp|bp)(?:,[^)]*)?\)")
ADDRESS_RE = re.compile(r"^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2}(?:\s+|$))+(.+?)\s*$")
TARGET_ADDR_RE = re.compile(r"^\s*([0-9a-f]+)")
PREFIX_TOKENS = {
    "addr32",
    "bnd",
    "cs",
    "data16",
    "ds",
    "es",
    "fs",
    "gs",
    "lock",
    "notrack",
    "rep",
    "repe",
    "repne",
    "repnz",
    "repz",
    "ss",
}


@dataclass(frozen=True)
class Instruction:
    address: int
    text: str
    mnemonic: str
    operands: str


@dataclass(frozen=True)
class Metrics:
    total_insns: int | None
    prologue: int | None
    spills: int | None
    branches: int | None
    calls: int | None
    spectre: int | None
    nops: int | None
    empty: bool = False
    missing: bool = False

    def value_for(self, category: str) -> int | None:
        return {
            "total_insns": self.total_insns,
            "prologue": self.prologue,
            "spills": self.spills,
            "branches": self.branches,
            "calls": self.calls,
            "spectre": self.spectre,
            "nops": self.nops,
        }[category]


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Compare kernel vs llvmbpf JIT disassembly for the pure-JIT micro suite.")
    parser.add_argument("--dumps-dir", default=str(DEFAULT_DUMPS_DIR), help="Directory containing <bench>.<runtime>.asm dumps.")
    parser.add_argument("--output", default=str(DEFAULT_OUTPUT), help="Optional markdown output path.")
    return parser.parse_args()


def parse_instruction(line: str) -> Instruction | None:
    match = ADDRESS_RE.match(line)
    if not match:
        return None

    address = int(match.group(1), 16)
    text = match.group(2).strip()
    if not text or text.endswith(":"):
        return None

    parts = text.split()
    index = 0
    while index < len(parts):
        token = parts[index]
        if token.startswith("."):
            return None
        if token in PREFIX_TOKENS or token.startswith("rex"):
            index += 1
            continue
        break

    if index >= len(parts):
        return None

    mnemonic = parts[index]
    operands = " ".join(parts[index + 1 :]).strip()
    return Instruction(address=address, text=text, mnemonic=mnemonic, operands=operands)


def load_instructions(path: Path) -> list[Instruction]:
    instructions: list[Instruction] = []
    for line in path.read_text(errors="replace").splitlines():
        instruction = parse_instruction(line)
        if instruction is not None:
            instructions.append(instruction)
    return instructions


def is_stack_adjust(inst: Instruction, register: str) -> bool:
    if inst.mnemonic not in {"sub", "subq", "add", "addq"}:
        return False
    return register in inst.operands


def is_frame_move(inst: Instruction, src: str, dst: str) -> bool:
    if not inst.mnemonic.startswith("mov"):
        return False
    normalized = inst.operands.replace(" ", "")
    return normalized == f"{src},{dst}"


def is_entry_padding(inst: Instruction) -> bool:
    return inst.mnemonic == "endbr64" or is_nop(inst)


def is_exit_padding(inst: Instruction) -> bool:
    return is_nop(inst) or inst.mnemonic == "int3"


def prologue_size(instructions: list[Instruction]) -> int:
    count = 0
    index = 0
    while index < len(instructions) and is_entry_padding(instructions[index]):
        index += 1

    while index < len(instructions):
        inst = instructions[index]
        if inst.mnemonic.startswith("push"):
            count += 1
        elif is_stack_adjust(inst, "%rsp"):
            count += 1
        elif is_frame_move(inst, "%rsp", "%rbp"):
            pass
        else:
            break
        index += 1

    index = len(instructions) - 1
    while index >= 0 and is_exit_padding(instructions[index]):
        index -= 1
    if index >= 0 and instructions[index].mnemonic.startswith("ret"):
        index -= 1

    while index >= 0:
        inst = instructions[index]
        if inst.mnemonic.startswith("pop"):
            count += 1
        elif is_stack_adjust(inst, "%rsp"):
            count += 1
        elif inst.mnemonic == "leave":
            count += 1
        elif is_frame_move(inst, "%rbp", "%rsp"):
            pass
        else:
            break
        index -= 1

    return count


def count_spills(instructions: list[Instruction]) -> int:
    count = 0
    for inst in instructions:
        if not inst.mnemonic.startswith("mov"):
            continue
        if STACK_SLOT_RE.search(inst.operands):
            count += 1
    return count


def count_branches(instructions: list[Instruction]) -> int:
    return sum(1 for inst in instructions if BRANCH_RE.match(inst.mnemonic))


def count_calls(instructions: list[Instruction]) -> int:
    return sum(1 for inst in instructions if inst.mnemonic.startswith("call"))


def is_nop(inst: Instruction) -> bool:
    if re.search(r"\bnop[a-z]*\b", inst.text):
        return True
    if inst.mnemonic == "xchg" and inst.operands.replace(" ", "") in {"%ax,%ax", "%eax,%eax", "%rax,%rax"}:
        return True
    return False


def call_target(inst: Instruction) -> int | None:
    if not inst.mnemonic.startswith("call"):
        return None
    match = TARGET_ADDR_RE.match(inst.operands)
    if not match:
        return None
    try:
        return int(match.group(1), 16)
    except ValueError:
        return None


def looks_like_retpoline_thunk(window: list[Instruction]) -> bool:
    mnemonics = [inst.mnemonic for inst in window]
    if any(mnemonic == "lfence" for mnemonic in mnemonics):
        return True
    if any(mnemonic == "pause" for mnemonic in mnemonics):
        return True
    if any(inst.mnemonic.startswith("push") for inst in window) and any(inst.mnemonic.startswith("ret") for inst in window):
        return True
    if any("jmp" == inst.mnemonic or inst.mnemonic.startswith("jmp") for inst in window) and any(
        inst.mnemonic.startswith("ret") for inst in window
    ):
        return True
    return False


def count_spectre(instructions: list[Instruction]) -> int:
    address_to_index = {inst.address: index for index, inst in enumerate(instructions)}
    lfence_count = sum(1 for inst in instructions if inst.mnemonic == "lfence")
    pause_count = sum(1 for inst in instructions if inst.mnemonic == "pause")
    retpoline_calls = 0
    retpoline_window_indexes: set[int] = set()

    for inst in instructions:
        target = call_target(inst)
        if target is None:
            continue
        target_index = address_to_index.get(target)
        if target_index is None:
            continue
        window = instructions[target_index : target_index + 8]
        if looks_like_retpoline_thunk(window):
            retpoline_calls += 1
            retpoline_window_indexes.update(range(target_index, min(target_index + 8, len(instructions))))

    spectre_nops = sum(1 for index, inst in enumerate(instructions) if index in retpoline_window_indexes and is_nop(inst))
    return lfence_count + pause_count + retpoline_calls + spectre_nops


def analyze_asm(path: Path) -> Metrics:
    if not path.exists():
        return Metrics(None, None, None, None, None, None, None, missing=True)

    instructions = load_instructions(path)
    if not instructions:
        return Metrics(0, 0, 0, 0, 0, 0, 0, empty=True)

    return Metrics(
        total_insns=len(instructions),
        prologue=prologue_size(instructions),
        spills=count_spills(instructions),
        branches=count_branches(instructions),
        calls=count_calls(instructions),
        spectre=count_spectre(instructions),
        nops=sum(1 for inst in instructions if is_nop(inst)),
    )


def format_metric(value: int | None) -> str:
    if value is None:
        return "n/a"
    return str(value)


def safe_ratio(numerator: int | None, denominator: int | None) -> float | None:
    if numerator is None or denominator in (None, 0):
        return None
    return numerator / denominator


def geometric_mean(values: Iterable[float]) -> float | None:
    filtered = [value for value in values if value > 0.0]
    if not filtered:
        return None
    return math.exp(sum(math.log(value) for value in filtered) / len(filtered))


def dominant_reason(kernel: Metrics, llvm: Metrics) -> str:
    deltas = {
        "spectre": (kernel.spectre or 0) - (llvm.spectre or 0),
        "calls": (kernel.calls or 0) - (llvm.calls or 0),
        "nops": (kernel.nops or 0) - (llvm.nops or 0),
        "spills": (kernel.spills or 0) - (llvm.spills or 0),
        "prologue": (kernel.prologue or 0) - (llvm.prologue or 0),
        "branches": (kernel.branches or 0) - (llvm.branches or 0),
    }
    positive = {name: delta for name, delta in deltas.items() if delta > 0}
    if not positive:
        return "little measured structural difference"

    sorted_positive = sorted(positive.items(), key=lambda item: item[1], reverse=True)
    label_map = {
        "spectre": "spectre/retpoline scaffolding",
        "calls": "call-based scaffolding",
        "nops": "nop/alignment padding",
        "spills": "stack spill/fill traffic",
        "prologue": "frame setup/teardown",
        "branches": "branch-heavy lowering",
    }

    leader, leader_value = sorted_positive[0]
    reason = f"kernel adds more {label_map[leader]}"
    if len(sorted_positive) > 1:
        runner_up, runner_up_value = sorted_positive[1]
        if runner_up_value * 4 >= leader_value * 3:
            reason += f" plus {label_map[runner_up]}"
    return reason


def category_ratio_rows(metrics_by_benchmark: dict[str, dict[str, Metrics]]) -> list[tuple[str, str]]:
    categories = [
        ("Total insns", "total_insns"),
        ("Prologue", "prologue"),
        ("Spills", "spills"),
        ("Branches", "branches"),
        ("Calls", "calls"),
        ("Spectre", "spectre"),
        ("NOPs", "nops"),
    ]
    rows: list[tuple[str, str]] = []
    for label, key in categories:
        ratios = []
        for runtime_metrics in metrics_by_benchmark.values():
            llvm = runtime_metrics["llvmbpf"]
            kernel = runtime_metrics["kernel"]
            ratio = safe_ratio(llvm.value_for(key), kernel.value_for(key))
            if ratio is not None:
                ratios.append(ratio)
        avg = geometric_mean(ratios)
        rows.append((label, "n/a" if avg is None else f"{avg:.2f}x"))
    return rows


def measured_extra_summary(metrics_by_benchmark: dict[str, dict[str, Metrics]]) -> list[tuple[str, int]]:
    categories = ["prologue", "spills", "branches", "calls", "spectre", "nops"]
    totals = {category: 0 for category in categories}
    for runtime_metrics in metrics_by_benchmark.values():
        llvm = runtime_metrics["llvmbpf"]
        kernel = runtime_metrics["kernel"]
        for category in categories:
            llvm_value = llvm.value_for(category)
            kernel_value = kernel.value_for(category)
            if llvm_value is None or kernel_value is None:
                continue
            totals[category] += max(kernel_value - llvm_value, 0)
    return sorted(totals.items(), key=lambda item: item[1], reverse=True)


def render_report(metrics_by_benchmark: dict[str, dict[str, Metrics]]) -> str:
    lines: list[str] = []
    lines.append("# JIT Instruction Analysis")
    lines.append("")
    lines.append("| Benchmark | Runtime | Total insns | Prologue | Spills | Branches | Calls | Spectre | NOPs |")
    lines.append("| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |")

    warnings: list[str] = []
    benchmark_deltas: list[tuple[int, float, str, str]] = []

    for benchmark, runtime_metrics in metrics_by_benchmark.items():
        for runtime in RUNTIMES:
            metrics = runtime_metrics[runtime]
            if metrics.missing:
                warnings.append(f"{benchmark} {runtime}: missing asm dump")
            elif metrics.empty:
                warnings.append(f"{benchmark} {runtime}: empty asm dump")
            lines.append(
                f"| {benchmark} | {runtime} | {format_metric(metrics.total_insns)} | "
                f"{format_metric(metrics.prologue)} | {format_metric(metrics.spills)} | "
                f"{format_metric(metrics.branches)} | {format_metric(metrics.calls)} | "
                f"{format_metric(metrics.spectre)} | {format_metric(metrics.nops)} |"
            )

        llvm = runtime_metrics["llvmbpf"]
        kernel = runtime_metrics["kernel"]
        if llvm.total_insns is None or kernel.total_insns is None:
            continue
        delta = kernel.total_insns - llvm.total_insns
        ratio = safe_ratio(kernel.total_insns, llvm.total_insns) or 0.0
        benchmark_deltas.append((delta, ratio, benchmark, dominant_reason(kernel, llvm)))

    lines.append("")
    lines.append("## Summary")
    lines.append("")
    lines.append("### Average llvmbpf/kernel Ratio")
    lines.append("")
    lines.append("| Category | Ratio |")
    lines.append("| --- | ---: |")
    for label, ratio in category_ratio_rows(metrics_by_benchmark):
        lines.append(f"| {label} | {ratio} |")

    lines.append("")
    lines.append("### Where Kernel Adds Instructions")
    lines.append("")
    extra_rows = measured_extra_summary(metrics_by_benchmark)
    extra_total = sum(value for _, value in extra_rows)
    if extra_total == 0:
        lines.append("- No consistent positive category deltas were measured.")
    else:
        overlap_note = "Measured categories overlap, so these shares are directional rather than additive."
        lines.append(f"- {overlap_note}")
        for category, value in extra_rows[:3]:
            share = (value / extra_total) * 100.0
            label = category.capitalize()
            lines.append(f"- {label}: +{value} instructions ({share:.1f}% of measured positive deltas)")

    if benchmark_deltas:
        benchmark_deltas.sort(key=lambda item: item[0], reverse=True)
        biggest = benchmark_deltas[0]
        smallest = min(benchmark_deltas, key=lambda item: abs(item[0]))
        lines.append("")
        lines.append("### Biggest/Smallest Gaps")
        lines.append("")
        lines.append(
            f"- Biggest kernel inflation: `{biggest[2]}` with +{biggest[0]} instructions "
            f"({biggest[1]:.2f}x kernel/llvmbpf), mainly because {biggest[3]}."
        )
        lines.append(
            f"- Closest match: `{smallest[2]}` with {smallest[0]:+d} instructions "
            f"({smallest[1]:.2f}x kernel/llvmbpf), indicating {smallest[3]}."
        )

    if warnings:
        lines.append("")
        lines.append("### Warnings")
        lines.append("")
        for warning in warnings:
            lines.append(f"- {warning}")

    lines.append("")
    return "\n".join(lines)


def main() -> int:
    args = parse_args()
    suite = load_suite(CONFIG_PATH)
    dumps_dir = Path(args.dumps_dir).resolve()
    metrics_by_benchmark: dict[str, dict[str, Metrics]] = {}

    for benchmark in suite.benchmarks.values():
        runtime_metrics: dict[str, Metrics] = {}
        for runtime in RUNTIMES:
            asm_path = dumps_dir / f"{benchmark.name}.{runtime}.asm"
            runtime_metrics[runtime] = analyze_asm(asm_path)
        metrics_by_benchmark[benchmark.name] = runtime_metrics

    report = render_report(metrics_by_benchmark)
    print(report, end="")

    if args.output:
        output_path = Path(args.output).resolve()
        output_path.parent.mkdir(parents=True, exist_ok=True)
        output_path.write_text(report)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
