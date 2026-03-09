#!/usr/bin/env python3
import json
import platform
import statistics
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
MICRO_EXEC = ROOT / "micro/build/runner/micro_exec"
DIRECTIVE_HINT = ROOT / "micro/build/tools/directive_hint"
RESULTS_PATH = ROOT / "docs/tmp/poc-v2-validation-results.json"

REPEAT = 200
WARMUPS = 1
ITERATIONS = 5

BENCHMARKS = [
    {
        "name": "cmov_select",
        "program": ROOT / "micro/programs/cmov_select.bpf.o",
        "program_name": "cmov_select_xdp",
        "memory": ROOT / "micro/generated-inputs/cmov_select.mem",
        "io_mode": "staged",
    },
    {
        "name": "binary_search",
        "program": ROOT / "micro/programs/binary_search.bpf.o",
        "program_name": "binary_search_xdp",
        "memory": ROOT / "micro/generated-inputs/binary_search.mem",
        "io_mode": "staged",
    },
    {
        "name": "switch_dispatch",
        "program": ROOT / "micro/programs/switch_dispatch.bpf.o",
        "program_name": "switch_dispatch_xdp",
        "memory": ROOT / "micro/generated-inputs/switch_dispatch.mem",
        "io_mode": "staged",
    },
]


def run_command(args):
    return subprocess.run(args, text=True, capture_output=True)


def parse_json_stdout(completed):
    stdout = completed.stdout.strip()
    if not stdout:
        raise ValueError("micro_exec produced no stdout")
    return json.loads(stdout)


def summarize_samples(samples):
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


def run_kernel_sample(benchmark, *, manual_load=False, directive_blob=None):
    args = [
        str(MICRO_EXEC),
        "run-kernel",
        "--program",
        str(benchmark["program"]),
        "--program-name",
        benchmark["program_name"],
        "--io-mode",
        benchmark["io_mode"],
        "--repeat",
        str(REPEAT),
        "--input-size",
        str(benchmark["memory"].stat().st_size),
        "--memory",
        str(benchmark["memory"]),
    ]
    if manual_load:
        args.append("--manual-load")
    if directive_blob is not None:
        args.extend(["--directive-blob", str(directive_blob)])

    completed = run_command(args)
    if completed.returncode != 0:
        return {
            "ok": False,
            "returncode": completed.returncode,
            "stdout": completed.stdout.strip(),
            "stderr": completed.stderr.strip(),
            "command": args,
        }

    try:
        sample = parse_json_stdout(completed)
    except Exception as exc:
        return {
            "ok": False,
            "returncode": completed.returncode,
            "stdout": completed.stdout.strip(),
            "stderr": completed.stderr.strip(),
            "command": args,
            "parse_error": str(exc),
        }

    return {"ok": True, "sample": sample}


def collect_mode_samples(benchmark, *, manual_load=False, directive_blob=None):
    warmup_results = []
    for _ in range(WARMUPS):
        result = run_kernel_sample(
            benchmark,
            manual_load=manual_load,
            directive_blob=directive_blob,
        )
        warmup_results.append(result)
        if not result["ok"]:
            return {
                "ok": False,
                "warmups": warmup_results,
                "error": result,
            }

    samples = []
    for _ in range(ITERATIONS):
        result = run_kernel_sample(
            benchmark,
            manual_load=manual_load,
            directive_blob=directive_blob,
        )
        if not result["ok"]:
            return {
                "ok": False,
                "warmups": warmup_results,
                "samples": samples,
                "error": result,
            }
        samples.append(result["sample"])

    return {
        "ok": True,
        "warmups": warmup_results,
        "summary": summarize_samples(samples),
    }


def generate_directive_blob(benchmark):
    blob_path = benchmark["memory"].with_suffix(".directive.bin")
    completed = run_command(
        [
            str(DIRECTIVE_HINT),
            str(benchmark["program"]),
            benchmark["program_name"],
            str(blob_path),
        ]
    )
    stdout = completed.stdout.strip()
    directive_count = None
    if completed.returncode == 0 and stdout:
        parts = stdout.split()
        if len(parts) >= 2:
            try:
                directive_count = int(parts[-1])
            except ValueError:
                directive_count = None

    return {
        "ok": completed.returncode == 0,
        "returncode": completed.returncode,
        "stdout": stdout,
        "stderr": completed.stderr.strip(),
        "blob_path": str(blob_path),
        "directive_count": directive_count,
    }


def benchmark_report(benchmark):
    directives = generate_directive_blob(benchmark)
    directive_blob = Path(directives["blob_path"])

    report = {
        "program": str(benchmark["program"]),
        "program_name": benchmark["program_name"],
        "memory": str(benchmark["memory"]),
        "directive_hint": directives,
        "baseline": collect_mode_samples(benchmark, manual_load=False),
        "manual_no_directives": collect_mode_samples(benchmark, manual_load=True),
    }

    if directives["ok"]:
        report["manual_with_directives"] = collect_mode_samples(
            benchmark,
            manual_load=True,
            directive_blob=directive_blob,
        )
    else:
        report["manual_with_directives"] = {
            "ok": False,
            "skipped": True,
            "reason": "directive_hint failed",
        }

    baseline = report["baseline"]
    with_directives = report["manual_with_directives"]
    if baseline.get("ok") and with_directives.get("ok"):
        baseline_exec = baseline["summary"]["exec_ns"]["median"]
        directive_exec = with_directives["summary"]["exec_ns"]["median"]
        report["directive_over_baseline_exec_ratio"] = (
            directive_exec / baseline_exec if baseline_exec else None
        )
    else:
        report["directive_over_baseline_exec_ratio"] = None

    return report


def main():
    report = {
        "kernel_release": platform.release(),
        "repeat": REPEAT,
        "warmups": WARMUPS,
        "iterations": ITERATIONS,
        "benchmarks": {},
    }

    for benchmark in BENCHMARKS:
        report["benchmarks"][benchmark["name"]] = benchmark_report(benchmark)

    RESULTS_PATH.write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps(report, indent=2))


if __name__ == "__main__":
    main()
