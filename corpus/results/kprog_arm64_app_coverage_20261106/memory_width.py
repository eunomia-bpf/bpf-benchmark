"""Require a single actual BPF memory instruction at each architectural width."""
import json
from pathlib import Path
import struct
import sys
from elftools.elf.elffile import ELFFile
phase=Path(sys.argv[1]).resolve()
rows=[]
with (phase/'width.bpf.o').open('rb') as source:
    elf=ELFFile(source)
    if elf['e_machine']!='EM_BPF':raise RuntimeError('width fixture is not BPF')
    for symbol in elf.get_section_by_name('.symtab').iter_symbols():
        if symbol['st_info']['type']!='STT_FUNC':continue
        name=symbol.name
        if not name.startswith(('read','write')):raise RuntimeError(f'unexpected width fixture: {name}')
        bits=int(name.removeprefix('read').removeprefix('write'))
        instructions=elf.get_section(symbol['st_shndx']).data()[symbol['st_value']:symbol['st_value']+symbol['st_size']]
        accesses=[]
        for offset in range(0,len(instructions),8):
            opcode,registers,displacement,immediate=struct.unpack('<BBhi',instructions[offset:offset+8])
            if (opcode & 7) in {1,3} and opcode & 0xe0==0x60:
                size={0:4,8:2,16:1,24:8}[opcode & 0x18]
                accesses.append(dict(size=size,load=(opcode&7)==1,displacement=displacement))
        if accesses!=[dict(size=bits//8,load=name.startswith('read'),displacement=0)]:
            raise RuntimeError(f'{name}: expected exactly one width-correct access: {accesses}')
        rows.append(dict(function=name,accesses=accesses))
if len(rows)!=8:raise RuntimeError('missing width fixture')
(phase/'bpf-accesses.json').write_text(json.dumps(rows,indent=2)+'\n')
print('all8 compiled BPF functions perform exactly ONE requested-width access at pointer+3')
