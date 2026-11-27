"""Locate the remaining scalar loads in exact archived B and generated C."""
import hashlib,json,os,re,subprocess,tarfile,sys,difflib
from pathlib import Path
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
run=json.loads((LANE/'scalar-run.json').read_text());parent=Path(run['result']);raw=Path(run['raw'])
data=json.loads((parent/'outcomes.json').read_text());selected={r['index']:r for r in data['requests'] if r['after']['family']=='scalar memory access'};assert len(selected)==8
compiled={r['index']:r for r in json.loads((parent/'compile-controller.json').read_text())['cases']}
receipt=json.loads((parent/'controller.json').read_text());wanted={str(i)+'/'+n for i in selected for n in ['after.bpf.c','after.bpf.o','stock-after.verifier.log']};found={}
parts=sorted(parent.glob('evidence.tar.zst.part-*'))
for p in parts:
 assert subprocess.check_output(['git','ls-tree','HEAD','--',str(p.relative_to(ROOT))],text=True).split()[2]==subprocess.check_output(['git','hash-object',str(p)],text=True).strip()
a=subprocess.Popen(['cat',*map(str,parts)],stdout=subprocess.PIPE);b=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close()
with tarfile.open(fileobj=b.stdout,mode='r|') as archive:
 for m in archive:
  p=Path(m.name)
  if m.isfile() and p.parts[0]==raw.name:
   rel=str(Path(*p.parts[1:]))
   if rel in wanted:found[rel]=archive.extractfile(m).read()
b.stdout.close();assert a.wait()==b.wait()==0 and set(found)==wanted
for name,body in found.items():assert receipt['archive_files'][name]==dict(bytes=len(body),sha256=hashlib.sha256(body).hexdigest())
now=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip();out=Path(json.loads((LANE/'scalar-load-sites.json').read_text())['result']) if '--complete-current' in sys.argv else HERE/('scalar-load-sites-'+now.replace('-','').replace(':',''));out.mkdir(exist_ok='--complete-current' in sys.argv);rows=[]
for index,row in selected.items():
 obj=found[str(index)+'/after.bpf.o'];assert hashlib.sha256(obj).hexdigest()==compiled[index]['object_sha256']
 source=found[str(index)+'/after.bpf.c'].decode().splitlines();log=found[str(index)+'/stock-after.verifier.log'].decode();assert hashlib.sha256(log.encode()).hexdigest()==row['after']['verifier_sha256']
 lines=log.splitlines();bad=next(i for i,l in enumerate(lines) if re.search(r'R\d+ invalid mem access .scalar.',l));instruction=lines[bad-1];pc=int(re.match(r'(\d+):',instruction)[1])
 fd=os.memfd_create('archived-B',flags=0)
 try:
  os.write(fd,obj);assembly=subprocess.check_output(['llvm-objdump-18','--line-numbers','-d','/proc/self/fd/'+str(fd)],pass_fds=(fd,),text=True)
 finally:os.close(fd)
 asm=assembly.splitlines();at=next(i for i,l in enumerate(asm) if re.match(r'\s*'+str(pc)+r':',l));a=max(0,at-65);z=min(len(asm),at+18);window=asm[a:z]
 refs=[(i,int(m[1])) for i,l in enumerate(asm[:at+1]) if (m:=re.search(r'after\.bpf\.c:(\d+)',l))]
 c_line=refs[-1][1] if refs else None
 cwindow=[];native=None
 if c_line:
  cwindow=[str(i+1)+': '+source[i] for i in range(max(0,c_line-8),min(len(source),c_line+6))]
  for i in range(min(c_line-1,len(source)-1),-1,-1):
   if re.search(r'/\*\s*0x[0-9a-f]+:',source[i]):native=dict(line=i+1,text=source[i]);break
 item=dict(index=index,app=row['app'],request=row['request'],symbol=row['symbol'],B_instruction=pc,instruction=instruction,diagnostic=lines[bad],generated_C_line=c_line,nearest_preceding_native_comment=native,source_window=cwindow,entry_invocations=[dict(line=i+1,text=l) for i,l in enumerate(source) if re.search(r'ARM64_SIM_ENTRY_(RAW|XDP|SKB)\(',l)],entry_prefix=source[:35],native_prefix=source[:min(c_line or 100,100)],assembly_window=window,verifier_tail=lines[max(0,bad-10):bad+2],evidence={n:receipt['archive_files'][str(index)+'/'+n] for n in ['after.bpf.c','after.bpf.o','stock-after.verifier.log']})
 rows.append(item);(out/(str(index)+'.txt')).write_text(json.dumps(item,indent=2)+'\n')
