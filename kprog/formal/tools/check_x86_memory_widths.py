#!/usr/bin/env python3
"""Check actual BPF primitive access kind, address, width and multiplicity."""
import argparse
import json
from pathlib import Path
import re
import struct
import subprocess
from bpf_memory_accesses import BpfObject

ROOT = Path(__file__).resolve().parent.parent


def command(argv):
    try:
        return subprocess.run(argv, text=True, capture_output=True, check=True).stdout
    except OSError as error:
        raise SystemExit(f"memory widths: cannot run {argv[0]}: {error}") from error
    except subprocess.CalledProcessError as error:
        raise SystemExit(f"memory widths: {argv[0]} failed: {error.stderr}") from error


def accesses(instructions, fixed_displacement=None, second_argument=None):
    # Register1 starts at the guest pointer; track pointer copies and constant
    # additions. Every other value is scalar. Unexpected control flow fails.
    registers = [None] * 11
    registers[1] = 0
    constants = [None] * 11
    constants[2] = second_argument
    events = []
    for raw in instructions:
        code, packed, offset, immediate = struct.unpack("<BBhi", raw)
        dst, src = packed & 15, packed >> 4
        if dst >= 11 or src >= 11:
            raise SystemExit("memory widths: invalid BPF register")
        # A compiler barrier can materialize a known displacement in a
        # register. Track that literal exactly, and forget it on every write.
        old_dst, old_src = constants[dst], constants[src]
        constants[dst] = None
        if code == 0xB7:
            registers[dst] = None
            constants[dst] = immediate
        elif code == 0x0F and registers[dst] is not None and old_src is not None:
            registers[dst] += old_src
        elif code == 0x0F and old_dst is not None and registers[src] is not None:
            # ADD64 also permits the constant destination plus guest pointer.
            registers[dst] = old_dst + registers[src]
        elif code in (0x07, 0x17):
            if registers[dst] is not None:
                registers[dst] += immediate if code == 0x07 else -immediate
            if old_dst is not None:
                constants[dst] = old_dst + (immediate if code == 0x07 else -immediate)
        elif code == 0xBF:
            registers[dst] = registers[src]
            constants[dst] = old_src
        elif code & 7 in (1, 2, 3) and code & 0xE0 == 0x60:
            kind = "read" if code & 7 == 1 else "write"
            pointer = registers[src if kind == "read" else dst]
            width = {0: 4, 8: 2, 16: 1, 24: 8}[code & 24]
            if pointer is None:
                raise SystemExit("memory widths: access lost its guest pointer")
            if fixed_displacement is not None and (pointer != 0 or offset != fixed_displacement):
                raise SystemExit("memory widths: fixed load modified its base or lost its literal displacement")
            events.append((kind, pointer + offset, width))
            if kind == "read":
                registers[dst] = None
        elif code == 0x95:
            pass
        elif code & 7 in (4, 7):
            registers[dst] = None
        else:
            raise SystemExit(f"memory widths: unexpected BPF opcode {code:#x}")
    return events


def instructions_by_function(disassembly):
    functions, current = {}, None
    for line in disassembly.splitlines():
        label = re.fullmatch(r"[0-9a-f]+ <([^>]+)>:", line)
        if label:
            current = label[1]
            if current in functions:
                raise SystemExit(f"memory widths: duplicate function {current}")
            functions[current] = []
            continue
        instruction = re.match(r"\s*\d+:((?:\s+[0-9a-f]{2}){8}(?:(?:\s+[0-9a-f]{2}){8})?)\s", line)
        if instruction:
            if current is None:
                raise SystemExit("memory widths: instruction outside a function")
            raw = bytes.fromhex(instruction[1])
            if raw[0] == 0x18:
                # A scalar64 literal kills pointer provenance like a scalar32
                # MOV. Validate both slots; erase no memory or control flow.
                if len(raw) != 16 or raw[1] >> 4 != 0 or raw[8:12] != bytes(4):
                    raise SystemExit("memory widths: invalid scalar64 literal")
                raw = bytes([0xB7, raw[1]]) + bytes(6)
            elif len(raw) != 8:
                raise SystemExit("memory widths: invalid instruction extent")
            functions[current].append(raw)
    return functions


