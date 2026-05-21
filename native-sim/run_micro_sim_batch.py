#!/usr/bin/env python3
"""Build and run generated ReverseSim micro proof artifacts."""

from __future__ import annotations

import argparse
import json
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


NATIVE_SIM_DIR = Path(__file__).resolve().parent
REPO_ROOT = NATIVE_SIM_DIR.parent
CONFIG = REPO_ROOT / "micro" / "config" / "micro_pure_jit.yaml"
LOADER_MANIFEST = NATIVE_SIM_DIR / "loader" / "Cargo.toml"
LOADER_BIN = NATIVE_SIM_DIR / "loader" / "target" / "debug" / "reversesim-loader"
NATIVE_LINK_MANIFEST = NATIVE_SIM_DIR / "x86" / "native_lab" / "native_link" / "Cargo.toml"
NATIVE_LINK_BIN = (
    NATIVE_SIM_DIR / "x86" / "native_lab" / "native_link" / "target" / "release" / "native-link"
)
MICRO_RESULTS_DIR = REPO_ROOT / "micro" / "results"
BPF_STACK_SIZE = os.environ.get("BPF_STACK_SIZE", "4096")

sys.path.insert(0, str(REPO_ROOT))
from runner.libs.input_generators import materialize_input  # noqa: E402


@dataclass(frozen=True)
class ArchConfig:
    name: str
    clang_opt: str
    target_define: str
    program_suffix: str
    result_glob: str
    require_micro_result: bool
    native_build_dir: Path
    stage2_native_build_dir: Path
    objdump: str

    @property
    def source_dir(self) -> Path:
        return NATIVE_SIM_DIR / self.name / "micro-prog"

    @property
    def build_dir(self) -> Path:
        return self.source_dir / "build"

    @property
    def results_dir(self) -> Path:
        return NATIVE_SIM_DIR / self.name / "results"


ARCHES = {
    "x86": ArchConfig(
        name="x86",
        clang_opt="-O3",
        target_define="-D__TARGET_ARCH_x86",
        program_suffix="_x86_sim_xdp",
        result_glob="x86_kvm_micro_*/metadata.json",
        require_micro_result=True,
        native_build_dir=REPO_ROOT / "micro" / "programs" / "build-x86",
        stage2_native_build_dir=REPO_ROOT / "native-sim" / "test" / "build-x86",
        objdump="objdump",
    ),
    "arm64": ArchConfig(
        name="arm64",
        clang_opt="-O2",
        target_define="-D__TARGET_ARCH_arm64",
        program_suffix="_arm64_sim_xdp",
        result_glob="arm64_qemu_micro_*/metadata.json",
        require_micro_result=False,
        native_build_dir=REPO_ROOT / "micro" / "programs" / "build-arm64",
        stage2_native_build_dir=REPO_ROOT / "native-sim" / "test" / "build-arm64",
        objdump="aarch64-linux-gnu-objdump",
    ),
}


@dataclass(frozen=True)
class Bench:
    name: str
    program_name: str
    input_generator: str
    expected_result: int
    expected_retval: int
    result_channel: str
    cgroup_skb_input: bool
    stage2: bool


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


def load_benches(config_path: Path) -> list[Bench]:
    data = yaml.safe_load(config_path.read_text(encoding="utf-8"))
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
                program_name=item.get("program_name", item["name"]),
                input_generator=generator,
                expected_result=int(expected),
                expected_retval=int(item.get("expected_retval", default_retval)),
                result_channel=result_channel,
                cgroup_skb_input="cgroup-skb" in tags,
                stage2="stage2" in tags,
            )
        )
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
            [bench.program_name, bench.name, f"{bench.name}_xdp", f"{bench.name}_prog"],
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


def build_loader() -> None:
    require_ok(["cargo", "build", "--manifest-path", str(LOADER_MANIFEST)])


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


def latest_micro_result_dir(config: ArchConfig) -> Path | None:
    override = os.environ.get("MICRO_RESULT_METADATA")
    if override:
        path = Path(override)
        return path.parent if path.name == "metadata.json" else path
    paths = sorted(MICRO_RESULTS_DIR.glob(config.result_glob), reverse=True)
    if not paths:
        if config.require_micro_result:
            raise RuntimeError("missing micro result metadata")
        return None
    for path in paths:
        dump_dir = path.parent / "details" / "jit_dumps"
        if any(dump_dir.glob("*__kernel__sample00.xlated.bin")):
            return path.parent
    return paths[0].parent if config.require_micro_result else None


def load_direct_bpf_counts(config: ArchConfig) -> dict[str, int]:
    result_dir = latest_micro_result_dir(config)
    if result_dir is None:
        return {}
    dump_dir = result_dir / "details" / "jit_dumps"
    counts: dict[str, int] = {}
    for path in dump_dir.glob("*__kernel__sample00.xlated.bin"):
        name = path.name.split("__kernel__sample00.xlated.bin", 1)[0]
        counts[name] = path.stat().st_size // 8
    return counts


