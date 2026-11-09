"""Replay the captured application compiler input with the current simulator."""
from pathlib import Path
import hashlib,json,subprocess,sys,tarfile,time
R=Path('/workspaces/repository')
G=Path('/var/tmp/kprog-tmp/C/katran-constant-offset')
G.mkdir(parents=True,exist_ok=True)
phase=sys.argv[1]
source=Path('/var/tmp/kprog-tmp/C/katran-regression-runtime/trusted-state-20261109T144721/requests/1.failure.tar.gz')
P=G/phase
P.mkdir()
with tarfile.open(source) as archive:
 code=archive.extractfile('request/generated/trusted_x86.bpf.c').read()
 commands=[json.loads(x) for x in archive.extractfile('request/generated/commands.jsonl').read().decode().splitlines()]
input=G/'captured.bpf.c'
if not input.exists():
 input.write_bytes(code)
 input.chmod(0o444)
assert input.read_bytes()==code
command=next(x['command'] for x in commands if '-target' in x['command'])
command[command.index('-c')+1]=str(input)
command[command.index('-o')+1]=str(P/'compiled.bpf.o')
header=R/'kprog/x86/x86_sim_local_bpf.h'
evidence=dict(phase=phase,source_archive_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),input_sha256=hashlib.sha256(code).hexdigest(),header_sha256=hashlib.sha256(header.read_bytes()).hexdigest(),command=command,source_commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=R,text=True).strip())
(P/'header.h').write_bytes(header.read_bytes())
start=time.monotonic()
with(P/'compile.stdout').open('w')as out,(P/'compile.stderr').open('w')as err:
 done=subprocess.run(command,cwd=R,stdout=out,stderr=err)
evidence.update(returncode=done.returncode,wall_seconds=time.monotonic()-start)
if done.returncode==0:
 with(P/'compiled.dis').open('w')as out:subprocess.run(['llvm-objdump-18','-d',str(P/'compiled.bpf.o')],stdout=out,check=True)
 evidence['object_sha256']=hashlib.sha256((P/'compiled.bpf.o').read_bytes()).hexdigest()
 evidence['object_bytes']=(P/'compiled.bpf.o').stat().st_size
(P/'result.json').write_text(json.dumps(evidence,indent=2)+chr(10))
print(json.dumps(evidence),flush=True)
sys.exit(done.returncode)
