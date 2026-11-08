#!/usr/bin/env python3
"""Where a native program's instructions sit, by kind of call site.

The run-time counters are per program, so a per-site time split needs
either sampling or a measurement of the code itself.  This measures the
code: each call site in the native object is classified, and the
instructions between one site and the next are attributed to it, which
gives the share of the program's instruction stream that each kind of site
guards.

The object and the plan are the published ones; nothing is rebuilt.
"""

import argparse
import collections
import json
import re
import subprocess
import sys

SYNTHETIC = "__native_x86"


def disassemble(obj, symbol):
    """`[(offset, text)]` for one symbol of a native object."""
    done = subprocess.run(
        ["objdump", "-d", "--no-show-raw-insn", str(obj)],
        capture_output=True, text=True)
    lines, inside = [], False
    for line in done.stdout.splitlines():
        if re.match(r"^[0-9a-f]+ <%s>:" % re.escape(symbol), line):
            inside = True
            continue
        if inside and re.match(r"^[0-9a-f]+ <", line):
            break
        match = re.match(r"^\s+([0-9a-f]+):\t(.*)$", line)
        if inside and match:
            lines.append((int(match.group(1), 16), match.group(2).strip()))
    return lines


def classify(plan):
    """`{address: kind}` for every call site the plan names."""
    kinds = {}
    for helper in plan.get("helpers") or []:
        if not helper["name"].startswith(SYNTHETIC):
            kinds[helper["addr"]] = "helper"
    for site in plan.get("lookup_sites") or []:
        kinds[site["target_addr"]] = "lookup"
    for site in plan.get("update_sites") or []:
        kinds[site["target_addr"]] = "update"
    return kinds


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--object", required=True)
    ap.add_argument("--plan", required=True)
    ap.add_argument("--symbol", required=True)
    args = ap.parse_args(argv[1:])

    plan = json.loads(open(args.plan).read())
    sites = classify(plan)
    body = disassemble(args.object, args.symbol)
    if not body:
        print("no disassembly for " + args.symbol, file=sys.stderr)
        return 1

    # A call site is the call instruction that reaches one of the plan's
    # targets; the instructions after it belong to that site until the
    # next call.  Everything before the first call is prologue.
    shares = collections.Counter()
    current, calls = "prologue", 0
    for _, text in body:
        if re.match(r"^call\b", text):
            calls += 1
            current = "call-%d" % calls
        shares[current] += 1
    tail = len(plan.get("tail_call_maps") or [])
    counts = collections.Counter(
        text.split()[0] for _, text in body if text)
    print(json.dumps(dict(
        symbol=args.symbol,
        instructions=len(body),
        call_instructions=calls,
        plan_sites=len(sites),
        plan_site_kinds=dict(collections.Counter(sites.values())),
        tail_call_maps=tail,
        instruction_kinds=dict(counts.most_common(8)),
    ), indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))