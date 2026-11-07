from pathlib import Path
import sys,struct,json,hashlib
from elftools.elf.elffile import ELFFile
root=Path(sys.argv[1]);forms=json.loads((root/'forms.json').read_text());rows=[]
for variant in ['before','candidate']:
 with (root/variant/'reads.o').open('rb') as f:
  elf=ELFFile(f)
  seen=set()
  for sym in elf.get_section_by_name('.symtab').iter_symbols():
   if sym['st_info']['type']!='STT_FUNC':continue
   name=sym.name
   assert name in {row['name'] for row in forms}
   section=elf.get_section(sym['st_shndx'])
   code=section.data()[sym['st_value']:sym['st_value']+sym['st_size']]
   assert len(code)%8==0 and code[-8]==0x95
   ins=[struct.unpack('<BBhi',code[i:i+8]) for i in range(0,len(code),8)]
   assert all((x[0]&7) not in [2,3] for x in ins),(variant,name,ins)
   assert all(x[0]!=0x85 for x in ins),(variant,name,ins)
   if variant=='candidate' and name.startswith('read_') and name.split('_')[1] in ['1','2']:
    expected=255 if name.split('_')[1]=='1' else 65535
    assert any(x[0] in [0x54,0x57] and x[3]==expected for x in ins),(name,ins)
   (root/variant/(name+'.bin')).write_bytes(code)
   rows.append(dict(variant=variant,form=name,instructions=ins,bytes=len(code),sha256=hashlib.sha256(code).hexdigest()))
   seen.add(name)
  assert seen=={row['name'] for row in forms}
assert len(rows)==40
(root/'bytecode.json').write_text(json.dumps(rows,indent=2)+'\n')
