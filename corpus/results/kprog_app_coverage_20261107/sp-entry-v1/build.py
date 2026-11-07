"""Retain the full negative suite and overlay only the frozen private SP header."""
import json,subprocess,sys,shutil,tarfile,hashlib
from pathlib import Path
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent
STATE=Path('/workspaces/.agent-state/kprog-lanes/C/sp-entry-source');BUILD=STATE/'negative'
sys.path.insert(0,str(ROOT/'kprog/fidelity'));import negative
negative.build('x86',BUILD)
shutil.copyfile(BUILD/'build.json',HERE/'original-build.json')
header=BUILD/'snapshot/kprog/x86/x86_sim_local_bpf.h';shutil.copyfile(STATE/'kprog/x86/x86_sim_local_bpf.h',header)
inc=BUILD/'snapshot/kinsn/module/include/native_lab_input.h';inc.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(STATE/'kinsn/module/include/native_lab_input.h',inc)
manifest=json.loads((BUILD/'build.json').read_text())
for row in manifest['cases']:
 path=BUILD/(row['name']+'.bpf.c')
 if not path.exists():continue
 cmd=['clang-18','-g','-O2','-target','bpf','-mllvm','-bpf-stack-size=4096','-D__TARGET_ARCH_x86','-I'+str(ROOT/'vendor/libbpf/include/uapi'),'-I'+str(ROOT/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu','-c',str(path),'-o',str(path.with_suffix('.o'))]
 p=subprocess.run(cmd,capture_output=True,text=True);(BUILD/(row['name']+'.candidate-compile.log')).write_text(p.stdout+p.stderr)
 row.update(stage='generated' if p.returncode==0 else 'compiler_rejected',command=cmd,returncode=p.returncode,message=p.stdout+p.stderr)
 print(row['name'],row['stage'],flush=True)
(BUILD/'build.json').write_text(json.dumps(manifest,indent=2)+'\n')
(HERE/'build.json').write_text(json.dumps(manifest,indent=2)+'\n')
with tarfile.open(HERE/'frozen-inputs.tar.gz','w:gz') as t:
 t.add(BUILD,arcname='negative');t.add(STATE/'base-head.txt',arcname='base-head.txt')
 t.add(STATE/'before.h',arcname='before.h')
