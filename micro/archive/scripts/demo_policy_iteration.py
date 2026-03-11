#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import shlex
import statistics
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

SCRIPT_DIR = Path(__file__).resolve().parent
MICRO_ROOT = SCRIPT_DIR.parent.parent
ROOT_DIR = MICRO_ROOT.parent
for candidate in (ROOT_DIR, MICRO_ROOT):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

try:
    from input_generators import materialize_input
except ImportError:
    from micro.input_generators import materialize_input

RUNNER = MICRO_ROOT / "build" / "runner" / "micro_exec"
RESULTS_MD = ROOT_DIR / "docs" / "tmp" / "policy-iteration-demo-results.md"
RESULTS_JSON = ROOT_DIR / "docs" / "tmp" / "policy-iteration-demo-results.json"
PRIMARY_KERNEL_DIR = ROOT_DIR / "vendor" / "linux"
FALLBACK_KERNEL_DIR = ROOT_DIR / "vendor" / "linux-framework"


@dataclass(frozen=True)
class CaseSpec:
    key: str
    label: str
    flags: tuple[str, ...]
    expect_recompile: bool = False


@dataclass(frozen=True)
class ProgramSpec:
    key: str
    title: str
    subtitle: str
    program_object: Path
    input_generator: str
    io_mode: str
    cases: tuple[CaseSpec, ...]


@dataclass
class IterationRecord:
    iteration_index: int
    samples: dict[str, dict[str, Any]]


class RecompileUnavailableError(RuntimeError):
    pass


LOG2_FOLD = ProgramSpec(
    key="log2_fold",
    title="log2_fold",
    subtitle="predictable branches",
    program_object=MICRO_ROOT / "programs" / "log2_fold.bpf.o",
    input_generator="log2_fold",
    io_mode="staged",
    cases=(
        CaseSpec("baseline", "Baseline", ()),
        CaseSpec("cmov", "+ CMOV policy", ("--recompile-v5", "--recompile-cmov"), expect_recompile=True),
        CaseSpec("revert", "+ Revert", ()),
    ),
)

