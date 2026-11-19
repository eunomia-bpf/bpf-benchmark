"""Regress real locked/plain native operations collapsing to one simulator encoding."""
from dataclasses import asdict
import json
from pathlib import Path
import subprocess
import sys

root = Path('/workspaces/repository')
sys.path.insert(0, str(root / 'kprog/x86'))
from trusted_specializer import gen

native = Path(sys.argv[1])
out = Path(sys.argv[2])
out.mkdir(parents=True, exist_ok=True)
commands, cases = [], []
for operation in ['inc64', 'inc32', 'add64', 'addimm64']:
    variants = {}
    for kind in ['locked', 'plain']:
        symbol = kind + '_' + operation
        command = ['objdump', '-dr', '--insn-width=16', '-Mintel',
                   '--disassemble=' + symbol, str(native)]
        result = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout=result.stdout, stderr=result.stderr))
        (out / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
        result.check_returncode()
        (out / (symbol + '.asm')).write_text(result.stdout)
        instructions = [i for i in gen.parse_asm_text(result.stdout)
                        if i.mnemonic in ['inc', 'add']]
        assert len(instructions) == 1, result.stdout
        instruction = instructions[0]
        assert ('lock ' in result.stdout) == (kind == 'locked'), result.stdout
        variants[kind] = dict(native_length=instruction.end_addr - instruction.addr,
                              decoded_raw=instruction.raw,
                              encoded=asdict(gen.encode(instruction, {})))
    cases.append(dict(operation=operation, variants=variants,
                      encodings_equal=variants['locked']['encoded'] == variants['plain']['encoded']))
summary = dict(cases=cases,
    scope='Actual assembly/object/parser regression. Not a concurrency, B-stock or app timing result.')
(out / 'evidence.json').write_text(json.dumps(summary, indent=2) + '\n')
print(json.dumps(summary), flush=True)
assert all(not case['encodings_equal'] for case in cases), 'LOCK semantics collapsed to the plain RMW encoding'
