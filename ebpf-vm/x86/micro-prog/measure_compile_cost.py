#!/usr/bin/env python3
"""Measure clang compile cost for x86 VM generated-C proof variants."""

from __future__ import annotations

import argparse
import os
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from dataclasses import dataclass
from pathlib import Path

import yaml


REPO_ROOT = Path(__file__).resolve().parents[3]
X86_DIR = REPO_ROOT / "ebpf-vm" / "x86"
MICRO_PROG_DIR = X86_DIR / "micro-prog"
BUILD_DIR = MICRO_PROG_DIR / "build"
CONFIG = REPO_ROOT / "micro" / "config" / "micro_pure_jit.yaml"
LOADER_BIN = REPO_ROOT / "ebpf-vm" / "loader" / "target" / "debug" / "ebpf-vm-loader"

sys.path.insert(0, str(REPO_ROOT))
from runner.libs.input_generators import materialize_input  # noqa: E402


@dataclass(frozen=True)
class Bench:
    name: str
    input_generator: str
    expected_result: int
    expected_retval: int


@dataclass(frozen=True)
class Variant:
    name: str
    source_dir: Path
    object_dir: Path
    log_label: str


def run_cmd(cmd: list[str], *, capture: bool = True) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        cmd,
        cwd=REPO_ROOT,
        check=False,
        text=True,
        stdout=subprocess.PIPE if capture else None,
        stderr=subprocess.PIPE if capture else None,
    )


def load_benches() -> list[Bench]:
    data = yaml.safe_load(CONFIG.read_text())
    default_retval = int(data.get("benchmark_defaults", {}).get("expected_retval", 2))
    benches: list[Bench] = []
    for item in data["benchmarks"]:
        if item.get("expected_result") is None or item.get("input_generator") is None:
            continue
        benches.append(Bench(
            name=item["name"],
            input_generator=item["input_generator"],
            expected_result=int(item["expected_result"]),
            expected_retval=int(item.get("expected_retval", default_retval)),
        ))
    return benches


def generator_for_variant(variant: str) -> Path:
    if variant == "current":
        return MICRO_PROG_DIR / "generate_micro_proofs.py"
    if variant == "helper-selection":
        return MICRO_PROG_DIR / "generate_micro_proofs_helper_selection.py"
    raise ValueError(f"unknown variant: {variant}")


def variant_config(name: str, run_label: str = "") -> Variant:
    suffix = f"-{run_label}" if run_label else ""
    if name == "current":
        return Variant(
            name=name,
            source_dir=MICRO_PROG_DIR,
            object_dir=BUILD_DIR / f"compile-cost-current{suffix}",
            log_label=f"current{suffix}",
        )
    if name == "helper-selection":
        return Variant(
            name=name,
            source_dir=X86_DIR / "build" / "helper-selection-src",
            object_dir=BUILD_DIR / f"compile-cost-helper-selection{suffix}",
            log_label=f"helper-selection{suffix}",
        )
    raise ValueError(f"unknown variant: {name}")


def generate_sources(variant: str, only: list[str]) -> None:
    cmd = [
        "python3",
        str(generator_for_variant(variant)),
        "--native-source",
        "object-no-jump-tables",
    ]
    if only:
        cmd.extend(["--only", *only])
    result = run_cmd(cmd)
    if result.returncode != 0:
        raise RuntimeError(compact_error(result.stderr or result.stdout))


def compile_one(variant: Variant, bench: Bench) -> tuple[Path | None, float, str, str]:
    src = variant.source_dir / f"{bench.name}.bpf.c"
    obj = variant.object_dir / f"{bench.name}.bpf.o"
    if not src.exists():
        return None, 0.0, "compile-fail", f"missing source: {src}"
    variant.object_dir.mkdir(parents=True, exist_ok=True)
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
    result = run_cmd(cmd)
    elapsed = time.monotonic() - start
    if result.returncode != 0:
        return None, elapsed, "compile-fail", compact_error(result.stderr or result.stdout)
    return obj, elapsed, "compiled", ""