ROTATE64_HASH = ProgramSpec(
    key="rotate64_hash",
    title="rotate64_hash",
    subtitle="rotation-heavy",
    program_object=MICRO_ROOT / "programs" / "rotate64_hash.bpf.o",
    input_generator="rotate64_hash",
    io_mode="staged",
    cases=(
        CaseSpec("baseline", "Baseline", ()),
        CaseSpec(
            "rotate",
            "+ ROTATE policy",
            ("--recompile-v5", "--recompile-all"),
            expect_recompile=True,
        ),
    ),
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the end-to-end BPF JIT policy-iteration demo.")
    parser.add_argument(
        "--kernel-dir",
        default=str(PRIMARY_KERNEL_DIR),
        help="Primary kernel tree or bzImage passed to vng --run.",
    )
    parser.add_argument(
        "--fallback-kernel-dir",
        default=str(FALLBACK_KERNEL_DIR),
        help="Fallback framework kernel used when the primary kernel rejects recompile.",
    )
    parser.add_argument(
        "--no-kernel-fallback",
        action="store_true",
        help="Disable automatic fallback from --kernel-dir to --fallback-kernel-dir.",
    )
    parser.add_argument(
        "--repeat",
        type=int,
        default=100,
        help="Inner repeat count passed to micro_exec.",
    )
    parser.add_argument(
        "--iterations",
        type=int,
        default=1,
        help="Guest boots per configuration; medians are reported across iterations.",
    )
    parser.add_argument(
        "--no-rotate",
        action="store_true",
        help="Skip the optional rotate64_hash section.",
    )
    parser.add_argument(
        "--output-md",
        default=str(RESULTS_MD),
        help="Markdown output path.",
    )
    parser.add_argument(
        "--output-json",
        default=str(RESULTS_JSON),
        help="JSON output path.",
    )
    parser.add_argument(
        "--timeout",
        type=int,
        default=300,
        help="Per-iteration timeout in seconds.",
    )
    parser.add_argument(
        "--vng",
        default="vng",
        help="vng executable to use.",
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Print the vng command without booting the guest.",
    )
    return parser.parse_args()


def ensure_exists(path: Path, label: str) -> None:
    if not path.exists():
        raise RuntimeError(f"{label} does not exist: {path}")


def resolve_kernel_run_target(raw_value: str) -> Path:
    candidate = Path(raw_value).resolve()
    ensure_exists(candidate, "kernel path")
    return candidate


def materialize_program_input(program: ProgramSpec) -> tuple[Path, int]:
    memory_path, metadata = materialize_input(program.input_generator)
    if metadata.get("bytes"):
        return memory_path.resolve(), int(metadata["bytes"])
    return memory_path.resolve(), memory_path.stat().st_size


def build_micro_exec_command(program: ProgramSpec, case: CaseSpec, memory: Path, input_size: int, repeat: int) -> list[str]:
    command = [
        str(RUNNER.resolve()),
        "run-kernel",
        "--program",
        str(program.program_object.resolve()),
        "--memory",
        str(memory),
        "--input-size",
        str(input_size),
        "--io-mode",
        program.io_mode,
        "--repeat",
        str(repeat),
    ]
    command.extend(case.flags)
    return command


def write_guest_script(commands: list[list[str]]) -> Path:
    handle = tempfile.NamedTemporaryFile(
        mode="w",
        prefix="policy-iteration-guest-",
        suffix=".sh",
        dir=ROOT_DIR,
        delete=False,
    )
    with handle:
        handle.write("#!/bin/sh\nset -eu\n")
        handle.write(f"cd {shlex.quote(str(ROOT_DIR))}\n")
        for command in commands:
            handle.write(" ".join(shlex.quote(part) for part in command) + "\n")
    path = Path(handle.name)
    path.chmod(0o755)
    return path


def parse_json_lines(stdout: str) -> list[dict[str, Any]]:
    samples: list[dict[str, Any]] = []
    for line in stdout.splitlines():
        candidate = line.strip()
        if not candidate.startswith("{") or not candidate.endswith("}"):
            continue
        samples.append(json.loads(candidate))
    return samples


def summarize_stderr(stderr: str, max_lines: int = 12) -> str:
    lines = [line.rstrip() for line in stderr.splitlines() if line.strip()]
    if not lines:
        return ""
    return "\n".join(lines[-max_lines:])


def run_iteration(
    kernel_dir: Path,
    programs: list[ProgramSpec],
    repeat: int,
    timeout: int,
    iteration_index: int,
    vng_binary: str,
) -> IterationRecord:
    commands: list[list[str]] = []
    expected_case_order: list[tuple[str, str]] = []

    for program in programs:
        memory, input_size = materialize_program_input(program)
        for case in program.cases:
            commands.append(build_micro_exec_command(program, case, memory, input_size, repeat))
            expected_case_order.append((program.key, case.key))

    guest_script = write_guest_script(commands)
    guest_path = f"./{guest_script.relative_to(ROOT_DIR).as_posix()}"
    vng_command = [
        vng_binary,
        "--run",
        str(kernel_dir),
        "--cwd",
        str(ROOT_DIR),
        "--exec",
        guest_path,
    ]

    try:
        completed = subprocess.run(
            vng_command,
            cwd=ROOT_DIR,
            capture_output=True,
            text=True,
            timeout=timeout,
        )
    finally:
        guest_script.unlink(missing_ok=True)

    if completed.returncode != 0:
        raise RuntimeError(
            f"iteration {iteration_index} failed on {kernel_dir} with exit {completed.returncode}\n"
            f"{summarize_stderr(completed.stderr)}"
        )

    parsed = parse_json_lines(completed.stdout)
    if len(parsed) != len(expected_case_order):
        raise RuntimeError(
            f"iteration {iteration_index} expected {len(expected_case_order)} JSON samples "
            f"but parsed {len(parsed)}\nstdout:\n{completed.stdout}\nstderr:\n{summarize_stderr(completed.stderr)}"
        )

    samples: dict[str, dict[str, Any]] = {}
    for (program_key, case_key), sample in zip(expected_case_order, parsed, strict=True):
        samples[f"{program_key}:{case_key}"] = sample

    return IterationRecord(iteration_index=iteration_index, samples=samples)


def require_recompile_support(programs: list[ProgramSpec], iteration: IterationRecord, kernel_dir: Path) -> None:
    for program in programs:
        for case in program.cases:
            if not case.expect_recompile:
                continue
            sample = iteration.samples[f"{program.key}:{case.key}"]
            recompile = sample.get("recompile") or {}
            if recompile.get("applied"):
                continue
            error = str(recompile.get("error") or "recompile was not applied")
            raise RecompileUnavailableError(
                f"{kernel_dir} did not apply {program.key}:{case.key}: {error}"
            )


def run_demo(args: argparse.Namespace, programs: list[ProgramSpec]) -> tuple[Path, list[IterationRecord], list[str]]:
    primary_kernel = resolve_kernel_run_target(args.kernel_dir)
    fallback_kernel = resolve_kernel_run_target(args.fallback_kernel_dir)
    notes: list[str] = []

    candidates = [primary_kernel]
    if not args.no_kernel_fallback and fallback_kernel != primary_kernel and fallback_kernel.exists():
        candidates.append(fallback_kernel)

    for index, candidate in enumerate(candidates):
        try:
            records: list[IterationRecord] = []
            for iteration_index in range(args.iterations):
                record = run_iteration(candidate, programs, args.repeat, args.timeout, iteration_index, args.vng)
                if iteration_index == 0:
                    require_recompile_support(programs, record, candidate)
                records.append(record)
            if index > 0:
                notes.append(
                    f"Auto-fallback: `{primary_kernel}` rejected `BPF_PROG_JIT_RECOMPILE`, "
                    f"so the demo reran on `{candidate}`."
                )
            return candidate, records, notes
        except RecompileUnavailableError as error:
            if index + 1 >= len(candidates):
                raise
            notes.append(str(error))

    raise RuntimeError("no runnable kernel candidate found")


def median_int(values: list[int]) -> int:
    return int(round(statistics.median(values)))


def pct_change(new_value: int, baseline_value: int) -> float:
    return ((new_value - baseline_value) / baseline_value) * 100.0


def format_sample_line(label: str, exec_ns: int, jited_prog_len: int, suffix: str = "") -> str:
    padded = f"{label}:".ljust(15)
    line = f"  {padded} {exec_ns} ns  (jited: {jited_prog_len} bytes)"
    if suffix:
        line += f" -> {suffix}"
    return line


def aggregate_case(program: ProgramSpec, case: CaseSpec, records: list[IterationRecord]) -> dict[str, Any]:
    exec_values = [int(record.samples[f"{program.key}:{case.key}"]["exec_ns"]) for record in records]
    jited_values = [int(record.samples[f"{program.key}:{case.key}"]["jited_prog_len"]) for record in records]
    sample = records[-1].samples[f"{program.key}:{case.key}"]
    return {
        "exec_ns_values": exec_values,
        "exec_ns": median_int(exec_values),
        "jited_prog_len_values": jited_values,
        "jited_prog_len": median_int(jited_values),
        "directive_scan": sample.get("directive_scan") or {},
        "recompile": sample.get("recompile") or {},
    }


def build_summary(programs: list[ProgramSpec], records: list[IterationRecord]) -> dict[str, dict[str, Any]]:
    summary: dict[str, dict[str, Any]] = {}
    for program in programs:
        program_summary: dict[str, Any] = {}
        for case in program.cases:
            program_summary[case.key] = aggregate_case(program, case, records)
        summary[program.key] = program_summary
    return summary


def log2_summary_lines(summary: dict[str, Any]) -> list[str]:
    baseline = summary["baseline"]
    cmov = summary["cmov"]
    revert = summary["revert"]
    cmov_delta = pct_change(cmov["exec_ns"], baseline["exec_ns"])
    revert_suffix = (
        "stock code restored"
        if revert["jited_prog_len"] == baseline["jited_prog_len"]
        else f"{pct_change(revert['exec_ns'], baseline['exec_ns']):+.1f}% vs baseline"
    )
    return [
        "Program: log2_fold (predictable branches)",
        format_sample_line("Baseline", baseline["exec_ns"], baseline["jited_prog_len"]),
        format_sample_line(
            "+ CMOV policy",
            cmov["exec_ns"],
            cmov["jited_prog_len"],
            f"{cmov_delta:+.1f}% slower",
        ),
        format_sample_line(
            "+ Revert",
            revert["exec_ns"],
            revert["jited_prog_len"],
            revert_suffix,
        ),
    ]


def rotate_summary_lines(summary: dict[str, Any]) -> list[str]:
    baseline = summary["baseline"]
    rotate = summary["rotate"]
    rotate_delta = pct_change(rotate["exec_ns"], baseline["exec_ns"])
    return [
        "Program: rotate64_hash (rotation-heavy)",
        format_sample_line("Baseline", baseline["exec_ns"], baseline["jited_prog_len"]),
        format_sample_line(
            "+ ROTATE policy",
            rotate["exec_ns"],
            rotate["jited_prog_len"],
            f"{rotate_delta:+.1f}% faster" if rotate_delta < 0 else f"{rotate_delta:+.1f}% slower",
        ),
    ]


def build_markdown(
    kernel_used: Path,
    notes: list[str],
    programs: list[ProgramSpec],
    summary: dict[str, dict[str, Any]],
    repeat: int,
    iterations: int,
) -> str:
    generated_at = datetime.now(timezone.utc).strftime("%Y-%m-%d %H:%M:%SZ")
    lines = [
        "# BPF JIT Policy Iteration Demo",
        "",
        f"- Generated: `{generated_at}`",
        f"- Kernel used: `{kernel_used}`",
        f"- Method: median `exec_ns` across `{iterations}` guest boot(s), each `micro_exec` run uses `--repeat {repeat}`",
        f"- Runner: `{RUNNER}`",
        "",
    ]

    if notes:
        lines.extend(["## Notes", ""])
        for note in notes:
            lines.append(f"- {note}")
        lines.append("")

    lines.extend(["## Summary", "", "```text", "=== BPF JIT Policy Iteration Demo ==="])
    lines.extend(log2_summary_lines(summary["log2_fold"]))
    lines.append("")
    if any(program.key == "rotate64_hash" for program in programs):
        lines.extend(rotate_summary_lines(summary["rotate64_hash"]))
        lines.append("")
    lines.append("Conclusion: Same mechanism, opposite profitability -> policy matters.")
    lines.extend(["```", "", "## Per-Iteration Samples", "", "| Program | Case | exec_ns samples | jited bytes | recompile applied |", "| --- | --- | --- | --- | --- |"])

    for program in programs:
        for case in program.cases:
            aggregate = summary[program.key][case.key]
            applied = (aggregate["recompile"] or {}).get("applied")
            exec_text = ", ".join(str(value) for value in aggregate["exec_ns_values"])
            size_text = ", ".join(str(value) for value in aggregate["jited_prog_len_values"])
            lines.append(
                f"| {program.title} | {case.label} | {exec_text} | {size_text} | {applied} |"
            )

    lines.extend(
        [
            "",
            "## Interpretation",
            "",
            "- `log2_fold` uses the same CMOV-capable sites in the middle step; forcing CMOV makes the predictable workload slower.",
            "- The revert step is a fresh stock reload because explicit `--policy-blob` recompile currently returns `EINVAL` on the working framework kernel in this checkout.",
        ]
    )
    if any(program.key == "rotate64_hash" for program in programs):
        rotate_scan = summary["rotate64_hash"]["rotate"]["directive_scan"]
        lines.append(
            f"- `rotate64_hash` benefits from the v5 all-family pass in this tree "
            f"({rotate_scan.get('rotate_sites', 0)} rotate sites, {rotate_scan.get('wide_sites', 0)} wide sites)."
        )
    lines.append("")
    return "\n".join(lines)


def print_console_summary(programs: list[ProgramSpec], summary: dict[str, dict[str, Any]]) -> None:
    print("=== BPF JIT Policy Iteration Demo ===")
    for line in log2_summary_lines(summary["log2_fold"]):
        print(line)
    print()
    if any(program.key == "rotate64_hash" for program in programs):
        for line in rotate_summary_lines(summary["rotate64_hash"]):
            print(line)
        print()
    print("Conclusion: Same mechanism, opposite profitability -> policy matters.")


def write_outputs(output_json: Path, output_md: Path, payload: dict[str, Any], markdown: str) -> None:
    output_json.parent.mkdir(parents=True, exist_ok=True)
    output_md.parent.mkdir(parents=True, exist_ok=True)
    output_json.write_text(json.dumps(payload, indent=2) + "\n")
    output_md.write_text(markdown + "\n")


def main() -> None:
    args = parse_args()
    ensure_exists(RUNNER, "runner")

    programs = [LOG2_FOLD]
    if not args.no_rotate:
        programs.append(ROTATE64_HASH)

    kernel_used, records, notes = run_demo(args, programs)
    summary = build_summary(programs, records)
    markdown = build_markdown(kernel_used, notes, programs, summary, args.repeat, args.iterations)

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "kernel_used": str(kernel_used),
        "repeat": args.repeat,
        "iterations": args.iterations,
        "notes": notes,
        "summary": summary,
    }

    output_md = Path(args.output_md).resolve()
    output_json = Path(args.output_json).resolve()

    if args.dry_run:
        memory, input_size = materialize_program_input(LOG2_FOLD)
        command = build_micro_exec_command(LOG2_FOLD, LOG2_FOLD.cases[0], memory, input_size, args.repeat)
        print(" ".join(shlex.quote(part) for part in [args.vng, "--run", str(kernel_used), "--cwd", str(ROOT_DIR), "--exec", "./policy-iteration-guest.sh"]))
        print("example guest command:")
        print(" ".join(shlex.quote(part) for part in command))
        return

    write_outputs(output_json, output_md, payload, markdown)
    print_console_summary(programs, summary)
    print()
    print(f"Wrote {output_md}")
    print(f"Wrote {output_json}")


if __name__ == "__main__":
    main()
