from pathlib import Path
import sys,os,subprocess,json
G=Path(sys.argv[1]);rows=[]
subprocess.run(['insmod',str(G/'runtime/bpf_x86_native_lab.ko')],check=True)
for width in [1,2,4,8]:
 command=[str(G/'probe'),str(G/('width'+str(width)+'.native.o')),str(G/'native_load_fault_module.ko')]
 env=dict(os.environ,BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='0')
 p=subprocess.run(command,env=env,text=True,capture_output=True)
 row=dict(width_bytes=width,command=command,returncode=p.returncode,stdout=p.stdout,stderr=p.stderr)
 rows.append(row);(G/'outcomes.json').write_text(json.dumps(rows,indent=2)+'\n');print(json.dumps(row),flush=True)
subprocess.run(['dmesg'],stdout=(G/'dmesg.log').open('w'),stderr=subprocess.STDOUT)
