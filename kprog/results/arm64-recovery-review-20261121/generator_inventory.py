"""Record current accepted read tokens and named decoder/producer exclusions."""
from pathlib import Path
import dataclasses,importlib.util,json,sys
R=Path('/workspaces/repository');S=Path(sys.argv[1])
p=R/'kprog/arm64/micro-prog/generate_micro_sim_proofs.py'
sys.path.insert(0,str(p.parent))
spec=importlib.util.spec_from_file_location('arm_recovery_generator',p);g=importlib.util.module_from_spec(spec);sys.modules[spec.name]=g;spec.loader.exec_module(g)
rows=json.loads((R/'kprog/results/kprog_arm64_read_recovery_20261109/generation-boundaries.json').read_text())
for form,asm in [('ldr_d0','ldr d0, [x2]'),('ldr_q0','ldr q0, [x2]'),('ldr_d0_post','ldr d0, [x2], #8'),('ldr_q0_post','ldr q0, [x2], #16')]:
    rows.append(dict(form=form,assembly=asm))
for row in rows:
    asm=row['assembly'];op,operands=asm.split(' ',1)
    try:
        row['current_token']=dataclasses.asdict(g.encode(g.NativeInsn(0,op,g.split_operands(operands),asm),{},{}));row['current_status']='accepted'
    except ValueError as e:row['current_diagnostic']=str(e);row['current_status']='generation_rejected'
    row.pop('generation_diagnostic',None)
accepted=[]
for op,regs in [('ldr','x0'),('ldur','w0'),('ldrb','w0'),('ldurb','w0'),('ldrh','w0'),('ldurh','w0'),('ldrsb','x0'),('ldrsh','x0'),('ldrsw','x0'),('ldxr','x0'),('ldaxr','x0')]:
    for mem in ['[x2]','[x2, #8]','[x2, x3]']:
        asm=op+' '+regs+', '+mem
        accepted.append(dict(assembly=asm,token=dataclasses.asdict(g.encode(g.NativeInsn(0,op,g.split_operands(regs+', '+mem),asm),{},{}))))
for asm in ['ldp x0, x1, [x2]','ldp w0, w1, [x2], #8','ldp x0, x1, [x2, #16]!','ldr x0, [x2], #8','ldr x0, [x2, #8]!','ldadd x0, x1, [x2]','ldset w0, w1, [x2]','ldclralh w0, w1, [x2]']:
    op,operands=asm.split(' ',1)
    accepted.append(dict(assembly=asm,token=dataclasses.asdict(g.encode(g.NativeInsn(0,op,g.split_operands(operands),asm),{},{}))))
(S/'generator-inventory.json').write_text(json.dumps(dict(named_exclusions=rows,accepted_examples=accepted),indent=2)+'\n')
print('named',len(rows),'rejected',sum(r['current_status']=='generation_rejected' for r in rows),'accepted_examples',len(accepted))
