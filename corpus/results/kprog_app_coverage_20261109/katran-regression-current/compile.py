from pathlib import Path
import json,sys,subprocess,hashlib,traceback,resource
resource.setrlimit(resource.RLIMIT_CORE,(0,0))
R=Path('/workspaces/repository');G=Path('/var/tmp/kprog-tmp/C/katran-regression-current');I=Path('/var/tmp/kprog-tmp/C/xdp-adjust-head-caller-frame/actual-inputs/18');sys.path.insert(0,str(R/'kprog/x86'));from trusted_specializer import specialize
row=dict(entry=(I/'kernel.entry').read_text().strip(),native_sha256=hashlib.sha256((I/'kernel.native.o').read_bytes()).hexdigest(),model_sha256=hashlib.sha256((R/'kprog/x86/x86_sim_local_bpf.h').read_bytes()).hexdigest())
try:row['result']=specialize((I/'kernel.native.o').read_bytes(),row['entry'],json.loads((I/'generation.metadata.json').read_text()),G/'generated',Path('/var/tmp/kprog-tmp/C/tail-helper-reaching-frame/native-link'));row['status']='compiled'
except BaseException as e:row.update(status='diagnostic',error=str(e),traceback=traceback.format_exc())
(G/'compiled.json').write_text(json.dumps(row,indent=2)+'\n');print(row['status'],row.get('error'),flush=True)
