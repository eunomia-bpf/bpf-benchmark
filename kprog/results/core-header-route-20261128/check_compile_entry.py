"""Check original relative compiler argv and libbpf-poisoned scalar accesses."""
from pathlib import Path
import datetime,fcntl,json,os,re,resource,shlex,subprocess,sys,traceback
ROOT=Path('/workspaces/repository');V=ROOT/'vendor/bpf';OUT=Path(__file__).resolve().parent
NAME=sys.argv[1] if len(sys.argv)>1 else 'compile-entry';D=OUT/NAME;D.mkdir(exist_ok=False)
os.sched_setaffinity(0,{16,18});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
now=lambda:datetime.datetime.now(datetime.timezone.utc).isoformat()
r=dict(pid=os.getpid(),started_utc=now(),status='running',cases=[],source_revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip())
def save():(OUT/(NAME+'-controller.json')).write_text(json.dumps(r,indent=2)+'\n')
def run(cmd,stem,success=True):
 with (D/(stem+'.stdout')).open('w') as stdout,(D/(stem+'.stderr')).open('w') as stderr:
  p=subprocess.run(cmd,cwd=V,stdin=subprocess.DEVNULL,stdout=stdout,stderr=stderr)
 item=dict(command=cmd,returncode=p.returncode,stdout=str(D/(stem+'.stdout')),stderr=str(D/(stem+'.stderr')))
 if success and p.returncode:raise RuntimeError(item)
 return item
try:
 save()
 with open('/workspaces/.agent-state/kprog-lanes/locks/image','a') as image:
  fcntl.flock(image,fcntl.LOCK_SH)
  oracle=D/'poison.bpf.o';poison=OUT/'input/poison.c'
  run(['clang-18','-target','bpf','-O2','-g','-DHEADER_ORACLE_BPF','-c',str(poison),'-o',str(oracle)],'poison-bpf')
  old=json.loads((OUT/'source-extension-final-review.json').read_text())
  for arch in ['x86','arm64']:
   case=dict(arch=arch,status='running');r['cases'].append(case);save()
   try:
    target=Path('/workspaces/.agent-state/kprog-ck')/('build-'+arch)/'vmlinux'
    read=run(['make','-s','--no-print-directory','-C',str(V),'ARCH='+arch,'--eval=__perf_flags:;@echo $(NATIVE_CFLAGS)','__perf_flags'],arch+'-flags')
    flags=shlex.split(Path(read['stdout']).read_text());flags+=['-I'+str(V)]
    prefix=['python3',str(V/'core-answers.py'),'--btf',str(target),'--bpftool',str(ROOT/'vendor/build/x86/bpftool/bin/bpftool'),'--compile']
    expected=next(c['expected'] for c in old['fixture_cases'] if c['arch']==arch)
    forms=[]
    for form in ['relative','dot-relative','absolute']:
     source=OUT/'input/queries.c';arg=os.path.relpath(source,V) if form=='relative' else str(source)
     if form=='dot-relative':arg='./'+os.path.relpath(source,V)
     ir=D/(arch+'-'+form+'.ll')
     result=run([*prefix,*flags,'-S','-emit-llvm','-o',str(ir),arg],arch+'-'+form)
     text=ir.read_text();assert not re.search(r'\bcall\b[^\n]*@__kprog_(?:core_unanswered|scan)',text)
     actual={}
     for name,value in expected.items():
      if name=='ancestor_index':continue
      body=re.search(r'define[^\n]*@'+re.escape(name)+r'\([^\n]*\)[^{]*\{(.*?)\n\}',text,re.S)
      ret=re.search(r'\bret i64 (-?\d+)\b',body[1]);assert ret and int(ret[1])==value,(name,value)
      actual[name]=int(ret[1])
     forms.append(dict(form=form,compile=result,constants=actual,no_unanswered_calls=True))
    case['source_forms']=forms
    query=run([str(ROOT/'kprog/results/native-ebpf-alignment-20261128/core-field-predicates/core-query'),str(oracle),str(target)],arch+'-poison-oracle')
    rows=json.loads(Path(query['stdout']).read_text());assert rows['errors']==0
    live=[x for x in rows['rows'] if x['section']=='query/live_poison'];assert live and all(x['poison'] for x in live)
    obj=D/(arch+'-poison.native.o')
    case['poison_compile']=run([*prefix,*flags,'-o',str(obj),str(poison)],arch+'-poison-native')
    links=[];tool=ROOT/'kprog/x86/native_lab/native_link/target/release/native-link'
    for symbol in ['live_poison','dead_poison']:
     proof=D/(arch+'-'+symbol+'.proof.o')
     prepared=run([str(tool),'--mode','proof','--input',str(obj),'--symbol',symbol,'--output',str(proof)],arch+'-'+symbol+'-proof')
     result=run([str(tool),'--input',str(proof),'--symbol',symbol,'--output',str(D/(arch+'-'+symbol+'.bin'))],arch+'-'+symbol,success=False)
     error=Path(result['stderr']).read_text()
     if symbol=='live_poison':assert result['returncode']!=0 and '__kprog_core_poisoned' in error,error
     else:assert result['returncode']==0,error
     links.append(dict(symbol=symbol,proof=prepared,**result))
    case.update(status='complete',original_live_poison=True,links=links)
   except Exception:case.update(status='failed',exception=traceback.format_exc())
   save()
  r.update(status='complete',all_cases_pass=all(c['status']=='complete' for c in r['cases']))
except Exception:r.update(status='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps(r),flush=True)
raise SystemExit(0 if r.get('all_cases_pass') else 1)
