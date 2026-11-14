#!/usr/bin/env python3
"""Catch wrong BPF immediate extension, invented bodies and default IR changes."""
import argparse
import json
from pathlib import Path
import struct
import subprocess


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ['build', 'compiler', 'reference', 'public-layout', 'physical-layout']:
        parser.add_argument('--' + name, type=Path, required=True)
    args = parser.parse_args()
    report = dict(cases=[], failures=[], scope='Host compiler/body ABI tests only; constructed test facts are never application runtime facts.')

    def run(command, label, success=True):
        result = subprocess.run(list(map(str, command)), capture_output=True)
        (args.build / (label + '.stdout')).write_bytes(result.stdout)
        (args.build / (label + '.stderr')).write_bytes(result.stderr)
        if success:
            result.check_returncode()
        elif result.returncode != 1:
            raise AssertionError('unsupported body did not fail explicitly: ' + label)
        return dict(argv=list(map(str, command)), returncode=result.returncode)

    base = [args.build / 'input.bc', '--public-layout', args.public_layout,
            '--physical-layout', args.physical_layout]
    native = ['--native-codegen', '--helper-names', args.build / 'helpers.json']
    for mode, flags in [('default', []), ('native', native)]:
        for which, tool in [('before', args.reference), ('after', args.compiler)]:
            run([tool, *base, *flags, '-o', args.build / (mode + '-' + which + '.bc')], mode + '-' + which)
        if (args.build / (mode + '-before.bc')).read_bytes() != (args.build / (mode + '-after.bc')).read_bytes():
            raise AssertionError('IR changed without explicit function facts: ' + mode)

    def body(imm, opcode=0xb7):
        return (struct.pack('<BBhi', opcode, 0, 0, imm) + bytes.fromhex('9500000000000000')).hex()

    def facts(imm):
        return dict(functions={name: body(imm, opcode) for name, opcode in [
            ('supplied64', 0xb7), ('supplied32', 0xb4), ('supplied_i32', 0xb7),
            ('supplied16', 0xb7), ('supplied_ptr', 0xb7), ('supplied_void', 0xb4)]})

    for i, value in enumerate([0, 1, -1, -(1 << 31), (1 << 31) - 1, 0x12345678]):
        prefix = args.build / ('case-%d' % i)
        prefix.with_suffix('.json').write_text(json.dumps(facts(value), indent=2) + '\n')
        commands = [run([args.compiler, *base, *native, '--bpf-function-bodies', prefix.with_suffix('.json'),
                         '-o', prefix.with_suffix('.bc')], 'case-%d-lower' % i),
                    run(['clang-18', '-O3', prefix.with_suffix('.bc'), '-o', prefix], 'case-%d-link' % i),
                    run([prefix, hex(value & ((1 << 64) - 1)), hex(value & ((1 << 32) - 1))], 'case-%d-run' % i)]
        report['cases'].append(dict(immediate=value, vectors=48, commands=commands))

    negative = {'nonconstant': dict(functions={'supplied64': body(0) + body(1)}),
                'wrong-register': dict(functions={'supplied64': 'b7010000000000009500000000000000'}),
                'defined-function': dict(functions={'main': body(0)}),
                'bad-hex': dict(functions={'supplied64': 'xx' * 16}),
                'disabled': facts(0)}
    for label, data in negative.items():
        path = args.build / (label + '.json');path.write_text(json.dumps(data) + '\n')
        output = args.build / (label + '.bc')
        command = run([args.compiler, *base, *([] if label == 'disabled' else native),
                       '--bpf-function-bodies', path, '-o', output], label, success=False)
        if output.exists():
            raise AssertionError('unsupported facts produced a partial output: ' + label)
        report['failures'].append(dict(case=label, command=command))
    report['absent_facts_default_and_native_byte_identical'] = True
    (args.build / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
    print('Six body values x48 real host ABI vectors, five explicit failures, both absent-facts paths PASS')


if __name__ == '__main__':
    main()
