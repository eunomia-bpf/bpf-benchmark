#!/usr/bin/env python3
"""Retain CO-RE compiler inputs/results without copying source or a kernel tree."""
import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import shutil
import tarfile
from elftools.elf.elffile import ELFFile


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('build', 'raw', 'tracee-ir', 'tracee-bpf', 'target', 'output'):
        parser.add_argument('--' + name, type=Path, required=True)
    args = parser.parse_args()
    snapshot = args.raw / 'build-evidence'
    snapshot.mkdir()
    for path in args.build.iterdir():
        if path.is_file():
            shutil.copy2(path, snapshot / path.name)
    inputs = args.raw / 'inputs'
    inputs.mkdir()
    for source, name in [(args.tracee_ir, 'tracee.bc'), (args.tracee_bpf, 'tracee.bpf.o')]:
        shutil.copy2(source, inputs / name)
    with args.target.open('rb') as stream:
        btf = ELFFile(stream).get_section_by_name('.BTF').data()
    (inputs / 'target.btf').write_bytes(btf)
    archive = args.output.with_suffix('.tar.gz')
    with tarfile.open(archive, 'x:gz') as target:
        target.add(args.raw, arcname=args.raw.name)
    count = 0
    with tarfile.open(archive) as target:
        for member in target.getmembers():
            if member.isfile():
                with target.extractfile(member) as stream:
                    if hashlib.sha256(stream.read()).hexdigest() != digest(args.raw.parent / member.name):
                        raise ValueError('archive bytes differ: ' + member.name)
                count += 1
    rows = json.loads((snapshot / 'tracee.resolved.json').read_text())
    fixture = json.loads((snapshot / 'fixture.json').read_text())
    ids = json.loads((snapshot / 'ids.json').read_text())
    result = dict(recorded_at=datetime.now(timezone.utc).isoformat(), raw=str(args.raw),
                  original_inputs=[dict(path=str(path), sha256=digest(path)) for path in (args.tracee_ir, args.tracee_bpf, args.target)],
                  target_btf_sha256=hashlib.sha256(btf).hexdigest(),
                  fixture_relocations=fixture, type_id_relocations=ids,
                  tracee_relocations=rows,
                  observed_errors={name: (snapshot / (name + '.log')).read_text() for name in ('unguarded', 'shifted', 'resized')},
                  limits=['Host compiler/fixture evidence only; no native application installation or workload execution.',
                          'Tracee asm/context/helper and data-layout integration remains with its owner.',
                          'Direct scalar field resizing is explicitly diagnosed and remains open under P1h.'],
                  archive=dict(path=str(archive), bytes=archive.stat().st_size, sha256=digest(archive), files_byte_compared=count))
    with args.output.open('x') as output:
        json.dump(result, output, indent=2)
        output.write('\n')


if __name__ == '__main__':
    main()
