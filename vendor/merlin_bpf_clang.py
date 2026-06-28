#!/usr/bin/env python3
from __future__ import annotations

import argparse
import os
from pathlib import Path
import subprocess
import sys
import tempfile


def run_checked(cmd: list[str]) -> None:
    if os.environ.get("MERLIN_BPF_CLANG_VERBOSE"):
        print("+ " + " ".join(cmd), file=sys.stderr)
    subprocess.run(cmd, check=True)


def require_file(path: Path, description: str) -> None:
    if not path.is_file():
        raise FileNotFoundError(f"{description} not found: {path}")


def find_output(args: list[str]) -> Path | None:
    for idx, arg in enumerate(args):
        if arg == "-o":
            if idx + 1 >= len(args):
                raise ValueError("clang -o requires an output path")
            if args[idx + 1] == "-":
                return None
            return Path(args[idx + 1]).resolve()
        if arg.startswith("-o") and len(arg) > 2:
            return Path(arg[2:]).resolve()
    return None


def output_to_stdout(args: list[str]) -> bool:
    for idx, arg in enumerate(args):
        if arg == "-o":
            if idx + 1 >= len(args):
                raise ValueError("clang -o requires an output path")
            return args[idx + 1] == "-"
        if arg == "-o-":
            return True
    return False


def source_paths(args: list[str]) -> list[Path]:
    out: list[Path] = []
    skip_next = False
    takes_value = {
        "-D",
        "-I",
        "-include",
        "-isystem",
        "-idirafter",
        "-iquote",
        "-MF",
        "-MT",
        "-MQ",
        "-o",
        "-target",
        "--target",
        "-mcpu",
        "-x",
        "-Xclang",
    }
    for idx, arg in enumerate(args):
        if skip_next:
            skip_next = False
            continue
        if arg in takes_value:
            skip_next = True
            continue
        if arg.startswith("-"):
            continue
        if arg.endswith((".c", ".h", ".S", ".bc", ".ll")):
            out.append(Path(arg))
    return out


def is_otel_ebpf_ir_compile(args: list[str], output: Path | None) -> bool:
    if output is None or output.suffix == ".ll":
        return False
    if ".ebpf." in output.name:
        return True
    return any(path.name.endswith(".ebpf.c") for path in source_paths(args))


def target_arg(args: list[str]) -> str | None:
    for idx, arg in enumerate(args):
        if arg in {"-target", "--target"}:
            if idx + 1 >= len(args):
                raise ValueError(f"{arg} requires a target")
            return args[idx + 1]
        if arg.startswith("--target="):
            return arg.split("=", 1)[1]
    return None


def has_flag(args: list[str], flag: str) -> bool:
    return any(arg == flag for arg in args)


def is_bpf_target(args: list[str]) -> bool:
    target = target_arg(args)
    return target is not None and target.startswith("bpf")


def llc_arch(args: list[str]) -> str:
    target = target_arg(args) or "bpf"
    if target.startswith("bpfel"):
        return "bpfel"
    if target.startswith("bpfeb"):
        return "bpfeb"
    return "bpf"


def llc_cpu_args(args: list[str]) -> list[str]:
    out: list[str] = []
    for idx, arg in enumerate(args):
        if arg == "-mcpu":
            if idx + 1 >= len(args):
                raise ValueError("-mcpu requires a value")
            out.extend(["-mcpu", args[idx + 1]])
        elif arg.startswith("-mcpu="):
            out.append(arg)
    return out


def replace_output(args: list[str], output: Path) -> list[str]:
    out: list[str] = []
    idx = 0
    replaced = False
    while idx < len(args):
        arg = args[idx]
        if arg == "-o":
            if idx + 1 >= len(args):
                raise ValueError("clang -o requires an output path")
            out.extend(["-o", str(output)])
            idx += 2
            replaced = True
            continue
        if arg.startswith("-o") and len(arg) > 2:
            out.extend(["-o", str(output)])
            idx += 1
            replaced = True
            continue
        out.append(arg)
        idx += 1
    if not replaced:
        out.extend(["-o", str(output)])
    return out


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


