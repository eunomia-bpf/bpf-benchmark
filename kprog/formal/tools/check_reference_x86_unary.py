#!/usr/bin/env python3
"""INC/DEC CF preservation, NEG flags, NOT preservation, lanes and RMW faults."""
import copy
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1 << 64) - 1


def main():
    cases = []

    def add(code, width, kind, left, old_flags, *, lane=0, memory=False, fault=None, dst=0):
        r = dict(isa="x86_64", native_bytes=list(bytes.fromhex(code)), state=dict(
            registers=list(range(16)), flags=old_flags, pc=0x1000, xmm0=(1 << 127) + 7,
            fs_base=0, gs_base=0, memory=[]))
        s = r["state"]
        s["registers"][dst], s["registers"][7] = left, 0x2001
        mask = (1 << (8 * width)) - 1
        a = (left >> lane) & mask
        value = ((a + 1) if kind == "inc" else (a - 1) if kind == "dec" else -a if kind == "neg" else ~a) & mask
        if memory:
            s["memory"] = [dict(address=0x2001 + i, value=(left >> (8 * i)) & 255,
                readable=True, writable=True, initialized=False) for i in range(width)]
            if fault: s["memory"][-1]["readable" if fault == "read" else "writable"] = False
        e = copy.deepcopy(s)
        e.update(pc=s["pc"] + len(r["native_bytes"]), events=[], fault=None, defined_flags=MASK)
        if kind != "not":
            sign = 1 << (8 * width - 1)
            cf = (old_flags & 1) if kind in ("inc", "dec") else int(a != 0)
            af = (a & 15) == 15 if kind == "inc" else (a & 15) == 0 if kind == "dec" else (a & 15) != 0
            of = a == (sign - 1) if kind == "inc" else a == sign
            flags = cf | (int((value & 255).bit_count() % 2 == 0) << 2) | (int(af) << 4) | \
                (int(value == 0) << 6) | ((value >> (width * 8 - 1)) << 7) | (int(of) << 11)
            e["flags"] = (old_flags & ~0x8D5) | flags
        if memory and fault != "read":
            e["events"] = [dict(kind="read", address=0x2001,
                value=[c["value"] for c in s["memory"]], initialized=False)]
        if fault:
            e.update(pc=s["pc"], flags=old_flags)
            e["fault"] = dict(kind=fault, address=0x2001, bytes=width)
            e["events"].append(dict(kind="fault", fault=e["fault"]))
        elif memory:
            data = list(value.to_bytes(width, "little"))
            for c, byte in zip(e["memory"], data): c.update(value=byte, initialized=True)
            e["events"].append(dict(kind="write", address=0x2001, value=data, initialized=True))
        else:
            e["registers"][dst] = value if width == 4 else (left & ~(mask << lane)) | (value << lane)
        cases.append((r, e))

    for width, prefix in ((1, ""), (2, "66"), (4, ""), (8, "48")):
        mask = (1 << (8 * width)) - 1
        for kind, opcode, group in (("inc", 0xFE, 0), ("dec", 0xFE, 1), ("neg", 0xF6, 3), ("not", 0xF6, 2)):
            opcode += int(width != 1)
            for flags in (0x202, 0xAD7):
                for a in (0, 1, 15, 16, 127, 128, mask >> 1, (mask >> 1) + 1, mask):
                    left = (0xABCDEF0123456789 & ~mask) | a
                    add(prefix + f"{opcode:02x}{0xC0 + group * 8:02x}", width, kind, left, flags)
                    add(prefix + f"{opcode:02x}{0x07 + group * 8:02x}", width, kind, a, flags, memory=True)
                for fault in ("read", "write"):
                    add(prefix + f"{opcode:02x}{0x07 + group * 8:02x}", width, kind, 15, flags, memory=True, fault=fault)
                if width == 1:
                    add(f"{opcode:02x}{0xC4 + group * 8:02x}", width, kind, 0xABCDEF127F89, flags, lane=8)
                    add(f"40{opcode:02x}{0xC4 + group * 8:02x}", width, kind, 0xABCDEF12807F, flags, dst=4)
                    add(f"41{opcode:02x}{0xC0 + group * 8:02x}", width, kind, 0xABCDEF12807F, flags, dst=8)
    run = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
        input="".join(json.dumps(r) + "\n" for r, _ in cases), text=True, stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(cases)
    for (r, e), actual in zip(cases, outputs): assert actual == e, (r, actual, e)
    print(f"x86 unary reference: {len(cases)} native width/lane/flags/RMW/fault cases OK")


if __name__ == "__main__":
    main()
