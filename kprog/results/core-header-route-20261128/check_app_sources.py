"""Use current producer flags on real affected translation units; write only diagnostic metadata/IR."""
from pathlib import Path
import datetime,fcntl,hashlib,json,os,re,resource,shlex,subprocess,sys,traceback
ROOT=Path('/workspaces/repository');V=ROOT/'vendor/bpf';OUT=Path(__file__).resolve().parent
os.sched_setaffinity(0,{16,18});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def seal(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1024*1024),b''):h.update(b)
 return dict(path=str(p),bytes=p.stat().st_size,sha256=h.hexdigest())
NAME=sys.argv[1] if len(sys.argv)>1 else 'real-source'
assert re.fullmatch(r'real-source(?:-[a-z0-9]+)*',NAME)
D=OUT/NAME;D.mkdir(exist_ok=False)
r=dict(pid=os.getpid(),started_utc=now(),status='running',scope='Readonly source-query/Clang-layout generation and diagnostic native IR for existing affected BCC/Tetragon units, both architectures. Flags read from unchanged producer Makefile; canonical P/stage/app/image/benchmark untouched.',inputs=[seal(p) for p in [V/'Makefile',V/'core-answers.py',V/'core-compat.h',V/'native_compat.h',V/'native-helpers.h',Path(__file__),OUT/'check_restored.py',OUT/'input/queries.c']],cases=[])
def save():(OUT/(NAME+'-controller.json')).write_text(json.dumps(r,indent=2)+'\n')
def run(args,stem,cwd=ROOT,env=None):
 with (D/(stem+'.stdout')).open('w') as stdout,(D/(stem+'.stderr')).open('w') as stderr:
  p=subprocess.run(args,cwd=cwd,env=env,stdin=subprocess.DEVNULL,stdout=stdout,stderr=stderr)
 result=dict(command=args,returncode=p.returncode,stdout=seal(D/(stem+'.stdout')),stderr=seal(D/(stem+'.stderr')))
 if p.returncode:raise RuntimeError(result)
 return result
try:
 save()
 with open('/workspaces/.agent-state/kprog-lanes/locks/image','w') as lock:
  fcntl.flock(lock,fcntl.LOCK_SH)
  for arch in ['x86','arm64']:
   result=run(['make','-s','--no-print-directory','-C',str(V),'ARCH='+arch,'--eval=__perf_read_flags:;@echo NATIVE=$(NATIVE_CFLAGS); echo SYS=$(SYS_INC); echo BPF_ARCH=$(BPF_ARCH)','__perf_read_flags'],arch+'-producer-flags')
   values=dict(line.split('=',1) for line in Path(result['stdout']['path']).read_text().splitlines() if '=' in line)
   native=shlex.split(values['NATIVE']);system=shlex.split(values['SYS']);assert values['BPF_ARCH']==arch
   for app in ['bcc','tetragon']:
    case=dict(arch=arch,app=app,status='running',producer_flags=result);r['cases'].append(case);save()
    try:
     target=Path('/workspaces/.agent-state/kprog-ck')/('build-'+arch)/'vmlinux'
     if app=='bcc':
      source=V/'bcc/libbpf-tools/biosnoop.bpf.c';header=V/('bcc/libbpf-tools/'+arch+'/vmlinux.h')
      flags=native+['-I'+str(V/'bcc/libbpf-tools'),'-I'+str(V/('bcc/libbpf-tools/'+arch)),'-I'+str(V/'bcc/src/cc/libbpf/include/uapi')]+system
     else:
      source=V/'tetragon/bpf/process/bpf_generic_kprobe.c';header=V/('tetragon/bpf/include/vmlinux_generated_'+arch+'.h')
      includes=['tetragon/bpf','tetragon/bpf/include','tetragon/bpf/lib','tetragon/bpf/libbpf','tetragon/bpf/process','tetragon/bpf/errmetrics']
      # Existing producer's v61 variant, not a new optimization or program choice.
      flags=native+['-fms-extensions','-DMICRO_NATIVE_TETRAGON','-D__TARGET_ARCH_'+arch]+['-I'+str(V/p) for p in includes]+system+['-D__LARGE_BPF_PROG','-D__V511_BPF_PROG','-D__V61_BPF_PROG']
     case['inputs']=[seal(p) for p in [source,header,target]];case['flags']=flags
     stem=arch+'-'+app;temp=D/(stem+'-tmp');temp.mkdir();env=dict(os.environ,TMPDIR=str(temp));table=D/(stem+'.h');report=D/(stem+'.json')
     case['generate']=run(['python3',str(V/'core-answers.py'),'--btf',str(target),'--bpftool',str(ROOT/'vendor/build/x86/bpftool/bin/bpftool'),'--clang','clang-18','--cflags='+shlex.join(flags),'--out',str(table),'--report',str(report),str(source)],stem+'-generate',V,env);save()
     ir=D/(stem+'.ll');case['native_ir_compile']=run(['clang-18',*flags,'-include',str(V/'core-compat.h'),'-D__KPROG_CORE_ANSWERS="'+str(table)+'"','-S','-emit-llvm',str(source),'-o',str(ir)],stem+'-native-ir',V,env)
     text=ir.read_text();case['unresolved_core_calls']=bool(re.search(r'\bcall\b[^\n]*@__kprog_(?:core_unanswered|scan)',text));assert not case['unresolved_core_calls']
     rows=json.load(open(report));case.update(status='complete',query_count=len(rows),query_kinds=sorted({x['kind'] for x in rows}),table=seal(table),report=seal(report),native_ir=seal(ir))
     for x in case['inputs']:assert seal(Path(x['path']))==x
    except Exception:case.update(status='failed',exception=traceback.format_exc())
    save()
  # A real typeof-qualified intermediate guards the same shared type rule.
  label=NAME+'-fixture'
  r['focused_fixture']=run(['python3',str(OUT/'check_restored.py'),label],label,env=dict(os.environ,TMPDIR=str(D)))
  focused=OUT/(label+'-controller.json')
  assert json.loads(focused.read_text())['all_architectures_match']
  r['focused_fixture_controller']=seal(focused)
  for x in r['inputs']:assert seal(Path(x['path']))==x
  r.update(status='complete',all_four_sources_compile=all(c['status']=='complete' for c in r['cases']))
except Exception:r.update(status='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps(r,indent=2),flush=True)
raise SystemExit(0 if r['status']=='complete' and r['all_four_sources_compile'] else 1)
