#!/usr/bin/env python3
"""Generate and compile arm64 simulator proofs from native app proof objects."""

from __future__ import annotations

import argparse
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
DEFAULT_SOURCE_DIR = DEFAULT_OUTPUT_DIR / "src"
DEFAULT_PROOF_DIR = DEFAULT_OUTPUT_DIR / "proof-objects"


@dataclass(frozen=True)
class AppProof:
    name: str
    source: Path


def run(cmd: list[str], *, cwd: Path = REPO_ROOT) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        cmd,
        cwd=cwd,
        check=False,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
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


def discover(proof_root: Path, apps: set[str], only: set[str], limit: int | None) -> list[AppProof]:
    proofs: list[AppProof] = []
    for app_dir in sorted(path for path in proof_root.iterdir() if path.is_dir()):
        app = app_dir.name
        if apps and app not in apps:
            continue
        for proof in sorted(app_dir.glob("*.proof.o")):
            name = safe_name(app, proof)
            if only and name not in only and proof.name.removesuffix(".proof.o") not in only:
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


def generate_source(config_path: Path, proof_dir: Path, source_dir: Path, proof: AppProof) -> tuple[bool, str]:
    source_dir.mkdir(parents=True, exist_ok=True)
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
    return True, ""


def compile_source(source: Path, build_dir: Path) -> tuple[bool, str]:
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
    result = run(cmd)
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
    parser.add_argument("--limit", type=int)
    parser.add_argument("--keep-going", action="store_true")
    args = parser.parse_args(argv)

    if args.limit is not None and args.limit < 1:
        raise SystemExit("--limit must be >= 1")

    output_dir = args.output_dir.resolve()
    proof_dir = output_dir / "proof-objects"
    source_dir = output_dir
    config_path = output_dir / "app_proofs.yaml"
    proofs = discover(args.proof_root.resolve(), set(args.app), set(args.only), args.limit)
    if not proofs:
        raise SystemExit("no selected app proof objects")

    prepare_generator_inputs(proofs, proof_dir, config_path)
    source_dir.mkdir(parents=True, exist_ok=True)
    for old in source_dir.glob("*.bpf.c"):
        old.unlink()

    failures: list[str] = []
    for proof in proofs:
        ok, note = generate_source(config_path, proof_dir, source_dir, proof)
        if not ok:
            print(f"fail {proof.name}: {note}")
            failures.append(proof.name)
            if not args.keep_going:
                break
            continue
        source = source_dir / f"{proof.name}.bpf.c"
        ok, note = compile_source(source, args.build_dir.resolve())
        if ok:
            print(f"ok {proof.name}")
            continue
        print(f"fail {proof.name}: {note}")
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
