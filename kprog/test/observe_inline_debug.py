"""Observe debug-variable and BTF metadata without retaining compiler outputs."""
import argparse
from collections import Counter
import hashlib
import json
import re
import subprocess
from elftools.elf.elffile import ELFFile


def main(a):
    command = ['llvm-dis-18', str(a.bitcode), '-o', '-']
    ir = subprocess.check_output(command, text=True)
    variables = re.findall(r'!DILocalVariable\(name: "([^"]+)"', ir)
    with a.object.open('rb') as stream:
        sections = {s.name: s.data() for s in ELFFile(stream).iter_sections()
                    if s.name in ('.BTF', '.BTF.ext', 'kprobe')}
    record = dict(command=command, bitcode_sha256=hashlib.sha256(a.bitcode.read_bytes()).hexdigest(),
        object_sha256=hashlib.sha256(a.object.read_bytes()).hexdigest(),
        local_variables=len(variables), names=dict(Counter(variables)),
        executor_debug_subprograms=len(re.findall(r'!DISubprogram\(name: "x86_sim_inline_execute"', ir)),
        sections={name:dict(bytes=len(data), sha256=hashlib.sha256(data).hexdigest())
                  for name,data in sections.items()})
    a.output.parent.mkdir(parents=True, exist_ok=True)
    a.output.write_text(json.dumps(record, indent=2)+'\n')
    print(json.dumps({k:v for k,v in record.items() if k!='names'}))


if __name__=='__main__':
    from pathlib import Path
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('bitcode','object','output'):
        parser.add_argument('--'+name, type=Path, required=True)
    main(parser.parse_args())
