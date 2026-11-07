#!/usr/bin/env python3
"""Real ARM control/stack composites paired with the production whole-program encoder."""
from dataclasses import replace
import importlib.util
import json
from pathlib import Path
import subprocess
import sys

from generate import native_wrapper
from tcb import includes, imports
import shutil

ROOT = Path(__file__).resolve().parents[2]
BASE = 0x1000000


def forms():
    out = []
    for cc in ['eq','ne','cs','cc','mi','pl','vs','vc','hi','ls','ge','lt','gt','le','al','nv']:
        for backward in [False, True]:
            out.append((f'b.{cc} {"backward" if backward else "forward"}', branch(f'b.{cc}', backward)))
    for width in ['w','x']:
        for op in ['cbz','cbnz']:
            for backward in [False, True]:
                out.append((f'{op} {width}1 {backward}', branch(f'{op} {width}1,', backward)))
        for op in ['tbz','tbnz']:
            for bit in ([0,7,31] if width == 'w' else [0,7,31,63]):
                for backward in [False, True]:
                    out.append((f'{op} {width}1 #{bit} {backward}', branch(f'{op} {width}1, #{bit},', backward)))
    for width in ['w','x']:
        out.append((f'cmp {width}1,{width}2 / b.gt', f'cmp {width}1, {width}2\n'+branch('b.gt', False)))
    out += [
        ('BR finite code choice', 'tbz x1, #0, 1f\nadr x10, 2f\nb 3f\n1: adr x10, 4f\n3: br x10\n2: eor x0,x0,x2\nb finish\n4: add x0,x0,x2\nb finish'),
        ('BL / RET x30', 'bl 1f\nb finish\n1: eor x0,x0,x2\nret'),
        ('BL / RET x17', 'bl 1f\nb finish\n1: eor x0,x0,x2\nmov x17,x30\nret x17'),
        ('BLR code / RET', 'adr x10, 1f\nblr x10\nb finish\n1: add x0,x0,x2\nret'),
        ('nested BL saved LR stack', 'bl 1f\nb finish\n1: stp x19,x30,[sp,#-16]!\nbl 2f\nldp x19,x30,[sp],#16\nret\n2: eor x0,x0,x2\nret'),
        ('BLR saved LR stack', 'bl 1f\nb finish\n1: str x30,[sp,#-16]!\nadr x10,2f\nblr x10\nldr x30,[sp],#16\nret\n2: add x0,x0,x2\nret'),
        ('stack pair pre/post', 'stp x1,x2,[sp,#-16]!\nldp x0,x3,[sp],#16\nb finish'),
        ('stack scalar pre/post', 'str x1,[sp,#-16]!\nldr x0,[sp],#16\nb finish'),
        ('MOV SP register round-trip', 'sub sp,sp,#16\nmov x0,sp\nadd x0,x0,#16\nmov sp,x0\nmov x0,#37\nb finish'),
        ('SP observation offset', 'sub sp,sp,#16\nmov x0,#37\nb finish'),
        ('SP compare flags', 'cmp sp,#0\n'+branch('b.eq', False)),
    ]
    # Numeric observations must expose actual address bytes while full-width
    # restores retain the private offset needed for typed stack indexing.
    out += [('entry LR compare flags', 'cmp x30,#0\n'+branch('b.eq',False)),
            ('SP numeric W move', 'mov w0,wsp\nb finish'),
            ('SP tagged numeric ADD', 'mov x0,sp\nadd x0,x0,#31\nb finish'),
            ('SP tagged numeric SUB', 'mov x0,sp\nsub x0,x0,#31\nb finish')]
    for source in ['sp','x30']:
        for width,load in [(1,'ldrb w0'),(2,'ldrh w0'),(4,'ldr w0'),(8,'ldr x0')]:
            for offset in [0,8-width]:
                out.append((f'{source} spill bytes{width} offset{offset}',
                    f'mov x10,{source}\nstr x10,[sp,#-16]!\n{load},[sp,#{offset}]\nadd sp,sp,#16\nb finish'))
    return out


