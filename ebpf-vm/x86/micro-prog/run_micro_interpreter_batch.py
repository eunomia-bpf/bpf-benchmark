#!/usr/bin/env python3
"""Build and run every generated x86 eBPF-VM micro proof artifact."""

from __future__ import annotations

import argparse
import os
import re
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path

import yaml


REPO_ROOT = Path(__file__).resolve().parents[3]
OUT_DIR = Path(__file__).resolve().parent
X86_DIR = OUT_DIR.parent
BUILD_DIR = OUT_DIR / "build"
RESULTS_DIR = X86_DIR / "results"
CONFIG = REPO_ROOT / "micro" / "config" / "micro_pure_jit.yaml"
LOADER_MANIFEST = REPO_ROOT / "ebpf-vm" / "loader" / "Cargo.toml"
LOADER_BIN = REPO_ROOT / "ebpf-vm" / "loader" / "target" / "debug" / "ebpf-vm-loader"

sys.path.insert(0, str(REPO_ROOT))
from runner.libs.input_generators import materialize_input  # noqa: E402


@dataclass(frozen=True)
class Bench:
    name: str
    input_generator: str
    expected_result: int
    expected_retval: int


@dataclass
class Result:
    name: str
    status: str
    note: str
    compile_s: float = 0.0
    verify_s: float = 0.0
    test_s: float = 0.0


def load_benches() -> list[Bench]:
    data = yaml.safe_load(CONFIG.read_text())
    defaults = data.get("benchmark_defaults", {})
    default_retval = int(defaults.get("expected_retval", 2))
    benches: list[Bench] = []
    for item in data["benchmarks"]:
        expected = item.get("expected_result")
        generator = item.get("input_generator")
        if expected is None or generator is None:
            continue
        name = item["name"]
        expected_retval = int(item.get("expected_retval", default_retval))
        benches.append(Bench(name, generator, int(expected),
                             expected_retval))
    return benches


def run_cmd(cmd: list[str], *, timeout: int | None, capture: bool = True) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        cmd,
        cwd=REPO_ROOT,
        check=False,
        text=True,
        stdout=subprocess.PIPE if capture else None,
        stderr=subprocess.PIPE if capture else None,
        timeout=timeout,
    )


def require_ok(cmd: list[str], *, timeout: int) -> None:
    result = run_cmd(cmd, timeout=timeout)
    if result.returncode != 0:
        out = (result.stdout or "").strip()
        err = (result.stderr or "").strip()
        detail = "\n".join(part for part in [out, err] if part)
        raise RuntimeError(f"{' '.join(cmd)} failed\n{detail}")


def generate_sources(only: list[str], native_source: str) -> None:
    cmd = [
        "python3",
        str(OUT_DIR / "generate_micro_proofs.py"),
        "--native-source",
        native_source,
    ]
    if only:
        cmd.extend(["--only", *only])
    require_ok(cmd, timeout=300)


def build_loader() -> None:
    require_ok(["cargo", "build", "--manifest-path", str(LOADER_MANIFEST)], timeout=300)


def compile_object(bench: Bench) -> tuple[Result | None, float]:
    src = OUT_DIR / f"{bench.name}.bpf.c"
    obj = BUILD_DIR / f"{bench.name}.bpf.o"
    if not src.exists():
        return Result(bench.name, "compile-fail",
                      f"missing generated source: {src}"), 0.0
    BUILD_DIR.mkdir(parents=True, exist_ok=True)
    cmd = [
        "clang",
        "-g",
        "-O2",
        "-target",
        "bpf",
        "-D__TARGET_ARCH_x86",
        "-I",
        str(REPO_ROOT / "vendor" / "libbpf" / "include" / "uapi"),
        "-I",
        str(REPO_ROOT / "vendor" / "libbpf" / "src"),
        "-I",
        "/usr/include/x86_64-linux-gnu",
        "-c",
        str(src),
        "-o",
        str(obj),
    ]
    start = time.monotonic()
    result = run_cmd(cmd, timeout=None)
    compile_s = time.monotonic() - start
    if result.returncode != 0:
        err = compact_error(result.stderr or result.stdout or "clang failed")
        return Result(bench.name, "compile-fail", err,
                      compile_s=compile_s), compile_s
    return None, compile_s


def run_object(bench: Bench, sudo: bool) -> Result:
    obj = BUILD_DIR / f"{bench.name}.bpf.o"
    input_path, _meta = materialize_input(bench.input_generator, force=False)
    cmd = [
        str(LOADER_BIN),
        "--object",
        str(obj),
        "--program",
        f"{bench.name}_x86_vm_xdp",
        "--case",
        bench.name,
        "--input",
        str(input_path),
        "--expected-result",
        str(bench.expected_result),
        "--expect-retval",
        str(bench.expected_retval),
    ]
    if sudo and os.geteuid() != 0:
        cmd = ["sudo", "-n", *cmd]
    try:
        start = time.monotonic()
        result = run_cmd(cmd, timeout=120)
        run_s = time.monotonic() - start
    except subprocess.TimeoutExpired:
        return Result(bench.name, "run-fail", "loader timeout", test_s=120.0)
    verify_s, test_s = parse_loader_timing(
        f"{result.stdout or ''}\n{result.stderr or ''}"
    )
    if result.returncode == 0:
        return Result(bench.name, "ok", "", verify_s=verify_s, test_s=test_s)
    return Result(bench.name, "run-fail",
                  compact_error(result.stderr or result.stdout or "loader failed"),
                  verify_s=verify_s, test_s=test_s or run_s)