def run_object(variant: Variant, bench: Bench, obj: Path, *, load_only: bool) -> tuple[str, str, float]:
    input_path, _meta = materialize_input(bench.input_generator, force=False)
    verifier_log = Path("/tmp") / f"{variant.log_label}-{bench.name}.verifier.log"
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
        "--verifier-log",
        str(verifier_log),
    ]
    if load_only:
        cmd.append("--load-only")
    if os.geteuid() != 0:
        cmd = ["sudo", "-n", *cmd]
    start = time.monotonic()
    result = run_cmd(cmd)
    elapsed = time.monotonic() - start
    if result.returncode == 0:
        return "load-ok" if load_only else "ok", "", elapsed
    return (
        "load-fail" if load_only else "run-fail",
        compact_error(result.stderr or result.stdout),
        elapsed,
    )


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
        or "processed" in line
        or "verifier log" in line
    ]
    return " | ".join((interesting or lines)[-2:])[:240]


def print_markdown_row(row: dict[str, str]) -> None:
    note = row["note"].replace("|", "\\|")
    print(
        f"| `{row['variant']}` | `{row['bench']}` | {row['clang_seconds']} "
        f"| {row['verify_seconds']} | {row['status']} | {note} |",
        flush=True,
    )


def measure_one(variant: Variant, bench: Bench, *, load_only: bool) -> dict[str, str]:
    obj, elapsed, status, note = compile_one(variant, bench)
    verify_elapsed = 0.0
    if obj is not None:
        status, note, verify_elapsed = run_object(
            variant, bench, obj, load_only=load_only
        )
    return {
        "variant": variant.name,
        "bench": bench.name,
        "clang_seconds": f"{elapsed:.3f}",
        "verify_seconds": f"{verify_elapsed:.3f}" if obj is not None else "-",
        "status": status,
        "note": note,
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--variant", choices=("current", "helper-selection"), action="append")
    parser.add_argument("--only", nargs="*", default=[])
    parser.add_argument("--skip", nargs="*", default=[])
    parser.add_argument("--no-generate", action="store_true")
    parser.add_argument("--load-only", action="store_true")
    parser.add_argument("--jobs", type=int, default=1)
    parser.add_argument(
        "--run-label",
        default="",
        help="suffix object directories and verifier logs to avoid clobbering another run",
    )
    args = parser.parse_args()
    if args.jobs < 1:
        raise SystemExit("--jobs must be >= 1")

    variants = args.variant or ["current", "helper-selection"]
    benches = load_benches()
    only = set(args.only)
    if only:
        benches = [bench for bench in benches if bench.name in only]
    skip = set(args.skip)
    if skip:
        benches = [bench for bench in benches if bench.name not in skip]
    if not benches:
        raise SystemExit("no selected benchmarks")

    rows: list[dict[str, str]] = []
    print("| Variant | Micro program | clang seconds | verify seconds | Status | Note |")
    print("| --- | --- | ---: | ---: | --- | --- |")
    for variant_name in variants:
        if not args.no_generate:
            generate_sources(variant_name, [bench.name for bench in benches] if only else [])
        variant = variant_config(variant_name, args.run_label)
        if args.jobs == 1:
            for bench in benches:
                row = measure_one(variant, bench, load_only=args.load_only)
                rows.append(row)
                print_markdown_row(row)
            continue
        with ThreadPoolExecutor(max_workers=args.jobs) as executor:
            futures = [
                executor.submit(measure_one, variant, bench,
                                load_only=args.load_only)
                for bench in benches
            ]
            for future in as_completed(futures):
                row = future.result()
                rows.append(row)
                print_markdown_row(row)
    return 0 if all(row["status"] in {"ok", "load-ok"} for row in rows) else 1


if __name__ == "__main__":
    raise SystemExit(main())
