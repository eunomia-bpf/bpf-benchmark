"""Build/test the canonical shared linker, compare identical real proof/plan inputs before/after."""
from pathlib import Path
from elftools.elf.elffile import ELFFile
import datetime,fcntl,hashlib,io,json,os,resource,struct,subprocess,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
LINK=ROOT/'kprog/x86/native_lab/native_link/target/release/native-link'
MANIFEST=ROOT/'kprog/x86/native_lab/native_link/Cargo.toml'
CACHE=ROOT/'kprog/results/cmov-branches-20261126/post-branch-profiles-20261126T145836Z/tetragon-profile/linkcache/native_kernel_link_cache'
os.sched_setaffinity(0,{16,18});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def seal(p):
 b=p.read_bytes();return dict(path=str(p),bytes=len(b),sha256=hashlib.sha256(b).hexdigest())
r=dict(pid=os.getpid(),started_utc=now(),status='running',phase='preflight',scope='Common x86 CFG map identity correction; canonical linker build/tests and identical retained Nov26 proofs/plans. No app compilation, guest, image, timing, kernel or benchmark change.',sources=[seal(ROOT/'kprog/x86/native_lab/native_link/src/x86.rs'),seal(Path(__file__))],commands=[],replays=[])
D=OUT/'cfg-join';D.mkdir(exist_ok=False)
def save():(OUT/'cfg-join-controller.json').write_text(json.dumps(r,indent=2)+'\n')
def command(args,log):
 with (D/log).open('w') as f:p=subprocess.run(args,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT)
 x=dict(command=args,returncode=p.returncode,log=seal(D/log));r['commands'].append(x);save()
 if p.returncode:raise RuntimeError(x)
def replay(label):
 rows=[]
 for key in ['45ba49203d276b52','5be2ee6f95ee536b','a751a5ae32d71696','e700f906b8500cb3']:
  proof=CACHE/(key+'.proof.o');plans=list(CACHE.glob(key+'*.link-plan.json'));assert len(plans)==1;plan=plans[0]
  data=proof.read_bytes();e=ELFFile(io.BytesIO(data));syms=e.get_section_by_name('.symtab')
  entry=next(s.name for s in syms.iter_symbols() if s['st_info']['type']=='STT_FUNC' and isinstance(s['st_shndx'],int))
  stem=D/(label+'-'+key)
  args=[str(LINK),'--input',str(proof),'--symbol',entry,'--mode','kernel','--output',str(stem)+'.blob.bin','--output-relocs',str(stem)+'.relocs.bin','--output-map-patches',str(stem)+'.maps.tsv','--output-abi',str(stem)+'.abi.tsv','--link-plan',str(plan)]
  command(args,label+'-'+key+'.log')
  raw=Path(str(stem)+'.relocs.bin').read_bytes();assert len(raw)%16==0
  relocs=[dict(offset=o,kind=k,target=a) for o,k,a in struct.iter_unpack('<IIQ',raw)]
  j=json.loads(plan.read_text());generic=next(h['addr'] for h in j['helpers'] if h['name']=='bpf_map_lookup_elem')
  row=dict(label=label,key=key,entry=entry,proof=seal(proof),plan=seal(plan),blob=seal(Path(str(stem)+'.blob.bin')),relocs=relocs,generic_lookup_calls=sum(x['kind']==1 and x['target']==generic for x in relocs))
  rows.append(row)
 return rows
try:
 save()
 with open('/workspaces/.agent-state/kprog-lanes/locks/image','w') as lock:
  fcntl.flock(lock,fcntl.LOCK_EX)
  r['before_linker']=seal(LINK);r['phase']='before-real-proof-replay';save();before=replay('before');r['replays']+=before
  r['phase']='cargo-test';save();command(['cargo','test','--release','-j','2','--manifest-path',str(MANIFEST)],'cargo-test.log')
  r['phase']='canonical-release-build';save();command(['cargo','build','--release','-j','2','--manifest-path',str(MANIFEST)],'cargo-build.log')
  r['after_linker']=seal(LINK);r['phase']='after-real-proof-replay';save();after=replay('after');r['replays']+=after
  for old,new in zip(before,after):
   assert old['proof']==new['proof'] and old['plan']==new['plan']
   if old['entry']=='generic_kprobe_event':
    assert old['generic_lookup_calls']==2 and new['generic_lookup_calls']==0,(old,new)
    assert len(old['relocs'])==len(new['relocs'])==7,(old,new)
  for x in r['sources']:assert seal(Path(x['path']))==x
  r.update(status='complete',phase='passed')
except Exception:r.update(status='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps(r),flush=True)
raise SystemExit(0 if r['status']=='complete' else 1)
