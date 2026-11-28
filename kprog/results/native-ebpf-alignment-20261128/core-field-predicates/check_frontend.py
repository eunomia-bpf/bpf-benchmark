#!/usr/bin/env python3
"""Build the shared frontend once and check real CO-RE bug witnesses on both BTFS."""
from pathlib import Path
import datetime,hashlib,json,os,re,subprocess,traceback
ROOT=Path('/workspaces/repository');BASE=Path(__file__).resolve().parent;OUT=BASE/'frontend-check'
SOURCE=ROOT/'kprog/x86/native_lab/native_link/native_core_frontend.cpp'
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def seal(p):return dict(path=str(p),size=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest())
def write(c):
 q=OUT/'controller.tmp';q.write_text(json.dumps(c,indent=2)+'\n');q.replace(OUT/'controller.json')
def main():
 OUT.mkdir(exist_ok=True);c=dict(pid=os.getpid(),started=now(),status='running',latest_resume='COORDINATOR2026-11-28T14:21Z',commands=[]);write(c)
 def run(label,args):
  out=OUT/(label+'.stdout');err=OUT/(label+'.stderr')
  with out.open('wb') as of,err.open('wb') as ef:r=subprocess.run(args,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=of,stderr=ef)
  c['commands'].append(dict(label=label,args=args,returncode=r.returncode,stdout=seal(out),stderr=seal(err)));write(c)
  if r.returncode:raise RuntimeError(f'{label} returned {r.returncode}; preserve actual stderr')
 try:
  c['inputs']=[seal(p) for p in [SOURCE,BASE/'marker-contract.c',BASE/'check_frontend.py',ROOT/'runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a',Path('/usr/lib/llvm-18/lib/libclang-cpp.so.18.1')]]
  exe=ROOT/'vendor/build/native-core-frontend'
  args=['clang++-18','-std=c++17','-O1','-I/usr/lib/llvm-18/include','-Ivendor/libbpf/include/uapi','-Ivendor/libbpf/src',str(SOURCE),'runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a','/usr/lib/llvm-18/lib/libclang-cpp.so.18.1','-L/usr/lib/llvm-18/lib','-lLLVM-18','-Wl,-rpath,/usr/lib/llvm-18/lib','-lelf','-lz','-o',str(exe)]
  run('build',args);c['executable']=seal(exe)
  # Compile the same witness with BPF's real builtins as an independent
  # source-BTF oracle; the frontend must agree despite assigning other IDs.
  fixture=(BASE/'marker-contract.c').read_text().replace('annotate("kprog_core")','preserve_access_index')
  fixture='\n'.join(line for line in fixture.splitlines() if not line.startswith('extern '))
  macros='#define __native_core_field_info(k,x) __builtin_preserve_field_info(x,k)\n#define __native_core_type_info(k,p) __builtin_preserve_type_info(*(p),((k)==12?2:(k)-8))\n#define __native_core_enum_info(k,p,v) __builtin_preserve_enum_value(*(__typeof__(*(p))*)(v),(k)-10)\n'
  oracle_source=OUT/'oracle.bpf.c';oracle_source.write_text(macros+fixture+'\n')
  oracle=OUT/'oracle.bpf.o'
  run('build-bpf-oracle',['clang-18','-target','bpf','-O2','-g','-c',str(oracle_source),'-o',str(oracle)])
  c['architectures']=[]
  for arch in ('x86','arm64'):
   target=Path('/workspaces/.agent-state/kprog-ck')/('build-'+arch)/'vmlinux';target_seal=seal(target)
   rewritten=OUT/(arch+'.rewritten.c');parse_args=['--target=aarch64-linux-gnu'] if arch=='arm64' else []
   run(arch+'-rewrite',[str(exe),str(target),str(BASE/'marker-contract.c'),str(rewritten),'--']+parse_args)
   records=[json.loads(line) for line in (OUT/(arch+'-rewrite.stdout')).read_text().splitlines()]
   run(arch+'-libbpf-oracle',[str(BASE/'core-query'),str(oracle),str(target)])
   expected=json.loads((OUT/(arch+'-libbpf-oracle.stdout')).read_text());assert expected['errors']==0 and expected['rows']
   for row in expected['rows']:
    key=(row['local_type'],row['access'],row['kind'])
    matching=[r for r in records if (r['type'],r['access'],r['kind'])==key]
    assert matching and {(r['new_val'],r['poison']) for r in matching}=={(row['new_val'],row['poison'])},(arch,key,matching,row)
   ir=OUT/(arch+'.ll')
   run(arch+'-native-ir',['clang-18']+parse_args+['-O3','-S','-emit-llvm','-Wno-unknown-attributes',str(rewritten),'-o',str(ir)])
   text=ir.read_text();assert '@__native_core_' not in text,'marker or poison survived native optimization'
   for fn,value in [('disk_field_exists',0),('old_pid_link_exists',0),('retprobe_exists',1),('retprobe_value',next(r['new_val'] for r in expected['rows'] if r['kind']==11))]:
    body=re.search(r'^define[^\n]*@'+fn+r'\([^\n]*\n(.*?)^}',text,re.M|re.S);assert body and re.search(r'ret i\d+ '+str(value)+r'\b',body[1]),(arch,fn)
   assert seal(target)==target_seal and seal(exe)==c['executable']
   c['architectures'].append(dict(arch=arch,target=target_seal,records=len(records),actual_BPF_oracle_records_matched=len(expected['rows']),bpf_oracle=seal(oracle),bpf_oracle_query=seal(OUT/(arch+'-libbpf-oracle.stdout')),rewritten=seal(rewritten),native_ir=seal(ir),all_native_marker_and_poison_calls_eliminated=True));write(c)
  c['inputs_unchanged']=all(seal(Path(x['path']))==x for x in c['inputs']);assert c['inputs_unchanged']
  c.update(status='complete',returncode=0)
 except Exception:c.update(status='failed',returncode=1,exception=traceback.format_exc())
 c['finished']=now();write(c);return c['returncode']
if __name__=='__main__':raise SystemExit(main())
