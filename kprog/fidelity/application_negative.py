#!/usr/bin/env python3
"""Prepend unsafe instructions to an actual application's preserved native body."""
import argparse
import importlib.util
import json
from pathlib import Path
import shutil
import subprocess
import sys

from tcb import includes, imports
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def build_bcc(out):
    package = ROOT/'corpus/results/kprog_app_coverage_20261106/bcc-runtime-18'
    source = ROOT/'corpus/results/kprog_app_coverage_20261106/bcc-real-17'
    symbol = 'fentry_vfs_read'
    entries = json.loads((package/'bcc/manifest.json').read_text())['objects']
    target = [x for x in entries if x['symbol'] == symbol]
    if len(target) != 1:
        raise ValueError('actual BCC entry must match exactly once')
    entry = target[0]
    with (source/'original/vfsstat.bpf.o').open('rb') as stream:
        original_symbols = {s.name for s in ELFFile(stream).get_section_by_name('.symtab').iter_symbols()}
    native = package/'bcc'/Path(entry['native_object']).name
    original_source = source/'sources/bcc_vfsstat_fentry_vfs_read.bpf.c'
    prelude = original_source.read_text().split('#include "'+str(source)+'/simulator/')[0]
    if '__x86_original_license' not in prelude or '#undef LICENSE' not in prelude:
        raise ValueError('cannot isolate the original BCC declarations')
    sys.path.insert(0, str(ROOT/'kprog/x86/micro-prog'))
    spec = importlib.util.spec_from_file_location('app_negative_encoder', ROOT/'kprog/x86/micro-prog/generate_micro_sim_proofs.py')
    gen = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = gen
    spec.loader.exec_module(gen)
    out.mkdir(parents=True, exist_ok=True)
    snapshot = out/'snapshot'
    for path in includes(ROOT/'kprog/x86/x86_sim_local_bpf.h') | imports(Path(gen.__file__)):
        dest = snapshot/path.relative_to(ROOT)
        dest.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(path, dest)
    commands = []

    def run(command):
        command = list(map(str, command))
        result = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=result.returncode, stdout=result.stdout, stderr=result.stderr))
        (out/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        if result.returncode:
            raise RuntimeError(result.stderr or result.stdout)
        return result.stdout

    renamed = out/'original-renamed.native.o'
    run(['objcopy', '--redefine-sym', symbol+'=__f_original_entry', native, renamed])
    # The original real function remains byte-for-byte present, including its
    # map relocations. A real CALL preserves its return convention. The source
    # program, maps, BTF and intercepted load attributes are reused by the proxy.
    prefixes = {
        'unchanged_call_control': 'nop',
        'stack_oob': 'mov rax,QWORD PTR [rsp-1024]',
        'uninitialized_stack': 'mov rax,QWORD PTR [rsp-8]',
        'unbounded_loop': '1: jmp 1b',
        'unbounded_indirect_jump': 'jmp rdi',
        'unsupported_instruction': 'ud2',
        'invalid_helper_argument': 'push rdi; mov rdi,1; xor esi,esi; call bpf_map_lookup_elem; pop rdi',
    }
    rows = []
    link = package/'native-link'
    for case, prefix in prefixes.items():
        name = 'bcc_vfs_read_'+case
        assembly = out/(name+'.S')
        assembly.write_text('.intel_syntax noprefix\n.text\n.global '+symbol+'\n.type '+symbol+',@function\n'+symbol+':\n'+prefix.replace('; ', '\n')+'\ncall __f_original_entry\nret\n.size '+symbol+',.-'+symbol+'\n.section .note.GNU-stack,"",@progbits\n')
        wrapper = out/(name+'.wrapper.o')
        candidate = out/(name+'.native.o')
        run(['cc', '-c', assembly, '-o', wrapper])
        run(['ld', '-r', wrapper, renamed, '-o', candidate])
        proof = out/(name+'.proof.o')
        row = dict(name=case, symbol=symbol, native_object=str(candidate), stage='generated', message='')
        try:
            run([link, '--input', candidate, '--symbol', symbol, '--mode', 'proof', '--preserve-entry-abi', '--output', proof])
            insns, subs, end, rodata = gen.parse_proof_object_program(name, out)
            text = gen.render_program(name, insns, subs, 'raw', exit_addr=end,
                                      rodata16=rodata, program_section='fentry/vfs_read',
                                      original_source=source/'upstream/vfsstat.bpf.c', original_symbols=original_symbols)
            text = text.replace('#include "../x86_sim_local_bpf.h"', '#include "'+str(snapshot/'kprog/x86/x86_sim_local_bpf.h')+'"')
            c = out/(name+'.bpf.c')
            c.write_text(text)
            run(['clang', '-g', '-O2', '-target', 'bpf', '-mllvm', '-bpf-stack-size=4096',
                 '-I'+str(ROOT/'vendor/libbpf/include/uapi'), '-I'+str(ROOT/'vendor/libbpf/src'),
                 '-I/usr/include/x86_64-linux-gnu', '-I'+str(source/'upstream'),
                 '-I'+str(ROOT/'vendor/bpf/bcc/libbpf-tools'),
                 '-c', c, '-o', out/(name+'.bpf.o')])
            plan = dict(entry)
            plan['native_object'] = '/f-negative/'+candidate.name
            plan['simulator_object'] = '/f-negative/'+name+'.bpf.o'
            plan['simulator_program'] = name+'_x86_sim_xdp'
            (out/(name+'.manifest.json')).write_text(json.dumps(dict(objects=[plan]), indent=2)+'\n')
        except ValueError as error:
            row.update(stage='specialization_rejected', message=str(error))
        rows.append(row)
        (out/'build.json').write_text(json.dumps(dict(app='bcc', real_native=str(native), real_manifest_entry=entry, cases=rows), indent=2)+'\n')
    (out/'cases.tsv').write_text(''.join(symbol+'\t'+r['name']+'\t/f-negative/bcc_vfs_read_'+r['name']+'.manifest.json\n' for r in rows if r['stage']=='generated'))


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('out', type=Path)
    args = parser.parse_args()
    build_bcc(args.out.resolve())
