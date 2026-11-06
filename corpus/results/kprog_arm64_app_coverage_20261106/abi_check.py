"""Real encodings that catch ABI opacity, lane-transfer, join and clobber bugs."""
import json
from pathlib import Path
import subprocess
import sys
from collections import OrderedDict
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen
phase=Path(sys.argv[1]).resolve();phase.mkdir(exist_ok=True)
cases=[
 ('tail-helper-args', 'mov x8,#1;br x8','undefined native ABI register'),
 ('helper-vector-clobber', 'str x30,[sp,#-16]!;fmov d0,x0;bl bpf_get_current_uid_gid;fmov x0,d0;ldr x30,[sp],#16;ret','undefined native ABI register'),
 ('blind-save', 'stp x19,x30,[sp,#-16]!;mov w0,#2;ldp x19,x30,[sp],#16;ret',None),
 ('opaque-reload', 'str x1,[sp,#-16]!;ldr x0,[sp],#16;ret','undefined native ABI register'),
 ('opaque-escape', 'str x1,[x0];mov w0,#2;ret','escapes private stack'),
 ('opaque-private-alias', 'sub sp,sp,#16;mov x2,sp;str x1,[x2];mov w0,#2;add sp,sp,#16;ret',None),
 ('partial-movk-low-return', 'movk x0,#2;ret',None),
 ('partial-movk-unknown-high', 'movk x1,#2;cmp x1,#2;mov w0,#2;ret','undefined native ABI register'),
 ('partial-movk-low-shift', 'movk x1,#2;lsl x0,x1,#48;ret',None),
 ('partial-movk-high-shift', 'movk x1,#2,lsl#48;lsr x0,x1,#48;ret',None),
 ('partial-movk-shift-survivor', 'movk x1,#2;lsr x0,x1,#16;ret','undefined native ABI register'),
 ('partial-four-lanes', 'movk x1,#1;movk x1,#2,lsl#16;movk x1,#3,lsl#32;movk x1,#4,lsl#48;mov x0,x1;ret',None),
 ('w-zero-extension', 'mov w1,w0;mov x0,x1;ret',None),
 ('flag-entry', 'b.eq 1f;mov w0,#2;1: ret','undefined native ABI flags'),
 ('unused-nv-flags', 'csel x0,x0,x0,nv;ret',None),
 ('self-compare', 'cmp x1,x1;cset w0,eq;ret',None),
 ('join-missing-write', 'cbz x0,1f;mov w1,#2;1: mov w0,w1;ret','undefined native ABI register'),
 ('join-both-writes', 'cbz x0,1f;mov w1,#2;b 2f;1:mov w1,#3;2:mov w0,w1;ret',None),
 ('helper-clobber', 'str x30,[sp,#-16]!;mov x1,#0;bl bpf_get_current_uid_gid;cbz x1,1f;1:ldr x30,[sp],#16;ret','undefined native ABI register'),
 ('helper-flags', 'str x30,[sp,#-16]!;cmp x0,x0;bl bpf_get_current_uid_gid;b.eq 1f;1:ldr x30,[sp],#16;ret','undefined native ABI flags'),
 ('callee-save-across-helper', 'stp x19,x30,[sp,#-16]!;mov x19,x0;bl bpf_get_current_uid_gid;mov x0,x19;ldp x19,x30,[sp],#16;ret',None),
 ('return-sp-unbalanced', 'sub sp,sp,#16;mov w0,#2;ret','unbalanced stack pointer'),
 ('local-call-context', 'str x30,[sp,#-16]!;mov w1,#2;bl 1f;ldr x30,[sp],#16;ret;1:mov w0,w1;ret',None),
 ('local-call-bad-context', 'str x30,[sp,#-16]!;bl 1f;cbz w0,2f;2:mov w1,#2;bl 1f;ldr x30,[sp],#16;ret;1:mov w0,w1;ret','undefined native ABI register'),
 ('tbz-defined-bit', 'movk x1,#2;tbz x1,#0,1f;1:mov w0,#2;ret',None),
 ('tbz-unknown-bit', 'movk x1,#2;tbz x1,#32,1f;1:mov w0,#2;ret','undefined native ABI register'),
 ('mask-defined-bits','movk x1,#2;and x0,x1,#0xffff;ret',None),
]
rows=[]
for name,body,error in cases:
 src=phase/(name+'.S');obj=phase/(name+'.proof.o')
 src.write_text('.text\n.global entry\n.type entry,%function\nentry:\n'+body.replace(';','\n')+'\n.size entry,.-entry\n')
 subprocess.run(['aarch64-linux-gnu-gcc','-c',src,'-o',obj],check=True)
 dump=subprocess.check_output(['aarch64-linux-gnu-objdump','-dr',obj],text=True)
 (phase/(name+'.asm')).write_text(dump)
 insns=gen.parse_flat_instructions(dump)
 try:
  source=gen.render_program(name.replace('-','_'),'entry',OrderedDict(entry=insns),'xdp')
  (phase/(name+'.bpf.c')).write_text(source)
  message='generated';passed=error is None
 except ValueError as failure:
  message=str(failure);passed=error is not None and error in message
 rows.append(dict(name=name,expected_error=error,message=message,passed=passed))
 print(f'{name}: {"PASS" if passed else "FAIL"}: {message}',flush=True)
(phase/'outcomes.json').write_text(json.dumps(rows,indent=2)+'\n')
raise SystemExit(int(not all(r['passed'] for r in rows)))
