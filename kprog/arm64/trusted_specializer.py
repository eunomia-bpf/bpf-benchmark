"""Generate and compile B from the immutable AArch64 request copy.

The shared service owns request transport and map/helper resolution.
"""
from __future__ import annotations

import hashlib
import importlib.util
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import sysconfig


ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "kprog"))
from trusted_generation import context_kind, declarations, validate_native
sys.path.insert(0, str(ROOT / "kprog/arm64/micro-prog"))
_SPEC = importlib.util.spec_from_file_location("kprog_arm64_trusted_generator",
    ROOT / "kprog/arm64/micro-prog/generate_micro_sim_proofs.py")
gen = importlib.util.module_from_spec(_SPEC)
sys.modules[_SPEC.name] = gen
_SPEC.loader.exec_module(gen)
sys.path.insert(0, str(ROOT / "kprog/x86/micro-prog"))
from inline_scalar import pid_source

def b_flags() -> list:
    """The B compile flags shared by generation and the checked native leg."""
    flags = ["-w", "-g", "-O2", "-mcpu=v4", "-target", "bpf",
             "-mllvm", "-bpf-stack-size=4096", "-D__TARGET_ARCH_arm64",
             "-I", ROOT / "vendor/libbpf/include/uapi", "-I", ROOT / "vendor/libbpf/src"]
    sysroot = os.environ.get("KPROG_ARM64_SYSROOT")
    if sysroot is None:
        flags.extend(["-I", Path("/usr/include") / sysconfig.get_config_var("MULTIARCH")])
    else:
        flags.extend(["--sysroot=" + sysroot,
                      "-I", Path(sysroot) / "usr/include/aarch64-linux-gnu"])
    return flags


def specialize(native_bytes: bytes, entry_symbol: str, metadata: dict,
               output_dir: Path, native_link: Path) -> dict:
    """Generate fresh simulator source and objects in the worker job directory."""
    validate_native(native_bytes, entry_symbol, "EM_AARCH64")
    declarations(metadata)
    kind = context_kind(metadata["prog_type"])
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
    source = output_dir / (name + ".bpf.c")
    text = gen.render_program(name, entry_symbol, functions, kind, rodata16=rodata,
        linked_exit=True, program_section=metadata["section"],
        trusted_map_bindings=[dict(native_symbol=m["name"], value_offset=m.get("value_offset")) for m in metadata["maps"]])
    text = text.replace('#include "../arm64_sim_local_bpf.h"',
                        '#include ' + json.dumps(str(ROOT / "kprog/arm64/arm64_sim_local_bpf.h")))
    source.write_text(text)
    obj = output_dir / (name + ".bpf.o")
    compiler_state = os.environ.get("KPROG_TRUSTED_COMPILE_STATE")
    if compiler_state is None:
        run(["clang", *b_flags(), "-c", source, "-o", obj])
    else:
        run([sys.executable, ROOT / "kprog/trusted_compile.py", "submit",
             "--state", compiler_state, "--source", source, "--output", obj, "--arch", "arm64"])
    result = dict(native_object=str(native), native_proof_object=str(native_proof),
        simulator_object=str(obj), simulator_program=name + "_arm64_sim_xdp",
        simulator_source=str(source), context_kind=kind, maps=metadata["maps"],
        kernel_btf=str(os.environ.get("KPROG_KERNEL_BTF", "/sys/kernel/btf/vmlinux")),
        symbol=entry_symbol, native_sha256=hashlib.sha256(native_bytes).hexdigest())
    (output_dir / "artifacts.json").write_text(json.dumps(result, indent=2) + "\n")
    return result


AARCH64_TRIPLE = "aarch64-unknown-linux-gnu"
AARCH64_LAYOUT = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i8:8:32-i16:16:32-i64:64-i128:128-n32:64-S128"
# The arm64 body declares its volatile arena as an anonymous union, so the IR
# type is %union.anon rather than x86's named union. The checked tools accept
# the arena by name; both spellings are named so a body that gains a tag
# typedef keeps matching.
AARCH64_STACK_ARENA = "union.anon"
AARCH64_HELPER_FLAGS = ["-target", AARCH64_TRIPLE, "-O3", "-foptimize-sibling-calls",
                         "-fomit-frame-pointer", "-mgeneral-regs-only",
                         "-fno-stack-protector", "-fno-asynchronous-unwind-tables",
                         "-fno-unwind-tables"]


