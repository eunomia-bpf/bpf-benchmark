from pathlib import Path
import hashlib,importlib.util,json,shutil,subprocess,sys
ROOT=Path('/workspaces/repository');BUILD=ROOT/'kprog/fidelity/build-sp-micro-paired';OUT=ROOT/'kprog/results/kprog_fidelity_20261107/negative/x86-sp-micro-paired';BUILD.mkdir(parents=True,exist_ok=True);OUT.mkdir(parents=True,exist_ok=True)
if sys.argv[1]=='build':
 rows=[]
 for phase,prefix in [('before','build-sp-entry-replay'),('candidate','build-sp-v2e')]:
  source=ROOT/('kprog/fidelity/'+prefix+'/source');p=source/'kprog/x86/micro-prog/generate_micro_sim_proofs.py';sys.path.insert(0,str(p.parent))
  spec=importlib.util.spec_from_file_location('sp_micro_'+phase,p);gen=importlib.util.module_from_spec(spec);sys.modules[spec.name]=gen;spec.loader.exec_module(gen);gen.STAGE2_PROGRAMS=ROOT/'kprog/test'
  inputs=BUILD/phase/'native-link';dest=BUILD/phase/'proofs';inputs.mkdir(parents=True,exist_ok=True);dest.mkdir(parents=True,exist_ok=True)
  for bench in gen.load_benches(ROOT/'micro/config/micro_pure_jit.yaml'):
   original=ROOT/'kprog/x86/micro-prog/build/native-link'/(bench.name+'.proof.o')
   shutil.copyfile(original,inputs/original.name);path=gen.write_one(bench,ROOT/'micro/programs',dest,inputs)
   text=path.read_text().replace('#include "../x86_sim_local_bpf.h"','#include "'+str(source/'kprog/x86/x86_sim_local_bpf.h')+'"').replace('#include "../../test/include/native_helpers.h"','#include "'+str(source/'kprog/test/include/native_helpers.h')+'"');path.write_text(text)
   obj=path.with_suffix('.o');command=['clang-18','-g','-O3','-target','bpf','-mllvm','-bpf-stack-size=4096','-D__TARGET_ARCH_x86','-I'+str(ROOT/'vendor/libbpf/include/uapi'),'-I'+str(ROOT/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu','-c',str(path),'-o',str(obj)]
   done=subprocess.run(command,stdout=subprocess.PIPE,stderr=subprocess.STDOUT);path.with_suffix('.compile.log').write_bytes(done.stdout)
   rows.append(dict(phase=phase,name=bench.name,object=str(obj),source=str(path),compile_returncode=done.returncode,compile_command=command,native_proof_sha256=hashlib.sha256(original.read_bytes()).hexdigest()))
   (OUT/'build.json').write_text(json.dumps(rows,indent=2)+'\n');print(phase,bench.name,'compile',done.returncode,flush=True)
 assert len(rows)==58
 if any(row['compile_returncode'] for row in rows):raise SystemExit(1)
 shutil.copyfile(ROOT/'kprog/loader/target/debug/reversesim-loader',BUILD/'loader');(BUILD/'loader').chmod(0o755)
else:
 rows=json.loads((OUT/'build.json').read_text())
 for row in rows:
  command=[str(BUILD/'loader'),'--object',row['object'],'--program',row['name']+'_x86_sim_xdp','--load-only']
  done=subprocess.run(command,stdout=subprocess.PIPE,stderr=subprocess.STDOUT);(OUT/(row['phase']+'-'+row['name']+'.log')).write_bytes(done.stdout)
  row.update(load_command=command,load_returncode=done.returncode);(OUT/'loads.json').write_text(json.dumps(rows,indent=2)+'\n');print(row['phase'],row['name'],'load',done.returncode,flush=True)
 before={row['name']:row['load_returncode'] for row in rows if row['phase']=='before'}
 after={row['name']:row['load_returncode'] for row in rows if row['phase']=='candidate'}
 print('before',before,'candidate',after,flush=True)
 if before!=after:raise SystemExit(1)
