"""Replay the production checked compilation of all retained BCC requests."""
import io
import json
from pathlib import Path
import subprocess
import sys
import tarfile
from elftools.elf.elffile import ELFFile
ROOT=Path('/workspaces/repository');sys.path.insert(0,str(ROOT/'kprog/x86'))
from trusted_specializer import compile_checked_simulator
out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True);rows=[]
archive=Path('/workspaces/kprog-raw/verified/20261118-deletion-check/bcc/service.tar.gz')
with tarfile.open(archive) as outer:
    members=sorted((m for m in outer.getmembers() if m.name.endswith('.success.tar.gz')),
                   key=lambda m:int(Path(m.name).name.split('.')[0]))
    for member in members:
        name=Path(member.name).name;directory=out/name.split('.')[0];directory.mkdir(exist_ok=True)
        with tarfile.open(fileobj=io.BytesIO(outer.extractfile(member).read())) as request:
            artifacts=json.load(request.extractfile('request/generated/artifacts.json'))
            metadata=json.load(request.extractfile('request/generation.metadata.json'))
            for source,target in [('trusted_x86.bpf.i','simulator.i'),('trusted_x86.bpf.bounds-input.bc','frontend.bc')]:
                (directory/target).write_bytes(request.extractfile('request/generated/'+source).read())
            baseline = ELFFile(io.BytesIO(request.extractfile('request/generated/checked-simulator.proof.o').read()))
            before_text = baseline.get_section_by_name('.text')['sh_size']
        artifacts['simulator_preprocessed']=str(directory/'simulator.i')
        artifacts['simulator_frontend']['path']=str(directory/'frontend.bc')
        artifacts['maps']=metadata['maps'];artifacts['kernel_btf']='/workspaces/.agent-state/kprog-ck/build-x86/vmlinux'
        result=compile_checked_simulator(artifacts,ROOT/'kprog/x86/native_lab/native_link/target/release/native-link',
            Path('/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir'))
        commands=[json.loads(line) for line in (directory/'native-commands.jsonl').read_text().splitlines()]
        assert all(command['returncode']==0 for command in commands)
        dis=subprocess.run(['llvm-dis-18',str(directory/'checked-simulator.native.bc'),'-o','-'],
                           text=True,capture_output=True,check=True).stdout
        selected={kind:sum('call i64 @__kprog_probe_read_'+kind+'(' in line for line in dis.splitlines())
                  for kind in ['user','kernel']}
        asm=subprocess.run(['llvm-objdump-18','-dr',result['native_proof_object']],text=True,capture_output=True,check=True).stdout
        assert '__kprog_probe_read_' not in asm
        row=dict(request=name,symbol=artifacts['symbol'],selected_calls=selected,
                 helpers=(directory/'checked-simulator.helpers.txt').read_text().splitlines(),
                 before_text_bytes=before_text,
                 after_text_bytes=ELFFile(io.BytesIO(Path(result['native_proof_object']).read_bytes())).get_section_by_name('.text')['sh_size'])
        rows.append(row);(out/'replay.json').write_text(json.dumps(rows,indent=2)+'\n');print(row,flush=True)
assert len(rows)==25
print('25 production compile API/proof links passed; selected user/kernel calls',
      {kind:sum(row['selected_calls'][kind] for row in rows) for kind in ['user','kernel']})
