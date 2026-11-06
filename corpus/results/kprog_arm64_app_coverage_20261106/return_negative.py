"""Load-only native RET forgery cases; never execute the unsafe native objects."""
import json
from pathlib import Path
import subprocess
import sys
from collections import OrderedDict
import coverage
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen
phase=Path(sys.argv[1]).resolve()
if sys.argv[2]=='generate':
 phase.mkdir();(phase/'sources').mkdir();(phase/'inputs').mkdir()
 rows=[]
 for name,body in [('outer_scalar_zero','mov w0,#2;mov x30,#0;ret'),
   ('local_scalar_pc','str x30,[sp,#-16]!;bl 1f;ldr x30,[sp],#16;mov w0,#2;ret;1:mov x30,#8;ret'),
   ('partial_saved_lr','str x30,[sp,#-16]!;strb wzr,[sp,#1];ldr x30,[sp],#16;mov w0,#2;ret'),
   ('crossword_saved_lr','sub sp,sp,#32;str x30,[sp,#8];strh wzr,[sp,#7];ldr x30,[sp,#8];add sp,sp,#32;mov w0,#2;ret'),
   ('memset_saved_lr','str x30,[sp,#-16]!;mov x0,sp;mov x1,#0;mov x2,#8;bl memset;ldr x30,[sp],#16;mov w0,#2;ret'),
   ('helper_saved_lr','str x30,[sp,#-16]!;mov x0,sp;mov x1,#8;bl bpf_get_current_comm;ldr x30,[sp],#16;mov w0,#2;ret')]:
  src=phase/(name+'.S');obj=phase/(name+'.proof.o')
  src.write_text('.text\n.global entry\n.type entry,%function\nentry:\n'+body.replace(';','\n')+'\n.size entry,.-entry\n')
  subprocess.run(['aarch64-linux-gnu-gcc','-c',src,'-o',obj],check=True)
  dump=subprocess.check_output(['aarch64-linux-gnu-objdump','-dr',obj],text=True)
  (phase/(name+'.asm')).write_text(dump)
  insns=gen.parse_flat_instructions(dump)
  out=phase/'sources'/(name+'.bpf.c')
  out.write_text(gen.render_program(name,'entry',OrderedDict(entry=insns),'xdp'))
  data=phase/'inputs'/(name+'.mem');data.write_bytes(bytes(64))
  rows.append(dict(name=name,proof=str(obj),source=str(out),stage='generate',ok=True,
   note='unsafe native RET forgery, load-only negative; native code is never executed',
   load_timeout_s=600))
 (phase/'programs.jsonl').write_text(''.join(json.dumps(r)+'\n' for r in rows))
 coverage.freeze_simulator(phase)
else:
 for row in coverage.records(phase):
  name=row['name'];rc=int((phase/'verify'/(name+'.rc')).read_text())
  log=(phase/'verify'/(name+'.verifier.log')).read_text()
  if rc==0 or 'invalid func unknown#-1' not in log:
   raise RuntimeError(f'{name}: forged return did not fail at PC default: rc={rc}\n{log}')
  print(f'{name}: forged RET rejects; unsafe native object never executed')
