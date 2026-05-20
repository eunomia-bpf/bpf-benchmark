#!/usr/bin/env python3
"""Build and run every generated arm64 ReverseSim micro proof artifact."""

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
ARM64_DIR = OUT_DIR.parent
BUILD_DIR = OUT_DIR / "build"
RESULTS_DIR = ARM64_DIR / "results"
CONFIG = REPO_ROOT / "micro" / "config" / "micro_pure_jit.yaml"
LOADER_MANIFEST = REPO_ROOT / "native-sim" / "loader" / "Cargo.toml"
LOADER_BIN = REPO_ROOT / "native-sim" / "loader" / "target" / "debug" / "reversesim-loader"
MICRO_RESULTS_DIR = REPO_ROOT / "micro" / "results"
BPF_STACK_SIZE = os.environ.get("BPF_STACK_SIZE", "4096")

sys.path.insert(0, str(REPO_ROOT))
from runner.libs.input_generators import materialize_input  # noqa: E402


@dataclass(frozen=True)
class Bench:
    name: str
    input_generator: str
    expected_result: int
    expected_retval: int
    result_channel: str
    cgroup_skb_input: bool


@dataclass
class Result:
    name: str
    status: str
    note: str
    compile_s: float = 0.0
    verify_s: float = 0.0
    test_s: float = 0.0
    proof_bpf_insns: int | None = None
    direct_bpf_insns: int | None = None


def load_benches() -> list[Bench]:
    data = yaml.safe_load(CONFIG.read_text(encoding="utf-8"))
    defaults = data.get("benchmark_defaults", {})
    default_retval = int(defaults.get("expected_retval", 2))
    benches: list[Bench] = []
    for item in data["benchmarks"]:
        expected = item.get("expected_result")
        generator = item.get("input_generator")
        if expected is None or generator is None:
            continue
        tags = set(item.get("tags", []))
        result_channel = "skb-cb" if {"tc", "cgroup-skb"} & tags else "packet"
        benches.append(
            Bench(
                name=item["name"],
                input_generator=generator,
                expected_result=int(expected),
                expected_retval=int(item.get("expected_retval", default_retval)),
                result_channel=result_channel,
                cgroup_skb_input="cgroup-skb" in tags,
            )
        )
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


def generate_sources(only: list[str]) -> None:
    cmd = ["python3", str(OUT_DIR / "generate_micro_sim_proofs.py")]
    if only:
        cmd.extend(["--only", *only])
    require_ok(cmd, timeout=300)


def build_loader() -> None:
    require_ok(["cargo", "build", "--manifest-path", str(LOADER_MANIFEST)], timeout=300)


