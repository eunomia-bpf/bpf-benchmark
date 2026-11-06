"""Check relocated readonly tail bytes through real native and BPF execution."""
import json
from pathlib import Path
import subprocess
import sys
ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
OUT=HERE/'raw-context';OUT.mkdir(exist_ok=True)
LINK=HERE/'native-dispatch-link/release/native-link'
CASES={'tail_word':('mov eax,DWORD PTR [rip+native_tail_word+20]',0x84332211),
       'tail_signed':('movsx eax,BYTE PTR [rip+native_tail_signed+23]',0xffffff84),
       'frame_slot':('sub rsp,256; mov QWORD PTR [rsp],1; mov eax,DWORD PTR [rsp]; add rsp,256',1),
       'outside_frame':('mov QWORD PTR [rsp-1024],1; mov eax,DWORD PTR [rsp-1024]',None)}
def run(args):
 result=subprocess.run([str(a) for a in args],text=True,capture_output=True,timeout=120)
 with (OUT/'commands.jsonl').open('a') as stream:stream.write(json.dumps(dict(command=[str(a) for a in args],returncode=result.returncode,stdout=result.stdout,stderr=result.stderr))+'\n')
 if result.returncode:raise RuntimeError(result.stderr or result.stdout)
 return result
if sys.argv[1]=='prepare':
 for name,(body,expected) in CASES.items():
  (OUT/(name+'.S')).write_text(f'''.intel_syntax noprefix
.text
.globl {name}_native
.type {name}_native,@function
{name}_native:
 {body}
 ret
.size {name}_native,.-{name}_native
.section .rodata
.type native_{name},@object
native_{name}:
 .zero 20
 .byte 0x11,0x22,0x33,0x84
.size native_{name},.-native_{name}
.section .note.GNU-stack,"",@progbits
''')
 (OUT/'source.bpf.c').write_text('''#include <linux/bpf.h>
#include <bpf_helpers.h>
SEC("xdp") int raw_source(struct xdp_md *ctx) { return EXPECTED; }
char LICENSE[] SEC("license")="GPL";
''')
 (OUT/'host.c').write_text('''#include <stdint.h>
#include <stdio.h>
extern uint32_t tail_word_native(void *),tail_signed_native(void *);
extern uint32_t frame_slot_native(void *);
int main(void) {
 unsigned word=tail_word_native(0),sign=tail_signed_native(0);
 unsigned frame=frame_slot_native(0);
 printf("word=%u signed=%u frame=%u\\n",word,sign,frame);
 return word!=0x84332211u || sign!=0xffffff84u || frame!=1;
}
''')
elif sys.argv[1]=='generate':
 sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
 import generate_micro_sim_proofs as g
 for name,(body,expected) in CASES.items():
  proof=OUT/(name+'.proof.o')
  run([LINK,'--input',OUT/(name+'.native.o'),'--symbol',name+'_native','--mode','proof','--preserve-entry-abi','--output',proof])
  (OUT/(name+'_native.proof.o')).write_bytes(proof.read_bytes())
  insns,subs,end,rodata=g.parse_proof_object_program(name,OUT)
  if name.startswith('tail_'):
   assert len(rodata)==1 and len(next(iter(rodata.values())))==24,rodata
   entry=insns[0]
   assert entry.symbol_offset==(20 if name=='tail_word' else 23),entry
  text=g.render_program(name,insns,subs,'raw',exit_addr=end,rodata16=rodata,program_section='xdp')
  (OUT/(name+'.bpf.c')).write_text(text.replace('#include "../x86_sim_local_bpf.h"',f'#include "{ROOT}/kprog/x86/x86_sim_local_bpf.h"'))
  (OUT/(name+'.manifest.json')).write_text(json.dumps(dict(objects=[dict(program='raw_source',
   native_object=str(OUT/(name+'.native.o')),symbol=name+'_native',
   simulator_object=str(OUT/(name+'.bpf.o')),simulator_program=name+'_x86_sim_xdp')])))
elif sys.argv[1]=='bound':
 failed=False
 for name,(_,expected) in CASES.items():
  args=[str(OUT/'bound-probe'),str(OUT/(name+'.source.bpf.o')),str(OUT/(name+'.manifest.json'))]
  if expected is not None:args+=['0',str(expected)]
  result=subprocess.run(args,text=True,capture_output=True,timeout=120)
  row=dict(command=args,returncode=result.returncode,stdout=result.stdout,stderr=result.stderr)
  (OUT/(name+'.bound.json')).write_text(json.dumps(row,indent=2)+'\n')
  print(name,result.returncode,result.stdout,result.stderr,flush=True)
  if expected is None:
   # Load only: this unsafe native is never executed, on host or in the VM.
   valid=result.returncode!=0 and 'verifier log tail:' in result.stderr and (
       'math between fp pointer' in result.stderr or 'invalid stack' in result.stderr.lower())
   failed|=not valid
  else:failed|=bool(result.returncode)
 raise SystemExit(int(failed))
else:raise SystemExit('expected prepare, generate or bound')
