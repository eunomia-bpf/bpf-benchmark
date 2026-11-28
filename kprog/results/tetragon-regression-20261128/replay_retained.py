"""Replay exact retained kernel-mode inputs through the common current linker; no source rebuild."""
from pathlib import Path
from elftools.elf.elffile import ELFFile
import hashlib,io,json,os,re,resource,subprocess,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;D=OUT/'replay';D.mkdir(exist_ok=True)
CACHE=ROOT/'kprog/results/cmov-branches-20261126/post-branch-profiles-20261126T145836Z/tetragon-profile/linkcache/native_kernel_link_cache';LINK=ROOT/'kprog/x86/native_lab/native_link/target/release/native-link';os.sched_setaffinity(0,{16});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3));sha=lambda b:hashlib.sha256(b).hexdigest();now=lambda:subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def src(p):
 b=p.read_bytes();return dict(path=str(p.relative_to(ROOT)),bytes=len(b),sha256=sha(b))
def decode(data):
 fd=os.memfd_create('retained-tetragon')
 try:
  os.write(fd,data);os.lseek(fd,0,os.SEEK_SET);p=subprocess.run(['objdump','-D','-b','binary','-m','i386:x86-64','--no-show-raw-insn',f'/proc/self/fd/{fd}'],pass_fds=(fd,),stdin=subprocess.DEVNULL,capture_output=True,text=True);assert p.returncode==0,p.stderr
 finally:os.close(fd)
 rows=[]
 for line in p.stdout.splitlines():
  m=re.match(r'\s*([0-9a-f]+):\s+(\S+)(?:\s+(.*))?$',line)
  if m:rows.append(dict(offset=int(m[1],16),opcode=m[2],operands=m[3] or '',text=line.strip()))
 return rows
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,scope='Actual11-26 retained proof/plan/blob replay with current common linker. Not11-23 installed bytes or a timing/guest run.',linker=src(LINK),rows=[])
def save():(OUT/'replay-controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 save()
 for key in ['45ba49203d276b52','5be2ee6f95ee536b','a751a5ae32d71696','e700f906b8500cb3']:
  proof=CACHE/(key+'.proof.o');plans=list(CACHE.glob(key+'*.link-plan.json'));assert len(plans)==1;plan=plans[0];oldfile=CACHE/(key+'.blob.bin');inputs=[src(p) for p in [proof,plan,oldfile]];ef=ELFFile(io.BytesIO(proof.read_bytes()));syms=ef.get_section_by_name('.symtab');entry=next(s.name for s in syms.iter_symbols() if s['st_info']['type']=='STT_FUNC' and isinstance(s['st_shndx'],int));new=D/(key+'.blob.bin');assert not new.exists();args=[str(LINK),'--input',str(proof),'--symbol',entry,'--mode','kernel','--output',str(new),'--output-relocs',str(D/(key+'.relocs.bin')),'--output-map-patches',str(D/(key+'.map-patches.tsv')),'--output-abi',str(D/(key+'.abi.tsv')),'--link-plan',str(plan)];p=subprocess.run(args,stdin=subprocess.DEVNULL,capture_output=True,text=True);(D/(key+'.log')).write_text(p.stdout+p.stderr);assert p.returncode==0,p.stderr
  old=decode(oldfile.read_bytes());fresh=decode(new.read_bytes());oi={x['offset']:i for i,x in enumerate(old)};ni={x['offset']:i for i,x in enumerate(fresh)};alignment=[];branches=[]
  for i,(a,b) in enumerate(zip(old,fresh)):
   ja=re.fullmatch(r'0x([0-9a-f]+)',a['operands']);jb=re.fullmatch(r'0x([0-9a-f]+)',b['operands']);direct=bool(ja and jb and a['opcode'].startswith('j') and b['opcode'].startswith('j'))
   if a['opcode']!=b['opcode'] or (not direct and a['operands']!=b['operands'] and not(a['opcode']==b['opcode']=='call' and ja and jb)):alignment.append(dict(index=i,old=a,new=b))
   elif direct:
    ta=int(ja[1],16);tb=int(jb[1],16);ia=oi.get(ta);ib=ni.get(tb)
    if ia!=ib:branches.append(dict(index=i,old=a,new=b,old_target_index=ia,new_target_index=ib,old_target=old[ia:ia+4] if ia is not None else [],new_target=fresh[ib:ib+4] if ib is not None else []))
  incoming=[];rel=ef.get_section_by_name('.rela.text');calls={x['r_offset']-1:syms.get_symbol(x['r_info_sym']).name for x in rel.iter_relocations() if x['r_info_type']==4};proofdis=subprocess.check_output(['objdump','-dr','--no-show-raw-insn',str(proof)],text=True)
  for line in proofdis.splitlines():
   m=re.match(r'\s*([0-9a-f]+):\s+(j\w+)\s+([0-9a-f]+)\s',line)
   if m and int(m[3],16) in calls:incoming.append(dict(source_offset=int(m[1],16),opcode=m[2],target_offset=int(m[3],16),callee=calls[int(m[3],16)]))
  for x in inputs:assert sha((ROOT/x['path']).read_bytes())==x['sha256']
  row=dict(cache_key=key,entry=entry,inputs=inputs,command=args,returncode=p.returncode,new_blob=src(new),old_blob_bytes=oldfile.stat().st_size,old_instruction_count=len(old),new_instruction_count=len(fresh),nonbranch_alignment_differences=alignment,changed_direct_branch_targets=branches,source_incoming_helper_branches=incoming,old_disassembly=old,new_disassembly=fresh,proof_disassembly=proofdis);r['rows'].append(row);save()
 assert sha(LINK.read_bytes())==r['linker']['sha256'];r.update(controller_status=0,phase='complete')
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps({k:v for k,v in r.items() if k!='rows'}),flush=True)
raise SystemExit(r['controller_status'])
