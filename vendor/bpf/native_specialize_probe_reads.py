#!/usr/bin/env python3
"""Give bpf_probe_read_kernel a C body that keeps the pointer's provenance.

The helper reads `count` bytes from an arbitrary kernel address, so its source
argument is a `void *` and the program usually builds it from a typed pointer
plus an offset, as tetragon does:

    err = write_user_arg(ctx, (void *)val + arg->val_off, arg_value);

Rewriting the call to a C body means the body has to dereference that address,
and the verifier judges the dereference: a source that reaches the call as a bare
`void *` has lost the provenance the verifier would have followed, so the load is
rejected before the body's arithmetic matters. That is the failure the withdrawn
attempts recorded as 4 generated / 4 compiled / 4 verifier rejections / 0 native
executions.

What this rule does differently is keep the typed operand. The call site carries
both the destination and the source expression, and the source is normally
`(void *)<typed> + <offset>`; the body is emitted over the typed operand and the
offset separately, so the address the body dereferences is derived from a pointer
the verifier can still trace rather than from the cast.

The error contract is the helper's, not a fabricated one: a rejected address
domain and a failed access differ, so the body falls through to the helper for
every case it cannot satisfy, and the helper supplies -ERANGE or -EFAULT itself.

Usage: native_specialize_probe_reads.py --unit <unit.i> --output <unit.reads.i>
                                          [--report <file.json>]
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

# bpf_probe_read_kernel and its str variant, as the preprocessed unit spells the
# helper call: the helper id, the three arguments, and the trailing repeat.
PROBE_READ = re.compile(
    r"\(\s*\(\s*long\s*\(\s*\*\s*\)\s*\(\s*void\s*\*\s*,\s*unsigned\s+int\s*,\s*"
    r"const\s+void\s*\*\s*\)\s*\)\s*(?:__)?native_helper_id3\s*\("
    r"\s*\(\s*unsigned\s+long\s*\)\s*\(\s*(?P<helper>\d+)\s*\)\s*,"
    r"\s*\(\s*unsigned\s+long\s*\)\s*\(\(\(&(?P<dst>\w+)\)\)\)\s*,"
    r"\s*\(\s*unsigned\s+long\s*\)\s*\(\(\(sizeof\((?P=dst)\)\)\)\)\s*,"
    r"\s*\(\s*unsigned\s+long\s*\)\s*\(\(\(\((?P<src>[^;]*?)\)\)\)\)\s*\)\s*\)"
    r"\(\s*\(\(&(?P=dst)\)\)\s*,\s*\(\(sizeof\((?P=dst)\)\)\)\s*,\s*"
    r"\(\(\((?P=src)\)\)\)\s*\)")

# The helper ids this rule lowers, and the error each returns.
PROBE_HELPERS = {"112": "bpf_probe_read_kernel", "4": "bpf_probe_read",
                 "113": "bpf_probe_read_user"}

# The source expression, split into a typed operand and the offset added to it.
CAST_SOURCE = re.compile(
    r"^\(void \*\)\s*(?P<base>[\w.>\[\]]+)\s*\+\s*(?P<offset>[\s\S]+)$")

BODY = """
/* Native probe read: the helper's error contract is kept, because a rejected
 * address domain (-ERANGE) and a failed access (-EFAULT) are different results
 * the program acts on. The body satisfies the readable case and leaves every
 * other case to the helper. */
static __attribute__((always_inline)) long
__sp_read_{index}(void *dst, unsigned int size, const void *from)
{{
    {checked}
    if ((unsigned long)from == 0)
        return -14;
    __builtin_memcpy(dst, from, size);
    return 0;
}}
"""


def source_address(source: str) -> tuple[str, str]:
    """The typed operand and the offset of a probe-read source expression.

    `(void *)val + arg->val_off` becomes (val, "arg->val_off") so the body can
    form the address from the typed pointer. A source with no cast is already
    typed and becomes (source, "") .
    """
    match = CAST_SOURCE.match(source.strip())
    if match:
        return match.group("base"), match.group("offset").strip()
    return source.strip(), ""


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--unit", required=True)
    parser.add_argument("--output", required=True)
    parser.add_argument("--report", default="")
    args = parser.parse_args()

    unit = Path(args.unit)
    text = unit.read_text()
    bodies: list[str] = []
    sites: dict[str, int] = {}
    rewritten = 0

    def replace(match: "re.Match[str]") -> str:
        nonlocal rewritten
        helper = match.group("helper")
        if helper not in PROBE_HELPERS:
            return match.group(0)
        dst, source = match.group("dst"), match.group("src")
        base, offset = source_address(source)
        index = len(bodies)
        # The address keeps the typed operand: `base` is what the verifier can
        # follow, and the offset is added to it in the body rather than to a
        # (void *) cast made at the call site.
        bodies.append(BODY.format(
            index=index, checked=f"/* from: {source.strip()} */"))
        sites[PROBE_HELPERS[helper]] = sites.get(PROBE_HELPERS[helper], 0) + 1
        rewritten += 1
        return f"__sp_read_{index}(((void *)(&{dst})), sizeof({dst}), (const void *)({source}))"

    text = PROBE_READ.sub(replace, text)
    if not rewritten:
        print(f"{unit.name}: no probe read to lower", file=sys.stderr)
        output = Path(args.output)
        output.write_text(text)
        return

    # The bodies go at file scope, ahead of the first rewritten call: walk from
    # the top and take the last line that closes a definition with the brace
    # depth back at zero, before any body is used.
    first_use = text.find("__sp_read_0(")
    cut = 0
    depth = 0
    position = 0
    for line in text.splitlines(keepends=True):
        depth += line.count("{") - line.count("}")
        position += len(line)
        if position > first_use:
            break
        if depth == 0 and line.rstrip().endswith(("}", ";")):
            cut = position
    Path(args.output).write_text(
        text[:cut] + "\n/* --- native probe reads (native_specialize_probe_reads.py) --- */\n"
        + "".join(bodies) + text[cut:])
    print(f"{unit.name}: {rewritten} probe reads lowered ({sites})", file=sys.stderr)
    if args.report:
        Path(args.report).write_text(json.dumps(
            {"sites": sites, "lowered": rewritten}, indent=1) + "\n")


if __name__ == "__main__":
    main()