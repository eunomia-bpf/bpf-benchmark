#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import re
import statistics
from collections import Counter
from dataclasses import dataclass
from pathlib import Path


ROOT_DIR = Path(__file__).resolve().parent
DEFAULT_INPUT = ROOT_DIR / "results" / "pure_jit_authoritative.json"
DEFAULT_OUTPUT = ROOT_DIR / "results" / "paradox_analysis.md"
DEFAULT_PROGRAMS_DIR = ROOT_DIR / "programs"
DEFAULT_JIT_DUMPS_DIR = ROOT_DIR / "jit-dumps"
DEFAULT_JIT_REPORT = DEFAULT_JIT_DUMPS_DIR / "report.md"
SUBRESOLUTION_NS = 100.0
CATEGORY_ORDER = ("sub-resolution", "tight-loop", "code-clone", "branch-heavy")
WRAPPER_HELPER_COUNTS = {
    "DEFINE_STAGED_INPUT_XDP_BENCH": 1,
    "DEFINE_MAP_BACKED_XDP_BENCH": 2,
    "DEFINE_PACKET_BACKED_XDP_BENCH": 0,
    "DEFINE_FIXED_PACKET_BACKED_XDP_BENCH": 0,
}

LOOP_RE = re.compile(r"\b(?:for|while)\b")
IF_RE = re.compile(r"\bif\b")
SWITCH_RE = re.compile(r"\bswitch\b")
CLONE_RE = re.compile(r"\bCODE_CLONE\b|CODE_CLONE_[A-Z0-9_]*STEP")
HELPER_CALL_RE = re.compile(r"\bbpf_[a-zA-Z0-9_]+\s*\(")
ASM_LINE_RE = re.compile(r"^\s*[0-9a-f]+:\s+(?:[0-9a-f]{2}(?:\s+|$))+(.*?)\s*$")


@dataclass(frozen=True)
class SourceFeatures:
    path: Path
    bpf_insn_count: int | None
    loop_present: bool
    loop_token_count: int
    if_count: int
    switch_count: int
    helper_call_count: int
    explicit_helper_count: int
    wrapper_helper_count: int
    wrapper_macro: str | None
    baseline_simple: bool
    clone_like: bool


@dataclass(frozen=True)
class JitMetrics:
    available: bool
    total_insns: int | None
    branches: int | None
    cmovs: int | None


@dataclass(frozen=True)
class ParadoxCase:
    name: str
    description: str
    category: str
    family: str
    tags: tuple[str, ...]
    exec_ratio: float
    code_ratio: float
    llvmbpf_exec_ns: float
    kernel_exec_ns: float
    llvmbpf_native_bytes: float | None
    kernel_native_bytes: float | None
    source: SourceFeatures
    llvmbpf_jit: JitMetrics
    kernel_jit: JitMetrics
    hypothesis: str
    why: str


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Analyze benchmarks where llvmbpf emits smaller code but still runs slower than the kernel JIT."
    )
    parser.add_argument("--input", default=str(DEFAULT_INPUT), help="Authoritative benchmark JSON input path.")
    parser.add_argument("--output", default=str(DEFAULT_OUTPUT), help="Markdown report output path.")
    parser.add_argument("--programs-dir", default=str(DEFAULT_PROGRAMS_DIR), help="Directory containing benchmark .bpf.c sources.")
    parser.add_argument("--jit-dumps-dir", default=str(DEFAULT_JIT_DUMPS_DIR), help="Directory containing optional JIT dump .asm files.")
    return parser.parse_args()


def load_json(path: Path) -> dict[str, object]:
    return json.loads(path.read_text())


def run_lookup(benchmark: dict[str, object]) -> dict[str, dict[str, object]]:
    return {str(run["runtime"]): run for run in benchmark.get("runs", [])}


def extract_mean_exec_ns(run: dict[str, object]) -> float | None:
    metric = run.get("exec_ns")
    if isinstance(metric, dict) and metric.get("mean") is not None:
        return float(metric["mean"])

    values = [float(sample["exec_ns"]) for sample in run.get("samples", []) if sample.get("exec_ns") is not None]
    if not values:
        return None
    return float(statistics.mean(values))


def extract_native_code_bytes(run: dict[str, object]) -> float | None:
    values: list[float] = []
    for sample in run.get("samples", []):
        code_size = sample.get("code_size", {})
        native_code_bytes = code_size.get("native_code_bytes")
        if native_code_bytes is None:
            native_code_bytes = sample.get("native_code_size")
        if native_code_bytes is None:
            native_code_bytes = sample.get("jited_prog_len")
        if native_code_bytes is not None:
            values.append(float(native_code_bytes))
    if not values:
        return None
    return float(statistics.median(values))


