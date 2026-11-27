"""Collect completed source-qualifier validation, BTF metadata and raw archive proof."""
import hashlib
import io
import json
import os
from pathlib import Path
import struct
import subprocess
import tarfile
from elftools.elf.elffile import ELFFile

ROOT=Path('/workspaces/repository')
HERE=Path(__file__).resolve().parent
OUT=HERE/'header-source-20261127T151253Z'
RAW=Path('/workspaces/kprog-raw/perf/arm64-loadtime-20261127/header-source-20261127T151253Z')
r=json.loads((OUT/'validation-controller.json').read_text())
assert r['controller_status']==0 and len(r['cases'])==8 and not r['header_drift']
def digest(data):return hashlib.sha256(data).hexdigest()
def btf(elf):
    data=elf.get_section_by_name('.BTF').data();h=struct.unpack_from('<HBBIIIII',data);assert h[0]==0xeb9f and h[1]==1
    strings=data[h[3]+h[6]:h[3]+h[6]+h[7]]
    def name(offset):return strings[offset:strings.index(b'\0',offset)].decode()
    types=[];cursor=h[3]+h[4];end=cursor+h[5]
    while cursor<end:
        off,info,size=struct.unpack_from('<III',data,cursor);cursor+=12;kind=(info>>24)&127;count=info&0xffffff;extra=[]
        def words(n):
            nonlocal cursor
            values=list(struct.unpack_from('<'+'I'*n,data,cursor));cursor+=4*n;return values
        if kind==1:extra=words(1)
        elif kind==3:extra=words(3)
        elif kind in [4,5,6,13,15,19]:
            width=2 if kind in [6,13] else 3
            for _ in range(count):
                item=words(width)
                if kind!=15:item[0]=name(item[0])
                extra.append(item)
        elif kind in [14,17]:extra=words(1)
        else:assert kind in [0,2,7,8,9,10,11,12,16,18],kind
        types.append(dict(name=name(off),info=info,size_or_type=size,extra=extra))
    assert cursor==end
    ext=elf.get_section_by_name('.BTF.ext').data();head=struct.unpack_from('<HBBIIIIIII',ext);assert head[0]==0xeb9f and head[1]==1
    def group(offset,length,core):
        if not length:return []
        start=head[3]+offset;end=start+length;record_size=struct.unpack_from('<I',ext,start)[0];cursor=start+4;groups=[]
        while cursor<end:
            section,count=struct.unpack_from('<II',ext,cursor);cursor+=8;records=[]
            for _ in range(count):
                values=list(struct.unpack_from('<'+'I'*(record_size//4),ext,cursor));cursor+=record_size
                if core:values[2]=name(values[2])
                records.append(values)
            groups.append(dict(section=name(section),records=records))
        assert cursor==end
        return groups
    return dict(types=types,func_info=group(head[4],head[5],False),core_relo=group(head[8],head[9],True))
comparisons=[]
for i,case in enumerate(r['cases'],1):
    folder=RAW/('validation-'+str(i));a=ELFFile(io.BytesIO((folder/'baseline.bpf.o').read_bytes()));b=ELFFile(io.BytesIO((folder/'trusted_arm64.bpf.o').read_bytes()))
    before={s.name:digest(s.data()) for s in a.iter_sections()};after={s.name:digest(s.data()) for s in b.iter_sections()};changed=[n for n in sorted(set(before)|set(after)) if before.get(n)!=after.get(n)]
    assert all(n.startswith(('.debug','.BTF')) for n in changed),changed
    x=btf(a);y=btf(b)
    comparisons.append(dict(app=case['app'],identity=case['identity'],changed_sections=changed,btf_types_equal=x['types']==y['types'],btf_func_info_equal=x['func_info']==y['func_info'],btf_core_relocations_equal=x['core_relo']==y['core_relo'],baseline_btf_types_sha256=digest(json.dumps(x['types'],sort_keys=True).encode()),current_btf_types_sha256=digest(json.dumps(y['types'],sort_keys=True).encode())))
summary=dict(utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),controller='validation-controller.json',compiled=8,allocated_sections_equal=8,code_relocations_equal=8,whole_ELF_equal=0,metadata=comparisons,regenerator=r['regenerator'],producer_sha256=r['producer_sha256'],scope='All8 actual ELF allocated sections and code relocations match. Changed bytes are exclusively .debug* and .BTF*. BTF types, function info and CO-RE records are compared after resolving string offsets; line/debug metadata remains byte-different. Includes working OMP direct.h captured exactly, not a claim that its pre-existing unpublished delta is in HEAD. No stock/native/900s timing acceptance.')
(OUT/'validation-summary.json').write_text(json.dumps(summary,indent=2)+'\n')
# Snapshot the exact current source bytes checked by the finished worker.
for path,h in r['compiler_header_sha256'].items():assert digest(Path(path).read_bytes())==h,path
paths=[Path(p) for p in r['compiler_header_sha256']]+[ROOT/'kprog/arm64/trusted_specializer.py',ROOT/'kprog/arm64/generate_sim_dispatch.py',HERE/'header_source_check.py',Path('/workspaces/repository/vendor/libbpf/include/uapi/linux/btf.h')]
with tarfile.open(RAW/'after-source.tar','w') as archive:
    for path in paths:archive.add(path,arcname=str(path.relative_to(ROOT)))
with (OUT/'archive.log').open('wb') as log:
    a=subprocess.Popen(['tar','-C',str(RAW.parent),'-cf','-',RAW.name],stdout=subprocess.PIPE,stderr=log)
    b=subprocess.Popen(['zstd','-T1','-3','-c'],stdin=a.stdout,stdout=subprocess.PIPE,stderr=log);a.stdout.close()
    c=subprocess.Popen(['split','-b','48000000','-',str(OUT/'evidence.tar.zst.part-')],stdin=b.stdout,stderr=log);b.stdout.close();codes=[a.wait(),b.wait(),c.wait()]
assert codes==[0,0,0]
parts=sorted(OUT.glob('evidence.tar.zst.part-*'));source=subprocess.Popen(['cat',*map(str,parts)],stdout=subprocess.PIPE);decode=subprocess.Popen(['zstd','-dc'],stdin=source.stdout,stdout=subprocess.PIPE);source.stdout.close();files=[]
with tarfile.open(fileobj=decode.stdout,mode='r|') as archive:
    for member in archive:
        if not member.isfile():continue
        path=RAW.parent/member.name;stream=archive.extractfile(member);h=hashlib.sha256()
        with path.open('rb') as raw:
            while True:
                block=stream.read(1024*1024);assert block==raw.read(len(block) if block else 1),path
                if not block:break
                h.update(block)
        files.append(dict(member=member.name,bytes=member.size,sha256=h.hexdigest()))
assert decode.wait()==source.wait()==0
receipt=dict(utc=summary['utc'],raw=str(RAW),pid=r['pid'],controller_status=0,ended_utc=r['ended_utc'],source_revision=r['source_revision'],validation_controller='validation-controller.json',archive_returncodes=codes,archived_files_equal_raw=len(files),archive_parts=[dict(path=p.name,bytes=p.stat().st_size,sha256=digest(p.read_bytes())) for p in parts],files=files,scope=summary['scope'])
(OUT/'controller.json').write_text(json.dumps(receipt,indent=2)+'\n')
print(json.dumps(dict(compiled=8,metadata=comparisons,archived_files_equal_raw=len(files),parts=receipt['archive_parts']),indent=2))
