#!/usr/bin/env python3
"""Generate and compile arm64 simulator proofs from native app proof objects."""

from __future__ import annotations

import argparse
import os
import re
import shutil
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[2]
ARM64_SIM_DIR = Path(__file__).resolve().parent
GENERATOR = ARM64_SIM_DIR / "micro-prog" / "generate_micro_sim_proofs.py"
DEFAULT_PROOF_ROOT = REPO_ROOT / "vendor" / "build" / "native-bpf" / "arm64" / "stage"
DEFAULT_OUTPUT_DIR = ARM64_SIM_DIR / "app-prog"
DEFAULT_BUILD_DIR = DEFAULT_OUTPUT_DIR / "build"


@dataclass(frozen=True)
class AppProof:
    name: str
    source: Path


def run(cmd: list[str], *, cwd: Path = REPO_ROOT,
        timeout_s: int | None = None) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        cmd,
        cwd=cwd,
        check=False,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        timeout=timeout_s,
    )


def compact(text: str, limit: int = 1200) -> str:
    text = text.strip()
    if len(text) <= limit:
        return text
    head = text[: limit // 3].rstrip()
    tail = text[-(limit - len(head) - 6):].lstrip()
    return head + "\n...\n" + tail


def safe_name(app: str, proof: Path) -> str:
    stem = proof.name.removesuffix(".proof.o")
    name = f"{app}_{stem}"
    name = re.sub(r"[^A-Za-z0-9_]", "_", name)
    if not name or name[0].isdigit():
        name = f"proof_{name}"
    return name


def discover(proof_root: Path, apps: set[str], only: set[str], offset: int, limit: int | None) -> list[AppProof]:
    proofs: list[AppProof] = []
    skipped = 0
    forbidden: list[Path] = []
    app_dirs = sorted(path for path in proof_root.iterdir() if path.is_dir())
    for app_dir in app_dirs:
        app = app_dir.name
        if apps and app not in apps:
            continue
        for proof in sorted(app_dir.glob("*.proof.o")):
            if app == "cilium" and proof.name.startswith("cilium_placeholders."):
                forbidden.append(proof)
    if forbidden:
        paths = "\n".join(str(path) for path in forbidden)
        raise SystemExit(f"forbidden Cilium placeholder proof objects in proof root:\n{paths}")
    for app_dir in app_dirs:
        app = app_dir.name
        if apps and app not in apps:
            continue
        for proof in sorted(app_dir.glob("*.proof.o")):
            name = safe_name(app, proof)
            if only and name not in only and proof.name.removesuffix(".proof.o") not in only:
                continue
            if skipped < offset:
                skipped += 1
                continue
            proofs.append(AppProof(name, proof))
            if limit is not None and len(proofs) >= limit:
                return proofs
    return proofs


def prepare_generator_inputs(proofs: list[AppProof], proof_dir: Path, config_path: Path) -> None:
    proof_dir.mkdir(parents=True, exist_ok=True)
    for old in proof_dir.glob("*.proof.o"):
        old.unlink()
    for proof in proofs:
        shutil.copyfile(proof.source, proof_dir / f"{proof.name}.proof.o")

    lines = ["benchmarks:"]
    for proof in proofs:
        lines.extend([
            f"  - name: {proof.name}",
            "    tags: [app-proof]",
        ])
    config_path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def undefined_symbols(proof: Path) -> list[str]:
    result = run(["llvm-nm-18", "--undefined-only", "--format=posix", str(proof)])
    if result.returncode != 0:
        detail = result.stderr or result.stdout or "llvm-nm-18 failed"
        raise RuntimeError(compact(detail))
    symbols: list[str] = []
    for line in result.stdout.splitlines():
        fields = line.split()
        if not fields:
            continue
        symbol = fields[0]
        if symbol.startswith("bpf_") or symbol in {"memcpy", "memset"}:
            continue
        if re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", symbol):
            symbols.append(symbol)
    return sorted(set(symbols))


def prepend_externs(source: Path, proof: Path) -> None:
    symbols = undefined_symbols(proof)
    if not symbols:
        return
    prelude = "".join(f"extern char {symbol};\n" for symbol in symbols)
    text = source.read_text(encoding="utf-8")
    source.write_text(prelude + text, encoding="utf-8")


def generate_source(config_path: Path, proof_dir: Path, source_dir: Path, proof: AppProof) -> tuple[bool, str]:
    source_dir.mkdir(parents=True, exist_ok=True)
    source = source_dir / f"{proof.name}.bpf.c"
    result = run([
        "python3",
        str(GENERATOR),
        "--config",
        str(config_path),
        "--proof-object-dir",
        str(proof_dir),
        "--output-dir",
        str(source_dir),
        "--compact",
        "--only",
        proof.name,
    ])
    if result.returncode != 0:
        detail = "\n".join(part for part in [result.stdout, result.stderr] if part)
        return False, compact(detail)
    if not source.is_file():
        detail = "\n".join(part for part in [result.stdout, result.stderr] if part)
        if not detail:
            detail = "generator did not write expected source"
        return False, compact(detail)
    try:
        prepend_externs(source, proof.source)
    except RuntimeError as err:
        return False, str(err)
    return True, ""


def compile_source(source: Path, build_dir: Path, timeout_s: int) -> tuple[bool, str]:
    build_dir.mkdir(parents=True, exist_ok=True)
    obj = build_dir / source.with_suffix(".bpf.o").name
    cmd = [
        "clang",
        "-g",
        "-O2",
        "-mcpu=v4",
        "-target",
        "bpf",
        "-mllvm",
        "-bpf-stack-size=4096",
        "-D__TARGET_ARCH_arm64",
        "-I",
        str(REPO_ROOT / "vendor" / "libbpf" / "include" / "uapi"),
        "-I",
        str(REPO_ROOT / "vendor" / "libbpf" / "src"),
        "-I",
        "/usr/include/x86_64-linux-gnu",
        "-c",
        str(source),
        "-o",
        str(obj),
    ]
    try:
        result = run(cmd, timeout_s=timeout_s)
    except subprocess.TimeoutExpired as err:
        detail = f"clang timed out after {timeout_s}s compiling {source.name}"
        timed_out_output = "\n".join(
            part.decode(errors="replace") if isinstance(part, bytes) else part
            for part in [err.stdout, err.stderr]
            if part
        )
        if timed_out_output:
            detail += "\n" + timed_out_output
        return False, compact(detail)
    if result.returncode == 0:
        return True, ""
    return False, compact(result.stderr or result.stdout or "clang failed")


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--proof-root", type=Path, default=DEFAULT_PROOF_ROOT)
    parser.add_argument("--output-dir", type=Path, default=DEFAULT_OUTPUT_DIR)
    parser.add_argument("--build-dir", type=Path, default=DEFAULT_BUILD_DIR)
    parser.add_argument("--app", action="append", default=[])
    parser.add_argument("--only", action="append", default=[])
    parser.add_argument("--offset", type=int, default=0)
    parser.add_argument("--limit", type=int)
    parser.add_argument("--compile-timeout-s", type=int, default=120)
    parser.add_argument("--keep-going", action="store_true")
    args = parser.parse_args(argv)

    if args.offset < 0:
        raise SystemExit("--offset must be >= 0")
    if args.limit is not None and args.limit < 1:
        raise SystemExit("--limit must be >= 1")
    if args.compile_timeout_s < 1:
        raise SystemExit("--compile-timeout-s must be >= 1")

    output_dir = args.output_dir.resolve()
    run_dir = output_dir.with_name(f"{output_dir.name}-run-{os.getpid()}")
    proof_dir = run_dir / "proof-objects"
    source_dir = run_dir
    config_path = run_dir / "app_proofs.yaml"
    build_dir = args.build_dir.resolve() / f"run-{os.getpid()}"
    proofs = discover(args.proof_root.resolve(), set(args.app), set(args.only), args.offset, args.limit)
    if not proofs:
        raise SystemExit("no selected app proof objects")

    prepare_generator_inputs(proofs, proof_dir, config_path)

    failures: list[str] = []
    for proof in proofs:
        ok, note = generate_source(config_path, proof_dir, source_dir, proof)
        if not ok:
            print(f"fail {proof.name}: {note}", flush=True)
            failures.append(proof.name)
            if not args.keep_going:
                break
            continue
        source = source_dir / f"{proof.name}.bpf.c"
        ok, note = compile_source(source, build_dir, args.compile_timeout_s)
        if ok:
            print(f"ok {proof.name}", flush=True)
            continue
        print(f"fail {proof.name}: {note}", flush=True)
        failures.append(proof.name)
        if not args.keep_going:
            break

    if failures:
        print(f"app proof smoke failed: {len(failures)}/{len(proofs)} failed", file=sys.stderr)
        return 1
    print(f"app proof smoke passed: {len(proofs)} generated and compiled")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
