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
    # POP reads the old stack, advances it, then writes the destination. Include
    # aliasing SP with a low16 carry, full RSP replacement, REX.B and faults.
    pop_cases = []
    for code, dst, width, rsp, value, fault in [
            ([0x5C], 4, 8, 0x2000, 0x3000, False),
            ([0x66, 0x5C], 4, 2, 0xFFFF, 0x1234, False),
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
    print("executable reference: CMOV writeback/eager faults, BT width/index/addressing, BZHI VEX/result flags, POP stack/destination alias and faults, undefined flags, arbitrary uninitialized bytes and signed displacement packing OK")


if __name__ == "__main__":
    main()
