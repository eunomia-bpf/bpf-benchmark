#!/usr/bin/env python3
"""Compare captured BPF bytes/relocations with source replay; evidence, not a gate."""
import argparse
import hashlib
import json
from pathlib import Path
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection


def object_data(path):
    with path.open('rb') as stream:
        elf=ELFFile(stream)
        sections={section.name:section.data() for section in elf.iter_sections() if section['sh_flags']&2}
        relocations=[]
        for section in elf.iter_sections():
            if not isinstance(section,RelocationSection): continue
            target=elf.get_section(section['sh_info'])
            if not target['sh_flags']&2: continue
            symbols=elf.get_section(section['sh_link'])
            for relocation in section.iter_relocations():
                symbol=symbols.get_symbol(relocation['r_info_sym'])
                name=symbol.name
                if not name and isinstance(symbol['st_shndx'],int): name=elf.get_section(symbol['st_shndx']).name
                relocations.append(dict(section=target.name,offset=relocation['r_offset'],
                                        type=relocation['r_info_type'],symbol=name,
                                        addend=relocation['r_addend'] if relocation.is_RELA() else None))
    return sections,relocations


def compare(expected,actual):
    original,relocations=object_data(expected)
    candidate,new_relocations=object_data(actual)
    rows=[]
    for name in sorted(original.keys()|candidate.keys()):
        left=original.get(name);right=candidate.get(name)
        row=dict(section=name,equal=left==right,
                 expected_bytes=len(left) if left is not None else None,
                 actual_bytes=len(right) if right is not None else None)
        if left is not None: row['expected_sha256']=hashlib.sha256(left).hexdigest()
        if right is not None: row['actual_sha256']=hashlib.sha256(right).hexdigest()
        if left is not None and right is not None and left!=right:
            row['first_difference']=next((i for i,(a,b) in enumerate(zip(left,right)) if a!=b),min(len(left),len(right)))
        rows.append(row)
    return dict(expected=str(expected),actual=str(actual),sections=rows,
                all_allocated_sections_equal=original==candidate,
                relocations_equal=relocations==new_relocations,
                expected_relocations=relocations,actual_relocations=new_relocations)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--record',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--extra-bpf',type=Path)
    args=parser.parse_args()
    record=json.loads(args.record.read_text())
    original=Path(record['runtime_object']['path'])
    result=dict(direct=compare(original,args.record.with_suffix('.direct.bpf.o')),
                saved_ir=compare(original,args.record.with_suffix('.bpf.o')))
    if args.extra_bpf:
        result['extra_bpf']=compare(original,args.extra_bpf)
    args.output.write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({key:{name:value[name] for name in ['all_allocated_sections_equal','relocations_equal']}
                      for key,value in result.items()}))


if __name__=='__main__': main()