record=dict(utc=now,controller_status=0,scope='Eight residual scalar load refusals from the completed145 sweep. Exact archived C/B/log hashes checked. Disassembly uses anonymous in-memory objects; no new build/RAW copy or compiler/guest/header change. A nearest C/native comment is debug-location evidence, not a dynamic native trace.',cases=rows)
header=ROOT/'kprog/arm64/arm64_sim_local_bpf.h';old=header.read_text()
capture=json.loads((parent/'compile-controller.json').read_text())['source_sha256']
assert hashlib.sha256(old.encode()).hexdigest()==capture[str(header)],'do not propose against drifted header'
assert all(any('ENTRY_RAW' in e['text'] for e in r['entry_invocations']) for r in rows)
old_tag='((TAG) != ARM64_SIM_TAG_STACK && (TAG) != ARM64_SIM_TAG_ABI && '
new_tag='((TAG) != ARM64_SIM_TAG_STACK && ((TAG) != ARM64_SIM_TAG_ABI || __a64_sim_abi_kind == ARM64_SIM_ABI_KIND_RAW) && '
assert old.count(old_tag)==1
new=old.replace(old_tag,new_tag)
start=new.index('        if ((SOURCE) == KPROG_ARM64_MEM_SRC_NORMAL_LOAD && ARM64_SIM_L_TAG_KERNEL_MEMORY(TAG))')
end=new.index('    } while (0)',start)
block=new[start:end]
lines=block.splitlines()
assert len(lines)==5,lines
# Keep the existing direct context access first, then broaden only the BPF probe predicate.
changed=[lines[2].replace('} else if','if'),lines[3],lines[0].replace('if ((SOURCE) == KPROG_ARM64_MEM_SRC_NORMAL_LOAD &&','} else if (((SOURCE) == KPROG_ARM64_MEM_SRC_NORMAL_LOAD || (SOURCE) == KPROG_ARM64_MEM_SRC_ABI_PTR_LOAD) &&'),lines[1],lines[4]]
new=new[:start]+'\n'.join(changed)+'\n'+new[end:]
patch=''.join(difflib.unified_diff(old.splitlines(True),new.splitlines(True),fromfile='a/kprog/arm64/arm64_sim_local_bpf.h',tofile='b/kprog/arm64/arm64_sim_local_bpf.h'))
(out/'raw-abi-probe-candidate.patch').write_text(patch)
record.update(shared_routing_cause='All8 use ENTRY_RAW; a64 RAW ABI 64-bit loads recursively retain TAG_ABI. Current kernel-memory predicate excludes that tag, and64-bit ABI_PTR_LOAD also bypasses the NORMAL_LOAD-only probe condition. Four32-bit andfour64-bit nested raw-context/pointee loads therefore remain direct while the verifier sees scalar addresses.',candidate=dict(path=str((out/'raw-abi-probe-candidate.patch').relative_to(ROOT)),state='PROPOSED ONLY, NOT APPLIED OR COMPILED',base_header_sha256=hashlib.sha256(old.encode()).hexdigest(),mechanism='Keep compiler-proven original context displacements direct first; permit remaining RAW ABI-tagged NORMAL_LOAD/ABI_PTR_LOAD through existing BPF probe. Existing host predicate0 and CompCert dispatch stay unchanged; no new tag/flags/per-app selection.',validation_pending='Need capped common-flags compilation and paired stock controls after current Tetragon consumes its captured headers. No acceptance predicted. ABI2 exclusive-retry relation remains independent.'))
(out/'sites.json').write_text(json.dumps(record,indent=2)+'\n')
(out/'README.md').write_text('# Eight residual scalar loads\n\n'+record['shared_routing_cause']+'\n\nThe exact archived C/B/log bytes were checked against the committed archive receipt and B compiler hashes. Source-annotated disassembly locates each failed B instruction at a native LDR comment; this is debug-location evidence, not a native execution trace. All8 use RAW entry.\n\nThe accompanying common BPF-only probe candidate keeps the current context access first and broadens the existing probe predicate to nested RAW ABI pointers. It is not applied or compiled. Active Tetragon headers are unchanged; host/Clight source, flags, tags, kernel, framework and full timing stay unchanged. A paired sweep and native stage2 would still be needed before claiming repair. See sites.json for all8 exact source/assembly/log windows and candidate status.\n')

(LANE/'scalar-load-sites.json').write_text(json.dumps(dict(result=str(out)),indent=2)+'\n')
print(json.dumps(dict(result=str(out),cases=[{k:r[k] for k in ['index','B_instruction','generated_C_line','nearest_preceding_native_comment']} for r in rows])),flush=True)
