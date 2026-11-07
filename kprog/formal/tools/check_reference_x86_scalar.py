#!/usr/bin/env python3
"""Concrete MOV/LEA encodings: register lanes, address prefixes and memory effects."""
import copy
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1 << 64) - 1


def main():
    base = dict(isa="x86_64", state=dict(registers=list(range(16)), flags=0x246,
        pc=0x1000, xmm0=(1 << 127) + 17, fs_base=0, gs_base=0, memory=[]))
    base["state"]["registers"][:5] = [0x1122334455667788, 0xABCDEF0198765432,
        0x7777777788888888, 0x8877665544332211, 0x9000ABCDEF12345A]
    base["state"]["registers"][7] = 0x112233445566778F
    base["state"]["registers"][8] = 0xFEDCBA98765432DD
    base["state"]["registers"][12] = 0x0102030405060708
    cases = []

    def result(request):
        expected = copy.deepcopy(request["state"])
        expected.update(pc=(expected["pc"] + len(request["native_bytes"])) & MASK,
                        events=[], fault=None, defined_flags=MASK)
        return expected

    # Fixed asymmetric values expose low/high-byte confusion, discarded REX40,
    # reversed register fields, accidental sign extension and merged writes.
    for code, dst, value in [
            ("88d8", 0, 0x1122334455667711), ("88fc", 0, 0x1122334455662288),
            ("88e0", 0, 0x1122334455667777), ("88c4", 0, 0x1122334455668888),
            ("4088e0", 0, 0x112233445566775A), ("4088fc", 4, 0x9000ABCDEF12348F),
            ("4488c0", 0, 0x11223344556677DD), ("4188c0", 8, 0xFEDCBA9876543288),
            ("6689d8", 0, 0x1122334455662211), ("89d8", 0, 0x44332211),
            ("4889d8", 0, 0x8877665544332211), ("4989d8", 8, 0x8877665544332211),
            ("4c89c0", 0, 0xFEDCBA98765432DD), ("404088e0", 0, 0x112233445566775A),
            ("486688e0", 0, 0x1122334455667777), ("664088e0", 0, 0x112233445566775A),
            ("486689d8", 0, 0x1122334455662211), ("664889d8", 0, 0x8877665544332211),
            ("4d89e0", 8, 0x0102030405060708),
            ("b07f", 0, 0x112233445566777F), ("b4fe", 0, 0x112233445566FE88),
            ("40b4fe", 4, 0x9000ABCDEF1234FE), ("41b4a5", 12, 0x01020304050607A5),
            ("66b8adde", 0, 0x112233445566DEAD), ("b8ffffffff", 0, 0xFFFFFFFF),
            ("48b8ffeeddccbbaa9988", 0, 0x8899AABBCCDDEEFF),
            ("48c7c0ffffffff", 0, MASK), ("66c7c0ffff", 0, 0x112233445566FFFF),
            ("c7c080000000", 0, 0x80), ("c6c480", 0, 0x1122334455668088),
            ("40c6c480", 4, 0x9000ABCDEF123480),
            ("66" * 13 + "b07f", 0, 0x112233445566777F)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(bytes.fromhex(code))
        expected = result(request)
        expected["registers"][dst] = value
        cases.append((request, expected))

    contents = [0xEF, 0xCD, 0xAB, 0x89, 0x67, 0x45, 0x23, 0x01]
    for code, count, load, dst, value, target in [
            ("8a07", 1, True, 0, 0x11223344556677EF, 0x2001),
            ("8a27", 1, True, 0, 0x112233445566EF88, 0x2001),
            ("408a27", 1, True, 4, 0x9000ABCDEF1234EF, 0x2001),
            ("668b07", 2, True, 0, 0x112233445566CDEF, 0x2001),
            ("8b07", 4, True, 0, 0x89ABCDEF, 0x2001),
            ("488b07", 8, True, 0, 0x0123456789ABCDEF, 0x2001),
            ("488b3f", 8, True, 7, 0x0123456789ABCDEF, 0x2001),
            ("678b07", 4, True, 0, 0x89ABCDEF, 0x2001),
            ("64488b07", 8, True, 0, 0x0123456789ABCDEF, 0x2001),
            ("65488b07", 8, True, 0, 0x0123456789ABCDEF, 0x2001),
            ("8b0500000000", 4, True, 0, 0x89ABCDEF, 0x1006),
            ("8b05ffffffff", 4, True, 0, 0x89ABCDEF, 0x1005),
            ("8827", 1, False, None, 0x77, 0x2001),
            ("408827", 1, False, None, 0x5A, 0x2001),
            ("668907", 2, False, None, 0x7788, 0x2001),
            ("8907", 4, False, None, 0x55667788, 0x2001),
            ("488907", 8, False, None, 0x1122334455667788, 0x2001),
            ("c607ff", 1, False, None, 0xFF, 0x2001),
            ("66c707ffff", 2, False, None, 0xFFFF, 0x2001),
            ("c707ffffffff", 4, False, None, 0xFFFFFFFF, 0x2001),
            ("48c707ffffffff", 8, False, None, MASK, 0x2001),
            ("48c70500000000ffffffff", 8, False, None, MASK, 0x100B),
            ("a00120000000000000", 1, True, 0, 0x11223344556677EF, 0x2001),
            ("a10120000000000000", 4, True, 0, 0x89ABCDEF, 0x2001),
            ("66a10120000000000000", 2, True, 0, 0x112233445566CDEF, 0x2001),
            ("48a10120000000000000", 8, True, 0, 0x0123456789ABCDEF, 0x2001),
            ("67a101200000", 4, True, 0, 0x89ABCDEF, 0x2001),
            ("67a101200080", 4, True, 0, 0x89ABCDEF, 0x80002001),
            ("a20120000000000000", 1, False, None, 0x88, 0x2001),
            ("a30120000000000000", 4, False, None, 0x55667788, 0x2001),
            ("48a30120000000000000", 8, False, None, 0x1122334455667788, 0x2001),
            ("67a201200000", 1, False, None, 0x88, 0x2001)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(bytes.fromhex(code))
        request["state"]["registers"][7] = 0x2001
        if code.startswith("678b"):
            request["state"]["registers"][7] += 1 << 32
        if code.startswith("64"):
            request["state"]["registers"][7] -= 0x10
            request["state"]["fs_base"] = 0x10
        if code.startswith("65"):
            request["state"]["registers"][7] -= 0x100
            request["state"]["gs_base"] = 0x100
        request["state"]["memory"] = [dict(address=target + i - 1, value=byte,
            readable=load, writable=not load, initialized=False)
            for i, byte in enumerate([0xA5] + contents + [0x5A])]
        expected = result(request)
        event_bytes = contents[:count] if load else list(value.to_bytes(count, "little"))
        expected["events"] = [dict(kind="read" if load else "write", address=target,
                                  value=event_bytes, initialized=not load)]
        if load:
            expected["registers"][dst] = value
        else:
            for cell, byte in zip(expected["memory"][1:1 + count], event_bytes):
                cell.update(value=byte, initialized=True)
        cases.append((request, expected))

    for code, count, kind in [("8a07", 1, "read"), ("668b07", 2, "read"),
            ("8b07", 4, "read"), ("488b07", 8, "read"), ("8807", 1, "write"),
            ("668907", 2, "write"), ("8907", 4, "write"), ("488907", 8, "write")]:
        request = copy.deepcopy(base)
        request["native_bytes"] = list(bytes.fromhex(code))
        request["state"]["registers"][7] = 0x2001
        request["state"]["memory"] = [dict(address=0x2001 + i, value=byte,
            readable=True, writable=True, initialized=False) for i, byte in enumerate(contents)]
        request["state"]["memory"][count - 1]["readable" if kind == "read" else "writable"] = False
        expected = copy.deepcopy(request["state"])
        fault = dict(kind=kind, address=0x2001, bytes=count)
        expected.update(events=[dict(kind="fault", fault=fault)], fault=fault, defined_flags=MASK)
        cases.append((request, expected))
    request = copy.deepcopy(base)
    request["native_bytes"] = [0xB0, 0x7F]  # MOV AL,0x7f at wrapping PC
    request["state"]["pc"] = MASK
    expected = result(request)
    expected["registers"][0] = 0x112233445566777F
    cases.append((request, expected))
    # LEA reads neither addressed memory nor segment bases. The address-size
    # truncation precedes the destination's independent partial write.
    lea_cases = [
        ("488d4705",0,64,7,None,0,5,False,False),
        ("488d44c7fd",0,64,7,0,3,-3,False,False),
        ("488d0447",0,64,7,0,1,0,False,False),
        ("4b8d44e405",0,64,12,12,3,5,False,False),
        ("4c8d440705",8,64,7,0,0,5,False,False),
        ("488d2c24",5,64,4,None,0,0,False,False),
        ("488d0501000000",0,64,None,None,0,1,True,False),
        ("488d0425ffffffff",0,64,None,None,0,-1,False,False),
        ("67488d0425ffffffff",0,64,None,None,0,-1,False,True),
        ("678d0501000000",0,32,None,None,0,1,True,True),
        ("488d5b01",3,64,3,None,0,1,False,False),
        ("8d44c7fd",0,32,7,0,3,-3,False,False),
        ("668d44c7fd",0,16,7,0,3,-3,False,False),
        ("66488d44c7fd",0,64,7,0,3,-3,False,False),
        ("48668d44c7fd",0,16,7,0,3,-3,False,False),
        ("64488d4705",0,64,7,None,0,5,False,False),
        ("65488d4705",0,64,7,None,0,5,False,False),
        ("48648d4705",0,32,7,None,0,5,False,False),
        ("66"*13+"8d00",0,16,0,None,0,0,False,False)]
    for code,dst,width,base_reg,index_reg,scale,disp,relative,address32 in lea_cases:
        for pc in (0x1000,MASK-5):
            request=copy.deepcopy(base)
            request["native_bytes"]=list(bytes.fromhex(code))
            state=request["state"]
            state.update(pc=pc,fs_base=0x123400000000,gs_base=0x567800000000)
            expected=result(request)
            address=(pc+len(request["native_bytes"])) if relative else state["registers"][base_reg] if base_reg is not None else 0
            address=(address+disp+(state["registers"][index_reg]<<scale if index_reg is not None else 0))&MASK
            if address32: address &= 0xFFFFFFFF
            # An absent memory mapping is intentional: even a noncanonical
            # offset must not turn LEA into a read, a fault or a helper event.
            value=address&((1<<width)-1)
            expected["registers"][dst]=(state["registers"][dst]&~0xFFFF)|value if width==16 else value
            cases.append((request,expected))
    run = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
        input="".join(json.dumps(request) + "\n" for request, _ in cases),
        text=True, stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(cases)
    for (request, expected), output in zip(cases, outputs):
        assert output == expected, (request, output, expected)
    for code in ("b8ffffff", "48b800", "a001200000", "c7c801000000", "66" * 14 + "b07f", "488dc0", "488d44", "66"*14+"8d00"):
        request = copy.deepcopy(base)
        request["native_bytes"] = list(bytes.fromhex(code))
        run = subprocess.run([str(ROOT / ".lake/build/bin/reference")], input=json.dumps(request) + "\n",
                             text=True, capture_output=True)
        assert run.returncode == 1 and run.stderr.startswith("reference:"), (request, run)
    print("x86 scalar reference: MOV/LEA lanes, REX/order, ModRM/SIB/RIP, address-size/segment rules, exact reads/faults and full preservation OK")


if __name__ == "__main__":
    main()
