"""Catch omitted undecodable bytes and objdump's zero-run elision in real ELFs."""
import json
from pathlib import Path
import subprocess
import sys

root = Path('/workspaces/repository')
sys.path.insert(0, str(root/'kprog/x86/micro-prog'))
import generate_micro_sim_proofs as gen

out = Path(sys.argv[1])
out.mkdir(parents=True, exist_ok=True)
rows, commands = [], []
for name, body in [('bad', 'nop\n.byte 0x06\nret'),
                   ('zeros', 'nop\n.zero 16\nret')]:
    source = out/f'{name}.S'
    source.write_text(f'.text\n.globl {name}\n.type {name},@function\n{name}:\n{body}\n.size {name},.-{name}\n')
    command = ['clang-18', '-c', str(source), '-o', str(out/f'{name}.proof.o')]
    process = subprocess.run(command, text=True, capture_output=True)
    commands.append(dict(command=command, returncode=process.returncode,
                         stdout=process.stdout, stderr=process.stderr))
    (out/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
    process.check_returncode()
    try:
        instructions, length, _ = gen.parse_native_link_blob(name, out)
    except ValueError as error:
        rows.append(dict(case=name, error=str(error),
                         passed=name == 'bad' and '0x1' in str(error)))
    else:
        covered = sum(insn.end_addr-insn.addr for insn in instructions)
        rows.append(dict(case=name, blob_bytes=length, parsed_bytes=covered,
                         instructions=[dict(address=i.addr, end=i.end_addr, asm=i.raw)
                                       for i in instructions],
                         passed=name == 'zeros' and covered == length == 18))
(out/'result.json').write_text(json.dumps(dict(cases=rows,
    scope='Real host object parser regression only; no guest, native execution or runtime gate.'), indent=2)+'\n')
print(json.dumps(rows), flush=True)
assert all(row['passed'] for row in rows), 'Native disassembly omitted instruction bytes'
