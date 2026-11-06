"""Reproduce the nonregister PUSH semantic loss on the real bound path."""
import importlib.util
import json
from pathlib import Path
import sys
import subprocess
ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'kprog/fidelity'))
spec=importlib.util.spec_from_file_location('negative_cases',ROOT/'kprog/fidelity/negative.py')
neg=importlib.util.module_from_spec(spec);spec.loader.exec_module(neg)
BEFORE=HERE/'pushpop-before'
assembly='push 1; pop rax; test rax, rax; je 1f; mov rax, QWORD PTR [rdi+8]; movzx eax, BYTE PTR [rax]; ret; 1: mov eax, 2; ret'
neg.FIXTURES={'x86':{'push_immediate_unsafe_arm':assembly}}
if sys.argv[1]=='before-build':
 neg.build('x86',BEFORE)
elif sys.argv[1]=='before-bound':
 rc=neg.run_bound('x86',BEFORE,HERE/'pushpop-before-bound',HERE/'indirect-build/bound-probe',HERE/'abi-definedness/companion.bpf.o')
 row=json.loads((HERE/'pushpop-before-bound/outcomes.json').read_text())['cases'][0]
 assert rc==1 and row['stage']=='accepted_finding',row
 print('BUG reproduced: PUSH1 became PUSH0 and admitted unsafe native control flow; native was not executed')
elif sys.argv[1]=='after-build':
 neg.build('x86',HERE/'pushpop-after')
elif sys.argv[1]=='after-bound':
 rc=neg.run_bound('x86',HERE/'pushpop-after',HERE/'pushpop-after-bound',HERE/'indirect-build/bound-probe',HERE/'abi-definedness/companion.bpf.o')
 row=json.loads((HERE/'pushpop-after-bound/outcomes.json').read_text())['cases'][0]
 assert rc==0 and row['stage']=='verifier_rejected',row
 print('PUSH immediate unsafe arm rejected by the actual bound verifier')
elif sys.argv[1]=='prepare':
 b=HERE/'pushpop-build';b.mkdir(exist_ok=True)
 cases={
  'imm8_negative':('push -128; pop rax; shr rax,32; ret',0xffffffff),
  'imm8_positive':('push 127; pop rax; ret',127),
  'imm32_negative':('.byte 0x68,0,0,0,0x80; pop rax; shr rax,32; ret',0xffffffff),
  'imm32_positive':('push 0x12345678; pop rax; ret',0x12345678),
  'imm16':('mov eax,0; .byte 0x66,0x6a,0xff; pop ax; ret',0xffff),
  'push_mem_old_sp':('sub rsp,16; mov QWORD PTR [rsp],0x23; mov QWORD PTR [rsp+8],0x99; push QWORD PTR [rsp+8]; pop rax; add rsp,16; ret',0x99),
  'pop_mem_new_sp':('sub rsp,24; mov QWORD PTR [rsp],0; mov eax,0x44; push rax; pop QWORD PTR [rsp]; mov rax,QWORD PTR [rsp]; add rsp,24; ret',0x44),
  'pop_mem16':('sub rsp,8; mov QWORD PTR [rsp],0; mov eax,0x1234; push ax; pop WORD PTR [rsp]; movzx eax,WORD PTR [rsp]; add rsp,8; ret',0x1234),
  'pop_mem_index':('sub rsp,32; mov eax,0x55; mov ecx,1; push rax; pop QWORD PTR [rsp+rcx*8+8]; mov rax,QWORD PTR [rsp+16]; add rsp,32; ret',0x55),
 }
 for name,(body,expected) in cases.items():
  (b/(name+'.S')).write_text('.intel_syntax noprefix\n.text\n.globl '+name+'_native\n.type '+name+'_native,@function\n'+name+'_native:\n'+body.replace('; ','\n')+'\n.size '+name+'_native, .-'+name+'_native\n.section .note.GNU-stack,"",@progbits\n')
 (b/'cases.json').write_text(json.dumps(cases,indent=2)+'\n')
elif sys.argv[1]=='generate':
 sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
 import generate_micro_sim_proofs as g
 b=HERE/'pushpop-build';cases=json.loads((b/'cases.json').read_text())
 for name in cases:
  insns,subs,end,rodata=g.parse_proof_object_program(name,b)
  text=g.render_program(name,insns,subs,exit_addr=end,rodata16=rodata).replace('#include "../x86_sim_local_bpf.h"',f'#include "{ROOT}/kprog/x86/x86_sim_local_bpf.h"')
  (b/(name+'.bpf.c')).write_text(text)
 lines=['#include <linux/bpf.h>','#include <stdint.h>','#include <stdio.h>']
 for name in cases:lines += [f'uint64_t {name}_native(void);',f'int {name}_x86_sim_xdp(struct xdp_md *);']
 lines += ['int main(void) { struct xdp_md ctx={0};unsigned failures=0;']
 for name,(_,expected) in cases.items():
  lines += [f'{{ uint32_t n={name}_native(),s={name}_x86_sim_xdp(&ctx);',f'printf("{name} native=%u simulator=%u expected=%u\\n",n,s,{expected}U);',f'failures += n!={expected}U || s!=n; }}']
 lines += ['return failures!=0;}']
 (b/'main.c').write_text('\n'.join(lines)+'\n')
elif sys.argv[1]=='verify':
 b=HERE/'pushpop-build';cases=json.loads((b/'cases.json').read_text())
 payload=b/'input.bin';payload.write_bytes(bytes(64))
 failed=False
 for name,(_,expected) in cases.items():
  command=[str(ROOT/'kprog/loader/target/debug/reversesim-loader'),
           '--object',str(b/(name+'.bpf.o')),'--program',name+'_x86_sim_xdp',
           '--input',str(payload),'--expected-result','0','--expect-retval',str(expected),
           '--repeat','1','--verifier-log',str(b/(name+'.verifier.log'))]
  result=subprocess.run(command,text=True,capture_output=True,timeout=60)
  (b/(name+'.verify.json')).write_text(json.dumps(dict(command=command,returncode=result.returncode,stdout=result.stdout,stderr=result.stderr))+'\n')
  print(name,'returncode',result.returncode,flush=True)
  failed |= result.returncode != 0
 raise SystemExit(int(failed))
else:raise SystemExit('expected before/after-build, before/after-bound, prepare, generate or verify')
