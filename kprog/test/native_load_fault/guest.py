"""Run the authorized NULL-BTF load experiment in an isolated guest."""
from pathlib import Path
import json,os,subprocess,sys,shutil,hashlib
R=Path('/workspaces/repository');G=Path(sys.argv[1]);O=G/'guest';O.mkdir(exist_ok=True)
C=Path('/workspaces/.agent-state/kprog-lanes/C')
old=C/'design-only/raw-helper-context/source'
paths={p.relative_to(old) for p in old.rglob('*') if p.is_file()}
paths.update(map(Path,['kinsn/module/include/native_lab_trusted_wire.h','kinsn/module/x86/bpf_x86_native_lab.c','kprog/x86/native_lab/native_link/src/main.rs','kprog/x86/native_lab/native_link/src/x86.rs']))
identities={}
for rel in sorted(paths):
 src=R/rel
 if src.is_file():
  dst=O/'source'/rel;dst.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(src,dst);identities[str(rel)]=hashlib.sha256(dst.read_bytes()).hexdigest()
for rel in identities:
 subprocess.run(['mount','--bind',str(O/'source'/rel),str(R/rel)],check=True)
(O/'inputs.json').write_text(json.dumps(identities,indent=2)+'\n')
service=None;log=[];exit_code=1
try:
 subprocess.run(['insmod',str(R/'kprog/tv/build-x86/corpus-modules/bpf_x86_native_lab.ko')],check=True)
 state=O/'requests';state.mkdir(mode=0o700,exist_ok=True)
 command=[sys.executable,str(R/'kprog/trusted_service.py'),'--arch','1','--endpoint','/sys/kernel/debug/bpf_x86_native_lab/specializer','--state',str(state),'--native-link',str(R/'kprog/x86/native_lab/native_link/target/release/native-link'),'--loader',str(R/'kprog/libnativeloader/build/trusted-native-loader')]
 service=subprocess.Popen(command,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
 log=[]
 line=service.stdout.readline();log.append(line);print(line,flush=True)
 env=dict(os.environ,CLANG='/usr/lib/llvm-18/bin/clang',BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1')
 p=subprocess.run([str(G/'fixture/probe'),str(G/'fixture/native.o'),str(G/'fixture/module/native_load_fault_module.ko')],env=env,text=True,capture_output=True)
 (O/'stdout').write_text(p.stdout);(O/'stderr').write_text(p.stderr);(O/'probe.exit').write_text(str(p.returncode)+'\n');print(p.stdout+p.stderr,flush=True)
 (O/'summary.json').write_text(json.dumps(dict(probe_exit=p.returncode,stdout=p.stdout,stderr=p.stderr),indent=2)+'\n')
 exit_code=p.returncode
except BaseException as error:
 (O/'summary.json').write_text(json.dumps(dict(stage='fixture_error',error=str(error),exit_code=1),indent=2)+'\n')
 print(str(error),file=sys.stderr,flush=True)
finally:
 if service is not None:
  service.terminate();log.append(service.communicate()[0])
 (O/'service.log').write_text(''.join(log))
 dmesg=subprocess.run(['dmesg'],text=True,capture_output=True)
 (O/'dmesg').write_text(dmesg.stdout+dmesg.stderr)
sys.exit(exit_code)
