from pathlib import Path
from elftools.elf.elffile import ELFFile
from elftools.common.exceptions import ELFError
import hashlib,io,json,re,struct,subprocess,tarfile
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;SOURCE=OUT.parent/'check-20261128T034810Z';r=json.loads((SOURCE/'collection-controller.json').read_text());a=subprocess.Popen(['cat',*[p['path'] for p in r['parts']]],stdout=subprocess.PIPE);b=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close();errors=[];parsed=0
with tarfile.open(fileobj=b.stdout,mode='r|') as t:
 for m in t:
  if not m.isfile():continue
  rel=str(Path(*Path(m.name).parts[1:]))
  if not re.fullmatch(r'[0-9a-f]{16}\.proof\.o',Path(rel).name):continue
  data=t.extractfile(m).read();h=hashlib.sha256(data).hexdigest();assert h==r['files'][rel]['sha256'] and len(data)==r['files'][rel]['bytes']
  try:ELFFile(io.BytesIO(data)).get_section_by_name('.symtab');parsed+=1
  except ELFError as e:
   p=OUT/('captured-'+rel.split('/')[0]+'-'+Path(rel).name);p.write_bytes(data);readelf=subprocess.run(['readelf','-h','-S',str(p)],stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True);p.with_suffix('.readelf.txt').write_text(readelf.stdout)
   errors.append(dict(member=rel,bytes=len(data),sha256=h,error=str(e),preserved=p.name,readelf_returncode=readelf.returncode,elf64_shoff=struct.unpack_from('<Q',data,40)[0],elf64_shentsize=struct.unpack_from('<H',data,58)[0],elf64_shnum=struct.unpack_from('<H',data,60)[0],elf64_shstrndx=struct.unpack_from('<H',data,62)[0]))
b.stdout.close();assert a.wait()==b.wait()==0
(OUT/'proof-inspection.json').write_text(json.dumps(dict(parsed=parsed,errors=errors),indent=2)+'\n');print(json.dumps(dict(parsed=parsed,errors=errors)))
