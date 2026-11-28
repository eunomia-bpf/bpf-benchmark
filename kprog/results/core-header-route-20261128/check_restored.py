"""Compare the restored header route with actual libbpf CO-RE relocation on both kernels."""
from pathlib import Path
import datetime,fcntl,hashlib,json,os,re,resource,subprocess,sys,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;VENDOR=ROOT/'vendor/bpf'
QUERY=ROOT/'kprog/results/native-ebpf-alignment-20261128/core-field-predicates/core-query'
os.sched_setaffinity(0,{16,18});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def seal(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1024*1024),b''):h.update(b)
 return dict(path=str(p),bytes=p.stat().st_size,sha256=h.hexdigest())
r=dict(pid=os.getpid(),started_utc=now(),status='running',scope='Restored historical CO-RE generator/header baseline; SAME input native constants vs real BPF ELF resolved by existing libbpf oracle against each actual kernel. No app/P/Make/flags/runtime/image changes, no C rewrite.',sources=[seal(VENDOR/'core-answers.py'),seal(VENDOR/'core-compat.h'),seal(VENDOR/'native-helpers.h'),seal(OUT/'input/queries.c'),seal(Path(__file__)),seal(QUERY)],cases=[])
label=sys.argv[1] if len(sys.argv)==2 else 'restored'
D=OUT/(label+'-baseline');D.mkdir(exist_ok=False)
def save():(OUT/(label+'-controller.json')).write_text(json.dumps(r,indent=2)+'\n')
def run(args,stem,cwd=ROOT,env=None):
 p=subprocess.run(args,cwd=cwd,env=env,stdin=subprocess.DEVNULL,capture_output=True,text=True)
 (D/(stem+'.stdout')).write_text(p.stdout);(D/(stem+'.stderr')).write_text(p.stderr)
 if p.returncode:raise RuntimeError(dict(command=args,returncode=p.returncode,stdout=p.stdout[-1500:],stderr=p.stderr[-3000:]))
 return p.stdout
try:
 save()
 with open('/workspaces/.agent-state/kprog-lanes/locks/image','w') as lock:
  fcntl.flock(lock,fcntl.LOCK_SH)
  source=OUT/'input/queries.c';bpf=D/'oracle.bpf.o'
  run(['clang-18','-target','bpf','-O2','-g','-DHEADER_ORACLE_BPF','-c',str(source),'-o',str(bpf)],'build-oracle')
  for arch in ['x86','arm64']:
   case=dict(arch=arch,status='running');r['cases'].append(case);save()
   try:
    target=Path('/workspaces/.agent-state/kprog-ck')/('build-'+arch)/'vmlinux';case['target']=seal(target)
    oracle=run([str(QUERY),str(bpf),str(target)],arch+'-oracle')
    rows=json.loads(oracle);assert rows['errors']==0 and rows['rows']
    expected={}
    for row in rows['rows']:
     assert row['status']==0 and not row['poison']
     name=row['section'].split('/')[-1]
     if row['kind']==0:expected[name]=expected.get(name,0)+row['new_val']
     elif row['kind'] in [2,8,10,11]:expected[name]=row['new_val']
     else:raise RuntimeError(('Unexpected relocation kind',row))
    flags=['-I'+str(VENDOR)]
    if arch=='arm64':flags+=['--target=aarch64-linux-gnu']
    temp=D/(arch+'-tmp');temp.mkdir();env=dict(os.environ,TMPDIR=str(temp))
    table=D/(arch+'-answers.h');report=D/(arch+'-answers.json')
    run(['python3',str(VENDOR/'core-answers.py'),'--btf',str(target),'--bpftool',str(ROOT/'vendor/build/x86/bpftool/bin/bpftool'),'--clang','clang-18','--cflags='+' '.join(flags),'--out',str(table),'--report',str(report),str(OUT/'input')],arch+'-generate',VENDOR,env)
    ir=D/(arch+'-native.ll')
    run(['clang-18',*flags,'-O3','-S','-emit-llvm','-Wno-unknown-attributes','-D__KPROG_CORE_ANSWERS="'+str(table)+'"',str(source),'-o',str(ir)],arch+'-native-ir')
    text=ir.read_text();actual={}
    for name in expected:
     m=re.search(r'define[^\n]*@'+re.escape(name)+r'\([^\n]*\)[^{]*\{(.*?)\n\}',text,re.S);assert m,name
     value=re.search(r'\bret i64 (-?\d+)\b',m[1]);actual[name]=int(value[1]) if value else 'not folded'
    case.update(status='complete',expected=expected,actual=actual,mismatches={name:dict(expected=v,actual=actual[name]) for name,v in expected.items() if actual[name]!=v},oracle=seal(bpf),table=seal(table),report=seal(report),native_ir=seal(ir),target_unchanged=seal(target)==case['target'])
   except Exception:case.update(status='failed',exception=traceback.format_exc())
   save()
  for x in r['sources']:assert seal(Path(x['path']))==x
  r.update(status='complete',all_architectures_match=all(c['status']=='complete' and not c['mismatches'] and c['target_unchanged'] for c in r['cases']))
except Exception:r.update(status='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps(r,indent=2),flush=True)
raise SystemExit(0 if r['status']=='complete' and r['all_architectures_match'] else 1)
