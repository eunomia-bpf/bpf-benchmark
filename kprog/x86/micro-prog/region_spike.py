#!/usr/bin/env python3
"""Compiler experiment: outline an expanded simulator's CFG basic blocks.

Input is clang -E -P output of the ordinary generated B. The production
generator and admission path retain their current behavior. One explicit
state object retains entry locals, native bytes and forwarding cells.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re


def top_statements(text):
    """Split C statements at semicolons outside nested expressions/blocks."""
    depth = 0
    quote = None
    escaped = False
    start = 0
    for i, char in enumerate(text):
        if quote:
            if escaped:
                escaped = False
            elif char == "\\":
                escaped = True
            elif char == quote:
                quote = None
        elif char in "\"'":
            quote = char
        elif char in "({[":
            depth += 1
        elif char in ")}]":
            depth -= 1
        elif char == ";" and depth == 0:
            yield text[start:i].strip()
            start = i + 1
    if text[start:].strip():
        raise ValueError("entry declaration suffix requires a complete statement")


def outline(text):
    signature = re.search(r"^int (\w+)\(([^;\n]*)\)\s*\n\{", text, re.M)
    start = signature.end()
    first = re.search(r"^x86_l_[0-9a-f]+:", text[start:], re.M)
    entry_end = start + first.start()
    # Generated B puts its closing brace at column zero before LICENSE.
    end = text.index("\n}", entry_end)
    fields = []
    entry = []
    names = []
    for stmt in top_statements(text[start:entry_end]):
        if not stmt:
            continue
        if re.match(r"(?:struct |union |volatile |const |void |__u\d+ )", stmt):
            decl, equal, value = stmt.partition("=")
            name = re.findall(r"\b__x86_\w+\b", decl)[-1]
            fields.append(decl.strip() + ";")
            names.append(name)
            if equal:
                # An initialized aggregate becomes a typed compound literal.
                value = value.strip()
                if value.startswith("{"):
                    ctype = decl[:decl.index(name)].strip()
                    value = "(" + ctype + ")" + value
                entry.append(name + " = " + value + ";")
        else:
            entry.append(stmt + ";")
    state_name = "__region_state"
    name_pattern = re.compile(r"\b(?:" + "|".join(map(re.escape, names)) + r")\b")

    def materialize(body):
        return name_pattern.sub(lambda m: state_name + "->" + m[0], body)

    native_body = text[entry_end:end]
    fragments = list(re.finditer(r"^(x86_l_[0-9a-f]+|x86_sim_ret_dispatch):", native_body, re.M))
    labels = [m[1] for m in fragments]
    payloads = [native_body[m.end():fragments[i+1].start() if i+1 < len(fragments) else len(native_body)]
                for i, m in enumerate(fragments)]
    # Every referenced label is a block leader. The label after a transfer
    # starts a separate block, including a conditional's fallthrough.
    leaders = {labels[0], *re.findall(r"\bgoto\s+(x86_l_[0-9a-f]+|x86_sim_ret_dispatch)\s*;", native_body)}
    for i, body in enumerate(payloads[:-1]):
        if re.search(r"\b(?:goto|return)\b", body):
            leaders.add(labels[i+1])
    blocks = []
    for label, body in zip(labels, payloads):
        if label in leaders:
            blocks.append([label, body])
        else:
            blocks[-1][1] += body
    ids = {label: i for i, (label, _) in enumerate(blocks)}
    exit_pc = len(blocks)
    functions = []
    edges = 0
    returns = 0
    for i, (label, body) in enumerate(blocks):
        # Move each original C return value into its dedicated state cell.
        # The value can be a GNU statement expression containing semicolons.
        pieces = []
        cursor = 0
        for match in re.finditer(r"\breturn\s+", body):
            expression = next(top_statements(body[match.end():]))
            # top_statements strips only outer whitespace.
            tail = body[match.end():]
            left = len(tail) - len(tail.lstrip())
            stop = match.end() + left + len(expression) + 1
            pieces.extend([body[cursor:match.start()],
                "{ " + state_name + "->__region_result = (" + expression
                + "); return " + str(exit_pc) + "ULL; }"])
            cursor = stop
            returns += 1
        pieces.append(body[cursor:])
        body = "".join(pieces)

        def edge(match):
            nonlocal edges
            edges += 1
            return "return " + str(ids[match[1]]) + "ULL;"
        body = re.sub(r"\bgoto\s+(x86_l_[0-9a-f]+|x86_sim_ret_dispatch)\s*;", edge, body)
        body = materialize(body)
        following = i+1 if i+1 < len(blocks) else exit_pc
        functions.append(
            "static __attribute__((noinline)) unsigned long long\n"
            f"__region_{i}(struct __region_image *{state_name})\n{{\n"
            + body + f"\nreturn {following}ULL;\n}}\n")
    declarations = "struct __region_image {\n" + "\n".join(fields) + "\nunsigned long long __region_result;\n};\n"
    dispatcher = (
        f"int {signature[1]}({signature[2]})\n{{\n"
        "struct __region_image __region_storage;\n"
        f"struct __region_image *{state_name} = &__region_storage;\n"
        + materialize("\n".join(entry)) + "\n"
        "unsigned long long __region_pc = 0;\n"
        "for (;;) {\nswitch (__region_pc) {\n"
        + "".join(f"case {i}: __region_pc = __region_{i}({state_name}); break;\n" for i in range(len(blocks)))
        + f"default: return {state_name}->__region_result;\n"
        "}\n}\n}\n")
    # SEC belongs to the entry, while outlined functions get ordinary .text.
    prefix = text[:signature.start()]
    section = list(re.finditer(r'__attribute__\s*\(\(section\("[^"]+"\), used\)\)', prefix))[-1]
    attribute = section[0]
    prefix = prefix[:section.start()] + prefix[section.end():]
    output = prefix + declarations + "\n".join(functions) + attribute + dispatcher + text[end+2:]
    report = dict(kind="compiler_region_spike",entry=signature[1],state_fields=names,
                  basic_blocks=len(blocks),explicit_edges=edges,value_returns=returns,
                  original_instruction_labels=len(labels),native_executions=0,
                  input_sha256=hashlib.sha256(text.encode()).hexdigest(),
                  output_sha256=hashlib.sha256(output.encode()).hexdigest())
    return output, report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("input", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("--report", type=Path, required=True)
    args = parser.parse_args()
    output, report = outline(args.input.read_text())
    args.output.write_text(output)
    args.report.write_text(json.dumps(report, indent=2) + "\n")


if __name__ == "__main__":
    main()
