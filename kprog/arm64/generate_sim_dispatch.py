#!/usr/bin/env python3
"""Specialize literal opcodes using the canonical C dispatcher's own arms."""
import argparse
from pathlib import Path
import re
import subprocess

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
PARAMS = 'OP, DST, SRC, SRC2, SRC3, FLAGS, AUX, IMM'


def render(header, opcodes, build):
    text = header.read_text()
    start = text.index('#define ARM64_SIM_L_EXEC(OP,')
    end = text.index('#define ARM64_SIM_RUN_OP3(', start)
    dispatcher = text[start:end].replace('\\\n', '\n')
    arms = []
    position = dispatcher.index('if (')
    while True:
        match = re.match(r'if\s*\((.*?)\)\s*\{', dispatcher[position:], re.S)
        if match is None:
            raise ValueError('cannot parse canonical dispatcher condition')
        begin = position + match.end()
        cursor, depth = begin, 1
        while depth:
            if dispatcher[cursor] == '{': depth += 1
            elif dispatcher[cursor] == '}': depth -= 1
            cursor += 1
        arms.append((match[1].strip(), dispatcher[begin:cursor-1].strip()))
        following = re.match(r'\s*else\s+if', dispatcher[cursor:])
        if following is None:
            break
        position = cursor + following.end() - 2
    default = re.match(r'\s*else\s*\{(.*?)\}\s*\}\s*while\s*\(0\)',
                       dispatcher[cursor:], re.S)
    if default is None:
        raise ValueError('cannot parse canonical unsupported-op arm')
    ops = re.findall(r'^#define (ARM64_OP_\w+)\s+0x[0-9a-fA-F]+U', opcodes.read_text(), re.M)
    if not ops:
        raise ValueError('no canonical opcode definitions')
    build.mkdir(parents=True, exist_ok=True)
    probe = build/'dispatch-probe.c'
    prelude = '''typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;
#define __always_inline inline
#define ARM64_SIM_DIRECT_H
'''
    statements = []
    for op in ops:
        predicates = [re.sub(r'\bOP\b', op, condition) for condition, _ in arms]
        chain = ' else '.join(f'if ({condition}) slot={index};'
                              for index, condition in enumerate(predicates))
        statements.append(f'{{ unsigned slot={len(arms)}; {chain} printf("{op} %u\\n", slot); }}')
    probe.write_text(prelude+f'#include "{header}"\n#include <stdio.h>\nint main(void) {{\n'
                     +'\n'.join(statements)+'\nreturn 0;\n}\n')
    binary = build/'dispatch-probe'
    subprocess.run(['cc', '-O2', '-I'+str(ROOT/'vendor/libbpf/src'), str(probe), '-o', str(binary)], check=True)
    mapping = [line.split() for line in subprocess.check_output([str(binary)], text=True).splitlines()]
    if [name for name, _ in mapping] != ops:
        raise ValueError('canonical classifier did not report every opcode exactly once')
    arms.append(('canonical default', default[1].strip()))
    output = ['/* Generated from the canonical C dispatcher by generate_sim_dispatch.py. */',
              '#ifndef ARM64_SIM_DIRECT_H', '#define ARM64_SIM_DIRECT_H']
    for index, (_, body) in enumerate(arms):
        lines = ['do {', '__u8 __a64_l_width = ARM64_SIM_L_EFFECTIVE_WIDTH(FLAGS);',
                 '(void)__a64_l_width;', *body.splitlines(), '} while (0)']
        output.append(f'#define ARM64_SIM_DIRECT_BODY_{index}({PARAMS}) \\')
        output.extend(line.rstrip()+' \\' for line in lines[:-1])
        output.append(lines[-1])
    for op, index in mapping:
        output += [f'#define ARM64_SIM_DIRECT_{op}(DST, SRC, SRC2, SRC3, FLAGS, AUX, IMM) \\',
                   f'ARM64_SIM_DIRECT_BODY_{index}({op}, DST, SRC, SRC2, SRC3, FLAGS, AUX, IMM)']
    output += [f'#define ARM64_SIM_RUN_KNOWN_OP3({PARAMS}) \\',
               'ARM64_SIM_DIRECT_##OP(DST, SRC, SRC2, SRC3, FLAGS, AUX, IMM)', '#endif']
    return '\n'.join(output)+'\n'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--check', action='store_true')
    args = parser.parse_args()
    output = HERE/'arm64_sim_direct.h'
    expected = render(HERE/'arm64_sim_local_bpf.h', HERE/'arm64_sim.h', HERE/'build/direct-dispatch')
    if args.check:
        if not output.exists() or output.read_text() != expected:
            raise SystemExit('arm64_sim_direct.h differs from canonical C dispatcher; regenerate it')
    elif not output.exists() or output.read_text() != expected:
        output.write_text(expected)


if __name__ == '__main__':
    main()