def compile_checked_simulator(artifacts: dict, native_link: Path, compiler: Path, *,
                              context_compiler=None, public_layout=None, physical_layout=None) -> dict:
    """Native aarch64 compilation of the B the stock verifier just accepted."""
    source = Path(artifacts["simulator_source"])
    directory = source.parent

    # Inside the guest the checked tools and the aarch64 compiler are host
    # builds, so each step runs through the same compiler broker that compiles
    # B; the guest keeps only paths and receipts.
    broker = os.environ.get("KPROG_TRUSTED_COMPILE_STATE")
    receipts = directory / "native-commands.jsonl"

    def run(command):
        command = [str(x) for x in command]
        command[0] = shutil.which(command[0]) or command[0]
        if broker is None:
            result = subprocess.run(command, text=True, capture_output=True)
            returncode, stdout, stderr = result.returncode, result.stdout, result.stderr
        else:
            receipt = directory / ("broker-" + hashlib.sha256(" ".join(command).encode()).hexdigest()[:16] + ".json")
            returncode = subprocess.run([sys.executable, str(ROOT / "kprog/trusted_compile.py"), "exec",
                                         "--state", broker, "--output", receipt, "--", *command],
                                        text=True, capture_output=True).returncode
            recorded = json.loads(receipt.read_text()) if receipt.exists() else {}
            stdout, stderr = recorded.get("stdout", ""), recorded.get("stderr", "")
        with receipts.open("a") as log:
            log.write(json.dumps(dict(command=command, returncode=returncode,
                                      stdout=stdout, stderr=stderr)) + "\n")
        if returncode:
            raise subprocess.CalledProcessError(returncode, command, stdout, stderr)
        return stdout

    clang = os.environ.get("CLANG") or str(ROOT / "kprog/stock-path/bin/clang")
    sysroot = os.environ.get("KPROG_ARM64_SYSROOT")
    include_flags = [] if sysroot is None else ["--sysroot=" + sysroot]
    ir, lowered = directory / "checked-simulator.bc", directory / "checked-simulator.native.bc"
    native, proof = directory / "checked-simulator.native.o", directory / "checked-simulator.proof.o"
    run([clang, *b_flags(), "-emit-llvm", "-c", source, "-o", ir])
    arrays = [m["name"] for m in artifacts.get("maps", [])
              if m["map_type"] == 2 and m.get("value_offset") is None]
    helper_list = directory / "checked-simulator.helpers.txt"
    run([compiler, ir, "-o", lowered, "--helper-list", helper_list,
         *[arg for name in arrays for arg in ("--array-map", name)],
         "--stack-arena", AARCH64_STACK_ARENA, "--arch", AARCH64_TRIPLE,
         "--data-layout", AARCH64_LAYOUT])
    helpers = helper_list.read_text().splitlines() if helper_list.exists() else []
    undefined = set(run(["llvm-nm-18", "-u", "-j", lowered]).splitlines())
    helper_irs = []
    if "bpf_get_current_pid_tgid" in undefined:
        pid_helper = directory / "checked-simulator.pid.c"
        pid_helper.write_text(pid_source(artifacts.get("kernel_btf", "/sys/kernel/btf/vmlinux")))
        pid_ir = pid_helper.with_suffix(".bc")
        run([clang, *AARCH64_HELPER_FLAGS, *include_flags, "-emit-llvm", "-c", pid_helper, "-o", pid_ir])
        helper_irs.append(pid_ir)
    if helper_irs:
        linked = directory / "checked-simulator.linked.bc"
        run(["llvm-link-18", lowered, *helper_irs, "-o", linked])
        lowered = linked
    if artifacts.get("context_kind", "raw") != "raw":
        context_ir = directory / "checked-simulator.context.bc"
        run([context_compiler, lowered, "--public-layout", public_layout,
             "--physical-layout", physical_layout, "-o", context_ir,
             "--arch", AARCH64_TRIPLE, "--data-layout", AARCH64_LAYOUT])
        lowered = context_ir
    # -fno-jump-tables is a driver flag that a .bc input never sees, so the
    # attribute is written onto every function the linker can reach.
    functions = [line.split()[-1] for line in
                 run(["llvm-nm-18", "--defined-only", lowered]).splitlines()
                 if len(line.split()) == 3 and line.split()[1] in ("T", "t")]
    attributes = directory / "checked-simulator.attributes.csv"
    attributes.write_text("".join(f"{name},no-jump-tables=true\n" for name in functions))
    run([clang, *AARCH64_HELPER_FLAGS, *include_flags,
         "-mllvm", f"-forceattrs-csv-path={attributes}",
         "-c", lowered, "-o", native])
    run([native_link, "--input", native, "--symbol", artifacts["simulator_program"],
         "--mode", "proof", "--preserve-entry-abi", "--output", proof])
    result = dict(artifacts, native_object=str(native), native_proof_object=str(proof),
                  checked_simulator_object=artifacts["simulator_object"], symbol=artifacts["simulator_program"])
    (directory / "checked-simulator.json").write_text(json.dumps(dict(
        source=str(source), source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),
        executable_sha256=hashlib.sha256(native.read_bytes()).hexdigest(),
        helpers=helpers, context_layouts={str(p): hashlib.sha256(Path(p).read_bytes()).hexdigest()
                                          for p in (public_layout, physical_layout) if p is not None},
        artifacts=result), indent=2) + "\n")
    return result
