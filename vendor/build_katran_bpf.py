#!/usr/bin/env python3
from __future__ import annotations

import argparse
import os
from pathlib import Path
import subprocess
import sys
import tempfile


BASE_CFLAGS = [
    "-DDEBUG",
    "-D__KERNEL__",
    "-Wno-unused-value",
    "-Wno-pointer-sign",
    "-Wno-compare-distinct-pointer-types",
    "-O2",
    "-emit-llvm",
    "-c",
    "-g",
]


def run_checked(cmd: list[str]) -> None:
    print("+ " + " ".join(cmd), file=sys.stderr)
    subprocess.run(cmd, check=True)


def require_file(path: Path, description: str) -> None:
    if not path.is_file():
        raise FileNotFoundError(f"{description} not found: {path}")


def run_merlin_pass(
    *,
    opt: str,
    plugin: Path,
    pass_name: str,
    input_bc: Path,
    output_bc: Path,
) -> None:
    require_file(plugin, f"Merlin {pass_name} plugin")
    run_checked(
        [
            opt,
            "-load-pass-plugin",
            str(plugin),
            f"-passes={pass_name}",
            str(input_bc),
            "-o",
            str(output_bc),
        ]
    )


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--input", required=True)
    parser.add_argument("--output", required=True)
    parser.add_argument("--katran-root", required=True)
    parser.add_argument("--clang", default="clang-18")
    parser.add_argument("--llc", default="llc-18")
    parser.add_argument("--opt", default="opt-18")
    parser.add_argument("--mode", choices=("none", "roundtrip", "atomic", "align", "both"), default="none")
    parser.add_argument("--atomic-plugin", required=True)
    parser.add_argument("--align-plugin", required=True)
    args = parser.parse_args()

    input_path = Path(args.input).resolve()
    output_path = Path(args.output).resolve()
    katran_root = Path(args.katran_root).resolve()
    atomic_plugin = Path(args.atomic_plugin).resolve()
    align_plugin = Path(args.align_plugin).resolve()

    require_file(input_path, "Katran BPF source")
    output_path.parent.mkdir(parents=True, exist_ok=True)

    with tempfile.TemporaryDirectory(prefix=f".{output_path.name}.", dir=output_path.parent) as tmp:
        tmpdir = Path(tmp)
        input_bc = tmpdir / "input.bc"
        current_bc = input_bc
        run_checked(
            [
                args.clang,
                f"-I{katran_root}",
                f"-I{katran_root / 'katran/lib/linux_includes'}",
                *BASE_CFLAGS,
                str(input_path),
                "-o",
                str(input_bc),
            ]
        )

        if args.mode in {"atomic", "both"}:
            next_bc = tmpdir / "atomic.bc"
            run_merlin_pass(
                opt=args.opt,
                plugin=atomic_plugin,
                pass_name="atomicbpf",
                input_bc=current_bc,
                output_bc=next_bc,
            )
            current_bc = next_bc

        if args.mode in {"align", "both"}:
            next_bc = tmpdir / "align.bc"
            run_merlin_pass(
                opt=args.opt,
                plugin=align_plugin,
                pass_name="alignbpf",
                input_bc=current_bc,
                output_bc=next_bc,
            )
            current_bc = next_bc

        tmp_output = tmpdir / output_path.name
        run_checked(
            [
                args.llc,
                "-march=bpf",
                "-filetype=obj",
                str(current_bc),
                "-o",
                str(tmp_output),
            ]
        )
        os.replace(tmp_output, output_path)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
