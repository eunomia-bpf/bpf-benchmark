from pathlib import Path
import hashlib,io,json,re,tarfile
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

ROOT=Path('/workspaces/repository')
ARCHIVE=Path('/workspaces/kprog-raw/perf/arm64-checked-corpus-20261127/20261127T090610Z/cilium-agent/service.tar.gz')
MEMBER='service/requests/1.success.tar.gz'
def sha(data):return hashlib.sha256(data).hexdigest()
with tarfile.open(ARCHIVE) as outer:
 nested=outer.extractfile(MEMBER).read()
with tarfile.open(fileobj=io.BytesIO(nested)) as archive:
 def get(name):return archive.extractfile('request/'+name).read()
 native=get('generated/request.native.o')
 source=get('generated/trusted_arm64.bpf.c')
 artifacts=json.loads(get('generated/artifacts.json'))
 identities=json.loads(get('source-identities.json'))
assert sha(native)==artifacts['native_sha256']
elf=ELFFile(io.BytesIO(native))
assert elf['e_machine']=='EM_AARCH64' and elf.little_endian
symbols=elf.get_section_by_name('.symtab')
entry=next(s for s in symbols.iter_symbols() if s.name==artifacts['symbol'])
section=elf.get_section(entry['st_shndx'])
relocs={}
for sec in elf.iter_sections():
 if isinstance(sec,RelocationSection) and sec['sh_info']==entry['st_shndx']:
  names=elf.get_section(sec['sh_link'])
  for rel in sec.iter_relocations():
   relocs[rel['r_offset']]=(rel,names.get_symbol(rel['r_info_sym']).name)
lines=source.decode().splitlines()
rows=[];label=None
for i,line in enumerate(lines):
 m=re.fullmatch(r'arm64_l_([0-9a-f]+):',line)
 if m:label=int(m[1],16)
 m=re.fullmatch(r'\s*ARM64_SIM_A64_LINK\(0x([0-9a-f]+)ULL\);',line)
 if not m:continue
 token=int(m[1],16);assert label is not None and token==label+4
 assert lines[i-1].strip().startswith('/* '+hex(label)+': bl ')
 assert lines[i+2]==f'arm64_l_{token:x}:'
 helper=re.fullmatch(r'\s*ARM64_SIM_BPF_CALL_([a-zA-Z0-9_]+)\(\);',lines[i+1])
 assert helper is not None
 at=entry['st_value']+label
 rel,name=relocs[at]
 assert rel['r_info_type']==283 and rel['r_addend']==0 and name==helper[1]
 words=[int.from_bytes(section.data()[at+j:at+j+4],'little') for j in [0,4]]
 assert words[0]==0x94000000 and token+4<=entry['st_size']
 rows.append({'source_pc':label,'source_token':token,'object_pc':at,'call_word':words[0],
 'continuation_word':words[1],'relocation_type':rel['r_info_type'],'relocation_symbol':name,
 'relocation_addend':rel['r_addend'],'source_line':i+1,'source_excerpt':lines[i-2:i+5]})
assert len(rows)==8
paths=['kprog/arm64/arm64_sim_local_bpf.h','kprog/arm64/micro-prog/generate_micro_sim_proofs.py']
source_ids={}
for path in paths:
 archived=identities[str(ROOT/path)];current=sha((ROOT/path).read_bytes())
 assert archived==current, path
 source_ids[path]={'captured_sha256':archived,'current_sha256':current,'equal':archived==current}
record={'archive':str(ARCHIVE),'archive_sha256':sha(ARCHIVE.read_bytes()),
 'member':MEMBER,'member_sha256':sha(nested),'native_sha256':sha(native),'source_sha256':sha(source),
 'native_member':'request/generated/request.native.o','source_member':'request/generated/trusted_arm64.bpf.c',
 'symbol':artifacts['symbol'],'section':section.name,'symbol_value':entry['st_value'],
 'symbol_size':entry['st_size'],'source_identities':source_ids,'calls':rows,
 'scope':'Eight actual Cilium LINK/helper sites in captured input P and generated source. The original CALL26 words are unrelocated;actual loaded symbol placement/patched BL fetch remain Code admission. This is not a captured memcpy caller or whole app acceptance. Canonical CODE9 stays raw;code coordinates are separate.'}
lean=ROOT/'kprog/formal/KProgFormal/ClightRefinement/Arm64MemcpyLinkCode.lean'
lean_text=lean.read_text()
for name,key,bits in [('pcs','source_pc',64),('tokens','source_token',64),('returns','continuation_word',32)]:
 pattern=r'private def '+name+r' : Array \(BitVec '+str(bits)+r'\) := #\[(.*?)\]'
 match=re.search(pattern,lean_text)
 assert match is not None,name
 actual=[int(x,16) for x in re.findall(r'0x([0-9a-f]+)#'+str(bits),match[1])]
 assert actual==[row[key] for row in rows],name
assert record['symbol_value']==18128 and record['symbol_size']==812
record['lean_source_sha256']=sha(lean.read_bytes())
Path(__file__).with_name('artifact.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps({'symbol':record['symbol'],'symbol_value':record['symbol_value'],'sites':len(rows),
 'source_ids':source_ids,'calls':[(r['source_pc'],r['source_token'],r['relocation_symbol']) for r in rows]},indent=2))
