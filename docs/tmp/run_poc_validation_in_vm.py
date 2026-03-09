#!/usr/bin/env python3
import json
import statistics
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
PROGRAM = ROOT / "micro/programs/load_byte_recompose.bpf.o"
MEMORY = ROOT / "micro/generated-inputs/load_byte_recompose.mem"
DIRECTIVE_HINT = ROOT / "micro/build/tools/directive_hint"
DIRECTIVE_BLOB = ROOT / "micro/generated-inputs/load_byte_recompose.directive.bin"
MICRO_EXEC = ROOT / "micro/build/runner/micro_exec"
RESULTS_PATH = ROOT / "docs/tmp/poc-validation-results.json"

REPEAT = 200
WARMUPS = 2
ITERATIONS = 10
INPUT_SIZE = 1032


def run(args):
    completed = subprocess.run(args, check=True, text=True, capture_output=True)
    return completed.stdout.strip()


def run_kernel_sample(use_directives: bool):
    args = [
        str(MICRO_EXEC),
        "run-kernel",
        "--program",
        str(PROGRAM),
        "--io-mode",
        "staged",
        "--repeat",
        str(REPEAT),
        "--input-size",
        str(INPUT_SIZE),
        "--memory",
        str(MEMORY),
    ]
    if use_directives:
        args.extend(["--directive-blob", str(DIRECTIVE_BLOB)])
    return json.loads(run(args))


def summarize(samples):
    exec_values = [sample["exec_ns"] for sample in samples]
    compile_values = [sample["compile_ns"] for sample in samples]
    return {
        "samples": samples,
        "exec_ns": {
            "median": statistics.median(exec_values),
            "min": min(exec_values),
            "max": max(exec_values),
        },
        "compile_ns": {
            "median": statistics.median(compile_values),
            "min": min(compile_values),
            "max": max(compile_values),
        },
        "jited_prog_len": samples[0].get("jited_prog_len"),
        "xlated_prog_len": samples[0].get("xlated_prog_len"),
    }


def main():
    kernel_release = run(["uname", "-r"])
    run([str(DIRECTIVE_HINT), str(PROGRAM), "load_byte_recompose_xdp", str(DIRECTIVE_BLOB)])

    for _ in range(WARMUPS):
        run_kernel_sample(False)
    baseline_samples = [run_kernel_sample(False) for _ in range(ITERATIONS)]

    for _ in range(WARMUPS):
        run_kernel_sample(True)
    directive_samples = [run_kernel_sample(True) for _ in range(ITERATIONS)]

    baseline = summarize(baseline_samples)
    directive = summarize(directive_samples)
    ratio = directive["exec_ns"]["median"] / baseline["exec_ns"]["median"]

    report = {
        "kernel_release": kernel_release,
        "program": str(PROGRAM),
        "directive_blob": str(DIRECTIVE_BLOB),
        "repeat": REPEAT,
        "warmups": WARMUPS,
        "iterations": ITERATIONS,
        "baseline": baseline,
        "with_directives": directive,
        "directive_over_baseline_exec_ratio": ratio,
        "baseline_delta_ns": directive["exec_ns"]["median"] - baseline["exec_ns"]["median"],
    }

    RESULTS_PATH.write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps(report, indent=2))


if __name__ == "__main__":
    main()