def run_bench(bench: Bench, sudo: bool) -> Result:
    compile_result, compile_s = compile_object(bench)
    if compile_result is not None:
        return compile_result
    result = run_object(bench, sudo=sudo)
    result.compile_s = compile_s
    return result


def compact_error(text: str) -> str:
    lines = [line.strip() for line in text.splitlines() if line.strip()]
    if not lines:
        return "unknown error"
    interesting = [
        line for line in lines
        if "error:" in line
        or "failed" in line
        or "mismatch" in line
        or "unexpected" in line
        or "too large" in line
        or "too complex" in line
        or "processed" in line
    ]
    chosen = interesting[-2:] if interesting else lines[-2:]
    return " | ".join(chosen)[:240]


def parse_loader_timing(text: str) -> tuple[float, float]:
    match = re.search(r"timing verify_s=([0-9.]+) test_s=([0-9.]+)", text)
    if match is None:
        return 0.0, 0.0
    return float(match.group(1)), float(match.group(2))


def markdown_table(results: list[Result]) -> str:
    lines = [
        "| Micro program | Status | Compile s | Verify s | Test s | Note |",
        "| --- | --- | ---: | ---: | ---: | --- |",
    ]
    for result in results:
        note = result.note.replace("|", "\\|")
        lines.append(
            f"| `{result.name}` | {result.status} | "
            f"{result.compile_s:.3f} | {result.verify_s:.3f} | "
            f"{result.test_s:.3f} | {note} |"
        )
    return "\n".join(lines)


def default_markdown_path() -> Path:
    timestamp = datetime.now().strftime("%Y%m%d-%H%M%S")
    return RESULTS_DIR / f"README-{timestamp}.md"


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--only", nargs="*", help="optional micro benchmark names")
    parser.add_argument("--no-generate", action="store_true")
    parser.add_argument("--no-build-loader", action="store_true")
    parser.add_argument("--no-sudo", action="store_true")
    parser.add_argument(
        "--jobs",
        type=int,
        default=min(8, os.cpu_count() or 1),
        help="parallel compile/load jobs; use --jobs 1 for serial",
    )
    parser.add_argument(
        "--native-source",
        choices=("markdown", "object-no-jump-tables"),
        default="object-no-jump-tables",
        help="native x86 disassembly source for generated proof C",
    )
    parser.add_argument(
        "--markdown",
        type=Path,
        help="write a markdown status table; defaults to ebpf-vm/x86/results/README-<timestamp>.md",
    )
    args = parser.parse_args()
    if args.jobs < 1:
        raise SystemExit("--jobs must be >= 1")

    benches = load_benches()
    only = set(args.only or [])
    if only:
        benches = [bench for bench in benches if bench.name in only]
    if not benches:
        raise SystemExit("no selected benchmarks")

    if not args.no_generate:
        generate_sources([bench.name for bench in benches] if only else [],
                         args.native_source)
    if not args.no_build_loader:
        build_loader()

    results_by_name: dict[str, Result] = {}
    if args.jobs == 1:
        for bench in benches:
            result = run_bench(bench, sudo=not args.no_sudo)
            results_by_name[bench.name] = result
            print(
                f"{bench.name}: {result.status}: "
                f"compile={result.compile_s:.3f}s "
                f"verify={result.verify_s:.3f}s "
                f"test={result.test_s:.3f}s {result.note}",
                flush=True,
            )
    else:
        print(f"running {len(benches)} benchmarks with {args.jobs} jobs", flush=True)
        with ThreadPoolExecutor(max_workers=args.jobs) as executor:
            futures = {
                executor.submit(run_bench, bench, not args.no_sudo): bench
                for bench in benches
            }
            for future in as_completed(futures):
                bench = futures[future]
                result = future.result()
                results_by_name[bench.name] = result
                print(
                    f"{bench.name}: {result.status}: "
                    f"compile={result.compile_s:.3f}s "
                    f"verify={result.verify_s:.3f}s "
                    f"test={result.test_s:.3f}s {result.note}",
                    flush=True,
                )

    results = [results_by_name[bench.name] for bench in benches]
    table = markdown_table(results)
    markdown_path = args.markdown or default_markdown_path()
    markdown_path.parent.mkdir(parents=True, exist_ok=True)
    markdown_path.write_text(table + "\n")
    print(f"wrote {markdown_path}")
    print(table)
    return 0 if all(result.status == "ok" for result in results) else 1


if __name__ == "__main__":
    raise SystemExit(main())