def run_object(
    config: ArchConfig,
    bench: Bench,
    build_dir: Path,
    sudo: bool,
    run_id: str,
) -> Result:
    obj = build_dir / f"{bench.name}.bpf.o"
    input_path, _meta = materialize_input(bench.input_generator, force=False)
    verifier_log = config.results_dir / f"{bench.name}-{run_id}.verifier.log"
    config.results_dir.mkdir(parents=True, exist_ok=True)
    cmd = [
        str(LOADER_BIN),
        "--object",
        str(obj),
        "--program",
        f"{bench.name}{config.program_suffix}",
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
    start = time.monotonic()
    result = run_cmd(cmd)
    run_s = time.monotonic() - start
    verify_s, test_s = parse_loader_timing(f"{result.stdout or ''}\n{result.stderr or ''}")
    if result.returncode == 0:
        return Result(bench.name, "ok", "", verify_s=verify_s, test_s=test_s)
    return Result(
        bench.name,
        "run-fail",
        compact_error(result.stderr or result.stdout or "loader failed"),
        verify_s=verify_s,
        test_s=test_s or run_s,
    )


def add_note(result: Result, note: str) -> None:
    if note:
        result.note = f"{result.note}; {note}" if result.note else note


def run_bench(
    config: ArchConfig,
    bench: Bench,
    build_dir: Path,
    sudo: bool,
    run_id: str,
    direct_counts: dict[str, int],
    *,
    build_only: bool = False,
) -> Result:
    direct_count = direct_counts.get(bench.name)
    direct_note = "" if build_only or direct_count is not None else f"missing direct xlated.bin in {config.name} micro result"
    compile_result, compile_s = compile_object(config, bench, build_dir)
    if compile_result is not None:
        compile_result.direct_bpf_insns = direct_count
        add_note(compile_result, direct_note)
        return compile_result
    try:
        proof_count = bpf_instruction_count(build_dir / f"{bench.name}.bpf.o")
        proof_note = ""
    except RuntimeError as exc:
        proof_count = None
        proof_note = f"proof BPF count failed: {exc}"
    if build_only:
        result = Result(bench.name, "ok", "", compile_s=compile_s)
        result.proof_bpf_insns = proof_count
        result.direct_bpf_insns = direct_count
        add_note(result, proof_note)
        return result
    result = run_object(
        config,
        bench,
        build_dir,
        sudo=sudo,
        run_id=run_id,
    )
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


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--arch", choices=sorted(ARCHES), required=True)
    parser.add_argument("--only", nargs="*", help="optional micro benchmark names")
    parser.add_argument("--no-generate", action="store_true")
    parser.add_argument("--generate-only", action="store_true")
    parser.add_argument("--no-build-loader", action="store_true")
    parser.add_argument("--build-only", action="store_true")
    parser.add_argument("--build-dir", type=Path)
    parser.add_argument("--native-build-dir", type=Path)
    parser.add_argument("--config", type=Path, default=CONFIG)
    parser.add_argument("--no-sudo", action="store_true")
    parser.add_argument("--jobs", type=int, default=min(8, os.cpu_count() or 1))
    parser.add_argument("--markdown", type=Path)
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

    if not args.no_generate:
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
    if args.generate_only:
        return 0
    if not args.no_build_loader and not args.build_only:
        build_loader()

    direct_counts = (
        load_direct_bpf_counts(config)
        if not args.build_only and proof_config_path.name == "micro_pure_jit.yaml"
        else {}
    )
    run_id = datetime.now().strftime("%Y%m%d-%H%M%S-%f")
    results_by_name: dict[str, Result] = {}
    if args.jobs == 1:
        for bench in benches:
            result = run_bench(
                config, bench, build_dir,
                sudo=not args.no_sudo,
                run_id=run_id,
                direct_counts=direct_counts,
                build_only=args.build_only,
            )
            results_by_name[bench.name] = result
            print_result(result)
    else:
        print(f"running {len(benches)} benchmarks with {args.jobs} jobs", flush=True)
        with ThreadPoolExecutor(max_workers=args.jobs) as executor:
            futures = {
                executor.submit(
                    run_bench,
                    config,
                    bench,
                    build_dir,
                    not args.no_sudo,
                    run_id,
                    direct_counts,
                    build_only=args.build_only,
                ): bench
                for bench in benches
            }
            for future in as_completed(futures):
                bench = futures[future]
                result = future.result()
                results_by_name[bench.name] = result
                print_result(result)

    results = [results_by_name[bench.name] for bench in benches]
    table = markdown_table(results)
    if args.markdown is not None or not args.build_only:
        markdown_path = args.markdown or (config.results_dir / f"README-{run_id}.md")
        markdown_path.parent.mkdir(parents=True, exist_ok=True)
        markdown_path.write_text(table + "\n", encoding="utf-8")
        print(f"wrote {markdown_path}")
    print(table)
    return 0 if all(result.status == "ok" for result in results) else 1


if __name__ == "__main__":
    raise SystemExit(main())
