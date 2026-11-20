"""Record actual cached-IR native stack code before/after the uniform flag."""
import json
from pathlib import Path
import subprocess
import sys
import tarfile
from elftools.elf.elffile import ELFFile

out=Path(sys.argv[1]);stage=sys.argv[2];out.mkdir(parents=True,exist_ok=True)
generation=Path('/var/tmp/kprog-tmp/perf/lpm-c-lto/generation')
native=generation/'checked-simulator.native.o'
command=['llvm-objdump-18','-d','--disassemble-symbols=trusted_x86_x86_sim_xdp',str(native)]
assembly=subprocess.run(command,capture_output=True,text=True,check=True).stdout
(out/(stage+'.asm')).write_text(assembly)
with native.open('rb') as stream:
    elf=ELFFile(stream)
    symbol=next(s for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name=='trusted_x86_x86_sim_xdp')
    size=symbol['st_size']
commands=[json.loads(line)['command'] for line in (generation/'native-commands.jsonl').read_text().splitlines()]
compile_command=next(command for command in reversed(commands) if str(native) in command and '-c' in command)
record=dict(stage=stage,native_entry_bytes=size,command=compile_command,
    source_frontend=json.loads((generation/'frontend-ir-reuse.json').read_text()),
    scope='Actual compiler API emitted native component stack code; no application/interrupt execution or speed claim')
if stage=='after':
    # Use the same installed compiler/options, emitting IR to stdout. This
    # records function attributes after the normal O3 pipeline without a new
    # compiler, optimizer stage or second canonical native build.
    emit=list(compile_command);emit[emit.index('-c')]='-S';emit.insert(1,'-emit-llvm')
    emit[emit.index('-o')+1]='-'
    ir=subprocess.run(emit,capture_output=True,text=True,check=True).stdout
    (out/'after.ll').write_text(ir)
    record['emitted_function_attributes']=[line for line in ir.splitlines() if line.startswith('attributes #')]
(out/(stage+'.json')).write_text(json.dumps(record,indent=2)+'\n')
with tarfile.open(out/(stage+'.tar.gz'),'w:gz') as archive:
    archive.add(generation,arcname='lpm-native-products')
print(stage,size)
