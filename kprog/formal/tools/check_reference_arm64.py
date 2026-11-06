#!/usr/bin/env python3
"""Regress real A64 byte encodings, ZR/SP separation and scalar boundary cases."""
import copy
import importlib.util
import sys
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parent.parent


def main():
    base = dict(isa="aarch64", state=dict(
        registers=[0xFEED000000000000 + i for i in range(31)] + [0x70001000],
        flags=0xF0000000, vector0=(1 << 127) + 17, pc=0x1000,
        memory=[dict(address=0x2000, value=0xA5, readable=True,
                     writable=False, initialized=False)]))
    # Encoding words were independently assembled with GNU AArch64 as. Expected
    # results are fixed boundary examples, not an alternate ISA interpreter.
    cases = []
    for word, lhs, rhs, addend, dst, result in [
            (0x1B020C20, 0xFFFFFFFF, 2, 3, 0, 1),  # MADD W
            (0x9B020C20, 0xFFFFFFFFFFFFFFFF, 2, 3, 0, 1),
            (0x1B028C20, 2, 3, 1, 0, 0xFFFFFFFB),  # MSUB W
            (0x9B028C20, 2, 3, 1, 0, 0xFFFFFFFFFFFFFFFB),
            (0x1B027C20, 0xFFFFFFFF, 2, 99, 0, 0xFFFFFFFE),  # MUL alias/ZR
            (0x9B027C20, 0xFFFFFFFFFFFFFFFF, 2, 99, 0, 0xFFFFFFFFFFFFFFFE),
            (0x9BA27C20, 0xABCD0000FFFFFFFF, 2, 99, 0, 0x1FFFFFFFE),  # UMULL
            (0x9BA20C20, 0xABCD0000FFFFFFFF, 2, 3, 0, 0x200000001),
            (0x9B220C20, 0xFFFFFFFF, 2, 3, 0, 1),  # SMADDL signed low32
            (0x9B220C20, 0x80000000, 0x80000000, 0x7FFFFFFFFFFFFFFF,
             0, 0xBFFFFFFFFFFFFFFF),
            (0x9BC27C20, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 99,
             0, 0xFFFFFFFFFFFFFFFE),
            (0x1AC20820, 0x8000000000000064, 0x100000007, 99, 0, 14),
            (0x1AC20820, 100, 0x100000000, 99, 0, 0),  # narrow divisor first
            (0x9AC20820, 0xFFFFFFFFFFFFFFFF, 0, 99, 0, 0),
            (0x9AC20820, 0xFFFFFFFFFFFFFFFF, 2, 99, 0, 0x7FFFFFFFFFFFFFFF),
            (0x9B020C3F, 2, 3, 4, None, None),  # discarded XZR, not SP
            (0x9B020FE0, 99, 2, 3, 0, 3),  # source XZR, not SP
            (0x9AC20821, 100, 7, 99, 1, 14)]:  # aliased destination
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["registers"][1:4] = [lhs, rhs, addend]
        expected = copy.deepcopy(request["state"])
        expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, events=[], fault=None)
        if dst is not None:
            expected["registers"][dst] = result
        cases.append((request, expected))
    run = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
                         input="".join(json.dumps(q) + "\n" for q, _ in cases),
                         text=True, stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(cases)
    for (request, expected), out in zip(cases, outputs):
        assert out == expected, (request, out, expected)
    # Unknown ISA, short words, reserved opcode bits and bad state dimensions
    # must fail explicitly instead of truncating or changing architecture.
    malformed = copy.deepcopy(base)
    malformed["native_bytes"] = [0x20, 0x0C, 0x02, 0x9B]
    bad = [dict(malformed, isa="unknown"), dict(malformed, native_bytes=[0x20]),
           dict(malformed, native_bytes=list((0x9B420C20).to_bytes(4, "little")))]
    wrong_registers = copy.deepcopy(malformed)
    wrong_registers["state"]["registers"].pop()
    bad.append(wrong_registers)
    for request in bad:
        run = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
                             input=json.dumps(request) + "\n", text=True, capture_output=True)
        assert run.returncode == 1 and run.stderr.startswith("reference:"), (request, run)
    # The real encoder must accept NV and normalize it to the proved AL
    # predicate; parity of the raw spelling must not turn it into "never".
    directory = ROOT.parent / "arm64/micro-prog"
    sys.path.insert(0, str(directory))
    spec = importlib.util.spec_from_file_location("arm_reference_encoder", directory / "generate_micro_sim_proofs.py")
    encoder = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = encoder
    spec.loader.exec_module(encoder)
    nv = encoder.NativeInsn(0, "csel", ("x0", "x1", "x2", "nv"), "csel x0,x1,x2,nv")
    al = encoder.NativeInsn(0, "csel", ("x0", "x1", "x2", "al"), "csel x0,x1,x2,al")
    assert encoder.encode(nv, {}, {}) == encoder.encode(al, {}, {})
    print("AArch64 reference: multiply/divide, exact native decode, W zero-extension, ZR/SP, aliasing and state preservation OK")


if __name__ == "__main__":
    main()
