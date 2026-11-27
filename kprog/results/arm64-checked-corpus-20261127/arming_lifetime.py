"""Check map-lifetime invariants behind the two captured ARM CHUNK failures."""
import ast
import datetime
import gzip
import hashlib
import io
import json
from pathlib import Path
import re
import subprocess
import tarfile
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
now=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip();token=now.replace('-','').replace(':','');OUT=HERE/('arming-lifetime-'+token);OUT.mkdir()
def sha(data):return hashlib.sha256(data).hexdigest()
record=dict(utc=now,scope='Read-only archive/source deduction. No kernel instrumentation, guest, compile, lifetime-policy change or install-success claim. Uploaded in-memory CHUNK wire was not captured.',cases=[],source_sha256={})
source_paths=['kprog/libnativeloader/src/native_loader.cpp','kprog/libnativeloader/src/native_loader_trusted.cpp','kprog/libnativeloader/src/native_loader_internal.hpp','kinsn/module/arm64/bpf_arm64_native_lab.c','kinsn/module/include/native_lab_trusted.h','kinsn/module/include/native_lab_trusted_wire.h']
for token,rid in [('20261127T120527Z',17),('20261127T140827Z',11)]:
 controller=json.loads((HERE/('guest-'+token)/'controller.json').read_text());case=Path(controller['raw'])/controller['app'].replace('/','-');dest=OUT/controller['app'].replace('/','-');dest.mkdir();service=case/'service.tar.gz';wanted={'error.json','kernel.entry','kernel.facts.json','kernel.metadata.json','source-identities.json','load-direct.stderr'};files={};rows=[]
 with tarfile.open(service,mode='r|gz') as outer:
  for member in outer:
   if not member.isfile():continue
   if member.name=='service/service.log':
    rows=[json.loads(l) for l in outer.extractfile(member).read().decode().splitlines() if '"request_id"' in l];continue
   if not member.name.endswith('/'+str(rid)+'.failure.tar.gz'):continue
   with tarfile.open(fileobj=outer.extractfile(member),mode='r|gz') as inner:
    artifacts={}
    for m in inner:
     if not m.isfile():continue
     leaf=Path(m.name).name
     if leaf in wanted or ('/kernel-link/' in m.name and leaf.endswith(('.map-patches.tsv','.relocs.bin'))):files[leaf]=inner.extractfile(m).read()
     elif leaf in ['request.native.o','kernel.native.o']:
      data=inner.extractfile(m).read();artifacts[leaf]=dict(bytes=len(data),sha256=sha(data))
 error=json.loads(files['error.json']);facts=json.loads(files['kernel.facts.json']);meta=json.loads(files['kernel.metadata.json']);identities=json.loads(files['source-identities.json']);row=next(x for x in rows if x['request_id']==rid)
 argv=ast.literal_eval(re.search(r"Command '(\[.*\])' returned",error['error'],re.S)[1]);assert argv[1]=='load-direct' and int(argv[3])==rid and int(argv[4])==facts['id']==row['source_prog_id']
 bindings={argv[i]:dict(map_id=int(argv[i+1]),value_offset=argv[i+2]) for i in range(17,len(argv),3)}
 patches=[(name,data) for name,data in files.items() if name.endswith('.map-patches.tsv')];base=[(name,data) for name,data in files.items() if name.endswith('.relocs.bin')];assert len(patches)==len(base)==1 and len(base[0][1])==0
 sites=[dict(name=l.split()[0],blob_offset=int(l.split()[1])) for l in patches[0][1].decode().splitlines() if l];metadata={m['name']:m for m in meta['maps']};fact_ids={m['id'] for m in facts['maps']}
 for site in sites:
  name=site['name'];assert name in bindings and bindings[name]['map_id']==metadata[name]['map_id'];site.update(bindings[name],in_captured_source_maps=bindings[name]['map_id'] in fact_ids)
 pins=sorted({x['map_id'] for x in sites});assert all(s['in_captured_source_maps'] for s in sites)
 loader=Path(argv[0]);assert sha(loader.read_bytes())==identities[str(loader)],'loader binary drift'
 for path in source_paths:
  current=(ROOT/path).read_bytes();old=subprocess.check_output(['git','show',controller['guest_start_revision']+':'+path],cwd=ROOT);assert current==old,path
  record['source_sha256'][path]=sha(current)
  if str(ROOT/path) in identities:assert identities[str(ROOT/path)]==sha(current)
 for name,data in files.items():(dest/(name+'.gz')).write_bytes(gzip.compress(data,mtime=0))
 with tarfile.open(case/'corpus.tar.gz') as corpus:
  m=next(x for x in corpus if x.isfile() and x.name.endswith('/metadata.json'));corpus_meta=json.loads(corpus.extractfile(m).read())
 result=dict(app=controller['app'],request_id=rid,symbol=files['kernel.entry'].decode().strip(),source_prog_id=facts['id'],service_started=row['started'],service_finished=row['finished'],service_status=row['status'],corpus_recorded_at=corpus_meta.get('generated_at'),corpus_status=corpus_meta.get('status'),loader_binary_sha256=identities[str(loader)],native_artifacts=artifacts,stderr=files['load-direct.stderr'].decode(),base_relocs=dict(name=base[0][0],bytes=0,sha256=sha(base[0][1])),runtime_map_sites=sites,inferred_wire_map_ids=pins,invocation_request_id=int(argv[3]),capture_files={name:dict(bytes=len(data),sha256=sha(data)) for name,data in files.items()})
 result['finished_after_corpus_record_seconds']=(datetime.datetime.fromisoformat(row['finished'])-datetime.datetime.fromisoformat(corpus_meta['generated_at'])).total_seconds()
 record['cases'].append(result)