def compile_object(bench: Bench) -> tuple[Result | None, float]:
    src = OUT_DIR / f"{bench.name}.bpf.c"
    obj = BUILD_DIR / f"{bench.name}.bpf.o"
    if not src.exists():
        return Result(bench.name, "compile-fail", f"missing generated source: {src}"), 0.0
    BUILD_DIR.mkdir(parents=True, exist_ok=True)
    cmd = [
        "clang",
        "-g",
        "-O2",
        "-target",
        "bpf",
        "-mllvm",
        f"-bpf-stack-size={BPF_STACK_SIZE}",
        "-D__TARGET_ARCH_arm64",
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
        return Result(bench.name, "compile-fail", compact_error(result.stderr or result.stdout or "clang failed"),
                      compile_s=compile_s), compile_s
    return None, compile_s


def bpf_instruction_count(obj: Path) -> int:
    result = run_cmd(["llvm-readelf", "-SW", str(obj)], timeout=30)
    if result.returncode != 0:
        raise RuntimeError(compact_error(result.stderr or result.stdout))
    total = 0
    for line in result.stdout.splitlines():
        match = re.match(
            r"\s*\[\s*\d+\]\s+\S+\s+PROGBITS\s+\S+\s+\S+\s+"
            r"([0-9a-fA-F]+)\s+\S+\s+([A-Z]+)",
            line,
        )
        if match is None:
            continue
        size = int(match.group(1), 16)
        flags = match.group(2)
        if "X" in flags:
            total += size // 8
    return total


def load_direct_bpf_counts() -> dict[str, int]:
    paths = sorted(MICRO_RESULTS_DIR.glob("arm64_qemu_micro_*/metadata.json"), reverse=True)
    if not paths:
        return {}
    for path in paths:
        dump_dir = path.parent / "details" / "jit_dumps"
        counts: dict[str, int] = {}
        for dump in dump_dir.glob("*__kernel__sample00.xlated.bin"):
            name = dump.name.split("__kernel__sample00.xlated.bin", 1)[0]
            counts[name] = dump.stat().st_size // 8
        if counts:
            return counts
    return {}


def run_object(bench: Bench, sudo: bool, run_id: str) -> Result:
    obj = BUILD_DIR / f"{bench.name}.bpf.o"
    input_path, _meta = materialize_input(bench.input_generator, force=False)
    verifier_log = RESULTS_DIR / f"{bench.name}-{run_id}.verifier.log"
    RESULTS_DIR.mkdir(parents=True, exist_ok=True)
    cmd = [
        str(LOADER_BIN),
        "--object",
        str(obj),
        "--program",
        f"{bench.name}_arm64_sim_xdp",
        "--verifier-log",
        str(verifier_log),
        "--case",
        bench.name,
        "--input",
        str(input_path),
        "--expected-result",
        str(bench.expected_result),
        "--expect-retval",
        str(bench.expected_retval),
        "--result-channel",
        bench.result_channel,
    ]
    if bench.cgroup_skb_input:
        cmd.append("--cgroup-skb-input")
    if sudo and os.geteuid() != 0:
        cmd = ["sudo", "-n", *cmd]
    try:
        start = time.monotonic()
        result = run_cmd(cmd, timeout=120)
        run_s = time.monotonic() - start
    except subprocess.TimeoutExpired:
        return Result(bench.name, "run-fail", "loader timeout", test_s=120.0)
    verify_s, test_s = parse_loader_timing(f"{result.stdout or ''}\n{result.stderr or ''}")
    if result.returncode == 0:
        return Result(bench.name, "ok", "", verify_s=verify_s, test_s=test_s)
    return Result(bench.name, "run-fail", compact_error(result.stderr or result.stdout or "loader failed"),
                  verify_s=verify_s, test_s=test_s or run_s)


def add_note(result: Result, note: str) -> None:
    if note:
        result.note = f"{result.note}; {note}" if result.note else note


def run_bench(bench: Bench, sudo: bool, run_id: str, direct_counts: dict[str, int]) -> Result:
    direct_count = direct_counts.get(bench.name)
    direct_note = "" if direct_count is not None else "missing direct xlated.bin in arm64 micro result"
    compile_result, compile_s = compile_object(bench)
    if compile_result is not None:
        compile_result.direct_bpf_insns = direct_count
        add_note(compile_result, direct_note)
        return compile_result
    try:
        proof_count = bpf_instruction_count(BUILD_DIR / f"{bench.name}.bpf.o")
        proof_note = ""
    except RuntimeError as exc:
        proof_count = None
        proof_note = f"proof BPF count failed: {exc}"
    result = run_object(bench, sudo=sudo, run_id=run_id)
    result.compile_s = compile_s
    result.proof_bpf_insns = proof_count
    result.direct_bpf_insns = direct_count
    add_note(result, proof_note)
    add_note(result, direct_note)
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
    return " | ".join(chosen)[:500]


def parse_loader_timing(text: str) -> tuple[float, float]:
    match = re.search(r"timing verify_s=([0-9.]+) test_s=([0-9.]+)", text)
    if match is None:
        return 0.0, 0.0
    return float(match.group(1)), float(match.group(2))


def markdown_table(results: list[Result]) -> str:
    lines = [
        "| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |",
        "| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |",
    ]
    for result in results:
        note = result.note.replace("|", "\\|")
        proof_insns = "" if result.proof_bpf_insns is None else str(result.proof_bpf_insns)
        direct_insns = "" if result.direct_bpf_insns is None else str(result.direct_bpf_insns)
        lines.append(
            f"| `{result.name}` | {result.status} | "
            f"{result.compile_s:.3f} | {proof_insns} | {direct_insns} | "
            f"{result.verify_s:.3f} | {result.test_s:.3f} | {note} |"
        )
    return "\n".join(lines)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--only", nargs="*", help="optional micro benchmark names")
    parser.add_argument("--no-generate", action="store_true")
    parser.add_argument("--no-build-loader", action="store_true")
    parser.add_argument("--no-sudo", action="store_true")
    parser.add_argument("--jobs", type=int, default=min(8, os.cpu_count() or 1))
    parser.add_argument("--markdown", type=Path)
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
        generate_sources([bench.name for bench in benches] if only else [])
    if not args.no_build_loader:
        build_loader()

    direct_counts = load_direct_bpf_counts()
    run_id = datetime.now().strftime("%Y%m%d-%H%M%S")
    results_by_name: dict[str, Result] = {}
    if args.jobs == 1:
        for bench in benches:
            result = run_bench(bench, sudo=not args.no_sudo, run_id=run_id,
                               direct_counts=direct_counts)
            results_by_name[bench.name] = result
            print_result(result)
    else:
        print(f"running {len(benches)} benchmarks with {args.jobs} jobs", flush=True)
        with ThreadPoolExecutor(max_workers=args.jobs) as executor:
            futures = {
                executor.submit(run_bench, bench, not args.no_sudo, run_id, direct_counts): bench
                for bench in benches
            }
            for future in as_completed(futures):
                bench = futures[future]
                result = future.result()
                results_by_name[bench.name] = result
                print_result(result)

    results = [results_by_name[bench.name] for bench in benches]
    table = markdown_table(results)
    markdown_path = args.markdown or (RESULTS_DIR / f"README-{run_id}.md")
    markdown_path.parent.mkdir(parents=True, exist_ok=True)
    markdown_path.write_text(table + "\n", encoding="utf-8")
    print(f"wrote {markdown_path}")
    print(table)
    return 0 if all(result.status == "ok" for result in results) else 1


def print_result(result: Result) -> None:
    print(
        f"{result.name}: {result.status}: "
        f"compile={result.compile_s:.3f}s "
        f"proof_insns={result.proof_bpf_insns or ''} "
        f"direct_insns={result.direct_bpf_insns or ''} "
        f"verify={result.verify_s:.3f}s "
        f"test={result.test_s:.3f}s {result.note}",
        flush=True,
    )


if __name__ == "__main__":
    raise SystemExit(main())
