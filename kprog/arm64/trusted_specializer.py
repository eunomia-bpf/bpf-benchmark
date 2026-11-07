"""AArch64 generation worker for the kernel-backed trusted specializer.

The common service supplies kernel-copied native bytes and normalized metadata
whose program/map identities it checked against the pinned source program.
Transport, capability registration, proof upload and request binding belong to
that service. This module only generates fresh artifacts in its private job dir.
"""
from __future__ import annotations

import hashlib
import importlib.util
import json
from pathlib import Path
import subprocess
import sys
import sysconfig


ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "kprog"))
from trusted_generation import declarations, validate_native
sys.path.insert(0, str(ROOT / "kprog/arm64/micro-prog"))
_SPEC = importlib.util.spec_from_file_location("kprog_arm64_trusted_generator",
    ROOT / "kprog/arm64/micro-prog/generate_micro_sim_proofs.py")
gen = importlib.util.module_from_spec(_SPEC)
sys.modules[_SPEC.name] = gen
_SPEC.loader.exec_module(gen)


def specialize(native_bytes: bytes, entry_symbol: str, metadata: dict,
               output_dir: Path, native_link: Path) -> dict:
    """Generate from one immutable native request, without any proof/source input.

    ``metadata`` is the generation view, normalized by the common trusted
    service from the pinned program/maps. It has no paths, C or compiler flags.
    The returned paths are freshly created worker outputs, never producer paths.
    """
    validate_native(native_bytes, entry_symbol, "EM_AARCH64")
    declarations(metadata)
    output_dir = Path(output_dir).resolve()
    output_dir.mkdir(parents=True, mode=0o700)
    native = output_dir / "request.native.o"
    native.write_bytes(native_bytes)
    name = "trusted_arm64"
    native_proof = output_dir / (name + ".proof.o")

    def run(command):
        command = [str(x) for x in command]
        result = subprocess.run(command, text=True, capture_output=True)
        with (output_dir / "commands.jsonl").open("a") as log:
            log.write(json.dumps(dict(command=command, returncode=result.returncode,
                                     stdout=result.stdout, stderr=result.stderr)) + "\n")
        result.check_returncode()

    run([native_link, "--input", native, "--symbol", entry_symbol,
         "--mode", "proof", "--preserve-entry-abi", "--output", native_proof])
    functions, rodata = gen.parse_native_linked_program(gen.Bench(name, entry_symbol, "raw"), output_dir)
    kind = {6: "xdp", 3: "tc", 8: "cgroup_skb"}.get(metadata["prog_type"], "raw")
    source = output_dir / (name + ".bpf.c")
    text = gen.render_program(name, entry_symbol, functions, kind, rodata16=rodata,
        linked_exit=True, program_section=metadata["section"],
        trusted_map_bindings=[dict(native_symbol=m["name"], value_offset=m.get("value_offset")) for m in metadata["maps"]])
    text = text.replace('#include "../arm64_sim_local_bpf.h"',
                        '#include ' + json.dumps(str(ROOT / "kprog/arm64/arm64_sim_local_bpf.h")))
    source.write_text(text)
    obj = output_dir / (name + ".bpf.o")
    run(["clang", "-g", "-O2", "-mcpu=v4", "-target", "bpf",
         "-mllvm", "-bpf-stack-size=4096", "-D__TARGET_ARCH_arm64",
         "-I", ROOT / "vendor/libbpf/include/uapi", "-I", ROOT / "vendor/libbpf/src",
         "-I", Path("/usr/include") / sysconfig.get_config_var("MULTIARCH"),
         "-c", source, "-o", obj])
    result = dict(native_object=str(native), native_proof_object=str(native_proof),
        simulator_object=str(obj), simulator_program=name + "_arm64_sim_xdp",
        symbol=entry_symbol, native_sha256=hashlib.sha256(native_bytes).hexdigest())
    (output_dir / "artifacts.json").write_text(json.dumps(result, indent=2) + "\n")
    return result
