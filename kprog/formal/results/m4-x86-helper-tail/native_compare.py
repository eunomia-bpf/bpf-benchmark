#!/usr/bin/env python3
"""Compare return normalization on one existing ordinary and tail profile."""
import argparse
import ast
import importlib.util
import json
from pathlib import Path
import subprocess
import sys

FORMAL = Path(__file__).resolve().parents[2]
ROOT = FORMAL.parents[1]
p = argparse.ArgumentParser(description=__doc__)
p.add_argument('--output', type=Path, required=True)
a = p.parse_args()
raw = a.output.resolve()
raw.mkdir(parents=True, exist_ok=False)
commands = []
sys.path.insert(0, str(ROOT / 'kprog/x86/micro-prog'))
import generate_micro_sim_proofs as producer
spec = importlib.util.spec_from_file_location('compare_helpers', FORMAL / 'tools/compare_c_header.py')
helper = importlib.util.module_from_spec(spec)
spec.loader.exec_module(helper)
historical = subprocess.check_output(['git', 'show', '944d9793f:kprog/x86/micro-prog/generate_micro_sim_proofs.py'], cwd=ROOT, text=True)
node = next(n for n in ast.parse(historical).body if isinstance(n, ast.FunctionDef) and n.name == 'normalize_native_link_entry_returns')
namespace = dict(producer.__dict__)
exec(compile(ast.get_source_segment(historical, node), '<historical normalization>', 'exec'), namespace)
normalize = producer.normalize_native_link_entry_returns
source = FORMAL / 'build/x86_program_profile.bpf.c'
obj = FORMAL / 'build/x86_program_profile.bpf.o'
flags = ['../stock-path/bin/clang', '-g', '-O2', '-mcpu=v4', '-target', 'bpf', '-mllvm', '-bpf-stack-size=4096', '-D__TARGET_ARCH_x86', '-I../../vendor/libbpf/include/uapi', '-I../../vendor/libbpf/src', '-I/usr/include/x86_64-linux-gnu']
def run(name, cmd, text=None):
    cmd = list(map(str, cmd))
    result = subprocess.run(cmd, cwd=FORMAL, input=text, text=True, capture_output=True)
    (raw / (name + '.log')).write_text(result.stdout + result.stderr)
    commands.append(dict(name=name, argv=cmd, exit=result.returncode))
    (raw / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
    result.check_returncode()
def render(normalizer):
    producer.normalize_native_link_entry_returns = normalizer
    try:
        instructions, functions, end, data = producer.parse_proof_object_program('x86_program_profile', FORMAL / 'build')
        text = producer.render_program('x86_program_profile', instructions, functions, kind='raw', program_section='socket', exit_addr=end, rodata16=data)
    finally:
        producer.normalize_native_link_entry_returns = normalize
    return text.replace('#include "../x86_sim_local_bpf.h"', '#include "../../x86/x86_sim_local_bpf.h"')
current = source.read_text()
assert render(normalize) == current
# Historical/current syntax on the SAME relocated tail: only current keeps it.
bad = render(namespace['normalize_native_link_entry_returns'])
assert bad.count('X86_SIM_HELPER_bpf_ktime_get_ns') == 1
assert current.count('X86_SIM_HELPER_bpf_ktime_get_ns') == 2
old = subprocess.check_output(['git', 'show', '944d9793f:kprog/formal/oracles/x86_program_profile.S'], cwd=ROOT, text=True)
try:
    run('ordinary-assembly', ['../stock-path/bin/clang', '-x', 'assembler', '-c', '-', '-o', 'build/x86_program_profile.proof.o'], old)
    before = render(namespace['normalize_native_link_entry_returns'])
    after = render(normalize)
    assert before == after, 'ordinary producer C changed'
    source.write_text(after)
    run('ordinary-bpf', flags + ['-c', source, '-o', obj])
    ordinary = helper.allocated(obj)
finally:
    run('tail-assembly', ['../stock-path/bin/clang', '-c', 'oracles/x86_program_profile.S', '-o', 'build/x86_program_profile.proof.o'])
    source.write_text(render(normalize))
    assert source.read_text() == current
run('tail-bpf', flags + ['-c', source, '-o', obj])
tail = helper.allocated(obj)
result = dict(ordinary_source_exact=True, historical_tail_helper_calls=1, corrected_tail_helper_calls=2,
    ordinary_section_bytes={n:len(b) for n,b in ordinary[0].items()}, tail_section_bytes={n:len(b) for n,b in tail[0].items()},
    ordinary_relocations=len(ordinary[1]), tail_relocations=len(tail[1]), current_source_restored=True,
    scope='Different fixture control graphs have different BPF code; ordinary C is unchanged, and the previously erased helper tail is repaired.')
(raw / 'result.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(result, indent=2))
