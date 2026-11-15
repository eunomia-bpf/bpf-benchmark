"""Measure existing all-pairs spill lowering on the archived OTel hotspot MIR."""
import argparse
from contextlib import ExitStack
from datetime import datetime, timezone
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import resource
import struct
import subprocess
import tarfile
import time
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def digest_file(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def main(args):
    args.build.mkdir(parents=True, exist_ok=True)
    args.output.mkdir(parents=True, exist_ok=True)
    began = time.monotonic()
    result = dict(started=datetime.now(timezone.utc).isoformat(), archive=str(args.archive),
                  member=args.member, scope='Archived hotspot MIR diagnostic, no P or production compiler change')
    try:
        wanted = {'request/generated/trusted_x86.bpf.before.mir': args.build/'trusted_x86.bpf.before.mir',
                  'request/kernel.native.o': args.build/'kernel.native.o'}
        facts = {'request/kernel.entry', 'request/kernel.facts.json', 'request/generation.metadata.json',
                 'request/source-identities.json', 'request/verify.stderr', 'request/generated/commands.jsonl'}
        hashes = {}
        # Stream the existing nested request; no duplicate 125 MB archive or
        # expanded source tree is created alongside the canonical build.
        with ExitStack() as stack:
            outer = stack.enter_context(tarfile.open(args.archive))
            nested = stack.enter_context(tarfile.open(fileobj=outer.extractfile(args.member), mode='r|gz'))
            for member in nested:
                if member.name in wanted:
                    stream = nested.extractfile(member)
                    target = wanted[member.name]
                    with target.open('wb') as output:
                        while data := stream.read(1 << 20):
                            output.write(data)
                    hashes[member.name] = digest_file(target)
                elif member.name in facts:
                    data = nested.extractfile(member).read()
                    (args.output/member.name.replace('/', '__')).write_bytes(data)
                    hashes[member.name] = hashlib.sha256(data).hexdigest()
                elif member.name in {'request/generated/trusted_x86.bpf.packed.mir', 'request/generated/trusted_x86.bpf.o'}:
                    hashes[member.name] = hashlib.file_digest(nested.extractfile(member), 'sha256').hexdigest()
        if not all(name in hashes for name in wanted) or not all(name in hashes for name in facts):
            raise ValueError('Retained request lacks actual MIR/native/context evidence')
        result['archived_hashes'] = hashes
        (args.output/'inputs.json').write_text(json.dumps(result, indent=2)+'\n')
        spec = importlib.util.spec_from_file_location('hotspot_spills', ROOT/'kprog/x86/whole_word_spills.py')
        spills = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(spills)
        before = args.build/'trusted_x86.bpf.before.mir'
        text = before.read_text()
        definitions = re.findall(r'  - \{ id: (\d+),[^\n]*type: spill-slot,[^\n]*size: (\d+), alignment: (\d+),', text)
        result['original_spill_slots'] = [dict(id=int(i), size=int(s), alignment=int(a)) for i, s, a in definitions]
        del text
        grouped, pairs = spills.automatic(before, all_scalar_pairs=True)
        packed = args.build/'trusted_x86.bpf.packed.mir'
        packed.write_text(grouped)
        del grouped
        result['grouped_mir_sha256'] = digest_file(packed)
        result['pairs'] = pairs
        (args.output/'lowering.json').write_text(json.dumps(result, indent=2)+'\n')
        obj = args.build/'trusted_x86.bpf.o'
        command = list(map(str, ['llc-18', '-O3', '-march=bpf', '-mcpu=v4', '-bpf-stack-size=4096',
            '-verify-machineinstrs', '-start-before=prologepilog', '-filetype=obj', packed, '-o', obj]))
        (args.output/'current-command.json').write_text(json.dumps(command, indent=2)+'\n')
        start = time.monotonic()
        completed = subprocess.run(command, text=True, capture_output=True)
        (args.output/'command.json').write_text(json.dumps(dict(command=command, returncode=completed.returncode,
            stdout=completed.stdout, stderr=completed.stderr, wall_seconds=time.monotonic()-start), indent=2)+'\n')
        completed.check_returncode()
        sections = []
        with obj.open('rb') as stream:
            elf = ELFFile(stream)
            for section in elf.iter_sections():
                if not section['sh_flags'] & 4:
                    continue
                depth = 0
                for opcode, registers, offset, immediate in struct.iter_unpack('<BBhi', section.data()):
                    kind, dst, src = opcode & 7, registers & 15, registers >> 4
                    if (kind in {2, 3} and dst == 10) or (kind == 1 and src == 10):
                        depth = max(depth, -offset)
                sections.append(dict(name=section.name, bytes=section['sh_size'], frame_access_depth=depth))
        result.update(compiled=True, sections=sections, object_sha256=digest_file(obj))
    except Exception as error:
        result.update(compiled=False, error=str(error))
        raise
    finally:
        result.update(finished=datetime.now(timezone.utc).isoformat(), wall_seconds=time.monotonic()-began,
                      address_space_limit_bytes=resource.getrlimit(resource.RLIMIT_AS)[0])
        (args.output/'result.json').write_text(json.dumps(result, indent=2)+'\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('archive', 'build', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--member', required=True)
    main(parser.parse_args())
