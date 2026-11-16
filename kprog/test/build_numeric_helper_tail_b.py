"""Generate B from the compiler fixture's production-linked tail proof."""
import argparse
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT/'kprog'), str(ROOT/'kprog/x86'), str(ROOT/'kprog/x86/micro-prog')]
import trusted_specializer as worker

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--build', type=Path, required=True)
parser.add_argument('--output', type=Path, required=True)
args = parser.parse_args()
args.output.mkdir(parents=True, exist_ok=True)
body, subprograms, end, data = worker.gen.parse_proof_object_program('numeric-tail', args.build)
source = args.build/'trusted_x86.bpf.c'
text = worker.gen.render_program('trusted_x86', body, subprograms, kind='raw',
    program_section='kprobe/trusted', exit_addr=end, rodata16=data, trusted_map_bindings=[])
text = text.replace('#include "../x86_sim_local_bpf.h"',
                    '#include '+json.dumps(str(ROOT/'kprog/x86/x86_sim_local_bpf.h')))
source.write_text(text)

def run(command):
    command = list(map(str, command))
    result = subprocess.run(command, capture_output=True, text=True)
    with (args.output/'commands.jsonl').open('a') as log:
        log.write(json.dumps(dict(command=command, returncode=result.returncode,
                                 stdout=result.stdout, stderr=result.stderr))+'\n')
    result.check_returncode()

worker.compile_simulator(str(ROOT/'kprog/stock-path/bin/clang'), source,
    args.build/'trusted_x86.bpf.o', run,
    bounds_compiler='/var/tmp/kprog-tmp/perf/context-loads-v2/packet-bounds')
(args.build/'metadata.json').write_text(json.dumps(dict(version=1, prog_type=2,
    section='kprobe/trusted', maps=[], kernel_kfunc_context=False), indent=2)+'\n')
(args.build/'context.json').write_text(json.dumps(dict(prog_type=2, expected_attach_type=0,
    prog_flags=0, attach_btf_id=0, attach_btf_obj_id=0, attach_prog_id=0, prog_ifindex=0,
    gpl_compatible=1), indent=2)+'\n')
(args.output/'result.json').write_text(json.dumps(dict(instructions=len(body),
    subprograms=len(subprograms), b_generated=True,
    scope='Compiler-generated numeric helper tails through production proof parser, shared I and B compiler; stock check is separate.'), indent=2)+'\n')
