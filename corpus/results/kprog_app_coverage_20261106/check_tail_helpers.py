"""Catch external JMP relocation shrinking and lost helper/return transitions."""
import json
import os
from pathlib import Path
import subprocess
import sys
from elftools.elf.elffile import ELFFile
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
OUT=HERE/'tail-helper';OUT.mkdir(exist_ok=True)
LINK=ROOT/'kprog/x86/native_lab/native_link/target-c-tail/release/native-link'
sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
import generate_micro_sim_proofs as gen
CASES={'direct':'jmp bpf_ktime_get_coarse_ns',
       'got':'jmp *bpf_ktime_get_coarse_ns@GOTPCREL(%rip)',
       'numeric':'mov $160,%eax; jmp *%rax',
       'subprogram':'call inner; ret\n.size entry,.-entry\n.type inner,@function\ninner:\njmp bpf_ktime_get_coarse_ns\n.size inner,.-inner'}
def run(args,**kwargs):
    args=list(map(str,args));r=subprocess.run(args,capture_output=True,text=True,timeout=120,**kwargs)
    with (OUT/'commands.jsonl').open('a') as stream:
        stream.write(json.dumps(dict(command=args,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))+'\n')
    if r.returncode:raise RuntimeError(r.stderr or r.stdout)
    return r
if sys.argv[1]=='build':
    for name,body in CASES.items():
        case=OUT/name;case.mkdir(exist_ok=True)
        source=case/'entry.S';source.write_text('.text\n.global entry\n.type entry,@function\nentry:\n'+body+('' if name=='subprogram' else '\n.size entry,.-entry')+'\n.section .note.GNU-stack,"",@progbits\n')
        native=case/'entry.native.o';proof=case/'entry.proof.o'
        run(['cc','-c',source,'-o',native])
        run([LINK,'--input',native,'--symbol','entry','--mode','proof','--preserve-entry-abi','--output',proof])
        insns,subs,end,rodata=gen.parse_proof_object_program('entry',case)
        all_insns=insns+[item for values in subs.values() for item in values]
        calls=[insn for insn in all_insns if insn.mnemonic=='call']
        if len(calls)!=(2 if name=='subprogram' else 1):raise RuntimeError(calls)
        with proof.open('rb') as stream:
            elf=ELFFile(stream)
            for section in elf.iter_sections():
                if section['sh_type']!='SHT_RELA':continue
                target=elf.get_section(section['sh_info'])
                for reloc in section.iter_relocations():
                    if reloc['r_info_type']==4:
                        off=reloc['r_offset']
                        if target.data()[off-1]!=0xe8 or off+4>len(target.data()):raise RuntimeError('tail relocation no longer points at a complete CALL field')
        text=gen.render_program('tail_'+name,insns,subs,'raw',exit_addr=end,rodata16=rodata,program_section='socket')
        bpf_source=case/'entry.bpf.c';bpf_source.write_text(text.replace('#include "../x86_sim_local_bpf.h"',f'#include "{ROOT}/kprog/x86/x86_sim_local_bpf.h"'))
        run(['clang','-O2','-g','-Wno-c23-extensions','-target','bpf','-I'+str(ROOT/'vendor/libbpf/include/uapi'),'-I'+str(ROOT/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu','-c',bpf_source,'-o',case/'entry.bpf.o'])
        (case/'proof.disassembly').write_text(run(['objdump','-dr','-Mintel',proof]).stdout)
        print(name,'canonical helper CALL + fragment return, valid ELF fields, proof compile PASS',flush=True)
elif sys.argv[1]=='negative':
    case=OUT/'unknown';case.mkdir(exist_ok=True)
    source=case/'entry.S'
    source.write_text('.text\n.global entry\n.type entry,@function\nentry:\ncall bpf_get_prandom_u32\ntest %eax,%eax\njz 1f\nmov $160,%eax\n1: jmp *%rax\n.size entry,.-entry\n')
    native=case/'entry.native.o';proof=case/'entry.proof.o'
    run(['cc','-c',source,'-o',native])
    run([LINK,'--input',native,'--symbol','entry','--mode','proof','--preserve-entry-abi','--output',proof])
    insns,subs,end,rodata=gen.parse_proof_object_program('entry',case)
    try:
        gen.render_program('tail_unknown',insns,subs,'raw',exit_addr=end,rodata16=rodata,program_section='socket')
    except ValueError as error:
        (case/'specialization-error.txt').write_text(str(error)+'\n')
        if 'indirect' not in str(error):raise
        print('unknown helper tail path specialization rejects:',error,flush=True)
    else:raise RuntimeError('unknown incoming helper target was admitted')
elif sys.argv[1]=='bound':
    for name in CASES:
        case=OUT/name
        env=dict(os.environ,KPROG_TEST_SHIM=str(HERE/'strict-runtime-input/libbpfrejit_shim.so'),
            KPROG_TEST_LOADER=str(HERE/'strict-runtime-input/libnative_loader.so'),
            KPROG_TEST_LINK=str(LINK),KPROG_TEST_COARSE_NATIVE=str(case/'entry.native.o'),
            KPROG_TEST_COARSE_SYMBOL='entry',KPROG_TEST_COARSE_SIM=str(case/'entry.bpf.o'),
            KPROG_TEST_COARSE_PROGRAM='tail_'+name+'_x86_sim_xdp')
        result=run([sys.executable,HERE/'check_object_startup.py','tail-object-'+name],env=env)
        print(name,result.stdout,flush=True)
else:raise SystemExit('expected build or bound')
