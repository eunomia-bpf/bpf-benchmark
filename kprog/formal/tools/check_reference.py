#!/usr/bin/env python3
"""Regress native CMOV counterexamples and the executable reference wire ABI."""
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
        expected.update(events=[], fault=None, pc=before["pc"] + len(request["native_bytes"]))
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
    assert bad.returncode == 1 and "truncated CMOV" in bad.stderr, bad
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
    print("executable reference: CMOV high-half clearing, eager reads/faults, arbitrary uninitialized values, frame/JSON ABI and signed displacement packing OK")


if __name__ == "__main__":
    main()
