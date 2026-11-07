"""Fresh x86-64 generation adapter for the kernel-backed trusted service."""
from __future__ import annotations
import hashlib
import importlib.util
import json
import os
import shutil
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "kprog"))
from trusted_generation import declarations, validate_native
sys.path.insert(0, str(ROOT / "kprog/x86/micro-prog"))

_SPEC = importlib.util.spec_from_file_location("kprog_x86_trusted_generator",
    ROOT / "kprog/x86/micro-prog/generate_micro_sim_proofs.py")
gen = importlib.util.module_from_spec(_SPEC)
sys.modules[_SPEC.name] = gen
_SPEC.loader.exec_module(gen)


def specialize(native_bytes: bytes, entry_symbol: str, metadata: dict,
               output_dir: Path, native_link: Path) -> dict:
    validate_native(native_bytes, entry_symbol, "EM_X86_64")
    declarations(metadata)
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
    kind = {6: "xdp", 3: "tc", 8: "cgroup_skb"}.get(metadata["prog_type"], "raw")
    source = output_dir / (name + ".bpf.c")
    text = gen.render_program(name, instructions, functions, kind=kind,
        exit_addr=exit_addr, rodata16=rodata, program_section=metadata["section"],
        trusted_map_bindings=[dict(native_symbol=m["name"], value_offset=m.get("value_offset")) for m in metadata["maps"]])
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
    run([clang, "-g", "-O3", "-mcpu=v4", "-target", "bpf",
         "-mllvm", "-bpf-stack-size=4096", "-D__TARGET_ARCH_x86",
         "-I", ROOT / "vendor/libbpf/include/uapi", "-I", ROOT / "vendor/libbpf/src",
         "-I", "/usr/include/x86_64-linux-gnu", "-c", source, "-o", obj])
    result = dict(native_object=str(native), native_proof_object=str(proof),
        simulator_object=str(obj), simulator_program=name + "_x86_sim_xdp",
        symbol=entry_symbol, native_sha256=hashlib.sha256(native_bytes).hexdigest())
    (output_dir / "artifacts.json").write_text(json.dumps(result, indent=2) + "\n")
    return result
