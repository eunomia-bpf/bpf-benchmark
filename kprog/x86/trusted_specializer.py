"""Fresh x86-64 generation adapter for the kernel-backed trusted service."""
from __future__ import annotations
import hashlib
import importlib.util
import json
import os
import re
import shutil
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "kprog"))
from trusted_generation import context_kind, declarations, validate_native
from kernel_function_abi import describe as kernel_functions
sys.path.insert(0, str(ROOT / "kprog/x86/micro-prog"))

_SPEC = importlib.util.spec_from_file_location("kprog_x86_trusted_generator",
    ROOT / "kprog/x86/micro-prog/generate_micro_sim_proofs.py")
gen = importlib.util.module_from_spec(_SPEC)
sys.modules[_SPEC.name] = gen
_SPEC.loader.exec_module(gen)


COMPILE_FLAGS = ["-g", "-O3", "-mcpu=v4", "-target", "bpf",
                 "-mllvm", "-bpf-stack-size=4096", "-D__TARGET_ARCH_x86",
                 "-I", ROOT / "vendor/libbpf/include/uapi", "-I", ROOT / "vendor/libbpf/src",
                 "-I", "/usr/include/x86_64-linux-gnu"]
# Clang gives a translation unit 2^31 bytes of source-location space and each
# macro expansion takes a share of it, so the instruction statements of a large
# B exhaust it while their expanded text stays far smaller. B is therefore
# preprocessed in pieces of whole instructions, each behind the same preamble
# (every directive of B sits in the preamble), and the joined token stream is
# compiled as one translation unit with the same compiler and flags.
INSTRUCTION_LABEL = re.compile(r"x86_l_[0-9a-f]+:")
PIECE_SOURCE_BYTES = 1 << 18
PIECE_MARK = "#pragma kprog_preprocessed_piece"


def compile_simulator(clang, source: Path, obj: Path, run, *, bounds_compiler=None) -> None:
    lines = source.read_text().split("\n")
    first = next(i for i, line in enumerate(lines) if INSTRUCTION_LABEL.fullmatch(line))
    bounds, start, size = [], first, 0
    for index in range(first, len(lines)):
        if index > start and size >= PIECE_SOURCE_BYTES and INSTRUCTION_LABEL.fullmatch(lines[index]):
            bounds.append((start, index))
            start, size = index, 0
        size += len(lines[index]) + 1
    bounds.append((start, len(lines)))
    location = json.dumps(str(source))
    preamble = "#line 1 " + location + "\n" + "\n".join(lines[:first]) + "\n"
    preprocessed = source.with_suffix(".i")
    # Keep one expanded piece live, rather than every piece plus a joined copy.
    # In particular, the parent must not retain the full B while clang optimizes it.
    with preprocessed.open("w") as joined:
        for number, (start, end) in enumerate(bounds):
            piece = source.with_name(f"{source.stem}.piece{number}.c")
            piece.write_text(preamble + PIECE_MARK + "\n" + f"#line {start + 1} {location}\n"
                             + "\n".join(lines[start:end]) + "\n")
            expanded = piece.with_suffix(".i")
            run([clang, *COMPILE_FLAGS, "-E", piece, "-o", expanded])
            head, body = expanded.read_text().split(PIECE_MARK + "\n")
            if number == 0:
                joined.write(head)
            joined.write(body)
    compiled_input = preprocessed
    if bounds_compiler:
        initial, lowered = source.with_suffix('.bounds-input.bc'), source.with_suffix('.bounds.bc')
        run([clang, *COMPILE_FLAGS, '-emit-llvm', '-c', preprocessed, '-o', initial])
        run([bounds_compiler, initial, '-o', lowered])
        compiled_input = lowered
    run([clang, *COMPILE_FLAGS, "-c", compiled_input, "-o", obj])


