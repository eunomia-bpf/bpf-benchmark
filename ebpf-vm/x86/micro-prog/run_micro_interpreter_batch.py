#!/usr/bin/env python3
"""Build and run every generated x86 eBPF-VM micro proof artifact."""

from __future__ import annotations

import argparse
import os
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path

import yaml


REPO_ROOT = Path(__file__).resolve().parents[3]
OUT_DIR = Path(__file__).resolve().parent
BUILD_DIR = OUT_DIR / "build"
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


@dataclass
class Result:
    name: str
    status: str
    note: str


def load_benches() -> list[Bench]:
    data = yaml.safe_load(CONFIG.read_text())
    benches: list[Bench] = []
    for item in data["benchmarks"]:
        expected = item.get("expected_result")
        generator = item.get("input_generator")
        if expected is None or generator is None:
            continue
        benches.append(Bench(item["name"], generator, int(expected)))
    return benches


def run_cmd(cmd: list[str], *, timeout: int, capture: bool = True) -> subprocess.CompletedProcess[str]:
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


def compile_object(bench: Bench) -> Result | None:
    src = OUT_DIR / f"{bench.name}.bpf.c"
    obj = BUILD_DIR / f"{bench.name}.bpf.o"
    if not src.exists():
        return Result(bench.name, "compile-fail", f"missing generated source: {src}")
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
    try:
        result = run_cmd(cmd, timeout=240)
    except subprocess.TimeoutExpired:
        return Result(bench.name, "compile-fail", "clang timeout")
    if result.returncode != 0:
        err = compact_error(result.stderr or result.stdout or "clang failed")
        return Result(bench.name, "compile-fail", err)
    return None


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
    ]
    if sudo and os.geteuid() != 0:
        cmd = ["sudo", "-n", *cmd]
    try:
        result = run_cmd(cmd, timeout=120)
    except subprocess.TimeoutExpired:
        return Result(bench.name, "run-fail", "loader timeout")
    if result.returncode == 0:
        return Result(bench.name, "ok", "")
    return Result(bench.name, "run-fail", compact_error(result.stderr or result.stdout or "loader failed"))


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


def markdown_table(results: list[Result]) -> str:
    lines = [
        "| Micro program | Status | Note |",
        "| --- | --- | --- |",
    ]
    for result in results:
        note = result.note.replace("|", "\\|")
        lines.append(f"| `{result.name}` | {result.status} | {note} |")
    return "\n".join(lines)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--only", nargs="*", help="optional micro benchmark names")
    parser.add_argument("--no-generate", action="store_true")
    parser.add_argument("--no-build-loader", action="store_true")
    parser.add_argument("--no-sudo", action="store_true")
    parser.add_argument(
        "--native-source",
        choices=("markdown", "object-no-jump-tables"),
        default="object-no-jump-tables",
        help="native x86 disassembly source for generated proof C",
    )
    parser.add_argument("--markdown", type=Path, help="write a markdown status table")
    args = parser.parse_args()

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

    results: list[Result] = []
    for bench in benches:
        compile_result = compile_object(bench)
        if compile_result is not None:
            results.append(compile_result)
            print(f"{bench.name}: {compile_result.status}: {compile_result.note}", flush=True)
            continue
        run_result = run_object(bench, sudo=not args.no_sudo)
        results.append(run_result)
        print(f"{bench.name}: {run_result.status}: {run_result.note}", flush=True)

    table = markdown_table(results)
    if args.markdown:
        args.markdown.write_text(table + "\n")
    print(table)
    return 0 if all(result.status == "ok" for result in results) else 1


if __name__ == "__main__":
    raise SystemExit(main())
