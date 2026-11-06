#!/usr/bin/env python3
"""Regress native instruction counterexamples and the executable reference wire ABI."""
import copy
import importlib.util
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parent.parent


def main():
    base = {
        "state": {"registers": [0xDEADBEEF12345678] + list(range(1, 16)),
                  "flags": 0x202, "pc": 0x1000, "xmm0": (1 << 127) + 17,
                  "fs_base": 0, "gs_base": 0, "memory": []},
        "native_bytes": [0x0F, 0x44, 0xC3]}  # CMOVE EAX, EBX
    requests = [copy.deepcopy(base) for _ in range(8)]
    cells = [{"address": 0x2000 + i, "value": b, "readable": True,
              "writable": False, "initialized": i != 0}
             for i, b in enumerate([0xEF, 0xBE])]
    requests[1]["state"]["memory"] = cells
    requests[1]["state"]["registers"][7] = 0x1FF8
    requests[1]["native_bytes"] = [0x66, 0x0F, 0x44, 0x47, 8]  # AX,[RDI+8]
    requests[2]["state"]["registers"][7] = 0x2FF8
    requests[2]["native_bytes"] = [0x0F, 0x44, 0x47, 8]  # fault at 0x3000
    requests[3]["native_bytes"] = [0x48, 0x0F, 0x45, 0xC3]  # CMOVNE RAX,RBX
    requests[4]["state"]["flags"] = 0x242
    requests[4]["state"]["registers"][12] = 0x2000
    requests[4]["state"]["registers"][9] = 2
    requests[4]["state"]["memory"] = [
        {"address": 0x2000 + i, "value": b, "readable": True,
         "writable": False, "initialized": True}
        for i, b in enumerate([0xEF, 0xCD, 0xAB, 0x89, 0x67, 0x45, 0x23, 1])]
    requests[4]["native_bytes"] = [0x4B, 0x0F, 0x44, 0x44, 0x8C, 0xF8]  # R12+4*R9-8
    requests[5]["state"]["flags"] = 0x242
    requests[5]["state"]["registers"][9] = 0xDEADBEEF55667788
    requests[5]["native_bytes"] = [0x45, 0x0F, 0x44, 0xC1]  # CMOVE R8D,R9D
    requests[6]["state"]["flags"] = 0x242
    requests[6]["state"]["registers"][7] = 0x100001FF8
    requests[6]["state"]["memory"] = requests[4]["state"]["memory"][:4]
    requests[6]["native_bytes"] = [0x67, 0x0F, 0x44, 0x47, 8]  # address-size override
    requests[7]["state"]["flags"] = 0x242
    requests[7]["state"]["fs_base"] = 0x4000
    requests[7]["state"]["registers"][7] = 0x1FF8
    requests[7]["state"]["memory"] = [dict(c, address=c["address"] + 0x4000)
                                        for c in requests[4]["state"]["memory"]]
    requests[7]["native_bytes"] = [0x64, 0x48, 0x0F, 0x44, 0x47, 8]  # FS-relative
    run = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
                         input="".join(json.dumps(r) + "\n" for r in requests),
                         text=True, stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(requests), "reference lost a request"
    for i, (request, out) in enumerate(zip(requests, outputs)):
        before = request["state"]
        expected = copy.deepcopy(before)
        expected.update(events=[], fault=None, defined_flags=(1 << 64) - 1, pc=before["pc"] + len(request["native_bytes"]))
        if i == 0:
            expected["registers"][0] = 0x12345678  # false EAX write clears high half
        elif i == 1:
            expected["events"] = [{"kind": "read", "address": 0x2000,
                                   "value": [0xEF, 0xBE], "initialized": False}]
        elif i == 2:
            expected["pc"] = before["pc"]
            expected["fault"] = {"kind": "read", "address": 0x3000, "bytes": 4}
            expected["events"] = [{"kind": "fault", "fault": expected["fault"]}]
        elif i == 3:
            expected["registers"][0] = 3
        elif i in (4, 6, 7):
            value = 0x89ABCDEF if i == 6 else 0x0123456789ABCDEF
            expected["registers"][0] = value
            address = 0x6000 if i == 7 else 0x2000
            read = before["memory"][:4] if i == 6 else before["memory"]
            expected["events"] = [{"kind": "read", "address": address,
                                   "value": [c["value"] for c in read], "initialized": True}]
        elif i == 5:
            expected["registers"][8] = 0x55667788
        assert out == expected, (i, out, expected)
    # BT regressions: operand-size wrapping, signed memory bit strings, and
    # RIP-relative fall-through including the trailing immediate byte.
    bt_cases = []
    def bt_request(code, regs, cells=None, pc=0x1000):
        request = copy.deepcopy(base)
        request["native_bytes"] = code
        request["state"]["registers"] = regs
        request["state"]["memory"] = cells or []
        request["state"]["pc"] = pc
        return request
    regs = list(range(16))
    regs[0], regs[3] = 1, 16
    bt_cases.append((bt_request([0x66, 0x0F, 0xA3, 0xD8], regs), True, None))
    bt_cases.append((bt_request([0x0F, 0xBA, 0xE0, 32], regs), True, None))
    mem = [{"address": 0x2000 + i, "value": b, "readable": True,
            "writable": False, "initialized": False} for i, b in enumerate([0, 128])]
    regs = regs.copy()
    regs[7], regs[3] = 0x2000, (1 << 64) - 1
    bt_cases.append((bt_request([0x66, 0x0F, 0xBA, 0x27, 255], regs, mem), True, 0x2000))
    regs = regs.copy()
    regs[7] = 0x2002
    bt_cases.append((bt_request([0x66, 0x0F, 0xA3, 0x1F], regs, mem), True, 0x2000))
    bt_cases.append((bt_request([0x66, 0x0F, 0xBA, 0x25, 0xF7, 15, 0, 0, 15],
                               regs, mem), True, 0x2000))
    bt_cases.append((bt_request([0x48, 0x0F, 0xBA, 0x27, 7], regs), None, None))
    run = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
                         input="".join(json.dumps(r) + "\n" for r, _, _ in bt_cases),
                         text=True, stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(bt_cases)
    for (request, carry, address), out in zip(bt_cases, outputs):
        expected = copy.deepcopy(request["state"])
        if carry is None:
            fault = {"kind": "read", "address": 0x2002, "bytes": 8}
            expected.update(defined_flags=(1 << 64) - 1, fault=fault,
                            events=[{"kind": "fault", "fault": fault}])
        else:
            expected.update(pc=expected["pc"] + len(request["native_bytes"]),
                            flags=(expected["flags"] & ~1) | carry,
                            defined_flags=0xFFFFFFFFFFFFF76B, fault=None, events=[])
            if address is not None:
                expected["events"] = [{"kind": "read", "address": address,
                                       "value": [0, 128], "initialized": False}]
        assert out == expected, (request, out, expected)
    # BZHI sets SF from a retained sign bit and reads only the count's low byte.
    bzhi_cases = []
    def bzhi_request(code, count, value, result, flag_bits, dst=0, src=1, cnt=3, cells=None):
        request = copy.deepcopy(base)
        request["native_bytes"] = code
        request["state"]["flags"] = 0xAD7
        request["state"]["registers"][cnt] = count
        request["state"]["registers"][src] = value
        request["state"]["registers"][7] = 0x1FF8
        request["state"]["memory"] = cells or []
        bzhi_cases.append((request, result, flag_bits, dst))
    bzhi_request([0xC4, 0xE2, 0xE0, 0xF5, 0xC1], 64, 1 << 63, 1 << 63, 0x81)
    bzhi_request([0xC4, 0xE2, 0x60, 0xF5, 0xC1], 32, 0xFFFFFFFF80000000, 1 << 31, 0x81)
    bzhi_request([0xC4, 0xE2, 0x60, 0xF5, 0xC1], 31, 0xFFFFFFFF80000000, 0, 0x40)
    bzhi_request([0xC4, 0xE2, 0xE0, 0xF5, 0xC1], 256, (1 << 64) - 1, 0, 0x40)
    bzhi_request([0xC4, 0x42, 0x30, 0xF5, 0xC2], 32, 0xFFFFFFFF80000000, 1 << 31,
                 0x81, dst=8, src=10, cnt=9)
    bzhi_mem = [dict(address=0x2000 + i, value=b, readable=True, writable=True,
                     initialized=True) for i, b in enumerate(bytes.fromhex("efcdab8967452381"))]
    bzhi_request([0xC4, 0xE2, 0xE0, 0xF5, 0x47, 8], 64, 0, 0x8123456789ABCDEF,
                 0x81, cells=bzhi_mem)
    run = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
                         input="".join(json.dumps(r) + "\n" for r, _, _, _ in bzhi_cases),
                         text=True, stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(bzhi_cases)
    for (request, result, flag_bits, dst), out in zip(bzhi_cases, outputs):
        expected = copy.deepcopy(request["state"])
        expected["registers"][dst] = result
        expected.update(flags=(expected["flags"] & ~0x8C1) | flag_bits,
                        pc=expected["pc"] + len(request["native_bytes"]),
                        defined_flags=0xFFFFFFFFFFFFFFEB, fault=None, events=[])
        if expected["memory"]:
            expected["events"] = [{"kind": "read", "address": 0x2000,
                                   "value": list(bytes.fromhex("efcdab8967452381")),
                                   "initialized": True}]
        assert out == expected, (request, out, expected)
    # ANDN differs from ordinary AND: inversion applies to the first source,
    # while AF/PF are undefined. Include zero/sign, 32-bit upper clearing,
    # extended registers, aliasing and a destination-addressed memory source.
    andn_cases = []
    for code, dst, first, second, a_value, b_value, result, bits in [
            ([0xC4, 0xE2, 0xE0, 0xF2, 0xC1], 0, 3, 1, 0xF0, 0xFF, 15, 0),
            ([0xC4, 0xE2, 0x60, 0xF2, 0xC1], 0, 3, 1, 0, 0xDEADBEEF00000000, 0, 0x40),
            ([0xC4, 0xE2, 0x60, 0xF2, 0xC1], 0, 3, 1, 0, 0xFFFFFFFF80000000, 1 << 31, 0x80),
            ([0xC4, 0x42, 0x30, 0xF2, 0xC2], 8, 9, 10, 0xF0, 0xFF, 15, 0),
            ([0xC4, 0xE2, 0xF8, 0xF2, 0xC1], 0, 0, 1, 0xF0, 0xFF, 15, 0),
            ([0xC4, 0xE2, 0xE0, 0xF2, 0x40, 8], 0, 3, None, 0xF0, 0xFF, 15, 0),
            ([0xC4, 0xE2, 0xE0, 0xF2, 0x40, 8], 0, 3, None, 0xF0, None, None, None)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = code
        request["state"]["flags"] = 0xAD7
        request["state"]["registers"][first] = a_value
        if second is None:
            request["state"]["registers"][0] = 0x1FF8
            if b_value is not None:
                request["state"]["memory"] = [
                    dict(address=0x2000 + i, value=b, readable=True, writable=False,
                         initialized=True) for i, b in enumerate(b_value.to_bytes(8, "little"))]
        else:
            request["state"]["registers"][second] = b_value
        expected = copy.deepcopy(request["state"])
        expected.update(defined_flags=0xFFFFFFFFFFFFFFEB, fault=None, events=[])
        if result is None:
            reason = dict(kind="read", address=0x2000, bytes=8)
            expected.update(defined_flags=(1 << 64) - 1, fault=reason,
                            events=[dict(kind="fault", fault=reason)])
        else:
            expected["pc"] += len(code)
            expected["registers"][dst] = result
            expected["flags"] = (expected["flags"] & ~0x8C1) | bits
            if second is None:
                expected["events"] = [dict(kind="read", address=0x2000,
                                           value=list(b_value.to_bytes(8, "little")), initialized=True)]
        andn_cases.append((request, expected))
    run = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
                         input="".join(json.dumps(r) + "\n" for r, _ in andn_cases),
                         text=True, stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(andn_cases)
    for (request, expected), out in zip(andn_cases, outputs):
        assert out == expected, (request, out, expected)
    # POP reads the old stack, advances it, then writes the destination. Include
    # aliasing SP with a low16 carry, full RSP replacement, REX.B and faults.
    pop_cases = []
    for code, dst, width, rsp, value, fault in [
            ([0x5C], 4, 8, 0x2000, 0x3000, False),
            ([0x66, 0x5C], 4, 2, 0xFFFF, 0x1234, False),
            ([0x66, 0x48, 0x5C], 4, 8, 0x2000, 0x3000, False),
            ([0x48, 0x66, 0x5C], 4, 2, 0xFFFF, 0x1234, False),
            ([0x66, 0x48, 0x8F, 0xC4], 4, 8, 0x2000, 0x3000, False),
            ([0x41, 0x5C], 12, 8, 0x2000, 0xFEDCBA9876543210, False),
            ([0x66, 0x41, 0x5C], 12, 2, 0x2000, 0x1234, False),
            ([0x8F, 0xC4], 4, 8, 0x2000, 0x3000, False),
            ([0x66, 0x8F, 0xC0], 0, 2, 0x2000, 0x1234, False),
            ([0x58], 0, 8, 0x2000, 0x3000, True)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = code
        request["state"]["registers"][4] = rsp
        request["state"]["memory"] = [
            dict(address=rsp + i, value=b, readable=not fault, writable=False,
                 initialized=i != 0) for i, b in enumerate(value.to_bytes(width, "little"))]
        expected = copy.deepcopy(request["state"])
        expected.update(defined_flags=(1 << 64) - 1, fault=None, events=[])
        if fault:
            reason = dict(kind="read", address=rsp, bytes=width)
            expected.update(fault=reason, events=[dict(kind="fault", fault=reason)])
        else:
            expected["pc"] += len(code)
            expected["registers"][4] = rsp + width
            old = expected["registers"][dst]
            expected["registers"][dst] = value if width == 8 else (old & ~0xFFFF) | value
            expected["events"] = [dict(kind="read", address=rsp,
                                       value=list(value.to_bytes(width, "little")),
                                       initialized=False)]
        pop_cases.append((request, expected))
    run = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
                         input="".join(json.dumps(r) + "\n" for r, _ in pop_cases),
                         text=True, stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(pop_cases)
    for (request, expected), out in zip(pop_cases, outputs):
        assert out == expected, (request, out, expected)
    # PUSH captures the old source (including RSP), writes exactly the operand
    # bytes, initializes those bytes only, and commits nothing on a late fault.
    push_cases = []
    for width in (2, 8):
        for src in range(16):
            for fault in (False, True):
                request = copy.deepcopy(base)
                request["native_bytes"] = ([0x66] if width == 2 else []) + (
                    [0x41] if src >= 8 else []) + [0x50 + src % 8]
                registers = request["state"]["registers"]
                registers[src] = 0xFEDCBA9876543210
                registers[4] = 0x2000
                address = 0x2000 - width
                cells = [dict(address=address + i, value=0xAA, readable=True,
                              writable=not (fault and i == width - 1), initialized=False)
                         for i in range(width + 1)]
                request["state"]["memory"] = cells
                expected = copy.deepcopy(request["state"])
                expected.update(defined_flags=(1 << 64) - 1, fault=None, events=[])
                if fault:
                    reason = dict(kind="write", address=address, bytes=width)
                    expected.update(fault=reason, events=[dict(kind="fault", fault=reason)])
                else:
                    expected["pc"] += len(request["native_bytes"])
                    expected["registers"][4] = address
                    value = registers[src] & ((1 << (8 * width)) - 1)
                    written = list(value.to_bytes(width, "little"))
                    for cell, byte in zip(expected["memory"], written):
                        cell.update(value=byte, initialized=True)
                    expected["events"] = [dict(kind="write", address=address,
                                               value=written, initialized=True)]
                push_cases.append((request, expected))
    # REX.W overrides66; a later legacy prefix invalidates an earlier REX.
    for code, width in [([0x66, 0x48, 0x53], 8), ([0x48, 0x66, 0x53], 2),
                        ([0x66, 0x48, 0xFF, 0xF3], 8), ([0x48, 0x66, 0xFF, 0xF3], 2)]:
        request = copy.deepcopy(base)
        request["native_bytes"] = code
        request["state"]["registers"][4] = 0x2000
        request["state"]["registers"][3] = 0xFEDCBA9876543210
        address = 0x2000 - width
        request["state"]["memory"] = [dict(address=address + i, value=0xAA,
            readable=True, writable=True, initialized=False) for i in range(width)]
        expected = copy.deepcopy(request["state"])
        written = list((0xFEDCBA9876543210 & ((1 << (8 * width)) - 1)).to_bytes(width, "little"))
        for cell, byte in zip(expected["memory"], written):
            cell.update(value=byte, initialized=True)
        expected["registers"][4] = address
        expected.update(pc=expected["pc"] + len(code), defined_flags=(1 << 64) - 1,
                        fault=None, events=[dict(kind="write", address=address, value=written, initialized=True)])
        push_cases.append((request, expected))
    run = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
                         input="".join(json.dumps(r) + "\n" for r, _ in push_cases),
                         text=True, stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(push_cases)
    for (request, expected), out in zip(push_cases, outputs):
        assert out == expected, (request, out, expected)
    # Full-field stack routes: signed immediates, source-before-decrement PUSH,
    # destination-after-increment POP, aliasing and read-before-write faults.
    stack_cases = []
    for code, operation, width, value, address, failure in [
            ([0x6A, 0xFF], "immediate", 8, (1 << 64) - 1, None, None),
            ([0x68, 0, 0, 0, 0x80], "immediate", 8, 0xFFFFFFFF80000000, None, None),
            ([0x66, 0x68, 0, 0x80], "immediate", 2, 0x8000, None, None),
            ([0x66, 0x6A, 0x80], "immediate", 2, 0xFF80, None, None),
            ([0x66, 0x48, 0x68, 0, 0, 0, 0x80], "immediate", 8, 0xFFFFFFFF80000000, None, None),
            ([0x6A, 1], "immediate", 8, 1, None, "write"),
            ([0xFF, 0x34, 0x24], "push", 8, 0xFEDCBA9876543210, 0x2000, None),
            ([0x66, 0xFF, 0x34, 0x24], "push", 2, 0xABCD, 0x2000, None),
            ([0xFF, 0x77, 8], "push", 8, 0xFEDCBA9876543210, 0x3000, None),
            ([0x43, 0xFF, 0x74, 0x8C, 0xF8], "push", 8, 0xFEDCBA9876543210, 0x3000, None),
            ([0xFF, 0x35, 0xFA, 0x1F, 0, 0], "push", 8, 0xFEDCBA9876543210, 0x3000, None),
            ([0x64, 0xFF, 0x37], "push", 8, 0xFEDCBA9876543210, 0x3FF8, None),
            ([0x67, 0xFF, 0x77, 8], "push", 8, 0xFEDCBA9876543210, 0x3000, None),
            ([0xFF, 0x34, 0x24], "push", 8, 0xFEDCBA9876543210, 0x2000, "read"),
            ([0xFF, 0x34, 0x24], "push", 8, 0xFEDCBA9876543210, 0x2000, "write"),
            ([0x8F, 0x04, 0x24], "pop", 8, 0xFEDCBA9876543210, 0x2008, None),
            ([0x66, 0x8F, 0x04, 0x24], "pop", 2, 0xABCD, 0x2002, None),
            ([0x8F, 0x44, 0x24, 0xF8], "pop", 8, 0xFEDCBA9876543210, 0x2000, None),
            ([0x8F, 0x47, 8], "pop", 8, 0xFEDCBA9876543210, 0x3000, None),
            ([0x8F, 0x05, 0xFA, 0x1F, 0, 0], "pop", 8, 0xFEDCBA9876543210, 0x3000, None),
            ([0x64, 0x8F, 0x07], "pop", 8, 0xFEDCBA9876543210, 0x3FF8, None),
            ([0x8F, 0x04, 0x24], "pop", 8, 0xFEDCBA9876543210, 0x2008, "read"),
            ([0x8F, 0x04, 0x24], "pop", 8, 0xFEDCBA9876543210, 0x2008, "write")]:
        request = copy.deepcopy(base)
        request["native_bytes"] = code
        before = request["state"]
        before["registers"][4] = 0x2000
        before["registers"][7] = 0x100002FF8 if code[0] == 0x67 else 0x2FF8
        before["registers"][9], before["registers"][12] = 2, 0x3000
        before["fs_base"] = 0x1000
        read_address = 0x2000 if operation == "pop" else address
        write_address = address if operation == "pop" else 0x2000 - width
        written = list(value.to_bytes(width, "little"))
        mapped = {write_address + i: dict(address=write_address + i, value=0xAA,
                  readable=True, writable=not (failure in ("read", "write") and i == width - 1),
                  initialized=False) for i in range(width + 1)}
        if read_address is not None:
            for i, byte in enumerate(written):
                cell = mapped.setdefault(read_address + i, dict(address=read_address + i,
                    writable=True))
                cell.update(value=byte, readable=not (failure == "read" and i == width - 1),
                            initialized=i != 0)
        before["memory"] = sorted(mapped.values(), key=lambda cell: cell["address"])
        expected = copy.deepcopy(before)
        expected.update(defined_flags=(1 << 64) - 1, fault=None, events=[])
        if read_address is not None and failure != "read":
            expected["events"].append(dict(kind="read", address=read_address,
                                            value=written, initialized=False))
        if failure:
            reason = dict(kind=failure, address=read_address if failure == "read" else write_address,
                          bytes=width)
            expected["fault"] = reason
            expected["events"].append(dict(kind="fault", fault=reason))
        else:
            expected["pc"] += len(code)
            expected["registers"][4] = 0x2000 + width if operation == "pop" else write_address
            for cell in expected["memory"]:
                index = cell["address"] - write_address
                if 0 <= index < width:
                    cell.update(value=written[index], initialized=True)
            expected["events"].append(dict(kind="write", address=write_address,
                                            value=written, initialized=True))
        stack_cases.append((request, expected))
    run = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
                         input="".join(json.dumps(r) + "\n" for r, _ in stack_cases),
                         text=True, stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(stack_cases)
    for (request, expected), out in zip(stack_cases, outputs):
        assert out == expected, (request, out, expected)
    # Reject rather than truncate malformed wire words and duplicate mappings.
    malformed = copy.deepcopy(base)
    malformed["state"]["registers"][0] = 1 << 64
    bad = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
                         input=json.dumps(malformed) + "\n", text=True, capture_output=True)
    assert bad.returncode == 1 and "64-bit range" in bad.stderr, bad
    duplicate = copy.deepcopy(base)
    duplicate["state"]["memory"] = [cells[0], cells[0]]
    bad = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
                         input=json.dumps(duplicate) + "\n", text=True, capture_output=True)
    assert bad.returncode == 1 and "duplicate memory address" in bad.stderr, bad
    truncated = copy.deepcopy(base)
    truncated["native_bytes"] = [0x0F, 0x44]
    bad = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
                         input=json.dumps(truncated) + "\n", text=True, capture_output=True)
    assert bad.returncode == 1 and "truncated native" in bad.stderr, bad
    # Pin the producer/consumer serialization bug found by lane F: a CMOV
    # memory source uses the checked contract's signed HIGH displacement half.
    directory = ROOT.parent / "x86/micro-prog"
    sys.path.insert(0, str(directory))
    spec = importlib.util.spec_from_file_location("reference_encoder", directory / "generate_micro_sim_proofs.py")
    encoder = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = encoder
    spec.loader.exec_module(encoder)
    for disp in [0, 8, -8, 0x7FFFFFFF, -0x80000000]:
        mem = f"QWORD PTR [rdi{'+' if disp >= 0 else '-'}0x{abs(disp):x}]"
        insn = encoder.NativeInsn(0, f"cmove rax, {mem}", "cmove", ("rax", mem))
        encoded = encoder.encode(insn, {})
        raw = int(encoded.imm.removesuffix("ULL"), 0)
        got = (raw >> 32) & 0xFFFFFFFF
        if got & 0x80000000:
            got -= 1 << 32
        assert got == disp, (insn, encoded, got)
    print("executable reference: CMOV writeback/eager faults, BT width/index/addressing, BZHI/ANDN VEX/result flags, PUSH immediate/memory and POP memory ordering, stack aliases, exact writes and faults, undefined flags, arbitrary uninitialized bytes and signed displacement packing OK")


if __name__ == "__main__":
    main()
