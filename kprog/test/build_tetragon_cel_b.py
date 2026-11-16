"""Generate B from P containing actual upstream CEL bodies and runtime input."""
import argparse
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT/'kprog/x86'), str(ROOT/'kprog/x86/micro-prog')]
import trusted_specializer as worker

parser = argparse.ArgumentParser(description=__doc__)
for option in ('build', 'output', 'cases', 'compiler', 'kernel', 'linker', 'bounds'):
    parser.add_argument('--'+option, type=Path, required=True)
args = parser.parse_args()
args.output.mkdir(parents=True, exist_ok=True)

def run(command):
    command = list(map(str, command))
    result = subprocess.run(command, capture_output=True, text=True)
    with (args.output/'commands.jsonl').open('a') as log:
        log.write(json.dumps(dict(command=command, returncode=result.returncode,
                                 stdout=result.stdout, stderr=result.stderr))+'\n')
    result.check_returncode()

rows = []
seen = set()
for case in json.loads(args.cases.read_text()):
    if case['code'] in seen:
        continue
    seen.add(case['code'])
    name = 'cel-'+str(len(rows))
    facts = args.output/(name+'.json')
    facts.write_text(json.dumps(dict(functions={'cel_expression':case['code']}))+'\n')
    native = args.build/(name+'.native.o')
    run([args.compiler, args.build/'cel-stock-input.o', '--symbol', 'native_cel_stock',
         '--prog-type', '2', '--kernel-btf', args.kernel, '--bpf-function-bodies', facts,
         '-o', native])
    run([args.linker, '--input', native, '--symbol', 'native_cel_stock', '--mode', 'proof',
         '--preserve-entry-abi', '--output', args.build/(name+'.proof.o')])
    body, subprograms, end, data = worker.gen.parse_proof_object_program(name, args.build)
    source = args.build/(name+'.bpf.c')
    text = worker.gen.render_program('trusted_x86', body, subprograms, kind='raw',
        program_section='kprobe/test', exit_addr=end, rodata16=data, trusted_map_bindings=[])
    source.write_text(text.replace('#include "../x86_sim_local_bpf.h"',
        '#include '+json.dumps(str(ROOT/'kprog/x86/x86_sim_local_bpf.h'))))
    output = args.build/(name+'.bpf.o')
    worker.compile_simulator(str(ROOT/'kprog/stock-path/bin/clang'), source, output,
                             run, bounds_compiler=str(args.bounds))
    rows.append(dict(name=name, expression=case['expression'], bpf_callee=case['code'],
                     native_instructions=len(body), b_generated=True, b_object=str(output)))
(args.output/'generated.json').write_text(json.dumps(dict(cases=rows,
    scope='Constructed KPROBE context/stack wrapper, actual upstream CEL bodies, same native P through shared I. Stock acceptance is separate; not app installation.'), indent=2)+'\n')
print('Upstream CEL bodies through P/shared I/B:',len(rows))
