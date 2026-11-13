#!/usr/bin/env python3
"""Build canonical proofs for every cgroup entry of the upstream socket object.

Offline linker execution only: no verifier submission or native installation.
"""
import argparse
import json
from pathlib import Path
import subprocess
from elftools.elf.elffile import ELFFile


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', type=Path, required=True)
    parser.add_argument('--linker', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    with args.input.open('rb') as stream:
        elf = ELFFile(stream)
        entries = [symbol.name for symbol in elf.get_section_by_name('.symtab').iter_symbols()
                   if symbol['st_info']['type'] == 'STT_FUNC' and isinstance(symbol['st_shndx'], int)
                   and elf.get_section(symbol['st_shndx']).name.startswith('cgroup/')]
    if not entries:
        raise ValueError('socket object has no cgroup entries')
    rows = []
    for name in sorted(entries):
        command = [str(args.linker), '--mode', 'proof', '--input', str(args.input),
                   '--symbol', name, '--output', str(args.output/(name+'.proof.o'))]
        result = subprocess.run(command, capture_output=True, text=True)
        (args.output/(name+'.stdout')).write_text(result.stdout)
        (args.output/(name+'.stderr')).write_text(result.stderr)
        rows.append(dict(symbol=name, command=command, returncode=result.returncode))
        (args.output/'report.json').write_text(json.dumps(rows, indent=2)+'\n')
        result.check_returncode()


if __name__ == '__main__':
    main()
