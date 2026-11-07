from pathlib import Path
import sys,subprocess,json,hashlib,shutil,importlib.util,tarfile
root=Path(__file__).resolve().parents[5];build=Path(sys.argv[1]);out=Path(sys.argv[2]);build.mkdir(parents=True,exist_ok=True)
producer=root/'kprog/fidelity/build-lea-final-published/source'
sys.path.insert(0,str(producer/'kprog/x86/micro-prog'))
p=producer/'kprog/x86/micro-prog/generate_micro_sim_proofs.py'
spec=importlib.util.spec_from_file_location('lea_micro_generator',p);gen=importlib.util.module_from_spec(spec);sys.modules[spec.name]=gen;spec.loader.exec_module(gen)
sys.path.insert(0,str(producer/'kprog/fidelity'));from tcb import includes,imports
gen.STAGE2_PROGRAMS=root/'kprog/test'
snapshot=build/'snapshot'
for path in includes(producer/'kprog/x86/x86_sim_local_bpf.h')|imports(p):
 dest=snapshot/path.relative_to(producer);dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(path,dest)
rows=[]
for label,config,source_dir in [('positive',root/'micro/config/micro_pure_jit.yaml',root/'micro/programs'),('negative',root/'kprog/test/kprog_negative_stage2.yaml',root/'kprog/test')]:
 inputs=build/label/'native-link';sources=build/label/'sources';inputs.mkdir(parents=True,exist_ok=True);sources.mkdir(parents=True,exist_ok=True)
 for bench in gen.load_benches(config):
  original=root/'kprog/x86/micro-prog/build/native-link'/(bench.name+'.proof.o')
  if not original.is_file():raise FileNotFoundError(original)
  shutil.copyfile(original,inputs/original.name)
  path=gen.write_one(bench,source_dir,sources,inputs)
  helper=root/'kprog/test/include/native_helpers.h'
  # Only the BPF branch is compiled; its quoted native common.h include is inactive.
  dest=snapshot/helper.relative_to(root);dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(helper,dest)
  text=path.read_text();text=text.replace('#include "../x86_sim_local_bpf.h"','#include "'+str(snapshot/'kprog/x86/x86_sim_local_bpf.h')+'"')
  text=text.replace('#include "../../test/include/native_helpers.h"','#include "'+str(snapshot/'kprog/test/include/native_helpers.h')+'"');path.write_text(text)
  obj=path.with_suffix('.o');command=['clang','-g','-O3','-target','bpf','-mllvm','-bpf-stack-size=4096','-D__TARGET_ARCH_x86','-I'+str(root/'vendor/libbpf/include/uapi'),'-I'+str(root/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu','-c',str(path),'-o',str(obj)]
  run=subprocess.run(command,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT);path.with_suffix('.log').write_text(run.stdout)
  rows.append(dict(name=bench.name,suite=label,command=command,returncode=run.returncode,native_proof_sha256=hashlib.sha256(original.read_bytes()).hexdigest(),source_sha256=hashlib.sha256(path.read_bytes()).hexdigest()))
  (out/'micro-build.json').write_text(json.dumps(rows,indent=2)+'\n');print(label,bench.name,run.returncode,flush=True)
assert sum(r['suite']=='positive' for r in rows)==29
with tarfile.open(out/'micro-inputs-source-objects.tar.gz','w:gz') as t:t.add(build,arcname='micro')
raise SystemExit(int(any(r['returncode'] for r in rows)))
