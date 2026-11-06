#!/usr/bin/env python3
"""Native logical encodings, five defined flags, lane writes and memory faults."""
import copy
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1 << 64) - 1


def main():
    cases = []

    def add(code, width, kind, left, right, *, lane=0, source_lane=0, memory=None, fault=None, address=0x2001):
        r = dict(isa="x86_64", native_bytes=list(bytes.fromhex(code)), state=dict(
            registers=list(range(16)), flags=0xFFF, pc=0x1000, xmm0=(1 << 127) + 11,
            fs_base=0, gs_base=0, memory=[]))
        s = r["state"]
        s["registers"][0], s["registers"][3], s["registers"][7] = left, right, address
        mask = (1 << (8 * width)) - 1
        a, b = (left >> lane) & mask, (right >> source_lane) & mask
        value = (a & b) if kind in ("and", "test") else (a | b) if kind == "or" else (a ^ b)
        if memory:
            raw = left if memory == "destination" else right
            s["memory"] = [dict(address=address + i, value=(raw >> (8 * i)) & 255,
                readable=True, writable=kind != "test", initialized=False) for i in range(width)]
            if fault: s["memory"][-1]["readable" if fault == "read" else "writable"] = False
        e = copy.deepcopy(s)
        e.update(pc=s["pc"] + len(r["native_bytes"]), events=[], fault=None, defined_flags=MASK ^ 16)
        e["flags"] = (s["flags"] & ~0x8C5) | (int((value & 255).bit_count() % 2 == 0) << 2) | \
            (int(value == 0) << 6) | ((value >> (width * 8 - 1)) << 7)
        if memory and fault != "read":
            e["events"] = [dict(kind="read", address=address,
                value=[c["value"] for c in s["memory"]], initialized=False)]
        if fault:
            e.update(pc=s["pc"], flags=s["flags"], defined_flags=MASK)
            e["fault"] = dict(kind=fault, address=address, bytes=width)
            e["events"].append(dict(kind="fault", fault=e["fault"]))
        elif kind != "test":
            if memory == "destination":
                data = list(value.to_bytes(width, "little"))
                for c, byte in zip(e["memory"], data): c.update(value=byte, initialized=True)
                e["events"].append(dict(kind="write", address=address, value=data, initialized=True))
            else:
                e["registers"][0] = value if width == 4 else (left & ~(mask << lane)) | (value << lane)
        cases.append((r, e))

    for width, prefix in ((1, ""), (2, "66"), (4, ""), (8, "48")):
        byte = int(width != 1)
        mask = (1 << (8 * width)) - 1
        for kind, group in (("or", 1), ("and", 4), ("xor", 6), ("test", None)):
            for a, b in ((0, 0), (mask, 0), (mask, mask), (mask >> 1, mask), (15, 0x81), (0xA5, 0x5A)):
                left, right = (0xABCDEF0123456789 & ~mask) | a, (0x1234567890ABCDEF & ~mask) | b
                direct = f"{0x84 + byte:02x}" if kind == "test" else f"{group * 8 + byte:02x}"
                add(prefix + direct + "d8", width, kind, left, right)
                add(prefix + direct + "1f", width, kind, a, right, memory="destination")
                if kind != "test":
                    reverse = f"{group * 8 + 2 + byte:02x}"
                    add(prefix + reverse + "c3", width, kind, left, right)
                    add(prefix + reverse + "07", width, kind, left, b, memory="source")
                for immediate in (0, -1, -128, 0x7F):
                    raw = (immediate & ((1 << (8 * min(width, 4))) - 1)).to_bytes(min(width, 4), "little").hex()
                    acc = f"{0xA8 + byte:02x}" if kind == "test" else f"{group * 8 + 4 + byte:02x}"
                    group_code = f"{0xF6 + byte:02x}c0" if kind == "test" else \
                        ("80" if width == 1 else "81") + f"{0xC0 + group * 8:02x}"
                    add(prefix + acc + raw, width, kind, left, immediate & MASK)
                    add(prefix + group_code + raw, width, kind, left, immediate & MASK)
                    if kind != "test" and width != 1:
                        add(prefix + "83" + f"{0xC0 + group * 8:02x}{immediate & 255:02x}", width, kind, left, immediate & MASK)
            add(prefix + direct + "1f", width, kind, 15, 0x81, memory="destination", fault="read")
            if kind != "test":
                add(prefix + direct + "1f", width, kind, 15, 0x81, memory="destination", fault="write")
            if width == 1:
                add(direct + "fc", 1, kind, 0xAB12CD, 0x9880FE, lane=8, source_lane=8)
    add("48832500000000ff", 8, "and", 0xFF00, MASK, memory="destination", address=0x1008)
    add("48f70500000000ffffffff", 8, "test", 0xFF00, MASK, memory="destination", address=0x100B)
    run = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
        input="".join(json.dumps(r) + "\n" for r, _ in cases), text=True, stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(cases)
    for (r, e), actual in zip(cases, outputs): assert actual == e, (r, actual, e)
    print(f"x86 logical reference: {len(cases)} native forms/lanes/defined flags/memory/fault cases OK")


if __name__ == "__main__":
    main()
