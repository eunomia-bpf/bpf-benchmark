"""Diagnose the retained MIR frame, without changing the production stack limit."""
import json
from pathlib import Path
import re
import subprocess
import sys
from elftools.elf.elffile import ELFFile
out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
source=Path('/workspaces/kprog-raw/perf/b-analysis-flags-20261119/production-20261119T063707Z-211523/tetragon6/trusted_x86.bpf.packed.mir')
obj=out/'diagnostic.bpf.o'
command=['llc-18','-O1','-march=bpf','-mcpu=v4','-bpf-stack-size=65536',
         '-start-before=prologepilog','-filetype=obj',str(source),'-o',str(obj)]
p=subprocess.run(command,text=True,capture_output=True)
(out/'emission.json').write_text(json.dumps(dict(command=command,returncode=p.returncode,stdout=p.stdout,stderr=p.stderr),indent=2)+'\n')
p.check_returncode()
with (out/'B.asm').open('w') as asm:subprocess.run(['llvm-objdump-18','-d',str(obj)],stdout=asm,check=True)
maximum=0
with (out/'B.asm').open() as asm:
    for line in asm:
        for value in re.findall(r'r10 - (0x[0-9a-f]+|[0-9]+)',line):maximum=max(maximum,int(value,0))
with obj.open('rb') as stream:
    elf=ELFFile(stream);text_bytes=sum(section['sh_size'] for section in elf.iter_sections() if section['sh_flags']&4)
summary=dict(max_direct_r10_displacement=maximum,executable_section_bytes=text_bytes,
    production_compiler_limit=4096,diagnostic_compiler_limit=65536,stock_stack_limit=512,
    scope='Diagnostic object only from existing packed MIR; no frontend/packing repeat, installation or stock acceptance. Production flags/limits unchanged.')
(out/'stack-summary.json').write_text(json.dumps(summary,indent=2)+'\n');print(summary,flush=True)
