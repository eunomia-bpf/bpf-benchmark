"""Compile the same captured P simulator with the two stock entry contracts."""
from pathlib import Path
import hashlib,json,subprocess,sys,tarfile,time
from elftools.elf.elffile import ELFFile
R=Path('/workspaces/repository');G=Path('/var/tmp/kprog-tmp/C/stock-entry')
phase=sys.argv[1];O=G/('compile-'+phase);O.mkdir(parents=True)
archive=Path('/var/tmp/kprog-tmp/C/katran-regression-runtime/trusted-state-20261109T144721/requests/1.failure.tar.gz')
with tarfile.open(archive)as t:
 code=t.extractfile('request/generated/trusted_x86.bpf.c').read()
 commands=[json.loads(l)for l in t.extractfile('request/generated/commands.jsonl').read().decode().splitlines()]
source=G/'captured.bpf.c'
if not source.exists():source.write_bytes(code);source.chmod(0o444)
header=G/'input-before.h'if phase=='before'else R/'kprog/stock-path/include/stock_native_input.h'
command=next(c['command']for c in commands if'-target'in c['command'])
command[0]='/usr/lib/llvm-18/bin/clang'
command[command.index('-c')+1]=str(source);command[command.index('-o')+1]=str(O/'program.bpf.o')
command[1:1]=['-include',str(header)]
if phase=='after':command[1:1]=['-DKPROG_X86_ENTRY_SAVES_CALLEE=1']
result=dict(phase=phase,command=command,input_sha256=hashlib.sha256(code).hexdigest(),input_header_sha256=hashlib.sha256(header.read_bytes()).hexdigest(),simulator_header_sha256=hashlib.sha256((R/'kprog/x86/x86_sim_local_bpf.h').read_bytes()).hexdigest(),source_commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=R,text=True).strip())
(O/'input.h').write_bytes(header.read_bytes());(O/'simulator.h').write_bytes((R/'kprog/x86/x86_sim_local_bpf.h').read_bytes())
start=time.monotonic()
with(O/'stdout').open('w')as out,(O/'stderr').open('w')as err:done=subprocess.run(command,cwd=R,stdout=out,stderr=err)
result.update(returncode=done.returncode,wall_seconds=time.monotonic()-start)
if done.returncode==0:
 with(O/'program.bpf.o').open('rb')as f:body=ELFFile(f).get_section_by_name('xdp').data()
 result.update(bpf_insns=len(body)//8,program_sha256=hashlib.sha256(body).hexdigest())
 with(O/'program.dis').open('w')as out:subprocess.run(['llvm-objdump-18','-d',str(O/'program.bpf.o')],stdout=out,check=True)
(O/'result.json').write_text(json.dumps(result,indent=2)+chr(10));print(json.dumps(result),flush=True)
sys.exit(done.returncode)