def merlin_transform_ir(
    *,
    opt: str,
    mode: str,
    atomic_plugin: Path,
    align_plugin: Path,
    input_bc: Path,
    tmpdir: Path,
) -> Path:
    current_bc = input_bc
    if mode in {"atomic", "both"}:
        next_bc = tmpdir / "atomic.bc"
        run_merlin_pass(
            opt=opt,
            plugin=atomic_plugin,
            pass_name="atomicbpf",
            input_bc=current_bc,
            output_bc=next_bc,
        )
        current_bc = next_bc

    if mode in {"align", "both"}:
        next_bc = tmpdir / "align.bc"
        run_merlin_pass(
            opt=opt,
            plugin=align_plugin,
            pass_name="alignbpf",
            input_bc=current_bc,
            output_bc=next_bc,
        )
        current_bc = next_bc
    return current_bc


def delegate(clang: str, clang_args: list[str]) -> int:
    return subprocess.run([clang, *clang_args]).returncode


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--clang", default="clang-18")
    parser.add_argument("--llc", default="llc-18")
    parser.add_argument("--opt", default="opt-18")
    parser.add_argument("--mode", choices=("none", "roundtrip", "atomic", "align", "both"), default="none")
    parser.add_argument("--atomic-plugin", required=True)
    parser.add_argument("--align-plugin", required=True)
    args, clang_args = parser.parse_known_args()

    if args.mode == "none":
        return delegate(args.clang, clang_args)

    output = find_output(clang_args)
    to_stdout = output_to_stdout(clang_args)
    if not has_flag(clang_args, "-c"):
        return delegate(args.clang, clang_args)
    if output is None and not to_stdout:
        return delegate(args.clang, clang_args)

    atomic_plugin = Path(args.atomic_plugin).resolve()
    align_plugin = Path(args.align_plugin).resolve()

    if has_flag(clang_args, "-emit-llvm"):
        if not is_otel_ebpf_ir_compile(clang_args, output):
            return delegate(args.clang, clang_args)
        assert output is not None
        output.parent.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix=f".{output.name}.", dir=output.parent) as tmp:
            tmpdir = Path(tmp)
            input_bc = tmpdir / "input.bc"
            compile_args = replace_output(clang_args, input_bc)
            run_checked([args.clang, *compile_args])
            current_bc = merlin_transform_ir(
                opt=args.opt,
                mode=args.mode,
                atomic_plugin=atomic_plugin,
                align_plugin=align_plugin,
                input_bc=input_bc,
                tmpdir=tmpdir,
            )
            os.replace(current_bc, output)
        return 0

    if not is_bpf_target(clang_args):
        return delegate(args.clang, clang_args)

    temp_parent = output.parent if output is not None else Path(os.environ.get("TMPDIR", "/tmp"))
    temp_parent.mkdir(parents=True, exist_ok=True)
    temp_prefix = f".{output.name}." if output is not None else ".merlin-bpf-stdout."
    with tempfile.TemporaryDirectory(prefix=temp_prefix, dir=temp_parent) as tmp:
        tmpdir = Path(tmp)
        input_bc = tmpdir / "input.bc"
        compile_args = replace_output(clang_args, input_bc)
        if "-emit-llvm" not in compile_args:
            compile_args.insert(0, "-emit-llvm")
        run_checked([args.clang, *compile_args])
        current_bc = merlin_transform_ir(
            opt=args.opt,
            mode=args.mode,
            atomic_plugin=atomic_plugin,
            align_plugin=align_plugin,
            input_bc=input_bc,
            tmpdir=tmpdir,
        )

        tmp_output = tmpdir / (output.name if output is not None else "stdout.o")
        run_checked(
            [
                args.llc,
                f"-march={llc_arch(clang_args)}",
                *llc_cpu_args(clang_args),
                "-filetype=obj",
                str(current_bc),
                "-o",
                str(tmp_output),
            ]
        )
        if output is None:
            sys.stdout.buffer.write(tmp_output.read_bytes())
        else:
            os.replace(tmp_output, output)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