def check_call_mutations(module):
    """Catch ignored callee widths, caller offsets, calls and ELF bindings.

    Mutate instructions in the real compiled byte fixture, in memory only.
    No separately compiled or copied source/product is needed.
    """
    entry = "fixed_b8_context"
    wanted = [("read", 88, 1)]
    assert module.accesses(entry) == wanted
    trace = module.executed

    def unique(predicate):
        candidates = [step for step in trace if predicate(step)]
        if len(candidates) != 1:
            raise AssertionError(("memory mutation site", candidates))
        return candidates[0]

    def immediate_mutant(step, value):
        data = bytearray(module.data)
        struct.pack_into("<i", data, module.file_offset(*step[:2]) + 4, value)
        return BpfObject(data)

    width = unique(lambda step: step[2] in (0xb4, 0xb7) and step[3] == 2 and step[4] == 1)
    displacement = unique(lambda step: step[2] in (0xb4, 0xb7) and step[3] == 3 and step[4] == 88)
    call = unique(lambda step: step[2:4] == (0x85, 0x10))
    probe = unique(lambda step: step[2:] == (0x85, 0, 113))
    results = {}
    for name, mutant, expected in (
        ("callee-width", immediate_mutant(width, 2), [("read", 88, 2)]),
        ("caller-displacement", immediate_mutant(displacement, 89), [("read", 89, 1)]),
    ):
        actual = mutant.accesses(entry)
        assert actual == expected and actual != wanted, (name, actual, expected)
        results[name] = actual
    try:
        immediate_mutant(displacement, 89).accesses(entry, fixed_displacement=88)
    except ValueError as error:
        assert "base/displacement" in str(error), str(error)
        results["fixed-call-arguments"] = str(error)
    else:
        raise AssertionError("memory trace accepted changed fixed-call displacement")
    data = bytearray(module.data)
    struct.pack_into("<BBhi", data, module.file_offset(*probe[:2]), 0xb7, 0, 0, 0)
    actual = BpfObject(data).accesses(entry)
    assert actual == [], ("removed-call", actual)
    results["removed-call"] = actual
    data = bytearray(module.data)
    _, _, relocation = module.relocations[call[:2]]
    struct.pack_into("<Q", data, relocation + 8, 10)  # Undefined symbol zero.
    try:
        BpfObject(data).accesses(entry)
    except ValueError as error:
        assert "undefined call target" in str(error), str(error)
        results["call-relocation"] = str(error)
    else:
        raise AssertionError("memory trace accepted undefined call relocation")
    return results


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--clang", default="clang-18")
    parser.add_argument("--objdump", default="llvm-objdump-18")
    parser.add_argument("--include-dir", type=Path, default=ROOT)
    parser.add_argument("--build-dir", type=Path, default=ROOT / "build/memory-widths")
    args = parser.parse_args()
    args.build_dir.mkdir(parents=True, exist_ok=True)
    obj = args.build_dir / "x86.bpf.o"
    command([args.clang, "-target", "bpfel", "-mcpu=v3", "-O2", "-g", "-I", str(args.include_dir),
             "-I", str(ROOT), "-I", str(ROOT.parents[1] / "vendor/libbpf/src"),
             "-I/usr/include/x86_64-linux-gnu", "-c", str(ROOT / "oracles/test_x86_memory_widths.c"), "-o", str(obj)])
    disassembly = command([args.objdump, "-d", str(obj)])
    (args.build_dir / "x86.asm").write_text(disassembly)
    module = BpfObject.read(obj)
    expected = {f"{kind}_{name}": [("read" if kind == "load" else "write", 3, width)]
                for name, width in [("b8", 1), ("b16", 2), ("b32", 4), ("b64", 8), ("default", 8)]
                for kind in ("load", "store")}
    fixed = {f"fixed_{name}_{suffix}": [("read", offset, width)]
             for name, width in [("b8", 1), ("b16", 2), ("b32", 4), ("b64", 8), ("default", 8)]
             for suffix, offset in [("context", 88), ("negative", -3), ("minimum", -32768), ("maximum", 32767)]}
    expected.update(fixed)
    if module.entries != expected.keys():
        raise SystemExit(f"memory widths: entry set mismatch: {module.entries ^ expected.keys()}")
    for name, wanted in expected.items():
        actual = module.accesses(name, fixed_displacement=wanted[0][1] if name in fixed else None)
        if actual != wanted:
            raise SystemExit(f"memory widths: {name}: got {actual}, expected {wanted}")
    mutations = check_call_mutations(module)
    (args.build_dir / "call-mutations.json").write_text(json.dumps(mutations, indent=2) + "\n")
    print("x86 BPF memory call mutations: " + json.dumps(mutations, sort_keys=True))
    # The current C preserves literal signed16 offsets and computes other
    # addresses. Check those existing supported cases instead of demanding a
    # removed compile-time refusal. R2 is the fixture's long-long argument.
    for mode in (1, 2, 3):
        computed = args.build_dir / f"computed-fixed-{mode}.o"
        command([args.clang, "-target", "bpfel", "-mcpu=v3", "-O2", "-I", str(args.include_dir),
            "-I", str(ROOT), "-I", str(ROOT.parents[1] / "vendor/libbpf/src"),
            "-I/usr/include/x86_64-linux-gnu", f"-DKPROG_TEST_COMPUTED_FIXED={mode}", "-c",
            str(ROOT / "oracles/test_x86_memory_widths.c"), "-o", str(computed)])
        assembly = command([args.objdump, "-d", str(computed)])
        (args.build_dir / f"computed-fixed-{mode}.asm").write_text(assembly)
        computed_module = BpfObject.read(computed)
        offsets = (-32769, -3, 0, 32768) if mode == 1 else ((32768,) if mode == 2 else (-32769,))
        for offset in offsets:
            actual = computed_module.accesses("computed_fixed", second_argument=offset if mode == 1 else None)
            if actual != [("read", offset, 4)]:
                raise SystemExit(f"memory widths: computed mode{mode} offset{offset}: got {actual}")
    movx = args.build_dir / "x86-movx.bpf.o"
    command([args.clang, "-target", "bpfel", "-mcpu=v3", "-O2", "-I", str(args.include_dir), "-I", str(ROOT),
             "-I", str(ROOT.parent / "x86"), "-I", str(ROOT.parents[1] / "vendor/libbpf/src"),
             "-I/usr/include/x86_64-linux-gnu", "-c", str(ROOT / "oracles/test_x86_movx_widths.c"), "-o", str(movx)])
    assembly = command([args.objdump, "-d", str(movx)])
    (args.build_dir / "x86-movx.asm").write_text(assembly)
    module = BpfObject.read(movx)
    expected = {f"{kind}_{sw}_{tw}": [("read", 3, sw)]
                for kind in ("zx", "sx") for sw, tw in ((1,2),(1,4),(1,8),(2,4),(2,8),(4,8))}
    if module.entries != expected.keys():
        raise SystemExit(f"MOVX memory widths: entry set mismatch: {module.entries ^ expected.keys()}")
    for name, wanted in expected.items():
        actual = module.accesses(name)
        if actual != wanted:
            raise SystemExit(f"MOVX memory widths: {name}: got {actual}, expected {wanted}")
    print("x86 BPF memory widths: ten generic + twenty fixed loads keep exact kind/address/width/count; fixed callee bases/displacements, dynamic and out-of-signed16 computed offsets and twelve actual MOVX handler access widths OK")


if __name__ == "__main__":
    main()
