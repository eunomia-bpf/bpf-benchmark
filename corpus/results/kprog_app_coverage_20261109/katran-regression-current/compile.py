from pathlib import Path
import json,sys,subprocess,hashlib,traceback,resource
resource.setrlimit(resource.RLIMIT_CORE,(0,0))
R=Path('/workspaces/repository');G=Path('/var/tmp/kprog-tmp/C/katran-regression-current');I=Path('/var/tmp/kprog-tmp/C/xdp-adjust-head-caller-frame/actual-inputs/18');sys.path.insert(0,str(R/'kprog/x86'));from trusted_specializer import specialize
native=Path(sys.argv[1])if len(sys.argv)>1 else I/'kernel.native.o';label=sys.argv[2]if len(sys.argv)>2 else 'restored-producer'
row=dict(entry=(I/'kernel.entry').read_text().strip(),native_sha256=hashlib.sha256(native.read_bytes()).hexdigest(),model_sha256=hashlib.sha256((R/'kprog/x86/x86_sim_local_bpf.h').read_bytes()).hexdigest())
try:row['result']=specialize(native.read_bytes(),row['entry'],json.loads((I/'generation.metadata.json').read_text()),G/label/'generated',Path('/var/tmp/kprog-tmp/C/tail-helper-reaching-frame/native-link'));row['status']='compiled'
except BaseException as e:row.update(status='diagnostic',error=str(e),traceback=traceback.format_exc())
(G/(label+'-compiled.json')).write_text(json.dumps(row,indent=2)+'\n');print(row['status'],row.get('error'),flush=True)
