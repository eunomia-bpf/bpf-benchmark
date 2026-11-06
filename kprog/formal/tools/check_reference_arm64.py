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
    for word, flags, result, dst in [
            (0x1A820020, 0x40000000, 5, 0),  # CSEL W EQ true/false
            (0x1A820020, 0, 7, 0),
            (0x9A82C020, 0, 0xFEED000000000005, 0),  # CSEL X GT
            (0x9A82C020, 0x40000000, 0xDEAD000000000007, 0),
            (0x1A820420, 0, 8, 0),  # CSINC false
            (0x1A820420, 0x40000000, 5, 0),
            (0xDA821020, 0x40000000, 0x2152FFFFFFFFFFF8, 0),  # CSINV false
            (0x5A82C420, 0x40000000, 0xFFFFFFF9, 0),  # CSNEG W false
            (0x5A82C420, 0, 5, 0),
            (0x1A9F17E0, 0x40000000, 1, 0),  # CSET alias
            (0x1A9F17E0, 0, 0, 0),
            (0xDA9F13E0, 0x40000000, 0xFFFFFFFFFFFFFFFF, 0),  # CSETM
            (0x1A811420, 0x40000000, 6, 0),  # CINC
            (0xDA811020, 0x40000000, 0x0112FFFFFFFFFFFA, 0),  # CINV
            (0x5A811420, 0x40000000, 0xFFFFFFFB, 0),  # CNEG W
            (0x9A82F020, 0, 0xFEED000000000005, 0),  # NV always true
            (0x9A82E03F, 0, None, None)]:  # discard to ZR, preserve SP
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["registers"][1:3] = [0xFEED000000000005, 0xDEAD000000000007]
        request["state"]["flags"] = flags
        expected = copy.deepcopy(request["state"])
        expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, events=[], fault=None)
        if dst is not None:
            expected["registers"][dst] = result
        cases.append((request, expected))
    for word, lhs, rhs, result, dst in [
            (0x13821020, 0x1111222233334444, 0x5555666677778888, 0x47777888, 0),
            (0x93C21020, 0x0123456789ABCDEF, 0xFEDCBA9876543210, 0xFFEDCBA987654321, 0),
            (0x13827C20, 0xA5A5000000000001, 0xDEAD000080000000, 3, 0),
            (0x93C2FC20, 0x0123456789ABCDEF, 0xFEDCBA9876543210, 0x02468ACF13579BDF, 0),
            (0x93C20020, 0x0123456789ABCDEF, 0xFEDCBA9876543210, 0xFEDCBA9876543210, 0),
            (0x5AC00820, 0x0123456789ABCDEF, 0, 0xEFCDAB89, 0),
            (0xDAC00C20, 0x0123456789ABCDEF, 0, 0xEFCDAB8967452301, 0),
            (0x5AC00420, 0x0123456789ABCDEF, 0, 0xAB89EFCD, 0),
            (0xDAC00420, 0x0123456789ABCDEF, 0, 0x23016745AB89EFCD, 0),
            (0x13001C20, 0xFFFFFFFFFFFFFF80, 0, 0xFFFFFF80, 0),
            (0x93401C20, 0xFFFFFFFFFFFFFF80, 0, 0xFFFFFFFFFFFFFF80, 0),
            (0x13003C20, 0x8001, 0, 0xFFFF8001, 0),
            (0x93403C20, 0x8001, 0, 0xFFFFFFFFFFFF8001, 0),
            (0x93407C20, 0x80000000, 0, 0xFFFFFFFF80000000, 0),
            (0x138213E0, 0xFFFFFFFFFFFFFFFF, 0x77778888, 0x07777888, 0),
            (0x93C21021, 0x0123456789ABCDEF, 0xFEDCBA9876543210, 0xFFEDCBA987654321, 1)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["registers"][1:3] = [lhs, rhs]
        expected = copy.deepcopy(request["state"])
        expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, events=[], fault=None)
        expected["registers"][dst] = result
        cases.append((request, expected))
    # Assembled register shifts, immediate aliases and shifted MVN/NEG.
    # Fixed expectations catch ignored modifiers and host-width source reads.
    for word, source, count, result, dst in [
            (0x1AC22020, 0xABCD000080000001, 32, 0x80000001, 0),
            (0x1AC22020, 0xABCD000080000001, 1, 2, 0),
            (0x1AC22420, 0xABCD000080000001, 1, 0x40000000, 0),
            (0x1AC22820, 0xABCD000080000001, 31, 0xFFFFFFFF, 0),
            (0x1AC22C20, 0xABCD000080000001, 1, 0xC0000000, 0),
            (0x9AC22020, 0x8000000000000001, 64, 0x8000000000000001, 0),
            (0x9AC22420, 0x8000000000000001, 0x100000040, 0x8000000000000001, 0),
            (0x9AC22820, 0x8000000000000001, 63, 0xFFFFFFFFFFFFFFFF, 0),
            (0x9AC22C20, 0x8000000000000001, 0, 0x8000000000000001, 0),
            (0x9AC22C20, 0x8000000000000001, 65, 0xC000000000000000, 0),
            (0x1AC223E0, 0x80000001, 1, 0, 0),
            (0x9ADF2C20, 0x8000000000000001, 99, 0x8000000000000001, 0),
            (0x9AC2283F, 0x8000000000000001, 63, None, None),
            (0x1AC22C21, 0xABCD000080000001, 1, 0xC0000000, 1),
            (0x53010020, 3, 0, 0x80000000, 0),
            (0xD37FFC20, 0x8000000000000001, 0, 1, 0),
            (0x131F7C20, 0xABCD000080000001, 0, 0xFFFFFFFF, 0),
            (0x13817C20, 0xABCD000080000001, 0, 3, 0),
            (0x2A2107E0, 0xABCD000080000001, 0, 0xFFFFFFFD, 0),
            (0x2A6107E0, 0xABCD000080000001, 0, 0xBFFFFFFF, 0),
            (0x2AA17FE0, 0xABCD000080000001, 0, 0, 0),
            (0x2AE107E0, 0xABCD000080000001, 0, 0x3FFFFFFF, 0),
            (0xAAA1FFE0, 0x8000000000000001, 0, 0, 0),
            (0xAAE1FFE0, 0x8000000000000001, 0, 0xFFFFFFFFFFFFFFFC, 0),
            (0x4B0107E0, 0xABCD000080000001, 0, 0xFFFFFFFE, 0),
            (0x4B4107E0, 0xABCD000080000001, 0, 0xC0000000, 0),
            (0x4B817FE0, 0xABCD000080000001, 0, 1, 0),
            (0xCB01FFE0, 1, 0, 0x8000000000000000, 0),
            (0xCB81FFE0, 0x8000000000000001, 0, 1, 0),
            (0x2AE17FFF, 0x80000001, 0, None, None),
            (0xCB4107E1, 0x8000000000000001, 0, 0xC000000000000000, 1),
            (0xAAFF03E0, 0xDEADBEEF, 0, 0xFFFFFFFFFFFFFFFF, 0)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["registers"][1:3] = [source, count]
        expected = copy.deepcopy(request["state"])
        expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, events=[], fault=None)
        if dst is not None:
            expected["registers"][dst] = result
        cases.append((request, expected))
    # Logical shifted-register forms, including NZCV replacement, TST/MOV
    # aliases, a complemented shifted source, and discarded/aliased writes.
    for word, lhs, rhs, result, dst, nzcv in [
            (0x0A420420, 0xFFFFFFFF000000F0, 0xFFFF0000000000FF, 0x70, 0, None),
            (0x8AA2FC20, 0xFFFFFFFFFFFFFFFF, 0x8000000000000000, 0, 0, None),
            (0xAA021020, 0x100, 1, 0x110, 0, None),
            (0xAA621020, 0xF0, 0xFF, 0xFFFFFFFFFFFFFFF0, 0, None),
            (0x4AC20420, 0xFFFFFFFF00000001, 3, 0x80000000, 0, None),
            (0x6A020020, 0xFFFFFFFF80000000, 0xFFFFFFFF, 0x80000000, 0, 0x80000000),
            (0x6A020020, 1, 1, 1, 0, 0),
            (0xEA020020, 0, 0xFFFFFFFFFFFFFFFF, 0, 0, 0x40000000),
            (0x6A227C20, 0xFFFFFFFF, 1, 0x7FFFFFFF, 0, 0),
            (0xEAE2FC20, 0xFFFFFFFFFFFFFFFF, 0x8000000000000001,
             0xFFFFFFFFFFFFFFFC, 0, 0x80000000),
            (0xEA82043F, 1, 0x8000000000000000, None, None, 0x40000000),
            (0xEA62FC3F, 1, 0x8000000000000000, None, None, 0x40000000),
            (0x8A02003F, 0xFFFFFFFFFFFFFFFF, 0xDEADBEEF, None, None, None),
            (0xAA0203E0, 0x1234, 0xFFFFFFFF80000001, 0xFFFFFFFF80000001, 0, None),
            (0x2A0203E0, 0x1234, 0xFFFFFFFF80000001, 0x80000001, 0, None),
            (0x0A0203E0, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0, 0, None),
            (0xCA020021, 0x8000000000000001, 1, 0x8000000000000000, 1, None),
            (0xAAFFFC20, 0x1234, 0xDEADBEEF, 0xFFFFFFFFFFFFFFFF, 0, None),
            (0x6A2203E0, 0xFFFFFFFFFFFFFFFF, 0xDEADBEEF, 0, 0, 0x40000000),
            (0x6A1F003F, 0xFFFFFFFFFFFFFFFF, 0xDEADBEEF, None, None, 0x40000000)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["registers"][1:3] = [lhs, rhs]
        request["state"]["flags"] = 0xABCDE000F1234567
        expected = copy.deepcopy(request["state"])
        expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, events=[], fault=None)
        if dst is not None:
            expected["registers"][dst] = result
        if nzcv is not None:
            expected["flags"] = (expected["flags"] & ~0xF0000000) | nzcv
        cases.append((request, expected))
    # MOVK retains every other halfword; W writes additionally clear high32.
    for word, dst, result in [
            (0x72824680, 0, 0x76541234),
            (0x72A24680, 0, 0x12343210),
            (0xF2824680, 0, 0xFEDCBA9876541234),
            (0xF2A24680, 0, 0xFEDCBA9812343210),
            (0xF2C24680, 0, 0xFEDC123476543210),
            (0xF2E24680, 0, 0x1234BA9876543210),
            (0xF2E00000, 0, 0xBA9876543210),
            (0x72BFFFE0, 0, 0xFFFF3210),
            (0xF2FFFFFF, None, None),
            (0xF2C2469E, 30, 0xFEDC123476543210)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["registers"][0 if dst is None else dst] = 0xFEDCBA9876543210
        expected = copy.deepcopy(request["state"])
        expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, events=[], fault=None)
        if dst is not None:
            expected["registers"][dst] = result
        cases.append((request, expected))
    # MOVZ/MOVN native halfword encodings feed MOV_IMM's scalar write path.
    # Include a legal MOVN that objdump does not print as a plain MOV alias.
    for word, dst, result in [
            (0x52824680, 0, 0x1234), (0x52A24680, 0, 0x12340000),
            (0xD2824680, 0, 0x1234), (0xD2A24680, 0, 0x12340000),
            (0xD2C24680, 0, 0x123400000000), (0xD2E24680, 0, 0x1234000000000000),
            (0x12824680, 0, 0xFFFFEDCB), (0x12A24680, 0, 0xEDCBFFFF),
            (0x92824680, 0, 0xFFFFFFFFFFFFEDCB), (0x92A24680, 0, 0xFFFFFFFFEDCBFFFF),
            (0x92C24680, 0, 0xFFFFEDCBFFFFFFFF), (0x92E24680, 0, 0xEDCBFFFFFFFFFFFF),
            (0x92FFFFFF, None, None), (0x12800000, 0, 0xFFFFFFFF),
            (0xD2800000, 0, 0), (0x12BFFFE0, 0, 0xFFFF),
            (0x92FFFFE0, 0, 0xFFFFFFFFFFFF), (0x52BFFFFF, None, None),
            (0xD2C2469E, 30, 0x123400000000)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
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
    for word in (0x2A2183E0, 0x4BC107E0, 0x4B2107E0, 0x6B0107E0,
                 0x1AE22020, 0x53207C20, 0x131FFC20, 0x0A028020, 0x6A228020,
                 0x72C24680, 0x72E24680, 0x72024680, 0x12C24680, 0x12E24680,
                 0x52C24680, 0x52E24680, 0x32824680):
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        rejected = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
                                  input=json.dumps(request) + "\n", text=True, capture_output=True)
        assert rejected.returncode == 1, (word, rejected)
    # Unknown ISA, short words, reserved opcode bits and bad state dimensions
    # must fail explicitly instead of truncating or changing architecture.
    malformed = copy.deepcopy(base)
    malformed["native_bytes"] = [0x20, 0x0C, 0x02, 0x9B]
    bad = [dict(malformed, isa="unknown"), dict(malformed, native_bytes=[0x20]),
           dict(malformed, native_bytes=list((0x9B420C20).to_bytes(4, "little"))),
           dict(malformed, native_bytes=list((0x13828020).to_bytes(4, "little")))]
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
    print("AArch64 reference: multiply/divide/select/extract/reverse/extend/shift/unary/logical/MOVK/MOVZ/MOVN, exact native decode, W zero-extension, ZR/SP, aliasing and state preservation OK")


if __name__ == "__main__":
    main()
