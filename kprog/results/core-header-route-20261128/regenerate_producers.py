"""Regenerate the one native P/stage per architecture through the common header entry."""
from pathlib import Path
import datetime,fcntl,hashlib,json,os,resource,subprocess,time,traceback
from elftools.elf.elffile import ELFFile
ROOT=Path('/workspaces/repository');V=ROOT/'vendor/bpf';OUT=Path(__file__).resolve().parent
os.sched_setaffinity(0,{16,18});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
D=OUT/'producer-regeneration';D.mkdir(exist_ok=False)
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def seal(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1024*1024),b''):h.update(b)
 return dict(path=str(p),bytes=p.stat().st_size,sha256=h.hexdigest())
def pin():return subprocess.check_output(['git','-C',str(ROOT/'vendor/repos/opentelemetry-ebpf-profiler'),'rev-parse','HEAD'],text=True).strip()
def objects(folder):
 result={}
 for p in sorted(folder.rglob('*.native.o')):
  item=seal(p)
  try:
   with p.open('rb') as f:
    elf=ELFFile(f);item['executable_sections']=[dict(name=s.name,bytes=s['sh_size'],sha256=hashlib.sha256(s.data()).hexdigest()) for s in elf.iter_sections() if s['sh_flags']&4]
  except Exception:item['elf_error']=traceback.format_exc()
  result[str(p)]=item
 return result
guards=[ROOT/p for p in ['vendor/bpf/Makefile','vendor/bpf/core-answers.py','vendor/bpf/core-compat.h','vendor/bpf/native_compat.h','vendor/bpf/native-helpers.h','kprog/perf/one-image/Makefile','runner/mk/build.mk','runner/containers/runner-runtime.Dockerfile']]
guards += [p for folder in ['runner/libs','corpus/config','corpus/configs','micro/configs','e2e'] if (ROOT/folder).exists() for p in sorted((ROOT/folder).rglob('*')) if p.is_file() and p.suffix in ('.py','.json','.yaml','.yml','.toml','.sh')]
r=dict(pid=os.getpid(),started_utc=now(),status='running',scope='All six native-artifacts producers, existing flags/default target lists, one canonical P/stage per architecture; no image or benchmark/timing run. x86 then arm64, make -k -j2, CPU16/18/48GiBAS.',inputs=[],otel_pin=None,architectures=[])
def save():(OUT/'producer-regeneration-controller.json').write_text(json.dumps(r,indent=2)+'\n')
def run(args,stem):
 with (D/(stem+'.stdout')).open('w') as stdout,(D/(stem+'.stderr')).open('w') as stderr:
  p=subprocess.run(args,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=stdout,stderr=stderr)
 return dict(command=args,returncode=p.returncode,stdout=seal(D/(stem+'.stdout')),stderr=seal(D/(stem+'.stderr')))
try:
 r['inputs']=[seal(p) for p in guards+[Path(__file__)]];r['otel_pin']=pin()
 assert r['otel_pin'].startswith('2689a430'),r['otel_pin']
 save()
 with open('/workspaces/.agent-state/kprog-lanes/locks/image','w') as image,open('/workspaces/.agent-state/kprog-lanes/locks/build-c','w') as build:
  fcntl.flock(image,fcntl.LOCK_EX);fcntl.flock(build,fcntl.LOCK_EX)
  r['locks_acquired_utc']=now();save()
  for arch in ['x86','arm64']:
   kernel=Path('/workspaces/.agent-state/kprog-ck')/('build-'+arch)
   release=(kernel/'include/config/kernel.release').read_text().strip()
   flags=['ARCH='+arch,'KERNEL_RELEASE='+release,'VMLINUX_BTF='+str(kernel/'vmlinux')]
   native=ROOT/'vendor/build/native-bpf'/arch/release/'native'
   stage=ROOT/'vendor/build/native-bpf'/arch/'stage'
   case=dict(arch=arch,status='running',kernel=seal(kernel/'vmlinux'),native=str(native),stage=str(stage),before_objects=objects(native),before_stage=objects(stage))
   r['architectures'].append(case);save()
   case['build']=run(['make','--keep-going','-j2','-C',str(V),*flags,'native-artifacts'],arch+'-build')
   case['after_objects']=objects(native);case['after_stage']=objects(stage)
   tables=[];comparisons=[]
   for p in sorted(native.rglob('*.native.o.core.json')):
    table=seal(p)
    try:rows=json.loads(p.read_text());table.update(queries=len(rows),query_kinds=sorted({x['kind'] for x in rows}))
    except Exception:table['parse_error']=traceback.format_exc();tables.append(table);continue
    tables.append(table)
    obj=str(p)[:-len('.core.json')]
    before=case['before_objects'].get(obj);after=case['after_objects'].get(obj)
    if not rows and before and after and 'executable_sections' in before and 'executable_sections' in after:
     comparisons.append(dict(path=obj,query_count=0,executable_sections_equal=before['executable_sections']==after['executable_sections']))
   case.update(status='complete',tables=tables,zero_query_executable_comparisons=comparisons,kernel_unchanged=seal(kernel/'vmlinux')==case['kernel'])
   save()
  assert pin()==r['otel_pin']
  for x in r['inputs']:assert seal(Path(x['path']))==x,x['path']
  r.update(status='complete',all_architectures_build=all(c['build']['returncode']==0 and c['kernel_unchanged'] for c in r['architectures']))
except Exception:r.update(status='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps({k:v for k,v in r.items() if k not in ['inputs','architectures']},indent=2),flush=True)
raise SystemExit(0 if r['status']=='complete' and r['all_architectures_build'] else 1)
