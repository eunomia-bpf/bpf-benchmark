#!/usr/bin/env python3
"""Retain original ELF function/relocation sites alongside native candidates."""
import argparse
import hashlib
import json
from pathlib import Path
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection


def functions(elf):
    return [dict(name=s.name, section=elf.get_section(s['st_shndx']).name,
                 offset=s['st_value'], bytes=s['st_size'])
            for s in elf.get_section_by_name('.symtab').iter_symbols()
            if s['st_info']['type'] == 'STT_FUNC' and isinstance(s['st_shndx'], int)]


def pair(native, original):
    with native.open('rb') as stream:
        native_functions = functions(ELFFile(stream))
    with original.open('rb') as stream:
        elf = ELFFile(stream)
        if elf['e_machine'] != 'EM_BPF':
            raise ValueError('expected original BPF ELF: ' + str(original))
        original_functions = functions(elf)
        relocations = []
        for section in elf.iter_sections():
            if not isinstance(section, RelocationSection):
                continue
            target = elf.get_section(section['sh_info'])
            if not target['sh_flags'] & 4:
                continue
            symbols = elf.get_section(section['sh_link'])
            data = target.data()
            for relocation in section.iter_relocations():
                offset = relocation['r_offset']
                symbol = symbols.get_symbol(relocation['r_info_sym'])
                index = symbol['st_shndx']
                relocations.append(dict(section=target.name, byte_offset=offset,
                    instruction_slot=offset // 8, relocation_type=relocation['r_info_type'],
                    target_symbol=symbol.name,
                    target_section=elf.get_section(index).name if isinstance(index, int) else index,
                    target_value=symbol['st_value'],
                    addend=relocation['r_addend'] if relocation.is_RELA() else None,
                    site_bytes_hex=data[offset:offset + 16].hex()))
    names = {f['name'] for f in original_functions}
    return dict(native_object=dict(path=str(native), sha256=hashlib.sha256(native.read_bytes()).hexdigest()),
        original_bpf_object=dict(path=str(original), sha256=hashlib.sha256(original.read_bytes()).hexdigest()),
        functions=[dict(original=f, native=[n for n in native_functions if n['name'] == f['name']])
                   for f in original_functions],
        native_functions_without_original_symbol=[f for f in native_functions if f['name'] not in names],
        relocations=relocations)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--pair', type=Path, nargs=2, action='append', required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    result = dict(version=1, objects=[pair(native, original) for native, original in args.pair],
                  scope='Original object sites and exact-name function correspondence only. No per-application map aliases, current-load FD inference, binding validation or runtime installation.')
    with args.output.open('x') as output:
        json.dump(result, output, indent=2)
        output.write('\n')


if __name__ == '__main__':
    main()
