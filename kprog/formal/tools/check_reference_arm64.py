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
    # Register MOV uses ORR/ZR or ADD-zero/SP encodings. Both sides of the
    # SP/ZR distinction and WSP zero-extension must survive normalization.
    for word, dst, result in [
            (0xAA0103E0, 0, 0xDEAD000012345678), (0x2A0103E0, 0, 0x12345678),
            (0xAA1F03E0, 0, 0), (0x2A1F03E0, 0, 0),
            (0xAA0103FF, None, None), (0x2A0103FF, None, None),
            (0x9100003F, 31, 0xDEAD000012345678), (0x910003E0, 0, 0xFFFF123456788000),
            (0x910003FF, 31, 0xFFFF123456788000), (0x1100003F, 31, 0x12345678),
            (0x110003E0, 0, 0x56788000), (0x110003FF, 31, 0x56788000),
            (0x910003FE, 30, 0xFFFF123456788000), (0x910003DF, 31, 0xBEEF000087654321),
            (0xAA1F03FF, None, None)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["registers"][1] = 0xDEAD000012345678
        request["state"]["registers"][30] = 0xBEEF000087654321
        request["state"]["registers"][31] = 0xFFFF123456788000
        expected = copy.deepcopy(request["state"])
        expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, events=[], fault=None)
        if dst is not None:
            expected["registers"][dst] = result
        cases.append((request, expected))
    # FMOV must copy raw NaN/sign bits, clear the upper vector lanes on a
    # scalar vector write, and discard ZR without touching SP or vector state.
    for word, source, dst, vector_result in [
            (0x9E670020, 1, None, 0xFFF8000000000001),
            (0x9E6703E0, 31, None, 0),
            (0x9E6703C0, 30, None, 0xFFF8000000000001),
            (0x1E270020, 1, None, 1),
            (0x1E2703E0, 31, None, 0),
            (0x9E660000, None, 0, None),
            (0x9E66001F, None, 31, None),
            (0x9E66001E, None, 30, None),
            (0x1E260000, None, 0, None),
            (0x1E26001F, None, 31, None),
            (0x1E26001E, None, 30, None)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["vector0"] = 0xFEDCBA98765432107FF8000080000001
        if source is not None and source != 31:
            request["state"]["registers"][source] = 0xFFF8000000000001
        expected = copy.deepcopy(request["state"])
        expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, events=[], fault=None)
        if vector_result is not None:
            expected["vector0"] = vector_result
        elif dst != 31:
            expected["registers"][dst] = 0x80000001 if word < (1 << 31) else 0x7FF8000080000001
        cases.append((request, expected))
    # All32 SIMD fields are distinct, including V31 (never integer ZR).
    # A patterned complete input bank detects writes to the wrong cell and
    # accidental corruption of inactive upper bits or unrelated vectors.
    for bank in range(32):
        for opcode, to_vector, wide in [(0x9E670000, True, True), (0x1E270000, True, False),
                                        (0x9E660000, False, True), (0x1E260000, False, False)]:
            request = copy.deepcopy(base)
            vectors = [(0xFEDCBA9876543200 + i) << 64 | (0xFFF8000080000001 + i) for i in range(32)]
            request["state"].update(vectors=vectors, vector0=vectors[0])
            request["state"]["registers"][1] = 0xFFF8000080000042
            word = opcode | ((1 << 5) | bank if to_vector else (bank << 5) | 1)
            request["native_bytes"] = list(word.to_bytes(4, "little"))
            expected = copy.deepcopy(request["state"])
            expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, events=[], fault=None)
            if to_vector:
                expected["vectors"][bank] = 0xFFF8000080000042 if wide else 0x80000042
                expected["vector0"] = expected["vectors"][0]
            else:
                expected["registers"][1] = (0xFFF8000080000001 + bank) if wide else (0x80000001 + bank)
            cases.append((request, expected))
    # CNT's inactive upper half clears even when it held data; UADDLV
    # sums unsigned lanes into H0 and clears the rest of the vector.
    for word, vector, result in [
            (0x0E205800, 0, 0), (0x4E205800, 0, 0),
            (0x2E303800, 0, 0), (0x6E303800, 0, 0),
            (0x0E205800, 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF, 0x0808080808080808),
            (0x4E205800, 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF, 0x08080808080808080808080808080808),
            (0x2E303800, 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF, 2040),
            (0x6E303800, 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF, 4080),
            (0x0E205800, 0xFF007F01030F55AA8040201008040201, 0x0101010101010101),
            (0x4E205800, 0xFF007F01030F55AA8040201008040201, 0x08000701020404040101010101010101),
            (0x2E303800, 0xFF007F01030F55AA8040201008040201, 255),
            (0x6E303800, 0xFF007F01030F55AA8040201008040201, 911)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["vector0"] = vector
        expected = copy.deepcopy(request["state"])
        expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, events=[], fault=None, vector0=result)
        cases.append((request, expected))
    # CCMP covers taken arithmetic and literal fallback independently, with
    # signed-overflow/carry boundaries, W input truncation and AL/NV predicates.
    for word, lhs, rhs, incoming, nzcv in [
            (0x7A5F0825, 0xABCD00000000001F, 0, 4, 6),
            (0x7A5F0825, 31, 0, 0, 5),
            (0xFA40182A, 0, 0, 0, 6),
            (0xFA40182A, 0, 0, 4, 10),
            (0x7A42B02F, 0x80000000, 1, 8, 3),
            (0x7A42B02F, 0x7FFFFFFF, 0xFFFFFFFF, 1, 9),
            (0x7A42B02F, 0, 1, 0, 15),
            (0xFA42A020, 0, 1, 0, 8),
            (0xFA42A020, 0, 1, 8, 0),
            (0xFA42A020, 0x8000000000000000, 1, 9, 3),
            (0x7A42E3E2, 99, 1, 0, 8),
            (0x7A42E3E2, 99, 0, 15, 6),
            (0xFA5FF023, 0, 99, 0, 6),
            (0xFA5FF023, 0x8000000000000000, 99, 15, 10),
            (0x7A5F4BE7, 99, 99, 8, 8),
            (0x7A5F4BE7, 99, 99, 0, 7),
            (0xFA5E83C8, 99, 99, 2, 6),
            (0xFA5E83C8, 99, 99, 6, 8)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["registers"][1:3] = [lhs, rhs]
        request["state"]["flags"] = 0xA5A50000000ABCDE | (incoming << 28)
        expected = copy.deepcopy(request["state"])
        expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, events=[], fault=None,
                        flags=0xA5A50000000ABCDE | (nzcv << 28))
        cases.append((request, expected))
    # ADD/SUB immediate and flag/compare aliases, including SP versus ZR,
    # WSP zero-extension and the maximum legal shifted twelve-bit immediate.
    for word, src, value, dst, result, nzcv in [
            (0x11000420, 1, 0xABCD0000FFFFFFFF, 0, 0, None),
            (0x91000420, 1, 0xFFFFFFFFFFFFFFFF, 0, 0, None),
            (0x51000420, 1, 0, 0, 0xFFFFFFFF, None),
            (0xD1000420, 1, 0, 0, 0xFFFFFFFFFFFFFFFF, None),
            (0x31000420, 1, 0xFFFFFFFF, 0, 0, 6),
            (0xB1000420, 1, 0xFFFFFFFFFFFFFFFF, 0, 0, 6),
            (0x71000420, 1, 0x80000000, 0, 0x7FFFFFFF, 3),
            (0xF1000420, 1, 0x8000000000000000, 0, 0x7FFFFFFFFFFFFFFF, 3),
            (0x7100043F, 1, 0, None, None, 8),
            (0xF100043F, 1, 1, None, None, 6),
            (0x3100043F, 1, 0x7FFFFFFF, None, None, 9),
            (0xB100043F, 1, 0x7FFFFFFFFFFFFFFF, None, None, 9),
            (0x910043FF, 31, 0x70001000, 31, 0x70001010, None),
            (0xD10043FF, 31, 0x70001000, 31, 0x70000FF0, None),
            (0x110043FF, 31, 0xABCD0000FFFFFFFF, 31, 15, None),
            (0x510043FF, 31, 0xABCD0000FFFFFFFF, 31, 0xFFFFFFEF, None),
            (0xB10003FF, 31, 0x70001000, None, None, 0),
            (0xF10043FF, 31, 0x70001000, None, None, 2),
            (0x917FFFE0, 31, 0x70001000, 0, 0x71000000, None),
            (0x517FFFE0, 31, 0xABCD000001000000, 0, 0x1000, None),
            (0x317FFC20, 1, 0xFF001000, 0, 0, 6),
            (0xF17FFC20, 1, 0x8000000000000000, 0, 0x7FFFFFFFFF001000, 3)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["registers"][src] = value
        request["state"]["flags"] = 0xA5A50000F00ABCDE
        expected = copy.deepcopy(request["state"])
        expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, events=[], fault=None)
        if dst is not None:
            expected["registers"][dst] = result
        if nzcv is not None:
            expected["flags"] = 0xA5A50000000ABCDE | (nzcv << 28)
        cases.append((request, expected))
    # Shifted register arithmetic includes NONE versus LSL0 temporaries,
    # sign-extended W ASR intermediates, maximum shifts and NEGS aliases.
    for word, lhs, rhs, dst, result, nzcv in [
            (0x0B027C20, 0, 1, 0, 0x80000000, None),
            (0x8B02FC20, 0, 1, 0, 0x8000000000000000, None),
            (0x4B427C20, 1, 0xABCD000080000000, 0, 0, None),
            (0xCB42FC20, 2, 0x8000000000000000, 0, 1, None),
            (0x2B821020, 0, 0xABCD000080000000, 0, 0xF8000000, 8),
            (0xAB82FC20, 0, 0x8000000000000000, 0, 0xFFFFFFFFFFFFFFFF, 8),
            (0x6B027C20, 0, 1, 0, 0x80000000, 9),
            (0xEB02FC20, 0, 1, 0, 0x8000000000000000, 9),
            (0x6B82103F, 0, 0xABCD000080000000, None, None, 0),
            (0xEB42FC3F, 1, 0x8000000000000000, None, None, 6),
            (0x2B027C3F, 0x80000000, 1, None, None, 7),
            (0xAB02FC3F, 0x8000000000000000, 1, None, None, 7),
            (0x0B020020, 0xABCD000000000002, 0xDEAD0000FFFFFFFF, 0, 1, None),
            (0xCB020020, 0, 0xFFFFFFFFFFFFFFFF, 0, 1, None),
            (0x2B020020, 1, 0xDEAD0000FFFFFFFF, 0, 0, 6),
            (0xEB1F0020, 1, 99, 0, 1, 2),
            (0x8B0203FF, 99, 0xFFFFFFFFFFFFFFFF, None, None, None),
            (0x0B4207E0, 99, 0x80000000, 0, 0x40000000, None),
            (0x6B8113E0, 0x80000000, 99, 0, 0x08000000, 0),
            (0x6B0107E0, 1, 99, 0, 0xFFFFFFFE, 8),
            (0xEB01FFE0, 1, 99, 0, 0x8000000000000000, 9),
            (0x0B010021, 3, 99, 1, 6, None),
            (0x2B1F03FF, 99, 99, None, None, 4)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["registers"][1:3] = [lhs, rhs]
        request["state"]["flags"] = 0xA5A50000F00ABCDE
        expected = copy.deepcopy(request["state"])
        expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, events=[], fault=None)
        if dst is not None:
            expected["registers"][dst] = result
        if nzcv is not None:
            expected["flags"] = 0xA5A50000000ABCDE | (nzcv << 28)
        cases.append((request, expected))
    # ExtendReg covers all eight options in both operand sizes, plus SP/WSP,
    # compare aliases and the assembler's NONE/LSL spellings of full-size extends.
    for word, src, rhs_index, lhs, rhs, dst, result, nzcv in [
            (0x8B221020, 1, 2, 100, 0xABCD0000000000FF, 0, 0x1054, None),
            (0x8B223020, 1, 2, 100, 0xABCD00000000FFFF, 0, 0x100054, None),
            (0x8B225020, 1, 2, 100, 0xABCD0000FFFFFFFF, 0, 0x1000000054, None),
            (0x8B227020, 1, 2, 100, 0x8000000000000001, 0, 0x74, None),
            (0x8B229020, 1, 2, 100, 0xABCD000000000080, 0, 0xFFFFFFFFFFFFF864, None),
            (0x8B22B020, 1, 2, 100, 0xABCD000000008000, 0, 0xFFFFFFFFFFF80064, None),
            (0x8B22D020, 1, 2, 100, 0xABCD000080000000, 0, 0xFFFFFFF800000064, None),
            (0x8B22F020, 1, 2, 100, 0x8000000000000001, 0, 0x74, None),
            (0x0B221020, 1, 2, 100, 0xABCD0000000000FF, 0, 0x1054, None),
            (0x0B223020, 1, 2, 100, 0xABCD00000000FFFF, 0, 0x100054, None),
            (0x0B225020, 1, 2, 100, 0xABCD0000FFFFFFFF, 0, 0x54, None),
            (0x0B227020, 1, 2, 100, 0xABCD0000FFFFFFFF, 0, 0x54, None),
            (0x0B229020, 1, 2, 100, 0xABCD000000000080, 0, 0xFFFFF864, None),
            (0x0B22B020, 1, 2, 100, 0xABCD000000008000, 0, 0xFFF80064, None),
            (0x0B22D020, 1, 2, 100, 0xABCD000080000000, 0, 100, None),
            (0x0B22F020, 1, 2, 100, 0x8000000000000001, 0, 0x74, None),
            (0x8B2203FF, 31, 2, 0x70001000, 0xABCD0000000000FF, 31, 0x700010FF, None),
            (0x4B2293FF, 31, 2, 0xABCD000000000064, 0x80, 31, 0x864, None),
            (0xAB2253FF, 31, 2, 0xFFFFFFFFFFFFFFF0, 1, None, None, 6),
            (0x6B229020, 1, 2, 100, 0x80, 0, 0x864, 0),
            (0xEB2213FF, 31, 2, 100, 0xFF, None, None, 8),
            (0x2B2253FF, 31, 2, 0xABCD000000000010, 0xFFFFFFFF, None, None, 6),
            (0x8B2263E0, 31, 2, 0x70001000, 0xFFFFFFFFFFFFFFFF, 0, 0x70000FFF, None),
            (0x0B2243E0, 31, 2, 0xABCD000000000064, 0xDEAD0000FFFFFFFF, 0, 99, None),
            (0x4B2107E0, 31, 1, 0x70001000, 1, 0, 0x70000FFE, None)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["registers"][src] = lhs
        request["state"]["registers"][rhs_index] = rhs
        request["state"]["flags"] = 0xA5A50000F00ABCDE
        expected = copy.deepcopy(request["state"])
        expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, events=[], fault=None)
        if dst is not None:
            expected["registers"][dst] = result
        if nzcv is not None:
            expected["flags"] = 0xA5A50000000ABCDE | (nzcv << 28)
        cases.append((request, expected))
    # Control transfers use signed byte displacements from the current PC.
    # Compare complete states so a branch cannot clobber flags, SP or memory.
    for word, pc, nzcv, src, value, target in [
            (0xD503201F, 0x1000, 15, None, None, 0x1004),
            (0xD503201F, 0xFFFFFFFFFFFFFFFC, 0, None, None, 0),
            (0x14000000, 0x1000, 15, None, None, 0x1000),
            (0x14000001, 0x1000, 15, None, None, 0x1004),
            (0x17FFFFFF, 0x1000, 15, None, None, 0xFFC),
            (0x15FFFFFF, 0x1000, 15, None, None, 0x8000FFC),
            (0x16000000, 0x1000, 15, None, None, 0xFFFFFFFFF8001000),
            (0x14000002, 0xFFFFFFFFFFFFFFFC, 15, None, None, 4),
            (0x17FFFFFF, 0, 15, None, None, 0xFFFFFFFFFFFFFFFC),
            (0x54000108, 0x1000, 2, None, None, 0x1020),
            (0x54000108, 0x1000, 6, None, None, 0x1004),
            (0x54000108, 0x1000, 0, None, None, 0x1004),
            (0x54000109, 0x1000, 2, None, None, 0x1004),
            (0x54000109, 0x1000, 6, None, None, 0x1020),
            (0x54000109, 0x1000, 0, None, None, 0x1020),
            (0x54FFFFE0, 0x1000, 4, None, None, 0xFFC),
            (0x54FFFFE0, 0x1000, 0, None, None, 0x1004),
            (0x5400010F, 0x1000, 0, None, None, 0x1020),
            (0x5400010E, 0x1000, 15, None, None, 0x1020),
            (0x547FFFE8, 0x1000, 2, None, None, 0x100FFC),
            (0x54800008, 0x1000, 2, None, None, 0xFFFFFFFFFFF01000),
            (0x34000101, 0x1000, 15, 1, 0x100000000, 0x1020),
            (0xB4000101, 0x1000, 15, 1, 0x100000000, 0x1004),
            (0x35000101, 0x1000, 15, 1, 0x100000000, 0x1004),
            (0x35000101, 0x1000, 15, 1, 1, 0x1020),
            (0xB5000101, 0x1000, 15, 1, 0x100000000, 0x1020),
            (0xB5000101, 0x1000, 15, 1, 0, 0x1004),
            (0x3400011F, 0x1000, 15, 31, 123, 0x1020),
            (0xB500011F, 0x1000, 15, 31, 123, 0x1004),
            (0x36000101, 0x1000, 15, 1, 0, 0x1020),
            (0x36000101, 0x1000, 15, 1, 1, 0x1004),
            (0xB7F80101, 0x1000, 15, 1, 0x8000000000000000, 0x1020),
            (0xB7F80101, 0x1000, 15, 1, 0x7FFFFFFFFFFFFFFF, 0x1004),
            (0x36F80101, 0x1000, 15, 1, 0xFFFFFFFF00000000, 0x1020),
            (0x36F80101, 0x1000, 15, 1, 0x80000000, 0x1004),
            (0x37F8011F, 0x1000, 15, 31, 123, 0x1004),
            (0xB6F8011F, 0x1000, 15, 31, 123, 0x1020),
            (0x36040001, 0x1000, 15, 1, 0, 0xFFFFFFFFFFFF9000),
            (0x3603FFE1, 0x1000, 15, 1, 0, 0x8FFC)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["pc"] = pc
        request["state"]["flags"] = 0xA5A50000000ABCDE | (nzcv << 28)
        if src is not None:
            request["state"]["registers"][src] = value
        expected = copy.deepcopy(request["state"])
        expected.update(pc=target, defined_flags=(1 << 64) - 1, events=[], fault=None)
        cases.append((request, expected))
    # Independent GNU-as encodings: unsigned and sign-extending loads, all
    # store widths, negative unscaled and maximum positive scaled offsets.
    # Fixed byte/value examples also check byte confinement and initialized bits.
    memory_forms = [
        (0xF9400020, 8, 0, 0, 0xCDAB45678023FE81),
        (0x39400420, 1, 1, 0, 0x81), (0x79400420, 2, 2, 0, 0xFE81),
        (0xB9400420, 4, 4, 0, 0x8023FE81), (0xF9400420, 8, 8, 0, 0xCDAB45678023FE81),
        (0x39000422, 1, 1, None, 0x0123456789ABCDEF),
        (0x79000422, 2, 2, None, 0x0123456789ABCDEF),
        (0xB9000422, 4, 4, None, 0x0123456789ABCDEF),
        (0xF9000422, 8, 8, None, 0x0123456789ABCDEF),
        (0xF8500020, 8, -256, 0, 0xCDAB45678023FE81),
        (0x384FF020, 1, 255, 0, 0x81), (0x785FE020, 2, -2, 0, 0xFE81),
        (0xB85FC020, 4, -4, 0, 0x8023FE81),
        (0x380FF022, 1, 255, None, 0x0123456789ABCDEF),
        (0x781FE022, 2, -2, None, 0x0123456789ABCDEF),
        (0xB81FC022, 4, -4, None, 0x0123456789ABCDEF),
        (0xF81F8022, 8, -8, None, 0x0123456789ABCDEF),
        (0x39800420, 1, 1, 0, 0xFFFFFFFFFFFFFF81), (0x39C00420, 1, 1, 0, 0xFFFFFF81),
        (0x79800420, 2, 2, 0, 0xFFFFFFFFFFFFFE81), (0x79C00420, 2, 2, 0, 0xFFFFFE81),
        (0xB9800420, 4, 4, 0, 0xFFFFFFFF8023FE81),
        (0x389FF020, 1, -1, 0, 0xFFFFFFFFFFFFFF81), (0x38DFF020, 1, -1, 0, 0xFFFFFF81),
        (0x789FE020, 2, -2, 0, 0xFFFFFFFFFFFFFE81), (0x78DFE020, 2, -2, 0, 0xFFFFFE81),
        (0xB89FC020, 4, -4, 0, 0xFFFFFFFF8023FE81),
        (0xF9400021, 8, 0, 1, 0xCDAB45678023FE81),
        (0xF9000021, 8, 0, None, 0x5001),  # store source aliases address base
        (0x397FFC20, 1, 4095, 0, 0x81), (0x797FFC20, 2, 8190, 0, 0xFE81),
        (0xB97FFC20, 4, 16380, 0, 0x8023FE81), (0xF97FFC20, 8, 32760, 0, 0xCDAB45678023FE81),
        (0x393FFC22, 1, 4095, None, 0x0123456789ABCDEF),
        (0x793FFC22, 2, 8190, None, 0x0123456789ABCDEF),
        (0xB93FFC22, 4, 16380, None, 0x0123456789ABCDEF),
        (0xF93FFC22, 8, 32760, None, 0x0123456789ABCDEF)]
    contents = [0x81, 0xFE, 0x23, 0x80, 0x67, 0x45, 0xAB, 0xCD]
    for word, count, offset, dst, value in memory_forms:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["registers"][1:3] = [(0x5001 - offset) % (1 << 64), 0x0123456789ABCDEF]
        request["state"]["memory"] = [dict(address=0x5000 + i, value=byte,
            readable=True, writable=True, initialized=i != 2)
            for i, byte in enumerate([0xA5] + contents + [0x5A])]
        expected = copy.deepcopy(request["state"])
        event = dict(kind="read" if dst is not None else "write", address=0x5001,
                     value=contents[:count] if dst is not None else list(value.to_bytes(8, "little")[:count]),
                     initialized=(count == 1) if dst is not None else True)
        expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, events=[event], fault=None)
        if dst is not None:
            expected["registers"][dst] = value
        else:
            for cell, byte in zip(expected["memory"][1:1 + count], event["value"]):
                cell.update(value=byte, initialized=True)
        cases.append((request, expected))
    # Base31 is SP; data31 is ZR. An unaligned effective address through a
    # GPR is already exercised above. These SP offsets are legal too.
    for word, count, offset, store in [(0x394007FF, 1, 1, False), (0xF90007FF, 8, 8, True)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["registers"][31] = 0x5000
        request["state"]["memory"] = [dict(address=0x5000 + offset + i, value=0x81,
            readable=True, writable=True, initialized=False) for i in range(count)]
        expected = copy.deepcopy(request["state"])
        expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, fault=None,
            events=[dict(kind="write" if store else "read", address=0x5000 + offset,
                         value=[0 if store else 0x81] * count, initialized=store)])
        if store:
            for cell in expected["memory"]:
                cell.update(value=0, initialized=True)
        cases.append((request, expected))
    for word, sp, check in [(0x394003E0, 0x5001, True), (0x39403FE0, 0x4FF1, True),
                             (0xF90007FF, 0x5001, True), (0x394003E0, 0x5001, False)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"].update(sp_alignment_check=check,
            memory=[dict(address=0x5001, value=0x81, readable=True, writable=True, initialized=False)])
        request["state"]["registers"][31] = sp
        expected = copy.deepcopy(request["state"])
        if check:
            fault = dict(kind="sp_alignment", address=sp)
            expected.update(defined_flags=(1 << 64) - 1, events=[dict(kind="fault", fault=fault)], fault=fault)
        else:
            expected["registers"][0] = 0x81
            expected.update(pc=0x1004, defined_flags=(1 << 64) - 1, fault=None,
                events=[dict(kind="read", address=0x5001, value=[0x81], initialized=False)])
        cases.append((request, expected))
    # Each fault checks the whole width, including its last byte; a failed
    # store must preserve every previously writable byte and initialized bit.
    for word, kind in [(0xF9400020, "read"), (0xF9000022, "write"), (0xF940003F, "read")]:
        for mapped in (False, True):
            request = copy.deepcopy(base)
            request["native_bytes"] = list(word.to_bytes(4, "little"))
            request["state"]["registers"][1] = 0x5001
            request["state"]["memory"] = [dict(address=0x5001 + i, value=byte,
                readable=True, writable=True, initialized=False) for i, byte in enumerate(contents)] if mapped else []
            if mapped:
                request["state"]["memory"][-1]["readable" if kind == "read" else "writable"] = False
            expected = copy.deepcopy(request["state"])
            fault = dict(kind=kind, address=0x5001, bytes=8)
            expected.update(defined_flags=(1 << 64) - 1, events=[dict(kind="fault", fault=fault)], fault=fault)
            cases.append((request, expected))
    for word, target, store in [(0xF9400420, 4, False),
            (0xF9400020, (1 << 64) - 4, False), (0xF9000022, (1 << 64) - 4, True)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(word.to_bytes(4, "little"))
        request["state"]["registers"][1:3] = [(1 << 64) - 4, 0x0123456789ABCDEF]
        request["state"]["pc"] = (1 << 64) - 4
        request["state"]["memory"] = [dict(address=(target + i) % (1 << 64), value=byte,
            readable=True, writable=True, initialized=True) for i, byte in enumerate(contents)]
        expected = copy.deepcopy(request["state"])
        event_bytes = [0xEF, 0xCD, 0xAB, 0x89, 0x67, 0x45, 0x23, 0x01] if store else contents
        expected.update(pc=0, defined_flags=(1 << 64) - 1, fault=None,
            events=[dict(kind="write" if store else "read", address=target, value=event_bytes, initialized=True)])
        if store:
            for cell, byte in zip(expected["memory"], event_bytes):
                cell["value"] = byte
        else:
            expected["registers"][0] = 0xCDAB45678023FE81
        cases.append((request, expected))
    run = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
                         input="".join(json.dumps(q) + "\n" for q, _ in cases),
                         text=True, stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(cases)
    for (request, expected), out in zip(cases, outputs):
        assert out == expected, (request, out, expected)
    for word in (0x2A2183E0, 0x4BC107E0,
                 0x1AE22020, 0x53207C20, 0x131FFC20, 0x0A028020, 0x6A228020,
                 0x72C24680, 0x72E24680, 0x72024680, 0x12C24680, 0x12E24680,
                 0x52C24680, 0x52E24680, 0x32824680,
                 0x1EE70020, 0x9EAE0001, 0x0E205801, 0x4E205820,
                 0x2E303801, 0x6E303820, 0x2E703800, 0x6EB03800,
                 0x7A5F0835, 0x7A5F0C25, 0x5A5F0825, 0x3A5F0825,
                 0x91800420, 0xD1800420, 0x31800420, 0xF1800420,
                 0x0BC20020, 0x8BC20020, 0x0B028020, 0x0B828020, 0x6BC20020,
                 0x8B221420, 0x0B221820, 0x6B22FC20, 0xEB2277FF, 0x4B2117E0,
                 0x54000118, 0xD4000108, 0xD503203F,
                 0xB9C00020, 0xF9C00020, 0xB8C00020, 0xF8C00020):
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
    bank_request = copy.deepcopy(base)
    bank_request["native_bytes"] = list((0x9E670021).to_bytes(4, "little"))
    bad.append(bank_request)  # Missing complete bank must not imply zero.
    for vectors in ([0] * 31, [0] * 33, [0] * 32,
                    [base["state"]["vector0"]] + [0] * 30 + [1 << 128]):
        wrong_vectors = copy.deepcopy(bank_request)
        wrong_vectors["state"]["vectors"] = vectors
        bad.append(wrong_vectors)
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
    # GNU objdump sometimes preserves MOVZ/MOVN rather than printing MOV.
    # Check decoded constants, legal halfword columns, and real operation fields.
    for mnemonic, operands, width, value in [
            ("movz", ("w0", "#0xffff", "lsl #16"), 32, 0xFFFF0000),
            ("movz", ("x0", "#0x8000", "lsl #48"), 64, 0x8000000000000000),
            ("movz", ("x0", "#2", "lsl #16"), 64, 0x20000),
            ("movn", ("w0", "#0xffff", "lsl #16"), 32, 0xFFFF),
            ("movn", ("w0", "#0"), 32, 0xFFFFFFFF),
            ("movn", ("x0", "#0x8000", "lsl #48"), 64, 0x7FFFFFFFFFFFFFFF)]:
        insn = encoder.NativeInsn(32, mnemonic, operands, mnemonic + " " + ", ".join(operands), "target", 7)
        expected = encoder.Encoded("ARM64_OP_MOV_IMM", "ARM64_X0",
                                   width=f"ARM64_WIDTH_{width}", imm=f"{value}ULL")
        assert encoder.encode(insn, {}, {}) == expected, insn
        normalized = encoder.normalize_alias(insn)
        assert (normalized.addr, normalized.raw, normalized.reloc_symbol, normalized.reloc_addend) == (32, insn.raw, "target", 7)
    for operands, width, modifier, shift in [
            (("w0", "w1"), 32, "NONE", 0),
            (("w0", "w1", "asr #4"), 32, "ASR", 4),
            (("x0", "x1", "lsl #63"), 64, "LSL", 63)]:
        insn = encoder.NativeInsn(0, "negs", operands, "negs " + ", ".join(operands))
        expected = encoder.Encoded("ARM64_OP_SUBS_REG", "ARM64_X0", "ARM64_XZR", "ARM64_X1",
                                   width=f"ARM64_WIDTH_{width}", aux=f"ARM64_AUX_ALU(0, ARM64_MOD_{modifier}, {shift})")
        assert encoder.encode(insn, {}, {}) == expected, insn
    for width, prefix in [(32, "w"), (64, "x")]:
        for extension in ("uxtx", "sxtx"):
            insn = encoder.NativeInsn(0, "add", (prefix+"0", prefix+"1", prefix+"2", extension+" #4"), "add extend")
            expected = encoder.Encoded("ARM64_OP_ALU_REG", "ARM64_X0", "ARM64_X1", "ARM64_X2",
                                       width=f"ARM64_WIDTH_{width}", aux="ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_LSL, 4)")
            assert encoder.encode(insn, {}, {}) == expected, insn
    # Normalization must precede ABI/CFG analysis, not only final encoding.
    # Otherwise MOVZ fails to define a register and NEGS retains a stale CODE tag.
    positive = encoder.parse_flat_instructions("0: d2800021 \tmovz x1, #1\n4: eb0103e0 \tnegs x0, x1\n8: d65f03c0 \tret\n")
    encoder.render_program("wide_alias", "entry", encoder.OrderedDict(entry=positive), "xdp")
    clobber = encoder.parse_flat_instructions("0: 10000081 \tadr x1, 10\n4: d2800022 \tmovz x2, #1\n8: eb0203e1 \tnegs x1, x2\nc: d61f0020 \tbr x1\n10: 52800040 \tmov w0, #2\n14: d65f03c0 \tret\n")
    try:
        encoder.indirect_targets(clobber)
    except ValueError as error:
        assert "unbounded indirect target at 0xc" in str(error), error
    else:
        raise AssertionError("NEGS retained a stale code target")
    for mnemonic, operands in [
            ("movz", ("w0", "#1", "lsl #32")), ("movz", ("x0", "#1", "lsl #8")),
            ("movn", ("x0", "#0x10000")), ("movn", ("wsp", "#1")),
            ("negs", ("w0", "w1", "ror #1")), ("negs", ("w0", "w1", "lsl #32")),
            ("negs", ("x0", "x1", "sxtx #4")),
            ("negs", ("w0", "x1")), ("negs", ("sp", "x1")),
            ("add", ("x0", "x1", "x2", "sxtx #5"))]:
        try:
            encoder.encode(encoder.NativeInsn(0, mnemonic, operands, "invalid alias"), {}, {})
        except ValueError as error:
            assert str(error).startswith(("invalid move-wide", "invalid NEGS", "invalid AArch64 extend")), error
            continue
        raise AssertionError((mnemonic, operands, "invalid alias was accepted"))
    print("AArch64 reference: multiply/divide/select/extract/reverse/extend/shift/unary/logical/MOVK/MOVZ/MOVN/MOV-register/FMOV-all32/CNT/UADDLV/CCMP/ADD-SUB-immediate/shifted-register/extended-register/NOP/branches/scalar-memory, exact native decode, W zero-extension, ZR/SP, aliasing and state preservation OK")


if __name__ == "__main__":
    main()
