#!/usr/bin/env python3
"""Check native widening moves: source width/lane, writeback, aliases and faults."""
import copy
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1 << 64) - 1


def main():
    cases = []

    def add(code, sw, tw, signed, value, *, src=1, dst=0, lane=0, memory=False, fault=False):
        request = dict(native_bytes=list(bytes.fromhex(code)), state=dict(
            registers=[0xABCDEF0123450000 + i for i in range(16)], flags=0xAD7,
            pc=0x1000, xmm0=(1 << 127) + 7, fs_base=0, gs_base=0, memory=[]))
        state = request["state"]
        if memory:
            state["registers"][src] = 0x2001
            state["memory"] = [dict(address=0x2001 + i, value=(value >> (8*i)) & 255,
                readable=not (fault and i == sw-1), writable=False, initialized=False) for i in range(sw)]
        else:
            state["registers"][src] = value
        expected = copy.deepcopy(state)
        expected.update(pc=state["pc"]+len(request["native_bytes"]), events=[], fault=None, defined_flags=MASK)
        if fault:
            expected.update(pc=state["pc"], fault=dict(kind="read", address=0x2001, bytes=sw))
            expected["events"] = [dict(kind="fault", fault=expected["fault"])]
        else:
            raw = (value >> lane) & ((1 << (8*sw))-1)
            result = raw - (1 << (8*sw)) if signed and raw & (1 << (8*sw-1)) else raw
            result &= (1 << (8*tw))-1
            expected["registers"][dst] = (state["registers"][dst] & ~0xFFFF) | result if tw == 2 else result
            if memory:
                expected["events"] = [dict(kind="read", address=0x2001,
                    value=[c["value"] for c in state["memory"]], initialized=False)]
        cases.append((request, expected))

    values = [0, 1, 0x7F, 0x80, 0xFF, 0x100, 0x7FFF, 0x8000, 0xFFFF,
              0x7FFFFFFF, 0x80000000, 0xFFFFFFFF, 0xAABBCCDD987681FA, MASK]
    for sw, signed, opcode in ((1, False, "b6"), (2, False, "b7"), (1, True, "be"), (2, True, "bf")):
        for tw, prefix in ((2, "66"), (4, ""), (8, "48")):
            if sw > tw: continue
            for value in values:
                for modrm, src, dst, memory in (("c1", 1, 0, False), ("c0", 0, 0, False),
                                               ("01", 1, 0, True), ("09", 1, 1, True)):
                    add(prefix+"0f"+opcode+modrm, sw, tw, signed, value, src=src, dst=dst, memory=memory)
                if sw == 1 and tw != 8:
                    add(prefix+"0f"+opcode+"c4", sw, tw, signed, value, src=0, lane=8)
                rex = "4d" if tw == 8 else "45"
                add(("66" if tw == 2 else "")+rex+"0f"+opcode+"c1", sw, tw, signed, value, src=9, dst=8)
                if sw == 1:
                    add(("66" if tw == 2 else "")+("48" if tw == 8 else "40")+"0f"+opcode+"c4",
                        sw, tw, signed, value, src=4)
            add(prefix+"0f"+opcode+"01", sw, tw, signed, MASK, memory=True, fault=True)
    for tw, prefix, sw in ((2, "66", 2), (4, "", 4), (8, "48", 4)):
        for value in values:
            add(prefix+"63c1", sw, tw, True, value)
            add(prefix+"6301", sw, tw, True, value, memory=True)
        add(prefix+"6301", sw, tw, True, MASK, memory=True, fault=True)
    for tw, prefix, sw in ((2, "66", 1), (4, "", 2), (8, "48", 4)):
        for value in values: add(prefix+"98", sw, tw, True, value, src=0)
    run = subprocess.run([str(ROOT/".lake/build/bin/reference")],
        input="".join(json.dumps(r)+"\n" for r, _ in cases), text=True, stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(cases)
    for (request, expected), actual in zip(cases, outputs): assert actual == expected, (request, actual, expected)
    print(f"x86 widening reference: {len(cases)} source/destination widths, byte lanes, aliases, exact reads/faults and accumulator cases OK")


if __name__ == "__main__":
    main()