record['deduction']=[
 'Empty cached .relocs.bin is NOT an empty CHUNK relocation list: bind_native_map_relocations appends a runtime map relocation for each map-patches.tsv site.',
 'Every appended low32 map ID comes from the same companion.map_addr_ids mapping collected into linked.relocated_map_ids. Captured CLI bindings agree with kernel metadata and source map IDs in both cases.',
 'Before CHUNK ioctl, reopen_relocated_map_fds opens these IDs; failure would report bpf_map_get_fd_by_id(...) for native relocation lifetime, not the captured arm kernel native image error. The opened FDs remain in ScopedFd pins through ioctl, with no exec between FD_CLOEXEC and ioctl.',
 'The kernel increments a map user/reference count when reopening by ID; an open FD keeps that ID live. With empty base relocations, every map ID reaching the CHUNK map-lookup branch is therefore already pinned under this code path.',
 'Consequently the map-disappearance ENOENT branch is inconsistent with the captured loader path and its FD invariant. The remaining ENOENT path is native_lab_active_capsule rejecting an absent, abandoned or mismatched active request.',
 'Both CLI request IDs match service request IDs. Exact kernel active-job state and which rejection predicate fired were not traced. Timeout/process teardown remains an inference rather than a directly observed signal or branch.'
]
record['limits']='This strengthens the earlier two-branch diagnosis using source/capture invariants, not a new runtime kernel trace. Actual in-memory image.relocs was not archived, and module source equality to guest-start Git does not independently prove module build provenance. No wrong-map-ID fix or kernel lifetime extension is justified by these captures.'
snippets=[]
regions={'kprog/libnativeloader/src/native_loader.cpp':[(3377,3398)],'kprog/libnativeloader/src/native_loader_trusted.cpp':[(2266,2296),(3043,3086)],'kprog/libnativeloader/src/native_loader_internal.hpp':[(13,28)],'kinsn/module/arm64/bpf_arm64_native_lab.c':[(85,152)],'kinsn/module/include/native_lab_trusted.h':[(350,362),(518,549)]}
for path,ranges in regions.items():
 lines=(ROOT/path).read_text().splitlines()
 for start,end in ranges:snippets.append(path+':'+str(start)+'\n'+'\n'.join(lines[start-1:end]))
path='vendor/linux-framework/kernel/bpf/syscall.c';data=(ROOT/path).read_bytes();record['source_sha256'][path]=sha(data);lines=data.decode().splitlines();snippets.append(path+':4854\n'+'\n'.join(lines[4853:4890]))
(OUT/'source-trace.txt').write_text('\n\n'.join(snippets)+'\n');record['controller_status']=0
(OUT/'analysis.json').write_text(json.dumps(record,indent=2)+'\n');(LANE/'arming-lifetime.json').write_text(json.dumps(dict(result=str(OUT)),indent=2)+'\n')
print(json.dumps(dict(result=str(OUT),cases=[dict(app=c['app'],maps=len(c['inferred_wire_map_ids']),base_reloc_bytes=c['base_relocs']['bytes'],finished_after_corpus_seconds=c['finished_after_corpus_record_seconds']) for c in record['cases']])),flush=True)
