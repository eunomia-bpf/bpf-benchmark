#!/usr/bin/env python3
"""Native arithmetic decoding, six status flags, lanes and ordered memory faults."""
import copy
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1 << 64) - 1


def main():
    cases = []
    base = dict(isa="x86_64", state=dict(registers=list(range(16)), flags=0xF7FF,
        pc=0x1000, xmm0=(1 << 127) + 19, fs_base=0, gs_base=0, memory=[]))

    def add(code, width, group, left, right, carry, *, lane=0, source_lane=0,
            memory=None, fault=None, address=0x2001):
        request = copy.deepcopy(base)
        request["native_bytes"] = list(bytes.fromhex(code))
        s = request["state"]
        s["registers"][0] = left
        s["registers"][3] = right
        s["registers"][7] = address
        s["flags"] = (s["flags"] & ~1) | carry
        mask = (1 << (width * 8)) - 1
        a = (left >> lane) & mask
        b = (right >> source_lane) & mask
        if memory:
            raw = left if memory == "destination" else right
            s["memory"] = [dict(address=address + i, value=(raw >> (8 * i)) & 255,
                readable=True, writable=True, initialized=False) for i in range(width)]
            if fault:
                s["memory"][-1]["readable" if fault == "read" else "writable"] = False
        expected = copy.deepcopy(s)
        expected.update(pc=s["pc"] + len(request["native_bytes"]), defined_flags=MASK, events=[], fault=None)
        subtract = group in (3, 5, 7)
        incoming = carry if group in (2, 3) else 0
        total = a - b - incoming if subtract else a + b + incoming
        result = total & mask
        signed = lambda value: value - (mask + 1) if value >> (width * 8 - 1) else value
        full_signed = signed(a) - signed(b) - incoming if subtract else signed(a) + signed(b) + incoming
        af = (a & 15) < (b & 15) + incoming if subtract else (a & 15) + (b & 15) + incoming >= 16
        flags = int(total < 0 or total > mask) | (int((result & 255).bit_count() % 2 == 0) << 2) | \
            (int(af) << 4) | (int(result == 0) << 6) | ((result >> (width * 8 - 1)) << 7) | \
            (int(full_signed != signed(result)) << 11)
        expected["flags"] = (s["flags"] & ~0x8D5) | flags
        if memory and fault != "read":
            expected["events"].append(dict(kind="read", address=address,
                value=[cell["value"] for cell in s["memory"]], initialized=False))
        if fault:
            expected.update(pc=s["pc"], flags=s["flags"])
            expected["fault"] = dict(kind=fault, address=address, bytes=width)
            expected["events"].append(dict(kind="fault", fault=expected["fault"]))
        elif group != 7:
            if memory == "destination":
                data = list(result.to_bytes(width, "little"))
                for cell, byte in zip(expected["memory"], data):
                    cell.update(value=byte, initialized=True)
                expected["events"].append(dict(kind="write", address=address, value=data, initialized=True))
            else:
                expected["registers"][0] = result if width == 4 else (left & ~(mask << lane)) | (result << lane)
        cases.append((request, expected))

    for width, prefix in ((1, ""), (2, "66"), (4, ""), (8, "48")):
        byte = int(width != 1)
        mask = (1 << (width * 8)) - 1
        # Carry/borrow, nibble carry, zero, signed min/max and parity boundaries.
        pairs = [(0, 0), (mask, 1), (15, 1), (0, mask),
                 (1 << (width * 8 - 1), 1), ((1 << (width * 8 - 1)) - 1, 1)]
        for group in (0, 2, 3, 5, 7):
            for carry in (0, 1):
                for a, b in pairs:
                    left = (0xA5123456789ABCDE & ~mask) | a
                    right = (0x5AFEDCBA98765432 & ~mask) | b
                    # Both native direction encodings write RAX from RBX.
                    for form, modrm in ((byte, "d8"), (2 + byte, "c3")):
                        add(prefix + f"{group * 8 + form:02x}" + modrm,
                            width, group, left, right, carry)
                    add(prefix + f"{group * 8 + byte:02x}" + "1f", width, group,
                        a, right, carry, memory="destination")
                    add(prefix + f"{group * 8 + 2 + byte:02x}" + "07", width, group,
                        left, b, carry, memory="source")
                for immediate in (0, 1, -1, -128):
                    # Accumulator and full group immediate; 64-bit immediates
                    # are sign-extended from32. Group83 sign-extends from8.
                    size = min(width, 4)
                    raw = (immediate & ((1 << (8 * size)) - 1)).to_bytes(size, "little").hex()
                    for code in (prefix + f"{group * 8 + 4 + byte:02x}" + raw,
                                 prefix + ("80" if width == 1 else "81") + f"{0xC0 + group * 8:02x}" + raw):
                        add(code, width, group, mask, immediate & MASK, carry)
                    if width != 1:
                        add(prefix + "83" + f"{0xC0 + group * 8:02x}" + f"{immediate & 255:02x}",
                            width, group, mask, immediate & MASK, carry)
            # Read fault changes nothing; a RMW write fault retains its read
            # event and old flags. CMP never asks for write permission.
            code = prefix + f"{group * 8 + byte:02x}" + "1f"
            add(code, width, group, 15, 1, 1, memory="destination", fault="read")
            if group != 7:
                add(code, width, group, 15, 1, 1, memory="destination", fault="write")
        for group in (0, 2, 3, 5, 7):
            if width == 1:
                add(f"{group * 8:02x}fc", 1, group, 0x12347FFF, 0x56780188, 1, lane=8, source_lane=8)
                add("40" + f"{group * 8:02x}e0", 1, group, 0x12347FFF, 4, 1)
                add(f"{group * 8:02x}e0", 1, group, 0x12807F, 0x80, 1)
                add("80" + f"{0xC4 + group * 8:02x}" + "ff", 1, group, 0x127FFF, MASK, 1, lane=8)
    # RIP-relative group83 counts the trailing immediate in the address.
    add("48830500000000ff", 8, 0, 15, MASK, 0, memory="destination", address=0x1008)
    run = subprocess.run([str(ROOT / ".lake/build/bin/reference")],
        input="".join(json.dumps(request) + "\n" for request, _ in cases),
        text=True, stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(cases), (len(outputs), len(cases))
    for (request, expected), actual in zip(cases, outputs):
        assert actual == expected, (request, actual, expected)
    print(f"x86 arithmetic reference: {len(cases)} six-flag/native decode/lane/immediate/memory cases OK")


if __name__ == "__main__":
    main()
