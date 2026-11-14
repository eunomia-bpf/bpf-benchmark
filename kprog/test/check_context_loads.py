"""Catch changed load widths/addresses and changed default IR compiler output."""
import argparse
import json
from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile


def check(tool, legacy, output):
    output.mkdir(parents=True, exist_ok=True)
    commands = []

    def run(command):
        command = list(map(str, command))
        result = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout=result.stdout, stderr=result.stderr))
        (output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        result.check_returncode()
        return result

    source = 'target triple = "bpf"\n@LICENSE = constant [4 x i8] c"GPL\\00", section "license"\n'
    for width in (8, 16, 32, 64):
        extension = '' if width == 64 else f'%wide = zext i{width} %value to i64\n'
        returned = '%value' if width == 64 else '%wide'
        source += f'''define i64 @ctx{width}(ptr %ctx) section "kprobe/ctx{width}" {{
%address = getelementptr i8, ptr %ctx, i64 80
%opaque = call ptr asm sideeffect "", "=r,0"(ptr %address)
%value = load volatile i{width}, ptr %opaque, align {width//8}
{extension}ret i64 {returned}
}}
'''
    before = output/'before.ll'
    before.write_text(source)
    run([legacy, before, '-o', output/'legacy.bc'])
    run([tool, before, '-o', output/'off.bc'])
    if (output/'legacy.bc').read_bytes() != (output/'off.bc').read_bytes():
        raise ValueError('Disabled context transform changes prior compiler bitcode')
    result = run([tool, before, '-o', output/'on.bc', '--canonical-ctx-loads'])
    if 'constant context loads canonicalized=4' not in result.stderr:
        raise ValueError('Constant context loads were disconnected')
    for variant in ('off', 'on'):
        run(['clang-18', '-target', 'bpf', '-mcpu=v4', '-O3', '-c',
             output/(variant+'.bc'), '-o', output/(variant+'.o')])
    with (output/'on.o').open('rb') as source:
        elf = ELFFile(source)
        for width, opcode in ((8, 0x71), (16, 0x69), (32, 0x61), (64, 0x79)):
            section = elf.get_section_by_name(f'kprobe/ctx{width}').data()
            loads = [struct.unpack('<BBhi', section[n:n+8]) for n in range(0, len(section), 8)
                     if section[n] & 7 == 1]
            if len(loads) != 1 or loads[0][0] != opcode or loads[0][1] >> 4 != 1 or loads[0][2] != 80:
                raise ValueError(f'Context memory instruction changed width/base/offset: {width}: {loads}')
    negative = output/'other.ll'
    negative.write_text('''target triple = "bpf"
define i32 @other(ptr %ctx) section "socket" {
%p = getelementptr i8, ptr %ctx, i64 8
%v = load volatile i32, ptr %p, align 4
ret i32 %v
}
define i32 @dynamic(ptr %ctx, i64 %offset) section "kprobe/dynamic" {
%p = getelementptr i8, ptr %ctx, i64 %offset
%v = load volatile i32, ptr %p, align 4
ret i32 %v
}
''')
    result = run([tool, negative, '-o', output/'other.bc', '--canonical-ctx-loads'])
    if 'constant context loads canonicalized=0' not in result.stderr:
        raise ValueError('Unrelated section or dynamic address was changed')
    record = dict(default_bitcode_equal=True, tracing_load_widths=[8, 16, 32, 64],
                  base_register=1, instruction_offset=80, other_section_and_dynamic_preserved=True)
    (output/'result.json').write_text(json.dumps(record, indent=2)+'\n')
    print(json.dumps(record))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('tool', 'legacy', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    args = parser.parse_args()
    check(args.tool, args.legacy, args.output)
