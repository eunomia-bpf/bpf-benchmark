#!/usr/bin/env python3
"""Compare actual producer programs and mutate their borrowed bindings in RAM."""
import argparse
import json
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[4]
FORMAL = ROOT / "kprog/formal"
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--output", type=Path, required=True)
args = parser.parse_args()
args.output.mkdir(parents=True, exist_ok=False)
commands, results = [], {}

def run(name, argv, source=None, capture=None, expected=0):
    with (args.output / (name + ".log")).open("w") as log:
        if capture:
            with capture.open("wb") as output:
                result = subprocess.run(argv, cwd=FORMAL, input=source, text=True,
                                        stdout=output, stderr=log)
        else:
            result = subprocess.run(argv, cwd=FORMAL, input=source, text=True,
                                    stdout=log, stderr=log)
    commands.append(dict(name=name, argv=argv, exit=result.returncode))
    (args.output / "commands.json").write_text(json.dumps(commands, indent=2) + "\n")
    if result.returncode != expected:
        raise SystemExit(f"{name}: exit {result.returncode}, expected {expected}")

flags = ["cc", "-std=c11", "-Wall", "-Wextra", "-O1", "-fsanitize=undefined",
         "-fno-sanitize-recover=undefined", "-include", "oracles/compcert_memory_host.h",
         "-I../../vendor/libbpf/include/uapi", "-I../../vendor/libbpf/src"]
binary = "build/test_x86_producer_profile_host"
test = FORMAL / "oracles/test_x86_producer_profile_host.c"
inline = ROOT / "kprog/x86/x86_sim_inline.h"

def options(frame):
    return [f"-DPROFILE={frame}",
            f'-DKPROG_X86_PROGRAM_SOURCE="../build/x86_stack_profile_{frame}.bpf.c"',
            f"-DKPROG_X86_PROGRAM_ENTRY=x86_stack_profile_{frame}_x86_sim_xdp"]

for frame in [200, 376]:
    for mode in ["native", "adapter"]:
        name = f"{frame}-{mode}"
        extra = ["-D__COMPCERT__"] if mode == "adapter" else []
        run(name + "-compile", flags + extra + options(frame) + [str(test), "-o", binary])
        capture = args.output / (name + ".bin")
        run(name, ["./" + binary, "--capture"], capture=capture)
        results[name] = dict(capture_bytes=capture.stat().st_size,
                             summary=(args.output / (name + ".log")).read_text().strip())
    if (args.output / f"{frame}-native.bin").read_bytes() != (args.output / f"{frame}-adapter.bin").read_bytes():
        raise SystemExit(f"{frame}: native/adapter capture mismatch")

# Expand just the test, actual generated program and actual inline header;
# other quoted includes retain their canonical absolute locations. No edited
# source copy or second interpreter is written to disk.
program = FORMAL / "build/x86_stack_profile_376.bpf.c"
expanded = {test, program, inline}
mutations = {
    "fact-references-alias-zero": (
        "[(I)] = { &X86_SIM_L_SV_TAG(I), &X86_SIM_L_SV_PTR(I) },",
        "[(I)] = { &X86_SIM_L_SV_TAG(0), &X86_SIM_L_SV_PTR(0) },"),
    "handler-pointer-slot-zero": (
        "#define X86_SIM_L_SV_PTR(I) (*__x86_bind->values[(I)].pointer)",
        "#define X86_SIM_L_SV_PTR(I) (*__x86_bind->values[0].pointer)"),
    "native-stack-base-low32": (
        "#define __x86_native_stack_base (*__x86_bind->native_stack_base)",
        "#define __x86_native_stack_base ((__u32)*__x86_bind->native_stack_base)")}

def source(path, mutation):
    body = path.read_text()
    if path == test:
        body = body.replace("#include KPROG_X86_PROGRAM_SOURCE", f'#include "{program}"')
    if path == inline:
        old, new = mutation
        assert body.count(old) == 1
        body = body.replace(old, new)
    def include(match):
        child = (path.parent / match[1]).resolve()
        return source(child, mutation) if child in expanded else f'#include "{child}"'
    return f'#line 1 "{path}"\n' + re.sub(r'^\s*#include "([^"]+)"', include, body, flags=re.M)

for name, mutation in mutations.items():
    run(name + "-compile", flags + options(376) + ["-x", "c", "-", "-o", binary], source(test, mutation))
    run(name, ["./" + binary], expected=1)
    if "x86 producer profile mismatch" not in (args.output / (name + ".log")).read_text():
        raise SystemExit(name + ": missing intended diagnostic")
results["mutations"] = list(mutations)
run("restore-compile", flags + ["-D__COMPCERT__"] + options(376) + [str(test), "-o", binary])
run("restore", ["./" + binary, "--capture"], capture=args.output / "restored.bin")
if (args.output / "restored.bin").read_bytes() != (args.output / "376-adapter.bin").read_bytes():
    raise SystemExit("normal product changed after mutation replay")
results["comparison"] = "all native/adapter capture bytes equal per profile; normal product restored"
(args.output / "results.json").write_text(json.dumps(results, indent=2) + "\n")
print(json.dumps(results, indent=2))
