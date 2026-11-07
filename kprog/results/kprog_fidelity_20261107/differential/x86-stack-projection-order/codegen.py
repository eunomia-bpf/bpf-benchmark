#!/usr/bin/env python3
from pathlib import Path
import argparse,hashlib,json,subprocess
R=Path('/workspaces/repository');O=Path(__file__).resolve().parent;B=R/'kprog/formal/build/fidelity-projection-order'
p=argparse.ArgumentParser();p.add_argument('phase');a=p.parse_args();d=O/a.phase;d.mkdir(exist_ok=True)
base=['clang-18','-g','-O3','-mcpu=v4','-target','bpf','-mllvm','-bpf-stack-size=4096','-D__TARGET_ARCH_x86','-I',str(R/'vendor/libbpf/include/uapi'),'-I',str(R/'vendor/libbpf/src'),'-I','/usr/include/x86_64-linux-gnu']
obj=B/('biosnoop-'+a.phase+'.bpf.o');commands=[]
for cmd in [base+['-c',str(B/'biosnoop.c'),'-o',str(obj)],['llvm-objdump-18','-d','-S',str(obj)]]:
 r=subprocess.run(cmd,text=True,capture_output=True);commands.append(dict(command=cmd,returncode=r.returncode,stderr=r.stderr));(d/'biosnoop-commands.json').write_text(json.dumps(commands,indent=2)+'\n');r.check_returncode()
 if cmd[0]=='llvm-objdump-18':(d/'biosnoop.asm').write_text(r.stdout)
(d/'biosnoop-codegen-pins.json').write_text(json.dumps(dict(header_sha256=hashlib.sha256((R/'kprog/x86/x86_sim_local_bpf.h').read_bytes()).hexdigest(),source_sha256=hashlib.sha256((B/'biosnoop.c').read_bytes()).hexdigest(),object_sha256=hashlib.sha256(obj.read_bytes()).hexdigest()),indent=2)+'\n')
print(a.phase,'actual BIOSNOOP object',obj.stat().st_size)
