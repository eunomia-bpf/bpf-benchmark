#!/usr/bin/env python3
"""Generate full-bank CPU observers around the production instruction emitter."""
import argparse
import json
from pathlib import Path
import shutil
import subprocess
import sys

from tcb import includes, imports

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen


def wrapper(index, instruction, clear_monitor=False):
    lines = [f'.global native_{index}', f'.type native_{index}, %function',
             f'native_{index}:', 'sub sp, sp, #176']
    lines += [f'stp x{i}, x{i+1}, [sp, #{(i-19)*8}]' for i in range(19, 31, 2)]
    lines += [f'stp d{i}, d{i+1}, [sp, #{112+(i-8)*8}]' for i in range(8, 16, 2)]
    lines += ['str x0, [sp, #96]', 'mrs x1, tpidr_el0', 'str x1, [sp, #104]',
              'mov x30, x0', 'ldr x1, [x30, #256]', 'msr nzcv, x1',
              'add x1, x30, #264']
    lines += [f'ldr q{i}, [x1, #{i*16}]' for i in range(32)]
    lines += ['adrp x1, native_stack_base', 'mov x2, sp',
              'str x2, [x1, :lo12:native_stack_base]']
    lines += [f'ldr x{i}, [x30, #{i*8}]' for i in range(30)]
    lines += ['ldr x30, [x30, #240]']
    if clear_monitor:
        lines += ['clrex']
    lines += [f'.global native_pc_{index}',
              f'native_pc_{index}:', instruction, f'.global native_next_{index}',
              f'native_next_{index}:']
    # SP is unchanged by every generated form. A writable user thread register
    # saves guest X0 without consuming a guest vector or general register.
    # Restore TLS before returning to C; no calls occur while it is displaced.
    lines += ['msr tpidr_el0, x0', 'ldr x0, [sp, #96]']
    lines += [f'str x{i}, [x0, #{i*8}]' for i in range(1, 31)]
    lines += ['mrs x1, tpidr_el0', 'str x1, [x0]', 'mrs x1, nzcv',
              'str x1, [x0, #256]', 'add x1, x0, #264']
    lines += [f'str q{i}, [x1, #{i*16}]' for i in range(32)]
    lines += ['ldr x1, [sp, #104]', 'msr tpidr_el0, x1']
    lines += [f'ldp d{i}, d{i+1}, [sp, #{112+(i-8)*8}]' for i in range(8, 16, 2)]
    lines += [f'ldp x{i}, x{i+1}, [sp, #{(i-19)*8}]' for i in range(19, 31, 2)]
    return '\n'.join(lines + ['add sp, sp, #176', 'ret'])


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--family', choices=['fmov','bitfield','exclusive','memory'], default='fmov')
    args = parser.parse_args()
    out = args.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    snapshot = out / 'snapshot'
    for path in includes(ROOT/'kprog/arm64/arm64_sim_local_bpf.h') | imports(Path(gen.__file__)):
        target = snapshot / path.relative_to(ROOT)
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(path, target)
    forms = []
    if args.family == 'fmov':
        for bank in range(32):
            register = bank % 31
            forms += [f'fmov d{bank}, x{register}', f'fmov x{register}, d{bank}',
                      f'fmov s{bank}, w{register}', f'fmov w{register}, s{bank}']
    elif args.family == 'bitfield':
        for bits,prefix in [(32,'w'),(64,'x')]:
            for op in ['ubfx','sbfx','ubfiz','bfxil','bfi']:
                for lsb,count in [(7,13),(0,bits),(0,1),(bits-1,1),(1,bits-1)]:
                    forms.append(f'{op} {prefix}0, {prefix}1, #{lsb}, #{count}')
                forms += [f'{op} {prefix}1, {prefix}1, #7, #13',
                          f'{op} {prefix}zr, {prefix}1, #7, #13']
    elif args.family == 'exclusive':
        for prefix in ['w','x']:
            forms += [f'{op} {prefix}0, [x4]' for op in ['ldxr','ldaxr']]
            forms += [f'{op} w0, {prefix}1, [x4]' for op in ['stxr','stlxr']]
    else:
        transfers = [('ldr','w0',2),('ldr','x0',3),('str','w0',2),('str','x0',3),
            ('ldrb','w0',0),('ldrh','w0',1),('strb','w0',0),('strh','w0',1),
            ('ldrsb','w0',0),('ldrsb','x0',0),('ldrsh','w0',1),('ldrsh','x0',1),
            ('ldrsw','x0',2),('ldr','d0',3),('ldr','q0',4),('str','d0',3),('str','q0',4)]
        for op,reg,scale in transfers:
            forms += [f'{op} {reg}, [x4, #16]']
            for delta in [-16,16]:
                forms += [f'{op} {reg}, [x4, #{delta}]!', f'{op} {reg}, [x4], #{delta}']
            for extension,index in [('lsl','x5'),('uxtw','w5'),('sxtw','w5'),('sxtx','x5')]:
                for amount in sorted({0,scale}):
                    forms += [f'{op} {reg}, [x4, {index}, {extension} #{amount}]']
        for op,reg in [('ldur','w0'),('ldur','x0'),('stur','w0'),('stur','x0'),
                ('ldurb','w0'),('ldurh','w0'),('sturb','w0'),('sturh','w0')]:
            forms += [f'{op} {reg}, [x4, #-8]', f'{op} {reg}, [x4, #8]']
        for reg in ['w4','x4','w5','x5','wzr','xzr']:
            forms += [f'ldr {reg}, [x4, x5]',f'str {reg}, [x4, x5]']
        forms += ['ldr x0, [x4, xzr]', 'str x0, [x4, xzr]']
        for reg in ['w','x']:
            for op in ['ldp','stp']:
                forms += [f'{op} {reg}0, {reg}1, [x4, #16]']
                for delta in [-16,16]:
                    forms += [f'{op} {reg}0, {reg}1, [x4, #{delta}]!',
                              f'{op} {reg}0, {reg}1, [x4], #{delta}']
    (out/'instructions.S').write_text('.text\n'+'\n'.join(forms)+'\n')
    subprocess.run(['aarch64-linux-gnu-gcc', '-c', out/'instructions.S', '-o', out/'instructions.o'], check=True)
    assembly = subprocess.check_output(['aarch64-linux-gnu-objdump', '-dr', out/'instructions.o'], text=True)
    (out/'instructions.asm').write_text(assembly)
    instructions = gen.parse_flat_instructions(assembly)
    if len(instructions) != len(forms):
        raise RuntimeError('instruction/form count mismatch')
    source = ['#include "../driver.h"', '#include <stdlib.h>',
              f'#include "{snapshot}/kprog/arm64/arm64_sim_local_bpf.h"',
              'static void arm64_sim_unsupported_opcode(void) { abort(); }']
    if args.family == 'exclusive':
        # Every observed store has CLREX immediately before native_pc. This
        # fixture supplies that explicit environment; arbitrary entry monitors
        # and paired attempts must never inherit a constant failure outcome.
        source += ['unsigned long native_lab_exclusive_failure_choice(unsigned int site) {',
                   'switch (site) {']
        source += [f'case {insn.addr}U: return 1;' for insn in instructions
                   if insn.mnemonic in {'stxr','stlxr'}]
        source += ['default: fputs("unknown exclusive observer site\\n", stderr); exit(1);',
                   '}', '}']
    entries, coverage = [], []
    for index, (form, instruction) in enumerate(zip(forms, instructions)):
        encoded = gen.encode(instruction, {}, {})
        source += [f'extern void native_{index}(struct state *);',
                   f'extern unsigned char native_pc_{index}, native_next_{index};',
                   f'static void sim_{index}(struct state *s) {{',
                   'ARM64_SIM_L_DECLARE_STATE(); ARM64_SIM_L_DECLARE_STACK();',
                   '__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;']
        source += [f'__a64_x{i}.x = s->r[{i}];' for i in range(31)]
        source += ['__a64_n = (s->flags >> 31) & 1; __a64_z = (s->flags >> 30) & 1;',
                   '__a64_c = (s->flags >> 29) & 1; __a64_v = (s->flags >> 28) & 1;']
        source += [f'__a64_vectors[{i}].lo=s->vec[{2*i}]; __a64_vectors[{i}].hi=s->vec[{2*i+1}];' for i in range(32)]
        gen.append_insn(source, instruction, {instruction.addr}, instruction.addr+4,
                        frozenset(), {}, {})
        source += [f's->r[{i}] = __a64_x{i}.x;' for i in range(31)]
        source += ['s->flags = ((uint64_t)__a64_n << 31) | ((uint64_t)__a64_z << 30) | ((uint64_t)__a64_c << 29) | ((uint64_t)__a64_v << 28);']
        source += [f's->vec[{2*i}]=__a64_vectors[{i}].lo; s->vec[{2*i+1}]=__a64_vectors[{i}].hi;' for i in range(32)]
        source += ['}']
        entries += [f'{{{json.dumps(form)}, {json.dumps(encoded.op)}, native_{index}, sim_{index}, 0xf0000000U, 64, 0, 0, &native_pc_{index}, &native_next_{index}}}']
        record = dict(assembly=form, decoded=instruction.raw, opcode=encoded.op)
        if args.family == 'exclusive':
            record['exclusive_monitor_initial'] = 'cleared by CLREX before native_pc'
        coverage += [record]
    source += ['const struct form forms[] = {', ',\n'.join(entries), '};',
               'const unsigned form_count = sizeof(forms) / sizeof(forms[0]);']
    (out/'generated.c').write_text('\n'.join(source)+'\n')
    (out/'native.S').write_text('.text\n'+'\n'.join(wrapper(i, form, args.family == 'exclusive') for i, form in enumerate(forms))+'\n.section .note.GNU-stack,"",%progbits\n')
    (out/'coverage.json').write_text(json.dumps(coverage, indent=2)+'\n')
    (out/'family.txt').write_text(args.family+'\n')
    print(f'generated {len(forms)} {args.family} forms, observing all 32 vectors')


if __name__ == '__main__':
    main()