def specialize(native_bytes: bytes, entry_symbol: str, metadata: dict,
               output_dir: Path, native_link: Path, *, kernel_btf='/sys/kernel/btf/vmlinux', bounds_compiler=None) -> dict:
    validate_native(native_bytes, entry_symbol, "EM_X86_64")
    declarations(metadata)
    kind = context_kind(metadata["prog_type"])
    output_dir = Path(output_dir).resolve()
    output_dir.mkdir(parents=True, mode=0o700)
    native = output_dir / "request.native.o"
    native.write_bytes(native_bytes)
    name = "trusted_x86"
    proof = output_dir / (name + ".proof.o")

    def run(command):
        command = [str(x) for x in command]
        result = subprocess.run(command, text=True, capture_output=True)
        with (output_dir / "commands.jsonl").open("a") as log:
            log.write(json.dumps(dict(command=command, returncode=result.returncode,
                                     stdout=result.stdout, stderr=result.stderr)) + "\n")
        result.check_returncode()

    run([native_link, "--input", native, "--symbol", entry_symbol,
         "--mode", "proof", "--preserve-entry-abi", "--output", proof])
    instructions, functions, exit_addr, rodata = gen.parse_native_linked_program(name, output_dir)
    source = output_dir / (name + ".bpf.c")
    functions_abi = kernel_functions(native_bytes, {m['name'] for m in metadata['maps']}, kernel_btf) \
        if metadata.get('kernel_kfunc_context', False) else {}
    (output_dir / 'kernel-functions.json').write_text(json.dumps(functions_abi, indent=2) + '\n')
    text = gen.render_program(name, instructions, functions, kind=kind,
        exit_addr=exit_addr, rodata16=rodata, program_section=metadata["section"],
        trusted_map_bindings=[dict(native_symbol=m["name"], value_offset=m.get("value_offset")) for m in metadata["maps"]],
        kernel_functions=functions_abi)
    text = text.replace('#include "../x86_sim_local_bpf.h"',
                        '#include ' + json.dumps(str(ROOT / "kprog/x86/x86_sim_local_bpf.h")))
    source.write_text(text)
    obj = output_dir / (name + ".bpf.o")
    # `clang` need not be on PATH where the service runs: it re-launches
    # itself with an explicit environment, and the container image ships the
    # compiler under /usr/lib/llvm-*/bin. Resolve in this order so the
    # specializer works without any caller plumbing: CLANG, then PATH, then
    # the versioned llvm bin directories the build already uses.
    clang = os.environ.get("CLANG") or shutil.which("clang")
    if not clang:
        candidates = sorted(Path("/usr/lib").glob("llvm-*/bin/clang"))
        clang = str(candidates[-1]) if candidates else "clang"
    compile_simulator(clang, source, obj, run, bounds_compiler=bounds_compiler)
    result = dict(native_object=str(native), native_proof_object=str(proof),
        simulator_object=str(obj), simulator_program=name + "_x86_sim_xdp",
        simulator_source=str(source), simulator_preprocessed=str(source.with_suffix('.i')),
        context_kind=kind, symbol=entry_symbol, native_sha256=hashlib.sha256(native_bytes).hexdigest())
    (output_dir / "artifacts.json").write_text(json.dumps(result, indent=2) + "\n")
    return result


def compile_checked_simulator(artifacts: dict, native_link: Path, compiler: Path, *,
                              context_compiler=None, public_layout=None, physical_layout=None) -> dict:
    """Called by the service only after the stock verifier accepts B."""
    source = Path(artifacts['simulator_preprocessed'])
    copied = source.with_name('checked-simulator.i')
    shutil.copyfile(source, copied)
    directory = source.parent

    def run(command):
        result = subprocess.run([str(x) for x in command], text=True, capture_output=True)
        with (directory/'native-commands.jsonl').open('a') as log:
            log.write(json.dumps(dict(command=[str(x) for x in command], returncode=result.returncode,
                                      stdout=result.stdout, stderr=result.stderr))+'\n')
        result.check_returncode()

    clang = os.environ.get('CLANG') or shutil.which('clang')
    if not clang:
        raise RuntimeError('checked simulator compilation requires clang')
    ir, lowered = directory/'checked-simulator.bc', directory/'checked-simulator.native.bc'
    native, proof = directory/'checked-simulator.native.o', directory/'checked-simulator.proof.o'
    run([clang, *COMPILE_FLAGS, '-emit-llvm', '-c', copied, '-o', ir])
    run([compiler, ir, '-o', lowered])
    if artifacts['context_kind'] != 'raw':
        if not context_compiler or not public_layout or not physical_layout:
            raise ValueError('packet simulator native compilation requires target context compiler/layouts')
        context_ir = directory/'checked-simulator.context.bc'
        run([context_compiler, lowered, '--public-layout', public_layout,
             '--physical-layout', physical_layout, '-o', context_ir])
        lowered = context_ir
    run([clang, '-target', 'x86_64-linux-gnu', '-O3', '-fPIC', '-mno-red-zone',
         '-mgeneral-regs-only', '-fno-stack-protector', '-fno-asynchronous-unwind-tables',
         '-c', lowered, '-o', native])
    run([native_link, '--input', native, '--symbol', artifacts['simulator_program'],
         '--mode', 'proof', '--preserve-entry-abi', '--output', proof])
    result = dict(artifacts, native_object=str(native), native_proof_object=str(proof),
                  symbol=artifacts['simulator_program'])
    (directory/'checked-simulator.json').write_text(json.dumps(dict(
        source=str(source), copied_source=str(copied),
        source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),
        copied_source_sha256=hashlib.sha256(copied.read_bytes()).hexdigest(),
        executable_sha256=hashlib.sha256(native.read_bytes()).hexdigest(),
        context_layouts={str(p):hashlib.sha256(Path(p).read_bytes()).hexdigest()
                         for p in (public_layout, physical_layout) if p is not None},
        artifacts=result), indent=2)+'\n')
    return result
