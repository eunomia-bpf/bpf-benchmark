#!/usr/bin/env python3
"""Real ARM control/stack composites paired with the production whole-program encoder."""
from collections import OrderedDict
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
    for cc in ['eq','ne','cs','cc','mi','pl','vs','vc','hi','ls','ge','lt','gt','le']:
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
        ('SP compare flags', 'cmp sp,#0\n'+branch('b.eq', False)),
    ]
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
        wrapper = wrapper.replace('ldr x0, [sp, #96]', 'ldr x0, [sp, #96]\n'+after)
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
        rendered = enc.render_program(f'control_{i}', 'entry', OrderedDict(entry=code), 'xdp')
        start = rendered.index('SEC("xdp")')
        active = False
        for line in rendered[:rendered.index('#include')].splitlines():
            if line.startswith('#define '): active = line.startswith('#define ARM64_SIM_RET_CASES_')
            if active: definitions.append(line)
            if not line.endswith('\\'): active = False
        body = rendered[start:].replace('SEC("xdp")\n','').replace(f'int control_{i}_arm64_sim_xdp(struct xdp_md *ctx)',f'static void sim_{i}(struct state *s)')
        init = ['ARM64_SIM_L_DECLARE_STATE(); ARM64_SIM_L_DECLARE_STACK(); __u8 __a64_sim_abi_kind=KPROG_ABI_KIND_XDP;']
        init += [f'__a64_x{j}.x=s->r[{j}];' for j in range(31)]
        init += ['for (unsigned k=0;k<64;k++) __a64_stack.b[ARM64_SIM_STACK_BIAS-64+k]=s->stack[k];',
                 '__a64_n=(s->flags>>31)&1; __a64_z=(s->flags>>30)&1; __a64_c=(s->flags>>29)&1; __a64_v=(s->flags>>28)&1;',
                 '__a64_v0=s->vec[0]; __a64_v0_hi=s->vec[1];']
        body = body.replace('ARM64_SIM_ENTRY_XDP(ctx);','\n'.join(init)).replace('\treturn 0;','\tgoto observed;').replace('ARM64_SIM_LICENSE();','')
        finish = ['observed:;']+[f's->r[{j}]=__a64_x{j}.x;' for j in range(31)]
        finish += ['s->r[31]=__a64_sp;', 's->flags=((uint64_t)__a64_n<<31)|((uint64_t)__a64_z<<30)|((uint64_t)__a64_c<<29)|((uint64_t)__a64_v<<28);',
                   's->vec[0]=__a64_v0; s->vec[1]=__a64_v0_hi;', 'for (unsigned k=0;k<64;k++) s->stack[k]=__a64_stack.b[ARM64_SIM_STACK_BIAS-64+k];']
        end = body.rindex('}')
        body = body[:end]+'\n'.join(finish)+'\n'+body[end:]
        functions += [f'extern void native_{i}(struct state *);',f'extern unsigned char native_pc_{i},native_next_{i};', body]
        entries.append(f'{{{json.dumps(name)},"ARM64_CONTROL",native_{i},sim_{i},0xf0000000U,64,0,6,&native_pc_{i},&native_next_{i}}}')
        coverage.append(dict(assembly=name,native_instructions=len(code),opcode='ARM64_CONTROL'))
    prelude = ['#include "../driver.h"','#include <stdlib.h>','#define ARM64_SIM_ENABLE_STACK 1',*definitions,
        f'#include "{snapshot}/kprog/arm64/arm64_sim_local_bpf.h"',
        'static void arm64_sim_unsupported_opcode(void) { abort(); }',
        '#undef ARM64_SIM_RET','#define ARM64_SIM_RET() goto observed']
    (out/'generated.c').write_text('\n'.join(prelude+functions+['const struct form forms[]={',',\n'.join(entries),'};','const unsigned form_count=sizeof(forms)/sizeof(forms[0]);'])+'\n')
    (out/'coverage.json').write_text(json.dumps(coverage,indent=2)+'\n')
    print(f'generated {len(matrix)} real ARM control/stack composites')


if __name__ == '__main__': main()
