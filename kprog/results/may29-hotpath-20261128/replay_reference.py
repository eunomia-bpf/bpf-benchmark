"""Run the retained reference linker on exact retained Tetragon proofs/plans, not a historical timing reconstruction."""
from pathlib import Path
from elftools.elf.elffile import ELFFile
import datetime,hashlib,io,json,os,resource,subprocess,tarfile,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
CACHE=ROOT/'kprog/results/cmov-branches-20261126/post-branch-profiles-20261126T145836Z/tetragon-profile/linkcache/native_kernel_link_cache'
LINK=Path('/workspaces/kprog-raw/paper-tree-untracked/native-sim/x86/native_lab/native_link/target/release/native-link')
os.sched_setaffinity(0,{16});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def seal(p):
 b=p.read_bytes();return dict(path=str(p),bytes=len(b),sha256=hashlib.sha256(b).hexdigest())
D=OUT/'reference-replay';D.mkdir(exist_ok=False)
r=dict(pid=os.getpid(),started_utc=now(),status='running',scope='Retained reference executable against exact Nov26 proofs/plans; neither original May29 installed bytes nor a new benchmark. No app compilation or runtime image change.',linker=seal(LINK),rows=[])
def save():(OUT/'reference-controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 save()
 for key in ['45ba49203d276b52','5be2ee6f95ee536b','a751a5ae32d71696','e700f906b8500cb3']:
  proof=CACHE/(key+'.proof.o');plans=list(CACHE.glob(key+'*.link-plan.json'));assert len(plans)==1;plan=plans[0]
  e=ELFFile(io.BytesIO(proof.read_bytes()));syms=e.get_section_by_name('.symtab');entry=next(s.name for s in syms.iter_symbols() if s['st_info']['type']=='STT_FUNC' and isinstance(s['st_shndx'],int))
  inputs=[seal(p) for p in [proof,plan,CACHE/(key+'.blob.bin')]]
  stem=D/key;args=[str(LINK),'--input',str(proof),'--symbol',entry,'--mode','kernel','--output',str(stem)+'.blob.bin','--output-relocs',str(stem)+'.relocs.bin','--output-map-patches',str(stem)+'.map-patches.tsv','--output-abi',str(stem)+'.abi.tsv','--link-plan',str(plan)]
  p=subprocess.run(args,stdin=subprocess.DEVNULL,capture_output=True,text=True)
  (D/(key+'.log')).write_text(p.stdout+p.stderr)
  row=dict(key=key,entry=entry,inputs=inputs,command=args,returncode=p.returncode)
  blob=D/(key+'.blob.bin')
  if p.returncode==0:
   fd=os.memfd_create('retained-reference-tetragon')
   try:
    os.write(fd,blob.read_bytes());os.lseek(fd,0,os.SEEK_SET)
    q=subprocess.run(['objdump','-D','-b','binary','-m','i386:x86-64','--no-show-raw-insn',f'/proc/self/fd/{fd}'],pass_fds=(fd,),stdin=subprocess.DEVNULL,capture_output=True,text=True);assert q.returncode==0,q.stderr
   finally:os.close(fd)
   (D/(key+'.dis')).write_text(q.stdout);row['blob']=seal(blob);row['identical_to_retained_nov26_blob']=blob.read_bytes()==(CACHE/(key+'.blob.bin')).read_bytes()
  for x in inputs:assert seal(Path(x['path']))==x
  r['rows'].append(row);save()
 assert seal(LINK)==r['linker'];r.update(status='complete',all_links_succeeded=all(x['returncode']==0 for x in r['rows']))
except Exception:r.update(status='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps(r),flush=True)
raise SystemExit(0 if r['status']=='complete' and r['all_links_succeeded'] else 1)
