#!/usr/bin/env python3
"""Build generated ReverseSim micro proof artifacts."""

from __future__ import annotations

import argparse
import json
import os
import re
import subprocess
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from dataclasses import dataclass
from pathlib import Path

import yaml


NATIVE_SIM_DIR = Path(__file__).resolve().parent
REPO_ROOT = NATIVE_SIM_DIR.parent
CONFIG = REPO_ROOT / "micro" / "config" / "micro_pure_jit.yaml"
NATIVE_LINK_MANIFEST = NATIVE_SIM_DIR / "x86" / "native_lab" / "native_link" / "Cargo.toml"
NATIVE_LINK_BIN = (
    NATIVE_SIM_DIR / "x86" / "native_lab" / "native_link" / "target" / "release" / "native-link"
)
BPF_STACK_SIZE = os.environ.get("BPF_STACK_SIZE", "4096")


@dataclass(frozen=True)
class ArchConfig:
    name: str
    clang_opt: str
    target_define: str
    native_build_dir: Path
    stage2_native_build_dir: Path
    objdump: str

    @property
    def source_dir(self) -> Path:
        return NATIVE_SIM_DIR / self.name / "micro-prog"

    @property
    def build_dir(self) -> Path:
        return self.source_dir / "build"


ARCHES = {
    "x86": ArchConfig(
        name="x86",
        clang_opt="-O3",
        target_define="-D__TARGET_ARCH_x86",
        native_build_dir=REPO_ROOT / "micro" / "programs" / "build-x86",
        stage2_native_build_dir=REPO_ROOT / "kprog" / "test" / "build-x86",
        objdump="objdump",
    ),
    "arm64": ArchConfig(
        name="arm64",
        clang_opt="-O2",
        target_define="-D__TARGET_ARCH_arm64",
        native_build_dir=REPO_ROOT / "micro" / "programs" / "build-arm64",
        stage2_native_build_dir=REPO_ROOT / "kprog" / "test" / "build-arm64",
        objdump="aarch64-linux-gnu-objdump",
    ),
}


@dataclass(frozen=True)
class Bench:
    name: str
    stage2: bool


@dataclass
class Result:
    name: str
    status: str
    note: str
    compile_s: float = 0.0
    proof_bpf_insns: int | None = None


def load_benches(config_path: Path) -> list[Bench]:
    data = yaml.safe_load(config_path.read_text(encoding="utf-8"))
    benches: list[Bench] = []
    for item in data["benchmarks"]:
        if item.get("expected_result") is None or item.get("input_generator") is None:
            continue
        benches.append(Bench(name=item["name"], stage2="stage2" in set(item.get("tags", []))))
    return benches


def default_native_build_dir(config: ArchConfig, benches: list[Bench]) -> Path:
    has_stage2 = any(bench.stage2 for bench in benches)
    has_non_stage2 = any(not bench.stage2 for bench in benches)
    if has_stage2 and has_non_stage2:
        raise RuntimeError("mixed stage2 and non-stage2 proof suites are not supported")
    return config.stage2_native_build_dir if has_stage2 else config.native_build_dir


def run_cmd(cmd: list[str]) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        cmd,
        cwd=REPO_ROOT,
        check=False,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )


def require_ok(cmd: list[str]) -> None:
    result = run_cmd(cmd)
    if result.returncode != 0:
        out = (result.stdout or "").strip()
        err = (result.stderr or "").strip()
        detail = "\n".join(part for part in [out, err] if part)
        raise RuntimeError(f"{' '.join(cmd)} failed\n{detail}")


def native_object_path(name: str, native_build_dir: Path) -> Path:
    for suffix in (".native.o", ".native.so"):
        path = native_build_dir / f"{name}{suffix}"
        if path.is_file():
            return path
    raise RuntimeError(f"missing native object for {name} in {native_build_dir}")


def native_entry_symbol(objdump: str, native_obj: Path, symbols: list[str]) -> str:
    result = run_cmd([objdump, "-t", str(native_obj)])
    if result.returncode != 0:
        detail = "\n".join(part.strip() for part in (result.stdout, result.stderr) if part.strip())
        raise RuntimeError(f"{objdump} -t {native_obj} failed\n{detail}")
    present = {line.rsplit(None, 1)[-1] for line in result.stdout.splitlines() if line.strip()}
    for symbol in symbols:
        if symbol in present:
            return symbol
    raise RuntimeError(f"{native_obj}: none of the native symbols exist: {symbols}")


def build_proof_objects(
    config: ArchConfig,
    benches: list[Bench],
    *,
    native_build_dir: Path,
) -> Path:
    require_ok(["cargo", "build", "--release", "--manifest-path", str(NATIVE_LINK_MANIFEST)])
    proof_object_dir = config.source_dir / "build" / "native-link"
    proof_object_dir.mkdir(parents=True, exist_ok=True)
    for bench in benches:
        native_obj = native_object_path(bench.name, native_build_dir)
        symbol = native_entry_symbol(
            config.objdump,
            native_obj,
            [bench.name, f"{bench.name}_xdp", f"{bench.name}_prog"],
        )
        proof_obj = proof_object_dir / f"{bench.name}.proof.o"
        require_ok([
            str(NATIVE_LINK_BIN),
            "--input", str(native_obj),
            "--symbol", symbol,
            "--output", str(proof_obj),
            "--mode", "proof",
        ])
    return proof_object_dir


