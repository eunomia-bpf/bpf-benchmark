#!/usr/bin/env python3
"""Catch missing POPCNT prefix/width handling, ZF, lane, alias and read effects."""
import copy
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1 << 64) - 1


def main():
    cases = []

    def add(code, width, source, old_flags, *, src=1, dst=0, memory=False, fault=False):
        request = dict(native_bytes=list(bytes.fromhex(code)), state=dict(
            registers=[0xABCDEF0000000000 + i for i in range(16)], flags=old_flags,
            pc=0x1000, xmm0=(1 << 127) + 7, fs_base=0, gs_base=0, memory=[]))
        state = request["state"]
        if memory:
            state["registers"][src] = 0x2001
            state["memory"] = [dict(address=0x2001 + i, value=(source >> (8 * i)) & 255,
                readable=True, writable=False, initialized=False) for i in range(width)]
            if fault: state["memory"][-1]["readable"] = False
        else:
            state["registers"][src] = source
        expected = copy.deepcopy(state)
        expected.update(pc=state["pc"] + len(request["native_bytes"]), events=[], fault=None, defined_flags=MASK)
        narrowed = source & ((1 << (width * 8)) - 1)
        value = narrowed.bit_count()
        if fault:
            expected.update(pc=state["pc"], fault=dict(kind="read", address=0x2001, bytes=width))
            expected["events"] = [dict(kind="fault", fault=expected["fault"])]
        else:
            expected["flags"] = (old_flags & ~0x8D5) | (64 if narrowed == 0 else 0)
            expected["registers"][dst] = ((state["registers"][dst] & ~0xFFFF) | value) if width == 2 else value
            if memory:
                expected["events"] = [dict(kind="read", address=0x2001,
                    value=[c["value"] for c in state["memory"]], initialized=False)]
        cases.append((request, expected))

    values = [0, MASK, 0xAAAAAAAAAAAAAAAA, 0x5555555555555555] + [1 << bit for bit in range(64)]
    for width, prefix, extended in ((2, "66f3", "66f345"), (4, "f3", "f345"), (8, "f348", "f34d")):
        for source in values:
            for flags in (0, 0x202, 0xAD7):
                add(prefix + "0fb8c1", width, source, flags)
                add(prefix + "0fb8c0", width, source, flags, src=0)
                add(extended + "0fb8c1", width, source, flags, src=9, dst=8)
                add(prefix + "0fb801", width, source, flags, memory=True)
                add(prefix + "0fb809", width, source, flags, memory=True, dst=1)
        add(prefix + "0fb801", width, MASK, 0xAD7, memory=True, fault=True)
    run = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
        input="".join(json.dumps(r) + "\n" for r, _ in cases), text=True, stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(cases)
    for (request, expected), actual in zip(cases, outputs):
        assert actual == expected, (request, actual, expected)
    bad = ["0fb8c1", "f20fb8c1", "f30fb8", "f3480fb8", "f3480fb804"]
    for code in bad:
        run = subprocess.run([str(ROOT / ".lake/build/bin/reference")], input=json.dumps(dict(
            native_bytes=list(bytes.fromhex(code)), state=cases[0][0]["state"])) + "\n",
            text=True, capture_output=True)
        assert run.returncode == 1 and run.stderr.startswith("reference: "), (code, run)
    print(f"x86 POPCNT reference: {len(cases)} width/flags/alias/memory/fault cases, {len(bad)} malformed encodings rejected")


if __name__ == "__main__":
    main()
