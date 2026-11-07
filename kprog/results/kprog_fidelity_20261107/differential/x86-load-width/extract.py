from pathlib import Path
import sys,struct,json,hashlib
from elftools.elf.elffile import ELFFile
root=Path(sys.argv[1]); rows=[]
for variant in ['before','current']:
 with (root/variant/'loads.o').open('rb') as f:
  elf=ELFFile(f)
  for sym in elf.get_section_by_name('.symtab').iter_symbols():
   if sym['st_info']['type']!='STT_FUNC':continue
   name=sym.name
   assert name.startswith(('load_','fixed_'))
   section=elf.get_section(sym['st_shndx'])
   code=section.data()[sym['st_value']:sym['st_value']+sym['st_size']]
   ins=[struct.unpack('<BBhi',code[i:i+8]) for i in range(0,len(code),8)]
   width=int(name.rsplit('_',1)[1]);size=width or 8
   offset=0 if name.startswith('load_') else [-32768,-3,-1,0,88,32767][int(name.split('_')[1])]
   loads=[x for x in ins if x[0]&7==1]
   assert len(loads)==1,(name,ins)
   assert loads[0][0]=={1:0x71,2:0x69,4:0x61,8:0x79}[size],(name,loads)
   assert loads[0][2]==offset,(name,loads,offset)
   assert all(x[0] in {0x71,0x69,0x61,0x79,0xbf,0xbc,0xb7,0xb4,0x57,0x54,0x67,0x77,0x95} for x in ins),(name,ins)
   assert ins[-1][0]==0x95
   (root/variant/(name+'.bin')).write_bytes(code)
   rows.append(dict(variant=variant,form=name,width_argument=width,bytes=size,displacement=offset,instructions=ins,sha256=hashlib.sha256(code).hexdigest()))
assert len(rows)==70
(root/'bytecode.json').write_text(json.dumps(rows,indent=2)+'\n')