def generate_sources(
    config: ArchConfig,
    only: list[str],
    *,
    proof_config_path: Path,
    proof_object_dir: Path,
) -> None:
    cmd = ["python3", str(config.source_dir / "generate_micro_sim_proofs.py")]
    cmd.extend(["--config", str(proof_config_path)])
    cmd.extend(["--proof-object-dir", str(proof_object_dir)])
    if only:
        cmd.extend(["--only", *only])
    require_ok(cmd)


def write_compile_metadata(
    *,
    config: ArchConfig,
    bench: Bench,
    src: Path,
    obj: Path,
    cmd: list[str],
    compile_s: float,
) -> None:
    metadata = {
        "arch": config.name,
        "name": bench.name,
        "source": str(src),
        "object": str(obj),
        "compile_ns": int(compile_s * 1_000_000_000),
        "compile_s": compile_s,
        "command": cmd,
    }
    (obj.parent / f"{bench.name}.compile.json").write_text(
        json.dumps(metadata, indent=2, sort_keys=True) + "\n",
        encoding="utf-8",
    )


def compile_object(
    config: ArchConfig,
    bench: Bench,
    build_dir: Path,
) -> tuple[Result | None, float]:
    src = config.source_dir / f"{bench.name}.bpf.c"
    obj = build_dir / f"{bench.name}.bpf.o"
    if not src.exists():
        return Result(bench.name, "compile-fail", f"missing generated source: {src}"), 0.0
    build_dir.mkdir(parents=True, exist_ok=True)
    cmd = [
        "clang",
        "-g",
        config.clang_opt,
        "-mcpu=v4",
        "-target",
        "bpf",
        "-mllvm",
        f"-bpf-stack-size={BPF_STACK_SIZE}",
        config.target_define,
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
    compile_s = time.monotonic() - start
    if result.returncode != 0:
        return Result(
            bench.name,
            "compile-fail",
            compact_error(result.stderr or result.stdout or "clang failed"),
            compile_s=compile_s,
        ), compile_s
    write_compile_metadata(
        config=config,
        bench=bench,
        src=src,
        obj=obj,
        cmd=cmd,
        compile_s=compile_s,
    )
    return None, compile_s


def bpf_instruction_count(obj: Path) -> int:
    result = run_cmd(["llvm-readelf", "-SW", str(obj)])
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


def build_bench(config: ArchConfig, bench: Bench, build_dir: Path) -> Result:
    compile_result, compile_s = compile_object(config, bench, build_dir)
    if compile_result is not None:
        return compile_result
    result = Result(bench.name, "ok", "", compile_s=compile_s)
    try:
        result.proof_bpf_insns = bpf_instruction_count(build_dir / f"{bench.name}.bpf.o")
    except RuntimeError as exc:
        result.note = f"proof BPF count failed: {exc}"
    return result


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
        or "too large" in line
        or "too complex" in line
        or "processed" in line
    ]
    chosen = interesting[-2:] if interesting else lines[-2:]
    return " | ".join(chosen)[:500]


def markdown_table(results: list[Result]) -> str:
    lines = [
        "| Micro program | Status | Compile s | Proof BPF insns | Note |",
        "| --- | --- | ---: | ---: | --- |",
    ]
    for result in results:
        note = result.note.replace("|", "\\|")
        proof_insns = "" if result.proof_bpf_insns is None else str(result.proof_bpf_insns)
        lines.append(
            f"| `{result.name}` | {result.status} | "
            f"{result.compile_s:.3f} | {proof_insns} | {note} |"
        )
    return "\n".join(lines)


def print_result(result: Result) -> None:
    print(
        f"{result.name}: {result.status}: "
        f"compile={result.compile_s:.3f}s "
        f"proof_insns={result.proof_bpf_insns or ''} {result.note}",
        flush=True,
    )


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--arch", choices=sorted(ARCHES), required=True)
    parser.add_argument("--only", nargs="*", help="optional micro benchmark names")
    parser.add_argument("--build-dir", type=Path)
    parser.add_argument("--native-build-dir", type=Path)
    parser.add_argument("--config", type=Path, default=CONFIG)
    parser.add_argument("--jobs", type=int, default=min(8, os.cpu_count() or 1))
    args = parser.parse_args(argv)
    if args.jobs < 1:
        raise SystemExit("--jobs must be >= 1")

    config = ARCHES[args.arch]
    build_dir = (args.build_dir or config.build_dir).resolve()
    proof_config_path = args.config.resolve()
    benches = load_benches(proof_config_path)
    only = set(args.only or [])
    if only:
        benches = [bench for bench in benches if bench.name in only]
    if not benches:
        raise SystemExit("no selected benchmarks")
    native_build_dir = (
        args.native_build_dir.resolve()
        if args.native_build_dir is not None
        else default_native_build_dir(config, benches).resolve()
    )

    proof_object_dir = build_proof_objects(
        config,
        benches,
        native_build_dir=native_build_dir,
    )
    generate_sources(
        config,
        [bench.name for bench in benches] if only else [],
        proof_config_path=proof_config_path,
        proof_object_dir=proof_object_dir,
    )

    results_by_name: dict[str, Result] = {}
    with ThreadPoolExecutor(max_workers=args.jobs) as executor:
        futures = {
            executor.submit(build_bench, config, bench, build_dir): bench
            for bench in benches
        }
        for future in as_completed(futures):
            result = future.result()
            results_by_name[futures[future].name] = result
            print_result(result)

    results = [results_by_name[bench.name] for bench in benches]
    print(markdown_table(results))
    return 0 if all(result.status == "ok" for result in results) else 1


if __name__ == "__main__":
    raise SystemExit(main())
