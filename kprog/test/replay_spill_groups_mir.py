"""Replay captured pre-frame-layout MIR without another C frontend."""
import argparse
import importlib.util
import io
import json
from pathlib import Path
import struct
import subprocess
import tarfile

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def allocated(source):
    elf = ELFFile(source)
    return {section.name: section.data() for section in elf.iter_sections() if section['sh_flags'] & 2}


def stack_depth(source):
    depth = 0
    for section in ELFFile(source).iter_sections():
        if section['sh_flags'] & 4:
            for opcode, regs, offset, _ in struct.iter_unpack('<BBhi', section.data()):
                kind, dst, src = opcode & 7, regs & 15, regs >> 4
                if (kind in (2,3) and dst == 10) or (kind == 1 and src == 10):
                    depth = max(depth, -offset)
    return depth


def replay(args):
    args.build.mkdir(parents=True, exist_ok=True)
    args.output.mkdir(parents=True, exist_ok=True)
    wanted = {'request/generated/trusted_x86.bpf.before.mir': 'before',
              'request/generated/trusted_x86.bpf.packed.mir': 'accepted',
              'request/generated/trusted_x86.bpf.o': 'object'}
    data = {}
    with tarfile.open(args.archive, 'r|gz') as archive:
        for member in archive:
            if member.name in wanted:
                data[wanted[member.name]] = archive.extractfile(member).read()
    if data.keys() != {'before','accepted','object'}:
        raise ValueError('Archive lacks original MIR, accepted MIR or accepted B')
    spec = importlib.util.spec_from_file_location('main_spill_groups', ROOT/'kprog/x86/whole_word_spills.py')
    spills = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(spills)
    before = args.build/'main.before.mir'
    before.write_bytes(data['before'])
    normalizations = []
    grouped, groups = spills.automatic(before, normalizations)
    same_mir = grouped.encode() == data['accepted']
    output = args.build/'main.groups.mir'
    output.write_text(grouped)
    del grouped
    obj = args.build/'main.bpf.o'
    command = list(map(str, ['llc-18', '-O3', '-march=bpf', '-mcpu=v4', '-bpf-stack-size=4096',
        '-verify-machineinstrs', '-start-before=prologepilog', '-filetype=obj', output, '-o', obj]))
    result = subprocess.run(command, text=True, capture_output=True)
    (args.output/'command.json').write_text(json.dumps(dict(command=command,
        returncode=result.returncode, stdout=result.stdout, stderr=result.stderr), indent=2)+'\n')
    result.check_returncode()
    reference = allocated(io.BytesIO(data['object']))
    with obj.open('rb') as file:
        actual = allocated(file)
        file.seek(0)
        depth = stack_depth(file)
    record = dict(archive=str(args.archive), narrowed_scalar_slots=normalizations,
        grouped_pairs=[dict(low=r['low'], high=r['high']) for r in groups],
        grouped_mir_equals_accepted=same_mir, allocated_bytes_equal_accepted=actual == reference,
        frame_access_depth=depth, retained_frame_access_depth=stack_depth(io.BytesIO(data['object'])), object=str(obj),
        scope='Captured whole-body MIR/codegen replay; stock verification not repeated')
    (args.output/'result.json').write_text(json.dumps(record, indent=2)+'\n')
    print(json.dumps(record))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('archive','build','output'):
        parser.add_argument('--'+name, type=Path, required=True)
    replay(parser.parse_args())
