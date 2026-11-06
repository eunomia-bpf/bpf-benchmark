#!/usr/bin/env python3
"""All native condition encodings, exact SETcc writebacks, eager CMOV faults."""
import copy
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1 << 64) - 1


def main():
    cases = []
    base = dict(isa="x86_64", state=dict(registers=list(range(16)), flags=0x202,
        pc=0x1000, xmm0=(1 << 127) + 13, fs_base=17, gs_base=19, memory=[]))
    base["state"]["registers"][0] = 0xAABBCCDD12345678
    base["state"]["registers"][3] = 0x1122334487654321
    base["state"]["registers"][7] = 0x2001

    def request(code, flags, pc=0x1000):
        r = copy.deepcopy(base)
        r["native_bytes"] = list(bytes.fromhex(code))
        r["state"].update(flags=flags, pc=pc)
        return r

    def expected(r):
        e = copy.deepcopy(r["state"])
        e.update(pc=(e["pc"] + len(r["native_bytes"])) & MASK,
                 events=[], fault=None, defined_flags=MASK)
        return e

    for bits in range(64):
        cf, pf, af, zf, sf, of = [(bits >> i) & 1 for i in range(6)]
        flags = 0x202 | cf | (pf << 2) | (af << 4) | (zf << 6) | (sf << 7) | (of << 11)
        predicates = [of, cf, zf, cf or zf, sf, pf, sf != of, zf or (sf != of)]
        for cc in range(16):
            taken = int(predicates[cc // 2]) ^ (cc & 1)
            for code, offset in ((f"{0x70 + cc:02x}80", -128),
                                 (f"0f{0x80 + cc:02x}ffffff7f", 0x7FFFFFFF)):
                for pc in (0x1000, MASK):
                    r = request(code, flags, pc)
                    e = expected(r)
                    if taken: e["pc"] = (e["pc"] + offset) & MASK
                    cases.append((r, e))
            for prefix, width in (("66", 2), ("", 4), ("48", 8)):
                r = request(prefix + f"0f{0x40 + cc:02x}c3", flags)
                e = expected(r)
                value = r["state"]["registers"][3 if taken else 0]
                e["registers"][0] = (r["state"]["registers"][0] & ~0xFFFF) | (value & 0xFFFF) if width == 2 else \
                    value & ((1 << (width * 8)) - 1)
                cases.append((r, e))
            for prefix, modrm, dst, shift in (("", "c0", 0, 0), ("", "c4", 0, 8),
                                               ("40", "c4", 4, 0), ("41", "c0", 8, 0),
                                               ("", "f8", 0, 0)):
                r = request(prefix + f"0f{0x90 + cc:02x}" + modrm, flags)
                e = expected(r)
                e["registers"][dst] = (e["registers"][dst] & ~(255 << shift)) | (taken << shift)
                cases.append((r, e))
            r = request(f"0f{0x90 + cc:02x}07", flags)
            r["state"]["memory"] = [dict(address=0x2001, value=0xA5, readable=False, writable=True, initialized=False)]
            e = expected(r)
            e["memory"][0].update(value=taken, initialized=True)
            e["events"] = [dict(kind="write", address=0x2001, value=[taken], initialized=True)]
            cases.append((r, e))
            r = copy.deepcopy(r)
            r["state"]["memory"][0]["writable"] = False
            e = expected(r)
            e["pc"] = r["state"]["pc"]
            e["fault"] = dict(kind="write", address=0x2001, bytes=1)
            e["events"] = [dict(kind="fault", fault=e["fault"])]
            cases.append((r, e))
            r = request(f"480f{0x40 + cc:02x}07", flags)
            e = expected(r)
            e["pc"] = r["state"]["pc"]
            e["fault"] = dict(kind="read", address=0x2001, bytes=8)
            e["events"] = [dict(kind="fault", fault=e["fault"])]
            cases.append((r, e))
    for code, offset in (("ebff", -1), ("e900000080", -(1 << 31)), ("66e901000000", 1)):
        r = request(code, 0xAD7, MASK)
        e = expected(r)
        e["pc"] = (e["pc"] + offset) & MASK
        cases.append((r, e))
    for code in ("90", "6690", "4890", "f390", "0f1f00", "660f1f00", "0f1f440000", "0f1f840000000000"):
        r = request(code, 0xAD7)
        cases.append((r, expected(r)))
    run = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
        input="".join(json.dumps(r) + "\n" for r, _ in cases), text=True,
        stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(cases)
    for (r, e), actual in zip(cases, outputs):
        assert actual == e, (r, actual, e)
    print(f"x86 conditions: {len(cases)} all-code/native-width/lane/branch/memory/fault cases OK")


if __name__ == "__main__":
    main()