def branch(op, backward):
    if backward:
        return f'b 2f\n1: eor x0,x0,x2\nb finish\n2: {op} 1b\nadd x0,x0,x2\nb finish'
    return f'{op} 1f\nadd x0,x0,x2\nb finish\n1: eor x0,x0,x2\nb finish'


def main():
    out = Path(sys.argv[1]).resolve()
    out.mkdir(parents=True, exist_ok=True)
    sys.path.insert(0, str(ROOT/'kprog/arm64/micro-prog'))
    spec = importlib.util.spec_from_file_location('encoder', ROOT/'kprog/arm64/micro-prog/generate_micro_sim_proofs.py')
    enc = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = enc
    spec.loader.exec_module(enc)
    snapshot = out/'snapshot'
    for path in includes(ROOT/'kprog/arm64/arm64_sim_local_bpf.h') | imports(Path(enc.__file__)):
        target = snapshot/path.relative_to(ROOT)
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(path, target)
    assembly = ['.section .kprog_native,"ax",%progbits']
    matrix = forms()
    for i, (_, body) in enumerate(matrix):
        body = body.replace('finish', f'outer_done_{i}')
        body += f'\n.global outer_done_{i}\nouter_done_{i}: b native_next_{i}'
        wrapper = native_wrapper('arm64', i, body)
        # Match the simulator's raw stack bytes, without initializing or guarding
        # production stack memory. Q1-Q4 are observer temporaries, outside V0.
        # LDUR's signed immediate cannot reach state.stack; use the pointer temp.
        before = 'add x1,x30,#280\n'+'\n'.join(f'ldr q{j+1}, [x1, #{j*16}]\nstur q{j+1}, [sp, #-{64-j*16}]' for j in range(4))
        wrapper = wrapper.replace('ldr x1, [x30, #256]', before+'\nldr x1, [x30, #256]')
        after = 'add x30,x0,#280\n'+'\n'.join(f'ldur q{j+1}, [sp, #-{64-j*16}]\nstr q{j+1}, [x30, #{j*16}]' for j in range(4))
        observer = 'stp x0, x30, [sp, #112]\nldr x0, [sp, #96]'
        if wrapper.count(observer) != 1:
            raise RuntimeError('ambiguous ARM stack observer insertion')
        wrapper = wrapper.replace(observer, observer+'\n'+after)
        assembly += [f'.org {i*4096}', wrapper]
    assembly += ['.section .note.GNU-stack,"",%progbits']
    source = out/'native.S'
    source.write_text('\n'.join(assembly)+'\n')
    subprocess.run(['aarch64-linux-gnu-gcc','-c',source,'-o',out/'native.o'], check=True)
    dump = subprocess.check_output(['aarch64-linux-gnu-objdump','-d',f'--adjust-vma={BASE}',out/'native.o'], text=True)
    (out/'native.asm').write_text(dump)
    insns = enc.parse_flat_instructions(dump)
    symbols = {}
    for line in subprocess.check_output(['aarch64-linux-gnu-nm',out/'native.o'], text=True).splitlines():
        fields = line.split()
        if len(fields) == 3: symbols[fields[2]] = int(fields[0],16)+BASE
    definitions = []
    functions = []
    entries = []
    coverage = []
    for i, (name, _) in enumerate(matrix):
        code = [x for x in insns if symbols[f'native_pc_{i}'] <= x.addr < symbols[f'native_next_{i}']]
        # The outer ABI return is our observation boundary. Inner RETs remain
        # real RETs in both the CPU and canonical production return dispatcher.
        code = [replace(x,mnemonic='ret',operands=('x20',),raw='ret x20 (outer observation)') if x.addr == symbols[f'outer_done_{i}'] else x for x in code]
        targets = enc.indirect_targets(code)
        returns = enc.return_targets(code, targets)
        for addr, destinations in sorted(returns.items()):
            cases=' '.join(f'case 0x{target:x}ULL: goto {enc.label(target)};' for target in sorted(destinations))
            definitions.append(f'#define ARM64_SIM_RET_CASES_{addr:x} {cases}')
        emitted=[]
        skip=set()
        for j, instruction in enumerate(code):
            if instruction.addr in skip: continue
            emitted.append(f'{enc.label(instruction.addr)}:;')
            if instruction.addr == symbols[f'outer_done_{i}']:
                # Both sides stop at the observer boundary, without forging
                # an application ABI return token or an extra entry argument.
                emitted.append('goto observed;')
                continue
            if name.endswith('/ b.gt') and j==0:
                selected=enc.encode(instruction,{},{}); following=code[j+1]
                emitted += [f'{enc.label(following.addr)}:;',
                    f'ARM64_SIM_A64_CMP_GT({selected.op}, {selected.dst}, {selected.src}, {selected.width}, {selected.aux}, {selected.imm}, {enc.label(enc.branch_target(following.operands[0]))});']
                skip.add(following.addr)
                continue
            enc.append_insn(emitted,instruction,{x.addr for x in code},code[j+1].addr if j+1<len(code) else None,
                            targets.get(instruction.addr),{}, {})
        init = ['ARM64_SIM_L_DECLARE_STATE(); ARM64_SIM_L_DECLARE_STACK(); __u8 __a64_sim_abi_kind=KPROG_ABI_KIND_XDP;']
        init += [f'__a64_x{j}.x=s->r[{j}];' for j in range(31)]
        init += ['entry_return_bits=s->r[30]; __a64_x30.x=0; __a64_x30_tag=ARM64_SIM_TAG_RETURN;']
        init += ['for (unsigned k=0;k<64;k++) __a64_stack.b[ARM64_SIM_STACK_BIAS-64+k]=s->stack[k];',
                 '__a64_n=(s->flags>>31)&1; __a64_z=(s->flags>>30)&1; __a64_c=(s->flags>>29)&1; __a64_v=(s->flags>>28)&1;',
                 '__a64_v0=s->vec[0]; __a64_v0_hi=s->vec[1];']
        finish = ['observed:;']+[f's->r[{j}]=ARM64_SIM_L_READ_REG({j});' for j in range(31)]
        finish += ['s->r[31]=__a64_sp;', 's->flags=((uint64_t)__a64_n<<31)|((uint64_t)__a64_z<<30)|((uint64_t)__a64_c<<29)|((uint64_t)__a64_v<<28);',
                   's->vec[0]=__a64_v0; s->vec[1]=__a64_v0_hi;', 'for (unsigned k=0;k<64;k++) s->stack[k]=__a64_stack.b[ARM64_SIM_STACK_BIAS-64+k];']
        body='\n'.join([f'static void sim_{i}(struct state *s) {{',*init,*emitted,'goto observed;',*finish,'}'])
        functions += [f'extern void native_{i}(struct state *);',f'extern unsigned char native_pc_{i},native_next_{i};', body]
        entries.append(f'{{{json.dumps(name)},"ARM64_CONTROL",native_{i},sim_{i},0xf0000000U,64,0,6,&native_pc_{i},&native_next_{i}}}')
        coverage.append(dict(assembly=name,native_instructions=len(code),opcode='ARM64_CONTROL'))
    prelude = ['#include "../driver.h"','#include <stdlib.h>','#define ARM64_SIM_ENABLE_STACK 1',*definitions,
        f'#include "{snapshot}/kprog/arm64/arm64_sim_local_bpf.h"',
        'static void arm64_sim_unsupported_opcode(void) { abort(); }',
        'extern uint64_t native_stack_base; static uint64_t entry_return_bits;',
        'unsigned long native_lab_entry_input(unsigned int kind) { if (kind == NATIVE_LAB_INPUT_SP) return native_stack_base; if (kind == NATIVE_LAB_INPUT_RETURN) return entry_return_bits; fputs("unknown control entry environment\\n",stderr); exit(1); }',
        '#undef ARM64_SIM_RET','#define ARM64_SIM_RET() goto observed']
    (out/'generated.c').write_text('\n'.join(prelude+functions+['const struct form forms[]={',',\n'.join(entries),'};','const unsigned form_count=sizeof(forms)/sizeof(forms[0]);'])+'\n')
    (out/'coverage.json').write_text(json.dumps(coverage,indent=2)+'\n')
    print(f'generated {len(matrix)} real ARM control/stack composites')


if __name__ == '__main__': main()
