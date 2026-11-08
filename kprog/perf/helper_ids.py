#!/usr/bin/env python3
"""Count an application's call sites by helper ID, from its native objects.

Each helper call in a native program carries the helper's number in `eax`
immediately before an indirect `call`, so the sites are counted exactly
rather than inferred from a plan's reachability list.  The numbers come from
the kernel's own enumeration in `include/uapi/linux/bpf.h`.

Usage: helper_ids.py --objects DIR [--out FILE]
"""

import argparse
import collections
import json
import pathlib
import re
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parents[2]
UAPI = ROOT / "vendor/linux-framework/include/uapi/linux/bpf.h"


def helper_names():
    """`{id: name}` from the kernel's own FN() enumeration."""
    out = {}
    for match in re.finditer(r"FN\((\w+),\s*(\d+),", UAPI.read_text()):
        out[int(match.group(2))] = "bpf_" + match.group(1)
    return out


def is_bpf(obj):
    """Whether the object is a BPF ELF rather than a host one."""
    done = subprocess.run(["readelf", "-hW", str(obj)],
                          capture_output=True, text=True)
    return "BPF" in done.stdout


def disassemble(obj):
    """`{symbol: [instruction text]}` for every function in an object.

    A BPF object carries the helper id as the call's own immediate, so the
    sites are read from that; a host object carries it in `eax` before an
    indirect call, which `sites` reads instead.
    """
    tool = (["llvm-objdump-18", "-d"] if is_bpf(obj) else ["objdump", "-d"])
    done = subprocess.run(tool + [str(obj)], capture_output=True, text=True)
    bodies, current = collections.defaultdict(list), None
    for line in done.stdout.splitlines():
        header = re.match(r"^[0-9a-f]+ <(\w+)>:", line)
        if header:
            current = header.group(1)
            continue
        if current and re.match(r"^\s*[0-9a-f]+:\s", line):
            bodies[current].append(line)
    return bodies


def sites(lines, names):
    """`Counter` of helper names called in one function's body."""
    counts = collections.Counter()
    # A BPF object names the helper in the call itself.
    direct = [re.search(r"call\s+0x([0-9a-f]+)", line) for line in lines]
    direct = [int(m.group(1), 16) for m in direct if m]
    if direct:
        for helper in direct:
            counts[names.get(helper, "helper_%d" % helper)] += 1
        return counts
    pending = None
    for line in lines:
        load = re.search(r"mov\s+\$0x([0-9a-f]+),%eax", line)
        if load:
            pending = int(load.group(1), 16)
            continue
        if "call" in line:
            if pending is not None:
                counts[names.get(pending, "helper_%d" % pending)] += 1
            pending = None
    return counts


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--objects", required=True)
    ap.add_argument("--out", default="")
    args = ap.parse_args(argv[1:])

    names = helper_names()
    per_object = {}
    totals = collections.Counter()
    instructions = 0
    for obj in sorted(list(pathlib.Path(args.objects).rglob("*.native.o")) +
                      list(pathlib.Path(args.objects).rglob("*.bpf.o"))):
        bodies = disassemble(obj)
        if not bodies:
            continue
        local = collections.Counter()
        for lines in bodies.values():
            instructions += len(lines)
            local.update(sites(lines, names))
        if local:
            per_object[obj.parent.name[:12]] = dict(local)
            totals.update(local)

    if not totals:
        print("no helper call found under " + args.objects, file=sys.stderr)
        return 1
    payload = dict(objects=len(per_object), instructions=instructions,
                   call_sites=sum(totals.values()),
                   by_helper=dict(totals.most_common()),
                   per_object=per_object)
    text = json.dumps(payload, indent=1)
    if args.out:
        pathlib.Path(args.out).write_text(text + "\n")
    print(text)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))