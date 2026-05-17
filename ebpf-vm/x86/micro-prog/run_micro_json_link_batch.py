#!/usr/bin/env python3
"""Run micro programs through the ReverseJIT JSON static-link path.

This is intentionally separate from run_micro_interpreter_batch.py. It does not
compile per-micro .bpf.c files after JSON generation. The only tested path is:

    native asm -> JSON proof -> Rust loader static-link -> BPF_PROG_LOAD
    -> BPF_PROG_TEST_RUN
"""

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
JSON_DIR = OUT_DIR / "build" / "json-proofs"
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


def run_cmd(cmd: list[str], *, timeout: int) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        cmd,
        cwd=REPO_ROOT,
        check=False,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        timeout=timeout,
    )


def require_ok(cmd: list[str], *, timeout: int) -> None:
    result = run_cmd(cmd, timeout=timeout)
    if result.returncode != 0:
        detail = "\n".join(
            part.strip() for part in [result.stdout, result.stderr] if part and part.strip()
        )
        raise RuntimeError(f"{' '.join(cmd)} failed\n{detail}")


def generate_json(benches: list[Bench], only_was_set: bool, native_source: str) -> None:
    cmd = [
        "python3",
        str(OUT_DIR / "generate_micro_json_proofs.py"),
        "--output-dir",
        str(JSON_DIR),
        "--native-source",
        native_source,
    ]
    if only_was_set:
        cmd.extend(["--only", *(bench.name for bench in benches)])
    require_ok(cmd, timeout=300)


def build_loader() -> None:
    require_ok(["make", "-C", str(REPO_ROOT / "ebpf-vm" / "x86"), "build-templates"], timeout=300)
    require_ok(["cargo", "build", "--manifest-path", str(LOADER_MANIFEST)], timeout=300)


def run_json(bench: Bench, sudo: bool) -> Result:
    json_path = JSON_DIR / f"{bench.name}.json"
    if not json_path.exists():
        return Result(bench.name, "json-fail", f"missing JSON proof: {json_path}")
    input_path, _meta = materialize_input(bench.input_generator, force=False)
    cmd = [
        str(LOADER_BIN),
        "--json",
        str(json_path),
        "--program",
        f"{bench.name[:12]}_rjit",
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
    note = compact_error(result.stderr or result.stdout)
    status = "linker-missing" if "has no bpf_program section" in note else "run-fail"
    return Result(bench.name, status, note)


def compact_error(text: str) -> str:
    lines = [line.strip() for line in text.splitlines() if line.strip()]
    if not lines:
        return "unknown error"
    interesting = [
        line
        for line in lines
        if "error:" in line
        or "failed" in line
        or "mismatch" in line
        or "unexpected" in line
        or "invalid" in line.lower()
        or "unsupported" in line.lower()
        or "processed" in line
        or "R" in line and "invalid" in line
    ]
    chosen = interesting[-3:] if interesting else lines[-3:]
    return " | ".join(chosen)[:360]


def markdown_table(results: list[Result]) -> str:
    lines = [
        "| Micro program | JSON-link status | Note |",
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
    )
    parser.add_argument("--markdown", type=Path, help="write a markdown status table")
    args = parser.parse_args()

    benches = load_benches()
    selected = set(args.only or [])
    if selected:
        benches = [bench for bench in benches if bench.name in selected]
    if not benches:
        raise SystemExit("no selected benchmarks")

    if not args.no_generate:
        generate_json(benches, bool(selected), args.native_source)
    if not args.no_build_loader:
        build_loader()

    results: list[Result] = []
    for bench in benches:
        result = run_json(bench, sudo=not args.no_sudo)
        results.append(result)
        print(f"{bench.name}: {result.status}: {result.note}", flush=True)

    table = markdown_table(results)
    if args.markdown:
        args.markdown.write_text(table + "\n")
    print(table)
    return 0 if all(result.status == "ok" for result in results) else 1


if __name__ == "__main__":
    raise SystemExit(main())
