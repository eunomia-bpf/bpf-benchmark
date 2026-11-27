"""Read-only inventory of retained real inputs; never create a replacement P."""
from pathlib import Path
import hashlib,io,json,tarfile
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

BASE=Path('/workspaces/kprog-raw/perf/arm64-checked-corpus-20261127')
SOURCES=[
 '20261127T012418Z/bcc-set/service.tar.gz',
 '20261127T020053Z/katran/service.tar.gz',
 '20261127T021445Z/otelcol-ebpf-profiler-profiling/service.tar.gz',
 '20261127T044717Z/otelcol-ebpf-profiler-profiling/service.tar.gz',
 '20261127T090610Z/cilium-agent/service.tar.gz',
]
def sha(data):return hashlib.sha256(data).hexdigest()
rows=[]
for relative in SOURCES:
 path=BASE/relative
 archive_bytes=path.read_bytes()
 record={'archive':str(path),'archive_sha256':sha(archive_bytes),'requests':[]}
 with tarfile.open(fileobj=io.BytesIO(archive_bytes)) as outer:
  for member in outer:
   if not member.name.endswith('.success.tar.gz'):continue
   nested=outer.extractfile(member).read()
   with tarfile.open(fileobj=io.BytesIO(nested)) as archive:
    def get(name):return archive.extractfile('request/'+name).read()
    native=get('generated/request.native.o')
    source=get('generated/trusted_arm64.bpf.c')
    manifest_present='request/generated/artifacts.json' in archive.getnames()
    if manifest_present:
     artifacts=json.loads(get('generated/artifacts.json'))
     assert sha(native)==artifacts['native_sha256']
    elf=ELFFile(io.BytesIO(native))
    assert elf['e_machine']=='EM_AARCH64' and elf.little_endian
    symbols=elf.get_section_by_name('.symtab')
    functions=[s for s in symbols.iter_symbols() if s['st_info']['type']=='STT_FUNC' and isinstance(s['st_shndx'],int)]
    calls=[]
    for section in elf.iter_sections():
     if not isinstance(section,RelocationSection):continue
     target=elf.get_section(section['sh_info'])
     if not target['sh_flags'] & 4:continue
     names=elf.get_section(section['sh_link'])
     for rel in section.iter_relocations():
      if rel['r_info_type']!=283:continue
      symbol=names.get_symbol(rel['r_info_sym']).name
      calls.append({'section':target.name,'section_offset':rel['r_offset'],'symbol':symbol,
       'owners':[f.name for f in functions if f['st_shndx']==section['sh_info'] and f['st_value']<=rel['r_offset']<f['st_value']+f['st_size']]})
    lines=source.decode().splitlines()
    memcpy=[i+1 for i,line in enumerate(lines) if line.strip()=='ARM64_SIM_LIBC_MEMCPY();']
    record['requests'].append({'member':member.name,'member_sha256':sha(nested),
     'artifact_manifest_present':manifest_present,'native_sha256':sha(native),'source_sha256':sha(source),
     'source_memcpy_lines':memcpy,'CALL26_sites':calls})
 rows.append(record)
requests=[x for row in rows for x in row['requests']]
assert requests
memcpy=[x for x in requests if x['source_memcpy_lines'] or any(c['symbol']=='memcpy' for c in x['CALL26_sites'])]
record={'archives':rows,'successful_requests':len(requests),'memcpy_requests':memcpy,
 'scope':'Exactly five named retained archives and their successful requests. All input ELF executable-section CALL26 relocations and original generated source are inspected. Missing artifact manifests are recorded explicitly; native/source bytes still come from the hashed request archive. Failures,other captures,loaded/patched text and future requests are outside this inventory. No new native input or simulator source is generated. No absence claim for the entire corpus.'}
assert not memcpy,'Real memcpy candidate found; inspect and retain it before choosing the next caller.'
Path(__file__).with_name('callers.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps({'archives':len(rows),'successful_requests':len(requests),'memcpy_requests':len(memcpy)},indent=2))
