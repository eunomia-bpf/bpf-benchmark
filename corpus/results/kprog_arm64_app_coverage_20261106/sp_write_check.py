"""Compare a balanced MOV-to-SP native function with its actual simulator proof."""
import json
from pathlib import Path
import subprocess
import sys
from collections import OrderedDict
import coverage
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen
phase=Path(sys.argv[1]).resolve();phase.mkdir()
for name in ['sources','inputs']:(phase/name).mkdir()
body='sub sp,sp,#32;mov x3,sp;add sp,sp,#16;mov sp,x3;mov x0,sp;sub x0,x0,x3;add sp,sp,#32;ret'
assembly=phase/'sp_restore.S';obj=phase/'sp_restore.proof.o'
assembly.write_text('.text\n.global sp_restore\n.type sp_restore,%function\nsp_restore:\n'+body.replace(';','\n')+'\n.size sp_restore,.-sp_restore\n.section .note.GNU-stack,"",%progbits\n')
main=phase/'main.c';main.write_text('#include <stdio.h>\nextern unsigned long sp_restore(void);\nint main(void){unsigned long value=sp_restore();printf("native MOV-to-SP result=%lu\\n",value);return value!=0;}\n')
subprocess.run(['aarch64-linux-gnu-gcc','-c',assembly,'-o',obj],check=True)
subprocess.run(['aarch64-linux-gnu-gcc','-O2','-static',main,obj,'-o',phase/'native'],check=True)
native=subprocess.run(['qemu-aarch64-static',phase/'native'],text=True,capture_output=True)
(phase/'native.json').write_text(json.dumps(dict(returncode=native.returncode,stdout=native.stdout,stderr=native.stderr))+'\n')
if native.returncode:raise RuntimeError(native.stdout+native.stderr)
dump=subprocess.check_output(['aarch64-linux-gnu-objdump','-dr',obj],text=True)
(phase/'sp_restore.asm').write_text(dump)
source=phase/'sources/sp_restore.bpf.c'
source.write_text(gen.render_program('sp_restore','sp_restore',OrderedDict(sp_restore=gen.parse_flat_instructions(dump)),'xdp'))
packet=phase/'inputs/sp_restore.mem';packet.write_bytes(bytes(64))
row=dict(name='sp_restore',proof=str(obj),source=str(source),stage='generate',ok=True,note='balanced real SP restore; native returns0',input_file=str(packet),expected_result=0,expected_retval=0,result_channel='packet',cgroup_skb_input=False,load_timeout_s=600)
(phase/'programs.jsonl').write_text(json.dumps(row)+'\n')
coverage.freeze_simulator(phase)
print(native.stdout,end='')
