"""Paired unchanged micro inputs: published header versus private numeric header."""
from pathlib import Path
import importlib.util,json,shutil,subprocess,sys,tarfile
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;STATE=Path('/workspaces/.agent-state/kprog-lanes/C/sp-entry-source');BUILD=STATE/'positive'
sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'));p=ROOT/'kprog/x86/micro-prog/generate_micro_sim_proofs.py'
spec=importlib.util.spec_from_file_location('positive_gen',p);gen=importlib.util.module_from_spec(spec);sys.modules[spec.name]=gen;spec.loader.exec_module(gen);gen.STAGE2_PROGRAMS=ROOT/'kprog/test'
rows=[]
for phase in ('before','candidate'):
 out=BUILD/phase;out.mkdir(parents=True);snap=out/'snapshot'
 shutil.copytree(STATE/'kprog',snap/'kprog',ignore=shutil.ignore_patterns('negative','positive'))
 shutil.copytree(STATE/'kinsn',snap/'kinsn')
 if phase=='before':shutil.copyfile(STATE/'before.h',snap/'kprog/x86/x86_sim_local_bpf.h')
 for bench in gen.load_benches(ROOT/'micro/config/micro_pure_jit.yaml'):
  path=gen.write_one(bench,ROOT/'micro/programs',out,ROOT/'kprog/x86/micro-prog/build/native-link')
  s=path.read_text().replace('#include "../x86_sim_local_bpf.h"','#include "'+str(snap/'kprog/x86/x86_sim_local_bpf.h')+'"')
  s=s.replace('#include "../../test/include/native_helpers.h"','#include "'+str(ROOT/'kprog/test/include/native_helpers.h')+'"');path.write_text(s)
  cmd=['clang-18','-g','-O3','-target','bpf','-mllvm','-bpf-stack-size=4096','-D__TARGET_ARCH_x86','-I'+str(ROOT/'vendor/libbpf/include/uapi'),'-I'+str(ROOT/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu','-c',str(path),'-o',str(path.with_suffix('.o'))]
  r=subprocess.run(cmd,capture_output=True,text=True);path.with_suffix('.compile.log').write_text(r.stdout+r.stderr)
  rows.append(dict(phase=phase,name=bench.name,source=str(path),object=str(path.with_suffix('.o')),command=cmd,returncode=r.returncode))
  (HERE/'positive-build.json').write_text(json.dumps(rows,indent=2)+'\n');print(phase,bench.name,r.returncode,flush=True)
with tarfile.open(HERE/'positive-inputs.tar.gz','w:gz') as t:t.add(BUILD,arcname='positive')
raise SystemExit(int(any(r['returncode'] for r in rows)))