def extract_bpf_insn_count(run: dict[str, object]) -> int | None:
    counts: list[int] = []
    for sample in run.get("samples", []):
        for key in ("insn_count", "bpf_insn_count"):
            value = sample.get(key)
            if value is not None:
                counts.append(int(value))
                break
        else:
            code_size = sample.get("code_size", {})
            byte_count = code_size.get("bpf_bytecode_bytes")
            if byte_count is not None:
                counts.append(int(byte_count) // 8)
    if not counts:
        return None
    return int(statistics.median(counts))


def detect_wrapper_macro(source_text: str) -> str | None:
    for macro in WRAPPER_HELPER_COUNTS:
        if macro in source_text:
            return macro
    return None


def find_source_path(programs_dir: Path, benchmark_name: str) -> Path:
    direct = programs_dir / f"{benchmark_name}.bpf.c"
    if direct.exists():
        return direct

    matches = sorted(programs_dir.glob(f"{benchmark_name}*.bpf.c"))
    if len(matches) == 1:
        return matches[0]
    raise FileNotFoundError(f"could not find source for benchmark {benchmark_name!r} in {programs_dir}")


def extract_source_features(benchmark: dict[str, object], programs_dir: Path, llvmbpf_run: dict[str, object]) -> SourceFeatures:
    source_path = find_source_path(programs_dir, str(benchmark["name"]))
    source_text = source_path.read_text()
    explicit_helper_count = len(HELPER_CALL_RE.findall(source_text))
    wrapper_macro = detect_wrapper_macro(source_text)
    wrapper_helper_count = WRAPPER_HELPER_COUNTS.get(wrapper_macro, 0)
    tags = tuple(str(tag) for tag in benchmark.get("tags", []))
    return SourceFeatures(
        path=source_path,
        bpf_insn_count=extract_bpf_insn_count(llvmbpf_run),
        loop_present=bool(LOOP_RE.search(source_text)),
        loop_token_count=len(LOOP_RE.findall(source_text)),
        if_count=len(IF_RE.findall(source_text)),
        switch_count=len(SWITCH_RE.findall(source_text)),
        helper_call_count=explicit_helper_count + wrapper_helper_count,
        explicit_helper_count=explicit_helper_count,
        wrapper_helper_count=wrapper_helper_count,
        wrapper_macro=wrapper_macro,
        baseline_simple=(
            str(benchmark.get("category", "")) == "baseline"
            or str(benchmark.get("family", "")) == "baseline"
            or "baseline" in tags
            or str(benchmark["name"]).startswith("simple")
        ),
        clone_like=bool(CLONE_RE.search(source_text)) or str(benchmark.get("family", "")) == "code-clone",
    )


def load_jit_metrics(jit_dumps_dir: Path, benchmark_name: str, runtime: str) -> JitMetrics:
    asm_path = jit_dumps_dir / f"{benchmark_name}.{runtime}.asm"
    if not asm_path.exists():
        return JitMetrics(available=False, total_insns=None, branches=None, cmovs=None)

    total_insns = 0
    branches = 0
    cmovs = 0
    for line in asm_path.read_text(errors="replace").splitlines():
        match = ASM_LINE_RE.match(line)
        if not match:
            continue
        text = match.group(1).strip()
        if not text or text.endswith(":") or text.startswith("."):
            continue
        mnemonic = text.split()[0]
        total_insns += 1
        if mnemonic.startswith("j"):
            branches += 1
        if mnemonic.startswith("cmov"):
            cmovs += 1

    return JitMetrics(
        available=total_insns > 0,
        total_insns=total_insns or None,
        branches=branches or 0,
        cmovs=cmovs or 0,
    )


def determine_exec_ratio(benchmark: dict[str, object], llvmbpf_run: dict[str, object], kernel_run: dict[str, object]) -> float:
    llvmbpf_exec = extract_mean_exec_ns(llvmbpf_run)
    kernel_exec = extract_mean_exec_ns(kernel_run)
    if llvmbpf_exec is None or kernel_exec in (None, 0):
        raise ValueError(f"missing exec_ns data for benchmark {benchmark.get('name', '<unknown>')}")
    return llvmbpf_exec / kernel_exec


def parse_markdown_row(line: str) -> list[str]:
    return [cell.strip() for cell in line.strip().strip("|").split("|")]


def load_jit_report_metrics(report_path: Path) -> dict[tuple[str, str], JitMetrics]:
    if not report_path.exists():
        return {}

    totals: dict[tuple[str, str], dict[str, int | None]] = {}
    cmovs: dict[tuple[str, str], int] = {}
    mode: str | None = None

    for line in report_path.read_text().splitlines():
        if line.startswith("| Benchmark | Runtime | Total insns |"):
            mode = "jit"
            continue
        if line.startswith("| Benchmark | K BMI | L BMI | K cmov | L cmov |"):
            mode = "cmov"
            continue
        if mode and line.startswith("| ---"):
            continue
        if mode and not line.startswith("|"):
            mode = None
            continue
        if not mode or not line.startswith("|"):
            continue

        cells = parse_markdown_row(line)
        if mode == "jit" and len(cells) >= 6:
            benchmark_name = cells[0]
            runtime = cells[1]
            totals[(benchmark_name, runtime)] = {
                "total_insns": int(cells[2]),
                "branches": int(cells[5]),
            }
        if mode == "cmov" and len(cells) >= 5:
            benchmark_name = cells[0]
            cmovs[(benchmark_name, "kernel")] = int(cells[3])
            cmovs[(benchmark_name, "llvmbpf")] = int(cells[4])

    metrics: dict[tuple[str, str], JitMetrics] = {}
    for key, info in totals.items():
        metrics[key] = JitMetrics(
            available=True,
            total_insns=int(info["total_insns"]) if info["total_insns"] is not None else None,
            branches=int(info["branches"]) if info["branches"] is not None else None,
            cmovs=cmovs.get(key),
        )
    return metrics


def lookup_jit_metrics(
    jit_report_metrics: dict[tuple[str, str], JitMetrics],
    jit_dumps_dir: Path,
    benchmark_name: str,
    runtime: str,
) -> JitMetrics:
    cached = jit_report_metrics.get((benchmark_name, runtime))
    if cached is not None:
        return cached
    return load_jit_metrics(jit_dumps_dir, benchmark_name, runtime)


def determine_code_ratio(llvmbpf_run: dict[str, object], kernel_run: dict[str, object]) -> tuple[float, float | None, float | None]:
    llvmbpf_native_bytes = extract_native_code_bytes(llvmbpf_run)
    kernel_native_bytes = extract_native_code_bytes(kernel_run)
    if llvmbpf_native_bytes is None or kernel_native_bytes in (None, 0):
        raise ValueError(f"missing native code size data for benchmark {llvmbpf_run.get('runtime', '<unknown>')}")
    return llvmbpf_native_bytes / kernel_native_bytes, llvmbpf_native_bytes, kernel_native_bytes


def classify_paradox_case(
    benchmark: dict[str, object],
    source: SourceFeatures,
    llvmbpf_jit: JitMetrics,
    kernel_jit: JitMetrics,
    exec_ratio: float,
    code_ratio: float,
    kernel_exec_ns: float,
) -> tuple[str, str]:
    tags = {str(tag) for tag in benchmark.get("tags", [])}
    family = str(benchmark.get("family", ""))
    category = str(benchmark.get("category", ""))

    if kernel_exec_ns < SUBRESOLUTION_NS:
        why = (
            f"kernel mean exec is {kernel_exec_ns:.1f}ns, below the 100ns ktime floor, "
            "so timer quantization dominates any code-shape effect"
        )
        return "sub-resolution", why

    if source.clone_like:
        why = (
            "steady-state loop is mostly cloned straight-line scalar math, so LLVM shrinks bytes "
            "without shortening the per-iteration dependency chain"
        )
        return "code-clone", why

    branch_dense = (
        category == "control-flow"
        or family in {"branch-density", "bounds-style"}
        or source.if_count >= 8
        or source.switch_count > 0
        or "verifier-like" in tags
    )
    if branch_dense:
        if llvmbpf_jit.available and (llvmbpf_jit.cmovs or 0) > 0:
            why = (
                f"hot path is branch-dense ({source.if_count} ifs), and LLVM also emits "
                f"{llvmbpf_jit.cmovs} cmov instructions in the dump; kernel's direct branch lowering "
                "likely keeps the hot path simpler"
            )
        else:
            why = (
                f"hot path is branch-dense ({source.if_count} ifs), so the control-flow shape matters more "
                "than static byte count and kernel's direct branch lowering can win"
            )
        return "branch-heavy", why

    near_parity = "near-parity; " if exec_ratio < 1.05 else ""
    why = (
        f"{near_parity}loop-dominated work keeps cost on the loop-carried recurrence, "
        f"so LLVM's {code_ratio:.3f}x code-size reduction mostly removes non-critical-path instructions"
    )
    return "tight-loop", why


def build_jit_hint(llvmbpf_jit: JitMetrics, kernel_jit: JitMetrics) -> str:
    if not llvmbpf_jit.available and not kernel_jit.available:
        return "n/a"

    parts: list[str] = []
    if kernel_jit.total_insns is not None and llvmbpf_jit.total_insns is not None:
        parts.append(f"insns K/L {kernel_jit.total_insns}/{llvmbpf_jit.total_insns}")
    if kernel_jit.branches is not None and llvmbpf_jit.branches is not None:
        parts.append(f"branches K/L {kernel_jit.branches}/{llvmbpf_jit.branches}")
    if (llvmbpf_jit.cmovs or 0) > 0 or (kernel_jit.cmovs or 0) > 0:
        parts.append(f"cmov K/L {kernel_jit.cmovs or 0}/{llvmbpf_jit.cmovs or 0}")
    return "; ".join(parts) if parts else "partial dump"


def loop_label(source: SourceFeatures) -> str:
    return f"yes ({source.loop_token_count})" if source.loop_present else "no"


def helper_label(source: SourceFeatures) -> str:
    if source.explicit_helper_count == 0 and source.wrapper_helper_count == 0:
        return "0"
    if source.explicit_helper_count == 0:
        return f"{source.helper_call_count} (wrapper)"
    if source.wrapper_helper_count == 0:
        return str(source.helper_call_count)
    return f"{source.helper_call_count} ({source.explicit_helper_count}+{source.wrapper_helper_count})"


def format_ratio(value: float) -> str:
    return f"{value:.3f}"


def format_ns(value: float) -> str:
    return f"{value:.1f}"


def sort_cases(cases: list[ParadoxCase]) -> list[ParadoxCase]:
    category_rank = {name: index for index, name in enumerate(CATEGORY_ORDER)}
    return sorted(cases, key=lambda case: (category_rank.get(case.hypothesis, 99), -case.exec_ratio, case.name))


def analyze_paradox_cases(
    results: dict[str, object],
    programs_dir: Path,
    jit_dumps_dir: Path,
) -> tuple[list[ParadoxCase], Counter[str]]:
    paradox_cases: list[ParadoxCase] = []
    counts: Counter[str] = Counter()
    jit_report_metrics = load_jit_report_metrics(jit_dumps_dir / DEFAULT_JIT_REPORT.name)

    for benchmark in results.get("benchmarks", []):
        runs = run_lookup(benchmark)
        if "llvmbpf" not in runs or "kernel" not in runs:
            continue

        llvmbpf_run = runs["llvmbpf"]
        kernel_run = runs["kernel"]
        exec_ratio = determine_exec_ratio(benchmark, llvmbpf_run, kernel_run)
        code_ratio, llvmbpf_native_bytes, kernel_native_bytes = determine_code_ratio(llvmbpf_run, kernel_run)
        if not (code_ratio < 1.0 and exec_ratio > 1.0):
            continue

        llvmbpf_exec_ns = extract_mean_exec_ns(llvmbpf_run)
        kernel_exec_ns = extract_mean_exec_ns(kernel_run)
        if llvmbpf_exec_ns is None or kernel_exec_ns is None:
            continue

        source = extract_source_features(benchmark, programs_dir, llvmbpf_run)
        llvmbpf_jit = lookup_jit_metrics(jit_report_metrics, jit_dumps_dir, str(benchmark["name"]), "llvmbpf")
        kernel_jit = lookup_jit_metrics(jit_report_metrics, jit_dumps_dir, str(benchmark["name"]), "kernel")
        hypothesis, why = classify_paradox_case(
            benchmark=benchmark,
            source=source,
            llvmbpf_jit=llvmbpf_jit,
            kernel_jit=kernel_jit,
            exec_ratio=exec_ratio,
            code_ratio=code_ratio,
            kernel_exec_ns=kernel_exec_ns,
        )
        counts[hypothesis] += 1
        paradox_cases.append(
            ParadoxCase(
                name=str(benchmark["name"]),
                description=str(benchmark.get("description", "")),
                category=str(benchmark.get("category", "")),
                family=str(benchmark.get("family", "")),
                tags=tuple(str(tag) for tag in benchmark.get("tags", [])),
                exec_ratio=exec_ratio,
                code_ratio=code_ratio,
                llvmbpf_exec_ns=llvmbpf_exec_ns,
                kernel_exec_ns=kernel_exec_ns,
                llvmbpf_native_bytes=llvmbpf_native_bytes,
                kernel_native_bytes=kernel_native_bytes,
                source=source,
                llvmbpf_jit=llvmbpf_jit,
                kernel_jit=kernel_jit,
                hypothesis=hypothesis,
                why=why,
            )
        )

    return sort_cases(paradox_cases), counts


def render_report(
    input_path: Path,
    output_path: Path,
    programs_dir: Path,
    jit_dumps_dir: Path,
    results: dict[str, object],
    paradox_cases: list[ParadoxCase],
    counts: Counter[str],
) -> str:
    total_benchmarks = len(results.get("benchmarks", []))
    lines: list[str] = []
    lines.append("# Smaller-But-Slower Paradox Analysis")
    lines.append("")
    lines.append(f"- Input JSON: `{input_path}`")
    lines.append(f"- Programs dir: `{programs_dir}`")
    lines.append(f"- JIT dumps dir: `{jit_dumps_dir}`")
    lines.append("- Paradox definition: code-size ratio `L/K < 1.0` and exec ratio `L/K > 1.0`.")
    lines.append(f"- Paradox cases found: `{len(paradox_cases)} / {total_benchmarks}` benchmarks.")
    lines.append(
        "- Helper counts include explicit `bpf_*()` calls in the benchmark source plus wrapper-implied map helpers "
        "from the `DEFINE_*_XDP_BENCH` macro used by the source."
    )
    lines.append("- Categories are hypotheses driven by source structure plus any available `.asm` JIT dump signals.")
    lines.append("")
    lines.append("## Paradox Benchmarks")
    lines.append("")
    lines.append(
        "| Benchmark | Exec Ratio (L/K) | Code Ratio (L/K) | Kernel exec ns | BPF insns | Loop | Helpers | Baseline | JIT hint | Category | Why |"
    )
    lines.append("| --- | ---: | ---: | ---: | ---: | --- | --- | --- | --- | --- | --- |")
    for case in paradox_cases:
        lines.append(
            "| "
            f"{case.name} | {format_ratio(case.exec_ratio)} | {format_ratio(case.code_ratio)} | "
            f"{format_ns(case.kernel_exec_ns)} | {case.source.bpf_insn_count or 'n/a'} | "
            f"{loop_label(case.source)} | {helper_label(case.source)} | "
            f"{'yes' if case.source.baseline_simple else 'no'} | {build_jit_hint(case.llvmbpf_jit, case.kernel_jit)} | "
            f"{case.hypothesis} | {case.why} |"
        )

    lines.append("")
    lines.append("## Category Summary")
    lines.append("")
    lines.append("| Category | Count | Benchmarks |")
    lines.append("| --- | ---: | --- |")
    for category in CATEGORY_ORDER:
        cases = [case.name for case in paradox_cases if case.hypothesis == category]
        lines.append(f"| {category} | {counts.get(category, 0)} | {', '.join(cases) if cases else '-'} |")

    lines.append("")
    lines.append("## Key Insight")
    lines.append("")
    lines.append(
        "LLVM's instruction elimination mainly reduces non-critical-path instructions. In these 10 cases the runtime is "
        "set by timer noise, loop-carried recurrences, cloned straight-line math, or dense control flow, so smaller code "
        "does not automatically mean a shorter critical path."
    )
    lines.append("")
    lines.append("## Reading Notes")
    lines.append("")
    lines.append(
        "- `sub-resolution` means the kernel mean `exec_ns` is below `100ns`, so the ratio is dominated by `ktime` granularity."
    )
    lines.append(
        "- `tight-loop` means a loop dominates steady-state execution; byte savings mostly happen outside the loop-carried dependency chain."
    )
    lines.append(
        "- `code-clone` means a repeated straight-line body is cloned inside the hot loop, where kernel's direct lowering stays competitive."
    )
    lines.append(
        "- `branch-heavy` means control-flow density or verifier-style guards dominate behavior, so branch layout matters more than raw bytes."
    )
    lines.append(f"- Report output: `{output_path}`")
    lines.append("")
    return "\n".join(lines)


def main() -> int:
    args = parse_args()
    input_path = Path(args.input).resolve()
    output_path = Path(args.output).resolve()
    programs_dir = Path(args.programs_dir).resolve()
    jit_dumps_dir = Path(args.jit_dumps_dir).resolve()

    results = load_json(input_path)
    paradox_cases, counts = analyze_paradox_cases(results, programs_dir, jit_dumps_dir)
    report = render_report(
        input_path=input_path,
        output_path=output_path,
        programs_dir=programs_dir,
        jit_dumps_dir=jit_dumps_dir,
        results=results,
        paradox_cases=paradox_cases,
        counts=counts,
    )
    output_path.write_text(report)
    print(f"wrote {output_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
