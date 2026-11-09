from pathlib import Path
import sys,os,subprocess,json,threading
G=Path(sys.argv[1]);rows=[]
subprocess.run(['insmod',str(G/'runtime/bpf_x86_native_lab.ko')],check=True)
(G/'requests').mkdir(mode=0o700,exist_ok=True)
service=subprocess.Popen([sys.executable,'/workspaces/repository/kprog/trusted_service.py','--arch','1','--endpoint','/sys/kernel/debug/bpf_x86_native_lab/specializer','--state',str(G/'requests'),'--native-link',str(G/'runtime/native-link'),'--loader',str(G/'runtime/trusted-native-loader')],stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
log=(G/'service.log').open('w');line=service.stdout.readline();log.write(line);log.flush();print(line,flush=True)
def drain():
 for line in service.stdout:log.write(line);log.flush()
reader=threading.Thread(target=drain);reader.start()
for width in [1,2,4,8]:
 command=[str(G/'probe'),str(G/('width'+str(width)+'.native.o')),str(G/'native_load_fault_module.ko')]
 env=dict(os.environ,BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1',CLANG='/usr/lib/llvm-18/bin/clang')
 p=subprocess.run(command,env=env,text=True,capture_output=True)
 row=dict(width_bytes=width,command=command,returncode=p.returncode,stdout=p.stdout,stderr=p.stderr)
 rows.append(row);(G/'outcomes.json').write_text(json.dumps(rows,indent=2)+'\n');print(json.dumps(row),flush=True)
subprocess.run(['dmesg'],stdout=(G/'dmesg.log').open('w'),stderr=subprocess.STDOUT)

service.terminate();service.wait();reader.join();log.close()
